function [Parameters, Parameter_strings] = initROVParameters(  )
%initROVParameters Initalises the ROV's parameters
files = dir('parameters.mat');

if isempty(files)
    warning('No parameter file found. Using default values.');
    % Some constants
    m = 6.621;       % ROV mass[kg];
    g = 9.81744;   % Gravity[m/s^2]
    rho = 1000; % water density [kg/m^3]
    V = 0.012;       % Discplaced water volume [m^3]
    % Thruster placement from CO [m]
    lx1 = 0.16;
    ly1 = 0.11;
    ly2 = 0.11;
    lx2 = 0.16;
    ly3 = 0.11;
    lx5 = 0.2;
    ly4 = 0.11;
    lz6 = 0.11;

    % Parameters that will be estimated
%     zb = -0.05/2;
%     Kp = -0.5/2;
%     Kp_dot = -1/10;
%     Kp_abs_p = -1/10;
%     Mq = -0.5;
%     Mq_dot = -1/10;
%     Mq_abs_q = -1/10;
%     Nr = -0.5;
%     Nr_dot = -1/10;
%     Nr_abs_r = -1/10;
%     Ix = 0.5;
%     Iy = 0.5;
%     Iz = 0.5;
%     Ix_Kp_dot = Ix - Kp_dot;
%     Iy_Mq_dot = Iy - Mq_dot;
%     Iz_Nr_dot = Iz - Nr_dot;
    
    zb = -0.39;
    Kp = -1.19;
    Kp_dot = -0.91;
    Kp_abs_p = -0.0007;
    Mq = -0.30;
    Mq_dot = -1.01;
    Mq_abs_q = -0.22;
    Nr = -1.52;
    Nr_dot = -1.07;
    Nr_abs_r = -1.14;
    Ix = 0.91;
    Iy = 1.01;
    Iz = 1.07;
    Ix_Kp_dot = 0.92;
    Iy_Mq_dot = 0.68;
    Iz_Nr_dot = 1.30;
    
    Parameters= [...
        m; g; rho; V; lx1; ly1; ly2; lx2; ly3; lx5; ly4;
        lz6; zb; Kp; Kp_dot; Kp_abs_p; Mq; Mq_dot; Mq_abs_q; Nr; Nr_dot;
        Nr_abs_r; Ix; Iy; Iz; Ix_Kp_dot; Iy_Mq_dot; Iz_Nr_dot];
%     saveParameters(Parameters, ones(size(Parameters)));
else
    temp = load('parameters.mat');
    disp('Parameters loaded from file')
    Parameters = temp.parameters;
end

Parameter_strings = {...
    'm';'g';'rho';'V';'lx1';'ly1';'ly2';'lx2';'ly3';'lx5';'ly4';'lz6';...
    'zb'; 'Kp';'Kp_dot'; 'Kp_abs_p'; 'Mq';'Mq_dot'; 'Mq_abs_q'; 'Nr';...
    'Nr_dot';'Nr_abs_r';'Ix';'Iy';'Iz';'Ix_Kp_dot'; 'Iy_Mq_dot';'Iz_Nr_dot'};
end
