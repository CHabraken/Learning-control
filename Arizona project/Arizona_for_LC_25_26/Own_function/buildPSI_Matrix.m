function PSI = buildPSI_Matrix(Psi_y_xx, Psi_y_xp,Psi_ff_xx,Psi_ff_xp)

PSI = [
    Psi_y_xx zeroMatrix(Psi_y_xp,Psi_y_xx) zeroMatrix(Psi_ff_xx,Psi_y_xx) zeroMatrix(Psi_ff_xp,Psi_y_xx)
    zeroMatrix(Psi_y_xx,Psi_y_xp ) Psi_y_xp zeroMatrix(Psi_ff_xx,Psi_y_xp ) zeroMatrix(Psi_ff_xp,Psi_y_xp)       
    zeroMatrix(Psi_y_xx,Psi_ff_xx) zeroMatrix(Psi_y_xp,Psi_ff_xx) Psi_ff_xx zeroMatrix(Psi_ff_xp,Psi_ff_xx)
    zeroMatrix(Psi_y_xx,Psi_ff_xp) zeroMatrix(Psi_y_xp,Psi_ff_xp) zeroMatrix(Psi_ff_xx,Psi_ff_xp) Psi_ff_xp
    ];
end

