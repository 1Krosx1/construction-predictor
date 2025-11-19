% =============================================================================
% Section 1: Setup Environment
% =============================================================================
clear; clc; close all;
disp('Environment cleared.');

% =============================================================================
% Section 2: Data Loading and Comprehensive Cleaning
% =============================================================================
disp(newline + "--- Section 2: Data Loading & Cleaning ---");
try
    % changed to Architectural dataset
    opts = detectImportOptions('C:\Users\User\Documents\MATLAB\Arch cost\Architectural_Total_Cost.csv');
    opts.VariableNamingRule = 'preserve';
    T = readtable('C:\Users\User\Documents\MATLAB\Arch cost\Architectural_Total_Cost.csv', opts);
    disp("Dataset 'Architectural_Total_Cost.csv' loaded successfully.");
catch ME
    error("Error loading 'Architectural_Total_Cost.csv'. Check file path and format. (%s)", ME.message);
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

% --- ROBUST DATA CLEANING AND TYPE CONVERSION ---
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

% --- ROBUST MISSING VALUE IMPUTATION ---
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

% Dynamically find column names (architectural)
plaster_col = all_vars{contains(all_vars, 'plaster') & ~contains(all_vars,'per')};
tiles_col = all_vars{contains(all_vars, 'glazedtiles')};
paint_masonry_col = all_vars{contains(all_vars, 'paintingmasonry')};
paint_wood_col = all_vars{contains(all_vars, 'paintingwood')};
paint_metal_col = all_vars{contains(all_vars, 'paintingmetal')};
chb100_col = all_vars{contains(all_vars, 'chb100')};
chb150_col = all_vars{contains(all_vars, 'chb150')};

% Create aggregated features (architectural)
T_clean.total_painting_area = T_clean.(paint_masonry_col) + T_clean.(paint_wood_col) + T_clean.(paint_metal_col);
T_clean.total_chb_area = T_clean.(chb100_col) + T_clean.(chb150_col);
T_clean.total_finishes_area = T_clean.(plaster_col) + T_clean.(tiles_col);

T_clean.plaster_per_chb = T_clean.(plaster_col) ./ T_clean.total_chb_area;
T_clean.tiles_per_chb = T_clean.(tiles_col) ./ T_clean.total_chb_area;

% Handle potential division by zero
T_clean.plaster_per_chb(isinf(T_clean.plaster_per_chb) | isnan(T_clean.plaster_per_chb)) = 0;
T_clean.tiles_per_chb(isinf(T_clean.tiles_per_chb) | isnan(T_clean.tiles_per_chb)) = 0;

disp("Feature engineering complete.");

% =============================================================================
% Section 4: Generate and Analyze Interaction Features
% =============================================================================
disp(newline + "--- Section 4: Generating and Analyzing Interaction Features ---");

final_feature_columns = { ...
    'year', 'num_storeys', 'num_classrooms', ...
    'quantityofplaster_sq_m__', 'quantityofglazedtiles_sq_m__', ...
    'total_painting_area', 'total_chb_area', 'total_finishes_area', ...
    'plaster_per_chb', 'tiles_per_chb'
};

X_final_features = T_clean(:, final_feature_columns);

% --- UPGRADE: Generate full polynomial features to match model training ---
[X_poly, poly_feature_names] = generatePolyFeatures(X_final_features, 2);
fprintf("Generated %d total polynomial features.\n", size(X_poly, 2));

% =============================================================================
% Section 5: Load Model and Calculate Feature Importance
% =============================================================================
disp(newline + "--- Section 5: Loading Model and Calculating Importance ---");
try
    % load architectural assets (was mepfs)
    load('C:\Users\User\Documents\MATLAB\Arch cost\architectural_model_assets.mat', 'optimized_model', 'selected_mask', 'poly_feature_names');
    disp("Loaded 'architectural_model_assets.mat' successfully.");
catch ME
    error("Could not load 'architectural_model_assets.mat'. Make sure the main script has been run. (%s)", ME.message);
end

% Get importances for the selected features from the optimized model
importances_selected = predictorImportance(optimized_model);

% Create a full importance vector, mapping selected importances back
full_importances = zeros(length(poly_feature_names), 1);
full_importances(selected_mask) = importances_selected;

% Normalize to get percentage while guarding against zero totals
total_importance = sum(full_importances);
if total_importance == 0
    warning("Feature importances sum to zero; importance percentages set to zero.");
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

% Prepare structured results for export
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

% --- Display Header in Command Window ---
fprintf('\n\n--- Numerical Analysis of Architectural Model Features ---\n');
fprintf('%-50s %12s %12s %12s %12s %12s %15s\n', ...
    'Feature Name', 'Min', '25th Pctl', 'Median', '75th Pctl', 'Max', 'Importance (%)');
fprintf([repmat('-', 1, 130) '\n']);

% --- Display Data for each feature ---
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

% Export results to CSV for downstream analysis
output_filename = 'architectural_feature_percentiles.csv';
writetable(results_table, output_filename);
fprintf("Saved feature percentiles and importances to '%s'.\n", output_filename);

disp(newline + "Process finished.");

