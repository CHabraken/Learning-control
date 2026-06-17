README

Please check the Arizona - Manual before performing experiments!

Main file to run: \Runfiles --> Arizona_base_GOAT.m

You can insert your feedforwardupdate in \ILC_updates --> FeedforwardUpdate_ILC_BFIS.m

So you only need to adapt Arizona_base_GOAT.m and FeedforwardUpdate_ILC_BFIS.m. No need to touch other parts.

Please do not change code of Arizona_base_GOAT.m outside the sections specified as this can break the runfiles.



Additional information:

Please note that the following feedback controllers are ran on the setup:
xControllerBad.mat
PhiController.mat

Note that folder \Models contrains old parametric SISO models
Note that Model_new contains the same models as you already received, i.e., MIMO model

The reference applied is \References --> Reference_X_slow.mat and a second reference will follow.

You can neglect folder \Simfiles as you made your own simulation.



