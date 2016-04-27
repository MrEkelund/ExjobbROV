function [nonlinear_greybox_model, data, val_data] = ...
    setupEstimation(parameters, parameter_strings, estimation_mode, simulation, filepath, plotting, detrend_enable)
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
            case 'Yaw0404'
                disp('Loading yaw test data from 2016-04-04');
                data = loadYaw0404();
            case 'RollPitch0404'
                disp('Loading roll pitch test data from 2016-04-04');
                data = loadRollPitch0404();
            case 'Pitch0404'
                disp('Loading pitch test data from 2016-04-04');
                data = loadPitch0404();
            case 'All0404'
                disp('Loading all test data from 2016-04-04');
                data = loadAll0404();
            case 'All0418'
                disp('Loading all test data from 2016-04-18');
                data = loadAll0418();
            case 'Yaw0321'
                disp('Loading yaw test data from 2016-03-21');
                data = loadYaw0321();
            case 'RollPitch0321'
                disp('Loading roll pitch test data from 2016-03-21');
                data = loadRollPitch0321();
            case 'Pitch0321'
                disp('Loading pitch test data from 2016-03-21');
                data = loadPitch0321();
            otherwise
                disp(sprintf('Loading test data from %s',filepath));
                [lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time,Ts]= ...
                    getTestData(filepath, plotting);
                output_data = ang_vel_data;
                input_data = [thrusters_data, antiModAngles(states(:,1:3))];
                data = iddata(output_data, input_data,  Ts);
        end
    case 1 % simulation
        disp(sprintf('Loading simulated data from %s',filepath));
        [lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time,Ts] = ...
            getSimulationData(filepath,plotting);
        output_data = ang_vel_data;
        input_data = [thrusters_data, antiModAngles(states(:,1:3))];
        data = iddata(output_data, input_data, Ts);
    otherwise
        error('Simulation can only be 0 or 1');
end

switch estimation_mode
    case 'Yaw'
        data = data(:,[3],[3, 4, 7, 8]);
        data.InputName =  {'Thruster3'; 'Thruster4';'fi';'theta'};
        data.InputUnit =  {'%';'%';,'rad';'rad'};
        data.OutputName = {'r'};
        data.OutputUnit = {'rad/s'};
    case 'YawCong'
        data = data(:,[3],[3, 4, 7, 8]);
        data.InputName =  {'Thruster3'; 'Thruster4';'fi';'theta'};
        data.InputUnit =  {'%';'%';,'rad';'rad'};
        data.OutputName = {'r'};
        data.OutputUnit = {'rad/s'};
    case 'RollPitch'
        data = data(:,[1, 2],[1, 2, 5, 6, 7, 8]);
        data.InputName =  {'Thruster1';'Thruster2';'Thruster5';'Thruster6';'fi';'theta'};
        data.InputUnit =  {'%';'%';'%';'%';'rad';'rad'};
        data.OutputName = {'p','q'};
        data.OutputUnit = {'rad/s','rad/s'};
    case 'RollPitchCong'
        data = data(:,[1, 2],[1, 2, 5, 6, 7, 8]);
        data.InputName =  {'Thruster1';'Thruster2';'Thruster5';'Thruster6';'fi';'theta'};
        data.InputUnit =  {'%';'%';'%';'%';'rad';'rad'};
        data.OutputName = {'p','q'};
        data.OutputUnit = {'rad/s','rad/s'};
    case 'Pitch'
        data = data(:,[2, 5],[1, 2, 5]);
        data.InputName =  {'Thruster1';'Thruster2';'Thruster5'};
        data.InputUnit =  {'%';'%';'%'};
        data.OutputName = {'q','theta'};
        data.OutputUnit = {'rad/s','rad'};
    case 'PitchCongregated'
        data = data(:,[2],[1, 2, 5, 8]);
        data.InputName =  {'Thruster1';'Thruster2';'Thruster5';'theta'};
        data.InputUnit =  {'%';'%';'%';'rad'};
        data.OutputName = {'q'};
        data.OutputUnit = {'rad/s'};
    case 'All'
        data = data(:,[1, 2, 3],[1, 2, 3, 4, 5, 6, 7, 8]);
        data.InputName =  {'Thruster1';'Thruster2';'Thruster3';'Thruster4';'Thruster5';'Thruster6';'fi';'theta'};
        data.InputUnit =  {'%';'%';'%';'%';'%';'%';'rad';'rad'};
        data.OutputName = {'p','q','r'};
        data.OutputUnit = {'rad/s','rad/s','rad/s'};    
    case 'AllSimple'
        data = data(:,[1, 2, 3],[1, 2, 3, 4, 5, 6, 7, 8]);
        data.InputName =  {'Thruster1';'Thruster2';'Thruster3';'Thruster4';'Thruster5';'Thruster6';'fi';'theta'};
        data.InputUnit =  {'%';'%';'%';'%';'%';'%';'rad';'rad'};
        data.OutputName = {'p','q','r'};
        data.OutputUnit = {'rad/s','rad/s','rad/s'};    
    case 'AllCong'
        data = data(:,[1, 2, 3],[1, 2, 3, 4, 5, 6, 7, 8]);
        data.InputName =  {'Thruster1';'Thruster2';'Thruster3';'Thruster4';'Thruster5';'Thruster6';'fi';'theta'};
        data.InputUnit =  {'%';'%';'%';'%';'%';'%';'rad';'rad'};
        data.OutputName = {'p','q','r'};
        data.OutputUnit = {'rad/s','rad/s','rad/s'};        
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
nx = length(data.OutputName);

