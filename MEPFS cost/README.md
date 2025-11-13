# MEPFS Budget Estimator

This folder contains a small MATLAB estimator for high-level budgets for MEPFS (Mechanical, Electrical, Plumbing, Fire, Structural) projects.

Files added:
- `estimate_MEPFS_budget.m` — main estimator function. Accepts name-value pairs or a struct and returns a `summary` struct and `breakdown` struct.
- `example_estimate.m` — example calls showing how to use the function.

Usage (in MATLAB):

1) Basic name-value call:

```matlab
summary = estimate_MEPFS_budget('Area',2000,'NumOccupants',150,'Complexity','high', ...
    'EquipmentCost',50000,'LaborRate',60);
```

2) Call with a parameter struct:

```matlab
params.Area = 800;
params.NumOccupants = 40;
params.Complexity = 'low';
params.EquipmentCost = 10000;
[summary, breakdown] = estimate_MEPFS_budget(params);
```

3) Optional asset loading:
If you have a `mepfs_model_assets.mat` in the same folder that contains a variable named `equipment_cost` (or `equipmentCost`), you can set `'UseAssetsFile'` to true and the loader will add that to `EquipmentCost`.

Assumptions and notes:
- This is a conceptual estimator using simple heuristics (cost per m^2, discipline percentage splits, simple labor-hour heuristic). It is intended for early-stage planning, not for final tendering.
- Default numbers (e.g., base cost per m^2 = 300, laborRate = 50) are placeholders — replace them to match your region and project.
- The estimator prints a readable summary to the MATLAB command window when no outputs are requested. When outputs are requested, use the returned structs for programmatic processing.

If you want me to adapt the estimator to use your `MEPFS_Total_Cost.csv` or `mepfs_model_assets.mat` more explicitly (e.g., read per-item costs and build a bottom-up estimate), tell me and I will add parsing and wiring to the estimator.
