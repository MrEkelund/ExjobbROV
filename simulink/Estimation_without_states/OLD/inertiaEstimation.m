clear all
close all
Ts = 0.0045;
%%
inertia_filepath = fullfile('bag','test1_pitch_inertia_2016-04-04-15-37-52.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time,Ts]= ...
    getTestData(inertia_filepath, 0);
output_data = [zeros(size(ang_vel_data)), ang_vel_data , states(:,1:2)];
input_data = thrusters_data;
data1_pitch = iddata(output_data, input_data, Ts);
data1_pitch = merge(data1_pitch(814:1243,:),...
    data1_pitch(814:1243,:), data1_pitch(1608:2040,:)...
    ,data1_pitch(2414:2814,:), data1_pitch(4113:4605,:)...
    ,data1_pitch(5296:5738,:), data1_pitch(6164:6681,:)...
    ,data1_pitch(6164:6681,:), data1_pitch(8595:9040)...
    ,data1_pitch(9536:10122,:));
%%
inertia_filepath = fullfile('bag','test1_roll_inertia_2016-04-04-15-34-25.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time,Ts]= ...
    getTestData(inertia_filepath, 0);
output_data = [zeros(size(ang_vel_data)), ang_vel_data , states(:,1:2)];
input_data = thrusters_data;
data = iddata(output_data, input_data, Ts);
data1_roll = merge(data1_roll(1129:1904,:), data1_roll(2723:3372,:), data1_roll(4094:4777,:), data1_roll(5505:6143,:), data1_roll(6843:7400,:));
%%
inertia_filepath = fullfile('bag','test2_roll_inertia_2016-04-04-15-36-20.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time,Ts]= ...
    getTestData(inertia_filepath, 0);
output_data = [zeros(size(ang_vel_data)), ang_vel_data , states(:,1:2)];
input_data = thrusters_data;
data2_roll = iddata(output_data, input_data, Ts);
data2_roll = merge(data2_roll(839:1361,:), data2_roll(1747:2289,:), data2_roll(2806:3212,:), data2_roll(3709:4155,:), data2_roll(4599:5040,:), data2_roll(5437:5979,:), data2_roll(6343:6897,:));
%%
pitch_data = data1_pitch;
roll_data = merge(data1_roll, data2_roll);
%%


