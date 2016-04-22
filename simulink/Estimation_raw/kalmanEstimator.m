%% load data set
Ts = 1/100;
data = loadAll0418(0,1/Ts);
%%
for k=1:length(data.exp)
    exp = getexp(data,k);
    tau = thrusterLookup(exp.InputData);
    %%
    measurements = exp.OutputData';
    g = 9.81744;
    %set the first magnetometer reading
    mag_n = measurements(7,1);
    mag_e = measurements(8,1);
    mag_d = measurements(9,1);
    %convert from control signal to force before running script to save time
    
    
    % Set initial variables
    P = blkdiag(1000*eye(7),1*eye(16));
    Q = blkdiag(1000*eye(3),0.01*eye(16));
    R = blkdiag(0.01*eye(3),0.1*eye(3),eye(3));
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
        state(8:end,1) = [zb; Kp; Kp_dot; Kp_abs_p; Mq;...
            Mq_dot; Mq_abs_q; Nr; Nr_dot; Nr_abs_r;...
            Ix; Iy; Iz; Ix_Kp_dot; Iy_Mq_dot; Iz_Nr_dot];
        display('first')
    else
        state(8:end,1)=PreviousEstimate;
        display('Not first')
    end
    
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
    % save
    PreviousEstimate = state(8:end,end)
end

