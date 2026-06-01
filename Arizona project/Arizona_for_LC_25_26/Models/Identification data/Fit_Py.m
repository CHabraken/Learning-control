clear; close all; clc
%% Load
load('Py_frf_CL_6.mat')
f = Py_frf_CL_6(:,1);
w = 2*pi*f;
P_ = Py_frf_CL_6(:,2);
P_frd = frd(P_,w);

% unit transfers
Ts = 1/1000;
z = tf('z',Ts);
delta = (1-z^-1)/Ts;
s = tf('s');
s_ = freqresp(s, w); s_ = squeeze(s_);

% Remove -2 slope
Ps_squared_ = s_.^2.*P_;

% Correct for mass offset
w_mass_line = [7.1, 23.7]; % rad/s
w_mass_line_selection = w >= w_mass_line(1) & w <= w_mass_line(2);
m = 1/mean(abs(Ps_squared_(w_mass_line_selection)));

Ps_squared_at_zero_ = Ps_squared_*m;
Ps_squared_at_zero_frd = frd(Ps_squared_at_zero_, w);

% Plot
fig_bode = figure;
h_bode = bodeplot(P_frd); hold on;
setoptions(h_bode,'PhaseWrapping','on');
xlim([w(2),max(w)])
fig_bode.Position = [770    42   766   738];

fig_bode_s_squared = figure;
h_bode_s_squared = bodeplot(Ps_squared_at_zero_frd); hold on;
setoptions(h_bode_s_squared,'PhaseWrapping','on');
xlim([w(2),max(w)])
fig_bode_s_squared.Position = [1    42   766   738];

%% Initial estiamte
% freqs and normalized damping of resonances
w_poles_est =   [68.6, 82.8, 121, 157,  194,  222, 414]; % rad/s
zeta_poles_est= [0.05,  .06, .03, .09, 0.06, 0.06, .1];  

w_zeros_est =    [54.4, 73.4, 116,  144,  182, 208, 284]; % rad/s;
zeta_zeros_est = [0.05, 0.03, .02, 0.05, 0.03, .02, 0.1];

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

P_init_ms_squared = minreal(ss(m*s^2*P_init));
Pd_init_ms_squared = c2d(P_init_ms_squared,Ts);

% IO delay
t_io_delay = 0.00079153; % s

P_init_io = P_init; P_init_io.InputDelay = t_io_delay;

% Plot it
figure(fig_bode); bode(P_init); bode(Pd_init); bode(P_init_io);
figure(fig_bode_s_squared); bode(P_init_ms_squared); bode(Pd_init_ms_squared);

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
w_min = 30;
w_max = 700;
selection_w = w >= w_min & w <= w_max;

P_sliced_ = P_(selection_w);

%% Fit
P_est_idft = tfest(frd(P_sliced_,w(selection_w)), P_init_io);
num = P_est_idft.Numerator;
den = P_est_idft.Denominator;

%% Remove low frequency shit
P_est_zpk = zpk(tf(num,den));
P_est_zpk.p{1}(end-1:end) = 0; % Set last two poles to 0
P_est = ss(P_est_zpk);

P_est.InputDelay = t_io_delay;

%% Discretize
Pd_est = c2d(P_est, Ts, 'foh');

% Save to matfile
Px_CT = P_est;
Px_DT = Pd_est;
save('Px_fit','Px_CT','Px_DT')

%% Plot
figure(fig_bode);
bode(P_est);

% close all;
figure;
h_bode = bodeplot(P_frd);
hold on;
bodeplot(Pd_est);
% bodeplot(Pd_est_iodelay); % Transport dleay 
setoptions(h_bode,'PhaseWrapping','on');
xlim([w(2),max(w)])