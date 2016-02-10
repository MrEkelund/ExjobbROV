function [ output_args ] = Untitled( input_args )


M = diag(m, m, m, Ix, Iy, Iz)...
    + diag(Xu_dot,Yv_dot,Zw_dot,Kp_dot,Mq_dot,Nr_dot);



C_added=...
    [0 0 0 0 -Zw_dot*w Yv_dot*v;
    0 0 0 Zw_dot*w 0 -Xu_dot*u;
    0 0 0 -Yv_dot*v Xu_dot*u 0;
    0 -Zw_dot*w Yv_dot*v 0 -Nr_dot*r Mq_dot*q;
    Zw_dot*w 0 -Xu_dot*u Nr_dot*r 0 -Kp_dot*p;
    -Yv_dot*v Xu_dot*u 0 -Mq_dot*q Kp_dot*p 0];

omega = [p, q, r]';
vel = [u, v, w]';
C_rigid = m*cross(omega,vel); % Ej klar
C = C_added + C_rigid;





end

