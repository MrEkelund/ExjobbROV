function new_state=timeStep(Ts,state,tau)
%extractstates
n=state(1);e1=state(2);e2=state(3);e3=state(4);p=state(5);
q=state(6);r=state(7);zb=state(8);Kp=state(9);Kp_dot=state(10);
Kp_abs_p=state(11);Mq=state(12);Mq_dot=state(13);Mq_abs_q=state(14);
Nr=state(15);Nr_dot=state(16);Nr_abs_r=state(17);Ix=state(18);
Iy=state(19);Iz=state(20);Ix_Kp_dot=state(21);Iy_Mq_dot=state(22);
Iz_Nr_dot=state(23);

m=6.621;%ROVmass[kg];
g=9.81744;%Gravity[m/s^2]
rho=1000;%waterdensity[kg/m^3]
V=0.012;%Discplacedwatervolume[m^3]
%ThrusterplacementfromCO[m]
lx1=0.16;
ly1=0.11;
ly2=0.11;
lx2=0.16;
ly3=0.11;
lx5=0.2;
ly4=0.11;
lz6=0.11;
B=m*g;


%extractforcesfromthrusters
f1=tau(1);
f2=tau(2);
f3=tau(3);
f4=tau(4);
f5=tau(5);
f6=tau(6);


%returnfoldtimestep.NotbasedonFosseneulerforward
%new_state=[...
%(-Ts^2/2-Ts/2)*p*e1+(-Ts^2/2-Ts/2)*q*e2+(-Ts^2/2-Ts/2)*r*e3+n;
%(Ts^2/2+Ts/2)*p*n+(-Ts^2/2-Ts/2)*q*e3+(Ts^2/2+Ts/2)*r*e2+e1;
%(Ts^2/2+Ts/2)*p*e3+(Ts^2/2+Ts/2)*q*n+(-Ts^2/2-Ts/2)*r*e1+e2;
%(-Ts^2/2-Ts/2)*p*e2+(Ts^2/2+Ts/2)*q*e1+(Ts^2/2+Ts/2)*r*n+e3;
%((Ts*(Kp+Kp_abs_p*abs(p)))/Ix_Kp_dot+1)*p+((Ts*(Iy-Iz-Mq_dot+Nr_dot))/Ix_Kp_dot)*q*r+((2*B*Ts*zb)/Ix_Kp_dot)*n*e1+((2*B*Ts*zb)/Ix_Kp_dot)*e2*e3+(Ts*(f1*ly1-f2*ly2+f6*lz6))/Ix_Kp_dot;
%(-(Ts*(Ix-Iz-Kp_dot+Nr_dot))/Iy_Mq_dot)*p*r+((Ts*(Mq+Mq_abs_q*abs(q)))/Iy_Mq_dot+1)*q+((2*B*Ts*zb)/Iy_Mq_dot)*n*e2+(-(2*B*Ts*zb)/Iy_Mq_dot)*e1*e3+(Ts*(f1*lx1+f2*lx2-f5*lx5))/Iy_Mq_dot;
%((Ts*(Ix-Iy-Kp_dot+Mq_dot))/Iz_Nr_dot)*p*q+((Ts*(Nr+Nr_abs_r*abs(r)))/Iz_Nr_dot+1)*r+(Ts*(f3*ly3-f4*ly4))/Iz_Nr_dot;
%zb;
%Kp;
%Kp_dot;
%Kp_abs_p;
%Mq;
%Mq_dot;
%Mq_abs_q;
%Nr;
%Nr_dot;
%Nr_abs_r;
%Ix;
%Iy;
%Iz;
%Ix_Kp_dot;
%Iy_Mq_dot;
%Iz_Nr_dot];

