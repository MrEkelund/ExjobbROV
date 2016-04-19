function [lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, Ts] = getTestData(filepath,plotting)
    %getTestData
    %   Input: filepath - Fullfilepath or relative.
    %   Input: plotting - 1 for subplots of the data. 0 for no plots
    %
    %   Output: lin_vel_data  - Linear velocites in x,y,z.
    %   Output: lin_acc_data  - Linear acceleration in x,y,z.
    %   Output: ang_vel_data  - Angular velocites about x,y,z.
    %   Output: thruster_data - thruster data vector.
    %   Output: states - states.
    %   Output: time - Time vector.
    %   Output: Ts - Sampling period.
    
    bag = rosbag(filepath);
    %% States
    states_bag = select(bag,'Topic','/sensor_fusion/states');
    states_msgs = readMessages(states_bag);
    
    states_data = zeros(size(states_msgs,1),size(states_msgs{1}.Data',2));
    states_time = zeros(size(states_msgs,1),1);
    for i = 1:size(states_msgs,1)
        data = double(states_msgs{i}.Data');
        states_data(i,:) = data(:);
        states_time(i) = states_bag.MessageList{i,1};
    end

%% Thrusters
    thrusters_bag = select(bag,'Topic','/rovio/thrusters');
    
    thrusters_msgs = readMessages(thrusters_bag);
    
    if isempty(thrusters_msgs)
        thrusters_data = zeros(size(states_data,1),6);
        time = states_time;
        Ts = 0.0045;
    else
        thrusters_data = zeros(size(thrusters_msgs,1),size(thrusters_msgs{1}.Data',2));
        thrusters_time = zeros(size(thrusters_msgs,1),1);
        for i = 1:size(thrusters_msgs,1)
            data = double(thrusters_msgs{i}.Data');
            thrusters_data(i,:) = (data(:) - 1500)/400;
            thrusters_time(i) = thrusters_bag.MessageList{i,1};
        end
        [thrusters_data, states_data, time, Ts] = resampleControlSignals(thrusters_data, thrusters_time, states_data, states_time);
    end
    
states = states_data(:,[1 2 3 10]); % Angels and depth
states(:,1:3) = antiModAngles(states(:,1:3));
ang_vel_data = states_data(:,4:6);
lin_acc_data = states_data(:,8:10);
lin_vel_data = 0;


if plotting
    plotData(states, ang_vel_data, lin_vel_data,lin_acc_data, thrusters_data, time, filepath);
end

end
