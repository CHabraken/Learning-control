%CONVMATMIMO   Convolution matrix of multi-input, multi-output, discrete-time, LTI system.
%
%   MAT = CONVMATMIMO(sys,N) returns the convolution matrix MAT for a
%   multi-input, multi-output system SYS for an impulse response of length N.
%
% Author: Jurgen van Zundert
% Date:   February 2016

function mat = ConvMatMIMO(SYS,N)
if ~SYS.Ts
    error('System must be in discrete-time.')
end

% Base system matrices.
[A,B,C,D] = ssdata(SYS);
[no,ni] = size(D);

Hblk = NaN(N*no,ni);
Hblk(1:no,:) = D;
for r = 2:N;
    Hblk((r-1)*no+1:r*no,:) = C*A^(r-2)*B;
end

% Stack blocks.
mat = zeros(N*no,N*ni);
for ii = 1:N
    mat((ii-1)*no+1:end,(ii-1)*ni+1:ii*ni) = Hblk(1:N*no-(ii-1)*no,:);
end