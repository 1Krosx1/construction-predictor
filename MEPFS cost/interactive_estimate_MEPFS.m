function interactive_estimate_MEPFS()
% interactive_estimate_MEPFS  Prompt for MEPFS estimate parameters and show result
%
% Run this function in MATLAB to enter values interactively. Leave input blank
% to accept the default shown in [brackets]. Currency defaults to PHP (Peso).
%
% Example:
%   interactive_estimate_MEPFS()

fprintf('\nInteractive MEPFS Budget Estimator (defaults shown in [])\n');
fprintf('-----------------------------------------------------\n');

% Default values (tweak if needed)
defaults = struct();
defaults.Area = 1000;                % m^2
defaults.NumOccupants = 100;         % people
defaults.Complexity = 'medium';      % low|medium|high|very_high or numeric factor
defaults.EquipmentCost = 0;          % PHP
defaults.LaborRate = 300;            % PHP per hour (example)
defaults.ContingencyPct = 0.10;     % fraction
defaults.OverheadPct = 0.12;         % fraction
defaults.InflationPct = 0.03;       % fraction
defaults.BaseCostPerM2 = 15000;     % PHP per m^2 (example value)
defaults.Currency = 'PHP';

% Helper to read numeric input with unit/label
readNum = @(prompt,def) parseNumberInteractive(prompt,def);

area = readNum('Area (m^2)', defaults.Area);
numOcc = readNum('Number of occupants', defaults.NumOccupants);

% Complexity (allow text or numeric)
cInput = strtrim(input(sprintf('Complexity (low|medium|high|very_high) [%s]: ',defaults.Complexity),'s'));
if isempty(cInput)
    complexity = defaults.Complexity;
else
    % try detect numeric
    cnum = str2double(cInput);
    if ~isnan(cnum)
        complexity = cnum;
    else
        complexity = cInput;
    end
end

equip = readNum('Equipment cost (PHP)', defaults.EquipmentCost);
laborRate = readNum('Labor rate (PHP per hour)', defaults.LaborRate);
contPct = readNum('Contingency percent (e.g. 10 for 10%)', defaults.ContingencyPct*100)/100;
overPct = readNum('Overhead percent (e.g. 12 for 12%)', defaults.OverheadPct*100)/100;
infPct = readNum('Inflation percent (e.g. 3 for 3%)', defaults.InflationPct*100)/100;
basePerM2 = readNum('Base cost per m^2 (PHP)', defaults.BaseCostPerM2);

% Build params struct for estimator
params = struct();
params.Area = area;
params.NumOccupants = numOcc;
params.Complexity = complexity;
params.EquipmentCost = equip;
params.LaborRate = laborRate;
params.ContingencyPct = contPct;
params.OverheadPct = overPct;
params.InflationPct = infPct;
params.BaseCostPerM2 = basePerM2;
params.Currency = defaults.Currency;

% Optionally load equipment from the assets file (auto-detect default)
assetsFile = fullfile(pwd,'mepfs_model_assets.mat');
assetsExist = exist(assetsFile,'file') == 2;
if assetsExist
    prompt = 'Load equipment from mepfs_model_assets.mat? (Y/n): ';
    defaultUse = true;
else
    prompt = 'Load equipment from mepfs_model_assets.mat? (y/N): ';
    defaultUse = false;
end
u = strtrim(input(prompt,'s'));
if isempty(u)
    params.UseAssetsFile = defaultUse;
else
    params.UseAssetsFile = strcmpi(u,'y') || strcmpi(u,'yes');
end

fprintf('\nCalculating estimate...\n');

% Call the estimator and capture outputs
[summary, breakdown] = estimate_MEPFS_budget(params);

% Inform user if assets file was used
if isfield(summary,'AssetsLoaded') && summary.AssetsLoaded
    fprintf('\nNote: equipment costs were loaded from mepfs_model_assets.mat and added to EquipmentCost.\n');
end

% Print a compact result (the estimator already returns detailed fields)
fprintf('\nMEPFS Estimated Budget (currency: %s)\n', summary.Currency);
fprintf('---------------------------------------------\n');
fprintf('Area: %.0f m^2\n', summary.Area);
fprintf('Complexity factor: %.2f\n', summary.ComplexityFactor);
fprintf('Direct cost (materials/subcontract): %s %.2f\n', summary.Currency, summary.DirectCost);
fprintf('Labor (%.1f hrs @ %s %.2f/hr): %s %.2f\n', summary.EstimatedLaborHours, summary.Currency, params.LaborRate, summary.Currency, summary.LaborCost);
fprintf('Equipment: %s %.2f\n', summary.Currency, summary.EquipmentCost);
fprintf('Subtotal: %s %.2f\n', summary.Currency, summary.Subtotal);
fprintf('Contingency (%.1f%%): %s %.2f\n', summary.ContingencyPct*100, summary.Currency, summary.Contingency);
fprintf('Overhead (%.1f%%): %s %.2f\n', summary.OverheadPct*100, summary.Currency, summary.Overhead);
fprintf('Inflation (%.1f%%): %s %.2f\n', summary.InflationPct*100, summary.Currency, summary.Inflation);
fprintf('\nTOTAL ESTIMATED BUDGET: %s %.2f\n\n', summary.Currency, summary.Total);

% Optionally show breakdown per discipline
showBreak = strtrim(input('Show per-discipline breakdown? (y/N): ','s'));
if strcmpi(showBreak,'y') || strcmpi(showBreak,'yes')
    fprintf('\nDiscipline breakdown:\n');
    fprintf('  Mechanical: %s %.2f\n', summary.Currency, breakdown.Mechanical);
    fprintf('  Electrical: %s %.2f\n', summary.Currency, breakdown.Electrical);
    fprintf('  Plumbing:   %s %.2f\n', summary.Currency, breakdown.Plumbing);
    fprintf('  Fire:       %s %.2f\n', summary.Currency, breakdown.Fire);
    fprintf('  Structural: %s %.2f\n', summary.Currency, breakdown.Structural);
    fprintf('  Other:      %s %.2f\n', summary.Currency, breakdown.Other);
    fprintf('\n');
end

end

function val = parseNumberInteractive(prompt, default)
    % prompt: text to show, default: numeric default
    if nargin < 2, default = 0; end
    s = strtrim(input(sprintf('%s [%s]: ', prompt, num2str(default)), 's'));
    if isempty(s)
        val = default;
        return;
    end
    % remove commas and optional percent sign
    s = strrep(s,',','');
    isPercent = false;
    if endsWith(s,'%')
        isPercent = true;
        s = s(1:end-1);
    end
    v = str2double(s);
    if isnan(v)
        fprintf('  Invalid numeric input, using default %.4g\n', default);
        val = default;
        return;
    end
    if isPercent
        val = v; % caller will divide by 100 if needed
    else
        val = v;
    end
end
