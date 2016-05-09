function state = normQuaternions(state)
state(1:4) = state(1:4)./norm(state(1:4));
%state = state*sign(state(1));
end