function [f_jplus1, J] = ILC_update_NO_ricatti(e_j, f_j, f_jmin1, w_e, w_f, w_df, A_g, B_g, A_f, B_f, C_f, D_f)
% w_e, w_f, w_Df are N (trial length) dimensional cell arrays
% each entry of w_e is no x no (error dimension)
% each entry of w_f and w_df is ni x ni (input dimension)

N = length(e_j);
nx = size(A_f,1); ni = size(C_f,1);

% Flip time and signal axis for conventions below
f_jmin1 = f_jmin1';
f_j = f_j';
e_j = e_j';

% Evaluate cost of previous trial
J = 0;
for k = 1:N
    J = J + e_j(:,k)'*w_e{k}*e_j(:,k) + f_j(:,k)'*w_f{k}*f_j(:,k) + (f_j(:,k)-f_jmin1(:,k))'*w_df{k}*(f_j(:,k)-f_jmin1(:,k));
end


% Solve vector difference equation.
g(:,N+1) = zeros(nx,1);
for k = N:-1:1
    g(:,k) = A_g(:,:,k)*g(:,k+1) + B_g(:,:,k)*[e_j(:,k); f_j(:,k)];
end

% Optimal state trajectory and control input.
dx_jplus1_star(:,1) = zeros(nx,1);
f_jplus1 = zeros(ni,N);
for k = 1:N
    dx_jplus1_star(:,k+1) = A_f(:,:,k)*dx_jplus1_star(:,k) + B_f(:,:,k)*[f_j(:,k); e_j(:,k); g(:,k+1)];
    f_jplus1(:,k)    = C_f(:,:,k)*dx_jplus1_star(:,k) + D_f(:,:,k)*[f_j(:,k); e_j(:,k); g(:,k+1)];
end

% Transpose again for original conventions
f_jplus1 = f_jplus1';
end