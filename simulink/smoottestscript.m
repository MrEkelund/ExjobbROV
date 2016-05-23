q0 = 0;
qf = 1;
ts = 10;
t = 0:0.01:20;
tf = 12;
V = 1;

traj = zeros(length(t),1);
for i = 1:length(t)
    traj(i) = smoothStep(q0, qf, ts, t(i), tf, V);
end
plot(t, traj)