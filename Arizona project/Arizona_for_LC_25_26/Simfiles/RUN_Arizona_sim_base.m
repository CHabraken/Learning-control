%% Description
%RUN_Arizona_sim_base   
% Simulation equivalent of minimum working example for working with Arizona. 
%
% Author: Johan Kon
% Date:   April 2021
%

%%
clear variables; close all; clc;
%% Paths
addpath(genpath('../Controllers'))
addpath(genpath('../Helper_functions'))
addpath(genpath('../Models'))
addpath(genpath('../Pars'))
addpath(genpath('../Plotter_functions'))
addpath(genpath('../Reference_generators'))
addpath(genpath('../References'))
addpath(genpath('Simulink'))
addpath(genpath('../Target_interfacing'))
addpath(genpath('../Build'))
addpath(genpath('../Utility_functions'))
addpath(genpath('../ILC_updates'))
addpath(genpath('../Models_new/Models/Parametric'))
%% Parameters and settings
Ts = get_Arizona_pars();
N_trial = 5; % 1,...,N_trial
Ts = 0.001; % sampling time

%% Generate reference
% [xref, yref, phiref, t] = reference_square(Ts);
% [xref, yref, phiref, t] = reference_triangle(Ts);
% [xref, yref, phiref, t] = reference_rounded_rectangle(Ts);
% load('test_reference.mat')
load('Reference_X_slow');
N = 13000;
[yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
% xref = xref*0;
yref = yref*0;
t = t';
% traj_number = 1;    
% % size_i = length(yRefs{traj_number});
% size_i = 1;
% times = linspace(0,size_i/Ts,size_i)';
% xref = zeros(size_i,1);
% yref = yRefs{:,traj_number};
% phiref = zeros(size_i,1);
% t = times;

Nref = length(xref);
%% Load  loop system (after decoupling) and controllers

% y translation
load('yControllerBad.mat')
Cy = shapeit_data.C_tf;
Cy_DT = shapeit_data.C_tf_z;
load('Py_fit.mat')
Py = Py_CT;


% x translation
load('xControllerBad.mat');
Cx = shapeit_data.C_tf;
Cx_DT = shapeit_data.C_tf_z;
load('Px_fit.mat')
Px = Px_CT;

% phi rotation
load('phiController.mat');
Cphi = Cphi_CT;
load('Pphi_fit.mat')
Pphi = Pphi_CT;

% Interconnection.
SPy = minreal(feedback(Py_DT, Cy_DT));
SPx = minreal(feedback(Px, Cx));
SPphi = minreal(feedback(Pphi, Cphi));
SP = SPy;
   

% Stack for MIMO
C_zpk = blkdiag(Cy, Cx, Cphi);
P_zpk = blkdiag(Py, Px, Pphi);

%% -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
% The decoupled plant (Need to copy to Run file)
% -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
% The length of the gantry
L = 2.62;

% The MIMO model
P_mimo = load('P_centralized.mat').Pz;

% The decoupled MIMO model
Ty = [0.5 0.5; -1/L 1/L];
Tu = [0.5 -1/L; 0.5 1/L];
P_d = Ty*P_mimo*Tu;

% Making the MIMO controller.
C_mimo = blkdiag(Cx_DT, Cphi_DT);

% Sensitivity functions
loops = loopsens(P_d,C_mimo);
GS_mimo = loops.PSi;
S_mimo = loops.So;
T_mimo = loops.Ti;

%% -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
% Parameterize input shaper Cy (need to copy to run file)
% -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
ni = 3;
no = 3; 
% initialize shaped reference


na = 2;
Psi_y = tf(zeros(1,na));
for i = 1:na
    num = zeros(1,i+1);
    for k = 0:i
        num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
    end
        Psi_y(i) = minreal(tf(num,1,Ts,'Variable','z^-1'));
end
    
%% -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-    
% Parameterize feedforward Cff (need to copy to run file)
% -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

nb_x = 4;
Psi_ff_x = tf(zeros(1,nb_x));
for i = 1:nb_x
    num = zeros(1,i+1);
    for k = 0:i
        num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
    end
        Psi_ff_x(i) = minreal(tf(num,1,Ts,'Variable','z^-1'));
end

nb_phi = 4;
Psi_ff_phi = tf(zeros(1,nb_phi));
for i = 1:nb_phi
    num = zeros(1,i+1);
    for k = 0:i
        num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
    end
        Psi_ff_phi(i) = minreal(tf(num,1,Ts,'Variable','z^-1'));
end

Psi = minreal([Psi_y, Psi_ff_x, Psi_ff_phi]);

history.r_y = zeros(N_trial,Nref,no); 

%% -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
% lifted ILC (Need to copy to run file)
% -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

% Intial theta
theta_init = zeros(size(Psi,2),N_trial);

% Defining the weighting Mats.
weight.wdf      = 0e-6;
weight.wry      = 0;
weight.wdry     = 0;
weight.we_x     = 1e5;
weight.we_phi   = 1e1;
weight.wf_x     = 1e-4;
weight.wf_phi   = 5e-7;
weight.wdf_x    = 1e-1;
weight.wdf_phi  = 1e-1;

% Calulating some weighting mats.
[weight.We_sq, weight.Wry_sq, weight.Wdry_sq, weight.Wf_sq, weight.Wdf_sq] = calcWeightingMats(Nref, weight);

%% ======================================================
% ILC startup initialization: your code here!
% =======================================================





%% Initialization
% history struct. All communication and plotting done through this struct.
% Order is always [y x phi]!
history.eNorm = NaN(N_trial,no,1);
history.e = NaN(N_trial,Nref,no); % [Trial, time, dim]
history.epsilon = NaN(N_trial,Nref,1);
history.epsilonNorm = NaN(N_trial,1);
history.f = NaN(N_trial,Nref,ni); % [Trial, time, dim]
history.r = NaN(N_trial,Nref,no); % [Tial, time, dim]
history.p = NaN(N_trial,Nref,no);
history.t = t;
history.trials = 1:N_trial;
history.Nref = Nref;

history.theta = theta_init;
history.theta(4,1) = 5e6;
history.e_y = NaN(N_trial,Nref,no);
history.weight = weight;

% Initial FFW and reference
history.r(1,:,:) = [yref, xref, phiref]; % Order [y x phi]
history.f(1,:,:) = zeros(Nref,ni);
PlotTrialDataContour(history,0,1,0,0,1,0,0,0); % Plots initial input
PlotTrialDataContour(history,1,0,0,0,0,1,0,0); % Plots reference

%% Execute trials
for jj = 1:N_trial
    % Display trial number.
    fprintf(['Trial %',num2str(numel(num2str(N_trial-1))),'d/%d finished.\n'],jj,N_trial);
    
    % Increase trial in plot
    PlotTrialDataContour(history,jj,0,1,0,0,0,0,0);
    
    % Set reference and feedforward. Used like this in simulink
    f_j = squeeze(history.f(jj,:,:));
    r_j = squeeze(history.r(jj,:,:));  
        
    % Execute trial.
    cd('..\Build') % To make sure sjlpr etc. end up in that folder
    sim('Arizona_sim_base.slx')
    cd('..\Simfiles')
    
    [epsilon, epsilon_vec, refc] = estimate_contour_error(r_j(:,2), r_j(:,1), y_j(:,2), y_j(:,1), 2000, 1);

    % Store position and error corresponding to reference and ffw
    history.p(jj,:,:)       = y_j;
    history.e(jj,:,:)       = e_j;
    history.eNorm(jj,:,:)   = vecnorm(e_j);
    history.epsilon(jj,:)   = epsilon;
    history.epsilonNorm(jj) = vecnorm(epsilon);
    
    PlotTrialDataContour(history,jj,0,0,0,0,0,1,0); % Plots error and position
    
    % Select new reference and feedforward.
    if jj ~= N_trial
        r_jplus1 = r_j; % Reference is trial-invariant here
        
        %% Your code here
        f_jplus1 = ILC_update_zeros(e_j,f_j);
        % f_jplus1 = feedforwardUpdateSim(SP,t,r_j,e_j,f_j,Ts);

        %% -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        % Made a small change in the arguments of this function s.t. it can
        % take in the weight structure.
        theta_delta = FeedforwardUpdate_BFIS_simo(na,nb_x,nb_phi,Psi,Nref,S_mimo,GS_mimo,weight,e_j,squeeze(history.r_y(jj,:,:)),f_j,xref,t,Ts);
        

        Cy  = minreal(1 + Psi_y*history.theta(1:na,jj));
        Cff_x = minreal(Psi_ff_x*history.theta(na+1:na+nb_x,jj));
        Cff_phi = minreal(Psi_ff_phi*history.theta(na+nb_x+1:end,jj));
        

        f_jplus1 = zeros(Nref,ni);
        f_jplus1(:,2) = brfus_v003(Cff_x,xref,t,Ts);
        f_jplus1(:,3) = brfus_v003(Cff_phi,xref,t,Ts);
        % ry_plus1 = history.r(jj+1,:,:);
        ry_plus1 = brfus_v003(Cy,xref,t,Ts);
        
        theta_jplus1= history.theta(:,jj) + theta_delta;




        %%       
        % Store in FFW
        history.r(jj+1,:,:) = r_jplus1;
        history.f(jj+1,:,:) = f_jplus1;
        history.theta(:,jj+1) = theta_jplus1;
        
        PlotTrialDataContour(history,jj,0,0,0,1,0,0,0); % Plots new ffw
    end
end