classdef StrucBudgetPredictorProgrammatic < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure                     matlab.ui.Figure
        Grid                        matlab.ui.container.GridLayout
        TitleLabel                  matlab.ui.control.Label
        YearDropdown                matlab.ui.control.DropDown
        NumStoreysSpinner           matlab.ui.control.Spinner
        NumClassroomsSpinner        matlab.ui.control.Spinner
        TotalGrossFloorAreaField    matlab.ui.control.NumericEditField
        TotalConcreteVolumeField    matlab.ui.control.NumericEditField
        TotalReinforcingSteelField  matlab.ui.control.NumericEditField
        AreaOfFormworksField        matlab.ui.control.NumericEditField
        CostPerSqmField             matlab.ui.control.NumericEditField
        CostPerClassroomField       matlab.ui.control.NumericEditField
        ConcretePerFloorAreaField   matlab.ui.control.NumericEditField
        SteelPerConcreteField       matlab.ui.control.NumericEditField
        LoadDefaultsButton          matlab.ui.control.Button
        ResetButton                 matlab.ui.control.Button
        PredictButton               matlab.ui.control.Button
        PredictedValueLabel         matlab.ui.control.Label
        StatusLabel                 matlab.ui.control.Label
        ModelInfoLabel              matlab.ui.control.Label % new: shows concise note when cost_per_* are disabled
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
            app.UIFigure = uifigure('Name','StrucBudgetPredictor','Position',[100 100 1280 720]);
            app.UIFigure.Color = [0.95 0.97 1];  % Soft light blue-gray background
            % Grid layout - 4 columns for parameters, each param gets label+input
            app.Grid = uigridlayout(app.UIFigure,[9,4]);
            app.Grid.RowHeight = {'fit','fit','fit','fit','fit','fit','fit','fit','1x','fit'};
            % Equal column widths for balanced parameter layout
            app.Grid.ColumnWidth = {'1x','1x','1x','1x'};
            app.Grid.Padding = [20 20 20 20];
            app.Grid.RowSpacing = 10;
            app.Grid.ColumnSpacing = 10;
            app.Grid.BackgroundColor = [0.95 0.97 1];  % Match UIFigure background

            % Title
            app.TitleLabel = uilabel(app.Grid);
            app.TitleLabel.Text = 'Struct Predictor Cost CTM 5 - DLSU'; % updated title
            app.TitleLabel.FontSize = 18;
            app.TitleLabel.FontWeight = 'bold';
            app.TitleLabel.FontColor = [0 0 0];
            app.TitleLabel.Layout.Row = 1;
            app.TitleLabel.Layout.Column = [1 4];
            app.TitleLabel.HorizontalAlignment = 'center';

            % Row 2 - PARAM 1 (Year), PARAM 2 (Num storeys)
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
            % Disable auto-update
            app.YearDropdown.ValueChangedFcn = [];

            pGrid2 = uigridlayout(app.Grid,[2,1]);
            pGrid2.Layout.Row = 2; pGrid2.Layout.Column = 2;
            pGrid2.RowHeight = {'fit','1x'}; pGrid2.Padding = [8 8 8 8];
            pGrid2.BackgroundColor = [0.94 0.94 0.96];
            lbl = uilabel(pGrid2,'Text','Num storeys','HorizontalAlignment','center','FontWeight','bold');
            lbl.Layout.Row = 1; lbl.Layout.Column = 1;
            lbl.BackgroundColor = [0.94 0.94 0.96];
            lbl.FontColor = [0 0 0];
            app.NumStoreysSpinner = uispinner(pGrid2,'Limits',[0 50],'Step',1,'RoundFractionalValues',true,'Value',2);
            app.NumStoreysSpinner.Layout.Row = 2; app.NumStoreysSpinner.Layout.Column = 1;
            app.NumStoreysSpinner.ValueDisplayFormat = '%.0f';
            app.NumStoreysSpinner.BackgroundColor = [1 1 1];
            app.NumStoreysSpinner.FontColor = [0 0 0];
            % Disable auto-update
            app.NumStoreysSpinner.ValueChangedFcn = [];

            % Row 3 - PARAM 3 (Num classrooms), PARAM 4 (Total gross floor area)
            pGrid3 = uigridlayout(app.Grid,[2,1]);
            pGrid3.Layout.Row = 3; pGrid3.Layout.Column = 1;
            pGrid3.RowHeight = {'fit','1x'}; pGrid3.Padding = [8 8 8 8];
            pGrid3.BackgroundColor = [0.94 0.94 0.96];
            lbl = uilabel(pGrid3,'Text','Num classrooms','HorizontalAlignment','center','FontWeight','bold');
            lbl.Layout.Row = 1; lbl.Layout.Column = 1;
            lbl.BackgroundColor = [0.94 0.94 0.96];
            lbl.FontColor = [0 0 0];
            app.NumClassroomsSpinner = uispinner(pGrid3,'Limits',[0 200],'Step',1,'RoundFractionalValues',true,'Value',4);
            app.NumClassroomsSpinner.Layout.Row = 2; app.NumClassroomsSpinner.Layout.Column = 1;
            app.NumClassroomsSpinner.ValueDisplayFormat = '%.0f';
            app.NumClassroomsSpinner.BackgroundColor = [1 1 1];
            app.NumClassroomsSpinner.FontColor = [0 0 0];
            % Disable auto-update
            app.NumClassroomsSpinner.ValueChangedFcn = [];

            pGrid4 = uigridlayout(app.Grid,[2,1]);
            pGrid4.Layout.Row = 3; pGrid4.Layout.Column = 2;
            pGrid4.RowHeight = {'fit','1x'}; pGrid4.Padding = [8 8 8 8];
            pGrid4.BackgroundColor = [0.94 0.94 0.96];
            lbl = uilabel(pGrid4,'Text','Total gross floor area (sq.m.)','HorizontalAlignment','center','FontWeight','bold');
            lbl.Layout.Row = 1; lbl.Layout.Column = 1;
            lbl.BackgroundColor = [0.94 0.94 0.96];
            lbl.FontColor = [0 0 0];
            app.TotalGrossFloorAreaField = uieditfield(pGrid4,'numeric','Value',100000);
            app.TotalGrossFloorAreaField.Layout.Row = 2; app.TotalGrossFloorAreaField.Layout.Column = 1;
            app.TotalGrossFloorAreaField.BackgroundColor = [1 1 1];
            app.TotalGrossFloorAreaField.FontColor = [0 0 0];
            try, app.TotalGrossFloorAreaField.ValueDisplayFormat = '%.2f'; end
            % Disable auto-update
            app.TotalGrossFloorAreaField.ValueChangedFcn = [];

            % Row 4 - PARAM 5 (Total concrete volume), PARAM 6 (Total reinforcing steel)
            pGrid5 = uigridlayout(app.Grid,[2,1]);
            pGrid5.Layout.Row = 4; pGrid5.Layout.Column = 1;
            pGrid5.RowHeight = {'fit','1x'}; pGrid5.Padding = [8 8 8 8];
            pGrid5.BackgroundColor = [0.94 0.94 0.96];
            lbl = uilabel(pGrid5,'Text','Total concrete volume (cu.m.)','HorizontalAlignment','center','FontWeight','bold');
            lbl.Layout.Row = 1; lbl.Layout.Column = 1;
            lbl.BackgroundColor = [0.94 0.94 0.96];
            lbl.FontColor = [0 0 0];
            app.TotalConcreteVolumeField = uieditfield(pGrid5,'numeric','Value',1000);
            app.TotalConcreteVolumeField.Layout.Row = 2; app.TotalConcreteVolumeField.Layout.Column = 1;
            app.TotalConcreteVolumeField.BackgroundColor = [1 1 1];
            app.TotalConcreteVolumeField.FontColor = [0 0 0];
            try, app.TotalConcreteVolumeField.ValueDisplayFormat = '%.2f'; end
            % Disable auto-update
            app.TotalConcreteVolumeField.ValueChangedFcn = [];

            pGrid6 = uigridlayout(app.Grid,[2,1]);
            pGrid6.Layout.Row = 4; pGrid6.Layout.Column = 2;
            pGrid6.RowHeight = {'fit','1x'}; pGrid6.Padding = [8 8 8 8];
            pGrid6.BackgroundColor = [0.94 0.94 0.96];
            lbl = uilabel(pGrid6,'Text','Total reinforcing steel (tons)','HorizontalAlignment','center','FontWeight','bold');
            lbl.Layout.Row = 1; lbl.Layout.Column = 1;
            lbl.BackgroundColor = [0.94 0.94 0.96];
            lbl.FontColor = [0 0 0];
            app.TotalReinforcingSteelField = uieditfield(pGrid6,'numeric','Value',100);
            app.TotalReinforcingSteelField.Layout.Row = 2; app.TotalReinforcingSteelField.Layout.Column = 1;
            app.TotalReinforcingSteelField.BackgroundColor = [1 1 1];
            app.TotalReinforcingSteelField.FontColor = [0 0 0];
            try, app.TotalReinforcingSteelField.ValueDisplayFormat = '%.2f'; end
            % Disable auto-update
            app.TotalReinforcingSteelField.ValueChangedFcn = [];

            % Row 5 - PARAM 7 (Area of formworks), PARAM 8 (Cost per sqm)
            pGrid7 = uigridlayout(app.Grid,[2,1]);
            pGrid7.Layout.Row = 5; pGrid7.Layout.Column = 1;
            pGrid7.RowHeight = {'fit','1x'}; pGrid7.Padding = [8 8 8 8];
            pGrid7.BackgroundColor = [0.94 0.94 0.96];
            lbl = uilabel(pGrid7,'Text','Area of formworks (sq.m.)','HorizontalAlignment','center','FontWeight','bold');
            lbl.Layout.Row = 1; lbl.Layout.Column = 1;
            lbl.BackgroundColor = [0.94 0.94 0.96];
            lbl.FontColor = [0 0 0];
            app.AreaOfFormworksField = uieditfield(pGrid7,'numeric','Value',5000);
            app.AreaOfFormworksField.Layout.Row = 2; app.AreaOfFormworksField.Layout.Column = 1;
            app.AreaOfFormworksField.BackgroundColor = [1 1 1];
            app.AreaOfFormworksField.FontColor = [0 0 0];
            try, app.AreaOfFormworksField.ValueDisplayFormat = '%.2f'; end
            % Disable auto-update
            app.AreaOfFormworksField.ValueChangedFcn = [];

            pGrid8 = uigridlayout(app.Grid,[2,1]);
            pGrid8.Layout.Row = 5; pGrid8.Layout.Column = 2;
            pGrid8.RowHeight = {'fit','1x'}; pGrid8.Padding = [8 8 8 8];
            pGrid8.BackgroundColor = [0.94 0.94 0.96];
            lbl = uilabel(pGrid8,'Text','Cost per sqm','HorizontalAlignment','center','FontWeight','bold');
            lbl.Layout.Row = 1; lbl.Layout.Column = 1;
            lbl.BackgroundColor = [0.94 0.94 0.96];
            lbl.FontColor = [0 0 0];
            app.CostPerSqmField = uieditfield(pGrid8,'numeric','Value',500);
            app.CostPerSqmField.Layout.Row = 2; app.CostPerSqmField.Layout.Column = 1;
            app.CostPerSqmField.BackgroundColor = [1 1 1];
            app.CostPerSqmField.FontColor = [0 0 0];
            try, app.CostPerSqmField.ValueDisplayFormat = '%.2f'; end
            % Disable auto-update
            app.CostPerSqmField.ValueChangedFcn = [];
            % Disable leaky field and add tooltip
            try
                app.CostPerSqmField.Enable = 'off';
                app.CostPerSqmField.Tooltip = 'Not used by the model (avoids leakage from budget).';
            end

            % Row 6 - PARAM 9 (Cost per classroom), PARAM 10 (Concrete per floor area)
            pGrid9 = uigridlayout(app.Grid,[2,1]);
            pGrid9.Layout.Row = 6; pGrid9.Layout.Column = 1;
            pGrid9.RowHeight = {'fit','1x'}; pGrid9.Padding = [8 8 8 8];
            pGrid9.BackgroundColor = [0.94 0.94 0.96];
            lbl = uilabel(pGrid9,'Text','Cost per classroom','HorizontalAlignment','center','FontWeight','bold');
            lbl.Layout.Row = 1; lbl.Layout.Column = 1;
            lbl.BackgroundColor = [0.94 0.94 0.96];
            lbl.FontColor = [0 0 0];
            app.CostPerClassroomField = uieditfield(pGrid9,'numeric','Value',10000);
            app.CostPerClassroomField.Layout.Row = 2; app.CostPerClassroomField.Layout.Column = 1;
            app.CostPerClassroomField.BackgroundColor = [1 1 1];
            app.CostPerClassroomField.FontColor = [0 0 0];
            try, app.CostPerClassroomField.ValueDisplayFormat = '%.2f'; end
            % Disable auto-update
            app.CostPerClassroomField.ValueChangedFcn = [];
            % Disable leaky field and add tooltip
            try
                app.CostPerClassroomField.Enable = 'off';
                app.CostPerClassroomField.Tooltip = 'Not used by the model (avoids leakage from budget).';
            end

            pGrid10 = uigridlayout(app.Grid,[2,1]);
            pGrid10.Layout.Row = 6; pGrid10.Layout.Column = 2;
            pGrid10.RowHeight = {'fit','1x'}; pGrid10.Padding = [8 8 8 8];
            pGrid10.BackgroundColor = [0.94 0.94 0.96];
            lbl = uilabel(pGrid10,'Text','Concrete per floor area','HorizontalAlignment','center','FontWeight','bold');
            lbl.Layout.Row = 1; lbl.Layout.Column = 1;
            lbl.BackgroundColor = [0.94 0.94 0.96];
            lbl.FontColor = [0 0 0];
            app.ConcretePerFloorAreaField = uieditfield(pGrid10,'numeric','Value',0.01);
            app.ConcretePerFloorAreaField.Layout.Row = 2; app.ConcretePerFloorAreaField.Layout.Column = 1;
            app.ConcretePerFloorAreaField.BackgroundColor = [1 1 1];
            app.ConcretePerFloorAreaField.FontColor = [0 0 0];
            try, app.ConcretePerFloorAreaField.ValueDisplayFormat = '%.4f'; end
            % Disable auto-update
            app.ConcretePerFloorAreaField.ValueChangedFcn = [];

            % Row 7 - PARAM 11 (Steel per concrete)
            pGrid11 = uigridlayout(app.Grid,[2,1]);
            pGrid11.Layout.Row = 7; pGrid11.Layout.Column = 1;
            pGrid11.RowHeight = {'fit','1x'}; pGrid11.Padding = [8 8 8 8];
            pGrid11.BackgroundColor = [0.94 0.94 0.96];
            lbl = uilabel(pGrid11,'Text','Steel per concrete','HorizontalAlignment','center','FontWeight','bold');
            lbl.Layout.Row = 1; lbl.Layout.Column = 1;
            lbl.BackgroundColor = [0.94 0.94 0.96];
            lbl.FontColor = [0 0 0];
            app.SteelPerConcreteField = uieditfield(pGrid11,'numeric','Value',0.1);
            app.SteelPerConcreteField.Layout.Row = 2; app.SteelPerConcreteField.Layout.Column = 1;
            app.SteelPerConcreteField.BackgroundColor = [1 1 1];
            app.SteelPerConcreteField.FontColor = [0 0 0];
            try, app.SteelPerConcreteField.ValueDisplayFormat = '%.4f'; end
            % Disable auto-update
            app.SteelPerConcreteField.ValueChangedFcn = [];

            % Estimated Budget area: centered panel with green border
            panel = uipanel(app.Grid);
            panel.Title = 'Estimated Structural Budget:';
            panel.Layout.Row = 8;
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
            btnGrid.Layout.Row = 9;
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

            % Add persistent info/note label (columns 2-4). Hidden by default; shown only when needed.
            app.ModelInfoLabel = uilabel(btnGrid,'Text','');
            app.ModelInfoLabel.Layout.Row = 1; app.ModelInfoLabel.Layout.Column = [2 4];
            app.ModelInfoLabel.Visible = 'off';
            app.ModelInfoLabel.FontColor = [0 0 0];
            try, app.ModelInfoLabel.BackgroundColor = [1 1 1]; end
        end

        % Helper: called when any parameter changes
        function onParamChanged(app)
            % Debounce-friendly simple call
            try
                app.onPredict();
            catch ME
                app.StatusLabel.Text = ['Auto-predict error: ' ME.message];
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
            f = matlab.lang.makeValidName('total_gross_floor_area');
            if isfield(app.medians,f), app.TotalGrossFloorAreaField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('total_concrete_volume');
            if isfield(app.medians,f), app.TotalConcreteVolumeField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('total_reinforcing_steel');
            if isfield(app.medians,f), app.TotalReinforcingSteelField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('area_of_formworks_sq_m__');
            if isfield(app.medians,f), app.AreaOfFormworksField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('cost_per_sqm');
            if isfield(app.medians,f), app.CostPerSqmField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('cost_per_classroom');
            if isfield(app.medians,f), app.CostPerClassroomField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('concrete_per_floor_area');
            if isfield(app.medians,f), app.ConcretePerFloorAreaField.Value = app.medians.(f); end
            f = matlab.lang.makeValidName('steel_per_concrete');
            if isfield(app.medians,f), app.SteelPerConcreteField.Value = app.medians.(f); end
            app.StatusLabel.Text = 'Defaults loaded.';
            % No auto prediction on load defaults
        end

        function onPredict(app)
            % convert year dropdown selection to numeric
            yr = str2double(app.YearDropdown.Value);
            vals = [yr, app.NumStoreysSpinner.Value, app.NumClassroomsSpinner.Value, ...
                    app.TotalGrossFloorAreaField.Value, app.TotalConcreteVolumeField.Value, ...
                    app.TotalReinforcingSteelField.Value, app.AreaOfFormworksField.Value, ...
                    app.CostPerSqmField.Value, app.CostPerClassroomField.Value, ...
                    app.ConcretePerFloorAreaField.Value, app.SteelPerConcreteField.Value];
            try
                [pred, ~] = run_model_test(vals);
                % Format predicted value without currency symbol (just the number)
                formatted = app.formatCurrency(pred,'');
                app.PredictedValueLabel.Text = formatted;
                app.StatusLabel.Text = 'Prediction successful.';
            catch ME
                app.StatusLabel.Text = ['Predict error: ' ME.message];
            end
        end

        function onReset(app)
            app.YearDropdown.Value = '2024';
            app.NumStoreysSpinner.Value = 2;
            app.NumClassroomsSpinner.Value = 4;
            app.TotalGrossFloorAreaField.Value = 100000;
            app.TotalConcreteVolumeField.Value = 1000;
            app.TotalReinforcingSteelField.Value = 100;
            app.AreaOfFormworksField.Value = 5000;
            app.CostPerSqmField.Value = 500;
            app.CostPerClassroomField.Value = 10000;
            app.ConcretePerFloorAreaField.Value = 0.01;
            app.SteelPerConcreteField.Value = 0.1;
            app.PredictedValueLabel.Text = '0.00';
            app.StatusLabel.Text = 'Reset to defaults.';
            % No auto prediction on reset
        end

        function loadAssets(app)
            % Load model_assets and medians if present
            assetsFile = fullfile(pwd,'structural_model_assets.mat');
            app.medians = [];
            app.ranges = [];
            if exist(assetsFile,'file')
                S = load(assetsFile);
                if isfield(S,'final_feature_columns')
                    % normalize saved feature names to lower valid names for matching
                    app.rawFeatureNames = cellfun(@(c) lower(matlab.lang.makeValidName(c)), S.final_feature_columns, 'UniformOutput', false);
                end
                app.modelAssets = S;
                % Determine if model uses cost_per_* features and update UI accordingly (no log messages)
                usesCostPer = false;
                if isfield(S,'final_feature_columns')
                    ffcLower = lower(S.final_feature_columns);
                    usesCostPer = any(contains(ffcLower,'cost_per_sqm')) || any(contains(ffcLower,'cost_per_classroom'));
                end
                if usesCostPer
                    % enable fields if model actually uses them; hide note
                    try
                        app.CostPerSqmField.Enable = 'on';
                        app.CostPerClassroomField.Enable = 'on';
                        app.CostPerSqmField.Tooltip = 'Used by this trained model.';
                        app.CostPerClassroomField.Tooltip = 'Used by this trained model.';
                    end
                    app.ModelInfoLabel.Text = '';
                    app.ModelInfoLabel.Visible = 'off';
                else
                    % disable fields to avoid leakage; show concise note explaining why
                    try
                        app.CostPerSqmField.Enable = 'off';
                        app.CostPerClassroomField.Enable = 'off';
                        app.CostPerSqmField.Tooltip = 'Not used to avoid target leakage (derived from budget).';
                        app.CostPerClassroomField.Tooltip = 'Not used to avoid target leakage (derived from budget).';
                    end
                    app.ModelInfoLabel.Text = 'Note: Cost per sqm and Cost per classroom are disabled because they are derived from budget and not used by the trained model.';
                    app.ModelInfoLabel.Visible = 'on';
                end
            end
            csvFile = fullfile(pwd,'Structural_Total_Cost.csv');
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
    end

    methods (Access = public)

        % Construct app
        function app = StrucBudgetPredictorProgrammatic()
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