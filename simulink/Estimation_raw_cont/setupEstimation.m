function [nonlinear_greybox_model, data, val_data] = ...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation,...
    filepath, plotting, detrend_enable, resampling_fs)
%setupEstimation Setups the nonlinear model of the rov and reads data
%   Detailed explanation goes here

%Compile necessary file
if exist('nakeinterp1.mexa64') ~= 3
    disp('nakeinterp1.mexa64 not found...Compiling')
    mex('CFLAGS="\$CFLAGS -std=c99"', 'nakeinterp1.c')
end
    

%% Read from data files
switch simulation
    case 0 % Test
        switch filepath
            case 'Yaw0418'
                disp('Loading yaw test data from 2016-04-18');
                data = loadYaw0418(plotting, resampling_fs);
            case 'RollPitch0418'
                disp('Loading roll pitch test data from 2016-04-18');
                data = loadRollPitch0418(plotting, resampling_fs);
            case 'All0418'
                disp('Loading all test data from 2016-04-18');
                data = loadAll0418(plotting, resampling_fs);
            otherwise
                disp(sprintf('Loading test data from %s',filepath));
                [imu_data, mag_data, thrusters_data, time]= ...
                    getTestData(All_filepath, plotting, resampling_fs);
                output_data = [imu_data, mag_data];
                input_data = thrusters_data;
                data = iddata(output_data, input_data, 1/resampling_fs);
        end
    case 1 % simulation
        warning('This functionallity has been depricated')
        disp(sprintf('Loading simulated data from %s',filepath));
        [lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time,Ts] = ...
            getSimulationData(filepath,plotting);
        output_data = [ang_vel_data , antiModAngles(states(:,1:3))];
        input_data = thrusters_data;
        data = iddata(output_data, input_data, Ts);
    otherwise
        error('Simulation can only be 0 or 1');
end

switch estimation_mode 
    case {'All','AllCong', 'AllCong_c','AllCong_disc_c'}
        if exist('rovMotionModelAllCong_c.mexa64') ~= 3
            disp('rovMotionModelAllCong_c.mexa64 not found...Compiling')
            mex rovMotionModelAllCong_c.c
        end
        data = data(:,:,:);
        data.InputName =  {'Thruster1';'Thruster2';'Thruster3';'Thruster4';'Thruster5';'Thruster6'};
        data.InputUnit =  {'%','%','%','%','%','%'};
        data.OutputName = {'p', 'q', 'r', 'a_x', 'a_y', 'a_z', 'm_x', 'm_y', 'm_z'};
        data.OutputUnit = {'rad/s','rad/s','rad/s', 'm/s', 'm/s', 'm/s', 'µT', 'µT', 'µT'};
        state_name = {'p', 'q', 'r', 'n', 'e1', 'e2','e3'};
        state_unit = {'rad/s', 'rad/s', 'rad/s', '','','',''};
    otherwise
        error('Unkown test: %s', estimation_mode);
end



ne = length(data.ExperimentName); % number of experiments

if ne == 1
    val_data = data(ceil(size(data.OutputData,1)/2):end);
    data = data(1:ceil(size(data.OutputData,1)/2)-1);
elseif ne == 2
    val_data = getexp(data,2);
    data = getexp(data,1);
else
    val_data = getexp(data, ceil(ne/2)+1:ne);
    data = getexp(data, 1:ceil(ne/2));
end

if detrend_enable
    val_data = detrend(val_data);
    data = detrend(data);
end
%% Setup the non linear greybox model
Ts_model = 0;      % Sample time [s].
ny = length(data.OutputName);
nu = length(data.InputName);
nx = length(state_name);

initial_states = zeros(nx,length(data.ExperimentName));
for i = 1:length(data.ExperimentName)
    temp_data = getexp(data, i);
    initial_states(1:3,i) = temp_data.OutputData(1,1:3);
    initial_states(4,i) = 1;
end

temp_exp = getexp(data, 1);
%parameters = [parameters; 100; temp_exp.OutputData(1,[7 8 9])'];
parameters = [parameters; 1/resampling_fs; temp_exp.OutputData(1,[7 8 9])'];
parameter_strings{end+1} = 'gam';
parameter_strings{end+1} = 'm_n';
parameter_strings{end+1} = 'm_e';
parameter_strings{end+1} = 'm_d';

file_name  = strcat('rovMotionModel',estimation_mode); % File describing the model structure.

disp(sprintf('Using %s %s',file_name,'as model file'));

order = [ny nu nx]; % Model orders [ny nu nx].

nonlinear_greybox_model = idnlgrey(file_name, order, parameters, initial_states, Ts_model, ...
    'Name', 'Rov Model', 'TimeUnit', 's');

for i = 1:nx
    nonlinear_greybox_model.InitialStates(i).Fixed = 0;
end
%% Setup names for the nonlinear greybox
nonlinear_greybox_model.Name = estimation_mode;

% Names on input
nonlinear_greybox_model.InputName =  data.InputName;
nonlinear_greybox_model.InputUnit =  data.InputUnit;

nonlinear_greybox_model.OutputName = data.OutputName;
nonlinear_greybox_model.OutputUnit = data.OutputUnit;

% Names on initial states
nonlinear_greybox_model = setinit(nonlinear_greybox_model, 'Name', state_name);
nonlinear_greybox_model = setinit(nonlinear_greybox_model, 'Unit', state_unit);

% Set the parameter names
nonlinear_greybox_model = setpar(nonlinear_greybox_model, 'Name', parameter_strings);

%% Setup parameters
% Set that some of the parameters are known the other parameters is to
% be estimated

fixed_parameters = [1:size(parameters,1)];  % Stores the index of the parameters that is fixed

yaw_parameters = [20:22, 25];
yaw_cong_parameters = [20:22, 28];
roll_pitch_parameters = [13:19, 23, 24];
roll_pitch_cong_parameters = [13:19, 26, 27];
all_parameters = [13:25];
all_cong_parameters = [13:28];
% Sets which parameters that will be estimated  
switch estimation_mode
    case 'Yaw'
        disp('Yaw test')
        fixed_parameters = setdiff(fixed_parameters, yaw_parameters);
     case 'YawCong'
        disp('Yaw test')
        fixed_parameters = setdiff(fixed_parameters, yaw_cong_parameters);       
    case 'RollPitch'
        disp('RollPitch test')
        fixed_parameters = setdiff(fixed_parameters, roll_pitch_parameters);
    case 'RollPitchCong'
        disp('RollPitch test')
        fixed_parameters = setdiff(fixed_parameters, roll_pitch_cong_parameters);
    case 'All'
        disp('All rotational dynamics test')
        fixed_parameters = setdiff(fixed_parameters, all_parameters);
    case {'AllCong', 'AllCong_c','AllCong_disc_c'}
        disp('All rotational dynamics test')
        fixed_parameters = setdiff(fixed_parameters, all_cong_parameters);
    otherwise
        error('Unkown test: %s', estimation_mode);
end

for i = 1:size(fixed_parameters,2)
    nonlinear_greybox_model.Parameters(fixed_parameters(i)).Fixed = true;
end

%Sets the sign of the parameters
positive_parameters = [1:12, 23:28];
negative_parameters = [13:22];
for i = 1:size(positive_parameters,2)
    nonlinear_greybox_model.Parameters(positive_parameters(i)).Minimum = 0;
end

for i = 1:size(negative_parameters,2)
    nonlinear_greybox_model.Parameters(negative_parameters(i)).Maximum = 0;
    nonlinear_greybox_model.Parameters(negative_parameters(i)).Minimum = -10;
end


end

