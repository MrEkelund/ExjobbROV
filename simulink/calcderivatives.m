syms yaw pitch roll...
    yaw_rate pitch_rate roll_rate...
    q q0 q1 q2 q3 qdot...
    Sq Sw Q...
    acc_meas a_global_x a_global_y a_global_z...
    acc_n acc_e acc_d g acc_ned...
    mag_global mag_n mag_e mag_d...
    wx wy wz...
    acc_bias...
    F T motion_model...
    rho g x_offset d pressure_atm...
    Gv

% define som matrixes
%rotation matrix from body/sensor frame to global frame
Q = [2*(q0^2+q1^2) - 1,  2*(q1*q2-q0*q3),    2*(q1*q3+q0*q2);
    2*(q1*q2+q0*q3),    2*(q0^2+q2^2) - 1,  2*(q2*q3-q0*q1);
    2*(q1*q3-q0*q2),    2*(q2*q3+q0*q1),    2*(q0^2+q3^2) - 1];
%quarternion vector
q = [q0;q1;q2;q3];



Sq = [-q1, -q2, -q3;
     q0, -q3,  q2;
     q3,  q0, -q1;
     -q2, q1, q0];

 

Sw = [0, -(wx ), -(wy ), -(wz ); % wk = gyro_meas - bias
    (wx ), 0, (wz ), -(wy );
    (wy ), -(wz ), 0, (wx );
    (wz ), (wy ), -(wx ), 0];

% qk+1 = Aq + Bu  u = w  With bias added as states.


% 
% A = blkdiag(eye(4) + 1/2*Sw*T,eye(7));
% B = [T/2*Sq;    %quaternions
%     0, 0, 0];   %D pos aka depth



 %% H matrix 
 %acceleration in body frame
acc_ned = [acc_n; acc_e; acc_d];
% measurement equation for acceleration
acc_meas = transpose(Q)*([0; 0; g]); % fråga Manon + acc_ned
% measurement equation for magnetometer 
mag_global=[sqrt(mag_n^2 + mag_e^2);0;mag_d]; % could change to mx 0 mz and use bjord =mz bjord sin(θdip)dˆ+ bjord cos(θdip)nˆ
mag_meas = transpose(Q)*mag_global;

% measurement equation pressure sensor
 pressure_meas =  rho*g*(d+[0,0,1]*Q*[x_offset;0;0]);
 
 measurement_eqs = [acc_meas;mag_meas;pressure_meas];
 
 states = [transpose(q),d];
 %derivatives for acc meas eq
 nr_meas_eqs = length(measurement_eqs);
 nr_states = length(states);

for i=1:nr_meas_eqs
    for j=1:nr_states
        H(i,j) = diff(measurement_eqs(i),states(j));
    end
end

 %% F matrix
 motion_model=[(eye(4) + 1/2*Sw*T)*q;d];
 for n=1:nr_states 
    for m=1:nr_states
       F(n,m) = diff(motion_model(n,1),states(m));
    end
 end
    
%% Gv matrix aka noise effect on states
% Use result from lab 2 sensor fusion for noise relations between
% quaternions. I asume that noise enters directly on measurements for the
% other states.
% this should but is not computed via derivatives.

Gv =  blkdiag(T/2*Sq, eye(1));
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 