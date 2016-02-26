function [x_dot, y] = rovMotionModel( t, x, control, parameters, varargin)
%******* Constants
m= parameters(1)
g= parameters(2)
rho= parameters(3)
V= parameters(4)
%Thruster placement from CO [m]
lx1= parameters(5)
ly1= parameters(6)
ly2= parameters(7)
lx2= parameters(8)
ly3= parameters(9)
lx5= parameters(10)
ly4= parameters(11)
lz6= parameters(12)
zb= parameters(13)

%******* Inputs
u1 = control(1);
u2 = control(2);
u3 = control(3);
u4 = control(4);
u5 = control(5);
u6 = control(6);

%******* States
u = x(1);
v = x(2);
w = x(3);

p = x(4);
q = x(5);
r = x(6);

fi = x(7);
theta = x(8);
%******* Computed values

ct = cosd(theta);
st = sind(theta);
cf = cosd(fi);
sf = sind(fi);

B = rho*g*V;
W = m*g;
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


%Thrusterforce in newtons. Lookup table returns in kgf
f1 = g*interp1(lookup(:,2),lookup(:,1),u1);
f2 = g*interp1(lookup(:,2),lookup(:,1),u2);
f3 = g*interp1(lookup(:,2),lookup(:,1),u3);
f4 = g*interp1(lookup(:,2),lookup(:,1),u4);
f5 = g*interp1(lookup(:,2),lookup(:,1),u5);
f6 = g*interp1(lookup(:,2),lookup(:,1),u6);
%******* Parameters
Xu= parameters(14)
Xu_dot= parameters(15)
Xu_abs_u= parameters(16)
Yv= parameters(17)
Yv_dot= parameters(18)
Yv_abs_v= parameters(19)
Zw= parameters(20)
Zw_dot= parameters(21)
Zw_abs_w= parameters(22)
Kp= parameters(23)
Kp_dot= parameters(24)
Kp_abs_p= parameters(25)
Mq= parameters(26)
Mq_dot= parameters(27)
Mq_abs_q= parameters(28)
Nr= parameters(29)
Nr_dot= parameters(30)
Nr_abs_r= parameters(31)
Ix= parameters(32)
Iy= parameters(33)
Iz= parameters(34)





u_dot  =(f3 + f4 + u*(Xu + Xu_abs_u*abs(u)) + st*(B - W) - m*(q*w - r*v) - Yv_dot*r*v + Zw_dot*q*w)/(Xu_dot + m);
v_dot  =-(f6 - v*(Yv + Yv_abs_v*abs(v)) - m*(p*w - r*u) + ct*sf*(B - W) - Xu_dot*r*u + Zw_dot*p*w)/(Yv_dot + m);
w_dot  =-(f1 + f2 + f5 - w*(Zw + Zw_abs_w*abs(w)) + m*(p*v - q*u) + ct*sf*(B - W) + Xu_dot*q*u - Yv_dot*p*v)/(Zw_dot + m);
p_dot  =(f1*ly1 - f2*ly2 + f6*lz6 + p*(Kp + Kp_abs_p*abs(p)) - q*r*(Iy - Iz) - q*r*(Mq_dot - Nr_dot) - v*w*(Yv_dot - Zw_dot) + B*ct*sf*zb)/(Ix + Kp_dot);
q_dot  =(f1*lx1 + f2*lx2 - f5*lx5 + q*(Mq + Mq_abs_q*abs(q)) + B*st*zb + p*r*(Ix - Iz) + p*r*(Kp_dot - Nr_dot) + u*w*(Xu_dot - Zw_dot))/(Iy + Mq_dot);
r_dot  =-(f4*ly4 - f3*ly3 - r*(Nr + Nr_abs_r*abs(r)) + p*q*(Ix - Iy) + p*q*(Kp_dot - Mq_dot) + u*v*(Xu_dot - Yv_dot))/(Iz + Nr_dot);


% old models
% u_dot = (u*(Xu + Xu_abs_u*abs(u)) - g + f3*g + f5*g - m*(q*w - r*v) - Yv_dot*r*v + Zw_dot*q*w)/(Xu_dot + m)
% v_dot = -(g - v*(Yv + Yv_abs_v*abs(v)) + f6*g - m*(p*w - r*u) - Xu_dot*r*u + Zw_dot*p*w)/(Yv_dot + m)
% w_dot = -(g - w*(Zw + Zw_abs_w*abs(w)) + f1*g + f2*g + f4*g + m*(p*v - q*u) + Xu_dot*q*u - Yv_dot*p*v)/(Zw_dot + m)
% p_dot = -(g - p*(Kp + Kp_abs_p*abs(p)) + q*r*(Iy - Iz) + f1*g*ly1 - f2*g*ly2 - f6*g*lz6 + q*r*(Mq_dot - Nr_dot) + v*w*(Yv_dot - Zw_dot))/(Ix + Kp_dot)
% q_dot = (q*(Mq + Mq_abs_q*abs(q)) - g + p*r*(Ix - Iz) - f1*g*lx1 + f2*g*lx2 - f4*g*lx5 + p*r*(Kp_dot - Nr_dot) + u*w*(Xu_dot - Zw_dot))/(Iy + Mq_dot)
% r_dot = -(g - r*(Nr + Nr_abs_r*abs(r)) + p*q*(Ix - Iy) + p*q*(Kp_dot - Mq_dot) - f3*g*ly3 + f5*g*ly4 + u*v*(Xu_dot - Yv_dot))/(Iz + Nr_dot)

% u_dot  = (u*(Xu + Xu_abs_u*abs(u)) - g + f3*g + f4*g - m*(q*w - r*v) - Yv_dot*r*v + Zw_dot*q*w)/(Xu_dot + m)
% v_dot  = -(g - v*(Yv + Yv_abs_v*abs(v)) + f6*g - m*(p*w - r*u) - Xu_dot*r*u + Zw_dot*p*w)/(Yv_dot + m)
% w_dot  = -(g - w*(Zw + Zw_abs_w*abs(w)) + f1*g + f2*g + f5*g + m*(p*v - q*u) + Xu_dot*q*u - Yv_dot*p*v)/(Zw_dot + m)
% p_dot  = -(g - p*(Kp + Kp_abs_p*abs(p)) + q*r*(Iy - Iz) - f1*g*ly1 + f2*g*ly2 - f6*g*lz6 + q*r*(Mq_dot - Nr_dot) + v*w*(Yv_dot - Zw_dot))/(Ix + Kp_dot)
% q_dot  = (q*(Mq + Mq_abs_q*abs(q)) - g + p*r*(Ix - Iz) + f1*g*lx1 + f2*g*lx2 - f5*g*lx5 + p*r*(Kp_dot - Nr_dot) + u*w*(Xu_dot - Zw_dot))/(Iy + Mq_dot)
% r_dot  = -(g - r*(Nr + Nr_abs_r*abs(r)) + p*q*(Ix - Iy) + p*q*(Kp_dot - Mq_dot) - f3*g*ly3 + f4*g*ly4 + u*v*(Xu_dot - Yv_dot))/(Iz + Nr_dot)


%should use predetermined cos(fi) sin fi etc.
fi_dot = p + q*sin(fi)*tan(theta) + r*cos(fi)*tan(theta);
theta_dot = q*cos(fi) - r*sin(fi);


x_dot = [u_dot;v_dot;w_dot;p_dot;q_dot;r_dot;fi_dot;theta_dot];
y = x;
end

