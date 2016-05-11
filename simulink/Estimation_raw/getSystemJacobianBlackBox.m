function F = getSystemJacobianBlackBox(Ts,state,tau)
%extractstates
n=state(1);e1=state(2);e2=state(3);e3=state(4);p=state(5);
q=state(6);r=state(7);a1=state(8);a2=state(9);a3=state(10);
a4=state(11);a5=state(12);a6=state(13);a7=state(14);
b1=state(15);b2=state(16);b3=state(17);b4=state(18);
b5=state(19);b6=state(20);b7=state(21);c1=state(22);
c2=state(23);c3=state(24);c4=state(25);c5=state(26);
f1=tau(1);
f2=tau(2);
f3=tau(3);
f4=tau(4);
f5=tau(5);
f6=tau(6);


F=[...
           1,  -(Ts*p)/2,  -(Ts*q)/2,  -(Ts*r)/2,                                -(Ts*e1)/2,                                -(Ts*e2)/2,                                -(Ts*e3)/2,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
    (Ts*p)/2,          1,   (Ts*r)/2,  -(Ts*q)/2,                                  (Ts*n)/2,                                -(Ts*e3)/2,                                 (Ts*e2)/2,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
    (Ts*q)/2,  -(Ts*r)/2,          1,   (Ts*p)/2,                                 (Ts*e3)/2,                                  (Ts*n)/2,                                -(Ts*e1)/2,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
    (Ts*r)/2,   (Ts*q)/2,  -(Ts*p)/2,          1,                                -(Ts*e2)/2,                                 (Ts*e1)/2,                                  (Ts*n)/2,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
  2*Ts*a7*e1,  2*Ts*a7*n, 2*Ts*a7*e3, 2*Ts*a7*e2, Ts*(a1 + a2*abs(p)) + Ts*a2*p*sign(p) + 1,                                   Ts*a3*r,                                   Ts*a3*q, Ts*p, Ts*p*abs(p), Ts*q*r, Ts*f1, Ts*f2, Ts*f6, 2*Ts*e2*e3 + 2*Ts*e1*n,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
 -2*Ts*b7*e2, 2*Ts*b7*e3, -2*Ts*b7*n, 2*Ts*b7*e1,                                   Ts*b3*r, Ts*(b1 + b2*abs(q)) + Ts*b2*q*sign(q) + 1,                                   Ts*b3*p,    0,           0,      0,     0,     0,     0,                      0, Ts*q, Ts*q*abs(q), Ts*p*r, Ts*f1, Ts*f2, Ts*f5, 2*Ts*e1*e3 - 2*Ts*e2*n,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                   Ts*c3*q,                                   Ts*c3*p, Ts*(c1 + c2*abs(r)) + Ts*c2*r*sign(r) + 1,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0, Ts*r, Ts*r*abs(r), Ts*p*q, Ts*f3, Ts*f4;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    1,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           1,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      1,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     1,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     1,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     1,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      1,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      0,    1,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      0,    0,           1,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      1,     0,     0,     0,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     1,     0,     0,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     1,     0,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     1,                      0,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      1,    0,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    1,           0,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           1,      0,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      1,     0,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     1,     0;
           0,          0,          0,          0,                                         0,                                         0,                                         0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     0,     0,                      0,    0,           0,      0,     0,     1];



end