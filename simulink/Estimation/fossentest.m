 endtime = 40;
 r= 100 * endtime; 
 acc_matrix = repmat([0 0 9.806],[r 1]);
 yaw = repmat([0], [r ,1]);
 roll =repmat([0], [r ,1]);
 pitch = repmat([0], [r ,1]);
 depth = repmat([0], [r ,1]);
 k1 = diag([0.01 0.01 0.1]);
 k2 = diag([1 1 1]);
 k3 = diag([0.1 0.1 0.1]*1);
 time = linspace(0,endtime,r)';
 [a b] = fossenIntegration(acc_matrix, roll , pitch, yaw,depth,k1, k2, k3, time);
 a;
 
 plot(time(1:end-1), a)
 legend('x','y','z')