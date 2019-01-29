
clc, close all 
B=[0 0;
   0 0;
   1/L1 0;
   0 1/L2];

a = -sqrt(2)*E;
b = sqrt(2)*E;
w1 = (b-a).*rand(2,1) + a;

a = -sqrt(2)*E;
b = sqrt(2)*E;
w2 = (b-a).*rand(2,1) + a;

W=[w1 w2];

covariance=cov(W)

%%
clc
V0= 10;
I0= 100; 

B_d=[0.495588302638375	0.383665028756318
0.00204749886420818	0.00137758017967379
0.0130175699344565	-0.00905805849580861
-0.00905805849580860	0.0114252219448669];

C_d=[1 0 0 0 ; 0 1 0 0];
D=[0 0 0 0]; 


N=B_d; 

% b = sqrt(2)*E*0.1;

% w1 = normrnd(0,3)*b;
% w2 = normrnd(0,3)*b;
sig_1= ((sqrt(2)*1000*0.06)/3)^2;
W_1=[sig_1 0; 0 sig_1];

sig_2=(sig_1)/2;
% W_2=W_1+[0 sig_2; sig_2 0]
W_2=(W_1+[0 sig_2; sig_2 0])/1000;

% W=[w1 0;0 w2]
% % W=[0.2 0; 0 2]
% % covariance =cov(W)
% covariance= W^2
% i=sqrt(covariance)
% 
% 
% noise= N*W; 
% syms u1 u2 'real' 
% 
% u=[u1;u2];
% B_u= B*u; 
% 
% B_noise= B_u+ noise;


sys=ss(A,B_d,C_d,D)

% [kest,L,P] = kalman(sys,Qn,Rn,Nn)


