yaw_filepath = fullfile('bag','act_1_2_5_6_test_6_2016-03-21-15-33-14.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, Ts]= ...
getTestData(yaw_filepath, 0, 0);

end_samp = 5500;
states(:,1:3) = states(:,1:3)*pi/180;
ang_vel_data = ang_vel_data*pi/180; 
states(:,1:3) = antiModAngles(states(:,1:3));
ang_vel_data = ang_vel_data(1:end_samp,:);
states = states(1:end_samp,1:3);
time = time(1:end_samp);
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
figure(1)
time = time - time(1);
plot(time,[cumsum(g_ang_vel(:,1))*Ts, antiModAngles(states(:,1))], 'LineWidth', 2)

ft = 30;
h = title('\phi');
set(h,'FontSize',ft);
h = ylabel('Angle [rad]');
set(h,'FontSize',ft);
h = xlabel('Time [s]');
set(h,'FontSize',ft);
set(gca,'FontSize',ft)

print -f1 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/velocityAnglePhi.eps' 
 %%
 figure(2)
 plot(time,[cumsum(g_ang_vel(:,2))*Ts, antiModAngles(states(:,2))], 'LineWidth', 2)

 ft = 30;
h = title('\theta');
set(h,'FontSize',ft);
h = ylabel('Angle [rad]');
set(h,'FontSize',ft);
h = xlabel('Time [s]');
set(h,'FontSize',ft);
set(gca,'FontSize',ft)

print -f2 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/velocityAngleTheta.eps'
%%
figure(3)
plot(time,[cumsum(g_ang_vel(:,3))*Ts, antiModAngles(states(:,3))], 'LineWidth', 2)

h = title('\psi');
set(h,'FontSize',ft);
h = ylabel('Angle [rad]');
set(h,'FontSize',ft);
h = xlabel('Time [s]');
set(h,'FontSize',ft);
set(gca,'FontSize',ft)

print -f3 -depsc2 '~/bin/ExjobbROV/Documents/Master/fig/velocityAnglePsi.eps'