function fig_mag_phase_coh = init_bode_coherence_plot(fignr)
fig_mag_phase_coh = figure(fignr); 
subplot(311); hold on; grid on; xlabel('Frequency [Hz]'); ylabel('Magnitude [dB]'); ax = gca; ax.XScale = 'log';
subplot(312); hold on; grid on; xlabel('Frequency [Hz]'); ylabel('Phase [deg]'); ax = gca; ax.XScale = 'log';
subplot(313); hold on; grid on; xlabel('Frequency [Hz]'); ylabel('Coherence [-]'); ax = gca; ax.XScale = 'log';
end