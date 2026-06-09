%CLOSEDLOOPTRANSFERS   Discrete-time state space realizations of closed loop transfers.
%
%   [S,SP] = CLOSEDLOOPTRANSFERS(method) returns discrete-time state space
%   realizations of sensitivity S and process sensitivity SP, given a system
%   P and feedback controller C.
%
% Author: Jurgen van Zundert
% Date:   February 2016

function [S,SP] = ClosedLoopTransfers(P,C)

% Check sampling times.
if P.Ts ~= C.Ts
    error('Sampling times do not match.')
end

% Transform to state-space.
P = ss(P);
C = ss(C);

% Input and output dimensions.
[no,ni] = size(P.d);
nx = length(C.a);

% Determine system matrices.
if isequal(P.d,zeros(size(P.d)))
    % Exploiting P.d=0:
    Acal = [ P.a-P.b*C.d*P.c, P.b*C.c; -C.b*P.c, C.a];
    Bcal = [ [P.b*C.d; C.b], [P.b; zeros(nx,ni)] ];
    Ccal = [P.c, zeros(no,nx)];
    Dcal = zeros(no,ni+no);
    
else
    % For nonzero P.d:
    inv1 = eye(ni)/(eye(ni)+C.d*P.d);
    inv2 = eye(no)/(eye(no)+P.d*C.d);
    
    Acal = [ P.a-P.b*inv1*C.d*P.c P.b*inv1*C.c; -C.b*inv2*P.c C.a-C.b*inv2*P.d*C.c];
    Bcal = [ [P.b*inv1*C.d; C.b*inv2], [P.b*inv1; -C.b*inv2*P.d] ];
    Ccal = [inv2*P.c, inv2*P.d*C.c];
    Dcal = [inv2*P.d*C.d, inv2*P.d];
end

% Extract state-space of sensitivity and process sensitvity.
S  = ss(Acal,Bcal(:,1:ni),-Ccal,eye(no)-Dcal(:,1:ni),P.Ts);
SP = ss(Acal,Bcal(:,end-no+1:end),Ccal,Dcal(:,end-no+1:end),P.Ts);