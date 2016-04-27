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

[All_nonlinear_greybox_model, All_data, All_val_data, initial_states] =...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation,All_filepath, plotting, detrend_enable, resampling_fs);

%%
opt = nlgreyestOptions;
opt.Display = 'on';
opt.SearchMethod = 'lm';
opt.SearchOption.MaxIter = 100;
w = diag([100 100 100 50 50 50 1 1 1]);
% opt.OutputWeight = 'noise';
opt.Outputweight = w;
opt.Advanced.ErrorThreshold = 0.8;

% opt.SearchOption.Advanced.UseParallel = true; 
% options = optimset('lsqnonlin');
% options = optimset(options,'UseParallel',true);
% opt.SearchOption = options;

tic
All_estimation = nlgreyest(All_data, All_nonlinear_greybox_model,opt);
toc
displayTable(parameters, parameter_strings,All_estimation)

All_estimation.Parameters(30).Value = initial_states(2,8);
All_estimation.Parameters(31).Value = initial_states(2,9);
All_estimation.Parameters(32).Value = initial_states(2,10);
figure(1)
comopt = compareOptions('InitialCondition',initial_states(2,1:7));
compare(All_val_data, All_estimation, inf);

%%
% temp_parameters = All_estimation.Report.Parameters.ParVector;
% save('Allparameters.mat','temp_parameters', 'All_estimation')
saveParameters(All_estimation.Report.Parameters.ParVector, All_estimation.Report.Parameters.Free);
