/*
 * Arizona_base_GOAT.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Arizona_base_GOAT".
 *
 * Model version              : 12.234
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C++ source code generated on : Fri May 29 15:30:46 2026
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Arizona_base_GOAT_h_
#define RTW_HEADER_Arizona_base_GOAT_h_
#include <logsrv.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "verify/verifyIntrf.h"
#include "sg_fpga_io30x_setup_util.h"
#include "sg_fpga_io31x_io32x_setup_util.h"
#include "sg_fpga_io33x_setup_util.h"
#include "sg_fpga_io39x_setup_util.h"
#include "sg_common.h"
#include "sg_printf.h"
#include "Arizona_base_GOAT_types.h"
#include <stddef.h>
#include <cstring>
#include "Arizona_base_GOAT_cal.h"

extern "C" {

#include "rt_nonfinite.h"

}
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (default storage) */
struct B_Arizona_base_GOAT_T {
  real_T analogvelin;                  /* '<S5>/Analog input 1' */
  real_T Analoginput1_o2;              /* '<S5>/Analog input 1' */
  real_T DIcarriagelimitswitch;        /* '<S5>/DI Limit Carriage ' */
  real_T DIgantryx1limitswitch;      /* '<S5>/DI Limit Gantry x1 = Gantry xR' */
  real_T DIgantryx2limitswitch;      /* '<S5>/DI Limit Gantry x2 = Gantry xL' */
  real_T DIblacksoftwarebutton;        /* '<S5>/DI black software button' */
  real_T DIcarriageamplifyerstatus;   /* '<S5>/DI carriage amp. fault status' */
  real_T DIgantryx1amplifyerstatus;    /* '<S5>/DI gantry x1 fault status' */
  real_T DIgantryx2amplifyerstatus;    /* '<S5>/DI gantry x2 fault status' */
  real_T DIredsoftwarefunctionbutton;  /* '<S5>/DI red software button' */
  real_T AIcarriagevelocitymonitor;    /* '<S5>/Gain1' */
  real_T Carriageencoder;              /* '<S5>/Carriage encoder' */
  real_T Calibration1;                 /* '<S5>/Calibration1' */
  real_T encodercarriage;              /* '<S5>/Gain5' */
  real_T Gantryx1GantryxR;             /* '<S5>/Gantry x1 = Gantry xR' */
  real_T Calibration2;                 /* '<S5>/Calibration2' */
  real_T encodergantryx1;              /* '<S5>/Gain6' */
  real_T Gantryx2GantryxL;             /* '<S5>/Gantry x2 = Gantry xL' */
  real_T Calibration3;                 /* '<S5>/Calibration3' */
  real_T encodergantryx2;              /* '<S5>/Gain7' */
  real_T u_loopback_yV;                /* '<S5>/Gain' */
  real_T penholderActive;              /* '<Root>/log_penholder_active' */
  real_T Delay2;                       /* '<Root>/Delay2' */
  real_T Delay1;                       /* '<S21>/Delay1' */
  real_T Delay;                        /* '<S21>/Delay' */
  real_T Switch1;                      /* '<S21>/Switch1' */
  real_T trialTrigger;                 /* '<Root>/Delay1' */
  real_T r_ym;                         /* '<Root>/reference_y' */
  real_T errory;                       /* '<Root>/error y' */
  real_T e_ym;                         /* '<Root>/Gain8' */
  real_T yNomm;                        /* '<S10>/Sum yNom' */
  real_T Dct2lowpassoutput_y;          /* '<S10>/Dct2lowpass output_y' */
  real_T TSamp;                        /* '<S41>/TSamp' */
  real_T Uk1;                          /* '<S41>/UD' */
  real_T Diff;                         /* '<S41>/Diff' */
  real_T Delay1_g;                     /* '<S20>/Delay1' */
  real_T Delay_m;                      /* '<S20>/Delay' */
  real_T Switch1_h;                    /* '<S20>/Switch1' */
  real_T r_xm;                         /* '<Root>/reference_x' */
  real_T Sumx_Lx_R;                    /* '<S2>/Sum x_L + x_R' */
  real_T Gainx;                        /* '<S2>/Gain x' */
  real_T errorx;                       /* '<Root>/error x' */
  real_T e_xm;                         /* '<Root>/Gain9' */
  real_T xNomm;                        /* '<S10>/Sum xNom' */
  real_T Dct2lowpassoutput_x;          /* '<S10>/Dct2lowpass output_x' */
  real_T TSamp_n;                      /* '<S40>/TSamp' */
  real_T Uk1_o;                        /* '<S40>/UD' */
  real_T Diff_n;                       /* '<S40>/Diff' */
  real_T Delay1_b;                     /* '<S19>/Delay1' */
  real_T main;                         /* '<S19>/Sum' */
  real_T Delay_j;                      /* '<S19>/Delay' */
  real_T Switch1_c;                    /* '<S19>/Switch1' */
  real_T r_phirad;                     /* '<Root>/reference phi' */
  real_T Sumx_Rx_L;                    /* '<S2>/Sum x_R - x_L' */
  real_T Gainphi;                      /* '<S2>/Gain phi' */
  real_T errorphi;                     /* '<Root>/error phi' */
  real_T e_phirad;                     /* '<Root>/Gain10' */
  real_T phiNomrad;                    /* '<S10>/Sum phiNom' */
  real_T Dct2lowpasscurrent_gantryAirbag;
                                  /* '<S10>/Dct2lowpass current_gantryAirbag' */
  real_T Internal;                     /* '<S7>/Internal' */
  real_T u_xV;                         /* '<Root>/Sum current x' */
  real_T Gainonu_x;                    /* '<S1>/Gain on u_x' */
  real_T Internal_j;                   /* '<S8>/Internal' */
  real_T u_phiV;                       /* '<Root>/Sum current phi' */
  real_T Gainonu_phi;                  /* '<S1>/Gain on u_phi' */
  real_T Sumcurrentx_R;                /* '<S1>/Sum current x_R' */
  real_T gantryx_Rmotorvoltage;        /* '<S10>/Switch current_yr' */
  real_T gantryx1motorvoltage;        /* '<S5>/Gain gantry x2 motor current1' */
  real_T Sumcurrentx_L;                /* '<S1>/Sum current x_L' */
  real_T gantryx_Lmotorvoltage;        /* '<S10>/Switch current_yl' */
  real_T gantryx2motorvoltage;         /* '<S5>/Gain gantry x2 motor current' */
  real_T Dct2lowpasscurrent_carriageAirb;
                                /* '<S10>/Dct2lowpass current_carriageAirbag' */
  real_T Internal_g;                   /* '<S6>/Internal' */
  real_T u_yV;                         /* '<Root>/Sum current y' */
  real_T carriagemotorvoltage;         /* '<S10>/Switch current_x' */
  real_T carriagemotorvoltage_o;       /* '<S5>/Gain carriage motor current' */
  real_T carriageamplifierenable;      /* '<S10>/Enable_amplifier_y' */
  real_T gantryx_Ramplifierenable;     /* '<S10>/Enable_amplifier_xR' */
  real_T gantryx_Lamplifierenable;     /* '<S10>/Enable_amplifier_xL' */
  real_T Cariagesecundair;             /* '<S5>/Cariage secundair' */
  real_T Calibration4;                 /* '<S5>/Calibration4' */
  real_T y_secundairm;                 /* '<S5>/Gain8' */
  real_T GantryX1secundair;            /* '<S5>/Gantry X1 secundair' */
  real_T Calibration5;                 /* '<S5>/Calibration5' */
  real_T x_R_secundairm;               /* '<S5>/Gain9' */
  real_T GentryX2secundair;            /* '<S5>/Gentry X2 secundair' */
  real_T Calibration6;                 /* '<S5>/Calibration6' */
  real_T x_L_secundairm;               /* '<S5>/Gain10' */
  real_T DIcarriagelimitswitchsecundaird;
                           /* '<S5>/DI Limit Carriage secundair (werkt niet)' */
  real_T DIgantryx1limitswitchsecundaird;
  /* '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' */
  real_T DIgantryx2limitswitchsecundaird;
  /* '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' */
  real_T startHoming;                  /* '<Root>/startHoming' */
  real_T startTrial;                   /* '<Root>/startTrial' */
  real_T startPenholder;               /* '<Root>/startPenholder' */
  real_T PenColor;                     /* '<Root>/PenColor' */
  real_T Memory_loop_phi;              /* '<S19>/Switch' */
  real_T Memory_loop_x;                /* '<S20>/Switch' */
  real_T Memory_loop_y;                /* '<S21>/Switch' */
  real_T Switch1_hm;                   /* '<Root>/Switch1' */
  real_T DataTypeConversion2;          /* '<S9>/Data Type Conversion2' */
  real_T DataTypeConversion1;          /* '<S9>/Data Type Conversion1' */
  real_T DataTypeConversion3;          /* '<S9>/Data Type Conversion3' */
  real_T jogSpeed;                     /* '<S9>/log_jogspeed' */
  real_T Gainonphi2;                   /* '<S9>/Gain on phi2' */
  real_T Abs;                          /* '<S32>/Abs' */
  real_T Abs_d;                        /* '<S35>/Abs' */
  real_T Gain1;                        /* '<S35>/Gain1' */
  real_T Abs1;                         /* '<S35>/Abs1' */
  real_T Switch;                       /* '<S35>/Switch' */
  real_T Divide;                       /* '<S35>/Divide' */
  real_T Gain;                         /* '<S35>/Gain' */
  real_T Subtract;                     /* '<S35>/Subtract' */
  real_T Divide1;                      /* '<S35>/Divide1' */
  real_T Divide2;                      /* '<S35>/Divide2' */
  real_T Divide3;                      /* '<S35>/Divide3' */
  real_T Gain8;                        /* '<S35>/Gain8' */
  real_T Sign2;                        /* '<S35>/Sign2' */
  real_T XtranMo_DIR;                  /* '<S35>/Saturation2' */
  real_T Gainonphi3;                   /* '<S9>/Gain on phi3' */
  real_T Abs1_l;                       /* '<S33>/Abs1' */
  real_T Abs_dw;                       /* '<S38>/Abs' */
  real_T Gain1_d;                      /* '<S38>/Gain1' */
  real_T Abs1_m;                       /* '<S38>/Abs1' */
  real_T Switch_i;                     /* '<S38>/Switch' */
  real_T Divide_b;                     /* '<S38>/Divide' */
  real_T Gain_b;                       /* '<S38>/Gain' */
  real_T Subtract_g;                   /* '<S38>/Subtract' */
  real_T Divide1_c;                    /* '<S38>/Divide1' */
  real_T Divide2_c;                    /* '<S38>/Divide2' */
  real_T Divide3_g;                    /* '<S38>/Divide3' */
  real_T Gain8_o;                      /* '<S38>/Gain8' */
  real_T Sign2_g;                      /* '<S38>/Sign2' */
  real_T XtranMo_DIR_k;                /* '<S38>/Saturation2' */
  real_T homeTrigger;             /* '<Root>/Trial control without penholder' */
  real_T trialTrigger_e;          /* '<Root>/Trial control without penholder' */
  real_T trialIndex;              /* '<Root>/Trial control without penholder' */
  real_T change_color;            /* '<Root>/Trial control without penholder' */
  real_T Product;                      /* '<S11>/Product' */
  real_T Sum;                          /* '<S11>/Sum' */
  real_T time;                         /* '<S11>/Data Type Conversion' */
  real_T yref_check;                   /* '<S11>/Direct Lookup Table yRef' */
  real_T DirectLookupTablechange_color;
                                  /* '<S11>/Direct Lookup Table change_color' */
  real_T DirectLookupTablephiRef;      /* '<S11>/Direct Lookup Table phiRef' */
  real_T DirectLookupTablexRef;        /* '<S11>/Direct Lookup Table xRef' */
  real_T Memory;                       /* '<S44>/Memory' */
  real_T Switch_b;                     /* '<Root>/Switch' */
  real_T current_carriageAirbag;       /* '<S10>/Supervisor' */
  real_T enableAirbags;                /* '<S10>/Supervisor' */
  real_T current_gantryAirbag;         /* '<S10>/Supervisor' */
  real_T stopSimulation;               /* '<S10>/Supervisor' */
  real_T jogspeed_Z;                   /* '<S9>/Change color Chart' */
  real_T jogspeed_Theta;               /* '<S9>/Change color Chart' */
  real_T active;                       /* '<S9>/Change color Chart' */
  real_T Sum_o;                        /* '<S21>/Sum' */
  real_T Sum_k;                        /* '<S20>/Sum' */
  real_T Delay_l;                      /* '<S15>/Delay' */
  real_T Switch_bb;                    /* '<S15>/Switch' */
  real_T Sum_b;                        /* '<S15>/Sum' */
  real_T home_time;                   /* '<S15>/Data Type Conversion counter' */
  real_T DirectLookupTableyFF;         /* '<S15>/Direct Lookup Table yFF' */
  real_T DirectLookupTablexFF;         /* '<S15>/Direct Lookup Table xFF' */
  real_T DirectLookupTablephiFF;       /* '<S15>/Direct Lookup Table phiFF' */
  real_T jogdistance_y_reset; /* '<S16>/Discrete-Time Integrator x2JogSpeed1' */
  real_T DiscreteTimeIntegratorx2JogSpee;
                               /* '<S16>/Discrete-Time Integrator x2JogSpeed' */
  real_T DiscreteTimeIntegratorx1JogSpee;
                               /* '<S16>/Discrete-Time Integrator x1JogSpeed' */
  real_T current_x4;                   /* '<S16>/current_x4' */
  real_T jogdistance_x_reset;          /* '<S16>/Gain x2' */
  real_T current_x3;                   /* '<S16>/current_x3' */
  real_T jogdistance_phi_reset;        /* '<S16>/Gain x3' */
  real_T AddphiHome;                   /* '<S13>/Add phiHome' */
  real_T AddxHome;                     /* '<S13>/Add xHome' */
  real_T AddyHome;                     /* '<S13>/Add yHome' */
  real_T DataTypeConversionendtrial;/* '<S15>/Data Type Conversion end trial' */
  real_T jogspeed_xR_reset;            /* '<S16>/Dct2lowpass x1JogSpeed' */
  real_T jogspeed_xL_reset;            /* '<S16>/Dct2lowpass x2JogSpeed' */
  real_T jogspeed_y_reset;             /* '<S16>/Dct2lowpass yJogSpeed' */
  real_T jogspeed_y_reset_d;           /* '<S16>/Supervisor' */
  real_T jogspeed_xL_reset_j;          /* '<S16>/Supervisor' */
  real_T jogspeed_xR_reset_f;          /* '<S16>/Supervisor' */
  real_T resetDone;                    /* '<S16>/Supervisor' */
  real_T change_color_j;               /* '<S16>/Supervisor' */
  real_T f_phi;                        /* '<S3>/Direct Lookup Table phiFF' */
  real_T f_x;                          /* '<S3>/Direct Lookup Table xFF' */
  real_T f_y;                          /* '<S3>/Direct Lookup Table yFF' */
  boolean_T DIblacksofwarefunctionbutton;/* '<S5>/Logical Operator' */
  boolean_T Compare;                   /* '<S34>/Compare' */
  boolean_T DataTypeConversion;        /* '<S32>/Data Type Conversion' */
  boolean_T Compare_p;                 /* '<S36>/Compare' */
  boolean_T Compare_l;                 /* '<S37>/Compare' */
  boolean_T DataTypeConversion1_n;     /* '<S33>/Data Type Conversion1' */
  boolean_T Compare_h;                 /* '<S39>/Compare' */
  boolean_T Delay_c;                   /* '<S11>/Delay' */
  boolean_T LogicalOperator;           /* '<S11>/Logical Operator' */
  boolean_T Compare_h2;                /* '<S43>/Compare' */
  boolean_T Compare_b;                 /* '<S17>/Compare' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_Arizona_base_GOAT_T {
  real_T log_penholder_active_DSTATE;  /* '<Root>/log_penholder_active' */
  real_T Delay2_DSTATE;                /* '<Root>/Delay2' */
  real_T Delay1_DSTATE;                /* '<S21>/Delay1' */
  real_T Delay_DSTATE;                 /* '<S21>/Delay' */
  real_T Delay1_DSTATE_g;              /* '<Root>/Delay1' */
  real_T UD_DSTATE;                    /* '<S41>/UD' */
  real_T Delay1_DSTATE_i;              /* '<S20>/Delay1' */
  real_T Delay_DSTATE_j;               /* '<S20>/Delay' */
  real_T UD_DSTATE_a;                  /* '<S40>/UD' */
  real_T Delay1_DSTATE_o;              /* '<S19>/Delay1' */
  real_T Delay_DSTATE_h;               /* '<S19>/Delay' */
  real_T Internal_DSTATE[2];           /* '<S7>/Internal' */
  real_T Internal_DSTATE_l[3];         /* '<S8>/Internal' */
  real_T Internal_DSTATE_h[2];         /* '<S6>/Internal' */
  real_T Delay_DSTATE_m;               /* '<S15>/Delay' */
  real_T DiscreteTimeIntegratorx2JogSpee;
                              /* '<S16>/Discrete-Time Integrator x2JogSpeed1' */
  real_T DiscreteTimeIntegratorx2JogSp_a;
                               /* '<S16>/Discrete-Time Integrator x2JogSpeed' */
  real_T DiscreteTimeIntegratorx1JogSpee;
                               /* '<S16>/Discrete-Time Integrator x1JogSpeed' */
  real_T timeIndex;               /* '<Root>/Trial control without penholder' */
  real_T Memory_PreviousInput;         /* '<S44>/Memory' */
  real_T counter;                      /* '<S9>/Change color Chart' */
  real_T job;                          /* '<S9>/Change color Chart' */
  real_T rot_change;                   /* '<S9>/Change color Chart' */
  real_T color_pos;                    /* '<S9>/Change color Chart' */
  real_T Ts_l;                         /* '<S16>/Supervisor' */
  real_T Carriageencoder_RWORK;        /* '<S5>/Carriage encoder' */
  real_T Gantryx1GantryxR_RWORK;       /* '<S5>/Gantry x1 = Gantry xR' */
  real_T Gantryx2GantryxL_RWORK;       /* '<S5>/Gantry x2 = Gantry xL' */
  real_T Dct2lowpassoutput_y_RWORK[4]; /* '<S10>/Dct2lowpass output_y' */
  real_T Dct2lowpassoutput_x_RWORK[4]; /* '<S10>/Dct2lowpass output_x' */
  real_T Dct2lowpasscurrent_gantryAirbag[4];
                                  /* '<S10>/Dct2lowpass current_gantryAirbag' */
  real_T Dct2lowpasscurrent_carriageAirb[4];
                                /* '<S10>/Dct2lowpass current_carriageAirbag' */
  real_T Cariagesecundair_RWORK;       /* '<S5>/Cariage secundair' */
  real_T GantryX1secundair_RWORK;      /* '<S5>/Gantry X1 secundair' */
  real_T GentryX2secundair_RWORK;      /* '<S5>/Gentry X2 secundair' */
  real_T Dct2lowpassx1JogSpeed_RWORK[4];/* '<S16>/Dct2lowpass x1JogSpeed' */
  real_T Dct2lowpassx2JogSpeed_RWORK[4];/* '<S16>/Dct2lowpass x2JogSpeed' */
  real_T Dct2lowpassyJogSpeed_RWORK[4];/* '<S16>/Dct2lowpass yJogSpeed' */
  void *Analoginput1_PWORK[4];         /* '<S5>/Analog input 1' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Analo;   /* synthesized block */

