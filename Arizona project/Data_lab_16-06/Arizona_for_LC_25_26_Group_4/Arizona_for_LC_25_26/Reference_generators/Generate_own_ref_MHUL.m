clear; clc; close all

Ts = get_Arizona_pars();

%______________________CREATE Y-REFERENCE__________________________________
pbar = 0.5;
offset = pbar;
vbar = 0.4;      % Maximum = 2
abar = 1;    % Maximum = 1.5
jbar = 100;     % Maximum = 100
sbar = 5000;    % Maximum = 5000
encoderResolution = 1e-6;
zeropadding = zeros(500,1);

%
[t_dd,dd] = make4(pbar,vbar,abar,jbar,sbar,Ts,encoderResolution);
[snapPoints,t_yfwd,syfwd,jyfwd,ayfwd,vyfwd,yfwd,tPoints] = profile4(t_dd,dd(1),Ts); % forward reference


ybckw = -yfwd(1:end-1) + offset;
yref = [zeropadding; yfwd; ybckw; zeropadding];           % Reference y-motor

t_y = [0:Ts:(length(yref)-1)*Ts]'; % Time vector
%
time_till_vc = 4*t_dd(1) + 2*t_dd(2) + t_dd(3);           % Time until constant velocity
time_vc = t_dd(4);                                        % Time constant velocity
        

%______________________CREATE X-REFERENCE_________________________________%
pbar = 0.4;
offset = pbar;
vbar = .3;     % Maximum = 2
abar = 0.35;    % Maximum = 1.5
jbar = 10;     % Maximum = 100
sbar = 50;    % Maximum = 5000
encoderResolution = 1e-6;
zeropadding = zeros(500,1);

%
[t_dd,dd] = make4(pbar,vbar,abar,jbar,sbar,Ts,encoderResolution);
[snapPoints,t_xfwd,sxfwd,jxfwd,axfwd,vxfwd,xfwd,tPoints] = profile4(t_dd,dd(1),Ts); % forward reference


xbckw = -xfwd(1:end-1) + offset;
xref = [zeropadding; xfwd; xbckw; zeropadding];             % Reference y-motor

t_x = [0:Ts:(length(xref)-1)*Ts]';                          % Time vector

%
time_till_vc_x = 4*t_dd(1) + 2*t_dd(2) + t_dd(3);           % time until constant velocity
time_vc_x = t_dd(4);                                        % Time constant velocity

% __________________________ Match size __________________________________%

if length(xref) >= length(yref)
    diff_length = length(xref) - length(yref);
    yref = [yref; zeros(diff_length,1)];

elseif length(yref) >= length(xref)
    diff_length = length(yref) - length(xref);
    xref = [xref; zeros(diff_length,1)];
end

%______________________CREATE PHI-REFERENCE_______________________________%
phiref = zeros(length(xref),1);

save('ref2','xref','yref','phiref')


%%
close all
[val,idx] = max(vyfwd);
figure(1)
subplot(1,2,1)
plot(t_yfwd,vyfwd); hold on
plot(t_yfwd,yfwd)
yline(yfwd(idx),'-',sprintf('%.4f',yfwd(idx)));
% yline(yfwd(idx + time_vc/Ts),'-',sprintf('%.4f',yfwd(idx + time_vc/Ts)));
xline(idx*Ts,'-',sprintf('%.0f',idx));
xline(idx*Ts + time_vc,'-',sprintf('%.0f',idx + time_vc/Ts));
xlabel('time [s]')
distance_vc = yfwd(end-idx) - yfwd(idx);
legend('vel y','pos y','','','','','location','best')
title('Carriage reference: Y-stage')

[val,idx] = max(vxfwd);
subplot(1,2,2)
plot(t_xfwd,vxfwd); hold on
plot(t_xfwd,xfwd)
yline(xfwd(idx),'-',sprintf('%.4f',xfwd(idx)));
yline(xfwd(idx + time_vc_x/Ts),'-',sprintf('%.4f',xfwd(idx + time_vc_x/Ts)));
xline(idx*Ts,'-',sprintf('%.0f',idx));
xline(idx*Ts + time_vc_x,'-',sprintf('%.0f',idx + time_vc_x/Ts));
xlabel('time [s]')
distance_vc = xfwd(end-idx) - xfwd(idx);
legend('vel x','pos x','','','','','location','best')
title('Gantry reference: X-stage')


figure()
plot(xref);hold on
plot(yref)
xline(length(zeropadding) + idx,'-',sprintf('%.0f',length(zeropadding) + idx));
xline(length(zeropadding) +idx + time_vc/Ts,'-',sprintf('%.0f',length(zeropadding) +idx + time_vc/Ts));
xline(length(zeropadding) +3*idx + time_vc/Ts,'-',sprintf('%.0f',length(zeropadding) +3*idx + time_vc/Ts));
xline(length(zeropadding) +3*idx + 2*time_vc/Ts,'-',sprintf('%.0f',length(zeropadding) +3*idx + 2*time_vc/Ts));
legend('xref','yref','','','','','location','best')
xlabel('Samples')