new_state=[...
(-(Ts^2*(Ix-Iy-Kp_dot+Mq_dot))/(2*Iz_Nr_dot))*p*q*e3+((Ts^2*(Ix-Iz-Kp_dot+Nr_dot))/(2*Iy_Mq_dot))*p*r*e2+(-Ts*((Ts*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot)+1/2))*p*e1+(-(Ts^2*(Iy-Iz-Mq_dot+Nr_dot))/(2*Ix_Kp_dot))*q*r*e1+(-Ts*((Ts*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot)+1/2))*q*e2+(-Ts*((Ts*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot)+1/2))*r*e3+(-(B*Ts^2*zb)/Ix_Kp_dot)*n*e1^2+(-(B*Ts^2*zb)/Iy_Mq_dot)*n*e2^2+n+(-Ts*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot))*e1*e2*e3+(-(Ts^2*(f1*ly1-f2*ly2+f6*lz6))/(2*Ix_Kp_dot))*e1+(-(Ts^2*(f1*lx1+f2*lx2-f5*lx5))/(2*Iy_Mq_dot))*e2+(-(Ts^2*(f3*ly3-f4*ly4))/(2*Iz_Nr_dot))*e3;
((Ts^2*(Ix-Iy-Kp_dot+Mq_dot))/(2*Iz_Nr_dot))*p*q*e2+((Ts^2*(Ix-Iz-Kp_dot+Nr_dot))/(2*Iy_Mq_dot))*p*r*e3+(Ts*((Ts*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot)+1/2))*p*n+((Ts^2*(Iy-Iz-Mq_dot+Nr_dot))/(2*Ix_Kp_dot))*q*r*n+(-Ts*((Ts*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot)+1/2))*q*e3+(Ts*((Ts*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot)+1/2))*r*e2+((B*Ts^2*zb)/Ix_Kp_dot)*n^2*e1+(Ts*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot))*n*e2*e3+((Ts^2*(f1*ly1-f2*ly2+f6*lz6))/(2*Ix_Kp_dot))*n+((B*Ts^2*zb)/Iy_Mq_dot)*e1*e3^2+e1+((Ts^2*(f3*ly3-f4*ly4))/(2*Iz_Nr_dot))*e2+(-(Ts^2*(f1*lx1+f2*lx2-f5*lx5))/(2*Iy_Mq_dot))*e3;
(-(Ts^2*(Ix-Iy-Kp_dot+Mq_dot))/(2*Iz_Nr_dot))*p*q*e1+(-(Ts^2*(Ix-Iz-Kp_dot+Nr_dot))/(2*Iy_Mq_dot))*p*r*n+(Ts*((Ts*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot)+1/2))*p*e3+((Ts^2*(Iy-Iz-Mq_dot+Nr_dot))/(2*Ix_Kp_dot))*q*r*e3+(Ts*((Ts*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot)+1/2))*q*n+(-Ts*((Ts*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot)+1/2))*r*e1+((B*Ts^2*zb)/Iy_Mq_dot)*n^2*e2+(Ts*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot))*n*e1*e3+((Ts^2*(f1*lx1+f2*lx2-f5*lx5))/(2*Iy_Mq_dot))*n+(-(Ts^2*(f3*ly3-f4*ly4))/(2*Iz_Nr_dot))*e1+((B*Ts^2*zb)/Ix_Kp_dot)*e2*e3^2+e2+((Ts^2*(f1*ly1-f2*ly2+f6*lz6))/(2*Ix_Kp_dot))*e3;
((Ts^2*(Ix-Iy-Kp_dot+Mq_dot))/(2*Iz_Nr_dot))*p*q*n+(-(Ts^2*(Ix-Iz-Kp_dot+Nr_dot))/(2*Iy_Mq_dot))*p*r*e1+(-Ts*((Ts*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot)+1/2))*p*e2+(-(Ts^2*(Iy-Iz-Mq_dot+Nr_dot))/(2*Ix_Kp_dot))*q*r*e2+(Ts*((Ts*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot)+1/2))*q*e1+(Ts*((Ts*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot)+1/2))*r*n+(-Ts*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot))*n*e1*e2+((Ts^2*(f3*ly3-f4*ly4))/(2*Iz_Nr_dot))*n+(-(B*Ts^2*zb)/Iy_Mq_dot)*e1^2*e3+((Ts^2*(f1*lx1+f2*lx2-f5*lx5))/(2*Iy_Mq_dot))*e1+(-(B*Ts^2*zb)/Ix_Kp_dot)*e2^2*e3+(-(Ts^2*(f1*ly1-f2*ly2+f6*lz6))/(2*Ix_Kp_dot))*e2+e3;
((Ts*(Kp+Kp_abs_p*abs(p)))/Ix_Kp_dot+1)*p+((Ts*(Iy-Iz-Mq_dot+Nr_dot))/Ix_Kp_dot)*q*r+((2*B*Ts*zb)/Ix_Kp_dot)*n*e1+((2*B*Ts*zb)/Ix_Kp_dot)*e2*e3+(Ts*(f1*ly1-f2*ly2+f6*lz6))/Ix_Kp_dot;
(-(Ts*(Ix-Iz-Kp_dot+Nr_dot))/Iy_Mq_dot)*p*r+((Ts*(Mq+Mq_abs_q*abs(q)))/Iy_Mq_dot+1)*q+((2*B*Ts*zb)/Iy_Mq_dot)*n*e2+(-(2*B*Ts*zb)/Iy_Mq_dot)*e1*e3+(Ts*(f1*lx1+f2*lx2-f5*lx5))/Iy_Mq_dot;
((Ts*(Ix-Iy-Kp_dot+Mq_dot))/Iz_Nr_dot)*p*q+((Ts*(Nr+Nr_abs_r*abs(r)))/Iz_Nr_dot+1)*r+(Ts*(f3*ly3-f4*ly4))/Iz_Nr_dot;
zb;
Kp;
Kp_dot;
Kp_abs_p;
Mq;
Mq_dot;
Mq_abs_q;
Nr;
Nr_dot;
Nr_abs_r;
Ix;
Iy;
Iz;
Ix_Kp_dot;
Iy_Mq_dot;
Iz_Nr_dot];



end