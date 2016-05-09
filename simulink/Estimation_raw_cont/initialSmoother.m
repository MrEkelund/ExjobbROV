function [smooth, forward] = initialSmoother(Ts,measurements, mag)    

mag_n = mag(1);
mag_e = mag(2);
mag_d = mag(3);
P = blkdiag(1*eye(7));
Q = blkdiag(0.00000001*eye(7));
R = blkdiag(0.01*eye(3),0.0001*eye(3),0.001*eye(3));
g = 9.8174;
state = zeros(7,size(measurements,2));
state(:,1) = [1/sqrt(2) 1/sqrt(2) 0 0 0 0 0];
%state(:,1) = [1 0 0 0 0 0 0];
j = 1;
statemeas = zeros(7,size(measurements,2));
statetime = zeros(7,size(measurements,2));
Pmeas = zeros(7,7,length(measurements));
Ptime = zeros(7,7,length(measurements));
for i=1:length(measurements)
    
    %measurement update
    H = getMeasurementJacobian(state(:,j),g, mag_n, mag_e, mag_d);
    h = getExpectedMeasurements(state(:,j),g, mag_n, mag_e, mag_d);
    state(:,j+1) = normQuaternions(state(:,j)+(P*H.'/(H*P*H.'+ R)*(measurements(:,i) - h)));
    P = P - P*H.'/(H*P*H.'+ R)*(H*P);
    P = P/2+P.'/2;
    statemeas(:,i) = state(:,j+1);
    Pmeas(:,:,i) = P;
    j=j+1;
    
    % Time update
    F = getSystemJacobian(Ts,state(:,j));
    Gv = getGvMatrix(Ts,state(:,j));
    state(:,j+1) = normQuaternions(timeStep(Ts,state(:,j)));
    P = F*P*F.' + Q;%Gv*Gv
    P = P/2+P.'/2;
    statetime(:,i) = state(:,j+1);
    Ptime(:,:,i) = P;
    
    j=j+1;
end

forward = statemeas;

statesmooth =  zeros(7, size(measurements,2));
statesmooth(:,end) = statemeas(:,end);
Psmooth =  zeros(7,7,length(measurements));
Psmooth(:,:,end) = Pmeas(:,:,end);
for k=length(measurements):-1:2 % length(measurements) -1
    F = getSystemJacobian(Ts,statemeas(:,k-1));
    J = Pmeas(:,:,k-1)*transpose(F)/Ptime(:,:,k-1);
    statesmooth(:,k-1) = normQuaternions(statemeas(:,k-1) + J*(statesmooth(:,k)-statetime(:,k-1)));
    Psmooth(:,:,k-1) = Pmeas(:,:,k-1) + J*(Psmooth(:,:,k) - Ptime(:,:,k-1))*transpose(J);
    Psmooth(:,:,k-1) = Psmooth(:,:,k-1)/2+Psmooth(:,:,k-1).'/2;
end

smooth = statesmooth;
end