function F=getSystemJacobian(Ts,state,tau)
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



f1=tau(1);
f2=tau(2);
f3=tau(3);
f4=tau(4);
f5=tau(5);
f6=tau(6);


%returnJacobianF
F=[...
1,-p*(Ts^2/2+Ts/2),-q*(Ts^2/2+Ts/2),-r*(Ts^2/2+Ts/2),-e1*(Ts^2/2+Ts/2),-e2*(Ts^2/2+Ts/2),-e3*(Ts^2/2+Ts/2),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
p*(Ts^2/2+Ts/2),1,r*(Ts^2/2+Ts/2),-q*(Ts^2/2+Ts/2),n*(Ts^2/2+Ts/2),-e3*(Ts^2/2+Ts/2),e2*(Ts^2/2+Ts/2),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
q*(Ts^2/2+Ts/2),-r*(Ts^2/2+Ts/2),1,p*(Ts^2/2+Ts/2),e3*(Ts^2/2+Ts/2),n*(Ts^2/2+Ts/2),-e1*(Ts^2/2+Ts/2),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
r*(Ts^2/2+Ts/2),q*(Ts^2/2+Ts/2),-p*(Ts^2/2+Ts/2),1,-e2*(Ts^2/2+Ts/2),e1*(Ts^2/2+Ts/2),n*(Ts^2/2+Ts/2),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
(2*B*Ts*e1*zb)/Ix_Kp_dot,(2*B*Ts*n*zb)/Ix_Kp_dot,(2*B*Ts*e3*zb)/Ix_Kp_dot,(2*B*Ts*e2*zb)/Ix_Kp_dot,(Ts*(Kp+Kp_abs_p*abs(p)))/Ix_Kp_dot+(Kp_abs_p*Ts*p*sign(p))/Ix_Kp_dot+1,(Ts*r*(Iy-Iz-Mq_dot+Nr_dot))/Ix_Kp_dot,(Ts*q*(Iy-Iz-Mq_dot+Nr_dot))/Ix_Kp_dot,(2*B*Ts*e2*e3)/Ix_Kp_dot+(2*B*Ts*e1*n)/Ix_Kp_dot,(Ts*p)/Ix_Kp_dot,0,(Ts*p*abs(p))/Ix_Kp_dot,0,-(Ts*q*r)/Ix_Kp_dot,0,0,(Ts*q*r)/Ix_Kp_dot,0,0,(Ts*q*r)/Ix_Kp_dot,-(Ts*q*r)/Ix_Kp_dot,-(Ts*(f1*ly1-f2*ly2+f6*lz6))/Ix_Kp_dot^2-(Ts*p*(Kp+Kp_abs_p*abs(p)))/Ix_Kp_dot^2-(Ts*q*r*(Iy-Iz-Mq_dot+Nr_dot))/Ix_Kp_dot^2-(2*B*Ts*e2*e3*zb)/Ix_Kp_dot^2-(2*B*Ts*e1*n*zb)/Ix_Kp_dot^2,0,0;
(2*B*Ts*e2*zb)/Iy_Mq_dot,-(2*B*Ts*e3*zb)/Iy_Mq_dot,(2*B*Ts*n*zb)/Iy_Mq_dot,-(2*B*Ts*e1*zb)/Iy_Mq_dot,-(Ts*r*(Ix-Iz-Kp_dot+Nr_dot))/Iy_Mq_dot,(Ts*(Mq+Mq_abs_q*abs(q)))/Iy_Mq_dot+(Mq_abs_q*Ts*q*sign(q))/Iy_Mq_dot+1,-(Ts*p*(Ix-Iz-Kp_dot+Nr_dot))/Iy_Mq_dot,(2*B*Ts*e2*n)/Iy_Mq_dot-(2*B*Ts*e1*e3)/Iy_Mq_dot,0,(Ts*p*r)/Iy_Mq_dot,0,(Ts*q)/Iy_Mq_dot,0,(Ts*q*abs(q))/Iy_Mq_dot,0,-(Ts*p*r)/Iy_Mq_dot,0,-(Ts*p*r)/Iy_Mq_dot,0,(Ts*p*r)/Iy_Mq_dot,0,(Ts*p*r*(Ix-Iz-Kp_dot+Nr_dot))/Iy_Mq_dot^2-(Ts*q*(Mq+Mq_abs_q*abs(q)))/Iy_Mq_dot^2-(Ts*(f1*lx1+f2*lx2-f5*lx5))/Iy_Mq_dot^2+(2*B*Ts*e1*e3*zb)/Iy_Mq_dot^2-(2*B*Ts*e2*n*zb)/Iy_Mq_dot^2,0;
0,0,0,0,(Ts*q*(Ix-Iy-Kp_dot+Mq_dot))/Iz_Nr_dot,(Ts*p*(Ix-Iy-Kp_dot+Mq_dot))/Iz_Nr_dot,(Ts*(Nr+Nr_abs_r*abs(r)))/Iz_Nr_dot+(Nr_abs_r*Ts*r*sign(r))/Iz_Nr_dot+1,0,0,-(Ts*p*q)/Iz_Nr_dot,0,0,(Ts*p*q)/Iz_Nr_dot,0,(Ts*r)/Iz_Nr_dot,0,(Ts*r*abs(r))/Iz_Nr_dot,(Ts*p*q)/Iz_Nr_dot,-(Ts*p*q)/Iz_Nr_dot,0,0,0,-(Ts*(f3*ly3-f4*ly4))/Iz_Nr_dot^2-(Ts*r*(Nr+Nr_abs_r*abs(r)))/Iz_Nr_dot^2-(Ts*p*q*(Ix-Iy-Kp_dot+Mq_dot))/Iz_Nr_dot^2;
0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1];
end