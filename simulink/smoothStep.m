function [ traj ] = smoothStep(q0, qf, ts, t, tf, V)

if ((qf - q0)/(tf - ts) >  V | V > 2*(qf - q0)/(tf - ts))
    disp(sprintf('V must be in %f < V <= %f', (qf - q0)/(tf - ts),2*(qf - q0)/(tf - ts)))
end

tb = (q0 - qf + V*(tf - ts))/V;
alfa = V/tb;
if ( t < ts)
    traj = q0;
elseif (0 <= (t - ts) & (t - ts) <= tb)
    traj = q0 + alfa*(t - ts)^2/2;
elseif (tb < (t - ts) & (t - ts) <= (tf - ts) - tb)
    traj = (qf + q0 - V*(tf - ts))/2 + V*(t - ts);
elseif (tf - ts - tb < (t - ts) & (t - ts) <= (tf - ts))
    traj = qf - alfa*(tf - ts)^2/2 + alfa*(tf - ts)*(t - ts) - alfa*(t - ts)^2/2;
else
    traj = qf;
end

end


