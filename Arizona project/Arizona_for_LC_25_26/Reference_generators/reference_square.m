function [yref, xref, phiref, tref] = reference_square(Ts)
%Trajectory Y_Long
pbarYl = 0.3;
vbar = 2.3 ;%2.3;
abar = 3;%3;
jbar = 100;
sbar = 5000;
encoderResolution = 1e-6;
[t_dd,dd] = make4(pbarYl,vbar,abar,jbar,sbar,Ts,encoderResolution);
[~,~,~,~,~,~,prefYl,~] = profile4(t_dd,dd(1),Ts);


% Trajectory Y_short
pbarYs = 0.5*pbarYl;
vbar = 2.3; %2.3;
abar = 3;  %3;
jbar = 100;
sbar = 5000;
encoderResolution = 1e-6;
[t_dd,dd] = make4(pbarYs,vbar,abar,jbar,sbar,Ts,encoderResolution);
[~,~,~,~,~,~,prefYs,~] = profile4(t_dd,dd(1),Ts);


%Trajectory X
pbarX = pbarYl;
vbar = 0.55;%0.55;
abar =  1.31;%1.31;
jbar = 100;
sbar = 5000;
encoderResolution = 1e-6;
[t_dd,dd] = make4(pbarX,vbar,abar,jbar,sbar,Ts,encoderResolution);
[~,~,~,~,~,~,prefX,~] = profile4(t_dd,dd(1),Ts);

% y reference
yref = [zeros(200,1);prefYs; pbarYs*ones(length(prefX),1); flipud(prefYl)-pbarYs; -pbarYs*ones(length(prefX),1); prefYs-pbarYs];

% x reference 
xref = [zeros(200,1); zeros(length(prefYs),1); flipud(prefX)-pbarX; -pbarX*ones(length(prefYl),1); prefX-pbarX; zeros(length(prefYs),1)];

% Phi reference
phiref = zeros(length(xref),1);

tref = (0:Ts:(length(yref)-1)*Ts)';
end