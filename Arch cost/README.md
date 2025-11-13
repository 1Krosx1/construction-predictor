Project: Architectural cost — model test helpers

Files added:

- `run_model_test.m`  — MATLAB helper function that loads `architectural_model_assets.mat`, applies preprocessing, and predicts budget for a single input row (table or struct).
- `test_model_from_matlab.py` — small Python wrapper that calls MATLAB non-interactively (`matlab -batch`) to run `run_model_test` on a chosen row from `Architectural_Total_Cost.csv`.

How to use (MATLAB):

1. Start MATLAB in the project folder (where `architectural_model_assets.mat` exists).
2. Prepare a table `Trow` with the same raw feature columns used in the pipeline (the variables shown in `main.m` are used). Example:

   Trow = table(2024, 2, 4, 100000, 20000, 30000, 15000, 50000, 70000, 'VariableNames', {...});

3. Call:

   [pred, details] = run_model_test(Trow);

The function prints the predicted budget and returns `pred` and `details` containing intermediate vectors and selected features.

How to use (Python wrapper):

1. Ensure MATLAB is installed and `matlab` is available on PATH.
2. From this folder run (PowerShell/CMD):

   python test_model_from_matlab.py --row 1

This will call MATLAB to load row 1 from `Architectural_Total_Cost.csv`, run `run_model_test`, and print MATLAB output.

Alternative (using compiled DLL from `codegen`):

- There is an example `test.py` that calls the generated `predictEnsemble.dll` directly. That requires the correct 32-length input vector ordering (the code generator used the selected polynomial features). Use that only if you can prepare the 32-element input vector in the correct order.

Notes and next steps:

- If you'd like, I can add a convenience function that converts a CSV row automatically to the required 32-length vector in Python by reading `architectural_model_assets.mat` via MATLAB Engine or by exporting the `poly_feature_names` and `selected_mask` to a JSON mapping file. Tell me which you prefer.
