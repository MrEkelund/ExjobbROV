function [ Parameters, Parameter_strings ] = initROVParameters(  )
%initROVParameters Initalises the ROV's parameters
%   Detailed explanation goes here

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
    zb = -0.05;
    
    % Parameters that will be estimated
    Xu = -1;
    Xu_dot = -1;
    Xu_abs_u = -1;
    Yv = -1;
    Yv_dot = -1;
    Yv_abs_v = -1;
    Zw = -1;
    Zw_dot = -1;
    Zw_abs_w = -1;
    Kp = -1;
    Kp_dot = -1;
    Kp_abs_p = -1;
    Mq = -1;
    Mq_dot = -1;
    Mq_abs_q = -1;
    Nr = -1;
    Nr_dot = -1;
    Nr_abs_r = -1;
    Ix = 1;
    Iy = 1;
    Iz = 1;
    Ix_Kp_dot = Ix - Kp_dot;
    Iy_Mq_dot = Iy - Mq_dot;
    Kp_Ix_Kp_dot = -1;
    Kp_abs_p_Ix_Kp_dot = -1;
    Mq_dot_Ix_Kp_dot = -1;
    Nr_dot_Ix_Kp_dot = -1;
    Mq_Iy_Mq_dot = -1;
    Mq_abs_q_Iy_Mq_dot = -1;
    Kp_dot_Iy_Mq_dot = -1;
    Nr_dot_Iy_Mq_dot = -1;
    Iy_Iz_Ix_Kp_dot = 1;
    Ix_Iz_Iy_Mq_dot = 1;
    Iz_Nr_dot = Iz - Nr_dot;
    Iy_Iz = 0.1; 
    Ix_Iz = 0.1;
    Ix_Iy = 0.1;
    
    Parameters= [...
        m; g; rho; V; lx1; ly1; ly2; lx2; ly3; lx5; ly4;
        lz6; zb; Xu; Xu_dot; Xu_abs_u; Yv; Yv_dot; Yv_abs_v; Zw; Zw_dot;
        Zw_abs_w; Kp; Kp_dot; Kp_abs_p; Mq; Mq_dot; Mq_abs_q; Nr; Nr_dot;
        Nr_abs_r; Ix; Iy; Iz; Ix_Kp_dot; Iy_Mq_dot; Kp_Ix_Kp_dot; 
        Kp_abs_p_Ix_Kp_dot; Mq_dot_Ix_Kp_dot; Nr_dot_Ix_Kp_dot; Mq_Iy_Mq_dot;
        Mq_abs_q_Iy_Mq_dot; Kp_dot_Iy_Mq_dot; Nr_dot_Iy_Mq_dot; 
        Iy_Iz_Ix_Kp_dot; Ix_Iz_Iy_Mq_dot; Iz_Nr_dot;Iy_Iz; Ix_Iz; Ix_Iy];
else
    temp = load('parameters.mat');
    disp('Parameters loaded from file')
    Parameters = temp.parameters;
end


Parameter_strings = {...
    'm';'g';'rho';'V';'lx1';'ly1';'ly2';'lx2';'ly3';'lx5';'ly4';'lz6';...
    'zb';'Xu';'Xu_dot';'Xu_abs_u';'Yv';'Yv_dot';'Yv_abs_v';'Zw';...
    'Zw_dot';'Zw_abs_w'; 'Kp';'Kp_dot'; 'Kp_abs_p'; 'Mq';'Mq_dot';...
    'Mq_abs_q'; 'Nr';'Nr_dot';'Nr_abs_r';'Ix';'Iy';'Iz';'Ix_Kp_dot';'Iy_Mq_dot';'Kp_Ix_Kp_dot';'Kp_abs_p_Ix_Kp_dot';...
    'Mq_dot_Ix_Kp_dot';'Nr_dot_Ix_Kp_dot';'Mq_Iy_Mq_dot';'Mq_abs_q_Iy_Mq_dot';'Kp_dot_Iy_Mq_dot';...
    'Nr_dot_Iy_Mq_dot';'Iy_Iz_Ix_Kp_dot';'Ix_Iz_Iy_Mq_dot'; 'Iz_Nr_dot';'Iy_Iz'; 'Ix_Iz'; 'Ix_Iy'};
end

