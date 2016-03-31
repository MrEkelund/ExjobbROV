function [nonlinear_greybox_model, input_data, output_data, Ts] = setupEstimation(parameters, parameter_strings, estimation_mode, simulation, filepath, plotting)
%setupEstimation Setups the nonlinear model of the rov and reads data
%   Detailed explanation goes here

%% Read from data files
switch simulation
    case 0
        disp(sprintf('Loading test data from %s',filepath));
       [lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time,Ts]= ...
            getTestData(filepath, plotting);
    case 1
        disp(sprintf('Loading simulated data from %s',filepath));
        [lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time,Ts] = ...
            getSimulationData(filepath,plotting);
    otherwise
        error('Simulation can only be 0 or 1');
end

output_data = [zeros(size(ang_vel_data)), ang_vel_data , states(:,1:2)];
input_data = thrusters_data;

%% Setup the non linear greybox model
Ts_model = 0;      % Sample time [s].  
% Initial states
u_init = 0;
v_init = 0;
w_init = 0;
p_init = ang_vel_data(1,1);
q_init = ang_vel_data(1,2);
r_init = ang_vel_data(1,3);
fi_init = states(1,1);
theta_init = states(1,2);

file_name  = strcat('rovMotionModel',estimation_mode); % File describing the model structure.

disp(sprintf('Using %s %s',file_name,'as model file'));

order = [8 6 8]; % Model orders [ny nu nx].

initial_states = [u_init; v_init; w_init; p_init; q_init; r_init;     % Initial initial states.
    fi_init; theta_init];

nonlinear_greybox_model = idnlgrey(file_name, order, parameters', initial_states, Ts_model, ...
    'Name', 'Rov Model', 'TimeUnit', 's');

%% Setup names for the nonlinear greybox
nonlinear_greybox_model.Name = estimation_mode;

% Names on input
nonlinear_greybox_model.InputName =  {'Thruster1'; 'Thruster2'; 'Thruster3';
    'Thurster4'; 'Thruster5'; 'Thruster6'};
nonlinear_greybox_model.InputUnit =  {'%'; '%'; '%'; '%'; '%';'%'};

nonlinear_greybox_model.OutputName = {'u';'v';'w'; 'p'; 'q'; 'r';'fi';'theta'};
nonlinear_greybox_model.OutputUnit = {'m/s'; 'm/s'; 'm/s';'rad/s'; 'rad/s'; 'rad/s';'rad';'rad'};

% Names on initial states
nonlinear_greybox_model = setinit(nonlinear_greybox_model, 'Name', {'u';'v';'w'; 'p'; 'q'; 'r';'fi';'theta'});
nonlinear_greybox_model = setinit(nonlinear_greybox_model, 'Unit', {'m/s'; 'm/s'; 'm/s';'rad/s'; 'rad/s'; 'rad/s';'rad';'rad'});

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
p_dot_congregated_estimate_parameter_index = [33, 34, 35, 37, 38, 39, 40];
%q_dot_congregated_estimate_parameter_index = [32, 34, 36, 41, 42, 43, 44];
q_dot_congregated_estimate_parameter_index = [36, 41, 42, 43, 44];

% Without translation dynamics
p_dot_estimate_parameter_index = [23, 25, 33, 34, 27, 30, 32, 24]; % Parameters p_dot estimates
q_dot_estimate_parameter_index = [26, 28, 32, 34, 24, 30, 33, 27]; % Parameters q_dot estimates
r_dot_estimate_parameter_index = [29, 31, 32, 33, 24, 27, 34, 30]; % Parameters r_dot estimates

% With translation dynamics
%p_dot_estimate_parameter_index = [23, 25, 33, 34, 27, 30, 18, 21, 32, 24]; % Parameters p_dot estimates
%q_dot_estimate_parameter_index = [26, 28, 32, 34, 24, 30, 15, 21, 33, 27]; % Parameters q_dot estimates
%r_dot_estimate_parameter_index = [29, 31, 32, 33, 24, 27, 15, 18, 34, 30]; % Parameters r_dot estimates

% Sets which parameters that will be estimated
switch estimation_mode
    case 'Yaw'
        disp('Yaw test')
        fixed_parameters = setdiff(fixed_parameters,r_dot_estimate_parameter_index);
    case 'RollPitch'
        disp('RollPitch test')
        fixed_parameters = setdiff(fixed_parameters, p_dot_estimate_parameter_index);
        fixed_parameters = setdiff(fixed_parameters, q_dot_estimate_parameter_index);
    case 'RollPitchCongregated'
        disp('RollPitch test')
        fixed_parameters = setdiff(fixed_parameters, p_dot_congregated_estimate_parameter_index);
        fixed_parameters = setdiff(fixed_parameters, q_dot_congregated_estimate_parameter_index);
    case 'Pitch'
        disp('Pitch test')
        fixed_parameters = setdiff(fixed_parameters, q_dot_estimate_parameter_index);
    case 'PitchCongregated'
        disp('PitchCongreted test')
        fixed_parameters = setdiff(fixed_parameters, q_dot_congregated_estimate_parameter_index);
    otherwise
        error('Unkown test: %s', estimation_mode);
end

for i = 1:size(fixed_parameters,2)
    nonlinear_greybox_model.Parameters(fixed_parameters(i)).Fixed = true;
end

%Sets the sign of the parameters
positive_parameters = [1:12, 32:34, 35, 36];
% negative_parameters = [13:size(parameters,1)-3];
negative_parameters = [15 18 21 24 27 30];
for i = 1:size(positive_parameters,2)
    nonlinear_greybox_model.Parameters(positive_parameters(i)).Minimum = 0;
end

for i = 1:size(negative_parameters,2)
    nonlinear_greybox_model.Parameters(negative_parameters(i)).Maximum = 0;
end

end

