% =============================================================================
% Structural Model Feature Percentile Analysis
% =============================================================================
clear; clc; close all;
disp('Environment cleared.');

% =============================================================================
% Section 2: Data Loading and Comprehensive Cleaning
% =============================================================================
disp(newline + "--- Section 2: Data Loading & Cleaning ---");
try
    opts = detectImportOptions('Structural_Total_Cost.csv');
    opts.VariableNamingRule = 'preserve';
    T = readtable('Structural_Total_Cost.csv', opts);
    disp("Dataset 'Structural_Total_Cost.csv' loaded successfully.");
catch ME
    error("Error loading 'Structural_Total_Cost.csv'. Check file path and format. (%s)", ME.message);
end

% --- Clean Column Names ---
validVarNames = matlab.lang.makeValidName(T.Properties.VariableNames);
uniqueVarNames = matlab.lang.makeUniqueStrings(validVarNames);
T.Properties.VariableNames = lower(uniqueVarNames);
T = T(:, ~startsWith(T.Properties.VariableNames, 'unnamed'));

% --- Identify and Standardize Budget Column ---
budget_idx = find(strcmp(T.Properties.VariableNames, 'budget'), 1);
if isempty(budget_idx)
    budget_idx = find(contains(T.Properties.VariableNames, 'budget', 'IgnoreCase', true), 1);
end
if isempty(budget_idx)
    error("Error: No column related to 'budget' found after cleaning headers.");
end
T.Properties.VariableNames{budget_idx} = 'budget';

% --- Robust data cleaning and type conversion ---
if iscell(T.budget)
    T.budget = str2double(strrep(T.budget, ',', ''));
end
T = T(~isnan(T.budget), :);

for i = 1:width(T)
    varName = T.Properties.VariableNames{i};
    if iscell(T.(varName)) && ~strcmp(varName, 'project')
        T.(varName) = str2double(strrep(T.(varName), ',', ''));
    end
end

numericVars = T.Properties.VariableNames(vartype('numeric'));
for i = 1:length(numericVars)
    varName = numericVars{i};
    colMedian = median(T.(varName), 'omitnan');
    T.(varName) = fillmissing(T.(varName), 'constant', colMedian);
end
disp("Data cleaning and type conversion complete.");

% =============================================================================
% Section 3: Enhanced Feature Engineering
% =============================================================================
disp(newline + "--- Section 3: Feature Engineering ---");

T.budget_log = log1p(T.budget);
T_clean = T(T.budget > 100000, :);

% Extract building scale indicators from project name
tokens_sty = regexp(T_clean.project, '(\d+)\s*STY', 'tokens');
tokens_cl = regexp(T_clean.project, '(\d+)\s*CL', 'tokens');
T_clean.num_storeys = nan(height(T_clean), 1);
T_clean.num_classrooms = nan(height(T_clean), 1);
for i = 1:height(T_clean)
    if ~isempty(tokens_sty{i}); T_clean.num_storeys(i) = str2double(tokens_sty{i}{1}); end
    if ~isempty(tokens_cl{i}); T_clean.num_classrooms(i) = str2double(tokens_cl{i}{1}); end
end

vars_to_fill = {'num_storeys', 'num_classrooms'};
for i = 1:length(vars_to_fill)
    varName = vars_to_fill{i};
    impute_val = round(mean(T_clean.(varName), 'omitnan'));
    T_clean.(varName) = fillmissing(T_clean.(varName), 'constant', impute_val);
end

all_vars = T_clean.Properties.VariableNames;

% Locate critical structural quantity columns
formworks_col = locateSingleColumn(all_vars, 'formworks', 'formworks area');
grade40_col = locateSingleColumn(all_vars, 'grade40', 'Grade 40 reinforcing steel');
grade60_col = locateSingleColumn(all_vars, 'grade60', 'Grade 60 reinforcing steel');

floor_area_cols = all_vars(contains(all_vars, 'grossfloorarea'));
if isempty(floor_area_cols)
    error('Unable to locate any gross floor area columns.');
end

concrete_cols = all_vars(contains(all_vars, 'volumeofstructuralconcrete'));
if isempty(concrete_cols)
    error('Unable to locate any structural concrete volume columns.');
end

T_clean.total_gross_floor_area = sum(T_clean{:, floor_area_cols}, 2);
T_clean.total_concrete_volume = sum(T_clean{:, concrete_cols}, 2);
T_clean.total_reinforcing_steel = T_clean.(grade40_col) + T_clean.(grade60_col);

