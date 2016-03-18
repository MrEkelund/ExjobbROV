function [ lin_acc_data, ang_vel_data, imu_time, thrusters_data, thrusters_time, states, states_time ] = getSimulationData(filepath,plotting)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

dataset = load(filepath);

acc_vel_list = {'x','y','z'};
ang_vel_list = {'p','q','r'};
thrusters_list = {'u1','u2','u3','u4','u5','u6'};
states_list = {'phi','theta','psi','D'};

if plotting
    imu_fig = figure('Name','IMU','units','normalized','position',[0 0.5 .5 .41]);
    states_fig = figure('Name','States','units','normalized','position',[0 0 .5 .41]);
    %integrated_fig = figure('Name','Integrated acc','units','normalized','position',[0.5 0.5 .5 .41]);
    thrusters_fig = figure('Name','Thruster','units','normalized','position',[0.5 0 .5 .41]);
end

lin_acc_data = zeros(size(dataset.data.get(char(ang_vel_list(1))).Values.Data,1),3);
% for i=1:3
%     lin_acc_data(:,i) = dataset.data.get(acc_vel_list(i)).Values.Data;
% end

ang_vel_data = zeros(size(dataset.data.get(char(ang_vel_list(1))).Values.Data,1),3);
for i=1:3
    ang_vel_data(:,i) = dataset.data.get(char(ang_vel_list(i))).Values.Data;
end
imu_time = dataset.data.get(char(ang_vel_list(1))).Values.Time;

thrusters_data = zeros(size(dataset.data.get(char(thrusters_list(1))).Values.Data,1),6);
for i=1:6
    thrusters_data(:,i) = dataset.data.get(char(thrusters_list(i))).Values.Data;
end
thrusters_time = dataset.data.get(char(thrusters_list(1))).Values.Time;
thrusters_data(1:40,:)
states = zeros(size(dataset.data.get(char(states_list(1))).Values.Data,1),4);
for i=1:4
    states(:,i) = dataset.data.get(char(states_list(i))).Values.Data;
end
states_time = dataset.data.get(char(states_list(1))).Values.Time;

if plotting
    plot_time = states_time-states_time(1)*ones(size(states_time,1),1);
    figure(states_fig);
    subplot(2,1,1)
    suptitle('States')
    plot(plot_time, states(:,1:3))
    legend('Roll','Pitch','Yaw')
    ylabel('Euler angles [rad]');
    xlabel('Time [s]')
    
    subplot(2,1,2)
    plot(plot_time, states(:,4))
    legend('Depth')
    ylabel('Depth [m]');
    xlabel('Time [s]')
    
    figure(imu_fig)
   % subplot(2,1,1)
    suptitle('Angular velocites');
    plot(plot_time, ang_vel_data)
    legend('Ang\_vel\_x','Ang\_vel\_y','Ang\_vel\_z')
    ylabel('Angular velocites [rad/s]');
    xlabel('Time [s]')
    
%     subplot(2,1,2)
%     plot(plot_time, states(:,8:10))
%     legend('Lin\_acc\_x','Lin\_acc\_y','Lin\_acc\_z')
%     ylabel('Linear acceleration [m/s]');
%     xlabel('Time [s]')
%     
%     figure(integrated_fig)
%     plot(plot_time, lin_vel_data)
%     legend('Lin\_vel\_x','Lin\_vel\_y','Lin\_vel\_z')
%     ylabel('Linear acceleration [m/s]');
%     xlabel('Time [s]')
    
    figure(thrusters_fig);
    title('Thrusters')
    plot(thrusters_time-thrusters_time(1)*ones(size(thrusters_time,1),1), thrusters_data)
    legend('Thruster1','Thruster2','Thruster3','Thruster4','Thruster5','Thruster6')
    ylabel('Output [%]');
    xlabel('Time [s]')
    axis([0 (thrusters_time(end)-thrusters_time(1)) -1 1])
end
end

