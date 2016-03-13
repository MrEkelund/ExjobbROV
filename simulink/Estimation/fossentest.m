 r= 1000; 
 acc_matrix = repmat([6.9343 0 -6.9343],[r 1]);
 yaw = repmat([0], [r ,1]);
 roll =repmat([0], [r ,1]);
 pitch = repmat([45], [r ,1]);
 depth = repmat([0], [r ,1]);
 k1 = [1 1 1];
 k2 = [1 1 1];
 k3 = [0.1 0.1 0.1]*1;
 time = linspace(0,10,r)';
 [a b] = fossenIntegration(acc_matrix, roll , pitch, yaw,depth,k1, k2, k3, time);
 a