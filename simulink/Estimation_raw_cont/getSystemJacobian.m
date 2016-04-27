function F = getSystemJacobian(delta_t,state)
%extractstates
quat_0=state(1);quat_1=state(2);quat_2=state(3);quat_3=state(4);p=state(5);
q=state(6);r=state(7);

%new based on euler forward
F=[...
             1, -(delta_t*p)/2, -(delta_t*q)/2, -(delta_t*r)/2, -(delta_t*quat_1)/2, -(delta_t*quat_2)/2, -(delta_t*quat_3)/2
 (delta_t*p)/2,              1,  (delta_t*r)/2, -(delta_t*q)/2,  (delta_t*quat_0)/2, -(delta_t*quat_3)/2,  (delta_t*quat_2)/2
 (delta_t*q)/2, -(delta_t*r)/2,              1,  (delta_t*p)/2,  (delta_t*quat_3)/2,  (delta_t*quat_0)/2, -(delta_t*quat_1)/2
 (delta_t*r)/2,  (delta_t*q)/2, -(delta_t*p)/2,              1, -(delta_t*quat_2)/2,  (delta_t*quat_1)/2,  (delta_t*quat_0)/2
             0,              0,              0,              0,                   1,                   0,                   0
             0,              0,              0,              0,                   0,                   1,                   0
             0,              0,              0,              0,                   0,                   0,                   1];


end