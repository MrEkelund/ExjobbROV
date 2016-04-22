function [x_dot, y] = rovMotionModelAllCong( t, x, control, ...
    m, g, rho, V, lx1, ly1, ly2, lx2, ly3, lx5, ly4, lz6, zb,...
    Kp, Kp_dot, Kp_abs_p, Mq, Mq_dot, Mq_abs_q,Nr, Nr_dot,...
    Nr_abs_r, Ix, Iy, Iz, Ix_Kp_dot, Iy_Mq_dot, Iz_Nr_dot, gam, mag_n, mag_e, mag_d,...
    varargin)
%******* States
p = x(1);
q = x(2);
r = x(3);

n = x(4);
e1 = x(5);
e2 = x(6);
e3 = x(7);
%*******    Computed values
W = m*g;
B = W;
%Thrusterforce in newtons. Lookup table returns in kgf
f1 = control(1);
f2 = control(2);
f3 = control(3);
f4 = control(4);
f5 = control(5);
f6 = control(6);

nu_dot = [... 
    ((Kp + Kp_abs_p*abs(p))/Ix_Kp_dot)*p + ((Iy - Iz - Mq_dot + Nr_dot)/Ix_Kp_dot)*q*r + ((2*B*zb)/Ix_Kp_dot)*n*e1 + ((2*B*zb)/Ix_Kp_dot)*e2*e3 + (f1*ly1 - f2*ly2 + f6*lz6)/Ix_Kp_dot
    (-(Ix - Iz - Kp_dot + Nr_dot)/Iy_Mq_dot)*p*r + ((Mq + Mq_abs_q*abs(q))/Iy_Mq_dot)*q + ((2*B*zb)/Iy_Mq_dot)*n*e2 + (-(2*B*zb)/Iy_Mq_dot)*e1*e3 + (f1*lx1 + f2*lx2 - f5*lx5)/Iy_Mq_dot
    ((Ix - Iy - Kp_dot + Mq_dot)/Iz_Nr_dot)*p*q + ((Nr + Nr_abs_r*abs(r))/Iz_Nr_dot)*r + (f3*ly3 - f4*ly4)/Iz_Nr_dot];

eta_dot = [...
    -(gam*e1^2*n)/2 - (p*e1)/2 - (gam*e2^2*n)/2 - (q*e2)/2 - (gam*e3^2*n)/2 - (r*e3)/2 - (gam*n^3)/2 + (gam*n)/2
    -(gam*e1^3)/2 - (gam*e1*e2^2)/2 - (gam*e1*e3^2)/2 - (gam*e1*n^2)/2 + (gam*e1)/2 + (r*e2)/2 - (q*e3)/2 + (p*n)/2
    -(gam*e1^2*e2)/2 - (r*e1)/2 - (gam*e2^3)/2 - (gam*e2*e3^2)/2 - (gam*e2*n^2)/2 + (gam*e2)/2 + (p*e3)/2 + (q*n)/2
    -(gam*e1^2*e3)/2 + (q*e1)/2 - (gam*e2^2*e3)/2 - (p*e2)/2 - (gam*e3^3)/2 - (gam*e3*n^2)/2 + (gam*e3)/2 + (r*n)/2];


x_dot = [nu_dot; eta_dot];


h = [...
    p
    q
    r
    (2*g)*n*e2 + (-2*g)*e1*e3
    (-2*g)*n*e1 + (-2*g)*e2*e3
    2*g*e1^2 + 2*g*e2^2 - g
    (-2*mag_d)*n*e2 + (2*mag_d)*e1*e3 + (-2*(mag_e^2 + mag_n^2)^(1/2))*e2^2 + (-2*(mag_e^2 + mag_n^2)^(1/2))*e3^2 + (mag_e^2 + mag_n^2)^(1/2)
    (2*mag_d)*n*e1 + (-2*(mag_e^2 + mag_n^2)^(1/2))*n*e3 + (2*(mag_e^2 + mag_n^2)^(1/2))*e1*e2 + (2*mag_d)*e2*e3
    (2*(mag_e^2 + mag_n^2)^(1/2))*n*e2 + (-2*mag_d)*e1^2 + (2*(mag_e^2 + mag_n^2)^(1/2))*e1*e3 + (-2*mag_d)*e2^2 + mag_d];

y = h;
end
