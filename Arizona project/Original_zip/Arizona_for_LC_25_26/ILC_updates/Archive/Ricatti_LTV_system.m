function [A_g, B_g, A_f, B_f, C_f, D_f] = Ricatti_LTV_system(sysd, w_e, w_f, w_df, N)
% Norm-optimal ILC, low order computation
% w_e, w_f, w_df are N (trial length) dimensional cell arrays
% w_e{:} is stage cost for error, i.e., in R^[no,no]
% w_f{:} is stage cost for input, i.e., in R^[ni,ni]
% w_df{:} is state cost for chagne in input over trials, i.e., in R^[ni,ni]

% Unpack system
A = sysd.A; B = sysd.B; C = sysd.C; D = sysd.D;
[no,ni] = size(D);
nx = size(A,1);

assert(size(w_e{1},1) == no, 'System output does not match error weighting')
assert(size(w_f{1},1) == ni, 'System input does not match input weighting')
assert(size(w_df{1},1) == ni, 'System input does not match input weighting')

% Riccati coefficient matrix.
P = NaN(nx,nx,N+1);
P(:,:,N+1) = zeros(nx);
beta = NaN(ni,ni,N);
K_g = NaN(nx,ni,N);
gamma = NaN(ni,ni,N);
tmp1 = NaN(nx,nx,N);
tmp2 = NaN(nx,nx,N);
tmp3 = NaN(nx,nx,N);
for k = N:-1:1
    gamma(:,:,k) = get_gamma(D, w_e{k}, w_f{k}, w_df{k}, ni);
    tmp1(:,:,k) = A.'-C.'*w_e{k}*D*gamma(:,:,k)*B.';
    tmp2(:,:,k) = A-B*gamma(:,:,k)*D.'*w_e{k}*C;
    tmp3(:,:,k) = C.'*w_e{k}*C - C.'*w_e{k}*D*gamma(:,:,k)*D.'*w_e{k}*C;
    P(:,:,k) = tmp1(:,:,k) * P(:,:,k+1) * (eye(nx)-B/(gamma(:,:,k)\eye(ni)+B.'*P(:,:,k+1)*B)*B.'*P(:,:,k+1)) * tmp2(:,:,k)+ tmp3(:,:,k);
    K_g(:,:,k) = tmp1(:,:,k)*P(:,:,k+1)/(eye(nx)+B*gamma(:,:,k)*B.'*P(:,:,k+1))*B*gamma(:,:,k);
    beta(:,:,k) = (gamma(:,:,k)\eye(ni) + B.'*P(:,:,k+1)*B) \ eye(ni);
end

% Backward state-space matrices g
A_g = NaN(nx,nx,N);
B_g = NaN(nx,ni+no,N);
for k = 1:N
    A_g(:,:,k) = tmp1(:,:,k) - K_g(:,:,k)*B.';
    B_g(:,:,k) = [C.'*w_e{k} - K_g(:,:,k)*D.'*w_e{k} - C.'*w_e{k}*D*gamma(:,:,k)*D.'*w_e{k}, K_g(:,:,k)*w_f{k} + C.'*w_e{k}*D*gamma(:,:,k)*w_f{k}];
end

% State-space matrices f^*
A_f = NaN(nx,nx,N);
B_f = NaN(nx,ni+no+nx,N);
C_f = NaN(ni,nx,N);
D_f = NaN(ni,ni+no+nx,N);
for k = 1:N
    A_f(:,:,k) = A-B*beta(:,:,k)*(D.'*w_e{k}*C+B.'*P(:,:,k+1)*A);
    B_f(:,:,k) = [-B*beta(:,:,k)*w_f{k}, B*beta(:,:,k)*D.'*w_e{k}, B*beta(:,:,k)*B.'];
    C_f(:,:,k) = -beta(:,:,k)*(D.'*w_e{k}*C + B.'*P(:,:,k+1)*A);
    D_f(:,:,k) = [eye(ni)-beta(:,:,k)*w_f{k}, beta(:,:,k)*D.'*w_e{k}, beta(:,:,k)*B.'];
end
end

function g = get_gamma(D, w_e, w_f, w_df, ni)
g = (D.'*w_e*D + w_f + w_df)\eye(ni);
end

