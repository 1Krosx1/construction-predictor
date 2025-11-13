function export_structural_metrics()
% Compute baseline and optimized test metrics for the structural model
% using a fixed train/test split, then export a LaTeX snippet with exact
% numbers for inclusion in Struc budget.tex.

rng(42, 'twister');
opts = detectImportOptions('Structural_Total_Cost.csv');
opts.VariableNamingRule = 'preserve';
T = readtable('Structural_Total_Cost.csv', opts);

% Clean headers
T.Properties.VariableNames = lower(matlab.lang.makeUniqueStrings(matlab.lang.makeValidName(T.Properties.VariableNames)));
T = T(:, ~startsWith(T.Properties.VariableNames, 'unnamed'));

% Budget standardization and cleaning
budget_idx = find(strcmp(T.Properties.VariableNames, 'budget'), 1);
if isempty(budget_idx)
    budget_idx = find(contains(T.Properties.VariableNames, 'budget'), 1);
end
T.Properties.VariableNames{budget_idx} = 'budget';
if iscell(T.budget)
    T.budget = str2double(strrep(T.budget, ',', ''));
end
T = T(~isnan(T.budget), :);

% Coerce numeric-like strings
for i = 1:width(T)
    vn = T.Properties.VariableNames{i};
    if iscell(T.(vn)) && ~strcmp(vn,'project')
        T.(vn) = str2double(strrep(T.(vn), ',', ''));
    end
end

% Impute NaNs by median
numVars = T.Properties.VariableNames(vartype('numeric'));
for i = 1:numel(numVars)
    vn = numVars{i};
    med = median(T.(vn), 'omitnan');
    T.(vn) = fillmissing(T.(vn), 'constant', med);
end

% Feature engineering (regex)
T = T(T.budget > 100000, :);
T.budget_log = log1p(T.budget);

tokens_sty = regexp(T.project, '(\d+)\s*STY', 'tokens');
tokens_cl  = regexp(T.project, '(\d+)\s*CL', 'tokens');
T.num_storeys = nan(height(T),1);
T.num_classrooms = nan(height(T),1);
for i = 1:height(T)
    if ~isempty(tokens_sty{i}); T.num_storeys(i) = str2double(tokens_sty{i}{1}); end
    if ~isempty(tokens_cl{i});  T.num_classrooms(i) = str2double(tokens_cl{i}{1}); end
end
for vn = {'num_storeys','num_classrooms'}
    med = median(T.(vn{1}), 'omitnan');
    T.(vn{1}) = fillmissing(T.(vn{1}), 'constant', med);
end

% Aggregates
fa_cols = T.Properties.VariableNames(contains(T.Properties.VariableNames, 'grossfloorarea'));
T.total_gross_floor_area = sum(T{:, fa_cols}, 2);
con_cols = T.Properties.VariableNames(contains(T.Properties.VariableNames, 'volumeofstructuralconcrete'));
T.total_concrete_volume = sum(T{:, con_cols}, 2);
if ismember('grade40', T.Properties.VariableNames)
    g40 = T.grade40; else, g40 = zeros(height(T),1); end
if ismember('grade60', T.Properties.VariableNames)
    g60 = T.grade60; else, g60 = zeros(height(T),1); end
T.total_reinforcing_steel = g40 + g60;

% Formworks column name (auto-detect)
fw_idx = find(contains(T.Properties.VariableNames, 'formworks'), 1);
assert(~isempty(fw_idx), 'Could not find a formworks column.');
formworks_col_name = T.Properties.VariableNames{fw_idx};

% Ratios
T.concrete_per_floor_area = T.total_concrete_volume ./ max(T.total_gross_floor_area, eps);
T.concrete_per_floor_area(~isfinite(T.concrete_per_floor_area)) = 0;
T.steel_per_concrete = T.total_reinforcing_steel ./ max(T.total_concrete_volume, eps);
T.steel_per_concrete(~isfinite(T.steel_per_concrete)) = 0;