  void *DILimitCarriage_PWORK[2];      /* '<S5>/DI Limit Carriage ' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DILim;   /* synthesized block */

  void *DILimitGantryx1GantryxR_PWORK[2];
                                     /* '<S5>/DI Limit Gantry x1 = Gantry xR' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIL_l;   /* synthesized block */

  void *DILimitGantryx2GantryxL_PWORK[2];
                                     /* '<S5>/DI Limit Gantry x2 = Gantry xL' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIL_j;   /* synthesized block */

  void *DIblacksoftwarebutton_PWORK[2];/* '<S5>/DI black software button' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIbla;   /* synthesized block */

  void *DIcarriageampfaultstatus_PWORK[2];
                                      /* '<S5>/DI carriage amp. fault status' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIcar;   /* synthesized block */

  void *DIgantryx1faultstatus_PWORK[2];/* '<S5>/DI gantry x1 fault status' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIgan;   /* synthesized block */

  void *DIgantryx2faultstatus_PWORK[2];/* '<S5>/DI gantry x2 fault status' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIg_f;   /* synthesized block */

  void *DIredsoftwarebutton_PWORK[2];  /* '<S5>/DI red software button' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIred;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gain1;   /* synthesized block */

  void *Carriageencoder_PWORK[5];      /* '<S5>/Carriage encoder' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gain5;   /* synthesized block */

