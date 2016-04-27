function initial_state = initialEkf(Ts,measurements,mag_n,mag_e,mag_d)    

P = blkdiag(100*eye(7));
Q = blkdiag(1000*eye(3));
R = blkdiag(0.001*eye(3),0.001*eye(3),0.0001*eye(3));
g = 9.82;
state = zeros(7,size(measurements,2));
state(:,1) = [1 0 0 0 0 0 0];
j = 1;
for i=1:length(measurements)
        %measurement update
        H = getMeasurementJacobian(state(:,j),g,mag_n,mag_e,mag_d);
        h = getExpectedMeasurements(state(:,j),g,mag_n,mag_e,mag_d);
        state(:,j+1) = normQuaternions(state(:,j)+(P*H.'/(H*P*H.'+ R)*(measurements(:,i) - h)));
        P = P - P*H.'/(H*P*H.'+ R)*(H*P);
        j=j+1;
        
        % Time update
        F = getSystemJacobian(Ts,state(:,j));
        Gv = getGvMatrix(Ts,state(:,j));
        state(:,j+1) = normQuaternions(timeStep(Ts,state(:,j)));
        P = F*P*F.' + Gv*Q*Gv.';
        j=j+1;
end
initial_state = [state(:,end).', mag_n, mag_e, mag_d];
end