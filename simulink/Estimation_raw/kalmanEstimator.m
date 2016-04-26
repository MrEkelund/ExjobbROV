%% load data set
fs= 100;
Ts = 1/fs;
data = loadAll0418(0,1/Ts);
%%
for k=1:length(data.exp)
    exp = getexp(data,k);
    tau = thrusterLookup(exp.InputData);
    measurements = exp.OutputData';
    measurements(1:3,:)=detrend(measurements(1:3,:),'constant');
    g = 9.81744;
    %set the first magnetometer reading
    mag_n = measurements(7,1);
    mag_e = measurements(8,1);
    mag_d = measurements(9,1);
    
    % Set initial variables
    P = blkdiag(100*eye(7),0.001*eye(16));
    Q = blkdiag(1000*eye(3),0.001*eye(16));
    R = blkdiag(0.001*eye(3),0.001*eye(3),0.001*eye(3));
    state = zeros(23,2*length(measurements));
    
    % First run variables
    eta = [1;0;0;0];
    nu =  [0;0;0];
    state(1:7,1)=[eta;nu];
    if k==1
        zb = -0.05;
        Kp = -1;
        Kp_dot = -1;
        Kp_abs_p = -1;
        Mq = -1;
        Mq_dot = -1;
        Mq_abs_q = -1;
        Nr = -1;
        Nr_dot = -1;
        Nr_abs_r = -1;
        Ix = 1;
        Iy = 1;
        Iz = 1;
        Ix_Kp_dot = Ix - Kp_dot;
        Iy_Mq_dot = Iy - Mq_dot;
        Iz_Nr_dot = Iz - Nr_dot;
        state(8:end,1) =... %EstimatedParams;
        [zb; Kp; Kp_dot; Kp_abs_p; Mq;...
            Mq_dot; Mq_abs_q; Nr; Nr_dot; Nr_abs_r;...
            Ix; Iy; Iz; Ix_Kp_dot; Iy_Mq_dot; Iz_Nr_dot];
    else
        state(8:end,1) = params(:,k-1);  
    end
    
    display(sprintf('Data set number %i',k))
    
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
    params(:,k) = state(8:end,end);
end
% Check if new parameter values are valid
temp = mean(params');
if(any(0<temp(1:10))|any(0>temp(11:16)))
    display('Wrong sign on one or more parameters.');
    display('Not saving.');
    paramsOK = false;
else
    display('New parameters are OK.')
    display('Starting simulation and saving to params.mat');
    paramsOK = true;
    EstimatedParams=mean(params');
    save('params.mat','EstimatedParams');
end


% compare against validation data
if(paramsOK)  
    close all;
    for k=1:length(data.exp);
        valid = getexp(data,k);
        tau_valid = thrusterLookup(valid.InputData);
        y_valid = valid.outputdata';
        initialCondition = [1;0;0;0;y_valid(1:3,1)];
        tend= (length(tau_valid)-1)/fs;
        t=(0:1/fs:tend);
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
        set_param(configSet,'StopTime',sprintf('%f',(length(tau_valid)-1)/fs));
        set_param('quatSim','SimulationCommand','Update');
        % generate thrust input signal
        tau_valid = [t;tau_valid];
        save('tau.mat','tau_valid');
        y=sim('quatSim',configSet);
        pqr=y.get('yout');

    % plot
        subplot(length(data.exp),3,3*k-2)
        plot(t,[pqr(:,1),y_valid(1,:)'])
        str = sprintf('p: Fit %f %%',100*goodnessOfFit(pqr(:,1),y_valid(1,:)','NMSE'));
        title(str)
        subplot(length(data.exp),3,3*k-1)
        plot(t,[pqr(:,2),y_valid(2,:)'])
        str = sprintf('q: Fit %f %%',100*goodnessOfFit(pqr(:,2),y_valid(2,:)','NMSE'));
        title(str)
        subplot(length(data.exp),3,3*k)
        plot(t,[pqr(:,3),y_valid(3,:)'])
        str = sprintf('r: Fit %f %%',100*goodnessOfFit(pqr(:,3),y_valid(3,:)','NMSE'));
        title(str)

    end
end




