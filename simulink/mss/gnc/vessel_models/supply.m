function xdot = supply(x,tau)
% xdot = supply(x,tau) returns the speed the time derivative xdot = A*x + B*tau
% of the state vector: x = [ x y psi u v r]'  for a supply vessel length L = 76 m.
%
% The model is only valid around zero speed (dynamic positioning).
%
% u     = surge velocity                    (m/s)     
% v     = sway velocity                     (m/s)
% r     = yaw velocity                      (rad/s)
% x     = position in x-direction           (m)
% y     = position in y-direction           (m)
% psi   = yaw angle                         (rad)
%
% tau   = [X, Y, N]' control force/moment
%
% Reference : Fossen, T. I., S. I. Sagatun and A. J. S�rensen (1996)
%             Identification of Dynamically Positioned Ships
%             Journal of Control Engineering Practice CEP-4(3):369-376
%
% Author:     Thor I. Fossen
% Date:       12 July 2002
% Revisions:  24 February 2994, included missing mass scaling in the Bis transformation
% ________________________________________________________________
%
% MSS GNC is a Matlab toolbox for guidance, navigation and control.
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

% Normalization variables
L    =  76.2;           % length of ship (m)
g    =  9.8;            % acceleration of gravity (m/s^2)
mass = 6000e3;          % mass (kg)

T    = diag([1 1 L]);
Tinv = diag([1 1 1/L]);

% Model matricses
Mbis = [1.1274         0          0
             0    1.8902    -0.0744
             0   -0.0744     0.1278];

Dbis = [0.0358        0        0
             0        0.1183  -0.0124
             0       -0.0041   0.0308];
 
 
 % Check of input and state dimensions
 if (length(x)  ~= 6),error('x-vector must have dimension 6 !');end
 if (length(tau) ~= 3),error('u-vector must have dimension 3 !');end
 
 M = (mass*Tinv^2)*(T*Mbis*Tinv);
 D = (mass*Tinv^2)*(sqrt(g/L)*T*Dbis*Tinv);
 
 A = [ zeros(3,3) eye(3)
     zeros(3,3) -inv(M)*D ];
 
 B = [zeros(3,3); inv(M) ];
 
 % Dimensional state derivative
 xdot = A*x + B*tau;
 
