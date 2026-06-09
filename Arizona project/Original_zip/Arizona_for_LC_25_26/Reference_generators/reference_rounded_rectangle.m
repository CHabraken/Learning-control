function [yref, xref, phiref, tref] = reference_rounded_rectangle(Ts)
traj = cell(6,5,3); % vertical: t,p,v,a,j,s. Horizontal: segments. Depth: coordinate [x y phi]
dx = .6;
dy_straight = .3;
t_arc_init = 2; % Will be optimized later
%% Ramp up to constant velocity
seg = 1;
% y
dir = 2;
pbarY1 = dy_straight;
vbar = 1;
abar = 1.6;
jbar = 200;
sbar = 10000;
encoderResolution = 1e-6;
[t_dd,dd] = make4(pbarY1,vbar,abar,jbar,sbar,Ts,encoderResolution);
[~,t,s,j,a,v,r,tt] = profile4(t_dd,dd(1),Ts);
id = 8;
tend = tt(id);
selection = t <= tend;
traj = store_traj(traj,selection,t,r,v,a,j,s,seg,dir);
% x
dir = 1;
traj = store_traj(traj,selection,t,0*r,0*v,0*a,0*j,0*s,seg,dir);
% phi
dir = 3;
traj = store_traj(traj,selection,t,0*r,0*v,0*a,0*j,0*s,seg,dir);

%% 'Circular' arc
% Arc is parametrized as 7th order polynomial (8 coefficients!) in x and y
% x(t) = p0 + p1*t + p2*t^2 + ... +  p7*t^7 = [t^7 t^6 ... t^1 1] p with 
% p = [p7, p6, ..., p1, p0]'. Polyder expects in decreasing order
seg = 2;
t_arc = t_arc_init;
found = 0;
while true
% x 
dir = 1;
t0 = traj{1,seg-1,dir}(end); 
t1 = t0 + t_arc;
t1 = round(t1/Ts)*Ts;% Prevent 2.87399999999 instead of 2.874 and thus missing sample...
% Constraints
p0 = traj{2,seg-1,dir}(end);
v0 = traj{3,seg-1,dir}(end); 
a0 = traj{4,seg-1,dir}(end);
j0 = traj{5,seg-1,dir}(end);
p1 = p0 + dx; % Arrive at translated x
v1 = 0; % Arrive at zero velocity for x (also start velocity)
a1 = 0; j1 = 0;
% Create system of equation
pow = (7:-1:0);
r = ones(1,8); % 7th order
v = polyder(r); a = polyder(v); j = polyder(a);
coeff = [r; v, 0; a, 0, 0; j, 0, 0, 0];
T0 = hankel(t0.^pow, flip(t0.^pow));
A0 = coeff.*T0(1:size(coeff,1),:); b0 = [p0;v0;a0;j0];
T1 = hankel(t1.^pow, flip(t1.^pow));
A1 = coeff.*T1(1:size(coeff,1),:); b1 = [p1;v1;a1;j1];
A = [A0;A1];
b = [b0; b1];
px = pinv(A)*b;
tx = (t0+Ts:Ts:t1)';
rx = polyval(px,tx); px_t = polyder(px); 
vx = polyval(px_t,tx); px_tt = polyder(px_t); 
ax = polyval(px_tt,tx); px_ttt = polyder(px_tt);
jx = polyval(px_ttt,tx); px_tttt = polyder(px_ttt);
sx = polyval(px_tttt,tx);

% y
dir = 2;
% Constraints
p0 = traj{2,seg-1,dir}(end);
v0 = traj{3,seg-1,dir}(end); a0 = traj{4,seg-1,dir}(end);
j0 = traj{5,seg-1,dir}(end); s0 = traj{6,seg-1,dir}(end);
p1 = p0; % Arrive at same y
v1 = -v0; % Arrive at same velocity, but opposing sign
a1 = 0; j1 = 0;
% Create system of equation
pow = (7:-1:0);
r = ones(1,8); % 7th order
v = polyder(r); a = polyder(v); j = polyder(a); s = polyder(j);
T0 = hankel(t0.^pow, flip(t0.^pow));
A0 = coeff.*T0(1:size(coeff,1),:); b0 = [p0;v0;a0;j0];
T1 = hankel(t1.^pow, flip(t1.^pow));
A1 = coeff.*T1(1:size(coeff,1),:); b1 = [p1;v1;a1;j1];
A = [A0;A1];
b = [b0; b1];
py = pinv(A)*b;
ty = tx;
ry = polyval(py,ty); py_t = polyder(py); 
vy = polyval(py_t,ty); py_tt = polyder(py_t); 
ay = polyval(py_tt,ty); py_ttt = polyder(py_tt);
jy = polyval(py_ttt,ty); py_tttt = polyder(py_ttt);
sy = polyval(py_tttt,ty);
if max(abs(sy))>sbar || max(abs(sx))>sbar || max(abs(jy))>jbar || max(abs(jx))>jbar || ...
        max(abs(ay))>abar || max(abs(ax))>abar || max(abs(vy))>vbar || max(abs(vx))>vbar 
    found = 1;
    t_arc = t_arc + Ts; % Increment by Ts and recalculate
