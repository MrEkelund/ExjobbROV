% Hydrodynamic processing of WAMIT tanker data
vessel = wamit2vessel('tanker',10,246,46);
vesselABC = vessel2ss(vessel);

% plot
plotABC(vessel,'A')
plotABC(vessel,'B')
plotTF(vessel,'motion','rads',1)
plotTF(vessel,'force','rads',1)
plotWD(vessel,'rads',1)

% display main data
display(vessel.main);



