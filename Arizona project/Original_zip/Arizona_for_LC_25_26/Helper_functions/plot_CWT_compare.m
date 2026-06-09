%% CWT comparison
Ts = 1e-3;
r1 = history.r(1,:,1);
figure(); plot(r1)
r1_r = round(r1,6); 

%[cfs_o,frq_o] = cwt(param_u_ini(i)*y_ref_set0 , 1/Ts,FrequencyLimits=[31 500],WaveletParameters=[3,60], VoicesPerOctave=[48]); 
[cfs_o,frq_o] = cwt(r1(1:5300), 1/Ts,FrequencyLimits=[30 500],WaveletParameters=[3,60], VoicesPerOctave=[48]); 
%[cfs_f,frq_f] = cwt(param_u_ini(i)*data_set_u(:,i), 1/Ts,FrequencyLimits=[31 500],WaveletParameters=[3,60], VoicesPerOctave=[48]);
[cfs_f,frq_f] = cwt(r1_r(1:5300), 1/Ts,FrequencyLimits=[30 500],WaveletParameters=[3,60], VoicesPerOctave=[48]);

figure();
subplot(2,1,1); 
pcolor(1:size(cfs_o,2),frq_o,abs(cfs_o(:,:)));
colorbar
shading flat
axis([1 5500 frq_o(end) frq_o(1) 0 max(max(abs(cfs_o)))])
xlabel('Time (s)')
ylabel('Frequency (Hz)')
title('')
subplot(2,1,2);
pcolor(1:size(cfs_f,2),frq_f,abs(cfs_f(:,:)));
colorbar
shading flat
axis([1 5500 frq_f(end) frq_f(1) 0 max(max(abs(cfs_f)))])
xlabel('Time (s)')
ylabel('Frequency (Hz)')
title('')