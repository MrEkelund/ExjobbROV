%simulation to make sure kalman estimator works
load('test_tau.mat');
fs=100;
Ts=1/fs;
Simparams=[...
    -0.5;
    -0.2;
    -0.5;
    -0.5;
    -0.5;
    -0.5;
    -0.5;
    -0.5;
    -0.5;
    -0.5;
    1;
    1;
    1;
    1;
    1;
    1;];

initialCondition=[...
    1;
    0;
    0;
    0;
    0;
    0;
    0];
quatSim;
for l=1:16
    set_param( sprintf('quatSim/GetParameters/Params%i',l), 'Value', sprintf('%f',Simparams(l)));
end
tend= (length(tau)-1)/fs;
tau;
t=(0:1/fs:tend);
tau = [t;tau];
tau;
%%



configSet = getActiveConfigSet('quatSim');
set_param(configSet, 'SolverType', 'Fixed-step')
set_param(configSet,'Solver','ode4')
set_param(configSet,'FixedStep',sprintf('%f',Ts));
set_param(configSet,'StopTime',sprintf('%f',(length(tau)-1)/fs));
set_param( 'quatSim/n', 'InitialCondition', sprintf('%f',initialCondition(1)))
set_param( 'quatSim/e1', 'InitialCondition', sprintf('%f',initialCondition(2)))
set_param( 'quatSim/e2', 'InitialCondition', sprintf('%f',initialCondition(3)))
set_param( 'quatSim/e3', 'InitialCondition', sprintf('%f',initialCondition(4)))
set_param( 'quatSim/p', 'InitialCondition', sprintf('%f',initialCondition(5)))
set_param( 'quatSim/q', 'InitialCondition', sprintf('%f',initialCondition(6)))
set_param( 'quatSim/r', 'InitialCondition', sprintf('%f',initialCondition(7)))
save('tau.mat','tau');
set_param('quatSim','SimulationCommand','Update');
y_sim=sim('quatSim',configSet);
dat=y_sim.get('yout');
measurements=dat(:,4:end)';
y_valid=measurements(1:3,:);
%%
P = blkdiag(100000000*eye(7),eye(3),0.000001*eye(13));
Q = blkdiag(100000000*eye(3),eye(3),0.00001*eye(13));
R = blkdiag(0.00001*eye(3),0.01*eye(3),0.001*eye(3));
state = zeros(23,2*length(measurements));


g = 9.81744;
% First run variables
eta = [1;0;0;0];
nu =  [0;0;0];
state(1:7,1)=[eta;nu];
zb = -0.5;
Kp = -0.2;
Kp_dot = -0.5;
Kp_abs_p = -0.5;
Mq = -0.5;
Mq_dot = -0.5;
Mq_abs_q = -0.5;
Nr = -0.5;
Nr_dot = -0.5;
Nr_abs_r = -0.5;
Ix = 1;
Iy = 1;
Iz = 1;
Ix_Kp_dot =1;% Ix - Kp_dot;
Iy_Mq_dot =1;% Iy - Mq_dot;
Iz_Nr_dot =1; %Iz - Nr_dot;
state(8:end,1) =... %EstimatedParams;
    [zb; Kp; Kp_dot; Kp_abs_p; Mq;...
    Mq_dot; Mq_abs_q; Nr; Nr_dot; Nr_abs_r;...
    Ix; Iy; Iz; Ix_Kp_dot; Iy_Mq_dot; Iz_Nr_dot];
mag_n = measurements(7,1);
mag_e = measurements(8,1);
mag_d = measurements(9,1);
for k=1:1    
    %run Kalman filter
    j = 1;
    for i=1:length(measurements)
        %measurement update
        H = getMeasurementJacobian(state(:,j),g,mag_n,mag_e,mag_d);
        h = getExpectedMeasurements(state(:,j),g,mag_n,mag_e,mag_d);
        state(:,j+1) = normQuaternions(state(:,j)+(P*H.'/(H*P*H.'+ R)*(measurements(:,i) - h)));
        P = P - P*H.'/(H*P*H.'+ R)*(H*P);
        j=j+1;
        
        % Time update
        F = getSystemJacobian(Ts,state(:,j),tau(:,i));
        Gv = getGvMatrix(Ts,state(:,j));
        state(:,j+1) = normQuaternions(timeStep(Ts,state(:,j),tau(:,i)));
        P = F*P*F.' + Gv*Q*Gv.';
        j=j+1;
    end
    state(8:end,1)=state(8:end,end);
end
EstimatedParams=state(8:end,end);

% Check if new parameter values are valid
% temp = mean(params');
% if(any(0<temp(1:10))|any(0>temp(11:16)))
%     display('Wrong sign on one or more parameters.');
%     display('Not saving.');
%     paramsOK = false;
% else
%     display('New parameters are OK.')
%     display('Starting simulation and saving to params.mat');
%     paramsOK = true;
%     EstimatedParams=mean(params');
%     %save('params.mat','EstimatedParams');
% end


% compare against validation data
if(1)  
    close all;
    for k=1:1;
        %valid = getexp(data,k);
        %tau_valid = thrusterLookup(valid.InputData);
        %y_valid = valid.outputdata';
        %initialCondition = [1;0;0;0;y_valid(1:3,1)];
        %tend= (length(tau_valid)-1)/fs;
        %t=(0:1/fs:tend);
        quatSim;
        % setup simulator
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
        %tau_valid = [t;tau_valid];
        %save('tau.mat','tau_valid');
        y=sim('quatSim',configSet);
        pqr=y.get('yout');

    % plot
        subplot(1,3,3*k-2)
        plot(t,[pqr(:,1),y_valid(1,:)'])
        str = sprintf('p: Fit %f %%',100*goodnessOfFit(pqr(:,1),y_valid(1,:)','NMSE'));
        title(str)
        subplot(1,3,3*k-1)
        plot(t,[pqr(:,2),y_valid(2,:)'])
        str = sprintf('q: Fit %f %%',100*goodnessOfFit(pqr(:,2),y_valid(2,:)','NMSE'));
        title(str)
        subplot(1,3,3*k)
        plot(t,[pqr(:,3),y_valid(3,:)'])
        str = sprintf('r: Fit %f %%',100*goodnessOfFit(pqr(:,3),y_valid(3,:)','NMSE'));
        title(str)

    end
end









