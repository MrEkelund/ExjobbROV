function [ compensated_acc_data ] = removeGravity( roll,pitch,yaw, acc_data)
    %Removes gravity from the acceleration data
    sfi = sind(roll);
    cfi = cosd(roll);
    spsi = sind(yaw);
    cpsi = cosd(yaw);
    stheta = sind(pitch);
    ctheta = cosd(pitch);
    
    compensated_acc_data = zeros(size(acc_data));
    for i=1:size(acc_data,1)
    rotmatrix = [ ctheta(i).*cpsi(i), ctheta(i).*spsi(i), -sfi(i);
        sfi(i).*stheta(i).*cpsi(i) - cfi(i).*spsi(i), sfi(i).*stheta(i).*spsi(i) + cfi(i).*cpsi(i), sfi(i).*ctheta(i);
        cfi(i).*stheta(i).*cpsi(i) + sfi(i).*spsi(i), cfi(i).*stheta(i).*spsi(i) - sfi(i).*spsi(i), cfi(i).*ctheta(i)];
    
    g = [0;0;9.80];
    % Gravity projected in the body fixed frame
    acc = rotmatrix\g;

    % Removed gravity from the acceleration    
    compensated_acc_data(i,:) = acc_data(i,:) + acc.';
    end
end

