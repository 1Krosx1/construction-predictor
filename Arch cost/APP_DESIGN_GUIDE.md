# App Designer Guide — Architectural Budget Predictor

This guide shows how to build a clean, user-friendly MATLAB App Designer application that collects the required inputs, validates them, and runs the saved model (`architectural_model_assets.mat`) to predict project budget. It includes suggested UI layout, component names, example callback code, validation rules, UX tips, and deployment notes.

Prerequisites
- MATLAB with App Designer (R2016a or newer; recent release recommended).
- Project folder contains:
  - `architectural_model_assets.mat` (saved by `main.m`).
  - `generatePolyFeatures.m`, `run_model_test.m`, `interactive_predict.m` (helpers we added).
  - `Architectural_Total_Cost.csv` (optional; used to infer medians/ranges for defaults).

Design goals
- Clear labels that show units (e.g., "Quantity of plaster (sq.m.)").
- Provide sensible defaults (medians from the training CSV) so the user can accept or tweak values.
- Validate inputs (integer for counts, numeric >=0 for areas, year range clamp).
- One prominent "Predict" button and an area to show the predicted budget and quick diagnostics.

Suggested layout (GridLayout inside the main UIFigure)
- Use a 2-column grid for inputs and labels, with controls stacked vertically.
- Top area: App title and short description.
- Left column: numeric input controls for each raw feature (year, num_storeys, num_classrooms, plaster, glazed tiles,...).
- Right column: action buttons and prediction output (large label for predicted budget).
- Bottom: optional axes for plots (Actual vs Predicted or feature importance) or a table showing the generated polynomial feature count.

Component list and recommended names
(map these to the `final_feature_columns` used in your model; the example below follows `main.m`):

- Labels
  - `LabelTitle` — app title
  - `LabelDescription` — one-line instruction

- Numeric inputs (use `NumericEditField` or `Spinner` in App Designer):
  - `YearSpinner` (numeric spinner) — unit: year (YYYY)
  - `NumStoreysSpinner` (spinner) — unit: count (integer)
  - `NumClassroomsSpinner` (spinner) — unit: count (integer)
  - `QuantityOfPlasterField` (numeric edit) — unit: sq.m.
  - `QuantityOfGlazedTilesField` (numeric edit) — unit: sq.m.
  - `TotalPaintingAreaField` (numeric edit) — unit: sq.m.
  - `TotalCHBAreaField` (numeric edit) — unit: sq.m.
  - `TotalFinishesAreaField` (numeric edit) — unit: sq.m.
  - `PlasterPerCHBField` (numeric edit) — unit: sq.m. per sq.m. (or ratio)
  - `TilesPerCHBField` (numeric edit) — unit: sq.m. per sq.m. (or ratio)

- Buttons
  - `LoadDefaultsButton` — fill fields with medians from training CSV
  - `PredictButton` — compute and display prediction
  - `ResetButton` — clear or restore defaults

- Output
  - `PredictedLabel` — small label "Predicted Budget"
  - `PredictedValueLabel` — large bold label to show the numeric prediction (formatted)
  - `StatusLabel` — bottom area for messages/errors
  - `UIAxes` (optional) — show a small diagnostic plot

