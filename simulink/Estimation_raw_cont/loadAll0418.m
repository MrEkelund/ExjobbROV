function [All_data, initial_states] = loadAll0418(plotting, resampling_fs, detrend_enable)
%%
All_filepath = {
    fullfile('bag','all_1_2016-04-18-14-00-41.bag');
    fullfile('bag','all_2_2016-04-18-14-56-58.bag');
%     fullfile('bag','all_3_2016-04-18-15-04-50.bag');
%     fullfile('bag','all_4_2016-04-18-15-06-06.bag');
%     fullfile('bag','all_5_2016-04-18-15-06-44.bag')
    };

data = cell(size(All_filepath,1),1);
initial_states = zeros(10, length(All_filepath));
parfor i = 1:size(All_filepath,1)
    [imu_data, mag_data, thrusters_data, ~, initial_states(:,i)]= ...
        getTestData(All_filepath{i}, plotting, resampling_fs);
    if detrend_enable
        imu_data(1:3,:) = detrend(imu_data(1:3,:), 'Constant');
    end
    output_data = [imu_data, mag_data];
    input_data  = thrusterLookup(thrusters_data)';
    data{i} = iddata(output_data, input_data, 1/resampling_fs);
end

All_data = data{1};
for i = 2:size(All_filepath,1)
    All_data = merge(All_data, data{i});
end
end

