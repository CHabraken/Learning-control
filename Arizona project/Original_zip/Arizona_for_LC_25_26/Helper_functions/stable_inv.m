function [e_filt, e_filt_, L] = stable_inv(GS,e,Npad)
% stable inversion
%
% Perform a stable inversion of a non-minimum phase discrete time SISO 
% state space model GS, and filter a signal e with the resulting 
% non-causal filter L = GS^-1. 
%
% e_filt = stable_inv(GS,e) has input arguments GS (the
% state space model to be inverted), e (the signal to be filtered,
% typically an error signal), and ts (the sample time of the discrete time
% system). The output is the signal e_filt, which is the signal e filtered 
% by L and shifted in time for phase compensation.
%
% AUTHORS: T. Oomen, L. Aarnoudse (Eindhoven University of Technology,
% Control Systems Technology)
% DATE: May 2022
z = tf('z',GS.Ts);
e = [e(1)*ones(Npad,1);e;e(end)*ones(Npad,1)];
N = length(e);
%% Check properness of GS and add delays if necessary
h = dimpulse(GS.A, GS.B, GS.C, GS.D, [], N);
p = find(h,1,'first')-1;
GS_p = minreal(GS*z^p);

[num,den] = ss2tf(GS.A, GS.B, GS.C, GS.D);
GS_tf=tf(num,den,GS.Ts);

ph = order(tf(1,den,GS.Ts))-order(tf(1,num,GS.Ts));

%% Invert GS to determine L
[GA, GB, GC, GD] = ssdata(GS_p);

LA = GA - GB*inv(GD)*GC;           
LB = GB*inv(GD);
LC = -inv(GD)*GC;
LD = inv(GD);

L = ss(LA,LB,LC,LD,GS.Ts);
[LS,LNS] = stabsep(L,'Mode',1,'Offset', -10^-10);              % stable/unstable decomposition of L
[LS2,LNS2] = stabsep(L);   
%% Solve stable part forward in time 
uff_S = lsim(LS,e);

%% Solve filtering of e through unstable part of L backward in time
[numNS,denNS] = tfdata(LNS,'v');    % unstable part of L
LNC = tf(fliplr(numNS),fliplr(denNS),1,'Variable','z^-1');  
uff_NS = flipud(filter(LNC.num{:},LNC.den{:},flipud(e)));

%% Combination of stable and unstable part and phase compensation       
errorFiltL = uff_S + uff_NS;

% Phase compensation: shift feedforward back over p samples
e_filt_ = [errorFiltL(p+1:end); zeros(p,1)];
% e_filt_ = errorFiltL;
e_filt = e_filt_(Npad+1:end-Npad);

end