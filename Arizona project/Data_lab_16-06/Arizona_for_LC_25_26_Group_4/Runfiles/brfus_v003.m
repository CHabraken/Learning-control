function y = brfus_v003(P_orig,u,t,Ts)

% Frank Boeren and Dennis Bruijnen
% Compute bounded outputs for unstable systems through stable inversion.

%% Version Control
% v002: Only use stable inversion if P is unstable. Else use lsim
% (numerically more reliable!) (Frank Boeren)

%% If non-proper system, first make the system proper. Then in the end, shift the signal back. 

if isdt(P_orig)
    % z_ss = ss(tf('z',Ts)); % z IS ADDED FOR PROPERNESS OF CFF 
    z_inv = tf(filt([0,1],1,Ts));
else
    z_inv = 1/tf('s'); % EDIT MAURICE
end
    
[no,ni]=size(P_orig);
if ni > 1
    error('Currently, brfus is not compatible with multi-input systems')
end
for i=1:no
    pp{i} = pole(tf(P_orig(i)));
    zz{i} = zero(tf(P_orig(i)));
    ord_dif(i) = length(zz{i})-length(pp{i});
end

if max(ord_dif)>0
    ord_dif = max(ord_dif);
    P = ( (z_inv)^ord_dif) * P_orig ; % NON-PROPER ->  BIPROPER
else
    P = P_orig;  
    ord_dif = 0 ;
end

% p = pole(P_orig); z = tzero(P_orig); 
% if (length(z)>length(p))
%    ord_dif = length(z)-length(p);
%    P = ( (z_inv)^ord_dif) * P_orig ; % NON-PROPER ->  BIPROPER
%    
% %    P = minreal(P);
% else
%     P = P_orig;  
%     ord_dif = 0 ;
% end


%% Algorithm

if ~isstable(P);
    %separate stable and unstable part
    dt = P.Ts;
    [Ps,Pu] = stabsep(P);
        
    %disp(['stable states: ' int2str(length(Ps.a)) ', unstable states: ' int2str(length(Pu.a))])
    [As,Bs,~,~] = ssdata(Ps);
    [Au,Bu,Cu,Du] = ssdata(Pu);
    pinvAu = pinv(Au);
    Pui = ss(pinvAu,-pinvAu*Bu,Cu*pinvAu,Du-Cu*pinvAu*Bu,dt); % TIME-REVERSED SS
    %initial conditions
    y0 = pinv(eye(size(As))-As)*Bs*u(1); % SOLUTION TO EQUILIBRIUM X(K+1)=X(K)
    ye = pinv(eye(size(Au))-Au)*Bu*u(end);
    
    %simulation
    ys = lsim(Ps,u,t,y0);
    u_rev = flipud(u); %u_rev = [u_rev(2:end);u_rev(end)];
    yu = flipud(lsim(Pui,u_rev,t,ye)); 
%     yu = [yu(2:end,:);yu(end,:)];
%     Pui ALREADY DEFINES TIME-REVERSED SYSTEM. FEED TIME-REVERSED INPUT AND THEN REVERSE THE OUTPUT
%     SINCE FINAL STATE ye IS DEFINED FOR EQUILIBRIUM, BOUNDED SOLUTION IS GUARANTEED 
    
    %final result
    y = ys+yu;   
    for i=1:size(y,2)
        y(:,i) = [y(ord_dif+1:end,i); y(end,i)*ones(ord_dif,1)]; % COMPANSATE FOR BIPROPER SYSTEM BY SHIFTING
    end
else
    % Simple forward solution
    y = lsim(P, u, t);
    for i=1:size(y,2)
        y(:,i) = [y(ord_dif+1:end,i);y(end,i)*ones(ord_dif,1)]; % COMPANSATE FOR BIPROPER SYSTEM BY SHIFTING
    end
end