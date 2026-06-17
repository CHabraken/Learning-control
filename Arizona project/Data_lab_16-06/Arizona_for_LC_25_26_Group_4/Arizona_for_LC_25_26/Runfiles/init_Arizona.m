%% INIT file
close all
clc
addpath('../Controllers')
addpath('../Helper_functions')
addpath('../Utility_functions')
addpath('../Pars')
addpath('../Plotter_functions')
addpath('../Reference_generators')
addpath('../References')
addpath('Simulink')
addpath('../Build')
addpath('../ILC_updates')
addpath('../Penholder_settings') 
addpath('../Models')
set_interpreter_latex

Ts = get_Arizona_pars();

