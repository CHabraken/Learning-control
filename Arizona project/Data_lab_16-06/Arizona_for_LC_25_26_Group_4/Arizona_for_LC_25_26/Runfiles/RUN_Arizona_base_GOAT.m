% +-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-
% ------------------------> Arizona Main Script <--------------------------
% This Matlab scribt is used to operate the Arizona printer in the DCT lab
%
% Author: Johan Kon, Peter Visser, Maarten van der Hulst
% Date:   July 2023
%
% Note: penholder activity not allowed during ILC trials (will result in
% variations of the trial length)

% Note: penholder not working
% +-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-

init_Arizona

%% ========================================================================
% ARIZONA OPTIONS - settings that can be changed
% =========================================================================

% Build options
optBuild              = false;              % (true/false)                 % When building, always make sure the POWER IS TURNED OFF
optSDIviewer          = false;               % (true/false)                  % Open simulink data inspector
clear_optBuild                                                             

% Homing options
optHomeDuringTrials   = false;               % (true/false)                % Set if trial should start with homing sequence

% Reference options                                                         
optSelectRef          = 'Gantry_slow';                                      % Set reference.   Change details in 'select_reference.m'
optSelectRef2         = 'ref2';                                             % Set reference 2. Change details in 'select_reference.m'
optRefDirections      = [0,1,0]              % (0=OFF, 1=ON)                % Set direction [y x phi] to apply reference
optTrialRefSwitch     = -1;                                                 % Set trial # reference change. Update on trial N+1

% Feedforward options                                                       
optFFmethod           = 'ILC_BF_IS'               % (off/ILC/other)               % Set Feedforward method. Change details ILC in 'feedforwardUpdate_XXX.m' 
optFFdirections       = [0,1,0]             % (0=OFF, 1=ON)                 % Set direction [y x phi] to apply feedforward
N_trial               = 50;                                                 % Set # trials
                                           
%% ========================================================================
% ARIZONA OPTIONS - settings that CANNOT be changed
% =========================================================================
BadControllers        = true;               % (true/false) if true, uses worse controllers (fbw~4 Hz), nice for demonstration penholder 

optHomePosition       = 'corner';            % (center/corner)              % Set homing position

% Penholder options (NOT WORKING)
PenONOFF              = 0;                  % (0=OFF, 1=ON)
ColorManualAuto       = 1;                                                  % 0 = Manual, 1 = Auto-rotate clockwise
PenColor              = [1 2 3 4];                                          % array of pen color positions

%% ========================================================================
% Build
% =========================================================================

if optBuild == true
    % Set penholder options (NOT WORKING)   
    % PenColor = penholder_settings(N_trial, ColorManualAuto,...
%            PenONOFF, PenColor);                                           % [1,2,3,4 = pen positions, 5 = pen up, must be same length as amount of trials]

    % Load trajectories
    [yref, xref, phiref, t, Nref] = select_reference(optSelectRef, Ts);             
    yref = round(yref*optRefDirections(1),16); 
    xref = round(xref*optRefDirections(2),16);
    phiref = round(phiref*optRefDirections(3),16);

    [yref2, xref2, phiref2, t2, Nref2] = select_reference(optSelectRef2, Ts);             
    yref2 = round(yref2*optRefDirections(1),6); 
    xref2 = round(xref2*optRefDirections(2),6);
    phiref2 = round(phiref2*optRefDirections(3),6);
    
    % Match array lengths ref1 and ref2
    if optTrialRefSwitch > 0
        if Nref > Nref2
            % Padzeros to ref2 match array length ref1
            [yref2, xref2, phiref2, t2] = pad_reference_to_N_zeros(yref2, xref2, phiref2,Nref, Ts);
        else
            % Padzeros to ref1 match array length ref2
            [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,Nref2, Ts);
        end
    end

    % Load homecenter
    [y_Init,x_Init,phi_Init, N_Init] = fGenerateInit_Center(Ts,optHomePosition);       

    % y translation 
    load('yController.mat')
    load('yControllerBad.mat');
    if BadControllers
        Cy = shapeit_data.C_tf_z;
    else
        Cy = Cy_DT;
    end
    load('Py_fit.mat')
    Py = Py_DT;

    % x translation
    load('xController.mat');
    load('xControllerBad.mat');
    
    if BadControllers
        Cx = shapeit_data.C_tf_z;
    else
        Cx = Cx_DT;
    end
    load('Px_fit.mat')
    Px = Px_DT;
    
    % phi rotation
    load('phiController.mat');
    Cphi = Cphi_DT;
    load('Pphi_fit.mat')
    Pphi = Pphi_DT;
    
    % Process sensitivity
    SPy = minreal(feedback(Py, Cy));
    SPx = minreal(feedback(Px, Cx));
    SPphi = minreal(feedback(Pphi, Cphi));
    SP = {SPy, SPx, SPphi};
   
    % Sensitivity
    Sy = minreal(feedback(1, Py*Cy));
    Sx = minreal(feedback(1, Px*Cx));
    Sphi = minreal(feedback(1, Pphi*Cphi));
    S = {Sy, Sx, Sphi};

    % Number of inputs and outputs.
    no = 3; ni = 3;
    
    % Prompt to check Arizona power is off
    waitfor(msgbox('Confirm that Arizona power switch is off!','Check'));
   
    % Get connection to target.
    model = 'Arizona_base_GOAT';
    tg = slrealtime('TargetPC1');
    
    % Open, build and load model
    cd('../Build');
    open(model);
    slbuild(model)
    tg.load(model)
    cd('../Runfiles');
    
    % Initial parameters
    startPenholder   = get_param_Arizona('startPenholder',tg);              
    startTrial       = get_param_Arizona('startTrial',tg);
    PenColor_setting = get_param_Arizona('PenColor',tg); 
    startHoming      = get_param_Arizona('startHoming',tg); 

    ref_y            = get_param_Arizona('set_yRef',tg); 
    ref_x            = get_param_Arizona('set_xRef',tg); 
    ref_phi          = get_param_Arizona('set_phiRef',tg); 
        
    ff_y             = get_param_Arizona('set_yFF',tg); 
    ff_x             = get_param_Arizona('set_xFF',tg); 
    ff_phi           = get_param_Arizona('set_phiFF',tg);

    % Check loaded model.
    if ~strcmp(tg.ModelStatus.Application,'Arizona_base_GOAT')
        error('Incorrect model loaded.');
    elseif length(ref_y) ~= length(yref)
        error(['Array sizes of workspace and simulink do not match!...' ...
        'Make sure to delete all .mldatx and slrealtime_rtw files in directory or check reference generator']);
    end

    % Start running the speedgoat signals on the Arizona
    tg.start()

    % Initial stopRecording, needs to be done before you can startRecording
    stopRecording(tg); 

    % Monitor reply
    disp('Building done. Re-run the script with the optBuild=false to start the experiment.');

    % Enable motor amplifiers
    enable_motor_amplifiers(1, tg)

    return;
