function [pred_budget, details] = run_model_test(input_row)
% RUN_MODEL_TEST Run the saved architectural model on a single input row.
%   [pred_budget, details] = run_model_test(input_row)
%
% input_row can be:
% - a 1xN table with the same raw columns used in the pipeline (project, year, ...), or
% - a struct with field names matching the cleaned column names (case-insensitive).
%
% The function loads 'architectural_model_assets.mat' (created by main.m)
% and uses the saved preprocessing assets (mu, sigma, selected_mask,
% final_feature_columns, poly_feature_names, optimized_model) to compute a
% prediction for the budget (returns the predicted budget in original scale).

    if nargin == 0
        error('Please provide a single input row (table, struct, or numeric vector).');
    end

    % Load model assets
    assets_file = fullfile(pwd, 'architectural_model_assets.mat');
    if ~isfile(assets_file)
        error("architectural_model_assets.mat not found in current folder. Run main.m first to produce it.");
    end
    S = load(assets_file, 'mu', 'sigma', 'selected_mask', 'final_feature_columns', 'poly_feature_names', 'optimized_model');
    if ~isfield(S, 'optimized_model')
        error('optimized_model not found inside architectural_model_assets.mat');
    end

    mu = S.mu; sigma = S.sigma; selected_mask = S.selected_mask;
    final_feature_columns = S.final_feature_columns;
    saved_poly_names = S.poly_feature_names;
    model = S.optimized_model;

    % Prepare input as table with required raw features
    if istable(input_row)
        Trow = input_row;
    elseif isstruct(input_row)
        Trow = struct2table(input_row);
    elseif isnumeric(input_row)
        % numeric vector assumed to be raw features in the same order as final_feature_columns
        v = input_row(:)'; % ensure row
        if numel(v) ~= numel(final_feature_columns)
            error('Numeric input must have %d elements matching final_feature_columns.', numel(final_feature_columns));
        end
        % Create table using the final feature column names (assumed to be valid variable names)
        try
            Trow = array2table(v, 'VariableNames', final_feature_columns);
        catch
            % Fall back to making valid names if necessary
            cleanNames = lower(matlab.lang.makeValidName(final_feature_columns));
            Trow = array2table(v, 'VariableNames', cleanNames);
        end
    else
        error('input_row must be a table, struct, or numeric vector.');
    end

    % Ensure column names are the same as used in training (lower-case/valid names)
    % main.m used matlab.lang.makeValidName and lower-case names; emulate that
    Trow.Properties.VariableNames = lower(matlab.lang.makeValidName(Trow.Properties.VariableNames));

    % Ensure the final raw features exist; if derived features missing, compute
    % Dynamically compute helper features if not present
    if ~all(ismember(final_feature_columns, Trow.Properties.VariableNames))
        % try to compute derived features used in main.m
        all_vars = Trow.Properties.VariableNames;
        % find likely raw column names based on substrings
        plaster_col_idx = find(contains(all_vars, 'plaster'), 1);
        tiles_col_idx = find(contains(all_vars, 'tiles'), 1);
        paint_masonry_idx = find(contains(all_vars, 'paintingmasonry'), 1);
        paint_wood_idx = find(contains(all_vars, 'paintingwood'), 1);
        paint_metal_idx = find(contains(all_vars, 'paintingmetal'), 1);
        chb100_idx = find(contains(all_vars, 'chb100mm'), 1);
        chb150_idx = find(contains(all_vars, 'chb150mm'), 1);

        try
            if ~ismember('total_painting_area', Trow.Properties.VariableNames) && ~isempty([paint_masonry_idx paint_wood_idx paint_metal_idx])
                Trow.total_painting_area = Trow{:, paint_masonry_idx} + Trow{:, paint_wood_idx} + Trow{:, paint_metal_idx};
            end
            if ~ismember('total_chb_area', Trow.Properties.VariableNames) && ~isempty([chb100_idx chb150_idx])
                Trow.total_chb_area = Trow{:, chb100_idx} + Trow{:, chb150_idx};
            end
            if ~ismember('total_finishes_area', Trow.Properties.VariableNames) && ~isempty([plaster_col_idx tiles_col_idx])
                Trow.total_finishes_area = Trow{:, plaster_col_idx} + Trow{:, tiles_col_idx};
            end
            if ~ismember('plaster_per_chb', Trow.Properties.VariableNames) && ismember('total_chb_area', Trow.Properties.VariableNames)
                Trow.plaster_per_chb = Trow{:, plaster_col_idx} ./ Trow.total_chb_area;
                Trow.plaster_per_chb(isinf(Trow.plaster_per_chb) | isnan(Trow.plaster_per_chb)) = 0;
            end
            if ~ismember('tiles_per_chb', Trow.Properties.VariableNames) && ismember('total_chb_area', Trow.Properties.VariableNames)
                Trow.tiles_per_chb = Trow{:, tiles_col_idx} ./ Trow.total_chb_area;
                Trow.tiles_per_chb(isinf(Trow.tiles_per_chb) | isnan(Trow.tiles_per_chb)) = 0;
            end
        catch
            warning('Could not auto-compute some derived features; ensure required raw columns exist.');
        end
    end

    % Verify required raw features now exist
    for i = 1:length(final_feature_columns)
        fname = final_feature_columns{i};
        if ~ismember(fname, Trow.Properties.VariableNames)
            error('Required feature ''%s'' is missing from the input. Provide it or compute derived features first.', fname);
        end
    end
    T_features = Trow(:, final_feature_columns);

    % Generate polynomial features (degree 2) consistent with training
    [X_poly_row, feature_names_row] = generatePolyFeatures(T_features, 2);

    % Map generated feature order to saved poly_feature_names (they should match)
    if ~isequal(feature_names_row, saved_poly_names)
        % try to align by name (safer if ordering differs)
        [~, idx_in_saved] = ismember(feature_names_row, saved_poly_names);
        if any(idx_in_saved == 0)
            error('Could not align generated polynomial feature names with saved names. Names mismatch.');
        end
        X_poly_row_aligned = X_poly_row(1, idx_in_saved);
    else
        X_poly_row_aligned = X_poly_row(1, :);
    end

    % Scale using saved mu and sigma
    X_scaled = (X_poly_row_aligned - mu) ./ sigma;
    X_scaled(isnan(X_scaled)) = 0;

    % Select features using saved mask
    X_selected = X_scaled(:, logical(selected_mask));

    % Predict (model expects row vector)
    log_pred = predict(model, X_selected);
    pred_budget = expm1(log_pred);

    details = struct();
    details.raw_features = T_features;
    details.poly_feature_names = saved_poly_names;
    details.poly_row = X_poly_row_aligned;
    details.selected_mask = selected_mask;
    details.selected_vector = X_selected;
    details.log_pred = log_pred;

    fprintf('Predicted budget: %.2f\n', pred_budget);
end
