function [yref_padded, xref_padded, phiref_padded] = pad_reference(yref, xref, phiref, Npad)
% Pads to length of memory
xref_padded = [xref; zeros(Npad,1)];
yref_padded = [yref; zeros(Npad,1)];
phiref_padded = [phiref; zeros(Npad,1)];
end