T_clean.concrete_per_floor_area = T_clean.total_concrete_volume ./ T_clean.total_gross_floor_area;
T_clean.steel_per_concrete = T_clean.total_reinforcing_steel ./ T_clean.total_concrete_volume;

ratio_fields = {'concrete_per_floor_area', 'steel_per_concrete'};
for i = 1:numel(ratio_fields)
    field = ratio_fields{i};
    mask = isinf(T_clean.(field)) | isnan(T_clean.(field));
    T_clean.(field)(mask) = 0;
end

disp("Feature engineering complete.");

% =============================================================================
% Section 4: Generate and Analyze Interaction Features
% =============================================================================
disp(newline + "--- Section 4: Generating and Analyzing Interaction Features ---");

final_feature_columns = {
    'year', 'num_storeys', 'num_classrooms', ...
    'total_gross_floor_area', 'total_concrete_volume', 'total_reinforcing_steel', ...
    formworks_col, 'concrete_per_floor_area', 'steel_per_concrete'
};

X_final_features = T_clean(:, final_feature_columns);

[X_poly, poly_feature_names] = generatePolyFeatures(X_final_features, 2);
fprintf("Generated %d total polynomial features.\n", size(X_poly, 2));

% =============================================================================
% Section 5: Load Model and Calculate Feature Importance
% =============================================================================
disp(newline + "--- Section 5: Loading Model and Calculating Importance ---");
try
    load('structural_model_assets.mat', 'optimized_model', 'selected_mask', 'poly_feature_names');
    disp("Loaded 'structural_model_assets.mat' successfully.");
catch ME
    error("Could not load 'structural_model_assets.mat'. Make sure the main script has been run. (%s)", ME.message);
end

importances_selected = predictorImportance(optimized_model);
full_importances = zeros(length(poly_feature_names), 1);
if numel(selected_mask) ~= numel(poly_feature_names)
    error('Mismatch between selected_mask and poly_feature_names lengths.');
end
full_importances(selected_mask) = importances_selected;

total_importance = sum(full_importances);
if total_importance == 0
    warning('Feature importances sum to zero; importance percentages set to zero.');
    importance_percentage = zeros(size(full_importances));
else
    importance_percentage = (full_importances / total_importance) * 100;
end
disp("Calculated and normalized feature importances.");

% =============================================================================
% Section 6: Calculate Percentiles and Display Results in Command Window
% =============================================================================
disp(newline + "--- Section 6: Calculating Percentiles and Displaying Results ---");

percentiles_to_calc = [0, 25, 50, 75, 100];
percentile_data = prctile(X_poly, percentiles_to_calc);

feature_names = string(poly_feature_names(:));
results_table = table( ...
    feature_names, ...
    percentile_data(1, :)', ...
    percentile_data(2, :)', ...
    percentile_data(3, :)', ...
    percentile_data(4, :)', ...
    percentile_data(5, :)', ...
    importance_percentage(:), ...
    'VariableNames', {'FeatureName', 'Min', 'Pctl25', 'Median', 'Pctl75', 'Max', 'ImportancePct'});

fprintf('\n\n--- Numerical Analysis of Structural Model Features ---\n');
fprintf('%-50s %12s %12s %12s %12s %12s %15s\n', ...
    'Feature Name', 'Min', '25th Pctl', 'Median', '75th Pctl', 'Max', 'Importance (%)');
fprintf([repmat('-', 1, 130) '\n']);

for i = 1:length(poly_feature_names)
    fprintf('%-50s %12.2e %12.2e %12.2e %12.2e %12.2e %15.2f\n', ...
        poly_feature_names{i}, ...
        percentile_data(1, i), ...
        percentile_data(2, i), ...
        percentile_data(3, i), ...
        percentile_data(4, i), ...
        percentile_data(5, i), ...
        importance_percentage(i));
end

output_filename = 'structural_feature_percentiles.csv';
writetable(results_table, output_filename);
fprintf("Saved feature percentiles and importances to '%s'.\n", output_filename);

disp(newline + "Process finished.");

% =============================================================================
% Helper Function
% =============================================================================
function colName = locateSingleColumn(allVars, pattern, label)
    matches = allVars(contains(allVars, pattern));
    if isempty(matches)
        error('Unable to locate column for %s (pattern: %s).', label, pattern);
    end
    if numel(matches) > 1
        warning('Multiple columns match %s (pattern: %s). Using the first match: %s.', label, pattern, matches{1});
    end
    colName = matches{1};
end
