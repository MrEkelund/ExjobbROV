function [dx, y] = rov_motion_model(t, x, control, Ix, Iy, Iz, Zw_dot,...
        Yv_dot, Xu_dot, Mq_dot, Nr_dot,Kp_dot, varargin)
%******* Constants
m = ?;      % ROV mass[kg];   
g = 9.80;   % Gravity[m/s^2]
rho =? ;    % water density [kg/m^3]
V = ?;      % Discplaced water volume [m^3]
%******* Inputs


%******* States
u = x();
v = x();
w = x();
p = x();
q = x();
r = x();


%******* Computed values
ct = cos(theta);
st = sin(theta);
cf = cos(fi);
sf = sin(fi);
cp = cos(psi);
sp = sin(psi);

B = rho*g*V;
W = m*g;

%******* Model
M = diag([m, m, m, Ix, Iy, Iz])...
    + diag([Xu_dot,Yv_dot,Zw_dot,Kp_dot,Mq_dot,Nr_dot]);

omega = [p, q, r]';
vel = [u, v, w]';

C_A = [...
        -Zw_dot*w*q+Yv_dot*v*r;
        Zw_dot*w*p-Xu_dot*u*r;
        -Yv_dot*v*p+Xu_dot*u*q;
        (-Zw_dot+Yv_dot)*v*w+(Mq_dot-Nr_dot)*q*r;
        (Zw_dot-Xu_dot)*u*w+(Nr_dot-Kp_dot)*p*r;
        (-Yv_dot+Xu_dot)*u*v+(Kp_dot-Mq_dot)*p*q];

% def (3.57) page 55 fossen
C_RB = [...
    m*(q*w-r*v);
    m*(r*u-p*w);
    m*(p*v-q*u);
    q*r*(Iy-Iz);
    r*p*(Iz-Ix);
    q*p*(Ix-Iy)];

C = C_A + C_RB;    

D = -diag([...
    (Xu + Xu_abs_u*abs(u))*u,(Yv + Yv_abs_v*abs(v))*v,...
    (Zw + Zw_abs_w*abs(w))*w,(Kp + Kp_abs_p*abs(p))*p,...
    (Mq + Mq_abs_q*abs(q))*q,(Nr + Nr_abs_r*abs(r))*r]);

g = [...
    (W - B)*st;
    -(W - B)*ct*sf;
    -(W - B)*ct*sf;
    -zb*B*ct*sf;
    -zb*B*st;
    0];

end











