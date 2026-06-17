%% Description
%RUN_Arizona_base
% Minimum working example for working with Arizona. 
%
% Author: Johan Kon
% Date:   May 2022
%
% Note: penholder activity not allowed during ILC trials (will result in
% variations of the trial length)

%%
clear variables; close all; clc;

%% Paths
addpath('../Controllers')
addpath('../Helper_functions')
addpath('../Models')
addpath('../Pars')
addpath('../Plotter_functions')
addpath('../Reference_generators')
addpath('./Simulink')
addpath('../Target_interfacing')
addpath('../Build')
addpath('../Utility_functions')
addpath('../Penholder_settings')
addpath('../ILC_updates/Ricatti_NO_ILC')
addpath('../References')

%% Parameters and settings
Ts = get_Arizona_pars();
N_trial = 5; % 0,1,...,N_trial-1
learningGain = [0.5*ones(10,1);0.3*ones(10,1);0.1*ones(10,1)];

% Pen holding mechanism
PenONOFF        = 1;                                                        % 0 = OFF,    1 = ON
ColorManualAuto = 1;                                                        % 0 = Manual, 1 = Auto-rotate clockwise

PenColor        = [1 2 3 4];                                                % array of pen color positions
PenColor = penholder_settings(N_trial, ColorManualAuto, PenONOFF, PenColor);%[1,2,3,4 = pen positions, 5 = pen up, must be same length as amount of trials]

% Generate reference
ref = 'final_path_v3';
switch ref
    case 'point2point'
        load('Reference_point2point.mat')
    case 'straight_lines'
        load('Reference_between_straight_lines.mat')
        N = 5000;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'square'
        load('Reference_square.mat')
        N = 4500;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'Reference_4th_order'
        load('Reference_4th_order.mat')
        N = 5973;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'X_Arizona'
        load('Reference_X_Arizona_nonan.mat')
        N = 6873;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'final_path_v2'
        load('final_path_v2.mat')
        N = 6873;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'final_path_v3'
        load('X_Arizona_padded.mat')
        N = 6873+500;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
end
Nref = N;

% Homing to center
% These ones are loaded in the homing procedure. Automatically loaded, not
% set via target struct.
GenerateInit_Center;

%% Load  loop system (after decoupling) and controllers
% y translation
load('yController.mat')
Cy = Cy_DT;
load('Py_Fit_Final.mat')
Py = Py_DT;

% x translation
load('xController.mat');
Cx = Cx_DT;
load('Px_Fit_Final.mat')
Px = Px_DT;

% phi rotation
load('phiController.mat');
Cphi = Cphi_DT;
load('Arizona_model_unknown_Phi.mat')
Pphi = Pphi_DT;

%% Interconnection.
SPy = minreal(feedback(Py, Cy));
SPx = minreal(feedback(Px, Cx));
SPphi = minreal(feedback(Pphi, Cphi));
% Number of states, inputs and outputs.
no = 3; ni = 3;

%% ILC startup initialization
% load('Matrices_QP.mat')
% load('Matrices_QP_X_Arizona.mat')
% load('Matrices_QP_X_Arizona_weights.mat')
load('Matrices_QP_X_Arizona_padded.mat')

use_lowpass = 1;    % if 0, no lowpass, if 1 lowpass is used on f_jplus1
lowpass_pole = 20;  % [Hz], pole of the lowpass filter on f_jplus1

%% Allocate memory.
% history struct. All communication and plotting done through this struct
% Order is always [y x phi]!
history.eNorm = NaN(N_trial,no,1);
history.e = NaN(N_trial,Nref,no); % [Trial, time, dim]
history.f = NaN(N_trial,Nref,ni); % [Trial, time, dim]
history.r = NaN(N_trial,Nref,no); % [Tial, time, dim]
history.p = NaN(N_trial,Nref,no);
history.t = t;
history.trials = 1:N_trial;
history.Nref = Nref;

% Penholder struct
pen.onoff = PenONOFF;
pen.manualauto = ColorManualAuto;
pen.color = PenColor;
history.pen = pen;

%% Initial FFW and reference
history.r(1,:,:) = [yref, xref, phiref]; % Order [y x phi]
history.f(1,:,:) = zeros(Nref,ni);
PlotTrialDataContour(history,0,1,0,0,1,0,0); % Plots initial input
PlotTrialDataContour(history,1,0,0,0,0,1,0); % Plots reference