elseif found
    break
else
    t_arc = t_arc - Ts; % Simply grid starting from initial guess
end
end
selection = true(size(sy));
traj = store_traj(traj,selection,tx,rx,vx,ax,jx,sx,seg,1);
traj = store_traj(traj,selection,ty,ry,vy,ay,jy,sy,seg,2);

% Phi
dir = 3;
traj = store_traj(traj,selection,ty,0*ry,0*vy,0*ay,0*jy,0*sy,seg,dir);

%% Constant velocity segment
% y
seg = 3;
ry0 = traj{2,seg-1,2}(end);
vy0 = traj{3,seg-1,2}(end);
% ay0, jy0 are 0, and sy0 can contain steps.
dt_const_velocity = dy_straight/abs(vy0);
N_const_velocity = ceil(dt_const_velocity/Ts);
t0 = traj{1,seg-1,2}(end);
vy0 = traj{3,seg-1,2}(end);
t_const_velocity = (t0+Ts:Ts:t0+N_const_velocity*Ts)';
vy_const_velocity = vy0*ones(size(t_const_velocity));
ry_const_velocity = ry0 + cumsum(vy_const_velocity)*Ts;
ay_const_velocity = zeros(size(t_const_velocity));
jy_const_velocity = zeros(size(t_const_velocity));
sy_const_velocity = zeros(size(t_const_velocity));
selection = true(size(sy_const_velocity));
traj = store_traj(traj,selection,t_const_velocity,ry_const_velocity,vy_const_velocity,ay_const_velocity,jy_const_velocity,sy_const_velocity,seg,2);
% x
one = ones(N_const_velocity,1);
zero = zeros(N_const_velocity,1);
rx0 = traj{2,seg-1,1}(end);
traj = store_traj(traj,selection,t_const_velocity,rx0*one,zero,zero,zero,zero,seg,1);
% phi
rphi0 = traj{2,seg-1,3}(end);
traj = store_traj(traj,selection,t_const_velocity,zero,zero,zero,zero,zero,seg,3);

%% Circular arc back
seg = 4;
t_arc = t_arc_init;
found = 0;
while true
% x 
dir = 1;
t0 = traj{1,seg-1,dir}(end); 
t1 = t0 + t_arc;
t1 = round(t1/Ts)*Ts;% Prevent 2.87399999999 instead of 2.874 and thus missing sample...
% Constraints
p0 = traj{2,seg-1,dir}(end);
v0 = traj{3,seg-1,dir}(end); 
a0 = traj{4,seg-1,dir}(end);
j0 = traj{5,seg-1,dir}(end); 
p1 = p0 - dx; % Arrive at translated x, should be 0 again
v1 = 0; % Arrive at zero velocity for x (also start velocity)
a1 = 0; j1 = 0;
% Create system of equation
pow = (7:-1:0);
r = ones(1,8); % 7th order
v = polyder(r); a = polyder(v); j = polyder(a);
coeff = [r; v, 0; a, 0, 0; j, 0, 0, 0];
T0 = hankel(t0.^pow, flip(t0.^pow));
A0 = coeff.*T0(1:size(coeff,1),:); b0 = [p0;v0;a0;j0];
T1 = hankel(t1.^pow, flip(t1.^pow));
A1 = coeff.*T1(1:size(coeff,1),:); b1 = [p1;v1;a1;j1];
A = [A0;A1];
b = [b0; b1];
px = pinv(A)*b;
tx = (t0+Ts:Ts:t1)';
rx = polyval(px,tx); px_t = polyder(px); 
vx = polyval(px_t,tx); px_tt = polyder(px_t); 
ax = polyval(px_tt,tx); px_ttt = polyder(px_tt);
jx = polyval(px_ttt,tx); px_tttt = polyder(px_ttt);
sx = polyval(px_tttt,tx);

% y
dir = 2;
% Constraints
p0 = traj{2,seg-1,dir}(end);
v0 = traj{3,seg-1,dir}(end); a0 = traj{4,seg-1,dir}(end);
j0 = traj{5,seg-1,dir}(end); s0 = traj{6,seg-1,dir}(end);
p1 = p0; % Arrive at same y
v1 = -v0; % Arrive at same velocity, but opposing sign
a1 = 0; j1 = 0;
% Create system of equation
pow = (7:-1:0);
r = ones(1,8); % 7th order
v = polyder(r); a = polyder(v); j = polyder(a); s = polyder(j);
T0 = hankel(t0.^pow, flip(t0.^pow));
A0 = coeff.*T0(1:size(coeff,1),:); b0 = [p0;v0;a0;j0];
T1 = hankel(t1.^pow, flip(t1.^pow));
A1 = coeff.*T1(1:size(coeff,1),:); b1 = [p1;v1;a1;j1];
A = [A0;A1];
b = [b0; b1];
py = pinv(A)*b;
ty = tx;
ry = polyval(py,ty); py_t = polyder(py); 
vy = polyval(py_t,ty); py_tt = polyder(py_t); 
ay = polyval(py_tt,ty); py_ttt = polyder(py_tt);
jy = polyval(py_ttt,ty); py_tttt = polyder(py_ttt);
sy = polyval(py_tttt,ty);
if max(abs(sy))>sbar || max(abs(sx))>sbar || max(abs(jy))>jbar || max(abs(jx))>jbar || ...
        max(abs(ay))>abar || max(abs(ax))>abar || max(abs(vy))>vbar || max(abs(vx))>vbar 
    found = 1;
    t_arc = t_arc + Ts; % Increment by Ts and recalculate
