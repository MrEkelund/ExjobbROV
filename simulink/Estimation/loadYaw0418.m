function yaw_data = loadYaw0418()
Ts = 0.0045;
%%
yaw_filepath = fullfile('bag','yaw_1_2016-04-18-13-44-26.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
yaw_data1 = iddata(output_data, input_data, Ts);
%%
yaw_filepath = fullfile('bag','yaw_2_2016-04-18-13-46-47.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
yaw_data2 = iddata(output_data, input_data, Ts);
%%
yaw_filepath = fullfile('bag','yaw_3_2016-04-18-13-50-03.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
yaw_data3 = iddata(output_data, input_data, Ts);
%%
yaw_filepath = fullfile('bag','yaw_4_2016-04-18-13-52-57.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
yaw_data4 = iddata(output_data, input_data, Ts);
%%
yaw_filepath = fullfile('bag','yaw_5_2016-04-18-13-56-59.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
yaw_data5 = iddata(output_data, input_data, Ts);
%%
yaw_data = merge(yaw_data1, yaw_data2, yaw_data3);
end