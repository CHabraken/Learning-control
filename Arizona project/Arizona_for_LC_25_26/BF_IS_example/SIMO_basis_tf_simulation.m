% Simulation for experiments
clear; close all; clc;

addpath(genpath('../Models'))
addpath(genpath('../Own_function'))
addpath(genpath('../Reference_generators'))
addpath(genpath('../Helper_functions'))
addpath(genpath('../Models_new/Models/Parametric'))
addpath(genpath('../Models_new/Models/Nonparametric'))

%% There are two different type of controllers given for this assignment. One of the works fine, the other one does not.
addpath(genpath('../Controllers/Controllers_simulation'))
% addpath(genpath('../Controllers'))

%% 
% parameters

L = 2.62; % gantry length


% we = 1e2;
% wf = 1e-8;
wdf = 0e-6;
wry = 0e-5;
wdry =0e-4;


we_x   = 1e2;
we_phi = 1e2*    0.5*L*pi/180;

wf_x = 1e-8;
wf_phi = 1e-8;
wdf_x = 0e-6;
wdf_phi = 0e-6;



Ntrials = 6;

noiseSTD = 1e-5;


% models

P = load('P_centralized.mat').Pz;
Cx = load('xController.mat').Cx;
Cphi = load('phiController.mat').Cphi;

Ts = P.Ts;

Pfrf = load("Gantry_FRF_centralized.mat");
Pfrf = Pfrf.P_carriage_left;



Ty = [0.5 0.5; -1/L 1/L];
Tu = [0.5 -1/L; 0.5 1/L];

P_d = Ty*P*Tu;


C = blkdiag(Cx, Cphi);
% C_central = Tu*C*Ty;


loops = loopsens(P_d,C);
GS = loops.PSi;
S = loops.So;
T = loops.Ti;


% Reference

Npad = 500;
        % [ty,ddy] = make4(0.01,0.25,30,1e5,1e9,Ts); % my reference
        [ty,ddy] = make4(0.2,1,20,1e3,1e7,Ts); % my reference
        [~,~,s,j,a,v,r_x,tt] = profile4(ty,ddy(1),Ts);
        r_x = [r_x; r_x(end)*ones(Npad,1)]; % zeros, forward, zeros,backward, zeros
        v = [v;zeros(Npad,1)];
        a = [a;zeros(Npad,1)];
        j = [j;zeros(Npad,1)];
        s = [s;zeros(Npad,1)];
        N = length(r_x);
        t = 0:Ts:(N-1)*Ts;
        rendidx = find(t>=tt(end),1);               % Index snap is zero, so reference ends here


% GS_lifted = liftedMIMOMatrix(GS, N);
% S_lifted = liftedMIMOMatrix(S,N);


% S_lifted_simo = S_lifted(:,1:2:end);

% GS_lifted(abs(GS_lifted)<=1e-8) = 0;
% S_lifted(abs(S_lifted)<=1e-8) = 0;

% F = [-S_lifted, GS_lifted];


% weighting


de = repmat([we_x we_phi], 1, N);

We = diag(de); We_sq = sqrt(We);

Wry = wry*eye(N); Wry_sq = sqrt(Wry);

Wdry = wdry*eye(N); Wdry_sq = sqrt(Wdry);

df = repmat([wf_x wf_phi], 1, N);
ddf = repmat([wdf_x wdf_phi], 1, N);
% Wf = wf*speye(2*N,2*N); Wf_sq = sqrt(Wf);
Wf = diag(df); Wf_sq = sqrt(Wf);
% Wdf = wdf*speye(2*N,2*N); Wdf_sq = sqrt(Wdf);
Wdf = diag(ddf); Wdf_sq = sqrt(Wdf);


%% Parameterize input shaper Cy
na = 4;
Psi_y = tf(zeros(1,na));
for i = 1:na
    num = zeros(1,i+1);
    for k = 0:i
        num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
    end
        Psi_y(i) = minreal(tf(num,1,Ts,'Variable','z^-1'));
end


%% Parameterize feedforward Cff
nb = 6;
Psi_ff = tf(zeros(1,nb));
for i = 1:nb
    num = zeros(1,i+1);
    for k = 0:i
        num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
    end
        Psi_ff(i) = minreal(tf(num,1,Ts,'Variable','z^-1'));
end


Psi = minreal([Psi_y, Psi_ff, Psi_ff]);

% Cost = 

%% Perform ILC

Ninputs = 2;

fj_plus1 = zeros(N,Ninputs);
fj_plus12 = zeros(2*N,1);
theta_jplus1 = zeros(size(Psi,2),1);
theta_j = NaN(size(Psi,2),Ntrials);
fj = NaN(N,Ninputs,Ntrials);
ej = NaN(N,Ninputs,Ntrials);
r_y = NaN(N,Ninputs,Ntrials);
enorm = NaN(Ninputs,Ntrials);

