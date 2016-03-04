function [lin_acc_data, ang_vel_data, ori_data,time_vector, rc_data ,rc_time] = retriveImuData(filepath,plotting)
    %retriveImuData Retrives Mavros imu data from filepath
    %   Input: filepath - Fullfilepath or relative.
    %   Input: plotting - 1 for subplots of the data. 0 for no plots
    %
    %   Output: lin_acc_data - Linear acceleration in x,y,z.
    %   Output: lin_acc_time - Time vector for lin_acc_data.
    %   Output: ang_vel_data - Angular velocites about x,y,z.
    %   Output: ang_vel_time - Time vector for ang_vel_data.
    %   Output: ori_data - Euler angles in roll, pitch, roll.
    %   Output: time_vector - Time vector for the sensor data.
    %   Output: rc_data - rc data vector.
    %   Output: rc_time - Time vector for the rc data.
    
    subplots = 1;
    %plotting = 1;
    x_layout = 4;
    y_layout = 1;

    %filepath = fullfile('..', 'bag', 'super_2016-02-16-09-13-35.bag');
    bag = rosbag(filepath);

    imu_bag = select(bag,'Topic','/rovio/imu/data');
    %imu_msgs = readMessages(imu_bag);
    %% Linear acceleration
    plot_num = 1;
    figures = 1;
    lin_acc_ts = timeseries(imu_bag, 'LinearAcceleration.X','LinearAcceleration.Y','LinearAcceleration.Z');
    start_time = lin_acc_ts.Time(1);
    lin_acc_ts.Time = lin_acc_ts.Time - start_time*ones(size(lin_acc_ts.Time,1),1);
    if plotting
        if subplots
            subplot(x_layout,y_layout,plot_num)
            plot_num = plot_num + 1;
        else
            figure(figures)
            figures = figure+1;
        end
        plot(lin_acc_ts)
        legend('X','Y','Z')
        ylabel('Linear Acceleration [m/s^2]')
        xlabel('Time [s]')
        title('Linear Acceleration')
    end
    lin_acc_data = lin_acc_ts.data;
    time_vector = lin_acc_ts.time;

    %% Angular velocites
    ang_vel_ts = timeseries(imu_bag, 'AngularVelocity.X','AngularVelocity.Y','AngularVelocity.Z');
    start_time = ang_vel_ts.Time(1);
    ang_vel_ts.Time = ang_vel_ts.Time - start_time*ones(size(ang_vel_ts.Time,1),1);
    if plotting
        if subplots
            subplot(x_layout,y_layout,plot_num)
            plot_num = plot_num + 1;
        else
            figure(figures)
            figures = figure+1;
        end

        plot(ang_vel_ts)
        legend('Roll','Pitch','Yaw')
        ylabel('Angular velocites [rad/s]')
        xlabel('Time [s]')
        title('Angular Velocites')
    end
    ang_vel_data = ang_vel_ts.data;    

    %% Orientation
    ori_ts = timeseries(imu_bag, 'Orientation.W','Orientation.X','Orientation.Y','Orientation.Z');
    start_time = ori_ts.Time(1);
    ori_ts.Time = ori_ts.Time - start_time*ones(size(ori_ts.Time,1),1);
    eul = quat2eul(ori_ts.data);
    yaw = 180/pi*(-eul(:,1));
    pitch = 180/pi*(-eul(:,2));
    roll = 180/pi*(eul(:,3));

    if plotting
        if subplots
            subplot(x_layout,y_layout,plot_num)
            plot_num = plot_num + 1;
        else
            figure(figures)
            figures = figure+1;
        end

        plot(ori_ts.Time,[roll,pitch,yaw])
        legend('Roll','Pitch','Yaw')
        ylabel(sprintf('Euler angles [%c]', char(176)));
        xlabel('Time [s]')
        title('Heading')
    end
    ori_data = [roll,pitch,yaw];
    %% Control signals
    rc_bag = select(bag,'Topic','/mavros/rc/out');
    rc_msgs = readMessages(rc_bag);
    start_time = rc_bag.StartTime;
    rc_ts = rc_bag.timeseries;
    rc_ts.Time = rc_ts.Time - start_time*ones(size(rc_ts.Time,1),1);
    
    control_signals = zeros(size(rc_msgs,1),8);
    for i = 1:size(rc_msgs,1)
        control_signals(i,:) = (double(rc_msgs{i}.Channels')-1500)/400;
    end
    if plotting
        if subplots
            subplot(x_layout,y_layout,plot_num)
            plot_num = plot_num + 1;
        else
            figure(figures)
            figures = figure+1;
        end

        plot(rc_ts.Time,control_signals)
        legend('u1','u2','u3','u4','u5','u6')
        ylabel('Amount of input [%]');
        xlabel('Time [s]')
        title('Control signals')
    end
    rc_data = control_signals;
    rc_time = rc_ts.Time;
end


