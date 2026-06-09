%FEEDFORWARDUPDATE   Compute feedforward signal for next trial.
function [f_jplus1 f_update] = feedforwardUpdate(SP,t,r_j,e_j,u_j,f_j,Ts)
% +-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-
%IN:
% SP = process sensitivity
% t = trial time vector
% r_j = current trial position reference
% e_j = current trial tracking error
% u_j = current trial control effort
% f_j = current trial feed forward signal

%OUT:
%f_jplus1 = feed forward signal for upcoming trial
% +-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-

% Arizona parameters
f_nyquist = 1/(2*Ts); 
ni = 3;
N_finite_time_fix = 1000;

% ----------------------------------------------------------------------- %
% Frequency Domain ILC: Parameters that can be changed
% ----------------------------------------------------------------------- %
% learning gain  
alpha_y =  0.35;
alpha_x = 0.4;
alpha_phi = 0.4;

% Q filter
fy_cutoff = 60;
fx_cutoff = 100;
fphi_cutoff = 50;

% Inversion method (stable_inv/ZPETC)
optINVmethod = 'stable_inv';           

% ----------------------------------------------------------------------- %
% Frequency Domain ILC: Initiate Q filters + vectors
% ----------------------------------------------------------------------- %
[numy, deny] = butter(6, fy_cutoff/f_nyquist);
[numx, denx] = butter(6, fx_cutoff/f_nyquist);
[numphi, denphi] = butter(2, fphi_cutoff/f_nyquist);

alpha = [alpha_y, alpha_x, alpha_phi]';
num = {numy, numx, numphi};
den = {deny, denx, denphi};

L_e_j     = zeros(size(e_j));
L_e_j_    = [zeros(N_finite_time_fix*2, 3); L_e_j]; 
f_j_      = [f_j(1,:).*zeros(N_finite_time_fix,3); f_j; f_j(end,:).*zeros(N_finite_time_fix,3)];
f_jplus1_ = zeros(size(f_j_));

% ----------------------------------------------------------------------- %
% Frequency Domain ILC: Model inversion
% ----------------------------------------------------------------------- %
if strcmp(optINVmethod, 'stable_inv')
    % STABLE INVERSE
    for ii = 1:ni
        [~, k] = stable_inv(SP{ii}, e_j(:,ii), N_finite_time_fix);
        L_e_j_(:,ii) = k;
    end
    
elseif strcmp(optINVmethod, 'ZPETC')
    % ZPETC
    e_j_      = [e_j(1,:).*ones(N_finite_time_fix,3); e_j; e_j(end,:).*ones(N_finite_time_fix,3)];
    for ii = 1:ni
        SP_ = SP{ii};
        [ai,bi,ci,di, phd] = zpetc(SP_.A, SP_.B, SP_.C, SP_.D, 1);
        L = ss(ai,bi,ci,di,Ts);
        k = lsim(L, e_j_(:,ii));
        L_e_j_(:,ii) = [k(phd+1:end); zeros(phd,1)];
    end
end

% ----------------------------------------------------------------------- %
% Frequency Domain ILC: Update
% ----------------------------------------------------------------------- %
% FF update
f_jplus1_unf = f_j_ + L_e_j_.*alpha';
f_update_ = zeros(size(f_jplus1_));
f_update_unf = L_e_j_.*alpha';

% Apply robustness filter
for ii = 1:ni
    f_jplus1_(:,ii) = filtfilt(num{ii}, den{ii}, f_jplus1_unf(:,ii));
    f_update_(:,ii) = filtfilt(num{ii}, den{ii}, f_update_unf(:,ii));

end

% Trim vector
f_jplus1 = f_jplus1_(N_finite_time_fix+1:end-N_finite_time_fix, :);
f_update = f_update_(N_finite_time_fix+1:end-N_finite_time_fix, :);

end