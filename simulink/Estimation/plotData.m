function [] = plotData(states, ang_vel_data, lin_vel_data,lin_acc_data, thrusters_data,time)
%plotData plots the data

imu_fig = figure('Name','IMU','units','normalized','position',[0 0.5 .5 .41]);
states_fig = figure('Name','States','units','normalized','position',[0 0 .5 .41]);
%integrated_fig = figure('Name','Integrated acc','units','normalized','position',[0.5 0.5 .5 .41]);
thrusters_fig = figure('Name','Thruster','units','normalized','position',[0.5 0 .5 .41]);

plot_time = time-time(1)*ones(size(time,1),1);
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
subplot(2,1,1)
suptitle('IMU data recived from sensor fusion');
plot(plot_time, ang_vel_data)
legend('Ang\_vel\_x','Ang\_vel\_y','Ang\_vel\_z')
ylabel('Angular velocites [rad/s]');
xlabel('Time [s]')

subplot(2,1,2)
plot(plot_time, lin_acc_data)
legend('Lin\_acc\_x','Lin\_acc\_y','Lin\_acc\_z')
ylabel('Linear acceleration [m/s]');
xlabel('Time [s]')

%     figure(integrated_fig)
%     plot(plot_time, lin_vel_data)
%     legend('Lin\_vel\_x','Lin\_vel\_y','Lin\_vel\_z')
%     ylabel('Linear acceleration [m/s]');
%     xlabel('Time [s]')

figure(thrusters_fig);
%     suptitle('Thrusters')
for i=1:size(thrusters_data,2)
    subplot(3,2,i)
    plot(plot_time, thrusters_data(:,i));
    title(sprintf('Thruster %i', i))
    xlabel('Time [s]')
    ylabel('Output [%]')
    axis([plot_time(1) plot_time(end) -1 1]);
end
end

