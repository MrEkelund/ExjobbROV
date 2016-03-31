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
    Xu_init = -1;
    Xu_dot_init = -1;
    Xu_abs_u_init = -1;
    Yv_init = -1;
    Yv_dot_init = -1;
    Yv_abs_v_init = 1;
    Zw_init = -1;
    Zw_dot_init = -1;
    Zw_abs_w_init = -1;
    Kp_init = -1;
    Kp_dot_init = -1;
    Kp_abs_p_init = -1;
    Mq_init = -1;
    Mq_dot_init = -1;
    Mq_abs_q_init = -1;
    Nr_init = -1;
    Nr_dot_init = -1;
    Nr_abs_r_init = -1;
    Ix_init = 13;
    Iy_init = 13;
    Iz_init = 13;
    Ix_Kp_dot = 1;
    Iy_Mq_dot = 1;
    Kp_Ix_Kp_dot = -1;
    Kp_abs_p_Ix_Kp_dot = -1;
    Mq_dot_Ix_Kp_dot = -1;
    Nr_dot_Ix_Kp_dot = -1;
    Mq_Iy_Mq_dot = -1;
    Mq_abs_q_Iy_Mq_dot = -1;
    Kp_dot_Iy_Mq_dot = -1;
    Nr_dot_Iy_Mq_dot = -1;
    
    Parameters= [...
        m; g; rho; V; lx1; ly1; ly2; lx2; ly3; lx5; ly4;
        lz6; zb; Xu_init; Xu_dot_init; Xu_abs_u_init;
        Yv_init; Yv_dot_init; Yv_abs_v_init; Zw_init;
        Zw_dot_init; Zw_abs_w_init; Kp_init; Kp_dot_init;
        Kp_abs_p_init; Mq_init; Mq_dot_init;
        Mq_abs_q_init; Nr_init; Nr_dot_init;
        Nr_abs_r_init; Ix_init; Iy_init; Iz_init; 
        Ix_Kp_dot; Iy_Mq_dot; Kp_Ix_Kp_dot; 
        Kp_abs_p_Ix_Kp_dot; Mq_dot_Ix_Kp_dot;
        Nr_dot_Ix_Kp_dot; Mq_Iy_Mq_dot;
        Mq_abs_q_Iy_Mq_dot; Kp_dot_Iy_Mq_dot;
        Nr_dot_Iy_Mq_dot];
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
    'Mq_dot_Ix_Kp_dot';'Nr_dot_Ix_Kp_dot';'Mq_Iy_Mq_dot';'Mq_abs_q_Iy_Mq_dot';'Kp_dot_Iy_Mq_dot';'Nr_dot_Iy_Mq_dot'};

end

