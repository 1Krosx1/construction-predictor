classdef ArchBudgetPredictorProgrammatic < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure                     matlab.ui.Figure
        Grid                        matlab.ui.container.GridLayout
        TitleLabel                  matlab.ui.control.Label
        YearDropdown                matlab.ui.control.DropDown
        NumStoreysSpinner           matlab.ui.control.Spinner
        NumClassroomsSpinner        matlab.ui.control.Spinner
        QuantityOfPlasterField      matlab.ui.control.NumericEditField
        QuantityOfGlazedTilesField  matlab.ui.control.NumericEditField
        TotalPaintingAreaField      matlab.ui.control.NumericEditField
        TotalCHBAreaField          matlab.ui.control.NumericEditField
        TotalFinishesAreaField     matlab.ui.control.NumericEditField
        PlasterPerCHBField         matlab.ui.control.NumericEditField
        TilesPerCHBField           matlab.ui.control.NumericEditField
        LoadDefaultsButton          matlab.ui.control.Button
        ResetButton                 matlab.ui.control.Button
        PredictButton               matlab.ui.control.Button
        PredictedValueLabel         matlab.ui.control.Label
        StatusLabel                 matlab.ui.control.Label
        % StatsTable removed per user request
    end

    properties (Access = private)
        modelAssets
        rawFeatureNames
        medians
        ranges
    end

    methods (Access = private)

        function createComponents(app)
    % UIFigure
    app.UIFigure = uifigure('Name','ArchBudgetPredictor','Position',[100 100 1280 720]);
    app.UIFigure.Color = [0.95 0.97 1];  % Soft light blue-gray background
        % Grid layout - 4 columns for parameters, each param gets label+input
        app.Grid = uigridlayout(app.UIFigure,[8,4]);
        app.Grid.RowHeight = {'fit','fit','fit','fit','fit','fit','1x','fit'};
        % Equal column widths for balanced parameter layout
        app.Grid.ColumnWidth = {'1x','1x','1x','1x'};
        app.Grid.Padding = [20 20 20 20];
        app.Grid.RowSpacing = 10;
        app.Grid.ColumnSpacing = 10;
        app.Grid.BackgroundColor = [0.95 0.97 1];  % Match UIFigure background

    % Title
    app.TitleLabel = uilabel(app.Grid);
    app.TitleLabel.Text = 'Archi Budget Predictor CTM 5 - DLSU';
    app.TitleLabel.FontSize = 18;
    app.TitleLabel.FontWeight = 'bold';
    app.TitleLabel.FontColor = [0 0 0];
    app.TitleLabel.Layout.Row = 1;
    app.TitleLabel.Layout.Column = [1 4];
    app.TitleLabel.HorizontalAlignment = 'center';
    
    % Row 2 - PARAM 1 (Year), PARAM 6 (Total CHB)
    pGrid1 = uigridlayout(app.Grid,[2,1]);
    pGrid1.Layout.Row = 2; pGrid1.Layout.Column = 1;
    pGrid1.RowHeight = {'fit','1x'}; pGrid1.Padding = [8 8 8 8];
    pGrid1.BackgroundColor = [0.94 0.94 0.96];
    lbl = uilabel(pGrid1,'Text','Year (YYYY)','HorizontalAlignment','center','FontWeight','bold');
    lbl.Layout.Row = 1; lbl.Layout.Column = 1;
    lbl.BackgroundColor = [0.94 0.94 0.96];
    lbl.FontColor = [0 0 0];
    years = arrayfun(@num2str,2000:2028,'UniformOutput',false);
    app.YearDropdown = uidropdown(pGrid1,'Items',years,'Value','2024');
    app.YearDropdown.Layout.Row = 2; app.YearDropdown.Layout.Column = 1;
    app.YearDropdown.BackgroundColor = [1 1 1];
    app.YearDropdown.FontColor = [0 0 0];

    pGrid6 = uigridlayout(app.Grid,[2,1]);
    pGrid6.Layout.Row = 2; pGrid6.Layout.Column = 3;
    pGrid6.RowHeight = {'fit','1x'}; pGrid6.Padding = [8 8 8 8];
    pGrid6.BackgroundColor = [0.94 0.94 0.96];
    lbl = uilabel(pGrid6,'Text','Total CHB area (sq.m.)','HorizontalAlignment','center','FontWeight','bold');
    lbl.Layout.Row = 1; lbl.Layout.Column = 1;
    lbl.BackgroundColor = [0.94 0.94 0.96];
    lbl.FontColor = [0 0 0];
    app.TotalCHBAreaField = uieditfield(pGrid6,'numeric','Value',34000);
    app.TotalCHBAreaField.Layout.Row = 2; app.TotalCHBAreaField.Layout.Column = 1;
    app.TotalCHBAreaField.BackgroundColor = [1 1 1];
    app.TotalCHBAreaField.FontColor = [0 0 0];
    try, app.TotalCHBAreaField.ValueDisplayFormat = '%.2f'; end

    % Row 3 - PARAM 2 (Num classrooms), PARAM 7 (Total finishes)
    pGrid2 = uigridlayout(app.Grid,[2,1]);
    pGrid2.Layout.Row = 3; pGrid2.Layout.Column = 1;
    pGrid2.RowHeight = {'fit','1x'}; pGrid2.Padding = [8 8 8 8];
    pGrid2.BackgroundColor = [0.94 0.94 0.96];
    lbl = uilabel(pGrid2,'Text','Num classrooms','HorizontalAlignment','center','FontWeight','bold');
    lbl.Layout.Row = 1; lbl.Layout.Column = 1;
    lbl.BackgroundColor = [0.94 0.94 0.96];
    lbl.FontColor = [0 0 0];
    app.NumClassroomsSpinner = uispinner(pGrid2,'Limits',[0 200],'Step',1,'RoundFractionalValues',true,'Value',4);
    app.NumClassroomsSpinner.Layout.Row = 2; app.NumClassroomsSpinner.Layout.Column = 1;
    app.NumClassroomsSpinner.ValueDisplayFormat = '%.0f';
    app.NumClassroomsSpinner.BackgroundColor = [1 1 1];
    app.NumClassroomsSpinner.FontColor = [0 0 0];
    
    pGrid7 = uigridlayout(app.Grid,[2,1]);
    pGrid7.Layout.Row = 3; pGrid7.Layout.Column = 3;
    pGrid7.RowHeight = {'fit','1x'}; pGrid7.Padding = [8 8 8 8];
    pGrid7.BackgroundColor = [0.94 0.94 0.96];
    lbl = uilabel(pGrid7,'Text','Total finishes area (sq.m.)','HorizontalAlignment','center','FontWeight','bold');
    lbl.Layout.Row = 1; lbl.Layout.Column = 1;
    lbl.BackgroundColor = [0.94 0.94 0.96];
    lbl.FontColor = [0 0 0];
    app.TotalFinishesAreaField = uieditfield(pGrid7,'numeric','Value',21000);
    app.TotalFinishesAreaField.Layout.Row = 2; app.TotalFinishesAreaField.Layout.Column = 1;
    app.TotalFinishesAreaField.BackgroundColor = [1 1 1];
    app.TotalFinishesAreaField.FontColor = [0 0 0];
    try, app.TotalFinishesAreaField.ValueDisplayFormat = '%.2f'; end

    % Row 4 - PARAM 3 (Num storeys), PARAM 8 (Plaster per CHB)
    pGrid3 = uigridlayout(app.Grid,[2,1]);
    pGrid3.Layout.Row = 4; pGrid3.Layout.Column = 1;
    pGrid3.RowHeight = {'fit','1x'}; pGrid3.Padding = [8 8 8 8];
    pGrid3.BackgroundColor = [0.94 0.94 0.96];
    lbl = uilabel(pGrid3,'Text','Num storeys','HorizontalAlignment','center','FontWeight','bold');
    lbl.Layout.Row = 1; lbl.Layout.Column = 1;
    lbl.BackgroundColor = [0.94 0.94 0.96];
    lbl.FontColor = [0 0 0];
    app.NumStoreysSpinner = uispinner(pGrid3,'Limits',[0 50],'Step',1,'RoundFractionalValues',true,'Value',2);
    app.NumStoreysSpinner.Layout.Row = 2; app.NumStoreysSpinner.Layout.Column = 1;
    app.NumStoreysSpinner.ValueDisplayFormat = '%.0f';
    app.NumStoreysSpinner.BackgroundColor = [1 1 1];
    app.NumStoreysSpinner.FontColor = [0 0 0];
    
    pGrid8 = uigridlayout(app.Grid,[2,1]);
    pGrid8.Layout.Row = 4; pGrid8.Layout.Column = 3;
    pGrid8.RowHeight = {'fit','1x'}; pGrid8.Padding = [8 8 8 8];
    pGrid8.BackgroundColor = [0.94 0.94 0.96];
    lbl = uilabel(pGrid8,'Text','Quantity per CHB (plaster)','HorizontalAlignment','center','FontWeight','bold');
    lbl.Layout.Row = 1; lbl.Layout.Column = 1;
    lbl.BackgroundColor = [0.94 0.94 0.96];
    lbl.FontColor = [0 0 0];
    app.PlasterPerCHBField = uieditfield(pGrid8,'numeric','Value',0.3);
    app.PlasterPerCHBField.Layout.Row = 2; app.PlasterPerCHBField.Layout.Column = 1;
    app.PlasterPerCHBField.BackgroundColor = [1 1 1];
    app.PlasterPerCHBField.FontColor = [0 0 0];
    try, app.PlasterPerCHBField.ValueDisplayFormat = '%.3f'; end

    % Row 5 - PARAM 4 (Total Wall Area), PARAM 9 (Tiles per CHB)
    pGrid4 = uigridlayout(app.Grid,[2,1]);
    pGrid4.Layout.Row = 5; pGrid4.Layout.Column = 1;
    pGrid4.RowHeight = {'fit','1x'}; pGrid4.Padding = [8 8 8 8];
    pGrid4.BackgroundColor = [0.94 0.94 0.96];
    lbl = uilabel(pGrid4,'Text','Total Wall Area (sq.m.)','HorizontalAlignment','center','FontWeight','bold');
    lbl.Layout.Row = 1; lbl.Layout.Column = 1;
    lbl.BackgroundColor = [0.94 0.94 0.96];
    lbl.FontColor = [0 0 0];
    app.QuantityOfPlasterField = uieditfield(pGrid4,'numeric','Value',1000);
    app.QuantityOfPlasterField.Layout.Row = 2; app.QuantityOfPlasterField.Layout.Column = 1;
    app.QuantityOfPlasterField.BackgroundColor = [1 1 1];
    app.QuantityOfPlasterField.FontColor = [0 0 0];
    try, app.QuantityOfPlasterField.ValueDisplayFormat = '%.2f'; end
    
    pGrid9 = uigridlayout(app.Grid,[2,1]);
    pGrid9.Layout.Row = 5; pGrid9.Layout.Column = 3;
    pGrid9.RowHeight = {'fit','1x'}; pGrid9.Padding = [8 8 8 8];
    pGrid9.BackgroundColor = [0.94 0.94 0.96];
    lbl = uilabel(pGrid9,'Text','Tiles per CHB (ratio)','HorizontalAlignment','center','FontWeight','bold');
    lbl.Layout.Row = 1; lbl.Layout.Column = 1;
    lbl.BackgroundColor = [0.94 0.94 0.96];
    lbl.FontColor = [0 0 0];
    app.TilesPerCHBField = uieditfield(pGrid9,'numeric','Value',0.06);
    app.TilesPerCHBField.Layout.Row = 2; app.TilesPerCHBField.Layout.Column = 1;
    app.TilesPerCHBField.BackgroundColor = [1 1 1];
    app.TilesPerCHBField.FontColor = [0 0 0];
    try, app.TilesPerCHBField.ValueDisplayFormat = '%.3f'; end

    % Row 6 - PARAM 5 (Quantity glazed tiles), PARAM 10 (Total painting)
    pGrid5 = uigridlayout(app.Grid,[2,1]);
    pGrid5.Layout.Row = 6; pGrid5.Layout.Column = 1;
    pGrid5.RowHeight = {'fit','1x'}; pGrid5.Padding = [8 8 8 8];
    pGrid5.BackgroundColor = [0.94 0.94 0.96];
    lbl = uilabel(pGrid5,'Text','Quantity glazed tiles (sq.m.)','HorizontalAlignment','center','FontWeight','bold');
    lbl.Layout.Row = 1; lbl.Layout.Column = 1;
    lbl.BackgroundColor = [0.94 0.94 0.96];
    lbl.FontColor = [0 0 0];
    app.QuantityOfGlazedTilesField = uieditfield(pGrid5,'numeric','Value',2300);
    app.QuantityOfGlazedTilesField.Layout.Row = 2; app.QuantityOfGlazedTilesField.Layout.Column = 1;
    app.QuantityOfGlazedTilesField.BackgroundColor = [1 1 1];
    app.QuantityOfGlazedTilesField.FontColor = [0 0 0];
    try, app.QuantityOfGlazedTilesField.ValueDisplayFormat = '%.2f'; end
    
    pGrid10 = uigridlayout(app.Grid,[2,1]);
    pGrid10.Layout.Row = 6; pGrid10.Layout.Column = 3;
    pGrid10.RowHeight = {'fit','1x'}; pGrid10.Padding = [8 8 8 8];
    pGrid10.BackgroundColor = [0.94 0.94 0.96];
    lbl = uilabel(pGrid10,'Text','Total painting area (sq.m.)','HorizontalAlignment','center','FontWeight','bold');
    lbl.Layout.Row = 1; lbl.Layout.Column = 1;
    lbl.BackgroundColor = [0.94 0.94 0.96];
    lbl.FontColor = [0 0 0];
    app.TotalPaintingAreaField = uieditfield(pGrid10,'numeric','Value',25000);
    app.TotalPaintingAreaField.Layout.Row = 2; app.TotalPaintingAreaField.Layout.Column = 1;
    app.TotalPaintingAreaField.BackgroundColor = [1 1 1];
    app.TotalPaintingAreaField.FontColor = [0 0 0];
    try, app.TotalPaintingAreaField.ValueDisplayFormat = '%.2f'; end

    % Estimated Budget area: centered panel with green border
    panel = uipanel(app.Grid);
    panel.Title = 'Estimated Budget:';
    panel.Layout.Row = 7;
    panel.Layout.Column = [1 4];
    panel.FontSize = 16;
    panel.FontWeight = 'bold';
    try
        panel.BorderWidth = 4;
        panel.BorderColor = [0 0.7 0.2];
        panel.BackgroundColor = [1 1 1];
    catch
    end
    
    % inner grid for centering the budget amount
    pgl = uigridlayout(panel,[1,3]);
    pgl.ColumnWidth = {'1x','fit','1x'};
    pgl.Padding = [20 20 20 20];
    pgl.BackgroundColor = [1 1 1];  % White background for inner grid
    
    % Single centered label for budget amount (large black text)
    app.PredictedValueLabel = uilabel(pgl,'Text','500,000.00');
    app.PredictedValueLabel.FontSize = 48;
    app.PredictedValueLabel.FontWeight = 'bold';
    app.PredictedValueLabel.HorizontalAlignment = 'center';
    app.PredictedValueLabel.VerticalAlignment = 'center';
    app.PredictedValueLabel.Layout.Row = 1;
    app.PredictedValueLabel.Layout.Column = 2;
    try
        app.PredictedValueLabel.FontColor = [0 0 0];
        app.PredictedValueLabel.BackgroundColor = [1 1 1];
    catch
    end

    % Bottom controls: three buttons in the last row, right-aligned
    btnGrid = uigridlayout(app.Grid,[1,7]);
    btnGrid.Layout.Row = 8;
    btnGrid.Layout.Column = [1 4];
    btnGrid.ColumnWidth = {'1x','1x','1x','1x','fit','fit','fit'};
    btnGrid.Padding = [0 0 0 0];
    btnGrid.ColumnSpacing = 15;
    btnGrid.BackgroundColor = [1 1 1];  % White background for button area

    % Status label left-aligned
    app.StatusLabel = uilabel(btnGrid,'Text','Ready');
    app.StatusLabel.Layout.Row = 1; app.StatusLabel.Layout.Column = 1;
    app.StatusLabel.FontColor = [0 0 0];
    app.StatusLabel.BackgroundColor = [1 1 1];
    
    app.LoadDefaultsButton = uibutton(btnGrid,'Text','Load default','ButtonPushedFcn',@(s,e)app.onLoadDefaults());
    app.LoadDefaultsButton.Layout.Row = 1; app.LoadDefaultsButton.Layout.Column = 5;
    app.LoadDefaultsButton.FontSize = 14;
    try, app.LoadDefaultsButton.BackgroundColor = [0.88 0.90 0.92]; app.LoadDefaultsButton.FontColor = [0 0 0]; end

    app.ResetButton = uibutton(btnGrid,'Text','RESET','ButtonPushedFcn',@(s,e)app.onReset());
    app.ResetButton.Layout.Row = 1; app.ResetButton.Layout.Column = 6;
    app.ResetButton.FontSize = 16;
    try, app.ResetButton.BackgroundColor = [0.88 0.90 0.92]; app.ResetButton.FontColor = [0 0 0]; end

    % Primary action: ESTIMATE (vibrant green with better shade)
    app.PredictButton = uibutton(btnGrid,'Text','ESTIMATE','ButtonPushedFcn',@(s,e)app.onPredict());
    app.PredictButton.Layout.Row = 1; app.PredictButton.Layout.Column = 7;
    app.PredictButton.FontSize = 16;
    app.PredictButton.FontWeight = 'bold';
    try
        app.PredictButton.BackgroundColor = [0.18 0.75 0.45];
        app.PredictButton.FontColor = [1 1 1];
    catch
    end
