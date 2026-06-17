% --- Helper Function ---
function G = liftedMIMOMatrix(sys, N)
    % Ensure the system is discrete
    if sys.Ts == 0
        error('The state-space system must be discrete-time. Use c2d() first if needed.');
    end

    % Extract state-space matrices
    A = sys.A; B = sys.B; C = sys.C; D = sys.D;
    [Ny, Nu] = size(D); % Number of outputs (Ny) and inputs (Nu)
    
    % Step 1: Compute Markov parameters g(k)
    g = cell(N, 1);
    g{1} = D; % g(0)
    
    CAK = C; % Tracks C * A^(k-1)
    for k = 2:N
        g{k} = CAK * B;
        CAK = CAK * A;
    end
    
    % Step 2: Preallocate a block cell array with zero matrices
    G_cell = cell(N, N);
    [G_cell{:}] = deal(zeros(Ny, Nu));
    
    % Step 3: Populate the lower-triangular block Toeplitz structure
    for r = 1:N
        for c = 1:r
            G_cell{r, c} = g{r - c + 1};
        end
    end
    
    % Step 4: Convert cell array to a single large matrix
    G = cell2mat(G_cell);
end