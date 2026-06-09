% function h_k_m = calculate_h(pd_k_m, pd_k_m_1, pa_k)
%     h_k_m = -( (pd_k_m_1 - pa_k)'*(pd_k_m - pd_k_m_1) )/( (pd_k_m - pd_k_m_1)'*(pd_k_m - pd_k_m_1) );
% end

function h = calculate_h(r_, r, p)
% Calculates inner product ratio to check if closest point from line
% segment by r_ to r to position p is on the line segment (indicated by 0
% <= h <= 1).
    h = -( dot(r_ - p, r - r_) )./( dot(r - r_, r - r_) );
end