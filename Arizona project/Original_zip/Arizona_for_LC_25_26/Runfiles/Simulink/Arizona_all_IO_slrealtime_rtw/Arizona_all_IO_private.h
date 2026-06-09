/*
 * Arizona_all_IO_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Arizona_all_IO".
 *
 * Model version              : 1.42
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C++ source code generated on : Thu May 15 16:00:42 2025
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Arizona_all_IO_private_h_
#define RTW_HEADER_Arizona_all_IO_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Arizona_all_IO.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void* slrtRegisterSignalToLoggingService(uintptr_t sigAddr);
extern "C" void sg_IO141_IO142_setup_s(SimStruct *rts);
extern "C" void sg_IO141_IO142_ad_s(SimStruct *rts);
extern "C" void sg_IO141_IO142_da_s(SimStruct *rts);
extern "C" void sg_fpga_qad_sf_5(SimStruct *rts);
extern "C" void sg_fpga_do_sf_a2(SimStruct *rts);
extern "C" void sg_fpga_di_sf_a2(SimStruct *rts);

#endif                                /* RTW_HEADER_Arizona_all_IO_private_h_ */
