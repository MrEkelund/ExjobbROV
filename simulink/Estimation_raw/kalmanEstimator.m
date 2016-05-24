 clear
 fs= 50;
 Ts = 1/fs;
 data = loadAll0418(0,fs);
%%
nr_sets=4;
nr_iter=1;
clear params
for iter=1:nr_iter
    display(sprintf('Iteration number %i',iter))
    for k=1:nr_sets
        %load data set
        exp = getexp(data,k);
        tau = exp.InputData;
        measurements = exp.OutputData';
        
        g = 9.81744;
        %Set the first magnetometer reading
        mag_n = measurements(7,1);
        mag_e = measurements(8,1);
        mag_d = measurements(9,1);
        
        % Set initial variables
        %Model noise covariance
        Q = blkdiag(...
            100*eye(4),... %Quat
            1000,... %pqr
            1000,....
            1000,...
            0.01*eye(3),...%Bias
            0.01*eye(10),...%Params
            0.000001*eye(4),0.000001);  %Moment arms
        %measurement covariance
        R = blkdiag(...
            0.01*eye(3),...    %Gyro
            0.1*eye(3),...    %Acc
            100*eye(3));   %Mag
        state = zeros(25,2*length(measurements));
        
        % First run variables
        eta = [1;0;0;0];
        nu =  [0;0;0];
        bias = [0;0;0];
        state(1:10,1)=[eta;nu;bias];
        if (k==1 && iter==1)
            %Initial state
            zb = -0.05;
            Kp = -1;
            Kp_abs_p = -1;
            Mq = -1;
            Mq_abs_q = -1;
            Nr = -1;
            Nr_abs_r = -1;
            Ix_Kp_dot = 1;
            Iy_Mq_dot = 1;
            Iz_Nr_dot = 1;
            lx1=0.19;%0.16;
            ly1=0.11;
            ly3=0.11;
            lx5=0.17;%0.2;
            lz6=0.11;
            
            state(11:end,1) =...
                [zb; Kp; Kp_abs_p; Mq;...
                Mq_abs_q; Nr; Nr_abs_r;...
                Ix_Kp_dot; Iy_Mq_dot; Iz_Nr_dot;lx1;ly1;ly3;lx5;lz6];
            
            % Initial P matrix                        
            P = blkdiag(...
                10000*eye(4),...     %Quat
                10000*eye(3),...     %pqr
                0.001*eye(3),...    %Bias
                1*eye(10),...%Params
                0.0000000001*eye(5));      %Moment arms
        else
            % if not first run use last runs results as initial state
            state(11:end,1) = params(:,(iter-1)*nr_sets+k-1);
        end
        
        %display(sprintf('Data set number %i',k))
        
        %run Kalman filter
        j = 1;
        for i=1:length(measurements)
            %measurement update
            H = getMeasurementJacobian(state(:,j),g,mag_n,mag_e,mag_d);
            h = getExpectedMeasurements(state(:,j),g,mag_n,mag_e,mag_d);
            
            innovation=measurements(:,i) - h;
            S=H*P*H.'+ R;
            
            Sigma = 0.05*ones(1,9);
            [innovation,H,S] = outlierReject(innovation,H,S,Sigma);
            KalmanGain=P*H.'/S;
            
            state(:,j+1) = normQuaternions(state(:,j) + KalmanGain*innovation);
            P = P - KalmanGain*S*KalmanGain.';
            j=j+1;
            
            % Time update
            F = getSystemJacobian(Ts,state(:,j),tau(i,:));
            Gv = getGvMatrix(Ts,state(:,j));
            state(:,j+1) = normQuaternions(timeStep(Ts,state(:,j),tau(i,:)));
            P = F*P*F.' + Q;%Gv*Q*Gv.'
            j=j+1;
        end
        params(:,(iter-1)*nr_sets+k) = state(11:end,end);
    end
end

