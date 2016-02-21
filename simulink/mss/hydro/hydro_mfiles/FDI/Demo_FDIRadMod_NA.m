
%Demo: example use of frequency-domain identification of radiation models
%of marine strucutres based on hydrodynamic data without using the
%infinite-frequency added mass.
%
% Created by Tristan Perez (tristan.perez@ntnu.no)
% Date 2009/9/1, Trondheim, Norway.
% Revision:
% Copyright (C) 2009 Thor I. Fossen and Tristan Perez
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

clear all

%Load data of the fpso (structure vessel, 6DOF)
load fpso.mat

%Extract the data from the vessel structure

Dof = [3,3]; %Use coupling 3-3 heave-heave
Nf = length(vessel.freqs);
W=vessel.freqs(1:Nf-1)';
Ainf=vessel.A(Dof(1),Dof(2),Nf);

A = reshape(vessel.A(Dof(1),Dof(2),1:Nf-1),1,length(W))';
B = reshape(vessel.B(Dof(1),Dof(2),1:Nf-1),1,length(W))';

%Define the structure with identification algorithm options
FDIopt.OrdMax     = 20;
FDIopt.AinfFlag   = 0;
FDIopt.Method     = 2;
FDIopt.Iterations = 20;
FDIopt.LogLin     = 1;
FDIopt.wsFactor   = 0.1;  
FDIopt.wminFactor = 0.1;
FDIopt.wmaxFactor = 5;

%call idenfication routine
[Krad,Ainf_hat]=FDIRadMod(W,A,0,B,FDIopt,Dof);


