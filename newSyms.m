syms Ts n e1 e2 e3 p q r Ix Iy Iz Kp_dot Mq_dot Nr_dot Kp  Kp_abs_p Mq  Mq_abs_q...
Nr Nr_abs_r gam zb W B ly1 lx1 ly2 lx2 ly3 ly4 lx5 lz6 f1 f2 f3 f4 f5 f6 ...
Ix_Kp_dot Iy_Mq_dot Iz_Nr_dot g mag_n mag_e mag_d
M = diag([ Ix, Iy, Iz]) - diag([Kp_dot,Mq_dot,Nr_dot]);
nu = [p;q;r];
eta = [n;e1;e2;e3];

C_AA = [...
    0 , -Nr_dot*r , Mq_dot*q ;
    Nr_dot*r , 0 , -Kp_dot*p ;
    -Mq_dot*q , Kp_dot*p , 0];

C_A =  C_AA*nu;


C_RB = [...
   q*r*(-Iy+Iz);
   r*p*(-Iz+Ix);
   q*p*(-Ix+Iy)];


C = C_A + C_RB;    

D = -[...
    (Kp + Kp_abs_p*abs(p))*p;
    (Mq + Mq_abs_q*abs(q))*q;
    (Nr + Nr_abs_r*abs(r))*r];


% rotation matrix from body to NED. NED_angle = RQ*Body_angle
RQ =...
    [1 - 2*(e2^2 + e3^2), 2*(e1*e2 - e3*n), 2*(e1*e3 + e2*n);
     2*(e1*e2 + e3*n),  1-2*(e1^2 + e3^2),2*(e2*e3-e1*n);
     2*(e1*e3 - e2*n),  2*(e2*e3 + e1*n), 1-2*(e1^2 + e2^2)];
 
 % Transform of angular velocities, from body to NED. 
 % NED_angle_Rate = TQ*Body_angle_rate
 T_eta =1/2*...
     [-e1 ,-e2 -e3;
     n -e3 e2;
     e3 n -e1;
     -e2 e1 n];
 T_bar_nu=1/2*...
     [0 -p -q -r;
     p 0 r -q;
     q -r 0 p;
     r q -p 0];

 %eta_dot = T_eta*nu;
 
rb = [0; 0; zb];
rg = [0; 0; 0];
fg = transpose(RQ)*[0; 0; W];
fb = transpose(RQ)*[0; 0; B];

gn = [cross(rb,fb) - cross(rg,fg)];

T = [...
    ly1, -ly2, 0, 0, 0, lz6;
    lx1, lx2, 0, 0, -lx5, 0;
    0, 0, ly3, -ly4, 0, 0];

thrusterforce = [...
        f1;
        f2;
        f3;
        f4;
        f5;
        f6];

tau = T*thrusterforce;

nu_dot = inv(M)*(tau-C-D-gn);
nu_dot = subs(nu_dot,Ix - Kp_dot, Ix_Kp_dot);
nu_dot = subs(nu_dot,Iy - Mq_dot, Iy_Mq_dot);
nu_dot = subs(nu_dot,Iz - Nr_dot, Iz_Nr_dot);
nu_k_1 = nu + Ts*nu_dot;
nu_k_1 = collect(nu_k_1,[p q r])

%eta_k_1 = eta + Ts*Q_dot
eta_k_1 =(eye(4) + Ts*T_bar_nu)*eta + (Ts^2*T_eta)*nu;
eta_k_1 = collect(eta_k_1,[p q r n e1 e2 e3])





 state = [eta; nu; zb; Kp; Kp_dot; Kp_abs_p; Mq;...
     Mq_dot; Mq_abs_q; Nr; Nr_dot; Nr_abs_r;...
     Ix; Iy; Iz; Ix_Kp_dot; Iy_Mq_dot; Iz_Nr_dot];
 f = [eta_k_1;nu_k_1];
 for i=1:length(f)
    for j=1:length(state)
        F(i,j) = diff(f(i),state(j));
    end
 end

 Gv =...
     [Ts^3/2*T_eta;Ts*eye(3)];
 Gv=blkdiag(Gv,eye(16));
 
acc_meas = transpose(RQ)*([0; 0; -g]);
gyro_meas = [p ; q ; r ];
mag_global=[sqrt(mag_n^2 + mag_e^2);0;mag_d]; % could change to mx 0 mz and use bjord =mz bjord sin(θdip)dˆ+ bjord cos(θdip)nˆ
mag_meas = transpose(RQ)*mag_global;

h = [gyro_meas;acc_meas;mag_meas];
h = collect(h, [p q r n e1 e2 e3])
%%
for i=1:length(h)
    for j=1:length(state);
        H(i,j) = diff(h(i),state(j));
    end
end
 
 
 
 