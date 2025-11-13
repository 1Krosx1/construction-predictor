function example_predict_row(rowIdx)
% EXAMPLE_PREDICT_ROW Example helper to run run_model_test on a CSV row.
%   example_predict_row(rowIdx) - loads `Architectural_Total_Cost.csv`,
%   cleans headers (same rules as main.m), picks the given 1-based row and
%   calls run_model_test on that row. If rowIdx omitted, defaults to 1.

    if nargin < 1 || isempty(rowIdx)
        rowIdx = 1;
    end

    fprintf('Loading CSV and preparing row %d...\n', rowIdx);
    opts = detectImportOptions('Architectural_Total_Cost.csv');
    opts.VariableNamingRule = 'preserve';
    T = readtable('Architectural_Total_Cost.csv', opts);

    % Make variable names consistent with main.m
    varNames = matlab.lang.makeValidName(T.Properties.VariableNames);
    T.Properties.VariableNames = lower(varNames);

    % Clamp row to valid range
    rowIdx = max(1, min(height(T), rowIdx));
    Trow = T(rowIdx, :);

    fprintf('Calling run_model_test for row %d...\n', rowIdx);
    try
        [pred_budget, details] = run_model_test(Trow);
        fprintf('Result: predicted budget = %.2f\n', pred_budget);
    catch ME
        fprintf('Error while running run_model_test:\n%s\n', getReport(ME));
    end
end
