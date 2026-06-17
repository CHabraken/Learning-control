function [yref, xref, phiref, t, Nref] = select_reference(ref, Ts)
% =========================================================================
% Select desired reference
% Make sure the reference stays within the printer bounds!
% =========================================================================
switch ref
    case 'point2point'
        load('Reference_point2point.mat')
    case 'straight_lines'
        load('Reference_between_straight_lines.mat')
        N = 5000;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'square'
        load('Reference_square.mat')
        N = 4500;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'triangle'
        [yref, xref, phiref] = reference_triangle(Ts);
        N = 5000;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'rounded_rectangle'
        [yref, xref, phiref] = reference_rounded_rectangle(Ts);
        [yref, xref, phiref] = prepad_reference(yref, xref, phiref, 500);
    case 'circle'    
        [yref, xref, phiref] = reference_circle();
        [yref, xref, phiref] = prepad_reference(yref, xref, phiref, 500);
    case 'Reference_4th_order'
        load('Reference_4th_order.mat')
        N = 5973;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'X_Arizona'
        load('Reference_X_Arizona_nonan.mat')
        N = 6873;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'final_path_v2'
        load('final_path_v2.mat')
        N = 6873;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'final_path_v3'
        load('X_Arizona_padded.mat')
        N = 6873+500;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'test_reference'
        load('test_reference.mat')
        N = 7000;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'Gantry_slow'
        load("Reference_X_slow.mat")        
        N = length(xref);
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
    case 'ref1'
        load('ref1.mat')
        N = 7000;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts); 
    case 'ref2'
        load('ref2.mat')
        N = 7000;
        [yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
end   
Nref = N;

end