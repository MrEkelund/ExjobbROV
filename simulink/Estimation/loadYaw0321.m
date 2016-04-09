function yaw_data = loadYaw0321()
Ts = 0.0045;
%%
% yaw_filepath = fullfile('bag','act_3_4_test_1_2016-03-21-15-03-06.bag');
% [lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
% getTestData(yaw_filepath, 0);
% states = states(:,[3 2 1 4]); % Change position of yaw and roll
% states = states(:,1:3)*pi/180;
% ang_vel_data = ang_vel_data*pi/180;
% output_data = [ang_vel_data, states(:,1:3)];
% input_data = thrusters_data;
% yaw_data1 = iddata(output_data, input_data, Ts);

%%
yaw_filepath = fullfile('bag','act_3_4_test_2_2016-03-21-15-06-06.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);
states = states(:,[3 2 1 4]); % Change position of yaw and roll
states = states(:,1:3)*pi/180;
ang_vel_data = ang_vel_data*pi/180;
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
yaw_data2 = iddata(output_data, input_data, Ts);
yaw_data2 = merge(yaw_data2(915:2890),yaw_data2(4000:end));

%%
yaw_filepath = fullfile('bag','act_3_4_test_3_2016-03-21-15-09-30.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);
states = states(:,[3 2 1 4]); % Change position of yaw and roll
states = states(:,1:3)*pi/180;
ang_vel_data = ang_vel_data*pi/180;
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
yaw_data3 = iddata(output_data, input_data, Ts);

%%
yaw_filepath = fullfile('bag','act_3_4_test_4_2016-03-21-15-14-04.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);
states = states(:,[3 2 1 4]); % Change position of yaw and roll
states = states(:,1:3)*pi/180;
ang_vel_data = ang_vel_data*pi/180;
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
yaw_data4 = iddata(output_data, input_data, Ts);
yaw_data4 = merge(yaw_data4(1:1900),yaw_data4(2100:end));
%%
yaw_filepath = fullfile('bag','act_3_4_test_5_2016-03-21-15-15-26.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);
states = states(:,[3 2 1 4]); % Change position of yaw and roll
states = states(:,1:3)*pi/180;
ang_vel_data = ang_vel_data*pi/180;
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
yaw_data5 = iddata(output_data, input_data, Ts);

%%
% yaw_data = merge(yaw_data1, yaw_data2, yaw_data3, yaw_data4, yaw_data5);
yaw_data = merge(yaw_data2, yaw_data3, yaw_data4, yaw_data5);
end