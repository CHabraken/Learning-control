#include "Arizona_all_IO_cal.h"
#include "Arizona_all_IO.h"

/* Storage class 'PageSwitching' */
Arizona_all_IO_cal_type Arizona_all_IO_cal_impl = {
  /* Mask Parameter: BandLimitedWhiteNoiseforcarriag
   * Referenced by: '<S1>/Output'
   */
  1.0E-7,

  /* Mask Parameter: BandLimitedWhiteNoiseforcarri_p
   * Referenced by: '<S1>/White Noise'
   */
  23341.0,

  /* Computed Parameter: Setup2_P1_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/Setup 2'
   */
  141.0,

  /* Computed Parameter: Setup2_P2_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parModuleId
   * Referenced by: '<Root>/Setup 2'
   */
  1.0,

  /* Computed Parameter: Setup2_P3_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parPciSlot
   * Referenced by: '<Root>/Setup 2'
   */
  -1.0,

  /* Computed Parameter: Setup2_P4_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parInterModuleSync
   * Referenced by: '<Root>/Setup 2'
   */
  1.0,

  /* Computed Parameter: Setup2_P5_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parAdcChannels
   * Referenced by: '<Root>/Setup 2'
   */
  4.0,

  /* Computed Parameter: Setup2_P6_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 2.0 },

  /* Expression: parAdcNumActiveChannels
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 0.0 },

  /* Computed Parameter: Setup2_P7_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 16.0 },

  /* Expression: parAdcVoltageRange
   * Referenced by: '<Root>/Setup 2'
   */
  { 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
    5.0 },

  /* Computed Parameter: Setup2_P8_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 2.0 },

  /* Expression: parAdcCoupling
   * Referenced by: '<Root>/Setup 2'
   */
  { 2.0, 1.0 },

  /* Computed Parameter: Setup2_P9_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parAdcAutoCorrection
   * Referenced by: '<Root>/Setup 2'
   */
  1.0,

  /* Computed Parameter: Setup2_P10_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parAdcContSampling
   * Referenced by: '<Root>/Setup 2'
   */
  0.0,

  /* Computed Parameter: Setup2_P11_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parAdcDmaEnable
   * Referenced by: '<Root>/Setup 2'
   */
  0.0,

  /* Computed Parameter: Setup2_P12_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 4.0 },

  /* Expression: parAdcActiveDmaDevices
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /* Computed Parameter: Setup2_P13_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parAdcFrameTriggerEnable
   * Referenced by: '<Root>/Setup 2'
   */
  0.0,

  /* Computed Parameter: Setup2_P14_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parAdcDmaClock
   * Referenced by: '<Root>/Setup 2'
   */
  1.0,

  /* Computed Parameter: Setup2_P15_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parAdcFrameSize
   * Referenced by: '<Root>/Setup 2'
   */
  100.0,

  /* Computed Parameter: Setup2_P16_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 2.0 },

  /* Expression: parDacChannels
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 2.0 },

  /* Computed Parameter: Setup2_P17_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 4.0 },

  /* Expression: parDacVoltageRange
   * Referenced by: '<Root>/Setup 2'
   */
  { 5.0, 5.0, 5.0, 7.0 },

  /* Computed Parameter: Setup2_P18_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 4.0 },

  /* Expression: parDacOverRange
   * Referenced by: '<Root>/Setup 2'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: Setup2_P19_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDacAutoCorrection
   * Referenced by: '<Root>/Setup 2'
   */
  1.0,

  /* Computed Parameter: Setup2_P20_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDacSyncOut
   * Referenced by: '<Root>/Setup 2'
   */
  1.0,

  /* Computed Parameter: Setup2_P21_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDacDmaEnable
   * Referenced by: '<Root>/Setup 2'
   */
  0.0,

  /* Computed Parameter: Setup2_P22_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 4.0 },

  /* Expression: parDacActiveDmaDevices
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /* Computed Parameter: Setup2_P23_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDacFrameTriggerEnable
   * Referenced by: '<Root>/Setup 2'
   */
  0.0,

  /* Computed Parameter: Setup2_P24_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDacDmaClock
   * Referenced by: '<Root>/Setup 2'
   */
  1.0,

  /* Computed Parameter: Setup2_P25_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDacDmaLatency
   * Referenced by: '<Root>/Setup 2'
   */
  1.0,

  /* Computed Parameter: Setup2_P26_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDacFrameSize
   * Referenced by: '<Root>/Setup 2'
   */
  100.0,

  /* Computed Parameter: Setup2_P27_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parConvClock1BaseRate
   * Referenced by: '<Root>/Setup 2'
   */
  1.0,

  /* Computed Parameter: Setup2_P28_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parConvClock1Divider
   * Referenced by: '<Root>/Setup 2'
   */
  20000.0,

  /* Computed Parameter: Setup2_P29_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parConvClock2BaseRate
   * Referenced by: '<Root>/Setup 2'
   */
  1.0,

  /* Computed Parameter: Setup2_P30_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parConvClock2Divider
   * Referenced by: '<Root>/Setup 2'
   */
  20000.0,

  /* Computed Parameter: Setup2_P31_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parFrameTriggerClock
   * Referenced by: '<Root>/Setup 2'
   */
  1.0,

  /* Computed Parameter: Setup2_P32_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parFrameTriggerDivider
   * Referenced by: '<Root>/Setup 2'
   */
  10.0,

  /* Computed Parameter: Setup2_P33_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 3.0 },

  /* Expression: parDoChannels
   * Referenced by: '<Root>/Setup 2'
   */
  { 6.0, 7.0, 8.0 },

  /* Computed Parameter: Setup2_P34_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 5.0 },

  /* Expression: parDiChannels
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0 },

  /* Computed Parameter: Setup2_P35_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDiDebounceValue
   * Referenced by: '<Root>/Setup 2'
   */
  0.0,

  /* Computed Parameter: Setup2_P36_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDioPullRefFront
   * Referenced by: '<Root>/Setup 2'
   */
  3.0,

  /* Computed Parameter: Setup2_P37_Size
   * Referenced by: '<Root>/Setup 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDioPullRefRear
   * Referenced by: '<Root>/Setup 2'
   */
  1.0,

  /* Computed Parameter: Analoginput1_P1_Size
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/Analog input 1'
   */
  141.0,

  /* Computed Parameter: Analoginput1_P2_Size
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 1.0 },

  /* Expression: parModuleId
   * Referenced by: '<Root>/Analog input 1'
   */
  1.0,

  /* Computed Parameter: Analoginput1_P3_Size
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 1.0 },

  /* Expression: parPciSlot
   * Referenced by: '<Root>/Analog input 1'
   */
  -1.0,

  /* Computed Parameter: Analoginput1_P4_Size
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 1.0 },

  /* Expression: parSampleTime
   * Referenced by: '<Root>/Analog input 1'
   */
  0.001,

  /* Computed Parameter: Analoginput1_P5_Size
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 1.0 },

  /* Expression: parAdcChannels
   * Referenced by: '<Root>/Analog input 1'
   */
  4.0,

  /* Computed Parameter: Analoginput1_P6_Size
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 2.0 },

  /* Expression: parAdcNumActiveChannels
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 0.0 },

  /* Computed Parameter: Analoginput1_P7_Size
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 16.0 },

  /* Expression: parAdcVoltageRange
   * Referenced by: '<Root>/Analog input 1'
   */
  { 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
    5.0 },

  /* Computed Parameter: Analoginput1_P8_Size
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 2.0 },

  /* Expression: parAdcCoupling
   * Referenced by: '<Root>/Analog input 1'
   */
  { 2.0, 1.0 },

  /* Computed Parameter: Analoginput1_P9_Size
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 1.0 },

  /* Expression: parAdcContSampling
   * Referenced by: '<Root>/Analog input 1'
   */
  0.0,

  /* Computed Parameter: Analoginput1_P10_Size
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 1.0 },

  /* Expression: parAdcDmaEnable
   * Referenced by: '<Root>/Analog input 1'
   */
  0.0,

  /* Computed Parameter: Analoginput1_P11_Size
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 4.0 },

  /* Expression: parAdcActiveDmaDevices
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /* Computed Parameter: Analoginput1_P12_Size
   * Referenced by: '<Root>/Analog input 1'
   */
  { 1.0, 1.0 },

  /* Expression: parAdcFrameSize
   * Referenced by: '<Root>/Analog input 1'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<Root>/Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/White Noise'
   */
  0.0,

  /* Computed Parameter: WhiteNoise_StdDev
   * Referenced by: '<S1>/White Noise'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Gain1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Gain2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Gain3'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain4'
   */
  -1.0,

  /* Computed Parameter: Analogoutput2_P1_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/Analog output 2'
   */
  141.0,

  /* Computed Parameter: Analogoutput2_P2_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 1.0 },

  /* Expression: parModuleId
   * Referenced by: '<Root>/Analog output 2'
   */
  1.0,

  /* Computed Parameter: Analogoutput2_P3_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 1.0 },

  /* Expression: parPciSlot
   * Referenced by: '<Root>/Analog output 2'
   */
  -1.0,

  /* Computed Parameter: Analogoutput2_P4_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 1.0 },

  /* Expression: parSampleTime
   * Referenced by: '<Root>/Analog output 2'
   */
  0.001,

  /* Computed Parameter: Analogoutput2_P5_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 3.0 },

  /* Expression: parDacChannels
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 2.0, 3.0 },

  /* Computed Parameter: Analogoutput2_P6_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 4.0 },

  /* Expression: parDacVoltageRange
   * Referenced by: '<Root>/Analog output 2'
   */
  { 5.0, 5.0, 5.0, 7.0 },

  /* Computed Parameter: Analogoutput2_P7_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 4.0 },

  /* Expression: parDacOverRange
   * Referenced by: '<Root>/Analog output 2'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: Analogoutput2_P8_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 3.0 },

  /* Expression: parDacInitValues
   * Referenced by: '<Root>/Analog output 2'
   */
  { 0.0, 0.0, 0.0 },

  /* Computed Parameter: Analogoutput2_P9_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 3.0 },

  /* Expression: parDacReset
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 1.0, 1.0 },

  /* Computed Parameter: Analogoutput2_P10_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDacSyncOut
   * Referenced by: '<Root>/Analog output 2'
   */
  1.0,

  /* Computed Parameter: Analogoutput2_P11_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDacDmaEnable
   * Referenced by: '<Root>/Analog output 2'
   */
  0.0,

  /* Computed Parameter: Analogoutput2_P12_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 4.0 },

  /* Expression: parDacActiveDmaDevices
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /* Computed Parameter: Analogoutput2_P13_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDacDmaLatency
   * Referenced by: '<Root>/Analog output 2'
   */
  1.0,

  /* Computed Parameter: Analogoutput2_P14_Size
   * Referenced by: '<Root>/Analog output 2'
   */
  { 1.0, 1.0 },

  /* Expression: parDacFrameSize
   * Referenced by: '<Root>/Analog output 2'
   */
  100.0,

  /* Computed Parameter: Cariagesecundair_P1_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/Cariage secundair'
   */
  30725.0,

  /* Computed Parameter: Cariagesecundair_P2_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: fpgaFrequency
   * Referenced by: '<Root>/Cariage secundair'
   */
  7.3728E+7,

  /* Computed Parameter: Cariagesecundair_P3_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/Cariage secundair'
   */
  1.0,

  /* Computed Parameter: Cariagesecundair_P4_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/Cariage secundair'
   */
  4.0,

  /* Computed Parameter: Cariagesecundair_P5_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<Root>/Cariage secundair'
   */
  0.001,

  /* Computed Parameter: Cariagesecundair_P6_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/Cariage secundair'
   */
  -1.0,

  /* Computed Parameter: Cariagesecundair_P7_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: numOfSlots
   * Referenced by: '<Root>/Cariage secundair'
   */
  1.0,

  /* Computed Parameter: Cariagesecundair_P8_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: sensorType
   * Referenced by: '<Root>/Cariage secundair'
   */
  1.0,

  /* Computed Parameter: Cariagesecundair_P9_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: interpolatePosition
   * Referenced by: '<Root>/Cariage secundair'
   */
  0.0,

  /* Computed Parameter: Cariagesecundair_P10_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: swapAB
   * Referenced by: '<Root>/Cariage secundair'
   */
  0.0,

  /* Computed Parameter: Cariagesecundair_P11_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: indexControlMode
   * Referenced by: '<Root>/Cariage secundair'
   */
  1.0,

  /* Computed Parameter: Cariagesecundair_P12_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: latchMode
   * Referenced by: '<Root>/Cariage secundair'
   */
  1.0,

  /* Computed Parameter: Cariagesecundair_P13_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: gateIndex
   * Referenced by: '<Root>/Cariage secundair'
   */
  1.0,

  /* Computed Parameter: Cariagesecundair_P14_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: speedFilterWidth
   * Referenced by: '<Root>/Cariage secundair'
   */
  4.0,

  /* Computed Parameter: Cariagesecundair_P15_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showInputSpeedFilterWidth
   * Referenced by: '<Root>/Cariage secundair'
   */
  0.0,

  /* Computed Parameter: Cariagesecundair_P16_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: glitchFilterSeconds
   * Referenced by: '<Root>/Cariage secundair'
   */
  1.067E-7,

  /* Computed Parameter: Cariagesecundair_P17_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showInputClearPosition
   * Referenced by: '<Root>/Cariage secundair'
   */
  0.0,

  /* Computed Parameter: Cariagesecundair_P18_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showInputClearIndexFound
   * Referenced by: '<Root>/Cariage secundair'
   */
  0.0,

  /* Computed Parameter: Cariagesecundair_P19_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputPosition
   * Referenced by: '<Root>/Cariage secundair'
   */
  0.0,

  /* Computed Parameter: Cariagesecundair_P20_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputTurn
   * Referenced by: '<Root>/Cariage secundair'
   */
  1.0,

  /* Computed Parameter: Cariagesecundair_P21_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputSpeed
   * Referenced by: '<Root>/Cariage secundair'
   */
  0.0,

  /* Computed Parameter: Cariagesecundair_P22_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputIndexFound
   * Referenced by: '<Root>/Cariage secundair'
   */
  0.0,

  /* Computed Parameter: Cariagesecundair_P23_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputLastPulse
   * Referenced by: '<Root>/Cariage secundair'
   */
  0.0,

  /* Computed Parameter: Cariagesecundair_P24_Size
   * Referenced by: '<Root>/Cariage secundair'
   */
  { 1.0, 1.0 },

  /* Expression: isDmaEnabled
   * Referenced by: '<Root>/Cariage secundair'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Carriage enable: 0=Inhibit, 1=Enable'
   */
  0.0,

  /* Computed Parameter: DOInhibitCarriage_P1_Size
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  30725.0,

  /* Computed Parameter: DOInhibitCarriage_P2_Size
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  1.0,

  /* Computed Parameter: DOInhibitCarriage_P3_Size
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  30.0,

  /* Computed Parameter: DOInhibitCarriage_P4_Size
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeInput
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  0.0,

  /* Computed Parameter: DOInhibitCarriage_P5_Size
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  { 1.0, 1.0 },

  /* Expression: reset
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  0.0,

  /* Computed Parameter: DOInhibitCarriage_P6_Size
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  { 1.0, 1.0 },

  /* Expression: init
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  0.0,

  /* Computed Parameter: DOInhibitCarriage_P7_Size
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  0.001,

  /* Computed Parameter: DOInhibitCarriage_P8_Size
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DO Inhibit Carriage'
   */
  -1.0,

  /* Computed Parameter: Carriageencoder_P1_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/Carriage encoder'
   */
  30725.0,

  /* Computed Parameter: Carriageencoder_P2_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: fpgaFrequency
   * Referenced by: '<Root>/Carriage encoder'
   */
  7.3728E+7,

  /* Computed Parameter: Carriageencoder_P3_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/Carriage encoder'
   */
  1.0,

  /* Computed Parameter: Carriageencoder_P4_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/Carriage encoder'
   */
  1.0,

  /* Computed Parameter: Carriageencoder_P5_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<Root>/Carriage encoder'
   */
  0.001,

  /* Computed Parameter: Carriageencoder_P6_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/Carriage encoder'
   */
  -1.0,

  /* Computed Parameter: Carriageencoder_P7_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: numOfSlots
   * Referenced by: '<Root>/Carriage encoder'
   */
  1.0,

  /* Computed Parameter: Carriageencoder_P8_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: sensorType
   * Referenced by: '<Root>/Carriage encoder'
   */
  1.0,

  /* Computed Parameter: Carriageencoder_P9_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: interpolatePosition
   * Referenced by: '<Root>/Carriage encoder'
   */
  0.0,

  /* Computed Parameter: Carriageencoder_P10_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: swapAB
   * Referenced by: '<Root>/Carriage encoder'
   */
  0.0,

  /* Computed Parameter: Carriageencoder_P11_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: indexControlMode
   * Referenced by: '<Root>/Carriage encoder'
   */
  1.0,

  /* Computed Parameter: Carriageencoder_P12_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: latchMode
   * Referenced by: '<Root>/Carriage encoder'
   */
  1.0,

  /* Computed Parameter: Carriageencoder_P13_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: gateIndex
   * Referenced by: '<Root>/Carriage encoder'
   */
  1.0,

  /* Computed Parameter: Carriageencoder_P14_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: speedFilterWidth
   * Referenced by: '<Root>/Carriage encoder'
   */
  4.0,

  /* Computed Parameter: Carriageencoder_P15_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: showInputSpeedFilterWidth
   * Referenced by: '<Root>/Carriage encoder'
   */
  0.0,

  /* Computed Parameter: Carriageencoder_P16_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: glitchFilterSeconds
   * Referenced by: '<Root>/Carriage encoder'
   */
  1.067E-7,

  /* Computed Parameter: Carriageencoder_P17_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: showInputClearPosition
   * Referenced by: '<Root>/Carriage encoder'
   */
  0.0,

  /* Computed Parameter: Carriageencoder_P18_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: showInputClearIndexFound
   * Referenced by: '<Root>/Carriage encoder'
   */
  0.0,

  /* Computed Parameter: Carriageencoder_P19_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputPosition
   * Referenced by: '<Root>/Carriage encoder'
   */
  0.0,

  /* Computed Parameter: Carriageencoder_P20_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputTurn
   * Referenced by: '<Root>/Carriage encoder'
   */
  1.0,

  /* Computed Parameter: Carriageencoder_P21_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputSpeed
   * Referenced by: '<Root>/Carriage encoder'
   */
  0.0,

  /* Computed Parameter: Carriageencoder_P22_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputIndexFound
   * Referenced by: '<Root>/Carriage encoder'
   */
  0.0,

  /* Computed Parameter: Carriageencoder_P23_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputLastPulse
   * Referenced by: '<Root>/Carriage encoder'
   */
  0.0,

  /* Computed Parameter: Carriageencoder_P24_Size
   * Referenced by: '<Root>/Carriage encoder'
   */
  { 1.0, 1.0 },

  /* Expression: isDmaEnabled
   * Referenced by: '<Root>/Carriage encoder'
   */
  0.0,

  /* Computed Parameter: DILimitCarriage_P1_Size
   * Referenced by: '<Root>/DI Limit Carriage '
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DI Limit Carriage '
   */
  30725.0,

  /* Computed Parameter: DILimitCarriage_P2_Size
   * Referenced by: '<Root>/DI Limit Carriage '
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DI Limit Carriage '
   */
  1.0,

  /* Computed Parameter: DILimitCarriage_P3_Size
   * Referenced by: '<Root>/DI Limit Carriage '
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DI Limit Carriage '
   */
  41.0,

  /* Computed Parameter: DILimitCarriage_P4_Size
   * Referenced by: '<Root>/DI Limit Carriage '
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeOutput
   * Referenced by: '<Root>/DI Limit Carriage '
   */
  0.0,

  /* Computed Parameter: DILimitCarriage_P5_Size
   * Referenced by: '<Root>/DI Limit Carriage '
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DI Limit Carriage '
   */
  0.001,

  /* Computed Parameter: DILimitCarriage_P6_Size
   * Referenced by: '<Root>/DI Limit Carriage '
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DI Limit Carriage '
   */
  -1.0,

  /* Computed Parameter: DILimitCarriagesecundairwerktni
   * Referenced by: '<Root>/DI Limit Carriage secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DI Limit Carriage secundair (werkt niet)'
   */
  30725.0,

  /* Computed Parameter: DILimitCarriagesecundairwerkt_l
   * Referenced by: '<Root>/DI Limit Carriage secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DI Limit Carriage secundair (werkt niet)'
   */
  1.0,

  /* Computed Parameter: DILimitCarriagesecundairwerkt_m
   * Referenced by: '<Root>/DI Limit Carriage secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DI Limit Carriage secundair (werkt niet)'
   */
  44.0,

  /* Computed Parameter: DILimitCarriagesecundairwerk_cc
   * Referenced by: '<Root>/DI Limit Carriage secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeOutput
   * Referenced by: '<Root>/DI Limit Carriage secundair (werkt niet)'
   */
  0.0,

  /* Computed Parameter: DILimitCarriagesecundairwerkt_e
   * Referenced by: '<Root>/DI Limit Carriage secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DI Limit Carriage secundair (werkt niet)'
   */
  0.001,

  /* Computed Parameter: DILimitCarriagesecundairwerk_kc
   * Referenced by: '<Root>/DI Limit Carriage secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DI Limit Carriage secundair (werkt niet)'
   */
  -1.0,

  /* Computed Parameter: DILimitGantryx1GantryxR_P1_Size
   * Referenced by: '<Root>/DI Limit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DI Limit Gantry x1 = Gantry xR'
   */
  30725.0,

  /* Computed Parameter: DILimitGantryx1GantryxR_P2_Size
   * Referenced by: '<Root>/DI Limit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DI Limit Gantry x1 = Gantry xR'
   */
  1.0,

  /* Computed Parameter: DILimitGantryx1GantryxR_P3_Size
   * Referenced by: '<Root>/DI Limit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DI Limit Gantry x1 = Gantry xR'
   */
  42.0,

  /* Computed Parameter: DILimitGantryx1GantryxR_P4_Size
   * Referenced by: '<Root>/DI Limit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeOutput
   * Referenced by: '<Root>/DI Limit Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: DILimitGantryx1GantryxR_P5_Size
   * Referenced by: '<Root>/DI Limit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DI Limit Gantry x1 = Gantry xR'
   */
  0.001,

  /* Computed Parameter: DILimitGantryx1GantryxR_P6_Size
   * Referenced by: '<Root>/DI Limit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DI Limit Gantry x1 = Gantry xR'
   */
  -1.0,

  /* Computed Parameter: DILimitGantryx1secundairGantryx
   * Referenced by: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
   */
  30725.0,

  /* Computed Parameter: DILimitGantryx1secundairGantr_l
   * Referenced by: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
   */
  1.0,

  /* Computed Parameter: DILimitGantryx1secundairGant_hm
   * Referenced by: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
   */
  45.0,

  /* Computed Parameter: DILimitGantryx1secundairGant_oo
   * Referenced by: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeOutput
   * Referenced by: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
   */
  0.0,

  /* Computed Parameter: DILimitGantryx1secundairGantr_n
   * Referenced by: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
   */
  0.001,

  /* Computed Parameter: DILimitGantryx1secundairGantr_i
   * Referenced by: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
   */
  -1.0,

  /* Computed Parameter: DILimitGantryx2GantryxL_P1_Size
   * Referenced by: '<Root>/DI Limit Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DI Limit Gantry x2 = Gantry xL'
   */
  30725.0,

  /* Computed Parameter: DILimitGantryx2GantryxL_P2_Size
   * Referenced by: '<Root>/DI Limit Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DI Limit Gantry x2 = Gantry xL'
   */
  1.0,

  /* Computed Parameter: DILimitGantryx2GantryxL_P3_Size
   * Referenced by: '<Root>/DI Limit Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DI Limit Gantry x2 = Gantry xL'
   */
  43.0,

  /* Computed Parameter: DILimitGantryx2GantryxL_P4_Size
   * Referenced by: '<Root>/DI Limit Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeOutput
   * Referenced by: '<Root>/DI Limit Gantry x2 = Gantry xL'
   */
  0.0,

  /* Computed Parameter: DILimitGantryx2GantryxL_P5_Size
   * Referenced by: '<Root>/DI Limit Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DI Limit Gantry x2 = Gantry xL'
   */
  0.001,

  /* Computed Parameter: DILimitGantryx2GantryxL_P6_Size
   * Referenced by: '<Root>/DI Limit Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DI Limit Gantry x2 = Gantry xL'
   */
  -1.0,

  /* Computed Parameter: DILimitGantryx2secundairGantryx
   * Referenced by: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
   */
  30725.0,

  /* Computed Parameter: DILimitGantryx2secundairGantr_j
   * Referenced by: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
   */
  1.0,

  /* Computed Parameter: DILimitGantryx2secundairGant_kr
   * Referenced by: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
   */
  46.0,

  /* Computed Parameter: DILimitGantryx2secundairGant_k3
   * Referenced by: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeOutput
   * Referenced by: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
   */
  0.0,

  /* Computed Parameter: DILimitGantryx2secundairGant_n0
   * Referenced by: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
   */
  0.001,

  /* Computed Parameter: DILimitGantryx2secundairGantr_d
   * Referenced by: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
   */
  -1.0,

  /* Computed Parameter: DIblacksoftwarebutton_P1_Size
   * Referenced by: '<Root>/DI black software button'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DI black software button'
   */
  30725.0,

  /* Computed Parameter: DIblacksoftwarebutton_P2_Size
   * Referenced by: '<Root>/DI black software button'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DI black software button'
   */
  1.0,

  /* Computed Parameter: DIblacksoftwarebutton_P3_Size
   * Referenced by: '<Root>/DI black software button'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DI black software button'
   */
  37.0,

  /* Computed Parameter: DIblacksoftwarebutton_P4_Size
   * Referenced by: '<Root>/DI black software button'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeOutput
   * Referenced by: '<Root>/DI black software button'
   */
  0.0,

  /* Computed Parameter: DIblacksoftwarebutton_P5_Size
   * Referenced by: '<Root>/DI black software button'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DI black software button'
   */
  0.001,

  /* Computed Parameter: DIblacksoftwarebutton_P6_Size
   * Referenced by: '<Root>/DI black software button'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DI black software button'
   */
  -1.0,

  /* Computed Parameter: DIcarriageampfaultstatus_P1_Siz
   * Referenced by: '<Root>/DI carriage amp. fault status'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DI carriage amp. fault status'
   */
  30725.0,

  /* Computed Parameter: DIcarriageampfaultstatus_P2_Siz
   * Referenced by: '<Root>/DI carriage amp. fault status'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DI carriage amp. fault status'
   */
  1.0,

  /* Computed Parameter: DIcarriageampfaultstatus_P3_Siz
   * Referenced by: '<Root>/DI carriage amp. fault status'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DI carriage amp. fault status'
   */
  33.0,

  /* Computed Parameter: DIcarriageampfaultstatus_P4_Siz
   * Referenced by: '<Root>/DI carriage amp. fault status'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeOutput
   * Referenced by: '<Root>/DI carriage amp. fault status'
   */
  0.0,

  /* Computed Parameter: DIcarriageampfaultstatus_P5_Siz
   * Referenced by: '<Root>/DI carriage amp. fault status'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DI carriage amp. fault status'
   */
  0.001,

  /* Computed Parameter: DIcarriageampfaultstatus_P6_Siz
   * Referenced by: '<Root>/DI carriage amp. fault status'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DI carriage amp. fault status'
   */
  -1.0,

  /* Computed Parameter: DIgantryx1faultstatus_P1_Size
   * Referenced by: '<Root>/DI gantry x1 fault status'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DI gantry x1 fault status'
   */
  30725.0,

  /* Computed Parameter: DIgantryx1faultstatus_P2_Size
   * Referenced by: '<Root>/DI gantry x1 fault status'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DI gantry x1 fault status'
   */
  1.0,

  /* Computed Parameter: DIgantryx1faultstatus_P3_Size
   * Referenced by: '<Root>/DI gantry x1 fault status'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DI gantry x1 fault status'
   */
  34.0,

  /* Computed Parameter: DIgantryx1faultstatus_P4_Size
   * Referenced by: '<Root>/DI gantry x1 fault status'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeOutput
   * Referenced by: '<Root>/DI gantry x1 fault status'
   */
  0.0,

  /* Computed Parameter: DIgantryx1faultstatus_P5_Size
   * Referenced by: '<Root>/DI gantry x1 fault status'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DI gantry x1 fault status'
   */
  0.001,

  /* Computed Parameter: DIgantryx1faultstatus_P6_Size
   * Referenced by: '<Root>/DI gantry x1 fault status'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DI gantry x1 fault status'
   */
  -1.0,

  /* Computed Parameter: DIgantryx2faultstatus_P1_Size
   * Referenced by: '<Root>/DI gantry x2 fault status'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DI gantry x2 fault status'
   */
  30725.0,

  /* Computed Parameter: DIgantryx2faultstatus_P2_Size
   * Referenced by: '<Root>/DI gantry x2 fault status'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DI gantry x2 fault status'
   */
  1.0,

  /* Computed Parameter: DIgantryx2faultstatus_P3_Size
   * Referenced by: '<Root>/DI gantry x2 fault status'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DI gantry x2 fault status'
   */
  35.0,

  /* Computed Parameter: DIgantryx2faultstatus_P4_Size
   * Referenced by: '<Root>/DI gantry x2 fault status'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeOutput
   * Referenced by: '<Root>/DI gantry x2 fault status'
   */
  0.0,

  /* Computed Parameter: DIgantryx2faultstatus_P5_Size
   * Referenced by: '<Root>/DI gantry x2 fault status'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DI gantry x2 fault status'
   */
  0.001,

  /* Computed Parameter: DIgantryx2faultstatus_P6_Size
   * Referenced by: '<Root>/DI gantry x2 fault status'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DI gantry x2 fault status'
   */
  -1.0,

  /* Computed Parameter: DIredsoftwarebutton_P1_Size
   * Referenced by: '<Root>/DI red software button'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DI red software button'
   */
  30725.0,

  /* Computed Parameter: DIredsoftwarebutton_P2_Size
   * Referenced by: '<Root>/DI red software button'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DI red software button'
   */
  1.0,

  /* Computed Parameter: DIredsoftwarebutton_P3_Size
   * Referenced by: '<Root>/DI red software button'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DI red software button'
   */
  36.0,

  /* Computed Parameter: DIredsoftwarebutton_P4_Size
   * Referenced by: '<Root>/DI red software button'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeOutput
   * Referenced by: '<Root>/DI red software button'
   */
  0.0,

  /* Computed Parameter: DIredsoftwarebutton_P5_Size
   * Referenced by: '<Root>/DI red software button'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DI red software button'
   */
  0.001,

  /* Computed Parameter: DIredsoftwarebutton_P6_Size
   * Referenced by: '<Root>/DI red software button'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DI red software button'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Gantry x1 enable: 0=Inhibit, 1=Enable'
   */
  0.0,

  /* Computed Parameter: DOInhibitGantryx1GantryxR_P1_Si
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  30725.0,

  /* Computed Parameter: DOInhibitGantryx1GantryxR_P2_Si
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  1.0,

  /* Computed Parameter: DOInhibitGantryx1GantryxR_P3_Si
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  31.0,

  /* Computed Parameter: DOInhibitGantryx1GantryxR_P4_Si
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeInput
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: DOInhibitGantryx1GantryxR_P5_Si
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: reset
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: DOInhibitGantryx1GantryxR_P6_Si
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: init
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: DOInhibitGantryx1GantryxR_P7_Si
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  0.001,

  /* Computed Parameter: DOInhibitGantryx1GantryxR_P8_Si
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DO Inhibit Gantry x1 = Gantry xR'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Gantry x2 enable: 0=Inhibit, 1=Enable'
   */
  0.0,

  /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P1_
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  30725.0,

  /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P2_
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  1.0,

  /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P3_
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  32.0,

  /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P4_
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: vectorizeInput
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  0.0,

  /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P5_
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: reset
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  0.0,

  /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P6_
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: init
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  0.0,

  /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P7_
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: ts
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  0.001,

  /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P8_
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/DO Inhibit Gantry x2 = DO Gantry xL'
   */
  -1.0,

  /* Computed Parameter: Gantryx1GantryxR_P1_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  30725.0,

  /* Computed Parameter: Gantryx1GantryxR_P2_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: fpgaFrequency
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  7.3728E+7,

  /* Computed Parameter: Gantryx1GantryxR_P3_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  1.0,

  /* Computed Parameter: Gantryx1GantryxR_P4_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  2.0,

  /* Computed Parameter: Gantryx1GantryxR_P5_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  0.001,

  /* Computed Parameter: Gantryx1GantryxR_P6_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  -1.0,

  /* Computed Parameter: Gantryx1GantryxR_P7_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: numOfSlots
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  1.0,

  /* Computed Parameter: Gantryx1GantryxR_P8_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: sensorType
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  1.0,

  /* Computed Parameter: Gantryx1GantryxR_P9_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: interpolatePosition
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: Gantryx1GantryxR_P10_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: swapAB
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: Gantryx1GantryxR_P11_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: indexControlMode
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  1.0,

  /* Computed Parameter: Gantryx1GantryxR_P12_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: latchMode
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  1.0,

  /* Computed Parameter: Gantryx1GantryxR_P13_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: gateIndex
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  1.0,

  /* Computed Parameter: Gantryx1GantryxR_P14_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: speedFilterWidth
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  4.0,

  /* Computed Parameter: Gantryx1GantryxR_P15_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: showInputSpeedFilterWidth
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: Gantryx1GantryxR_P16_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: glitchFilterSeconds
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  1.067E-7,

  /* Computed Parameter: Gantryx1GantryxR_P17_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: showInputClearPosition
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: Gantryx1GantryxR_P18_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: showInputClearIndexFound
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: Gantryx1GantryxR_P19_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputPosition
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: Gantryx1GantryxR_P20_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputTurn
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  1.0,

  /* Computed Parameter: Gantryx1GantryxR_P21_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputSpeed
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: Gantryx1GantryxR_P22_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputIndexFound
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: Gantryx1GantryxR_P23_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputLastPulse
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  0.0,

  /* Computed Parameter: Gantryx1GantryxR_P24_Size
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  { 1.0, 1.0 },

  /* Expression: isDmaEnabled
   * Referenced by: '<Root>/Gantry x1 = Gantry xR'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain9'
   */
  -1.0,

  /* Computed Parameter: GantryX1secundair_P1_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  30725.0,

  /* Computed Parameter: GantryX1secundair_P2_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: fpgaFrequency
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  7.3728E+7,

  /* Computed Parameter: GantryX1secundair_P3_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  1.0,

  /* Computed Parameter: GantryX1secundair_P4_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  5.0,

  /* Computed Parameter: GantryX1secundair_P5_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  0.001,

  /* Computed Parameter: GantryX1secundair_P6_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  -1.0,

  /* Computed Parameter: GantryX1secundair_P7_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: numOfSlots
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  1.0,

  /* Computed Parameter: GantryX1secundair_P8_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: sensorType
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  1.0,

  /* Computed Parameter: GantryX1secundair_P9_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: interpolatePosition
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  0.0,

  /* Computed Parameter: GantryX1secundair_P10_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: swapAB
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  0.0,

  /* Computed Parameter: GantryX1secundair_P11_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: indexControlMode
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  1.0,

  /* Computed Parameter: GantryX1secundair_P12_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: latchMode
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  1.0,

  /* Computed Parameter: GantryX1secundair_P13_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: gateIndex
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  1.0,

  /* Computed Parameter: GantryX1secundair_P14_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: speedFilterWidth
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  4.0,

  /* Computed Parameter: GantryX1secundair_P15_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showInputSpeedFilterWidth
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  0.0,

  /* Computed Parameter: GantryX1secundair_P16_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: glitchFilterSeconds
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  1.067E-7,

  /* Computed Parameter: GantryX1secundair_P17_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showInputClearPosition
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  0.0,

  /* Computed Parameter: GantryX1secundair_P18_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showInputClearIndexFound
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  0.0,

  /* Computed Parameter: GantryX1secundair_P19_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputPosition
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  0.0,

  /* Computed Parameter: GantryX1secundair_P20_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputTurn
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  1.0,

  /* Computed Parameter: GantryX1secundair_P21_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputSpeed
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  0.0,

  /* Computed Parameter: GantryX1secundair_P22_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputIndexFound
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  0.0,

  /* Computed Parameter: GantryX1secundair_P23_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputLastPulse
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  0.0,

  /* Computed Parameter: GantryX1secundair_P24_Size
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: isDmaEnabled
   * Referenced by: '<Root>/Gantry X1 secundair'
   */
  0.0,

  /* Computed Parameter: Gantryx2GantryxL_P1_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  30725.0,

  /* Computed Parameter: Gantryx2GantryxL_P2_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: fpgaFrequency
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  7.3728E+7,

  /* Computed Parameter: Gantryx2GantryxL_P3_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  1.0,

  /* Computed Parameter: Gantryx2GantryxL_P4_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  3.0,

  /* Computed Parameter: Gantryx2GantryxL_P5_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  0.001,

  /* Computed Parameter: Gantryx2GantryxL_P6_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  -1.0,

  /* Computed Parameter: Gantryx2GantryxL_P7_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: numOfSlots
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  1.0,

  /* Computed Parameter: Gantryx2GantryxL_P8_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: sensorType
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  1.0,

  /* Computed Parameter: Gantryx2GantryxL_P9_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: interpolatePosition
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  0.0,

  /* Computed Parameter: Gantryx2GantryxL_P10_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: swapAB
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  0.0,

  /* Computed Parameter: Gantryx2GantryxL_P11_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: indexControlMode
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  1.0,

  /* Computed Parameter: Gantryx2GantryxL_P12_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: latchMode
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  1.0,

  /* Computed Parameter: Gantryx2GantryxL_P13_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: gateIndex
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  1.0,

  /* Computed Parameter: Gantryx2GantryxL_P14_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: speedFilterWidth
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  4.0,

  /* Computed Parameter: Gantryx2GantryxL_P15_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: showInputSpeedFilterWidth
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  0.0,

  /* Computed Parameter: Gantryx2GantryxL_P16_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: glitchFilterSeconds
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  1.067E-7,

  /* Computed Parameter: Gantryx2GantryxL_P17_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: showInputClearPosition
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  0.0,

  /* Computed Parameter: Gantryx2GantryxL_P18_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: showInputClearIndexFound
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  0.0,

  /* Computed Parameter: Gantryx2GantryxL_P19_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputPosition
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  0.0,

  /* Computed Parameter: Gantryx2GantryxL_P20_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputTurn
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  1.0,

  /* Computed Parameter: Gantryx2GantryxL_P21_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputSpeed
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  0.0,

  /* Computed Parameter: Gantryx2GantryxL_P22_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputIndexFound
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  0.0,

  /* Computed Parameter: Gantryx2GantryxL_P23_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputLastPulse
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  0.0,

  /* Computed Parameter: Gantryx2GantryxL_P24_Size
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  { 1.0, 1.0 },

  /* Expression: isDmaEnabled
   * Referenced by: '<Root>/Gantry x2 = Gantry xL'
   */
  0.0,

  /* Computed Parameter: GentryX2secundair_P1_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  30725.0,

  /* Computed Parameter: GentryX2secundair_P2_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: fpgaFrequency
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  7.3728E+7,

  /* Computed Parameter: GentryX2secundair_P3_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: id
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  1.0,

  /* Computed Parameter: GentryX2secundair_P4_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: chan
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  6.0,

  /* Computed Parameter: GentryX2secundair_P5_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  0.001,

  /* Computed Parameter: GentryX2secundair_P6_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: pciSlot
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  -1.0,

  /* Computed Parameter: GentryX2secundair_P7_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: numOfSlots
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  1.0,

  /* Computed Parameter: GentryX2secundair_P8_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: sensorType
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  1.0,

  /* Computed Parameter: GentryX2secundair_P9_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: interpolatePosition
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  0.0,

  /* Computed Parameter: GentryX2secundair_P10_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: swapAB
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  0.0,

  /* Computed Parameter: GentryX2secundair_P11_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: indexControlMode
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  1.0,

  /* Computed Parameter: GentryX2secundair_P12_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: latchMode
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  1.0,

  /* Computed Parameter: GentryX2secundair_P13_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: gateIndex
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  1.0,

  /* Computed Parameter: GentryX2secundair_P14_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: speedFilterWidth
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  4.0,

  /* Computed Parameter: GentryX2secundair_P15_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showInputSpeedFilterWidth
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  0.0,

  /* Computed Parameter: GentryX2secundair_P16_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: glitchFilterSeconds
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  1.067E-7,

  /* Computed Parameter: GentryX2secundair_P17_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showInputClearPosition
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  0.0,

  /* Computed Parameter: GentryX2secundair_P18_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showInputClearIndexFound
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  0.0,

  /* Computed Parameter: GentryX2secundair_P19_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputPosition
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  0.0,

  /* Computed Parameter: GentryX2secundair_P20_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputTurn
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  1.0,

  /* Computed Parameter: GentryX2secundair_P21_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputSpeed
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  0.0,

  /* Computed Parameter: GentryX2secundair_P22_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputIndexFound
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  0.0,

  /* Computed Parameter: GentryX2secundair_P23_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: showOutputLastPulse
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  0.0,

  /* Computed Parameter: GentryX2secundair_P24_Size
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  { 1.0, 1.0 },

  /* Expression: isDmaEnabled
   * Referenced by: '<Root>/Gentry X2 secundair'
   */
  0.0
};

Arizona_all_IO_cal_type *Arizona_all_IO_cal = &Arizona_all_IO_cal_impl;
