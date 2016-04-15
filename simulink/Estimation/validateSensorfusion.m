Ts = 0.0045;
yaw_filepath = fullfile('bag','sensorValidation_2016-04-15-13-54-45.bag');
[lin_vel_data ,lin_acc_data, ang_vel_est, thrusters_data, states, time, ~]= ...
getTestData(yaw_filepath, 0);

states(:,1:3) = antiModAngles(states(:,1:3));
roll = states(:,1);
pitch = states(:,2);
yaw = states(:,3);
%%
sfi = sin(roll);
cfi = cos(roll);
spsi = sin(yaw);
cpsi = cos(yaw);
stheta = sin(pitch);
ctheta = cos(pitch);




g_ang_vel = zeros(size(ang_vel_est));
for i=1:size(states,1)
    rotmatrix=...
[1 , sfi(i)*stheta(i)/ctheta(i) ,cfi(i)*stheta(i)/ctheta(i);
0, cfi(i), -sfi(i);
0, sfi(i)/ctheta(i) ,cfi(i)/ctheta(i)];
    
    % Removed gravity from the acceleration
    g_ang_vel(i,:) = (rotmatrix*(ang_vel_est(i,:)'))';
end
%%
plot([cumsum(g_ang_vel(:,3))*Ts, antiModAngles(states(:,3))])