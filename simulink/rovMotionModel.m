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
lx4= parameters(10)
ly5= parameters(11)
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

%Thrusterforce
p = [-1.3536   -0.4257    2.5444    0.8196    0.9102    0.0111];
f1 = g*polyval(p,u1);
f2 = g*polyval(p,u2);
f3 = g*polyval(p,u3);
f4 = g*polyval(p,u4);
f5 = g*polyval(p,u5);
f6 = g*polyval(p,u6);
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


u_dot = (u*(Xu + Xu_abs_u*abs(u)) - g + f3*g + f5*g - m*(q*w - r*v) - Yv_dot*r*v + Zw_dot*q*w)/(Xu_dot + m)
v_dot = -(g - v*(Yv + Yv_abs_v*abs(v)) + f6*g - m*(p*w - r*u) - Xu_dot*r*u + Zw_dot*p*w)/(Yv_dot + m)
w_dot = -(g - w*(Zw + Zw_abs_w*abs(w)) + f1*g + f2*g + f4*g + m*(p*v - q*u) + Xu_dot*q*u - Yv_dot*p*v)/(Zw_dot + m)
p_dot = -(g - p*(Kp + Kp_abs_p*abs(p)) + q*r*(Iy - Iz) + f1*g*ly1 - f2*g*ly2 - f6*g*lz6 + q*r*(Mq_dot - Nr_dot) + v*w*(Yv_dot - Zw_dot))/(Ix + Kp_dot)
q_dot = (q*(Mq + Mq_abs_q*abs(q)) - g + p*r*(Ix - Iz) - f1*g*lx1 + f2*g*lx2 - f4*g*lx4 + p*r*(Kp_dot - Nr_dot) + u*w*(Xu_dot - Zw_dot))/(Iy + Mq_dot)
r_dot = -(g - r*(Nr + Nr_abs_r*abs(r)) + p*q*(Ix - Iy) + p*q*(Kp_dot - Mq_dot) - f3*g*ly3 + f5*g*ly5 + u*v*(Xu_dot - Yv_dot))/(Iz + Nr_dot)
 
 
 
fi_dot = p + q*sin(fi)*tan(theta) + r*cos(fi)*tan(theta);
theta_dot = q*cos(fi) - r*sin(fi);
 
 
x_dot = [u_dot;v_dot;w_dot;p_dot;q_dot;r_dot;fi_dot;theta_dot];
y = x;
end

