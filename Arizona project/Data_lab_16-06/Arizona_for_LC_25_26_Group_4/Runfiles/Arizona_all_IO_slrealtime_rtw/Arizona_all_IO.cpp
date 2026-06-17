/*
 * Arizona_all_IO.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Arizona_all_IO".
 *
 * Model version              : 1.41
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C++ source code generated on : Wed Apr 30 13:15:42 2025
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Arizona_all_IO.h"
#include "rtwtypes.h"
#include "Arizona_all_IO_cal.h"
#include <cmath>

extern "C" {

#include "rt_nonfinite.h"

}
#include "Arizona_all_IO_private.h"

/* Block signals (default storage) */
B_Arizona_all_IO_T Arizona_all_IO_B;

/* Block states (default storage) */
DW_Arizona_all_IO_T Arizona_all_IO_DW;

/* Real-time model */
RT_MODEL_Arizona_all_IO_T Arizona_all_IO_M_ = RT_MODEL_Arizona_all_IO_T();
RT_MODEL_Arizona_all_IO_T *const Arizona_all_IO_M = &Arizona_all_IO_M_;
real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return static_cast<real_T>(*u) * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = std::sqrt(-2.0 * std::log(si) / si) * sr;
  return y;
}

/* Model step function */
void Arizona_all_IO_step(void)
{
  real_T x;

  /* S-Function (sg_IO141_IO142_setup_s): '<Root>/Setup 2' */

  /* Level2 S-Function Block: '<Root>/Setup 2' (sg_IO141_IO142_setup_s) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_IO141_IO142_ad_s): '<Root>/Analog input 1' */

  /* Level2 S-Function Block: '<Root>/Analog input 1' (sg_IO141_IO142_ad_s) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain' */
  Arizona_all_IO_B.Gain = Arizona_all_IO_cal->Gain_Gain *
    Arizona_all_IO_B.analogvelin;

  /* RandomNumber: '<S1>/White Noise' */
  Arizona_all_IO_B.WhiteNoise = Arizona_all_IO_DW.NextOutput;

  /* Gain: '<S1>/Output' */
  x = Arizona_all_IO_cal->BandLimitedWhiteNoiseforcarriag;
  x = std::sqrt(x);
  x /= 0.031622776601683791;

  /* Gain: '<S1>/Output' */
  Arizona_all_IO_B.Output = x * Arizona_all_IO_B.WhiteNoise;

  /* Gain: '<Root>/Gain1' */
  Arizona_all_IO_B.Gain1 = Arizona_all_IO_cal->Gain1_Gain *
    Arizona_all_IO_B.Output;

  /* Gain: '<Root>/Gain2' */
  Arizona_all_IO_B.Gain2 = Arizona_all_IO_cal->Gain2_Gain *
    Arizona_all_IO_B.Output;

  /* Gain: '<Root>/Gain3' */
  Arizona_all_IO_B.Gain3 = Arizona_all_IO_cal->Gain3_Gain *
    Arizona_all_IO_B.Output;

  /* Gain: '<Root>/Gain4' */
  Arizona_all_IO_B.gantry_input_enabled_L = Arizona_all_IO_cal->Gain4_Gain *
    Arizona_all_IO_B.Gain3;

  /* S-Function (sg_IO141_IO142_da_s): '<Root>/Analog output 2' */

  /* Level2 S-Function Block: '<Root>/Analog output 2' (sg_IO141_IO142_da_s) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_qad_sf_5): '<Root>/Cariage secundair' */

  /* Level2 S-Function Block: '<Root>/Cariage secundair' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<Root>/Carriage enable: 0=Inhibit, 1=Enable' */
  Arizona_all_IO_B.Carriageenable0Inhibit1Enable =
    Arizona_all_IO_cal->Carriageenable0Inhibit1Enable_V;

  /* S-Function (sg_fpga_do_sf_a2): '<Root>/DO Inhibit Carriage' */

  /* Level2 S-Function Block: '<Root>/DO Inhibit Carriage' (sg_fpga_do_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_qad_sf_5): '<Root>/Carriage encoder' */

  /* Level2 S-Function Block: '<Root>/Carriage encoder' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Carriage ' */

  /* Level2 S-Function Block: '<Root>/DI Limit Carriage ' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Carriage secundair (werkt niet)' */

  /* Level2 S-Function Block: '<Root>/DI Limit Carriage secundair (werkt niet)' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Gantry x1 = Gantry xR' */

  /* Level2 S-Function Block: '<Root>/DI Limit Gantry x1 = Gantry xR' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[8];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' */

  /* Level2 S-Function Block: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[9];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Gantry x2 = Gantry xL' */

  /* Level2 S-Function Block: '<Root>/DI Limit Gantry x2 = Gantry xL' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[10];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' */

  /* Level2 S-Function Block: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[11];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<Root>/DI black software button' */

  /* Level2 S-Function Block: '<Root>/DI black software button' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[12];
    sfcnOutputs(rts,0);
  }

  /* Logic: '<Root>/Logical Operator' */
  Arizona_all_IO_B.LogicalOperator = !(Arizona_all_IO_B.DIblacksoftwarebutton !=
    0.0);

  /* S-Function (sg_fpga_di_sf_a2): '<Root>/DI carriage amp. fault status' */

  /* Level2 S-Function Block: '<Root>/DI carriage amp. fault status' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[13];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<Root>/DI gantry x1 fault status' */

  /* Level2 S-Function Block: '<Root>/DI gantry x1 fault status' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[14];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<Root>/DI gantry x2 fault status' */

  /* Level2 S-Function Block: '<Root>/DI gantry x2 fault status' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[15];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<Root>/DI red software button' */

  /* Level2 S-Function Block: '<Root>/DI red software button' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[16];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<Root>/Gantry x1 enable: 0=Inhibit, 1=Enable' */
  Arizona_all_IO_B.Gantryx1enable0Inhibit1Enable =
    Arizona_all_IO_cal->Gantryx1enable0Inhibit1Enable_V;

  /* S-Function (sg_fpga_do_sf_a2): '<Root>/DO Inhibit Gantry x1 = Gantry xR' */

  /* Level2 S-Function Block: '<Root>/DO Inhibit Gantry x1 = Gantry xR' (sg_fpga_do_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[17];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<Root>/Gantry x2 enable: 0=Inhibit, 1=Enable' */
  Arizona_all_IO_B.Gantryx2enable0Inhibit1Enable =
    Arizona_all_IO_cal->Gantryx2enable0Inhibit1Enable_V;

  /* S-Function (sg_fpga_do_sf_a2): '<Root>/DO Inhibit Gantry x2 = DO Gantry xL' */

  /* Level2 S-Function Block: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL' (sg_fpga_do_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[18];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_qad_sf_5): '<Root>/Gantry x1 = Gantry xR' */

  /* Level2 S-Function Block: '<Root>/Gantry x1 = Gantry xR' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[19];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain9' */
  Arizona_all_IO_B.encodergantryx_R = Arizona_all_IO_cal->Gain9_Gain *
    Arizona_all_IO_B.Gantryx1GantryxR;

  /* S-Function (sg_fpga_qad_sf_5): '<Root>/Gantry X1 secundair' */

  /* Level2 S-Function Block: '<Root>/Gantry X1 secundair' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[20];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_qad_sf_5): '<Root>/Gantry x2 = Gantry xL' */

  /* Level2 S-Function Block: '<Root>/Gantry x2 = Gantry xL' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[21];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_qad_sf_5): '<Root>/Gentry X2 secundair' */

  /* Level2 S-Function Block: '<Root>/Gentry X2 secundair' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[22];
    sfcnOutputs(rts,0);
  }

  /* Update for RandomNumber: '<S1>/White Noise' */
  Arizona_all_IO_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&Arizona_all_IO_DW.RandSeed) * Arizona_all_IO_cal->WhiteNoise_StdDev +
    Arizona_all_IO_cal->WhiteNoise_Mean;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Arizona_all_IO_M->Timing.clockTick0)) {
    ++Arizona_all_IO_M->Timing.clockTickH0;
  }

  Arizona_all_IO_M->Timing.t[0] = Arizona_all_IO_M->Timing.clockTick0 *
    Arizona_all_IO_M->Timing.stepSize0 + Arizona_all_IO_M->Timing.clockTickH0 *
    Arizona_all_IO_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Arizona_all_IO_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtsiSetSolverName(&Arizona_all_IO_M->solverInfo,"FixedStepDiscrete");
  Arizona_all_IO_M->solverInfoPtr = (&Arizona_all_IO_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Arizona_all_IO_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Arizona_all_IO_M points to
       static memory which is guaranteed to be non-NULL" */
    Arizona_all_IO_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Arizona_all_IO_M->Timing.sampleTimes =
      (&Arizona_all_IO_M->Timing.sampleTimesArray[0]);
    Arizona_all_IO_M->Timing.offsetTimes =
      (&Arizona_all_IO_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Arizona_all_IO_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    Arizona_all_IO_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Arizona_all_IO_M, &Arizona_all_IO_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Arizona_all_IO_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Arizona_all_IO_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Arizona_all_IO_M, -1);
  Arizona_all_IO_M->Timing.stepSize0 = 0.001;
  Arizona_all_IO_M->solverInfoPtr = (&Arizona_all_IO_M->solverInfo);
  Arizona_all_IO_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Arizona_all_IO_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Arizona_all_IO_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) std::memset((static_cast<void *>(&Arizona_all_IO_B)), 0,
                     sizeof(B_Arizona_all_IO_T));

  {
    Arizona_all_IO_B.analogvelin = 0.0;
    Arizona_all_IO_B.Gain = 0.0;
    Arizona_all_IO_B.WhiteNoise = 0.0;
    Arizona_all_IO_B.Output = 0.0;
    Arizona_all_IO_B.Gain1 = 0.0;
    Arizona_all_IO_B.Gain2 = 0.0;
    Arizona_all_IO_B.Gain3 = 0.0;
    Arizona_all_IO_B.gantry_input_enabled_L = 0.0;
    Arizona_all_IO_B.Cariagesecundair = 0.0;
    Arizona_all_IO_B.Carriageenable0Inhibit1Enable = 0.0;
    Arizona_all_IO_B.Carriageencoder = 0.0;
    Arizona_all_IO_B.DILimitCarriage = 0.0;
    Arizona_all_IO_B.DILimitCarriagesecundairwerktni = 0.0;
    Arizona_all_IO_B.DILimitGantryx1GantryxR = 0.0;
    Arizona_all_IO_B.DILimitGantryx1secundairGantryx = 0.0;
    Arizona_all_IO_B.DILimitGantryx2GantryxL = 0.0;
    Arizona_all_IO_B.DILimitGantryx2secundairGantryx = 0.0;
    Arizona_all_IO_B.DIblacksoftwarebutton = 0.0;
    Arizona_all_IO_B.DIcarriageampfaultstatus = 0.0;
    Arizona_all_IO_B.DIgantryx1faultstatus = 0.0;
    Arizona_all_IO_B.DIgantryx2faultstatus = 0.0;
    Arizona_all_IO_B.DIredsoftwarebutton = 0.0;
    Arizona_all_IO_B.Gantryx1enable0Inhibit1Enable = 0.0;
    Arizona_all_IO_B.Gantryx2enable0Inhibit1Enable = 0.0;
    Arizona_all_IO_B.Gantryx1GantryxR = 0.0;
    Arizona_all_IO_B.encodergantryx_R = 0.0;
    Arizona_all_IO_B.GantryX1secundair = 0.0;
    Arizona_all_IO_B.Gantryx2GantryxL = 0.0;
    Arizona_all_IO_B.GentryX2secundair = 0.0;
  }

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&Arizona_all_IO_DW), 0,
                     sizeof(DW_Arizona_all_IO_T));
  Arizona_all_IO_DW.NextOutput = 0.0;
  Arizona_all_IO_DW.Cariagesecundair_RWORK = 0.0;
  Arizona_all_IO_DW.Carriageencoder_RWORK = 0.0;
  Arizona_all_IO_DW.Gantryx1GantryxR_RWORK = 0.0;
  Arizona_all_IO_DW.GantryX1secundair_RWORK = 0.0;
  Arizona_all_IO_DW.Gantryx2GantryxL_RWORK = 0.0;
  Arizona_all_IO_DW.GentryX2secundair_RWORK = 0.0;

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Arizona_all_IO_M->NonInlinedSFcns.sfcnInfo;
    Arizona_all_IO_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Arizona_all_IO_M)));
    Arizona_all_IO_M->Sizes.numSampTimes = (1);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Arizona_all_IO_M->Sizes.numSampTimes);
    Arizona_all_IO_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (Arizona_all_IO_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,Arizona_all_IO_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Arizona_all_IO_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Arizona_all_IO_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Arizona_all_IO_M));
    rtssSetStepSizePtr(sfcnInfo, &Arizona_all_IO_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Arizona_all_IO_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Arizona_all_IO_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &Arizona_all_IO_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Arizona_all_IO_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &Arizona_all_IO_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Arizona_all_IO_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Arizona_all_IO_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Arizona_all_IO_M->solverInfoPtr);
  }

  Arizona_all_IO_M->Sizes.numSFcns = (23);

  /* register each child */
  {
    (void) std::memset(static_cast<void *>
                       (&Arizona_all_IO_M->NonInlinedSFcns.childSFunctions[0]),
                       0,
                       23*sizeof(SimStruct));
    Arizona_all_IO_M->childSfunctions =
      (&Arizona_all_IO_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 23; i++) {
        Arizona_all_IO_M->childSfunctions[i] =
          (&Arizona_all_IO_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/Setup 2 (sg_IO141_IO142_setup_s) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[0]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* path info */
      ssSetModelName(rts, "Setup 2");
      ssSetPath(rts, "Arizona_all_IO/Setup 2");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 37);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Arizona_all_IO_cal->Setup2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Arizona_all_IO_cal->Setup2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Arizona_all_IO_cal->Setup2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Arizona_all_IO_cal->Setup2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Arizona_all_IO_cal->Setup2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Arizona_all_IO_cal->Setup2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)Arizona_all_IO_cal->Setup2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)Arizona_all_IO_cal->Setup2_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)Arizona_all_IO_cal->Setup2_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)Arizona_all_IO_cal->Setup2_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)Arizona_all_IO_cal->Setup2_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)Arizona_all_IO_cal->Setup2_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)Arizona_all_IO_cal->Setup2_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)Arizona_all_IO_cal->Setup2_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)Arizona_all_IO_cal->Setup2_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)Arizona_all_IO_cal->Setup2_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)Arizona_all_IO_cal->Setup2_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)Arizona_all_IO_cal->Setup2_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)Arizona_all_IO_cal->Setup2_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)Arizona_all_IO_cal->Setup2_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)Arizona_all_IO_cal->Setup2_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)Arizona_all_IO_cal->Setup2_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)Arizona_all_IO_cal->Setup2_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)Arizona_all_IO_cal->Setup2_P24_Size);
        ssSetSFcnParam(rts, 24, (mxArray*)Arizona_all_IO_cal->Setup2_P25_Size);
        ssSetSFcnParam(rts, 25, (mxArray*)Arizona_all_IO_cal->Setup2_P26_Size);
        ssSetSFcnParam(rts, 26, (mxArray*)Arizona_all_IO_cal->Setup2_P27_Size);
        ssSetSFcnParam(rts, 27, (mxArray*)Arizona_all_IO_cal->Setup2_P28_Size);
        ssSetSFcnParam(rts, 28, (mxArray*)Arizona_all_IO_cal->Setup2_P29_Size);
        ssSetSFcnParam(rts, 29, (mxArray*)Arizona_all_IO_cal->Setup2_P30_Size);
        ssSetSFcnParam(rts, 30, (mxArray*)Arizona_all_IO_cal->Setup2_P31_Size);
        ssSetSFcnParam(rts, 31, (mxArray*)Arizona_all_IO_cal->Setup2_P32_Size);
        ssSetSFcnParam(rts, 32, (mxArray*)Arizona_all_IO_cal->Setup2_P33_Size);
        ssSetSFcnParam(rts, 33, (mxArray*)Arizona_all_IO_cal->Setup2_P34_Size);
        ssSetSFcnParam(rts, 34, (mxArray*)Arizona_all_IO_cal->Setup2_P35_Size);
        ssSetSFcnParam(rts, 35, (mxArray*)Arizona_all_IO_cal->Setup2_P36_Size);
        ssSetSFcnParam(rts, 36, (mxArray*)Arizona_all_IO_cal->Setup2_P37_Size);
      }

      /* registration */
      sg_IO141_IO142_setup_s(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/Analog input 1 (sg_IO141_IO142_ad_s) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[1]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn1.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.analogvelin));
        }
      }

      /* path info */
      ssSetModelName(rts, "Analog input 1");
      ssSetPath(rts, "Arizona_all_IO/Analog input 1");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->Analoginput1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->Analoginput1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->Analoginput1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->Analoginput1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->Analoginput1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->Analoginput1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_all_IO_cal->Analoginput1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_all_IO_cal->Analoginput1_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_all_IO_cal->Analoginput1_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_all_IO_cal->Analoginput1_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_all_IO_cal->Analoginput1_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_all_IO_cal->Analoginput1_P12_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.Analoginput1_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.Analoginput1_PWORK[0]);
      }

      /* registration */
      sg_IO141_IO142_ad_s(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/Analog output 2 (sg_IO141_IO142_da_s) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[2]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn2.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Arizona_all_IO_B.Gain1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &Arizona_all_IO_B.Gain2);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }

        /* port 2 */
        {
          ssSetInputPortRequiredContiguous(rts, 2, 1);
          ssSetInputPortSignal(rts, 2, &Arizona_all_IO_B.gantry_input_enabled_L);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidthAsInt(rts, 2, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Analog output 2");
      ssSetPath(rts, "Arizona_all_IO/Analog output 2");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 14);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_all_IO_cal->Analogoutput2_P14_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.Analogoutput2_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.Analogoutput2_PWORK[0]);
      }

      /* registration */
      sg_IO141_IO142_da_s(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/Cariage secundair (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[3]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn3.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.Cariagesecundair));
        }
      }

      /* path info */
      ssSetModelName(rts, "Cariage secundair");
      ssSetPath(rts, "Arizona_all_IO/Cariage secundair");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       Arizona_all_IO_cal->Cariagesecundair_P24_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Arizona_all_IO_DW.Cariagesecundair_RWORK);
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.Cariagesecundair_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.Cariagesecundair_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Arizona_all_IO_DW.Cariagesecundair_PWORK[0]);
      }

      /* registration */
      sg_fpga_qad_sf_5(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DO Inhibit Carriage (sg_fpga_do_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[4]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn4.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn4.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Arizona_all_IO_B.Carriageenable0Inhibit1Enable);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "DO Inhibit Carriage");
      ssSetPath(rts, "Arizona_all_IO/DO Inhibit Carriage");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitCarriage_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitCarriage_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitCarriage_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitCarriage_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitCarriage_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitCarriage_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitCarriage_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitCarriage_P8_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.DOInhibitCarriage_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DOInhibitCarriage_PWORK[0]);
      }

      /* registration */
      sg_fpga_do_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/Carriage encoder (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[5]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn5.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.Carriageencoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Carriage encoder");
      ssSetPath(rts, "Arizona_all_IO/Carriage encoder");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       Arizona_all_IO_cal->Carriageencoder_P24_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Arizona_all_IO_DW.Carriageencoder_RWORK);
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.Carriageencoder_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.Carriageencoder_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Arizona_all_IO_DW.Carriageencoder_PWORK[0]);
      }

      /* registration */
      sg_fpga_qad_sf_5(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DI Limit Carriage  (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[6]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize[6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn6.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.DILimitCarriage));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI Limit Carriage ");
      ssSetPath(rts, "Arizona_all_IO/DI Limit Carriage ");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DILimitCarriage_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DILimitCarriage_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DILimitCarriage_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DILimitCarriage_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DILimitCarriage_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DILimitCarriage_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.DILimitCarriage_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DILimitCarriage_PWORK[0]);
      }

      /* registration */
      sg_fpga_di_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DI Limit Carriage secundair (werkt niet) (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[7]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize[7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn7.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn7.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.DILimitCarriagesecundairwerktni));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI Limit Carriage secundair (werkt niet)");
      ssSetPath(rts, "Arizona_all_IO/DI Limit Carriage secundair (werkt niet)");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DILimitCarriagesecundairwerktni);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DILimitCarriagesecundairwerkt_l);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DILimitCarriagesecundairwerkt_m);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DILimitCarriagesecundairwerk_cc);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DILimitCarriagesecundairwerkt_e);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DILimitCarriagesecundairwerk_kc);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_all_IO_DW.DILimitCarriagesecundairwerktni[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DILimitCarriagesecundairwerktni[0]);
      }

      /* registration */
      sg_fpga_di_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DI Limit Gantry x1 = Gantry xR (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[8]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize[8]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[8]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[8]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn8.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn8.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn8.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.DILimitGantryx1GantryxR));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI Limit Gantry x1 = Gantry xR");
      ssSetPath(rts, "Arizona_all_IO/DI Limit Gantry x1 = Gantry xR");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx1GantryxR_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx1GantryxR_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx1GantryxR_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx1GantryxR_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx1GantryxR_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx1GantryxR_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_all_IO_DW.DILimitGantryx1GantryxR_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DILimitGantryx1GantryxR_PWORK[0]);
      }

      /* registration */
      sg_fpga_di_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet) (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[9]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize[9]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[9]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[9]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[9]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[9]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn9.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn9.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn9.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.DILimitGantryx1secundairGantryx));
        }
      }

      /* path info */
      ssSetModelName(rts,
                     "DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)");
      ssSetPath(rts,
                "Arizona_all_IO/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx1secundairGantryx);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx1secundairGantr_l);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx1secundairGant_hm);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx1secundairGant_oo);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx1secundairGantr_n);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx1secundairGantr_i);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_all_IO_DW.DILimitGantryx1secundairGantryx[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn9.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn9.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DILimitGantryx1secundairGantryx[0]);
      }

      /* registration */
      sg_fpga_di_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DI Limit Gantry x2 = Gantry xL (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[10]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [10]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[10]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[10]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[10]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[10]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[10]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn10.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn10.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn10.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.DILimitGantryx2GantryxL));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI Limit Gantry x2 = Gantry xL");
      ssSetPath(rts, "Arizona_all_IO/DI Limit Gantry x2 = Gantry xL");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx2GantryxL_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx2GantryxL_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx2GantryxL_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx2GantryxL_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx2GantryxL_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx2GantryxL_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_all_IO_DW.DILimitGantryx2GantryxL_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn10.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn10.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DILimitGantryx2GantryxL_PWORK[0]);
      }

      /* registration */
      sg_fpga_di_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet) (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[11]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [11]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[11]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[11]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[11]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[11]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[11]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn11.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn11.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn11.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.DILimitGantryx2secundairGantryx));
        }
      }

      /* path info */
      ssSetModelName(rts,
                     "DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)");
      ssSetPath(rts,
                "Arizona_all_IO/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx2secundairGantryx);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx2secundairGantr_j);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx2secundairGant_kr);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx2secundairGant_k3);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx2secundairGant_n0);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DILimitGantryx2secundairGantr_d);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_all_IO_DW.DILimitGantryx2secundairGantryx[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn11.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn11.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DILimitGantryx2secundairGantryx[0]);
      }

      /* registration */
      sg_fpga_di_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DI black software button (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[12]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [12]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[12]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[12]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[12]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[12]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[12]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn12.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn12.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn12.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn12.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.DIblacksoftwarebutton));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI black software button");
      ssSetPath(rts, "Arizona_all_IO/DI black software button");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DIblacksoftwarebutton_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DIblacksoftwarebutton_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DIblacksoftwarebutton_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DIblacksoftwarebutton_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DIblacksoftwarebutton_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DIblacksoftwarebutton_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.DIblacksoftwarebutton_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn12.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn12.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DIblacksoftwarebutton_PWORK[0]);
      }

      /* registration */
      sg_fpga_di_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DI carriage amp. fault status (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[13]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [13]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[13]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[13]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[13]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[13]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[13]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[13]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn13.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn13.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn13.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn13.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.DIcarriageampfaultstatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI carriage amp. fault status");
      ssSetPath(rts, "Arizona_all_IO/DI carriage amp. fault status");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DIcarriageampfaultstatus_P1_Siz);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DIcarriageampfaultstatus_P2_Siz);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DIcarriageampfaultstatus_P3_Siz);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DIcarriageampfaultstatus_P4_Siz);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DIcarriageampfaultstatus_P5_Siz);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DIcarriageampfaultstatus_P6_Siz);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_all_IO_DW.DIcarriageampfaultstatus_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn13.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn13.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DIcarriageampfaultstatus_PWORK[0]);
      }

      /* registration */
      sg_fpga_di_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DI gantry x1 fault status (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[14];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn14.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn14.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn14.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[14]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [14]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[14]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[14]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[14]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[14]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[14]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[14]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn14.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn14.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn14.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn14.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.DIgantryx1faultstatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI gantry x1 fault status");
      ssSetPath(rts, "Arizona_all_IO/DI gantry x1 fault status");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn14.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DIgantryx1faultstatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DIgantryx1faultstatus_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DIgantryx1faultstatus_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DIgantryx1faultstatus_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DIgantryx1faultstatus_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DIgantryx1faultstatus_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.DIgantryx1faultstatus_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn14.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn14.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DIgantryx1faultstatus_PWORK[0]);
      }

      /* registration */
      sg_fpga_di_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DI gantry x2 fault status (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[15];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn15.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn15.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn15.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[15]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [15]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[15]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[15]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[15]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[15]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[15]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[15]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn15.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn15.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn15.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn15.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.DIgantryx2faultstatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI gantry x2 fault status");
      ssSetPath(rts, "Arizona_all_IO/DI gantry x2 fault status");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn15.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DIgantryx2faultstatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DIgantryx2faultstatus_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DIgantryx2faultstatus_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DIgantryx2faultstatus_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DIgantryx2faultstatus_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DIgantryx2faultstatus_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.DIgantryx2faultstatus_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn15.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn15.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DIgantryx2faultstatus_PWORK[0]);
      }

      /* registration */
      sg_fpga_di_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DI red software button (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[16];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn16.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn16.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn16.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[16]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [16]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[16]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[16]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[16]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[16]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[16]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[16]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn16.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn16.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn16.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn16.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.DIredsoftwarebutton));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI red software button");
      ssSetPath(rts, "Arizona_all_IO/DI red software button");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn16.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DIredsoftwarebutton_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DIredsoftwarebutton_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DIredsoftwarebutton_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DIredsoftwarebutton_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DIredsoftwarebutton_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DIredsoftwarebutton_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.DIredsoftwarebutton_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn16.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn16.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DIredsoftwarebutton_PWORK[0]);
      }

      /* registration */
      sg_fpga_di_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DO Inhibit Gantry x1 = Gantry xR (sg_fpga_do_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[17];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn17.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn17.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn17.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[17]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [17]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[17]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[17]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[17]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[17]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[17]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[17]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn17.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn17.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn17.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn17.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Arizona_all_IO_B.Gantryx1enable0Inhibit1Enable);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "DO Inhibit Gantry x1 = Gantry xR");
      ssSetPath(rts, "Arizona_all_IO/DO Inhibit Gantry x1 = Gantry xR");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn17.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx1GantryxR_P1_Si);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx1GantryxR_P2_Si);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx1GantryxR_P3_Si);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx1GantryxR_P4_Si);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx1GantryxR_P5_Si);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx1GantryxR_P6_Si);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx1GantryxR_P7_Si);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx1GantryxR_P8_Si);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_all_IO_DW.DOInhibitGantryx1GantryxR_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn17.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn17.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DOInhibitGantryx1GantryxR_PWORK[0]);
      }

      /* registration */
      sg_fpga_do_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/DO Inhibit Gantry x2 = DO Gantry xL (sg_fpga_do_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[18];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn18.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn18.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn18.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[18]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [18]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[18]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[18]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[18]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[18]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[18]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[18]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn18.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn18.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn18.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn18.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Arizona_all_IO_B.Gantryx2enable0Inhibit1Enable);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "DO Inhibit Gantry x2 = DO Gantry xL");
      ssSetPath(rts, "Arizona_all_IO/DO Inhibit Gantry x2 = DO Gantry xL");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn18.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx2DOGantryxL_P1_);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx2DOGantryxL_P2_);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx2DOGantryxL_P3_);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx2DOGantryxL_P4_);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx2DOGantryxL_P5_);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx2DOGantryxL_P6_);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx2DOGantryxL_P7_);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_all_IO_cal->DOInhibitGantryx2DOGantryxL_P8_);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_all_IO_DW.DOInhibitGantryx2DOGantryxL_PWO[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn18.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn18.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.DOInhibitGantryx2DOGantryxL_PWO[0]);
      }

      /* registration */
      sg_fpga_do_sf_a2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/Gantry x1 = Gantry xR (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[19];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn19.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn19.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn19.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[19]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [19]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[19]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[19]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[19]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[19]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[19]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[19]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn19.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn19.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn19.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn19.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.Gantryx1GantryxR));
        }
      }

      /* path info */
      ssSetModelName(rts, "Gantry x1 = Gantry xR");
      ssSetPath(rts, "Arizona_all_IO/Gantry x1 = Gantry xR");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn19.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       Arizona_all_IO_cal->Gantryx1GantryxR_P24_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Arizona_all_IO_DW.Gantryx1GantryxR_RWORK);
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.Gantryx1GantryxR_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn19.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn19.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.Gantryx1GantryxR_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Arizona_all_IO_DW.Gantryx1GantryxR_PWORK[0]);
      }

      /* registration */
      sg_fpga_qad_sf_5(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/Gantry X1 secundair (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[20];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn20.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn20.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn20.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[20]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [20]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[20]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[20]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[20]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[20]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[20]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[20]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn20.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn20.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn20.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn20.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.GantryX1secundair));
        }
      }

      /* path info */
      ssSetModelName(rts, "Gantry X1 secundair");
      ssSetPath(rts, "Arizona_all_IO/Gantry X1 secundair");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn20.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       Arizona_all_IO_cal->GantryX1secundair_P24_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Arizona_all_IO_DW.GantryX1secundair_RWORK);
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.GantryX1secundair_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn20.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn20.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.GantryX1secundair_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Arizona_all_IO_DW.GantryX1secundair_PWORK[0]);
      }

      /* registration */
      sg_fpga_qad_sf_5(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/Gantry x2 = Gantry xL (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[21];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn21.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn21.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn21.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[21]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [21]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[21]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[21]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[21]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[21]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[21]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[21]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn21.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn21.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn21.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn21.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.Gantryx2GantryxL));
        }
      }

      /* path info */
      ssSetModelName(rts, "Gantry x2 = Gantry xL");
      ssSetPath(rts, "Arizona_all_IO/Gantry x2 = Gantry xL");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn21.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       Arizona_all_IO_cal->Gantryx2GantryxL_P24_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Arizona_all_IO_DW.Gantryx2GantryxL_RWORK);
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.Gantryx2GantryxL_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn21.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn21.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.Gantryx2GantryxL_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Arizona_all_IO_DW.Gantryx2GantryxL_PWORK[0]);
      }

      /* registration */
      sg_fpga_qad_sf_5(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_all_IO/<Root>/Gentry X2 secundair (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[22];

      /* timing info */
      time_T *sfcnPeriod = Arizona_all_IO_M->NonInlinedSFcns.Sfcn22.sfcnPeriod;
      time_T *sfcnOffset = Arizona_all_IO_M->NonInlinedSFcns.Sfcn22.sfcnOffset;
      int_T *sfcnTsMap = Arizona_all_IO_M->NonInlinedSFcns.Sfcn22.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_all_IO_M->NonInlinedSFcns.blkInfo2[22]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_all_IO_M->NonInlinedSFcns.blkInfoSLSize
                              [22]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_all_IO_M->NonInlinedSFcns.inputOutputPortInfo2[22]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_all_IO_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods2[22]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods3[22]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_all_IO_M->NonInlinedSFcns.methods4[22]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_all_IO_M->NonInlinedSFcns.statesInfo2[22]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.periodicStatesInfo[22]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn22.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn22.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn22.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn22.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_all_IO_B.GentryX2secundair));
        }
      }

      /* path info */
      ssSetModelName(rts, "Gentry X2 secundair");
      ssSetPath(rts, "Arizona_all_IO/Gentry X2 secundair");
      ssSetRTModel(rts,Arizona_all_IO_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn22.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       Arizona_all_IO_cal->GentryX2secundair_P24_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Arizona_all_IO_DW.GentryX2secundair_RWORK);
      ssSetPWork(rts, (void **) &Arizona_all_IO_DW.GentryX2secundair_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn22.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_all_IO_M->NonInlinedSFcns.Sfcn22.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_all_IO_DW.GentryX2secundair_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Arizona_all_IO_DW.GentryX2secundair_PWORK[0]);
      }

      /* registration */
      sg_fpga_qad_sf_5(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  {
    /* user code (Start function Header) */
    {
      uint16_t moduleArchitecture;
      int32_t ErrCode;
      uint32_t *bitstream, i;
      uint8_t *fpgacode;
      char *devname;
      sg_fpga_io3xxModuleIdT moduleId;
      FILE *mcs;
      static char mcsFileName[200];
      static char msg[256];
      sg_initModelRun();

      // Create the MCS file and then add it to the mldatx

      // Determine path to bitstream file
      if (sg_getModelBaseDir(mcsFileName, sizeof(mcsFileName))) {
        sprintf(msg,
                "Could not determine location of the model on the target machine.");
        rtmSetErrorStatus(Arizona_all_IO_M, msg);
        return;
      }

      if ((strlen(mcsFileName) + strlen("/fpga/speedgoat_IO307_25k_CI_02479.mcs")
           + 1) > sizeof(mcsFileName)) {
        sprintf(msg,
                "Path to the bitstream (model name + bitstream name) is too long.");
        rtmSetErrorStatus(Arizona_all_IO_M, msg);
        return;
      }

      strcat(mcsFileName, "/fpga/speedgoat_IO307_25k_CI_02479.mcs");
      SG_PRINTF(DEBUG, "Bitstream: %s\n", mcsFileName);

#ifdef _MSC_BUILD

      if (sg_isModelInit())
#endif

        {
          if ((mcs = fopen(mcsFileName, "r")) == NULL) {
            sprintf(msg, "Bitstream file not found at %s.\n", mcsFileName);
            rtmSetErrorStatus(Arizona_all_IO_M, msg);
            SG_PRINTF(ERROR,msg);
            return;
          }

          bitstream = (uint32_t *) malloc(801530*sizeof(uint32_t));
          fpgacode = (uint8_t *) malloc(801530*sizeof(uint8_t));
          for (i = 0; i<801530; i++) {
            fscanf(mcs,"%d\n",&bitstream[i]);
            fpgacode[i] = bitstream[i];
          }

          fclose(mcs);

          // Get module IDs (PIC info)
          SG_PRINTF(INFO,"Getting module information.\n");
          ErrCode = (int32_t)sg_fpga_IO3xxGetModuleId(30725, &moduleId);
          if (ErrCode >= 0) {
            devname = moduleId.devname;
            moduleArchitecture = moduleId.moduleArchitecture;
            SG_PRINTF(DEBUG, "boardType: %d\n", 30725);
            SG_PRINTF(DEBUG, "ErrCode: %d\n", ErrCode);
            SG_PRINTF(DEBUG, "******************************************\n");
            SG_PRINTF(DEBUG, "moduleId->devname: %s\n", moduleId.devname);
            SG_PRINTF(DEBUG, "moduleId->vendorid: 0x%x\n", moduleId.vendorid);
            SG_PRINTF(DEBUG, "moduleId->subvendorid: 0x%x\n",
                      moduleId.subvendorid);
            SG_PRINTF(DEBUG, "moduleId->deviceid: 0x%x\n", moduleId.deviceid);
            SG_PRINTF(DEBUG, "moduleId->subdeviceid: 0x%x\n",
                      moduleId.subdeviceid);
            SG_PRINTF(DEBUG, "moduleId.moduleArchitecture: %d\n",
                      moduleId.moduleArchitecture);
          } else {
            sprintf(msg, "Setup block: board type unknown.");
            rtmSetErrorStatus(Arizona_all_IO_M, msg);
            SG_PRINTF(ERROR,msg);
            return;
          }

          // Support for different architectures
          SG_PRINTF(INFO,"Running board specific programming file.\n");
          switch (moduleArchitecture)
          {
           case TEWS_TPMC:
            ErrCode = IO30x_programFPGA(devname, (int16_t)-1, (int16_t)-1,
              (int32_t)1, (int32_t)1,
              (int32_t)0, (uint32_t)801530, bitstream,
              &moduleId);
            break;

           case TEWS_TXMC:
            if (30725 == 324200) {
              ErrCode = IO324_programmFPGA(devname, (int16_t)-1,
                (int16_t)-1, (int32_t)1, (int32_t)1,
                (int32_t)0, (uint32_t)801530, fpgacode,
                (uint32_t)0, &moduleId, (uint32_t)85, (uint32_t)0);
            } else                     // IO31x, IO32x
            {
              ErrCode = IO31x_IO32x_programmFPGA(devname, (int16_t)-1,
                (int16_t)-1, (int32_t)1, (int32_t)1,
                (int32_t)0, (uint32_t)801530, fpgacode,
                &moduleId, (uint32_t)85);
            }
            break;

           case ACROMAG_PMC:
            ErrCode = IO331_programmFPGA(devname, (int16_t)-1, (int16_t)-1,
              (int32_t)1, (int32_t)1,
              (uint32_t)801530, bitstream, &moduleId);
            break;

           case ACROMAG_XMC:
            if (30725 == 332) {
              ErrCode = IO332_programmFPGA(devname, (int16_t)-1,
                (int16_t)-1, (int32_t)1, (int32_t)1,
                (uint32_t)801530, bitstream, (uint32_t)0,
                &moduleId);
            } else                     // IO333
            {
              ErrCode = IO333_programmFPGA(devname, (int16_t)-1,
                (int16_t)-1, (int32_t)1, (int32_t)1,
                (uint32_t)801530, bitstream, (uint32_t)0,
                &moduleId);
            }
            break;

           case TEWS_MPCIE:
            ErrCode = IO39x_programmFPGA(devname, (int16_t)-1, (int16_t)-1,
              (int32_t)1, (int32_t)1,
              (uint32_t)801530, fpgacode, (uint32_t)85, &moduleId);
            break;

           default:
            sprintf(msg, "Setup block: module architecture incorrect.");
            rtmSetErrorStatus(Arizona_all_IO_M, msg);

            // Free the bitstream allocation
            SG_PRINTF(ERROR,msg);
            free(bitstream);
            free(fpgacode);
            return;
          }

          // Free the bitstream allocation
          free(bitstream);
          free(fpgacode);

          // Handle any error states
          switch (ErrCode)
          {
           case NO_ERR:
            // Nothing to do.
            break;

           case BOARD_NOT_FOUND:
            sprintf(msg, "Setup block %s: Board could not be found.\n",devname);
            rtmSetErrorStatus(Arizona_all_IO_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           case EEPROM_ERROR:
            sprintf(msg, "Setup block %s: Error updating board EEPROM.\n",
                    devname);
            rtmSetErrorStatus(Arizona_all_IO_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           case REPROG_ERROR:
            sprintf(msg,
                    "Setup block %s: Error writing new bitstream to FPGA.\n",
                    devname);
            rtmSetErrorStatus(Arizona_all_IO_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           case FLASH_ERROR:
            sprintf(msg, "Setup block %s: Bitstream flash storage error.\n",
                    devname);
            rtmSetErrorStatus(Arizona_all_IO_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           case BIST_ERROR:
            sprintf(msg, "Setup block %s: Built in self test error.\n", devname);
            rtmSetErrorStatus(Arizona_all_IO_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           case ICAP_RECONF_FAILED:
            sprintf(msg,
                    "Setup block %s: ICAP Reconfiguration was not successful.\n",
                    devname);
            rtmSetErrorStatus(Arizona_all_IO_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           case BOARD_TYPE_UNKNOWN:
            sprintf(msg, "Setup block %s: The board type selected is unknown.\n",
                    devname);
            rtmSetErrorStatus(Arizona_all_IO_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           default:
            sprintf(msg, "Setup block %s: An unknown error occurred.\n",devname);
            rtmSetErrorStatus(Arizona_all_IO_M, msg);
            SG_PRINTF(ERROR,msg);
            return;
          }

          if (1 == 2) {
            IO3xx_21_update(devname, 1, 0, 0, 0);
          } else if (1 == 3) {
            IO3xx_22_update(devname, 1, 0, 0, 0);
          }
        }
    }

    /* Start for S-Function (sg_IO141_IO142_setup_s): '<Root>/Setup 2' */
    /* Level2 S-Function Block: '<Root>/Setup 2' (sg_IO141_IO142_setup_s) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[0];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_IO141_IO142_ad_s): '<Root>/Analog input 1' */
    /* Level2 S-Function Block: '<Root>/Analog input 1' (sg_IO141_IO142_ad_s) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[1];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_IO141_IO142_da_s): '<Root>/Analog output 2' */
    /* Level2 S-Function Block: '<Root>/Analog output 2' (sg_IO141_IO142_da_s) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[2];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_qad_sf_5): '<Root>/Cariage secundair' */
    /* Level2 S-Function Block: '<Root>/Cariage secundair' (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[3];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for Constant: '<Root>/Carriage enable: 0=Inhibit, 1=Enable' */
    Arizona_all_IO_B.Carriageenable0Inhibit1Enable =
      Arizona_all_IO_cal->Carriageenable0Inhibit1Enable_V;

    /* Start for S-Function (sg_fpga_do_sf_a2): '<Root>/DO Inhibit Carriage' */
    /* Level2 S-Function Block: '<Root>/DO Inhibit Carriage' (sg_fpga_do_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[4];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_qad_sf_5): '<Root>/Carriage encoder' */
    /* Level2 S-Function Block: '<Root>/Carriage encoder' (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[5];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Carriage ' */
    /* Level2 S-Function Block: '<Root>/DI Limit Carriage ' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[6];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Carriage secundair (werkt niet)' */
    /* Level2 S-Function Block: '<Root>/DI Limit Carriage secundair (werkt niet)' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[7];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Gantry x1 = Gantry xR' */
    /* Level2 S-Function Block: '<Root>/DI Limit Gantry x1 = Gantry xR' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[8];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' */
    /* Level2 S-Function Block: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[9];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Gantry x2 = Gantry xL' */
    /* Level2 S-Function Block: '<Root>/DI Limit Gantry x2 = Gantry xL' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[10];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' */
    /* Level2 S-Function Block: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[11];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<Root>/DI black software button' */
    /* Level2 S-Function Block: '<Root>/DI black software button' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[12];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<Root>/DI carriage amp. fault status' */
    /* Level2 S-Function Block: '<Root>/DI carriage amp. fault status' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[13];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<Root>/DI gantry x1 fault status' */
    /* Level2 S-Function Block: '<Root>/DI gantry x1 fault status' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[14];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<Root>/DI gantry x2 fault status' */
    /* Level2 S-Function Block: '<Root>/DI gantry x2 fault status' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[15];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<Root>/DI red software button' */
    /* Level2 S-Function Block: '<Root>/DI red software button' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[16];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for Constant: '<Root>/Gantry x1 enable: 0=Inhibit, 1=Enable' */
    Arizona_all_IO_B.Gantryx1enable0Inhibit1Enable =
      Arizona_all_IO_cal->Gantryx1enable0Inhibit1Enable_V;

    /* Start for S-Function (sg_fpga_do_sf_a2): '<Root>/DO Inhibit Gantry x1 = Gantry xR' */
    /* Level2 S-Function Block: '<Root>/DO Inhibit Gantry x1 = Gantry xR' (sg_fpga_do_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[17];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for Constant: '<Root>/Gantry x2 enable: 0=Inhibit, 1=Enable' */
    Arizona_all_IO_B.Gantryx2enable0Inhibit1Enable =
      Arizona_all_IO_cal->Gantryx2enable0Inhibit1Enable_V;

    /* Start for S-Function (sg_fpga_do_sf_a2): '<Root>/DO Inhibit Gantry x2 = DO Gantry xL' */
    /* Level2 S-Function Block: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL' (sg_fpga_do_sf_a2) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[18];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_qad_sf_5): '<Root>/Gantry x1 = Gantry xR' */
    /* Level2 S-Function Block: '<Root>/Gantry x1 = Gantry xR' (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[19];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_qad_sf_5): '<Root>/Gantry X1 secundair' */
    /* Level2 S-Function Block: '<Root>/Gantry X1 secundair' (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[20];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_qad_sf_5): '<Root>/Gantry x2 = Gantry xL' */
    /* Level2 S-Function Block: '<Root>/Gantry x2 = Gantry xL' (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[21];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_qad_sf_5): '<Root>/Gentry X2 secundair' */
    /* Level2 S-Function Block: '<Root>/Gentry X2 secundair' (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_all_IO_M->childSfunctions[22];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  {
    real_T tmp;
    int32_T r;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for RandomNumber: '<S1>/White Noise' */
    tmp = std::floor(Arizona_all_IO_cal->BandLimitedWhiteNoiseforcarri_p);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    r = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(r) << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    Arizona_all_IO_DW.RandSeed = tseed;
    Arizona_all_IO_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&Arizona_all_IO_DW.RandSeed) * Arizona_all_IO_cal->WhiteNoise_StdDev +
      Arizona_all_IO_cal->WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S1>/White Noise' */
  }
}

/* Model terminate function */
void Arizona_all_IO_terminate(void)
{
  /* Terminate for S-Function (sg_IO141_IO142_setup_s): '<Root>/Setup 2' */
  /* Level2 S-Function Block: '<Root>/Setup 2' (sg_IO141_IO142_setup_s) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_IO141_IO142_ad_s): '<Root>/Analog input 1' */
  /* Level2 S-Function Block: '<Root>/Analog input 1' (sg_IO141_IO142_ad_s) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_IO141_IO142_da_s): '<Root>/Analog output 2' */
  /* Level2 S-Function Block: '<Root>/Analog output 2' (sg_IO141_IO142_da_s) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_qad_sf_5): '<Root>/Cariage secundair' */
  /* Level2 S-Function Block: '<Root>/Cariage secundair' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_do_sf_a2): '<Root>/DO Inhibit Carriage' */
  /* Level2 S-Function Block: '<Root>/DO Inhibit Carriage' (sg_fpga_do_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_qad_sf_5): '<Root>/Carriage encoder' */
  /* Level2 S-Function Block: '<Root>/Carriage encoder' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Carriage ' */
  /* Level2 S-Function Block: '<Root>/DI Limit Carriage ' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Carriage secundair (werkt niet)' */
  /* Level2 S-Function Block: '<Root>/DI Limit Carriage secundair (werkt niet)' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Gantry x1 = Gantry xR' */
  /* Level2 S-Function Block: '<Root>/DI Limit Gantry x1 = Gantry xR' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' */
  /* Level2 S-Function Block: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Gantry x2 = Gantry xL' */
  /* Level2 S-Function Block: '<Root>/DI Limit Gantry x2 = Gantry xL' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' */
  /* Level2 S-Function Block: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<Root>/DI black software button' */
  /* Level2 S-Function Block: '<Root>/DI black software button' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<Root>/DI carriage amp. fault status' */
  /* Level2 S-Function Block: '<Root>/DI carriage amp. fault status' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<Root>/DI gantry x1 fault status' */
  /* Level2 S-Function Block: '<Root>/DI gantry x1 fault status' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[14];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<Root>/DI gantry x2 fault status' */
  /* Level2 S-Function Block: '<Root>/DI gantry x2 fault status' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[15];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<Root>/DI red software button' */
  /* Level2 S-Function Block: '<Root>/DI red software button' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[16];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_do_sf_a2): '<Root>/DO Inhibit Gantry x1 = Gantry xR' */
  /* Level2 S-Function Block: '<Root>/DO Inhibit Gantry x1 = Gantry xR' (sg_fpga_do_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[17];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_do_sf_a2): '<Root>/DO Inhibit Gantry x2 = DO Gantry xL' */
  /* Level2 S-Function Block: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL' (sg_fpga_do_sf_a2) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[18];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_qad_sf_5): '<Root>/Gantry x1 = Gantry xR' */
  /* Level2 S-Function Block: '<Root>/Gantry x1 = Gantry xR' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[19];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_qad_sf_5): '<Root>/Gantry X1 secundair' */
  /* Level2 S-Function Block: '<Root>/Gantry X1 secundair' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[20];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_qad_sf_5): '<Root>/Gantry x2 = Gantry xL' */
  /* Level2 S-Function Block: '<Root>/Gantry x2 = Gantry xL' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[21];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_qad_sf_5): '<Root>/Gentry X2 secundair' */
  /* Level2 S-Function Block: '<Root>/Gentry X2 secundair' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_all_IO_M->childSfunctions[22];
    sfcnTerminate(rts);
  }

  /* user code (Terminate function Trailer) */
  {
    volatile io3xx_pull *ptrIO31x_pull;
    volatile io3xx_2x *ptrio3xx_2x;
    uint16_t moduleArchitecture;
    sg_fpga_io3xxModuleIdT moduleId;

#ifdef _MSC_BUILD

    if (!sg_isModelInit())
#endif

      {
        // Get module IDs (PIC info)
        sg_fpga_IO3xxGetModuleId(30725, &moduleId);
        moduleArchitecture = moduleId.moduleArchitecture;
        SG_PRINTF(DEBUG, "moduleArchitecture %d\n",moduleArchitecture);
        if (moduleArchitecture == TEWS_TXMC) {
          // Get pointer to io31x_pull
          ptrIO31x_pull = (io3xx_pull *)((uintptr_t)io3xxGetAddressSgLib(
            (int32_t)1, SG_FPGA_IO3XX_BAR2) + IO3xx_PULL_BASE);

          // Disable pull resistors
          ptrIO31x_pull->enable = 0x0; // disable
        }

        // Pull down and disable DIOs
        if (1 >= 2) {
          ptrio3xx_2x = (io3xx_2x *)(
            (uintptr_t)io3xxGetAddressSgLib((int32_t)1, SG_FPGA_IO3XX_BAR2) +
            IO3xx_2x_BASE);
          ptrio3xx_2x->pull = 0xffffffff;// pull down
          ptrio3xx_2x->dir = 0x0;      // input
          ptrio3xx_2x->update = 0x1;
          sg_wait_s(SG_FPGA_WAIT_TIME_100us);
          ptrio3xx_2x->update = 0x0;
          sg_wait_s(SG_FPGA_WAIT_TIME_1ms);

#if DEBUGGING

          // For debugging output port register of IO-Expander
          sg_wait_s(SG_FPGA_WAIT_TIME_100ms);
          SG_PRINTF(INFO, "last configuration from mdl start\n");
          SG_PRINTF(INFO, "rxData of Expander1: 0x%X\n",
                    ptrio3xx_2x->rxDataExpander1);
          SG_PRINTF(INFO, "rxData of Expander2: 0x%X\n",
                    ptrio3xx_2x->rxDataExpander2);
          SG_PRINTF(INFO, "rxData of Expander3: 0x%X\n",
                    ptrio3xx_2x->rxDataExpander3);
          SG_PRINTF(INFO, "rxData of Expander4: 0x%X\n",
                    ptrio3xx_2x->rxDataExpander4);

#endif

        }
      }
  }
}
