 %% Initialise the parameters of the ROV estimation.
        [lin_acc_data, ang_vel_data, imu_time, thrusters_data, thrusters_time, states, states_time] = ...
            getSimulationData('simulator_runs/Actuators_1_2_5',0);
 estimation_mode = 'RollPitch';
 % Some constants
 Ts = 0;      % Sample time [s].                                                     
 m = 5;       % ROV mass[kg];       
 g = 9.82;   % Gravity[m/s^2]
 rho = 1000; % water density [kg/m^3]
 V = 0.012;       % Discplaced water volume [m^3]
 % Thruster placement from CO [m]
 
 lx1 = 0.16;
 ly1 = 0.11;
 ly2 = 0.11;
 lx2 = 0.16;
 ly3 = 0.11;
 lx5 = 0.2;
 ly4 = 0.11;
 lz6 = 1;
 zb = -0.15;
 
 % Parameters that will be estimated
 Xu_init = 1;
 Xu_dot_init = 1;
 Xu_abs_u_init = 1;
 Yv_init = 1;
 Yv_dot_init = 1;
 Yv_abs_v_init = 1;
 Zw_init = 1;
 Zw_dot_init = 1;
 Zw_abs_w_init = 1;
 Kp_init = 1;
 Kp_dot_init = -1;
 Kp_abs_p_init = 1;
 Mq_init = 1;
 Mq_dot_init = -1;
 Mq_abs_q_init = 1;
 Nr_init = 1;
 Nr_dot_init = 1;
 Nr_abs_r_init = 1;
 Ix_init = 13;
 Iy_init = 13;
 Iz_init = 13;
 
 % Initial states
 u_init = 0;
 v_init = 0;
 w_init = 0;
 p_init = ang_vel_data(1,1);
 q_init = ang_vel_data(1,2);
 r_init = ang_vel_data(1,3);
 fi_init = states(1,1);
 theta_init = states(1,2);
 
 parameter_strings = {'m';'g';'rho';'V';'lx1';'ly1';'ly2';'lx2';'ly3';'lx5';'ly4';'lz6';'zb';'Xu';'Xu_dot';'Xu_abs_u';'Yv';'Yv_dot';'Yv_abs_w';'Zw';'Zw_dot';'Zw_abs_w'; 'Kp';'Kp_dot'; 'Kp_abs_p'; 'Mq';'Mq_dot'; 'Mq_abs_q'; 'Nr';'Nr_dot';'Nr_abs_r';'Ix';'Iy';'Iz'};
 state_strings = {'u';'v';'w'; 'p'; 'q'; 'r';'fi';'theta'};
 state_units = {'m/s'; 'm/s'; 'm/s';'rad/s'; 'rad/s'; 'rad/s';'rad';'rad'};
 
 %% Set up the nglr object
 
 FileName      = strcat('rovMotionModel',estimation_mode);                                       % File describing the model structure.
  
  Order         = [8 6 8];                                                % Model orders [ny nu nx].
  

 Parameters    = [m; g; rho; V; lx1; ly1; ly2; lx2; ly3; lx5; ly4;    % Initial parameters.
                 lz6; zb; Xu_init; Xu_dot_init; Xu_abs_u_init;     
                 Yv_init; Yv_dot_init; Yv_abs_v_init; Zw_init;     
                 Zw_dot_init; Zw_abs_w_init; Kp_init; Kp_dot_init; 
                 Kp_abs_p_init; Mq_init; Mq_dot_init;              
                 Mq_abs_q_init; Nr_init; Nr_dot_init;              
                  Nr_abs_r_init; Ix_init; Iy_init; Iz_init];
              
 InitialStates = [u_init; v_init; w_init; p_init; q_init; r_init;     % Initial initial states.
                  fi_init; theta_init];                          
              
  
 
  nlgr = idnlgrey(FileName, Order, Parameters', InitialStates, Ts, ...
                      'Name', 'Rov Model', 'TimeUnit', 's');
  

 nlgr.InputName =  {'Thruster1'; 'Thruster2'; 'Thruster3'; 
                     'Thurster4'; 'Thruster5'; 'Thruster6'};
  
                nlgr.InputUnit =  {'%'; '%'; '%'; '%'; '%';'%'};
 
               nlgr.OutputName = state_strings;
               nlgr.OutputUnit = state_units;
 
 
 
 % Names on initial states
 nlgr = setinit(nlgr, 'Name', state_strings);
 
 
 nlgr = setinit(nlgr, 'Unit', state_units);
 
 % Demands on the initial states
 %nlgr.InitialStates(1).Minimum = eps(0);   % Longitudinal velocity > 0 for the model to be valid.
 
 % Set the parameter names
 nlgr = setpar(nlgr, 'Name', parameter_strings);
 
 % Set the parameter units 
 %nlgr = setpar(nlgr, 'Unit', {'kg'; 'm'; 'm'; 'N'; 'N/rad'; '1/m'}); 
 
 % Set minimum of the parameters
 %nlgr = setpar(nlgr, 'Minimum', num2cell(eps(0)*ones(6, 1)));   % All parameters > 0!
 
 % Set that some of the parameters are known the other parameters is to 
 % be estimated
 
