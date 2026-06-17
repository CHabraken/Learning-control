function [yref_padded, xref_padded, phiref_padded] = prepad_reference(yref, xref, phiref, Npad)
% Pads to length of memory
xref_padded = [zeros(Npad,1); xref];
yref_padded = [zeros(Npad,1); yref];
phiref_padded = [zeros(Npad,1); phiref];
end

