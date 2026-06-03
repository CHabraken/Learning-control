 function H = mimoImpulse(A,B,C,D,N)
    %MIMOIMPULSE Returns N impulse response samples for a discrete MIMO system
    %
    % System:
    %   x[k+1] = A x[k] + B u[k]
    %   y[k]   = C x[k] + D u[k]
    %
    % Output:
    %   H(:,:,k+1) = impulse response at sample k
    %
    % Meaning:
    %   H(:,:,1) = D
    %   H(:,:,2) = C*B
    %   H(:,:,3) = C*A*B
    %   ...
    %
    % Dimensions:
    %   A : nx x nx
    %   B : nx x nu
    %   C : ny x nx
    %   D : ny x nu
    %
    % Result:
    %   H : ny x nu x N
    %
    % Example:
    %   H(:,:,1) -> D
    %   H(:,:,2) -> C*B
    %
    
    % Sizes
    ny = size(C,1);
    nu = size(B,2);
    
    % Preallocate
    H = zeros(ny,nu,N);
    
    % First sample: direct feedthrough
    H(:,:,1) = D;
    
    % Powers of A
    Ak = eye(size(A));
    
    % Remaining Markov parameters
    for k = 2:N
    
        H(:,:,k) = C * Ak * B;
    
        Ak = Ak * A;
    end
    
 end