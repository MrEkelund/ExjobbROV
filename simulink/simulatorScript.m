initialCondition = [0 0 0 1 0 0 0];
Ts = 0.01;
end_time = 20;
controller_nr = 4;
ft = 30;

% Reference signals
phi_ref_signal = 2;
phi_ref_time = 3;
phi_final_ref_time = 15;
phi_v_scaling = 1.5; % has to be between 1 and 2
phi_initial_value = 0;
phi_final_value = 1;
phi_amplitude = 1;
phi_frequency = 0.5;
phi_bias = 0;
phi_constant = 0;

theta_ref_signal = 2;
theta_ref_time = 3;
theta_final_ref_time = 15;
theta_v_scaling = 1.5; % has to be between 1 and 2
theta_initial_value = 0;
theta_final_value = 1;
theta_amplitude = 1;
theta_frequency = 0.5;
theta_bias = 0;
theta_constant = 0;

psi_ref_signal = 2;
psi_ref_time = 3;
psi_final_ref_time = 15;
psi_v_scaling = 1.5; % has to be between 1 and 2
psi_initial_value = 0;
psi_final_value = 1;
psi_amplitude = 1;
psi_frequency = 0.5;
psi_bias = 0;
psi_constant = 0;

p_ref_signal = 1;
p_ref_time = 3;
p_final_ref_time = 10;
p_v_scaling = 1.5; % has to be between 1 and 2
p_initial_value = 0;
p_final_value = 1;
p_amplitude = 1;
p_frequency = 0.5;
p_bias = 0;
p_constant = 0;

q_ref_signal = 1;
q_ref_time = 3;
q_final_ref_time = 10;
q_v_scaling = 1.5; % has to be between 1 and 2
q_initial_value = 0;
q_final_value = 1;
q_amplitude = 1;
q_frequency = 0.5;
q_bias = 0;
q_constant = 0;

r_ref_signal = 1;
r_ref_time = 3;
r_final_ref_time = 15;
r_v_scaling = 1.5; % has to be between 1 and 2
r_initial_value = 0;
r_final_value = 1;
r_amplitude = 1;
r_frequency = 0.5;
r_bias = 0;
r_constant = 0;

d_ref_signal = 3;
d_ref_time = 3;
d_final_ref_time = 10;
d_v_scaling = 1.5; % has to be between 1 and 2
d_initial_value = 0;
d_final_value = 1;
d_amplitude = 0.5;
d_frequency = 1;
d_bias = 0;
d_constant = 0;

use_noise = 1;
noise_power = 0.00001;
% Exact Lin feedforward
Kd = 1*diag([0.1,0.1,0.1]);
Kp = 1*diag([2,2.7,0.7]);
Ki = 1*diag([0.1,0.1,0.1]);

% Kd = 1*diag([2,0,0]);
% Kp = 1*diag([0.1,0,0]);
% Ki = 1*diag([0.1,0,0]);

% Kd = 1*diag([0,2.7,0]);
% Kp = 1*diag([0,0.1,0]);
% Ki = 1*diag([0,0.1,0]);
% 
% Kd = 1*diag([0,0,0.7]);
% Kp = 1*diag([0,0,0.1]);
% Ki = 1*diag([0,0,0.1]);


% global_to_local_and_thrust_alloc
PIDxP = 0;
PIDxI = 0;
PIDxD = 0;
PIDxN = 100;

PIDyP = 0;
PIDyI = 0;
PIDyD = 0;
PIDyN = 100;

PIDzP = 0;
PIDzI = 0;
PIDzD = 0;
PIDzN = 100;

% Exact Lin rate
Kd_rate = 0*diag([3.5,3.5,3]);
Kp_rate = diag([3.5,3.5,3]);
Ki_rate = diag([2,2,2]);

% Depth
Kd_depth = 0;
Kp_depth = 0;
Ki_depth = 0;

load_system('simulator')

% Controller setup
set_param('simulator/noise', 'value', sprintf('%f',use_noise));

set_param('simulator/Controllers/Exact_lin_attitude/Kd', 'value', mat2str(Kd));
set_param('simulator/Controllers/Exact_lin_attitude/Kp', 'value', mat2str(Kp));
set_param('simulator/Controllers/Exact_lin_attitude/Ki', 'value', mat2str(Ki));
set_param('simulator/Controllers/Exact_lin_attitude/Ts', 'value', sprintf('%f',Ts));

