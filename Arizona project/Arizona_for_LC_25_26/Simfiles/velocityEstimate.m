function v = velocityEstimate(x, Ts)

    v = zeros(size(x));

    for k = 2:length(x)
        v(k) = (x(k) - x(k-1)) / Ts;
    end

end