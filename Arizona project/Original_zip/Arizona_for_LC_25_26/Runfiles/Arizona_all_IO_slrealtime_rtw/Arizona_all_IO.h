/*
 * Arizona_all_IO.h
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

#ifndef RTW_HEADER_Arizona_all_IO_h_
#define RTW_HEADER_Arizona_all_IO_h_
#include <logsrv.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "sg_fpga_io30x_setup_util.h"
#include "sg_fpga_io31x_io32x_setup_util.h"
#include "sg_fpga_io33x_setup_util.h"
#include "sg_fpga_io39x_setup_util.h"
#include "sg_common.h"
#include "sg_printf.h"
#include "Arizona_all_IO_types.h"
#include <stddef.h>
#include <cstring>
#include "Arizona_all_IO_cal.h"

extern "C" {

#include "rtGetInf.h"

}
  extern "C"
{

#include "rt_nonfinite.h"

}

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
struct B_Arizona_all_IO_T {
  real_T analogvelin;                  /* '<Root>/Analog input 1' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T WhiteNoise;                   /* '<S1>/White Noise' */
  real_T Output;                       /* '<S1>/Output' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Gain3;                        /* '<Root>/Gain3' */
  real_T gantry_input_enabled_L;       /* '<Root>/Gain4' */
  real_T Cariagesecundair;             /* '<Root>/Cariage secundair' */
  real_T Carriageenable0Inhibit1Enable;
                             /* '<Root>/Carriage enable: 0=Inhibit, 1=Enable' */
  real_T Carriageencoder;              /* '<Root>/Carriage encoder' */
  real_T DILimitCarriage;              /* '<Root>/DI Limit Carriage ' */
  real_T DILimitCarriagesecundairwerktni;
                         /* '<Root>/DI Limit Carriage secundair (werkt niet)' */
  real_T DILimitGantryx1GantryxR;  /* '<Root>/DI Limit Gantry x1 = Gantry xR' */
  real_T DILimitGantryx1secundairGantryx;
  /* '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' */
  real_T DILimitGantryx2GantryxL;  /* '<Root>/DI Limit Gantry x2 = Gantry xL' */
  real_T DILimitGantryx2secundairGantryx;
  /* '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' */
  real_T DIblacksoftwarebutton;        /* '<Root>/DI black software button' */
  real_T DIcarriageampfaultstatus;  /* '<Root>/DI carriage amp. fault status' */
  real_T DIgantryx1faultstatus;        /* '<Root>/DI gantry x1 fault status' */
  real_T DIgantryx2faultstatus;        /* '<Root>/DI gantry x2 fault status' */
  real_T DIredsoftwarebutton;          /* '<Root>/DI red software button' */
  real_T Gantryx1enable0Inhibit1Enable;
                            /* '<Root>/Gantry x1 enable: 0=Inhibit, 1=Enable' */
  real_T Gantryx2enable0Inhibit1Enable;
                            /* '<Root>/Gantry x2 enable: 0=Inhibit, 1=Enable' */
  real_T Gantryx1GantryxR;             /* '<Root>/Gantry x1 = Gantry xR' */
  real_T encodergantryx_R;             /* '<Root>/Gain9' */
  real_T GantryX1secundair;            /* '<Root>/Gantry X1 secundair' */
  real_T Gantryx2GantryxL;             /* '<Root>/Gantry x2 = Gantry xL' */
  real_T GentryX2secundair;            /* '<Root>/Gentry X2 secundair' */
  boolean_T LogicalOperator;           /* '<Root>/Logical Operator' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_Arizona_all_IO_T {
  real_T NextOutput;                   /* '<S1>/White Noise' */
  real_T Cariagesecundair_RWORK;       /* '<Root>/Cariage secundair' */
  real_T Carriageencoder_RWORK;        /* '<Root>/Carriage encoder' */
  real_T Gantryx1GantryxR_RWORK;       /* '<Root>/Gantry x1 = Gantry xR' */
  real_T GantryX1secundair_RWORK;      /* '<Root>/Gantry X1 secundair' */
  real_T Gantryx2GantryxL_RWORK;       /* '<Root>/Gantry x2 = Gantry xL' */
  real_T GentryX2secundair_RWORK;      /* '<Root>/Gentry X2 secundair' */
  void *Analoginput1_PWORK[4];         /* '<Root>/Analog input 1' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Analo;   /* synthesized block */

  void *Analogoutput2_PWORK[5];        /* '<Root>/Analog output 2' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_BandL;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gain4;   /* synthesized block */

  void *Cariagesecundair_PWORK[5];     /* '<Root>/Cariage secundair' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Caria;   /* synthesized block */

  void *DOInhibitCarriage_PWORK[2];    /* '<Root>/DO Inhibit Carriage' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Carri;   /* synthesized block */

  void *Carriageencoder_PWORK[5];      /* '<Root>/Carriage encoder' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Car_i;   /* synthesized block */

  void *DILimitCarriage_PWORK[2];      /* '<Root>/DI Limit Carriage ' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DILim;   /* synthesized block */

  void *DILimitCarriagesecundairwerktni[2];
                         /* '<Root>/DI Limit Carriage secundair (werkt niet)' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIL_b;   /* synthesized block */

  void *DILimitGantryx1GantryxR_PWORK[2];
                                   /* '<Root>/DI Limit Gantry x1 = Gantry xR' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIL_l;   /* synthesized block */

  void *DILimitGantryx1secundairGantryx[2];
  /* '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DI_b3;   /* synthesized block */

  void *DILimitGantryx2GantryxL_PWORK[2];
                                   /* '<Root>/DI Limit Gantry x2 = Gantry xL' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIL_j;   /* synthesized block */

  void *DILimitGantryx2secundairGantryx[2];
  /* '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIL_h;   /* synthesized block */

  void *DIblacksoftwarebutton_PWORK[2];/* '<Root>/DI black software button' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIbla;   /* synthesized block */

  void *DIcarriageampfaultstatus_PWORK[2];
                                    /* '<Root>/DI carriage amp. fault status' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIcar;   /* synthesized block */

  void *DIgantryx1faultstatus_PWORK[2];/* '<Root>/DI gantry x1 fault status' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIgan;   /* synthesized block */

  void *DIgantryx2faultstatus_PWORK[2];/* '<Root>/DI gantry x2 fault status' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIg_f;   /* synthesized block */

  void *DIredsoftwarebutton_PWORK[2];  /* '<Root>/DI red software button' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_DIred;   /* synthesized block */

  void *DOInhibitGantryx1GantryxR_PWORK[2];
                                 /* '<Root>/DO Inhibit Gantry x1 = Gantry xR' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gantr;   /* synthesized block */

  void *DOInhibitGantryx2DOGantryxL_PWO[2];
                              /* '<Root>/DO Inhibit Gantry x2 = DO Gantry xL' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gan_o;   /* synthesized block */

  void *Gantryx1GantryxR_PWORK[5];     /* '<Root>/Gantry x1 = Gantry xR' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gain9;   /* synthesized block */

  void *GantryX1secundair_PWORK[5];    /* '<Root>/Gantry X1 secundair' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gan_g;   /* synthesized block */

  void *Gantryx2GantryxL_PWORK[5];     /* '<Root>/Gantry x2 = Gantry xL' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gan_p;   /* synthesized block */

  void *GentryX2secundair_PWORK[5];    /* '<Root>/Gentry X2 secundair' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gentr;   /* synthesized block */

  struct {
    void *USERIO_P_IND;
    void *PROG_SPACE_P_IND;
    void *CONFIG_REGISTER_P_IND;
    void *CONDITIONING_MODULE_IO3xx_2x_P_IND;
    void *DEVICENAME_P_IND;
  } Setup_PWORK;                       /* '<Root>/Setup' */

  uint32_T RandSeed;                   /* '<S1>/White Noise' */
  struct {
    int_T MODULEARCHITECTURE_I_IND;
  } Setup_IWORK;                       /* '<Root>/Setup' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Arizona_all_IO_T {
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
    SimStruct childSFunctions[23];
    SimStruct *childSFunctionPtrs[23];
    struct _ssBlkInfo2 blkInfo2[23];
    struct _ssBlkInfoSLSize blkInfoSLSize[23];
    struct _ssSFcnModelMethods2 methods2[23];
    struct _ssSFcnModelMethods3 methods3[23];
    struct _ssSFcnModelMethods4 methods4[23];
    struct _ssStatesInfo2 statesInfo2[23];
    ssPeriodicStatesInfo periodicStatesInfo[23];
    struct _ssPortInfo2 inputOutputPortInfo2[23];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[37];
      mxArray *params[37];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[12];
      mxArray *params[12];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

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
    } Sfcn2;

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
    } Sfcn3;

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
    } Sfcn4;

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
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn13;

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
    } Sfcn14;

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
    } Sfcn15;

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
    } Sfcn16;

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
    } Sfcn17;

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
    } Sfcn18;

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
    } Sfcn19;

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
    } Sfcn20;

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
    } Sfcn21;

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
    } Sfcn22;
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

  extern struct B_Arizona_all_IO_T Arizona_all_IO_B;

#ifdef __cplusplus

}
#endif

/* Block states (default storage) */
extern struct DW_Arizona_all_IO_T Arizona_all_IO_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void Arizona_all_IO_initialize(void);
  extern void Arizona_all_IO_step(void);
  extern void Arizona_all_IO_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Arizona_all_IO_T *const Arizona_all_IO_M;

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
 * '<Root>' : 'Arizona_all_IO'
 * '<S1>'   : 'Arizona_all_IO/Band-Limited White Noise for carriage'
 */
#endif                                 /* RTW_HEADER_Arizona_all_IO_h_ */
