function [] = enable_motor_amplifiers(mode, tg)

% Change the Arizona motor amplifier mode
set_param_Arizona('Enable_amplifier_y', mode,tg);
set_param_Arizona('Enable_amplifier_xL',mode,tg);
set_param_Arizona('Enable_amplifier_xR',mode,tg);
end