  void *Gantryx1GantryxR_PWORK[5];     /* '<S5>/Gantry x1 = Gantry xR' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gain6;   /* synthesized block */

  void *Gantryx2GantryxL_PWORK[5];     /* '<S5>/Gantry x2 = Gantry xL' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gain7;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gain_;   /* synthesized block */

  void *Analogoutput2_PWORK[5];        /* '<S5>/Analog output 2' */
  void *DOInhibitCarriage_PWORK[2];    /* '<S5>/DO Inhibit Carriage' */
  void *DOInhibitGantryx1GantryxR_PWORK[2];
                                   /* '<S5>/DO Inhibit Gantry x1 = Gantry xR' */
  void *DOInhibitGantryx2DOGantryxL_PWO[2];
                                /* '<S5>/DO Inhibit Gantry x2 = DO Gantry xL' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_BusSe;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Bus_i;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Bus_h;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gainc;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gaing;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gai_e;   /* synthesized block */

  void *Cariagesecundair_PWORK[5];     /* '<S5>/Cariage secundair' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gain8;   /* synthesized block */

  void *GantryX1secundair_PWORK[5];    /* '<S5>/Gantry X1 secundair' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gain9;   /* synthesized block */

  void *GentryX2secundair_PWORK[5];    /* '<S5>/Gentry X2 secundair' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gai_j;   /* synthesized block */