%% Configure model
% Get connection to target.
tg = SimulinkRealTime.target;

cd('../Build');
rtwbuild('Arizona_base');
cd('../Runfiles');

% Check loaded model.
if ~strcmp(tg.Application,'Arizona_base')
    error('Incorrect model loaded.');
end

% Create file system object.  
fsys = SimulinkRealTime.fileSystem;

% Clear all scopes.
tg.remscope;

% Add scopes to target.
AddScopes_target;

% Add file scope.
fileScope = tg.addscope('file');

fileScope.addsignal(tg.getsignalid('log_jogspeed'));
fileScope.addsignal(tg.getsignalid('log_r_y'));
fileScope.addsignal(tg.getsignalid('log_r_x'));
fileScope.addsignal(tg.getsignalid('log_r_phi'));
fileScope.addsignal(tg.getsignalid('log_f_y'));
fileScope.addsignal(tg.getsignalid('log_f_x'));
fileScope.addsignal(tg.getsignalid('log_f_phi'));
fileScope.addsignal(tg.getsignalid('log_u_y'));
fileScope.addsignal(tg.getsignalid('log_u_x'));
fileScope.addsignal(tg.getsignalid('log_u_phi'));
fileScope.addsignal(tg.getsignalid('log_e_y'));
fileScope.addsignal(tg.getsignalid('log_e_x'));
fileScope.addsignal(tg.getsignalid('log_e_phi'));
fileScope.addsignal(tg.getsignalid('log_y'));
fileScope.addsignal(tg.getsignalid('log_x'));
fileScope.addsignal(tg.getsignalid('log_phi'));
fileScope.addsignal(tg.getsignalid('log_penholder_active'));
fileScope.addsignal(tg.getsignalid('log_u_phi_fb_diff'));

fileScope.NumSamples = N;
fileScope.TriggerMode = 'Signal';
fileScope.TriggerSignal = tg.getsignalid('log_trialTrigger');
fileScope.TriggerLevel = 0.5;
fileScope.TriggerSlope = 'Rising';
fileScope.FileName = 'trialDat.dat';

% IDs.
paramid_startPenholder  = tg.getparamid('startPenholder','Value');
paramid_startTrial      = tg.getparamid('startTrial','Value');
paramid_PenColor        = tg.getparamid('PenColor','Value');
paramid_Homing          = tg.getparamid('Homing/home','Value');

paramid_ref_y      = tg.getparamid('Trajectory/set_yRef','Value');
paramid_ref_x      = tg.getparamid('Trajectory/set_xRef','Value');
paramid_ref_phi    = tg.getparamid('Trajectory/set_phiRef','Value');

paramid_ff_y       = tg.getparamid('Feedforward/set_yFF','Value');
paramid_ff_x       = tg.getparamid('Feedforward/set_xFF','Value');
paramid_ff_phi     = tg.getparamid('Feedforward/set_phiFF','Value');

%% Experiment.
fileScope.start;
% Select to home or not.
% Add to list of to set variables
tg.setparam(paramid_PenColor,PenColor(1));
tg.setparam(paramid_Homing,1);

% Start experiment.
tg.start;

% Await homing procedure.
while ~tg.getsignal(tg.getsignalid('log_homingDone'))
    pause(0.1);
end

