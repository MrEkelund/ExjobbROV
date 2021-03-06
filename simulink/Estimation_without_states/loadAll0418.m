function All_data = loadAll0418()
%%
Ts = 0.0045;
All_filepath = {
    fullfile('bag','all_1_2016-04-18-14-00-41.bag');
%    fullfile('bag','all_2_2016-04-18-14-56-58.bag');
%     fullfile('bag','all_3_2016-04-18-15-04-50.bag');
%     fullfile('bag','all_4_2016-04-18-15-06-06.bag');
%     fullfile('bag','all_5_2016-04-18-15-06-44.bag')
    };

data = cell(size(All_filepath,1),1);
for i = 1:size(All_filepath,1)
    [lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
        getTestData(All_filepath{i}, 0);
    output_data = ang_vel_data;
    input_data = [thrusters_data, antiModAngles(states(:,1:3))];
    data{i} = iddata(output_data, input_data, Ts);
end

All_data = data{1};
for i = 2:size(All_filepath,1)
    All_data = merge(All_data, data{i});
end
end

