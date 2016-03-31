function [] = displayTable(parameters, parameter_strings, nonlinear_model)
%displayTable Presents parameters with parameter strings. 
%   If the input is two inputs only parameters and parameter_strings will
%   be shown. If the input is three inputs only the estimated parameters
%   will be shown with parneter_strings, starting value and estimated
%   value.

if nargin == 3
    free_parameters = find(nonlinear_model.Report.Parameters.Free);
    est_parameters = nonlinear_model.Report.Parameters.ParVector(free_parameters);
    est_table = table(parameters(free_parameters), est_parameters,'RowNames',...
        parameter_strings(free_parameters),...
        'VariableNames', {'Starting_values','Estimated_values'});
else
    est_table = table(parameters,'RowNames',...
        parameter_strings,...
        'VariableNames', {'Starting_values'});
end
 disp(est_table);
end