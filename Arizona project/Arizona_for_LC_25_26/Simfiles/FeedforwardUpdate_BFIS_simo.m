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

function theta_delta = FeedforwardUpdate_BFIS_simo(na,nb_x,nb_phi,Psi,N,S,PS,weight,e_y,r_y,f,r,t,Ts)

    % Matricies
    We_sq = weight.We_sq;
    Wry_sq = weight.Wry_sq;
    Wdry_sq = weight.Wdry_sq;
    Wf_sq = weight.Wf_sq;
    Wdf_sq = weight.Wdf_sq;


        e_ys = zeros(2*N,1);
        e_ys(1:2:end) = e_y(:,2);
        e_ys(2:2:end) = e_y(:,3);

        f_s = zeros(2*N,1);
        f_s(1:2:end) = f(:,2);
        f_s(2:2:end) = f(:,3);
        r_y = r_y(:,2);

        Phi = zeros(2*N,na+nb_x+nb_phi);

        % SIMO thus we can split
        Phi(1:2:end,1:na) = -brfus_v003((series(S(1,1),Psi(1:na))).',r,t,Ts);
        Phi(2:2:end,1:na) = -brfus_v003((series(S(2,1),Psi(1:na))).',r,t,Ts);

        % Phi(:,na+1:end) = brfus_v003((series(PS,Psi(na+1:end))).',r,t,Ts);
        Phi(1:2:end,na+1:na+nb_x) = brfus_v003((series(PS(1,1),Psi(na+1:na+nb_x))).',r,t,Ts) + brfus_v003((series(PS(1,2),Psi(na+nb_x+1:end))).',r,t,Ts);
        Phi(2:2:end,na+nb_x+1:end) = brfus_v003((series(PS(2,1),Psi(na+1:na+nb_x))).',r,t,Ts) + brfus_v003((series(PS(2,2),Psi(na+nb_x+1:end))).',r,t,Ts);

        Psi_y_r = brfus_v003(Psi(1:na).',r,t,Ts);

        Psi_ff_r = zeros(2*N,nb_x+nb_phi);
        Psi_ff_r(1:2:end,1:nb_x) = brfus_v003(Psi(na+1:na+nb_x).',r,t,Ts);
        Psi_ff_r(2:2:end,nb_x+1:end) = brfus_v003(Psi(na+nb_x+1:end).',r,t,Ts);

        % Create regressor matrix
        X = [We_sq*Phi;
            -Wry_sq*Psi_y_r, zeros(N,nb_x+nb_phi);
            -Wdry_sq*Psi_y_r, zeros(N,nb_x+nb_phi);
            zeros(2*N,na), -Wf_sq*Psi_ff_r;
            zeros(2*N,na), -Wdf_sq*Psi_ff_r];

        % Create response vector
        Y = [We_sq*e_ys;
            Wry_sq*r_y;
            zeros(N,1);
            Wf_sq*f_s;
            zeros(2*N,1)];

        X_scaled = X ./ vecnorm(X);                                     % For better conditioning
        th_scaled = X_scaled \ Y;
        theta_delta = th_scaled ./ vecnorm(X).';
        
        % Cost = e_ys.'*We_sq* We_sq * e_ys + (Psi_y_r*theta_j(1:na)).'*W

        
end