theta_init = zeros(size(Psi,2),1);
theta_j(:,1) = theta_init;

r_y_i = NaN(2*N,1);
f_i = NaN(2*N,1);

figure;
for j = 1:Ntrials

    % Update feedforward
     % fj(:,:,j) = fj_plus1;
     
     % theta_j(:,j) = theta_jplus1;

     Cy  = minreal(1 + Psi_y*theta_j(1:na,j));
     Cff_x = minreal(Psi_ff*theta_j(na+1:na+nb,j));
     Cff_phi = minreal(Psi_ff*theta_j(na+nb+1:end,j));

     % learn = Psi*theta_j(:,j);
     % f_i = learn(size(Phi_y,1)+1:end);
     % fj_plus1(:,1) = f_i(1:2:end);
     fj_plus1(:,1) = brfus_v003(Cff_x,r_x,t,Ts);
    
     % fj_plus1(:,2) = f_i(2:2:end);
     fj_plus1(:,2) = brfus_v003(Cff_phi,r_x,t,Ts);

     fj(:,:,j) = fj_plus1;


     r_y(:,1,j) =  brfus_v003(Cy,r_x,t,Ts);
     r_y(:,2,j) = zeros(N,1);


     noiseRealization = [noiseSTD*randn(N,1) noiseSTD*randn(N,1)];
     y = lsim(GS,squeeze(fj(:,:,j)),t) + lsim(series(GS,C),squeeze(r_y(:,:,j)),t);

     ej(:,:,j) = r_y(:,:,j) - y;

     % [theta_L, theta_R] = sequential_update(squeeze(ej(:,:,j)),squeeze(r_y(:,:,j)),squeeze(fj(:,:,j)),X_L,X_R,We_sq,Wry_sq,Wf_sq,N);
     % theta_jplus1 = SIMO_update(squeeze(ej(:,:,j)), theta_j(:,j),L,Q);
     theta_delta = FeedforwardUpdate_BFIS_simo(na,nb,nb,Psi,N,S,GS,We_sq,Wry_sq,Wdry_sq,Wf_sq,Wdf_sq,squeeze(ej(:,:,j)),squeeze(r_y(:,:,j)),squeeze(fj(:,:,j)),r_x,t,Ts);

     % theta_jplus1 = theta_j(:,j) + theta_delta;
     theta_j(:,j+1) = theta_j(:,j) + theta_delta;

     

     % Calculate error 2-norm
     % enorm(j) = norm(ej(:,j),2);
     enorm(1,j) = norm(ej(:,1,j),2);
     enorm(2,j) = norm(ej(:,2,j),2);

    

    

    % Tracking error loop 1
    subplot(4,2,1)
    plot(t,ej(:,1,j),'LineWidth',1.2)
    grid on
    ylabel('Error')
    title('Loop x')
    xlim([t(1) t(end)])
    
    % Feedforward loop 1
    subplot(4,2,3)
    plot(t,fj(:,1,j),'LineWidth',1.2)
    grid on
    ylabel('Feedforward')
    xlim([t(1) t(end)])

    subplot(4,2,5)
    plot(t,r_y(:,1,j),'LineWidth',1.2)
    hold on
    plot(t,r_x,'LineWidth',1.2)
    grid on
    ylabel('r_y')
    xlim([t(1) t(end)])
    hold off
    
    % Error norm loop 1
    subplot(4,2,7)
    semilogy(1:j,enorm(1,1:j),'k--x','LineWidth',1.2)
    grid on
    xlabel('Trial index')
    ylabel('||e_x||_2')
    xlim([1 Ntrials])
    
    
    % Tracking error loop 2
    subplot(4,2,2)
    plot(t,ej(:,2,j),'LineWidth',1.2)
    grid on
    ylabel('Error')
    title('Loop $\phi$', 'Interpreter','latex')
    xlim([t(1) t(end)])
    
    % Feedforward loop 2
    subplot(4,2,4)
    plot(t,fj(:,2,j),'LineWidth',1.2)
    grid on
    ylabel('Feedforward')
    xlim([t(1) t(end)])

    subplot(4,2,6)
    plot(t,r_y(:,2,j),'LineWidth',1.2)
    % hold on
    % plot(t,r_x,'LineWidth',1.2)
    grid on
    ylabel('r_y')
    xlim([t(1) t(end)])
    hold off
    
    % Error norm loop 2
    subplot(4,2,8)
    semilogy(1:j,enorm(2,1:j),'k--x','LineWidth',1.2)
    grid on
    xlabel('Trial index')
    ylabel('$||e_{\phi}||_2$', 'Interpreter','latex')
    xlim([1 Ntrials])
    
    % drawnow
end





test = inv(P_d);
figure
subplot(1,2,1)
bode(test(1,1))
hold on
bode(minreal(Cff_x/Cy))


subplot(1,2,2)
bode(test(2,1))
hold on
bode(minreal(Cff_phi/Cy))