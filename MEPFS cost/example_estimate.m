% example_estimate.m
% Example usage of estimate_MEPFS_budget

% 1) Call with name-value pairs
summary = estimate_MEPFS_budget('Area',2000,'NumOccupants',150,'Complexity','high',... 
    'EquipmentCost',50000,'LaborRate',60,'ContingencyPct',0.12,'OverheadPct',0.10,'InflationPct',0.04,'Currency','USD');

fprintf('\nReturned total (from struct): %s %.2f\n',summary.Currency,summary.Total);

% 2) Call with a params struct
params.Area = 800;
params.NumOccupants = 40;
params.Complexity = 'low';
params.EquipmentCost = 10000;
params.LaborRate = 40;
params.ContingencyPct = 0.08;
params.OverheadPct = 0.10;
params.InflationPct = 0.02;
params.Currency = 'USD';

[summary2, breakdown2] = estimate_MEPFS_budget(params);

fprintf('\nSecond example total: %s %.2f\n',summary2.Currency,summary2.Total);

% 3) If you want to load equipment from the provided assets file (if available):
% summary3 = estimate_MEPFS_budget('Area',1500,'UseAssetsFile',true);
% fprintf('\nWith assets file total: %s %.2f\n',summary3.Currency,summary3.Total);
