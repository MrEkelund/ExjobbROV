% Hydrodynamic processing of ShipX S175 data
vessel = veres2vessel('input');
vesselABC = vessel2ss(vessel);

% plot
plotABC(vessel,'A')
plotABC(vessel,'B')
plotTF(vessel,'motion','rads',1)
plotTF(vessel,'force','rads',1)
plotWD(vessel,'rads',1)

% display main data
display(vessel.main);




