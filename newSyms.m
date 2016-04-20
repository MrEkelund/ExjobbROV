syms Ts n e1 e2 e3 p q r Ix Iy Iz Kp_dot Mq_dot Nr_dot Kp  Kp_abs_p Mq  Mq_abs_q...
Nr Nr_abs_r gam zb W B ly1 lx1 ly2 lx2 ly3 ly4 lx5 lz6 f1 f2 f3 f4 f5 f6 Ix_Kp_dot Iy_Mq_dot Iz_Nr_dot
M = diag([ Ix, Iy, Iz]) - diag([Kp_dot,Mq_dot,Nr_dot]);
nu = [p;q;r];

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

Q = [n;e1;e2;e3];
% rotation matrix from body to NED. NED_angle = RQ*Body_angle
RQ =...
    [1 - 2*(e2^2 + e3^2), 2*(e1*e2 - e3*n), 2*(e1*e3 + e2*n);
     2*(e1*e2 + e3*n),  1-2*(e1^2 + e3^2),2*(e2*e3-e1*n);
     2*(e1*e3 - e2*n),  2*(e2*e3 + e1*n), 1-2*(e1^2 + e2^2)];
 
 % Transform of angular velocities, from body to NED. 
 % NED_angle_Rate = TQ*Body_angle_rate
 TQ =1/2*...
     [-e1 ,-e2 -e3;
     n -e3 e2;
     e3 n -e1;
     -e2 e1 n];

 Q_dot = TQ*nu;
 
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
nu_dot = collect(nu_dot,[p q r]);
nu_dot = subs(nu_dot,Ix - Kp_dot, Ix_Kp_dot);
nu_dot = subs(nu_dot,Iy - Mq_dot, Iy_Mq_dot);
nu_dot = subs(nu_dot,Iz - Nr_dot, Iz_Nr_dot);
nu_k_1 = nu + Ts*nu_dot

Q_k_1 = Q + Ts*Q_dot






 state = [Q; nu; zb; Kp; Kp_dot; Kp_abs_p; Mq;...
     Mq_dot; Mq_abs_q; Nr; Nr_dot; Nr_abs_r;...
     Ix; Iy; Iz; Ix_Kp_dot; Iy_Mq_dot; Iz_Nr_dot];
 f = [Q_k_1;nu_k_1];
 for i=1:length(f)
    for j=1:length(state)
        F(i,j) = diff(f(i),state(j));
    end
end
 
 