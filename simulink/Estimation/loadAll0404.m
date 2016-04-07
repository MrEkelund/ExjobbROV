function All_data = loadAll0404()
Ts = 0.0045;
%%
All_filepath = fullfile('bag','test1_all_2016-04-04-15-23-32.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(All_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
input_data(:,6) = 0; %Due to broken propeller
All_data1 = iddata(output_data, input_data,Ts);

%%
All_filepath = fullfile('bag','test2_all_2016-04-04-15-27-58.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
getTestData(All_filepath, 0);
output_data = [ang_vel_data, states(:,1:3)];
input_data = thrusters_data;
input_data(:,6) = 0; %Due to broken propeller
All_data2 = iddata(output_data, input_data,Ts);

%%
All_data = merge(All_data1, All_data2);
end

