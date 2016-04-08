function [x_dot, y] = rovMotionModelYaw( t, x, control,  ...
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
r = x(1);

fi = x(2);
theta = x(3);
%******* Computed values

ct = cos(theta);
st = sin(theta);
cf = cos(fi);
sf = sin(fi);
 
% B = rho*g*V;
W = m*g;
B = W;
% look-up table for t200.
lookup =[...
    -4.0823   -1.0000
    -4.0823   -0.9750
    -4.0869   -0.9500
    -3.8283   -0.9250
    -3.7331   -0.9000
    -3.6197   -0.8750
    -3.4428   -0.8500
    -3.3022   -0.8250
    -3.1842   -0.8000
    -3.0572   -0.7750
    -2.9075   -0.7500
    -2.8168   -0.7250
    -2.7079   -0.7000
    -2.5265   -0.6750
    -2.3632   -0.6500
    -2.2589   -0.6250
    -2.1772   -0.6000
    -1.9913   -0.5750
    -1.8824   -0.5500
    -1.7690   -0.5250
    -1.6420   -0.5000
    -1.4923   -0.4750
    -1.3336   -0.4500
    -1.2428   -0.4250
    -1.1204   -0.4000
    -1.0251   -0.3750
    -0.9072   -0.3500
    -0.7893   -0.3250
    -0.6940   -0.3000
    -0.6169   -0.2750
    -0.5216   -0.2500
    -0.4354   -0.2250
    -0.3538   -0.2000
    -0.2767   -0.1750
    -0.1905   -0.1500
    -0.1134   -0.1250
    -0.0544   -0.1000
    -0.0272   -0.0750
    0   -0.0500
    0   -0.0250
    0         0
    0    0.0250
    0    0.0500
    0.0590    0.0750
    0.1134    0.1000
    0.1860    0.1250
    0.2631    0.1500
    0.3493    0.1750
    0.4173    0.2000
    0.5216    0.2250
    0.6350    0.2500
    0.7167    0.2750
    0.8437    0.3000
    0.9435    0.3250
    1.1022    0.3500
    1.2474    0.3750
    1.3925    0.4000
    1.5286    0.4250
    1.6783    0.4500
    1.8053    0.4750
    1.9595    0.5000
    2.0956    0.5250
    2.2181    0.5500
    2.4131    0.5750
    2.5220    0.6000
    2.6943    0.6250
    2.8259    0.6500
    3.0209    0.6750
    3.1933    0.7000
    3.3521    0.7250
    3.4473    0.7500
    3.4927    0.7750
    3.7784    0.8000
    3.9417    0.8250
    4.0052    0.8500
    4.1957    0.8750
    4.3772    0.9000
    4.5677    0.9250
    4.8035    0.9500
    4.8988    0.9750
    5.0938    1.0000];


forces = g*nakeinterp1(lookup(:,2),lookup(:,1),control');
%Thrusterforce in newtons. Lookup table returns in kgf
f3 = forces(1);
f4 = forces(2);
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
 
r_dot =...
    (r*(Nr + Nr_abs_r*abs(r)) + f3*ly3 - f4*ly4)/(Iz - Nr_dot); 

fi_dot = r*cf*st/ct;
theta_dot = r*sf;

x_dot = [r_dot;fi_dot;theta_dot];
y = x;
end

