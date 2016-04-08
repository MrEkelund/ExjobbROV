function pitch_data = loadPitch0321()
Ts = 0.0045;
%%
pitch_filepath = fullfile('bag','act_5_test_1_2016-03-21-15-36-48.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(pitch_filepath, 0);
states = states(:,[3 2 1 4]); % Change position of yaw and roll
states = states(:,1:3)*pi/180;
ang_vel_data = ang_vel_data*pi/180;
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
pitch_data1 = iddata(output_data, input_data,Ts);

%%
pitch_filepath = fullfile('bag','act_5_test_2_2016-03-21-15-37-53.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(pitch_filepath, 0);
states = states(:,[3 2 1 4]); % Change position of yaw and roll
states = states(:,1:3)*pi/180;
ang_vel_data = ang_vel_data*pi/180;
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
pitch_data2 = iddata(output_data, input_data,Ts);

%%
pitch_data = merge(pitch_data1, pitch_data2);
end