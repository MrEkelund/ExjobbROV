function [lin_vel_data ,lin_acc_data, ang_vel_data, imu_time, thrusters_data, thrusters_time, states, states_time] = retriveData(filepath,plotting)
    %retriveData
    %   Input: filepath - Fullfilepath or relative.
    %   Input: plotting - 1 for subplots of the data. 0 for no plots
    %
    %   Output: lin_acc_data  - Linear acceleration in x,y,z.
    %   Output: ang_vel_data  - Angular velocites about x,y,z.
    %   Output: imu_time      - Time vector for imu data.
    %   Output: time_vector   - Time vector for the sensor data.
    %   Output: thruster_data - thruster data vector.
    %   Output: thruster_time - Time vector for the thruster data.
    
    bag = rosbag(filepath);
%% States
    states_bag = select(bag,'Topic','/sensor_fusion/states');
    
    states_msgs = readMessages(states_bag);
    
    states_data = zeros(size(states_msgs,1),10);
    states_time = zeros(size(states_msgs,1),1);
    for i = 1:size(states_msgs,1)
        data = double(states_msgs{i}.Data');
        states_data(i,:) = data(:);
        states_time(i) = states_bag.MessageList{i,1};
    end
    

    
    
    % Integrate the acc to get vel
%     compensated_lin_acc_data = removeGravity(states_data(:,3),states_data(:,2),states_data(:,1), lin_acc_data);
%     lin_vel_data = integrateAcc(compensated_lin_acc_data, imu_time);
%     
%     %{
%      Remove the first and last sample  to get the same length vectors
%      (this is due to integration of the acc)
%     %}
%     
%     states = states(2:end-1,:);
%     ang_vel_data = ang_vel_data(2:end-1,:);
%     states_time = states_time(2:end-1,:);
%     imu_time = imu_time(2:end-1,:);
%     


%% IMU
%     imu_bag = select(bag,'Topic','/rovio/imu/data');
%     imu_msgs = readMessages(imu_bag);
%     
%     imu_data = zeros(size(imu_msgs,1),6);
%     imu_time = zeros(size(imu_msgs,1),1);
%     for i = 1:size(imu_msgs,1)
%         data = double(imu_msgs{i}.Data');
%         imu_data(i,:) = data(2:end);
%         imu_time(i) = data(1);
%     end
%     ang_vel_data = imu_data(:,1:3);
%     lin_acc_data = imu_data(:,4:6);
%     
%     if plotting
%         figure(imu_fig);
%         subplot(2,1,1)
%         suptitle('IMU data')
%         
%         plot(imu_time-imu_time(1)*ones(size(imu_time,1),1), imu_data(:,1:3))
%         legend('Ang_vel_x','Ang_vel_y','Ang_vel_z')
%         ylabel(sprintf('Angular velocites [%c/s]', char(176)));
%         xlabel('Time [s]')
%         
%         subplot(2,1,2)
%         plot(imu_time-imu_time(1)*ones(size(imu_time,1),1), imu_data(:,4:6))
%         legend('Lin_acc_x','Lin_acc_y','Lin_acc_z')
%         ylabel('Linear acceleration [m/s]');
%         xlabel('Time [s]')
%     end
%% Thrusters
    thrusters_bag = select(bag,'Topic','/rovio/thrusters');
    
    thrusters_msgs = readMessages(thrusters_bag);
    
    thrusters_data = zeros(size(thrusters_msgs,1),6);
    thrusters_time = zeros(size(thrusters_msgs,1),1);
    for i = 1:size(thrusters_msgs,1)
        data = double(thrusters_msgs{i}.Data');
        thrusters_data(i,:) = (data(:) - 1500)/400;
        thrusters_time(i) = thrusters_bag.MessageList{i,1};
    end
    
       %{
     Remove the first and last sample  to get the same length vectors
     (this is due to integration of the acc)
    %}
    
%     thrusters_data = thrusters_data(2:end-1,:);
%     thrusters_time = thrusters_time(2:end-1,:);
%
[thrusters_data, states_data, time] = resampleControlSignals(thrusters_data, thrusters_time, states_data, states_time);
states = states_data(:,[1 2 3 7]); % Angels and depth
ang_vel_data = states_data(:,4:6);
lin_acc_data = states_data(:,8:10);
imu_time = time;
thrusters_time = time;

if plotting
    plot_time = time-time(1)*ones(size(time,1),1);
    figure(states_fig);
    subplot(2,1,1)
    suptitle('States')
    plot(plot_time, states_data(:,1:3))
    legend('Roll','Yaw','Pitch')
    ylabel('Euler angles [rad]');
    xlabel('Time [s]')
    
    subplot(2,1,2)
    plot(plot_time, states_data(:,7))
    legend('Depth')
    ylabel('Depth [m]');
    xlabel('Time [s]')
    
    figure(imu_fig)
    subplot(2,1,1)
    suptitle('IMU data recived from sensor fusion');
    plot(plot_time, states_data(:,4:6))
    legend('Ang\_vel\_x','Ang\_vel\_y','Ang\_vel\_z')
    ylabel(sprintf('Angular velocites [%c/s]', char(176)));
    xlabel('Time [s]')
    
    subplot(2,1,2)
    plot(plot_time, states_data(:,8:10))
    legend('Lin\_acc\_x','Lin\_acc\_y','Lin\_acc\_z')
    ylabel('Linear acceleration [m/s]');
    xlabel('Time [s]')
    
    figure(integrated_fig)
    plot(plot_time, lin_vel_data)
    legend('Lin\_vel\_x','Lin\_vel\_y','Lin\_vel\_z')
    ylabel('Linear acceleration [m/s]');
    xlabel('Time [s]')
    
    figure(thrusters_fig);
    title('Thrusters')
    plot(plot_time, thrusters_data)
    legend('Thruster1','Thruster2','Thruster3','Thruster4','Thruster5','Thruster6')
    ylabel('Output [%]');
    xlabel('Time [s]')
    axis([0 plot_time(end) -1 1])
end

end
    
    
