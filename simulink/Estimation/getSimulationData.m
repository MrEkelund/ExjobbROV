function [lin_vel_data lin_acc_data, ang_vel_data, thrusters_data, states, time, Ts] = getSimulationData(filepath,plotting)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

dataset = load(filepath);

acc_vel_list = {'x','y','z'};
ang_vel_list = {'p','q','r'};
thrusters_list = {'u1','u2','u3','u4','u5','u6'};
states_list = {'phi','theta','psi','D'};

lin_vel_data = 0;

lin_acc_data = zeros(size(dataset.data.get(char(ang_vel_list(1))).Values.Data,1),3);
% for i=1:3
%     lin_acc_data(:,i) = dataset.data.get(acc_vel_list(i)).Values.Data;
% end

ang_vel_data = zeros(size(dataset.data.get(char(ang_vel_list(1))).Values.Data,1),3);
for i=1:3
    ang_vel_data(:,i) = dataset.data.get(char(ang_vel_list(i))).Values.Data;
end

thrusters_data = zeros(size(dataset.data.get(char(thrusters_list(1))).Values.Data,1),6);
for i=1:6
    thrusters_data(:,i) = dataset.data.get(char(thrusters_list(i))).Values.Data;
end

states = zeros(size(dataset.data.get(char(states_list(1))).Values.Data,1),4);
for i=1:4
    states(:,i) = dataset.data.get(char(states_list(i))).Values.Data;
end
time = dataset.data.get(char(states_list(1))).Values.Time;
Ts = mean(time(2:end) - time(1:end-1));

if plotting
    plotData(states, ang_vel_data, lin_vel_data,lin_acc_data, thrusters_data, time);
end
end

