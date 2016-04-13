Ts = 0.0045;
yaw_filepath = fullfile('bag','test1_t3_t4_2016-04-04-14-57-52.bag');
[lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time, ~]= ...
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

g_ang_vel = zeros(size(ang_vel_data));
for i=1:size(states,1)
    rotmatrix = [ ctheta(i).*cpsi(i), ctheta(i).*spsi(i), -sfi(i);
        sfi(i).*stheta(i).*cpsi(i) - cfi(i).*spsi(i), sfi(i).*stheta(i).*spsi(i) + cfi(i).*cpsi(i), sfi(i).*ctheta(i);
        cfi(i).*stheta(i).*cpsi(i) + sfi(i).*spsi(i), cfi(i).*stheta(i).*spsi(i) - sfi(i).*spsi(i), cfi(i).*ctheta(i)]';
    
    % Removed gravity from the acceleration
    g_ang_vel(i,:) = (rotmatrix*(ang_vel_data(i,:)'))';
end
%%
plot([cumsum(detrend(g_ang_vel(:,3)))*Ts, antiModAngles(states(:,3))])