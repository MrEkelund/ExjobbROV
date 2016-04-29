syms yaw pitch roll...
    yaw_rate pitch_rate roll_rate...
    q quat_0 quat_1 quat_2 quat_3 qdot...
    Sq Sw Q...
    acc_meas a_global_x a_global_y a_global_z...
    acc_n acc_e acc_d g acc_ned...
    mag_global mag_n mag_e mag_d...
    wx wy wz...
    p q r...
    b_p b_q b_r...
    F T motion_model...
    rho g x_offset d pressure_atm...
    Gv Euler delta_t n quat_1 quat_2 quat_3

% define som matrixes
%rotation matrix from body/sensor frame to global frame
%old rot Q = [2*(quat_0^2+quat_1^2) - 1,  2*(quat_1*quat_2-quat_0*quat_3),    2*(quat_1*quat_3+quat_0*quat_2);
 %   2*(quat_1*quat_2+quat_0*quat_3),    2*(quat_0^2+quat_2^2) - 1,  2*(quat_2*quat_3-quat_0*quat_1);
 %   2*(quat_1*quat_3-quat_0*quat_2),    2*(quat_2*quat_3+quat_0*quat_1),    2*(quat_0^2+quat_3^2) - 1];
RQ =...
    [1 - 2*(quat_2^2 + quat_3^2), 2*(quat_1*quat_2 - quat_3*quat_0), 2*(quat_1*quat_3 + quat_2*quat_0);
     2*(quat_1*quat_2 + quat_3*quat_0),  1-2*(quat_1^2 + quat_3^2),2*(quat_2*quat_3-quat_1*quat_0);
     2*(quat_1*quat_3 - quat_2*quat_0),  2*(quat_2*quat_3 + quat_1*quat_0), 1-2*(quat_1^2 + quat_2^2)];

%quarternion vector
quat = [quat_0;quat_1;quat_2;quat_3];
nu=[p;q;r];



Sq = [-quat_1, -quat_2, -quat_3;
     quat_0, -quat_3,  quat_2;
     quat_3,  quat_0, -quat_1;
     -quat_2, quat_1, quat_0];


 T_eta =1/2*...
     [-quat_1 ,-quat_2 -quat_3;
     quat_0 -quat_3 quat_2;
     quat_3 quat_0 -quat_1;
     -quat_2 quat_1 quat_0];
 T_bar_nu=1/2*...
     [0 -p -q -r;
     p 0 r -q;
     q -r 0 p;
     r q -p 0];





 %% H matrix 
 %acceleration in body frame
acc_ned = [acc_n; acc_e; acc_d];


% measurement equation for acceleration
acc_meas = transpose(RQ)*([0; 0; -g]); % fråga Manon + acc_ned


% measurement equation for magnetometer 
mag_global=[sqrt(mag_n^2 + mag_e^2);0;mag_d]; % could change to mx 0 mz and use bjord =mz bjord sin(θdip)dˆ+ bjord cos(θdip)nˆ
mag_meas = transpose(RQ)*mag_global;

% measurement equation pressure sensor
 pressure_meas =  rho*g*(d+[0,0,1]*RQ*[x_offset;0;0]);
 
% Measurement equation for gyro
 gyro_meas = [p + b_p; q + b_q; r + b_r];
 
 measurement_eqs = [acc_meas;gyro_meas;mag_meas;pressure_meas];
 
 states = [transpose(quat),p,q,r,b_p,b_q,b_r,d];
 %derivatives for acc meas eq
 nr_meas_eqs = length(measurement_eqs);
 nr_states = length(states);

for i=1:nr_meas_eqs
    for j=1:nr_states
        H(i,j) = diff(measurement_eqs(i),states(j));
    end
end

 %% Motion model
 %old !!!!motion_model = blkdiag([eye(4) + delta_t*T_bar_nu,delta_t^2*T_eta;zeros(3,4),eye(3)],eye(4));
 motionmodel = blkdiag(eye(4) + delta_t*T_bar_nu,eye(7));
 
 
 %old !!1 Gv = [[delta_t^3*T_eta/2;delta_t*eye(3)],zeros(7,3),zeros(7,1);
 Gv= blkdiag([delta_t^2*T_eta;delta_t*eye(3)],delta_t*eye(4))
 %% F matrix
 for n=1:nr_states
   for m=1:nr_states
      F(n,m) = diff(motionmodel(n,:)*transpose(states),states(m));
   end
 end
    
%% print
H_acc=H(1:3,:);
h_acc=measurement_eqs(1:3);

H_gyro=H(4:6,:);
h_gyro=measurement_eqs(4:6); 

H_mag=H(7:9,:);
h_mag=measurement_eqs(7:9);

H_pressure=H(10,:);
h_pressure=measurement_eqs(10);

f=motionmodel;

strrep(strrep(strrep(ccode(H_acc),'][',','),'[','('),']',')')
strrep(strrep(strrep(ccode(h_acc),'][',','),'[','('),']',')')
strrep(strrep(strrep(ccode(H_gyro),'][',','),'[','('),']',')')
strrep(strrep(strrep(ccode(h_gyro),'][',','),'[','('),']',')')
strrep(strrep(strrep(ccode(H_mag),'][',','),'[','('),']',')')
strrep(strrep(strrep(ccode(h_mag),'][',','),'[','('),']',')')
strrep(strrep(strrep(ccode(H_pressure),'][',','),'[','('),']',')')
strrep(strrep(strrep(ccode(h_pressure),'][',','),'[','('),']',')')
strrep(strrep(strrep(ccode(F),'][',','),'[','('),']',')')
strrep(strrep(strrep(ccode(f),'][',','),'[','('),']',')')
strrep(strrep(strrep(ccode(Gv),'][',','),'[','('),']',')')
 
 
 
 
 
 
 
 
 