function y = liftedSignal(rx,rphi)

N = length(rx);

y = zeros(2*N,1);

for k = 1:N

    idx = 2*k-1:2*k;

    y(idx) = [
        rx(k);
        rphi(k)
    ];

end

end