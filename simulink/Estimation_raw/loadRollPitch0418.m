function roll_pitch_data = loadRollPitch0418(plotting, resampling_fs)
%%
roll_pitch_filepath = fullfile('bag','pitch_roll_1_2016-04-18-13-11-33.bag');
[imu_data, mag_data, thrusters_data, time]= ...
getTestData(roll_pitch_filepath, plotting, resampling_fs);
output_data = [imu_data, mag_data];
input_data = thrusters_data;
roll_pitch_data1 = iddata(output_data, input_data, 1/resampling_fs);
%%
roll_pitch_filepath = fullfile('bag','pitch_roll_2_2016-04-18-13-25-02.bag');
[imu_data, mag_data, thrusters_data, time]= ...
getTestData(roll_pitch_filepath, plotting, resampling_fs);
output_data = [imu_data, mag_data];
input_data = thrusters_data;
roll_pitch_data2 = iddata(output_data, input_data, 1/resampling_fs);
%%
roll_pitch_filepath = fullfile('bag','pitch_roll_3_2016-04-18-13-37-02.bag');
[imu_data, mag_data, thrusters_data, time]= ...
getTestData(roll_pitch_filepath, plotting, resampling_fs);
output_data = [imu_data, mag_data];
input_data = thrusters_data;
roll_pitch_data3 = iddata(output_data, input_data, 1/resampling_fs);
%%
roll_pitch_data = merge(roll_pitch_data1, roll_pitch_data2, roll_pitch_data3);
end