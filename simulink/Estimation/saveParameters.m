function [ output_args ] = saveParameters(new_parameters,estimated_parameters)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

files = dir('parameters.mat');

if isempty(files)
    warning('No parameter file found. Creating one.');
    parameters = new_parameters;
else 
 temp = load('parameters.mat');
 parameters = temp.parameters;
 indices = find(estimated_parameters);
 for i=1:size(indices)
     parameters(indices(i)) = new_parameters(indices(i));
 end
end
save('parameters.mat','parameters')
disp('Parameters saved to parameters.mat')



end

