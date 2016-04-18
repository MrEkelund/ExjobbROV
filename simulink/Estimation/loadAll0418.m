function All_data = loadAll0418()
Ts = 0.0045;
%%
All_filepath = fullfile('bag','all_1_2016-04-18-14-00-41.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(All_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
All_data1 = iddata(output_data, input_data,Ts);

%%
All_filepath = fullfile('bag','all_2_2016-04-18-14-56-58.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(All_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
All_data2 = iddata(output_data, input_data,Ts);
%%
All_filepath = fullfile('bag','all_3_2016-04-18-15-04-50.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(All_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
All_data3 = iddata(output_data, input_data,Ts);
%%
All_filepath = fullfile('bag','all_4_2016-04-18-15-06-06.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(All_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
All_data4 = iddata(output_data, input_data,Ts);
%%
All_filepath = fullfile('bag','all_5_2016-04-18-15-06-44.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(All_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
All_data5 = iddata(output_data, input_data,Ts);

%%
All_data = merge(All_data1, All_data2, All_data3, All_data4, All_data5);
end