Startup tasks (app's startupFcn)
1. Load model assets and CSV medians.
2. Save useful variables on the `app` object (so they are accessible in callbacks): `app.modelAssets`, `app.rawFeatureNames`, `app.medians`, `app.ranges`.

Example startupFcn code (paste into App Designer > Code View > startupFcn):

```matlab
function startupFcn(app)
    % Load model assets
    assetsFile = fullfile(pwd, 'architectural_model_assets.mat');
    if exist(assetsFile, 'file')
        S = load(assetsFile, 'final_feature_columns', 'mu', 'sigma', 'selected_mask', 'poly_feature_names');
        app.modelAssets = S; % keep for later
        app.rawFeatureNames = S.final_feature_columns;
    else
        uialert(app.UIFigure, 'architectural_model_assets.mat not found in the project folder. Run main.m to create it first.', 'Missing file');
        app.rawFeatureNames = {};
    end

    % Try to load CSV and compute medians/ranges to use as defaults
    csvFile = fullfile(pwd, 'Architectural_Total_Cost.csv');
    app.medians = struct();
    app.ranges = struct();
    if exist(csvFile, 'file')
        opts = detectImportOptions(csvFile); opts.VariableNamingRule = 'preserve';
        T = readtable(csvFile, opts);
        T.Properties.VariableNames = lower(matlab.lang.makeValidName(T.Properties.VariableNames));
        for i = 1:numel(app.rawFeatureNames)
            fn = app.rawFeatureNames{i};
            if ismember(fn, T.Properties.VariableNames)
                col = T.(fn);
                if ~isnumeric(col)
                    col = str2double(strrep(string(col), ',', ''));
                end
                col = col(~isnan(col));
                if ~isempty(col)
                    app.medians.(matlab.lang.makeValidName(fn)) = median(col);
                    app.ranges.(matlab.lang.makeValidName(fn)) = [min(col), max(col)];
                end
            end
        end
    end

    % Optionally populate UI with medians
    if isfield(app.medians, 'year')
        app.YearSpinner.Value = round(app.medians.year);
    end
    % set other controls similarly (example)
    if isfield(app.medians, 'num_storeys'), app.NumStoreysSpinner.Value = round(app.medians.num_storeys); end
    if isfield(app.medians, 'num_classrooms'), app.NumClassroomsSpinner.Value = round(app.medians.num_classrooms); end
    % ... set the other fields (QuantityOfPlasterField, etc.) using the same pattern
end
```

Filling defaults (LoadDefaultsButton pushed)
- Implement a callback that reads `app.medians` and populates input controls.

Example LoadDefaults callback:

```matlab
function LoadDefaultsButtonPushed(app, event)
    fn = matlab.lang.makeValidName('quantityofplaster_sq_m__'); % example field name mapping
    if isfield(app.medians, fn), app.QuantityOfPlasterField.Value = app.medians.(fn); end
    % repeat for other fields
    app.StatusLabel.Text = 'Defaults loaded from training data.';
end
```

Predict callback (PredictButton pushed)
- Gather values from UI fields into a table with variable names matching `final_feature_columns`.
- Call `run_model_test(Trow)` and display the returned `pred_budget` in `PredictedValueLabel`.

Example PredictButton callback:

```matlab
function PredictButtonPushed(app, event)
    % Build a 1-row table matching final_feature_columns order
    cols = app.rawFeatureNames;
    vals = zeros(1, numel(cols));

    for i = 1:numel(cols)
        switch lower(cols{i})
            case 'year'
                vals(i) = app.YearSpinner.Value;
            case 'num_storeys'
                vals(i) = app.NumStoreysSpinner.Value;
            case 'num_classrooms'
                vals(i) = app.NumClassroomsSpinner.Value;
            case 'quantityofplaster_sq_m__'
                vals(i) = app.QuantityOfPlasterField.Value;
            case 'quantityofglazedtiles_sq_m__'
                vals(i) = app.QuantityOfGlazedTilesField.Value;
            case 'total_painting_area'
                vals(i) = app.TotalPaintingAreaField.Value;
            case 'total_chb_area'
                vals(i) = app.TotalCHBAreaField.Value;
            case 'total_finishes_area'
                vals(i) = app.TotalFinishesAreaField.Value;
            case 'plaster_per_chb'
                vals(i) = app.PlasterPerCHBField.Value;
            case 'tiles_per_chb'
                vals(i) = app.TilesPerCHBField.Value;
            otherwise
                vals(i) = 0; % safe default
        end
    end

    % Call the helper (we added this earlier)
    try
        [pred_budget, details] = run_model_test(vals);
        app.PredictedValueLabel.Text = sprintf('₱ %.2f', pred_budget);
        app.StatusLabel.Text = 'Prediction successful';
        % Optionally plot diagnostics in app.UIAxes using `details`
    catch ME
        app.StatusLabel.Text = sprintf('Prediction failed: %s', ME.message);
    end
end
```

Validation notes
- For integer fields (storeys, classrooms): use `Spinner` components and round values before using.
- For areas: ensure non-negative numbers. Show red border or an alert if invalid.
- For Year: restrict spinner min/max (e.g., 2000..2025) or clamp inputs and show a tooltip.

UX improvements
- Allow pressing Enter to trigger Predict (set default button in App Designer).
- Support keyboard navigation between fields.
- Show units next to each control and an information icon with a short help tooltip.
- Provide an example preset dropdown (e.g., "Small classroom", "Medium school", "Large campus") which fills fields with recommended values.

Spinner configuration (detailed)
--------------------------------
App Designer's `Spinner` (or `NumericEditField` with spinner) exposes many properties you can tune in the right-side Component Browser. Use the Component Browser to select a spinner (for example `app.YearSpinner`) and edit properties under the "VALUE" and "FONT AND COLOR" sections. The attached screenshot shows the Year spinner's properties pane as an example.

Recommended spinner settings for common fields
- Year (`YearSpinner`)
    - Value: (set programmatically from median or default)
    - Limits: [2000, 2025]  % example; adjust to your supported range
    - Step: 1
    - RoundFractionalValues: checked (so entries are integers)
    - ValueDisplayFormat: '%d' or '%11.4g' (use '%d' for clean integer display)
    - AllowEmpty: unchecked
    - LowerLimitInclusive / UpperLimitInclusive: checked

- Counts (`NumStoreysSpinner`, `NumClassroomsSpinner`)
    - Limits: [0, 100] (or appropriate max)
    - Step: 1
    - RoundFractionalValues: checked
    - ValueDisplayFormat: '%d'

- Areas (`QuantityOfPlasterField`, `QuantityOfGlazedTilesField`, `TotalPaintingAreaField`, etc.)
    - Limits: [0, Inf]
    - Step: 1 or 0.1 (choose depending on desired precision)
    - RoundFractionalValues: unchecked (if you allow decimals)
    - ValueDisplayFormat: '%.0f' for whole sq.m. or '%.2f' for two decimals

How to set these properties in App Designer (visual)
1. Open your app in App Designer.
2. In the Component Browser (left), click the spinner you want to edit (e.g., `YearSpinner`).
3. On the right, under the "VALUE" group, update `Limits`, `Step`, `RoundFractionalValues`, `ValueDisplayFormat`, and `AllowEmpty`.
4. Under "FONT AND COLOR" you can change `FontName`, `FontSize`, `FontWeight` and `FontColor` to match your app style.

Set spinner properties programmatically
-------------------------------------
You can also set or override spinner properties in code (for example in `startupFcn`) so defaults and limits are enforced when the app starts. Example:

```matlab
% in startupFcn
app.YearSpinner.Limits = [2000 2025];
app.YearSpinner.Step = 1;
app.YearSpinner.RoundFractionalValues = true;
app.YearSpinner.ValueDisplayFormat = '%d';

app.NumStoreysSpinner.Limits = [0 20];
app.NumStoreysSpinner.Step = 1;
app.NumStoreysSpinner.RoundFractionalValues = true;

app.QuantityOfPlasterField.Limits = [0 Inf];
app.QuantityOfPlasterField.Step = 1; % or 0.1
app.QuantityOfPlasterField.ValueDisplayFormat = '%.0f';
```

Value validation and callbacks
------------------------------
Use the spinner `ValueChangedFcn` callback to validate or auto-correct user input. App Designer generates a callback skeleton when you double-click the spinner and then click "Callbacks > Add ValueChangedFcn" in the Component Browser. Example callback code that rounds, clamps, and updates a status label:

```matlab
% Value changed callback (App Designer auto-generates the function signature)
function YearSpinnerValueChanged(app, event)
        val = round(app.YearSpinner.Value);
        val = max(2000, min(2025, val)); % clamp
        app.YearSpinner.Value = val; % write back corrected value
        app.StatusLabel.Text = sprintf('Year set to %d', val);
end
```

For counts:

```matlab
function NumStoreysSpinnerValueChanged(app, event)
        val = round(app.NumStoreysSpinner.Value);
        val = max(0, val);
        app.NumStoreysSpinner.Value = val;
end
```

Hint: allow pressing Enter to accept the current field and trigger `PredictButton` as the app's `Default` button for faster input.

Accessibility & visual polish
--------------------------------
- Use `FontWeight = 'bold'` and a larger `FontSize` on `PredictedValueLabel` so the predicted budget is prominent.
- For spinners that accept large numbers, set `ValueDisplayFormat` to include grouping or fewer decimal places for readability.
- Use consistent `BackgroundColor` and `FontColor` for all spinners to keep the UI cohesive.


Testing & debugging
- Test with several rows from `Architectural_Total_Cost.csv` (use `example_predict_row` to get a quick baseline).
- Log intermediate `details` to the Command Window first while developing: `disp(details.poly_row)` and `disp(details.selected_vector)`.

Deployment
- Save the app (`File > Save`) as `ArchBudgetPredictor.mlapp`.
- To share with colleagues who don't have the source, use `Share > Package App` to create an installer. Include `architectural_model_assets.mat` in the packaged files.

Appendix: mapping helper (function)
Add a private method inside the app that returns the ordered numeric vector for the saved `final_feature_columns`.

```matlab
function vec = buildInputVector(app)
    cols = app.rawFeatureNames;
    vec = zeros(1, numel(cols));
    for i = 1:numel(cols)
        switch lower(cols{i})
            case 'year'
                vec(i) = app.YearSpinner.Value;
            % add the other cases exactly as in PredictButtonPushed
        end
    end
end
```

Final tips
- Keep variable names consistent with the pipeline (`final_feature_columns` in `architectural_model_assets.mat`).
- Reuse the `run_model_test` helper in the app to avoid duplicating preprocessing logic.
- When packaging, include `generatePolyFeatures.m` and `run_model_test.m` so the app can run standalone.

If you'd like, I can generate the App Designer `.mlapp` skeleton (component creation code) or produce the full callback code with exact component names wired — tell me whether you prefer a copy-paste-ready App Designer code or a step-by-step visual layout guide.
