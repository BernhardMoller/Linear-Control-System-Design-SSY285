clc 

syms alp the dalp dthe 'real'
syms Vm 'real'

x = [the alp dthe dalp]';

Mp = 0.127; Lr = 0.127; Lp = 0.3111; 
Jr = 0.0083; Jp = 0.0012; Dr = 0.069;
C0 = 0.1285; g = 0.981;

f1 = dthe;
f2 = dalp;

f3_a = (4*Mp*Lp^2*alp*dthe*dalp-8*C0*Vm+8*Dr*dthe)*Jp;
f3_b = Mp^2*Lp^4*alp*dthe*dalp-Mp^2*Lp^3*Lr*dthe^2*alp;
f3_c = 20*Mp^2*Lp^2*Lr*g*alp-2*Mp*Lp^2*Dr*dthe+2*Mp*Lp^2*C0*Vm;
f3_d = ((Jr+Mp*Lr^2)*4*Jp+Mp*Lp^2*Jr);
f3 = -.5*(f3_a+f3_b+f3_c)/f3_d;

f4_a = ((Mp^2*Lp^2*Lr^2 + Mp*Lp^2*Jr)*dthe^2 + 20*Jr*Mp*Lp*g)*alp;
f4_b = 20*Mp^2*Lr^2*Lp*g*alp + 2*Mp*Lr*Lp*C0*Vm - 2*Mp*Lr*Lp*Dr*dthe;
f4_c = -Mp^2*Lp^3*Lr*alp*dthe*dalp;
f4_d = f3_d;
f4 = (f4_a+f4_b+f4_c)/f4_d;

f_mat = [f1 f2 f3 f4];

Ad = jacobian(f_mat,x);
Bd = jacobian(f_mat,Vm);
Cd= [1 0 0 0 ; 
     0 1 0 0];
 Dd=[0;0];
 
% ex 3 
syms z 'real'
x_new = [x;z];
A = jacobian(f_mat,x_new)
B = jacobian(f_mat,Vm);

    

%%
syms z 'real' 
syms t 'real'

z= int(the,t);

x_new=[f_mat z];
A_new = jacobian(f_mat,x_new)
B_new = jacobian(f_mat,Vm);




%% task 5, chack obs via rank 

cont=obs(A,Cd)







