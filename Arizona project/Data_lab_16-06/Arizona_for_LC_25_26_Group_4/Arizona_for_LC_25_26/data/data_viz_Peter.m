%% data visualisation Peter

%% 
last_trial = 47;

yc_ = history.p(:,:,1);
ym_ = history.p2(:,:,1);
ff_ = history.f(:,:,1);
e_ = history.e(:,:,1);
eNorm_ = history.eNorm(:,1);

% yc_p = history.p(:,:,1);
% ym_p = history.p2(:,:,1);
% ff_p = history.f(:,:,1);
% e_p = history.e(:,:,1);
% eNorm_p = history.eNorm(:,1);

% compare e's
figure(); hold on;
plot(e_(last_trial-4,:))
plot(e_(last_trial-3,:))
plot(e_(last_trial-2,:))
plot(e_(last_trial-1,:))
plot(e_(last_trial,:))

e_mean = mean(e_(last_trial-5:end,:));
figure(); plot(e_mean')

% compare e with -j components
figure(); hold on;
plot(e_(last_trial,:)/max(e_(last_trial,:)))
plot(-data.(exp).j/max(data.(exp).j))

% compare yc, ym
figure(); hold on;
plot(yc_(last_trial,:))
plot(ym_(last_trial,:))

% compare ff NI, SG
figure(); hold on;
plot(data.(exp).johan.ff)
plot(ff_(last_trial,:))
plot(ff_p(last_trial,:))

% compare e NI, SG
figure(); hold on;
plot(data.(exp).johan.e)
plot(e_(last_trial,:))
plot(e_p(last_trial,:))

F = 7;
[z,p,k] = butter(4,F/((1/Ts)/2),'high');
[sos,g] = zp2sos(z,p,k);
e_filt = filtfilt(sos,g,e_(last_trial,:))';
e_filt_p = filtfilt(sos,g,e_p(last_trial,:))';
plot(e_filt)
plot(e_filt_p)

figure(); hold on;
plot(data.(exp).johan.e)
plot(- e_filt)

% compare SPy
%SPy_p = SPy;
%save('SPy_peter.mat','SPy_p')
load('SPy_peter.mat')
figure(); bode(SPy_p); hold on; bode(SPy)



