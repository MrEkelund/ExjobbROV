function yaw_data = loadYaw0418(plotting, resampling_fs)
%%
yaw_filepath = fullfile('bag','yaw_1_2016-04-18-13-44-26.bag');
[imu_data, mag_data, thrusters_data, time]= ...
getTestData(yaw_filepath, plotting, resampling_fs);
output_data = [imu_data, mag_data];
input_data = thrusters_data;
yaw_data1 = iddata(output_data, input_data, 1/resampling_fs);
%%
yaw_filepath = fullfile('bag','yaw_2_2016-04-18-13-46-47.bag');
[imu_data, mag_data, thrusters_data, time]= ...
getTestData(yaw_filepath, plotting, resampling_fs);
output_data = [imu_data, mag_data];
input_data = thrusters_data;
yaw_data2 = iddata(output_data, input_data, 1/resampling_fs);
%%
yaw_filepath = fullfile('bag','yaw_3_2016-04-18-13-50-03.bag');
[imu_data, mag_data, thrusters_data, time]= ...
getTestData(yaw_filepath, plotting, resampling_fs);
output_data = [imu_data, mag_data];
input_data = thrusters_data;
yaw_data3 = iddata(output_data, input_data, 1/resampling_fs);
%%
yaw_filepath = fullfile('bag','yaw_4_2016-04-18-13-52-57.bag');
[imu_data, mag_data, thrusters_data, time]= ...
getTestData(yaw_filepath, plotting, resampling_fs);
output_data = [imu_data, mag_data];
input_data = thrusters_data;
yaw_data4 = iddata(output_data, input_data, 1/resampling_fs);
%%
yaw_filepath = fullfile('bag','yaw_5_2016-04-18-13-56-59.bag');
[imu_data, mag_data, thrusters_data, time]= ...
getTestData(yaw_filepath, plotting, resampling_fs);
output_data = [imu_data, mag_data];
input_data = thrusters_data;
yaw_data5 = iddata(output_data, input_data, 1/resampling_fs);
%%
yaw_data = merge(yaw_data1, yaw_data2, yaw_data3, yaw_data4, yaw_data5);
end