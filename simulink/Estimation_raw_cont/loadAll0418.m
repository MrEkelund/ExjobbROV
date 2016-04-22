function All_data = loadAll0418(plotting, resampling_fs)
%%
All_filepath = fullfile('bag','all_1_2016-04-18-14-00-41.bag');
[imu_data, mag_data, thrusters_data, time]= ...
getTestData(All_filepath, plotting, resampling_fs);
imu_data(:,1:3) = detrend(imu_data(:,1:3), 'constant');
output_data = [imu_data, mag_data];
input_data = thrusterLookup(thrusters_data)';
All_data1 = iddata(output_data, input_data, 1/resampling_fs);

%%
All_filepath = fullfile('bag','all_2_2016-04-18-14-56-58.bag');
[imu_data, mag_data, thrusters_data, time]= ...
getTestData(All_filepath, plotting, resampling_fs);
imu_data(:,1:3) = detrend(imu_data(:,1:3), 'constant');
output_data = [imu_data, mag_data];
input_data = thrusterLookup(thrusters_data)';
All_data2 = iddata(output_data, input_data, 1/resampling_fs);
% %%
% All_filepath = fullfile('bag','all_3_2016-04-18-15-04-50.bag');
% [imu_data, mag_data, thrusters_data, time]= ...
% getTestData(All_filepath, plotting, resampling_fs);
% output_data = [imu_data, mag_data];
% input_data = thrusterLookup(thrusters_data)';
% All_data3 = iddata(output_data, input_data, 1/resampling_fs);
% %%
% All_filepath = fullfile('bag','all_4_2016-04-18-15-06-06.bag');
% [imu_data, mag_data, thrusters_data, time]= ...
% getTestData(All_filepath, plotting, resampling_fs);
% output_data = [imu_data, mag_data];
% input_data = thrusterLookup(thrusters_data)';
% All_data4 = iddata(output_data, input_data, 1/resampling_fs);
%%
% All_filepath = fullfile('bag','all_5_2016-04-18-15-06-44.bag');
% [imu_data, mag_data, thrusters_data, time]= ...
% getTestData(All_filepath, plotting, resampling_fs);
% output_data = [imu_data, mag_data];
% input_data = thrusterLookup(thrusters_data)';
% All_data5 = iddata(output_data, input_data, 1/resampling_fs);

%%
% All_data = merge(All_data1, All_data2, All_data3, All_data4, All_data5);
All_data = merge(All_data1, All_data2);
end

