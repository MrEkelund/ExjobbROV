%% load data set
if(~exist('data'))
    fs = 250;
    Ts = 1/fs;
    data = loadAll0418(0,fs);
end
for k=1:length(data.exp)
    exp = getexp(data,k);
    tau = thrusterLookup(exp.InputData);
    measurements = exp.OutputData';
    %measurements(1:3,:)=detrend(measurements(1:3,:),'constant');
    g = 9.81744;
    %set the first magnetometer reading
    mag_n = measurements(7,1);
    mag_e = measurements(8,1);
    mag_d = measurements(9,1);
    %convert from control signal to force before running script to save time
    
    
    % Set initial variables
    P = blkdiag(1000000*eye(7),0.000005*eye(16));
    Q = blkdiag(1000000*eye(3),0.000005*eye(16)); %19x19
    R = blkdiag(1*eye(3),1*eye(3),100*eye(3)); %9x9
    state = zeros(23,2*length(measurements));
    
    % First run variables
    eta = [1;0;0;0];
    nu =  [0;0;0];
    state(1:7,1)=[eta;nu];
    if k==1
        zb = -0.01;%-0.05;
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
        state(8:end,1) = [zb; Kp; Kp_dot; Kp_abs_p; Mq;...
            Mq_dot; Mq_abs_q; Nr; Nr_dot; Nr_abs_r;...
            Ix; Iy; Iz; Ix_Kp_dot; Iy_Mq_dot; Iz_Nr_dot];
    else
        state(8:end,1) = state_last_it;  
    end
    display(sprintf('Data set number %i',k))
    
    %run Kalman
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
    state_last_it = state(8:end,end);
    params(:,k) = state_last_it;
end
EstimatedParams=mean(params');

% compare against validation data
    
close all;
for k=1:length(data.exp)
    if(any(0<EstimatedParams(1:10))|any(0>EstimatedParams(11:end)))
        display('Wrong sign on one or more parameters. Simulator will not work.');
        break
    end
    dataset = k;
    valid = getexp(data,dataset);
    tau_valid = thrusterLookup(valid.InputData);
    y_valid = valid.outputdata';
    initialCondition = [1;0;0;0;y_valid(1:3,1)];
    t=(0:1/fs:(length(tau_valid)-1)/fs);
    tau_valid = [t;tau_valid];
    save('tau.mat','tau_valid');
    save('config.mat','EstimatedParams','initialCondition');
    sim('quatSim',t);
    
    str = sprintf('Data set nr %i ',k);
    figure('Name',str);
    subplot(3,1,1)
    plot(t,[pqr.data(:,1),y_valid(1,:)'])
    str = sprintf('p: Fit %f %%',100*goodnessOfFit(pqr.data(:,1),y_valid(1,:)','NMSE'));
    title(str)
    subplot(3,1,2)
    plot(t,[pqr.data(:,2),y_valid(2,:)'])
    str = sprintf('q: Fit %f %%',100*goodnessOfFit(pqr.data(:,2),y_valid(2,:)','NMSE'));
    title(str)
    subplot(3,1,3)
    plot(t,[pqr.data(:,3),y_valid(3,:)'])
    str = sprintf('r: Fit %f %%',100*goodnessOfFit(pqr.data(:,3),y_valid(3,:)','NMSE'));
    title(str)
end










