filepath= fullfile('Estimation','bag','sinPa05hz05_2016-05-23-15-13-18.bag');
bag = rosbag(filepath);
resampling_fs = 100;
ft = 30;

% filepath = fullfile('Estimation','bag','sinPa05hz05_2016-05-23-15-13-18.bag');
% start_time = 200; 
% end_time = 2100;

% filepath = fullfile('Estimation','bag','sinPA1Hz05_2016-05-23-15-25-06.bag');
% start_time = 300; 
% end_time = 2125;
% axis([0 (end_time - start_time)/resampling_fs -1.5 1.5])

% filepath = fullfile('Estimation','bag','sinAllA05Hz05_2016-05-23-15-31-03.bag');
% start_time = 300; 
% end_time = 2300;
%axis([0 (end_time - start_time)/resampling_fs -0.7 0.7])

% filepath = fullfile('Estimation','bag','sinAllA1hz05_2016-05-23-15-28-28.bag');
% start_time = 350; 
% end_time = 1200;
% axis([0 (end_time - start_time)/resampling_fs -1.3 1.3])

% filepath = fullfile('Estimation','bag','sinQA1Hz05_2016-05-23-15-27-20.bag');
% start_time = 400; 
% end_time = 2200;
% axis([0 (end_time - start_time)/resampling_fs -1.3 1.3])


% filepath = fullfile('Estimation','bag','sinQNewA05Hz05_2016-05-23-15-20-56.bag');
% start_time = 600; 
% end_time = 1800;
% axis([0 (end_time - start_time)/resampling_fs -0.8 0.8])

% filepath = fullfile('Estimation','bag','sinRA1Hz05_2016-05-23-15-23-40.bag');
% start_time = 300; 
% end_time = 1900;
% axis([0 (end_time - start_time)/resampling_fs -1.2 1.2])

% filepath = fullfile('Estimation','bag','sinRNewA05Hz05_2016-05-23-15-21-51.bag');
% start_time = 400; 
% end_time = 1200;
% axis([0 (end_time - start_time)/resampling_fs -1.2 1.2])

% filepath = fullfile('Estimation','bag','stepAlls3e10a1_2016-05-23-14-55-40.bag');
% start_time = 300; 
% end_time = 2000;
% axis([0 (end_time - start_time)/resampling_fs -0.5 1.6])

% filepath = fullfile('Estimation','bag','stepPs3e10_2016-05-23-13-53-27.bag');
% start_time = 300; 
% end_time = 2000;
% axis([0 (end_time - start_time)/resampling_fs -0.5 1.6])

% filepath = fullfile('Estimation','bag','stepQs3e10_2016-05-23-13-56-33.bag');
% start_time = 300; 
% end_time = 1900;
% axis([0 (end_time - start_time)/resampling_fs -0.5 1.6])

% filepath = fullfile('Estimation','bag','stepRs3e10_2016-05-23-13-59-06.bag');
% start_time = 1; 
% end_time = 1600;
% axis([0 (end_time - start_time)/resampling_fs -0.5 1.6])

% filepath = fullfile('Estimation','bag','constDepth_2016-05-23-15-53-10.bag');
% start_time = 700; 
% end_time = 5000;
% start_time = 5000; 
% end_time = 7960;
% axis([0 (end_time - start_time)/resampling_fs 0 3])

%%    
bag = rosbag(filepath);
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
time = ref_time_series.Time(start_time:end_time) - ref_time_series.Time(start_time);
legend_ent = {'\phi', '\theta', '\psi', 'p',  'q',  'r',  'd'};
legend_ent_ref = {'\phi_{ref}', '\theta_{ref}', '\psi_{ref}', 'p_{ref}', 'q_{ref}', 'r_{ref}', 'd_{ref}'};
units = {'rad', 'rad', 'rad', 'rad/s', 'rad/s', 'rad/s', 'm'};
ylabel_ent = {'Angle', 'Angle', 'Angle', 'Angle Velocity', 'Angle Velocity', 'Angle Velocity', 'Depth'};
for i=1:7
    h = figure(i);
    plot(time,[ref_data(start_time:end_time,i), state_data(start_time:end_time,i)],'LineWidth',2)
    h = legend({legend_ent_ref{i}, legend_ent{i}});
    set(h,'FontSize',ft);
    h = ylabel(strcat(ylabel_ent{i},'[', units{i}, ']'));
    set(h,'FontSize',ft);
    h = xlabel('Time [s]');
    set(h,'FontSize',ft);
    title(legend_ent{i})
    set(gca,'FontSize',ft)
end
%%
% print -f6 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/testStepAllRs3e10a1.eps'