function pitch_data = loadPitch0404()
Ts = 0.0045;
%%
pitch_filepath = fullfile('bag','test1_t1_lock_t2_2016-04-04-14-24-09.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(pitch_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
pitch_data1 = iddata(output_data, input_data,Ts);
%%
pitch_filepath = fullfile('bag','test2_t1_lock_t2_2016-04-04-14-36-20.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(pitch_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
pitch_data2 = iddata(output_data, input_data,Ts);
%%
pitch_filepath = fullfile('bag','test3_t1_lock_t2_2016-04-04-14-40-15.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(pitch_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
pitch_data3 = iddata(output_data, input_data,Ts);
%%
pitch_filepath = fullfile('bag','test4_t1_lock_t2_2016-04-04-14-46-48.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(pitch_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
pitch_data4 = iddata(output_data, input_data,Ts);
%%
pitch_filepath = fullfile('bag','test6_t1_lock_t2_2016-04-04-14-50-33.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(pitch_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
pitch_data6 = iddata(output_data, input_data,Ts);
%%
pitch_data = merge(pitch_data1, pitch_data2, pitch_data3, pitch_data4, pitch_data6);
