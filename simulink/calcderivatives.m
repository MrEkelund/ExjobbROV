syms yaw pitch roll yaw_rate pitch_rate roll_rate w x y z rotmatrix acc_meas a_body_x a_body_y a_body_z g a_body
a_body = [ a_body_x; a_body_y; a_body_z];
rotmatrix = [2*w^2+2*x^2-1, 2*x*y-2*w*z, 2*x*z+2*w*y; 
    2*x*y+2*w*z, 2*w^2+2*y^2-1, 2*x*z-2*w*x;
    2*x*z-2*w*y, 2*y*z+2*w*x, 2*w^2+2*z^2-1];
% measurement equation for acceleration
acc_meas = transpose(rotmatrix)*([0; 0; g] + a_body);

% measurement eequation for 
