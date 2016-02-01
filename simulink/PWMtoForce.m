function [force] = PWMtoForce(pwm_in)
%Converts PWm signal in us to force in newtons
% several doifferent sets of coefficients are supplied
% Data used for poyfit comes from BlueROV extra folder.
% p = [-6.2137   -1.9239   15.5456    3.7720  -14.4402   -2.7320    6.6768
% 1.2707    0.5515   -0.0028];
p = [-1.3536   -0.4257    2.5444    0.8196    0.9102    0.0111];
% center pwm signal and scale to 1
pwm_in= (pwm_in - 1500)/400;
force = 9.82*polyval(p,pwm_in);
end

