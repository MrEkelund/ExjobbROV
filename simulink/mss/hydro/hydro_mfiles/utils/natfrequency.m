function w_n = natfrequency(vessel,dof,w_0,speed,LCF)
% NATFREQUENCY (MSS Hydro)
%
% w_n = natfrequency(vessel,dof,w_0,speed,LCF) computes the natural
% frequency in heave, roll, and pitch w.r.t. the Centre of Flotation (CF), i.e.
% the centroid of the water plane area.  For small angles, a starboard-port
% symmetrical vessel the decoupled pitching and rolling motions will be
% about the point [LFC, 0, 0] in CO where CO is the b-frame coordinate
% origin midtships on the centre line (Lpp/2, B/2, WL) and LCF denotes the
% longitudinal centre of floatation. IF LCF is omitted it is assumed that
% CF = CO. 
%
% For a linear system, the harmonic motions in 6 DOF satisfy
%
%    -[M_RB + A(w) ]*w^2 + C = 0
%
% which reduces to
%
%    w_i = sqrt(C_ii/(M_RB_ii + A_ii(w_i))
%
% for the 1 DOF case. These are implicit equations f(x)= 0 that are solved
% using fsolve.m
%
% 6 DOF Example: 
% >> w_n = natfrequency(vessel,-1,0.5,1)    
%
% 1 DOF Examples:
% >> w_n = natfrequency(vessel,3,0.5,1,LCF)
% >> w_n = natfrequency(vessel,4,0.5,1)
%
% Inputs:
%    vessel    MSS vessel data (computed in CO)
%    dof       degree of freedom (3,4, or 5). Use -1 for 6 DOF coupled data
%    w_0       initial natural frequency (typical 0.5)
%    speed     speed index 1,2,3...
%    LCF       optionally - longitudinal distance to CF from CO
%              (x-coordinate of the water plane centroid)
%
% Outputs:
%    w_n       natural frequency
%
% Author:    Thor I. Fossen
% Date:      2006-03-26
% Revisions: 2008-01-23   R1.0 (only for 1 DOF)
%            2008-10-28   Updated to solve 6 DOF coupled motions
% _________________________________________________________________________
%
% MSS HYDRO is a Matlab toolbox for guidance, navigation and control.
% The toolbox is part of the Marine Systems Simulator (MSS).
%
% Copyright (C) 2008 Thor I. Fossen and Tristan Perez
%
% This program is free software: you can redistribute it and/or modify
% it under the terms of the GNU General Public License as published by
% the Free Software Foundation, either version 3 of the License, or
% (at your option) any later version.
%
% This program is distributed in the hope that it will be useful, but
% WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU General Public License for more details.
%
% You should have received a copy of the GNU General Public License
% along with this program.  If not, see <http://www.gnu.org/licenses/>.
%
% E-mail: contact@marinecontrol.org
% URL:    <http://www.marinecontrol.org>

%--------------------------------------------------------------------------
%% Solve frequency-dependent equation for natural frequency
%--------------------------------------------------------------------------
w = vessel.freqs;
N = length(w);

if dof ~= -1  % 1 DOF
    
    if nargin == 4
        LCF = 0;
    end
    
    % vector from GLOBAL COORD to CF:
    r = [LCF 0 0];
    
    if dof == 3 | dof == 4 | dof == 5
        
        % mass and spring data in CF
        Hinv   = inv(Hmtrx(r));
        MRB_CF = Hinv'*vessel.MRB*Hinv;
        G_CF   = Hinv'*reshape(vessel.C(:,:,N,speed),6,6)*Hinv;
        
        for k=1:N
            Aii(:,:,k) = Hinv'*reshape(vessel.A(:,:,k,1),6,6,1)*Hinv;
        end
        Aii_CF = reshape(Aii(dof,dof,:),1,N);
        
        k = G_CF(dof,dof);
        m = MRB_CF(dof,dof) + Aii_CF;
        
        % solve w_n = sqrt(C/(M + A(w_n))
        finito = 0;
        
        while finito == 0
            
            if exist('fsolve')  % requires optimization toolbox
                % for debugging
                % [w_n,F_n,flag] = fsolve(@natfreq,w_0,optimset('TolFun',1e-10));
                [w_n,F_n,flag] = fsolve(@(x) natfreq(x,m,k,w),w_0,optimset('Display','off','TolFun',1e-10));
            else
                [w_n,F_n,flag]  = fzero(@(x) natfreq(x,m,k,w),w_0,optimset('Display','off','TolFun',1e-10));
            end
            
            if flag ~= 1,
                w_0 = w_0 + 0.1;
                disp(['Warning: natural frequency did not converge for dof = ', num2str(dof),...
                    ', increasing w_0 to ' num2str(w_0)]);
            else
                finito = 1;
            end
            
        end
        
        
        if flag ~= 1,
            disp(['Warning: natural frequency did not converge for dof = ', num2str(dof),...
                ', using w_n = 1 rad/s instead']);
            w_n = 1.0;
        end
        
    else
        
        disp('DOF must be 3, 4, or 5 corresponding to heave, roll, and pitch');
        disp('Use -1 for 6 DOF coupled data');        
        w_n = 0;
        return
        
    end
    
else  %  6 DOF (no spring in DOF 1,2,6)
    
    MRB = vessel.MRB;
    C   = reshape(vessel.C(:,:,:,1),6,6,N);
    A   = reshape(vessel.A(:,:,:,1),6,6,N);
    
    % Longitudinal modes
    for i=1:length(w)
        
       M = MRB + A(:,:,i);
       G = C(:,:,i);
       
       AA = inv(M)*G;
       AA = AA([3,5],[3,5]);
       lambda(:,i) = eig(AA);
       
    end
        
    if exist('fsolve')  % requires optimization toolbox
        [w_3,F_n,flag] = fsolve(@(x) eigs(x,lambda(1,:),w),w_0,optimset('Display','off','TolFun',1e-10));
        [w_5,F_n,flag] = fsolve(@(x) eigs(x,lambda(2,:),w),w_0,optimset('Display','off','TolFun',1e-10));
    else
        [w_3,F_n,flag] = fzero(@(x)  eigs(x,lambda(1,:),w),w_0,optimset('Display','off','TolFun',1e-10));
        [w_5,F_n,flag] = fzero(@(x)  eigs(x,lambda(2,:),w),w_0,optimset('Display','off','TolFun',1e-10));
    end
    
    % Lateral modes
    for i=1:length(w)
        
        M = MRB + A(:,:,i);
        G = C(:,:,i);
        
        AA = inv(M)*G;
        AA = AA([4],[4]);
        lambda(:,i) = eig(AA);
        
    end
    
    if exist('fsolve')  % requires optimization toolbox
        [w_4,F_n,flag] = fsolve(@(x) eigs(x,lambda(1,:),w),w_0,optimset('Display','off','TolFun',1e-10));
    else
        [w_4,F_n,flag] = fzero(@(x)  eigs(x,lambda(1,:),w),w_0,optimset('Display','off','TolFun',1e-10));
    end
    
    w_n = [w_3 w_4 w_5]';
    
end



%--------------------------------------------------------------------------
%% Function for fsolve
%--------------------------------------------------------------------------
function F = natfreq(x,m,k,w)
F = x - sqrt(k/interp1(w,m,x));

function F = eigs(x,lam,w)
F = x.^2 - interp1(w,lam,x);
        