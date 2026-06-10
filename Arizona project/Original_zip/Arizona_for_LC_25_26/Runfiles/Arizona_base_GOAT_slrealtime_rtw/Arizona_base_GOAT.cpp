/*
 * Arizona_base_GOAT.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Arizona_base_GOAT".
 *
 * Model version              : 12.234
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C++ source code generated on : Fri May 22 15:33:26 2026
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Arizona_base_GOAT.h"
#include "rtwtypes.h"
#include "Arizona_base_GOAT_cal.h"
#include "rte_Arizona_base_GOAT_parameters.h"

extern "C" {

#include "rt_nonfinite.h"

}
#include "Arizona_base_GOAT_private.h"
#include <cmath>
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S16>/Supervisor' */
const uint32_T Arizona__IN_MoveToLimitSwitches = 2U;
const uint32_T Arizona_ba_IN_enablePointToRefs = 4U;
const uint32_T Arizona_ba_IN_increase_jogspeed = 1U;
const int32_T Arizona_base_GOAT_CALL_EVENT = -1;
const uint32_T Arizona_base_GOAT_IN_PEN_READY = 3U;
const uint32_T Arizona_base_GOAT_IN_stop = 2U;
const uint32_T Arizona_base_GOA_IN_MOVE_PEN_UP = 1U;
const uint8_T Arizona_base_IN_NO_ACTIVE_CHILD = 0U;

/* Named constants for Chart: '<S9>/Change color Chart' */
const uint32_T Arizona_base_GOAT_IN_ALREADY_UP = 2U;
const uint32_T Arizona_base_GOAT_IN_ARRIVAL = 1U;
const uint32_T Arizona_base_GOAT_IN_DEPARTURE = 3U;
const uint32_T Arizona_base_GOAT_IN_DONE = 1U;
const uint32_T Arizona_base_GOAT_IN_DOWN = 3U;
const uint32_T Arizona_base_GOAT_IN_FINISHED = 1U;
const uint32_T Arizona_base_GOAT_IN_GOING_DOWN = 2U;
const uint32_T Arizona_base_GOAT_IN_GOING_UP = 3U;
const uint32_T Arizona_base_GOAT_IN_HOMING = 4U;
const uint32_T Arizona_base_GOAT_IN_IDLE = 5U;
const uint32_T Arizona_base_GOAT_IN_IDLE_c = 4U;
const uint32_T Arizona_base_GOAT_IN_INITIAL = 6U;
const uint32_T Arizona_base_GOAT_IN_INITIALIZE = 6U;
const uint32_T Arizona_base_GOAT_IN_INITIAL_j = 4U;
const uint32_T Arizona_base_GOAT_IN_INITIAL_jz = 5U;
const uint32_T Arizona_base_GOAT_IN_MOVING_UP = 6U;
const uint32_T Arizona_base_GOAT_IN_ROTATE = 4U;
const uint32_T Arizona_base_GOAT_IN_ROTATING = 7U;
const uint32_T Arizona_base_GOAT_IN_UP = 7U;
const uint32_T Arizona_base_GOAT_IN_UP_b = 5U;
const int32_T Arizona_base_GOAT_event_go_down = 0;
const int32_T Arizona_base_GOAT_event_go_up = 1;
const int32_T Arizona_base_GOAT_event_is_down = 3;
const int32_T Arizona_base_GOAT_event_is_up = 4;
const uint32_T Arizona_base_GOA_IN_INITIAL_jzy = 2U;
const uint32_T Arizona_base_GOA_IN_MOVING_DOWN = 5U;
const uint32_T Arizona_base_GOA_IN_MOVING_UP_j = 3U;
const uint32_T Arizona_base_GO_IN_ALREADY_DOWN = 1U;
const uint32_T Arizona_base_GO_IN_CHECK_ROTATE = 2U;
const uint32_T Arizona_base__IN_MOVE_PENHOLDER = 1U;
const int32_T Arizona_base__event_homing_done = 2;
const int32_T Arizona_base__event_rotate_done = 5;
const int32_T Arizona_base_event_start_homing = 6;
const int32_T Arizona_base_event_start_rotate = 7;

/* Named constants for Chart: '<S10>/Supervisor' */
const uint32_T Arizona__IN_stop_carriageAirbag = 4U;
const uint32_T Arizona_ba_IN_stop_gantryAirbag = 4U;
const uint32_T Arizona_base_GOAT_IN_backAirbag = 1U;
const uint32_T Arizona_base_GOAT_IN_errorStop = 2U;
const uint32_T Arizona_base_GOAT_IN_leftAirbag = 2U;
const uint32_T Arizona_base_GOA_IN_frontAirbag = 3U;
const uint32_T Arizona_base_GOA_IN_rightAirbag = 3U;
const uint32_T Arizona_base_GO_IN_defaultState = 2U;
const uint32_T Arizona_base_GO_IN_stopCarriage = 2U;
const uint32_T Arizona_base__IN_defaultState_m = 1U;
const uint32_T Arizona_base__IN_evaluateSatefy = 1U;

/* Named constants for Chart: '<Root>/Trial control without penholder' */
const uint32_T Arizona_base_GOAT_IN_Home = 1U;
const uint32_T Arizona_base_GOAT_IN_idle = 2U;
const uint32_T Arizona_base_GOAT_IN_trial = 3U;

/* Block signals (default storage) */
B_Arizona_base_GOAT_T Arizona_base_GOAT_B;

/* Block states (default storage) */
DW_Arizona_base_GOAT_T Arizona_base_GOAT_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Arizona_base_GOAT_T Arizona_base_GOAT_PrevZCX;

/* Real-time model */
RT_MODEL_Arizona_base_GOAT_T Arizona_base_GOAT_M_ = RT_MODEL_Arizona_base_GOAT_T
  ();
RT_MODEL_Arizona_base_GOAT_T *const Arizona_base_GOAT_M = &Arizona_base_GOAT_M_;

/* Forward declaration for local functions */
static void Arizona_base_GOAT_ROTATION(void);
static void Arizona_base_GOAT_HOME(void);
static void Arizona_base_GOAT_VERTICAL(void);
static void Arizona_base_GOAT_MAIN(void);
real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

