function Psi = construct_psi(nd,no,r)

if(isempty(r))
    Psi = [];
    return
end

total_len = no + nd;

N = length(r);

rend = r(end)*ones(nd,1);

rd = zeros(N+nd,1);
rd(1:N) = r;
rd(N+1:end) = rend;

first_row = zeros(1, total_len);
first_row(1) = rd(1);

Psi = toeplitz(rd, first_row);
Psi = Psi(nd+1:end,1:no);

end