end

        function onLoadDefaults(app)
            if isempty(app.medians)
                app.StatusLabel.Text = 'No medians available.';
                return;
            end
            f = matlab.lang.makeValidName('year');
            if isfield(app.medians,f), app.YearDropdown.Value = num2str(round(app.medians.(f))); end
            f = matlab.lang.makeValidName('num_storeys');
            if isfield(app.medians,f), app.NumStoreysSpinner.Value = round(app.medians.(f)); end
            f = matlab.lang.makeValidName('num_classrooms');
            if isfield(app.medians,f), app.NumClassroomsSpinner.Value = round(app.medians.(f)); end
            f = matlab.lang.makeValidName('quantityofplaster_sq_m__');
            if isfield(app.medians,f), app.QuantityOfPlasterField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('quantityofglazedtiles_sq_m__');
            if isfield(app.medians,f), app.QuantityOfGlazedTilesField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('total_painting_area');
            if isfield(app.medians,f), app.TotalPaintingAreaField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('total_chb_area');
            if isfield(app.medians,f), app.TotalCHBAreaField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('total_finishes_area');
            if isfield(app.medians,f), app.TotalFinishesAreaField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('plaster_per_chb');
            if isfield(app.medians,f), app.PlasterPerCHBField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('tiles_per_chb');
            if isfield(app.medians,f), app.TilesPerCHBField.Value = app.medians.(f); end
            app.StatusLabel.Text = 'Defaults loaded.';
        end

        function onPredict(app)
    fprintf('--- Starting Prediction ---\n');

    % Convert year dropdown selection to numeric
    yr = str2double(app.YearDropdown.Value);

    % Build the canonical values vector in the order THIS app uses
    vals_app = [yr, ...
                app.NumStoreysSpinner.Value, ...
                app.NumClassroomsSpinner.Value, ...
                app.QuantityOfPlasterField.Value, ...        % ensure name matches properties
                app.QuantityOfGlazedTilesField.Value, ...
                app.TotalPaintingAreaField.Value, ...
                app.TotalCHBAreaField.Value, ...
                app.TotalFinishesAreaField.Value, ...
                app.PlasterPerCHBField.Value, ...
                app.TilesPerCHBField.Value];

    fprintf('Input values being passed to run_model_test (app ordering):\n');
    disp(vals_app);

    try
        % Determine expected feature length from loaded model assets (if present)
        expected = [];
        if ~isempty(app.modelAssets) && isfield(app.modelAssets,'final_feature_columns')
            expected = numel(app.modelAssets.final_feature_columns);
            fprintf('Model expects %d features (from model_assets.final_feature_columns).\n', expected);
        end

        % If model didn't provide expected length, try to infer from run_model_test by calling
        % a safe wrapper or assume length of current vector (fallback)
        if isempty(expected)
            expected = numel(vals_app); % fallback to what this UI sends
            fprintf('No feature list in model assets; using app feature count = %d.\n', expected);
        end

        % Adjust vals to match expected length (pad with zeros if short, trim if long)
        if numel(vals_app) < expected
            fprintf('Warning: app has %d features but model expects %d. Padding with zeros.\n', numel(vals_app), expected);
            vals = [vals_app, zeros(1, expected - numel(vals_app))];
        elseif numel(vals_app) > expected
            fprintf('Warning: app has %d features but model expects %d. Trimming extra features.\n', numel(vals_app), expected);
            vals = vals_app(1:expected);
        else
            vals = vals_app;
        end

        % show final vector
        fprintf('Final feature vector passed to run_model_test:\n'); disp(vals);

        % Safely call run_model_test (assumes it accepts a numeric row vector)
        appPath = fileparts(mfilename('fullpath'));
        modelTestPath = fullfile(appPath, 'run_model_test.m');
        if ~exist(modelTestPath, 'file')
            error('run_model_test.m not found in the application directory: %s', appPath);
        end
        addpath(appPath);
        [pred, details] = run_model_test(vals);
        rmpath(appPath);

        fprintf('Prediction successful.\n');
        fprintf('Predicted budget: %.2f\n', pred);

        if exist('details','var') && isstruct(details)
            fprintf('Model run details:\n'); disp(details);
        end

        formatted = app.formatCurrency(pred,'');
        app.PredictedValueLabel.Text = formatted;
        app.StatusLabel.Text = 'Prediction successful.';
        fprintf('--- Prediction Finished Successfully ---\n');

    catch ME
        if exist('appPath','var'), rmpath(appPath); end
        fprintf('!!! PREDICTION ERROR !!!\n');
        fprintf('Error message: %s\n', ME.message);
        fprintf('Error identifier: %s\n', ME.identifier);
        fprintf('Error stack trace:\n');
        for i = 1:length(ME.stack)
            fprintf('File: %s, Name: %s, Line: %d\n', ME.stack(i).file, ME.stack(i).name, ME.stack(i).line);
        end
        app.StatusLabel.Text = ['Predict error: ' ME.message];
        fprintf('--- Prediction Finished with Error ---\n');
    end
