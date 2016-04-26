fs= 100;
Ts = 1/fs;
data = loadAll0418(0,1/Ts);
%%
for k=1:1%2%length(data.exp)
    exp = getexp(data,k);
    tau = thrusterLookup(exp.InputData);
    measurements = exp.OutputData';
    measurements(1:3,:)=detrend(measurements(1:3,:),'constant');
    g = 9.81744;
    %set the first magnetometer reading
    mag_n = measurements(7,1);
    mag_e = measurements(8,1);
    mag_d = measurements(9,1);
    %convert from control signal to force before running script to save time
    
    
    % Set initial variables
    P = blkdiag(100*eye(7),0.000001*eye(19));
    Q = blkdiag(1000*eye(3),0.000001*eye(19));
    R = blkdiag(0.01*eye(3),1000*eye(3),0.001*eye(3));
    state = zeros(26,2*length(measurements));
    
    % First run variables
    eta = [1;0;0;0];
    nu =  [0;0;0];
    state(1:7,1)=[eta;nu];
    if k==1
        a1=0.4;
        a2=-0.1;
        a3=0;
        a4=0;
        a5=0;
        a6=0;
        a7=0;
        b1=-0.1;
        b2=-0.1;
        b3=0;
        b4=0;
        b5=0;
        b6=0;
        b7=0;
        c1=-0.1;
        c2=-0.1;
        c3=0;
        c4=0;
        c5=0;

        state(8:end,1) =... %EstimatedParams;
        [a1;a2;a3;a4;a5;a6;a7;b1;b2;b3;b4;b5;b6;b7;c1;c2;c3;c4;c5];
    else
        state(8:end,1) = params(:,k-1);  
    end
    
    display(sprintf('Data set number %i',k))
    
    %run Kalman filter
    j = 1;
    for i=1:length(measurements)
        %measurement update
        H = getMeasurementJacobianBlackBox(state(:,j),g,mag_n,mag_e,mag_d);
        h = getExpectedMeasurements(state(:,j),g,mag_n,mag_e,mag_d);
        state(:,j+1) = normQuaternions(state(:,j)+(P*H.'/(H*P*H.'+ R)*(measurements(:,i) - h)));
        P = P - P*H.'/(H*P*H.'+ R)*(H*P);
        j=j+1;
        
        % Time update
        F = getSystemJacobianBlackBox(Ts,state(:,j),tau(:,i));
        Gv = getGvMatrixBlackBox(Ts,state(:,j));
        state(:,j+1) = normQuaternions(timeStepBlackBox(Ts,state(:,j),tau(:,i)));
        P = F*P*F.' + Gv*Q*Gv.';
        j=j+1;
    end
    params(:,k) = state(8:end,end);
end
