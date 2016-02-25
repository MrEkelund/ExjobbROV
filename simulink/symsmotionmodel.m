syms q p r u w v Zw_dot Yv_dot Xu_dot Mq_dot Nr_dot Kp_dot Yv Xu Zw Mq Nr Kp ...
    m Iy Iz Ix W B Nr_abs_r Xu_abs_u Yv_abs_v Zw_abs_w Kp_abs_p Mq_abs_q ct ...
    st sf cf cp sp lx1 lx2 ly1 ly2 ly3 lx5 ly4 lz6 zb g f1 f2 f3 f4 f5 f6;

M = diag([m, m, m, Ix, Iy, Iz])...
    + diag([Xu_dot,Yv_dot,Zw_dot,Kp_dot,Mq_dot,Nr_dot]);

nu = [u;v;w;p;q;r];

C_AA = [0 , 0 , 0 , 0 , -Zw_dot*w , Yv_dot*v ;
    0 , 0 , 0 , Zw_dot*w , 0 , -Xu_dot*u ;
    0 , 0 , 0 , -Yv_dot*v , Xu_dot*u , 0 ;
    0 , -Zw_dot*w , Yv_dot*v , 0 , -Nr_dot*r , Mq_dot*q ;
    Zw_dot*w , 0 , -Xu_dot*u , Nr_dot*r , 0 , -Kp_dot*p ;
    -Yv_dot*v , Xu_dot*u , 0 , - Mq_dot*q , Kp_dot*p , 0];

C_A = [...
        Yv_dot*v*r - Zw_dot*w*q;
        Zw_dot*w*p - Xu_dot*u*r;
        Xu_dot*u*q - Yv_dot*v*p;
        (Yv_dot - Zw_dot)*v*w + (Mq_dot - Nr_dot)*q*r;
        (Zw_dot - Xu_dot)*u*w + (Nr_dot - Kp_dot)*p*r;
        (Xu_dot - Yv_dot)*u*v + (Kp_dot - Mq_dot)*p*q];

% def (3.57) page 55 fossen
C_RB = [...
    m*(q*w-r*v);
    m*(r*u-p*w);
    m*(p*v-q*u);
    q*r*(Iy-Iz);
    r*p*(Iz-Ix);
    q*p*(Ix-Iy)];

C = C_A + C_RB;    

%Hydrodynamic dampening
D = -[...
    (Xu + Xu_abs_u*abs(u))*u;
    (Yv + Yv_abs_v*abs(v))*v;
    (Zw + Zw_abs_w*abs(w))*w;
    (Kp + Kp_abs_p*abs(p))*p;
    (Mq + Mq_abs_q*abs(q))*q;
    (Nr + Nr_abs_r*abs(r))*r];

gn = [...
    (W - B)*st;
    -(W - B)*ct*sf;
    -(W - B)*ct*sf;
    -zb*B*ct*sf;
    -zb*B*st;
    0];

% Thrust allocation
% T = [...
%     0, 0, 1,  0, 1, 0;
%     0, 0, 0,  0, 0, -1;
%     -1, -1, 0,  -1, 0, 0;
%     -ly1, ly2, 0,  0,  0, lz6;
%     -lx1, lx2, 0,  -lx4, 0, 0;
%     0,   0,  ly3, 0, -ly5, 0];


T = [...
    0, 0, 1, 1, 0, 0;
    0, 0, 0,  0, 0, -1;
    -1, -1, 0, 0, -1, 0;
    ly1, -ly2, 0, 0, 0, lz6;
    lx1, lx2, 0, 0, -lx5 0;
    0, 0, ly3, -ly4, 0, 0];


% old p = [-1.3536   -0.4257    2.5444    0.8196    0.9102    0.0111];
% is this right? Should it take kgf as input?
% why not controllsignal
thrusterforce = [...
        g*f1;
        g*f2;
        g*f3;
        g*f4;
        g*f5;
        g*f6];

tau = T*thrusterforce;

nu_dot = inv(M)*(tau-C-D-gn)