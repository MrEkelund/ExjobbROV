function [ vel_data ] = integrateAcc( acc_data, time_vector )
    %Integrate something
    %   Assumes that the first two samples of the velocity is zero
    
    vel_data = zeros(size(acc_data));
    
    for i=1:size(acc_data,1)-1
        Ts = time_vector(i+1) - time_vector(i);
        vel_data(i+1,:) = vel_data(i,:)+Ts*acc_data(i,:);
    end
    
    
    
end

