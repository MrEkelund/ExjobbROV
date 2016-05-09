function [imu_data, mag_data, thrusters_data, time] = ...
    getTestData(filepath, plotting, resampling_fs)
    %getTestData
    %   Input: filepath - Fullfilepath or relative.
    %   Input: plotting - 1 for subplots of the data. 0 for no plots
    %   Input: resampling_fs - Resampling frequency in Hz
    %
    %   Output: imu_data  - Angular velocites and linear acceleration about/in x,y,z.
    %   Output: mag_data  - Magnetic field in x,y,z.
    %   Output: thruster_data - thruster data vector.
    %   Output: time - Time vector.
    
    bag = rosbag(filepath);
    %% Imu
    imu_bag = select(bag,'Topic','/rovio/imu/data');
    imu_msgs = readMessages(imu_bag);
    
    imu_data = zeros(size(imu_msgs,1),size(imu_msgs{1}.Data',2) - 1);
    imu_time = zeros(size(imu_msgs,1),1);
    for i = 1:size(imu_msgs,1)
        data = double(imu_msgs{i}.Data');
        imu_data(i,:) = data(2:end); %skip the time
        imu_time(i) = imu_bag.MessageList{i,1};
    end
    
    imu_time_series = timeseries(imu_data, imu_time);
    %% Magnetometer
    mag_bag = select(bag,'Topic','/rovio/magnetometer/data');
    mag_msgs = readMessages(mag_bag);
    
    mag_data = zeros(size(mag_msgs,1),size(mag_msgs{1}.Data',2));
    mag_time = zeros(size(mag_msgs,1),1);
    for i = 1:size(mag_msgs,1)
        data = double(mag_msgs{i}.Data');
        mag_data(i,:) = data(:);
        mag_time(i) = mag_bag.MessageList{i,1};
    end
    
    mag_time_series = timeseries(mag_data, mag_time);
    
    % Syncronize the sensors
    [imu_time_series, mag_time_series] =...
        synchronize(imu_time_series, mag_time_series,...
        'Uniform','Interval', 1/resampling_fs);
    %% states
    state_bag = select(bag,'Topic','/sensor_fusion/states');
    state_msgs = readMessages(state_bag);
    
    state_data = zeros(size(state_msgs,1),size(state_msgs{1}.Data',2));
    state_time = zeros(size(state_msgs,1),1);
    for i = 1:size(state_msgs,1)
        data = double(state_msgs{i}.Data');
        state_data(i,:) = data(:);
        state_time(i) = state_bag.MessageList{i,1};
    end
    
    
%% Thrusters
    thrusters_bag = select(bag,'Topic','/rovio/thrusters');
    
    thrusters_msgs = readMessages(thrusters_bag);
    
    if isempty(thrusters_msgs)
        thrusters_data = zeros(size(imu_data,1),6);
        time = imu_time;
    else
        thrusters_data = zeros(size(thrusters_msgs,1),size(thrusters_msgs{1}.Data',2));
        thrusters_time = zeros(size(thrusters_msgs,1),1);
        for i = 1:size(thrusters_msgs,1)
            data = double(thrusters_msgs{i}.Data');
            thrusters_data(i,:) = (data(:) - 1500)/400; % Remove the pwm offset and normalise
            thrusters_time(i) = thrusters_bag.MessageList{i,1};
        end
        [thrusters_data, time] =...
            resampleControlSignals(thrusters_data, thrusters_time,...
            imu_time_series.Time, resampling_fs);
    end
    thrusters_time_series = timeseries(thrusters_data, time);
    % Syncronize the sensor data with the thrusters data over the experiment time
    [thrusters_time_series_test, imu_time_series_test] =...
        synchronize(thrusters_time_series, imu_time_series,...
        'Uniform','Interval', 1/resampling_fs);
    [thrusters_time_series_test, mag_time_series_test] =...
        synchronize(thrusters_time_series, mag_time_series,...
        'Uniform','Interval', 1/resampling_fs);
if plotting
    plotData(imu_time_series_test, mag_time_series_test, thrusters_time_series_test, filepath);
end
first_time_instant = find((imu_time_series.Time - imu_time_series_test.Time(1)) > -0.1*1/resampling_fs & (imu_time_series.Time - imu_time_series_test.Time(1) < 1/resampling_fs*2),1);

imu_data = imu_time_series_test.Data;
mag_data = mag_time_series_test.Data;
thrusters_data = thrusters_time_series_test.Data;
time = imu_time_series_test.Time;

% initial_state = initialEkf(1/resampling_fs, [imu_time_series.Data(1:first_time_instant,:).'; mag_time_series.Data(1:first_time_instant,:).'], mag_data(1,1), mag_data(1,2), mag_data(1,3));
end
