function Psi_inner = Construct_inner_psi(Psi_x, Psi_phi)
    nx = size(Psi_x);
    nphi = size(Psi_phi);
    
    rows = max(nx(1),nphi(1));%ref length
    columns = nx(2)+nphi(2); 

   
    % if(nx(1)~=0 && nx(2) < columns)
    %     append = columns - nx(2);
    %     Psi_x = [Psi_x, zeros(append, nx(1))];
    % end
    % 
    % if(nphi(1)~=0 && nphi(2) < columns)
    %     append = columns - nphi(2);
    %     Psi_phi = [Psi_phi, zeros(append, nphi(1))];
    % end

    % Psi_x   
    % Psi_phi

    Psi_inner = zeros(2*rows,columns);
    Psi_inner(1:2:end,1:nx(2)) = Psi_x;
    Psi_inner(2:2:end,nx(2)+1:end) = Psi_phi;
    % size(Psi_inner);
    % Psi_inner
end