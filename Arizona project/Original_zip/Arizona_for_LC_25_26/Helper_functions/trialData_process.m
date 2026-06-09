function [f_j,u_j,e_j,p1_j,p2_j,y_j] = trialData_process(dataLog)
    % dataLog = logsOut

    % get indexes for the trial of length Nref
    trigger_data = find(dataLog, 'trialTrigger').Values.Data;
    trial_indexes =  find(trigger_data);
    
    % get trial data for output
    f_y = find(dataLog,'f_y [V]').Values.Data(trial_indexes);
    f_x = find(dataLog,'f_x [V]').Values.Data(trial_indexes);
    f_phi = find(dataLog,'f_phi [V]').Values.Data(trial_indexes); 
    f_j = [f_y, f_x, f_phi];

    u_y = find(dataLog,'u_y [V]').Values.Data(trial_indexes); 
    u_x = find(dataLog,'u_x [V]').Values.Data(trial_indexes); 
    u_phi = find(dataLog,'u_phi [V]').Values.Data(trial_indexes);
    u_j = [u_y, u_x, u_phi];

    y_y = find(dataLog,'y [m]').Values.Data(trial_indexes); 
    y_x = find(dataLog,'x [m]').Values.Data(trial_indexes); 
    y_phi = find(dataLog,'phi [m]').Values.Data(trial_indexes);
    y_j = [y_y, y_x, y_phi];
    

    u_loopback = find(dataLog,'u_loopback_y [V]').Values.Data(trial_indexes);

    e_y = find(dataLog,'e_y [m]').Values.Data(trial_indexes); 
    e_x = find(dataLog,'e_x [m]').Values.Data(trial_indexes); 
    e_phi = find(dataLog,'e_phi [rad]').Values.Data(trial_indexes); 
    e_j = [e_y, e_x, e_phi];

    p1_y = find(dataLog,'yNom [m]').Values.Data(trial_indexes); 
    p1_x = find(dataLog,'xNom [m]').Values.Data(trial_indexes); 
    p1_phi = find(dataLog,'phiNom [rad]').Values.Data(trial_indexes);

    p1_j = [p1_y, p1_x, p1_phi];

    p2_y = find(dataLog,'y_secundair [m]').Values.Data(trial_indexes); 
    p2_x1 = find(dataLog,'x_R_secundair [m]').Values.Data(trial_indexes); 
    p2_x2 = find(dataLog,'x_L_secundair [m]').Values.Data(trial_indexes);

    p2_j = [p2_y, p2_x1, p2_x2];

end
