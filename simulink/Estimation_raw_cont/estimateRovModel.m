%% All rotational dynamics estimation
% clear;
% close all;
LASTN = maxNumCompThreads(4);
estimation_mode = 'AllCong_c';
All_filepath = 'All0418';
simulation = 0;
plotting = 0;
detrend_enable = 0;
resampling_fs = 50;

[parameters, parameter_strings]= initROVParameters();
displayTable(parameters, parameter_strings);

[All_nonlinear_greybox_model, All_data, All_val_data] =...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation,All_filepath, plotting, detrend_enable, resampling_fs);

%%
opt = nlgreyestOptions;
opt.Display = 'on';
opt.SearchOption.MaxIter = 100;
w = diag([100 100 100 5 5 5 1 1 1]);
% opt.OutputWeight = 'noise';
opt.Outputweight = w;
opt.SearchMethod = 'lm';
opt.Advanced.ErrorThreshold = 0.8;

% opt.SearchOption.Advanced.UseParallel = true; 
% options = optimset('lsqnonlin');
% options = optimset(options,'UseParallel',true);
% opt.SearchOption = options;

tic
All_estimation = nlgreyest(All_data, All_nonlinear_greybox_model,opt);
toc
displayTable(parameters, parameter_strings,All_estimation)

figure(1)
comopt = compareOptions('InitialCondition','e','OutputWeight',w);
compare(All_val_data, All_estimation, inf);

%%
% temp_parameters = All_estimation.Report.Parameters.ParVector;
% save('Allparameters.mat','temp_parameters', 'All_estimation')
saveParameters(All_estimation.Report.Parameters.ParVector, All_estimation.Report.Parameters.Free);
