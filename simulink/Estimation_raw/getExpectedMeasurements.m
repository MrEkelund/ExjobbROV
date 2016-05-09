function h = getExpectedMeasurements(state,g,mag_n,mag_e,mag_d)
%extract states
n=state(1);e1=state(2);e2=state(3);e3=state(4);
p=state(5);q=state(6);r=state(7);
bias_p=state(8);bias_q=state(9);bias_r=state(10);

%returnexpectedmeasurementsh
h=[...
    p+bias_p;
    q+bias_q;
    r+bias_r;
    (2*g)*n*e2+(-2*g)*e1*e3;
    (-2*g)*n*e1+(-2*g)*e2*e3;
    2*g*e1^2+2*g*e2^2-g;
    (-2*mag_d)*n*e2+(2*mag_d)*e1*e3+(-2*(mag_e^2+mag_n^2)^(1/2))*e2^2+(-2*(mag_e^2+mag_n^2)^(1/2))*e3^2+(mag_e^2+mag_n^2)^(1/2);
    (2*mag_d)*n*e1+(-2*(mag_e^2+mag_n^2)^(1/2))*n*e3+(2*(mag_e^2+mag_n^2)^(1/2))*e1*e2+(2*mag_d)*e2*e3;
    (2*(mag_e^2+mag_n^2)^(1/2))*n*e2+(-2*mag_d)*e1^2+(2*(mag_e^2+mag_n^2)^(1/2))*e1*e3+(-2*mag_d)*e2^2+mag_d];
end