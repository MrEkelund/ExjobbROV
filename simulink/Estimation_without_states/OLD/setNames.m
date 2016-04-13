function [ data ] = setNames(outputs, inputs, data)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here'

input_name = {'Thruster1'; 'Thruster2'; 'Thruster3';
    'Thurster4'; 'Thruster5'; 'Thruster6'};
input_unit = {'%'; '%'; '%'; '%'; '%';'%'};
output_name = {'u';'v';'w'; 'p'; 'q'; 'r';'fi';'theta'};
output_unit = {'m/s'; 'm/s'; 'm/s';'rad/s'; 'rad/s'; 'rad/s';'rad';'rad'};

data.InputName =  input_name([inputs]);
data.InputUnit =  input_unit([inputs]);

data.OutputName = output_name([outputs]);
data.OutputUnit = output_unit([outputs]);

end

