%% Yaw estimation
% clear
% close all
% clc
simulation = 0;
plotting = 1;
detrend_enable = 0;
estimation_mode = 'YawCong';
% yaw_filepath = fullfile('bag','act_3_4_test_1_2016-03-21-15-03-06.bag');
%yaw_filepath = fullfile('bag','act_3_4_test_2_2016-03-21-15-06-06.bag');
% yaw_filepath = fullfile('bag','act_3_4_test_3_2016-03-21-15-09-30.bag');
% yaw_filepath = fullfile('bag','act_3_4_test_4_2016-03-21-15-14-04.bag');
%yaw_filepath = fullfile('bag','act_3_4_test_5_2016-03-21-15-15-26.bag');
% yaw_filepath = fullfile('bag','test1_t3_t4_2016-04-04-14-57-52.bag');
% yaw_filepath = fullfile('bag','test2_t3_t4_2016-04-04-14-59-57.bag');
%  yaw_filepath = fullfile('bag','test3_t3_t4_2016-04-04-15-02-24.bag');

%yaw_filepath = 'Yaw0321';
yaw_filepath = 'Yaw0404';

[parameters, parameter_strings]= initROVParameters();
displayTable(parameters, parameter_strings);
[yaw_nonlinear_greybox_model, yaw_data, yaw_val_data] =...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation, yaw_filepath, plotting, detrend_enable);

%%

opt = nlgreyestOptions; 
opt.Display = 'on';
opt.SearchOption.MaxIter = 50;
tic
%yaw_estimation = pem(yaw_data, yaw_nonlinear_greybox_model,opt);
yaw_estimation = nlgreyest(yaw_data, yaw_nonlinear_greybox_model,opt);
toc
displayTable(parameters, parameter_strings, yaw_estimation)

figure(1)
compare(yaw_val_data, yaw_estimation, inf);
%%
saveParameters(yaw_estimation.Report.Parameters.ParVector, yaw_estimation.Report.Parameters.Free)
% temp_parameters = yaw_estimation.Report.Parameters.ParVector;
% save('yawparameters.mat','temp_parameters', 'yaw_estimation')
%% RollPitch estimation
% clear;
% close all;
estimation_mode = 'RollPitchCong';
%roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_1_2016-03-21-15-23-37.bag');
%roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_2_2016-03-21-15-26-12.bag');
%roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_3_2016-03-21-15-28-14.bag');
%roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_4_2016-03-21-15-29-25.bag');
%roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_5_2016-03-21-15-32-03.bag');

% roll_pitch_filepath = fullfile('bag','test1_roll_pitch_2016-04-04-15-11-53.bag');
% roll_pitch_filepath = fullfile('bag','test2_roll_pitch_2016-04-04-15-14-44.bag');
% roll_pitch_filepath = fullfile('bag','test3_roll_pitch_2016-04-04-15-16-43.bag');
%roll_pitch_filepath = fullfile('bag','test4_roll_pitch_2016-04-04-15-18-34.bag');

%roll_pitch_filepath = 'RollPitch0321';
roll_pitch_filepath = 'RollPitch0404';
[parameters, parameter_strings]= initROVParameters();
displayTable(parameters, parameter_strings);
simulation = 0;
plotting = 1;
detrend_enable = 0;

[roll_pitch_nonlinear_greybox_model, roll_pitch_data, roll_pitch_val_data] =...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation, roll_pitch_filepath, plotting, detrend_enable);

%%
opt = nlgreyestOptions;
opt.Display = 'on';
opt.SearchOption.MaxIter = 50;
tic
roll_pitch_estimation = nlgreyest(roll_pitch_data(1:7000), roll_pitch_nonlinear_greybox_model,opt);
toc
displayTable(parameters, parameter_strings, roll_pitch_estimation)

figure(2)
compare(roll_pitch_val_data(1:7000), roll_pitch_estimation, inf);
%%
saveParameters(roll_pitch_estimation.Report.Parameters.ParVector, roll_pitch_estimation.Report.Parameters.Free)
% temp_parameters = roll_pitch_estimation.Report.Parameters.ParVector;
% save('rollpitchparameters.mat','temp_parameters', 'roll_pitch_estimation')

%% Pitch estimation
% clear;
% close all;
estimation_mode = 'Pitch';
% pitch_filepath = fullfile('bag','act_5_test_1_2016-03-21-15-36-48.bag');
% pitch_filepath = fullfile('bag','act_5_test_2_2016-03-21-15-37-53.bag');

% pitch_filepath = fullfile('bag','test1_t1_lock_t2_2016-04-04-14-24-09.bag');
% pitch_filepath = fullfile('bag','test2_t1_lock_t2_2016-04-04-14-36-20.bag');
% pitch_filepath = fullfile('bag','test3_t1_lock_t2_2016-04-04-14-40-15.bag');
% pitch_filepath = fullfile('bag','test4_t1_lock_t2_2016-04-04-14-46-48.bag');
% pitch_filepath = fullfile('bag','test5_t1_lock_t2_2016-04-04-14-48-38.bag');
% pitch_filepath = fullfile('bag','test6_t1_lock_t2_2016-04-04-14-50-33.bag');

%pitch_filepath = 'Pitch0321';
pitch_filepath = 'Pitch0404';

[parameters, parameter_strings]= initROVParameters();
displayTable(parameters, parameter_strings);
simulation = 0;
plotting = 0;
detrend_enable = 1;

[pitch_nonlinear_greybox_model, pitch_data, pitch_val_data] =...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation,pitch_filepath, plotting, detrend_enable);

%%

opt = nlgreyestOptions;
opt.Display = 'on';
opt.SearchOption.MaxIter = 50;
tic
pitch_estimation = nlgreyest(pitch_data, pitch_nonlinear_greybox_model,opt);
%pitch_estimation = pem(pitch_data, pitch_nonlinear_greybox_model,opt);
toc
displayTable(parameters, parameter_strings,pitch_estimation)

figure(3)
compare(pitch_val_data, pitch_estimation, inf);

%%
temp_parameters = pitch_estimation.Report.Parameters.ParVector;
save('pitchparameters.mat','temp_parameters', 'pitch_estimation')
%% All rotational dynamics estimation
% clear;
% close all;
estimation_mode = 'AllCong';

All_filepath = fullfile('bag','test1_all_2016-04-04-15-23-32.bag');
% All_filepath = fullfile('bag','test2_all_2016-04-04-15-27-58.bag');

All_filepath = 'All0418';

[parameters, parameter_strings]= initROVParameters();
displayTable(parameters, parameter_strings);
simulation = 0;
plotting = 1;
detrend_enable = 0;

[All_nonlinear_greybox_model, All_data, All_val_data] =...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation,All_filepath, plotting, detrend_enable);

%%

opt = nlgreyestOptions;
opt.Display = 'on';
opt.SearchOption.MaxIter = 50;
tic
All_estimation = nlgreyest(All_data, All_nonlinear_greybox_model,opt)
%All_estimation = pem(All_data, All_nonlinear_greybox_model,opt);
toc
displayTable(parameters, parameter_strings,All_estimation)

figure(4)
compare(All_val_data, All_estimation, inf);

%%
% temp_parameters = All_estimation.Report.Parameters.ParVector;
% save('Allparameters.mat','temp_parameters', 'All_estimation')
saveParameters(All_estimation.Report.Parameters.ParVector, All_estimation.Report.Parameters.Free);
