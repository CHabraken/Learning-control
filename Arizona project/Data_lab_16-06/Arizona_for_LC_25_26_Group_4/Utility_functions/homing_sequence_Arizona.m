%% ==========================================================================
% Runfile to start homing sequence
% ===========================================================================

% Start SG datastreaming
startRecording(tg);
                                                        
                                         
% Start homing procedure
set_param_Arizona('startHoming',1,tg);
pause(1)
set_param_Arizona('startHoming',0,tg);

% Await homing procedure.
while ~tg.getsignal('Arizona_base_GOAT/Homing',4)
   pause(0.1);
end


% End SG datastreaming
stopRecording(tg);                                                          