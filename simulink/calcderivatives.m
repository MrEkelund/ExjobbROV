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
    Gv Euler delta_t

% define som matrixes
%rotation matrix from body/sensor frame to global frame
Q = [2*(quat_0^2+quat_1^2) - 1,  2*(quat_1*quat_2-quat_0*quat_3),    2*(quat_1*quat_3+quat_0*quat_2);
    2*(quat_1*quat_2+quat_0*quat_3),    2*(quat_0^2+quat_2^2) - 1,  2*(quat_2*quat_3-quat_0*quat_1);
    2*(quat_1*quat_3-quat_0*quat_2),    2*(quat_2*quat_3+quat_0*quat_1),    2*(quat_0^2+quat_3^2) - 1];
%quarternion vector
quat = [quat_0;quat_1;quat_2;quat_3];



Sq = [-quat_1, -quat_2, -quat_3;
     quat_0, -quat_3,  quat_2;
     quat_3,  quat_0, -quat_1;
     -quat_2, quat_1, quat_0];

 

Sw = [0, -(p ), -(q ), -(r ); % wx = p +b_p  bias is subtracted in ard
    (p ), 0, (r ), -(q );
    (q ), -(r ), 0, (p );
    (r ), (q ), -(p ), 0];




 %% H matrix 
 %acceleration in body frame
acc_ned = [acc_n; acc_e; acc_d];


% measurement equation for acceleration
acc_meas = transpose(Q)*([0; 0; -g]); % fråga Manon + acc_ned


% measurement equation for magnetometer 
mag_global=[sqrt(mag_n^2 + mag_e^2);0;mag_d]; % could change to mx 0 mz and use bjord =mz bjord sin(θdip)dˆ+ bjord cos(θdip)nˆ
mag_meas = transpose(Q)*mag_global;

% measurement equation pressure sensor
 pressure_meas =  rho*g*(d+[0,0,1]*Q*[x_offset;0;0]);
 
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
 motion_model = blkdiag([eye(4) + delta_t*Sw/2,delta_t^2*Sq/2;zeros(3,4),eye(3)],eye(4))
 Gv = [[delta_t^3*Sq/4;delta_t*eye(3)],zeros(7,3),zeros(7,1);
     zeros(3,3),delta_t*eye(3),zeros(3,1);
     zeros(1,3),zeros(1,3),delta_t*eye(1)];
 %% F matrix
 %for n=1:nr_states
 %  for m=1:nr_states
 %     F(n,m) = diff(motion_model(n,1),states(m));
 %  end
 %end
    
%% print


strrep(strrep(strrep(ccode(Gv),'][',','),'[','('),']',')')

 
 
 
 
 
 
 
 
 
 
 