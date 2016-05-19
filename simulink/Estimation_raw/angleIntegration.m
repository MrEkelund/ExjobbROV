yaw_filepath = fullfile('bag','all_1_low_sensor_cov_7_2016-04-20-10-50-53.bag');
[imu_data, mag_data, thrusters_data, states, time, Ts]= ...
getTestData(yaw_filepath, 0, 0);



imu_data, mag_data, thrusters_data, time
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


g_ang_vel = zeros(size(ang_vel_data));
for i=1:size(states,1)
    rotmatrix = [...
    1, sfi(i)*stheta(i)/ctheta(i), cfi(i)*stheta(i)/ctheta(i);
    0, cfi(i), -sfi(i);
    0, sfi(i)/ctheta(i), cfi(i)/ctheta(i)];
    
    % Removed gravity from the acceleration
    g_ang_vel(i,:) = (rotmatrix*(ang_vel_data(i,:)'))';
end
%%
plot([cumsum(g_ang_vel(:,1))*Ts, antiModAngles(states(:,1))])

ft = 30;
h = legend('\int R(\nu_2)','\phi');
set(h,'FontSize',ft);
h = ylabel('Angle [rad]');
set(h,'FontSize',ft);
h = xlabel('Sample');
set(h,'FontSize',ft);
set(gca,'FontSize',ft)

% print -f1 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/velocityAnglePhi.eps' 
 %%
 close all
 plot([cumsum(g_ang_vel(:,2))*Ts, antiModAngles(states(:,2))])

h = legend('\int R(\nu_2)','\theta');
set(h,'FontSize',ft);
h = ylabel('Angle [rad]');
set(h,'FontSize',ft);
h = xlabel('Sample');
set(h,'FontSize',ft);
set(gca,'FontSize',ft)

% print -f1 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/velocityAngleTheta.eps'
%%
close all
plot([cumsum(g_ang_vel(:,3))*Ts, antiModAngles(states(:,3))])

h = legend('\int R(\nu_2)','\psi');
set(h,'FontSize',ft);
h = ylabel('Angle [rad]');
set(h,'FontSize',ft);
h = xlabel('Sample');
set(h,'FontSize',ft);
set(gca,'FontSize',ft)

% print -f1 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/velocityAnglePsi.eps'