  void *DILimitCarriagesecundairwerktni[2];
                           /* '<S5>/DI Limit Carriage secundair (werkt niet)' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIL_b;   /* synthesized block */

  void *DILimitGantryx1secundairGantryx[2];
  /* '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DI_b3;   /* synthesized block */

  void *DILimitGantryx2secundairGantryx[2];
  /* '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIL_h;   /* synthesized block */

  struct {
    void *USERIO_P_IND;
    void *PROG_SPACE_P_IND;
    void *CONFIG_REGISTER_P_IND;
    void *CONDITIONING_MODULE_IO3xx_2x_P_IND;
    void *DEVICENAME_P_IND;
  } Setup_PWORK;                       /* '<S5>/Setup' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Coupl;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Cou_n;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Cou_j;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Decou;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Dec_g;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Dec_b;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Delay;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Feedf;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Fee_g;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Fee_b;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ga_j5;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gai_a;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gai_b;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Homin;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Hom_k;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Hom_l;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Hom_n;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sumcu;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sum_j;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sum_b;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Traje;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Trial;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_refer;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_ref_b;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_ref_h;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_start;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sum_a;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Switc;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Swi_h;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sw_h0;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_log_j;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sumph;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_SumxN;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_SumyN;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Super;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sup_g;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Su_gv;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sup_e;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Swi_i;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Swi_d;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sw_hi;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DataT;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Direc;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Initi;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ini_h;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ini_o;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Reset;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Res_m;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Res_a;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Res_c;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Dat_n;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Dct2l;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Dct_h;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Dct_n;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Discr;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gainx;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gai_f;   /* synthesized block */

