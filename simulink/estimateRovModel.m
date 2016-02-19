%% Initialise the parameters of the ROV estimation.
% 
[lin_acc_data, ang_vel_data, ori_data,time_vector, rc_data ,rc_time] = retriveImuData('../bag/super_2016-02-16-09-13-35.bag',0);

% Some constants
Ts = 0;      % Sample time [s].                                                     
m = 5;       % ROV mass[kg];       
g = 9.82;   % Gravity[m/s^2]
rho = 1000; % water density [kg/m^3]
V = 1;       % Discplaced water volume [m^3]
% Thruster placement from CO [m]

lx1 = 1;
ly1 = 1;
ly2 = 1;
lx2 = 1;
ly3 = 1;
lx5 = 1;
ly4 = 1;
lz6 = 1;
zb = 1;

% Parameters that will be estimated
Xu_init = 1;
Xu_dot_init = 1;
Xu_abs_u_init = 1;
Yv_init = 1;
Yv_dot_init = 1;
Yv_abs_w_init = 1;
Zw_init = 1;
Zw_dot_init = 1;
Zw_abs_w_init = 1;
Kp_init = 1;
Kp_dot_init = 1;
Kp_abs_p_init = 1;
Mq_init = 1;
Mq_dot_init = 1;
Mq_abs_q_init = 1;
Nr_init = 1;
Nr_dot_init = 1;
Nr_abs_r_init = 1;
Ix_init = 1;
Iy_init = 1;
Iz_init = 1;

% Initial states
u_init = 0;
v_init = 0;
w_init = 0;
p_init = ang_vel_data(1,1);
q_init = ang_vel_data(1,2);
r_init = ang_vel_data(1,3);
fi_init = ori_data(1,1);
theta_init = ori_data(1,2);

parameter_strings = {'m';'g';'rho';'V';'lx1';'ly1';'ly2';'lx2';'ly3';'lx5';'ly4';'lz6';'zb';'Xu';'Xu_dot';'Xu_abs_u';'Yv';'Yv_dot';'Yv_abs_w';'Zw';'Zw_dot';'Zw_abs_w'; 'Kp';'Kp_dot'; 'Kp_abs_p'; 'Mq';'Mq_dot'; 'Mq_abs_q'; 'Nr';'Nr_dot';'Nr_abs_r';'Ix';'Iy';'Iz'};
state_strings = {'u';'v';'w'; 'p'; 'q'; 'r';'fi';'theta'};
state_units = {'m/s'; 'm/s'; 'm/s';'rad/s'; 'rad/s'; 'rad/s';'rad';'rad'};

%% Set up the nglr object

FileName      = 'rovMotionModel';                                       % File describing the model structure.

Order         = [8 6 8];                                                % Model orders [ny nu nx].

Parameters    = [m; g; rho; V; lx1; ly1; ly2; lx2; ly3; lx5; ly4; ...   % Initial parameters.
                lz6; zb; Xu_init; Xu_dot_init; Xu_abs_u_init;     ...
                Yv_init; Yv_dot_init; Yv_abs_w_init; Zw_init;     ...
                Zw_dot_init; Zw_abs_w_init; Kp_init; Kp_dot_init; ...
                Kp_abs_p_init; Mq_init; Mq_dot_init;              ...
                Mq_abs_q_init; Nr_init; Nr_dot_init;              ...
                Nr_abs_r_init; Ix_init; Iy_init; Iz_init];
            
InitialStates = [u_init; v_init; w_init; p_init; q_init; r_init;    ... % Initial initial states.
                fi_init; theta_init];                          
            


nlgr = idnlgrey(FileName, Order, Parameters, InitialStates, Ts, ...
                    'Name', 'Rov Model', 'TimeUnit', 's');

