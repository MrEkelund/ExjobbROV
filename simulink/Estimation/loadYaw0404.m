function yaw_data = loadYaw0404()
Ts = 0.0045;
%%
yaw_filepath = fullfile('bag','test1_t3_t4_2016-04-04-14-57-52.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);
output_data = [ang_vel_data, antiModAngles(states(:,1:3))];
input_data = thrusters_data;
yaw_data1 = iddata(output_data, input_data, Ts);
%%
yaw_filepath = fullfile('bag','test2_t3_t4_2016-04-04-14-59-57.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);
output_data = [ang_vel_data, antiModAngles(states(:,1:3))];
input_data = thrusters_data;
yaw_data2 = iddata(output_data, input_data, Ts);
%%
yaw_filepath = fullfile('bag','test3_t3_t4_2016-04-04-15-02-24.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);
output_data = [ang_vel_data, antiModAngles(states(:,1:3))];
input_data = thrusters_data;
yaw_data3 = iddata(output_data, input_data, Ts);
%%
yaw_data = merge(yaw_data1, yaw_data2, yaw_data3);
end