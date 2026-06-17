% reference script
% clear

Npad_middle = 1000;
Ts = 1e-3;
Npad_start = 500;

% Settings other references:
% 0.1,1,1,1e3,1e3 (this caused bit problems when learning nb=4)
% 0.1,1,1,1e3,1e4 (also cannot get higher than na=nb=3
% forward motion
[ty,ddy] = make4(0.1,1,0.4,1e3,2e2,Ts);
[~,~,s,j,a,v,r,tt] = profile4(ty,ddy(1),Ts);


%return motion
r_return = flipud(r);
v_return = -flipud(v);
a_return = flipud(a);
j_return = -flipud(j);
s_return = flipud(s);

% -------------------------------------------------
% Combine trajectories
% -------------------------------------------------
r_full = [ ...
    zeros(Npad_start,1); ...
    r; ...
    r(end)*ones(Npad_middle,1); ...
    r_return;
    zeros(Npad_start,1)];

v_full = [ ...
    zeros(Npad_start,1); ...
    v; ...
    zeros(Npad_middle,1); ...
    v_return;
    zeros(Npad_start,1) ];

a_full = [ ...
    zeros(Npad_start,1); ...
    a; ...
    zeros(Npad_middle,1); ...
    a_return;
    zeros(Npad_start,1) ];

j_full = [ ...
    zeros(Npad_start,1); ...
    j; ...
    zeros(Npad_middle,1); ...
    j_return;
    zeros(Npad_start,1) ];

s_full = [ ...
    zeros(Npad_start,1); ...
    s; ...
    zeros(Npad_middle,1); ...
    s_return;
    zeros(Npad_start,1) ];

% -------------------------------------------------
% Rename back to original variables if desired
% -------------------------------------------------
r = r_full;
v = v_full;
a = a_full;
j = j_full;
s = s_full;

% -------------------------------------------------
% Time vector
% -------------------------------------------------
N = length(r);

t = (0:N-1)' * Ts;

figure(1);clf
subplot(5,1,1)
plot(t,r)
subplot(5,1,2)
plot(t,v)
subplot(5,1,3)
plot(t,a)
subplot(5,1,4)
plot(t,j)
subplot(5,1,5)
plot(t,s)

% %% save 
% % slow gantry ref
xref = r;
yref = zeros(N,1);
phiref = zeros(N,1);


% save('Reference_X_slow.mat', 'xref', 'yref', 'phiref', 't')
% 
%%
clear;
load("Reference_X_slow.mat")
