function roll_pitch_data = loadRollPitch0404()
Ts = 0.0045;
%%
roll_pitch_filepath = fullfile('bag','test1_roll_pitch_2016-04-04-15-11-53.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(roll_pitch_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
input_data(:,6) = 0; %Due to broken propeller
roll_pitch_data1 = iddata(output_data, input_data,Ts);
%%
roll_pitch_filepath = fullfile('bag','test2_roll_pitch_2016-04-04-15-14-44.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(roll_pitch_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
input_data(:,6) = 0; %Due to broken propeller
roll_pitch_data2 = iddata(output_data, input_data,Ts);
%%
roll_pitch_filepath = fullfile('bag','test3_roll_pitch_2016-04-04-15-16-43.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(roll_pitch_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
input_data(:,6) = 0; %Due to broken propeller
roll_pitch_data3 = iddata(output_data(1:2500,:), input_data(1:2500,:),Ts);
%%
roll_pitch_filepath = fullfile('bag','test4_roll_pitch_2016-04-04-15-18-34.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(roll_pitch_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
input_data(:,6) = 0; %Due to broken propeller
roll_pitch_data4 = iddata(output_data, input_data,Ts);
%%
roll_pitch_data = merge(roll_pitch_data1, roll_pitch_data2, roll_pitch_data3, roll_pitch_data4);
end