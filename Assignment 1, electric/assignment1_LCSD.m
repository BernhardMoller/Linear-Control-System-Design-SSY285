
clc 
close all 
clear all 

f=50;
w=2*pi*f;
E=10000;
RL=100;
LL=1;

R1=30;
C1=10^-6;
L1=0.1;

R2=30;
C2=3*10^-6;
L2=0.2;

% T=0.5;
% dt =10^-3;
% t=linspace(0,dt,T);


e10= @(t) sqrt(2)*E*sin(w*t);
e20= @(t) sqrt(2)*E*cos(w*t);

% 
% A= [0 -2/(C1+C2) 2/(C1+C2) 2/(C1+C2);
%     1/LL -RL/LL 0 0;
%     1/L1 0 -R1/L1 0;
%     1/L2 0 0 -R2/L2];
A= [0 -2/(C1+C2) 2/(C1+C2) 2/(C1+C2); %osäker på om det ska vara + eller
    1/LL -RL/LL 0 0;                  % i 3 & 4 raden, första kolumnen
    -1/L1 0 -R1/L1 0; 
    -1/L2 0 0 -R2/L2];
B=[0 0;
   0 0;
   1/L1 0;
   0 1/L2];

C=[1 0 0 0];
D=[ 0 ];

state_space=ss(A,B,C,D);

transfer_function=tf(state_space); % bygger upp tf från ss 
%    [num,den]=tfdata(state_space,'v'); % plockar ut num och den från tf 

G1=transfer_function(1,1); 
G2=transfer_function(1,2);
[mag,phase]=bode(G1,w);  % mag & phase från G1
[mag,phase]=bode(G2,w) ; % mag & phase från G2

poles_G1=pole(G1);
zeros_G1=zero(G1);

poles_G2=pole(G2);
zeros_G2=zero(G2);

A_tilde= 10000;
f_tilde= 5; 
w_tilde= 2* pi * f_tilde; 




% 
% u1=A_tilde*sin(w_tilde*t);
% u2=A_tilde*cos(w_tilde*t);



% lsim(G1,u1(t),t)   % u,t define the input signal
%% Ass 2 

syms C1 C2 LL RL R1 R2 L1 L2 LL 'real' 
% assume(RL > 0);
% assume(R1 > 0);
% assume(R2 > 0);


A= [0 -2/(C1+C2) 2/(C1+C2) 2/(C1+C2); %osäker på om det ska vara + eller
    1/LL -RL/LL 0 0;                  % i 3 & 4 raden, första kolumnen
    -1/L1 0 -R1/L1 0; 
    -1/L2 0 0 -R2/L2];
B=[0 0;
   0 0;
   1/L1 0;
   0 1/L2];

C=[1 0 0 0];
D=[ 0 ];

obs= [C
    C*A
    C*A^2
   C*A^3
    ];
simplify(obs);
det_obs=det(obs);
simplify(det_obs)

% controllability

cont1=[ B(:,1) A*B(:,1) A^2*B(:,1) A^3*B(:,1)];
g1=simplify(cont1);


cont2=[ B(:,2) A*B(:,2) A^2*B(:,2) A^3*B(:,2)];
g2=simplify(cont2);

det_cont1=det(cont1);
det_cont2=det(cont2); 

% task 2 

[GS, GNS] = stabsep(transfer_function);




