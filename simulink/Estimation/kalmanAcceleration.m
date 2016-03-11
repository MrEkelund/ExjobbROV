function [ filter_data CP] = kalmanAcceleration(x0, p0, acc_data)
    %UNTITLED2 Summary of this function goes here
    %   Detailed explanation goes here
    
    H = [1 0 0 1 0 0;
         0 1 0 0 1 0;
         0 0 1 0 0 1];
     
     
     F = eye(6);
     
     Gv = [1 0 0 1 0 0;
           0 1 0 0 1 0;
           0 0 1 0 0 1].';
     
     R = eye(3);
     
     Q = diag([100 100 100]);
     
     x = x0;
     P = p0;
     filter_data = zeros(size(acc_data));
     for i=1:size(acc_data);
         % Measurement update
         y = acc_data(i,:)';
         x = x + P*(H.')*inv(H*P*(H.')+R)*(y-H*x);
         P = P - P*(H.')*inv(H*P*(H.')+R)*H*P;
         % Time update
         x = F*x;
         CP(i,:) = x';
         filter_data(i,:) = x(1:3)';
         P = F*P*(F.') + Gv*Q*(Gv.');
     end
end

