function  [] = set_new_feedforward(feedforward,tg)

    tg.setparam('Arizona_base_GOAT/Feedforward/set_yFF', 'Value', squeeze(feedforward(:,:,1)'));
    tg.setparam('Arizona_base_GOAT/Feedforward/set_xFF', 'Value', squeeze(feedforward(:,:,2)'));
    tg.setparam('Arizona_base_GOAT/Feedforward/set_phiFF', 'Value', squeeze(feedforward(:,:,3)'));

end