syms Ts n e1 e2 e3 p q r f1 f2 f3 f4 f5 f6 a1 a2 a3 a4 a5 a6 a7 b1 b2 b3 b4...
    b5 b6 b7 c1 c2 c3 c4 c5 g mag_n mag_e mag_d v1 v2 v3
nu = [p;q;r];
eta = [n;e1;e2;e3];

RQ =...
    [1 - 2*(e2^2 + e3^2), 2*(e1*e2 - e3*n), 2*(e1*e3 + e2*n);
     2*(e1*e2 + e3*n),  1-2*(e1^2 + e3^2),2*(e2*e3-e1*n);
     2*(e1*e3 - e2*n),  2*(e2*e3 + e1*n), 1-2*(e1^2 + e2^2)];
 
eta_dot=[ -(e1*p)/2 - (e2*q)/2 - (e3*r)/2;
   (e2*r)/2 - (e3*q)/2 + (n*p)/2; 
   (e3*p)/2 - (e1*r)/2 + (n*q)/2;
   (e1*q)/2 - (e2*p)/2 + (n*r)/2];


nu_dot= [...
    (p*(a1+a2*abs(p)) + a3*q*r +a4*f1 + a5*f2 + a6*f6 + a7*(2*e2*e3 + 2*e1*n));
    (q*(b1+b2*abs(q)) + b3*r*p +b4*f1 + b5*f2 + b6*f5 + b7*(2*e1*e3 - 2*e2*n));
    (r*(c1+c2*abs(r)) + c3*p*q +c4*f3 + c5*f4)];
 
nu_k_1 = nu + Ts*nu_dot
%nu_k_1 = collect(nu_k_1,[p q r])
eta_k_1=eta+Ts*eta_dot;
eta_k_1 = collect(eta_k_1,[p q r n e1 e2 e3])

 state = [eta; nu; a1;a2;a3;a4;a5;a6;a7;b1;b2;b3;b4;b5;b6;b7;c1;c2;c3;c4;c5];
 f = [eta_k_1;nu_k_1;state(8:end)] 
 
 f = collect(f,[p q r n e1 e2 e3]);

 for i=1:length(f)
    for j=1:length(state)
        F(i,j) = diff(f(i),state(j));
    end
 end

acc_meas = transpose(RQ)*([0; 0; -g]);
gyro_meas = [p ; q ; r ];
mag_global=[sqrt(mag_n^2 + mag_e^2);0;mag_d]; % could change to mx 0 mz and use bjord =mz bjord sin(θdip)dˆ+ bjord cos(θdip)nˆ
mag_meas = transpose(RQ)*mag_global;

h = [gyro_meas;acc_meas;mag_meas];

h = collect(h, [p q r n e1 e2 e3]);

for i=1:length(h)
    for j=1:length(state);
        H(i,j) = diff(h(i),state(j));
    end
end
%%
 T_eta =1/2*...
     [-e1 ,-e2 -e3;
     n -e3 e2;
     e3 n -e1;
     -e2 e1 n];
noise = [v1;v2;v3];
coloured_noise_nu = noise;
coloured_noise_eta = T_eta*Ts/2*noise;
coloured_noise = [coloured_noise_eta;coloured_noise_nu];
for i=1:7
    for j=1:3
       Gv_discrete(i,j)=Ts*diff(coloured_noise(i),noise(j));
    end
end
Gv_discrete
 %Gv =...
 %    [Ts^3/2*T_eta;Ts*eye(3)];
 Gv_discrete=blkdiag(Gv_discrete,Ts*eye(19));

 