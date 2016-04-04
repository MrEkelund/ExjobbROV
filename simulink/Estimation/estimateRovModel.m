%% Yaw estimation
clear
close all
clc
simulation = 0;
plotting = 1;
estimation_mode = 'Yaw';
% yaw_filepath = fullfile('bag','act_3_4_test_1_2016-03-21-15-03-06.bag');
%yaw_filepath = fullfile('bag','act_3_4_test_2_2016-03-21-15-06-06.bag');
% yaw_filepath = fullfile('bag','act_3_4_test_3_2016-03-21-15-09-30.bag');
% yaw_filepath = fullfile('bag','act_3_4_test_4_2016-03-21-15-14-04.bag');
%yaw_filepath = fullfile('bag','act_3_4_test_5_2016-03-21-15-15-26.bag');
yaw_filepath =  fullfile('~','Desktop','test2_t1_lock_t2_2016-04-04-14-36-20.bag');
%yaw_filepath = 'Yaw0321';
[parameters, parameter_strings]= initROVParameters();
displayTable(parameters, parameter_strings);
[yaw_nonlinear_greybox_model, yaw_data] =...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation, yaw_filepath, plotting);

%%
% yaw_val_data = getexp(yaw_data,1);
% yaw_est_data = getexp(yaw_data,[2:length(yaw_data.OutputData)]);

opt = nlgreyestOptions;
opt.Display = 'on';
opt.SearchOption.MaxIter = 50;
tic
%yaw_estimation = pem(yaw_data, yaw_nonlinear_greybox_model,opt);
yaw_estimation = nlgreyest(yaw_data, yaw_nonlinear_greybox_model,opt);
toc
displayTable(parameters, parameter_strings, yaw_estimation)

figure(1)
compare(yaw_data, yaw_estimation, inf);
%%
% saveParameters(yaw_estimation.Report.Parameters.ParVector, yaw_estimation.Report.Parameters.Free)
temp_parameters = yaw_estimation.Report.Parameters.ParVector;
save('yawparameters.mat','temp_parameters', 'yaw_estimation')
%% RollPitch estimation
% clear;
% close all;
estimation_mode = 'RollPitch';
%roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_1_2016-03-21-15-23-37.bag');
%roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_2_2016-03-21-15-26-12.bag');
%roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_3_2016-03-21-15-28-14.bag');
%roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_4_2016-03-21-15-29-25.bag');
%roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_5_2016-03-21-15-32-03.bag');
roll_pitch_filepath = 'RollPitch0321';
[parameters, parameter_strings]= initROVParameters();
displayTable(parameters, parameter_strings);
simulation = 0;
plotting = 0;

[roll_pitch_nonlinear_greybox_model, roll_pitch_data] =...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation, roll_pitch_filepath, plotting);

%%
% roll_pitch_val_data = getexp(roll_pitch_data,1);
% roll_pitch_est_data = getexp(roll_pitch_data,[2:length(roll_pitch_data.OutputData)]);

opt = nlgreyestOptions;
opt.Display = 'on';
opt.SearchOption.MaxIter = 50;
tic
roll_pitch_estimation = nlgreyest(roll_pitch_data, roll_pitch_nonlinear_greybox_model,opt);
toc
displayTable(parameters, parameter_strings, roll_pitch_estimation)

figure(2)
compare(roll_pitch_data, roll_pitch_estimation, inf);
%%
temp_parameters = roll_pitch_estimation.Report.Parameters.ParVector;
save('rollpitchparameters.mat','temp_parameters', 'roll_pitch_estimation')

%% Pitch estimation
% clear;
% close all;
estimation_mode = 'Pitch';
%pitch_filepath = fullfile('bag','act_5_test_1_2016-03-21-15-36-48.bag');
% pitch_filepath = fullfile('bag','act_5_test_2_2016-03-21-15-37-53.bag');
pitch_filepath = 'Pitch0321';

[parameters, parameter_strings]= initROVParameters();
displayTable(parameters, parameter_strings);
simulation = 0;
plotting = 0;

[pitch_nonlinear_greybox_model, pitch_data] =...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation,pitch_filepath, plotting);

%%
% pitch_val_data = getexp(pitch_data,1);
% pitch_est_data = getexp(pitch_data,[2:length(pitch_data.OutputData)]);

opt = nlgreyestOptions;
opt.Display = 'on';
opt.SearchOption.MaxIter = 50;
tic
pitch_estimation = nlgreyest(pitch_data, pitch_nonlinear_greybox_model,opt);
%pitch_estimation = pem(pitch_data, pitch_nonlinear_greybox_model,opt);
toc
displayTable(parameters, parameter_strings,pitch_estimation)

figure(3)
compare(pitch_data, pitch_estimation, inf);

%%
temp_parameters = pitch_estimation.Report.Parameters.ParVector;
save('pitchparameters.mat','temp_parameters', 'pitch_estimation')