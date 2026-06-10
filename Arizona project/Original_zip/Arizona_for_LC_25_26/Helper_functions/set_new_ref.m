function  [] = set_new_ref(reference,tg)
    
    tg.setparam('Arizona_base_GOAT/Trajectory/set_yRef', 'Value', squeeze(reference(:,:,1)'));
    tg.setparam('Arizona_base_GOAT/Trajectory/set_xRef', 'Value', squeeze(reference(:,:,2)'));
    tg.setparam('Arizona_base_GOAT/Trajectory/set_phiRef', 'Value', squeeze(reference(:,:,3)'));

end