initial_states = zeros(nx,length(data.ExperimentName));
for i = 1:length(data.ExperimentName)
    temp_data = getexp(data, i);
    initial_states(:,i) = temp_data.OutputData(1,:);
end

file_name  = strcat('rovMotionModel',estimation_mode); % File describing the model structure.

disp(sprintf('Using %s %s',file_name,'as model file'));

order = [ny nu nx]; % Model orders [ny nu nx].

nonlinear_greybox_model = idnlgrey(file_name, order, parameters, initial_states, Ts_model, ...
    'Name', 'Rov Model', 'TimeUnit', 's');

%% Setup names for the nonlinear greybox
nonlinear_greybox_model.Name = estimation_mode;

% Names on input
nonlinear_greybox_model.InputName =  data.InputName;
nonlinear_greybox_model.InputUnit =  data.InputUnit;

nonlinear_greybox_model.OutputName = data.OutputName;
nonlinear_greybox_model.OutputUnit = data.OutputUnit;

% Names on initial states
nonlinear_greybox_model = setinit(nonlinear_greybox_model, 'Name', data.OutputName);
nonlinear_greybox_model = setinit(nonlinear_greybox_model, 'Unit', data.OutputUnit);

% Set the parameter names
nonlinear_greybox_model = setpar(nonlinear_greybox_model, 'Name', parameter_strings);

%% Setup parameters
% Set that some of the parameters are known the other parameters is to
% be estimated

fixed_parameters = [1:size(parameters,1)];  % Stores the index of the parameters that is fixed

% Translation dynamics
u_dot_estimate_parameter_index = [14, 16, 18, 21, 15]; % Parameters u_dot estimates
v_dot_estimate_parameter_index = [17, 19, 15, 21, 18]; % Parameters v_dot estimates
w_dot_estimate_parameter_index = [20, 22, 15, 18, 21]; % Parameters w_dot estimates


% Congregated parameters
p_dot_congregated_estimate_parameter_index = [13, 35, 37, 38, 39, 40, 45];
q_dot_congregated_estimate_parameter_index = [13, 36, 41, 42, 43, 44, 46];

% Without translation dynamics
p_dot_estimate_parameter_index = [24, 27, 29, 30, 31, 32, 33, 34]; % Parameters p_dot estimates
q_dot_estimate_parameter_index = [13, 24, 26, 27, 28, 30, 32, 33, 34]; % Parameters q_dot estimates
r_dot_estimate_parameter_index = [13, 23, 24, 25, 27, 30, 32, 33, 34]; % Parameters r_dot estimates

r_dot_only_estimate_parameter_index = [29, 30, 31, 34]; % Parameters q_dot estimates
q_dot_only_estimate_parameter_index = [13, 26, 27, 28, 33]; % Parameters q_dot estimates
p_dot_only_estimate_parameter_index = [13, 23, 24, 25, 32]; % Parameters r_dot estimates

