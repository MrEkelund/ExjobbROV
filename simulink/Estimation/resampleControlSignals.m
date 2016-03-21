function [resampled_control_signals, states, time] = resampleControlSignals(control_signals, control_time, states_data,sensor_time)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

Ts = mean(sensor_time(2:end) - sensor_time(1:end-1));
first_time_instant = find((sensor_time - control_time(1)) > -0.001 & (sensor_time - control_time(1) < 0.5),1);
last_time_instant = find((sensor_time - control_time(end)) > -Ts & (sensor_time - control_time(end) < Ts),1)
test_time = sensor_time(first_time_instant:last_time_instant);


resampled_control_signals = zeros(length(test_time),size(control_signals,2));
resampled_index = 1;
for i =1:length(control_time)-1
    while(resampled_index <= length(test_time) && control_time(i+1) > test_time(resampled_index))
        resampled_control_signals(resampled_index) = control_signals(i);
        resampled_index = resampled_index + 1;
    end
end
time = test_time;
states = states_data(first_time_instant:last_time_instant,:);
end