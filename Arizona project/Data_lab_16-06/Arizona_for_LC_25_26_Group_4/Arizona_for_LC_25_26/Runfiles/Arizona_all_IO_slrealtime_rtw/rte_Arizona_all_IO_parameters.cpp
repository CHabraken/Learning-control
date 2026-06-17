#include "rte_Arizona_all_IO_parameters.h"
#include "Arizona_all_IO.h"
#include "Arizona_all_IO_cal.h"

extern Arizona_all_IO_cal_type Arizona_all_IO_cal_impl;
namespace slrealtime
{
  /* Description of SEGMENTS */
  SegmentVector segmentInfo {
    { (void*)&Arizona_all_IO_cal_impl, (void**)&Arizona_all_IO_cal, sizeof
      (Arizona_all_IO_cal_type), 2 }
  };

  SegmentVector &getSegmentVector(void)
  {
    return segmentInfo;
  }
}                                      // slrealtime
