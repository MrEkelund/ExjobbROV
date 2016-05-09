function F=getSystemJacobian(Ts,state,tau)
%extract states
n=state(1);e1=state(2);e2=state(3);e3=state(4);
p=state(5);q=state(6);r=state(7);
bias_p=state(8);bias_q=state(9);bias_r=state(10);
zb=state(11);
Kp=state(12);Kp_dot=state(13);Kp_abs_p=state(14);
Mq=state(15);Mq_dot=state(16);Mq_abs_q=state(17);
Nr=state(18);Nr_dot=state(19);Nr_abs_r=state(20);
Ix=state(21);Iy=state(22);Iz=state(23);
Ix_Kp_dot=state(24);Iy_Mq_dot=state(25);Iz_Nr_dot=state(26);

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
F=...
[1-(B*Ts^2*e2^2*zb)/Iy_Mq_dot-(B*Ts^2*e1^2*zb)/Ix_Kp_dot,-Ts*p*((Ts*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot)+1/2)-(Ts^2*(f1*ly1-f2*ly2+f6*lz6))/(2*Ix_Kp_dot)-Ts*e2*e3*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot)-(Ts^2*q*r*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot)-(2*B*Ts^2*e1*n*zb)/Ix_Kp_dot,(Ts^2*p*r*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot)-(Ts^2*(f1*lx1+f2*lx2-f5*lx5))/(2*Iy_Mq_dot)-Ts*e1*e3*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot)-Ts*q*((Ts*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot)+1/2)-(2*B*Ts^2*e2*n*zb)/Iy_Mq_dot,-Ts*r*((Ts*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot)+1/2)-(Ts^2*(f3*ly3-f4*ly4))/(2*Iz_Nr_dot)-Ts*e1*e2*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot)-(Ts^2*p*q*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot),(Ts^2*e2*r*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot)-(Ts^2*e3*q*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot)-Ts*e1*((Ts*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot)+1/2)-(Kp_abs_p*Ts^2*e1*p*sign(p))/(2*Ix_Kp_dot),-Ts*e2*((Ts*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot)+1/2)-(Ts^2*e3*p*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot)-(Ts^2*e1*r*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot)-(Mq_abs_q*Ts^2*e2*q*sign(q))/(2*Iy_Mq_dot),(Ts^2*e2*p*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot)-Ts*e3*((Ts*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot)+1/2)-(Ts^2*e1*q*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot)-(Nr_abs_r*Ts^2*e3*r*sign(r))/(2*Iz_Nr_dot),0,0,0,-(B*Ts^2*e1^2*n)/Ix_Kp_dot-(B*Ts^2*e2^2*n)/Iy_Mq_dot-Ts*e1*e2*e3*((B*Ts)/Ix_Kp_dot-(B*Ts)/Iy_Mq_dot),-(Ts^2*e1*p)/(2*Ix_Kp_dot),0,-(Ts^2*e1*p*abs(p))/(2*Ix_Kp_dot),-(Ts^2*e2*q)/(2*Iy_Mq_dot),0,-(Ts^2*e2*q*abs(q))/(2*Iy_Mq_dot),-(Ts^2*e3*r)/(2*Iz_Nr_dot),0,-(Ts^2*e3*r*abs(r))/(2*Iz_Nr_dot),0,0,0,(Ts^2*e1*(f1*ly1-f2*ly2+f6*lz6))/(2*Ix_Kp_dot^2)-(Ts^2*e3*p*q)/(2*Iz_Nr_dot)+(Ts^2*e2*p*r)/(2*Iy_Mq_dot)+(Ts^2*e1*p*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot^2)+(Ts^2*e1*q*r*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot^2)+(B*Ts^2*e1^2*n*zb)/Ix_Kp_dot^2+(B*Ts^2*e1*e2*e3*zb)/Ix_Kp_dot^2,(Ts^2*e2*(f1*lx1+f2*lx2-f5*lx5))/(2*Iy_Mq_dot^2)+(Ts^2*e3*p*q)/(2*Iz_Nr_dot)-(Ts^2*e1*q*r)/(2*Ix_Kp_dot)+(Ts^2*e2*q*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot^2)-(Ts^2*e2*p*r*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot^2)+(B*Ts^2*e2^2*n*zb)/Iy_Mq_dot^2-(B*Ts^2*e1*e2*e3*zb)/Iy_Mq_dot^2,(Ts^2*e3*(f3*ly3-f4*ly4))/(2*Iz_Nr_dot^2)-(Ts^2*e2*p*r)/(2*Iy_Mq_dot)+(Ts^2*e1*q*r)/(2*Ix_Kp_dot)+(Ts^2*e3*r*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot^2)+(Ts^2*e3*p*q*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot^2);
Ts*p*((Ts*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot)+1/2)+(Ts^2*(f1*ly1-f2*ly2+f6*lz6))/(2*Ix_Kp_dot)+Ts*e2*e3*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot)+(Ts^2*q*r*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot)+(2*B*Ts^2*e1*n*zb)/Ix_Kp_dot,(B*zb*Ts^2*e3^2)/Iy_Mq_dot+(B*zb*Ts^2*n^2)/Ix_Kp_dot+1,Ts*r*((Ts*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot)+1/2)+(Ts^2*(f3*ly3-f4*ly4))/(2*Iz_Nr_dot)+Ts*e3*n*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot)+(Ts^2*p*q*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot),Ts*e2*n*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot)-(Ts^2*(f1*lx1+f2*lx2-f5*lx5))/(2*Iy_Mq_dot)-Ts*q*((Ts*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot)+1/2)+(Ts^2*p*r*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot)+(2*B*Ts^2*e1*e3*zb)/Iy_Mq_dot,Ts*n*((Ts*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot)+1/2)+(Ts^2*e2*q*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot)+(Ts^2*e3*r*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot)+(Kp_abs_p*Ts^2*n*p*sign(p))/(2*Ix_Kp_dot),(Ts^2*e2*p*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot)-Ts*e3*((Ts*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot)+1/2)+(Ts^2*n*r*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot)-(Mq_abs_q*Ts^2*e3*q*sign(q))/(2*Iy_Mq_dot),Ts*e2*((Ts*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot)+1/2)+(Ts^2*e3*p*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot)+(Ts^2*n*q*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot)+(Nr_abs_r*Ts^2*e2*r*sign(r))/(2*Iz_Nr_dot),0,0,0,(B*Ts^2*e1*e3^2)/Iy_Mq_dot+(B*Ts^2*e1*n^2)/Ix_Kp_dot+Ts*e2*e3*n*((B*Ts)/Ix_Kp_dot-(B*Ts)/Iy_Mq_dot),(Ts^2*n*p)/(2*Ix_Kp_dot),0,(Ts^2*n*p*abs(p))/(2*Ix_Kp_dot),-(Ts^2*e3*q)/(2*Iy_Mq_dot),0,-(Ts^2*e3*q*abs(q))/(2*Iy_Mq_dot),(Ts^2*e2*r)/(2*Iz_Nr_dot),0,(Ts^2*e2*r*abs(r))/(2*Iz_Nr_dot),0,0,0,(Ts^2*e2*p*q)/(2*Iz_Nr_dot)-(Ts^2*n*(f1*ly1-f2*ly2+f6*lz6))/(2*Ix_Kp_dot^2)+(Ts^2*e3*p*r)/(2*Iy_Mq_dot)-(Ts^2*n*p*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot^2)-(Ts^2*n*q*r*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot^2)-(B*Ts^2*e1*n^2*zb)/Ix_Kp_dot^2-(B*Ts^2*e2*e3*n*zb)/Ix_Kp_dot^2,(Ts^2*e3*(f1*lx1+f2*lx2-f5*lx5))/(2*Iy_Mq_dot^2)-(Ts^2*e2*p*q)/(2*Iz_Nr_dot)+(Ts^2*n*q*r)/(2*Ix_Kp_dot)+(Ts^2*e3*q*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot^2)-(Ts^2*e3*p*r*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot^2)-(B*Ts^2*e1*e3^2*zb)/Iy_Mq_dot^2+(B*Ts^2*e2*e3*n*zb)/Iy_Mq_dot^2,-(Ts^2*e2*(f3*ly3-f4*ly4))/(2*Iz_Nr_dot^2)-(Ts^2*e3*p*r)/(2*Iy_Mq_dot)-(Ts^2*n*q*r)/(2*Ix_Kp_dot)-(Ts^2*e2*r*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot^2)-(Ts^2*e2*p*q*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot^2);
Ts*q*((Ts*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot)+1/2)+(Ts^2*(f1*lx1+f2*lx2-f5*lx5))/(2*Iy_Mq_dot)+Ts*e1*e3*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot)-(Ts^2*p*r*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot)+(2*B*Ts^2*e2*n*zb)/Iy_Mq_dot,Ts*e3*n*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot)-(Ts^2*(f3*ly3-f4*ly4))/(2*Iz_Nr_dot)-Ts*r*((Ts*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot)+1/2)-(Ts^2*p*q*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot),(B*zb*Ts^2*e3^2)/Ix_Kp_dot+(B*zb*Ts^2*n^2)/Iy_Mq_dot+1,Ts*p*((Ts*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot)+1/2)+(Ts^2*(f1*ly1-f2*ly2+f6*lz6))/(2*Ix_Kp_dot)+Ts*e1*n*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot)+(Ts^2*q*r*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot)+(2*B*Ts^2*e2*e3*zb)/Ix_Kp_dot,Ts*e3*((Ts*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot)+1/2)-(Ts^2*e1*q*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot)-(Ts^2*n*r*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot)+(Kp_abs_p*Ts^2*e3*p*sign(p))/(2*Ix_Kp_dot),Ts*n*((Ts*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot)+1/2)-(Ts^2*e1*p*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot)+(Ts^2*e3*r*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot)+(Mq_abs_q*Ts^2*n*q*sign(q))/(2*Iy_Mq_dot),(Ts^2*e3*q*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot)-Ts*e1*((Ts*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot)+1/2)-(Ts^2*n*p*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot)-(Nr_abs_r*Ts^2*e1*r*sign(r))/(2*Iz_Nr_dot),0,0,0,(B*Ts^2*e2*e3^2)/Ix_Kp_dot+(B*Ts^2*e2*n^2)/Iy_Mq_dot+Ts*e1*e3*n*((B*Ts)/Ix_Kp_dot-(B*Ts)/Iy_Mq_dot),(Ts^2*e3*p)/(2*Ix_Kp_dot),0,(Ts^2*e3*p*abs(p))/(2*Ix_Kp_dot),(Ts^2*n*q)/(2*Iy_Mq_dot),0,(Ts^2*n*q*abs(q))/(2*Iy_Mq_dot),-(Ts^2*e1*r)/(2*Iz_Nr_dot),0,-(Ts^2*e1*r*abs(r))/(2*Iz_Nr_dot),0,0,0,-(Ts^2*e3*(f1*ly1-f2*ly2+f6*lz6))/(2*Ix_Kp_dot^2)-(Ts^2*e1*p*q)/(2*Iz_Nr_dot)-(Ts^2*n*p*r)/(2*Iy_Mq_dot)-(Ts^2*e3*p*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot^2)-(Ts^2*e3*q*r*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot^2)-(B*Ts^2*e2*e3^2*zb)/Ix_Kp_dot^2-(B*Ts^2*e1*e3*n*zb)/Ix_Kp_dot^2,(Ts^2*e1*p*q)/(2*Iz_Nr_dot)-(Ts^2*n*(f1*lx1+f2*lx2-f5*lx5))/(2*Iy_Mq_dot^2)+(Ts^2*e3*q*r)/(2*Ix_Kp_dot)-(Ts^2*n*q*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot^2)+(Ts^2*n*p*r*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot^2)-(B*Ts^2*e2*n^2*zb)/Iy_Mq_dot^2+(B*Ts^2*e1*e3*n*zb)/Iy_Mq_dot^2,(Ts^2*e1*(f3*ly3-f4*ly4))/(2*Iz_Nr_dot^2)-(Ts^2*e3*q*r)/(2*Ix_Kp_dot)+(Ts^2*n*p*r)/(2*Iy_Mq_dot)+(Ts^2*e1*r*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot^2)+(Ts^2*e1*p*q*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot^2);
Ts*r*((Ts*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot)+1/2)+(Ts^2*(f3*ly3-f4*ly4))/(2*Iz_Nr_dot)-Ts*e1*e2*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot)+(Ts^2*p*q*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot),Ts*q*((Ts*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot)+1/2)+(Ts^2*(f1*lx1+f2*lx2-f5*lx5))/(2*Iy_Mq_dot)-Ts*e2*n*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot)-(Ts^2*p*r*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot)-(2*B*Ts^2*e1*e3*zb)/Iy_Mq_dot,-Ts*p*((Ts*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot)+1/2)-(Ts^2*(f1*ly1-f2*ly2+f6*lz6))/(2*Ix_Kp_dot)-Ts*e1*n*((B*Ts*zb)/Ix_Kp_dot-(B*Ts*zb)/Iy_Mq_dot)-(Ts^2*q*r*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot)-(2*B*Ts^2*e2*e3*zb)/Ix_Kp_dot,1-(B*Ts^2*e1^2*zb)/Iy_Mq_dot-(B*Ts^2*e2^2*zb)/Ix_Kp_dot,(Ts^2*n*q*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot)-(Ts^2*e1*r*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot)-Ts*e2*((Ts*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot)+1/2)-(Kp_abs_p*Ts^2*e2*p*sign(p))/(2*Ix_Kp_dot),Ts*e1*((Ts*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot)+1/2)-(Ts^2*e2*r*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot)+(Ts^2*n*p*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot)+(Mq_abs_q*Ts^2*e1*q*sign(q))/(2*Iy_Mq_dot),Ts*n*((Ts*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot)+1/2)-(Ts^2*e1*p*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot)-(Ts^2*e2*q*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot)+(Nr_abs_r*Ts^2*n*r*sign(r))/(2*Iz_Nr_dot),0,0,0,-(B*Ts^2*e2^2*e3)/Ix_Kp_dot-(B*Ts^2*e1^2*e3)/Iy_Mq_dot-Ts*e1*e2*n*((B*Ts)/Ix_Kp_dot-(B*Ts)/Iy_Mq_dot),-(Ts^2*e2*p)/(2*Ix_Kp_dot),0,-(Ts^2*e2*p*abs(p))/(2*Ix_Kp_dot),(Ts^2*e1*q)/(2*Iy_Mq_dot),0,(Ts^2*e1*q*abs(q))/(2*Iy_Mq_dot),(Ts^2*n*r)/(2*Iz_Nr_dot),0,(Ts^2*n*r*abs(r))/(2*Iz_Nr_dot),0,0,0,(Ts^2*e2*(f1*ly1-f2*ly2+f6*lz6))/(2*Ix_Kp_dot^2)-(Ts^2*e1*p*r)/(2*Iy_Mq_dot)+(Ts^2*n*p*q)/(2*Iz_Nr_dot)+(Ts^2*e2*p*(Kp+Kp_abs_p*abs(p)))/(2*Ix_Kp_dot^2)+(Ts^2*e2*q*r*(Iy_Mq_dot-Iz_Nr_dot))/(2*Ix_Kp_dot^2)+(B*Ts^2*e2^2*e3*zb)/Ix_Kp_dot^2+(B*Ts^2*e1*e2*n*zb)/Ix_Kp_dot^2,(Ts^2*e1*p*r*(Ix_Kp_dot-Iz_Nr_dot))/(2*Iy_Mq_dot^2)-(Ts^2*e2*q*r)/(2*Ix_Kp_dot)-(Ts^2*n*p*q)/(2*Iz_Nr_dot)-(Ts^2*e1*q*(Mq+Mq_abs_q*abs(q)))/(2*Iy_Mq_dot^2)-(Ts^2*e1*(f1*lx1+f2*lx2-f5*lx5))/(2*Iy_Mq_dot^2)+(B*Ts^2*e1^2*e3*zb)/Iy_Mq_dot^2-(B*Ts^2*e1*e2*n*zb)/Iy_Mq_dot^2,(Ts^2*e1*p*r)/(2*Iy_Mq_dot)-(Ts^2*n*(f3*ly3-f4*ly4))/(2*Iz_Nr_dot^2)+(Ts^2*e2*q*r)/(2*Ix_Kp_dot)-(Ts^2*n*r*(Nr+Nr_abs_r*abs(r)))/(2*Iz_Nr_dot^2)-(Ts^2*n*p*q*(Ix_Kp_dot-Iy_Mq_dot))/(2*Iz_Nr_dot^2);
(2*B*Ts*e1*zb)/Ix_Kp_dot,(2*B*Ts*n*zb)/Ix_Kp_dot,(2*B*Ts*e3*zb)/Ix_Kp_dot,(2*B*Ts*e2*zb)/Ix_Kp_dot,(Ts*(Kp+Kp_abs_p*abs(p)))/Ix_Kp_dot+(Kp_abs_p*Ts*p*sign(p))/Ix_Kp_dot+1,(Ts*r*(Iy_Mq_dot-Iz_Nr_dot))/Ix_Kp_dot,(Ts*q*(Iy_Mq_dot-Iz_Nr_dot))/Ix_Kp_dot,0,0,0,(2*B*Ts*e2*e3)/Ix_Kp_dot+(2*B*Ts*e1*n)/Ix_Kp_dot,(Ts*p)/Ix_Kp_dot,0,(Ts*p*abs(p))/Ix_Kp_dot,0,0,0,0,0,0,0,0,0,-(Ts*(f1*ly1-f2*ly2+f6*lz6))/Ix_Kp_dot^2-(Ts*p*(Kp+Kp_abs_p*abs(p)))/Ix_Kp_dot^2-(Ts*q*r*(Iy_Mq_dot-Iz_Nr_dot))/Ix_Kp_dot^2-(2*B*Ts*e2*e3*zb)/Ix_Kp_dot^2-(2*B*Ts*e1*n*zb)/Ix_Kp_dot^2,(Ts*q*r)/Ix_Kp_dot,-(Ts*q*r)/Ix_Kp_dot;
(2*B*Ts*e2*zb)/Iy_Mq_dot,-(2*B*Ts*e3*zb)/Iy_Mq_dot,(2*B*Ts*n*zb)/Iy_Mq_dot,-(2*B*Ts*e1*zb)/Iy_Mq_dot,-(Ts*r*(Ix_Kp_dot-Iz_Nr_dot))/Iy_Mq_dot,(Ts*(Mq+Mq_abs_q*abs(q)))/Iy_Mq_dot+(Mq_abs_q*Ts*q*sign(q))/Iy_Mq_dot+1,-(Ts*p*(Ix_Kp_dot-Iz_Nr_dot))/Iy_Mq_dot,0,0,0,(2*B*Ts*e2*n)/Iy_Mq_dot-(2*B*Ts*e1*e3)/Iy_Mq_dot,0,0,0,(Ts*q)/Iy_Mq_dot,0,(Ts*q*abs(q))/Iy_Mq_dot,0,0,0,0,0,0,-(Ts*p*r)/Iy_Mq_dot,(Ts*p*r*(Ix_Kp_dot-Iz_Nr_dot))/Iy_Mq_dot^2-(Ts*q*(Mq+Mq_abs_q*abs(q)))/Iy_Mq_dot^2-(Ts*(f1*lx1+f2*lx2-f5*lx5))/Iy_Mq_dot^2+(2*B*Ts*e1*e3*zb)/Iy_Mq_dot^2-(2*B*Ts*e2*n*zb)/Iy_Mq_dot^2,(Ts*p*r)/Iy_Mq_dot;
0,0,0,0,(Ts*q*(Ix_Kp_dot-Iy_Mq_dot))/Iz_Nr_dot,(Ts*p*(Ix_Kp_dot-Iy_Mq_dot))/Iz_Nr_dot,(Ts*(Nr+Nr_abs_r*abs(r)))/Iz_Nr_dot+(Nr_abs_r*Ts*r*sign(r))/Iz_Nr_dot+1,0,0,0,0,0,0,0,0,0,0,(Ts*r)/Iz_Nr_dot,0,(Ts*r*abs(r))/Iz_Nr_dot,0,0,0,(Ts*p*q)/Iz_Nr_dot,-(Ts*p*q)/Iz_Nr_dot,-(Ts*(f3*ly3-f4*ly4))/Iz_Nr_dot^2-(Ts*r*(Nr+Nr_abs_r*abs(r)))/Iz_Nr_dot^2-(Ts*p*q*(Ix_Kp_dot-Iy_Mq_dot))/Iz_Nr_dot^2;
0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0;
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1];
end