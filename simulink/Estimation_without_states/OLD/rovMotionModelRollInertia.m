function [x_dot, y] = rovMotionModelRollInertia( t, x, control, ...
    m, g, rho, V, lx1, ly1, ly2, lx2, ly3, lx5, ly4, lz6, zb, Xu, ...
    Xu_dot, Xu_abs_u, Yv, Yv_dot, Yv_abs_v, Zw, Zw_dot,...
    Zw_abs_w, Kp, Kp_dot, Kp_abs_p, Mq, Mq_dot, Mq_abs_q,...
    Nr, Nr_dot, Nr_abs_r, Ix, Iy, Iz, Ix_Kp_dot, Iy_Mq_dot,...
    Kp_Ix_Kp_dot, Kp_abs_p_Ix_Kp_dot, Mq_dot_Ix_Kp_dot,...
    Nr_dot_Ix_Kp_dot, Mq_Iy_Mq_dot, Mq_abs_q_Iy_Mq_dot,...
    Kp_dot_Iy_Mq_dot, Nr_dot_Iy_Mq_dot, varargin)
%******* Constants
% m = parameters(1);
% g = parameters(2);
% rho = parameters(3);
% V = parameters(4);
% %Thruster placement from CO [m]
% lx1= parameters(5);
% ly1= parameters(6);
% ly2= parameters(7);
% lx2= parameters(8);
% ly3= parameters(9);
% lx5= parameters(10);
% ly4= parameters(11);
% lz6= parameters(12);
% zb= parameters(13);

%******* States
u = x(1);
v = x(2);
w = x(3);

p = x(4);
q = x(5);
r = x(6);

fi = x(7);
theta = x(8);
%*******    Computed values

ct = cos(theta);
st = sin(theta);
cf = cos(fi);
sf = sin(fi);

% B = rho*g*V;
W = m*g;
B = W;
%******* Parameters
% Xu= parameters(14);
% Xu_dot= parameters(15);
% Xu_abs_u= parameters(16);
% Yv= parameters(17);
% Yv_dot= parameters(18);
% Yv_abs_v= parameters(19);
% Zw= parameters(20);
% Zw_dot= parameters(21);
% Zw_abs_w= parameters(22);
% Kp= parameters(23);
% Kp_dot= parameters(24);
% Kp_abs_p= parameters(25);
% Mq= parameters(26);
% Mq_dot= parameters(27);
% Mq_abs_q= parameters(28);
% Nr= parameters(29);
% Nr_dot= parameters(30);
% Nr_abs_r= parameters(31);
% Ix= parameters(32);
% Iy= parameters(33);
% Iz= parameters(34);
% Ix_Kp_dot = parameters(35);
% Iy_Mq_dot = parameters(36);
% Kp_Ix_Kp_dot = parameters(37);
% Kp_abs_p_Ix_Kp_dot = parameters(38);
% Mq_dot_Ix_Kp_dot = parameters(39);
% Nr_dot_Ix_Kp_dot = parameters(40);
% Mq_Iy_Mq_dot = parameters(41);
% Mq_abs_q_Iy_Mq_dot = parameters(42);
% Kp_dot_Iy_Mq_dot = parameters(43);
% Nr_dot_Iy_Mq_dot = parameters(44);

u_dot = 0;

v_dot = 0;

w_dot = 0;

p_dot =...
     (p*(Kp + Kp_abs_p*abs(p)) + B*ct*sf*zb )/(Ix - Kp_dot); %- Yv_dot*v*w + Zw_dot*v*w

q_dot = 0;



fi_dot = p + q*sf*st/ct + r*cf*st/ct;
theta_dot = q*cf - r*sf;

x_dot = [u_dot;v_dot;w_dot;p_dot;q_dot;r_dot;fi_dot;theta_dot];

y = x;
end