tg.setparam(paramid_ref_y,squeeze(history.r(1,:,1)'));
tg.setparam(paramid_ref_x,squeeze(history.r(1,:,2)'));
tg.setparam(paramid_ref_phi,squeeze(history.r(1,:,3)'));

%% Trial execution.
% Move penholder down
tg.setparam(paramid_startPenholder,1);

% Different loop indices
for trial = 0:N_trial-1
    jj = trial + 1; % Change loop to jj, indexing from 1 because matlab!
    
    % Display trial number.
    fprintf(['Trial %',num2str(numel(num2str(N_trial-1))),'d/%d finished.\n'],trial,N_trial-1);
           
    % Set feedforward
    tg.setparam(paramid_ff_y  , squeeze(history.f(jj,:,1)'));
    tg.setparam(paramid_ff_x  , squeeze(history.f(jj,:,2)'));
    tg.setparam(paramid_ff_phi, squeeze(history.f(jj,:,3)'));
    
    % Check feedforward signal
    CheckFeedforward;
    
    % Increase trial in plot
    PlotTrialDataContour(history,jj,0,1,0,0,0,0);
    
    % Always wait until penholder is idle
    % Only ak for signal ID once, then reuse
    while tg.getsignal(tg.getsignalid('log_penholder_active'))
        pause(0.1);
    end

    % Execute trial.
    fileScope.start;
    tg.setparam(paramid_startTrial,1);
    tg.setparam(paramid_PenColor,PenColor(trial+2));
    tg.setparam(paramid_startTrial,0);
    
    % Wait until done
    while tg.getsignal(tg.getsignalid('log_trialTrigger'))
        pause(0.1);
    end
    
    if trial == N_trial-1
        % Move penholder up
        tg.setparam(paramid_startPenholder,0);
        % Wait until finished
        pause(0.1);
        while tg.getsignal(tg.getsignalid('log_penholder_active'))
            pause(0.1);
        end
    end
    fileScope.stop;
    
    % Extract data.
    h = fsys.fopen('trialDat.dat');
    xpcfile_data = fsys.fread(h);
    fsys.fclose(h);
    matlab_data = SimulinkRealTime.utils.getFileScopeData(xpcfile_data);
    for sigID = 1:matlab_data.numSignals
        assignin('base',strrep(strrep(matlab_data.signalNames{sigID},' ',''),'/',''),matlab_data.data(:,sigID))
    end
       
    % Compose signals.
    f_j = [log_f_y, log_f_x, log_f_phi];
    u_j = [log_u_y, log_u_x, log_u_phi];
    e_j = [log_e_y, log_e_x, log_e_phi]; 
%     p_j = [log_y, log_x, log_phi];
%     r_j = [log_r_y, log_r_x, log_r_phi];
    r_j = squeeze(history.r(jj,:,:)); % not logged reference, that one has an offset, thus cannot compare to reference in this script!
    p_j = r_j - e_j; 
    
    % Store trial data
    % Store position and error corresponding to reference and ffw
    history.p(jj,:,:)       = p_j;
    history.e(jj,:,:)       = e_j;
    history.eNorm(jj,:,:)   = vecnorm_2016b(e_j);
        
    % Update figure.
    PlotTrialDataContour(history,jj,0,0,0,0,0,1); % Plots error and position
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    % Select new reference
    if jj == -1
        change_ref = 1;
    else
        change_ref = 0;
    end
    if change_ref
        [yref, xref, phiref] = reference_triangle(Ts);
        [yref, xref, phiref, t] = pad_reference_to_N(yref, xref, phiref,N, Ts);
        r_jplus1 = [yref, xref, phiref]; % Order [y x phi]
    else
        r_jplus1 = history.r(jj,:,:); % Reference is trial-invariant here
    end
    history.r(jj+1,:,:) = r_jplus1;
    
    
    % Select new FFW
    change_ffw = 1;
    Npad = 1e4;
    if change_ffw
        % ILC update law, function of history and spits out new ffw
        tic
        f_jplus1 = ILC_update_zeros(e_j, f_j, H_y, H_x, M1y, M2y, M1x, M2x, Ts, lowpass_pole, use_lowpass);
        toc
    else
        f_jplus1 = f_j; 
    end
    f_jplus1(1:230,1) = 0;
    f_jplus1(1:230,2) = 0;
    history.f(jj+1,:,:) = f_jplus1;

    % Update ref. FFW is updated at start of loop
    if change_ref
        PlotTrialDataContour(history,jj+1,0,0,0,0,1,0); % Plots reference
        tg.setparam(paramid_ref_y,squeeze(history.r(jj+1,:,1)'));
        tg.setparam(paramid_ref_x,squeeze(history.r(jj+1,:,2)'));
        tg.setparam(paramid_ref_phi,squeeze(history.r(jj+1,:,3)'));
    end
    PlotTrialDataContour(history,jj,0,0,0,1,0,0); % Plots new ffw

end

%% End experiment.
pause(1);

% Always wait until penholder is finished/idle
% Move penholder up
tg.setparam(paramid_startPenholder,0);
        
while tg.getsignal(tg.getsignalid('log_penholder_active'))
    pause(0.1);
end
tg.stop;

% Save data.
% save('ExperimentalResults','-regexp', '^(?!(ans|fsys|tg|scope_.*|.*Scope|x_j.*|W_.*|I|J|Q|L)$).');