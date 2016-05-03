%% All rotational dynamics estimation
% clear;
% close all;
LASTN = maxNumCompThreads(4);
estimation_mode = 'AllSuperCong_c';
All_filepath = 'All0418';
simulation = 0;
plotting = 0;
detrend_enable = 1;
resampling_fs = 50;
load('rtau.mat') 
initialCondition = [1 0 0 1 0 0 0].';
parameter_variance = 0.2;
output_variance = 0.3;


[parameters, parameter_strings]= initROVParameters();
parameters = [parameters; 100;];
parameter_strings{end+1} = 'gam';
displayTable(parameters, parameter_strings);

[All_nonlinear_greybox_model, All_data, All_val_data, initial_states, dist_parameters] =...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation, All_filepath,...
    plotting, detrend_enable, resampling_fs, real_tau, initialCondition, parameter_variance, output_variance);

%%
opt = nlgreyestOptions;
opt.Display = 'on';
opt.SearchMethod = 'lm';
opt.SearchOption.MaxIter = 100;
%  w = diag([100 100 100 50 50 50]);
opt.OutputWeight = 'noise';
% opt.Outputweight = w;
opt.Advanced.ErrorThreshold = 1.6;

tic
All_estimation = nlgreyest(All_data, All_nonlinear_greybox_model,opt);
toc
displayTable(parameters, parameter_strings,All_estimation)

figure
comopt = compareOptions('InitialCondition', initial_states(:,5));

compare(getexp(All_val_data,2), All_estimation, inf,comopt);
%%
dist_parameters - parameters
%%
% temp_parameters = All_estimation.Report.Parameters.ParVector;
% save('Allparameters.mat','temp_parameters', 'All_estimation')
saveParameters(All_estimation.Report.Parameters.ParVector, All_estimation.Report.Parameters.Free);