end

%% ========================================================================
% Pre-computations for ILC-BFIS (if required)
% you might want to expand the history struct with more variables
% =========================================================================
if strcmp(optFFmethod, 'ILC_BF_IS')

    % order of FF and IS filters
    na = 0;  % Order input shaper Cy
    nb = 0;  % Order feedforward Cff

    % your code here ...



    history.r_y = zeros(N_trial,Nref,no);                                   % initialize shaped reference
end

%% ========================================================================
% Init ILC settings
% =========================================================================
% Allocate memory -> history struct. All communication and plotting done through this struct
% Order is always [y x phi]!
history.eNorm = NaN(N_trial,no,1);
history.e = NaN(N_trial,Nref,no);                                           % [Trial, time, dim]
history.epsilon = NaN(N_trial,Nref,1);
history.epsilonNorm = NaN(N_trial,1);
history.f = NaN(N_trial,Nref,ni);                                           % [Trial, time, dim]
history.fupdate = NaN(N_trial,Nref,ni);                                     % [Trial, time, dim]
history.r = NaN(N_trial,Nref,no);                                           % [Trial, time, dim]
history.p = NaN(N_trial,Nref,no);
history.p2 = NaN(N_trial,Nref,no);                                          % positions of secondary motor
history.t = t;
history.trials = 1:N_trial;
history.Nref = Nref;

% Penholder struct
pen.onoff      = PenONOFF;
pen.manualauto = ColorManualAuto;
pen.color      = PenColor;
history.pen    = pen;

% Initial FFW and reference
history.r(1,:,:) = [yref, xref, phiref];                                    % Order [y x phi]
history.f(1,:,:) = zeros(Nref,ni);
history.r_y(1,:,:) = history.r(1,:,:);
PlotTrialDataContour(history,0,1,0,0,1,0,0,0);                                % Plots initial input
PlotTrialDataContour(history,1,0,0,0,0,1,0,1);                                % Plots reference

% Prompt to check Arizona power is off
waitfor(msgbox('Confirm that the reference stays within bounds!','Check'));

%% ========================================================================
% Init Experiment
% =========================================================================
% Penholder mechanism (NOT WORKING)
% Set penholder settings
% set_param_Arizona('PenColor',PenColor(1),tg);

% Open Simulink realtime data viewer (replaces scopes on seperate monitor)
if optSDIviewer
    Simulink.sdi.view
end

% Prompt to check Arizona power is on
waitfor(msgbox('Confirm that the Arizona power switch is on! Check multimeter!','Check') );

