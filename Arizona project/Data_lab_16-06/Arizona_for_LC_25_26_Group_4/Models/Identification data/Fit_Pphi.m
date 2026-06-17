clear; close all; clc
%% Load
load('Pphi_frf_CL_5.mat')
f = Pphi_frf_CL_5(:,1);
w = 2*pi*f;
P_ = Pphi_frf_CL_5(:,2);
P_frd = frd(P_,w);

% unit transfers
Ts = 1/1000;
z = tf('z',Ts);
delta = (1-z^-1)/Ts;
s = tf('s');
s_ = freqresp(s, w); s_ = squeeze(s_);

% Correct for mass offset
w_mass_line = [22.5, 60]; % rad/s
w_mass_line_selection = w >= w_mass_line(1) & w <= w_mass_line(2);
Ps_squared_ = s_.^2.*P_;
m = 1/mean(abs(Ps_squared_(w_mass_line_selection)));

% Plot
fig_bode = figure;
h_bode = bodeplot(P_frd); hold on;
setoptions(h_bode,'PhaseWrapping','on');
xlim([w(2),max(w)])
% fig_bode.Position = [        1921        -295        1920        1083];

%% Initial estiamte
% freqs and normalized damping of resonances
w_poles_est =   [85, 99,     227, 319, 365, 568 1000]; % rad/s
zeta_poles_est= [0.07, 0.07, .05, .02, 0.06, .05, 0.3, 0.3];  

w_zeros_est =    [67.4, 95, 215, 290, 334, 390, 780]; % rad/s;
zeta_zeros_est = [0.07, 0.1, 0.1, .05, 0.03, 0.08, 0.3];

% Initial transfer 
P_init = 1/(m*s^2);
for ii = 1:length(w_poles_est)
    resonance = w_poles_est(ii)^2/(s^2 + 2*w_poles_est(ii)*zeta_poles_est(ii)*s + w_poles_est(ii)^2); % magnitude 1 at s = 0
    P_init = P_init*resonance;
end
for ii = 1:length(w_zeros_est)
    antiresonance = (s^2 + 2*w_zeros_est(ii)*zeta_zeros_est(ii)*s + w_zeros_est(ii)^2)/(w_zeros_est(ii)^2); % magnitude 1 at s = 0
    P_init = P_init*antiresonance;
end
P_init = ss(P_init);
Pd_init = c2d(P_init,Ts);

% IO delay
t_io_delay = 0.00079153; % s

P_init_io = P_init; P_init_io.InputDelay = t_io_delay;

bode(P_init_io)

%% Plot zero and pole locations 
% Find real value in frequency array, above are read from a plot
w_repped = repmat(f*2*pi,[1, length(w_poles_est)]);
[~, id_poles] = min(abs(w_repped - w_poles_est));
w_poles = w(id_poles);
P_poles = P_(id_poles);

w_repped = repmat(f*2*pi,[1, length(w_zeros_est)]);
[~, id_zeros] = min(abs(w_repped - w_zeros_est));
w_zeros = w(id_zeros);
P_zeros = P_(id_zeros);

% Plot them
figure(fig_bode);
axes(fig_bode.Children(3)); hold on;
plot(w_poles, mag2db(abs(P_poles)), 'kx')
plot(w_zeros, mag2db(abs(P_zeros)), 'ko')

%% Select relevant frequency range
w_min = 20;
w_max = 1000;
selection_w = w >= w_min & w <= w_max;

P_sliced_ = P_(selection_w);

%% Fit
P_est_idft = tfest(frd(P_sliced_,w(selection_w)), P_init_io);
num = P_est_idft.Numerator;
den = P_est_idft.Denominator;

%% Remove low frequency shit
P_est_zpk = zpk(minreal(tf(num,den)));
P_est_zpk.p{1}(end-1:end) = 0; % Set last two poles to 0
P_est = ss(P_est_zpk);
P_est.InputDelay = t_io_delay;
figure(fig_bode);
bode(P_est);
color = fig_bode.Children(2).Children(1).Children.Color;

P_est_ = freqresp(P_est,w);
for ii = 1:length(P_est_zpk.z{1})
    zii = P_est_zpk.z{1}(ii);
    if imag(zii) ~= 0
        omega_ii = imag(zii);
        [~, id_zero] = min(abs(w - omega_ii));
        plot(w(id_zero),mag2db(abs(P_est_(id_zero))),'Color',color,'Marker','o')
    end
end

for ii = 1:length(P_est_zpk.p{1})
    pii = P_est_zpk.p{1}(ii);
    if imag(pii) ~= 0
        omega_ii = imag(pii);
        [~, id_pole] = min(abs(w - omega_ii));
        plot(w(id_pole),mag2db(abs(P_est_(id_pole))),'Color',color,'Marker','x')
    end
end

%% Discretize
Pd_est = c2d(P_est, Ts);

Pphi_CT = P_est;
Pphi_DT = Pd_est;
save('Pphi_fit','Pphi_CT','Pphi_DT')

%% Plot final
figure;
h_bode = bodeplot(P_frd);
hold on;
bodeplot(Pd_est);
setoptions(h_bode,'PhaseWrapping','on');
xlim([w(2),max(w)])

%% Check I - GS L 
L = Pd_est^-1;
L_ = freqresp(L,w);
L_frd = frd(L_,w);
figure; bodemag(1 - P_frd*L_frd);