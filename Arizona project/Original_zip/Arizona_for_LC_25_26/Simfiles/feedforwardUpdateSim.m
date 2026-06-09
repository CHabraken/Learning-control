%FEEDFORWARDUPDATE   Compute feedforward signal for next trial.
function f_jplus1 = feedforwardUpdateSim(SP,t,r_j,e_j,f_j,Ts)
%OUT:
%f_jplus1 = feed forward signal for upcoming trial
%
%IN:
% SP = process sensitivity
% t = trial time vector
% r_j = current trial position reference
% e_j = current trial tracking error
% u_j = current trial control effort
% f_j = current trial feed forward signal

% ----------------------------------------------------------------------- %
% Frequency Domain ILC: Input
% ----------------------------------------------------------------------- %
f_nyquist = 1/(2*Ts); 
ni = 3;
N_finite_time_fix = 1000;

% learning gain  
alpha = 0.5;

% Q filter
fy_cutoff = 100;
[numy, deny] = butter(6, fy_cutoff/f_nyquist);

fx_cutoff = 100;
[numx, denx] = butter(6, fx_cutoff/f_nyquist);

fphi_cutoff = 50;
[numphi, denphi] = butter(2, fphi_cutoff/f_nyquist);

num = {numy, numx, numphi};
den = {deny, denx, denphi};

% ----------------------------------------------------------------------- %
% Frequency Domain ILC: Compute Update
% ----------------------------------------------------------------------- %
% Initialize vectors
L_e_j     = zeros(size(e_j));

L_e_j_    = [zeros(N_finite_time_fix*2, 3); L_e_j]; 
f_j_      = [f_j(1,:).*zeros(N_finite_time_fix,3); f_j; f_j(end,:).*zeros(N_finite_time_fix,3)];
f_jplus1_ = zeros(size(f_j_));

% STABLE INVERSE Perform learning update
for ii = 1:1
    [~, k] = stable_inv(SP, e_j(:,ii), N_finite_time_fix);
    L_e_j_(:,ii) = k;
end

% e_j_      = [e_j(1,:).*ones(N_finite_time_fix,3); e_j; e_j(end,:).*ones(N_finite_time_fix,3)];
% for ii = 1:1
%     [ai,bi,ci,di, phd] = zpetc(SP.A, SP.B, SP.C, SP.D, 1);
%     L = ss(ai,bi,ci,di,Ts);
%     k = lsim(L, e_j_(:,ii));
%     L_e_j_(:,ii) = [k(phd+1:end); zeros(phd,1)];
% end

% FF update
f_jplus1_unf = f_j_ + alpha*L_e_j_;

% Apply robustness filter
for ii = 1:ni
    f_jplus1_(:,ii) = filtfilt(num{ii}, den{ii}, f_jplus1_unf(:,ii));
end

% Trim vector
f_jplus1 = f_jplus1_(N_finite_time_fix+1:end-N_finite_time_fix, :);

end