% Set initial reference
set_new_ref(history.r(1,:,:),tg);


%% ========================================================================
% Start Experiment
% =========================================================================
% Penholder mechanism (NOT WORKING)
% % Move penholder down
% set_param_Arizona('startPenholder',1,tg);


for trial = 0:N_trial-1
    % Change loop to jj, indexing from 1 because matlab!
    jj = trial + 1; 

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % COMPUTE start of trial computations for BF-IS (e.g. Cy, Cff)??
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    % =====================================================================
    % Load and check feedforward signal and shaped reference signal
    % =====================================================================
    f1 = history.f(jj,:,1); f2 = history.f(jj,:,2); f3 = history.f(jj,:,3);
    f_appl  = [f1,  f2, f3];
    df_appl = [gradient(f1, Ts), gradient(f2, Ts), gradient(f3, Ts)];
    f_threshold = 10;


    r_y_appl  = [squeeze(history.r_y(jj,:,:))];
    dr_y_appl = [gradient(r_y_appl(:,1), Ts); gradient(r_y_appl(:,2), Ts); gradient(r_y_appl(:,3), Ts)];
    ddr_y_appl = [gradient(gradient(r_y_appl(:,1), Ts),Ts);...
                  gradient(gradient(r_y_appl(:,2), Ts),Ts);...
                  gradient(gradient(r_y_appl(:,3), Ts),Ts);];
    ddry_threshold = 5;

    % Check feedforward signal, loads it in model if good, then needs to be confirmed. Else: target is paused
    if any(abs(f_appl) > f_threshold) || sum(isnan(f_appl))
        waitfor(msgbox('New feedforward should not be loaded: out of bounds ('+string(f_threshold)+'V) or NaN! Ending operation'));
        break % makes the zero input feedforward the last trial

    % Check acceleration of r_y
    elseif any(abs(ddr_y_appl) > ddry_threshold)
        waitfor(msgbox('WARNING: acceleration ddr_y exceeds limit of '+string(ddry_threshold)+'!'));
        switch questdlg('WARNING: acceleration ddr_y exceeds limit; apply feedforward signal?','Confirmation','Yes')
            case 'Yes'
                set_new_feedforward(history.f(jj,:,:),tg);
            otherwise
                warning('New feedforward not loaded. Experiment interrupted.');
                break
        end
 
    % check passed: confirm feedforward signal.
    else
        switch questdlg('Apply feedforward signal?','Confirmation','Yes')
            case 'Yes'
                % Set new feedforward signal, will not be loaded otherwise
                set_new_feedforward(history.f(jj,:,:),tg);
            otherwise
                warning('New feedforward not loaded. Experiment interrupted.');
                break
        end
    end
    
    
    % =====================================================================
    % Home
    % =====================================================================
    if optHomeDuringTrials
        % Start homing sequence
        homing_sequence_Arizona
    else
        if jj == 1
            % Start homing sequence
            homing_sequence_Arizona
        end
    end
    
%     waitfor(msgbox('Confirm that Arizona power switch is off!','Check'));
    % =====================================================================
    % Start trial
    % =====================================================================
    % Always wait until penholder is idle
    while tg.getsignal('Arizona_base_GOAT/log_penholder_active',1)
        pause(0.1);
    end

    % Start 'streaming' data: logs trial data. Will be send *during* realtime run to workspace, *after* 'stopRecording' command is used
    startRecording(tg);

    % Execute trial
    set_param_Arizona('startTrial',1,tg);
%     set_param_Arizona('PenColor',PenColor(trial+2),tg);
    set_param_Arizona('startTrial',0,tg); % reset trial start setting
    
    % Wait until trial is done
    while ~tg.getsignal('Arizona_base_GOAT/Trajectory', 6) 
        pause(0.01)
    end

    % stop data streaming and send to workspace
    stopRecording(tg); 

