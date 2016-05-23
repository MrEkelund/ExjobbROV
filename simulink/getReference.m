filepath= fullfile('Estimation','bag','ratetest2_2016-05-20-08-30-09.bag');
bag = rosbag(filepath);
resampling_fs = 100;
ft = 30;

ref_bag = select(bag,'Topic','/reference');
ref_msgs = readMessages(ref_bag);

ref_data = zeros(size(ref_msgs,1),size(ref_msgs{1}.Data',2));
ref_time = zeros(size(ref_msgs,1),1);
for i = 1:size(ref_msgs,1)
    data = double(ref_msgs{i}.Data');
    ref_data(i,:) = data(:);
    ref_time(i) = ref_bag.MessageList{i,1};
end
ref_time_series = timeseries(ref_data, ref_time);

states_bag = select(bag,'Topic','/sensor_fusion/states');
states_msgs = readMessages(states_bag);

states_data = zeros(size(states_msgs,1),size(states_msgs{1}.Data',2));
states_time = zeros(size(states_msgs,1),1);
for i = 1:size(states_msgs,1)
    data = double(states_msgs{i}.Data');
    states_data(i,:) = data(:);
    states_time(i) = states_bag.MessageList{i,1};
end
states_time_series = timeseries(states_data, states_time);

% Syncronize the sensors
[ref_time_series, state_time_series] =...
    synchronize(ref_time_series, states_time_series,...
    'Uniform','Interval', 1/resampling_fs);
%%
ref_data = ref_time_series.data;
state_data = state_time_series.data;
time = ref_time_series.Time - ref_time_series.Time(1);
legend_ent = {'\phi', '\theta', '\psi', 'p',  'q',  'r',  'd'};
legend_ent_ref = {'\phi_{ref}', '\theta_{ref}', '\psi_{ref}', 'p_{ref}', 'q_{ref}', 'r_{ref}', 'd_{ref}'};
units = {'rad', 'rad', 'rad', 'rad/s', 'rad/s', 'rad/s', 'm'};
ylabel_ent = {'Angle', 'Angle', 'Angle', 'Angle Velocity', 'Angle Velocity', 'Angle Velocity', 'Depth'};
for i=1:7
    h = figure(i);
    plot(time,[ref_data(:,i), state_data(:,i)],'LineWidth',2)
    h = legend({legend_ent{i}, legend_ent_ref{i}});
    
    set(h,'FontSize',ft);
    h = ylabel(strcat(ylabel_ent{i},'[', units{i}, ']'));
    set(h,'FontSize',ft);
    h = xlabel('Time [s]');
    set(h,'FontSize',ft);
    set(gca,'FontSize',ft)
end
