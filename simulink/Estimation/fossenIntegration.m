function [ filter_data  states] = fossenIntegration( acc_data, roll, pitch, yaw, depth, k1, k2, k3, time_vector)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

gn = [0 0 9.80665]';

sfi = sind(roll);
cfi = cosd(roll);
spsi = sind(yaw);
cpsi = cosd(yaw);
stheta = sind(pitch);
ctheta = cosd(pitch);

filter_data = zeros(size(acc_data,1)-1,size(acc_data,2));
states = zeros(size(acc_data,1)-1,9);
y = [0 0 depth(1)]';
v = [0 0 0]';
Pos = [0 0 0]';
acc_bias = [0.1 0.1 0.1]';
for i=1:size(acc_data,1)-1;
    
    Ts = time_vector(i+1) - time_vector(i);
    acc = acc_data(i,:).';
   
    
rotmatrix = ([...
    cpsi(i)*ctheta(i), -spsi(i)*cfi(i)+cpsi(i)*stheta(i)*sfi(i), spsi(i)*sfi(i)+cpsi(i)*cfi(i)*stheta(i);
    spsi(i)*ctheta(i), cpsi(i)*cfi(i)+sfi(i)*stheta(i)*spsi(i), -cpsi(i)*sfi(i)+stheta(i)*spsi(i)*cfi(i);
    -stheta(i), ctheta(i)*sfi(i), ctheta(i)*cfi(i)].');
    
    
    error = ( y - Pos);
    
    Pos = Pos + Ts*(v + k1*error);
    v = v + Ts*(rotmatrix*(acc - acc_bias) - gn + k2*error);
    acc_bias = acc_bias + Ts*(k3*(rotmatrix.')*error);
    y = [0;0;depth(i)];
    filter_data(i,:) = v';
    states(i,:) = [Pos', v', acc_bias'];
end

end
% r= 10; [a b] = fossenIntegration(repmat([0 0 9],[r 1]), repmat([0], [r ,1]), repmat([0], [r ,1]), repmat([0], [r ,1]), repmat([0], [r ,1]),[0 0 1], [0 0 0.01], [0 0 0.01], [1:r]')

