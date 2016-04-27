load('tau.mat')
[parameters, parameters_strings] = initROVParameters();
EstimatedParams = parameters([13:28]);
eta_init = [0 1 0 0];
nu_init = [0 0 0];
initialCondition = [eta_init nu_init];
Ts = 1/100;
fs = 1/Ts;
N = 20;


tend= (length(tau)-1)/fs;
t=(0:1/fs:tend);
% setup simulator
quatSim
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

configSet = getActiveConfigSet('quatSim');
set_param(configSet, 'SolverType', 'Fixed-step')
set_param(configSet,'Solver','ode4')
set_param(configSet,'FixedStep',sprintf('%f',Ts));
set_param(configSet,'StopTime',sprintf('%f',(length(tau)-1)/fs));
set_param('quatSim','SimulationCommand','Update');
% generate thrust input signal
tau0 = [0:Ts:(N-1)*Ts;zeros(6,N)];
save('cont.mat', 'tau0')
y0=sim('quatSim',configSet);

initial_state = initialEkf(Ts,y0.get('yout').',10,10,10)
%%
save('cont.mat','tau');
y=sim('quatSim',configSet);
pqr=y.get('yout');
%%
data = iddata(pqr,tau(2:end,:).',Ts);
opt = compareOptions;
opt.InitialCondition = [nu_init eta_init]';
compare(data, All_nonlinear_greybox_model,opt)
