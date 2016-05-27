function new_state=timeStep(Ts,state,tau)
%extractstates
n=state(1);e1=state(2);e2=state(3);e3=state(4);
p=state(5);q=state(6);r=state(7);
bias_p=state(8);bias_q=state(9);bias_r=state(10);
zb=state(11);
Kp=state(12);Kp_abs_p=state(13);
Mq=state(14);Mq_abs_q=state(15);
Nr=state(16);Nr_abs_r=state(17);
Ix_Kp_dot=state(18);Iy_Mq_dot=state(19);Iz_Nr_dot=state(20);


m=6.621;%ROVmass[kg];
g=9.81744;%Gravity[m/s^2]
rho=1000;%waterdensity[kg/m^3]
V=0.012;%Discplacedwatervolume[m^3]
%ThrusterplacementfromCO[m]
lx1=0.19;
lx2=0.19;
ly1=0.11;
ly2=0.11;
ly3=0.11;
ly4=0.11;
lx5=0.17;
lz6=0;%0.11;

B=m*g;

%extractforcesfromthrusters
f1=tau(1);
f2=tau(2);
f3=tau(3);
f4=tau(4);
f5=tau(5);
f6=tau(6);

% new_state=[...
% (-Ts/2)*p*e1+(-Ts/2)*q*e2+(-Ts/2)*r*e3+n
% (Ts/2)*p*n+(-Ts/2)*q*e3+(Ts/2)*r*e2+e1
% (Ts/2)*p*e3+(Ts/2)*q*n+(-Ts/2)*r*e1+e2
% (-Ts/2)*p*e2+(Ts/2)*q*e1+(Ts/2)*r*n+e3
% ((Ts*(Kp+Kp_abs_p*abs(p)))/Ix_Kp_dot+1)*p+((Ts*(Iy_Mq_dot-Iz_Nr_dot))/Ix_Kp_dot)*q*r+((2*B*Ts*zb)/Ix_Kp_dot)*n*e1+((2*B*Ts*zb)/Ix_Kp_dot)*e2*e3+(Ts*(f1*ly1-f2*ly2+f6*lz6))/Ix_Kp_dot
% (-(Ts*(Ix_Kp_dot-Iz_Nr_dot))/Iy_Mq_dot)*p*r+((Ts*(Mq+Mq_abs_q*abs(q)))/Iy_Mq_dot+1)*q+((2*B*Ts*zb)/Iy_Mq_dot)*n*e2+(-(2*B*Ts*zb)/Iy_Mq_dot)*e1*e3+(Ts*(f1*lx1+f2*lx2-f5*lx5))/Iy_Mq_dot
% ((Ts*(Ix_Kp_dot-Iy_Mq_dot))/Iz_Nr_dot)*p*q+((Ts*(Nr+Nr_abs_r*abs(r)))/Iz_Nr_dot+1)*r+(Ts*(f3*ly3-f4*ly4))/Iz_Nr_dot
% bias_p
% bias_q
% bias_r
% zb
% Kp
% Kp_abs_p
% Mq
% Mq_abs_q
% Nr
% Nr_abs_r
% Ix_Kp_dot
% Iy_Mq_dot
% Iz_Nr_dot];


new_state =[...
(-Ts/2)*p*e1+(-Ts/2)*q*e2+(-Ts/2)*r*e3+n
(Ts/2)*p*n+(-Ts/2)*q*e3+(Ts/2)*r*e2+e1
(Ts/2)*p*e3+(Ts/2)*q*n+(-Ts/2)*r*e1+e2
(-Ts/2)*p*e2+(Ts/2)*q*e1+(Ts/2)*r*n+e3
((Ts*(Kp+Kp_abs_p*abs(p)))/Ix_Kp_dot+1)*p+((Ts*(Iy_Mq_dot-Iz_Nr_dot))/Ix_Kp_dot)*q*r+((2*B*Ts*zb)/Ix_Kp_dot)*n*e1+((2*B*Ts*zb)/Ix_Kp_dot)*e2*e3+(Ts*(f1*ly1-f2*ly2+f6*lz6))/Ix_Kp_dot
(-(Ts*(Ix_Kp_dot-Iz_Nr_dot))/Iy_Mq_dot)*p*r+((Ts*(Mq+Mq_abs_q*abs(q)))/Iy_Mq_dot+1)*q+((2*B*Ts*zb)/Iy_Mq_dot)*n*e2+(-(2*B*Ts*zb)/Iy_Mq_dot)*e1*e3+(Ts*(f1*lx1+f2*lx2-f5*lx5))/Iy_Mq_dot
((Ts*(Ix_Kp_dot-Iy_Mq_dot))/Iz_Nr_dot)*p*q+((Ts*(Nr+Nr_abs_r*abs(r)))/Iz_Nr_dot+1)*r+(Ts*(f3*ly3-f4*ly4))/Iz_Nr_dot
bias_p
bias_q
bias_r
zb
Kp
Kp_abs_p
Mq
Mq_abs_q
Nr
Nr_abs_r
Ix_Kp_dot
Iy_Mq_dot
Iz_Nr_dot];


end