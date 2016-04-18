function [resampled_control_signals, states, time, Ts] = resampleControlSignals(control_signals, control_time, states_data, state_time)
%resampleControlSingals Resamples the control signal with a zero hold
%method to the same sampletime as the states
%   input: control_singals - Control signals vector with lower sampling
%   time than states vector.
%   input: control_time - The time vector for the control signals. Used for
%   syncing the test time.
%   input: states_data - State vector.
%   input: state_time - Time vector for the states.
%
%   output: resampled_control_signals - The resampled control signals.
%   output: states - The relevant states for the test.
%   output: time - New time vector for both the states and control signals.
%   output: Ts - Sampling period for the vectors

Ts = mean(state_time(2:end) - state_time(1:end-1));
first_time_instant = find((state_time - control_time(1)) > -0.001 & (state_time - control_time(1) < 0.5),1);
last_time_instant = find((state_time - control_time(end)) > -Ts*1.2 & (state_time - control_time(end) < Ts*1.2));
if isempty(last_time_instant)
    error('Couldnt find last experiment time.')
end
test_time = state_time(first_time_instant:last_time_instant);


resampled_control_signals = zeros(length(test_time),size(control_signals,2));
resampled_index = 1;
for i =1:length(control_time)-1
    while(resampled_index <= length(test_time) && control_time(i+1) > test_time(resampled_index))
        resampled_control_signals(resampled_index,:) = control_signals(i,:);
        resampled_index = resampled_index + 1;
    end
end
time = test_time;
states = states_data(first_time_instant:last_time_instant,:);
end