set_param('simulator/Controllers/global_to_local_and_thrust_alloc/PIDxP', 'Value', sprintf('%f',PIDxP));
set_param('simulator/Controllers/global_to_local_and_thrust_alloc/PIDxI', 'Value', sprintf('%f',PIDxI));
set_param('simulator/Controllers/global_to_local_and_thrust_alloc/PIDxD', 'Value', sprintf('%f',PIDxD));
set_param('simulator/Controllers/global_to_local_and_thrust_alloc/PIDxN', 'Value', sprintf('%f',PIDxN));
set_param('simulator/Controllers/global_to_local_and_thrust_alloc/PIDyP', 'Value', sprintf('%f',PIDyP));
set_param('simulator/Controllers/global_to_local_and_thrust_alloc/PIDyI', 'Value', sprintf('%f',PIDyI));
set_param('simulator/Controllers/global_to_local_and_thrust_alloc/PIDyD', 'Value', sprintf('%f',PIDyD));
set_param('simulator/Controllers/global_to_local_and_thrust_alloc/PIDyN', 'Value', sprintf('%f',PIDyN));
set_param('simulator/Controllers/global_to_local_and_thrust_alloc/PIDzP', 'Value', sprintf('%f',PIDzP));
set_param('simulator/Controllers/global_to_local_and_thrust_alloc/PIDzI', 'Value', sprintf('%f',PIDzI));
set_param('simulator/Controllers/global_to_local_and_thrust_alloc/PIDzD', 'Value', sprintf('%f',PIDzD));
set_param('simulator/Controllers/global_to_local_and_thrust_alloc/PIDzN', 'Value', sprintf('%f',PIDzN));

set_param('simulator/Controllers/Exact_lin_rate/Kd', 'value', mat2str(Kd_rate));
set_param('simulator/Controllers/Exact_lin_rate/Kp', 'value', mat2str(Kp_rate));
set_param('simulator/Controllers/Exact_lin_rate/Ki', 'value', mat2str(Ki_rate));
set_param('simulator/Controllers/Exact_lin_rate/Ts', 'value', sprintf('%f',Ts));

set_param('simulator/Controllers/Depth_PI/Kd', 'value', mat2str(Kd_depth));
set_param('simulator/Controllers/Depth_PI/Kp', 'value', mat2str(Kp_depth));
set_param('simulator/Controllers/Depth_PI/Ki', 'value', mat2str(Ki_depth));
set_param('simulator/Controllers/Depth_PI/Ts', 'value', sprintf('%f',Ts));

% Set step time and step size
sim_list = {'phi','theta','psi','p','q','r','d'};
for i = 1:length(sim_list)
    set_param(sprintf('simulator/ref_signals/%s_ref_signal',sim_list{i}), 'Value', sprintf('%f',eval(strcat(sim_list{i},'_ref_signal'))));
    set_param(sprintf('simulator/ref_signals/%s_step/start_step_time', sim_list{i}), 'Value', sprintf('%f',eval(strcat(sim_list{i},'_ref_time'))));
    set_param(sprintf('simulator/ref_signals/%s_step/step_time_final', sim_list{i}), 'Value', sprintf('%f',eval(strcat(sim_list{i},'_final_ref_time'))));
    set_param(sprintf('simulator/ref_signals/%s_step/v_scaling', sim_list{i}), 'Value', sprintf('%f',eval(strcat(sim_list{i},'_v_scaling'))));
    set_param(sprintf('simulator/ref_signals/%s_step/initial_value', sim_list{i}),'Value', sprintf('%f',eval(strcat(sim_list{i},'_initial_value'))));
    set_param(sprintf('simulator/ref_signals/%s_step/final_value', sim_list{i}),'Value', sprintf('%f',eval(strcat(sim_list{i},'_final_value'))));
    set_param(sprintf('simulator/ref_signals/%s_sin/sin_amplitude', sim_list{i}),'Value', sprintf('%f',eval(strcat(sim_list{i},'_amplitude'))));
    set_param(sprintf('simulator/ref_signals/%s_sin/sin_frequency', sim_list{i}),'Value', sprintf('%f',eval(strcat(sim_list{i},'_frequency'))));
    set_param(sprintf('simulator/ref_signals/%s_sin/sin_bias', sim_list{i}),'Value', sprintf('%f',eval(strcat(sim_list{i},'_bias'))));
    set_param(sprintf('simulator/ref_signals/%s_sin/start_step_time', sim_list{i}), 'Value', sprintf('%f',eval(strcat(sim_list{i},'_ref_time'))));
    set_param(sprintf('simulator/ref_signals/%s_sin/step_time_final', sim_list{i}), 'Value', sprintf('%f',eval(strcat(sim_list{i},'_final_ref_time'))));
    set_param(sprintf('simulator/ref_signals/%s_ref_constant', sim_list{i}),'Value', sprintf('%f',eval(strcat(sim_list{i},'_constant'))));
end


% Initial condition for the model
set_param('simulator/ROV_model/n', 'InitialCondition', sprintf('%f',initialCondition(4)))
set_param('simulator/ROV_model/e1', 'InitialCondition', sprintf('%f',initialCondition(5)))
set_param('simulator/ROV_model/e2', 'InitialCondition', sprintf('%f',initialCondition(6)))
set_param('simulator/ROV_model/e3', 'InitialCondition', sprintf('%f',initialCondition(7)))
set_param('simulator/ROV_model/p', 'InitialCondition', sprintf('%f',initialCondition(1)))
set_param('simulator/ROV_model/q', 'InitialCondition', sprintf('%f',initialCondition(2)))
set_param('simulator/ROV_model/r', 'InitialCondition', sprintf('%f',initialCondition(3)))