% Check if new parameter values are valid
temp = mean(params,2);
if(any(0<temp(1:7))|any(0>temp(8:14)))
    display('Wrong sign on one or more parameters.');
    display('Not saving.');
    paramsOK = false;
else
    display('New parameters are OK.')
    display('Starting simulation and saving to params.mat');
    paramsOK = true;
    EstimatedParams=params(:,end)
    mean(params,2);
    save('params.mat','EstimatedParams');
end


% compare against validation data
if(paramsOK)
    close all;
    for k=1:length(data.exp);
        valid = getexp(data,k);
        tau_valid = valid.InputData;
        y_valid = valid.outputdata;
        initialCondition = [1;0;0;0;y_valid(1,1:3)'];
        tend= (length(tau_valid)-1)/fs;
        t=(0:1/fs:tend);
        load_system('quatSim1');
        % setup simulator
        set_param( 'quatSim1/n', 'InitialCondition', sprintf('%f',initialCondition(1)) )
        set_param( 'quatSim1/e1', 'InitialCondition', sprintf('%f',initialCondition(2)) )
        set_param( 'quatSim1/e2', 'InitialCondition', sprintf('%f',initialCondition(3)) )
        set_param( 'quatSim1/e3', 'InitialCondition', sprintf('%f',initialCondition(4)) )
        set_param( 'quatSim1/p', 'InitialCondition', sprintf('%f',initialCondition(5)) )
        set_param( 'quatSim1/q', 'InitialCondition', sprintf('%f',initialCondition(6)) )
        set_param( 'quatSim1/r', 'InitialCondition', sprintf('%f',initialCondition(7)) )
        for l=1:15
            set_param( sprintf('quatSim1/GetParameters/Params%i',l), 'Value', sprintf('%f',EstimatedParams(l)));
        end
        
        configSet = getActiveConfigSet('quatSim1');
        set_param(configSet, 'SolverType', 'Fixed-step')
        set_param(configSet,'Solver','ode4')
        set_param(configSet,'FixedStep',sprintf('%f',Ts));
        set_param(configSet,'StopTime',sprintf('%f',(length(tau_valid)-1)/fs));
        set_param('quatSim1','SimulationCommand','Update');
        % generate thrust input signal
        tau_valid = [t;tau_valid'];
        save('tau.mat','tau_valid');
        y=sim('quatSim1',configSet);
        sim_data=y.get('yout');
        
        % plot
        %subplot(length(data.exp),3,3*k-2)
        figure(3*k-2)
        plot(t,[sim_data(:,1),y_valid(:,1)],'LineWidth',2)
        xlabel('Time [s]','FontSize',30);
        ylabel('Angular velocity [rad/s]','FontSize',30);
        legend({'Simulated data','Validation data'},'FontSize',30)
        str = sprintf('Data set %i p: Fit %f %%',k,100*goodnessOfFit(sim_data(:,1),y_valid(:,1),'NMSE'));
        title(str,'FontSize',30)
        %subplot(length(data.exp),3,3*k-1)
        figure(3*k-1)
        plot(t,[sim_data(:,2),y_valid(:,2)],'LineWidth',2)
        xlabel('Time [s]','FontSize',30);
        ylabel('Angular velocity [rad/s]','FontSize',30);
        legend({'Simulated data','Validation data'},'FontSize',30)
        str = sprintf('Data set %i q: Fit %f %%',k,100*goodnessOfFit(sim_data(:,2),y_valid(:,2),'NMSE'));
        title(str,'FontSize',30)
        %subplot(length(data.exp),3,3*k)
        figure(3*k)
        plot(t,[sim_data(:,3),y_valid(:,3)],'LineWidth',2)
        xlabel('Time [s]','FontSize',30);
        ylabel('Angular velocity [rad/s]','FontSize',30);
        legend({'Simulated data','Validation data'},'FontSize',30)
        str = sprintf('Data set %i r: Fit %f %%',k,100*goodnessOfFit(sim_data(:,3),y_valid(:,3),'NMSE'));
        title(str,'FontSize',30)
        
    end
end




