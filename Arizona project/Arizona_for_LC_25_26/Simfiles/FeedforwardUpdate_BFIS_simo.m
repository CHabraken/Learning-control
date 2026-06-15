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

    % Weighting matricies.
    We_sq = weight.We_sq;
    Wry_sq = weight.Wry_sq;
    Wdry_sq = weight.Wdry_sq;
    Wf_sq = weight.Wf_sq;
    Wdf_sq = weight.Wdf_sq;

    % Making an error signal which alternates the error samples.
    % e_ys = [e_x(1), e_phi(1), e_x(2), e_phi(2), ... , e_x(N), e_phi(N)]
    e_ys = zeros(2*N,1);
    e_ys(1:2:end) = e_y(:,2);
    e_ys(2:2:end) = e_y(:,3);

    % Same thing for above, but now with the Feedforward signal.
    f_s = zeros(2*N,1);
    f_s(1:2:end) = f(:,2);
    f_s(2:2:end) = f(:,3);
    % Reference signal for the x direction
    r_y = r_y(:,2);

    % Size of Phi. 
    %   - na     = Amount of params for input shaper Cy
    %   - nb_x   = Amount of params for ff for x-coordinate
    %   - nb_phi = Amount of params for ff for phi-coordinate
    Phi = zeros(2*N,na+nb_x+nb_phi);

    % Filling Phi and checking if basis functions for the
    %   - Input shaper
    %   - Cff for x
    %   - Cff for phi.
    % It should be possible to choose no basis functions at all.
    if na ~= 0
        Phi(1:2:end,1:na) = -brfus_v003((series(S(1,1),Psi(1:na))).',r,t,Ts);
        Phi(2:2:end,1:na) = -brfus_v003((series(S(2,1),Psi(1:na))).',r,t,Ts);
    end

    % Quite an if statement for when the basis functions are chosen to have
    % different sizes or when they are chosen to be empty.
    if nb_x ~=0 && nb_phi ~= 0
        % Case where there are both basis functions for x and for phi. The
        % matrix multiplication might be wrong due to the different sizes
        % of arrays which are output by brfus_v003. Size of arrays are:
        %   - N by nb_x
        %   - N by nb_phi
        % For now, we just add them by imagining that there are rows of
        % zeros s.t. the sizes are equal.

        % The matrix multiplication and SP "entries"
        SP_Psi_11_input_x = brfus_v003((series(PS(1,1),Psi(na+1:na+nb_x))).',r,t,Ts);
        SP_Psi_22_input_phi = brfus_v003((series(PS(2,2),Psi(na+nb_x+1:end))).',r,t,Ts);
        SP_Psi_12_input_phi = brfus_v003((series(PS(1,2),Psi(na+nb_x+1:end))).',r,t,Ts); 
        SP_Psi_21_input_x = brfus_v003((series(PS(2,1),Psi(na+1:na+nb_x))).',r,t,Ts);

        if nb_x == nb_phi
            Phi(1:2:end,na+1:na+nb_phi) = SP_Psi_11_input_x + SP_Psi_12_input_phi;
            Phi(2:2:end,na+1:na+nb_x) = SP_Psi_22_input_phi + SP_Psi_21_input_x;
        elseif nb_x > nb_phi
            % Making sure the sizing is ok
            intermediateX = [SP_Psi_12_input_phi zeros(N,nb_x-nb_phi)] + SP_Psi_11_input_x;
            intermediatePhi = [SP_Psi_22_input_phi zeros(N,nb_x-nb_phi)] + SP_Psi_21_input_x;

            % Making of Phi
            Phi(1:2:end,na+1:na+nb_x) = intermediateX;
            Phi(2:2:end,na+1:na+nb_x) = intermediatePhi;
        elseif nb_phi > nb_x
            % Making sure the sizing is ok
            intermediateX = [SP_Psi_11_input_x zeros(N,nb_phi-nb_x)] + SP_Psi_12_input_phi;
            intermediatePhi = [SP_Psi_21_input_x zeros(N,nb_phi-nb_x)] + SP_Psi_22_input_phi;
            
            % Making of Phi
            Phi(1:2:end,na+nb_x+1:end) = intermediateX;
            Phi(2:2:end,na+nb_x+1:end) = intermediatePhi;
        else
            % If something goes wrong we end up here. In which case we just
            % use the diagonal terms and not look at the cross terms. This
            % way something happens insteaf of maybe getting an error.
            Phi(1:2:end,na+1:na+nb_x) = SP_Psi_11_input_x;
            Phi(2:2:end,na+nb_x+1:end) = SP_Psi_22_input_phi;
            fprintf("Something went wrong in this itteration. Look at the FeedforwardUpdate_BFIS_simo function. \n");
        end
    elseif nb_x ~= 0
        % The case where only phi basis functions is empty.
        Phi(1:2:end,na+1:na+nb_x) = brfus_v003((series(PS(1,1),Psi(na+1:na+nb_x))).',r,t,Ts);
        Phi(2:2:end,na+nb_x+1:end) = brfus_v003((series(PS(2,1),Psi(na+nb_x+1:end))).',r,t,Ts);
    elseif nb_phi ~= 0
        % The case where only x basis functions is empty.
        Phi(2:2:end,na+nb_x+1:end) = brfus_v003((series(PS(2,2),Psi(na+nb_x+1:end))).',r,t,Ts);
    end


    Psi_y_r = zeros(N,na);
    if na ~= 0
        % I didnt check why we do this. I left it in when doing the revamp
        % of the simulation.
        Psi_y_r = brfus_v003(Psi(1:na).',r,t,Ts);
    end


    % I didnt check why we do this. I left it in when doing the revamp
    % of the simulation..
    Psi_ff_r = zeros(2*N,nb_x+nb_phi);
    if nb_x ~= 0
        Psi_ff_r(1:2:end,1:nb_x) = brfus_v003(Psi(na+1:na+nb_x).',r,t,Ts);
    end
    if nb_phi ~= 0
        Psi_ff_r(2:2:end,nb_x+1:end) = brfus_v003(Psi(na+nb_x+1:end).',r,t,Ts);
    end

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
    
    % Output of the function.
    X_scaled = X ./ vecnorm(X);                                     % For better conditioning
    th_scaled = X_scaled \ Y;
    theta_delta = th_scaled ./ vecnorm(X).';
    
    % % TO DO: Calculate the cost function with the new theta delta.
    % Cost = e_ys.'*We_sq* We_sq * e_ys + (Psi_y_r*theta_j(1:na)).'*W;        
end
