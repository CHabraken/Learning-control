function PSI = buildDiag_Matrix(blocks)
% blocks = {M1,M2,M3,...,Mn}

PSI = blkdiag(blocks{:});
end

