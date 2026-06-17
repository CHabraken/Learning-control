function [] = set_param_Arizona(paramName,value,tg)

    paramNames = {'startPenholder';
         'startTrial'; 
         'PenColor';
         'startHoming';
         'set_yRef';
         'set_xRef';
         'set_phiRef';
         'set_yFF';
         'set_xFF';
         'set_phiFF';
         'Enable_amplifier_y';
         'Enable_amplifier_xL';
         'Enable_amplifier_xR'};
    
    BlockPaths = {'Arizona_base_GOAT/startPenholder';
    'Arizona_base_GOAT/startTrial';
    'Arizona_base_GOAT/PenColor';
    'Arizona_base_GOAT/startHoming';
    'Arizona_base_GOAT/Trajectory/set_yRef';
    'Arizona_base_GOAT/Trajectory/set_xRef';
    'Arizona_base_GOAT/Trajectory/set_phiRef';
    'Arizona_base_GOAT/Feedforward/set_yFF';
    'Arizona_base_GOAT/Feedforward/set_xFF';
    'Arizona_base_GOAT/Feedforward/set_phiFF';
    'Arizona_base_GOAT/Safety/Enable_amplifier_y';
    'Arizona_base_GOAT/Safety/Enable_amplifier_xL';
    'Arizona_base_GOAT/Safety/Enable_amplifier_xR'};
    
    param_index = strcmp(paramNames, paramName);
    tg.setparam(BlockPaths{param_index},'Value',value);

end