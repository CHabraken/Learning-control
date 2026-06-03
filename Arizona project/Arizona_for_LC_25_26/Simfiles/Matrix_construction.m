clear all
%% Parameters and settings
Ts = get_Arizona_pars();
N_trials = 15; % 1,...,N_trial
Ts = 0.001; % sampling time
%% Generate reference
% [xref, yref, phiref, t] = reference_square(Ts);
%[xref, yref, phiref, t] = reference_triangle(Ts);
% [xref, yref, phiref, t] = reference_rounded_rectangle(Ts);
load('test_reference.mat')
N = 13000;
[yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
xref = xref*0;
t = t';
% traj_number = 1;    
% % size_i = length(yRefs{traj_number});
% size_i = 1;
% times = linspace(0,size_i/Ts,size_i)';
% xref = zeros(size_i,1);
% yref = yRefs{:,traj_number};
% phiref =zeros(size_i,1);
% t = times;

Nref = length(xref);