/* Function for Chart: '<S9>/Change color Chart' */
static void Arizona_base_GOAT_ROTATION(void)
{
  boolean_T guard1 = false;

  /* During 'ROTATION': '<S31>:356' */
  guard1 = false;
  switch (Arizona_base_GOAT_DW.is_ROTATION) {
   case Arizona_base_GOAT_IN_ARRIVAL:
    {
      boolean_T out;

      /* During 'ARRIVAL': '<S31>:351' */
      out = ((Arizona_base_GOAT_DW.counter == 0.0) &&
             (Arizona_base_GOAT_B.Switch1_hm == 7.0));
      if (out) {
        int32_T c_previousEvent;

        /* Transition: '<S31>:385' */
        c_previousEvent = Arizona_base_GOAT_DW.sfEvent_l;
        Arizona_base_GOAT_DW.sfEvent_l = Arizona_base__event_rotate_done;
        if (Arizona_base_GOAT_DW.is_active_MAIN != 0U) {
          Arizona_base_GOAT_MAIN();
        }

        Arizona_base_GOAT_DW.sfEvent_l = c_previousEvent;
        if (Arizona_base_GOAT_DW.is_ROTATION == Arizona_base_GOAT_IN_ARRIVAL) {
          Arizona_base_GOAT_DW.color_pos = 1.0;
        }

        if (Arizona_base_GOAT_DW.is_ROTATION != Arizona_base_GOAT_IN_ARRIVAL) {
        } else {
          guard1 = true;
        }
      } else {
        out = ((Arizona_base_GOAT_DW.counter == 0.0) &&
               (Arizona_base_GOAT_B.Switch1_hm != 7.0));
        if (out) {
          int32_T c_previousEvent;

          /* Transition: '<S31>:353' */
          c_previousEvent = Arizona_base_GOAT_DW.sfEvent_l;
          Arizona_base_GOAT_DW.sfEvent_l = Arizona_base__event_rotate_done;
          if (Arizona_base_GOAT_DW.is_active_MAIN != 0U) {
            Arizona_base_GOAT_MAIN();
          }

          Arizona_base_GOAT_DW.sfEvent_l = c_previousEvent;
          if (Arizona_base_GOAT_DW.is_ROTATION != Arizona_base_GOAT_IN_ARRIVAL)
          {
          } else {
            guard1 = true;
          }
        } else if (Arizona_base_GOAT_DW.counter != 0.0) {
          real_T u;

          /* Transition: '<S31>:344' */
          Arizona_base_GOAT_DW.is_ROTATION = Arizona_base_GOAT_IN_DEPARTURE;
          Arizona_base_GOAT_DW.temporalCounter_i2 = 0U;

          /* Entry 'DEPARTURE': '<S31>:347' */
          Arizona_base_GOAT_B.jogspeed_Theta = Arizona_base_GOAT_DW.counter;
          u = Arizona_base_GOAT_B.jogspeed_Theta;
          if (rtIsNaN(u)) {
            Arizona_base_GOAT_B.jogspeed_Theta = u;
          } else if (u < 0.0) {
            Arizona_base_GOAT_B.jogspeed_Theta = -1.0;
          } else {
            Arizona_base_GOAT_B.jogspeed_Theta = (u > 0.0);
          }
        }
      }
    }
    break;

   case Arizona_base_GO_IN_CHECK_ROTATE:
    {
      /* During 'CHECK_ROTATE': '<S31>:358' */
      if (Arizona_base_GOAT_DW.counter != 0.0) {
        real_T u;

        /* Transition: '<S31>:349' */
        Arizona_base_GOAT_DW.is_ROTATION = Arizona_base_GOAT_IN_DEPARTURE;
        Arizona_base_GOAT_DW.temporalCounter_i2 = 0U;

        /* Entry 'DEPARTURE': '<S31>:347' */
        Arizona_base_GOAT_B.jogspeed_Theta = Arizona_base_GOAT_DW.counter;
        u = Arizona_base_GOAT_B.jogspeed_Theta;
        if (rtIsNaN(u)) {
          Arizona_base_GOAT_B.jogspeed_Theta = u;
        } else if (u < 0.0) {
          Arizona_base_GOAT_B.jogspeed_Theta = -1.0;
        } else {
          Arizona_base_GOAT_B.jogspeed_Theta = (u > 0.0);
        }
      }
    }
    break;

   case Arizona_base_GOAT_IN_DEPARTURE:
    {
      boolean_T out;

      /* During 'DEPARTURE': '<S31>:347' */
      out = ((Arizona_base_GOAT_DW.temporalCounter_i2 >= 1000U) &&
             (Arizona_base_GOAT_B.DataTypeConversion3 == 1.0));
      if (out) {
        real_T u;

        /* Transition: '<S31>:345' */
        Arizona_base_GOAT_DW.is_ROTATION = Arizona_base_GOAT_IN_ARRIVAL;

        /* Entry 'ARRIVAL': '<S31>:351' */
        u = Arizona_base_GOAT_DW.counter;
        if (!rtIsNaN(u)) {
          if (u < 0.0) {
            u = -1.0;
          } else {
            u = (u > 0.0);
          }
        }

        Arizona_base_GOAT_DW.counter -= u;
        Arizona_base_GOAT_DW.color_pos = Arizona_base_GOAT_B.Switch1_hm;
      }
    }
    break;

   case Arizona_base_GOAT_IN_IDLE_c:
    /* During 'IDLE': '<S31>:352' */
    if (Arizona_base_GOAT_DW.sfEvent_l == Arizona_base_event_start_rotate) {
      /* Transition: '<S31>:357' */
      Arizona_base_GOAT_DW.is_ROTATION = Arizona_base_GOAT_IN_INITIALIZE;

      /* Entry 'INITIALIZE': '<S31>:355' */
      Arizona_base_GOAT_DW.rot_change = Arizona_base_GOAT_B.Switch1_hm -
        Arizona_base_GOAT_DW.color_pos;
    }
    break;

   case Arizona_base_GOAT_IN_INITIAL_jz:
    /* During 'INITIAL': '<S31>:354' */
    if (Arizona_base_GOAT_DW.temporalCounter_i2 >= 100U) {
      /* Transition: '<S31>:346' */
      Arizona_base_GOAT_DW.is_ROTATION = Arizona_base_GOAT_IN_IDLE_c;

      /* Entry 'IDLE': '<S31>:352' */
      Arizona_base_GOAT_B.jogspeed_Theta = 0.0;
    }
    break;

   case Arizona_base_GOAT_IN_INITIALIZE:
    {
      boolean_T out;

      /* During 'INITIALIZE': '<S31>:355' */
      out = ((Arizona_base_GOAT_DW.rot_change >= -2.0) &&
             (Arizona_base_GOAT_DW.rot_change <= 2.0));
      if (out) {
        /* Transition: '<S31>:342' */
        Arizona_base_GOAT_DW.counter = Arizona_base_GOAT_DW.rot_change;
        Arizona_base_GOAT_DW.is_ROTATION = Arizona_base_GO_IN_CHECK_ROTATE;
      } else if (Arizona_base_GOAT_DW.rot_change == -3.0) {
        /* Transition: '<S31>:343' */
        Arizona_base_GOAT_DW.counter = 1.0;
        Arizona_base_GOAT_DW.is_ROTATION = Arizona_base_GO_IN_CHECK_ROTATE;
      } else if (Arizona_base_GOAT_DW.rot_change == 3.0) {
        /* Transition: '<S31>:348' */
        Arizona_base_GOAT_DW.counter = -1.0;
        Arizona_base_GOAT_DW.is_ROTATION = Arizona_base_GO_IN_CHECK_ROTATE;
      }
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    Arizona_base_GOAT_DW.is_ROTATION = Arizona_base_IN_NO_ACTIVE_CHILD;
    break;
  }

  if (guard1) {
    Arizona_base_GOAT_DW.is_ROTATION = Arizona_base_GOAT_IN_IDLE_c;

    /* Entry 'IDLE': '<S31>:352' */
    Arizona_base_GOAT_B.jogspeed_Theta = 0.0;
  }
}

/* Function for Chart: '<S9>/Change color Chart' */
static void Arizona_base_GOAT_HOME(void)
{
  /* During 'HOME': '<S31>:398' */
  switch (Arizona_base_GOAT_DW.is_HOME) {
   case Arizona_base_GOAT_IN_DONE:
    {
      int32_T b_previousEvent;

      /* During 'DONE': '<S31>:417' */
      /* Transition: '<S31>:406' */
      b_previousEvent = Arizona_base_GOAT_DW.sfEvent_l;
      Arizona_base_GOAT_DW.sfEvent_l = Arizona_base__event_homing_done;
      if (Arizona_base_GOAT_DW.is_active_MAIN != 0U) {
        Arizona_base_GOAT_MAIN();
      }

      Arizona_base_GOAT_DW.sfEvent_l = b_previousEvent;
      if (Arizona_base_GOAT_DW.is_HOME == Arizona_base_GOAT_IN_DONE) {
        Arizona_base_GOAT_DW.is_HOME = Arizona_base_GOA_IN_INITIAL_jzy;
      }
    }
    break;

   case Arizona_base_GOA_IN_INITIAL_jzy:
    /* During 'INITIAL': '<S31>:399' */
    if (Arizona_base_GOAT_DW.sfEvent_l == Arizona_base_event_start_homing) {
      /* Transition: '<S31>:402' */
      Arizona_base_GOAT_DW.is_HOME = Arizona_base_GOA_IN_MOVING_UP_j;

      /* Entry 'MOVING_UP': '<S31>:401' */
      Arizona_base_GOAT_B.jogspeed_Z = 1.0;
    }
    break;

   case Arizona_base_GOA_IN_MOVING_UP_j:
    /* During 'MOVING_UP': '<S31>:401' */
    if (Arizona_base_GOAT_B.DataTypeConversion2 == 1.0) {
      /* Transition: '<S31>:405' */
      Arizona_base_GOAT_DW.is_HOME = Arizona_base_GOAT_IN_UP_b;
      Arizona_base_GOAT_DW.temporalCounter_i3 = 0U;

      /* Entry 'UP': '<S31>:404' */
      Arizona_base_GOAT_B.jogspeed_Z = 0.0;
    }
    break;

   case Arizona_base_GOAT_IN_ROTATE:
    {
      boolean_T out;

      /* During 'ROTATE': '<S31>:415' */
      out = ((Arizona_base_GOAT_DW.temporalCounter_i3 >= 100U) &&
             (Arizona_base_GOAT_B.DataTypeConversion3 == 1.0));
      if (out) {
        /* Transition: '<S31>:419' */
        Arizona_base_GOAT_DW.is_HOME = Arizona_base_GOAT_IN_DONE;

        /* Entry 'DONE': '<S31>:417' */
        Arizona_base_GOAT_B.jogspeed_Theta = 0.0;
      }
    }
    break;

   case Arizona_base_GOAT_IN_UP_b:
    {
      /* During 'UP': '<S31>:404' */
      if (Arizona_base_GOAT_B.DataTypeConversion3 == 1.0) {
        /* Transition: '<S31>:416' */
        Arizona_base_GOAT_DW.is_HOME = Arizona_base_GOAT_IN_DONE;

        /* Entry 'DONE': '<S31>:417' */
        Arizona_base_GOAT_B.jogspeed_Theta = 0.0;
      } else {
        boolean_T out;
        out = ((Arizona_base_GOAT_DW.temporalCounter_i3 >= 100U) &&
               (Arizona_base_GOAT_B.DataTypeConversion3 != 1.0));
        if (out) {
          /* Transition: '<S31>:418' */
          Arizona_base_GOAT_DW.is_HOME = Arizona_base_GOAT_IN_ROTATE;
          Arizona_base_GOAT_DW.temporalCounter_i3 = 0U;

          /* Entry 'ROTATE': '<S31>:415' */
          Arizona_base_GOAT_B.jogspeed_Theta = 1.0;
        }
      }
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    Arizona_base_GOAT_DW.is_HOME = Arizona_base_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<S9>/Change color Chart' */
static void Arizona_base_GOAT_VERTICAL(void)
{
  /* During 'VERTICAL': '<S31>:228' */
  switch (Arizona_base_GOAT_DW.is_VERTICAL) {
   case Arizona_base_GO_IN_ALREADY_DOWN:
    {
      /* During 'ALREADY_DOWN': '<S31>:323' */
      if (Arizona_base_GOAT_DW.temporalCounter_i1_b >= 100U) {
        int32_T b_previousEvent;

        /* Transition: '<S31>:324' */
        b_previousEvent = Arizona_base_GOAT_DW.sfEvent_l;
        Arizona_base_GOAT_DW.sfEvent_l = Arizona_base_GOAT_event_is_down;
        if (Arizona_base_GOAT_DW.is_active_MAIN != 0U) {
          Arizona_base_GOAT_MAIN();
        }

        Arizona_base_GOAT_DW.sfEvent_l = b_previousEvent;
        if (Arizona_base_GOAT_DW.is_VERTICAL == Arizona_base_GO_IN_ALREADY_DOWN)
        {
          Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_GOAT_IN_DOWN;

          /* Entry 'DOWN': '<S31>:215' */
          Arizona_base_GOAT_B.jogspeed_Z = 0.0;
        }
      }
    }
    break;

   case Arizona_base_GOAT_IN_ALREADY_UP:
    {
      /* During 'ALREADY_UP': '<S31>:321' */
      if (Arizona_base_GOAT_DW.temporalCounter_i1_b >= 100U) {
        int32_T b_previousEvent;

        /* Transition: '<S31>:322' */
        b_previousEvent = Arizona_base_GOAT_DW.sfEvent_l;
        Arizona_base_GOAT_DW.sfEvent_l = Arizona_base_GOAT_event_is_up;
        if (Arizona_base_GOAT_DW.is_active_MAIN != 0U) {
          Arizona_base_GOAT_MAIN();
        }

        Arizona_base_GOAT_DW.sfEvent_l = b_previousEvent;
        if (Arizona_base_GOAT_DW.is_VERTICAL == Arizona_base_GOAT_IN_ALREADY_UP)
        {
          Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_GOAT_IN_UP;

          /* Entry 'UP': '<S31>:214' */
          Arizona_base_GOAT_B.jogspeed_Z = 0.0;
        }
      }
    }
    break;

   case Arizona_base_GOAT_IN_DOWN:
    /* During 'DOWN': '<S31>:215' */
    if (Arizona_base_GOAT_DW.sfEvent_l == Arizona_base_GOAT_event_go_up) {
      /* Transition: '<S31>:219' */
      Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_GOAT_IN_MOVING_UP;

      /* Entry 'MOVING_UP': '<S31>:217' */
      Arizona_base_GOAT_B.jogspeed_Z = 1.0;
    } else if (Arizona_base_GOAT_DW.sfEvent_l == Arizona_base_GOAT_event_go_down)
    {
      /* Transition: '<S31>:320' */
      Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_GO_IN_ALREADY_DOWN;
      Arizona_base_GOAT_DW.temporalCounter_i1_b = 0U;
    }
    break;

   case Arizona_base_GOAT_IN_INITIAL_j:
    /* During 'INITIAL': '<S31>:222' */
    if (Arizona_base_GOAT_DW.sfEvent_l == Arizona_base_GOAT_event_go_up) {
      /* Transition: '<S31>:223' */
      Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_GOAT_IN_MOVING_UP;

      /* Entry 'MOVING_UP': '<S31>:217' */
      Arizona_base_GOAT_B.jogspeed_Z = 1.0;
    } else if (Arizona_base_GOAT_DW.sfEvent_l == Arizona_base_GOAT_event_go_down)
    {
      /* Transition: '<S31>:224' */
      Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_GOA_IN_MOVING_DOWN;

      /* Entry 'MOVING_DOWN': '<S31>:216' */
      Arizona_base_GOAT_B.jogspeed_Z = -1.0;
    }
    break;

   case Arizona_base_GOA_IN_MOVING_DOWN:
    {
      /* During 'MOVING_DOWN': '<S31>:216' */
      if (Arizona_base_GOAT_B.DataTypeConversion1 == 1.0) {
        int32_T b_previousEvent;

        /* Transition: '<S31>:218' */
        b_previousEvent = Arizona_base_GOAT_DW.sfEvent_l;
        Arizona_base_GOAT_DW.sfEvent_l = Arizona_base_GOAT_event_is_down;
        if (Arizona_base_GOAT_DW.is_active_MAIN != 0U) {
          Arizona_base_GOAT_MAIN();
        }

        Arizona_base_GOAT_DW.sfEvent_l = b_previousEvent;
        if (Arizona_base_GOAT_DW.is_VERTICAL == Arizona_base_GOA_IN_MOVING_DOWN)
        {
          Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_GOAT_IN_DOWN;

          /* Entry 'DOWN': '<S31>:215' */
          Arizona_base_GOAT_B.jogspeed_Z = 0.0;
        }
      }
    }
    break;

   case Arizona_base_GOAT_IN_MOVING_UP:
    {
      /* During 'MOVING_UP': '<S31>:217' */
      if (Arizona_base_GOAT_B.DataTypeConversion2 == 1.0) {
        int32_T b_previousEvent;

        /* Transition: '<S31>:220' */
        b_previousEvent = Arizona_base_GOAT_DW.sfEvent_l;
        Arizona_base_GOAT_DW.sfEvent_l = Arizona_base_GOAT_event_is_up;
        if (Arizona_base_GOAT_DW.is_active_MAIN != 0U) {
          Arizona_base_GOAT_MAIN();
        }

        Arizona_base_GOAT_DW.sfEvent_l = b_previousEvent;
        if (Arizona_base_GOAT_DW.is_VERTICAL == Arizona_base_GOAT_IN_MOVING_UP)
        {
          Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_GOAT_IN_UP;

          /* Entry 'UP': '<S31>:214' */
          Arizona_base_GOAT_B.jogspeed_Z = 0.0;
        }
      }
    }
    break;

   case Arizona_base_GOAT_IN_UP:
    /* During 'UP': '<S31>:214' */
    if (Arizona_base_GOAT_DW.sfEvent_l == Arizona_base_GOAT_event_go_down) {
      /* Transition: '<S31>:221' */
      Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_GOA_IN_MOVING_DOWN;

      /* Entry 'MOVING_DOWN': '<S31>:216' */
      Arizona_base_GOAT_B.jogspeed_Z = -1.0;
    } else if (Arizona_base_GOAT_DW.sfEvent_l == Arizona_base_GOAT_event_go_up)
    {
      /* Transition: '<S31>:319' */
      Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_GOAT_IN_ALREADY_UP;
      Arizona_base_GOAT_DW.temporalCounter_i1_b = 0U;
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<S9>/Change color Chart' */
static void Arizona_base_GOAT_MAIN(void)
{
  /* During 'MAIN': '<S31>:274' */
  switch (Arizona_base_GOAT_DW.is_MAIN) {
   case Arizona_base_GOAT_IN_FINISHED:
    Arizona_base_GOAT_B.active = 0.0;

    /* During 'FINISHED': '<S31>:303' */
    /* Transition: '<S31>:304' */
    Arizona_base_GOAT_DW.is_MAIN = Arizona_base_GOAT_IN_IDLE;

    /* Entry 'IDLE': '<S31>:279' */
    break;

   case Arizona_base_GOAT_IN_GOING_DOWN:
    Arizona_base_GOAT_B.active = 1.0;

    /* During 'GOING_DOWN': '<S31>:281' */
    if (Arizona_base_GOAT_DW.sfEvent_l == Arizona_base_GOAT_event_is_down) {
      /* Transition: '<S31>:290' */
      Arizona_base_GOAT_DW.is_MAIN = Arizona_base_GOAT_IN_FINISHED;

      /* Entry 'FINISHED': '<S31>:303' */
      Arizona_base_GOAT_B.active = 0.0;
    }
    break;

   case Arizona_base_GOAT_IN_GOING_UP:
    {
      boolean_T out;
      Arizona_base_GOAT_B.active = 1.0;

      /* During 'GOING_UP': '<S31>:280' */
      out = ((Arizona_base_GOAT_DW.sfEvent_l == Arizona_base_GOAT_event_is_up) &&
             (Arizona_base_GOAT_DW.job == 5.0));
      if (out) {
        /* Transition: '<S31>:287' */
        Arizona_base_GOAT_DW.is_MAIN = Arizona_base_GOAT_IN_FINISHED;

        /* Entry 'FINISHED': '<S31>:303' */
        Arizona_base_GOAT_B.active = 0.0;
      } else {
        out = ((Arizona_base_GOAT_DW.sfEvent_l == Arizona_base_GOAT_event_is_up)
               && (Arizona_base_GOAT_DW.job != 5.0));
        if (out) {
          int32_T b_previousEvent;

          /* Transition: '<S31>:288' */
          b_previousEvent = Arizona_base_GOAT_DW.sfEvent_l;
          Arizona_base_GOAT_DW.sfEvent_l = Arizona_base_event_start_rotate;
          if (Arizona_base_GOAT_DW.is_active_ROTATION != 0U) {
            Arizona_base_GOAT_ROTATION();
          }

          Arizona_base_GOAT_DW.sfEvent_l = b_previousEvent;
          if (Arizona_base_GOAT_DW.is_MAIN == Arizona_base_GOAT_IN_GOING_UP) {
            Arizona_base_GOAT_DW.is_MAIN = Arizona_base_GOAT_IN_ROTATING;
          }
        }
      }
    }
    break;

   case Arizona_base_GOAT_IN_HOMING:
    /* During 'HOMING': '<S31>:407' */
    if (Arizona_base_GOAT_DW.sfEvent_l == Arizona_base__event_homing_done) {
      /* Transition: '<S31>:409' */
      Arizona_base_GOAT_DW.is_MAIN = Arizona_base_GOAT_IN_FINISHED;

      /* Entry 'FINISHED': '<S31>:303' */
      Arizona_base_GOAT_B.active = 0.0;
    }
    break;

   case Arizona_base_GOAT_IN_IDLE:
    {
      boolean_T out;

      /* During 'IDLE': '<S31>:279' */
      out = ((Arizona_base_GOAT_DW.job != Arizona_base_GOAT_B.Switch1_hm) &&
             (Arizona_base_GOAT_B.Switch1_hm != 0.0) &&
             (Arizona_base_GOAT_B.DataTypeConversionendtrial != 0.0) &&
             (Arizona_base_GOAT_B.Switch1_hm != 6.0));
      if (out) {
        int32_T b_previousEvent;

        /* Transition: '<S31>:284' */
        b_previousEvent = Arizona_base_GOAT_DW.sfEvent_l;
        Arizona_base_GOAT_DW.sfEvent_l = Arizona_base_GOAT_event_go_up;
        if (Arizona_base_GOAT_DW.is_active_VERTICAL != 0U) {
          Arizona_base_GOAT_VERTICAL();
        }

        Arizona_base_GOAT_DW.sfEvent_l = b_previousEvent;
        if (Arizona_base_GOAT_DW.is_MAIN == Arizona_base_GOAT_IN_IDLE) {
          Arizona_base_GOAT_DW.job = Arizona_base_GOAT_B.Switch1_hm;
          Arizona_base_GOAT_DW.is_MAIN = Arizona_base_GOAT_IN_GOING_UP;

          /* Entry 'GOING_UP': '<S31>:280' */
          Arizona_base_GOAT_B.active = 1.0;
        }
      } else {
        out = ((Arizona_base_GOAT_DW.job != Arizona_base_GOAT_B.Switch1_hm) &&
               (Arizona_base_GOAT_B.Switch1_hm == 6.0));
        if (out) {
          int32_T b_previousEvent;

          /* Transition: '<S31>:285' */
          b_previousEvent = Arizona_base_GOAT_DW.sfEvent_l;
          Arizona_base_GOAT_DW.sfEvent_l = Arizona_base_GOAT_event_go_down;
          if (Arizona_base_GOAT_DW.is_active_VERTICAL != 0U) {
            Arizona_base_GOAT_VERTICAL();
          }

          Arizona_base_GOAT_DW.sfEvent_l = b_previousEvent;
          if (Arizona_base_GOAT_DW.is_MAIN == Arizona_base_GOAT_IN_IDLE) {
            Arizona_base_GOAT_DW.job = Arizona_base_GOAT_B.Switch1_hm;
            Arizona_base_GOAT_DW.is_MAIN = Arizona_base_GOAT_IN_GOING_DOWN;

            /* Entry 'GOING_DOWN': '<S31>:281' */
            Arizona_base_GOAT_B.active = 1.0;
          }
        } else {
          out = ((Arizona_base_GOAT_DW.job != Arizona_base_GOAT_B.Switch1_hm) &&
                 (Arizona_base_GOAT_B.Switch1_hm == 0.0));
          if (out) {
            /* Transition: '<S31>:318' */
            Arizona_base_GOAT_DW.job = Arizona_base_GOAT_B.Switch1_hm;
            Arizona_base_GOAT_DW.is_MAIN = Arizona_base_GOAT_IN_IDLE;

            /* Entry 'IDLE': '<S31>:279' */
          } else {
            out = ((Arizona_base_GOAT_B.DataTypeConversionendtrial == 0.0) &&
                   (Arizona_base_GOAT_B.Switch1_hm == 5.0));
            if (out) {
              int32_T b_previousEvent;

              /* Transition: '<S31>:408' */
              b_previousEvent = Arizona_base_GOAT_DW.sfEvent_l;
              Arizona_base_GOAT_DW.sfEvent_l = Arizona_base_event_start_homing;
              if (Arizona_base_GOAT_DW.is_active_HOME != 0U) {
                Arizona_base_GOAT_HOME();
              }

              Arizona_base_GOAT_DW.sfEvent_l = b_previousEvent;
              if (Arizona_base_GOAT_DW.is_MAIN == Arizona_base_GOAT_IN_IDLE) {
                Arizona_base_GOAT_DW.is_MAIN = Arizona_base_GOAT_IN_HOMING;
              }
            }
          }
        }
      }
    }
    break;

   case Arizona_base_GOAT_IN_INITIAL:
    Arizona_base_GOAT_B.active = 0.0;

    /* During 'INITIAL': '<S31>:299' */
    /* Transition: '<S31>:302' */
    Arizona_base_GOAT_DW.is_MAIN = Arizona_base_GOAT_IN_IDLE;

    /* Entry 'IDLE': '<S31>:279' */
    break;

   case Arizona_base_GOAT_IN_ROTATING:
    {
      boolean_T out;

      /* During 'ROTATING': '<S31>:282' */
      out = ((Arizona_base_GOAT_DW.sfEvent_l == Arizona_base__event_rotate_done)
             && (Arizona_base_GOAT_DW.job != 7.0));
      if (out) {
        int32_T b_previousEvent;

        /* Transition: '<S31>:289' */
        b_previousEvent = Arizona_base_GOAT_DW.sfEvent_l;
        Arizona_base_GOAT_DW.sfEvent_l = Arizona_base_GOAT_event_go_down;
        if (Arizona_base_GOAT_DW.is_active_VERTICAL != 0U) {
          Arizona_base_GOAT_VERTICAL();
        }

        Arizona_base_GOAT_DW.sfEvent_l = b_previousEvent;
        if (Arizona_base_GOAT_DW.is_MAIN == Arizona_base_GOAT_IN_ROTATING) {
          Arizona_base_GOAT_DW.is_MAIN = Arizona_base_GOAT_IN_GOING_DOWN;

          /* Entry 'GOING_DOWN': '<S31>:281' */
          Arizona_base_GOAT_B.active = 1.0;
        }
      }
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    Arizona_base_GOAT_DW.is_MAIN = Arizona_base_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Model step function */
void Arizona_base_GOAT_step(void)
{
  real_T u0;
  real_T u1;
  real_T u2;
  int32_T tableOffset;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Arizona_base_GOAT_DW.Feedforward_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Arizona_base_GOAT_DW.Enabledsubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Arizona_base_GOAT_DW.Trajectory_SubsysRanBC);

  /* S-Function (sg_IO141_IO142_setup_s): '<S5>/Setup 1' */

  /* Level2 S-Function Block: '<S5>/Setup 1' (sg_IO141_IO142_setup_s) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_IO141_IO142_ad_s): '<S5>/Analog input 1' */

  /* Level2 S-Function Block: '<S5>/Analog input 1' (sg_IO141_IO142_ad_s) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Carriage ' */

  /* Level2 S-Function Block: '<S5>/DI Limit Carriage ' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Gantry x1 = Gantry xR' */

  /* Level2 S-Function Block: '<S5>/DI Limit Gantry x1 = Gantry xR' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Gantry x2 = Gantry xL' */

  /* Level2 S-Function Block: '<S5>/DI Limit Gantry x2 = Gantry xL' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<S5>/DI black software button' */

  /* Level2 S-Function Block: '<S5>/DI black software button' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[8];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<S5>/DI carriage amp. fault status' */

  /* Level2 S-Function Block: '<S5>/DI carriage amp. fault status' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[9];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<S5>/DI gantry x1 fault status' */

  /* Level2 S-Function Block: '<S5>/DI gantry x1 fault status' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[10];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<S5>/DI gantry x2 fault status' */

  /* Level2 S-Function Block: '<S5>/DI gantry x2 fault status' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[11];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<S5>/DI red software button' */

  /* Level2 S-Function Block: '<S5>/DI red software button' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[12];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S5>/Gain1' */
  Arizona_base_GOAT_B.AIcarriagevelocitymonitor =
    Arizona_base_GOAT_cal->Gain1_Gain * Arizona_base_GOAT_B.analogvelin;

  /* S-Function (sg_fpga_qad_sf_5): '<S5>/Carriage encoder' */

  /* Level2 S-Function Block: '<S5>/Carriage encoder' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[13];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S5>/Calibration1' */
  Arizona_base_GOAT_B.Calibration1 = Arizona_base_GOAT_cal->Calibration1_Gain *
    Arizona_base_GOAT_B.Carriageencoder;

  /* Gain: '<S5>/Gain5' */
  Arizona_base_GOAT_B.encodercarriage = Arizona_base_GOAT_cal->Gain5_Gain *
    Arizona_base_GOAT_B.Calibration1;

  /* S-Function (sg_fpga_qad_sf_5): '<S5>/Gantry x1 = Gantry xR' */

  /* Level2 S-Function Block: '<S5>/Gantry x1 = Gantry xR' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[14];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S5>/Calibration2' */
  Arizona_base_GOAT_B.Calibration2 = Arizona_base_GOAT_cal->Calibration2_Gain *
    Arizona_base_GOAT_B.Gantryx1GantryxR;

  /* Gain: '<S5>/Gain6' */
  Arizona_base_GOAT_B.encodergantryx1 = Arizona_base_GOAT_cal->Gain6_Gain *
    Arizona_base_GOAT_B.Calibration2;

  /* S-Function (sg_fpga_qad_sf_5): '<S5>/Gantry x2 = Gantry xL' */

  /* Level2 S-Function Block: '<S5>/Gantry x2 = Gantry xL' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[15];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S5>/Calibration3' */
  Arizona_base_GOAT_B.Calibration3 = Arizona_base_GOAT_cal->Calibration3_Gain *
    Arizona_base_GOAT_B.Gantryx2GantryxL;

  /* Gain: '<S5>/Gain7' */
  Arizona_base_GOAT_B.encodergantryx2 = Arizona_base_GOAT_cal->Gain7_Gain *
    Arizona_base_GOAT_B.Calibration3;

  /* Gain: '<S5>/Gain' */
  Arizona_base_GOAT_B.u_loopback_yV = Arizona_base_GOAT_cal->Gain_Gain *
    Arizona_base_GOAT_B.Analoginput1_o2;

  /* Logic: '<S5>/Logical Operator' */
  Arizona_base_GOAT_B.DIblacksofwarefunctionbutton =
    !(Arizona_base_GOAT_B.DIblacksoftwarebutton != 0.0);

  /* Delay: '<Root>/log_penholder_active' */
  Arizona_base_GOAT_B.penholderActive =
    Arizona_base_GOAT_DW.log_penholder_active_DSTATE;

  /* Delay: '<Root>/Delay2' */
  Arizona_base_GOAT_B.Delay2 = Arizona_base_GOAT_DW.Delay2_DSTATE;

  /* Outputs for Enabled SubSystem: '<S4>/Enabled subsystem' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (Arizona_base_GOAT_B.Delay2 > 0.0) {
    if (!Arizona_base_GOAT_DW.Enabledsubsystem_MODE) {
      /* InitializeConditions for Delay: '<S15>/Delay' */
      Arizona_base_GOAT_DW.Delay_DSTATE_m =
        Arizona_base_GOAT_cal->Delay_InitialCondition;

      /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator x2JogSpeed1' */
      Arizona_base_GOAT_DW.DiscreteTimeIntegratorx2JogSpee =
        Arizona_base_GOAT_cal->DiscreteTimeIntegratorx2JogSp_m;

      /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator x2JogSpeed' */
      Arizona_base_GOAT_DW.DiscreteTimeIntegratorx2JogSp_a =
        Arizona_base_GOAT_cal->DiscreteTimeIntegratorx2JogSp_e;

      /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator x1JogSpeed' */
      Arizona_base_GOAT_DW.DiscreteTimeIntegratorx1JogSpee =
        Arizona_base_GOAT_cal->DiscreteTimeIntegratorx1JogSp_k;

      /* SystemReset for Chart: '<S16>/Supervisor' */
      Arizona_base_GOAT_DW.temporalCounter_i1 = 0U;
      Arizona_base_GOAT_DW.is_active_reset_carriage = 0U;
      Arizona_base_GOAT_DW.is_reset_carriage = Arizona_base_IN_NO_ACTIVE_CHILD;
      Arizona_base_GOAT_DW.is_active_reset_gantryLeft = 0U;
      Arizona_base_GOAT_DW.is_reset_gantryLeft = Arizona_base_IN_NO_ACTIVE_CHILD;
      Arizona_base_GOAT_DW.is_active_reset_gantryright = 0U;
      Arizona_base_GOAT_DW.is_reset_gantryright =
        Arizona_base_IN_NO_ACTIVE_CHILD;
      Arizona_base_GOAT_DW.is_active_c7_Arizona_base_GOAT = 0U;
      Arizona_base_GOAT_DW.is_c7_Arizona_base_GOAT =
        Arizona_base_IN_NO_ACTIVE_CHILD;
      Arizona_base_GOAT_DW.Ts_l = *get_Ts();
      Arizona_base_GOAT_B.jogspeed_y_reset_d = -0.00025;
      Arizona_base_GOAT_B.jogspeed_xL_reset_j = -0.0001;
      Arizona_base_GOAT_B.jogspeed_xR_reset_f = -0.0001;
      Arizona_base_GOAT_B.resetDone = 0.0;
      Arizona_base_GOAT_B.change_color_j = 0.0;
      Arizona_base_GOAT_DW.Enabledsubsystem_MODE = true;
    }

    /* Delay: '<S15>/Delay' */
    Arizona_base_GOAT_B.Delay_l = Arizona_base_GOAT_DW.Delay_DSTATE_m;

    /* Chart: '<S16>/Supervisor' */
    if (Arizona_base_GOAT_DW.temporalCounter_i1 < 1023U) {
      Arizona_base_GOAT_DW.temporalCounter_i1 = static_cast<uint16_T>
        (Arizona_base_GOAT_DW.temporalCounter_i1 + 1U);
    }

    /* Gateway: Homing/Enabled subsystem/Reset/Supervisor */
    Arizona_base_GOAT_DW.sfEvent_h = Arizona_base_GOAT_CALL_EVENT;

    /* During: Homing/Enabled subsystem/Reset/Supervisor */
    if (Arizona_base_GOAT_DW.is_active_c7_Arizona_base_GOAT == 0U) {
      /* Entry: Homing/Enabled subsystem/Reset/Supervisor */
      Arizona_base_GOAT_DW.is_active_c7_Arizona_base_GOAT = 1U;

      /* Entry Internal: Homing/Enabled subsystem/Reset/Supervisor */
      /* Transition: '<S18>:181' */
      Arizona_base_GOAT_DW.is_c7_Arizona_base_GOAT =
        Arizona_base_GOA_IN_MOVE_PEN_UP;
      Arizona_base_GOAT_DW.temporalCounter_i1 = 0U;

      /* Entry 'MOVE_PEN_UP': '<S18>:177' */
      Arizona_base_GOAT_B.change_color_j = 5.0;
    } else {
      switch (Arizona_base_GOAT_DW.is_c7_Arizona_base_GOAT) {
       case Arizona_base_GOA_IN_MOVE_PEN_UP:
        Arizona_base_GOAT_B.change_color_j = 5.0;

        /* During 'MOVE_PEN_UP': '<S18>:177' */
        if ((Arizona_base_GOAT_DW.temporalCounter_i1 >= 1000U) &&
            (Arizona_base_GOAT_B.penholderActive == 0.0)) {
          /* Transition: '<S18>:184' */
          Arizona_base_GOAT_DW.is_c7_Arizona_base_GOAT =
            Arizona_base_GOAT_IN_PEN_READY;

          /* Entry 'PEN_READY': '<S18>:182' */
          Arizona_base_GOAT_B.change_color_j = 0.0;
        }
        break;

       case Arizona__IN_MoveToLimitSwitches:
        /* During 'MoveToLimitSwitches': '<S18>:141' */
        if ((Arizona_base_GOAT_B.jogspeed_xL_reset_j == 0.0) &&
            (Arizona_base_GOAT_B.jogspeed_xR_reset_f == 0.0) &&
            (Arizona_base_GOAT_B.jogspeed_y_reset_d == 0.0)) {
          /* Transition: '<S18>:147' */
          /* Exit Internal 'MoveToLimitSwitches': '<S18>:141' */
          /* Exit Internal 'reset_carriage': '<S18>:174' */
          Arizona_base_GOAT_DW.is_reset_carriage =
            Arizona_base_IN_NO_ACTIVE_CHILD;
          Arizona_base_GOAT_DW.is_active_reset_carriage = 0U;

          /* Exit Internal 'reset_gantryright': '<S18>:169' */
          Arizona_base_GOAT_DW.is_reset_gantryright =
            Arizona_base_IN_NO_ACTIVE_CHILD;
          Arizona_base_GOAT_DW.is_active_reset_gantryright = 0U;

          /* Exit Internal 'reset_gantryLeft': '<S18>:136' */
          Arizona_base_GOAT_DW.is_reset_gantryLeft =
            Arizona_base_IN_NO_ACTIVE_CHILD;
          Arizona_base_GOAT_DW.is_active_reset_gantryLeft = 0U;
          Arizona_base_GOAT_DW.is_c7_Arizona_base_GOAT =
            Arizona_ba_IN_enablePointToRefs;

          /* Entry 'enablePointToRefs': '<S18>:146' */
          Arizona_base_GOAT_B.resetDone = 1.0;
        } else {
          /* During 'reset_gantryLeft': '<S18>:136' */
          if (Arizona_base_GOAT_DW.is_reset_gantryLeft ==
              Arizona_ba_IN_increase_jogspeed) {
            /* During 'increase_jogspeed': '<S18>:87' */
            if (!(Arizona_base_GOAT_B.DIgantryx2limitswitch != 0.0)) {
              Arizona_base_GOAT_DW.durationCounter_1 = 0;
            }

            tableOffset = Arizona_base_GOAT_DW.durationCounter_1;
            if (tableOffset < 0) {
              tableOffset = 0;
            }

            if (static_cast<uint32_T>(tableOffset) >= 10U) {
              /* Transition: '<S18>:85' */
              Arizona_base_GOAT_DW.is_reset_gantryLeft =
                Arizona_base_GOAT_IN_stop;

              /* Entry 'stop': '<S18>:88' */
              Arizona_base_GOAT_B.jogspeed_xL_reset_j = 0.0;
            } else {
              u1 = Arizona_base_GOAT_B.jogspeed_xL_reset_j - 0.10 *
                Arizona_base_GOAT_DW.Ts_l;
              if ((u1 <= -0.1) || rtIsNaN(u1)) {
                Arizona_base_GOAT_B.jogspeed_xL_reset_j = -0.1;
              } else {
                Arizona_base_GOAT_B.jogspeed_xL_reset_j = u1;
              }
            }
          } else {
            /* During 'stop': '<S18>:88' */
          }

          /* During 'reset_gantryright': '<S18>:169' */
          if (Arizona_base_GOAT_DW.is_reset_gantryright ==
              Arizona_ba_IN_increase_jogspeed) {
            /* During 'increase_jogspeed': '<S18>:170' */
            if (!(Arizona_base_GOAT_B.DIgantryx1limitswitch != 0.0)) {
              Arizona_base_GOAT_DW.durationCounter_1_n = 0;
            }

            tableOffset = Arizona_base_GOAT_DW.durationCounter_1_n;
            if (tableOffset < 0) {
              tableOffset = 0;
            }

            if (static_cast<uint32_T>(tableOffset) >= 10U) {
              /* Transition: '<S18>:168' */
              Arizona_base_GOAT_DW.is_reset_gantryright =
                Arizona_base_GOAT_IN_stop;

              /* Entry 'stop': '<S18>:167' */
              Arizona_base_GOAT_B.jogspeed_xR_reset_f = 0.0;
            } else {
              u1 = Arizona_base_GOAT_B.jogspeed_xR_reset_f - 0.10 *
                Arizona_base_GOAT_DW.Ts_l;
              if ((u1 <= -0.1) || rtIsNaN(u1)) {
                Arizona_base_GOAT_B.jogspeed_xR_reset_f = -0.1;
              } else {
                Arizona_base_GOAT_B.jogspeed_xR_reset_f = u1;
              }
            }
          } else {
            /* During 'stop': '<S18>:167' */
          }

          /* During 'reset_carriage': '<S18>:174' */
          if (Arizona_base_GOAT_DW.is_reset_carriage ==
              Arizona_ba_IN_increase_jogspeed) {
            /* During 'increase_jogspeed': '<S18>:173' */
            if (!(Arizona_base_GOAT_B.DIcarriagelimitswitch != 0.0)) {
              Arizona_base_GOAT_DW.durationCounter_1_d = 0;
            }

            tableOffset = Arizona_base_GOAT_DW.durationCounter_1_d;
            if (tableOffset < 0) {
              tableOffset = 0;
            }

            if (static_cast<uint32_T>(tableOffset) >= 10U) {
              /* Transition: '<S18>:176' */
              Arizona_base_GOAT_DW.is_reset_carriage = Arizona_base_GOAT_IN_stop;

              /* Entry 'stop': '<S18>:175' */
              Arizona_base_GOAT_B.jogspeed_y_reset_d = 0.0;
            } else {
              u1 = Arizona_base_GOAT_B.jogspeed_y_reset_d - 0.25 *
                Arizona_base_GOAT_DW.Ts_l;
              if ((u1 <= -0.25) || rtIsNaN(u1)) {
                Arizona_base_GOAT_B.jogspeed_y_reset_d = -0.25;
              } else {
                Arizona_base_GOAT_B.jogspeed_y_reset_d = u1;
              }
            }
          } else {
            /* During 'stop': '<S18>:175' */
          }
        }
        break;

       case Arizona_base_GOAT_IN_PEN_READY:
        Arizona_base_GOAT_B.change_color_j = 0.0;

        /* During 'PEN_READY': '<S18>:182' */
        /* Transition: '<S18>:183' */
        Arizona_base_GOAT_DW.is_c7_Arizona_base_GOAT =
          Arizona__IN_MoveToLimitSwitches;

        /* Entry Internal 'MoveToLimitSwitches': '<S18>:141' */
        Arizona_base_GOAT_DW.is_active_reset_gantryLeft = 1U;

        /* Entry Internal 'reset_gantryLeft': '<S18>:136' */
        /* Transition: '<S18>:139' */
        Arizona_base_GOAT_DW.durationCounter_1 = 0;
        Arizona_base_GOAT_DW.is_reset_gantryLeft =
          Arizona_ba_IN_increase_jogspeed;
        Arizona_base_GOAT_DW.is_active_reset_gantryright = 1U;

        /* Entry Internal 'reset_gantryright': '<S18>:169' */
        /* Transition: '<S18>:171' */
        Arizona_base_GOAT_DW.durationCounter_1_n = 0;
        Arizona_base_GOAT_DW.is_reset_gantryright =
          Arizona_ba_IN_increase_jogspeed;
        Arizona_base_GOAT_DW.is_active_reset_carriage = 1U;

        /* Entry Internal 'reset_carriage': '<S18>:174' */
        /* Transition: '<S18>:172' */
        Arizona_base_GOAT_DW.durationCounter_1_d = 0;
        Arizona_base_GOAT_DW.is_reset_carriage = Arizona_ba_IN_increase_jogspeed;
        break;

       default:
        Arizona_base_GOAT_B.resetDone = 1.0;

        /* During 'enablePointToRefs': '<S18>:146' */
        break;
      }
    }

    if (Arizona_base_GOAT_B.DIgantryx2limitswitch != 0.0) {
      Arizona_base_GOAT_DW.durationCounter_1++;
    } else {
      Arizona_base_GOAT_DW.durationCounter_1 = 0;
    }

    if (Arizona_base_GOAT_B.DIgantryx1limitswitch != 0.0) {
      Arizona_base_GOAT_DW.durationCounter_1_n++;
    } else {
      Arizona_base_GOAT_DW.durationCounter_1_n = 0;
    }

    if (Arizona_base_GOAT_B.DIcarriagelimitswitch != 0.0) {
      Arizona_base_GOAT_DW.durationCounter_1_d++;
    } else {
      Arizona_base_GOAT_DW.durationCounter_1_d = 0;
    }

    /* End of Chart: '<S16>/Supervisor' */

    /* Switch: '<S15>/Switch' */
    if (Arizona_base_GOAT_B.resetDone > Arizona_base_GOAT_cal->Switch_Threshold)
    {
      /* Switch: '<S15>/Switch' incorporates:
       *  Constant: '<S15>/Constant1'
       */
      Arizona_base_GOAT_B.Switch_bb = Arizona_base_GOAT_cal->Constant1_Value;
    } else {
      /* Switch: '<S15>/Switch' incorporates:
       *  Constant: '<S15>/Constant'
       */
      Arizona_base_GOAT_B.Switch_bb = Arizona_base_GOAT_cal->Constant_Value;
    }

    /* End of Switch: '<S15>/Switch' */

    /* Sum: '<S15>/Sum' */
    Arizona_base_GOAT_B.Sum_b = Arizona_base_GOAT_B.Delay_l +
      Arizona_base_GOAT_B.Switch_bb;

    /* DataTypeConversion: '<S15>/Data Type Conversion counter' */
    Arizona_base_GOAT_B.home_time = Arizona_base_GOAT_B.Sum_b;

    /* LookupNDDirect: '<S15>/Direct Lookup Table yFF' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion counter'
     *
     * About '<S15>/Direct Lookup Table yFF':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    u0 = Arizona_base_GOAT_B.home_time;
    if (u0 > 3492.0) {
      u0 = 3492.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    tableOffset = static_cast<int32_T>(u0);

    /* LookupNDDirect: '<S15>/Direct Lookup Table yFF' incorporates:
     *  Constant: '<S15>/set_y_homing'
     *
     * About '<S15>/Direct Lookup Table yFF':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    Arizona_base_GOAT_B.DirectLookupTableyFF = (get_y_Init())[tableOffset];

    /* LookupNDDirect: '<S15>/Direct Lookup Table xFF' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion counter'
     *
     * About '<S15>/Direct Lookup Table xFF':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    u0 = Arizona_base_GOAT_B.home_time;
    if (u0 > 3116.0) {
      u0 = 3116.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    tableOffset = static_cast<int32_T>(u0);

    /* LookupNDDirect: '<S15>/Direct Lookup Table xFF' incorporates:
     *  Constant: '<S15>/set_x_homing'
     *
     * About '<S15>/Direct Lookup Table xFF':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    Arizona_base_GOAT_B.DirectLookupTablexFF = (get_x_Init())[tableOffset];

    /* LookupNDDirect: '<S15>/Direct Lookup Table phiFF' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion counter'
     *
     * About '<S15>/Direct Lookup Table phiFF':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    u0 = Arizona_base_GOAT_B.home_time;
    if (u0 > 3492.0) {
      u0 = 3492.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    tableOffset = static_cast<int32_T>(u0);

    /* LookupNDDirect: '<S15>/Direct Lookup Table phiFF' incorporates:
     *  Constant: '<S15>/set_phi_homing'
     *
     * About '<S15>/Direct Lookup Table phiFF':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    Arizona_base_GOAT_B.DirectLookupTablephiFF = (get_phi_Init())[tableOffset];

    /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator x2JogSpeed1' */
    Arizona_base_GOAT_B.jogdistance_y_reset =
      Arizona_base_GOAT_DW.DiscreteTimeIntegratorx2JogSpee;

    /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator x2JogSpeed' */
    Arizona_base_GOAT_B.DiscreteTimeIntegratorx2JogSpee =
      Arizona_base_GOAT_DW.DiscreteTimeIntegratorx2JogSp_a;

    /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator x1JogSpeed' */
    Arizona_base_GOAT_B.DiscreteTimeIntegratorx1JogSpee =
      Arizona_base_GOAT_DW.DiscreteTimeIntegratorx1JogSpee;

    /* Sum: '<S16>/current_x4' */
    Arizona_base_GOAT_B.current_x4 =
      Arizona_base_GOAT_B.DiscreteTimeIntegratorx2JogSpee +
      Arizona_base_GOAT_B.DiscreteTimeIntegratorx1JogSpee;

    /* Gain: '<S16>/Gain x2' */
    Arizona_base_GOAT_B.jogdistance_x_reset = Arizona_base_GOAT_cal->Gainx2_Gain
      * Arizona_base_GOAT_B.current_x4;

    /* Sum: '<S16>/current_x3' */
    Arizona_base_GOAT_B.current_x3 =
      Arizona_base_GOAT_B.DiscreteTimeIntegratorx1JogSpee -
      Arizona_base_GOAT_B.DiscreteTimeIntegratorx2JogSpee;

    /* Gain: '<S16>/Gain x3' */
    Arizona_base_GOAT_B.jogdistance_phi_reset =
      Arizona_base_GOAT_cal->Gainx3_Gain * Arizona_base_GOAT_B.current_x3;

    /* Sum: '<S13>/Add phiHome' */
    Arizona_base_GOAT_B.AddphiHome = Arizona_base_GOAT_B.jogdistance_phi_reset +
      Arizona_base_GOAT_B.DirectLookupTablephiFF;

    /* Sum: '<S13>/Add xHome' */
    Arizona_base_GOAT_B.AddxHome = Arizona_base_GOAT_B.jogdistance_x_reset +
      Arizona_base_GOAT_B.DirectLookupTablexFF;

    /* Sum: '<S13>/Add yHome' */
    Arizona_base_GOAT_B.AddyHome = Arizona_base_GOAT_B.jogdistance_y_reset +
      Arizona_base_GOAT_B.DirectLookupTableyFF;

    /* RelationalOperator: '<S17>/Compare' incorporates:
     *  Constant: '<S17>/Constant'
     */
    Arizona_base_GOAT_B.Compare_b = (Arizona_base_GOAT_B.home_time >=
      *get_N_Init());

    /* DataTypeConversion: '<S15>/Data Type Conversion end trial' */
    Arizona_base_GOAT_B.DataTypeConversionendtrial =
      Arizona_base_GOAT_B.Compare_b;

    /* S-Function (dlowpass2): '<S16>/Dct2lowpass x1JogSpeed' */

    /* Level2 S-Function Block: '<S16>/Dct2lowpass x1JogSpeed' (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[0];
      sfcnOutputs(rts,0);
    }

    /* S-Function (dlowpass2): '<S16>/Dct2lowpass x2JogSpeed' */

    /* Level2 S-Function Block: '<S16>/Dct2lowpass x2JogSpeed' (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[1];
      sfcnOutputs(rts,0);
    }

    /* S-Function (dlowpass2): '<S16>/Dct2lowpass yJogSpeed' */

    /* Level2 S-Function Block: '<S16>/Dct2lowpass yJogSpeed' (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[2];
      sfcnOutputs(rts,0);
    }

    /* Update for Delay: '<S15>/Delay' */
    Arizona_base_GOAT_DW.Delay_DSTATE_m = Arizona_base_GOAT_B.Sum_b;

    /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator x2JogSpeed1' */
    Arizona_base_GOAT_DW.DiscreteTimeIntegratorx2JogSpee +=
      Arizona_base_GOAT_cal->DiscreteTimeIntegratorx2JogSpee *
      Arizona_base_GOAT_B.jogspeed_y_reset;

    /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator x2JogSpeed' */
    Arizona_base_GOAT_DW.DiscreteTimeIntegratorx2JogSp_a +=
      Arizona_base_GOAT_cal->DiscreteTimeIntegratorx2JogSp_n *
      Arizona_base_GOAT_B.jogspeed_xL_reset;

    /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator x1JogSpeed' */
    Arizona_base_GOAT_DW.DiscreteTimeIntegratorx1JogSpee +=
      Arizona_base_GOAT_cal->DiscreteTimeIntegratorx1JogSpee *
      Arizona_base_GOAT_B.jogspeed_xR_reset;
    srUpdateBC(Arizona_base_GOAT_DW.Enabledsubsystem_SubsysRanBC);
  } else if (Arizona_base_GOAT_DW.Enabledsubsystem_MODE) {
    /* Disable for DiscreteIntegrator: '<S16>/Discrete-Time Integrator x2JogSpeed1' */
    Arizona_base_GOAT_DW.DiscreteTimeIntegratorx2JogSpee =
      Arizona_base_GOAT_B.jogdistance_y_reset;

    /* Disable for DiscreteIntegrator: '<S16>/Discrete-Time Integrator x2JogSpeed' */
    Arizona_base_GOAT_DW.DiscreteTimeIntegratorx2JogSp_a =
      Arizona_base_GOAT_B.DiscreteTimeIntegratorx2JogSpee;

    /* Disable for DiscreteIntegrator: '<S16>/Discrete-Time Integrator x1JogSpeed' */
    Arizona_base_GOAT_DW.DiscreteTimeIntegratorx1JogSpee =
      Arizona_base_GOAT_B.DiscreteTimeIntegratorx1JogSpee;
    Arizona_base_GOAT_DW.Enabledsubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S4>/Enabled subsystem' */

  /* Delay: '<S21>/Delay1' */
  Arizona_base_GOAT_B.Delay1 = Arizona_base_GOAT_DW.Delay1_DSTATE;

  /* Delay: '<S21>/Delay' */
  Arizona_base_GOAT_B.Delay = Arizona_base_GOAT_DW.Delay_DSTATE;

  /* Switch: '<S21>/Switch1' */
  if (Arizona_base_GOAT_B.Delay > Arizona_base_GOAT_cal->Switch1_Threshold) {
    /* Sum: '<S21>/Sum' */
    Arizona_base_GOAT_B.Sum_o = Arizona_base_GOAT_B.AddyHome +
      Arizona_base_GOAT_B.Delay1;

    /* Switch: '<S21>/Switch1' */
    Arizona_base_GOAT_B.Switch1 = Arizona_base_GOAT_B.Sum_o;
  } else {
    /* Switch: '<S21>/Switch1' */
    Arizona_base_GOAT_B.Switch1 = Arizona_base_GOAT_B.Delay1;
  }

  /* End of Switch: '<S21>/Switch1' */

  /* Delay: '<Root>/Delay1' */
  Arizona_base_GOAT_B.trialTrigger = Arizona_base_GOAT_DW.Delay1_DSTATE_g;

  /* Outputs for Enabled SubSystem: '<Root>/Trajectory' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (Arizona_base_GOAT_B.trialTrigger > 0.0) {
    boolean_T zcEvent;
    if (!Arizona_base_GOAT_DW.Trajectory_MODE) {
      /* InitializeConditions for Delay: '<S11>/Delay' */
      Arizona_base_GOAT_DW.Delay_DSTATE_k =
        Arizona_base_GOAT_cal->Delay_InitialCondition_g;

      /* SystemReset for Resettable SubSystem: '<S11>/Resettable Subsystem // Memory' */
      /* InitializeConditions for Memory: '<S44>/Memory' */
      Arizona_base_GOAT_DW.Memory_PreviousInput =
        Arizona_base_GOAT_cal->Memory_InitialCondition;

      /* End of SystemReset for SubSystem: '<S11>/Resettable Subsystem // Memory' */
      Arizona_base_GOAT_DW.Trajectory_MODE = true;
    }

    /* Delay: '<S11>/Delay' */
    Arizona_base_GOAT_B.Delay_c = Arizona_base_GOAT_DW.Delay_DSTATE_k;

    /* Outputs for Resettable SubSystem: '<S11>/Resettable Subsystem // Memory' incorporates:
     *  ResetPort: '<S44>/Reset'
     */
    zcEvent = (Arizona_base_GOAT_B.Delay_c &&
               (Arizona_base_GOAT_PrevZCX.ResettableSubsystemMemory_Reset !=
                POS_ZCSIG));
    if (zcEvent) {
      /* InitializeConditions for Memory: '<S44>/Memory' */
      Arizona_base_GOAT_DW.Memory_PreviousInput =
        Arizona_base_GOAT_cal->Memory_InitialCondition;
    }

    Arizona_base_GOAT_PrevZCX.ResettableSubsystemMemory_Reset =
      Arizona_base_GOAT_B.Delay_c;

    /* Memory: '<S44>/Memory' */
    Arizona_base_GOAT_B.Memory = Arizona_base_GOAT_DW.Memory_PreviousInput;

    /* End of Outputs for SubSystem: '<S11>/Resettable Subsystem // Memory' */

    /* Logic: '<S11>/Logical Operator' */
    Arizona_base_GOAT_B.LogicalOperator = !(Arizona_base_GOAT_B.penholderActive
      != 0.0);

    /* Product: '<S11>/Product' incorporates:
     *  Constant: '<S11>/Constant'
     */
    Arizona_base_GOAT_B.Product = Arizona_base_GOAT_cal->Constant_Value_e *
      static_cast<real_T>(Arizona_base_GOAT_B.LogicalOperator);

    /* Sum: '<S11>/Sum' */
    Arizona_base_GOAT_B.Sum = Arizona_base_GOAT_B.Memory +
      Arizona_base_GOAT_B.Product;

    /* DataTypeConversion: '<S11>/Data Type Conversion' */
    Arizona_base_GOAT_B.time = Arizona_base_GOAT_B.Sum;

    /* LookupNDDirect: '<S11>/Direct Lookup Table yRef' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion'
     *
     * About '<S11>/Direct Lookup Table yRef':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    u0 = Arizona_base_GOAT_B.time;
    if (u0 > 4999.0) {
      u0 = 4999.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    tableOffset = static_cast<int32_T>(u0);

    /* LookupNDDirect: '<S11>/Direct Lookup Table yRef' incorporates:
     *  Constant: '<S11>/set_yRef'
     *
     * About '<S11>/Direct Lookup Table yRef':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    Arizona_base_GOAT_B.yref_check = Arizona_base_GOAT_cal->
      set_yRef_Value[tableOffset];

    /* RelationalOperator: '<S43>/Compare' incorporates:
     *  Constant: '<S43>/Constant'
     */
    Arizona_base_GOAT_B.Compare_h2 = (Arizona_base_GOAT_B.time >= *get_Nref());

    /* LookupNDDirect: '<S11>/Direct Lookup Table change_color' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion'
     *
     * About '<S11>/Direct Lookup Table change_color':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    u0 = Arizona_base_GOAT_B.time;
    if (u0 > 4999.0) {
      u0 = 4999.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    tableOffset = static_cast<int32_T>(u0);

    /* LookupNDDirect: '<S11>/Direct Lookup Table change_color' incorporates:
     *  Constant: '<S11>/set_cRef'
     *
     * About '<S11>/Direct Lookup Table change_color':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    Arizona_base_GOAT_B.DirectLookupTablechange_color =
      Arizona_base_GOAT_cal->set_cRef_Value[tableOffset];

    /* LookupNDDirect: '<S11>/Direct Lookup Table phiRef' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion'
     *
     * About '<S11>/Direct Lookup Table phiRef':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    u0 = Arizona_base_GOAT_B.time;
    if (u0 > 4999.0) {
      u0 = 4999.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    tableOffset = static_cast<int32_T>(u0);

    /* LookupNDDirect: '<S11>/Direct Lookup Table phiRef' incorporates:
     *  Constant: '<S11>/set_phiRef'
     *
     * About '<S11>/Direct Lookup Table phiRef':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    Arizona_base_GOAT_B.DirectLookupTablephiRef =
      Arizona_base_GOAT_cal->set_phiRef_Value[tableOffset];

    /* LookupNDDirect: '<S11>/Direct Lookup Table xRef' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion'
     *
     * About '<S11>/Direct Lookup Table xRef':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    u0 = Arizona_base_GOAT_B.time;
    if (u0 > 4999.0) {
      u0 = 4999.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    tableOffset = static_cast<int32_T>(u0);

    /* LookupNDDirect: '<S11>/Direct Lookup Table xRef' incorporates:
     *  Constant: '<S11>/set_xRef'
     *
     * About '<S11>/Direct Lookup Table xRef':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    Arizona_base_GOAT_B.DirectLookupTablexRef =
      Arizona_base_GOAT_cal->set_xRef_Value[tableOffset];

    /* Update for Delay: '<S11>/Delay' */
    Arizona_base_GOAT_DW.Delay_DSTATE_k = Arizona_base_GOAT_B.Compare_h2;

    /* Update for Resettable SubSystem: '<S11>/Resettable Subsystem // Memory' incorporates:
     *  ResetPort: '<S44>/Reset'
     */
    /* Update for Memory: '<S44>/Memory' */
    Arizona_base_GOAT_DW.Memory_PreviousInput = Arizona_base_GOAT_B.Sum;

    /* End of Update for SubSystem: '<S11>/Resettable Subsystem // Memory' */
    srUpdateBC(Arizona_base_GOAT_DW.Trajectory_SubsysRanBC);
  } else {
    Arizona_base_GOAT_DW.Trajectory_MODE = false;
  }

  /* End of Outputs for SubSystem: '<Root>/Trajectory' */

  /* Sum: '<Root>/reference_y' */
  Arizona_base_GOAT_B.r_ym = Arizona_base_GOAT_B.Switch1 +
    Arizona_base_GOAT_B.yref_check;

  /* Sum: '<Root>/error y' */
  Arizona_base_GOAT_B.errory = Arizona_base_GOAT_B.r_ym -
    Arizona_base_GOAT_B.encodercarriage;

  /* Gain: '<Root>/Gain8' */
  Arizona_base_GOAT_B.e_ym = Arizona_base_GOAT_cal->Gain8_Gain *
    Arizona_base_GOAT_B.errory;

  /* Sum: '<S10>/Sum yNom' */
  Arizona_base_GOAT_B.yNomm = Arizona_base_GOAT_B.encodercarriage -
    Arizona_base_GOAT_B.Switch1;

  /* S-Function (dlowpass2): '<S10>/Dct2lowpass output_y' */

  /* Level2 S-Function Block: '<S10>/Dct2lowpass output_y' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[16];
    sfcnOutputs(rts,0);
  }

  /* SampleTimeMath: '<S41>/TSamp'
   *
   * About '<S41>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Arizona_base_GOAT_B.TSamp = Arizona_base_GOAT_B.Dct2lowpassoutput_y *
    Arizona_base_GOAT_cal->TSamp_WtEt;

  /* UnitDelay: '<S41>/UD' */
  Arizona_base_GOAT_B.Uk1 = Arizona_base_GOAT_DW.UD_DSTATE;

  /* Sum: '<S41>/Diff' */
  Arizona_base_GOAT_B.Diff = Arizona_base_GOAT_B.TSamp - Arizona_base_GOAT_B.Uk1;

  /* Delay: '<S20>/Delay1' */
  Arizona_base_GOAT_B.Delay1_g = Arizona_base_GOAT_DW.Delay1_DSTATE_i;

  /* Delay: '<S20>/Delay' */
  Arizona_base_GOAT_B.Delay_m = Arizona_base_GOAT_DW.Delay_DSTATE_j;

  /* Switch: '<S20>/Switch1' */
  if (Arizona_base_GOAT_B.Delay_m > Arizona_base_GOAT_cal->Switch1_Threshold_m)
  {
    /* Sum: '<S20>/Sum' */
    Arizona_base_GOAT_B.Sum_k = Arizona_base_GOAT_B.AddxHome +
      Arizona_base_GOAT_B.Delay1_g;

    /* Switch: '<S20>/Switch1' */
    Arizona_base_GOAT_B.Switch1_h = Arizona_base_GOAT_B.Sum_k;
  } else {
    /* Switch: '<S20>/Switch1' */
    Arizona_base_GOAT_B.Switch1_h = Arizona_base_GOAT_B.Delay1_g;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Sum: '<Root>/reference_x' */
  Arizona_base_GOAT_B.r_xm = Arizona_base_GOAT_B.Switch1_h +
    Arizona_base_GOAT_B.DirectLookupTablexRef;

  /* Sum: '<S2>/Sum x_L + x_R' */
  Arizona_base_GOAT_B.Sumx_Lx_R = Arizona_base_GOAT_B.encodergantryx2 +
    Arizona_base_GOAT_B.encodergantryx1;

  /* Gain: '<S2>/Gain x' */
  Arizona_base_GOAT_B.Gainx = Arizona_base_GOAT_cal->Gainx_Gain *
    Arizona_base_GOAT_B.Sumx_Lx_R;

  /* Sum: '<Root>/error x' */
  Arizona_base_GOAT_B.errorx = Arizona_base_GOAT_B.r_xm -
    Arizona_base_GOAT_B.Gainx;

  /* Gain: '<Root>/Gain9' */
  Arizona_base_GOAT_B.e_xm = Arizona_base_GOAT_cal->Gain9_Gain *
    Arizona_base_GOAT_B.errorx;

  /* Sum: '<S10>/Sum xNom' */
  Arizona_base_GOAT_B.xNomm = Arizona_base_GOAT_B.Gainx -
    Arizona_base_GOAT_B.Switch1_h;

  /* S-Function (dlowpass2): '<S10>/Dct2lowpass output_x' */

  /* Level2 S-Function Block: '<S10>/Dct2lowpass output_x' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[17];
    sfcnOutputs(rts,0);
  }

  /* SampleTimeMath: '<S40>/TSamp'
   *
   * About '<S40>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Arizona_base_GOAT_B.TSamp_n = Arizona_base_GOAT_B.Dct2lowpassoutput_x *
    Arizona_base_GOAT_cal->TSamp_WtEt_p;

  /* UnitDelay: '<S40>/UD' */
  Arizona_base_GOAT_B.Uk1_o = Arizona_base_GOAT_DW.UD_DSTATE_a;

  /* Sum: '<S40>/Diff' */
  Arizona_base_GOAT_B.Diff_n = Arizona_base_GOAT_B.TSamp_n -
    Arizona_base_GOAT_B.Uk1_o;

  /* Delay: '<S19>/Delay1' */
  Arizona_base_GOAT_B.Delay1_b = Arizona_base_GOAT_DW.Delay1_DSTATE_o;

  /* Sum: '<S19>/Sum' */
  Arizona_base_GOAT_B.main = Arizona_base_GOAT_B.AddphiHome +
    Arizona_base_GOAT_B.Delay1_b;

  /* Delay: '<S19>/Delay' */
  Arizona_base_GOAT_B.Delay_j = Arizona_base_GOAT_DW.Delay_DSTATE_h;

  /* Switch: '<S19>/Switch1' */
  if (Arizona_base_GOAT_B.Delay_j > Arizona_base_GOAT_cal->Switch1_Threshold_e)
  {
    /* Switch: '<S19>/Switch1' */
    Arizona_base_GOAT_B.Switch1_c = Arizona_base_GOAT_B.main;
  } else {
    /* Switch: '<S19>/Switch1' */
    Arizona_base_GOAT_B.Switch1_c = Arizona_base_GOAT_B.Delay1_b;
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Sum: '<Root>/reference phi' */
  Arizona_base_GOAT_B.r_phirad = Arizona_base_GOAT_B.Switch1_c +
    Arizona_base_GOAT_B.DirectLookupTablephiRef;

  /* Sum: '<S2>/Sum x_R - x_L' */
  Arizona_base_GOAT_B.Sumx_Rx_L = Arizona_base_GOAT_B.encodergantryx1 -
    Arizona_base_GOAT_B.encodergantryx2;

  /* Gain: '<S2>/Gain phi' */
  Arizona_base_GOAT_B.Gainphi = Arizona_base_GOAT_cal->Gainphi_Gain *
    Arizona_base_GOAT_B.Sumx_Rx_L;

  /* Sum: '<Root>/error phi' */
  Arizona_base_GOAT_B.errorphi = Arizona_base_GOAT_B.r_phirad -
    Arizona_base_GOAT_B.Gainphi;

  /* Gain: '<Root>/Gain10' */
  Arizona_base_GOAT_B.e_phirad = Arizona_base_GOAT_cal->Gain10_Gain *
    Arizona_base_GOAT_B.errorphi;

  /* Sum: '<S10>/Sum phiNom' */
  Arizona_base_GOAT_B.phiNomrad = Arizona_base_GOAT_B.Gainphi -
    Arizona_base_GOAT_B.Switch1_c;

  /* Chart: '<S10>/Supervisor' */
  /* Gateway: Safety/Supervisor */
  Arizona_base_GOAT_DW.sfEvent_i = Arizona_base_GOAT_CALL_EVENT;

  /* During: Safety/Supervisor */
  if (Arizona_base_GOAT_DW.is_active_c3_Arizona_base_GOAT == 0U) {
    /* Entry: Safety/Supervisor */
    Arizona_base_GOAT_DW.is_active_c3_Arizona_base_GOAT = 1U;

    /* Entry Internal: Safety/Supervisor */
    /* Transition: '<S42>:218' */
    Arizona_base_GOAT_DW.is_c3_Arizona_base_GOAT =
      Arizona_base__IN_evaluateSatefy;

    /* Entry Internal 'evaluateSatefy': '<S42>:215' */
    Arizona_base_GOAT_DW.is_active_errorAirbag = 1U;

    /* Entry Internal 'errorAirbag': '<S42>:256' */
    /* Transition: '<S42>:251' */
    Arizona_base_GOAT_DW.is_errorAirbag = Arizona_base__IN_defaultState_m;
    Arizona_base_GOAT_DW.is_active_carriageAirbag = 1U;

    /* Entry Internal 'carriageAirbag': '<S42>:212' */
    /* Transition: '<S42>:235' */
    Arizona_base_GOAT_DW.is_carriageAirbag = Arizona_base__IN_defaultState_m;
    Arizona_base_GOAT_DW.is_active_gantryAirbag = 1U;

    /* Entry Internal 'gantryAirbag': '<S42>:242' */
    /* Transition: '<S42>:292' */
    Arizona_base_GOAT_DW.is_gantryAirbag = Arizona_base_GO_IN_defaultState;
  } else if (Arizona_base_GOAT_DW.is_c3_Arizona_base_GOAT ==
             Arizona_base__IN_evaluateSatefy) {
    /* During 'evaluateSatefy': '<S42>:215' */
    /*  Stop simulation if the airbags are active with zero current and the velocity is small. */
    if ((Arizona_base_GOAT_B.enableAirbags != 0.0) &&
        (Arizona_base_GOAT_B.current_carriageAirbag == 0.0) &&
        (Arizona_base_GOAT_B.current_gantryAirbag == 0.0) && (std::sqrt
         (rt_powd_snf(Arizona_base_GOAT_B.Diff_n, 2.0) + rt_powd_snf
          (Arizona_base_GOAT_B.Diff, 2.0)) < 0.01)) {
      /* Transition: '<S42>:303' */
      /* Exit Internal 'evaluateSatefy': '<S42>:215' */
      /* Exit Internal 'gantryAirbag': '<S42>:242' */
      if (Arizona_base_GOAT_DW.is_gantryAirbag ==
          Arizona_base_GO_IN_defaultState) {
        /* Exit 'defaultState': '<S42>:289' */
        Arizona_base_GOAT_B.enableAirbags = 1.0;
        Arizona_base_GOAT_DW.is_gantryAirbag = Arizona_base_IN_NO_ACTIVE_CHILD;
      } else {
        Arizona_base_GOAT_DW.is_gantryAirbag = Arizona_base_IN_NO_ACTIVE_CHILD;
      }

      Arizona_base_GOAT_DW.is_active_gantryAirbag = 0U;

      /* Exit Internal 'carriageAirbag': '<S42>:212' */
      if (Arizona_base_GOAT_DW.is_carriageAirbag ==
          Arizona_base__IN_defaultState_m) {
        /* Exit 'defaultState': '<S42>:234' */
        Arizona_base_GOAT_B.enableAirbags = 1.0;
        Arizona_base_GOAT_DW.is_carriageAirbag = Arizona_base_IN_NO_ACTIVE_CHILD;
      } else {
        Arizona_base_GOAT_DW.is_carriageAirbag = Arizona_base_IN_NO_ACTIVE_CHILD;
      }

      Arizona_base_GOAT_DW.is_active_carriageAirbag = 0U;

      /* Exit Internal 'errorAirbag': '<S42>:256' */
      Arizona_base_GOAT_DW.is_errorAirbag = Arizona_base_IN_NO_ACTIVE_CHILD;
      Arizona_base_GOAT_DW.is_active_errorAirbag = 0U;
      Arizona_base_GOAT_DW.is_c3_Arizona_base_GOAT =
        Arizona_base_GO_IN_stopCarriage;

      /* Entry 'stopCarriage': '<S42>:307' */
      Arizona_base_GOAT_B.stopSimulation = 1.0;
    } else {
      /* During 'errorAirbag': '<S42>:256' */
      if ((Arizona_base_GOAT_DW.is_errorAirbag ==
           Arizona_base__IN_defaultState_m) && ((std::abs
            (Arizona_base_GOAT_B.e_xm) > 0.05) || (std::abs
            (Arizona_base_GOAT_B.e_ym) > 0.05) || (std::abs
            (Arizona_base_GOAT_B.e_phirad) > 0.05) || (std::abs
            (Arizona_base_GOAT_B.phiNomrad) > 0.0038461348810665233))) {
        /* During 'defaultState': '<S42>:248' */
        /* Transition: '<S42>:294' */
        Arizona_base_GOAT_DW.is_errorAirbag = Arizona_base_GOAT_IN_errorStop;

        /* Entry 'errorStop': '<S42>:293' */
        Arizona_base_GOAT_B.enableAirbags = 1.0;
      } else {
        /* During 'errorStop': '<S42>:293' */
      }

      /* During 'carriageAirbag': '<S42>:212' */
      switch (Arizona_base_GOAT_DW.is_carriageAirbag) {
       case Arizona_base__IN_defaultState_m:
        /* During 'defaultState': '<S42>:234' */
        if ((Arizona_base_GOAT_B.DataTypeConversionendtrial != 0.0) &&
            (Arizona_base_GOAT_B.yNomm < -1.2600000000000144)) {
          /* Transition: '<S42>:217' */
          /* Exit 'defaultState': '<S42>:234' */
          Arizona_base_GOAT_B.enableAirbags = 1.0;
          Arizona_base_GOAT_DW.is_carriageAirbag =
            Arizona_base_GOAT_IN_leftAirbag;

          /* Entry 'leftAirbag': '<S42>:219' */
          Arizona_base_GOAT_B.current_carriageAirbag = 5.0;
        } else if ((Arizona_base_GOAT_B.DataTypeConversionendtrial != 0.0) &&
                   (Arizona_base_GOAT_B.yNomm > 1.5599999999999858)) {
          /* Transition: '<S42>:223' */
          /* Exit 'defaultState': '<S42>:234' */
          Arizona_base_GOAT_B.enableAirbags = 1.0;
          Arizona_base_GOAT_DW.is_carriageAirbag =
            Arizona_base_GOA_IN_rightAirbag;

          /* Entry 'rightAirbag': '<S42>:222' */
          Arizona_base_GOAT_B.current_carriageAirbag = -5.0;
        }
        break;

       case Arizona_base_GOAT_IN_leftAirbag:
        Arizona_base_GOAT_B.current_carriageAirbag = 5.0;

        /* During 'leftAirbag': '<S42>:219' */
        if (Arizona_base_GOAT_B.Diff >= 0.0) {
          /* Transition: '<S42>:214' */
          Arizona_base_GOAT_DW.is_carriageAirbag =
            Arizona__IN_stop_carriageAirbag;

          /* Entry 'stop_carriageAirbag': '<S42>:220' */
          Arizona_base_GOAT_B.current_carriageAirbag = 0.0;
        }
        break;

       case Arizona_base_GOA_IN_rightAirbag:
        Arizona_base_GOAT_B.current_carriageAirbag = -5.0;

        /* During 'rightAirbag': '<S42>:222' */
        if (Arizona_base_GOAT_B.Diff <= 0.0) {
          /* Transition: '<S42>:224' */
          Arizona_base_GOAT_DW.is_carriageAirbag =
            Arizona__IN_stop_carriageAirbag;

          /* Entry 'stop_carriageAirbag': '<S42>:220' */
          Arizona_base_GOAT_B.current_carriageAirbag = 0.0;
        }
        break;

       default:
        Arizona_base_GOAT_B.current_carriageAirbag = 0.0;

        /* During 'stop_carriageAirbag': '<S42>:220' */
        break;
      }

      /* During 'gantryAirbag': '<S42>:242' */
      switch (Arizona_base_GOAT_DW.is_gantryAirbag) {
       case Arizona_base_GOAT_IN_backAirbag:
        Arizona_base_GOAT_B.current_gantryAirbag = -5.0;

        /* During 'backAirbag': '<S42>:237' */
        if (Arizona_base_GOAT_B.Diff_n <= 0.0) {
          /* Transition: '<S42>:238' */
          Arizona_base_GOAT_DW.is_gantryAirbag = Arizona_ba_IN_stop_gantryAirbag;

          /* Entry 'stop_gantryAirbag': '<S42>:246' */
          Arizona_base_GOAT_B.current_gantryAirbag = 0.0;
        }
        break;

       case Arizona_base_GO_IN_defaultState:
        /* During 'defaultState': '<S42>:289' */
        if ((Arizona_base_GOAT_B.DataTypeConversionendtrial != 0.0) &&
            (Arizona_base_GOAT_B.xNomm < -0.49249999999999133)) {
          /* Transition: '<S42>:244' */
          /* Exit 'defaultState': '<S42>:289' */
          Arizona_base_GOAT_B.enableAirbags = 1.0;
          Arizona_base_GOAT_DW.is_gantryAirbag = Arizona_base_GOA_IN_frontAirbag;

          /* Entry 'frontAirbag': '<S42>:241' */
          Arizona_base_GOAT_B.current_gantryAirbag = 5.0;
        } else if ((Arizona_base_GOAT_B.DataTypeConversionendtrial != 0.0) &&
                   (Arizona_base_GOAT_B.xNomm > 0.32750000000000862)) {
          /* Transition: '<S42>:239' */
          /* Exit 'defaultState': '<S42>:289' */
          Arizona_base_GOAT_B.enableAirbags = 1.0;
          Arizona_base_GOAT_DW.is_gantryAirbag = Arizona_base_GOAT_IN_backAirbag;

          /* Entry 'backAirbag': '<S42>:237' */
          Arizona_base_GOAT_B.current_gantryAirbag = -5.0;
        }
        break;

       case Arizona_base_GOA_IN_frontAirbag:
        Arizona_base_GOAT_B.current_gantryAirbag = 5.0;

        /* During 'frontAirbag': '<S42>:241' */
        if (Arizona_base_GOAT_B.Diff_n >= 0.0) {
          /* Transition: '<S42>:243' */
          Arizona_base_GOAT_DW.is_gantryAirbag = Arizona_ba_IN_stop_gantryAirbag;

          /* Entry 'stop_gantryAirbag': '<S42>:246' */
          Arizona_base_GOAT_B.current_gantryAirbag = 0.0;
        }
        break;

       default:
        Arizona_base_GOAT_B.current_gantryAirbag = 0.0;

        /* During 'stop_gantryAirbag': '<S42>:246' */
        break;
      }
    }
  } else {
    Arizona_base_GOAT_B.stopSimulation = 1.0;

    /* During 'stopCarriage': '<S42>:307' */
  }

  /* End of Chart: '<S10>/Supervisor' */

  /* S-Function (dlowpass2): '<S10>/Dct2lowpass current_gantryAirbag' */

  /* Level2 S-Function Block: '<S10>/Dct2lowpass current_gantryAirbag' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[18];
    sfcnOutputs(rts,0);
  }

  /* Outputs for Enabled SubSystem: '<Root>/Feedforward' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (Arizona_base_GOAT_B.trialTrigger > 0.0) {
    /* LookupNDDirect: '<S3>/Direct Lookup Table phiFF' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion'
     *
     * About '<S3>/Direct Lookup Table phiFF':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    u0 = Arizona_base_GOAT_B.time;
    if (u0 > 4999.0) {
      u0 = 4999.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    tableOffset = static_cast<int32_T>(u0);

    /* LookupNDDirect: '<S3>/Direct Lookup Table phiFF' incorporates:
     *  Constant: '<S3>/set_phiFF'
     *
     * About '<S3>/Direct Lookup Table phiFF':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    Arizona_base_GOAT_B.f_phi = Arizona_base_GOAT_cal->
      set_phiFF_Value[tableOffset];

    /* LookupNDDirect: '<S3>/Direct Lookup Table xFF' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion'
     *
     * About '<S3>/Direct Lookup Table xFF':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    u0 = Arizona_base_GOAT_B.time;
    if (u0 > 4999.0) {
      u0 = 4999.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    tableOffset = static_cast<int32_T>(u0);

    /* LookupNDDirect: '<S3>/Direct Lookup Table xFF' incorporates:
     *  Constant: '<S3>/set_xFF'
     *
     * About '<S3>/Direct Lookup Table xFF':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    Arizona_base_GOAT_B.f_x = Arizona_base_GOAT_cal->set_xFF_Value[tableOffset];

    /* LookupNDDirect: '<S3>/Direct Lookup Table yFF' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion'
     *
     * About '<S3>/Direct Lookup Table yFF':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    u0 = Arizona_base_GOAT_B.time;
    if (u0 > 4999.0) {
      u0 = 4999.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    tableOffset = static_cast<int32_T>(u0);

    /* LookupNDDirect: '<S3>/Direct Lookup Table yFF' incorporates:
     *  Constant: '<S3>/set_yFF'
     *
     * About '<S3>/Direct Lookup Table yFF':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    Arizona_base_GOAT_B.f_y = Arizona_base_GOAT_cal->set_yFF_Value[tableOffset];
    srUpdateBC(Arizona_base_GOAT_DW.Feedforward_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<Root>/Feedforward' */

  /* DiscreteStateSpace: '<S7>/Internal' */
  {
    Arizona_base_GOAT_B.Internal = (Arizona_base_GOAT_cal->Internal_C[0])*
      Arizona_base_GOAT_DW.Internal_DSTATE[0]
      + (Arizona_base_GOAT_cal->Internal_C[1])*
      Arizona_base_GOAT_DW.Internal_DSTATE[1];
    Arizona_base_GOAT_B.Internal += Arizona_base_GOAT_cal->Internal_D*
      Arizona_base_GOAT_B.e_xm;
  }

  /* Sum: '<Root>/Sum current x' */
  Arizona_base_GOAT_B.u_xV = Arizona_base_GOAT_B.f_x +
    Arizona_base_GOAT_B.Internal;

  /* Gain: '<S1>/Gain on u_x' */
  Arizona_base_GOAT_B.Gainonu_x = Arizona_base_GOAT_cal->Gainonu_x_Gain *
    Arizona_base_GOAT_B.u_xV;

  /* DiscreteStateSpace: '<S8>/Internal' */
  {
    Arizona_base_GOAT_B.Internal_j = (Arizona_base_GOAT_cal->Internal_C_i[0])*
      Arizona_base_GOAT_DW.Internal_DSTATE_l[0]
      + (Arizona_base_GOAT_cal->Internal_C_i[1])*
      Arizona_base_GOAT_DW.Internal_DSTATE_l[1]
      + (Arizona_base_GOAT_cal->Internal_C_i[2])*
      Arizona_base_GOAT_DW.Internal_DSTATE_l[2];
    Arizona_base_GOAT_B.Internal_j += Arizona_base_GOAT_cal->Internal_D_g*
      Arizona_base_GOAT_B.e_phirad;
  }

  /* Sum: '<Root>/Sum current phi' */
  Arizona_base_GOAT_B.u_phiV = Arizona_base_GOAT_B.f_phi +
    Arizona_base_GOAT_B.Internal_j;

  /* Gain: '<S1>/Gain on u_phi' */
  Arizona_base_GOAT_B.Gainonu_phi = Arizona_base_GOAT_cal->Gainonu_phi_Gain *
    Arizona_base_GOAT_B.u_phiV;

  /* Sum: '<S1>/Sum current x_R' */
  Arizona_base_GOAT_B.Sumcurrentx_R = Arizona_base_GOAT_B.Gainonu_x +
    Arizona_base_GOAT_B.Gainonu_phi;

  /* Switch: '<S10>/Switch current_yr' */
  if (Arizona_base_GOAT_B.enableAirbags != 0.0) {
    /* Switch: '<S10>/Switch current_yr' */
    Arizona_base_GOAT_B.gantryx_Rmotorvoltage =
      Arizona_base_GOAT_B.Dct2lowpasscurrent_gantryAirbag;
  } else {
    /* Switch: '<S10>/Switch current_yr' */
    Arizona_base_GOAT_B.gantryx_Rmotorvoltage =
      Arizona_base_GOAT_B.Sumcurrentx_R;
  }

  /* End of Switch: '<S10>/Switch current_yr' */

  /* Gain: '<S5>/Gain gantry x2 motor current1' */
  Arizona_base_GOAT_B.gantryx1motorvoltage =
    Arizona_base_GOAT_cal->Gaingantryx2motorcurrent1_Gain *
    Arizona_base_GOAT_B.gantryx_Rmotorvoltage;

  /* Sum: '<S1>/Sum current x_L' */
  Arizona_base_GOAT_B.Sumcurrentx_L = Arizona_base_GOAT_B.Gainonu_x -
    Arizona_base_GOAT_B.Gainonu_phi;

  /* Switch: '<S10>/Switch current_yl' */
  if (Arizona_base_GOAT_B.enableAirbags != 0.0) {
    /* Switch: '<S10>/Switch current_yl' */
    Arizona_base_GOAT_B.gantryx_Lmotorvoltage =
      Arizona_base_GOAT_B.Dct2lowpasscurrent_gantryAirbag;
  } else {
    /* Switch: '<S10>/Switch current_yl' */
    Arizona_base_GOAT_B.gantryx_Lmotorvoltage =
      Arizona_base_GOAT_B.Sumcurrentx_L;
  }

  /* End of Switch: '<S10>/Switch current_yl' */

  /* Gain: '<S5>/Gain gantry x2 motor current' */
  Arizona_base_GOAT_B.gantryx2motorvoltage =
    Arizona_base_GOAT_cal->Gaingantryx2motorcurrent_Gain *
    Arizona_base_GOAT_B.gantryx_Lmotorvoltage;

  /* S-Function (dlowpass2): '<S10>/Dct2lowpass current_carriageAirbag' */

  /* Level2 S-Function Block: '<S10>/Dct2lowpass current_carriageAirbag' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[19];
    sfcnOutputs(rts,0);
  }

  /* DiscreteStateSpace: '<S6>/Internal' */
  {
    Arizona_base_GOAT_B.Internal_g = (Arizona_base_GOAT_cal->Internal_C_l[0])*
      Arizona_base_GOAT_DW.Internal_DSTATE_h[0]
      + (Arizona_base_GOAT_cal->Internal_C_l[1])*
      Arizona_base_GOAT_DW.Internal_DSTATE_h[1];
    Arizona_base_GOAT_B.Internal_g += Arizona_base_GOAT_cal->Internal_D_f*
      Arizona_base_GOAT_B.e_ym;
  }

  /* Sum: '<Root>/Sum current y' */
  Arizona_base_GOAT_B.u_yV = Arizona_base_GOAT_B.f_y +
    Arizona_base_GOAT_B.Internal_g;

  /* Switch: '<S10>/Switch current_x' */
  if (Arizona_base_GOAT_B.enableAirbags != 0.0) {
    /* Switch: '<S10>/Switch current_x' */
    Arizona_base_GOAT_B.carriagemotorvoltage =
      Arizona_base_GOAT_B.Dct2lowpasscurrent_carriageAirb;
  } else {
    /* Switch: '<S10>/Switch current_x' */
    Arizona_base_GOAT_B.carriagemotorvoltage = Arizona_base_GOAT_B.u_yV;
  }

  /* End of Switch: '<S10>/Switch current_x' */

  /* Gain: '<S5>/Gain carriage motor current' */
  Arizona_base_GOAT_B.carriagemotorvoltage_o =
    Arizona_base_GOAT_cal->Gaincarriagemotorcurrent_Gain *
    Arizona_base_GOAT_B.carriagemotorvoltage;

  /* S-Function (sg_IO141_IO142_da_s): '<S5>/Analog output 2' */

  /* Level2 S-Function Block: '<S5>/Analog output 2' (sg_IO141_IO142_da_s) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[20];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S10>/Enable_amplifier_y' */
  Arizona_base_GOAT_B.carriageamplifierenable =
    Arizona_base_GOAT_cal->Enable_amplifier_y_Value;

  /* S-Function (sg_fpga_do_sf_a2): '<S5>/DO Inhibit Carriage' */

  /* Level2 S-Function Block: '<S5>/DO Inhibit Carriage' (sg_fpga_do_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[21];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S10>/Enable_amplifier_xR' */
  Arizona_base_GOAT_B.gantryx_Ramplifierenable =
    Arizona_base_GOAT_cal->Enable_amplifier_xR_Value;

  /* S-Function (sg_fpga_do_sf_a2): '<S5>/DO Inhibit Gantry x1 = Gantry xR' */

  /* Level2 S-Function Block: '<S5>/DO Inhibit Gantry x1 = Gantry xR' (sg_fpga_do_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[22];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S10>/Enable_amplifier_xL' */
  Arizona_base_GOAT_B.gantryx_Lamplifierenable =
    Arizona_base_GOAT_cal->Enable_amplifier_xL_Value;

  /* S-Function (sg_fpga_do_sf_a2): '<S5>/DO Inhibit Gantry x2 = DO Gantry xL' */

  /* Level2 S-Function Block: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL' (sg_fpga_do_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[23];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_qad_sf_5): '<S5>/Cariage secundair' */

  /* Level2 S-Function Block: '<S5>/Cariage secundair' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[24];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S5>/Calibration4' */
  Arizona_base_GOAT_B.Calibration4 = Arizona_base_GOAT_cal->Calibration4_Gain *
    Arizona_base_GOAT_B.Cariagesecundair;

  /* Gain: '<S5>/Gain8' */
  Arizona_base_GOAT_B.y_secundairm = Arizona_base_GOAT_cal->Gain8_Gain_l *
    Arizona_base_GOAT_B.Calibration4;

  /* S-Function (sg_fpga_qad_sf_5): '<S5>/Gantry X1 secundair' */

  /* Level2 S-Function Block: '<S5>/Gantry X1 secundair' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[25];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S5>/Calibration5' */
  Arizona_base_GOAT_B.Calibration5 = Arizona_base_GOAT_cal->Calibration5_Gain *
    Arizona_base_GOAT_B.GantryX1secundair;

  /* Gain: '<S5>/Gain9' */
  Arizona_base_GOAT_B.x_R_secundairm = Arizona_base_GOAT_cal->Gain9_Gain_j *
    Arizona_base_GOAT_B.Calibration5;

  /* S-Function (sg_fpga_qad_sf_5): '<S5>/Gentry X2 secundair' */

  /* Level2 S-Function Block: '<S5>/Gentry X2 secundair' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[26];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S5>/Calibration6' */
  Arizona_base_GOAT_B.Calibration6 = Arizona_base_GOAT_cal->Calibration6_Gain *
    Arizona_base_GOAT_B.GentryX2secundair;

  /* Gain: '<S5>/Gain10' */
  Arizona_base_GOAT_B.x_L_secundairm = Arizona_base_GOAT_cal->Gain10_Gain_n *
    Arizona_base_GOAT_B.Calibration6;

  /* S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Carriage secundair (werkt niet)' */

  /* Level2 S-Function Block: '<S5>/DI Limit Carriage secundair (werkt niet)' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[27];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' */

  /* Level2 S-Function Block: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[28];
    sfcnOutputs(rts,0);
  }

  /* S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' */

  /* Level2 S-Function Block: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[29];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<Root>/startHoming' */
  Arizona_base_GOAT_B.startHoming = Arizona_base_GOAT_cal->startHoming_Value;

  /* Constant: '<Root>/startTrial' */
  Arizona_base_GOAT_B.startTrial = Arizona_base_GOAT_cal->startTrial_Value;

  /* Constant: '<Root>/startPenholder' */
  Arizona_base_GOAT_B.startPenholder =
    Arizona_base_GOAT_cal->startPenholder_Value;

  /* Constant: '<Root>/PenColor' */
  Arizona_base_GOAT_B.PenColor = Arizona_base_GOAT_cal->PenColor_Value;

  /* Chart: '<Root>/Trial control without penholder' */
  /* Gateway: Trial control without penholder */
  Arizona_base_GOAT_DW.sfEvent = Arizona_base_GOAT_CALL_EVENT;

  /* During: Trial control without penholder */
  if (Arizona_base_GOAT_DW.is_active_c5_Arizona_base_GOAT == 0U) {
    /* Entry: Trial control without penholder */
    Arizona_base_GOAT_DW.is_active_c5_Arizona_base_GOAT = 1U;

    /* Entry Internal: Trial control without penholder */
    /* Transition: '<S12>:168' */
    Arizona_base_GOAT_DW.is_c5_Arizona_base_GOAT = Arizona_base_GOAT_IN_idle;

    /* Entry 'idle': '<S12>:194' */
    Arizona_base_GOAT_B.trialTrigger_e = 0.0;
    Arizona_base_GOAT_B.homeTrigger = 0.0;
  } else {
    switch (Arizona_base_GOAT_DW.is_c5_Arizona_base_GOAT) {
     case Arizona_base_GOAT_IN_Home:
      Arizona_base_GOAT_B.homeTrigger = 1.0;

      /* During 'Home': '<S12>:167' */
      /* Transition if home is completed. */
      if (Arizona_base_GOAT_B.DataTypeConversionendtrial != 0.0) {
        /* Transition: '<S12>:191' */
        Arizona_base_GOAT_DW.is_c5_Arizona_base_GOAT = Arizona_base_GOAT_IN_idle;

        /* Entry 'idle': '<S12>:194' */
        Arizona_base_GOAT_B.trialTrigger_e = 0.0;
        Arizona_base_GOAT_B.homeTrigger = 0.0;
      }
      break;

     case Arizona_base_GOAT_IN_idle:
      Arizona_base_GOAT_B.trialTrigger_e = 0.0;
      Arizona_base_GOAT_B.homeTrigger = 0.0;

      /* During 'idle': '<S12>:194' */
      /* Redo homing during run. */
      if (Arizona_base_GOAT_B.startHoming != 0.0) {
        /* Transition: '<S12>:198' */
        Arizona_base_GOAT_DW.is_c5_Arizona_base_GOAT = Arizona_base_GOAT_IN_Home;

        /* Entry 'Home': '<S12>:167' */
        Arizona_base_GOAT_B.homeTrigger = 1.0;

        /* Start ILC trial */
      } else if (Arizona_base_GOAT_B.startTrial != 0.0) {
        /* Transition: '<S12>:196' */
        Arizona_base_GOAT_DW.is_c5_Arizona_base_GOAT =
          Arizona_base_GOAT_IN_trial;

        /* Entry 'trial': '<S12>:192' */
        Arizona_base_GOAT_B.trialTrigger_e = 1.0;
        Arizona_base_GOAT_DW.timeIndex = 0.0;
        Arizona_base_GOAT_B.trialIndex++;
      }
      break;

     default:
      Arizona_base_GOAT_B.trialTrigger_e = 1.0;

      /* During 'trial': '<S12>:192' */
      /* Transition if trial is ended. */
      if (Arizona_base_GOAT_B.Compare_h2) {
        /* Transition: '<S12>:188' */
        Arizona_base_GOAT_DW.is_c5_Arizona_base_GOAT = Arizona_base_GOAT_IN_idle;

        /* Entry 'idle': '<S12>:194' */
        Arizona_base_GOAT_B.trialTrigger_e = 0.0;
        Arizona_base_GOAT_B.homeTrigger = 0.0;
      } else {
        Arizona_base_GOAT_DW.timeIndex++;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Trial control without penholder' */
  /* Switch: '<S19>/Switch' */
  if (Arizona_base_GOAT_B.Delay2 > Arizona_base_GOAT_cal->Switch_Threshold_l) {
    /* Switch: '<S19>/Switch' */
    Arizona_base_GOAT_B.Memory_loop_phi = Arizona_base_GOAT_B.Delay1_b;
  } else {
    /* Switch: '<S19>/Switch' */
    Arizona_base_GOAT_B.Memory_loop_phi = Arizona_base_GOAT_B.Switch1_c;
  }

  /* End of Switch: '<S19>/Switch' */
  /* Switch: '<S20>/Switch' */
  if (Arizona_base_GOAT_B.Delay2 > Arizona_base_GOAT_cal->Switch_Threshold_b) {
    /* Switch: '<S20>/Switch' */
    Arizona_base_GOAT_B.Memory_loop_x = Arizona_base_GOAT_B.Delay1_g;
  } else {
    /* Switch: '<S20>/Switch' */
    Arizona_base_GOAT_B.Memory_loop_x = Arizona_base_GOAT_B.Switch1_h;
  }

  /* End of Switch: '<S20>/Switch' */
  /* Switch: '<S21>/Switch' */
  if (Arizona_base_GOAT_B.Delay2 > Arizona_base_GOAT_cal->Switch_Threshold_o) {
    /* Switch: '<S21>/Switch' */
    Arizona_base_GOAT_B.Memory_loop_y = Arizona_base_GOAT_B.Delay1;
  } else {
    /* Switch: '<S21>/Switch' */
    Arizona_base_GOAT_B.Memory_loop_y = Arizona_base_GOAT_B.Switch1;
  }

  /* End of Switch: '<S21>/Switch' */
  /* Switch: '<Root>/Switch1' incorporates:
   *  Switch: '<Root>/Switch'
   */
  if (Arizona_base_GOAT_B.trialTrigger_e != 0.0) {
    /* Switch: '<Root>/Switch1' */
    Arizona_base_GOAT_B.Switch1_hm =
      Arizona_base_GOAT_B.DirectLookupTablechange_color;
  } else {
    if (Arizona_base_GOAT_B.DataTypeConversionendtrial != 0.0) {
      /* Switch: '<Root>/Switch' */
      Arizona_base_GOAT_B.Switch_b = Arizona_base_GOAT_B.change_color;
    } else {
      /* Switch: '<Root>/Switch' */
      Arizona_base_GOAT_B.Switch_b = Arizona_base_GOAT_B.change_color_j;
    }

    /* Switch: '<Root>/Switch1' */
    Arizona_base_GOAT_B.Switch1_hm = Arizona_base_GOAT_B.Switch_b;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  Arizona_base_GOAT_B.DataTypeConversion2 = 0.0;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  Arizona_base_GOAT_B.DataTypeConversion1 = 0.0;

  /* DataTypeConversion: '<S9>/Data Type Conversion3' */
  Arizona_base_GOAT_B.DataTypeConversion3 = 0.0;

  /* Chart: '<S9>/Change color Chart' */
  if (Arizona_base_GOAT_DW.temporalCounter_i1_b < 127U) {
    Arizona_base_GOAT_DW.temporalCounter_i1_b = static_cast<uint8_T>
      (Arizona_base_GOAT_DW.temporalCounter_i1_b + 1U);
  }

  if (Arizona_base_GOAT_DW.temporalCounter_i2 < 1023U) {
    Arizona_base_GOAT_DW.temporalCounter_i2 = static_cast<uint16_T>
      (Arizona_base_GOAT_DW.temporalCounter_i2 + 1U);
  }

  if (Arizona_base_GOAT_DW.temporalCounter_i3 < 127U) {
    Arizona_base_GOAT_DW.temporalCounter_i3 = static_cast<uint8_T>
      (Arizona_base_GOAT_DW.temporalCounter_i3 + 1U);
  }

  /* Gateway: Penholder mechanism1/Change color Chart */
  Arizona_base_GOAT_DW.sfEvent_l = Arizona_base_GOAT_CALL_EVENT;

  /* During: Penholder mechanism1/Change color Chart */
  if (Arizona_base_GOAT_DW.is_active_c4_Arizona_base_GOAT == 0U) {
    /* Entry: Penholder mechanism1/Change color Chart */
    Arizona_base_GOAT_DW.is_active_c4_Arizona_base_GOAT = 1U;

    /* Entry Internal: Penholder mechanism1/Change color Chart */
    /* Transition: '<S31>:278' */
    Arizona_base_GOAT_DW.is_c4_Arizona_base_GOAT =
      Arizona_base__IN_MOVE_PENHOLDER;

    /* Entry Internal 'MOVE_PENHOLDER': '<S31>:275' */
    Arizona_base_GOAT_DW.is_active_MAIN = 1U;

    /* Entry Internal 'MAIN': '<S31>:274' */
    /* Transition: '<S31>:283' */
    Arizona_base_GOAT_DW.is_MAIN = Arizona_base_GOAT_IN_INITIAL;

    /* Entry 'INITIAL': '<S31>:299' */
    Arizona_base_GOAT_B.active = 0.0;
    Arizona_base_GOAT_DW.job = 0.0;
    Arizona_base_GOAT_DW.is_active_VERTICAL = 1U;

    /* Entry Internal 'VERTICAL': '<S31>:228' */
    /* Transition: '<S31>:258' */
    Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_GOAT_IN_INITIAL_j;
    Arizona_base_GOAT_DW.is_active_ROTATION = 1U;

    /* Entry Internal 'ROTATION': '<S31>:356' */
    /* Transition: '<S31>:350' */
    Arizona_base_GOAT_DW.is_ROTATION = Arizona_base_GOAT_IN_INITIAL_jz;
    Arizona_base_GOAT_DW.temporalCounter_i2 = 0U;

    /* Entry 'INITIAL': '<S31>:354' */
    Arizona_base_GOAT_DW.color_pos = 1.0;
    Arizona_base_GOAT_DW.is_active_HOME = 1U;

    /* Entry Internal 'HOME': '<S31>:398' */
    /* Transition: '<S31>:400' */
    Arizona_base_GOAT_DW.is_HOME = Arizona_base_GOA_IN_INITIAL_jzy;
  } else if (Arizona_base_GOAT_DW.is_c4_Arizona_base_GOAT ==
             Arizona_base__IN_MOVE_PENHOLDER) {
    /* During 'MOVE_PENHOLDER': '<S31>:275' */
    if (Arizona_base_GOAT_DW.is_active_MAIN != 0U) {
      Arizona_base_GOAT_MAIN();
    }

    if (Arizona_base_GOAT_DW.is_active_VERTICAL != 0U) {
      Arizona_base_GOAT_VERTICAL();
    }

    if (Arizona_base_GOAT_DW.is_active_ROTATION != 0U) {
      Arizona_base_GOAT_ROTATION();
    }

    if (Arizona_base_GOAT_DW.is_active_HOME != 0U) {
      Arizona_base_GOAT_HOME();
    }
  }

  /* End of Chart: '<S9>/Change color Chart' */

  /* Gain: '<S9>/log_jogspeed' */
  Arizona_base_GOAT_B.jogSpeed = Arizona_base_GOAT_cal->log_jogspeed_Gain *
    Arizona_base_GOAT_B.jogspeed_Theta;

  /* Gain: '<S9>/Gain on phi2' */
  Arizona_base_GOAT_B.Gainonphi2 = Arizona_base_GOAT_cal->Gainonphi2_Gain *
    Arizona_base_GOAT_B.jogSpeed;

  /* Abs: '<S32>/Abs' */
  Arizona_base_GOAT_B.Abs = std::abs(Arizona_base_GOAT_B.Gainonphi2);

  /* RelationalOperator: '<S34>/Compare' incorporates:
   *  Constant: '<S34>/Constant'
   */
  Arizona_base_GOAT_B.Compare = (Arizona_base_GOAT_B.Abs >
    Arizona_base_GOAT_cal->Constant_Value_a);

  /* DataTypeConversion: '<S32>/Data Type Conversion' */
  Arizona_base_GOAT_B.DataTypeConversion = Arizona_base_GOAT_B.Compare;

  /* Abs: '<S35>/Abs' incorporates:
   *  Constant: '<S35>/dutycycle blockwave'
   */
  Arizona_base_GOAT_B.Abs_d = std::abs
    (Arizona_base_GOAT_cal->dutycycleblockwave_Value);

  /* Gain: '<S35>/Gain1' */
  Arizona_base_GOAT_B.Gain1 = Arizona_base_GOAT_cal->Gain1_Gain_o *
    Arizona_base_GOAT_B.Gainonphi2;

  /* Abs: '<S35>/Abs1' */
  Arizona_base_GOAT_B.Abs1 = std::abs(Arizona_base_GOAT_B.Gain1);

  /* RelationalOperator: '<S36>/Compare' incorporates:
   *  Constant: '<S36>/Constant'
   */
  Arizona_base_GOAT_B.Compare_p = (Arizona_base_GOAT_B.Abs1 >=
    Arizona_base_GOAT_cal->CompareToConstant_const);

  /* Switch: '<S35>/Switch' */
  if (Arizona_base_GOAT_B.Compare_p) {
    /* Switch: '<S35>/Switch' */
    Arizona_base_GOAT_B.Switch = Arizona_base_GOAT_B.Abs1;
  } else {
    /* Switch: '<S35>/Switch' incorporates:
     *  Constant: '<S35>/dutycycle blockwave1'
     */
    Arizona_base_GOAT_B.Switch =
      Arizona_base_GOAT_cal->dutycycleblockwave1_Value;
  }

  /* End of Switch: '<S35>/Switch' */

  /* Product: '<S35>/Divide' incorporates:
   *  Constant: '<S35>/basefreq'
   */
  Arizona_base_GOAT_B.Divide = 1.0 / Arizona_base_GOAT_B.Switch *
    Arizona_base_GOAT_cal->basefreq_Value;

  /* Gain: '<S35>/Gain' */
  Arizona_base_GOAT_B.Gain = Arizona_base_GOAT_cal->Gain_Gain_c *
    Arizona_base_GOAT_B.Abs_d;

  /* Sum: '<S35>/Subtract' incorporates:
   *  Constant: '<S35>/PWM1'
   */
  Arizona_base_GOAT_B.Subtract = Arizona_base_GOAT_cal->PWM1_Value -
    Arizona_base_GOAT_B.Gain;

  /* Product: '<S35>/Divide1' */
  Arizona_base_GOAT_B.Divide1 = Arizona_base_GOAT_B.Subtract *
    Arizona_base_GOAT_B.Divide;

  /* Product: '<S35>/Divide2' */
  Arizona_base_GOAT_B.Divide2 = Arizona_base_GOAT_B.Gain *
    Arizona_base_GOAT_B.Divide;

  /* Product: '<S35>/Divide3' */
  Arizona_base_GOAT_B.Divide3 = Arizona_base_GOAT_B.Divide1 * static_cast<real_T>
    (Arizona_base_GOAT_B.Compare_p);

  /* Gain: '<S35>/Gain8' */
  Arizona_base_GOAT_B.Gain8 = Arizona_base_GOAT_cal->Gain8_Gain_e *
    Arizona_base_GOAT_B.Gain1;

  /* Signum: '<S35>/Sign2' */
  u1 = Arizona_base_GOAT_B.Gain8;
  if (rtIsNaN(u1)) {
    /* Signum: '<S35>/Sign2' */
    Arizona_base_GOAT_B.Sign2 = u1;
  } else if (u1 < 0.0) {
    /* Signum: '<S35>/Sign2' */
    Arizona_base_GOAT_B.Sign2 = -1.0;
  } else {
    /* Signum: '<S35>/Sign2' */
    Arizona_base_GOAT_B.Sign2 = (u1 > 0.0);
  }

  /* End of Signum: '<S35>/Sign2' */

  /* Saturate: '<S35>/Saturation2' */
  u0 = Arizona_base_GOAT_B.Sign2;
  u1 = Arizona_base_GOAT_cal->Saturation2_LowerSat;
  u2 = Arizona_base_GOAT_cal->Saturation2_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S35>/Saturation2' */
    Arizona_base_GOAT_B.XtranMo_DIR = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S35>/Saturation2' */
    Arizona_base_GOAT_B.XtranMo_DIR = u1;
  } else {
    /* Saturate: '<S35>/Saturation2' */
    Arizona_base_GOAT_B.XtranMo_DIR = u0;
  }

  /* End of Saturate: '<S35>/Saturation2' */

  /* Gain: '<S9>/Gain on phi3' */
  Arizona_base_GOAT_B.Gainonphi3 = Arizona_base_GOAT_cal->Gainonphi3_Gain *
    Arizona_base_GOAT_B.jogspeed_Z;

  /* Abs: '<S33>/Abs1' */
  Arizona_base_GOAT_B.Abs1_l = std::abs(Arizona_base_GOAT_B.Gainonphi3);

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S37>/Constant'
   */
  Arizona_base_GOAT_B.Compare_l = (Arizona_base_GOAT_B.Abs1_l >
    Arizona_base_GOAT_cal->Constant_Value_l);

  /* DataTypeConversion: '<S33>/Data Type Conversion1' */
  Arizona_base_GOAT_B.DataTypeConversion1_n = Arizona_base_GOAT_B.Compare_l;

  /* Abs: '<S38>/Abs' incorporates:
   *  Constant: '<S38>/dutycycle blockwave'
   */
  Arizona_base_GOAT_B.Abs_dw = std::abs
    (Arizona_base_GOAT_cal->dutycycleblockwave_Value_h);

  /* Gain: '<S38>/Gain1' */
  Arizona_base_GOAT_B.Gain1_d = Arizona_base_GOAT_cal->Gain1_Gain_i *
    Arizona_base_GOAT_B.Gainonphi3;

  /* Abs: '<S38>/Abs1' */
  Arizona_base_GOAT_B.Abs1_m = std::abs(Arizona_base_GOAT_B.Gain1_d);

  /* RelationalOperator: '<S39>/Compare' incorporates:
   *  Constant: '<S39>/Constant'
   */
  Arizona_base_GOAT_B.Compare_h = (Arizona_base_GOAT_B.Abs1_m >=
    Arizona_base_GOAT_cal->CompareToConstant_const_n);

  /* Switch: '<S38>/Switch' */
  if (Arizona_base_GOAT_B.Compare_h) {
    /* Switch: '<S38>/Switch' */
    Arizona_base_GOAT_B.Switch_i = Arizona_base_GOAT_B.Abs1_m;
  } else {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S38>/dutycycle blockwave1'
     */
    Arizona_base_GOAT_B.Switch_i =
      Arizona_base_GOAT_cal->dutycycleblockwave1_Value_k;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Product: '<S38>/Divide' incorporates:
   *  Constant: '<S38>/basefreq'
   */
  Arizona_base_GOAT_B.Divide_b = 1.0 / Arizona_base_GOAT_B.Switch_i *
    Arizona_base_GOAT_cal->basefreq_Value_i;

  /* Gain: '<S38>/Gain' */
  Arizona_base_GOAT_B.Gain_b = Arizona_base_GOAT_cal->Gain_Gain_f *
    Arizona_base_GOAT_B.Abs_dw;

  /* Sum: '<S38>/Subtract' incorporates:
   *  Constant: '<S38>/PWM1'
   */
  Arizona_base_GOAT_B.Subtract_g = Arizona_base_GOAT_cal->PWM1_Value_l -
    Arizona_base_GOAT_B.Gain_b;

  /* Product: '<S38>/Divide1' */
  Arizona_base_GOAT_B.Divide1_c = Arizona_base_GOAT_B.Subtract_g *
    Arizona_base_GOAT_B.Divide_b;

  /* Product: '<S38>/Divide2' */
  Arizona_base_GOAT_B.Divide2_c = Arizona_base_GOAT_B.Gain_b *
    Arizona_base_GOAT_B.Divide_b;

  /* Product: '<S38>/Divide3' */
  Arizona_base_GOAT_B.Divide3_g = Arizona_base_GOAT_B.Divide1_c *
    static_cast<real_T>(Arizona_base_GOAT_B.Compare_h);

  /* Gain: '<S38>/Gain8' */
  Arizona_base_GOAT_B.Gain8_o = Arizona_base_GOAT_cal->Gain8_Gain_c *
    Arizona_base_GOAT_B.Gain1_d;

  /* Signum: '<S38>/Sign2' */
  u1 = Arizona_base_GOAT_B.Gain8_o;
  if (rtIsNaN(u1)) {
    /* Signum: '<S38>/Sign2' */
    Arizona_base_GOAT_B.Sign2_g = u1;
  } else if (u1 < 0.0) {
    /* Signum: '<S38>/Sign2' */
    Arizona_base_GOAT_B.Sign2_g = -1.0;
  } else {
    /* Signum: '<S38>/Sign2' */
    Arizona_base_GOAT_B.Sign2_g = (u1 > 0.0);
  }

  /* End of Signum: '<S38>/Sign2' */

  /* Saturate: '<S38>/Saturation2' */
  u0 = Arizona_base_GOAT_B.Sign2_g;
  u1 = Arizona_base_GOAT_cal->Saturation2_LowerSat_e;
  u2 = Arizona_base_GOAT_cal->Saturation2_UpperSat_m;
  if (u0 > u2) {
    /* Saturate: '<S38>/Saturation2' */
    Arizona_base_GOAT_B.XtranMo_DIR_k = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S38>/Saturation2' */
    Arizona_base_GOAT_B.XtranMo_DIR_k = u1;
  } else {
    /* Saturate: '<S38>/Saturation2' */
    Arizona_base_GOAT_B.XtranMo_DIR_k = u0;
  }

  /* End of Saturate: '<S38>/Saturation2' */
  /* Update for Delay: '<Root>/log_penholder_active' */
  Arizona_base_GOAT_DW.log_penholder_active_DSTATE = Arizona_base_GOAT_B.active;

  /* Update for Delay: '<Root>/Delay2' */
  Arizona_base_GOAT_DW.Delay2_DSTATE = Arizona_base_GOAT_B.homeTrigger;

  /* Update for Delay: '<S21>/Delay1' */
  Arizona_base_GOAT_DW.Delay1_DSTATE = Arizona_base_GOAT_B.Memory_loop_y;

  /* Update for Delay: '<S21>/Delay' */
  Arizona_base_GOAT_DW.Delay_DSTATE = Arizona_base_GOAT_B.Delay2;

  /* Update for Delay: '<Root>/Delay1' */
  Arizona_base_GOAT_DW.Delay1_DSTATE_g = Arizona_base_GOAT_B.trialTrigger_e;

  /* Update for UnitDelay: '<S41>/UD' */
  Arizona_base_GOAT_DW.UD_DSTATE = Arizona_base_GOAT_B.TSamp;

  /* Update for Delay: '<S20>/Delay1' */
  Arizona_base_GOAT_DW.Delay1_DSTATE_i = Arizona_base_GOAT_B.Memory_loop_x;

  /* Update for Delay: '<S20>/Delay' */
  Arizona_base_GOAT_DW.Delay_DSTATE_j = Arizona_base_GOAT_B.Delay2;

  /* Update for UnitDelay: '<S40>/UD' */
  Arizona_base_GOAT_DW.UD_DSTATE_a = Arizona_base_GOAT_B.TSamp_n;

  /* Update for Delay: '<S19>/Delay1' */
  Arizona_base_GOAT_DW.Delay1_DSTATE_o = Arizona_base_GOAT_B.Memory_loop_phi;

  /* Update for Delay: '<S19>/Delay' */
  Arizona_base_GOAT_DW.Delay_DSTATE_h = Arizona_base_GOAT_B.Delay2;

  /* Update for DiscreteStateSpace: '<S7>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (Arizona_base_GOAT_cal->Internal_A[0])*
      Arizona_base_GOAT_DW.Internal_DSTATE[0]
      + (Arizona_base_GOAT_cal->Internal_A[1])*
      Arizona_base_GOAT_DW.Internal_DSTATE[1];
    xnew[0] += (Arizona_base_GOAT_cal->Internal_B[0])*Arizona_base_GOAT_B.e_xm;
    xnew[1] = (Arizona_base_GOAT_cal->Internal_A[2])*
      Arizona_base_GOAT_DW.Internal_DSTATE[1];
    xnew[1] += (Arizona_base_GOAT_cal->Internal_B[1])*Arizona_base_GOAT_B.e_xm;
    (void) std::memcpy(&Arizona_base_GOAT_DW.Internal_DSTATE[0], xnew,
                       sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S8>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (Arizona_base_GOAT_cal->Internal_A_p[0])*
      Arizona_base_GOAT_DW.Internal_DSTATE_l[0]
      + (Arizona_base_GOAT_cal->Internal_A_p[1])*
      Arizona_base_GOAT_DW.Internal_DSTATE_l[1];
    xnew[1] = (Arizona_base_GOAT_cal->Internal_A_p[2])*
      Arizona_base_GOAT_DW.Internal_DSTATE_l[0]
      + (Arizona_base_GOAT_cal->Internal_A_p[3])*
      Arizona_base_GOAT_DW.Internal_DSTATE_l[1]
      + (Arizona_base_GOAT_cal->Internal_A_p[4])*
      Arizona_base_GOAT_DW.Internal_DSTATE_l[2];
    xnew[1] += (Arizona_base_GOAT_cal->Internal_B_g[0])*
      Arizona_base_GOAT_B.e_phirad;
    xnew[2] = (Arizona_base_GOAT_cal->Internal_A_p[5])*
      Arizona_base_GOAT_DW.Internal_DSTATE_l[2];
    xnew[2] += (Arizona_base_GOAT_cal->Internal_B_g[1])*
      Arizona_base_GOAT_B.e_phirad;
    (void) std::memcpy(&Arizona_base_GOAT_DW.Internal_DSTATE_l[0], xnew,
                       sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S6>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (Arizona_base_GOAT_cal->Internal_A_g[0])*
      Arizona_base_GOAT_DW.Internal_DSTATE_h[0]
      + (Arizona_base_GOAT_cal->Internal_A_g[1])*
      Arizona_base_GOAT_DW.Internal_DSTATE_h[1];
    xnew[0] += (Arizona_base_GOAT_cal->Internal_B_j[0])*Arizona_base_GOAT_B.e_ym;
    xnew[1] = (Arizona_base_GOAT_cal->Internal_A_g[2])*
      Arizona_base_GOAT_DW.Internal_DSTATE_h[1];
    xnew[1] += (Arizona_base_GOAT_cal->Internal_B_j[1])*Arizona_base_GOAT_B.e_ym;
    (void) std::memcpy(&Arizona_base_GOAT_DW.Internal_DSTATE_h[0], xnew,
                       sizeof(real_T)*2);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Arizona_base_GOAT_M->Timing.clockTick0)) {
    ++Arizona_base_GOAT_M->Timing.clockTickH0;
  }

  Arizona_base_GOAT_M->Timing.t[0] = Arizona_base_GOAT_M->Timing.clockTick0 *
    Arizona_base_GOAT_M->Timing.stepSize0 +
    Arizona_base_GOAT_M->Timing.clockTickH0 *
    Arizona_base_GOAT_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Arizona_base_GOAT_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtsiSetSolverName(&Arizona_base_GOAT_M->solverInfo,"FixedStepDiscrete");
  Arizona_base_GOAT_M->solverInfoPtr = (&Arizona_base_GOAT_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Arizona_base_GOAT_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Arizona_base_GOAT_M points to
       static memory which is guaranteed to be non-NULL" */
    Arizona_base_GOAT_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Arizona_base_GOAT_M->Timing.sampleTimes =
      (&Arizona_base_GOAT_M->Timing.sampleTimesArray[0]);
    Arizona_base_GOAT_M->Timing.offsetTimes =
      (&Arizona_base_GOAT_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Arizona_base_GOAT_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    Arizona_base_GOAT_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Arizona_base_GOAT_M, &Arizona_base_GOAT_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Arizona_base_GOAT_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Arizona_base_GOAT_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Arizona_base_GOAT_M, -1);
  Arizona_base_GOAT_M->Timing.stepSize0 = 0.001;
  Arizona_base_GOAT_M->solverInfoPtr = (&Arizona_base_GOAT_M->solverInfo);
  Arizona_base_GOAT_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Arizona_base_GOAT_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Arizona_base_GOAT_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) std::memset((static_cast<void *>(&Arizona_base_GOAT_B)), 0,
                     sizeof(B_Arizona_base_GOAT_T));

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&Arizona_base_GOAT_DW), 0,
                     sizeof(DW_Arizona_base_GOAT_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Arizona_base_GOAT_M->NonInlinedSFcns.sfcnInfo;
    Arizona_base_GOAT_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Arizona_base_GOAT_M)));
    Arizona_base_GOAT_M->Sizes.numSampTimes = (1);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &Arizona_base_GOAT_M->Sizes.numSampTimes);
    Arizona_base_GOAT_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (Arizona_base_GOAT_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,Arizona_base_GOAT_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Arizona_base_GOAT_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Arizona_base_GOAT_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Arizona_base_GOAT_M));
    rtssSetStepSizePtr(sfcnInfo, &Arizona_base_GOAT_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Arizona_base_GOAT_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Arizona_base_GOAT_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Arizona_base_GOAT_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Arizona_base_GOAT_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &Arizona_base_GOAT_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Arizona_base_GOAT_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Arizona_base_GOAT_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Arizona_base_GOAT_M->solverInfoPtr);
  }

  Arizona_base_GOAT_M->Sizes.numSFcns = (30);

  /* register each child */
  {
    (void) std::memset(static_cast<void *>
                       (&Arizona_base_GOAT_M->NonInlinedSFcns.childSFunctions[0]),
                       0,
                       30*sizeof(SimStruct));
    Arizona_base_GOAT_M->childSfunctions =
      (&Arizona_base_GOAT_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 30; i++) {
        Arizona_base_GOAT_M->childSfunctions[i] =
          (&Arizona_base_GOAT_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Arizona_base_GOAT/<S16>/Dct2lowpass x1JogSpeed (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[0]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &Arizona_base_GOAT_B.jogspeed_xR_reset_f;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.jogspeed_xR_reset));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass x1JogSpeed");
      ssSetPath(rts,
                "Arizona_base_GOAT/Homing/Enabled subsystem/Reset/Dct2lowpass x1JogSpeed");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassx1JogSpeed_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassx1JogSpeed_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassx1JogSpeed_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Arizona_base_GOAT_DW.Dct2lowpassx1JogSpeed_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.Dct2lowpassx1JogSpeed_RWORK[0]);
      }

      /* registration */
      dlowpass2(rts);
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
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Arizona_base_GOAT/<S16>/Dct2lowpass x2JogSpeed (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[1]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &Arizona_base_GOAT_B.jogspeed_xL_reset_j;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.jogspeed_xL_reset));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass x2JogSpeed");
      ssSetPath(rts,
                "Arizona_base_GOAT/Homing/Enabled subsystem/Reset/Dct2lowpass x2JogSpeed");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassx2JogSpeed_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassx2JogSpeed_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassx2JogSpeed_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Arizona_base_GOAT_DW.Dct2lowpassx2JogSpeed_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.Dct2lowpassx2JogSpeed_RWORK[0]);
      }

      /* registration */
      dlowpass2(rts);
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
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Arizona_base_GOAT/<S16>/Dct2lowpass yJogSpeed (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[2]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &Arizona_base_GOAT_B.jogspeed_y_reset_d;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.jogspeed_y_reset));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass yJogSpeed");
      ssSetPath(rts,
                "Arizona_base_GOAT/Homing/Enabled subsystem/Reset/Dct2lowpass yJogSpeed");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassyJogSpeed_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassyJogSpeed_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassyJogSpeed_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Arizona_base_GOAT_DW.Dct2lowpassyJogSpeed_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.Dct2lowpassyJogSpeed_RWORK[0]);
      }

      /* registration */
      dlowpass2(rts);
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
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/Setup 1 (sg_IO141_IO142_setup_s) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[3]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* path info */
      ssSetModelName(rts, "Setup 1");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/Setup 1");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 37);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Arizona_base_GOAT_cal->Setup1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Arizona_base_GOAT_cal->Setup1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Arizona_base_GOAT_cal->Setup1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Arizona_base_GOAT_cal->Setup1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Arizona_base_GOAT_cal->Setup1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Arizona_base_GOAT_cal->Setup1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)Arizona_base_GOAT_cal->Setup1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)Arizona_base_GOAT_cal->Setup1_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)Arizona_base_GOAT_cal->Setup1_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)Arizona_base_GOAT_cal->Setup1_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)Arizona_base_GOAT_cal->Setup1_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)Arizona_base_GOAT_cal->Setup1_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)Arizona_base_GOAT_cal->Setup1_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)Arizona_base_GOAT_cal->Setup1_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)Arizona_base_GOAT_cal->Setup1_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)Arizona_base_GOAT_cal->Setup1_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)Arizona_base_GOAT_cal->Setup1_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)Arizona_base_GOAT_cal->Setup1_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)Arizona_base_GOAT_cal->Setup1_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)Arizona_base_GOAT_cal->Setup1_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)Arizona_base_GOAT_cal->Setup1_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)Arizona_base_GOAT_cal->Setup1_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)Arizona_base_GOAT_cal->Setup1_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)Arizona_base_GOAT_cal->Setup1_P24_Size);
        ssSetSFcnParam(rts, 24, (mxArray*)Arizona_base_GOAT_cal->Setup1_P25_Size);
        ssSetSFcnParam(rts, 25, (mxArray*)Arizona_base_GOAT_cal->Setup1_P26_Size);
        ssSetSFcnParam(rts, 26, (mxArray*)Arizona_base_GOAT_cal->Setup1_P27_Size);
        ssSetSFcnParam(rts, 27, (mxArray*)Arizona_base_GOAT_cal->Setup1_P28_Size);
        ssSetSFcnParam(rts, 28, (mxArray*)Arizona_base_GOAT_cal->Setup1_P29_Size);
        ssSetSFcnParam(rts, 29, (mxArray*)Arizona_base_GOAT_cal->Setup1_P30_Size);
        ssSetSFcnParam(rts, 30, (mxArray*)Arizona_base_GOAT_cal->Setup1_P31_Size);
        ssSetSFcnParam(rts, 31, (mxArray*)Arizona_base_GOAT_cal->Setup1_P32_Size);
        ssSetSFcnParam(rts, 32, (mxArray*)Arizona_base_GOAT_cal->Setup1_P33_Size);
        ssSetSFcnParam(rts, 33, (mxArray*)Arizona_base_GOAT_cal->Setup1_P34_Size);
        ssSetSFcnParam(rts, 34, (mxArray*)Arizona_base_GOAT_cal->Setup1_P35_Size);
        ssSetSFcnParam(rts, 35, (mxArray*)Arizona_base_GOAT_cal->Setup1_P36_Size);
        ssSetSFcnParam(rts, 36, (mxArray*)Arizona_base_GOAT_cal->Setup1_P37_Size);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/Analog input 1 (sg_IO141_IO142_ad_s) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[4]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [4]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn4.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.analogvelin));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidthAsInt(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &Arizona_base_GOAT_B.Analoginput1_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Analog input 1");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/Analog input 1");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Analoginput1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Analoginput1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Analoginput1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->Analoginput1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->Analoginput1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->Analoginput1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_base_GOAT_cal->Analoginput1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_base_GOAT_cal->Analoginput1_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_base_GOAT_cal->Analoginput1_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_base_GOAT_cal->Analoginput1_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_base_GOAT_cal->Analoginput1_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_base_GOAT_cal->Analoginput1_P12_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_base_GOAT_DW.Analoginput1_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.Analoginput1_PWORK[0]);
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
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DI Limit Carriage  (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[5]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [5]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn5.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.DIcarriagelimitswitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI Limit Carriage ");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/DI Limit Carriage ");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitCarriage_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitCarriage_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitCarriage_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitCarriage_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitCarriage_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitCarriage_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_base_GOAT_DW.DILimitCarriage_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.DILimitCarriage_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DI Limit Gantry x1 = Gantry xR (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[6]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [6]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn6.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.DIgantryx1limitswitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI Limit Gantry x1 = Gantry xR");
      ssSetPath(rts,
                "Arizona_base_GOAT/IO Arizona/DI Limit Gantry x1 = Gantry xR");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx1GantryxR_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx1GantryxR_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx1GantryxR_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx1GantryxR_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx1GantryxR_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx1GantryxR_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_base_GOAT_DW.DILimitGantryx1GantryxR_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.DILimitGantryx1GantryxR_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DI Limit Gantry x2 = Gantry xL (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[7]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [7]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn7.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn7.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.DIgantryx2limitswitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI Limit Gantry x2 = Gantry xL");
      ssSetPath(rts,
                "Arizona_base_GOAT/IO Arizona/DI Limit Gantry x2 = Gantry xL");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx2GantryxL_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx2GantryxL_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx2GantryxL_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx2GantryxL_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx2GantryxL_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx2GantryxL_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_base_GOAT_DW.DILimitGantryx2GantryxL_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.DILimitGantryx2GantryxL_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DI black software button (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[8]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [8]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[8]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [8]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn8.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn8.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn8.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.DIblacksoftwarebutton));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI black software button");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/DI black software button");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DIblacksoftwarebutton_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DIblacksoftwarebutton_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DIblacksoftwarebutton_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DIblacksoftwarebutton_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DIblacksoftwarebutton_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DIblacksoftwarebutton_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_base_GOAT_DW.DIblacksoftwarebutton_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.DIblacksoftwarebutton_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DI carriage amp. fault status (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[9]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [9]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[9]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3[9]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4[9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [9]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[9]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn9.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn9.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn9.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.DIcarriageamplifyerstatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI carriage amp. fault status");
      ssSetPath(rts,
                "Arizona_base_GOAT/IO Arizona/DI carriage amp. fault status");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DIcarriageampfaultstatus_P1_Siz);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DIcarriageampfaultstatus_P2_Siz);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DIcarriageampfaultstatus_P3_Siz);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DIcarriageampfaultstatus_P4_Siz);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DIcarriageampfaultstatus_P5_Siz);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DIcarriageampfaultstatus_P6_Siz);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_base_GOAT_DW.DIcarriageampfaultstatus_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn9.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn9.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.DIcarriageampfaultstatus_PWORK
                   [0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DI gantry x1 fault status (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[10]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [10]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[10]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [10]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [10]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [10]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[10]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn10.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn10.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn10.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.DIgantryx1amplifyerstatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI gantry x1 fault status");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/DI gantry x1 fault status");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DIgantryx1faultstatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DIgantryx1faultstatus_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DIgantryx1faultstatus_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DIgantryx1faultstatus_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DIgantryx1faultstatus_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DIgantryx1faultstatus_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_base_GOAT_DW.DIgantryx1faultstatus_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn10.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn10.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.DIgantryx1faultstatus_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DI gantry x2 fault status (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[11]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [11]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[11]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [11]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [11]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [11]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[11]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn11.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn11.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn11.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.DIgantryx2amplifyerstatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI gantry x2 fault status");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/DI gantry x2 fault status");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DIgantryx2faultstatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DIgantryx2faultstatus_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DIgantryx2faultstatus_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DIgantryx2faultstatus_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DIgantryx2faultstatus_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DIgantryx2faultstatus_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_base_GOAT_DW.DIgantryx2faultstatus_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn11.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn11.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.DIgantryx2faultstatus_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DI red software button (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[12]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [12]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[12]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [12]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [12]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [12]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[12]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn12.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn12.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn12.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn12.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.DIredsoftwarefunctionbutton));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI red software button");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/DI red software button");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DIredsoftwarebutton_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DIredsoftwarebutton_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DIredsoftwarebutton_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DIredsoftwarebutton_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DIredsoftwarebutton_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DIredsoftwarebutton_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_base_GOAT_DW.DIredsoftwarebutton_PWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn12.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn12.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.DIredsoftwarebutton_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/Carriage encoder (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[13]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [13]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[13]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [13]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [13]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [13]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [13]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[13]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn13.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn13.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn13.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn13.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.Carriageencoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Carriage encoder");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/Carriage encoder");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       Arizona_base_GOAT_cal->Carriageencoder_P24_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Arizona_base_GOAT_DW.Carriageencoder_RWORK);
      ssSetPWork(rts, (void **) &Arizona_base_GOAT_DW.Carriageencoder_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn13.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn13.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.Carriageencoder_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Arizona_base_GOAT_DW.Carriageencoder_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/Gantry x1 = Gantry xR (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[14];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn14.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn14.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn14.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[14]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [14]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[14]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [14]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [14]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [14]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [14]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[14]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn14.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn14.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn14.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn14.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.Gantryx1GantryxR));
        }
      }

      /* path info */
      ssSetModelName(rts, "Gantry x1 = Gantry xR");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/Gantry x1 = Gantry xR");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn14.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx1GantryxR_P24_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Arizona_base_GOAT_DW.Gantryx1GantryxR_RWORK);
      ssSetPWork(rts, (void **) &Arizona_base_GOAT_DW.Gantryx1GantryxR_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn14.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn14.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.Gantryx1GantryxR_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Arizona_base_GOAT_DW.Gantryx1GantryxR_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/Gantry x2 = Gantry xL (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[15];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn15.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn15.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn15.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[15]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [15]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[15]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [15]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [15]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [15]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [15]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[15]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn15.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn15.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn15.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn15.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.Gantryx2GantryxL));
        }
      }

      /* path info */
      ssSetModelName(rts, "Gantry x2 = Gantry xL");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/Gantry x2 = Gantry xL");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn15.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       Arizona_base_GOAT_cal->Gantryx2GantryxL_P24_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Arizona_base_GOAT_DW.Gantryx2GantryxL_RWORK);
      ssSetPWork(rts, (void **) &Arizona_base_GOAT_DW.Gantryx2GantryxL_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn15.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn15.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.Gantryx2GantryxL_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Arizona_base_GOAT_DW.Gantryx2GantryxL_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S10>/Dct2lowpass output_y (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[16];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[16]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [16]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[16]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [16]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [16]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [16]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [16]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[16]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.UPtrs0;
          sfcnUPtrs[0] = &Arizona_base_GOAT_B.encodercarriage;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.Dct2lowpassoutput_y));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass output_y");
      ssSetPath(rts, "Arizona_base_GOAT/Safety/Dct2lowpass output_y");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassoutput_y_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassoutput_y_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassoutput_y_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Arizona_base_GOAT_DW.Dct2lowpassoutput_y_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn16.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.Dct2lowpassoutput_y_RWORK[0]);
      }

      /* registration */
      dlowpass2(rts);
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
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Arizona_base_GOAT/<S10>/Dct2lowpass output_x (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[17];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[17]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [17]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[17]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [17]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [17]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [17]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [17]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[17]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.UPtrs0;
          sfcnUPtrs[0] = &Arizona_base_GOAT_B.Gainx;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.Dct2lowpassoutput_x));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass output_x");
      ssSetPath(rts, "Arizona_base_GOAT/Safety/Dct2lowpass output_x");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassoutput_x_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassoutput_x_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpassoutput_x_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Arizona_base_GOAT_DW.Dct2lowpassoutput_x_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn17.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.Dct2lowpassoutput_x_RWORK[0]);
      }

      /* registration */
      dlowpass2(rts);
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
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Arizona_base_GOAT/<S10>/Dct2lowpass current_gantryAirbag (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[18];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[18]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [18]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[18]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [18]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [18]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [18]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [18]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[18]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.UPtrs0;
          sfcnUPtrs[0] = &Arizona_base_GOAT_B.current_gantryAirbag;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.Dct2lowpasscurrent_gantryAirbag));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass\ncurrent_gantryAirbag");
      ssSetPath(rts, "Arizona_base_GOAT/Safety/Dct2lowpass current_gantryAirbag");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpasscurrent_gantryAirbag);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpasscurrent_gantryAirb_o);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpasscurrent_gantryAirb_p);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Arizona_base_GOAT_DW.Dct2lowpasscurrent_gantryAirbag[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn18.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Arizona_base_GOAT_DW.Dct2lowpasscurrent_gantryAirbag[0]);
      }

      /* registration */
      dlowpass2(rts);
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
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Arizona_base_GOAT/<S10>/Dct2lowpass current_carriageAirbag (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[19];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[19]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [19]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[19]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [19]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [19]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [19]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [19]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[19]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.UPtrs0;
          sfcnUPtrs[0] = &Arizona_base_GOAT_B.current_carriageAirbag;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.Dct2lowpasscurrent_carriageAirb));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass\ncurrent_carriageAirbag");
      ssSetPath(rts,
                "Arizona_base_GOAT/Safety/Dct2lowpass current_carriageAirbag");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpasscurrent_carriageAirb);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpasscurrent_carriageAi_e);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Dct2lowpasscurrent_carriageAi_g);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Arizona_base_GOAT_DW.Dct2lowpasscurrent_carriageAirb[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn19.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Arizona_base_GOAT_DW.Dct2lowpasscurrent_carriageAirb[0]);
      }

      /* registration */
      dlowpass2(rts);
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
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/Analog output 2 (sg_IO141_IO142_da_s) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[20];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn20.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn20.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn20.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[20]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [20]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[20]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [20]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [20]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [20]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [20]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[20]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn20.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn20.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn20.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn20.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Arizona_base_GOAT_B.gantryx1motorvoltage);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &Arizona_base_GOAT_B.gantryx2motorvoltage);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }

        /* port 2 */
        {
          ssSetInputPortRequiredContiguous(rts, 2, 1);
          ssSetInputPortSignal(rts, 2,
                               &Arizona_base_GOAT_B.carriagemotorvoltage_o);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidthAsInt(rts, 2, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Analog output 2");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/Analog output 2");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn20.params;
        ssSetSFcnParamsCount(rts, 14);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_base_GOAT_cal->Analogoutput2_P14_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_base_GOAT_DW.Analogoutput2_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn20.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn20.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.Analogoutput2_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DO Inhibit Carriage (sg_fpga_do_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[21];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn21.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn21.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn21.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[21]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [21]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[21]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [21]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [21]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [21]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [21]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[21]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn21.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn21.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn21.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn21.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Arizona_base_GOAT_B.carriageamplifierenable);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "DO Inhibit Carriage");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/DO Inhibit Carriage");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn21.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitCarriage_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitCarriage_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitCarriage_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitCarriage_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitCarriage_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitCarriage_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitCarriage_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitCarriage_P8_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Arizona_base_GOAT_DW.DOInhibitCarriage_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn21.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn21.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.DOInhibitCarriage_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DO Inhibit Gantry x1 = Gantry xR (sg_fpga_do_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[22];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn22.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn22.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn22.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[22]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [22]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[22]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [22]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [22]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [22]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [22]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[22]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn22.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn22.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn22.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn22.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Arizona_base_GOAT_B.gantryx_Ramplifierenable);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "DO Inhibit Gantry x1 = Gantry xR");
      ssSetPath(rts,
                "Arizona_base_GOAT/IO Arizona/DO Inhibit Gantry x1 = Gantry xR");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn22.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx1GantryxR_P1_Si);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx1GantryxR_P2_Si);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx1GantryxR_P3_Si);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx1GantryxR_P4_Si);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx1GantryxR_P5_Si);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx1GantryxR_P6_Si);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx1GantryxR_P7_Si);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx1GantryxR_P8_Si);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_base_GOAT_DW.DOInhibitGantryx1GantryxR_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn22.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn22.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Arizona_base_GOAT_DW.DOInhibitGantryx1GantryxR_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DO Inhibit Gantry x2 = DO Gantry xL (sg_fpga_do_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[23];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn23.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn23.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn23.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[23]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [23]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[23]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [23]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [23]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [23]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [23]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[23]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn23.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn23.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn23.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn23.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Arizona_base_GOAT_B.gantryx_Lamplifierenable);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "DO Inhibit Gantry x2 = DO Gantry xL");
      ssSetPath(rts,
                "Arizona_base_GOAT/IO Arizona/DO Inhibit Gantry x2 = DO Gantry xL");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn23.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx2DOGantryxL_P1_);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx2DOGantryxL_P2_);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx2DOGantryxL_P3_);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx2DOGantryxL_P4_);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx2DOGantryxL_P5_);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx2DOGantryxL_P6_);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx2DOGantryxL_P7_);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_base_GOAT_cal->DOInhibitGantryx2DOGantryxL_P8_);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_base_GOAT_DW.DOInhibitGantryx2DOGantryxL_PWO[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn23.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn23.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Arizona_base_GOAT_DW.DOInhibitGantryx2DOGantryxL_PWO[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/Cariage secundair (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[24];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn24.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn24.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn24.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[24]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [24]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[24]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [24]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [24]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [24]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [24]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[24]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn24.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn24.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn24.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn24.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.Cariagesecundair));
        }
      }

      /* path info */
      ssSetModelName(rts, "Cariage secundair");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/Cariage secundair");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn24.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       Arizona_base_GOAT_cal->Cariagesecundair_P24_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Arizona_base_GOAT_DW.Cariagesecundair_RWORK);
      ssSetPWork(rts, (void **) &Arizona_base_GOAT_DW.Cariagesecundair_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn24.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn24.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.Cariagesecundair_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Arizona_base_GOAT_DW.Cariagesecundair_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/Gantry X1 secundair (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[25];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn25.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn25.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn25.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[25]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [25]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[25]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [25]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [25]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [25]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [25]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[25]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn25.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn25.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn25.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn25.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.GantryX1secundair));
        }
      }

      /* path info */
      ssSetModelName(rts, "Gantry X1 secundair");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/Gantry X1 secundair");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn25.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       Arizona_base_GOAT_cal->GantryX1secundair_P24_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Arizona_base_GOAT_DW.GantryX1secundair_RWORK);
      ssSetPWork(rts, (void **) &Arizona_base_GOAT_DW.GantryX1secundair_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn25.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn25.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.GantryX1secundair_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Arizona_base_GOAT_DW.GantryX1secundair_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/Gentry X2 secundair (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[26];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn26.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn26.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn26.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[26]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [26]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[26]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [26]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [26]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [26]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [26]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[26]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn26.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn26.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn26.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn26.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.GentryX2secundair));
        }
      }

      /* path info */
      ssSetModelName(rts, "Gentry X2 secundair");
      ssSetPath(rts, "Arizona_base_GOAT/IO Arizona/Gentry X2 secundair");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn26.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)
                       Arizona_base_GOAT_cal->GentryX2secundair_P24_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Arizona_base_GOAT_DW.GentryX2secundair_RWORK);
      ssSetPWork(rts, (void **) &Arizona_base_GOAT_DW.GentryX2secundair_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn26.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn26.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Arizona_base_GOAT_DW.GentryX2secundair_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Arizona_base_GOAT_DW.GentryX2secundair_PWORK[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DI Limit Carriage secundair (werkt niet) (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[27];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn27.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn27.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn27.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[27]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [27]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[27]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [27]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [27]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [27]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [27]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[27]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn27.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn27.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn27.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn27.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.DIcarriagelimitswitchsecundaird));
        }
      }

      /* path info */
      ssSetModelName(rts, "DI Limit Carriage secundair (werkt niet)");
      ssSetPath(rts,
                "Arizona_base_GOAT/IO Arizona/DI Limit Carriage secundair (werkt niet)");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn27.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitCarriagesecundairwerktni);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitCarriagesecundairwerkt_f);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitCarriagesecundairwerkt_i);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitCarriagesecundairwerkt_d);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitCarriagesecundairwerkt_k);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitCarriagesecundairwerkt_m);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_base_GOAT_DW.DILimitCarriagesecundairwerktni[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn27.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn27.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Arizona_base_GOAT_DW.DILimitCarriagesecundairwerktni[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet) (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[28];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn28.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn28.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn28.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[28]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [28]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[28]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [28]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [28]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [28]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [28]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[28]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn28.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn28.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn28.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn28.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.DIgantryx1limitswitchsecundaird));
        }
      }

      /* path info */
      ssSetModelName(rts,
                     "DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)");
      ssSetPath(rts,
                "Arizona_base_GOAT/IO Arizona/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn28.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx1secundairGantryx);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx1secundairGantr_p);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx1secundairGantr_f);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx1secundairGant_ne);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx1secundairGantr_i);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx1secundairGantr_g);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_base_GOAT_DW.DILimitGantryx1secundairGantryx[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn28.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn28.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Arizona_base_GOAT_DW.DILimitGantryx1secundairGantryx[0]);
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

    /* Level2 S-Function Block: Arizona_base_GOAT/<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet) (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[29];

      /* timing info */
      time_T *sfcnPeriod =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn29.sfcnPeriod;
      time_T *sfcnOffset =
        Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn29.sfcnOffset;
      int_T *sfcnTsMap = Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn29.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfo2[29]);
        ssSetBlkInfoSLSizePtr(rts,
                              &Arizona_base_GOAT_M->NonInlinedSFcns.blkInfoSLSize
                              [29]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Arizona_base_GOAT_M->NonInlinedSFcns.inputOutputPortInfo2[29]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Arizona_base_GOAT_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods2
                           [29]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods3
                           [29]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.methods4
                           [29]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Arizona_base_GOAT_M->NonInlinedSFcns.statesInfo2
                         [29]);
        ssSetPeriodicStatesInfo(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.periodicStatesInfo[29]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn29.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs =
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn29.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn29.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn29.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Arizona_base_GOAT_B.DIgantryx2limitswitchsecundaird));
        }
      }

      /* path info */
      ssSetModelName(rts,
                     "DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)");
      ssSetPath(rts,
                "Arizona_base_GOAT/IO Arizona/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)");
      ssSetRTModel(rts,Arizona_base_GOAT_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn29.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx2secundairGantryx);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx2secundairGantr_p);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx2secundairGantr_m);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx2secundairGantr_k);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx2secundairGant_p4);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Arizona_base_GOAT_cal->DILimitGantryx2secundairGant_o0);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &Arizona_base_GOAT_DW.DILimitGantryx2secundairGantryx[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn29.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Arizona_base_GOAT_M->NonInlinedSFcns.Sfcn29.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Arizona_base_GOAT_DW.DILimitGantryx2secundairGantryx[0]);
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
        rtmSetErrorStatus(Arizona_base_GOAT_M, msg);
        return;
      }

      if ((strlen(mcsFileName) + strlen("/fpga/speedgoat_IO307_25k_CI_02479.mcs")
           + 1) > sizeof(mcsFileName)) {
        sprintf(msg,
                "Path to the bitstream (model name + bitstream name) is too long.");
        rtmSetErrorStatus(Arizona_base_GOAT_M, msg);
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
            rtmSetErrorStatus(Arizona_base_GOAT_M, msg);
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
            rtmSetErrorStatus(Arizona_base_GOAT_M, msg);
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
            rtmSetErrorStatus(Arizona_base_GOAT_M, msg);

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
            rtmSetErrorStatus(Arizona_base_GOAT_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           case EEPROM_ERROR:
            sprintf(msg, "Setup block %s: Error updating board EEPROM.\n",
                    devname);
            rtmSetErrorStatus(Arizona_base_GOAT_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           case REPROG_ERROR:
            sprintf(msg,
                    "Setup block %s: Error writing new bitstream to FPGA.\n",
                    devname);
            rtmSetErrorStatus(Arizona_base_GOAT_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           case FLASH_ERROR:
            sprintf(msg, "Setup block %s: Bitstream flash storage error.\n",
                    devname);
            rtmSetErrorStatus(Arizona_base_GOAT_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           case BIST_ERROR:
            sprintf(msg, "Setup block %s: Built in self test error.\n", devname);
            rtmSetErrorStatus(Arizona_base_GOAT_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           case ICAP_RECONF_FAILED:
            sprintf(msg,
                    "Setup block %s: ICAP Reconfiguration was not successful.\n",
                    devname);
            rtmSetErrorStatus(Arizona_base_GOAT_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           case BOARD_TYPE_UNKNOWN:
            sprintf(msg, "Setup block %s: The board type selected is unknown.\n",
                    devname);
            rtmSetErrorStatus(Arizona_base_GOAT_M, msg);
            SG_PRINTF(ERROR,msg);
            return;

           default:
            sprintf(msg, "Setup block %s: An unknown error occurred.\n",devname);
            rtmSetErrorStatus(Arizona_base_GOAT_M, msg);
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

    /* Start for S-Function (sg_IO141_IO142_setup_s): '<S5>/Setup 1' */
    /* Level2 S-Function Block: '<S5>/Setup 1' (sg_IO141_IO142_setup_s) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[3];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_IO141_IO142_ad_s): '<S5>/Analog input 1' */
    /* Level2 S-Function Block: '<S5>/Analog input 1' (sg_IO141_IO142_ad_s) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[4];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Carriage ' */
    /* Level2 S-Function Block: '<S5>/DI Limit Carriage ' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[5];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Gantry x1 = Gantry xR' */
    /* Level2 S-Function Block: '<S5>/DI Limit Gantry x1 = Gantry xR' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[6];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Gantry x2 = Gantry xL' */
    /* Level2 S-Function Block: '<S5>/DI Limit Gantry x2 = Gantry xL' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[7];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<S5>/DI black software button' */
    /* Level2 S-Function Block: '<S5>/DI black software button' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[8];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<S5>/DI carriage amp. fault status' */
    /* Level2 S-Function Block: '<S5>/DI carriage amp. fault status' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[9];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<S5>/DI gantry x1 fault status' */
    /* Level2 S-Function Block: '<S5>/DI gantry x1 fault status' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[10];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<S5>/DI gantry x2 fault status' */
    /* Level2 S-Function Block: '<S5>/DI gantry x2 fault status' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[11];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<S5>/DI red software button' */
    /* Level2 S-Function Block: '<S5>/DI red software button' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[12];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_qad_sf_5): '<S5>/Carriage encoder' */
    /* Level2 S-Function Block: '<S5>/Carriage encoder' (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[13];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_qad_sf_5): '<S5>/Gantry x1 = Gantry xR' */
    /* Level2 S-Function Block: '<S5>/Gantry x1 = Gantry xR' (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[14];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_qad_sf_5): '<S5>/Gantry x2 = Gantry xL' */
    /* Level2 S-Function Block: '<S5>/Gantry x2 = Gantry xL' (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[15];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (dlowpass2): '<S10>/Dct2lowpass output_y' */
    /* Level2 S-Function Block: '<S10>/Dct2lowpass output_y' (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[16];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (dlowpass2): '<S10>/Dct2lowpass output_x' */
    /* Level2 S-Function Block: '<S10>/Dct2lowpass output_x' (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[17];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (dlowpass2): '<S10>/Dct2lowpass current_gantryAirbag' */
    /* Level2 S-Function Block: '<S10>/Dct2lowpass current_gantryAirbag' (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[18];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (dlowpass2): '<S10>/Dct2lowpass current_carriageAirbag' */
    /* Level2 S-Function Block: '<S10>/Dct2lowpass current_carriageAirbag' (dlowpass2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[19];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_IO141_IO142_da_s): '<S5>/Analog output 2' */
    /* Level2 S-Function Block: '<S5>/Analog output 2' (sg_IO141_IO142_da_s) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[20];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for Constant: '<S10>/Enable_amplifier_y' */
    Arizona_base_GOAT_B.carriageamplifierenable =
      Arizona_base_GOAT_cal->Enable_amplifier_y_Value;

    /* Start for S-Function (sg_fpga_do_sf_a2): '<S5>/DO Inhibit Carriage' */
    /* Level2 S-Function Block: '<S5>/DO Inhibit Carriage' (sg_fpga_do_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[21];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for Constant: '<S10>/Enable_amplifier_xR' */
    Arizona_base_GOAT_B.gantryx_Ramplifierenable =
      Arizona_base_GOAT_cal->Enable_amplifier_xR_Value;

    /* Start for S-Function (sg_fpga_do_sf_a2): '<S5>/DO Inhibit Gantry x1 = Gantry xR' */
    /* Level2 S-Function Block: '<S5>/DO Inhibit Gantry x1 = Gantry xR' (sg_fpga_do_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[22];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for Constant: '<S10>/Enable_amplifier_xL' */
    Arizona_base_GOAT_B.gantryx_Lamplifierenable =
      Arizona_base_GOAT_cal->Enable_amplifier_xL_Value;

    /* Start for S-Function (sg_fpga_do_sf_a2): '<S5>/DO Inhibit Gantry x2 = DO Gantry xL' */
    /* Level2 S-Function Block: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL' (sg_fpga_do_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[23];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_qad_sf_5): '<S5>/Cariage secundair' */
    /* Level2 S-Function Block: '<S5>/Cariage secundair' (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[24];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_qad_sf_5): '<S5>/Gantry X1 secundair' */
    /* Level2 S-Function Block: '<S5>/Gantry X1 secundair' (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[25];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_qad_sf_5): '<S5>/Gentry X2 secundair' */
    /* Level2 S-Function Block: '<S5>/Gentry X2 secundair' (sg_fpga_qad_sf_5) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[26];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Carriage secundair (werkt niet)' */
    /* Level2 S-Function Block: '<S5>/DI Limit Carriage secundair (werkt niet)' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[27];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' */
    /* Level2 S-Function Block: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[28];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' */
    /* Level2 S-Function Block: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' (sg_fpga_di_sf_a2) */
    {
      SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[29];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for Constant: '<Root>/startHoming' */
    Arizona_base_GOAT_B.startHoming = Arizona_base_GOAT_cal->startHoming_Value;

    /* Start for Constant: '<Root>/startTrial' */
    Arizona_base_GOAT_B.startTrial = Arizona_base_GOAT_cal->startTrial_Value;

    /* Start for Constant: '<Root>/startPenholder' */
    Arizona_base_GOAT_B.startPenholder =
      Arizona_base_GOAT_cal->startPenholder_Value;

    /* Start for Constant: '<Root>/PenColor' */
    Arizona_base_GOAT_B.PenColor = Arizona_base_GOAT_cal->PenColor_Value;
  }

  Arizona_base_GOAT_PrevZCX.ResettableSubsystemMemory_Reset = POS_ZCSIG;

  /* InitializeConditions for Delay: '<Root>/log_penholder_active' */
  Arizona_base_GOAT_DW.log_penholder_active_DSTATE =
    Arizona_base_GOAT_cal->log_penholder_active_InitialCon;

  /* InitializeConditions for Delay: '<Root>/Delay2' */
  Arizona_base_GOAT_DW.Delay2_DSTATE =
    Arizona_base_GOAT_cal->Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S21>/Delay1' */
  Arizona_base_GOAT_DW.Delay1_DSTATE =
    Arizona_base_GOAT_cal->Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S21>/Delay' */
  Arizona_base_GOAT_DW.Delay_DSTATE =
    Arizona_base_GOAT_cal->Delay_InitialCondition_o;

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  Arizona_base_GOAT_DW.Delay1_DSTATE_g =
    Arizona_base_GOAT_cal->Delay1_InitialCondition_m;

  /* InitializeConditions for UnitDelay: '<S41>/UD' */
  Arizona_base_GOAT_DW.UD_DSTATE =
    Arizona_base_GOAT_cal->DiscreteDerivativeoutput_y_ICPr;

  /* InitializeConditions for Delay: '<S20>/Delay1' */
  Arizona_base_GOAT_DW.Delay1_DSTATE_i =
    Arizona_base_GOAT_cal->Delay1_InitialCondition_mu;

  /* InitializeConditions for Delay: '<S20>/Delay' */
  Arizona_base_GOAT_DW.Delay_DSTATE_j =
    Arizona_base_GOAT_cal->Delay_InitialCondition_d;

  /* InitializeConditions for UnitDelay: '<S40>/UD' */
  Arizona_base_GOAT_DW.UD_DSTATE_a =
    Arizona_base_GOAT_cal->DiscreteDerivativeoutput_x_ICPr;

  /* InitializeConditions for Delay: '<S19>/Delay1' */
  Arizona_base_GOAT_DW.Delay1_DSTATE_o =
    Arizona_base_GOAT_cal->Delay1_InitialCondition_l;

  /* InitializeConditions for Delay: '<S19>/Delay' */
  Arizona_base_GOAT_DW.Delay_DSTATE_h =
    Arizona_base_GOAT_cal->Delay_InitialCondition_a;

  /* InitializeConditions for DiscreteStateSpace: '<S7>/Internal' */
  Arizona_base_GOAT_DW.Internal_DSTATE[0] =
    Arizona_base_GOAT_cal->Internal_InitialCondition;
  Arizona_base_GOAT_DW.Internal_DSTATE[1] =
    Arizona_base_GOAT_cal->Internal_InitialCondition;

  /* InitializeConditions for DiscreteStateSpace: '<S8>/Internal' */
  Arizona_base_GOAT_DW.Internal_DSTATE_l[0] =
    Arizona_base_GOAT_cal->Internal_InitialCondition_e;
  Arizona_base_GOAT_DW.Internal_DSTATE_l[1] =
    Arizona_base_GOAT_cal->Internal_InitialCondition_e;
  Arizona_base_GOAT_DW.Internal_DSTATE_l[2] =
    Arizona_base_GOAT_cal->Internal_InitialCondition_e;

  /* InitializeConditions for DiscreteStateSpace: '<S6>/Internal' */
  Arizona_base_GOAT_DW.Internal_DSTATE_h[0] =
    Arizona_base_GOAT_cal->Internal_InitialCondition_o;
  Arizona_base_GOAT_DW.Internal_DSTATE_h[1] =
    Arizona_base_GOAT_cal->Internal_InitialCondition_o;

  /* Start for S-Function (dlowpass2): '<S16>/Dct2lowpass x1JogSpeed' */
  /* Level2 S-Function Block: '<S16>/Dct2lowpass x1JogSpeed' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S16>/Dct2lowpass x2JogSpeed' */
  /* Level2 S-Function Block: '<S16>/Dct2lowpass x2JogSpeed' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S16>/Dct2lowpass yJogSpeed' */
  /* Level2 S-Function Block: '<S16>/Dct2lowpass yJogSpeed' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Delay: '<S15>/Delay' */
  Arizona_base_GOAT_DW.Delay_DSTATE_m =
    Arizona_base_GOAT_cal->Delay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator x2JogSpeed1' */
  Arizona_base_GOAT_DW.DiscreteTimeIntegratorx2JogSpee =
    Arizona_base_GOAT_cal->DiscreteTimeIntegratorx2JogSp_m;

  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator x2JogSpeed' */
  Arizona_base_GOAT_DW.DiscreteTimeIntegratorx2JogSp_a =
    Arizona_base_GOAT_cal->DiscreteTimeIntegratorx2JogSp_e;

  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator x1JogSpeed' */
  Arizona_base_GOAT_DW.DiscreteTimeIntegratorx1JogSpee =
    Arizona_base_GOAT_cal->DiscreteTimeIntegratorx1JogSp_k;

  /* SystemInitialize for Chart: '<S16>/Supervisor' */
  Arizona_base_GOAT_DW.sfEvent_h = Arizona_base_GOAT_CALL_EVENT;
  Arizona_base_GOAT_DW.temporalCounter_i1 = 0U;
  Arizona_base_GOAT_DW.is_active_reset_carriage = 0U;
  Arizona_base_GOAT_DW.is_reset_carriage = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.is_active_reset_gantryLeft = 0U;
  Arizona_base_GOAT_DW.is_reset_gantryLeft = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.is_active_reset_gantryright = 0U;
  Arizona_base_GOAT_DW.is_reset_gantryright = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.is_active_c7_Arizona_base_GOAT = 0U;
  Arizona_base_GOAT_DW.is_c7_Arizona_base_GOAT = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.Ts_l = *get_Ts();
  Arizona_base_GOAT_B.jogspeed_y_reset_d = -0.00025;
  Arizona_base_GOAT_B.jogspeed_xL_reset_j = -0.0001;
  Arizona_base_GOAT_B.jogspeed_xR_reset_f = -0.0001;
  Arizona_base_GOAT_B.resetDone = 0.0;
  Arizona_base_GOAT_B.change_color_j = 0.0;

  /* SystemInitialize for Sum: '<S13>/Add yHome' incorporates:
   *  Outport: '<S13>/yHome'
   */
  Arizona_base_GOAT_B.AddyHome = Arizona_base_GOAT_cal->yHome_Y0;

  /* SystemInitialize for Sum: '<S13>/Add xHome' incorporates:
   *  Outport: '<S13>/xHome'
   */
  Arizona_base_GOAT_B.AddxHome = Arizona_base_GOAT_cal->xHome_Y0;

  /* SystemInitialize for Sum: '<S13>/Add phiHome' incorporates:
   *  Outport: '<S13>/phiHome'
   */
  Arizona_base_GOAT_B.AddphiHome = Arizona_base_GOAT_cal->phiHome_Y0;

  /* SystemInitialize for DataTypeConversion: '<S15>/Data Type Conversion end trial' incorporates:
   *  Outport: '<S13>/homingDone'
   */
  Arizona_base_GOAT_B.DataTypeConversionendtrial =
    Arizona_base_GOAT_cal->homingDone_Y0;

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled subsystem' */
  /* InitializeConditions for Delay: '<S11>/Delay' */
  Arizona_base_GOAT_DW.Delay_DSTATE_k =
    Arizona_base_GOAT_cal->Delay_InitialCondition_g;

  /* SystemInitialize for Resettable SubSystem: '<S11>/Resettable Subsystem // Memory' */
  /* InitializeConditions for Memory: '<S44>/Memory' */
  Arizona_base_GOAT_DW.Memory_PreviousInput =
    Arizona_base_GOAT_cal->Memory_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S11>/Resettable Subsystem // Memory' */

  /* SystemInitialize for DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Outport: '<S11>/time'
   */
  Arizona_base_GOAT_B.time = Arizona_base_GOAT_cal->time_Y0;

  /* SystemInitialize for LookupNDDirect: '<S11>/Direct Lookup Table yRef' incorporates:
   *  Outport: '<S11>/yRef'
   *
   * About '<S11>/Direct Lookup Table yRef':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  Arizona_base_GOAT_B.yref_check = Arizona_base_GOAT_cal->yRef_Y0;

  /* SystemInitialize for LookupNDDirect: '<S11>/Direct Lookup Table xRef' incorporates:
   *  Outport: '<S11>/xRef'
   *
   * About '<S11>/Direct Lookup Table xRef':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  Arizona_base_GOAT_B.DirectLookupTablexRef = Arizona_base_GOAT_cal->xRef_Y0;

  /* SystemInitialize for LookupNDDirect: '<S11>/Direct Lookup Table phiRef' incorporates:
   *  Outport: '<S11>/phiRef'
   *
   * About '<S11>/Direct Lookup Table phiRef':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  Arizona_base_GOAT_B.DirectLookupTablephiRef = Arizona_base_GOAT_cal->phiRef_Y0;

  /* SystemInitialize for LookupNDDirect: '<S11>/Direct Lookup Table change_color' incorporates:
   *  Outport: '<S11>/change_color'
   *
   * About '<S11>/Direct Lookup Table change_color':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  Arizona_base_GOAT_B.DirectLookupTablechange_color =
    Arizona_base_GOAT_cal->change_color_Y0;

  /* SystemInitialize for RelationalOperator: '<S43>/Compare' incorporates:
   *  Outport: '<S11>/trialDone'
   */
  Arizona_base_GOAT_B.Compare_h2 = Arizona_base_GOAT_cal->trialDone_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Trajectory' */

  /* SystemInitialize for Chart: '<S10>/Supervisor' */
  Arizona_base_GOAT_DW.sfEvent_i = Arizona_base_GOAT_CALL_EVENT;
  Arizona_base_GOAT_DW.is_active_carriageAirbag = 0U;
  Arizona_base_GOAT_DW.is_carriageAirbag = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.is_active_errorAirbag = 0U;
  Arizona_base_GOAT_DW.is_errorAirbag = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.is_active_gantryAirbag = 0U;
  Arizona_base_GOAT_DW.is_gantryAirbag = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.is_active_c3_Arizona_base_GOAT = 0U;
  Arizona_base_GOAT_DW.is_c3_Arizona_base_GOAT = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_B.current_carriageAirbag = 0.0;
  Arizona_base_GOAT_B.enableAirbags = 0.0;
  Arizona_base_GOAT_B.current_gantryAirbag = 0.0;
  Arizona_base_GOAT_B.stopSimulation = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<Root>/Feedforward' */
  /* SystemInitialize for LookupNDDirect: '<S3>/Direct Lookup Table yFF' incorporates:
   *  Outport: '<S3>/yFF'
   *
   * About '<S3>/Direct Lookup Table yFF':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  Arizona_base_GOAT_B.f_y = Arizona_base_GOAT_cal->yFF_Y0;

  /* SystemInitialize for LookupNDDirect: '<S3>/Direct Lookup Table xFF' incorporates:
   *  Outport: '<S3>/xFF'
   *
   * About '<S3>/Direct Lookup Table xFF':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  Arizona_base_GOAT_B.f_x = Arizona_base_GOAT_cal->xFF_Y0;

  /* SystemInitialize for LookupNDDirect: '<S3>/Direct Lookup Table phiFF' incorporates:
   *  Outport: '<S3>/phiFF'
   *
   * About '<S3>/Direct Lookup Table phiFF':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  Arizona_base_GOAT_B.f_phi = Arizona_base_GOAT_cal->phiFF_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Feedforward' */

  /* SystemInitialize for Chart: '<Root>/Trial control without penholder' */
  Arizona_base_GOAT_DW.sfEvent = Arizona_base_GOAT_CALL_EVENT;
  Arizona_base_GOAT_DW.is_active_c5_Arizona_base_GOAT = 0U;
  Arizona_base_GOAT_DW.is_c5_Arizona_base_GOAT = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.timeIndex = 0.0;
  Arizona_base_GOAT_B.homeTrigger = 0.0;
  Arizona_base_GOAT_B.trialTrigger_e = 0.0;
  Arizona_base_GOAT_B.trialIndex = 0.0;
  Arizona_base_GOAT_B.change_color = 0.0;

  /* SystemInitialize for Chart: '<S9>/Change color Chart' */
  Arizona_base_GOAT_DW.sfEvent_l = Arizona_base_GOAT_CALL_EVENT;
  Arizona_base_GOAT_DW.is_active_HOME = 0U;
  Arizona_base_GOAT_DW.is_HOME = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.temporalCounter_i3 = 0U;
  Arizona_base_GOAT_DW.is_active_MAIN = 0U;
  Arizona_base_GOAT_DW.is_MAIN = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.is_active_ROTATION = 0U;
  Arizona_base_GOAT_DW.is_ROTATION = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.temporalCounter_i2 = 0U;
  Arizona_base_GOAT_DW.is_active_VERTICAL = 0U;
  Arizona_base_GOAT_DW.is_VERTICAL = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.temporalCounter_i1_b = 0U;
  Arizona_base_GOAT_DW.is_active_c4_Arizona_base_GOAT = 0U;
  Arizona_base_GOAT_DW.is_c4_Arizona_base_GOAT = Arizona_base_IN_NO_ACTIVE_CHILD;
  Arizona_base_GOAT_DW.counter = 0.0;
  Arizona_base_GOAT_DW.job = 0.0;
  Arizona_base_GOAT_DW.rot_change = 0.0;
  Arizona_base_GOAT_DW.color_pos = 0.0;
  Arizona_base_GOAT_B.jogspeed_Z = 0.0;
  Arizona_base_GOAT_B.jogspeed_Theta = 0.0;
  Arizona_base_GOAT_B.active = 0.0;
}

/* Model terminate function */
void Arizona_base_GOAT_terminate(void)
{
  /* Terminate for S-Function (sg_IO141_IO142_setup_s): '<S5>/Setup 1' */
  /* Level2 S-Function Block: '<S5>/Setup 1' (sg_IO141_IO142_setup_s) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_IO141_IO142_ad_s): '<S5>/Analog input 1' */
  /* Level2 S-Function Block: '<S5>/Analog input 1' (sg_IO141_IO142_ad_s) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Carriage ' */
  /* Level2 S-Function Block: '<S5>/DI Limit Carriage ' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Gantry x1 = Gantry xR' */
  /* Level2 S-Function Block: '<S5>/DI Limit Gantry x1 = Gantry xR' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Gantry x2 = Gantry xL' */
  /* Level2 S-Function Block: '<S5>/DI Limit Gantry x2 = Gantry xL' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<S5>/DI black software button' */
  /* Level2 S-Function Block: '<S5>/DI black software button' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<S5>/DI carriage amp. fault status' */
  /* Level2 S-Function Block: '<S5>/DI carriage amp. fault status' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<S5>/DI gantry x1 fault status' */
  /* Level2 S-Function Block: '<S5>/DI gantry x1 fault status' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<S5>/DI gantry x2 fault status' */
  /* Level2 S-Function Block: '<S5>/DI gantry x2 fault status' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<S5>/DI red software button' */
  /* Level2 S-Function Block: '<S5>/DI red software button' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_qad_sf_5): '<S5>/Carriage encoder' */
  /* Level2 S-Function Block: '<S5>/Carriage encoder' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_qad_sf_5): '<S5>/Gantry x1 = Gantry xR' */
  /* Level2 S-Function Block: '<S5>/Gantry x1 = Gantry xR' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[14];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_qad_sf_5): '<S5>/Gantry x2 = Gantry xL' */
  /* Level2 S-Function Block: '<S5>/Gantry x2 = Gantry xL' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[15];
    sfcnTerminate(rts);
  }

  /* Terminate for Enabled SubSystem: '<S4>/Enabled subsystem' */

  /* Terminate for S-Function (dlowpass2): '<S16>/Dct2lowpass x1JogSpeed' */
  /* Level2 S-Function Block: '<S16>/Dct2lowpass x1JogSpeed' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S16>/Dct2lowpass x2JogSpeed' */
  /* Level2 S-Function Block: '<S16>/Dct2lowpass x2JogSpeed' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S16>/Dct2lowpass yJogSpeed' */
  /* Level2 S-Function Block: '<S16>/Dct2lowpass yJogSpeed' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S4>/Enabled subsystem' */

  /* Terminate for S-Function (dlowpass2): '<S10>/Dct2lowpass output_y' */
  /* Level2 S-Function Block: '<S10>/Dct2lowpass output_y' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[16];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S10>/Dct2lowpass output_x' */
  /* Level2 S-Function Block: '<S10>/Dct2lowpass output_x' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[17];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S10>/Dct2lowpass current_gantryAirbag' */
  /* Level2 S-Function Block: '<S10>/Dct2lowpass current_gantryAirbag' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[18];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S10>/Dct2lowpass current_carriageAirbag' */
  /* Level2 S-Function Block: '<S10>/Dct2lowpass current_carriageAirbag' (dlowpass2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[19];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_IO141_IO142_da_s): '<S5>/Analog output 2' */
  /* Level2 S-Function Block: '<S5>/Analog output 2' (sg_IO141_IO142_da_s) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[20];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_do_sf_a2): '<S5>/DO Inhibit Carriage' */
  /* Level2 S-Function Block: '<S5>/DO Inhibit Carriage' (sg_fpga_do_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[21];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_do_sf_a2): '<S5>/DO Inhibit Gantry x1 = Gantry xR' */
  /* Level2 S-Function Block: '<S5>/DO Inhibit Gantry x1 = Gantry xR' (sg_fpga_do_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[22];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_do_sf_a2): '<S5>/DO Inhibit Gantry x2 = DO Gantry xL' */
  /* Level2 S-Function Block: '<S5>/DO Inhibit Gantry x2 = DO Gantry xL' (sg_fpga_do_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[23];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_qad_sf_5): '<S5>/Cariage secundair' */
  /* Level2 S-Function Block: '<S5>/Cariage secundair' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[24];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_qad_sf_5): '<S5>/Gantry X1 secundair' */
  /* Level2 S-Function Block: '<S5>/Gantry X1 secundair' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[25];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_qad_sf_5): '<S5>/Gentry X2 secundair' */
  /* Level2 S-Function Block: '<S5>/Gentry X2 secundair' (sg_fpga_qad_sf_5) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[26];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Carriage secundair (werkt niet)' */
  /* Level2 S-Function Block: '<S5>/DI Limit Carriage secundair (werkt niet)' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[27];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' */
  /* Level2 S-Function Block: '<S5>/DI Limit Gantry x1 secundair =  Gantry xR secundair (werkt niet)' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[28];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sg_fpga_di_sf_a2): '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' */
  /* Level2 S-Function Block: '<S5>/DI Limit Gantry x2 secundair =  Gantry xL secundair (werkt niet)' (sg_fpga_di_sf_a2) */
  {
    SimStruct *rts = Arizona_base_GOAT_M->childSfunctions[29];
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