nlgr.InputName =  {'Thruster1'; 'Thruster2'; 'Thruster3'; ...
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

fixed_parameters = [1:7];  % Stores the index of the parameters that is fixed
for i = 1:size(fixed_parameters,2)
 nlgr.Parameters(fixed_parameters(i)).Fixed = true;
end


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
load(fullfile(matlabroot, 'toolbox', 'ident', 'iddemos', 'data', 'vehicledata'));

%% A. System Identification Using Simulated High Tire Stiffness Data
% In our first vehicle identification experiment we consider simulated high
% tire stiffness data. A copy of the model structure nlgr and an IDDATA
% object z1 reflecting this particular modeling situation is first created.
% The 5 input signals are stored in u1 and the 3 output signals in y1. The
% slip inputs (generated from the wheel speed signals) for the front wheels
% were chosen to be sinusoidal with a constant offset; the yaw rate was
% also sinusoidal but with a different amplitude and frequency. In reality,
% this is a somewhat artificial situation, because one rarely excites the
% vehicle so much in the lateral direction.
nlgr1 = nlgr;
nlgr1.Name = 'Bicycle vehicle model with high tire stiffness';
z1 = iddata([], rc_data, , 'Name', 'Simulated high tire stiffness vehicle data');
z1.InputName = nlgr1.InputName;
z1.InputUnit = nlgr1.InputUnit;
z1.OutputName = nlgr1.OutputName;
z1.OutputUnit = nlgr1.OutputUnit;
z1.Tstart = 0;
z1.TimeUnit = 's';

%%
% The inputs and outputs are shown in two plot figures.
h_gcf = gcf;
set(h_gcf,'DefaultLegendLocation','southeast');
h_gcf.Position = [100 100 795 634];
for i = 1:z1.Nu
   subplot(z1.Nu, 1, i);
   plot(z1.SamplingInstants, z1.InputData(:,i));
   title(['Input #' num2str(i) ': ' z1.InputName{i}]);
   xlabel('');
   axis tight;
end
xlabel([z1.Domain ' (' z1.TimeUnit ')']);


%%
% *Figure 2:* Inputs to a vehicle system with high tire stiffness.

%%
for i = 1:z1.Ny
   subplot(z1.Ny, 1, i);
   plot(z1.SamplingInstants, z1.OutputData(:,i));
   title(['Output #' num2str(i) ': ' z1.OutputName{i}]);
   xlabel('');
   axis tight;
end
xlabel([z1.Domain ' (' z1.TimeUnit ')']);

%%
% *Figure 3:* Outputs from a vehicle system with high tire stiffness.

%%
% The next step is to investigate the performance of the initial model and
% for this we perform a simulation. Notice that the initial state has been
% fixed to a non-zero value as the first state (the longitudinal vehicle
% velocity) is used as denominator in the model structure. A comparison
% between the true and the simulated outputs (with the initial model) is
% shown in a plot window.
clf
compare(z1, nlgr1, [], compareOptions('InitialCondition', 'model'));

%%
% *Figure 4:* Comparison between true outputs and the simulated outputs of
% the initial vehicle model with high tire stiffness.

%%
% In order to improve the model fit, the two tire stiffness parameters Cx
% and Cy are next estimated, and a new simulation with the estimated
% model is carried out.
nlgr1 = nlgreyest(z1, nlgr1);

%%
% A comparison between the true and the simulated outputs (with the
% estimated model) is shown in a plot window.
compare(z1, nlgr1, [], compareOptions('InitialCondition', 'model'));

%%
% *Figure 5:* Comparison between true outputs and the simulated outputs of
% the estimated vehicle model with high tire stiffness.

%%
% The simulation performance of the estimated model is quite good. The
% estimated stiffness parameters are also close to the ones used in
% Simulink(R) to generate the true output data:
disp('                        True      Estimated');
fprintf('Longitudinal stiffness: %6.0f    %6.0f\n', 2e5, nlgr1.Parameters(4).Value);
fprintf('Lateral stiffness     : %6.0f    %6.0f\n', 5e4, nlgr1.Parameters(5).Value);

%% B. System Identification Using Simulated Low Tire Stiffness Data
% In the second experiment we repeat the modeling from the first
% experiment, but now with simulated low tire stiffness data.
nlgr2 = nlgr;
nlgr2.Name = 'Bicycle vehicle model with low tire stiffness';
z2 = iddata(y2, u2, 0.1, 'Name', 'Simulated low tire stiffness vehicle data');
z2.InputName = nlgr2.InputName;
z2.InputUnit = nlgr2.InputUnit;
z2.OutputName = nlgr2.OutputName;
z2.OutputUnit = nlgr2.OutputUnit;
z2.Tstart = 0;
z2.TimeUnit =  's';

%%
% The inputs and outputs are shown in two plot figures.
clf
for i = 1:z2.Nu
   subplot(z2.Nu, 1, i);
   plot(z2.SamplingInstants, z2.InputData(:,i));
   title(['Input #' num2str(i) ': ' z2.InputName{i}]);
   xlabel('');
   axis tight;
end
xlabel([z2.Domain ' (' z2.TimeUnit ')']);

%%
% *Figure 6:* Inputs to a vehicle system with low tire stiffness.

%%
clf
for i = 1:z2.Ny
   subplot(z2.Ny, 1, i);
   plot(z2.SamplingInstants, z2.OutputData(:,i));
   title(['Output #' num2str(i) ': ' z2.OutputName{i}]);
   xlabel('');
   axis tight;
end
xlabel([z2.Domain ' (' z2.TimeUnit ')']);

%%
% *Figure 7:* Outputs from a vehicle system with low tire stiffness.

%%
% Next we investigate the performance of the initial model (which has the
% same parameters as the initial high tire stiffness model). A comparison
% between the true and the simulated outputs (with the initial model) is
% shown in a plot window.
clf
compare(z2, nlgr2, [], compareOptions('InitialCondition', 'model'));

%%
% *Figure 8:* Comparison between true outputs and the simulated outputs of
% the initial vehicle model with low tire stiffness.

%%
% The two stiffness parameters are next estimated.
nlgr2 = nlgreyest(z2, nlgr2);

%%
% A comparison between the true and the simulated outputs (with the
% estimated model) is shown in a plot window.
compare(z2, nlgr2, [], compareOptions('InitialCondition', 'model'));

%%
% *Figure 9:* Comparison betweentrue outputs and the simulated outputs of
% the estimated vehicle model with low tire stiffness.

%%
% The simulation performance of the estimated model is again really good.
% Even with the same parameter starting point as was used in the high tire
% stiffness case, the estimated stiffness parameters are also here close to
% the ones used in Simulink to generate the true output data:
disp('                        True      Estimated');
fprintf('Longitudinal stiffness: %6.0f    %6.0f\n', 1e5, nlgr2.Parameters(4).Value);
fprintf('Lateral stiffness     : %6.0f    %6.0f\n', 2.5e4, nlgr2.Parameters(5).Value);

%% C. System Identification Using Measured Volvo V70 Data
% In the final experiment we consider data collected in a Volvo V70. As
% above, we make a copy of the generic vehicle model object nlgr and create
% a new IDDATA object containing the measured data. Here we have also
% increased the air resistance coefficient from 0.50 to 0.70 to better
% reflect the Volvo V70 situation.
nlgr3 = nlgr;
nlgr3.Name = 'Volvo V70 vehicle model';
nlgr3.Parameters(6).Value = 0.70;   % Use another initial CA for the Volvo data.
z3 = iddata(y3, u3, 0.1, 'Name', 'Volvo V70 data');
z3.InputName = nlgr3.InputName;
z3.InputUnit = nlgr3.InputUnit;
z3.OutputName = nlgr3.OutputName;
z3.OutputUnit = nlgr3.OutputUnit;
z3.Tstart = 0;
z3.TimeUnit = 's';

%%
% The inputs and outputs are shown in two plot figures. As can be seen, the
% measured data is rather noisy.
clf
for i = 1:z3.Nu
   subplot(z3.Nu, 1, i);
   plot(z3.SamplingInstants, z3.InputData(:,i));
   title(['Input #' num2str(i) ': ' z3.InputName{i}]);
   xlabel('');
   axis tight;
end
xlabel([z3.Domain ' (' z3.TimeUnit ')']);

%%
% *Figure 10:* Measured inputs from a Volvo V70 vehicle.

%%
clf
for i = 1:z3.Ny
   subplot(z3.Ny, 1, i);
   plot(z3.SamplingInstants, z3.OutputData(:,i));
   title(['Output #' num2str(i) ': ' z3.OutputName{i}]);
   xlabel('');
   axis tight;
end
xlabel([z3.Domain ' (' z3.TimeUnit ')']);

%%
% *Figure 11:* Measured outputs from a Volvo V70 vehicle.

%%
% Next we investigate the performance of the initial model with the initial
% states being estimated. A comparison between the true and the simulated
% outputs (with the initial model) is shown in a plot window.
nlgr3 = setinit(nlgr3, 'Value', {18.7; 0; 0});   % Initial initial states.
clf
compare(z3, nlgr3);

%%
% *Figure 12:* Comparison between measured outputs and the simulated outputs
% of the initial Volvo V70 vehicle model.

%%
% The tire stiffness parameters Cx and Cy are next estimated, in this case
% using the Levenberg-Marquardt search method, whereupon a new
% simulation with the estimated model is performed. In addition, we here
% estimate the initial value of the longitudinal velocity, whereas the
% initial values of the lateral velocity and the yaw rate are kept fixed.
nlgr3 = setinit(nlgr3, 'Fixed', {false; true; true});
nlgr3 = nlgreyest(z3, nlgr3, nlgreyestOptions('SearchMethod', 'lm'));

%%
% A comparison between the true and the simulated outputs (with the
% estimated model) is shown in a plot window.
compare(z3, nlgr3);

%%
% *Figure 13:* Comparison between measured outputs and the simulated outputs
% of the first estimated Volvo V70 vehicle model.

%%
% The estimated stiffness parameters of the final Volvo V70 model are
% reasonable, yet it is here unknown what their real values are.
disp('                        Estimated');
fprintf('Longitudinal stiffness: %6.0f\n', nlgr3.Parameters(4).Value);
fprintf('Lateral stiffness     : %6.0f\n', nlgr3.Parameters(5).Value);

%%
% Further information about the estimated Volvo V70 vehicle model is
% obtained through PRESENT. It is here interesting to note that the
% uncertainty related to the estimated lateral tire stiffness is quite high
% (and significantly higher than for the longitudinal tire stiffness). This
% uncertainty originates partly from that the lateral acceleration is
% varied so little during the test drive.
present(nlgr3);

%% Concluding Remarks
% Estimating the tire stiffness parameters is in practice a rather
% intricate problem. First, the approximations introduced in the model
% structure above are valid for a rather narrow operation region, and data
% during high accelerations, braking, etc., cannot be used. The stiffness
% also varies with the environmental condition, e.g., the surrounding
% temperature, the temperature in the tires and the road surface
% conditions, which are not accounted for in the used model structure.
% Secondly, the estimation of the stiffness parameters relies heavily on
% the driving style. When mostly going straight ahead as in the third
% identification experiment, it becomes hard to estimate the stiffness
% parameters (especially the lateral one), or put another way, the
% parameter uncertainties become rather high.

%% Additional Information
% For more information on identification of dynamic systems with System
% Identification Toolbox(TM) visit the
% <http://www.mathworks.com/products/sysid/ System Identification Toolbox> 
% product information page.