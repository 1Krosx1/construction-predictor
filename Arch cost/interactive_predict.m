function interactive_predict()
% INTERACTIVE_PREDICT Prompt user for raw feature values and run the model.
%   Shows units and typical ranges (min/median/max) inferred from
%   `Architectural_Total_Cost.csv` so you know what to input.

    assets_file = fullfile(pwd, 'architectural_model_assets.mat');
    if ~isfile(assets_file)
        error("architectural_model_assets.mat not found in the current folder. Run main.m to create it first.");
    end
    S = load(assets_file, 'final_feature_columns');
    if ~isfield(S, 'final_feature_columns')
        error('final_feature_columns not found in architectural_model_assets.mat');
    end
    raw_feats = S.final_feature_columns;

    % Try to load CSV to infer ranges and medians for helpful prompts
    stats = struct();
    csv_file = fullfile(pwd, 'Architectural_Total_Cost.csv');
    if isfile(csv_file)
        try
            opts = detectImportOptions(csv_file);
            opts.VariableNamingRule = 'preserve';
            Tcsv = readtable(csv_file, opts);
            Tcsv.Properties.VariableNames = lower(matlab.lang.makeValidName(Tcsv.Properties.VariableNames));
        catch
            Tcsv = table();
        end
    else
        Tcsv = table();
    end

    % Compute stats per feature where possible
    for i = 1:numel(raw_feats)
        fname = raw_feats{i};
        s = struct('hasData', false, 'min', [], 'median', [], 'max', []);
        if ~isempty(Tcsv) && ismember(fname, Tcsv.Properties.VariableNames)
            col = Tcsv.(fname);
            if ~isnumeric(col)
                % attempt conversion
                col = str2double(strrep(string(col), ',', ''));
            end
            col = col(:);
            col = col(~isnan(col));
            if ~isempty(col)
                s.hasData = true;
                s.min = min(col);
                s.median = median(col);
                s.max = max(col);
            end
        end
        stats.(matlab.lang.makeValidName(fname)) = s;
    end

    fprintf('Interactive prediction helper. You will be prompted for %d features.\n', numel(raw_feats));
    vals = zeros(1, numel(raw_feats));

    for i = 1:numel(raw_feats)
        fname = raw_feats{i};

        % Determine unit/description heuristically
        lname = lower(fname);
        if contains(lname, 'year')
            unit = 'year (YYYY)';
        elseif contains(lname, {'num_', 'num', 'storey', 'classroom', 'class'})
            unit = 'count (integer)';
        elseif contains(lname, {'plaster','tile','tiles','painting','chb','area','finishes'})
            unit = 'square meters (sq.m.)';
        elseif contains(lname, 'per')
            unit = 'ratio (unitless)';
        else
            unit = 'number';
        end

        sname = matlab.lang.makeValidName(fname);
        s = stats.(sname);
        if s.hasData
            prompt = sprintf('%d) %s (%s) — typical: %.0f to %.0f (median: %.0f) = ', i, fname, unit, s.min, s.max, s.median);
        else
            prompt = sprintf('%d) %s (%s) = ', i, fname, unit);
        end

        while true
            user = input(prompt, 's');
            if isempty(user)
                fprintf('Empty input not allowed. Please enter a numeric value (or 0).\n');
                continue;
            end
            num = str2double(user);
            if isnan(num)
                fprintf('Invalid number. Try again.\n');
                continue;
            end
            vals(i) = num;
            break;
        end
    end

    % Call run_model_test with numeric vector
    try
        [pred_budget, details] = run_model_test(vals);
        fprintf('\nPredicted budget: %.2f\n', pred_budget);
    catch ME
        fprintf('Error running prediction:\n%s\n', getReport(ME));
    end
end
