function roll_pitch_data = loadRollPitch0418(resampling_fs)
% Ts = 0.0045;
%%
roll_pitch_filepath = fullfile('bag','pitch_roll_1_2016-04-18-13-11-33.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, Ts]= ...
getTestData(roll_pitch_filepath, 0, resampling_fs);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
roll_pitch_data1 = iddata(output_data, input_data,Ts);
%%
roll_pitch_filepath = fullfile('bag','pitch_roll_2_2016-04-18-13-25-02.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(roll_pitch_filepath, 0, resampling_fs);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
roll_pitch_data2 = iddata(output_data, input_data,Ts);
%%
roll_pitch_filepath = fullfile('bag','pitch_roll_3_2016-04-18-13-37-02.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(roll_pitch_filepath, 0, resampling_fs);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
roll_pitch_data3 = iddata(output_data, input_data,Ts);
%%
roll_pitch_data = merge(roll_pitch_data1, roll_pitch_data2, roll_pitch_data3);
end