p_dot_Cong_estimate_parameter_index = [13, 24, 27, 29, 30, 31, 47, 35]; % Parameters p_dot estimates
q_dot_Cong_estimate_parameter_index = [13, 24, 26, 27, 28, 30, 36, 48]; % Parameters q_dot estimates
r_dot_Cong_estimate_parameter_index = [23, 24, 25, 27, 30, 47, 49, 50]; % Parameters r_dot estimates

p_dot_cong_only_estimate_parameter_index = [13 23, 25, 35]; % Parameters p_dot estimates
q_dot_cong_only_estimate_parameter_index = [13, 26, 28, 36]; % Parameters q_dot estimates
r_dot_cong_only_estimate_parameter_index = [29, 31, 47]; % Parameters q_dot estimates

% With translation dynamics
%p_dot_estimate_parameter_index = [23, 25, 33, 34, 27, 30, 18, 21, 32, 24]; % Parameters p_dot estimates
%q_dot_estimate_parameter_index = [26, 28, 32, 34, 24, 30, 15, 21, 33, 27]; % Parameters q_dot estimates
%r_dot_estimate_parameter_index = [29, 31, 32, 33, 24, 27, 15, 18, 34, 30]; % Parameters r_dot estimates

% Sets which parameters that will be estimated  
switch estimation_mode
    case 'Yaw'
        disp('Yaw test')
        fixed_parameters = setdiff(fixed_parameters, r_dot_only_estimate_parameter_index);
     case 'YawCong'
        disp('Yaw test')
        fixed_parameters = setdiff(fixed_parameters, r_dot_cong_only_estimate_parameter_index);       
    case 'RollPitch'
        disp('RollPitch test')
        fixed_parameters = setdiff(fixed_parameters, p_dot_only_estimate_parameter_index);
        fixed_parameters = setdiff(fixed_parameters, q_dot_only_estimate_parameter_index);
    case 'RollPitchCong'
        disp('RollPitch test')
        fixed_parameters = setdiff(fixed_parameters, p_dot_cong_only_estimate_parameter_index);
        fixed_parameters = setdiff(fixed_parameters, q_dot_cong_only_estimate_parameter_index);
    case 'Pitch'
        disp('Pitch test')
        fixed_parameters = setdiff(fixed_parameters, q_dot_only_estimate_parameter_index);
    case 'All'
        disp('All rotational dynamics test')
        fixed_parameters = setdiff(fixed_parameters, p_dot_estimate_parameter_index);
        fixed_parameters = setdiff(fixed_parameters, q_dot_estimate_parameter_index);
        fixed_parameters = setdiff(fixed_parameters, r_dot_estimate_parameter_index);
    case 'AllSimple'
        disp('All rotational dynamics test')
        fixed_parameters = setdiff(fixed_parameters, p_dot_only_estimate_parameter_index);
        fixed_parameters = setdiff(fixed_parameters, q_dot_only_estimate_parameter_index);
        fixed_parameters = setdiff(fixed_parameters, r_dot_only_estimate_parameter_index);
    case 'AllCong'
        disp('All rotational dynamics test')
        fixed_parameters = setdiff(fixed_parameters, p_dot_Cong_estimate_parameter_index);
        fixed_parameters = setdiff(fixed_parameters, q_dot_Cong_estimate_parameter_index);
        fixed_parameters = setdiff(fixed_parameters, r_dot_Cong_estimate_parameter_index);
    otherwise
        error('Unkown test: %s', estimation_mode);
end

for i = 1:size(fixed_parameters,2)
    nonlinear_greybox_model.Parameters(fixed_parameters(i)).Fixed = true;
end

%Sets the sign of the parameters
positive_parameters = [1:12, 32:34, 35, 36 50];
negative_parameters = [13:31];
for i = 1:size(positive_parameters,2)
    nonlinear_greybox_model.Parameters(positive_parameters(i)).Minimum = 0;
end

for i = 1:size(negative_parameters,2)
    nonlinear_greybox_model.Parameters(negative_parameters(i)).Maximum = 0;
end

end

