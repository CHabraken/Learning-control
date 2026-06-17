function [yref, xref, phiref, tref] = reference_triangle(Ts)
% Trajectory y
pbarY = 0.3;
vbar = 1;
abar = 1.6;
jbar = 200;
sbar = 10000;
encoderResolution = 1e-6;
[t_dd,dd] = make4(pbarY,vbar,abar,jbar,sbar,Ts,encoderResolution);
[~,~,~,~,~,~,prefY,~] = profile4(t_dd,dd(1),Ts);
 
 
% Trajectory x_short
pbarXs = 0.5*pbarY;
vbar = 0.5;
abar = 0.8;
jbar = 100;
sbar = 5000;
encoderResolution = 1e-6;
[t_dd,dd] = make4(pbarXs,vbar,abar,jbar,sbar,Ts,encoderResolution);
[~,~,~,~,~,~,prefXs,~] = profile4(t_dd,dd(1),Ts);
 
% x reference
xref =[zeros(500,1); prefXs; flipud(prefXs); flipud(prefXs)-pbarXs; prefXs-pbarXs];

%y Reference
yref = [zeros(500,1); zeros(length(prefXs),1); prefY; flipud(prefY); zeros(length(prefXs),1)];

% Phi reference
phiref = 0*yref;

tref = (0:Ts:(length(yref)-1)*Ts)';
end