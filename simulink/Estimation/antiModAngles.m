function [new_angle] = antiModAngles(angle)
%antiModAngles Removes bounds on angles from [-pi, pi] to [-inf,inf]

samples = size(angle,1);
num_angles = size(angle,2);
design = 0.7;
new_angle = zeros(size(angle));
new_angle(1,:) = angle(1,:);

for j = 1:num_angles
    offset = 0;
    for i = 1:samples-1
        if (angle(i,j) - angle(i+1,j)) >= 2*pi*design
            offset = offset + 2*pi;
        elseif(angle(i,j) - angle(i+1,j)) <= -2*pi*design
            offset = offset - 2*pi;
        end
        new_angle(i+1,j) = angle(i+1,j) + offset;
    end
end

% figure(1)
% subplot(3,1,1)
% plot(new_angle(:,1))
% subplot(3,1,2)
% plot(new_angle(:,2))
% subplot(3,1,3)
% plot(new_angle(:,3))
end


