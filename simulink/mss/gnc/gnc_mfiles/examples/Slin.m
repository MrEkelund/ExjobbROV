function Pyy = Slin(lambda,w)
% Pyy = Slin(lambda,w) 2nd-order linear power spectracl density (PSD) function
%
%   w       = wave spectrum frequency (rad/s)
%   lambda  = relative damping factor
%
%   See ExLinspec.m
%
% Author:   Thor I. Fossen
% Date:     15th August 2001
% Revisions: 
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

global sigma wo  

Pyy = 4*(lambda*wo*sigma)^2*w.^2 ./ ( (wo^2-w.^2).^2 + 4*(lambda*wo.*w).^2 );

