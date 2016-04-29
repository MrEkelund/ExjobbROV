function [data, initialCondition] = simulateROV(parameters, sampling_fs, tau, initialCondition)
%UNTITLED2 Summary of this function goes here
%   input - parameters: 
%   input - sampling_fs:
%   input - tau:
%   input - initialCondition:

load_system('quatSim')
set_param( 'quatSim/n', 'InitialCondition', sprintf('%f',initialCondition(4)) )
set_param( 'quatSim/e1', 'InitialCondition', sprintf('%f',initialCondition(5)) )
set_param( 'quatSim/e2', 'InitialCondition', sprintf('%f',initialCondition(6)) )
set_param( 'quatSim/e3', 'InitialCondition', sprintf('%f',initialCondition(7)) )
set_param( 'quatSim/p', 'InitialCondition', sprintf('%f',initialCondition(1)) )
set_param( 'quatSim/q', 'InitialCondition', sprintf('%f',initialCondition(2)) )
set_param( 'quatSim/r', 'InitialCondition', sprintf('%f',initialCondition(3)) )

estimated_parameters = parameters([13:28]);
for i=1:16
    set_param(sprintf('quatSim/GetParameters/Params%i',i), 'Value', sprintf('%f',estimated_parameters(i)));
end

Ts = 1/sampling_fs;
fs = sampling_fs;
tend= (length(tau)-1)/fs;
t=(0:1/fs:tend);
tauSim = timeseries(tau,t);

configSet = getActiveConfigSet('quatSim');
set_param(configSet, 'SolverType', 'Fixed-step')
set_param(configSet,'Solver','ode4')
set_param(configSet,'FixedStep',sprintf('%f',Ts));
set_param(configSet,'StopTime',sprintf('%f',tend));
set_param('quatSim','SimulationCommand','Update');
hws = get_param(bdroot, 'modelworkspace');
hws.assignin('tauSim', tauSim);
y=sim('quatSim',configSet);
simOut=y.get('yout');
data = iddata(simOut(:,1:9),tau, Ts);
end