  int32_T sfEvent;                /* '<Root>/Trial control without penholder' */
  int32_T sfEvent_i;                   /* '<S10>/Supervisor' */
  int32_T sfEvent_l;                   /* '<S9>/Change color Chart' */
  int32_T sfEvent_h;                   /* '<S16>/Supervisor' */
  int32_T durationCounter_1;           /* '<S16>/Supervisor' */
  int32_T durationCounter_1_n;         /* '<S16>/Supervisor' */
  int32_T durationCounter_1_d;         /* '<S16>/Supervisor' */
  uint32_T is_c5_Arizona_base_GOAT;
                                  /* '<Root>/Trial control without penholder' */
  uint32_T is_c3_Arizona_base_GOAT;    /* '<S10>/Supervisor' */
  uint32_T is_gantryAirbag;            /* '<S10>/Supervisor' */
  uint32_T is_errorAirbag;             /* '<S10>/Supervisor' */
  uint32_T is_carriageAirbag;          /* '<S10>/Supervisor' */
  uint32_T is_c4_Arizona_base_GOAT;    /* '<S9>/Change color Chart' */
  uint32_T is_MAIN;                    /* '<S9>/Change color Chart' */
  uint32_T is_VERTICAL;                /* '<S9>/Change color Chart' */
  uint32_T is_ROTATION;                /* '<S9>/Change color Chart' */
  uint32_T is_HOME;                    /* '<S9>/Change color Chart' */
  uint32_T is_c7_Arizona_base_GOAT;    /* '<S16>/Supervisor' */
  uint32_T is_reset_gantryLeft;        /* '<S16>/Supervisor' */
  uint32_T is_reset_gantryright;       /* '<S16>/Supervisor' */
  uint32_T is_reset_carriage;          /* '<S16>/Supervisor' */
  struct {
    int_T MODULEARCHITECTURE_I_IND;
  } Setup_IWORK;                       /* '<S5>/Setup' */

