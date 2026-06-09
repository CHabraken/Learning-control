function [yref_padded, xref_padded, phiref_padded, t_padded] = pad_reference_to_N_zeros(yref, xref, phiref, N, Ts)
% Pads to length of memory
xref_padded = [xref; zeros(N-length(xref),1)];
yref_padded = [yref; zeros(N-length(yref),1)];
phiref_padded = [phiref; zeros(N-length(phiref),1)];
t_padded = 0:Ts:(N-1)*Ts;
end

