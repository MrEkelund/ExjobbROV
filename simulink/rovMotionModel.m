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
% look-up table
lookup =[...
   -1.7682   -1.0000
   -1.6409   -0.9750
   -1.5773   -0.9500
   -1.5273   -0.9250
   -1.4409   -0.9000
   -1.4000   -0.8750
   -1.3227   -0.8500
   -1.2591   -0.8250
   -1.2091   -0.8000
   -1.1636   -0.7750
   -1.1045   -0.7500
   -1.0409   -0.7250
   -0.9909   -0.7000
   -0.9273   -0.6750
   -0.8545   -0.6500
   -0.7909   -0.6250
   -0.7545   -0.6000
   -0.7045   -0.5750
   -0.6682   -0.5500
   -0.6227   -0.5250
   -0.5818   -0.5000
   -0.5318   -0.4750
   -0.4727   -0.4500
   -0.4273   -0.4250
   -0.4000   -0.4000
   -0.3682   -0.3750
   -0.3273   -0.3500
   -0.2727   -0.3250
   -0.2318   -0.3000
   -0.2000   -0.2750
   -0.1682   -0.2500
   -0.1409   -0.2250
   -0.1045   -0.2000
   -0.0727   -0.1750
   -0.0500   -0.1500
   -0.0318   -0.1250
   -0.0136   -0.1000
   -0.0091   -0.0750
         0   -0.0500
         0         0
         0    0.0250
         0    0.0500
    0.0091    0.0750
    0.0364    0.1000
    0.0636    0.1250
    0.1045    0.1500
    0.1455    0.1750
    0.1955    0.2000
    0.2545    0.2250
    0.3091    0.2500
    0.3682    0.2750
    0.4318    0.3000
    0.4818    0.3250
    0.5455    0.3500
    0.6136    0.3750
    0.6864    0.4000
    0.7364    0.4250
    0.8045    0.4500
    0.8818    0.4750
    0.9636    0.5000
    1.0591    0.5250
    1.1318    0.5500
    1.1864    0.5750
    1.2545    0.6000
    1.3045    0.6250
    1.3864    0.6500
    1.4909    0.6750
    1.5773    0.7000
    1.6545    0.7250
    1.7273    0.7500
    1.8227    0.7750
    1.9591    0.8000
    2.0455    0.8250
    2.1000    0.8500
    2.1818    0.8750
    2.2636    0.9000
    2.3227    0.9250
    2.4182    0.9500
    2.4864    0.9750
    2.5182    1.0000];


% old polynomial for polyeval p = [-1.3536   -0.4257    2.5444    0.8196    0.9102    0.0111];
%Thrusterforce
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
Yv_abs_w= parameters(19)
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





u_dot  = (u*(Xu + Xu_abs_u*abs(u)) - g + f3*g + f4*g - m*(q*w - r*v) - Yv_dot*r*v + Zw_dot*q*w)/(Xu_dot + m)
v_dot  = -(g - v*(Yv + Yv_abs_v*abs(v)) + f6*g - m*(p*w - r*u) - Xu_dot*r*u + Zw_dot*p*w)/(Yv_dot + m)
w_dot  = -(g - w*(Zw + Zw_abs_w*abs(w)) + f1*g + f2*g + f5*g + m*(p*v - q*u) + Xu_dot*q*u - Yv_dot*p*v)/(Zw_dot + m)
p_dot  = -(g - p*(Kp + Kp_abs_p*abs(p)) + q*r*(Iy - Iz) - f1*g*ly1 + f2*g*ly2 - f6*g*lz6 + q*r*(Mq_dot - Nr_dot) + v*w*(Yv_dot - Zw_dot))/(Ix + Kp_dot)
q_dot  = (q*(Mq + Mq_abs_q*abs(q)) - g + p*r*(Ix - Iz) + f1*g*lx1 + f2*g*lx2 - f5*g*lx5 + p*r*(Kp_dot - Nr_dot) + u*w*(Xu_dot - Zw_dot))/(Iy + Mq_dot)
r_dot  = -(g - r*(Nr + Nr_abs_r*abs(r)) + p*q*(Ix - Iy) + p*q*(Kp_dot - Mq_dot) - f3*g*ly3 + f4*g*ly4 + u*v*(Xu_dot - Yv_dot))/(Iz + Nr_dot)
 

% u_dot = (u*(Xu + Xu_abs_u*abs(u)) - g + f3*g + f5*g - m*(q*w - r*v) - Yv_dot*r*v + Zw_dot*q*w)/(Xu_dot + m)
% v_dot = -(g - v*(Yv + Yv_abs_v*abs(v)) + f6*g - m*(p*w - r*u) - Xu_dot*r*u + Zw_dot*p*w)/(Yv_dot + m)
% w_dot = -(g - w*(Zw + Zw_abs_w*abs(w)) + f1*g + f2*g + f4*g + m*(p*v - q*u) + Xu_dot*q*u - Yv_dot*p*v)/(Zw_dot + m)
% p_dot = -(g - p*(Kp + Kp_abs_p*abs(p)) + q*r*(Iy - Iz) + f1*g*ly1 - f2*g*ly2 - f6*g*lz6 + q*r*(Mq_dot - Nr_dot) + v*w*(Yv_dot - Zw_dot))/(Ix + Kp_dot)
% q_dot = (q*(Mq + Mq_abs_q*abs(q)) - g + p*r*(Ix - Iz) - f1*g*lx1 + f2*g*lx2 - f4*g*lx5 + p*r*(Kp_dot - Nr_dot) + u*w*(Xu_dot - Zw_dot))/(Iy + Mq_dot)
% r_dot = -(g - r*(Nr + Nr_abs_r*abs(r)) + p*q*(Ix - Iy) + p*q*(Kp_dot - Mq_dot) - f3*g*ly3 + f5*g*ly4 + u*v*(Xu_dot - Yv_dot))/(Iz + Nr_dot)
 
 
 
fi_dot = p + q*sin(fi)*tan(theta) + r*cos(fi)*tan(theta);
theta_dot = q*cos(fi) - r*sin(fi);
 
 
x_dot = [u_dot;v_dot;w_dot;p_dot;q_dot;r_dot;fi_dot;theta_dot];
y = x;
end

