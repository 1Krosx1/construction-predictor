classdef Arch_sample < matlab.apps.AppBase
    % ArchBudgetPredictorApp Programmatic App to predict architectural budget
    % Usage: run by typing `app = ArchBudgetPredictorApp;` in MATLAB command window.

    properties (Access = public)
        UIFigure                   matlab.ui.Figure
        GridLayout                 matlab.ui.container.GridLayout
        TitleLabel                 matlab.ui.control.Label
        YearSpinner               matlab.ui.control.Spinner
        YearLabel                 matlab.ui.control.Label
        NumStoreysSpinner         matlab.ui.control.Spinner
        NumStoreysLabel           matlab.ui.control.Label
        NumClassroomsSpinner      matlab.ui.control.Spinner
        NumClassroomsLabel        matlab.ui.control.Label
        QuantityOfPlasterField    matlab.ui.control.NumericEditField
        QuantityOfPlasterLabel    matlab.ui.control.Label
        QuantityOfGlazedTilesField matlab.ui.control.NumericEditField
        QuantityOfGlazedTilesLabel matlab.ui.control.Label
        TotalPaintingAreaField    matlab.ui.control.NumericEditField
        TotalPaintingAreaLabel    matlab.ui.control.Label
        TotalCHBAreaField         matlab.ui.control.NumericEditField
        TotalCHBAreaLabel         matlab.ui.control.Label
        TotalFinishesAreaField    matlab.ui.control.NumericEditField
        TotalFinishesAreaLabel    matlab.ui.control.Label
        PlasterPerCHBField        matlab.ui.control.NumericEditField
        PlasterPerCHBLabel        matlab.ui.control.Label
        TilesPerCHBField          matlab.ui.control.NumericEditField
        TilesPerCHBLabel          matlab.ui.control.Label
        LoadDefaultsButton        matlab.ui.control.Button
        PredictButton             matlab.ui.control.Button
        ResetButton               matlab.ui.control.Button
        PredictedLabel            matlab.ui.control.Label
        PredictedValueLabel       matlab.ui.control.Label
        StatusLabel               matlab.ui.control.Label
    end

    properties (Access = private)
        modelAssets struct
        medians struct
        ranges struct
        rawFeatureNames cell
    end

    methods (Access = private)
        function createComponents(app)
            % Create and configure components
            app.UIFigure = uifigure('Name','Arch Budget Predictor','Position',[200 200 720 520]);
            app.GridLayout = uigridlayout(app.UIFigure,[8,4]);
            app.GridLayout.RowHeight = {30,30,30,30,30,30,30,'1x'};
            app.GridLayout.ColumnWidth = {140, '1x', 140, '1x'};

            app.TitleLabel = uilabel(app.GridLayout);
            app.TitleLabel.Text = 'Architectural Budget Predictor';
            app.TitleLabel.FontSize = 16;
            app.TitleLabel.FontWeight = 'bold';
            app.TitleLabel.Layout.Row = 1;
            app.TitleLabel.Layout.Column = [1 4];

            % Row 2: Year and Num Storeys
            app.YearLabel = uilabel(app.GridLayout);
            app.YearLabel.Text = 'Year (YYYY)';
            app.YearLabel.Layout.Row = 2; app.YearLabel.Layout.Column = 1;
            app.YearSpinner = uispinner(app.GridLayout);
            app.YearSpinner.Limits = [2000 2025];
            app.YearSpinner.Value = 2024;
            app.YearSpinner.Step = 1;
            app.YearSpinner.RoundFractionalValues = true;
            app.YearSpinner.Layout.Row = 2; app.YearSpinner.Layout.Column = 2;

            app.NumStoreysLabel = uilabel(app.GridLayout);
            app.NumStoreysLabel.Text = 'Num storeys';
            app.NumStoreysLabel.Layout.Row = 2; app.NumStoreysLabel.Layout.Column = 3;
            app.NumStoreysSpinner = uispinner(app.GridLayout);
            app.NumStoreysSpinner.Limits = [0 20];
            app.NumStoreysSpinner.Value = 2;
            app.NumStoreysSpinner.Step = 1;
            app.NumStoreysSpinner.RoundFractionalValues = true;
            app.NumStoreysSpinner.Layout.Row = 2; app.NumStoreysSpinner.Layout.Column = 4;

            % Row 3: Num classrooms and plaster
            app.NumClassroomsLabel = uilabel(app.GridLayout);
            app.NumClassroomsLabel.Text = 'Num classrooms';
            app.NumClassroomsLabel.Layout.Row = 3; app.NumClassroomsLabel.Layout.Column = 1;
            app.NumClassroomsSpinner = uispinner(app.GridLayout);
            app.NumClassroomsSpinner.Limits = [0 200];
            app.NumClassroomsSpinner.Value = 4;
            app.NumClassroomsSpinner.Step = 1;
            app.NumClassroomsSpinner.RoundFractionalValues = true;
            app.NumClassroomsSpinner.Layout.Row = 3; app.NumClassroomsSpinner.Layout.Column = 2;

            app.QuantityOfPlasterLabel = uilabel(app.GridLayout);
            app.QuantityOfPlasterLabel.Text = 'Quantity of plaster (sq.m.)';
            app.QuantityOfPlasterLabel.Layout.Row = 3; app.QuantityOfPlasterLabel.Layout.Column = 3;
            app.QuantityOfPlasterField = uieditfield(app.GridLayout,'numeric');
            app.QuantityOfPlasterField.Value = 1000;
            app.QuantityOfPlasterField.Layout.Row = 3; app.QuantityOfPlasterField.Layout.Column = 4;

            % Row 4: glazed tiles and total painting
            app.QuantityOfGlazedTilesLabel = uilabel(app.GridLayout);
            app.QuantityOfGlazedTilesLabel.Text = 'Quantity of glazed tiles (sq.m.)';
            app.QuantityOfGlazedTilesLabel.Layout.Row = 4; app.QuantityOfGlazedTilesLabel.Layout.Column = 1;
            app.QuantityOfGlazedTilesField = uieditfield(app.GridLayout,'numeric');
            app.QuantityOfGlazedTilesField.Value = 2300;
            app.QuantityOfGlazedTilesField.Layout.Row = 4; app.QuantityOfGlazedTilesField.Layout.Column = 2;

            app.TotalPaintingAreaLabel = uilabel(app.GridLayout);
            app.TotalPaintingAreaLabel.Text = 'Total painting area (sq.m.)';
            app.TotalPaintingAreaLabel.Layout.Row = 4; app.TotalPaintingAreaLabel.Layout.Column = 3;
            app.TotalPaintingAreaField = uieditfield(app.GridLayout,'numeric');
            app.TotalPaintingAreaField.Value = 25000;
            app.TotalPaintingAreaField.Layout.Row = 4; app.TotalPaintingAreaField.Layout.Column = 4;

            % Row 5: total CHB and finishes
            app.TotalCHBAreaLabel = uilabel(app.GridLayout);
            app.TotalCHBAreaLabel.Text = 'Total CHB area (sq.m.)';
            app.TotalCHBAreaLabel.Layout.Row = 5; app.TotalCHBAreaLabel.Layout.Column = 1;
            app.TotalCHBAreaField = uieditfield(app.GridLayout,'numeric');
            app.TotalCHBAreaField.Value = 34000;
            app.TotalCHBAreaField.Layout.Row = 5; app.TotalCHBAreaField.Layout.Column = 2;

            app.TotalFinishesAreaLabel = uilabel(app.GridLayout);
            app.TotalFinishesAreaLabel.Text = 'Total finishes area (sq.m.)';
            app.TotalFinishesAreaLabel.Layout.Row = 5; app.TotalFinishesAreaLabel.Layout.Column = 3;
            app.TotalFinishesAreaField = uieditfield(app.GridLayout,'numeric');
            app.TotalFinishesAreaField.Value = 21000;
            app.TotalFinishesAreaField.Layout.Row = 5; app.TotalFinishesAreaField.Layout.Column = 4;

            % Row 6: ratios
            app.PlasterPerCHBLabel = uilabel(app.GridLayout);
            app.PlasterPerCHBLabel.Text = 'Plaster per CHB (sq.m./sq.m.)';
            app.PlasterPerCHBLabel.Layout.Row = 6; app.PlasterPerCHBLabel.Layout.Column = 1;
            app.PlasterPerCHBField = uieditfield(app.GridLayout,'numeric');
            app.PlasterPerCHBField.Value = 0.3;
            app.PlasterPerCHBField.Layout.Row = 6; app.PlasterPerCHBField.Layout.Column = 2;

            app.TilesPerCHBLabel = uilabel(app.GridLayout);
            app.TilesPerCHBLabel.Text = 'Tiles per CHB (sq.m./sq.m.)';
            app.TilesPerCHBLabel.Layout.Row = 6; app.TilesPerCHBLabel.Layout.Column = 3;
            app.TilesPerCHBField = uieditfield(app.GridLayout,'numeric');
            app.TilesPerCHBField.Value = 0.06;
            app.TilesPerCHBField.Layout.Row = 6; app.TilesPerCHBField.Layout.Column = 4;

            % Row 7: Buttons and prediction output
            app.LoadDefaultsButton = uibutton(app.GridLayout,'push');
            app.LoadDefaultsButton.Text = 'Load Defaults';
            app.LoadDefaultsButton.Layout.Row = 7; app.LoadDefaultsButton.Layout.Column = 1;
            app.LoadDefaultsButton.ButtonPushedFcn = @(~,~) app.onLoadDefaults();

            app.PredictButton = uibutton(app.GridLayout,'push');
            app.PredictButton.Text = 'Predict';
            app.PredictButton.Layout.Row = 7; app.PredictButton.Layout.Column = 2;
            app.PredictButton.ButtonPushedFcn = @(~,~) app.onPredict();

            app.ResetButton = uibutton(app.GridLayout,'push');
            app.ResetButton.Text = 'Reset';
            app.ResetButton.Layout.Row = 7; app.ResetButton.Layout.Column = 3;
            app.ResetButton.ButtonPushedFcn = @(~,~) app.onReset();

            app.PredictedLabel = uilabel(app.GridLayout);
            app.PredictedLabel.Text = 'Predicted Budget';
            app.PredictedLabel.Layout.Row = 7; app.PredictedLabel.Layout.Column = 4;

            app.PredictedValueLabel = uilabel(app.GridLayout);
            app.PredictedValueLabel.Text = '₱ 0.00';
            app.PredictedValueLabel.FontSize = 14;
            app.PredictedValueLabel.FontWeight = 'bold';
            app.PredictedValueLabel.Layout.Row = 8; app.PredictedValueLabel.Layout.Column = [1 4];

            app.StatusLabel = uilabel(app.GridLayout);
            app.StatusLabel.Text = '';
            app.StatusLabel.Layout.Row = 8; app.StatusLabel.Layout.Column = 4;
        end

        function loadModelAndMedians(app)
            % Load model assets
            assetsFile = fullfile(pwd, 'architectural_model_assets.mat');
            if exist(assetsFile,'file')
                S = load(assetsFile, 'final_feature_columns');
                app.rawFeatureNames = S.final_feature_columns;
                app.modelAssets = S;
            else
                app.rawFeatureNames = {};
                app.StatusLabel.Text = 'Warning: architectural_model_assets.mat not found.';
            end

            % Load CSV medians
            csvFile = fullfile(pwd, 'Architectural_Total_Cost.csv');
            app.medians = struct(); app.ranges = struct();
            if exist(csvFile,'file')
                opts = detectImportOptions(csvFile); opts.VariableNamingRule='preserve';
                T = readtable(csvFile, opts);
                T.Properties.VariableNames = lower(matlab.lang.makeValidName(T.Properties.VariableNames));
                % Map known fields
                map = { 'year', 'YearSpinner'; 'num_storeys','NumStoreysSpinner'; 'num_classrooms','NumClassroomsSpinner';
                        'quantityofplaster_sq_m__','QuantityOfPlasterField'; 'quantityofglazedtiles_sq_m__','QuantityOfGlazedTilesField';
                        'total_painting_area','TotalPaintingAreaField'; 'total_chb_area','TotalCHBAreaField'; 'total_finishes_area','TotalFinishesAreaField';
                        'plaster_per_chb','PlasterPerCHBField'; 'tiles_per_chb','TilesPerCHBField'};
                for i=1:size(map,1)
                    fn = map{i,1}; uiName = map{i,2};
                    if ismember(fn, T.Properties.VariableNames)
                        col = T.(fn);
                        if ~isnumeric(col), col = str2double(strrep(string(col),',','')); end
                        col = col(~isnan(col));
                        if ~isempty(col)
                            app.medians.(matlab.lang.makeValidName(fn)) = median(col);
                            app.ranges.(matlab.lang.makeValidName(fn)) = [min(col), max(col)];
                        end
                    end
                end
            end
        end

        function onLoadDefaults(app)
            % Populate UI with medians if available
            try
                if isfield(app.medians,'year'), app.YearSpinner.Value = round(app.medians.year); end
                if isfield(app.medians,'num_storeys'), app.NumStoreysSpinner.Value = round(app.medians.num_storeys); end
                if isfield(app.medians,'num_classrooms'), app.NumClassroomsSpinner.Value = round(app.medians.num_classrooms); end
                if isfield(app.medians,'quantityofplaster_sq_m__'), app.QuantityOfPlasterField.Value = app.medians.quantityofplaster_sq_m__; end
                if isfield(app.medians,'quantityofglazedtiles_sq_m__'), app.QuantityOfGlazedTilesField.Value = app.medians.quantityofglazedtiles_sq_m__; end
                if isfield(app.medians,'total_painting_area'), app.TotalPaintingAreaField.Value = app.medians.total_painting_area; end
                if isfield(app.medians,'total_chb_area'), app.TotalCHBAreaField.Value = app.medians.total_chb_area; end
                if isfield(app.medians,'total_finishes_area'), app.TotalFinishesAreaField.Value = app.medians.total_finishes_area; end
                if isfield(app.medians,'plaster_per_chb'), app.PlasterPerCHBField.Value = app.medians.plaster_per_chb; end
                if isfield(app.medians,'tiles_per_chb'), app.TilesPerCHBField.Value = app.medians.tiles_per_chb; end
                app.StatusLabel.Text = 'Defaults loaded.';
            catch ME
                app.StatusLabel.Text = ['Load defaults failed: ' ME.message];
            end
        end

        function onPredict(app)
            % Build numeric vector in the order used by training
            vals = zeros(1,10);
            vals(1) = app.YearSpinner.Value;
            vals(2) = app.NumStoreysSpinner.Value;
            vals(3) = app.NumClassroomsSpinner.Value;
            vals(4) = app.QuantityOfPlasterField.Value;
            vals(5) = app.QuantityOfGlazedTilesField.Value;
            vals(6) = app.TotalPaintingAreaField.Value;
            vals(7) = app.TotalCHBAreaField.Value;
            vals(8) = app.TotalFinishesAreaField.Value;
            vals(9) = app.PlasterPerCHBField.Value;
            vals(10)= app.TilesPerCHBField.Value;

            % Basic validation
            if any(isnan(vals))
                app.StatusLabel.Text = 'Please fill all numeric fields.';
                return;
            end

            try
                [pred, details] = run_model_test(vals);
                app.PredictedValueLabel.Text = sprintf('₱ %.2f', pred);
                app.StatusLabel.Text = 'Prediction successful.';
            catch ME
                app.StatusLabel.Text = ['Prediction failed: ' ME.message];
            end
        end

        function onReset(app)
            % Reset to sensible defaults
            app.YearSpinner.Value = 2024;
            app.NumStoreysSpinner.Value = 2;
            app.NumClassroomsSpinner.Value = 4;
            app.QuantityOfPlasterField.Value = 1000;
            app.QuantityOfGlazedTilesField.Value = 2300;
            app.TotalPaintingAreaField.Value = 25000;
            app.TotalCHBAreaField.Value = 34000;
            app.TotalFinishesAreaField.Value = 21000;
            app.PlasterPerCHBField.Value = 0.3;
            app.TilesPerCHBField.Value = 0.06;
            app.PredictedValueLabel.Text = '₱ 0.00';
            app.StatusLabel.Text = 'Reset to defaults.';
        end
    end

    methods (Access = public)
        function app = ArchBudgetPredictorApp()
            % Constructor: create components and load data
            createComponents(app);
            loadModelAndMedians(app);
            % populate medians if available
            onLoadDefaults(app);
        end

        function delete(app)
            % Destructor: delete UIFigure
            if isvalid(app.UIFigure)
                delete(app.UIFigure);
            end
        end
    end
end
