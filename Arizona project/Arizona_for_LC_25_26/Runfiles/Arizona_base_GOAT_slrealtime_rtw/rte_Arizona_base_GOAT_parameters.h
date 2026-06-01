#ifndef _RTE_ARIZONA_BASE_GOAT_PARAMETERS_H
#define _RTE_ARIZONA_BASE_GOAT_PARAMETERS_H
#include "rtwtypes.h"
#include "SegmentInfo.hpp"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Arizona_base_GOAT_types.h"

struct RTE_Param_Service_T {
  real_T N_Init;
  real_T Nref;
  real_T Ts;
  real_T phi_Init[3493];
  real_T x_Init[3117];
  real_T y_Init[3493];
};

extern RTE_Param_Service_T RTE_Param_Service;
extern RTE_Param_Service_T *RTE_Param_Service_ptr;
real_T* get_N_Init(void);
real_T* get_Nref(void);
real_T* get_Ts(void);
real_T* get_phi_Init(void);
real_T* get_x_Init(void);
real_T* get_y_Init(void);
namespace slrealtime
{
  SegmentVector &getSegmentVector(void);
}                                      // slrealtime

#endif