  uint16_T temporalCounter_i2;         /* '<S9>/Change color Chart' */
  uint16_T temporalCounter_i1;         /* '<S16>/Supervisor' */
  boolean_T Delay_DSTATE_k;            /* '<S11>/Delay' */
  int8_T Trajectory_SubsysRanBC;       /* '<Root>/Trajectory' */
  int8_T Enabledsubsystem_SubsysRanBC; /* '<S4>/Enabled subsystem' */
  int8_T Feedforward_SubsysRanBC;      /* '<Root>/Feedforward' */
  uint8_T is_active_c5_Arizona_base_GOAT;
                                  /* '<Root>/Trial control without penholder' */
  uint8_T is_active_c3_Arizona_base_GOAT;/* '<S10>/Supervisor' */
  uint8_T is_active_gantryAirbag;      /* '<S10>/Supervisor' */
  uint8_T is_active_errorAirbag;       /* '<S10>/Supervisor' */
  uint8_T is_active_carriageAirbag;    /* '<S10>/Supervisor' */
  uint8_T is_active_c4_Arizona_base_GOAT;/* '<S9>/Change color Chart' */
  uint8_T is_active_MAIN;              /* '<S9>/Change color Chart' */
  uint8_T is_active_VERTICAL;          /* '<S9>/Change color Chart' */
  uint8_T is_active_ROTATION;          /* '<S9>/Change color Chart' */
  uint8_T is_active_HOME;              /* '<S9>/Change color Chart' */
  uint8_T temporalCounter_i1_b;        /* '<S9>/Change color Chart' */
  uint8_T temporalCounter_i3;          /* '<S9>/Change color Chart' */
  uint8_T is_active_c7_Arizona_base_GOAT;/* '<S16>/Supervisor' */
  uint8_T is_active_reset_gantryLeft;  /* '<S16>/Supervisor' */
  uint8_T is_active_reset_gantryright; /* '<S16>/Supervisor' */
  uint8_T is_active_reset_carriage;    /* '<S16>/Supervisor' */
  boolean_T Trajectory_MODE;           /* '<Root>/Trajectory' */
  boolean_T Enabledsubsystem_MODE;     /* '<S4>/Enabled subsystem' */
};