% Penholder mechanism (NOT WORKING)
%     if trial == N_trial-1
%         % Move penholder up
%         set_param_Arizona('startPenholder',0,tg);
%         % Wait until finished
%         pause(0.1);
%         while tg.getsignal('Arizona_base_GOAT/log_penholder_active')
%             pause(0.1);
%         end
%     end
    
    % =====================================================================
    % Extract trial data
    % =====================================================================
    [f_j,u_j,e_j,p1_j,p2_j,y_j] = trialData_process(logsOut);                   % p1_j primair encoder data, p2_j secundair encoder data
    r_j = squeeze(history.r(jj,:,:));                                                                                     
    p_j = p1_j;                                                             

    % Calculate contour error
    [epsilon, epsilon_vec, refc] = estimate_contour_error(r_j(:,2), r_j(:,1), p_j(:,2), p_j(:,1), 3000, 1);
    
    % Store trial data
    % Store position and error corresponding to reference and ffw
    history.p(jj,:,:)       = p_j;
    history.p2(jj,:,:)      = p2_j;
    history.e(jj,:,:)       = e_j;
    history.eNorm(jj,:,:)   = vecnorm_2016b(e_j);
    history.epsilon(jj,:)   = epsilon;
    history.epsilonNorm(jj) = vecnorm_2016b(epsilon);

    % Display trial loop progress
    fprintf(['Trial %',num2str(numel(num2str(N_trial))),'d/%d finished.\n'],jj,N_trial);
        
    % Update figure
    PlotTrialDataContour(history,jj,0,1,0,0,0,0,0);                           % Increase trial in plot
    PlotTrialDataContour(history,jj,0,0,0,0,0,1,0);                           % Plots error and position
    
    % =====================================================================
    % Reference update
    % =====================================================================

    % Load new reference
    if jj == optTrialRefSwitch
        % Load reference2
        r_jplus1 = [yref2, xref2, phiref2];                               
        history.r(jj+1,:,:) = r_jplus1;

    else
        % Load reference1
        r_jplus1 = history.r(jj,:,:);
        history.r(jj+1,:,:) = r_jplus1;
    end 

    % =====================================================================
    % Feedforward update
    % =====================================================================
    % 
    if strcmp(optFFmethod, 'off')
        % set FF update to zero
        f_jplus1 = zeros(size(f_j));
  
        % Update history struct        
        history.f(jj+1,:,:) = f_jplus1;                                     % Store f_jplus1
        history.fupdate(jj+1,:,:) = zeros(size(f_j));                       % Store f_jplus1 - f_j

    elseif strcmp(optFFmethod, 'ILC')
        % Frequency domain ILC update law
        [f_jplus1, f_update] = feedforwardUpdate_ILC(SP,t,r_j,e_j,u_j,f_j,Ts);

        % Set specified feedforward directions to zero
        f_jplus1 = f_jplus1.*optFFdirections;
        f_update = f_update.*optFFdirections;
          
        % Update history struct        
        history.f(jj+1,:,:) = f_jplus1;                                     % Store f_jplus1
        history.fupdate(jj+1,:,:) = f_update;                               % Store f_jplus1 - f_j

    elseif strcmp(optFFmethod, 'other')
        % Custom update law
        [f_jplus1, f_update] = feedforwardUpdate_other(SP,t,r_j,e_j,u_j,f_j,Ts);

        % Set specified feedforward directions to zero
        f_jplus1 = f_jplus1.*optFFdirections;
        f_update = f_update.*optFFdirections;
          
        % Update history struct        
        history.f(jj+1,:,:) = f_jplus1;                                     % Store f_jplus1
        history.fupdate(jj+1,:,:) = f_update;                               % Store f_jplus1 - f_j

    elseif strcmp(optFFmethod, 'ILC_BF_IS')

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % Your own feedforward update
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        theta_delta = FeedforwardUpdate_ILC_BFIS(na,nb);

        f_jplus1 = zeros(Nref,ni);
        ry_jplus1 = history.r(jj+1,:,:);

        % Set specified feedforward directions to zero
        f_jplus1 = f_jplus1.*optFFdirections;
          
        % Update history struct        
        history.f(jj+1,:,:) = f_jplus1;                                     % Store f_jplus1
        history.r_y(jj+1,:,:) = ry_jplus1;
    end


    % Update trial data plot
    PlotTrialDataContour(history,jj+1,0,0,0,0,1,0,1);         
    if strcmp(optFFmethod, 'ILC_BF_IS')
        set_new_ref(history.r_y(jj+1,:,:),tg);                                  % Apply shaped reference to the loop
    else
        set_new_ref(history.r(jj+1,:,:),tg);                                  % Apply shaped reference to the loop
    end
    
    % Update trial data plot
    PlotTrialDataContour(history,jj,0,0,0,1,0,0,0);                        % added last entry is plot_r_y
    % assumes the vector r_y is in history
    %try for both 0 and 1
    % It plots r_y of current trial, should it be next trial?

    % =====================================================================
    % End trial
    % =====================================================================
end

% Check
switch questdlg('Continue Experimenting?','Confirmation','Yes')
    case 'Yes'
    disp('Change experiment settings and re-run file')
    return
end


%% ==========================================================================
% End experiment
% ===========================================================================
% Disable amplifiers
enable_motor_amplifiers(0, tg)

pause(1);

% Penholder mechanism (NOT WORKING)
% % Always wait until penholder is finished/idle
% % Move penholder up
% set_param_Arizona('startPenholder',0,tg);
%         
% while tg.getsignal('Arizona_base_GOAT/log_penholder_active')
%     pause(0.1);
% end

% Prompt to check Arizona power is off
waitfor(msgbox('Confirm that Arizona power switch is off again!','Check') );

tg.stop;
