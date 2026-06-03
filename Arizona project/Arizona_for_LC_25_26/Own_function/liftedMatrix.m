function P = liftedMatrix(H)
    % H(:,:,k) = kth impulse block
    %
    % Size:
    %   H : ny x nu x N
    %
    % Returns:
    %   P : (ny*N) x (nu*N)
    
    [ny,nu,N] = size(H);
    
    P = zeros(ny*N, nu*N);
    
    for row = 1:N
        for col = 1:row
    
            % Which Markov parameter
            k = row-col+1;
    
            % Block indices
            rows = (row-1)*ny + (1:ny);
            cols = (col-1)*nu + (1:nu);
    
            % Fill block
            P(rows,cols) = H(:,:,k);
        end
    end
end