load('EstimatedParameters')
% Set model parameters
for i=1:10
    set_param(sprintf('simulator/ROV_model/GetParameters/Params%i',i), 'Value', sprintf('%f',EstimatedParams(i)));
end

for i=1:10
    set_param(sprintf('simulator/Controllers/Exact_lin_attitude/GetParameters/Params%i',i), 'Value', sprintf('%f',EstimatedParams(i)));
end

% setup correct sampling time
for i=1:7       
    set_param(sprintf('simulator/ROV_model/white_noise%i',i), 'Ts', sprintf('%f',Ts));
    set_param(sprintf('simulator/ROV_model/white_noise%i',i), 'Cov', sprintf('%f',noise_power));
end

set_param('simulator/controller', 'value', sprintf('%f',controller_nr));

configSet = getActiveConfigSet('simulator');
set_param(configSet, 'SolverType', 'Fixed-step')
set_param(configSet,'Solver','ode4')
set_param(configSet,'FixedStep',sprintf('%f',Ts));
set_param(configSet,'StopTime',sprintf('%f',end_time));
set_param('simulator','SimulationCommand','Update');
time = [0:Ts:end_time];

y=sim('simulator', configSet);
simOut=y.get('yout');


units = {'rad', 'rad', 'rad', 'rad/s', 'rad/s', 'rad/s', 'm'};
ylabel_ent = {'Angle', 'Angle', 'Angle', 'Angle Velocity', 'Angle Velocity', 'Angle Velocity', 'Depth'};
legend_ent = {'\phi', '\theta', '\psi', 'p',  'q',  'r',  'd'};
legend_ent_ref = {'\phi_{ref}', '\theta_{ref}', '\psi_{ref}', 'p_{ref}', 'q_{ref}', 'r_{ref}', 'd_{ref}'};
% close all
%figure('units', 'normalized', 'position', [0 0.5 .5 .41])
label_name = {'p','q','r'};
for i = 1:3
    %subplot(3,1,i)
    figure(i+3)
    plot(time,[simOut(:,i+10) simOut(:,i+3)],'LineWidth',2)
    h = legend({legend_ent_ref{i+3}, legend_ent{i+3}});
    set(h,'FontSize',ft);
    h = ylabel(strcat(ylabel_ent{i+3},'[', units{i+3}, ']'));
    set(h,'FontSize',ft);
    h = xlabel('Time [s]');
    set(h,'FontSize',ft);
    title(legend_ent{i+3})
    set(gca,'FontSize',ft)
end

%figure('units', 'normalized', 'position', [0.5 0 .5 1])
% for i = 1:3
%     figure(i)
% %     subplot(3,1,i)
%     plot(time,[simOut(:,i+7) simOut(:,i)],'LineWidth',2)
%     h = legend({legend_ent_ref{i}, legend_ent{i}});
%     set(h,'FontSize',ft);
%     h = ylabel(strcat(ylabel_ent{i},'[', units{i}, ']'));
%     set(h,'FontSize',ft);
%     h = xlabel('Time [s]');
%     set(h,'FontSize',ft);
%     title(legend_ent{i})
%     set(gca,'FontSize',ft)
%     axis([0 end_time -0.1 1.5])
% end

%figure('units', 'normalized', 'position', [0 0 .5 .41])
% label_name = {'u_1','u_2','u_3','u_4','u_5','u_6'};
% for i = 1:6
%     figure(i+6)
%     subplot(3,2,i)
%     plot(time,simOut(:,i+14))
%     ylabel(label_name{i})
% end
%%

print -f4 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simStepAllPs3e10a1.eps'
%print -f1 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinPhiA05.eps'
%print -f4 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinAllPA1.eps'

print -f5 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simStepAllQs3e10a1.eps'
%print -f2 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinThetaA05.eps'
%print -f5 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinAllQA1.eps'

print -f6 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simStepAllRs3e10a1.eps'
%print -f3 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinPsiA05.eps'
%print -f6 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinAllRA1.eps'

%%
%print -f1 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simStepPhis3e10a1.eps'
%print -f1 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinPhiA05.eps'
%print -f1 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinPhiA1.eps'

%print -f2 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simStepThetas3e10a1.eps'
%print -f2 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinThetaA05.eps'
%print -f2 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinThetaA1.eps'

%print -f3 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simStepPsis3e10a1.eps'
%print -f3 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinPsiA05.eps'
%print -f3 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinPsiA1.eps'

%print -f4 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simStepPs3e10a1.eps'
%print -f4 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinPA05.eps'
%print -f4 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinPA1.eps'

%print -f5 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simStepQs3e10a1.eps'
%print -f5 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinQA05.eps'
%print -f5 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinQA1.eps'

%print -f6 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simStepRs3e10a1.eps'
%print -f6 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinRA05.eps'
%print -f6 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/simSinRA1.eps'