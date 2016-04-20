syms n e1 e2 e3 p q r Ix Iy Iz Kp_dot Mq_dot Nr_dot Kp  Kp_abs_p Mq  Mq_abs_q...
Nr Nr_abs_r 

M = -diag([Kp_dot,Mq_dot,Nr_dot]);

nu = [p;q;r];

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


Q = [n;e1;e2;e3];
% rotation matrix from body to NED. NED_angle = RQ*Body_angle
RQ =...
    [1 - 2*(e2^2 + e3^2), 2*(e1*e2 - e3*n), 2*(e1*e3 + e2*n);
     2*(e1*e2 + e3*n),  1-2*(e1^2 + e3^2),2*(e2*e3-e1*n);
     2*(e1*e3 - e2*n),  2*(e2*e3 + e1*n), 1-2*(e1^2 + e2^2);]
 
 % Transform of angular velocities, from body to NED. 
 % NED_angle_Rate = TQ*Body_angle_rate
 TQ =1/2*...
     [-e1 ,-e2 -e3;
     n -e3 e2;
     e3 n -e1;
     -e2 e1 n];
 Q_dot = TQ*[p;q;r] +g gamma/2 *(1-transpose(Q)*Q)*Q
 
 SM2 =...
     [0, -Iz*r,Iy*q;
      Iz*r, 0 , -Ix*p;
     ]
 
 
 
 