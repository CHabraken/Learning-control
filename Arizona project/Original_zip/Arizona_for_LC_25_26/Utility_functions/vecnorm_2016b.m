function [n] = vecnorm_2016b(vecs)
dim = 1; % dimension
p = 2; % power
vec2p = vecs.^p;
s = sum(vec2p, dim);
n = s.^(1/p);
end

