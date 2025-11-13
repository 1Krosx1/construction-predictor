function [summary, breakdown] = estimate_MEPFS_budget(varargin)
% estimate_MEPFS_budget  Estimate a high-level budget for MEPFS projects.
%
% USAGE:
%   summary = estimate_MEPFS_budget('Area',1000,'NumOccupants',100,...)
%   [summary, breakdown] = estimate_MEPFS_budget(paramsStruct)
%
% INPUTS (name-value or a single struct):
%   'Area'            - area in m^2 (default 1000)
%   'NumOccupants'    - number of occupants (default 100)
%   'Complexity'      - 'low'|'medium'|'high'|'very_high' or numeric factor (default 'medium')
%   'EquipmentCost'   - additional equipment procurement cost (default 0)
%   'LaborRate'       - labor rate in currency units per hour (default 50)
%   'ContingencyPct'  - contingency fraction of direct costs (default 0.10)
%   'OverheadPct'     - overhead fraction (default 0.12)
%   'InflationPct'    - inflation fraction applied at end (default 0.03)
%   'BaseCostPerM2'   - base cost per m^2 for direct MEPFS works (default 300)
%   'Currency'        - string used for display (default 'USD')
%   'UseAssetsFile'   - true/false, attempt to load 'mepfs_model_assets.mat' to override equipment (default false)
%
% OUTPUTS:
%   summary   - struct with high-level numbers (DirectCost, LaborCost, EquipmentCost, Contingency, Overhead, Inflation, Total)
%   breakdown - struct with per-discipline breakdown (Mechanical, Electrical, Plumbing, Fire, Structural, Other)
%
% NOTES & ASSUMPTIONS:
% - This is a top-level estimator using simple heuristics and percentages. It's not a replacement
%   for detailed take-off or vendor quotes.
% - If you have a workspace file `mepfs_model_assets.mat` with a variable `equipment_cost`, set
%   'UseAssetsFile' true to load it and add to EquipmentCost.

% Parse inputs
if nargin == 1 && isstruct(varargin{1})
    params = varargin{1};
else
    p = inputParser;
    addParameter(p,'Area',1000,@(x)isnumeric(x)&&isscalar(x)&&x>=0);
    addParameter(p,'NumOccupants',100,@(x)isnumeric(x)&&isscalar(x)&&x>=0);
    addParameter(p,'Complexity','medium');
    addParameter(p,'EquipmentCost',0,@(x)isnumeric(x)&&isscalar(x)&&x>=0);
    addParameter(p,'LaborRate',50,@(x)isnumeric(x)&&isscalar(x)&&x>=0);
    addParameter(p,'ContingencyPct',0.10,@(x)isnumeric(x)&&isscalar(x)&&x>=0);
    addParameter(p,'OverheadPct',0.12,@(x)isnumeric(x)&&isscalar(x)&&x>=0);
    addParameter(p,'InflationPct',0.03,@(x)isnumeric(x)&&isscalar(x)&&x>=0);
    addParameter(p,'BaseCostPerM2',300,@(x)isnumeric(x)&&isscalar(x)&&x>=0);
    addParameter(p,'Currency','USD',@ischar);
    addParameter(p,'UseAssetsFile',false,@(x)islogical(x)||ismember(x,[0 1]));
    parse(p,varargin{:});
    params = p.Results;
end

% Normalize complexity to numeric factor
if ischar(params.Complexity) || isstring(params.Complexity)
    c = lower(char(params.Complexity));
    switch c
        case 'low'
            cf = 0.9;
        case 'medium'
            cf = 1.0;
        case 'high'
            cf = 1.3;
        case 'very_high'
            cf = 1.6;
        otherwise
            warning('Unknown complexity string "%s"; using 1.0',c);
            cf = 1.0;
    end
elseif isnumeric(params.Complexity)
    cf = params.Complexity;
else
    cf = 1.0;
end

% Optional: load asset file to get equipment_cost
assetsLoaded = false;
if isfield(params,'UseAssetsFile') && params.UseAssetsFile
    assetsFile = fullfile(pwd,'mepfs_model_assets.mat');
    if exist(assetsFile,'file')
        try
            S = load(assetsFile);
            if isfield(S,'equipment_cost')
                params.EquipmentCost = params.EquipmentCost + S.equipment_cost;
                assetsLoaded = true;
            elseif isfield(S,'equipmentCost')
                params.EquipmentCost = params.EquipmentCost + S.equipmentCost;
                assetsLoaded = true;
            else
                % no recognized var; leave as-is
                warning('Asset file found but no recognizable equipment cost variable inside.');
            end
        catch
            warning('Failed to load %s — ignoring asset file.',assetsFile);
        end
    else
        warning('UseAssetsFile requested but %s not found.',assetsFile);
    end
