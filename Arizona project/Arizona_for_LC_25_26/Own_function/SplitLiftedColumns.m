function [M1, M2] = SplitLiftedColumns(M)
    M1 = M(:,1:2:end);
    M2 = M(:,2:2:end);
end