/* Zero-crossing (trigger) state */
struct PrevZCX_Arizona_base_GOAT_T {
  ZCSigState ResettableSubsystemMemory_Reset;
                                    /* '<S11>/Resettable Subsystem // Memory' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Arizona_base_GOAT_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[1];
    SimStruct childSFunctions[30];
    SimStruct *childSFunctionPtrs[30];
    struct _ssBlkInfo2 blkInfo2[30];
    struct _ssBlkInfoSLSize blkInfoSLSize[30];
    struct _ssSFcnModelMethods2 methods2[30];
    struct _ssSFcnModelMethods3 methods3[30];
    struct _ssSFcnModelMethods4 methods4[30];
    struct _ssStatesInfo2 statesInfo2[30];
    ssPeriodicStatesInfo periodicStatesInfo[30];
    struct _ssPortInfo2 inputOutputPortInfo2[30];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortInputsSLSize inputPortInfoSLSize[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortInputsSLSize inputPortInfoSLSize[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortInputsSLSize inputPortInfoSLSize[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[37];
      mxArray *params[37];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[12];
      mxArray *params[12];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn12;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[24];
      mxArray *params[24];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn13;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[24];
      mxArray *params[24];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn14;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[24];
      mxArray *params[24];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn15;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortInputsSLSize inputPortInfoSLSize[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn16;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortInputsSLSize inputPortInfoSLSize[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn17;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortInputsSLSize inputPortInfoSLSize[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn18;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortInputsSLSize inputPortInfoSLSize[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn19;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      struct _ssPortInputsSLSize inputPortInfoSLSize[3];
      struct _ssInPortUnit inputPortUnits[3];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[3];
      uint_T attribs[14];
      mxArray *params[14];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn20;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortInputsSLSize inputPortInfoSLSize[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn21;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortInputsSLSize inputPortInfoSLSize[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn22;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortInputsSLSize inputPortInfoSLSize[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn23;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[24];
      mxArray *params[24];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn24;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[24];
      mxArray *params[24];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn25;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[24];
      mxArray *params[24];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn26;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn27;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn28;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn29;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_Arizona_base_GOAT_T Arizona_base_GOAT_B;

#ifdef __cplusplus

}
#endif

/* Block states (default storage) */
extern struct DW_Arizona_base_GOAT_T Arizona_base_GOAT_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Arizona_base_GOAT_T Arizona_base_GOAT_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void Arizona_base_GOAT_initialize(void);
  extern void Arizona_base_GOAT_step(void);
  extern void Arizona_base_GOAT_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Arizona_base_GOAT_T *const Arizona_base_GOAT_M;

#ifdef __cplusplus

}
#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Arizona_base_GOAT'
 * '<S1>'   : 'Arizona_base_GOAT/Coupling'
 * '<S2>'   : 'Arizona_base_GOAT/Decoupling'
 * '<S3>'   : 'Arizona_base_GOAT/Feedforward'
 * '<S4>'   : 'Arizona_base_GOAT/Homing'
 * '<S5>'   : 'Arizona_base_GOAT/IO Arizona'
 * '<S6>'   : 'Arizona_base_GOAT/LTI System'
 * '<S7>'   : 'Arizona_base_GOAT/LTI System1'
 * '<S8>'   : 'Arizona_base_GOAT/LTI System2'
 * '<S9>'   : 'Arizona_base_GOAT/Penholder mechanism1'
 * '<S10>'  : 'Arizona_base_GOAT/Safety'
 * '<S11>'  : 'Arizona_base_GOAT/Trajectory'
 * '<S12>'  : 'Arizona_base_GOAT/Trial control without penholder'
 * '<S13>'  : 'Arizona_base_GOAT/Homing/Enabled subsystem'
 * '<S14>'  : 'Arizona_base_GOAT/Homing/Memory block for homing during trials'
 * '<S15>'  : 'Arizona_base_GOAT/Homing/Enabled subsystem/Initialization'
 * '<S16>'  : 'Arizona_base_GOAT/Homing/Enabled subsystem/Reset'
 * '<S17>'  : 'Arizona_base_GOAT/Homing/Enabled subsystem/Initialization/Compare To Constant NInit'
 * '<S18>'  : 'Arizona_base_GOAT/Homing/Enabled subsystem/Reset/Supervisor'
 * '<S19>'  : 'Arizona_base_GOAT/Homing/Memory block for homing during trials/Memory_phi'
 * '<S20>'  : 'Arizona_base_GOAT/Homing/Memory block for homing during trials/Memory_x'
 * '<S21>'  : 'Arizona_base_GOAT/Homing/Memory block for homing during trials/Memory_y'
 * '<S22>'  : 'Arizona_base_GOAT/LTI System/IO Delay'
 * '<S23>'  : 'Arizona_base_GOAT/LTI System/Input Delay'
 * '<S24>'  : 'Arizona_base_GOAT/LTI System/Output Delay'
 * '<S25>'  : 'Arizona_base_GOAT/LTI System1/IO Delay'
 * '<S26>'  : 'Arizona_base_GOAT/LTI System1/Input Delay'
 * '<S27>'  : 'Arizona_base_GOAT/LTI System1/Output Delay'
 * '<S28>'  : 'Arizona_base_GOAT/LTI System2/IO Delay'
 * '<S29>'  : 'Arizona_base_GOAT/LTI System2/Input Delay'
 * '<S30>'  : 'Arizona_base_GOAT/LTI System2/Output Delay'
 * '<S31>'  : 'Arizona_base_GOAT/Penholder mechanism1/Change color Chart'
 * '<S32>'  : 'Arizona_base_GOAT/Penholder mechanism1/Motor Theta'
 * '<S33>'  : 'Arizona_base_GOAT/Penholder mechanism1/Motor Z'
 * '<S34>'  : 'Arizona_base_GOAT/Penholder mechanism1/Motor Theta/Compare To Zero'
 * '<S35>'  : 'Arizona_base_GOAT/Penholder mechanism1/Motor Theta/PWMcreator5'
 * '<S36>'  : 'Arizona_base_GOAT/Penholder mechanism1/Motor Theta/PWMcreator5/Compare To Constant'
 * '<S37>'  : 'Arizona_base_GOAT/Penholder mechanism1/Motor Z/Compare To Zero1'
 * '<S38>'  : 'Arizona_base_GOAT/Penholder mechanism1/Motor Z/PWMcreator1'
 * '<S39>'  : 'Arizona_base_GOAT/Penholder mechanism1/Motor Z/PWMcreator1/Compare To Constant'
 * '<S40>'  : 'Arizona_base_GOAT/Safety/Discrete Derivative output_x'
 * '<S41>'  : 'Arizona_base_GOAT/Safety/Discrete Derivative output_y'
 * '<S42>'  : 'Arizona_base_GOAT/Safety/Supervisor'
 * '<S43>'  : 'Arizona_base_GOAT/Trajectory/Compare To Constant'
 * '<S44>'  : 'Arizona_base_GOAT/Trajectory/Resettable Subsystem // Memory'
 */
#endif                                 /* RTW_HEADER_Arizona_base_GOAT_h_ */
