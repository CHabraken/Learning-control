function [We_sq, Wry_sq, Wdry_sq, Wf_sq, Wdf_sq] = calcWeightingMats(Nref, weight)
    % Comments on what the hell this should do
    %   - 1) Should construct the matricies.
    %   - 2) Give decoupled matrix of plant

    %% Calculation

    % I dont really know what this does.
    de = repmat([weight.we_x weight.we_phi], 1, Nref);

    % Weighting matricies.
    We = diag(de);
    We_sq = sqrt(We);
    
    Wry = weight.wry*eye(Nref);
    Wry_sq = sqrt(Wry);
    
    Wdry = weight.wdry*eye(Nref);
    Wdry_sq = sqrt(Wdry);
    
    % More weighting matricies.
    df = repmat([weight.wf_x weight.wf_phi], 1, Nref);
    ddf = repmat([weight.wdf_x weight.wdf_phi], 1, Nref);
    % Wf = wf*speye(2*N,2*N); Wf_sq = sqrt(Wf);
    Wf = diag(df);
    Wf_sq = sqrt(Wf);
    % Wdf = wdf*speye(2*N,2*N); Wdf_sq = sqrt(Wdf);
    Wdf = diag(ddf);
    Wdf_sq = sqrt(Wdf);

end