% Move the print head to center of the working area.
Ts = get_Arizona_pars();
%% Carriage translation initialization.
pbar = 2.9/2;
vbar = 0.7;
abar = 0.5;
jbar = 100;
sbar = 5000;
encoderResolution = 1e-6;

[t_dd,dd] = make4(pbar,vbar,abar,jbar,sbar,Ts,encoderResolution);
[snapPoints,t_yInit,sref,jref,aref,vref,yInit,tPoints] = profile4(t_dd,dd(1),Ts);


%% Gantry translation initialization.
pbar = 0.8/2+0.2;
vbar = 0.5;
abar = 0.25;
jbar = 100;
sbar = 5000;
encoderResolution = 1e-6;

[t_dd,dd] = make4(pbar,vbar,abar,jbar,sbar,Ts,encoderResolution);
[snapPoints,t_xInit,sref,jref,aref,vref,xInit,tPoints] = profile4(t_dd,dd(1),Ts);


%% Gantry rotation initialization.
phiInit = 0*yInit;
t_phiInit = t_yInit;


%% Maximum signal length.
NInit = max([length(yInit); length(xInit); length(phiInit)]);


%% Transition from Square -> Triangle
y_offset = 0.2;
x_offset = -0.15;   % watch out with negative directions in make4/profile4

%Trajectory Y
pbarY2 = y_offset;
vbar = 0.55;%0.52;
abar =  1.31;%1.5;
jbar = 100;
sbar = 5000;
encoderResolution = 1e-6;
[t_dd,dd] = make4(pbarY2,vbar,abar,jbar,sbar,Ts,encoderResolution);
[snapPoints,tref,sref,jref,arefY2,vref2,prefY2,tPoints] = profile4(t_dd,dd(1),Ts);

%Trajectory X
pbarX2 = x_offset;
vbar = 0.55;%0.52;
abar =  1.31;%1.5;
jbar = 100;
sbar = 5000;
encoderResolution = 1e-6;
[t_dd,dd] = make4(pbarX2,vbar,abar,jbar,sbar,Ts,encoderResolution);
[snapPoints,tref,sref,jref,arefX2,vref2,prefX2,tPoints] = profile4(t_dd,dd(1),Ts);

% Yreference forwards
Yref_triangle = [zeros(200,1);prefY2;prefY2(end)*ones(500,1) ];
Xref_triangle = sign(x_offset)*[zeros(200,1);prefX2;prefX2(end)*ones(length(Yref_triangle)-200-length(prefX2),1) ];
Phiref_triangle = zeros(size(Yref_triangle));

NInit_S2T = length(Yref_triangle);

phiInit_S2T = Phiref_triangle; 
xInit_S2T = Xref_triangle;
yInit_S2T= Yref_triangle;

return
%% Transition from first to second line
y_offset2 = -y_offset+0;
x_offset2 = -x_offset+0.15;   

%Trajectory Y
pbarY3 = y_offset;
vbar = 0.55;%0.52;
abar =  1.31;%1.5;
jbar = 100;
sbar = 5000;
encoderResolution = 1e-6;
[t_dd,dd] = make4(pbarY2,vbar,abar,jbar,sbar,Ts,encoderResolution);
[snapPoints,tref,sref,jref,arefY2,vref2,prefY3,tPoints] = profile4(t_dd,dd(1),Ts);

%Trajectory X
pbarX3 = x_offset;
vbar = 0.55;%0.52;
abar =  1.31;%1.5;
jbar = 100;
sbar = 5000;
encoderResolution = 1e-6;
[t_dd,dd] = make4(pbarX2,vbar,abar,jbar,sbar,Ts,encoderResolution);
[snapPoints,tref,sref,jref,arefX2,vref2,prefX3,tPoints] = profile4(t_dd,dd(1),Ts);

% Yreference forwards
Yref_2ndline = [zeros(200,1);prefY2;prefY2(end)*ones(500,1) ];
Xref_2ndline = [zeros(200,1);-prefX2;-prefX2(end)*ones(length(Yref_2ndline)-200-length(prefX2),1) ];
Phiref_2ndline = zeros(size(Yref_2ndline));

NInit_2ndline = length(Yref_2ndline);

phiInit_2ndline = Phiref_2ndline; 
xInit_2ndline = Xref_2ndline;
yInit_2ndline= Yref_2ndline;