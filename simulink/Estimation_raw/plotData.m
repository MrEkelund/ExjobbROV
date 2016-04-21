function [] = plotData(imu_time_series, mag_time_series, thrusters_time_series, filename)
%plotData plots the data

if nargin == 4
    imu_name = strcat(filename ,' - IMU');
    mag_name = strcat(filename ,' - Magnetometer');
    thrusters_name = strcat(filename ,' - Thrusters');
else
    imu_name = 'IMU';
    mag_name = 'Magnetometer';
    thrusters_name = 'Thrusters';
end

imu_fig = figure('Name', imu_name, 'units', 'normalized', 'position', [0 0 .5 1]);
mag_fig = figure('Name', mag_name, 'units', 'normalized', 'position', [0.5 0.5 .5 0.42]);
thrusters_fig = figure('Name', thrusters_name, 'units', 'normalized', 'position', [0.5 0 .5 .42]);

plot_time = imu_time_series.Time - imu_time_series.Time(1);
figure(mag_fig);
suptitle('Magnetometer')
plot(plot_time, mag_time_series.Data)
legend('Mx','My','Mz')
ylabel('Magnetic field [µT]');
xlabel('Time [s]')
xlim([plot_time(1) plot_time(end)]);

figure(imu_fig)
subplot(2,1,1)
suptitle('IMU data');
plot(plot_time, imu_time_series.Data(:,1:3))
legend('Ang\_vel\_x','Ang\_vel\_y','Ang\_vel\_z')
ylabel('Angular velocites [rad/s]');
xlabel('Time [s]')
xlim([plot_time(1) plot_time(end)]);

subplot(2,1,2)
plot(plot_time, imu_time_series.Data(:,4:6))
legend('acc\_x','acc\_y','acc\_z')
ylabel('Acceleration [m/s]');
xlabel('Time [s]')
xlim([plot_time(1) plot_time(end)]);

figure(thrusters_fig);
for i=1:size(thrusters_time_series.Data,2)
    subplot(3,2,i)
    plot(plot_time, thrusters_time_series.Data(:,i));
    title(sprintf('Thruster %i', i))
    xlabel('Time [s]')
    ylabel('Output [%]')
    axis([plot_time(1) plot_time(end) -1 1]);
end
end

