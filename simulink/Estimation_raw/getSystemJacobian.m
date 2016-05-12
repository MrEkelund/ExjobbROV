function F=getSystemJacobian(Ts,state,tau)
%extract states
n=state(1);e1=state(2);e2=state(3);e3=state(4);
p=state(5);q=state(6);r=state(7);
bias_p=state(8);bias_q=state(9);bias_r=state(10);
zb=state(11);
Kp=state(12);Kp_abs_p=state(13);
Mq=state(14);Mq_abs_q=state(15);
Nr=state(16);Nr_abs_r=state(17);
Ix_Kp_dot=state(18);Iy_Mq_dot=state(19);Iz_Nr_dot=state(20);

m=6.621;%ROV mass [kg];
g=9.81744;%Gravity [m/s^2]
rho=1000;%water density [kg/m^3]
V=0.012;%Discplaced water volume [m^3]
%Thruster placement fromCO[m]
lx1=0.16;
ly1=0.11;
ly2=0.11;
lx2=0.16;
ly3=0.11;
lx5=0.2;
ly4=0.11;
lz6=0.11;

B=m*g;



f1=tau(1);
f2=tau(2);
f3=tau(3);
f4=tau(4);
f5=tau(5);
f6=tau(6);


%new based on euler forward
F=[...
1,-(Ts*p)/2,-(Ts*q)/2,-(Ts*r)/2,-(Ts*e1)/2,-(Ts*e2)/2,-(Ts*e3)/2,0,0,0,0,0,0,0,0,0,0,0,0,0
(Ts*p)/2,1,(Ts*r)/2,-(Ts*q)/2,(Ts*n)/2,-(Ts*e3)/2,(Ts*e2)/2,0,0,0,0,0,0,0,0,0,0,0,0,0
(Ts*q)/2,-(Ts*r)/2,1,(Ts*p)/2,(Ts*e3)/2,(Ts*n)/2,-(Ts*e1)/2,0,0,0,0,0,0,0,0,0,0,0,0,0
(Ts*r)/2,(Ts*q)/2,-(Ts*p)/2,1,-(Ts*e2)/2,(Ts*e1)/2,(Ts*n)/2,0,0,0,0,0,0,0,0,0,0,0,0,0
(2*B*Ts*e1*zb)/Ix_Kp_dot,(2*B*Ts*n*zb)/Ix_Kp_dot,(2*B*Ts*e3*zb)/Ix_Kp_dot,(2*B*Ts*e2*zb)/Ix_Kp_dot,(Ts*(Kp+Kp_abs_p*abs(p)))/Ix_Kp_dot+(Kp_abs_p*Ts*p*sign(p))/Ix_Kp_dot+1,(Ts*r*(Iy_Mq_dot-Iz_Nr_dot))/Ix_Kp_dot,(Ts*q*(Iy_Mq_dot-Iz_Nr_dot))/Ix_Kp_dot,0,0,0,(2*B*Ts*e2*e3)/Ix_Kp_dot+(2*B*Ts*e1*n)/Ix_Kp_dot,(Ts*p)/Ix_Kp_dot,(Ts*p*abs(p))/Ix_Kp_dot,0,0,0,0,-(Ts*(f1*ly1-f2*ly2+f6*lz6))/Ix_Kp_dot^2-(Ts*p*(Kp+Kp_abs_p*abs(p)))/Ix_Kp_dot^2-(Ts*q*r*(Iy_Mq_dot-Iz_Nr_dot))/Ix_Kp_dot^2-(2*B*Ts*e2*e3*zb)/Ix_Kp_dot^2-(2*B*Ts*e1*n*zb)/Ix_Kp_dot^2,(Ts*q*r)/Ix_Kp_dot,-(Ts*q*r)/Ix_Kp_dot
(2*B*Ts*e2*zb)/Iy_Mq_dot,-(2*B*Ts*e3*zb)/Iy_Mq_dot,(2*B*Ts*n*zb)/Iy_Mq_dot,-(2*B*Ts*e1*zb)/Iy_Mq_dot,-(Ts*r*(Ix_Kp_dot-Iz_Nr_dot))/Iy_Mq_dot,(Ts*(Mq+Mq_abs_q*abs(q)))/Iy_Mq_dot+(Mq_abs_q*Ts*q*sign(q))/Iy_Mq_dot+1,-(Ts*p*(Ix_Kp_dot-Iz_Nr_dot))/Iy_Mq_dot,0,0,0,(2*B*Ts*e2*n)/Iy_Mq_dot-(2*B*Ts*e1*e3)/Iy_Mq_dot,0,0,(Ts*q)/Iy_Mq_dot,(Ts*q*abs(q))/Iy_Mq_dot,0,0,-(Ts*p*r)/Iy_Mq_dot,(Ts*p*r*(Ix_Kp_dot-Iz_Nr_dot))/Iy_Mq_dot^2-(Ts*q*(Mq+Mq_abs_q*abs(q)))/Iy_Mq_dot^2-(Ts*(f1*lx1+f2*lx2-f5*lx5))/Iy_Mq_dot^2+(2*B*Ts*e1*e3*zb)/Iy_Mq_dot^2-(2*B*Ts*e2*n*zb)/Iy_Mq_dot^2,(Ts*p*r)/Iy_Mq_dot
0,0,0,0,(Ts*q*(Ix_Kp_dot-Iy_Mq_dot))/Iz_Nr_dot,(Ts*p*(Ix_Kp_dot-Iy_Mq_dot))/Iz_Nr_dot,(Ts*(Nr+Nr_abs_r*abs(r)))/Iz_Nr_dot+(Nr_abs_r*Ts*r*sign(r))/Iz_Nr_dot+1,0,0,0,0,0,0,0,0,(Ts*r)/Iz_Nr_dot,(Ts*r*abs(r))/Iz_Nr_dot,(Ts*p*q)/Iz_Nr_dot,-(Ts*p*q)/Iz_Nr_dot,-(Ts*(f3*ly3-f4*ly4))/Iz_Nr_dot^2-(Ts*r*(Nr+Nr_abs_r*abs(r)))/Iz_Nr_dot^2-(Ts*p*q*(Ix_Kp_dot-Iy_Mq_dot))/Iz_Nr_dot^2
0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1];


end