% Final feature columns (9)
final_feature_columns = {'year','num_storeys','num_classrooms', ...
    'total_gross_floor_area','total_concrete_volume','total_reinforcing_steel', ...
    formworks_col_name,'concrete_per_floor_area','steel_per_concrete'};

X = T(:, final_feature_columns);
y = T.budget_log;

% Split
cv = cvpartition(height(X), 'HoldOut', 0.2);
X_train = X(training(cv),:); y_train = y(training(cv),:);
X_test  = X(test(cv),:);     y_test  = y(test(cv),:);

% Poly features
[Xtr_poly, poly_names] = generatePolyFeatures(X_train, 2);
Xte_poly = generatePolyFeatures(X_test, 2);

% Scale
[Xtr_sc, mu, sigma] = zscore(Xtr_poly);
Xte_sc = (Xte_poly - mu) ./ sigma; Xte_sc(~isfinite(Xte_sc)) = 0;

% Baseline model
base = fitrensemble(Xtr_sc, y_train, 'Method','LSBoost','NumLearningCycles',100);
yp_base = predict(base, Xte_sc);
yp_base_lin = expm1(yp_base); yt_lin = expm1(y_test);
r2_base = 1 - sum((yt_lin-yp_base_lin).^2)/sum((yt_lin-mean(yt_lin)).^2);
mae_base = mean(abs(yt_lin-yp_base_lin));

% Feature selection
imp_base = predictorImportance(base);
thr = median(imp_base);
sel_mask = imp_base > thr; sel_names = poly_names(sel_mask);
Xtr_sel = Xtr_sc(:, sel_mask); Xte_sel = Xte_sc(:, sel_mask);

% Optimized model (bounded evaluations)
optimizable_vars = [ ...
    optimizableVariable('NumLearningCycles',[500,1000],'Type','integer');
    optimizableVariable('MaxNumSplits',[8,32],'Type','integer');
    optimizableVariable('LearnRate',[0.01,0.1],'Type','real','Transform','log')];
opts = struct('AcquisitionFunctionName','expected-improvement-plus', ...
              'ShowPlots',false, 'Verbose',0, 'MaxObjectiveEvaluations',15);
opt = fitrensemble(Xtr_sel, y_train, 'Method','LSBoost', ...
    'OptimizeHyperparameters', optimizable_vars, ...
    'HyperparameterOptimizationOptions', opts);
yp_opt = predict(opt, Xte_sel);
yp_opt_lin = expm1(yp_opt);
r2_best = 1 - sum((yt_lin-yp_opt_lin).^2)/sum((yt_lin-mean(yt_lin)).^2);
mae_best = mean(abs(yt_lin-yp_opt_lin));

% Export LaTeX snippet
fid = fopen('structural_metrics.tex','w');
assert(fid>0, 'Cannot open structural_metrics.tex for writing');
cleanup = onCleanup(@() fclose(fid));
fprintf(fid, '%% Auto-generated by export_structural_metrics()\\n');
fprintf(fid, '\\section*{Testing metrics (numerical summary)}\\n');
fprintf(fid, 'Holdout: 20\\%% (fixed RNG seed).\\\\\\n');
fprintf(fid, 'Baseline LSBoost: $R^2 = %.4f$, MAE $= %.2f$.\\\\\\n', r2_base, mae_base);
fprintf(fid, 'Optimized LSBoost: $R^2 = %.4f$, MAE $= %.2f$.\\n', r2_best, mae_best);
fprintf(fid, 'Selected feature count: %d of %d (median-importance threshold).\\n', nnz(sel_mask), numel(sel_mask));

% Console echo
fprintf('Exported structural_metrics.tex with: R2_base=%.4f, MAE_base=%.2f, R2_best=%.4f, MAE_best=%.2f\n', ...
    r2_base, mae_base, r2_best, mae_best);

end
