%clear; clc; close all

Ts = get_Arizona_pars();

%______________________CREATE Y-REFERENCE__________________________________
pbar = 0.5;
offset = pbar;
vbar = 0.2;      % Maximum = 2
abar = 1.5;    % Maximum = 1.5
jbar = 100;     % Maximum = 100
sbar = 5000;    % Maximum = 5000
encoderResolution = 1e-6;
zeropadding = zeros(500,1);

%
[t_dd,dd] = make4(pbar,vbar,abar,jbar,sbar,Ts,encoderResolution);
[snapPoints,t_yfwd,syfwd,jyfwd,ayfwd,vyfwd,yfwd,tPoints] = profile4(t_dd,dd(1),Ts); % forward reference


ybckw = -yfwd(1:end-1) + offset;
yref = [zeropadding; yfwd; ybckw; zeropadding];           % Reference y-motor

t = [0:Ts:(length(yref)-1)*Ts]';        % Time vector
%
time_till_vc = 4*t_dd(1) + 2*t_dd(2) + t_dd(3);     % time until constant velocity
time_vc = t_dd(4);      % Time constant velocity
        

% %______________________CREATE X-REFERENCE__________________________________
% pbar = 0.05;
% vbar = 0.1;     % Maximum = 2
% abar = 1;       % Maximum = 1.5
% jbar = 100;     % Maximum = 100
% sbar = 5000;    % Maximum = 5000
% encoderResolution = 1e-6;
% 
% 
% [t_dd,dd] = make4(pbar,vbar,abar,jbar,sbar,Ts,encoderResolution);
% [snapPointsx,t_xfwd,sxfwd,jxfwd,axfwd,vxfwd,xfwd,tPointsx] = profile4(t_dd,dd(1),Ts); % forward reference
% 
% % outputs:
% %      t(1) = constant djerk phase duration
% %      t(2) = constant jerk phase duration 
% %      t(3) = constant acceleration phase duration 
% %      t(4) = constant velocity phase duration 
% %      
% %       t1               t1               t1     t1  
% %       .-.              .-.              .-.    .-.
% %       | |              | |              | |    | |
% %       | |t2    t3    t2| |   t4       t2| | t3 | |t2   
% %       '-'--.-.----.-.--' '---------.-.--'-'----'-'--.-.--
% %            | |    | |              | |              | |
% %            | |    | |              | |              | |
% %            '-'    '-'              '-'              '-'
% %            t1     t1               t1               t1
% %
% 
% [snapPoints,t_xInit,sxInit,jxInit,axInit,vxInit,xInit,tPoints] = profile4(t_dd,dd(1),Ts);
% 
% %  Outputs:
% %
% %      dj  = derivative of jerk profile suitable for simulink 
% %
% %      tx  = time sequence for plotting profiles
% %      d   = derivative of jerk profile
% %      j   = jerk profile
% %      a   = acceleration profile
% %      v   = velocity profile
% %      p   = position profile
% %
% %      tt  = 16 switching times for profile:
% %
% %       0 1              6 7             10 11  12 13
% %       .-.              .-.              .-.    .-.
% %       | |              | |              | |    | |
% %       | |  2 3    4 5  | |         8 9  | |    | |  14 15
% %       '-'--.-.----.-.--' '---------.-.--'-'----'-'--.-.--
% %            | |    | |              | |              | |
% %            | |    | |              | |              | |
% %            '-'    '-'              '-'              '-'
% %
% %  Note: coinciding switching times are not removed 
% 
% 
% pbar = 0.1;
% vbar = 0.5;       % Maximum = 2
% abar = 0.5;       % Maximum = 1.5
% jbar = 100;     % Maximum = 100
% sbar = 5000;    % Maximum = 5000
% encoderResolution = 1e-6;
% offset = 0.05;      % because the algorithm cannot deal with negative positions
% time_offset = t_xInit(end);     % because the algo start always at t = 0
% 
% 
% 
% [t_dd,dd] = make4(pbar,vbar,abar,jbar,sbar,Ts,encoderResolution);
% [snapPoints,t_xTA,sxTA,jxTA,axTA,vxTA,xTA,tPoints] = profile4(t_dd,dd(1),Ts);
% t_xTA = t_xTA(2:end) + time_offset;
% xTA = -xTA(2:end) + offset;
% 
% 
% pbar = 0.05;
% vbar = 1;       % Maximum = 2
% abar = 1;       % Maximum = 1.5
% jbar = 100;     % Maximum = 100
% sbar = 5000;    % Maximum = 5000
% encoderResolution = 1e-6;
% offset = -0.05;      % because the algorithm cannot deal with negative positions
% time_offset = t_xTA(end);
% 
% 
% [t_dd,dd] = make4(pbar,vbar,abar,jbar,sbar,Ts,encoderResolution);
% [snapPoints,t_xEND,sxEND,jxEND,axEND,vxEND,xEND,tPoints] = profile4(t_dd,dd(1),Ts);
% t_xEND = t_xEND(2:end) + time_offset;
% xEND = xEND(2:end) + offset;
% 
% offset = 0.05;
% xref = [zeropadding; xInit; offset*ones(time_vc/Ts + 34,1); xTA; -offset*ones(time_vc/Ts + 34,1); xEND; zeropadding];
% 
% phiref = zeros(length(t),1);
% % save('Reference_4th_order','phiref','xref','yref','t')
%%
close all
[val,idx] = max(vyfwd);
figure(1)
plot(t_yfwd,vyfwd); hold on
plot(t_yfwd,yfwd)
yline(yfwd(idx),'-',sprintf('%.4f',yfwd(idx)));
yline(yfwd(idx + time_vc/Ts),'-',sprintf('%.4f',yfwd(idx + time_vc/Ts)));
xline(idx*Ts,'-',sprintf('%.0f',idx));
xline(idx*Ts + time_vc,'-',sprintf('%.0f',idx + time_vc/Ts));
xlabel('time [s]')
distance_vc = yfwd(end-idx) - yfwd(idx);
legend('vel y','pos y','','','','','location','best')

% [val,idx] = max(vxfwd);
% figure(2)
% plot(t_xfwd,vxfwd); hold on
% plot(t_xfwd,xfwd)
% yline(xfwd(idx),'-',sprintf('%.4f',xfwd(idx)));
% % yline(xfwd(idx + time_vc/Ts),'-',sprintf('%.4f',xfwd(idx + time_vc/Ts)));
% % xline(idx*Ts,'-',sprintf('%.0f',idx));
% % xline(idx*Ts + time_vc,'-',sprintf('%.0f',idx + time_vc/Ts));
% xlabel('time [s]')
% distance_vc = xfwd(end-idx) - xfwd(idx);
% legend('vel x','pos x','','','','','location','best')


figure()
plot(xref);hold on
plot(yref)
xline(length(zeropadding) + idx,'-',sprintf('%.0f',length(zeropadding) + idx));
xline(length(zeropadding) +idx + time_vc/Ts,'-',sprintf('%.0f',length(zeropadding) +idx + time_vc/Ts));
xline(length(zeropadding) +3*idx + time_vc/Ts,'-',sprintf('%.0f',length(zeropadding) +3*idx + time_vc/Ts));
xline(length(zeropadding) +3*idx + 2*time_vc/Ts,'-',sprintf('%.0f',length(zeropadding) +3*idx + 2*time_vc/Ts));
legend('xref','yref','','','','','location','best')
xlabel('Samples')