end

        function onReset(app)
            app.YearDropdown.Value = '2024';
            app.NumStoreysSpinner.Value = 2;
            app.NumClassroomsSpinner.Value = 4;
            app.QuantityOfPlasterField.Value = 1000;
            app.QuantityOfGlazedTilesField.Value = 2300;
            app.TotalPaintingAreaField.Value = 25000;
            app.TotalCHBAreaField.Value = 34000;
            app.TotalFinishesAreaField.Value = 21000;
            app.PlasterPerCHBField.Value = 0.3;
            app.TilesPerCHBField.Value = 0.06;
            app.PredictedValueLabel.Text = '0.00';
            app.StatusLabel.Text = 'Reset to defaults.';
        end

        function loadAssets(app)
            % Load model_assets and medians if present
            assetsFile = fullfile(pwd,'architectural_model_assets.mat');
            app.medians = [];
            app.ranges = [];
            if exist(assetsFile,'file')
                S = load(assetsFile);
                if isfield(S,'final_feature_columns')
                    % normalize saved feature names to lower valid names for matching
                    app.rawFeatureNames = cellfun(@(c) lower(matlab.lang.makeValidName(c)), S.final_feature_columns, 'UniformOutput', false);
                end
                app.modelAssets = S;
            end
            csvFile = fullfile(pwd,'Architectural_Total_Cost.csv');
            if exist(csvFile,'file')
                opts = detectImportOptions(csvFile); opts.VariableNamingRule='preserve';
                T = readtable(csvFile,opts);
                % normalize table variable names to lower valid names so they match app.rawFeatureNames
                T.Properties.VariableNames = cellfun(@(c) lower(matlab.lang.makeValidName(c)), T.Properties.VariableNames, 'UniformOutput', false);
                app.medians = struct();
                app.ranges = struct();
                for i = 1:numel(app.rawFeatureNames)
                    fn = app.rawFeatureNames{i}; % already normalized
                    if ismember(fn, T.Properties.VariableNames)
                        col = T.(fn); col = col(~isnan(col));
                        if ~isempty(col)
                            app.medians.(fn) = median(col);
                            app.ranges.(fn) = struct('min',min(col),'max',max(col));
                        end
                    end
                end
                % stats table removed — no UI population required
            end
        end

        function out = formatCurrency(app,val,prefix)
            if nargin<3, prefix = ''; end
            try
                if ~isnumeric(val) || isnan(val), out = [prefix '0.00']; return; end
                s = sprintf('%.2f',round(val*100)/100);
                parts = split(s,'.');
                intpart = parts{1}; decpart = parts{2};
                neg = startsWith(intpart,'-');
                if neg, intpart = intpart(2:end); end
                C = '';
                while numel(intpart) > 3
                    C = [',' intpart(end-2:end) C];
                    intpart(end-2:end) = [];
                end
                C = [intpart C];
                if neg, C = ['-' C]; end
                out = [prefix C '.' decpart];
            catch
                out = [prefix num2str(val)];
            end
        end

        % (Removed onBudgetFrameResized) panel uses nested uigridlayout so manual
        % resizing callback is not required; the nested grid will keep the label
        % centered and sized automatically across MATLAB versions.
    end

    methods (Access = public)

        % Construct app
        function app = ArchBudgetPredictorProgrammatic()
            createComponents(app)
            app.loadAssets();
            app.onLoadDefaults();
        end

        % Code that executes before app deletion
        function delete(app)
            if isvalid(app.UIFigure), delete(app.UIFigure); end
        end
    end
end