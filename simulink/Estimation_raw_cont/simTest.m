[parameters, parameters_strings] = initROVParameters();
EstimatedParams = parameters([13:28]);
eta_init = [1 0 0 0];
nu_init = [0 0 0];
initialCondition = [eta_init nu_init];
Ts = 1/100;
fs = 1/Ts;
N = 2000;

% setup simulator
load_system('quatSim')
set_param( 'quatSim/n', 'InitialCondition', sprintf('%f',initialCondition(1)) )
set_param( 'quatSim/e1', 'InitialCondition', sprintf('%f',initialCondition(2)) )
set_param( 'quatSim/e2', 'InitialCondition', sprintf('%f',initialCondition(3)) )
set_param( 'quatSim/e3', 'InitialCondition', sprintf('%f',initialCondition(4)) )
set_param( 'quatSim/p', 'InitialCondition', sprintf('%f',initialCondition(5)) )
set_param( 'quatSim/q', 'InitialCondition', sprintf('%f',initialCondition(6)) )
set_param( 'quatSim/r', 'InitialCondition', sprintf('%f',initialCondition(7)) )
for l=1:16
    set_param( sprintf('quatSim/GetParameters/Params%i',l), 'Value', sprintf('%f',EstimatedParams(l)));
end
%%
tau0 = [0:Ts:(N-1)*Ts;zeros(6,N)];
tend= (length(tau0)-1)/fs;
t=(0:1/fs:tend);
configSet = getActiveConfigSet('quatSim');
set_param(configSet, 'SolverType', 'Fixed-step')
set_param(configSet,'Solver','ode4')
set_param(configSet,'FixedStep',sprintf('%f',Ts));
set_param(configSet,'StopTime',sprintf('%f',tend));
set_param('quatSim','SimulationCommand','Update');
% generate thrust input signal
tauSim = timeseries(tau0,t);
hws = get_param(bdroot, 'modelworkspace');
hws.assignin('tauSim', tauSim);
y0=sim('quatSim',configSet);
meas = y0.get('yout').';
smooth = initialSmoother(Ts, meas(1:end-4,:)+ 0.1*randn(6,length(meas(1:end-4,:))));
%initial_state(1:4).' - meas(end-3:end,end)
%returns in yaw pitch roll order.
smooth_euler = quat2eul(smooth(1:4,:).');
meas_euler = quat2eul(meas(7:10,:).');
plot([smooth_euler(:,3), meas_euler(:,3)])

%%
All_filepath = {
    fullfile('bag','all_1_2016-04-18-14-00-41.bag');
%     fullfile('bag','all_2_2016-04-18-14-56-58.bag');
%     fullfile('bag','all_3_2016-04-18-15-04-50.bag');
%     fullfile('bag','all_4_2016-04-18-15-06-06.bag');
%     fullfile('bag','all_5_2016-04-18-15-06-44.bag')
    };

data = cell(size(All_filepath,1),1);
initial_states = zeros(length(All_filepath),7);
for i = 1:size(All_filepath,1)
    [imu_data, mag_data, thrusters_data, ~, initial_state]= ...
        getTestData(All_filepath{i}, 0, 1/Ts);
    imu_data(:,1:3) = detrend(imu_data(:,1:3), 'constant');
    output_data = [imu_data];
    input_data  = thrusterLookup(thrusters_data)';
end
%%

smooth = initialSmoother(Ts, [output_data mag_data].',mag_data(1,:));
euler = quat2eul(smooth(1:4,:).');

plot([euler(:,2)])

%%
load('tau.mat')
load('rtau.mat')
tau = real_tau;
save('cont.mat','tau');
tend= (length(tau)-1)/fs;
t=(0:1/fs:tend);
configSet = getActiveConfigSet('quatSim');
set_param(configSet, 'SolverType', 'Fixed-step')
set_param(configSet,'Solver','ode4')
set_param(configSet,'FixedStep',sprintf('%f',Ts));
set_param(configSet,'StopTime',sprintf('%f',(length(tau)-1)/fs));
set_param('quatSim','SimulationCommand','Update');
tauSim = timeseries(tau0,t);
hws = get_param(bdroot, 'modelworkspace');
hws.assignin('tauSim', tauSim);
y=sim('quatSim',configSet);
pqr=y.get('yout');

[smooth, forward]= initialSmoother(Ts, (pqr(:,1:end-4).')+ 0.5*randn(9,length(pqr)), [10, 10, 10]);
euler_smooth = antiModAngles(quat2eul(smooth(1:4,:).'));
euler_forward = antiModAngles(quat2eul(forward(1:4,:).'));
pqr_euler = antiModAngles(quat2eul(pqr(:,10:13)));
plot([euler_smooth(:,1), euler_forward(:,1), pqr_euler(:,1)])

%%
data = iddata(pqr,tau(2:end,:).',Ts);
opt = compareOptions;
opt.InitialCondition = [nu_init eta_init]';
compare(data, All_nonlinear_greybox_model,opt)
