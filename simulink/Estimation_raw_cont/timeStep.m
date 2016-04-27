function new_state=timeStep(delta_t,state)
%extractstates
quat_0=state(1);quat_1=state(2);quat_2=state(3);quat_3=state(4);p=state(5);
q=state(6);r=state(7);

new_state=[...
 quat_0 - (delta_t*p*quat_1)/2 - (delta_t*q*quat_2)/2 - (delta_t*quat_3*r)/2
 quat_1 + (delta_t*p*quat_0)/2 - (delta_t*q*quat_3)/2 + (delta_t*quat_2*r)/2
 quat_2 + (delta_t*p*quat_3)/2 + (delta_t*q*quat_0)/2 - (delta_t*quat_1*r)/2
 quat_3 - (delta_t*p*quat_2)/2 + (delta_t*q*quat_1)/2 + (delta_t*quat_0*r)/2
                                                                           p
                                                                           q
                                                                           r];



end