function roll_pitch_data = loadRollPitch0321()
Ts = 0.0045;
%%
% roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_1_2016-03-21-15-23-37.bag');
% [lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
% getTestData(roll_pitch_filepath, 0);
% states = states(:,[3 2 1 4]); % Change position of yaw and roll
% states = states(:,1:3)*pi/180;
% ang_vel_data = ang_vel_data*pi/180;
% output_data = [ang_vel_data, antiModAngles(states(:,1:3))];
% input_data = thrusters_data;
% roll_pitch_data1 = iddata(output_data, input_data,Ts);

%%
roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_2_2016-03-21-15-26-12.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(roll_pitch_filepath, 0);
states = states(:,[3 2 1 4]); % Change position of yaw and roll
states = states(:,1:3)*pi/180;
ang_vel_data = ang_vel_data*pi/180;
output_data = [ang_vel_data, antiModAngles(states(:,1:3))];
input_data = thrusters_data;
roll_pitch_data2 = iddata(output_data, input_data,Ts);
%%
roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_3_2016-03-21-15-28-14.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(roll_pitch_filepath, 0);
states = states(:,[3 2 1 4]); % Change position of yaw and roll
states = states(:,1:3)*pi/180;
ang_vel_data = ang_vel_data*pi/180;
output_data = [ang_vel_data, antiModAngles(states(:,1:3))];
input_data = thrusters_data;
roll_pitch_data3 = iddata(output_data, input_data,Ts);
roll_pitch_data3 = roll_pitch_data3(1:2500);
%%
roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_4_2016-03-21-15-29-25.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(roll_pitch_filepath, 0);
states = states(:,[3 2 1 4]); % Change position of yaw and roll
states = states(:,1:3)*pi/180;
ang_vel_data = ang_vel_data*pi/180;
output_data = [ang_vel_data, antiModAngles(states(:,1:3))];
input_data = thrusters_data;
roll_pitch_data4 = iddata(output_data, input_data,Ts);
%%
% roll_pitch_filepath = fullfile('bag','act_1_2_5_6_test_5_2016-03-21-15-32-03.bag');
% [lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
% getTestData(roll_pitch_filepath, 0);
% states = states(:,[3 2 1 4]); % Change position of yaw and roll
% states = states(:,1:3)*pi/180;
% ang_vel_data = ang_vel_data*pi/180;
% output_data = [ang_vel_data, antiModAngles(states(:,1:3))];
% input_data = thrusters_data;
% roll_pitch_data5 = iddata(output_data, input_data,Ts);
% roll_pitch_data5 = merge(roll_pitch_data5(1:3340));
%%
roll_pitch_data = merge(roll_pitch_data2, roll_pitch_data3, roll_pitch_data4);
end