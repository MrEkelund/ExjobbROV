function [] = displayTable(nonlinear_model, parameters, parameter_strings)
%UNTITLED7 Summary of this function goes here 
%   Detailed explanation goes here

free_parameters = find(nonlinear_model.Report.Parameters.Free);
est_parameters = nonlinear_model.Report.Parameters.ParVector(free_parameters);

est_table = table(parameters(free_parameters), est_parameters,'RowNames',...
    parameter_strings(free_parameters),...
    'VariableNames', {'Starting_values','Estimated_values'});
disp(est_table);

end