fixed_parameters = [1:size(Parameters,1)];  % Stores the index of the parameters that is fixed
u_dot_estimate_parameter_index = [14, 16, 18, 21, 15]; % Parameters u_dot estimates
v_dot_estimate_parameter_index = [17, 19, 15, 21, 18]; % Parameters v_dot estimates
w_dot_estimate_parameter_index = [20, 22, 15, 18, 21]; % Parameters w_dot estimates
p_dot_estimate_parameter_index = [23, 25, 33, 34, 27, 30, 32, 24]; % Parameters p_dot estimates
%p_dot_estimate_parameter_index = [23, 25, 33, 34, 27, 30, 18, 21, 32, 24]; % Parameters p_dot estimates
q_dot_estimate_parameter_index = [26, 28, 32, 34, 24, 30, 33, 27]; % Parameters q_dot estimates
% q_dot_estimate_parameter_index = [26, 28, 32, 34, 24, 30, 15, 21, 33, 27]; % Parameters q_dot estimates
r_dot_estimate_parameter_index = [29, 31, 32, 33, 24, 27, 34, 30]; % Parameters r_dot estimates
%r_dot_estimate_parameter_index = [29, 31, 32, 33, 24, 27, 15, 18, 34, 30]; % Parameters r_dot estimates
  
  switch estimation_mode
      case 'Yaw'
         fixed_parameters = setdiff(fixed_parameters,r_dot_estimate_parameter_index)
      case 'RollPitch'
         fixed_parameters = setdiff(fixed_parameters, p_dot_estimate_parameter_index);
         fixed_parameters = setdiff(fixed_parameters, q_dot_estimate_parameter_index);
      otherwise
          error('Unkown test: %s', estimation_mode);
  end
 
 for i = 1:size(fixed_parameters,2)
  nlgr.Parameters(fixed_parameters(i)).Fixed = true;
 end
 
 nlgr.Name = estimation_mode;
 estmation_data = iddata();
 %%
 % With this, a textual summary of the entered IDNLGREY model structure is
 % obtained through PRESENT as follows.
 present(nlgr);
 %% Input-Output Data
 % At this point, we load the available input-output data. This file
 % contains data from three different experiments:
 %
 %    A. Simulated data with high stiffness tires [y1 u1].
 %    B. Simulated data with low stiffness tires  [y2 u2].
 %    C. Measured data from a Volvo V70           [y3 u3].
  %
  % In all cases, the sample time Ts = 0.1 seconds.
             
 z1 = iddata([zeros(size(ang_vel_data(1:40,:))), ang_vel_data(1:40,:), states(1:40,1:2)], thrusters_data(1:40,:),0.05,'Name', strcat(estimation_mode, 'data'));
 z1.InputName = nlgr.InputName;
 z1.InputUnit = nlgr.InputUnit;
 z1.OutputName = nlgr.OutputName;
 z1.OutputUnit = nlgr.OutputUnit;
opt = nlgreyestOptions;
opt.Display = 'full';
opt.SearchOption.MaxIter = 1;
tic
najs = nlgreyest(z1, nlgr,opt);
toc