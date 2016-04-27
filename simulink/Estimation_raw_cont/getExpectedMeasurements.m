function h = getExpectedMeasurements(state,g,mag_n,mag_e,mag_d)
%extract states
quat_0=state(1);quat_1=state(2);quat_2=state(3);quat_3=state(4);p=state(5);
q=state(6);r=state(7);

% return expected measurements h
h=[...   
p
q
r
g*(2*quat_0*quat_2 - 2*quat_1*quat_3)
-g*(2*quat_0*quat_1 + 2*quat_2*quat_3)
g*(2*quat_1^2 + 2*quat_2^2 - 1)
- (mag_e^2 + mag_n^2)^(1/2)*(2*quat_2^2 + 2*quat_3^2 - 1) - mag_d*(2*quat_0*quat_2 - 2*quat_1*quat_3)
mag_d*(2*quat_0*quat_1 + 2*quat_2*quat_3) - (2*quat_0*quat_3 - 2*quat_1*quat_2)*(mag_e^2 + mag_n^2)^(1/2)
(2*quat_0*quat_2 + 2*quat_1*quat_3)*(mag_e^2 + mag_n^2)^(1/2) - mag_d*(2*quat_1^2 + 2*quat_2^2 - 1)];
end