function new_state=timeStepBlackBox(Ts,state,tau)
%extractstates
n=state(1);e1=state(2);e2=state(3);e3=state(4);p=state(5);
q=state(6);r=state(7);a1=state(8);a2=state(9);a3=state(10);
a4=state(11);a5=state(12);a6=state(13);a7=state(14);
b1=state(15);b2=state(16);b3=state(17);b4=state(18);
b5=state(19);b6=state(20);b7=state(21);c1=state(22);
c2=state(23);c3=state(24);c4=state(25);c5=state(26);


%extractforcesfromthrusters
f1=tau(1);
f2=tau(2);
f3=tau(3);
f4=tau(4);
f5=tau(5);
f6=tau(6);


new_state=[...
 
                                                             (-Ts/2)*p*e1 + (-Ts/2)*q*e2 + (-Ts/2)*r*e3 + n;
                                                               (Ts/2)*p*n + (-Ts/2)*q*e3 + (Ts/2)*r*e2 + e1;
                                                               (Ts/2)*p*e3 + (Ts/2)*q*n + (-Ts/2)*r*e1 + e2;
                                                               (-Ts/2)*p*e2 + (Ts/2)*q*e1 + (Ts/2)*r*n + e3;
  (Ts*(a1 + a2*abs(p)) + 1)*p + (Ts*a3)*q*r + (2*Ts*a7)*n*e1 + (2*Ts*a7)*e2*e3 + Ts*(a4*f1 + a5*f2 + a6*f6);
 (Ts*b3)*p*r + (Ts*(b1 + b2*abs(q)) + 1)*q + (-2*Ts*b7)*n*e2 + (2*Ts*b7)*e1*e3 + Ts*(b4*f1 + b5*f2 + b6*f5);
                                             (Ts*c3)*p*q + (Ts*(c1 + c2*abs(r)) + 1)*r + Ts*(c4*f3 + c5*f4);
                                                                                                         a1;
                                                                                                         a2;
                                                                                                         a3;
                                                                                                         a4;
                                                                                                         a5;
                                                                                                         a6;
                                                                                                         a7;
                                                                                                         b1;
                                                                                                         b2;
                                                                                                         b3;
                                                                                                         b4;
                                                                                                         b5;
                                                                                                         b6;
                                                                                                         b7;
                                                                                                         c1;
                                                                                                         c2;
                                                                                                         c3;
                                                                                                         c4;
                                                                                                         c5];




end