elseif found
    break
else
    t_arc = t_arc - Ts; % Simply grid starting from initial guess
end
end
selection = true(size(sy));
traj = store_traj(traj,selection,tx,rx,vx,ax,jx,sx,seg,1);
traj = store_traj(traj,selection,ty,ry,vy,ay,jy,sy,seg,2);

% Phi
dir = 3;
traj = store_traj(traj,selection,ty,0*ry,0*vy,0*ay,0*jy,0*sy,seg,dir);

%% Decelerate
seg = 5;
% y
dir = 2;
pbarY1 = dy_straight;
vbar = 1;
abar = 1.6;
jbar = 200;
sbar = 10000;
encoderResolution = 1e-6;
[t_dd,dd] = make4(pbarY1,vbar,abar,jbar,sbar,Ts,encoderResolution);
[~,ty,sy,jy,ay,vy,ry,tt] = profile4(t_dd,dd(1),Ts);
id = 8;
tend = tt(id);
selection = ty > tend + Ts;
ty_window = ty(selection);
ry_window = ry(selection);
ty = ty + traj{1,seg-1,2}(end) - ty_window(1) + Ts;
ry = ry - ry_window(1) + traj{2,seg-1,2}(end);
traj = store_traj(traj,selection,ty,ry,vy,ay,jy,sy,seg,dir);
% x
dir = 1;
traj = store_traj(traj,selection,ty,0*ry,0*vy,0*ay,0*jy,0*sy,seg,dir);
% phi
dir = 3;
traj = store_traj(traj,selection,ty,0*ry,0*vy,0*ay,0*jy,0*sy,seg,dir);
%% Validate
check_time = find(abs(diff(vertcat(traj{1,:,3})) - Ts)>10^-13);
check_place = find(vecnorm(diff([vertcat(traj{2,:,1}),vertcat(traj{2,:,2})]))<10^-13);
%% Plot
% x
% dir = 1;
% figure; hold on; grid on; xlabel('Time [s]'); ylabel('Reference x')
% plot(vertcat(traj{1,:,dir}),vertcat(traj{2,:,dir}))
% figure; hold on; grid on; xlabel('Time [s]'); ylabel('Velocity x')
% plot(vertcat(traj{1,:,dir}),vertcat(traj{3,:,dir}))
% figure; hold on; grid on; xlabel('Time [s]'); ylabel('Acceleration x')
% plot(vertcat(traj{1,:,dir}),vertcat(traj{4,:,dir}))
% figure; hold on; grid on; xlabel('Time [s]'); ylabel('Jerk x')
% plot(vertcat(traj{1,:,dir}),vertcat(traj{5,:,dir}))
% figure; hold on; grid on; xlabel('Time [s]'); ylabel('Snap x')
% plot(vertcat(traj{1,:,dir}),vertcat(traj{6,:,dir}))
% % y
% dir = 2;
% figure; hold on; grid on; xlabel('Time [s]'); ylabel('Reference y')
% plot(vertcat(traj{1,:,dir}),vertcat(traj{2,:,dir}))
% figure; hold on; grid on; xlabel('Time [s]'); ylabel('Velocity y')
% plot(vertcat(traj{1,:,dir}),vertcat(traj{3,:,dir}))
% figure; hold on; grid on; xlabel('Time [s]'); ylabel('Acceleration y')
% plot(vertcat(traj{1,:,dir}),vertcat(traj{4,:,dir}))
% figure; hold on; grid on; xlabel('Time [s]'); ylabel('Jerk y')
% plot(vertcat(traj{1,:,dir}),vertcat(traj{5,:,dir}))
% figure; hold on; grid on; xlabel('Time [s]'); ylabel('Snap y')
% plot(vertcat(traj{1,:,dir}),vertcat(traj{6,:,dir}))
% %x,y
% figure; hold on; grid on; xlabel('x [m]'); ylabel('y [m]'); zlabel('Time [s]')
% plot3(vertcat(traj{2,:,1}), vertcat(traj{2,:,2}), vertcat(traj{1,:,2}))
% view(-35,65)
%% Unpack
xref = vertcat(traj{2,:,1});
yref = vertcat(traj{2,:,2});
phiref = vertcat(traj{2,:,3});
tref = vertcat(traj{1,:,1});
end

%% Local functions
function traj = store_traj(traj,selection,t,r,v,a,j,s,seg,dir)
traj{1,seg,dir} = t(selection);
traj{2,seg,dir} = r(selection);
traj{3,seg,dir} = v(selection);
traj{4,seg,dir} = a(selection);
traj{5,seg,dir} = j(selection);
traj{6,seg,dir} = s(selection);
end