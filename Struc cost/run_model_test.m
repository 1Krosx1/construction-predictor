function [predicted_budget, debugInfo] = run_model_test(inputValues)
%RUN_MODEL_TEST Predict structural budget from UI inputs using saved assets.
%   inputValues is a 1xN numeric vector in this order:
%   [year, num_storeys, num_classrooms, total_gross_floor_area, ...
%    total_concrete_volume, total_reinforcing_steel, area_of_formworks, ...
%    cost_per_sqm, cost_per_classroom, concrete_per_floor_area, steel_per_concrete]
%
%   Returns predicted_budget (scalar, same unit as training budget)
%   and debugInfo (struct with mapping details).

% Robust defaults
predicted_budget = NaN;
debugInfo = struct();

assetsFile = fullfile(pwd,'structural_model_assets.mat');
if ~exist(assetsFile,'file')
    error('Model assets file not found: %s', assetsFile);
end
S = load(assetsFile);
reqFields = {'optimized_model','mu','sigma','selected_mask','final_feature_columns'};
missing = setdiff(reqFields, fieldnames(S));
if ~isempty(missing)
    error('Model assets missing required fields: %s', strjoin(missing, ', '));
end

final_feature_columns = S.final_feature_columns; % cellstr in training order
normFFC = cellfun(@(c) lower(matlab.lang.makeValidName(c)), final_feature_columns, 'UniformOutput', false);

% Build a mapping from canonical UI names to vector indices
uiIndex = containers.Map( ...
    {'year','num_storeys','num_classrooms','total_gross_floor_area', ...
     'total_concrete_volume','total_reinforcing_steel','cost_per_sqm', ...
     'cost_per_classroom','concrete_per_floor_area','steel_per_concrete'}, ...
    num2cell([1 2 3 4 5 6 8 9 10 11]) ...
);

% Prepare a single-row vector aligned to final_feature_columns order
v = zeros(1, numel(final_feature_columns));
for i = 1:numel(final_feature_columns)
    fnameNorm = normFFC{i};
    if contains(fnameNorm, 'formworks')
        v(i) = inputValues(7); % area_of_formworks from UI
    elseif isKey(uiIndex, fnameNorm)
        v(i) = inputValues(uiIndex(fnameNorm));
    else
        % In case of unseen/extra engineered raw feature names, default to 0
        v(i) = 0;
    end
end

% Build a 1xK table with the exact variable names from training
T_row = array2table(v, 'VariableNames', final_feature_columns);

% Generate polynomial + interaction features up to degree 2 like training
[X_poly, poly_feature_names] = generatePolyFeatures(T_row, 2);

% Scale using stored mu/sigma from training
mu = S.mu; sigma = S.sigma;
% Ensure row vectors for broadcasting
if size(mu,1) > 1 && size(mu,2) == 1, mu = mu'; end
if size(sigma,1) > 1 && size(sigma,2) == 1, sigma = sigma'; end
% Guard against size mismatches by truncating/padding if necessary
nTrain = numel(mu);
nNow = size(X_poly,2);
if nNow ~= nTrain
    % Align by min size; pad with zeros/ones as safe fallback
    if nNow < nTrain
        X_poly(:, end+1:nTrain) = 0; %#ok<AGROW>
    elseif nNow > nTrain
        X_poly = X_poly(:, 1:nTrain);
        poly_feature_names = poly_feature_names(1:nTrain);
    end
end
sigmaSafe = sigma; sigmaSafe(sigmaSafe==0) = 1; % avoid div-by-zero
X_poly_scaled = (X_poly - mu) ./ sigmaSafe;
X_poly_scaled(isnan(X_poly_scaled)) = 0;

% Feature selection mask
mask = S.selected_mask;
if iscolumn(mask), mask = mask'; end
if numel(mask) ~= size(X_poly_scaled,2)
    % Align sizes if needed (fallback conservative)
    m = min(numel(mask), size(X_poly_scaled,2));
    mask = mask(1:m);
    X_poly_scaled = X_poly_scaled(:,1:m);
end
X_sel = X_poly_scaled(:, mask);

% Predict log-budgets then invert the transform
log_pred = predict(S.optimized_model, X_sel);
pred = expm1(log_pred);

% Safety: clamp to non-negative
predicted_budget = max(0, pred);

% Debug info for inspection if needed
debugInfo.final_feature_columns = final_feature_columns;
debugInfo.norm_final_feature_columns = normFFC;
debugInfo.input_row = v;
debugInfo.poly_feature_count = size(X_poly,2);
debugInfo.selected_feature_count = size(X_sel,2);
end
