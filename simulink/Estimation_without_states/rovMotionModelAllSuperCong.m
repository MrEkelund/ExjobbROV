function [x_dot, y] = rovMotionModelAllSuperCong( t, x, control, ...
    m, g, rho, V, lx1, ly1, ly2, lx2, ly3, lx5, ly4, lz6, zb, Xu, ...
    Xu_dot, Xu_abs_u, Yv, Yv_dot, Yv_abs_v, Zw, Zw_dot,...
    Zw_abs_w, Kp, Kp_dot, Kp_abs_p, Mq, Mq_dot, Mq_abs_q,...
    Nr, Nr_dot, Nr_abs_r, Ix, Iy, Iz, Ix_Kp_dot, Iy_Mq_dot,...
    Kp_Ix_Kp_dot, Kp_abs_p_Ix_Kp_dot, Mq_dot_Ix_Kp_dot,...
    Nr_dot_Ix_Kp_dot, Mq_Iy_Mq_dot, Mq_abs_q_Iy_Mq_dot,...
    Kp_dot_Iy_Mq_dot, Nr_dot_Iy_Mq_dot,Iz_Nr_dot,Iy_Iz, Ix_Iz, Ix_Iy, varargin)
%******* States
p = x(1);
q = x(2);
r = x(3);

fi = control(7);
theta = control(8);
%*******    Computed values

ct = cos(theta);
st = sin(theta);
cf = cos(fi);
sf = sin(fi);
 
% B = rho*g*V;
W = m*g;
B = W;
% look-up table for t200.
lookup =[...
  -40.0337   -1.0000
  -40.0337   -0.9750
  -40.0788   -0.9500
  -37.5428   -0.9250
  -36.6092   -0.9000
  -35.4971   -0.8750
  -33.7623   -0.8500
  -32.3835   -0.8250
  -31.2263   -0.8000
  -29.9809   -0.7750
  -28.5128   -0.7500
  -27.6234   -0.7250
  -26.5554   -0.7000
  -24.7765   -0.6750
  -23.1751   -0.6500
  -22.1522   -0.6250
  -21.3510   -0.6000
  -19.5280   -0.5750
  -18.4600   -0.5500
  -17.3480   -0.5250
  -16.1025   -0.5000
  -14.6345   -0.4750
  -13.0781   -0.4500
  -12.1877   -0.4250
  -10.9874   -0.4000
  -10.0528   -0.3750
   -8.8966   -0.3500
   -7.7404   -0.3250
   -6.8058   -0.3000
   -6.0497   -0.2750
   -5.1151   -0.2500
   -4.2698   -0.2250
   -3.4696   -0.2000
   -2.7135   -0.1750
   -1.8682   -0.1500
   -1.1121   -0.1250
   -0.5335   -0.1000
   -0.2667   -0.0750
         0   -0.0500
         0   -0.0250
         0         0
         0    0.0250
         0    0.0500
    0.5786    0.0750
    1.1121    0.1000
    1.8240    0.1250
    2.5801    0.1500
    3.4255    0.1750
    4.0923    0.2000
    5.1151    0.2250
    6.2272    0.2500
    7.0284    0.2750
    8.2739    0.3000
    9.2526    0.3250
   10.8089    0.3500
   12.2328    0.3750
   13.6558    0.4000
   14.9904    0.4250
   16.4585    0.4500
   17.7039    0.4750
   19.2161    0.5000
   20.5508    0.5250
   21.7521    0.5500
   23.6644    0.5750
   24.7324    0.6000
   26.4221    0.6250
   27.7126    0.6500
   29.6249    0.6750
   31.3156    0.7000
   32.8729    0.7250
   33.8065    0.7500
   34.2517    0.7750
   37.0534    0.8000
   38.6549    0.8250
   39.2776    0.8500
   41.1458    0.8750
   42.9257    0.9000
   44.7938    0.9250
   47.1062    0.9500
   48.0408    0.9750
   49.9531    1.0000];

forces = nakeinterp1(lookup(:,2),lookup(:,1),control');
%Thrusterforce in newtons. Lookup table returns in kgf
f1 = forces(1);
f2 = forces(2);
f3 = forces(3);
f4 = forces(4);
f5 = forces(5);
f6 = forces(6);

p_dot =...
    (f1*ly1 - f2*ly2 + f6*lz6 + p*(Kp + Kp_abs_p*abs(p)) + Iy_Mq_dot*q*r - Iz_Nr_dot*q*r  + B*ct*sf*zb )/(Ix_Kp_dot);
 
q_dot =...
     (f1*lx1 + f2*lx2 - f5*lx5 + q*(Mq + Mq_abs_q*abs(q)) - Ix_Kp_dot*p*r + B*st*zb + Iz_Nr_dot*p*r)/(Iy_Mq_dot);

r_dot =...
     (r*(Nr + Nr_abs_r*abs(r)) + f3*ly3 - f4*ly4 + Ix_Kp_dot*p*q - Iy_Mq_dot*p*q)/(Iz_Nr_dot);

x_dot = [p_dot;q_dot;r_dot];

y = x;
end
