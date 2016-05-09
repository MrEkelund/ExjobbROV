function H = getMeasurementJacobian(state,g, mag_n, mag_e, mag_d)
%extract states
quat_0=state(1);quat_1=state(2);quat_2=state(3);quat_3=state(4);p=state(5);
q=state(6);r=state(7);

% return jacobian of measurement equation
H=[...
    0,                                                   0,                                                     0,                                                   0, 1, 0, 0
    0,                                                   0,                                                     0,                                                   0, 0, 1, 0
    0,                                                   0,                                                     0,                                                   0, 0, 0, 1
    2*g*quat_2,                                         -2*g*quat_3,                                            2*g*quat_0,                                         -2*g*quat_1, 0, 0, 0
    -2*g*quat_1,                                         -2*g*quat_0,                                           -2*g*quat_3,                                         -2*g*quat_2, 0, 0, 0
    0,                                          4*g*quat_1,                                            4*g*quat_2,                                                   0, 0, 0, 0
    -2*mag_d*quat_2,                                      2*mag_d*quat_3, - 4*quat_2*(mag_e^2 + mag_n^2)^(1/2) - 2*mag_d*quat_0, 2*mag_d*quat_1 - 4*quat_3*(mag_e^2 + mag_n^2)^(1/2), 0, 0, 0
    2*mag_d*quat_1 - 2*quat_3*(mag_e^2 + mag_n^2)^(1/2), 2*quat_2*(mag_e^2 + mag_n^2)^(1/2) + 2*mag_d*quat_0,   2*quat_1*(mag_e^2 + mag_n^2)^(1/2) + 2*mag_d*quat_3, 2*mag_d*quat_2 - 2*quat_0*(mag_e^2 + mag_n^2)^(1/2), 0, 0, 0
    2*quat_2*(mag_e^2 + mag_n^2)^(1/2), 2*quat_3*(mag_e^2 + mag_n^2)^(1/2) - 4*mag_d*quat_1,   2*quat_0*(mag_e^2 + mag_n^2)^(1/2) - 4*mag_d*quat_2,                  2*quat_1*(mag_e^2 + mag_n^2)^(1/2), 0, 0, 0];
end