end

% Heuristics and splits
area = params.Area;
base = params.BaseCostPerM2;

direct_cost = area * base * cf; % cost of direct MEPFS works (materials + subcontract)

% Discipline shares (sum = 1.0)
shares = struct('Mechanical',0.30,'Electrical',0.25,'Plumbing',0.15,'Fire',0.10,'Structural',0.07,'Other',0.13);

breakdown.Mechanical = direct_cost * shares.Mechanical;
breakdown.Electrical = direct_cost * shares.Electrical;
breakdown.Plumbing   = direct_cost * shares.Plumbing;
breakdown.Fire       = direct_cost * shares.Fire;
breakdown.Structural = direct_cost * shares.Structural;
breakdown.Other      = direct_cost * shares.Other;

% Labor estimate: simple hours per m2 * complexity
hours_per_m2 = 0.2; % heuristic: 0.2 labor-hours per m2 baseline
estimated_hours = area * hours_per_m2 * cf;
labor_cost = estimated_hours * params.LaborRate;

% Equipment cost (user-supplied or loaded)
equipment_cost = params.EquipmentCost;

subtotal = direct_cost + labor_cost + equipment_cost;
contingency = params.ContingencyPct * subtotal;
overhead = params.OverheadPct * (subtotal + contingency);
total_before_inflation = subtotal + contingency + overhead;
inflation = params.InflationPct * total_before_inflation;
total_cost = total_before_inflation + inflation;

% Assemble summary
summary = struct();
summary.Area = area;
summary.NumOccupants = params.NumOccupants;
summary.ComplexityFactor = cf;
summary.DirectCost = direct_cost;
summary.LaborCost = labor_cost;
summary.EstimatedLaborHours = estimated_hours;
summary.EquipmentCost = equipment_cost;
summary.Subtotal = subtotal;
summary.Contingency = contingency;
summary.Overhead = overhead;
summary.Inflation = inflation;
summary.Total = total_cost;
summary.Currency = params.Currency;
% Echo key input percentages and config back to caller
summary.ContingencyPct = params.ContingencyPct;
summary.OverheadPct = params.OverheadPct;
summary.InflationPct = params.InflationPct;
summary.LaborRate = params.LaborRate;
summary.BaseCostPerM2 = params.BaseCostPerM2;
summary.AssetsLoaded = assetsLoaded;

% If no outputs requested, print a friendly table
if nargout == 0
    fprintf('\nMEPFS Budget Estimate (currency: %s)\n',params.Currency);
    fprintf('----------------------------------------\n');
    fprintf('Area: %.0f m^2, Occupants: %.0f, Complexity factor: %.2f\n',summary.Area,summary.NumOccupants,summary.ComplexityFactor);
    fprintf('\nDirect works breakdown:\n');
    fprintf('  Mechanical: %s %.2f\n',params.Currency,breakdown.Mechanical);
    fprintf('  Electrical: %s %.2f\n',params.Currency,breakdown.Electrical);
    fprintf('  Plumbing:   %s %.2f\n',params.Currency,breakdown.Plumbing);
    fprintf('  Fire:       %s %.2f\n',params.Currency,breakdown.Fire);
    fprintf('  Structural: %s %.2f\n',params.Currency,breakdown.Structural);
    fprintf('  Other:      %s %.2f\n',params.Currency,breakdown.Other);
    fprintf('\nLabor (%.1f hrs): %s %.2f\n',summary.EstimatedLaborHours,params.Currency,summary.LaborCost);
    fprintf('Equipment: %s %.2f\n',params.Currency,summary.EquipmentCost);
    fprintf('\nSubtotal: %s %.2f\n',params.Currency,summary.Subtotal);
    fprintf('Contingency (%.1f%%): %s %.2f\n',params.ContingencyPct*100,params.Currency,summary.Contingency);
    fprintf('Overhead (%.1f%%): %s %.2f\n',params.OverheadPct*100,params.Currency,summary.Overhead);
    fprintf('Inflation (%.1f%%): %s %.2f\n',params.InflationPct*100,params.Currency,summary.Inflation);
    fprintf('\nTOTAL ESTIMATED BUDGET: %s %.2f\n\n',params.Currency,summary.Total);
else
    % Also include discipline breakdown in the output variable for programmatic use
    % convert breakdown values to numeric fields (already numeric)
end
end
