function h = getExpectedMeasurements(state,g,mag_n,mag_e,mag_d)
%extract states
n=state(1);e1=state(2);e2=state(3);e3=state(4);p=state(5);
q=state(6);r=state(7);

% return expected measurements h
h=[...
p;
q;
r;
-g*(2*e1*e3-2*e2*n);
-g*(2*e2*e3+2*e1*n);
g*(2*e1^2+2*e2^2-1);
mag_d*(2*e1*e3-2*e2*n)-(mag_e^2+mag_n^2)^(1/2)*(2*e2^2+2*e3^2-1);
(2*e1*e2-2*e3*n)*(mag_e^2+mag_n^2)^(1/2)+mag_d*(2*e2*e3+2*e1*n);
(2*e1*e3+2*e2*n)*(mag_e^2+mag_n^2)^(1/2)-mag_d*(2*e1^2+2*e2^2-1)];
end