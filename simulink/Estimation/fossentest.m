
 yaw_filepath = fullfile('bag','act_3_4_test_3_2016-03-21-15-09-30.bag');
 [lin_vel_data ,lin_acc_data, ang_vel_data, thrusters_data, states, time,Ts]= ...
     getTestData(yaw_filepath, 0);
%%

 acc_matrix = lin_acc_data;
 pitch = states(:,1);
 roll = states(:,2);
 yaw = states(:,3);
 depth = states(:,4);
%  compensated_acc_data = removeGravity( roll,pitch,yaw, acc_matrix)
%   pitch = compensated_acc_data(:,1);
%  roll = compensated_acc_data(:,2);
%  yaw = compensated_acc_data(:,3);

 k1 = diag([0.00001 0.00001 10]);
 k2 = diag([1 1 100]);
 k3 = diag([0.1 0.1 0.1]*0.1);
 [a b] = fossenIntegration(acc_matrix, roll , pitch, yaw,depth,k1, k2, k3, time);
 a;
 
figure
 plot(time(1:end-1)-time(1), a(:,1))
%  legend('x','y','z')
 
%  plot(time - time(1),compensated_acc_data)