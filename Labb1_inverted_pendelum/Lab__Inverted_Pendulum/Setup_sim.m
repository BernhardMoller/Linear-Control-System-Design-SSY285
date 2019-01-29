
%% Initialization Settings(DONT CHANGE ANYTHING !!)
clear all;
EXT_GEAR_CONFIG = 'HIGH';
ENCODER_TYPE = 'E';
TACH_OPTION = 'YES';
LOAD_TYPE = 'NONE';
K_AMP = 1;
AMP_TYPE = 'VoltPAQ';
VMAX_DAC = 10;
ROTPEN_OPTION = '2DGANTRY-E';
PEND_TYPE = 'MEDIUM_12IN';
[ Rm, kt, km, Kg, eta_g, Beq, Jm, Jeq_noload, eta_m, K_POT, K_TACH, K_ENC, VMAX_AMP, IMAX_AMP ] = config_srv02( EXT_GEAR_CONFIG, ENCODER_TYPE, TACH_OPTION, AMP_TYPE, LOAD_TYPE );
[ Lb, Jarm, K_POT_2DP, K_ENC_2DP ] = config_2d_gantry( Jeq_noload );
%
%%%
%%%%
%%%%%
%%%%%% DO NOT CHANGE ANYTHING ABOVE THIS AREA !!
%%%%
%%%
%
%% System State-Space Matrices
% A
A = [0 0 1 0;
    0 0 0 1;
    0 12.8209195623776 -7.77440984306008 0;
    0 52.8827720124606 -4.56483960609997 0];
% B
B =[0;0;14.4784299251191;8.50118680266443];
% C
C = [1 0 0 0;0 1 0 0];
% D
D = [0;0];
%
%% Augment State-Space Matrices
% Ai
Ai = [0 0 0 1 0;
      0 0 0 0 1;
      0 0 12.8209195623776 -7.77440984306008 0;
      0 0 52.8827720124606 -4.56483960609997 0;
      1 0 0 0 0];
% Bi
Bi = [0;0;14.4784299251191;8.50118680266443;0];
% Ci
Ci = [1 0 0 0 0;
     0 1 0 0 0;
     0 0 0 0 1];
% Di
Di = [0;0;0];
%

%% DT State-Space
sysc = ss(A,B,C,D);
sysi = ss(Ai,Bi,Ci,Di);

%% Calculate LQR Control Gain
% Set LQR weighting matrices.
% Qx
xmax = 1/(20^2);
umax = 1/(10^2);
% Qx = [xmax 0 0 0 0;0 xmax 0 0 0;0 0 xmax 0 0;0 0 0 xmax 0;0 0 0 0 xmax];
Qx = diag([500 500 1 1 1]);
% Qu
% Qu = umax;
Qu = 0.2;
% Calculate control gain using LQR optimization.
% K_CT
K_CT = lqr(Ai,Bi,Qx,Qu);

%
%% Calculate Kalman Filter Gain
% Set Kalman Filter weighting matrices
% Qw
% Qw = [10 0 ; 0 10];
Qw = 50 * diag([1, 1]);
Q = Qw*Qw.';
% Qv
% Qv = [1 0; 0 1];
Qv = 0.01 * diag([1, 1]);
R = Qv*Qv.';
% Nn
Nn = Qw*Qv.';
% Calculate filter gain
% L_CT
G = [0 0;
     0 0;
     1 0;
     0 1];
plant=ss(sysc.a,[sysc.b G],sysc.c,[sysc.d zeros(2)]);
% Calculate filter gain
[~,L_CT,~] = kalman(plant,Q,R,Nn);
%
%% Display
disp( ' ' );
disp( 'SRV02+SIP Setup Succeed!' );
%
%%