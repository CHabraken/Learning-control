% FeedforwardUpdate for ILC with polynomial basis functions and input
% shaper

% Two options:
% 1) IFT approach. --> See (Boeren,2014)
% 2) ILC approach. --> See Challenge_description.pdf Section 4
% Please note that we primarily want to investigate the ILC approach

% This function uses brfus_v003.m which is similar to stable_inv.m.
% brfus_v003 is able to obtain a stable response from an unstable system,
% hence, it does not invert the system that you give as input (what
% stable_inv does!)

function theta_delta = FeedforwardUpdate_BFIS(method,na,nb,Psi,C,N,S,PS,We_sq,Wry_sq,Wdry_sq,Wf_sq,Wdf_sq,e_y,u,y,r_y,f,r,t,Ts)

switch method
    case 'IFT'
        Phi = zeros(N,na+nb);
        Phi(:,1:na) = brfus_v003(minreal(series(Psi(1:na),inv(C))).',-u,t,Ts);
        Phi(:,na+1:na+nb) = brfus_v003(minreal(series(Psi(na+1:na+nb),inv(C))).',y,t,Ts);

        D = vecnorm(Phi);
        Phi_scaled = Phi ./ D;                                          % For better conditioning
        th_scaled = Phi_scaled \ e_y;
        theta_delta = th_scaled ./ D.';

    case 'ILC'
        Phi = zeros(N,na+nb);
        Phi(:,1:na) = -brfus_v003((series(S,Psi(1:na))).',r,t,Ts);
        Phi(:,na+1:end) = brfus_v003((series(PS,Psi(na+1:end))).',r,t,Ts);

        Psi_y_r = brfus_v003(Psi(1:na).',r,t,Ts);
        Psi_ff_r = brfus_v003(Psi(na+1:end).',r,t,Ts);

        % Create regressor matrix
        X = [We_sq*Phi;
            -Wry_sq*Psi_y_r, zeros(N,nb);
            -Wdry_sq*Psi_y_r, zeros(N,nb);
            zeros(N,na), -Wf_sq*Psi_ff_r;
            zeros(N,na), -Wdf_sq*Psi_ff_r];

        % Create response vector
        Y = [We_sq*e_y;
            Wry_sq*r_y;
            zeros(N,1);
            Wf_sq*f;
            zeros(N,1)];

        X_scaled = X ./ vecnorm(X);                                     % For better conditioning
        th_scaled = X_scaled \ Y;
        theta_delta = th_scaled ./ vecnorm(X).';
end
end