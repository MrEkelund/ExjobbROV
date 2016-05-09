function [nonlinear_greybox_model, data, val_data, initial_states_out, temp_parameters] = ...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation,...
    filepath, plotting, detrend_enable, sampling_fs, varargin)
%setupEstimation Setups the nonlinear model of the rov and reads data
%   Detailed explanation goes here

%Compile necessary file
if exist('nakeinterp1.mexa64') ~= 3
    disp('nakeinterp1.mexa64 not found...Compiling')
    mex('CFLAGS="\$CFLAGS -std=c99"', 'nakeinterp1.c')
end
    
temp_parameters = parameters;
%% Read from data files
switch simulation
    case 0 % Test
        switch filepath
            case 'Yaw0418'
                disp('Loading yaw test data from 2016-04-18');
                data = loadYaw0418(plotting, sampling_fs);
            case 'RollPitch0418'
                disp('Loading roll pitch test data from 2016-04-18');
                data = loadRollPitch0418(plotting, sampling_fs);
            case 'All0418'
                disp('Loading all test data from 2016-04-18');
                [data, initial_states_and_mag] = loadAll0418(plotting, sampling_fs, detrend_enable);
            otherwise
                disp(sprintf('Loading test data from %s',filepath));
                [imu_data, mag_data, thrusters_data, time]= ...
                    getTestData(All_filepath, plotting, sampling_fs);
                output_data = [imu_data, mag_data];
                input_data = thrusters_data;
                data = iddata(output_data, input_data, 1/sampling_fs);
        end
    case 1 % simulation
        temp_parameters = parameters + [zeros(12,1); varargin{3}*randn(size(parameters(13:28))); 0];
        [data, initial_states_and_mag] = simulateROV(temp_parameters , sampling_fs, varargin{1}, varargin{2}, varargin{4});
    otherwise
        error('Simulation can only be 0 or 1');
end

ne = length(data.ExperimentName); % number of experiments
if ne == 1
    if simulation
        mag = [10 10 10];
    else
        mag = data.OutputData(1,7:9);
    end
    smooth = initialSmoother(1/sampling_fs, data.OutputData.', mag);
    sample_num = ceil(size(data.OutputData,1)/2);
    initial_states_and_mag = [initial_states_and_mag, [smooth(5:end, sample_num); smooth(1:4, sample_num)]];   
end

switch estimation_mode 
    case {'All','AllCong', 'AllCong_c','AllCong_disc_c','AllSuperCong_c'}
        if exist('rovMotionModelAllCong_c.mexa64') ~= 3
            disp('rovMotionModelAllCong_c.mexa64 not found...Compiling')
            mex rovMotionModelAllCong_c.c
        end
        data = data(:,[1:6],:);
        data.InputName =  {'Thruster1';'Thruster2';'Thruster3';'Thruster4';'Thruster5';'Thruster6'};
        data.InputUnit =  {'%','%','%','%','%','%'};
        data.OutputName = {'p', 'q', 'r', 'a_x', 'a_y', 'a_z'};
        data.OutputUnit = {'rad/s','rad/s','rad/s', 'm/s', 'm/s', 'm/s'};
        state_name = {'p', 'q', 'r', 'n', 'e1', 'e2','e3'};
        state_unit = {'rad/s', 'rad/s', 'rad/s', '','','',''};
    otherwise
        error('Unkown test: %s', estimation_mode);
end

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

%% Setup the non linear greybox model
Ts_model = 0;      % Sample time [s].
ny = length(data.OutputName);
nu = length(data.InputName);
nx = length(state_name);

initial_states = zeros(nx,length(data.ExperimentName));
initial_states_out = zeros(nx,length(data.ExperimentName) + length(val_data.ExperimentName));
for i = 1:length(data.ExperimentName)
    temp_data = getexp(data, i);
    initial_states(:,i) = [temp_data.OutputData(1,1:3).'; initial_states_and_mag(4:7,i)];
    %     initial_states_out(:,i) = [temp_data.OutputData(1,1:3).'; initial_states_and_mag(i,4:7).'; initial_states_and_mag(i,8:10)];
    initial_states_out(:,i) = [temp_data.OutputData(1,1:3).'; initial_states_and_mag(4:7,i)];
end

j = length(data.ExperimentName);
for i = 1:length(val_data.ExperimentName)
    temp_data = getexp(val_data, i);
    %     initial_states_out(:,j+i) = [temp_data.OutputData(1,1:3).'; initial_states_and_mag(j+i,4:7).'; initial_states_and_mag(j+i,8:10).'];
    initial_states_out(:,j+i) = [temp_data.OutputData(1,1:3).'; initial_states_and_mag(4:7,j+i)];
end

% parameters = [parameters; initial_states_and_mag(1,8)];
% parameters = [parameters; initial_states_and_mag(1,9)];
% parameters = [parameters; initial_states_and_mag(1,10)];
% parameter_strings{end+1} = 'mag_n';
% parameter_strings{end+1} = 'mag_e';
% parameter_strings{end+1} = 'mag_d';

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
all_super_cong_parameters = [13:14, 16:17, 19:20, 22, 26:28];
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
    case 'AllSuperCong_c'
        disp('All rotational dynamics test')
        fixed_parameters = setdiff(fixed_parameters, all_super_cong_parameters);
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
    if i ~= 3
        nonlinear_greybox_model.Parameters(positive_parameters(i)).Maximum = 15;
    else
        nonlinear_greybox_model.Parameters(positive_parameters(i)).Maximum = 1200; % density
    end
end

for i = 1:size(negative_parameters,2)
    nonlinear_greybox_model.Parameters(negative_parameters(i)).Maximum = 0;
    nonlinear_greybox_model.Parameters(negative_parameters(i)).Minimum = -10;
end


end

