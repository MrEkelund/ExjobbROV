function Gv=getGvMatrix(delta_t,state)
%extractstates
quat_0=state(1);quat_1=state(2);quat_2=state(3);quat_3=state(4);p=state(5);
q=state(6);r=state(7);


Gv=[...
 -(delta_t^2*quat_1)/2, -(delta_t^2*quat_2)/2, -(delta_t^2*quat_3)/2
  (delta_t^2*quat_0)/2, -(delta_t^2*quat_3)/2,  (delta_t^2*quat_2)/2
  (delta_t^2*quat_3)/2,  (delta_t^2*quat_0)/2, -(delta_t^2*quat_1)/2
 -(delta_t^2*quat_2)/2,  (delta_t^2*quat_1)/2,  (delta_t^2*quat_0)/2
               delta_t,                     0,                     0
                     0,               delta_t,                     0
                     0,                     0,               delta_t];




end