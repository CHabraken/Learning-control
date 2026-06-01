function [yref_padded, xref_padded, phiref_padded, t_padded] = pad_reference_to_N_repeat(yref, xref, phiref, N, Ts)
% Pads to length of memory
xref_padded = [xref; xref(end)*ones(N-length(xref),1)];
yref_padded = [yref; yref(end)*ones(N-length(yref),1)];
phiref_padded = [phiref; phiref(end)*ones(N-length(phiref),1)];
t_padded = 0:Ts:(N-1)*Ts;
end

