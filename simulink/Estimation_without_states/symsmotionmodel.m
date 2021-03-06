syms q p r u w v Zw_dot Yv_dot Xu_dot Mq_dot Nr_dot Kp_dot Yv Xu Zw Mq Nr Kp ...
    m Iy Iz Ix W B Nr_abs_r Xu_abs_u Yv_abs_v Zw_abs_w Kp_abs_p Mq_abs_q ct ...
    st sf cf cp sp lx1 lx2 ly1 ly2 ly3 lx5 lx4 ly5 ly4 lz6 zb g f1 f2 f3 f4 f5 f6;
% Mass, intertia and added mass
M = diag([m, m, m, Ix, Iy, Iz])...
   - diag([Xu_dot,Yv_dot,Zw_dot,Kp_dot,Mq_dot,Nr_dot]);

nu = [u;v;w;p;q;r];

C_AA = [0 , 0 , 0 , 0 , -Zw_dot*w , Yv_dot*v ;
    0 , 0 , 0 , Zw_dot*w , 0 , -Xu_dot*u ;
    0 , 0 , 0 , -Yv_dot*v , Xu_dot*u , 0 ;
    0 , -Zw_dot*w , Yv_dot*v , 0 , -Nr_dot*r , Mq_dot*q ;
    Zw_dot*w , 0 , -Xu_dot*u , Nr_dot*r , 0 , -Kp_dot*p ;
    -Yv_dot*v , Xu_dot*u , 0 , - Mq_dot*q , Kp_dot*p , 0];

C_A =  C_AA*nu;


% def (3.57) page 55 fossen
C_RB = [...
    m*(q*w-r*v);
    m*(r*u-p*w);
    m*(p*v-q*u);
   q*r*(-Iy+Iz);
   r*p*(-Iz+Ix);
   q*p*(-Ix+Iy)];

C = C_A + C_RB;    

% Hydrodynamic dampening
D = -[...
    (Xu + Xu_abs_u*abs(u))*u;
    (Yv + Yv_abs_v*abs(v))*v;
    (Zw + Zw_abs_w*abs(w))*w;
    (Kp + Kp_abs_p*abs(p))*p;
    (Mq + Mq_abs_q*abs(q))*q;
    (Nr + Nr_abs_r*abs(r))*r];

% Restoring forces page 60 Fossen
% zb positive distance from center of origin
gn = [...
    (W - B)*st;
    -(W - B)*ct*sf;
    -(W - B)*ct*cf;
    -zb*B*ct*sf;
    -zb*B*st;
    0];

%Thrust allocation
% T = [...
%     0, 0, 1,  0, 1, 0;
%     0, 0, 0,  0, 0, -1;
%     -1, -1, 0,  -1, 0, 0;
%     -ly1, ly2, 0,  0,  0, lz6;
%     -lx1, lx2, 0,  -lx4, 0, 0;
%     0,   0,  ly3, 0, -ly5, 0];


T = [...
    0, 0, 1, 1, 0, 0;
    0, 0, 0, 0, 0, -1;
    -1, -1, 0, 0, -1, 0;
    ly1, -ly2, 0, 0, 0, lz6;
    lx1, lx2, 0, 0, -lx5, 0;
    0, 0, ly3, -ly4, 0, 0];


% T = [...
%     0, 0, 1, 1, 0, 0;
%     0, 0, 0,  0, 0, -1;
%     -1, -1, 0, 0, -1, 0;
%     ly1, -ly2, 0, 0, 0, lz6;
%     lx1, lx2, 0, 0, -lx5 0;
%     0, 0, ly3, -ly4, 0, 0];

thrusterforce = [...
        f1;
        f2;
        f3;
        f4;
        f5;
        f6];

tau = T*thrusterforce;

nu_dot = inv(M)*(tau-C-D-gn);

u_dot = nu_dot(1)
v_dot = nu_dot(2)
w_dot = nu_dot(3)
p_dot = nu_dot(4)
q_dot = nu_dot(5)
r_dot = nu_dot(6)

%% atempt at linearizing input. Missing effect of look-up table.
syms a_b a_n a_n1 a_n2 a_n3 sphi cphi sth cth tth cphi phi_dot theta_dot J_dot J
a_n=[a_n1;a_n2;a_n3];
J  =...
    [1 sphi*tth cphi*tth;
    0 cphi -sphi;
    0 sphi/cth cphi/cth];
J_dot = ...
    [0, cphi*tth*phi_dot + sphi*(1+tth*tth)*theta_dot, -sphi*tth*phi_dot+cphi*(1+tth*tth)*theta_dot;
    0, -sphi*phi_dot, -cphi*phi_dot;
    0, (cphi*cth*phi_dot+sphi*sth*theta_dot)/(cth*cth), (-sphi*cth*phi_dot+cphi*sth*theta_dot)/(cth*cth)];  

a_b = inv(J)*(a_n - J_dot*[p;q;r]);
%control law
a_b=[0;0;0;a_b]
tau = M*a_b+C+D+gn;

