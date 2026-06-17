#ifndef RTW_HEADER_Arizona_base_GOAT_cal_h_
#define RTW_HEADER_Arizona_base_GOAT_cal_h_
#include "rtwtypes.h"

/* Storage class 'PageSwitching', for system '<Root>' */
struct Arizona_base_GOAT_cal_type {
  real_T DiscreteDerivativeoutput_y_ICPr;
                              /* Mask Parameter: DiscreteDerivativeoutput_y_ICPr
                               * Referenced by: '<S41>/UD'
                               */
  real_T DiscreteDerivativeoutput_x_ICPr;
                              /* Mask Parameter: DiscreteDerivativeoutput_x_ICPr
                               * Referenced by: '<S40>/UD'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S36>/Constant'
                                       */
  real_T CompareToConstant_const_n; /* Mask Parameter: CompareToConstant_const_n
                                     * Referenced by: '<S39>/Constant'
                                     */
  real_T yFF_Y0;                       /* Computed Parameter: yFF_Y0
                                        * Referenced by: '<S3>/yFF'
                                        */
  real_T xFF_Y0;                       /* Computed Parameter: xFF_Y0
                                        * Referenced by: '<S3>/xFF'
                                        */
  real_T phiFF_Y0;                     /* Computed Parameter: phiFF_Y0
                                        * Referenced by: '<S3>/phiFF'
                                        */
  real_T set_phiFF_Value[5000];        /* Expression: zeros(Nref,1)
                                        * Referenced by: '<S3>/set_phiFF'
                                        */
  real_T set_xFF_Value[5000];          /* Expression: zeros(Nref,1)
                                        * Referenced by: '<S3>/set_xFF'
                                        */
  real_T set_yFF_Value[5000];          /* Expression: zeros(Nref,1)
                                        * Referenced by: '<S3>/set_yFF'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T yHome_Y0;                     /* Computed Parameter: yHome_Y0
                                        * Referenced by: '<S13>/yHome'
                                        */
  real_T xHome_Y0;                     /* Computed Parameter: xHome_Y0
                                        * Referenced by: '<S13>/xHome'
                                        */
  real_T phiHome_Y0;                   /* Computed Parameter: phiHome_Y0
                                        * Referenced by: '<S13>/phiHome'
                                        */
  real_T homingDone_Y0;                /* Expression: 0
                                        * Referenced by: '<S13>/homingDone'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S15>/Delay'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S15>/Switch'
                                        */
  real_T DiscreteTimeIntegratorx2JogSpee;
                          /* Computed Parameter: DiscreteTimeIntegratorx2JogSpee
                           * Referenced by: '<S16>/Discrete-Time Integrator x2JogSpeed1'
                           */
  real_T DiscreteTimeIntegratorx2JogSp_m;/* Expression: 0
                                          * Referenced by: '<S16>/Discrete-Time Integrator x2JogSpeed1'
                                          */
  real_T DiscreteTimeIntegratorx2JogSp_n;
                          /* Computed Parameter: DiscreteTimeIntegratorx2JogSp_n
                           * Referenced by: '<S16>/Discrete-Time Integrator x2JogSpeed'
                           */
  real_T DiscreteTimeIntegratorx2JogSp_e;/* Expression: 0
                                          * Referenced by: '<S16>/Discrete-Time Integrator x2JogSpeed'
                                          */
  real_T DiscreteTimeIntegratorx1JogSpee;
                          /* Computed Parameter: DiscreteTimeIntegratorx1JogSpee
                           * Referenced by: '<S16>/Discrete-Time Integrator x1JogSpeed'
                           */
  real_T DiscreteTimeIntegratorx1JogSp_k;/* Expression: 0
                                          * Referenced by: '<S16>/Discrete-Time Integrator x1JogSpeed'
                                          */
  real_T Gainx2_Gain;                  /* Expression: 1/2
                                        * Referenced by: '<S16>/Gain x2'
                                        */
  real_T Gainx3_Gain;                  /* Expression: 1/2.62
                                        * Referenced by: '<S16>/Gain x3'
                                        */
  real_T Dct2lowpassx1JogSpeed_P1_Size[2];
                            /* Computed Parameter: Dct2lowpassx1JogSpeed_P1_Size
                             * Referenced by: '<S16>/Dct2lowpass x1JogSpeed'
                             */
  real_T Dct2lowpassx1JogSpeed_P1;     /* Expression: f_den
                                        * Referenced by: '<S16>/Dct2lowpass x1JogSpeed'
                                        */
  real_T Dct2lowpassx1JogSpeed_P2_Size[2];
                            /* Computed Parameter: Dct2lowpassx1JogSpeed_P2_Size
                             * Referenced by: '<S16>/Dct2lowpass x1JogSpeed'
                             */
  real_T Dct2lowpassx1JogSpeed_P2;     /* Expression: b_den
                                        * Referenced by: '<S16>/Dct2lowpass x1JogSpeed'
                                        */
  real_T Dct2lowpassx1JogSpeed_P3_Size[2];
                            /* Computed Parameter: Dct2lowpassx1JogSpeed_P3_Size
                             * Referenced by: '<S16>/Dct2lowpass x1JogSpeed'
                             */
  real_T Dct2lowpassx1JogSpeed_P3;     /* Expression: 0.001
                                        * Referenced by: '<S16>/Dct2lowpass x1JogSpeed'
                                        */
  real_T Dct2lowpassx2JogSpeed_P1_Size[2];
                            /* Computed Parameter: Dct2lowpassx2JogSpeed_P1_Size
                             * Referenced by: '<S16>/Dct2lowpass x2JogSpeed'
                             */
  real_T Dct2lowpassx2JogSpeed_P1;     /* Expression: f_den
                                        * Referenced by: '<S16>/Dct2lowpass x2JogSpeed'
                                        */
  real_T Dct2lowpassx2JogSpeed_P2_Size[2];
                            /* Computed Parameter: Dct2lowpassx2JogSpeed_P2_Size
                             * Referenced by: '<S16>/Dct2lowpass x2JogSpeed'
                             */
  real_T Dct2lowpassx2JogSpeed_P2;     /* Expression: b_den
                                        * Referenced by: '<S16>/Dct2lowpass x2JogSpeed'
                                        */
  real_T Dct2lowpassx2JogSpeed_P3_Size[2];
                            /* Computed Parameter: Dct2lowpassx2JogSpeed_P3_Size
                             * Referenced by: '<S16>/Dct2lowpass x2JogSpeed'
                             */
  real_T Dct2lowpassx2JogSpeed_P3;     /* Expression: 0.001
                                        * Referenced by: '<S16>/Dct2lowpass x2JogSpeed'
                                        */
  real_T Dct2lowpassyJogSpeed_P1_Size[2];
                             /* Computed Parameter: Dct2lowpassyJogSpeed_P1_Size
                              * Referenced by: '<S16>/Dct2lowpass yJogSpeed'
                              */
  real_T Dct2lowpassyJogSpeed_P1;      /* Expression: f_den
                                        * Referenced by: '<S16>/Dct2lowpass yJogSpeed'
                                        */
  real_T Dct2lowpassyJogSpeed_P2_Size[2];
                             /* Computed Parameter: Dct2lowpassyJogSpeed_P2_Size
                              * Referenced by: '<S16>/Dct2lowpass yJogSpeed'
                              */
  real_T Dct2lowpassyJogSpeed_P2;      /* Expression: b_den
                                        * Referenced by: '<S16>/Dct2lowpass yJogSpeed'
                                        */
  real_T Dct2lowpassyJogSpeed_P3_Size[2];
                             /* Computed Parameter: Dct2lowpassyJogSpeed_P3_Size
                              * Referenced by: '<S16>/Dct2lowpass yJogSpeed'
                              */
  real_T Dct2lowpassyJogSpeed_P3;      /* Expression: 0.001
                                        * Referenced by: '<S16>/Dct2lowpass yJogSpeed'
                                        */
  real_T dutycycleblockwave1_Value;    /* Expression: 20
                                        * Referenced by: '<S35>/dutycycle blockwave1'
                                        */
  real_T dutycycleblockwave1_Value_k;  /* Expression: 20
                                        * Referenced by: '<S38>/dutycycle blockwave1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S44>/Memory'
                                        */
  real_T time_Y0;                      /* Computed Parameter: time_Y0
                                        * Referenced by: '<S11>/time'
                                        */
  real_T yRef_Y0;                      /* Computed Parameter: yRef_Y0
                                        * Referenced by: '<S11>/yRef'
                                        */
  real_T xRef_Y0;                      /* Computed Parameter: xRef_Y0
                                        * Referenced by: '<S11>/xRef'
                                        */
  real_T phiRef_Y0;                    /* Computed Parameter: phiRef_Y0
                                        * Referenced by: '<S11>/phiRef'
                                        */
  real_T change_color_Y0;              /* Computed Parameter: change_color_Y0
                                        * Referenced by: '<S11>/change_color'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T set_yRef_Value[5000];         /* Expression: zeros(Nref,1)
                                        * Referenced by: '<S11>/set_yRef'
                                        */
  real_T set_cRef_Value[5000];         /* Expression: zeros(Nref,1)
                                        * Referenced by: '<S11>/set_cRef'
                                        */
  real_T set_phiRef_Value[5000];       /* Expression: zeros(Nref,1)
                                        * Referenced by: '<S11>/set_phiRef'
                                        */
  real_T set_xRef_Value[5000];         /* Expression: zeros(Nref,1)
                                        * Referenced by: '<S11>/set_xRef'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Setup1_P1_Size[2];            /* Computed Parameter: Setup1_P1_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P1;                    /* Expression: boardType
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P2_Size[2];            /* Computed Parameter: Setup1_P2_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P2;                    /* Expression: parModuleId
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P3_Size[2];            /* Computed Parameter: Setup1_P3_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P3;                    /* Expression: parPciSlot
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P4_Size[2];            /* Computed Parameter: Setup1_P4_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P4;                    /* Expression: parInterModuleSync
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P5_Size[2];            /* Computed Parameter: Setup1_P5_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P5[2];                 /* Expression: parAdcChannels
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P6_Size[2];            /* Computed Parameter: Setup1_P6_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P6[2];                 /* Expression: parAdcNumActiveChannels
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P7_Size[2];            /* Computed Parameter: Setup1_P7_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P7[16];                /* Expression: parAdcVoltageRange
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P8_Size[2];            /* Computed Parameter: Setup1_P8_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P8[2];                 /* Expression: parAdcCoupling
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P9_Size[2];            /* Computed Parameter: Setup1_P9_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P9;                    /* Expression: parAdcAutoCorrection
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P10_Size[2];           /* Computed Parameter: Setup1_P10_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P10;                   /* Expression: parAdcContSampling
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P11_Size[2];           /* Computed Parameter: Setup1_P11_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P11;                   /* Expression: parAdcDmaEnable
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P12_Size[2];           /* Computed Parameter: Setup1_P12_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P12[4];                /* Expression: parAdcActiveDmaDevices
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P13_Size[2];           /* Computed Parameter: Setup1_P13_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P13;                   /* Expression: parAdcFrameTriggerEnable
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P14_Size[2];           /* Computed Parameter: Setup1_P14_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P14;                   /* Expression: parAdcDmaClock
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P15_Size[2];           /* Computed Parameter: Setup1_P15_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P15;                   /* Expression: parAdcFrameSize
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P16_Size[2];           /* Computed Parameter: Setup1_P16_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P16[2];                /* Expression: parDacChannels
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P17_Size[2];           /* Computed Parameter: Setup1_P17_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P17[4];                /* Expression: parDacVoltageRange
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P18_Size[2];           /* Computed Parameter: Setup1_P18_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P18[4];                /* Expression: parDacOverRange
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P19_Size[2];           /* Computed Parameter: Setup1_P19_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P19;                   /* Expression: parDacAutoCorrection
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P20_Size[2];           /* Computed Parameter: Setup1_P20_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P20;                   /* Expression: parDacSyncOut
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P21_Size[2];           /* Computed Parameter: Setup1_P21_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P21;                   /* Expression: parDacDmaEnable
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P22_Size[2];           /* Computed Parameter: Setup1_P22_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P22[4];                /* Expression: parDacActiveDmaDevices
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P23_Size[2];           /* Computed Parameter: Setup1_P23_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P23;                   /* Expression: parDacFrameTriggerEnable
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P24_Size[2];           /* Computed Parameter: Setup1_P24_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P24;                   /* Expression: parDacDmaClock
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P25_Size[2];           /* Computed Parameter: Setup1_P25_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P25;                   /* Expression: parDacDmaLatency
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P26_Size[2];           /* Computed Parameter: Setup1_P26_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P26;                   /* Expression: parDacFrameSize
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P27_Size[2];           /* Computed Parameter: Setup1_P27_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P27;                   /* Expression: parConvClock1BaseRate
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P28_Size[2];           /* Computed Parameter: Setup1_P28_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P28;                   /* Expression: parConvClock1Divider
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P29_Size[2];           /* Computed Parameter: Setup1_P29_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P29;                   /* Expression: parConvClock2BaseRate
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P30_Size[2];           /* Computed Parameter: Setup1_P30_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P30;                   /* Expression: parConvClock2Divider
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P31_Size[2];           /* Computed Parameter: Setup1_P31_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P31;                   /* Expression: parFrameTriggerClock
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P32_Size[2];           /* Computed Parameter: Setup1_P32_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P32;                   /* Expression: parFrameTriggerDivider
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P33_Size[2];           /* Computed Parameter: Setup1_P33_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P33[3];                /* Expression: parDoChannels
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P34_Size[2];           /* Computed Parameter: Setup1_P34_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P34[5];                /* Expression: parDiChannels
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P35_Size[2];           /* Computed Parameter: Setup1_P35_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P35;                   /* Expression: parDiDebounceValue
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P36_Size[2];           /* Computed Parameter: Setup1_P36_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P36;                   /* Expression: parDioPullRefFront
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P37_Size[2];           /* Computed Parameter: Setup1_P37_Size
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Setup1_P37;                   /* Expression: parDioPullRefRear
                                        * Referenced by: '<S5>/Setup 1'
                                        */
  real_T Analoginput1_P1_Size[2];    /* Computed Parameter: Analoginput1_P1_Size
                                      * Referenced by: '<S5>/Analog input 1'
                                      */
  real_T Analoginput1_P1;              /* Expression: boardType
                                        * Referenced by: '<S5>/Analog input 1'
                                        */
  real_T Analoginput1_P2_Size[2];    /* Computed Parameter: Analoginput1_P2_Size
                                      * Referenced by: '<S5>/Analog input 1'
                                      */
  real_T Analoginput1_P2;              /* Expression: parModuleId
                                        * Referenced by: '<S5>/Analog input 1'
                                        */
  real_T Analoginput1_P3_Size[2];    /* Computed Parameter: Analoginput1_P3_Size
                                      * Referenced by: '<S5>/Analog input 1'
                                      */
  real_T Analoginput1_P3;              /* Expression: parPciSlot
                                        * Referenced by: '<S5>/Analog input 1'
                                        */
  real_T Analoginput1_P4_Size[2];    /* Computed Parameter: Analoginput1_P4_Size
                                      * Referenced by: '<S5>/Analog input 1'
                                      */
  real_T Analoginput1_P4;              /* Expression: parSampleTime
                                        * Referenced by: '<S5>/Analog input 1'
                                        */
  real_T Analoginput1_P5_Size[2];    /* Computed Parameter: Analoginput1_P5_Size
                                      * Referenced by: '<S5>/Analog input 1'
                                      */
  real_T Analoginput1_P5[2];           /* Expression: parAdcChannels
                                        * Referenced by: '<S5>/Analog input 1'
                                        */
  real_T Analoginput1_P6_Size[2];    /* Computed Parameter: Analoginput1_P6_Size
                                      * Referenced by: '<S5>/Analog input 1'
                                      */
  real_T Analoginput1_P6[2];           /* Expression: parAdcNumActiveChannels
                                        * Referenced by: '<S5>/Analog input 1'
                                        */
  real_T Analoginput1_P7_Size[2];    /* Computed Parameter: Analoginput1_P7_Size
                                      * Referenced by: '<S5>/Analog input 1'
                                      */
  real_T Analoginput1_P7[16];          /* Expression: parAdcVoltageRange
                                        * Referenced by: '<S5>/Analog input 1'
                                        */
  real_T Analoginput1_P8_Size[2];    /* Computed Parameter: Analoginput1_P8_Size
                                      * Referenced by: '<S5>/Analog input 1'
                                      */
  real_T Analoginput1_P8[2];           /* Expression: parAdcCoupling
                                        * Referenced by: '<S5>/Analog input 1'
                                        */
  real_T Analoginput1_P9_Size[2];    /* Computed Parameter: Analoginput1_P9_Size
                                      * Referenced by: '<S5>/Analog input 1'
                                      */
  real_T Analoginput1_P9;              /* Expression: parAdcContSampling
                                        * Referenced by: '<S5>/Analog input 1'
                                        */
  real_T Analoginput1_P10_Size[2];  /* Computed Parameter: Analoginput1_P10_Size
                                     * Referenced by: '<S5>/Analog input 1'
                                     */
  real_T Analoginput1_P10;             /* Expression: parAdcDmaEnable
                                        * Referenced by: '<S5>/Analog input 1'
                                        */
  real_T Analoginput1_P11_Size[2];  /* Computed Parameter: Analoginput1_P11_Size
                                     * Referenced by: '<S5>/Analog input 1'
                                     */
  real_T Analoginput1_P11[4];          /* Expression: parAdcActiveDmaDevices
                                        * Referenced by: '<S5>/Analog input 1'
                                        */
  real_T Analoginput1_P12_Size[2];  /* Computed Parameter: Analoginput1_P12_Size
                                     * Referenced by: '<S5>/Analog input 1'
                                     */
  real_T Analoginput1_P12;             /* Expression: parAdcFrameSize
                                        * Referenced by: '<S5>/Analog input 1'
                                        */
  real_T DILimitCarriage_P1_Size[2];
                                  /* Computed Parameter: DILimitCarriage_P1_Size
                                   * Referenced by: '<S5>/DI Limit Carriage '
                                   */
  real_T DILimitCarriage_P1;           /* Expression: boardType
                                        * Referenced by: '<S5>/DI Limit Carriage '
                                        */
  real_T DILimitCarriage_P2_Size[2];
                                  /* Computed Parameter: DILimitCarriage_P2_Size
                                   * Referenced by: '<S5>/DI Limit Carriage '
                                   */
  real_T DILimitCarriage_P2;           /* Expression: id
                                        * Referenced by: '<S5>/DI Limit Carriage '
                                        */
  real_T DILimitCarriage_P3_Size[2];
                                  /* Computed Parameter: DILimitCarriage_P3_Size
                                   * Referenced by: '<S5>/DI Limit Carriage '
                                   */
  real_T DILimitCarriage_P3;           /* Expression: chan
                                        * Referenced by: '<S5>/DI Limit Carriage '
                                        */
  real_T DILimitCarriage_P4_Size[2];
                                  /* Computed Parameter: DILimitCarriage_P4_Size
                                   * Referenced by: '<S5>/DI Limit Carriage '
                                   */
  real_T DILimitCarriage_P4;           /* Expression: vectorizeOutput
                                        * Referenced by: '<S5>/DI Limit Carriage '
                                        */
  real_T DILimitCarriage_P5_Size[2];
                                  /* Computed Parameter: DILimitCarriage_P5_Size
                                   * Referenced by: '<S5>/DI Limit Carriage '
                                   */
  real_T DILimitCarriage_P5;           /* Expression: ts
                                        * Referenced by: '<S5>/DI Limit Carriage '
                                        */
  real_T DILimitCarriage_P6_Size[2];
                                  /* Computed Parameter: DILimitCarriage_P6_Size
                                   * Referenced by: '<S5>/DI Limit Carriage '
                                   */
  real_T DILimitCarriage_P6;           /* Expression: pciSlot
                                        * Referenced by: '<S5>/DI Limit Carriage '
                                        */
  real_T DILimitGantryx1GantryxR_P1_Size[2];
                          /* Computed Parameter: DILimitGantryx1GantryxR_P1_Size
                           * Referenced by: '<S5>/DI Limit Gantry x1 = Gantry xR'
                           */
  real_T DILimitGantryx1GantryxR_P1;   /* Expression: boardType
                                        * Referenced by: '<S5>/DI Limit Gantry x1 = Gantry xR'
                                        */
  real_T DILimitGantryx1GantryxR_P2_Size[2];
                          /* Computed Parameter: DILimitGantryx1GantryxR_P2_Size
                           * Referenced by: '<S5>/DI Limit Gantry x1 = Gantry xR'
                           */
  real_T DILimitGantryx1GantryxR_P2;   /* Expression: id
                                        * Referenced by: '<S5>/DI Limit Gantry x1 = Gantry xR'
                                        */
  real_T DILimitGantryx1GantryxR_P3_Size[2];
                          /* Computed Parameter: DILimitGantryx1GantryxR_P3_Size
                           * Referenced by: '<S5>/DI Limit Gantry x1 = Gantry xR'
                           */
  real_T DILimitGantryx1GantryxR_P3;   /* Expression: chan
                                        * Referenced by: '<S5>/DI Limit Gantry x1 = Gantry xR'
                                        */
  real_T DILimitGantryx1GantryxR_P4_Size[2];
                          /* Computed Parameter: DILimitGantryx1GantryxR_P4_Size
                           * Referenced by: '<S5>/DI Limit Gantry x1 = Gantry xR'
                           */
  real_T DILimitGantryx1GantryxR_P4;   /* Expression: vectorizeOutput
                                        * Referenced by: '<S5>/DI Limit Gantry x1 = Gantry xR'
                                        */
  real_T DILimitGantryx1GantryxR_P5_Size[2];
                          /* Computed Parameter: DILimitGantryx1GantryxR_P5_Size
                           * Referenced by: '<S5>/DI Limit Gantry x1 = Gantry xR'
                           */
  real_T DILimitGantryx1GantryxR_P5;   /* Expression: ts
                                        * Referenced by: '<S5>/DI Limit Gantry x1 = Gantry xR'
                                        */
  real_T DILimitGantryx1GantryxR_P6_Size[2];
                          /* Computed Parameter: DILimitGantryx1GantryxR_P6_Size
                           * Referenced by: '<S5>/DI Limit Gantry x1 = Gantry xR'
                           */
  real_T DILimitGantryx1GantryxR_P6;   /* Expression: pciSlot
                                        * Referenced by: '<S5>/DI Limit Gantry x1 = Gantry xR'
                                        */
  real_T DILimitGantryx2GantryxL_P1_Size[2];
                          /* Computed Parameter: DILimitGantryx2GantryxL_P1_Size
                           * Referenced by: '<S5>/DI Limit Gantry x2 = Gantry xL'
                           */
  real_T DILimitGantryx2GantryxL_P1;   /* Expression: boardType
                                        * Referenced by: '<S5>/DI Limit Gantry x2 = Gantry xL'
                                        */
  real_T DILimitGantryx2GantryxL_P2_Size[2];
                          /* Computed Parameter: DILimitGantryx2GantryxL_P2_Size
                           * Referenced by: '<S5>/DI Limit Gantry x2 = Gantry xL'
                           */
  real_T DILimitGantryx2GantryxL_P2;   /* Expression: id
                                        * Referenced by: '<S5>/DI Limit Gantry x2 = Gantry xL'
                                        */
  real_T DILimitGantryx2GantryxL_P3_Size[2];
                          /* Computed Parameter: DILimitGantryx2GantryxL_P3_Size
                           * Referenced by: '<S5>/DI Limit Gantry x2 = Gantry xL'
                           */
  real_T DILimitGantryx2GantryxL_P3;   /* Expression: chan
                                        * Referenced by: '<S5>/DI Limit Gantry x2 = Gantry xL'
                                        */
  real_T DILimitGantryx2GantryxL_P4_Size[2];
                          /* Computed Parameter: DILimitGantryx2GantryxL_P4_Size
                           * Referenced by: '<S5>/DI Limit Gantry x2 = Gantry xL'
                           */
  real_T DILimitGantryx2GantryxL_P4;   /* Expression: vectorizeOutput
                                        * Referenced by: '<S5>/DI Limit Gantry x2 = Gantry xL'
                                        */
  real_T DILimitGantryx2GantryxL_P5_Size[2];
                          /* Computed Parameter: DILimitGantryx2GantryxL_P5_Size
                           * Referenced by: '<S5>/DI Limit Gantry x2 = Gantry xL'
                           */
  real_T DILimitGantryx2GantryxL_P5;   /* Expression: ts
                                        * Referenced by: '<S5>/DI Limit Gantry x2 = Gantry xL'
                                        */
  real_T DILimitGantryx2GantryxL_P6_Size[2];
                          /* Computed Parameter: DILimitGantryx2GantryxL_P6_Size
                           * Referenced by: '<S5>/DI Limit Gantry x2 = Gantry xL'
                           */
  real_T DILimitGantryx2GantryxL_P6;   /* Expression: pciSlot
                                        * Referenced by: '<S5>/DI Limit Gantry x2 = Gantry xL'
                                        */
  real_T DIblacksoftwarebutton_P1_Size[2];
                            /* Computed Parameter: DIblacksoftwarebutton_P1_Size
                             * Referenced by: '<S5>/DI black software button'
                             */
  real_T DIblacksoftwarebutton_P1;     /* Expression: boardType
                                        * Referenced by: '<S5>/DI black software button'
                                        */
  real_T DIblacksoftwarebutton_P2_Size[2];
                            /* Computed Parameter: DIblacksoftwarebutton_P2_Size
                             * Referenced by: '<S5>/DI black software button'
                             */
  real_T DIblacksoftwarebutton_P2;     /* Expression: id
                                        * Referenced by: '<S5>/DI black software button'
                                        */
  real_T DIblacksoftwarebutton_P3_Size[2];
                            /* Computed Parameter: DIblacksoftwarebutton_P3_Size
                             * Referenced by: '<S5>/DI black software button'
                             */
  real_T DIblacksoftwarebutton_P3;     /* Expression: chan
                                        * Referenced by: '<S5>/DI black software button'
                                        */
  real_T DIblacksoftwarebutton_P4_Size[2];
                            /* Computed Parameter: DIblacksoftwarebutton_P4_Size
                             * Referenced by: '<S5>/DI black software button'
                             */
  real_T DIblacksoftwarebutton_P4;     /* Expression: vectorizeOutput
                                        * Referenced by: '<S5>/DI black software button'
                                        */
  real_T DIblacksoftwarebutton_P5_Size[2];
                            /* Computed Parameter: DIblacksoftwarebutton_P5_Size
                             * Referenced by: '<S5>/DI black software button'
                             */
  real_T DIblacksoftwarebutton_P5;     /* Expression: ts
                                        * Referenced by: '<S5>/DI black software button'
                                        */
  real_T DIblacksoftwarebutton_P6_Size[2];
                            /* Computed Parameter: DIblacksoftwarebutton_P6_Size
                             * Referenced by: '<S5>/DI black software button'
                             */
  real_T DIblacksoftwarebutton_P6;     /* Expression: pciSlot
                                        * Referenced by: '<S5>/DI black software button'
                                        */
  real_T DIcarriageampfaultstatus_P1_Siz[2];
                          /* Computed Parameter: DIcarriageampfaultstatus_P1_Siz
                           * Referenced by: '<S5>/DI carriage amp. fault status'
                           */
  real_T DIcarriageampfaultstatus_P1;  /* Expression: boardType
                                        * Referenced by: '<S5>/DI carriage amp. fault status'
                                        */
  real_T DIcarriageampfaultstatus_P2_Siz[2];
                          /* Computed Parameter: DIcarriageampfaultstatus_P2_Siz
                           * Referenced by: '<S5>/DI carriage amp. fault status'
                           */
  real_T DIcarriageampfaultstatus_P2;  /* Expression: id
                                        * Referenced by: '<S5>/DI carriage amp. fault status'
                                        */
  real_T DIcarriageampfaultstatus_P3_Siz[2];
                          /* Computed Parameter: DIcarriageampfaultstatus_P3_Siz
                           * Referenced by: '<S5>/DI carriage amp. fault status'
                           */
  real_T DIcarriageampfaultstatus_P3;  /* Expression: chan
                                        * Referenced by: '<S5>/DI carriage amp. fault status'
                                        */
  real_T DIcarriageampfaultstatus_P4_Siz[2];
                          /* Computed Parameter: DIcarriageampfaultstatus_P4_Siz
                           * Referenced by: '<S5>/DI carriage amp. fault status'
                           */
  real_T DIcarriageampfaultstatus_P4;  /* Expression: vectorizeOutput
                                        * Referenced by: '<S5>/DI carriage amp. fault status'
                                        */
  real_T DIcarriageampfaultstatus_P5_Siz[2];
                          /* Computed Parameter: DIcarriageampfaultstatus_P5_Siz
                           * Referenced by: '<S5>/DI carriage amp. fault status'
                           */
  real_T DIcarriageampfaultstatus_P5;  /* Expression: ts
                                        * Referenced by: '<S5>/DI carriage amp. fault status'
                                        */
  real_T DIcarriageampfaultstatus_P6_Siz[2];
                          /* Computed Parameter: DIcarriageampfaultstatus_P6_Siz
                           * Referenced by: '<S5>/DI carriage amp. fault status'
                           */
  real_T DIcarriageampfaultstatus_P6;  /* Expression: pciSlot
                                        * Referenced by: '<S5>/DI carriage amp. fault status'
                                        */
  real_T DIgantryx1faultstatus_P1_Size[2];
                            /* Computed Parameter: DIgantryx1faultstatus_P1_Size
                             * Referenced by: '<S5>/DI gantry x1 fault status'
                             */
  real_T DIgantryx1faultstatus_P1;     /* Expression: boardType
                                        * Referenced by: '<S5>/DI gantry x1 fault status'
                                        */
  real_T DIgantryx1faultstatus_P2_Size[2];
                            /* Computed Parameter: DIgantryx1faultstatus_P2_Size
                             * Referenced by: '<S5>/DI gantry x1 fault status'
                             */
  real_T DIgantryx1faultstatus_P2;     /* Expression: id
                                        * Referenced by: '<S5>/DI gantry x1 fault status'
                                        */
  real_T DIgantryx1faultstatus_P3_Size[2];
                            /* Computed Parameter: DIgantryx1faultstatus_P3_Size
                             * Referenced by: '<S5>/DI gantry x1 fault status'
                             */
  real_T DIgantryx1faultstatus_P3;     /* Expression: chan
                                        * Referenced by: '<S5>/DI gantry x1 fault status'
                                        */
  real_T DIgantryx1faultstatus_P4_Size[2];
                            /* Computed Parameter: DIgantryx1faultstatus_P4_Size
                             * Referenced by: '<S5>/DI gantry x1 fault status'
                             */
  real_T DIgantryx1faultstatus_P4;     /* Expression: vectorizeOutput
                                        * Referenced by: '<S5>/DI gantry x1 fault status'
                                        */
  real_T DIgantryx1faultstatus_P5_Size[2];
                            /* Computed Parameter: DIgantryx1faultstatus_P5_Size
                             * Referenced by: '<S5>/DI gantry x1 fault status'
                             */
  real_T DIgantryx1faultstatus_P5;     /* Expression: ts
                                        * Referenced by: '<S5>/DI gantry x1 fault status'
                                        */
  real_T DIgantryx1faultstatus_P6_Size[2];
                            /* Computed Parameter: DIgantryx1faultstatus_P6_Size
                             * Referenced by: '<S5>/DI gantry x1 fault status'
                             */
  real_T DIgantryx1faultstatus_P6;     /* Expression: pciSlot
                                        * Referenced by: '<S5>/DI gantry x1 fault status'
                                        */
  real_T DIgantryx2faultstatus_P1_Size[2];
                            /* Computed Parameter: DIgantryx2faultstatus_P1_Size
                             * Referenced by: '<S5>/DI gantry x2 fault status'
                             */
  real_T DIgantryx2faultstatus_P1;     /* Expression: boardType
                                        * Referenced by: '<S5>/DI gantry x2 fault status'
                                        */
  real_T DIgantryx2faultstatus_P2_Size[2];
                            /* Computed Parameter: DIgantryx2faultstatus_P2_Size
                             * Referenced by: '<S5>/DI gantry x2 fault status'
                             */
  real_T DIgantryx2faultstatus_P2;     /* Expression: id
                                        * Referenced by: '<S5>/DI gantry x2 fault status'
                                        */
  real_T DIgantryx2faultstatus_P3_Size[2];
                            /* Computed Parameter: DIgantryx2faultstatus_P3_Size
                             * Referenced by: '<S5>/DI gantry x2 fault status'
                             */
  real_T DIgantryx2faultstatus_P3;     /* Expression: chan
                                        * Referenced by: '<S5>/DI gantry x2 fault status'
                                        */
  real_T DIgantryx2faultstatus_P4_Size[2];
                            /* Computed Parameter: DIgantryx2faultstatus_P4_Size
                             * Referenced by: '<S5>/DI gantry x2 fault status'
                             */
  real_T DIgantryx2faultstatus_P4;     /* Expression: vectorizeOutput
                                        * Referenced by: '<S5>/DI gantry x2 fault status'
                                        */
  real_T DIgantryx2faultstatus_P5_Size[2];
                            /* Computed Parameter: DIgantryx2faultstatus_P5_Size
                             * Referenced by: '<S5>/DI gantry x2 fault status'
                             */
  real_T DIgantryx2faultstatus_P5;     /* Expression: ts
                                        * Referenced by: '<S5>/DI gantry x2 fault status'
                                        */
  real_T DIgantryx2faultstatus_P6_Size[2];
                            /* Computed Parameter: DIgantryx2faultstatus_P6_Size
                             * Referenced by: '<S5>/DI gantry x2 fault status'
                             */
  real_T DIgantryx2faultstatus_P6;     /* Expression: pciSlot
                                        * Referenced by: '<S5>/DI gantry x2 fault status'
                                        */
  real_T DIredsoftwarebutton_P1_Size[2];
                              /* Computed Parameter: DIredsoftwarebutton_P1_Size
                               * Referenced by: '<S5>/DI red software button'
                               */
  real_T DIredsoftwarebutton_P1;       /* Expression: boardType
                                        * Referenced by: '<S5>/DI red software button'
                                        */
  real_T DIredsoftwarebutton_P2_Size[2];
                              /* Computed Parameter: DIredsoftwarebutton_P2_Size
                               * Referenced by: '<S5>/DI red software button'
                               */
  real_T DIredsoftwarebutton_P2;       /* Expression: id
                                        * Referenced by: '<S5>/DI red software button'
                                        */
  real_T DIredsoftwarebutton_P3_Size[2];
                              /* Computed Parameter: DIredsoftwarebutton_P3_Size
                               * Referenced by: '<S5>/DI red software button'
                               */
  real_T DIredsoftwarebutton_P3;       /* Expression: chan
                                        * Referenced by: '<S5>/DI red software button'
                                        */
  real_T DIredsoftwarebutton_P4_Size[2];
                              /* Computed Parameter: DIredsoftwarebutton_P4_Size
                               * Referenced by: '<S5>/DI red software button'
                               */
  real_T DIredsoftwarebutton_P4;       /* Expression: vectorizeOutput
                                        * Referenced by: '<S5>/DI red software button'
                                        */
  real_T DIredsoftwarebutton_P5_Size[2];
                              /* Computed Parameter: DIredsoftwarebutton_P5_Size
                               * Referenced by: '<S5>/DI red software button'
                               */
  real_T DIredsoftwarebutton_P5;       /* Expression: ts
                                        * Referenced by: '<S5>/DI red software button'
                                        */
  real_T DIredsoftwarebutton_P6_Size[2];
                              /* Computed Parameter: DIredsoftwarebutton_P6_Size
                               * Referenced by: '<S5>/DI red software button'
                               */
  real_T DIredsoftwarebutton_P6;       /* Expression: pciSlot
                                        * Referenced by: '<S5>/DI red software button'
                                        */
  real_T Gain1_Gain;                   /* Expression: 134
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Carriageencoder_P1_Size[2];
                                  /* Computed Parameter: Carriageencoder_P1_Size
                                   * Referenced by: '<S5>/Carriage encoder'
                                   */
  real_T Carriageencoder_P1;           /* Expression: boardType
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P2_Size[2];
                                  /* Computed Parameter: Carriageencoder_P2_Size
                                   * Referenced by: '<S5>/Carriage encoder'
                                   */
  real_T Carriageencoder_P2;           /* Expression: fpgaFrequency
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P3_Size[2];
                                  /* Computed Parameter: Carriageencoder_P3_Size
                                   * Referenced by: '<S5>/Carriage encoder'
                                   */
  real_T Carriageencoder_P3;           /* Expression: id
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P4_Size[2];
                                  /* Computed Parameter: Carriageencoder_P4_Size
                                   * Referenced by: '<S5>/Carriage encoder'
                                   */
  real_T Carriageencoder_P4;           /* Expression: chan
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P5_Size[2];
                                  /* Computed Parameter: Carriageencoder_P5_Size
                                   * Referenced by: '<S5>/Carriage encoder'
                                   */
  real_T Carriageencoder_P5;           /* Expression: sampleTime
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P6_Size[2];
                                  /* Computed Parameter: Carriageencoder_P6_Size
                                   * Referenced by: '<S5>/Carriage encoder'
                                   */
  real_T Carriageencoder_P6;           /* Expression: pciSlot
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P7_Size[2];
                                  /* Computed Parameter: Carriageencoder_P7_Size
                                   * Referenced by: '<S5>/Carriage encoder'
                                   */
  real_T Carriageencoder_P7;           /* Expression: numOfSlots
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P8_Size[2];
                                  /* Computed Parameter: Carriageencoder_P8_Size
                                   * Referenced by: '<S5>/Carriage encoder'
                                   */
  real_T Carriageencoder_P8;           /* Expression: sensorType
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P9_Size[2];
                                  /* Computed Parameter: Carriageencoder_P9_Size
                                   * Referenced by: '<S5>/Carriage encoder'
                                   */
  real_T Carriageencoder_P9;           /* Expression: interpolatePosition
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P10_Size[2];
                                 /* Computed Parameter: Carriageencoder_P10_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P10;          /* Expression: swapAB
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P11_Size[2];
                                 /* Computed Parameter: Carriageencoder_P11_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P11;          /* Expression: indexControlMode
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P12_Size[2];
                                 /* Computed Parameter: Carriageencoder_P12_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P12;          /* Expression: latchMode
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P13_Size[2];
                                 /* Computed Parameter: Carriageencoder_P13_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P13;          /* Expression: gateIndex
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P14_Size[2];
                                 /* Computed Parameter: Carriageencoder_P14_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P14;          /* Expression: speedFilterWidth
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P15_Size[2];
                                 /* Computed Parameter: Carriageencoder_P15_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P15;          /* Expression: showInputSpeedFilterWidth
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P16_Size[2];
                                 /* Computed Parameter: Carriageencoder_P16_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P16;          /* Expression: glitchFilterSeconds
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P17_Size[2];
                                 /* Computed Parameter: Carriageencoder_P17_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P17;          /* Expression: showInputClearPosition
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P18_Size[2];
                                 /* Computed Parameter: Carriageencoder_P18_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P18;          /* Expression: showInputClearIndexFound
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P19_Size[2];
                                 /* Computed Parameter: Carriageencoder_P19_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P19;          /* Expression: showOutputPosition
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P20_Size[2];
                                 /* Computed Parameter: Carriageencoder_P20_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P20;          /* Expression: showOutputTurn
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P21_Size[2];
                                 /* Computed Parameter: Carriageencoder_P21_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P21;          /* Expression: showOutputSpeed
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P22_Size[2];
                                 /* Computed Parameter: Carriageencoder_P22_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P22;          /* Expression: showOutputIndexFound
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P23_Size[2];
                                 /* Computed Parameter: Carriageencoder_P23_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P23;          /* Expression: showOutputLastPulse
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Carriageencoder_P24_Size[2];
                                 /* Computed Parameter: Carriageencoder_P24_Size
                                  * Referenced by: '<S5>/Carriage encoder'
                                  */
  real_T Carriageencoder_P24;          /* Expression: isDmaEnabled
                                        * Referenced by: '<S5>/Carriage encoder'
                                        */
  real_T Calibration1_Gain;            /* Expression: 4e-6
                                        * Referenced by: '<S5>/Calibration1'
                                        */
  real_T Gain5_Gain;                   /* Expression: -1
                                        * Referenced by: '<S5>/Gain5'
                                        */
  real_T Gantryx1GantryxR_P1_Size[2];
                                 /* Computed Parameter: Gantryx1GantryxR_P1_Size
                                  * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                  */
  real_T Gantryx1GantryxR_P1;          /* Expression: boardType
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P2_Size[2];
                                 /* Computed Parameter: Gantryx1GantryxR_P2_Size
                                  * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                  */
  real_T Gantryx1GantryxR_P2;          /* Expression: fpgaFrequency
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P3_Size[2];
                                 /* Computed Parameter: Gantryx1GantryxR_P3_Size
                                  * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                  */
  real_T Gantryx1GantryxR_P3;          /* Expression: id
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P4_Size[2];
                                 /* Computed Parameter: Gantryx1GantryxR_P4_Size
                                  * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                  */
  real_T Gantryx1GantryxR_P4;          /* Expression: chan
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P5_Size[2];
                                 /* Computed Parameter: Gantryx1GantryxR_P5_Size
                                  * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                  */
  real_T Gantryx1GantryxR_P5;          /* Expression: sampleTime
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P6_Size[2];
                                 /* Computed Parameter: Gantryx1GantryxR_P6_Size
                                  * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                  */
  real_T Gantryx1GantryxR_P6;          /* Expression: pciSlot
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P7_Size[2];
                                 /* Computed Parameter: Gantryx1GantryxR_P7_Size
                                  * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                  */
  real_T Gantryx1GantryxR_P7;          /* Expression: numOfSlots
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P8_Size[2];
                                 /* Computed Parameter: Gantryx1GantryxR_P8_Size
                                  * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                  */
  real_T Gantryx1GantryxR_P8;          /* Expression: sensorType
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P9_Size[2];
                                 /* Computed Parameter: Gantryx1GantryxR_P9_Size
                                  * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                  */
  real_T Gantryx1GantryxR_P9;          /* Expression: interpolatePosition
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P10_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P10_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P10;         /* Expression: swapAB
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P11_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P11_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P11;         /* Expression: indexControlMode
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P12_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P12_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P12;         /* Expression: latchMode
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P13_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P13_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P13;         /* Expression: gateIndex
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P14_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P14_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P14;         /* Expression: speedFilterWidth
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P15_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P15_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P15;         /* Expression: showInputSpeedFilterWidth
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P16_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P16_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P16;         /* Expression: glitchFilterSeconds
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P17_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P17_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P17;         /* Expression: showInputClearPosition
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P18_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P18_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P18;         /* Expression: showInputClearIndexFound
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P19_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P19_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P19;         /* Expression: showOutputPosition
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P20_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P20_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P20;         /* Expression: showOutputTurn
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P21_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P21_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P21;         /* Expression: showOutputSpeed
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P22_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P22_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P22;         /* Expression: showOutputIndexFound
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P23_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P23_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P23;         /* Expression: showOutputLastPulse
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Gantryx1GantryxR_P24_Size[2];
                                /* Computed Parameter: Gantryx1GantryxR_P24_Size
                                 * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                 */
  real_T Gantryx1GantryxR_P24;         /* Expression: isDmaEnabled
                                        * Referenced by: '<S5>/Gantry x1 = Gantry xR'
                                        */
  real_T Calibration2_Gain;            /* Expression: 4e-6
                                        * Referenced by: '<S5>/Calibration2'
                                        */
  real_T Gain6_Gain;                   /* Expression: -1
                                        * Referenced by: '<S5>/Gain6'
                                        */
  real_T Gantryx2GantryxL_P1_Size[2];
                                 /* Computed Parameter: Gantryx2GantryxL_P1_Size
                                  * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                  */
  real_T Gantryx2GantryxL_P1;          /* Expression: boardType
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P2_Size[2];
                                 /* Computed Parameter: Gantryx2GantryxL_P2_Size
                                  * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                  */
  real_T Gantryx2GantryxL_P2;          /* Expression: fpgaFrequency
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P3_Size[2];
                                 /* Computed Parameter: Gantryx2GantryxL_P3_Size
                                  * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                  */
  real_T Gantryx2GantryxL_P3;          /* Expression: id
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P4_Size[2];
                                 /* Computed Parameter: Gantryx2GantryxL_P4_Size
                                  * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                  */
  real_T Gantryx2GantryxL_P4;          /* Expression: chan
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P5_Size[2];
                                 /* Computed Parameter: Gantryx2GantryxL_P5_Size
                                  * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                  */
  real_T Gantryx2GantryxL_P5;          /* Expression: sampleTime
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P6_Size[2];
                                 /* Computed Parameter: Gantryx2GantryxL_P6_Size
                                  * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                  */
  real_T Gantryx2GantryxL_P6;          /* Expression: pciSlot
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P7_Size[2];
                                 /* Computed Parameter: Gantryx2GantryxL_P7_Size
                                  * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                  */
  real_T Gantryx2GantryxL_P7;          /* Expression: numOfSlots
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P8_Size[2];
                                 /* Computed Parameter: Gantryx2GantryxL_P8_Size
                                  * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                  */
  real_T Gantryx2GantryxL_P8;          /* Expression: sensorType
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P9_Size[2];
                                 /* Computed Parameter: Gantryx2GantryxL_P9_Size
                                  * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                  */
  real_T Gantryx2GantryxL_P9;          /* Expression: interpolatePosition
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P10_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P10_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P10;         /* Expression: swapAB
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P11_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P11_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P11;         /* Expression: indexControlMode
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P12_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P12_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P12;         /* Expression: latchMode
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P13_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P13_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P13;         /* Expression: gateIndex
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P14_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P14_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P14;         /* Expression: speedFilterWidth
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P15_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P15_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P15;         /* Expression: showInputSpeedFilterWidth
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P16_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P16_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P16;         /* Expression: glitchFilterSeconds
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P17_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P17_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P17;         /* Expression: showInputClearPosition
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P18_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P18_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P18;         /* Expression: showInputClearIndexFound
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P19_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P19_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P19;         /* Expression: showOutputPosition
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P20_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P20_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P20;         /* Expression: showOutputTurn
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P21_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P21_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P21;         /* Expression: showOutputSpeed
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P22_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P22_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P22;         /* Expression: showOutputIndexFound
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P23_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P23_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P23;         /* Expression: showOutputLastPulse
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Gantryx2GantryxL_P24_Size[2];
                                /* Computed Parameter: Gantryx2GantryxL_P24_Size
                                 * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                 */
  real_T Gantryx2GantryxL_P24;         /* Expression: isDmaEnabled
                                        * Referenced by: '<S5>/Gantry x2 = Gantry xL'
                                        */
  real_T Calibration3_Gain;            /* Expression: 4e-6
                                        * Referenced by: '<S5>/Calibration3'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1
                                        * Referenced by: '<S5>/Gain7'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T log_penholder_active_InitialCon;/* Expression: 0
                                          * Referenced by: '<Root>/log_penholder_active'
                                          */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Delay2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S21>/Delay1'
                                        */
  real_T Delay_InitialCondition_o;     /* Expression: 0.0
                                        * Referenced by: '<S21>/Delay'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S21>/Switch1'
                                        */
  real_T Delay1_InitialCondition_m;    /* Expression: 0
                                        * Referenced by: '<Root>/Delay1'
                                        */
  real_T Gain8_Gain;                   /* Expression: 1/4
                                        * Referenced by: '<Root>/Gain8'
                                        */
  real_T Dct2lowpassoutput_y_P1_Size[2];
                              /* Computed Parameter: Dct2lowpassoutput_y_P1_Size
                               * Referenced by: '<S10>/Dct2lowpass output_y'
                               */
  real_T Dct2lowpassoutput_y_P1;       /* Expression: f_den
                                        * Referenced by: '<S10>/Dct2lowpass output_y'
                                        */
  real_T Dct2lowpassoutput_y_P2_Size[2];
                              /* Computed Parameter: Dct2lowpassoutput_y_P2_Size
                               * Referenced by: '<S10>/Dct2lowpass output_y'
                               */
  real_T Dct2lowpassoutput_y_P2;       /* Expression: b_den
                                        * Referenced by: '<S10>/Dct2lowpass output_y'
                                        */
  real_T Dct2lowpassoutput_y_P3_Size[2];
                              /* Computed Parameter: Dct2lowpassoutput_y_P3_Size
                               * Referenced by: '<S10>/Dct2lowpass output_y'
                               */
  real_T Dct2lowpassoutput_y_P3;       /* Expression: 0.001
                                        * Referenced by: '<S10>/Dct2lowpass output_y'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S41>/TSamp'
                                        */
  real_T Delay1_InitialCondition_mu;   /* Expression: 0.0
                                        * Referenced by: '<S20>/Delay1'
                                        */
  real_T Delay_InitialCondition_d;     /* Expression: 0.0
                                        * Referenced by: '<S20>/Delay'
                                        */
  real_T Switch1_Threshold_m;          /* Expression: 0
                                        * Referenced by: '<S20>/Switch1'
                                        */
  real_T Gainx_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S2>/Gain x'
                                        */
  real_T Gain9_Gain;                   /* Expression: 1/4
                                        * Referenced by: '<Root>/Gain9'
                                        */
  real_T Dct2lowpassoutput_x_P1_Size[2];
                              /* Computed Parameter: Dct2lowpassoutput_x_P1_Size
                               * Referenced by: '<S10>/Dct2lowpass output_x'
                               */
  real_T Dct2lowpassoutput_x_P1;       /* Expression: f_den
                                        * Referenced by: '<S10>/Dct2lowpass output_x'
                                        */
  real_T Dct2lowpassoutput_x_P2_Size[2];
                              /* Computed Parameter: Dct2lowpassoutput_x_P2_Size
                               * Referenced by: '<S10>/Dct2lowpass output_x'
                               */
  real_T Dct2lowpassoutput_x_P2;       /* Expression: b_den
                                        * Referenced by: '<S10>/Dct2lowpass output_x'
                                        */
  real_T Dct2lowpassoutput_x_P3_Size[2];
                              /* Computed Parameter: Dct2lowpassoutput_x_P3_Size
                               * Referenced by: '<S10>/Dct2lowpass output_x'
                               */
  real_T Dct2lowpassoutput_x_P3;       /* Expression: 0.001
                                        * Referenced by: '<S10>/Dct2lowpass output_x'
                                        */
  real_T TSamp_WtEt_p;                 /* Computed Parameter: TSamp_WtEt_p
                                        * Referenced by: '<S40>/TSamp'
                                        */
  real_T Delay1_InitialCondition_l;    /* Expression: 0.0
                                        * Referenced by: '<S19>/Delay1'
                                        */
  real_T Delay_InitialCondition_a;     /* Expression: 0.0
                                        * Referenced by: '<S19>/Delay'
                                        */
  real_T Switch1_Threshold_e;          /* Expression: 0
                                        * Referenced by: '<S19>/Switch1'
                                        */
  real_T Gainphi_Gain;                 /* Expression: 1/2.62
                                        * Referenced by: '<S2>/Gain phi'
                                        */
  real_T Gain10_Gain;                  /* Expression: 1/4
                                        * Referenced by: '<Root>/Gain10'
                                        */
  real_T Dct2lowpasscurrent_gantryAirbag[2];
                          /* Computed Parameter: Dct2lowpasscurrent_gantryAirbag
                           * Referenced by: '<S10>/Dct2lowpass current_gantryAirbag'
                           */
  real_T Dct2lowpasscurrent_gantryAirb_e;/* Expression: f_den
                                          * Referenced by: '<S10>/Dct2lowpass current_gantryAirbag'
                                          */
  real_T Dct2lowpasscurrent_gantryAirb_o[2];
                          /* Computed Parameter: Dct2lowpasscurrent_gantryAirb_o
                           * Referenced by: '<S10>/Dct2lowpass current_gantryAirbag'
                           */
  real_T Dct2lowpasscurrent_gantryAirb_m;/* Expression: b_den
                                          * Referenced by: '<S10>/Dct2lowpass current_gantryAirbag'
                                          */
  real_T Dct2lowpasscurrent_gantryAirb_p[2];
                          /* Computed Parameter: Dct2lowpasscurrent_gantryAirb_p
                           * Referenced by: '<S10>/Dct2lowpass current_gantryAirbag'
                           */
  real_T Dct2lowpasscurrent_gantryAirb_a;/* Expression: 0.001
                                          * Referenced by: '<S10>/Dct2lowpass current_gantryAirbag'
                                          */
  real_T Internal_A[3];                /* Computed Parameter: Internal_A
                                        * Referenced by: '<S7>/Internal'
                                        */
  real_T Internal_B[2];                /* Computed Parameter: Internal_B
                                        * Referenced by: '<S7>/Internal'
                                        */
  real_T Internal_C[2];                /* Computed Parameter: Internal_C
                                        * Referenced by: '<S7>/Internal'
                                        */
  real_T Internal_D;                   /* Computed Parameter: Internal_D
                                        * Referenced by: '<S7>/Internal'
                                        */
  real_T Internal_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S7>/Internal'
                                        */
  real_T Gainonu_x_Gain;               /* Expression: 1/2
                                        * Referenced by: '<S1>/Gain on u_x'
                                        */
  real_T Internal_A_p[6];              /* Computed Parameter: Internal_A_p
                                        * Referenced by: '<S8>/Internal'
                                        */
  real_T Internal_B_g[2];              /* Computed Parameter: Internal_B_g
                                        * Referenced by: '<S8>/Internal'
                                        */
  real_T Internal_C_i[3];              /* Computed Parameter: Internal_C_i
                                        * Referenced by: '<S8>/Internal'
                                        */
  real_T Internal_D_g;                 /* Computed Parameter: Internal_D_g
                                        * Referenced by: '<S8>/Internal'
                                        */
  real_T Internal_InitialCondition_e;  /* Expression: 0
                                        * Referenced by: '<S8>/Internal'
                                        */
  real_T Gainonu_phi_Gain;             /* Expression: 1/2.62
                                        * Referenced by: '<S1>/Gain on u_phi'
                                        */
  real_T Gaingantryx2motorcurrent1_Gain;/* Expression: 1
                                         * Referenced by: '<S5>/Gain gantry x2 motor current1'
                                         */
  real_T Gaingantryx2motorcurrent_Gain;/* Expression: -1
                                        * Referenced by: '<S5>/Gain gantry x2 motor current'
                                        */
  real_T Dct2lowpasscurrent_carriageAirb[2];
                          /* Computed Parameter: Dct2lowpasscurrent_carriageAirb
                           * Referenced by: '<S10>/Dct2lowpass current_carriageAirbag'
                           */
  real_T Dct2lowpasscurrent_carriageAi_c;/* Expression: f_den
                                          * Referenced by: '<S10>/Dct2lowpass current_carriageAirbag'
                                          */
  real_T Dct2lowpasscurrent_carriageAi_e[2];
                          /* Computed Parameter: Dct2lowpasscurrent_carriageAi_e
                           * Referenced by: '<S10>/Dct2lowpass current_carriageAirbag'
                           */
  real_T Dct2lowpasscurrent_carriageAi_l;/* Expression: b_den
                                          * Referenced by: '<S10>/Dct2lowpass current_carriageAirbag'
                                          */
  real_T Dct2lowpasscurrent_carriageAi_g[2];
                          /* Computed Parameter: Dct2lowpasscurrent_carriageAi_g
                           * Referenced by: '<S10>/Dct2lowpass current_carriageAirbag'
                           */
  real_T Dct2lowpasscurrent_carriageAi_n;/* Expression: 0.001
                                          * Referenced by: '<S10>/Dct2lowpass current_carriageAirbag'
                                          */
  real_T Internal_A_g[3];              /* Computed Parameter: Internal_A_g
                                        * Referenced by: '<S6>/Internal'
                                        */
  real_T Internal_B_j[2];              /* Computed Parameter: Internal_B_j
                                        * Referenced by: '<S6>/Internal'
                                        */
  real_T Internal_C_l[2];              /* Computed Parameter: Internal_C_l
                                        * Referenced by: '<S6>/Internal'
                                        */
  real_T Internal_D_f;                 /* Computed Parameter: Internal_D_f
                                        * Referenced by: '<S6>/Internal'
                                        */
  real_T Internal_InitialCondition_o;  /* Expression: 0
                                        * Referenced by: '<S6>/Internal'
                                        */
  real_T Gaincarriagemotorcurrent_Gain;/* Expression: -1
                                        * Referenced by: '<S5>/Gain carriage motor current'
                                        */
  real_T Analogoutput2_P1_Size[2];  /* Computed Parameter: Analogoutput2_P1_Size
                                     * Referenced by: '<S5>/Analog output 2'
                                     */
  real_T Analogoutput2_P1;             /* Expression: boardType
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P2_Size[2];  /* Computed Parameter: Analogoutput2_P2_Size
                                     * Referenced by: '<S5>/Analog output 2'
                                     */
  real_T Analogoutput2_P2;             /* Expression: parModuleId
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P3_Size[2];  /* Computed Parameter: Analogoutput2_P3_Size
                                     * Referenced by: '<S5>/Analog output 2'
                                     */
  real_T Analogoutput2_P3;             /* Expression: parPciSlot
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P4_Size[2];  /* Computed Parameter: Analogoutput2_P4_Size
                                     * Referenced by: '<S5>/Analog output 2'
                                     */
  real_T Analogoutput2_P4;             /* Expression: parSampleTime
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P5_Size[2];  /* Computed Parameter: Analogoutput2_P5_Size
                                     * Referenced by: '<S5>/Analog output 2'
                                     */
  real_T Analogoutput2_P5[3];          /* Expression: parDacChannels
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P6_Size[2];  /* Computed Parameter: Analogoutput2_P6_Size
                                     * Referenced by: '<S5>/Analog output 2'
                                     */
  real_T Analogoutput2_P6[4];          /* Expression: parDacVoltageRange
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P7_Size[2];  /* Computed Parameter: Analogoutput2_P7_Size
                                     * Referenced by: '<S5>/Analog output 2'
                                     */
  real_T Analogoutput2_P7[4];          /* Expression: parDacOverRange
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P8_Size[2];  /* Computed Parameter: Analogoutput2_P8_Size
                                     * Referenced by: '<S5>/Analog output 2'
                                     */
  real_T Analogoutput2_P8[3];          /* Expression: parDacInitValues
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P9_Size[2];  /* Computed Parameter: Analogoutput2_P9_Size
                                     * Referenced by: '<S5>/Analog output 2'
                                     */
  real_T Analogoutput2_P9[3];          /* Expression: parDacReset
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P10_Size[2];/* Computed Parameter: Analogoutput2_P10_Size
                                    * Referenced by: '<S5>/Analog output 2'
                                    */
  real_T Analogoutput2_P10;            /* Expression: parDacSyncOut
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P11_Size[2];/* Computed Parameter: Analogoutput2_P11_Size
                                    * Referenced by: '<S5>/Analog output 2'
                                    */
  real_T Analogoutput2_P11;            /* Expression: parDacDmaEnable
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P12_Size[2];/* Computed Parameter: Analogoutput2_P12_Size
                                    * Referenced by: '<S5>/Analog output 2'
                                    */
  real_T Analogoutput2_P12[4];         /* Expression: parDacActiveDmaDevices
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P13_Size[2];/* Computed Parameter: Analogoutput2_P13_Size
                                    * Referenced by: '<S5>/Analog output 2'
                                    */
  real_T Analogoutput2_P13;            /* Expression: parDacDmaLatency
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Analogoutput2_P14_Size[2];/* Computed Parameter: Analogoutput2_P14_Size
                                    * Referenced by: '<S5>/Analog output 2'
                                    */
  real_T Analogoutput2_P14;            /* Expression: parDacFrameSize
                                        * Referenced by: '<S5>/Analog output 2'
                                        */
  real_T Enable_amplifier_y_Value;     /* Expression: 0
                                        * Referenced by: '<S10>/Enable_amplifier_y'
                                        */
  real_T DOInhibitCarriage_P1_Size[2];
                                /* Computed Parameter: DOInhibitCarriage_P1_Size
                                 * Referenced by: '<S5>/DO Inhibit Carriage'
                                 */
  real_T DOInhibitCarriage_P1;         /* Expression: boardType
                                        * Referenced by: '<S5>/DO Inhibit Carriage'
                                        */
  real_T DOInhibitCarriage_P2_Size[2];
                                /* Computed Parameter: DOInhibitCarriage_P2_Size
                                 * Referenced by: '<S5>/DO Inhibit Carriage'
                                 */
  real_T DOInhibitCarriage_P2;         /* Expression: id
                                        * Referenced by: '<S5>/DO Inhibit Carriage'
                                        */
  real_T DOInhibitCarriage_P3_Size[2];
                                /* Computed Parameter: DOInhibitCarriage_P3_Size
                                 * Referenced by: '<S5>/DO Inhibit Carriage'
                                 */
  real_T DOInhibitCarriage_P3;         /* Expression: chan
                                        * Referenced by: '<S5>/DO Inhibit Carriage'
                                        */
  real_T DOInhibitCarriage_P4_Size[2];
                                /* Computed Parameter: DOInhibitCarriage_P4_Size
                                 * Referenced by: '<S5>/DO Inhibit Carriage'
                                 */
  real_T DOInhibitCarriage_P4;         /* Expression: vectorizeInput
                                        * Referenced by: '<S5>/DO Inhibit Carriage'
                                        */
  real_T DOInhibitCarriage_P5_Size[2];
                                /* Computed Parameter: DOInhibitCarriage_P5_Size
                                 * Referenced by: '<S5>/DO Inhibit Carriage'
                                 */
  real_T DOInhibitCarriage_P5;         /* Expression: reset
                                        * Referenced by: '<S5>/DO Inhibit Carriage'
                                        */
  real_T DOInhibitCarriage_P6_Size[2];
                                /* Computed Parameter: DOInhibitCarriage_P6_Size
                                 * Referenced by: '<S5>/DO Inhibit Carriage'
                                 */
  real_T DOInhibitCarriage_P6;         /* Expression: init
                                        * Referenced by: '<S5>/DO Inhibit Carriage'
                                        */
  real_T DOInhibitCarriage_P7_Size[2];
                                /* Computed Parameter: DOInhibitCarriage_P7_Size
                                 * Referenced by: '<S5>/DO Inhibit Carriage'
                                 */
  real_T DOInhibitCarriage_P7;         /* Expression: ts
                                        * Referenced by: '<S5>/DO Inhibit Carriage'
                                        */
  real_T DOInhibitCarriage_P8_Size[2];
                                /* Computed Parameter: DOInhibitCarriage_P8_Size
                                 * Referenced by: '<S5>/DO Inhibit Carriage'
                                 */
  real_T DOInhibitCarriage_P8;         /* Expression: pciSlot
                                        * Referenced by: '<S5>/DO Inhibit Carriage'
                                        */
  real_T Enable_amplifier_xR_Value;    /* Expression: 0
                                        * Referenced by: '<S10>/Enable_amplifier_xR'
                                        */
  real_T DOInhibitGantryx1GantryxR_P1_Si[2];
                          /* Computed Parameter: DOInhibitGantryx1GantryxR_P1_Si
                           * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                           */
  real_T DOInhibitGantryx1GantryxR_P1; /* Expression: boardType
                                        * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                                        */
  real_T DOInhibitGantryx1GantryxR_P2_Si[2];
                          /* Computed Parameter: DOInhibitGantryx1GantryxR_P2_Si
                           * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                           */
  real_T DOInhibitGantryx1GantryxR_P2; /* Expression: id
                                        * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                                        */
  real_T DOInhibitGantryx1GantryxR_P3_Si[2];
                          /* Computed Parameter: DOInhibitGantryx1GantryxR_P3_Si
                           * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                           */
  real_T DOInhibitGantryx1GantryxR_P3; /* Expression: chan
                                        * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                                        */
  real_T DOInhibitGantryx1GantryxR_P4_Si[2];
                          /* Computed Parameter: DOInhibitGantryx1GantryxR_P4_Si
                           * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                           */
  real_T DOInhibitGantryx1GantryxR_P4; /* Expression: vectorizeInput
                                        * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                                        */
  real_T DOInhibitGantryx1GantryxR_P5_Si[2];
                          /* Computed Parameter: DOInhibitGantryx1GantryxR_P5_Si
                           * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                           */
  real_T DOInhibitGantryx1GantryxR_P5; /* Expression: reset
                                        * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                                        */
  real_T DOInhibitGantryx1GantryxR_P6_Si[2];
                          /* Computed Parameter: DOInhibitGantryx1GantryxR_P6_Si
                           * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                           */
  real_T DOInhibitGantryx1GantryxR_P6; /* Expression: init
                                        * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                                        */
  real_T DOInhibitGantryx1GantryxR_P7_Si[2];
                          /* Computed Parameter: DOInhibitGantryx1GantryxR_P7_Si
                           * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                           */
  real_T DOInhibitGantryx1GantryxR_P7; /* Expression: ts
                                        * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                                        */
  real_T DOInhibitGantryx1GantryxR_P8_Si[2];
                          /* Computed Parameter: DOInhibitGantryx1GantryxR_P8_Si
                           * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                           */
  real_T DOInhibitGantryx1GantryxR_P8; /* Expression: pciSlot
                                        * Referenced by: '<S5>/DO Inhibit Gantry x1 = Gantry xR'
                                        */
  real_T Enable_amplifier_xL_Value;    /* Expression: 0
                                        * Referenced by: '<S10>/Enable_amplifier_xL'
                                        */
  real_T DOInhibitGantryx2DOGantryxL_P1_[2];
                          /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P1_
                           * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                           */
  real_T DOInhibitGantryx2DOGantryxL_P1;/* Expression: boardType
                                         * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                                         */
  real_T DOInhibitGantryx2DOGantryxL_P2_[2];
                          /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P2_
                           * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                           */
  real_T DOInhibitGantryx2DOGantryxL_P2;/* Expression: id
                                         * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                                         */
  real_T DOInhibitGantryx2DOGantryxL_P3_[2];
                          /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P3_
                           * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                           */
  real_T DOInhibitGantryx2DOGantryxL_P3;/* Expression: chan
                                         * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                                         */
  real_T DOInhibitGantryx2DOGantryxL_P4_[2];
                          /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P4_
                           * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                           */
  real_T DOInhibitGantryx2DOGantryxL_P4;/* Expression: vectorizeInput
                                         * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                                         */
  real_T DOInhibitGantryx2DOGantryxL_P5_[2];
                          /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P5_
                           * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                           */
  real_T DOInhibitGantryx2DOGantryxL_P5;/* Expression: reset
                                         * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                                         */
  real_T DOInhibitGantryx2DOGantryxL_P6_[2];
                          /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P6_
                           * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                           */
  real_T DOInhibitGantryx2DOGantryxL_P6;/* Expression: init
                                         * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                                         */
  real_T DOInhibitGantryx2DOGantryxL_P7_[2];
                          /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P7_
                           * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                           */
  real_T DOInhibitGantryx2DOGantryxL_P7;/* Expression: ts
                                         * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                                         */
  real_T DOInhibitGantryx2DOGantryxL_P8_[2];
                          /* Computed Parameter: DOInhibitGantryx2DOGantryxL_P8_
                           * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                           */
  real_T DOInhibitGantryx2DOGantryxL_P8;/* Expression: pciSlot
                                         * Referenced by: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL'
                                         */
  real_T Cariagesecundair_P1_Size[2];
                                 /* Computed Parameter: Cariagesecundair_P1_Size
                                  * Referenced by: '<S5>/Cariage secundair'
                                  */
  real_T Cariagesecundair_P1;          /* Expression: boardType
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P2_Size[2];
                                 /* Computed Parameter: Cariagesecundair_P2_Size
                                  * Referenced by: '<S5>/Cariage secundair'
                                  */
  real_T Cariagesecundair_P2;          /* Expression: fpgaFrequency
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P3_Size[2];
                                 /* Computed Parameter: Cariagesecundair_P3_Size
                                  * Referenced by: '<S5>/Cariage secundair'
                                  */
  real_T Cariagesecundair_P3;          /* Expression: id
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P4_Size[2];
                                 /* Computed Parameter: Cariagesecundair_P4_Size
                                  * Referenced by: '<S5>/Cariage secundair'
                                  */
  real_T Cariagesecundair_P4;          /* Expression: chan
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P5_Size[2];
                                 /* Computed Parameter: Cariagesecundair_P5_Size
                                  * Referenced by: '<S5>/Cariage secundair'
                                  */
  real_T Cariagesecundair_P5;          /* Expression: sampleTime
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P6_Size[2];
                                 /* Computed Parameter: Cariagesecundair_P6_Size
                                  * Referenced by: '<S5>/Cariage secundair'
                                  */
  real_T Cariagesecundair_P6;          /* Expression: pciSlot
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P7_Size[2];
                                 /* Computed Parameter: Cariagesecundair_P7_Size
                                  * Referenced by: '<S5>/Cariage secundair'
                                  */
  real_T Cariagesecundair_P7;          /* Expression: numOfSlots
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P8_Size[2];
                                 /* Computed Parameter: Cariagesecundair_P8_Size
                                  * Referenced by: '<S5>/Cariage secundair'
                                  */
  real_T Cariagesecundair_P8;          /* Expression: sensorType
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P9_Size[2];
                                 /* Computed Parameter: Cariagesecundair_P9_Size
                                  * Referenced by: '<S5>/Cariage secundair'
                                  */
  real_T Cariagesecundair_P9;          /* Expression: interpolatePosition
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P10_Size[2];
                                /* Computed Parameter: Cariagesecundair_P10_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P10;         /* Expression: swapAB
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P11_Size[2];
                                /* Computed Parameter: Cariagesecundair_P11_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P11;         /* Expression: indexControlMode
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P12_Size[2];
                                /* Computed Parameter: Cariagesecundair_P12_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P12;         /* Expression: latchMode
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P13_Size[2];
                                /* Computed Parameter: Cariagesecundair_P13_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P13;         /* Expression: gateIndex
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P14_Size[2];
                                /* Computed Parameter: Cariagesecundair_P14_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P14;         /* Expression: speedFilterWidth
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P15_Size[2];
                                /* Computed Parameter: Cariagesecundair_P15_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P15;         /* Expression: showInputSpeedFilterWidth
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P16_Size[2];
                                /* Computed Parameter: Cariagesecundair_P16_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P16;         /* Expression: glitchFilterSeconds
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P17_Size[2];
                                /* Computed Parameter: Cariagesecundair_P17_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P17;         /* Expression: showInputClearPosition
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P18_Size[2];
                                /* Computed Parameter: Cariagesecundair_P18_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P18;         /* Expression: showInputClearIndexFound
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P19_Size[2];
                                /* Computed Parameter: Cariagesecundair_P19_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P19;         /* Expression: showOutputPosition
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P20_Size[2];
                                /* Computed Parameter: Cariagesecundair_P20_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P20;         /* Expression: showOutputTurn
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P21_Size[2];
                                /* Computed Parameter: Cariagesecundair_P21_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P21;         /* Expression: showOutputSpeed
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P22_Size[2];
                                /* Computed Parameter: Cariagesecundair_P22_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P22;         /* Expression: showOutputIndexFound
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P23_Size[2];
                                /* Computed Parameter: Cariagesecundair_P23_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P23;         /* Expression: showOutputLastPulse
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Cariagesecundair_P24_Size[2];
                                /* Computed Parameter: Cariagesecundair_P24_Size
                                 * Referenced by: '<S5>/Cariage secundair'
                                 */
  real_T Cariagesecundair_P24;         /* Expression: isDmaEnabled
                                        * Referenced by: '<S5>/Cariage secundair'
                                        */
  real_T Calibration4_Gain;            /* Expression: 1e-6
                                        * Referenced by: '<S5>/Calibration4'
                                        */
  real_T Gain8_Gain_l;                 /* Expression: -1
                                        * Referenced by: '<S5>/Gain8'
                                        */
  real_T GantryX1secundair_P1_Size[2];
                                /* Computed Parameter: GantryX1secundair_P1_Size
                                 * Referenced by: '<S5>/Gantry X1 secundair'
                                 */
  real_T GantryX1secundair_P1;         /* Expression: boardType
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P2_Size[2];
                                /* Computed Parameter: GantryX1secundair_P2_Size
                                 * Referenced by: '<S5>/Gantry X1 secundair'
                                 */
  real_T GantryX1secundair_P2;         /* Expression: fpgaFrequency
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P3_Size[2];
                                /* Computed Parameter: GantryX1secundair_P3_Size
                                 * Referenced by: '<S5>/Gantry X1 secundair'
                                 */
  real_T GantryX1secundair_P3;         /* Expression: id
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P4_Size[2];
                                /* Computed Parameter: GantryX1secundair_P4_Size
                                 * Referenced by: '<S5>/Gantry X1 secundair'
                                 */
  real_T GantryX1secundair_P4;         /* Expression: chan
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P5_Size[2];
                                /* Computed Parameter: GantryX1secundair_P5_Size
                                 * Referenced by: '<S5>/Gantry X1 secundair'
                                 */
  real_T GantryX1secundair_P5;         /* Expression: sampleTime
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P6_Size[2];
                                /* Computed Parameter: GantryX1secundair_P6_Size
                                 * Referenced by: '<S5>/Gantry X1 secundair'
                                 */
  real_T GantryX1secundair_P6;         /* Expression: pciSlot
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P7_Size[2];
                                /* Computed Parameter: GantryX1secundair_P7_Size
                                 * Referenced by: '<S5>/Gantry X1 secundair'
                                 */
  real_T GantryX1secundair_P7;         /* Expression: numOfSlots
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P8_Size[2];
                                /* Computed Parameter: GantryX1secundair_P8_Size
                                 * Referenced by: '<S5>/Gantry X1 secundair'
                                 */
  real_T GantryX1secundair_P8;         /* Expression: sensorType
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P9_Size[2];
                                /* Computed Parameter: GantryX1secundair_P9_Size
                                 * Referenced by: '<S5>/Gantry X1 secundair'
                                 */
  real_T GantryX1secundair_P9;         /* Expression: interpolatePosition
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P10_Size[2];
                               /* Computed Parameter: GantryX1secundair_P10_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P10;        /* Expression: swapAB
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P11_Size[2];
                               /* Computed Parameter: GantryX1secundair_P11_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P11;        /* Expression: indexControlMode
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P12_Size[2];
                               /* Computed Parameter: GantryX1secundair_P12_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P12;        /* Expression: latchMode
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P13_Size[2];
                               /* Computed Parameter: GantryX1secundair_P13_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P13;        /* Expression: gateIndex
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P14_Size[2];
                               /* Computed Parameter: GantryX1secundair_P14_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P14;        /* Expression: speedFilterWidth
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P15_Size[2];
                               /* Computed Parameter: GantryX1secundair_P15_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P15;        /* Expression: showInputSpeedFilterWidth
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P16_Size[2];
                               /* Computed Parameter: GantryX1secundair_P16_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P16;        /* Expression: glitchFilterSeconds
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P17_Size[2];
                               /* Computed Parameter: GantryX1secundair_P17_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P17;        /* Expression: showInputClearPosition
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P18_Size[2];
                               /* Computed Parameter: GantryX1secundair_P18_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P18;        /* Expression: showInputClearIndexFound
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P19_Size[2];
                               /* Computed Parameter: GantryX1secundair_P19_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P19;        /* Expression: showOutputPosition
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P20_Size[2];
                               /* Computed Parameter: GantryX1secundair_P20_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P20;        /* Expression: showOutputTurn
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P21_Size[2];
                               /* Computed Parameter: GantryX1secundair_P21_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P21;        /* Expression: showOutputSpeed
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P22_Size[2];
                               /* Computed Parameter: GantryX1secundair_P22_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P22;        /* Expression: showOutputIndexFound
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P23_Size[2];
                               /* Computed Parameter: GantryX1secundair_P23_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P23;        /* Expression: showOutputLastPulse
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T GantryX1secundair_P24_Size[2];
                               /* Computed Parameter: GantryX1secundair_P24_Size
                                * Referenced by: '<S5>/Gantry X1 secundair'
                                */
  real_T GantryX1secundair_P24;        /* Expression: isDmaEnabled
                                        * Referenced by: '<S5>/Gantry X1 secundair'
                                        */
  real_T Calibration5_Gain;            /* Expression: 1e-6
                                        * Referenced by: '<S5>/Calibration5'
                                        */
  real_T Gain9_Gain_j;                 /* Expression: -1
                                        * Referenced by: '<S5>/Gain9'
                                        */
  real_T GentryX2secundair_P1_Size[2];
                                /* Computed Parameter: GentryX2secundair_P1_Size
                                 * Referenced by: '<S5>/Gentry X2 secundair'
                                 */
  real_T GentryX2secundair_P1;         /* Expression: boardType
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P2_Size[2];
                                /* Computed Parameter: GentryX2secundair_P2_Size
                                 * Referenced by: '<S5>/Gentry X2 secundair'
                                 */
  real_T GentryX2secundair_P2;         /* Expression: fpgaFrequency
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P3_Size[2];
                                /* Computed Parameter: GentryX2secundair_P3_Size
                                 * Referenced by: '<S5>/Gentry X2 secundair'
                                 */
  real_T GentryX2secundair_P3;         /* Expression: id
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P4_Size[2];
                                /* Computed Parameter: GentryX2secundair_P4_Size
                                 * Referenced by: '<S5>/Gentry X2 secundair'
                                 */
  real_T GentryX2secundair_P4;         /* Expression: chan
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P5_Size[2];
                                /* Computed Parameter: GentryX2secundair_P5_Size
                                 * Referenced by: '<S5>/Gentry X2 secundair'
                                 */
  real_T GentryX2secundair_P5;         /* Expression: sampleTime
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P6_Size[2];
                                /* Computed Parameter: GentryX2secundair_P6_Size
                                 * Referenced by: '<S5>/Gentry X2 secundair'
                                 */
  real_T GentryX2secundair_P6;         /* Expression: pciSlot
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P7_Size[2];
                                /* Computed Parameter: GentryX2secundair_P7_Size
                                 * Referenced by: '<S5>/Gentry X2 secundair'
                                 */
  real_T GentryX2secundair_P7;         /* Expression: numOfSlots
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P8_Size[2];
                                /* Computed Parameter: GentryX2secundair_P8_Size
                                 * Referenced by: '<S5>/Gentry X2 secundair'
                                 */
  real_T GentryX2secundair_P8;         /* Expression: sensorType
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P9_Size[2];
                                /* Computed Parameter: GentryX2secundair_P9_Size
                                 * Referenced by: '<S5>/Gentry X2 secundair'
                                 */
  real_T GentryX2secundair_P9;         /* Expression: interpolatePosition
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P10_Size[2];
                               /* Computed Parameter: GentryX2secundair_P10_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P10;        /* Expression: swapAB
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P11_Size[2];
                               /* Computed Parameter: GentryX2secundair_P11_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P11;        /* Expression: indexControlMode
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P12_Size[2];
                               /* Computed Parameter: GentryX2secundair_P12_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P12;        /* Expression: latchMode
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P13_Size[2];
                               /* Computed Parameter: GentryX2secundair_P13_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P13;        /* Expression: gateIndex
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P14_Size[2];
                               /* Computed Parameter: GentryX2secundair_P14_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P14;        /* Expression: speedFilterWidth
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P15_Size[2];
                               /* Computed Parameter: GentryX2secundair_P15_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P15;        /* Expression: showInputSpeedFilterWidth
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P16_Size[2];
                               /* Computed Parameter: GentryX2secundair_P16_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P16;        /* Expression: glitchFilterSeconds
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P17_Size[2];
                               /* Computed Parameter: GentryX2secundair_P17_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P17;        /* Expression: showInputClearPosition
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P18_Size[2];
                               /* Computed Parameter: GentryX2secundair_P18_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P18;        /* Expression: showInputClearIndexFound
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P19_Size[2];
                               /* Computed Parameter: GentryX2secundair_P19_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P19;        /* Expression: showOutputPosition
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P20_Size[2];
                               /* Computed Parameter: GentryX2secundair_P20_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P20;        /* Expression: showOutputTurn
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P21_Size[2];
                               /* Computed Parameter: GentryX2secundair_P21_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P21;        /* Expression: showOutputSpeed
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P22_Size[2];
                               /* Computed Parameter: GentryX2secundair_P22_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P22;        /* Expression: showOutputIndexFound
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P23_Size[2];
                               /* Computed Parameter: GentryX2secundair_P23_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P23;        /* Expression: showOutputLastPulse
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T GentryX2secundair_P24_Size[2];
                               /* Computed Parameter: GentryX2secundair_P24_Size
                                * Referenced by: '<S5>/Gentry X2 secundair'
                                */
  real_T GentryX2secundair_P24;        /* Expression: isDmaEnabled
                                        * Referenced by: '<S5>/Gentry X2 secundair'
                                        */
  real_T Calibration6_Gain;            /* Expression: 1e-6
                                        * Referenced by: '<S5>/Calibration6'
                                        */
  real_T Gain10_Gain_n;                /* Expression: 1
                                        * Referenced by: '<S5>/Gain10'
                                        */
  real_T DILimitCarriagesecundairwerktni[2];
                          /* Computed Parameter: DILimitCarriagesecundairwerktni
                           * Referenced by: '<S5>/DI Limit Carriage secundair (werkt niet)'
                           */
  real_T DILimitCarriagesecundairwerkt_a;/* Expression: boardType
                                          * Referenced by: '<S5>/DI Limit Carriage secundair (werkt niet)'
                                          */
  real_T DILimitCarriagesecundairwerkt_f[2];
                          /* Computed Parameter: DILimitCarriagesecundairwerkt_f
                           * Referenced by: '<S5>/DI Limit Carriage secundair (werkt niet)'
                           */
  real_T DILimitCarriagesecundairwerkt_n;/* Expression: id
                                          * Referenced by: '<S5>/DI Limit Carriage secundair (werkt niet)'
                                          */
  real_T DILimitCarriagesecundairwerkt_i[2];
                          /* Computed Parameter: DILimitCarriagesecundairwerkt_i
                           * Referenced by: '<S5>/DI Limit Carriage secundair (werkt niet)'
                           */
  real_T DILimitCarriagesecundairwerk_ix;/* Expression: chan
                                          * Referenced by: '<S5>/DI Limit Carriage secundair (werkt niet)'
                                          */
  real_T DILimitCarriagesecundairwerkt_d[2];
                          /* Computed Parameter: DILimitCarriagesecundairwerkt_d
                           * Referenced by: '<S5>/DI Limit Carriage secundair (werkt niet)'
                           */
  real_T DILimitCarriagesecundairwerk_nn;/* Expression: vectorizeOutput
                                          * Referenced by: '<S5>/DI Limit Carriage secundair (werkt niet)'
                                          */
  real_T DILimitCarriagesecundairwerkt_k[2];
                          /* Computed Parameter: DILimitCarriagesecundairwerkt_k
                           * Referenced by: '<S5>/DI Limit Carriage secundair (werkt niet)'
                           */
  real_T DILimitCarriagesecundairwerkt_g;/* Expression: ts
                                          * Referenced by: '<S5>/DI Limit Carriage secundair (werkt niet)'
                                          */
  real_T DILimitCarriagesecundairwerkt_m[2];
                          /* Computed Parameter: DILimitCarriagesecundairwerkt_m
                           * Referenced by: '<S5>/DI Limit Carriage secundair (werkt niet)'
                           */
  real_T DILimitCarriagesecundairwerkt_l;/* Expression: pciSlot
                                          * Referenced by: '<S5>/DI Limit Carriage secundair (werkt niet)'
                                          */
  real_T DILimitGantryx1secundairGantryx[2];
                          /* Computed Parameter: DILimitGantryx1secundairGantryx
                           * Referenced by: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
                           */
  real_T DILimitGantryx1secundairGantr_d;/* Expression: boardType
                                          * Referenced by: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
                                          */
  real_T DILimitGantryx1secundairGantr_p[2];
                          /* Computed Parameter: DILimitGantryx1secundairGantr_p
                           * Referenced by: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
                           */
  real_T DILimitGantryx1secundairGantr_n;/* Expression: id
                                          * Referenced by: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
                                          */
  real_T DILimitGantryx1secundairGantr_f[2];
                          /* Computed Parameter: DILimitGantryx1secundairGantr_f
                           * Referenced by: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
                           */
  real_T DILimitGantryx1secundairGantr_b;/* Expression: chan
                                          * Referenced by: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
                                          */
  real_T DILimitGantryx1secundairGant_ne[2];
                          /* Computed Parameter: DILimitGantryx1secundairGant_ne
                           * Referenced by: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
                           */
  real_T DILimitGantryx1secundairGant_ns;/* Expression: vectorizeOutput
                                          * Referenced by: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
                                          */
  real_T DILimitGantryx1secundairGantr_i[2];
                          /* Computed Parameter: DILimitGantryx1secundairGantr_i
                           * Referenced by: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
                           */
  real_T DILimitGantryx1secundairGant_du;/* Expression: ts
                                          * Referenced by: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
                                          */
  real_T DILimitGantryx1secundairGantr_g[2];
                          /* Computed Parameter: DILimitGantryx1secundairGantr_g
                           * Referenced by: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
                           */
  real_T DILimitGantryx1secundairGant_ir;/* Expression: pciSlot
                                          * Referenced by: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)'
                                          */
  real_T DILimitGantryx2secundairGantryx[2];
                          /* Computed Parameter: DILimitGantryx2secundairGantryx
                           * Referenced by: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
                           */
  real_T DILimitGantryx2secundairGantr_d;/* Expression: boardType
                                          * Referenced by: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
                                          */
  real_T DILimitGantryx2secundairGantr_p[2];
                          /* Computed Parameter: DILimitGantryx2secundairGantr_p
                           * Referenced by: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
                           */
  real_T DILimitGantryx2secundairGantr_f;/* Expression: id
                                          * Referenced by: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
                                          */
  real_T DILimitGantryx2secundairGantr_m[2];
                          /* Computed Parameter: DILimitGantryx2secundairGantr_m
                           * Referenced by: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
                           */
  real_T DILimitGantryx2secundairGantr_o;/* Expression: chan
                                          * Referenced by: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
                                          */
  real_T DILimitGantryx2secundairGantr_k[2];
                          /* Computed Parameter: DILimitGantryx2secundairGantr_k
                           * Referenced by: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
                           */
  real_T DILimitGantryx2secundairGantr_a;/* Expression: vectorizeOutput
                                          * Referenced by: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
                                          */
  real_T DILimitGantryx2secundairGant_p4[2];
                          /* Computed Parameter: DILimitGantryx2secundairGant_p4
                           * Referenced by: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
                           */
  real_T DILimitGantryx2secundairGantr_l;/* Expression: ts
                                          * Referenced by: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
                                          */
  real_T DILimitGantryx2secundairGant_o0[2];
                          /* Computed Parameter: DILimitGantryx2secundairGant_o0
                           * Referenced by: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
                           */
  real_T DILimitGantryx2secundairGant_dj;/* Expression: pciSlot
                                          * Referenced by: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)'
                                          */
  real_T startHoming_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/startHoming'
                                        */
  real_T startTrial_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/startTrial'
                                        */
  real_T startPenholder_Value;         /* Expression: 0
                                        * Referenced by: '<Root>/startPenholder'
                                        */
  real_T PenColor_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/PenColor'
                                        */
  real_T Switch_Threshold_l;           /* Expression: 0
                                        * Referenced by: '<S19>/Switch'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 0
                                        * Referenced by: '<S20>/Switch'
                                        */
  real_T Switch_Threshold_o;           /* Expression: 0
                                        * Referenced by: '<S21>/Switch'
                                        */
  real_T log_jogspeed_Gain;            /* Expression: 1
                                        * Referenced by: '<S9>/log_jogspeed'
                                        */
  real_T Gainonphi2_Gain;              /* Expression: 0.07
                                        * Referenced by: '<S9>/Gain on phi2'
                                        */
  real_T dutycycleblockwave_Value;     /* Expression: 20
                                        * Referenced by: '<S35>/dutycycle blockwave'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 1/0.00396875
                                        * Referenced by: '<S35>/Gain1'
                                        */
  real_T basefreq_Value;               /* Expression: 80e6
                                        * Referenced by: '<S35>/basefreq'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 0.01
                                        * Referenced by: '<S35>/Gain'
                                        */
  real_T PWM1_Value;                   /* Expression: 1
                                        * Referenced by: '<S35>/PWM1'
                                        */
  real_T Gain8_Gain_e;                 /* Expression: 1
                                        * Referenced by: '<S35>/Gain8'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S35>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S35>/Saturation2'
                                        */
  real_T Gainonphi3_Gain;              /* Expression: 1
                                        * Referenced by: '<S9>/Gain on phi3'
                                        */
  real_T dutycycleblockwave_Value_h;   /* Expression: 20
                                        * Referenced by: '<S38>/dutycycle blockwave'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 1/0.00396875
                                        * Referenced by: '<S38>/Gain1'
                                        */
  real_T basefreq_Value_i;             /* Expression: 80e6
                                        * Referenced by: '<S38>/basefreq'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 0.01
                                        * Referenced by: '<S38>/Gain'
                                        */
  real_T PWM1_Value_l;                 /* Expression: 1
                                        * Referenced by: '<S38>/PWM1'
                                        */
  real_T Gain8_Gain_c;                 /* Expression: 1
                                        * Referenced by: '<S38>/Gain8'
                                        */
  real_T Saturation2_UpperSat_m;       /* Expression: 1
                                        * Referenced by: '<S38>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_e;       /* Expression: 0
                                        * Referenced by: '<S38>/Saturation2'
                                        */
  boolean_T trialDone_Y0;              /* Computed Parameter: trialDone_Y0
                                        * Referenced by: '<S11>/trialDone'
                                        */
  boolean_T Delay_InitialCondition_g;
                                 /* Computed Parameter: Delay_InitialCondition_g
                                  * Referenced by: '<S11>/Delay'
                                  */
};

/* Storage class 'PageSwitching' */
extern Arizona_base_GOAT_cal_type Arizona_base_GOAT_cal_impl;
extern Arizona_base_GOAT_cal_type *Arizona_base_GOAT_cal;

#endif                                 /* RTW_HEADER_Arizona_base_GOAT_cal_h_ */
