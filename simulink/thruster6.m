resampling_fs = 100;
ft = 30;
filepath = fullfile('Estimation','bag','thruster6_2016-05-25-09-31-53.bag');
start_time = 1; 
end_time = 930;

filepath = fullfile('Estimation','bag','thruster6Lowontrol_2016-05-25-09-32-19.bag');
start_time = 1; 
end_time = 1684;

%%
bag = rosbag(filepath);
thrusters_bag = select(bag,'Topic','/rovio/thrusters');
thrusters_msgs = readMessages(thrusters_bag);

thrusters_data = zeros(size(thrusters_msgs,1),size(thrusters_msgs{1}.Data',2));
thrusters_time = zeros(size(thrusters_msgs,1),1);
for i = 1:size(thrusters_msgs,1)
    data = double(thrusters_msgs{i}.Data');
    thrusters_data(i,:) = (data(:) - 1500)/400;
    thrusters_time(i) = thrusters_bag.MessageList{i,1};
end
thrusters_time_series = timeseries(thrusters_data, thrusters_time);

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
[thrusters_time_series, state_time_series] =...
    synchronize(thrusters_time_series, states_time_series,...
    'Uniform','Interval', 1/resampling_fs);
%%
thrusters_data = thrusters_time_series.data;
state_data = state_time_series.data;
time = thrusters_time_series.Time(start_time:end_time) - thrusters_time_series.Time(start_time);
legend_ent = {'u_6', 'p', 'r'};
units = {'%', 'rad/s', 'rad/s'};
ylabel_ent = {'Amplitude','Angle Velocity','Angle Velocity'};
h = figure(1);
plot(time,[thrusters_data(start_time:end_time,6)],'LineWidth',2)
h = ylabel(strcat(ylabel_ent{1},'[', units{1}, ']'));
set(h,'FontSize',ft);
h = xlabel('Time [s]');
set(h,'FontSize',ft);
title(legend_ent{1})
set(gca,'FontSize',ft)
axis([0 (end_time - start_time)/resampling_fs -1 1])

h = figure(2);
plot(time,[states_data(start_time:end_time,4)],'LineWidth',2)
h = ylabel(strcat(ylabel_ent{2},'[', units{2}, ']'));
set(h,'FontSize',ft);
h = xlabel('Time [s]');
set(h,'FontSize',ft);
title(legend_ent{2})
set(gca,'FontSize',ft)
axis([0 (end_time - start_time)/resampling_fs -1.5 1.5])

h = figure(3);
plot(time,[states_data(start_time:end_time,5)],'LineWidth',2)
h = ylabel(strcat(ylabel_ent{3},'[', units{3}, ']'));
set(h,'FontSize',ft);
h = xlabel('Time [s]');
set(h,'FontSize',ft);
title(legend_ent{3})
set(gca,'FontSize',ft)
axis([0 (end_time - start_time)/resampling_fs -1.5 1.5])

%%
print -f1 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/lowcontrolthruster6u6.eps'
print -f2 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/lowcontrolthruster6p.eps'
print -f3 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/lowcontrolthruster6r.eps'