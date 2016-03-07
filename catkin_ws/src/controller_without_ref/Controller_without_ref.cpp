//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Controller_without_ref.cpp
//
// Code generated for Simulink model 'Controller_without_ref'.
//
// Model version                  : 1.149
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Mon Mar  7 17:07:29 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Controller_without_ref.h"
#include "Controller_without_ref_private.h"

// Named constants for State Transition Table: '<S15>/State Transition Table'
#define Controller_w_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Controller_without_re_IN_state1 ((uint8_T)1U)
#define Controller_without_re_IN_state2 ((uint8_T)2U)
#define Cont_ParameterInitialValue_oeap (false)
#define Contr_ParameterInitialValue_oea (1.0)
#define Contro_ParameterInitialValue_oe (0.0)
#define Control_ParameterInitialValue_o (1)
#define Controlle_ParameterInitialValue (0)
#define Controller_wi_MessageQueueLen_o (1)
#define Controller_with_MessageQueueLen (10)

//
// Output and update for atomic system:
//    '<S3>/MATLAB Function'
//    '<S4>/MATLAB Function'
//
void Controller_witho_MATLABFunction(real_T rtu_angular_x, real_T rtu_angular_y,
  real_T rtu_angular_z, real_T rtu_vel_x, real_T rtu_vel_y, real_T rtu_vel_z,
  real_T rtu_front_strafe_decouple, real_T rtu_front_forward_decouple, real_T
  rtu_front_pitch_bias, real_T rtu_front_vertical_bias, real_T
  rtu_buoyancy_control, rtB_MATLABFunction_Controller_T *localB)
{
  // MATLAB Function 'Decouple1/MATLAB Function': '<S13>:1'
  //  Vertical Left thruster (VL)
  // '<S13>:1:7'
  localB->thruster1 = ((((rtu_angular_x - rtu_front_forward_decouple * rtu_vel_x)
    - rtu_front_strafe_decouple * rtu_vel_y) - rtu_front_pitch_bias *
                        rtu_angular_y) + rtu_front_vertical_bias * rtu_vel_z) +
    rtu_buoyancy_control;

  //  Vertical Back thruster (VB)
  // '<S13>:1:17'
  localB->thruster2 = ((rtu_front_forward_decouple * rtu_vel_x + rtu_angular_y)
                       + rtu_vel_z) + rtu_buoyancy_control;

  // '<S13>:1:24'
  localB->thruster3 = ((((-rtu_angular_x - rtu_front_forward_decouple *
    rtu_vel_x) + rtu_front_strafe_decouple * rtu_vel_y) - rtu_front_pitch_bias *
                        rtu_angular_y) + rtu_front_vertical_bias * rtu_vel_z) +
    rtu_buoyancy_control;

  // Forward Left (FL)
  // '<S13>:1:33'
  localB->thruster4 = -rtu_angular_z + rtu_vel_x;

  // '<S13>:1:36'
  localB->thruster5 = rtu_vel_y;

  //  LATeral (LAT)
  //  Forward Right (FR)
  // '<S13>:1:39'
  localB->thruster6 = rtu_angular_z + rtu_vel_x;
}

//
// Output and update for atomic system:
//    '<S15>/MATLAB Function'
//    '<S16>/MATLAB Function'
//    '<S17>/MATLAB Function'
//    '<S18>/MATLAB Function'
//    '<S19>/MATLAB Function'
//    '<S20>/MATLAB Function'
//
void Controller_wit_MATLABFunction_a(real_T rtu_u, real_T rtu_min_scale, real_T
  rtu_max_scale, rtB_MATLABFunction_Controll_n_T *localB)
{
  // MATLAB Function 'Telegraph/Thruster1 block/MATLAB Function': '<S21>:1'
  if (rtu_u < 0.0) {
    // '<S21>:1:4'
    // '<S21>:1:5'
    localB->y = rtu_min_scale * rtu_u;
  } else {
    // '<S21>:1:7'
    localB->y = rtu_max_scale * rtu_u;
  }
}

//
// Initial conditions for atomic system:
//    '<S15>/State Transition Table'
//    '<S16>/State Transition Table'
//    '<S17>/State Transition Table'
//    '<S18>/State Transition Table'
//    '<S19>/State Transition Table'
//    '<S20>/State Transition Table'
//
void Contr_StateTransitionTable_Init(rtDW_StateTransitionTable_Con_T *localDW)
{
  localDW->is_active_c6_Controller_without = 0U;
  localDW->is_c6_Controller_without_ref = Controller_w_IN_NO_ACTIVE_CHILD;
}

//
// Output and update for atomic system:
//    '<S15>/State Transition Table'
//    '<S16>/State Transition Table'
//    '<S17>/State Transition Table'
//    '<S18>/State Transition Table'
//    '<S19>/State Transition Table'
//    '<S20>/State Transition Table'
//
void Controller_StateTransitionTable(real_T rtu_x,
  rtB_StateTransitionTable_Cont_T *localB, rtDW_StateTransitionTable_Con_T
  *localDW)
{
  // Gateway: Telegraph/Thruster1 block/State Transition Table
  // During: Telegraph/Thruster1 block/State Transition Table
  if (localDW->is_active_c6_Controller_without == 0U) {
    // Entry: Telegraph/Thruster1 block/State Transition Table
    localDW->is_active_c6_Controller_without = 1U;

    // Entry Internal: Telegraph/Thruster1 block/State Transition Table
    // Transition: '<S22>:15'
    localDW->is_c6_Controller_without_ref = Controller_without_re_IN_state1;
  } else if (localDW->is_c6_Controller_without_ref ==
             Controller_without_re_IN_state1) {
    // During 'state1': '<S22>:13'
    if (rtu_x > 0.0) {
      // Transition: '<S22>:17'
      localB->u = 1.0;
      localDW->is_c6_Controller_without_ref = Controller_without_re_IN_state2;
    } else {
      // Transition: '<S22>:19'
      // Transition: '<S22>:21'
      localDW->is_c6_Controller_without_ref = Controller_without_re_IN_state1;
    }
  } else {
    // During 'state2': '<S22>:14'
    if (rtu_x > 0.0) {
      // Transition: '<S22>:18'
      localB->u = -1.0;
      localDW->is_c6_Controller_without_ref = Controller_without_re_IN_state1;
    } else {
      // Transition: '<S22>:23'
      // Transition: '<S22>:25'
      localDW->is_c6_Controller_without_ref = Controller_without_re_IN_state2;
    }
  }
}

void ControllerModelClass::Controller_without__RandSrc_U_D(real_T y[], const
  real_T minVec[], int32_T minLen, const real_T maxVec[], int32_T maxLen, real_T
  state[], int32_T nChans, int32_T nSamps)
{
  int32_T one;
  int32_T lsw;
  int8_T *onePtr;
  int32_T chan;
  int32_T samps;
  int32_T i;
  uint32_T j;
  int32_T ii[2];

  // Start for S-Function (sdsprandsrc2): '<S15>/Random Source'
  // RandSrc_U_D
  one = 1;
  onePtr = (int8_T *)&one;
  lsw = (onePtr[0U] == 0);
  for (chan = 0; chan < nChans; chan++) {
    Controller_without_ref_B.min_c = minVec[minLen > 1 ? chan : 0];
    Controller_without_ref_B.max_b = maxVec[maxLen > 1 ? chan : 0];
    Controller_without_ref_B.max_b -= Controller_without_ref_B.min_c;
    i = (int32_T)((uint32_T)state[chan * 35 + 33] & 31U);
    j = (uint32_T)state[chan * 35 + 34];
    for (samps = 0; samps < nSamps; samps++) {
      // "Subtract with borrow" generator
      Controller_without_ref_B.d = state[((i + 20) & 31) + chan * 35];
      Controller_without_ref_B.d -= state[((i + 5) & 31) + chan * 35];
      Controller_without_ref_B.d -= state[chan * 35 + 32];
      if (Controller_without_ref_B.d >= 0.0) {
        state[chan * 35 + 32] = 0.0;
      } else {
        Controller_without_ref_B.d++;

        // set 1 in LSB
        state[chan * 35 + 32] = 1.1102230246251565E-16;
      }

      state[chan * 35 + i] = Controller_without_ref_B.d;
      i = (i + 1) & 31;

      // XOR with shift register sequence
      memcpy((void *)&ii[0U], (void *)&Controller_without_ref_B.d, sizeof(real_T));
      ii[lsw] ^= j;
      j ^= j << 13;
      j ^= j >> 17;
      j ^= j << 5;
      ii[lsw ^ 1] ^= j & 1048575U;
      memcpy((void *)&Controller_without_ref_B.d, (void *)&ii[0U], sizeof(real_T));
      y[chan * nSamps + samps] = Controller_without_ref_B.max_b *
        Controller_without_ref_B.d + Controller_without_ref_B.min_c;
    }

    state[chan * 35 + 33] = i;
    state[chan * 35 + 34] = j;
  }

  // End of Start for S-Function (sdsprandsrc2): '<S15>/Random Source'
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = u0 / u1;
      if (fabs(u1_0 - rt_roundd_snf(u1_0)) <= DBL_EPSILON * fabs(u1_0)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S11>/removeGravity'
void ControllerModelClass::Controller_without_ref_sind(real_T *x)
{
  int8_T n;
  real_T c_x;
  real_T absx;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    c_x = (rtNaN);
  } else {
    c_x = rt_remd_snf(*x, 360.0);
    absx = fabs(c_x);
    if (absx > 180.0) {
      if (c_x > 0.0) {
        c_x -= 360.0;
      } else {
        c_x += 360.0;
      }

      absx = fabs(c_x);
    }

    if (absx <= 45.0) {
      c_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (c_x > 0.0) {
        c_x = (c_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        c_x = (c_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (c_x > 0.0) {
      c_x = (c_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      c_x = (c_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    if (n == 0) {
      c_x = sin(c_x);
    } else if (n == 1) {
      c_x = cos(c_x);
    } else if (n == -1) {
      c_x = -cos(c_x);
    } else {
      c_x = -sin(c_x);
    }
  }

  *x = c_x;
}

// Function for MATLAB Function: '<S11>/removeGravity'
void ControllerModelClass::Controller_without_ref_cosd(real_T *x)
{
  int8_T n;
  real_T b_x;
  real_T absx;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    *x = (rtNaN);
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    if (n == 0) {
      *x = cos(b_x);
    } else if (n == 1) {
      *x = -sin(b_x);
    } else if (n == -1) {
      *x = sin(b_x);
    } else {
      *x = -cos(b_x);
    }
  }
}

// Function for MATLAB Function: '<S11>/removeGravity'
void ControllerModelClass::Controller_without_ref_inv(const real_T x[9], real_T
  y[9])
{
  int32_T p1;
  int32_T p2;
  int32_T p3;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T itmp;
  memcpy(&Controller_without_ref_B.b_x[0], &x[0], 9U * sizeof(real_T));
  p1 = 0;
  p2 = 3;
  p3 = 6;
  absx11 = fabs(x[0]);
  absx21 = fabs(x[1]);
  absx31 = fabs(x[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    Controller_without_ref_B.b_x[0] = x[1];
    Controller_without_ref_B.b_x[1] = x[0];
    Controller_without_ref_B.b_x[3] = x[4];
    Controller_without_ref_B.b_x[4] = x[3];
    Controller_without_ref_B.b_x[6] = x[7];
    Controller_without_ref_B.b_x[7] = x[6];
  } else {
    if (absx31 > absx11) {
      p1 = 6;
      p3 = 0;
      Controller_without_ref_B.b_x[0] = x[2];
      Controller_without_ref_B.b_x[2] = x[0];
      Controller_without_ref_B.b_x[3] = x[5];
      Controller_without_ref_B.b_x[5] = x[3];
      Controller_without_ref_B.b_x[6] = x[8];
      Controller_without_ref_B.b_x[8] = x[6];
    }
  }

  absx11 = Controller_without_ref_B.b_x[1] / Controller_without_ref_B.b_x[0];
  Controller_without_ref_B.b_x[1] /= Controller_without_ref_B.b_x[0];
  absx21 = Controller_without_ref_B.b_x[2] / Controller_without_ref_B.b_x[0];
  Controller_without_ref_B.b_x[2] /= Controller_without_ref_B.b_x[0];
  Controller_without_ref_B.b_x[4] -= absx11 * Controller_without_ref_B.b_x[3];
  Controller_without_ref_B.b_x[5] -= absx21 * Controller_without_ref_B.b_x[3];
  Controller_without_ref_B.b_x[7] -= absx11 * Controller_without_ref_B.b_x[6];
  Controller_without_ref_B.b_x[8] -= absx21 * Controller_without_ref_B.b_x[6];
  if (fabs(Controller_without_ref_B.b_x[5]) > fabs(Controller_without_ref_B.b_x
       [4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    Controller_without_ref_B.b_x[1] = absx21;
    Controller_without_ref_B.b_x[2] = absx11;
    absx11 = Controller_without_ref_B.b_x[4];
    Controller_without_ref_B.b_x[4] = Controller_without_ref_B.b_x[5];
    Controller_without_ref_B.b_x[5] = absx11;
    absx11 = Controller_without_ref_B.b_x[7];
    Controller_without_ref_B.b_x[7] = Controller_without_ref_B.b_x[8];
    Controller_without_ref_B.b_x[8] = absx11;
  }

  absx11 = Controller_without_ref_B.b_x[5] / Controller_without_ref_B.b_x[4];
  Controller_without_ref_B.b_x[5] /= Controller_without_ref_B.b_x[4];
  Controller_without_ref_B.b_x[8] -= absx11 * Controller_without_ref_B.b_x[7];
  absx11 = (Controller_without_ref_B.b_x[5] * Controller_without_ref_B.b_x[1] -
            Controller_without_ref_B.b_x[2]) / Controller_without_ref_B.b_x[8];
  absx21 = -(Controller_without_ref_B.b_x[7] * absx11 +
             Controller_without_ref_B.b_x[1]) / Controller_without_ref_B.b_x[4];
  y[p1] = ((1.0 - Controller_without_ref_B.b_x[3] * absx21) -
           Controller_without_ref_B.b_x[6] * absx11) /
    Controller_without_ref_B.b_x[0];
  y[p1 + 1] = absx21;
  y[p1 + 2] = absx11;
  absx11 = -Controller_without_ref_B.b_x[5] / Controller_without_ref_B.b_x[8];
  absx21 = (1.0 - Controller_without_ref_B.b_x[7] * absx11) /
    Controller_without_ref_B.b_x[4];
  y[p2] = -(Controller_without_ref_B.b_x[3] * absx21 +
            Controller_without_ref_B.b_x[6] * absx11) /
    Controller_without_ref_B.b_x[0];
  y[p2 + 1] = absx21;
  y[p2 + 2] = absx11;
  absx11 = 1.0 / Controller_without_ref_B.b_x[8];
  absx21 = -Controller_without_ref_B.b_x[7] * absx11 /
    Controller_without_ref_B.b_x[4];
  y[p3] = -(Controller_without_ref_B.b_x[3] * absx21 +
            Controller_without_ref_B.b_x[6] * absx11) /
    Controller_without_ref_B.b_x[0];
  y[p3 + 1] = absx21;
  y[p3 + 2] = absx11;
}

void RandSrcInitState_U_64(const uint32_T seed[], real_T state[], int32_T nChans)
{
  int32_T i;
  uint32_T j;
  int32_T k;
  int32_T n;
  real_T d;

  // Start for S-Function (sdsprandsrc2): '<S15>/Random Source'
  // RandSrcInitState_U_64
  for (i = 0; i < nChans; i++) {
    j = seed[i] != 0U ? seed[i] : 2147483648U;
    state[35 * i + 34] = j;
    for (k = 0; k < 32; k++) {
      d = 0.0;
      for (n = 0; n < 53; n++) {
        j ^= j << 13;
        j ^= j >> 17;
        j ^= j << 5;
        d = (real_T)((int32_T)(j >> 19) & 1) + (d + d);
      }

      state[35 * i + k] = ldexp(d, -53);
    }

    state[35 * i + 32] = 0.0;
    state[35 * i + 33] = 0.0;
  }

  // End of Start for S-Function (sdsprandsrc2): '<S15>/Random Source'
}

void ControllerModelClass::Controlle_RandSrcCreateSeeds_64(uint32_T initSeed,
  uint32_T seedArray[], int32_T numSeeds)
{
  int32_T i;

  // Start for S-Function (sdsprandsrc2): '<S15>/Random Source'
  // RandSrcCreateSeeds_64
  Controller_without_ref_B.min = 0.0;
  Controller_without_ref_B.max = 1.0;
  RandSrcInitState_U_64(&initSeed, Controller_without_ref_B.state, 1);
  for (i = 0; i < numSeeds; i++) {
    Controller_without__RandSrc_U_D(&Controller_without_ref_B.tmp,
      &Controller_without_ref_B.min, 1, &Controller_without_ref_B.max, 1,
      Controller_without_ref_B.state, 1, 1);
    seedArray[i] = (uint32_T)(Controller_without_ref_B.tmp * 2.147483648E+9);
  }

  // End of Start for S-Function (sdsprandsrc2): '<S15>/Random Source'
}

// Model step function
void ControllerModelClass::step()
{
  int32_T rtb_Swtichingfactor_d_0;
  boolean_T p;
  boolean_T p_0;
  boolean_T rtb_Compare;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_NotEqual;
  int32_T i;
  int32_T i_0;
  int8_T rtb_DataTypeConv2_0;
  int8_T tmp;

  // Start for MATLABSystem: '<Root>/Get test' incorporates:
  //   MATLABSystem: '<Root>/Get test'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_h2.SampleTime ==
        Controller_without_ref_P.Gettest_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_h2.SampleTime =
      Controller_without_ref_P.Gettest_SampleTime;
  }

  ParamGet_Controller_without_ref_823.get_parameter(&i);

  // End of Start for MATLABSystem: '<Root>/Get test'

  // RelationalOperator: '<S1>/Compare' incorporates:
  //   Constant: '<S1>/Constant'
  //   MATLABSystem: '<Root>/Get test'

  rtb_Compare = (i <= Controller_without_ref_P.CompareToConstant_const);

  // Outputs for Enabled SubSystem: '<Root>/Telegraph' incorporates:
  //   EnablePort: '<S5>/Enable'

  if (rtb_Compare) {
    // S-Function (sdsprandsrc2): '<S15>/Random Source'
    Controller_without__RandSrc_U_D(&Controller_without_ref_B.RandomSource,
      &Controller_without_ref_P.RandomSource_MinVal, 1,
      &Controller_without_ref_P.RandomSource_MaxVal, 1,
      Controller_without_ref_DWork.RandomSource_STATE_DWORK, 1, 1);

    // Start for MATLABSystem: '<S15>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S15>/Swtiching factor'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_of.SampleTime ==
          Controller_without_ref_P.Swtichingfactor_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_of.SampleTime =
        Controller_without_ref_P.Swtichingfactor_SampleTime;
    }

    ParamGet_Controller_without_ref_714.get_parameter(&rtb_Swtichingfactor_d_0);

    // End of Start for MATLABSystem: '<S15>/Swtiching factor'

    // State Transition Table: '<S15>/State Transition Table' incorporates:
    //   Constant: '<S15>/Constant'
    //   MATLABSystem: '<S15>/Swtiching factor'
    //   Sum: '<S15>/Add'

    Controller_StateTransitionTable((Controller_without_ref_B.RandomSource +
      (real_T)rtb_Swtichingfactor_d_0) -
      Controller_without_ref_P.Constant_Value_f,
      &Controller_without_ref_B.sf_StateTransitionTable,
      &Controller_without_ref_DWork.sf_StateTransitionTable);

    // Start for MATLABSystem: '<S15>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S15>/Swtiching factor1'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_fx.SampleTime ==
          Controller_without_ref_P.Swtichingfactor1_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_fx.SampleTime =
        Controller_without_ref_P.Swtichingfactor1_SampleTime;
    }

    ParamGet_Controller_without_ref_715.get_parameter
      (&Controller_without_ref_B.cfi);

    // End of Start for MATLABSystem: '<S15>/Swtiching factor1'

    // Start for MATLABSystem: '<S15>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S15>/Swtiching factor2'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_d3.SampleTime ==
          Controller_without_ref_P.Swtichingfactor2_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_d3.SampleTime =
        Controller_without_ref_P.Swtichingfactor2_SampleTime;
    }

    ParamGet_Controller_without_ref_716.get_parameter
      (&Controller_without_ref_B.spsi);

    // End of Start for MATLABSystem: '<S15>/Swtiching factor2'

    // MATLAB Function: '<S15>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S15>/Swtiching factor1'
    //   MATLABSystem: '<S15>/Swtiching factor2'

    Controller_wit_MATLABFunction_a
      (Controller_without_ref_B.sf_StateTransitionTable.u,
       Controller_without_ref_B.cfi, Controller_without_ref_B.spsi,
       &Controller_without_ref_B.sf_MATLABFunction_a);

    // S-Function (sdsprandsrc2): '<S16>/Random Source'
    Controller_without__RandSrc_U_D(&Controller_without_ref_B.RandomSource,
      &Controller_without_ref_P.RandomSource_MinVal_h, 1,
      &Controller_without_ref_P.RandomSource_MaxVal_o, 1,
      Controller_without_ref_DWork.RandomSource_STATE_DWORK_i, 1, 1);

    // Start for MATLABSystem: '<S16>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S16>/Swtiching factor'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_i.SampleTime ==
          Controller_without_ref_P.Swtichingfactor_SampleTime_k)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_i.SampleTime =
        Controller_without_ref_P.Swtichingfactor_SampleTime_k;
    }

    ParamGet_Controller_without_ref_724.get_parameter(&rtb_Swtichingfactor_d_0);

    // End of Start for MATLABSystem: '<S16>/Swtiching factor'

    // State Transition Table: '<S16>/State Transition Table' incorporates:
    //   Constant: '<S16>/Constant'
    //   MATLABSystem: '<S16>/Swtiching factor'
    //   Sum: '<S16>/Add'

    Controller_StateTransitionTable((Controller_without_ref_B.RandomSource +
      (real_T)rtb_Swtichingfactor_d_0) -
      Controller_without_ref_P.Constant_Value_k,
      &Controller_without_ref_B.sf_StateTransitionTable_i,
      &Controller_without_ref_DWork.sf_StateTransitionTable_i);

    // Start for MATLABSystem: '<S16>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S16>/Swtiching factor1'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_j5.SampleTime ==
          Controller_without_ref_P.Swtichingfactor1_SampleTime_i)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_j5.SampleTime =
        Controller_without_ref_P.Swtichingfactor1_SampleTime_i;
    }

    ParamGet_Controller_without_ref_725.get_parameter
      (&Controller_without_ref_B.cfi);

    // End of Start for MATLABSystem: '<S16>/Swtiching factor1'

    // Start for MATLABSystem: '<S16>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S16>/Swtiching factor2'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_fu.SampleTime ==
          Controller_without_ref_P.Swtichingfactor2_SampleTime_b)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_fu.SampleTime =
        Controller_without_ref_P.Swtichingfactor2_SampleTime_b;
    }

    ParamGet_Controller_without_ref_726.get_parameter
      (&Controller_without_ref_B.spsi);

    // End of Start for MATLABSystem: '<S16>/Swtiching factor2'

    // MATLAB Function: '<S16>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S16>/Swtiching factor1'
    //   MATLABSystem: '<S16>/Swtiching factor2'

    Controller_wit_MATLABFunction_a
      (Controller_without_ref_B.sf_StateTransitionTable_i.u,
       Controller_without_ref_B.cfi, Controller_without_ref_B.spsi,
       &Controller_without_ref_B.sf_MATLABFunction_l);

    // S-Function (sdsprandsrc2): '<S17>/Random Source'
    Controller_without__RandSrc_U_D(&Controller_without_ref_B.RandomSource,
      &Controller_without_ref_P.RandomSource_MinVal_b, 1,
      &Controller_without_ref_P.RandomSource_MaxVal_g, 1,
      Controller_without_ref_DWork.RandomSource_STATE_DWORK_a, 1, 1);

    // Start for MATLABSystem: '<S17>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S17>/Swtiching factor'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_o.SampleTime ==
          Controller_without_ref_P.Swtichingfactor_SampleTime_g)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_o.SampleTime =
        Controller_without_ref_P.Swtichingfactor_SampleTime_g;
    }

    ParamGet_Controller_without_ref_734.get_parameter(&rtb_Swtichingfactor_d_0);

    // End of Start for MATLABSystem: '<S17>/Swtiching factor'

    // State Transition Table: '<S17>/State Transition Table' incorporates:
    //   Constant: '<S17>/Constant'
    //   MATLABSystem: '<S17>/Swtiching factor'
    //   Sum: '<S17>/Add'

    Controller_StateTransitionTable((Controller_without_ref_B.RandomSource +
      (real_T)rtb_Swtichingfactor_d_0) -
      Controller_without_ref_P.Constant_Value_a,
      &Controller_without_ref_B.sf_StateTransitionTable_m,
      &Controller_without_ref_DWork.sf_StateTransitionTable_m);

    // Start for MATLABSystem: '<S17>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S17>/Swtiching factor1'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_f.SampleTime ==
          Controller_without_ref_P.Swtichingfactor1_SampleTime_o)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_f.SampleTime =
        Controller_without_ref_P.Swtichingfactor1_SampleTime_o;
    }

    ParamGet_Controller_without_ref_735.get_parameter
      (&Controller_without_ref_B.cfi);

    // End of Start for MATLABSystem: '<S17>/Swtiching factor1'

    // Start for MATLABSystem: '<S17>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S17>/Swtiching factor2'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_mb.SampleTime ==
          Controller_without_ref_P.Swtichingfactor2_SampleTime_o)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_mb.SampleTime =
        Controller_without_ref_P.Swtichingfactor2_SampleTime_o;
    }

    ParamGet_Controller_without_ref_736.get_parameter
      (&Controller_without_ref_B.spsi);

    // End of Start for MATLABSystem: '<S17>/Swtiching factor2'

    // MATLAB Function: '<S17>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S17>/Swtiching factor1'
    //   MATLABSystem: '<S17>/Swtiching factor2'

    Controller_wit_MATLABFunction_a
      (Controller_without_ref_B.sf_StateTransitionTable_m.u,
       Controller_without_ref_B.cfi, Controller_without_ref_B.spsi,
       &Controller_without_ref_B.sf_MATLABFunction_j);

    // S-Function (sdsprandsrc2): '<S18>/Random Source'
    Controller_without__RandSrc_U_D(&Controller_without_ref_B.RandomSource,
      &Controller_without_ref_P.RandomSource_MinVal_d, 1,
      &Controller_without_ref_P.RandomSource_MaxVal_d, 1,
      Controller_without_ref_DWork.RandomSource_STATE_DWORK_g, 1, 1);

    // Start for MATLABSystem: '<S18>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S18>/Swtiching factor'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_gv.SampleTime ==
          Controller_without_ref_P.Swtichingfactor_SampleTime_n)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_gv.SampleTime =
        Controller_without_ref_P.Swtichingfactor_SampleTime_n;
    }

    ParamGet_Controller_without_ref_744.get_parameter(&rtb_Swtichingfactor_d_0);

    // End of Start for MATLABSystem: '<S18>/Swtiching factor'

    // State Transition Table: '<S18>/State Transition Table' incorporates:
    //   Constant: '<S18>/Constant'
    //   MATLABSystem: '<S18>/Swtiching factor'
    //   Sum: '<S18>/Add'

    Controller_StateTransitionTable((Controller_without_ref_B.RandomSource +
      (real_T)rtb_Swtichingfactor_d_0) -
      Controller_without_ref_P.Constant_Value_a4,
      &Controller_without_ref_B.sf_StateTransitionTable_mx,
      &Controller_without_ref_DWork.sf_StateTransitionTable_mx);

    // Start for MATLABSystem: '<S18>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S18>/Swtiching factor1'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_c2.SampleTime ==
          Controller_without_ref_P.Swtichingfactor1_SampleTime_j)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_c2.SampleTime =
        Controller_without_ref_P.Swtichingfactor1_SampleTime_j;
    }

    ParamGet_Controller_without_ref_745.get_parameter
      (&Controller_without_ref_B.cfi);

    // End of Start for MATLABSystem: '<S18>/Swtiching factor1'

    // Start for MATLABSystem: '<S18>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S18>/Swtiching factor2'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_g0e.SampleTime ==
          Controller_without_ref_P.Swtichingfactor2_SampleTime_e)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_g0e.SampleTime =
        Controller_without_ref_P.Swtichingfactor2_SampleTime_e;
    }

    ParamGet_Controller_without_ref_746.get_parameter
      (&Controller_without_ref_B.spsi);

    // End of Start for MATLABSystem: '<S18>/Swtiching factor2'

    // MATLAB Function: '<S18>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S18>/Swtiching factor1'
    //   MATLABSystem: '<S18>/Swtiching factor2'

    Controller_wit_MATLABFunction_a
      (Controller_without_ref_B.sf_StateTransitionTable_mx.u,
       Controller_without_ref_B.cfi, Controller_without_ref_B.spsi,
       &Controller_without_ref_B.sf_MATLABFunction_o);

    // S-Function (sdsprandsrc2): '<S19>/Random Source'
    Controller_without__RandSrc_U_D(&Controller_without_ref_B.RandomSource,
      &Controller_without_ref_P.RandomSource_MinVal_n, 1,
      &Controller_without_ref_P.RandomSource_MaxVal_n, 1,
      Controller_without_ref_DWork.RandomSource_STATE_DWORK_j, 1, 1);

    // Start for MATLABSystem: '<S19>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S19>/Swtiching factor'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_j0.SampleTime ==
          Controller_without_ref_P.Swtichingfactor_SampleTime_nq)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_j0.SampleTime =
        Controller_without_ref_P.Swtichingfactor_SampleTime_nq;
    }

    ParamGet_Controller_without_ref_850.get_parameter(&rtb_Swtichingfactor_d_0);

    // End of Start for MATLABSystem: '<S19>/Swtiching factor'

    // State Transition Table: '<S19>/State Transition Table' incorporates:
    //   Constant: '<S19>/Constant'
    //   MATLABSystem: '<S19>/Swtiching factor'
    //   Sum: '<S19>/Add'

    Controller_StateTransitionTable((Controller_without_ref_B.RandomSource +
      (real_T)rtb_Swtichingfactor_d_0) -
      Controller_without_ref_P.Constant_Value_dg,
      &Controller_without_ref_B.sf_StateTransitionTable_o,
      &Controller_without_ref_DWork.sf_StateTransitionTable_o);

    // Start for MATLABSystem: '<S19>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S19>/Swtiching factor1'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_hr.SampleTime ==
          Controller_without_ref_P.Swtichingfactor1_SampleTime_a)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_hr.SampleTime =
        Controller_without_ref_P.Swtichingfactor1_SampleTime_a;
    }

    ParamGet_Controller_without_ref_851.get_parameter
      (&Controller_without_ref_B.cfi);

    // End of Start for MATLABSystem: '<S19>/Swtiching factor1'

    // Start for MATLABSystem: '<S19>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S19>/Swtiching factor2'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_dn.SampleTime ==
          Controller_without_ref_P.Swtichingfactor2_SampleTime_n)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_dn.SampleTime =
        Controller_without_ref_P.Swtichingfactor2_SampleTime_n;
    }

    ParamGet_Controller_without_ref_852.get_parameter
      (&Controller_without_ref_B.spsi);

    // End of Start for MATLABSystem: '<S19>/Swtiching factor2'

    // MATLAB Function: '<S19>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S19>/Swtiching factor1'
    //   MATLABSystem: '<S19>/Swtiching factor2'

    Controller_wit_MATLABFunction_a
      (Controller_without_ref_B.sf_StateTransitionTable_o.u,
       Controller_without_ref_B.cfi, Controller_without_ref_B.spsi,
       &Controller_without_ref_B.sf_MATLABFunction_e);

    // S-Function (sdsprandsrc2): '<S20>/Random Source'
    Controller_without__RandSrc_U_D(&Controller_without_ref_B.RandomSource,
      &Controller_without_ref_P.RandomSource_MinVal_i, 1,
      &Controller_without_ref_P.RandomSource_MaxVal_i, 1,
      Controller_without_ref_DWork.RandomSource_STATE_DWORK_h, 1, 1);

    // Start for MATLABSystem: '<S20>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S20>/Swtiching factor'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_gf.SampleTime ==
          Controller_without_ref_P.Swtichingfactor_SampleTime_f)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_gf.SampleTime =
        Controller_without_ref_P.Swtichingfactor_SampleTime_f;
    }

    ParamGet_Controller_without_ref_764.get_parameter(&rtb_Swtichingfactor_d_0);

    // End of Start for MATLABSystem: '<S20>/Swtiching factor'

    // State Transition Table: '<S20>/State Transition Table' incorporates:
    //   Constant: '<S20>/Constant'
    //   MATLABSystem: '<S20>/Swtiching factor'
    //   Sum: '<S20>/Add'

    Controller_StateTransitionTable((Controller_without_ref_B.RandomSource +
      (real_T)rtb_Swtichingfactor_d_0) -
      Controller_without_ref_P.Constant_Value_fo,
      &Controller_without_ref_B.sf_StateTransitionTable_o2,
      &Controller_without_ref_DWork.sf_StateTransitionTable_o2);

    // Start for MATLABSystem: '<S20>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S20>/Swtiching factor1'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_cvy.SampleTime ==
          Controller_without_ref_P.Swtichingfactor1_SampleTime_e)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_cvy.SampleTime =
        Controller_without_ref_P.Swtichingfactor1_SampleTime_e;
    }

    ParamGet_Controller_without_ref_765.get_parameter
      (&Controller_without_ref_B.cfi);

    // End of Start for MATLABSystem: '<S20>/Swtiching factor1'

    // Start for MATLABSystem: '<S20>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S20>/Swtiching factor2'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_dt.SampleTime ==
          Controller_without_ref_P.Swtichingfactor2_SampleTime_c)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_dt.SampleTime =
        Controller_without_ref_P.Swtichingfactor2_SampleTime_c;
    }

    ParamGet_Controller_without_ref_766.get_parameter
      (&Controller_without_ref_B.spsi);

    // End of Start for MATLABSystem: '<S20>/Swtiching factor2'

    // MATLAB Function: '<S20>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S20>/Swtiching factor1'
    //   MATLABSystem: '<S20>/Swtiching factor2'

    Controller_wit_MATLABFunction_a
      (Controller_without_ref_B.sf_StateTransitionTable_o2.u,
       Controller_without_ref_B.cfi, Controller_without_ref_B.spsi,
       &Controller_without_ref_B.sf_MATLABFunction_io);

    // SignalConversion: '<S5>/OutportBufferForThrusters'
    Controller_without_ref_B.OutportBufferForThrusters[0] =
      Controller_without_ref_B.sf_MATLABFunction_a.y;
    Controller_without_ref_B.OutportBufferForThrusters[1] =
      Controller_without_ref_B.sf_MATLABFunction_l.y;
    Controller_without_ref_B.OutportBufferForThrusters[2] =
      Controller_without_ref_B.sf_MATLABFunction_j.y;
    Controller_without_ref_B.OutportBufferForThrusters[3] =
      Controller_without_ref_B.sf_MATLABFunction_o.y;
    Controller_without_ref_B.OutportBufferForThrusters[4] =
      Controller_without_ref_B.sf_MATLABFunction_e.y;
    Controller_without_ref_B.OutportBufferForThrusters[5] =
      Controller_without_ref_B.sf_MATLABFunction_io.y;
  }

  // End of Outputs for SubSystem: '<Root>/Telegraph'

  // Start for MATLABSystem: '<Root>/Get controller type' incorporates:
  //   MATLABSystem: '<Root>/Get controller type'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_nl.SampleTime ==
        Controller_without_ref_P.Getcontrollertype_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_nl.SampleTime =
      Controller_without_ref_P.Getcontrollertype_SampleTime;
  }

  ParamGet_Controller_without_ref_106.get_parameter(&rtb_Swtichingfactor_d_0);

  // End of Start for MATLABSystem: '<Root>/Get controller type'

  // Outputs for Atomic SubSystem: '<Root>/cmd_vel'
  // Start for MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   MATLABSystem: '<S8>/SourceBlock'

  rtb_LogicalOperator = Sub_Controller_without_ref_1.get_latest_msg
    (&Controller_without_ref_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S33>/Enable'

  // MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Inport: '<S33>/In1'

  if (rtb_LogicalOperator) {
    Controller_without_ref_B.In1_m = Controller_without_ref_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/cmd_vel'

  // Outputs for Atomic SubSystem: '<Root>/imu_data'
  // Start for MATLABSystem: '<S10>/SourceBlock' incorporates:
  //   MATLABSystem: '<S10>/SourceBlock'

  p = Sub_Controller_without_ref_28.get_latest_msg
    (&Controller_without_ref_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S58>/Enable'

  // MATLABSystem: '<S10>/SourceBlock' incorporates:
  //   Inport: '<S58>/In1'

  if (p) {
    Controller_without_ref_B.In1 = Controller_without_ref_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/cmd_vel'
  // Logic: '<Root>/Logical Operator' incorporates:
  //   MATLABSystem: '<S10>/SourceBlock'
  //   MATLABSystem: '<S8>/SourceBlock'

  rtb_LogicalOperator = (rtb_LogicalOperator || p);

  // End of Outputs for SubSystem: '<Root>/cmd_vel'
  // End of Outputs for SubSystem: '<Root>/imu_data'

  // Outputs for Enabled SubSystem: '<Root>/Xbox_input' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (rtb_LogicalOperator) {
    // SignalConversion: '<S6>/TmpSignal ConversionAtBus SelectorOutport1'
    Controller_without_ref_B.X_h = Controller_without_ref_B.In1_m.Linear.X;

    // SignalConversion: '<S6>/TmpSignal ConversionAtBus SelectorOutport2'
    Controller_without_ref_B.Y_i = Controller_without_ref_B.In1_m.Linear.Y;

    // SignalConversion: '<S6>/TmpSignal ConversionAtBus SelectorOutport3'
    Controller_without_ref_B.Z = Controller_without_ref_B.In1_m.Linear.Z;

    // SignalConversion: '<S6>/TmpSignal ConversionAtBus SelectorOutport4'
    Controller_without_ref_B.X_hw = Controller_without_ref_B.In1_m.Angular.X;

    // SignalConversion: '<S6>/TmpSignal ConversionAtBus SelectorOutport5'
    Controller_without_ref_B.Y_in = Controller_without_ref_B.In1_m.Angular.Y;

    // SignalConversion: '<S6>/TmpSignal ConversionAtBus SelectorOutport6'
    Controller_without_ref_B.Z_n = Controller_without_ref_B.In1_m.Angular.Z;
  }

  // End of Outputs for SubSystem: '<Root>/Xbox_input'

  // Start for MATLABSystem: '<S4>/Get front strafe decouple' incorporates:
  //   MATLABSystem: '<S4>/Get front strafe decouple'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_mp.SampleTime ==
        Controller_without_ref_P.Getfrontstrafedecouple_Sample_b)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_mp.SampleTime =
      Controller_without_ref_P.Getfrontstrafedecouple_Sample_b;
  }

  ParamGet_Controller_without_ref_810.get_parameter
    (&Controller_without_ref_B.RandomSource);

  // Start for MATLABSystem: '<S4>/Get front forward decouple' incorporates:
  //   MATLABSystem: '<S4>/Get front forward decouple'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_ij.SampleTime ==
        Controller_without_ref_P.Getfrontforwarddecouple_Sampl_h)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_ij.SampleTime =
      Controller_without_ref_P.Getfrontforwarddecouple_Sampl_h;
  }

  ParamGet_Controller_without_ref_808.get_parameter
    (&Controller_without_ref_B.cfi);

  // Start for MATLABSystem: '<S4>/Get front pitch bias' incorporates:
  //   MATLABSystem: '<S4>/Get front pitch bias'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_nr.SampleTime ==
        Controller_without_ref_P.Getfrontpitchbias_SampleTime_n)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_nr.SampleTime =
      Controller_without_ref_P.Getfrontpitchbias_SampleTime_n;
  }

  ParamGet_Controller_without_ref_809.get_parameter
    (&Controller_without_ref_B.spsi);

  // Start for MATLABSystem: '<S4>/Get front vertical bias' incorporates:
  //   MATLABSystem: '<S4>/Get front vertical bias'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_o5.SampleTime ==
        Controller_without_ref_P.Getfrontverticalbias_SampleTi_e)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_o5.SampleTime =
      Controller_without_ref_P.Getfrontverticalbias_SampleTi_e;
  }

  ParamGet_Controller_without_ref_811.get_parameter
    (&Controller_without_ref_B.cpsi);

  // Start for MATLABSystem: '<S4>/Get buoyancy' incorporates:
  //   MATLABSystem: '<S4>/Get buoyancy'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_ot.SampleTime ==
        Controller_without_ref_P.Getbuoyancy_SampleTime_e)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_ot.SampleTime =
      Controller_without_ref_P.Getbuoyancy_SampleTime_e;
  }

  ParamGet_Controller_without_ref_807.get_parameter
    (&Controller_without_ref_B.stheta);

  // MATLAB Function: '<S4>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S4>/Get buoyancy'
  //   Start for MATLABSystem: '<S4>/Get buoyancy'
  //   MATLABSystem: '<S4>/Get front forward decouple'
  //   Start for MATLABSystem: '<S4>/Get front forward decouple'
  //   MATLABSystem: '<S4>/Get front pitch bias'
  //   Start for MATLABSystem: '<S4>/Get front pitch bias'
  //   MATLABSystem: '<S4>/Get front strafe decouple'
  //   Start for MATLABSystem: '<S4>/Get front strafe decouple'
  //   MATLABSystem: '<S4>/Get front vertical bias'
  //   Start for MATLABSystem: '<S4>/Get front vertical bias'

  Controller_witho_MATLABFunction(Controller_without_ref_B.X_hw,
    Controller_without_ref_B.Y_in, Controller_without_ref_B.Z_n,
    Controller_without_ref_B.X_h, Controller_without_ref_B.Y_i,
    Controller_without_ref_B.Z, Controller_without_ref_B.RandomSource,
    Controller_without_ref_B.cfi, Controller_without_ref_B.spsi,
    Controller_without_ref_B.cpsi, Controller_without_ref_B.stheta,
    &Controller_without_ref_B.sf_MATLABFunction);

  // Outputs for Enabled SubSystem: '<Root>/states' incorporates:
  //   EnablePort: '<S11>/Enable'

  if (rtb_LogicalOperator) {
    // MATLAB Function: '<S11>/removeGravity' incorporates:
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    // MATLAB Function 'states/removeGravity': '<S59>:1'
    //  rotmatrix = [2*w^2+2*x^2-1, 2*x*y-2*w*z, 2*x*z+2*w*y;
    //      2*x*y+2*w*z, 2*w^2+2*y^2-1, 2*x*z-2*w*x;
    //      2*x*z-2*w*y, 2*y*z+2*w*x, 2*w^2+2*z^2-1];
    // '<S59>:1:8'
    Controller_without_ref_B.RandomSource = Controller_without_ref_B.In1.Data[2];
    Controller_without_ref_sind(&Controller_without_ref_B.RandomSource);

    // '<S59>:1:9'
    Controller_without_ref_B.cfi = Controller_without_ref_B.In1.Data[2];
    Controller_without_ref_cosd(&Controller_without_ref_B.cfi);

    // '<S59>:1:10'
    Controller_without_ref_B.spsi = Controller_without_ref_B.In1.Data[0];
    Controller_without_ref_sind(&Controller_without_ref_B.spsi);

    // '<S59>:1:11'
    Controller_without_ref_B.cpsi = Controller_without_ref_B.In1.Data[0];
    Controller_without_ref_cosd(&Controller_without_ref_B.cpsi);

    // '<S59>:1:12'
    Controller_without_ref_B.stheta = Controller_without_ref_B.In1.Data[1];
    Controller_without_ref_sind(&Controller_without_ref_B.stheta);

    // '<S59>:1:13'
    Controller_without_ref_B.ctheta_c = Controller_without_ref_B.In1.Data[1];
    Controller_without_ref_cosd(&Controller_without_ref_B.ctheta_c);

    // '<S59>:1:16'
    //  Gravity projected in the body fixed frame
    // '<S59>:1:22'
    Controller_without_ref_B.ctheta[0] = Controller_without_ref_B.ctheta_c *
      Controller_without_ref_B.cpsi;
    Controller_without_ref_B.ctheta[3] = Controller_without_ref_B.ctheta_c *
      Controller_without_ref_B.spsi;
    Controller_without_ref_B.ctheta[6] = -Controller_without_ref_B.RandomSource;
    Controller_without_ref_B.ctheta[1] = Controller_without_ref_B.RandomSource *
      Controller_without_ref_B.stheta * Controller_without_ref_B.cpsi -
      Controller_without_ref_B.cfi * Controller_without_ref_B.spsi;
    Controller_without_ref_B.ctheta[4] = Controller_without_ref_B.RandomSource *
      Controller_without_ref_B.stheta * Controller_without_ref_B.spsi +
      Controller_without_ref_B.cfi * Controller_without_ref_B.cpsi;
    Controller_without_ref_B.ctheta[7] = Controller_without_ref_B.RandomSource *
      Controller_without_ref_B.ctheta_c;
    Controller_without_ref_B.ctheta[2] = Controller_without_ref_B.cfi *
      Controller_without_ref_B.stheta * Controller_without_ref_B.cpsi +
      Controller_without_ref_B.RandomSource * Controller_without_ref_B.spsi;
    Controller_without_ref_B.ctheta[5] = Controller_without_ref_B.cfi *
      Controller_without_ref_B.stheta * Controller_without_ref_B.spsi -
      Controller_without_ref_B.RandomSource * Controller_without_ref_B.spsi;
    Controller_without_ref_B.ctheta[8] = Controller_without_ref_B.cfi *
      Controller_without_ref_B.ctheta_c;
    Controller_without_ref_inv(Controller_without_ref_B.ctheta,
      Controller_without_ref_B.dv0);
    for (i_0 = 0; i_0 < 3; i_0++) {
      Controller_without_ref_B.acc[i_0] = Controller_without_ref_B.dv0[i_0 + 6] *
        -9.8 + (Controller_without_ref_B.dv0[i_0 + 3] * 0.0 +
                Controller_without_ref_B.dv0[i_0] * 0.0);
    }

    // SignalConversion: '<S11>/OutportBufferFor<acc X [m//s^2]>' incorporates:
    //   MATLAB Function: '<S11>/removeGravity'
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    //  Removed gravity from the acceleration
    // '<S59>:1:25'
    // '<S59>:1:26'
    // '<S59>:1:27'
    Controller_without_ref_B.OutportBufferForaccXms2 =
      Controller_without_ref_B.In1.Data[7] + Controller_without_ref_B.acc[0];

    // SignalConversion: '<S11>/OutportBufferFor<acc Y [m//s^2]>' incorporates:
    //   MATLAB Function: '<S11>/removeGravity'
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_without_ref_B.OutportBufferForaccYms2 =
      Controller_without_ref_B.In1.Data[8] + Controller_without_ref_B.acc[1];

    // SignalConversion: '<S11>/OutportBufferFor<acc Z [m//s^2]>' incorporates:
    //   MATLAB Function: '<S11>/removeGravity'
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_without_ref_B.OutportBufferForaccZms2 =
      Controller_without_ref_B.In1.Data[9] + Controller_without_ref_B.acc[2];

    // SignalConversion: '<S11>/OutportBufferFor<angular_vel X [degrees//s]>' incorporates:
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_without_ref_B.X = Controller_without_ref_B.In1.Data[3];

    // SignalConversion: '<S11>/OutportBufferFor<angular_vel Y [degrees//s]>' incorporates:
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_without_ref_B.Y = Controller_without_ref_B.In1.Data[4];

    // SignalConversion: '<S11>/OutportBufferFor<angular_vel Z [degrees//s]>' incorporates:
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_without_ref_B.OutportBufferForangular_velZdeg =
      Controller_without_ref_B.In1.Data[5];
  }

  // End of Outputs for SubSystem: '<Root>/states'

  // Start for MATLABSystem: '<S7>/Enable integration?' incorporates:
  //   MATLABSystem: '<S7>/Enable integration?'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_g0.SampleTime ==
        Controller_without_ref_P.Enableintegration_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_g0.SampleTime =
      Controller_without_ref_P.Enableintegration_SampleTime;
  }

  ParamGet_Controller_without_ref_686.get_parameter(&p);

  // End of Start for MATLABSystem: '<S7>/Enable integration?'

  // DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S7>/Discrete-Time Integrator2'
  //   Logic: '<S7>/Logical Operator'
  //   MATLABSystem: '<S7>/Enable integration?'

  if (!p) {
    Controller_without_ref_DWork.DiscreteTimeIntegrator_DSTATE =
      Controller_without_ref_P.DiscreteTimeIntegrator_IC;
    Controller_without_ref_DWork.DiscreteTimeIntegrator1_DSTATE =
      Controller_without_ref_P.DiscreteTimeIntegrator1_IC;
    Controller_without_ref_DWork.DiscreteTimeIntegrator2_DSTATE =
      Controller_without_ref_P.DiscreteTimeIntegrator2_IC;
  }

  // Outputs for Enabled SubSystem: '<Root>/decController' incorporates:
  //   EnablePort: '<S9>/Enable'

  // Outputs for Enabled SubSystem: '<Root>/Create errors' incorporates:
  //   EnablePort: '<S2>/Enable'

  if (rtb_LogicalOperator) {
    // Sum: '<S2>/Error x'
    Controller_without_ref_B.Errorx = Controller_without_ref_B.X_hw -
      Controller_without_ref_B.X;

    // Sum: '<S2>/Error y'
    Controller_without_ref_B.Errory = Controller_without_ref_B.Y_in -
      Controller_without_ref_B.Y;

    // Sum: '<S2>/Error z'
    Controller_without_ref_B.Errorz = Controller_without_ref_B.Z_n -
      Controller_without_ref_B.OutportBufferForangular_velZdeg;

    // Sum: '<S2>/Error z8' incorporates:
    //   DiscreteIntegrator: '<S7>/Discrete-Time Integrator'

    Controller_without_ref_B.Errorz8 = Controller_without_ref_B.X_h -
      Controller_without_ref_DWork.DiscreteTimeIntegrator_DSTATE;

    // Sum: '<S2>/Error z9' incorporates:
    //   DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'

    Controller_without_ref_B.Errorz9 = Controller_without_ref_B.Y_i -
      Controller_without_ref_DWork.DiscreteTimeIntegrator1_DSTATE;

    // Sum: '<S2>/Error z10' incorporates:
    //   DiscreteIntegrator: '<S7>/Discrete-Time Integrator2'

    Controller_without_ref_B.Errorz10 = Controller_without_ref_B.Z -
      Controller_without_ref_DWork.DiscreteTimeIntegrator2_DSTATE;

    // Start for MATLABSystem: '<S41>/P_angular_vel_x' incorporates:
    //   MATLABSystem: '<S41>/P_angular_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_bm.SampleTime ==
          Controller_without_ref_P.P_angular_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_bm.SampleTime =
        Controller_without_ref_P.P_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_508.get_parameter
      (&Controller_without_ref_B.cfi);

    // End of Start for MATLABSystem: '<S41>/P_angular_vel_x'

    // Start for MATLABSystem: '<S41>/D_angular_vel_x' incorporates:
    //   MATLABSystem: '<S41>/D_angular_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_be.SampleTime ==
          Controller_without_ref_P.D_angular_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_be.SampleTime =
        Controller_without_ref_P.D_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_505.get_parameter
      (&Controller_without_ref_B.RandomSource);

    // End of Start for MATLABSystem: '<S41>/D_angular_vel_x'

    // Start for MATLABSystem: '<S41>/N_angular_vel_x ' incorporates:
    //   MATLABSystem: '<S41>/N_angular_vel_x '

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_l.SampleTime ==
          Controller_without_ref_P.N_angular_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_l.SampleTime =
        Controller_without_ref_P.N_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_507.get_parameter
      (&Controller_without_ref_B.spsi);

    // End of Start for MATLABSystem: '<S41>/N_angular_vel_x '

    // Product: '<S40>/NOut' incorporates:
    //   DiscreteIntegrator: '<S40>/Filter'
    //   MATLABSystem: '<S41>/D_angular_vel_x'
    //   MATLABSystem: '<S41>/N_angular_vel_x '
    //   Product: '<S40>/DOut'
    //   Sum: '<S40>/SumD'

    Controller_without_ref_B.RandomSource = (Controller_without_ref_B.Errorx *
      Controller_without_ref_B.RandomSource -
      Controller_without_ref_DWork.Filter_DSTATE) *
      Controller_without_ref_B.spsi;

    // Sum: '<S40>/Sum' incorporates:
    //   DiscreteIntegrator: '<S40>/Integrator'
    //   MATLABSystem: '<S41>/P_angular_vel_x'
    //   Product: '<S40>/POut'

    Controller_without_ref_B.SignPreIntegrator =
      (Controller_without_ref_B.Errorx * Controller_without_ref_B.cfi +
       Controller_without_ref_DWork.Integrator_DSTATE) +
      Controller_without_ref_B.RandomSource;

    // DeadZone: '<S42>/DeadZone'
    if (Controller_without_ref_B.SignPreIntegrator >
        Controller_without_ref_P.PIDController_UpperSaturationLi) {
      Controller_without_ref_B.SumI1 =
        Controller_without_ref_B.SignPreIntegrator -
        Controller_without_ref_P.PIDController_UpperSaturationLi;
    } else if (Controller_without_ref_B.SignPreIntegrator >=
               Controller_without_ref_P.PIDController_LowerSaturationLi) {
      Controller_without_ref_B.SumI1 = 0.0;
    } else {
      Controller_without_ref_B.SumI1 =
        Controller_without_ref_B.SignPreIntegrator -
        Controller_without_ref_P.PIDController_LowerSaturationLi;
    }

    // End of DeadZone: '<S42>/DeadZone'

    // RelationalOperator: '<S42>/NotEqual' incorporates:
    //   Gain: '<S42>/ZeroGain'

    rtb_NotEqual = (Controller_without_ref_P.ZeroGain_Gain *
                    Controller_without_ref_B.SignPreIntegrator !=
                    Controller_without_ref_B.SumI1);

    // Signum: '<S42>/SignDeltaU'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      Controller_without_ref_B.SumI1 = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      Controller_without_ref_B.SumI1 = 1.0;
    } else {
      if (Controller_without_ref_B.SumI1 == 0.0) {
        Controller_without_ref_B.SumI1 = 0.0;
      }
    }

    // End of Signum: '<S42>/SignDeltaU'

    // DataTypeConversion: '<S42>/DataTypeConv1'
    if (Controller_without_ref_B.SumI1 < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_without_ref_B.SumI1;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // Start for MATLABSystem: '<S41>/I_angular_vel_x' incorporates:
    //   MATLABSystem: '<S41>/I_angular_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_pb.SampleTime ==
          Controller_without_ref_P.I_angular_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_pb.SampleTime =
        Controller_without_ref_P.I_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_506.get_parameter
      (&Controller_without_ref_B.cfi);

    // End of Start for MATLABSystem: '<S41>/I_angular_vel_x'

    // Saturate: '<S40>/Saturate'
    if (Controller_without_ref_B.SignPreIntegrator >
        Controller_without_ref_P.PIDController_UpperSaturationLi) {
      Controller_without_ref_B.Saturate =
        Controller_without_ref_P.PIDController_UpperSaturationLi;
    } else if (Controller_without_ref_B.SignPreIntegrator <
               Controller_without_ref_P.PIDController_LowerSaturationLi) {
      Controller_without_ref_B.Saturate =
        Controller_without_ref_P.PIDController_LowerSaturationLi;
    } else {
      Controller_without_ref_B.Saturate =
        Controller_without_ref_B.SignPreIntegrator;
    }

    // End of Saturate: '<S40>/Saturate'

    // Sum: '<S40>/SumI1' incorporates:
    //   Gain: '<S40>/Kt'
    //   MATLABSystem: '<S41>/I_angular_vel_x'
    //   Product: '<S40>/IOut'
    //   Sum: '<S40>/SumI3'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.X_hw -
      Controller_without_ref_B.Saturate) *
      Controller_without_ref_P.PIDController_Kt +
      Controller_without_ref_B.Errorx * Controller_without_ref_B.cfi;

    // Signum: '<S42>/SignPreIntegrator'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S42>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S42>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = 1.0;
    } else if (Controller_without_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S42>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = 0.0;
    } else {
      // DataTypeConversion: '<S42>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = Controller_without_ref_B.SumI1;
    }

    // End of Signum: '<S42>/SignPreIntegrator'

    // DataTypeConversion: '<S42>/DataTypeConv2'
    if (Controller_without_ref_B.Switch_i < 128.0) {
      tmp = (int8_T)Controller_without_ref_B.Switch_i;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S40>/Switch' incorporates:
    //   Constant: '<S40>/Constant'
    //   DataTypeConversion: '<S42>/DataTypeConv1'
    //   Logic: '<S42>/AND'
    //   RelationalOperator: '<S42>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_without_ref_B.cfi = Controller_without_ref_P.Constant_Value_ke;
    } else {
      Controller_without_ref_B.cfi = Controller_without_ref_B.SumI1;
    }

    // End of Switch: '<S40>/Switch'

    // Start for MATLABSystem: '<S44>/P_angular_vel_y' incorporates:
    //   MATLABSystem: '<S44>/P_angular_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_b.SampleTime ==
          Controller_without_ref_P.P_angular_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_b.SampleTime =
        Controller_without_ref_P.P_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_522.get_parameter
      (&Controller_without_ref_B.cpsi);

    // End of Start for MATLABSystem: '<S44>/P_angular_vel_y'

    // Start for MATLABSystem: '<S44>/D_angular_vel_y' incorporates:
    //   MATLABSystem: '<S44>/D_angular_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_m.SampleTime ==
          Controller_without_ref_P.D_angular_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_m.SampleTime =
        Controller_without_ref_P.D_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_519.get_parameter
      (&Controller_without_ref_B.spsi);

    // End of Start for MATLABSystem: '<S44>/D_angular_vel_y'

    // Start for MATLABSystem: '<S44>/N_angular_vel_y ' incorporates:
    //   MATLABSystem: '<S44>/N_angular_vel_y '

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_dp.SampleTime ==
          Controller_without_ref_P.N_angular_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_dp.SampleTime =
        Controller_without_ref_P.N_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_521.get_parameter
      (&Controller_without_ref_B.stheta);

    // End of Start for MATLABSystem: '<S44>/N_angular_vel_y '

    // Product: '<S43>/NOut' incorporates:
    //   DiscreteIntegrator: '<S43>/Filter'
    //   MATLABSystem: '<S44>/D_angular_vel_y'
    //   MATLABSystem: '<S44>/N_angular_vel_y '
    //   Product: '<S43>/DOut'
    //   Sum: '<S43>/SumD'

    Controller_without_ref_B.spsi = (Controller_without_ref_B.Errory *
      Controller_without_ref_B.spsi -
      Controller_without_ref_DWork.Filter_DSTATE_c) *
      Controller_without_ref_B.stheta;

    // Sum: '<S43>/Sum' incorporates:
    //   DiscreteIntegrator: '<S43>/Integrator'
    //   MATLABSystem: '<S44>/P_angular_vel_y'
    //   Product: '<S43>/POut'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Errory *
      Controller_without_ref_B.cpsi +
      Controller_without_ref_DWork.Integrator_DSTATE_h) +
      Controller_without_ref_B.spsi;

    // DeadZone: '<S45>/DeadZone'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_o) {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_UpperSaturation_o;
    } else if (Controller_without_ref_B.SumI1 >=
               Controller_without_ref_P.PIDController_LowerSaturation_e) {
      Controller_without_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_LowerSaturation_e;
    }

    // End of DeadZone: '<S45>/DeadZone'

    // RelationalOperator: '<S45>/NotEqual' incorporates:
    //   Gain: '<S45>/ZeroGain'

    rtb_NotEqual = (Controller_without_ref_P.ZeroGain_Gain_k *
                    Controller_without_ref_B.SumI1 !=
                    Controller_without_ref_B.SignPreIntegrator);

    // Signum: '<S45>/SignDeltaU'
    if (Controller_without_ref_B.SignPreIntegrator < 0.0) {
      Controller_without_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_without_ref_B.SignPreIntegrator > 0.0) {
      Controller_without_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_without_ref_B.SignPreIntegrator == 0.0) {
        Controller_without_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S45>/SignDeltaU'

    // Start for MATLABSystem: '<S44>/I_angular_vel_y' incorporates:
    //   MATLABSystem: '<S44>/I_angular_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_ep.SampleTime ==
          Controller_without_ref_P.I_angular_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_ep.SampleTime =
        Controller_without_ref_P.I_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_520.get_parameter
      (&Controller_without_ref_B.cpsi);

    // End of Start for MATLABSystem: '<S44>/I_angular_vel_y'

    // Saturate: '<S43>/Saturate'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_o) {
      Controller_without_ref_B.Saturate_f =
        Controller_without_ref_P.PIDController_UpperSaturation_o;
    } else if (Controller_without_ref_B.SumI1 <
               Controller_without_ref_P.PIDController_LowerSaturation_e) {
      Controller_without_ref_B.Saturate_f =
        Controller_without_ref_P.PIDController_LowerSaturation_e;
    } else {
      Controller_without_ref_B.Saturate_f = Controller_without_ref_B.SumI1;
    }

    // End of Saturate: '<S43>/Saturate'

    // Sum: '<S43>/SumI1' incorporates:
    //   Gain: '<S43>/Kt'
    //   MATLABSystem: '<S44>/I_angular_vel_y'
    //   Product: '<S43>/IOut'
    //   Sum: '<S43>/SumI3'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Y_in -
      Controller_without_ref_B.Saturate_f) *
      Controller_without_ref_P.PIDController_Kt_j +
      Controller_without_ref_B.Errory * Controller_without_ref_B.cpsi;

    // Signum: '<S45>/SignPreIntegrator'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S45>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S45>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = 1.0;
    } else if (Controller_without_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S45>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = 0.0;
    } else {
      // DataTypeConversion: '<S45>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = Controller_without_ref_B.SumI1;
    }

    // End of Signum: '<S45>/SignPreIntegrator'

    // DataTypeConversion: '<S45>/DataTypeConv1'
    if (Controller_without_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_without_ref_B.SignPreIntegrator;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S45>/DataTypeConv1'

    // DataTypeConversion: '<S45>/DataTypeConv2'
    if (Controller_without_ref_B.Switch_i < 128.0) {
      tmp = (int8_T)Controller_without_ref_B.Switch_i;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S43>/Switch' incorporates:
    //   Constant: '<S43>/Constant'
    //   Logic: '<S45>/AND'
    //   RelationalOperator: '<S45>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_without_ref_B.cpsi = Controller_without_ref_P.Constant_Value_m;
    } else {
      Controller_without_ref_B.cpsi = Controller_without_ref_B.SumI1;
    }

    // End of Switch: '<S43>/Switch'

    // Start for MATLABSystem: '<S47>/P_angular_vel_z' incorporates:
    //   MATLABSystem: '<S47>/P_angular_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_e.SampleTime ==
          Controller_without_ref_P.P_angular_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_e.SampleTime =
        Controller_without_ref_P.P_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_536.get_parameter
      (&Controller_without_ref_B.ctheta_c);

    // End of Start for MATLABSystem: '<S47>/P_angular_vel_z'

    // Start for MATLABSystem: '<S47>/D_angular_vel_z' incorporates:
    //   MATLABSystem: '<S47>/D_angular_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_jg.SampleTime ==
          Controller_without_ref_P.D_angular_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_jg.SampleTime =
        Controller_without_ref_P.D_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_533.get_parameter
      (&Controller_without_ref_B.stheta);

    // End of Start for MATLABSystem: '<S47>/D_angular_vel_z'

    // Start for MATLABSystem: '<S47>/N_angular_vel_z ' incorporates:
    //   MATLABSystem: '<S47>/N_angular_vel_z '

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_g.SampleTime ==
          Controller_without_ref_P.N_angular_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_g.SampleTime =
        Controller_without_ref_P.N_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_535.get_parameter
      (&Controller_without_ref_B.NOut_b);

    // End of Start for MATLABSystem: '<S47>/N_angular_vel_z '

    // Product: '<S46>/NOut' incorporates:
    //   DiscreteIntegrator: '<S46>/Filter'
    //   MATLABSystem: '<S47>/D_angular_vel_z'
    //   MATLABSystem: '<S47>/N_angular_vel_z '
    //   Product: '<S46>/DOut'
    //   Sum: '<S46>/SumD'

    Controller_without_ref_B.stheta = (Controller_without_ref_B.Errorz *
      Controller_without_ref_B.stheta -
      Controller_without_ref_DWork.Filter_DSTATE_f) *
      Controller_without_ref_B.NOut_b;

    // Sum: '<S46>/Sum' incorporates:
    //   DiscreteIntegrator: '<S46>/Integrator'
    //   MATLABSystem: '<S47>/P_angular_vel_z'
    //   Product: '<S46>/POut'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Errorz *
      Controller_without_ref_B.ctheta_c +
      Controller_without_ref_DWork.Integrator_DSTATE_a) +
      Controller_without_ref_B.stheta;

    // DeadZone: '<S48>/DeadZone'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_e) {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_UpperSaturation_e;
    } else if (Controller_without_ref_B.SumI1 >=
               Controller_without_ref_P.PIDController_LowerSaturation_p) {
      Controller_without_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_LowerSaturation_p;
    }

    // End of DeadZone: '<S48>/DeadZone'

    // RelationalOperator: '<S48>/NotEqual' incorporates:
    //   Gain: '<S48>/ZeroGain'

    rtb_NotEqual = (Controller_without_ref_P.ZeroGain_Gain_a *
                    Controller_without_ref_B.SumI1 !=
                    Controller_without_ref_B.SignPreIntegrator);

    // Signum: '<S48>/SignDeltaU'
    if (Controller_without_ref_B.SignPreIntegrator < 0.0) {
      Controller_without_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_without_ref_B.SignPreIntegrator > 0.0) {
      Controller_without_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_without_ref_B.SignPreIntegrator == 0.0) {
        Controller_without_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S48>/SignDeltaU'

    // Start for MATLABSystem: '<S47>/I_angular_vel_z' incorporates:
    //   MATLABSystem: '<S47>/I_angular_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_p.SampleTime ==
          Controller_without_ref_P.I_angular_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_p.SampleTime =
        Controller_without_ref_P.I_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_534.get_parameter
      (&Controller_without_ref_B.ctheta_c);

    // End of Start for MATLABSystem: '<S47>/I_angular_vel_z'

    // Saturate: '<S46>/Saturate'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_e) {
      Controller_without_ref_B.Saturate_i =
        Controller_without_ref_P.PIDController_UpperSaturation_e;
    } else if (Controller_without_ref_B.SumI1 <
               Controller_without_ref_P.PIDController_LowerSaturation_p) {
      Controller_without_ref_B.Saturate_i =
        Controller_without_ref_P.PIDController_LowerSaturation_p;
    } else {
      Controller_without_ref_B.Saturate_i = Controller_without_ref_B.SumI1;
    }

    // End of Saturate: '<S46>/Saturate'

    // Sum: '<S46>/SumI1' incorporates:
    //   Gain: '<S46>/Kt'
    //   MATLABSystem: '<S47>/I_angular_vel_z'
    //   Product: '<S46>/IOut'
    //   Sum: '<S46>/SumI3'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Z_n -
      Controller_without_ref_B.Saturate_i) *
      Controller_without_ref_P.PIDController_Kt_p +
      Controller_without_ref_B.Errorz * Controller_without_ref_B.ctheta_c;

    // Signum: '<S48>/SignPreIntegrator'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S48>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S48>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = 1.0;
    } else if (Controller_without_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S48>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = 0.0;
    } else {
      // DataTypeConversion: '<S48>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = Controller_without_ref_B.SumI1;
    }

    // End of Signum: '<S48>/SignPreIntegrator'

    // DataTypeConversion: '<S48>/DataTypeConv1'
    if (Controller_without_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_without_ref_B.SignPreIntegrator;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S48>/DataTypeConv1'

    // DataTypeConversion: '<S48>/DataTypeConv2'
    if (Controller_without_ref_B.Switch_i < 128.0) {
      tmp = (int8_T)Controller_without_ref_B.Switch_i;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S46>/Switch' incorporates:
    //   Constant: '<S46>/Constant'
    //   Logic: '<S48>/AND'
    //   RelationalOperator: '<S48>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_without_ref_B.ctheta_c =
        Controller_without_ref_P.Constant_Value_fw;
    } else {
      Controller_without_ref_B.ctheta_c = Controller_without_ref_B.SumI1;
    }

    // End of Switch: '<S46>/Switch'

    // Start for MATLABSystem: '<S50>/P_vel_x' incorporates:
    //   MATLABSystem: '<S50>/P_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_ns.SampleTime ==
          Controller_without_ref_P.P_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_ns.SampleTime =
        Controller_without_ref_P.P_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_550.get_parameter
      (&Controller_without_ref_B.Switch_e);

    // End of Start for MATLABSystem: '<S50>/P_vel_x'

    // Start for MATLABSystem: '<S50>/D_vel_x' incorporates:
    //   MATLABSystem: '<S50>/D_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_d.SampleTime ==
          Controller_without_ref_P.D_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_d.SampleTime =
        Controller_without_ref_P.D_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_547.get_parameter
      (&Controller_without_ref_B.NOut_b);

    // End of Start for MATLABSystem: '<S50>/D_vel_x'

    // Start for MATLABSystem: '<S50>/N_vel_x ' incorporates:
    //   MATLABSystem: '<S50>/N_vel_x '

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_a3.SampleTime ==
          Controller_without_ref_P.N_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_a3.SampleTime =
        Controller_without_ref_P.N_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_549.get_parameter
      (&Controller_without_ref_B.SignPreIntegrator);

    // End of Start for MATLABSystem: '<S50>/N_vel_x '

    // Product: '<S49>/NOut' incorporates:
    //   DiscreteIntegrator: '<S49>/Filter'
    //   MATLABSystem: '<S50>/D_vel_x'
    //   MATLABSystem: '<S50>/N_vel_x '
    //   Product: '<S49>/DOut'
    //   Sum: '<S49>/SumD'

    Controller_without_ref_B.NOut_b = (Controller_without_ref_B.Errorz8 *
      Controller_without_ref_B.NOut_b -
      Controller_without_ref_DWork.Filter_DSTATE_a) *
      Controller_without_ref_B.SignPreIntegrator;

    // Sum: '<S49>/Sum' incorporates:
    //   DiscreteIntegrator: '<S49>/Integrator'
    //   MATLABSystem: '<S50>/P_vel_x'
    //   Product: '<S49>/POut'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Errorz8 *
      Controller_without_ref_B.Switch_e +
      Controller_without_ref_DWork.Integrator_DSTATE_f) +
      Controller_without_ref_B.NOut_b;

    // DeadZone: '<S51>/DeadZone'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_d) {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_UpperSaturation_d;
    } else if (Controller_without_ref_B.SumI1 >=
               Controller_without_ref_P.PIDController_LowerSaturation_i) {
      Controller_without_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_LowerSaturation_i;
    }

    // End of DeadZone: '<S51>/DeadZone'

    // RelationalOperator: '<S51>/NotEqual' incorporates:
    //   Gain: '<S51>/ZeroGain'

    rtb_NotEqual = (Controller_without_ref_P.ZeroGain_Gain_j *
                    Controller_without_ref_B.SumI1 !=
                    Controller_without_ref_B.SignPreIntegrator);

    // Signum: '<S51>/SignDeltaU'
    if (Controller_without_ref_B.SignPreIntegrator < 0.0) {
      Controller_without_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_without_ref_B.SignPreIntegrator > 0.0) {
      Controller_without_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_without_ref_B.SignPreIntegrator == 0.0) {
        Controller_without_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S51>/SignDeltaU'

    // Start for MATLABSystem: '<S50>/I_vel_x' incorporates:
    //   MATLABSystem: '<S50>/I_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_cv.SampleTime ==
          Controller_without_ref_P.I_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_cv.SampleTime =
        Controller_without_ref_P.I_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_548.get_parameter
      (&Controller_without_ref_B.Switch_e);

    // End of Start for MATLABSystem: '<S50>/I_vel_x'

    // Saturate: '<S49>/Saturate'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_d) {
      Controller_without_ref_B.Saturate_b =
        Controller_without_ref_P.PIDController_UpperSaturation_d;
    } else if (Controller_without_ref_B.SumI1 <
               Controller_without_ref_P.PIDController_LowerSaturation_i) {
      Controller_without_ref_B.Saturate_b =
        Controller_without_ref_P.PIDController_LowerSaturation_i;
    } else {
      Controller_without_ref_B.Saturate_b = Controller_without_ref_B.SumI1;
    }

    // End of Saturate: '<S49>/Saturate'

    // Sum: '<S49>/SumI1' incorporates:
    //   Gain: '<S49>/Kt'
    //   MATLABSystem: '<S50>/I_vel_x'
    //   Product: '<S49>/IOut'
    //   Sum: '<S49>/SumI3'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.X_h -
      Controller_without_ref_B.Saturate_b) *
      Controller_without_ref_P.PIDController_Kt_jw +
      Controller_without_ref_B.Errorz8 * Controller_without_ref_B.Switch_e;

    // Signum: '<S51>/SignPreIntegrator'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S51>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S51>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = 1.0;
    } else if (Controller_without_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S51>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = 0.0;
    } else {
      // DataTypeConversion: '<S51>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = Controller_without_ref_B.SumI1;
    }

    // End of Signum: '<S51>/SignPreIntegrator'

    // DataTypeConversion: '<S51>/DataTypeConv1'
    if (Controller_without_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_without_ref_B.SignPreIntegrator;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S51>/DataTypeConv1'

    // DataTypeConversion: '<S51>/DataTypeConv2'
    if (Controller_without_ref_B.Switch_i < 128.0) {
      tmp = (int8_T)Controller_without_ref_B.Switch_i;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S49>/Switch' incorporates:
    //   Constant: '<S49>/Constant'
    //   Logic: '<S51>/AND'
    //   RelationalOperator: '<S51>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_without_ref_B.Switch_e =
        Controller_without_ref_P.Constant_Value_m0;
    } else {
      Controller_without_ref_B.Switch_e = Controller_without_ref_B.SumI1;
    }

    // End of Switch: '<S49>/Switch'

    // Start for MATLABSystem: '<S53>/P_vel_y' incorporates:
    //   MATLABSystem: '<S53>/P_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_ji.SampleTime ==
          Controller_without_ref_P.P_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_ji.SampleTime =
        Controller_without_ref_P.P_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_564.get_parameter
      (&Controller_without_ref_B.SignPreIntegrator);

    // End of Start for MATLABSystem: '<S53>/P_vel_y'

    // Start for MATLABSystem: '<S53>/D_vel_y' incorporates:
    //   MATLABSystem: '<S53>/D_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_n.SampleTime ==
          Controller_without_ref_P.D_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_n.SampleTime =
        Controller_without_ref_P.D_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_561.get_parameter
      (&Controller_without_ref_B.NOut_i);

    // End of Start for MATLABSystem: '<S53>/D_vel_y'

    // Start for MATLABSystem: '<S53>/N_vel_y ' incorporates:
    //   MATLABSystem: '<S53>/N_vel_y '

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_c.SampleTime ==
          Controller_without_ref_P.N_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_c.SampleTime =
        Controller_without_ref_P.N_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_563.get_parameter
      (&Controller_without_ref_B.SumI1);

    // End of Start for MATLABSystem: '<S53>/N_vel_y '

    // Product: '<S52>/NOut' incorporates:
    //   DiscreteIntegrator: '<S52>/Filter'
    //   MATLABSystem: '<S53>/D_vel_y'
    //   MATLABSystem: '<S53>/N_vel_y '
    //   Product: '<S52>/DOut'
    //   Sum: '<S52>/SumD'

    Controller_without_ref_B.NOut_i = (Controller_without_ref_B.Errorz9 *
      Controller_without_ref_B.NOut_i -
      Controller_without_ref_DWork.Filter_DSTATE_g) *
      Controller_without_ref_B.SumI1;

    // Sum: '<S52>/Sum' incorporates:
    //   DiscreteIntegrator: '<S52>/Integrator'
    //   MATLABSystem: '<S53>/P_vel_y'
    //   Product: '<S52>/POut'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Errorz9 *
      Controller_without_ref_B.SignPreIntegrator +
      Controller_without_ref_DWork.Integrator_DSTATE_n) +
      Controller_without_ref_B.NOut_i;

    // DeadZone: '<S54>/DeadZone'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_b) {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_UpperSaturation_b;
    } else if (Controller_without_ref_B.SumI1 >=
               Controller_without_ref_P.PIDController_LowerSaturation_g) {
      Controller_without_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_LowerSaturation_g;
    }

    // End of DeadZone: '<S54>/DeadZone'

    // RelationalOperator: '<S54>/NotEqual' incorporates:
    //   Gain: '<S54>/ZeroGain'

    rtb_NotEqual = (Controller_without_ref_P.ZeroGain_Gain_jk *
                    Controller_without_ref_B.SumI1 !=
                    Controller_without_ref_B.SignPreIntegrator);

    // Signum: '<S54>/SignDeltaU'
    if (Controller_without_ref_B.SignPreIntegrator < 0.0) {
      Controller_without_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_without_ref_B.SignPreIntegrator > 0.0) {
      Controller_without_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_without_ref_B.SignPreIntegrator == 0.0) {
        Controller_without_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S54>/SignDeltaU'

    // Start for MATLABSystem: '<S53>/I_vel_y' incorporates:
    //   MATLABSystem: '<S53>/I_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_jx.SampleTime ==
          Controller_without_ref_P.I_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_jx.SampleTime =
        Controller_without_ref_P.I_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_562.get_parameter
      (&Controller_without_ref_B.Switch_i);

    // End of Start for MATLABSystem: '<S53>/I_vel_y'

    // Saturate: '<S52>/Saturate'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_b) {
      Controller_without_ref_B.Saturate_h =
        Controller_without_ref_P.PIDController_UpperSaturation_b;
    } else if (Controller_without_ref_B.SumI1 <
               Controller_without_ref_P.PIDController_LowerSaturation_g) {
      Controller_without_ref_B.Saturate_h =
        Controller_without_ref_P.PIDController_LowerSaturation_g;
    } else {
      Controller_without_ref_B.Saturate_h = Controller_without_ref_B.SumI1;
    }

    // End of Saturate: '<S52>/Saturate'

    // Sum: '<S52>/SumI1' incorporates:
    //   Gain: '<S52>/Kt'
    //   MATLABSystem: '<S53>/I_vel_y'
    //   Product: '<S52>/IOut'
    //   Sum: '<S52>/SumI3'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Y_i -
      Controller_without_ref_B.Saturate_h) *
      Controller_without_ref_P.PIDController_Kt_c +
      Controller_without_ref_B.Errorz9 * Controller_without_ref_B.Switch_i;

    // Signum: '<S54>/SignPreIntegrator'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S54>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S54>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = 1.0;
    } else if (Controller_without_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S54>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = 0.0;
    } else {
      // DataTypeConversion: '<S54>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = Controller_without_ref_B.SumI1;
    }

    // End of Signum: '<S54>/SignPreIntegrator'

    // DataTypeConversion: '<S54>/DataTypeConv1'
    if (Controller_without_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_without_ref_B.SignPreIntegrator;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S54>/DataTypeConv1'

    // DataTypeConversion: '<S54>/DataTypeConv2'
    if (Controller_without_ref_B.Switch_i < 128.0) {
      tmp = (int8_T)Controller_without_ref_B.Switch_i;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S52>/Switch' incorporates:
    //   Constant: '<S52>/Constant'
    //   Logic: '<S54>/AND'
    //   RelationalOperator: '<S54>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_without_ref_B.Switch_i =
        Controller_without_ref_P.Constant_Value_p;
    } else {
      Controller_without_ref_B.Switch_i = Controller_without_ref_B.SumI1;
    }

    // End of Switch: '<S52>/Switch'

    // Start for MATLABSystem: '<S56>/P_vel_z' incorporates:
    //   MATLABSystem: '<S56>/P_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj.SampleTime ==
          Controller_without_ref_P.P_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj.SampleTime =
        Controller_without_ref_P.P_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_578.get_parameter
      (&Controller_without_ref_B.SignPreIntegrator);

    // End of Start for MATLABSystem: '<S56>/P_vel_z'

    // Start for MATLABSystem: '<S56>/D_vel_z' incorporates:
    //   MATLABSystem: '<S56>/D_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_a.SampleTime ==
          Controller_without_ref_P.D_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_a.SampleTime =
        Controller_without_ref_P.D_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_575.get_parameter
      (&Controller_without_ref_B.SumI1);

    // End of Start for MATLABSystem: '<S56>/D_vel_z'

    // Start for MATLABSystem: '<S56>/N_vel_z ' incorporates:
    //   MATLABSystem: '<S56>/N_vel_z '

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_h.SampleTime ==
          Controller_without_ref_P.N_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_h.SampleTime =
        Controller_without_ref_P.N_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_577.get_parameter
      (&Controller_without_ref_B.NOut_d);

    // End of Start for MATLABSystem: '<S56>/N_vel_z '

    // Product: '<S55>/NOut' incorporates:
    //   DiscreteIntegrator: '<S55>/Filter'
    //   MATLABSystem: '<S56>/D_vel_z'
    //   MATLABSystem: '<S56>/N_vel_z '
    //   Product: '<S55>/DOut'
    //   Sum: '<S55>/SumD'

    Controller_without_ref_B.NOut_d *= Controller_without_ref_B.Errorz10 *
      Controller_without_ref_B.SumI1 -
      Controller_without_ref_DWork.Filter_DSTATE_cw;

    // Sum: '<S55>/Sum' incorporates:
    //   DiscreteIntegrator: '<S55>/Integrator'
    //   MATLABSystem: '<S56>/P_vel_z'
    //   Product: '<S55>/POut'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Errorz10 *
      Controller_without_ref_B.SignPreIntegrator +
      Controller_without_ref_DWork.Integrator_DSTATE_ny) +
      Controller_without_ref_B.NOut_d;

    // DeadZone: '<S57>/DeadZone'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturatio_ba) {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_UpperSaturatio_ba;
    } else if (Controller_without_ref_B.SumI1 >=
               Controller_without_ref_P.PIDController_LowerSaturatio_pm) {
      Controller_without_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_LowerSaturatio_pm;
    }

    // End of DeadZone: '<S57>/DeadZone'

    // RelationalOperator: '<S57>/NotEqual' incorporates:
    //   Gain: '<S57>/ZeroGain'

    rtb_NotEqual = (Controller_without_ref_P.ZeroGain_Gain_p *
                    Controller_without_ref_B.SumI1 !=
                    Controller_without_ref_B.SignPreIntegrator);

    // Signum: '<S57>/SignDeltaU'
    if (Controller_without_ref_B.SignPreIntegrator < 0.0) {
      Controller_without_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_without_ref_B.SignPreIntegrator > 0.0) {
      Controller_without_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_without_ref_B.SignPreIntegrator == 0.0) {
        Controller_without_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S57>/SignDeltaU'

    // Start for MATLABSystem: '<S56>/I_vel_z' incorporates:
    //   MATLABSystem: '<S56>/I_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_j.SampleTime ==
          Controller_without_ref_P.I_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_j.SampleTime =
        Controller_without_ref_P.I_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_576.get_parameter
      (&Controller_without_ref_B.rtb_I_vel_z_k);

    // End of Start for MATLABSystem: '<S56>/I_vel_z'

    // Saturate: '<S55>/Saturate'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturatio_ba) {
      Controller_without_ref_B.Saturate_bk =
        Controller_without_ref_P.PIDController_UpperSaturatio_ba;
    } else if (Controller_without_ref_B.SumI1 <
               Controller_without_ref_P.PIDController_LowerSaturatio_pm) {
      Controller_without_ref_B.Saturate_bk =
        Controller_without_ref_P.PIDController_LowerSaturatio_pm;
    } else {
      Controller_without_ref_B.Saturate_bk = Controller_without_ref_B.SumI1;
    }

    // End of Saturate: '<S55>/Saturate'

    // Sum: '<S55>/SumI1' incorporates:
    //   Gain: '<S55>/Kt'
    //   MATLABSystem: '<S56>/I_vel_z'
    //   Product: '<S55>/IOut'
    //   Sum: '<S55>/SumI3'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Z -
      Controller_without_ref_B.Saturate_bk) *
      Controller_without_ref_P.PIDController_Kt_l +
      Controller_without_ref_B.Errorz10 * Controller_without_ref_B.rtb_I_vel_z_k;

    // Update for DiscreteIntegrator: '<S40>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE +=
      Controller_without_ref_P.Integrator_gainval * Controller_without_ref_B.cfi;

    // Update for DiscreteIntegrator: '<S40>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE +=
      Controller_without_ref_P.Filter_gainval *
      Controller_without_ref_B.RandomSource;

    // Update for DiscreteIntegrator: '<S43>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_h +=
      Controller_without_ref_P.Integrator_gainval_c *
      Controller_without_ref_B.cpsi;

    // Update for DiscreteIntegrator: '<S43>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_c +=
      Controller_without_ref_P.Filter_gainval_i * Controller_without_ref_B.spsi;

    // Update for DiscreteIntegrator: '<S46>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_a +=
      Controller_without_ref_P.Integrator_gainval_n *
      Controller_without_ref_B.ctheta_c;

    // Update for DiscreteIntegrator: '<S46>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_f +=
      Controller_without_ref_P.Filter_gainval_k *
      Controller_without_ref_B.stheta;

    // Update for DiscreteIntegrator: '<S49>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_f +=
      Controller_without_ref_P.Integrator_gainval_j *
      Controller_without_ref_B.Switch_e;

    // Update for DiscreteIntegrator: '<S49>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_a +=
      Controller_without_ref_P.Filter_gainval_h *
      Controller_without_ref_B.NOut_b;

    // Update for DiscreteIntegrator: '<S52>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_n +=
      Controller_without_ref_P.Integrator_gainval_np *
      Controller_without_ref_B.Switch_i;

    // Update for DiscreteIntegrator: '<S52>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_g +=
      Controller_without_ref_P.Filter_gainval_h0 *
      Controller_without_ref_B.NOut_i;

    // Signum: '<S57>/SignPreIntegrator'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S57>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S57>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = 1.0;
    } else if (Controller_without_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S57>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = 0.0;
    } else {
      // DataTypeConversion: '<S57>/DataTypeConv2'
      Controller_without_ref_B.Switch_i = Controller_without_ref_B.SumI1;
    }

    // End of Signum: '<S57>/SignPreIntegrator'

    // DataTypeConversion: '<S57>/DataTypeConv1'
    if (Controller_without_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_without_ref_B.SignPreIntegrator;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S57>/DataTypeConv1'

    // DataTypeConversion: '<S57>/DataTypeConv2'
    if (Controller_without_ref_B.Switch_i < 128.0) {
      tmp = (int8_T)Controller_without_ref_B.Switch_i;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S55>/Switch' incorporates:
    //   Constant: '<S55>/Constant'
    //   Logic: '<S57>/AND'
    //   RelationalOperator: '<S57>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_without_ref_B.SumI1 = Controller_without_ref_P.Constant_Value_l;
    }

    // End of Switch: '<S55>/Switch'

    // Update for DiscreteIntegrator: '<S55>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_ny +=
      Controller_without_ref_P.Integrator_gainval_m *
      Controller_without_ref_B.SumI1;

    // Update for DiscreteIntegrator: '<S55>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_cw +=
      Controller_without_ref_P.Filter_gainval_b *
      Controller_without_ref_B.NOut_d;
  }

  // End of Outputs for SubSystem: '<Root>/Create errors'
  // End of Outputs for SubSystem: '<Root>/decController'

  // Start for MATLABSystem: '<S3>/Get front strafe decouple' incorporates:
  //   MATLABSystem: '<S3>/Get front strafe decouple'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_np.SampleTime ==
        Controller_without_ref_P.Getfrontstrafedecouple_SampleTi)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_np.SampleTime =
      Controller_without_ref_P.Getfrontstrafedecouple_SampleTi;
  }

  ParamGet_Controller_without_ref_787.get_parameter
    (&Controller_without_ref_B.RandomSource);

  // Start for MATLABSystem: '<S3>/Get front forward decouple' incorporates:
  //   MATLABSystem: '<S3>/Get front forward decouple'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_dti.SampleTime ==
        Controller_without_ref_P.Getfrontforwarddecouple_SampleT)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_dti.SampleTime =
      Controller_without_ref_P.Getfrontforwarddecouple_SampleT;
  }

  ParamGet_Controller_without_ref_785.get_parameter
    (&Controller_without_ref_B.cfi);

  // Start for MATLABSystem: '<S3>/Get front pitch bias' incorporates:
  //   MATLABSystem: '<S3>/Get front pitch bias'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_cp.SampleTime ==
        Controller_without_ref_P.Getfrontpitchbias_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_cp.SampleTime =
      Controller_without_ref_P.Getfrontpitchbias_SampleTime;
  }

  ParamGet_Controller_without_ref_786.get_parameter
    (&Controller_without_ref_B.spsi);

  // Start for MATLABSystem: '<S3>/Get front vertical bias' incorporates:
  //   MATLABSystem: '<S3>/Get front vertical bias'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_ci.SampleTime ==
        Controller_without_ref_P.Getfrontverticalbias_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_ci.SampleTime =
      Controller_without_ref_P.Getfrontverticalbias_SampleTime;
  }

  ParamGet_Controller_without_ref_788.get_parameter
    (&Controller_without_ref_B.cpsi);

  // Start for MATLABSystem: '<S3>/Get buoyancy' incorporates:
  //   MATLABSystem: '<S3>/Get buoyancy'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_ae.SampleTime ==
        Controller_without_ref_P.Getbuoyancy_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_ae.SampleTime =
      Controller_without_ref_P.Getbuoyancy_SampleTime;
  }

  ParamGet_Controller_without_ref_784.get_parameter
    (&Controller_without_ref_B.stheta);

  // MATLAB Function: '<S3>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S3>/Get buoyancy'
  //   Start for MATLABSystem: '<S3>/Get buoyancy'
  //   MATLABSystem: '<S3>/Get front forward decouple'
  //   Start for MATLABSystem: '<S3>/Get front forward decouple'
  //   MATLABSystem: '<S3>/Get front pitch bias'
  //   Start for MATLABSystem: '<S3>/Get front pitch bias'
  //   MATLABSystem: '<S3>/Get front strafe decouple'
  //   Start for MATLABSystem: '<S3>/Get front strafe decouple'
  //   MATLABSystem: '<S3>/Get front vertical bias'
  //   Start for MATLABSystem: '<S3>/Get front vertical bias'

  Controller_witho_MATLABFunction(Controller_without_ref_B.Saturate,
    Controller_without_ref_B.Saturate_f, Controller_without_ref_B.Saturate_i,
    Controller_without_ref_B.Saturate_b, Controller_without_ref_B.Saturate_h,
    Controller_without_ref_B.Saturate_bk, Controller_without_ref_B.RandomSource,
    Controller_without_ref_B.cfi, Controller_without_ref_B.spsi,
    Controller_without_ref_B.cpsi, Controller_without_ref_B.stheta,
    &Controller_without_ref_B.sf_MATLABFunction_i);

  // MultiPortSwitch: '<Root>/Choose Controller or test' incorporates:
  //   MATLABSystem: '<Root>/Get test'

  if (i == 0) {
    for (i = 0; i < 6; i++) {
      Controller_without_ref_B.ChooseControllersignal[i] =
        Controller_without_ref_B.OutportBufferForThrusters[i];
    }
  } else {
    // MultiPortSwitch: '<Root>/Choose Controller signal' incorporates:
    //   Constant: '<Root>/Constant4'
    //   MATLABSystem: '<Root>/Get controller type'

    switch (rtb_Swtichingfactor_d_0) {
     case 0:
      Controller_without_ref_B.ChooseControllersignal[0] =
        Controller_without_ref_B.sf_MATLABFunction.thruster1;
      Controller_without_ref_B.ChooseControllersignal[1] =
        Controller_without_ref_B.sf_MATLABFunction.thruster2;
      Controller_without_ref_B.ChooseControllersignal[2] =
        Controller_without_ref_B.sf_MATLABFunction.thruster3;
      Controller_without_ref_B.ChooseControllersignal[3] =
        Controller_without_ref_B.sf_MATLABFunction.thruster4;
      Controller_without_ref_B.ChooseControllersignal[4] =
        Controller_without_ref_B.sf_MATLABFunction.thruster5;
      Controller_without_ref_B.ChooseControllersignal[5] =
        Controller_without_ref_B.sf_MATLABFunction.thruster6;
      break;

     case 1:
      Controller_without_ref_B.ChooseControllersignal[0] =
        Controller_without_ref_B.sf_MATLABFunction_i.thruster1;
      Controller_without_ref_B.ChooseControllersignal[1] =
        Controller_without_ref_B.sf_MATLABFunction_i.thruster2;
      Controller_without_ref_B.ChooseControllersignal[2] =
        Controller_without_ref_B.sf_MATLABFunction_i.thruster3;
      Controller_without_ref_B.ChooseControllersignal[3] =
        Controller_without_ref_B.sf_MATLABFunction_i.thruster4;
      Controller_without_ref_B.ChooseControllersignal[4] =
        Controller_without_ref_B.sf_MATLABFunction_i.thruster5;
      Controller_without_ref_B.ChooseControllersignal[5] =
        Controller_without_ref_B.sf_MATLABFunction_i.thruster6;
      break;

     default:
      for (i = 0; i < 6; i++) {
        Controller_without_ref_B.ChooseControllersignal[i] =
          Controller_without_ref_P.Constant4_Value[i];
      }
      break;
    }

    // End of MultiPortSwitch: '<Root>/Choose Controller signal'
  }

  // End of MultiPortSwitch: '<Root>/Choose Controller or test'

  // Outputs for Enabled SubSystem: '<Root>/toPWM' incorporates:
  //   EnablePort: '<S12>/Enable'

  // Logic: '<Root>/Logical Operator1'
  if (rtb_Compare || rtb_LogicalOperator) {
    // MATLAB Function: '<S12>/PWM assign' incorporates:
    //   Constant: '<S60>/Constant'
    //   DataTypeConversion: '<S12>/Data Type Conversion'

    // MATLAB Function 'toPWM/Calc pwm signal': '<S61>:1'
    //  thruster values should be between 1100 and 1900 microseconds (us)
    //  values less than 1500 us are backwards; values more than are forwards
    // '<S61>:1:5'
    Controller_without_ref_B.msg = Controller_without_ref_P.Constant_Value_i;

    // MATLAB Function 'toPWM/PWM assign': '<S62>:1'
    // '<S62>:1:4'
    for (i = 0; i < 6; i++) {
      // Saturate: '<S12>/Saturation'
      if (Controller_without_ref_B.ChooseControllersignal[i] >
          Controller_without_ref_P.Saturation_UpperSat) {
        Controller_without_ref_B.RandomSource =
          Controller_without_ref_P.Saturation_UpperSat;
      } else if (Controller_without_ref_B.ChooseControllersignal[i] <
                 Controller_without_ref_P.Saturation_LowerSat) {
        Controller_without_ref_B.RandomSource =
          Controller_without_ref_P.Saturation_LowerSat;
      } else {
        Controller_without_ref_B.RandomSource =
          Controller_without_ref_B.ChooseControllersignal[i];
      }

      // DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
      //   MATLAB Function: '<S12>/Calc pwm signal'
      //   Saturate: '<S12>/Saturation'

      Controller_without_ref_B.Switch_i = floor
        ((Controller_without_ref_B.RandomSource + 1.0) * 400.0 + 1100.0);
      if (rtIsNaN(Controller_without_ref_B.Switch_i) || rtIsInf
          (Controller_without_ref_B.Switch_i)) {
        Controller_without_ref_B.Switch_i = 0.0;
      } else {
        Controller_without_ref_B.Switch_i = fmod
          (Controller_without_ref_B.Switch_i, 65536.0);
      }

      Controller_without_ref_B.msg.Data[i] = (uint16_T)
        (Controller_without_ref_B.Switch_i < 0.0 ? (int32_T)(uint16_T)-(int16_T)
         (uint16_T)-Controller_without_ref_B.Switch_i : (int32_T)(uint16_T)
         Controller_without_ref_B.Switch_i);
    }

    // '<S62>:1:5'
    Controller_without_ref_B.msg.Layout.DataOffset = 0U;

    // '<S62>:1:6'
    Controller_without_ref_B.msg.Layout.Dim[0].Stride = 1U;

    // '<S62>:1:7'
    Controller_without_ref_B.msg.Layout.Dim[0].Size = 6U;

    // '<S62>:1:8'
    Controller_without_ref_B.msg.Data_SL_Info.CurrentLength = 6U;

    // End of MATLAB Function: '<S12>/PWM assign'

    // Outputs for Atomic SubSystem: '<S12>/Publish'
    // MATLABSystem: '<S63>/SinkBlock'
    // '<S62>:1:9'
    Pub_Controller_without_ref_607.publish(&Controller_without_ref_B.msg);

    // End of Outputs for SubSystem: '<S12>/Publish'
  }

  // End of Logic: '<Root>/Logical Operator1'
  // End of Outputs for SubSystem: '<Root>/toPWM'

  // Start for MATLABSystem: '<S7>/Get alpha' incorporates:
  //   MATLABSystem: '<S7>/Get alpha'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_hx.SampleTime ==
        Controller_without_ref_P.Getalpha_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_hx.SampleTime =
      Controller_without_ref_P.Getalpha_SampleTime;
  }

  ParamGet_Controller_without_ref_687.get_parameter
    (&Controller_without_ref_B.RandomSource);

  // End of Start for MATLABSystem: '<S7>/Get alpha'

  // SignalConversion: '<S7>/TmpSignal ConversionAtDiscrete FilterInport2' incorporates:
  //   Constant: '<S7>/Constant'
  //   MATLABSystem: '<S7>/Get alpha'

  Controller_without_ref_B.TmpSignalConversionAtDiscreteFi[0] =
    Controller_without_ref_P.Constant_Value_ay;
  Controller_without_ref_B.TmpSignalConversionAtDiscreteFi[1] =
    Controller_without_ref_B.RandomSource;

  // DiscreteFilter: '<S7>/Discrete Filter'
  Controller_without_ref_B.RandomSource =
    Controller_without_ref_P.DiscreteFilter_NumCoef *
    Controller_without_ref_B.OutportBufferForaccXms2 -
    Controller_without_ref_B.TmpSignalConversionAtDiscreteFi[1] *
    Controller_without_ref_DWork.DiscreteFilter_denStates;
  Controller_without_ref_DWork.DiscreteFilter_tmp =
    Controller_without_ref_B.RandomSource;

  // DiscreteFilter: '<S7>/Discrete Filter1'
  Controller_without_ref_B.cfi =
    Controller_without_ref_P.DiscreteFilter1_NumCoef *
    Controller_without_ref_B.OutportBufferForaccYms2 -
    Controller_without_ref_B.TmpSignalConversionAtDiscreteFi[1] *
    Controller_without_ref_DWork.DiscreteFilter1_denStates;
  Controller_without_ref_DWork.DiscreteFilter1_tmp =
    Controller_without_ref_B.cfi;

  // DiscreteFilter: '<S7>/Discrete Filter2'
  Controller_without_ref_B.spsi =
    Controller_without_ref_P.DiscreteFilter2_NumCoef *
    Controller_without_ref_B.OutportBufferForaccZms2 -
    Controller_without_ref_B.TmpSignalConversionAtDiscreteFi[1] *
    Controller_without_ref_DWork.DiscreteFilter2_denStates;
  Controller_without_ref_DWork.DiscreteFilter2_tmp =
    Controller_without_ref_B.spsi;

  // Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
  Controller_without_ref_DWork.DiscreteTimeIntegrator_DSTATE +=
    Controller_without_ref_P.DiscreteTimeIntegrator_gainval *
    Controller_without_ref_B.RandomSource;

  // Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'
  Controller_without_ref_DWork.DiscreteTimeIntegrator1_DSTATE +=
    Controller_without_ref_P.DiscreteTimeIntegrator1_gainval *
    Controller_without_ref_B.cfi;

  // Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator2'
  Controller_without_ref_DWork.DiscreteTimeIntegrator2_DSTATE +=
    Controller_without_ref_P.DiscreteTimeIntegrator2_gainval *
    Controller_without_ref_B.spsi;

  // Update for DiscreteFilter: '<S7>/Discrete Filter'
  Controller_without_ref_DWork.DiscreteFilter_denStates =
    Controller_without_ref_DWork.DiscreteFilter_tmp;

  // Update for DiscreteFilter: '<S7>/Discrete Filter1'
  Controller_without_ref_DWork.DiscreteFilter1_denStates =
    Controller_without_ref_DWork.DiscreteFilter1_tmp;

  // Update for DiscreteFilter: '<S7>/Discrete Filter2'
  Controller_without_ref_DWork.DiscreteFilter2_denStates =
    Controller_without_ref_DWork.DiscreteFilter2_tmp;
}

// Model initialize function
void ControllerModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus((&Controller_without_ref_M), (NULL));

  // block I/O
  (void) memset(((void *) &Controller_without_ref_B), 0,
                sizeof(BlockIO_Controller_without_re_T));

  // states (dwork)
  (void) memset((void *)&Controller_without_ref_DWork, 0,
                sizeof(D_Work_Controller_without_ref_T));

  {
    int32_T i;
    static const char_T tmp[24] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_', 'c',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'a', 'l', 'p', 'h', 'a'
    };

    static const char_T tmp_0[16] = { '/', 'r', 'o', 'v', 'i', 'o', '/', 't',
      'h', 'r', 'u', 's', 't', 'e', 'r', 's' };

    static const char_T tmp_1[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'b', 'u', 'o', 'y',
      'a', 'n', 'c', 'y', '_', 'c', 'o', 'n', 't', 'r', 'o', 'l' };

    static const char_T tmp_2[38] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'f', 'r', 'o', 'n',
      't', '_', 'v', 'e', 'r', 't', 'i', 'c', 'a', 'l', '_', 'b', 'i', 'a', 's'
    };

    static const char_T tmp_3[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'f', 'r', 'o', 'n',
      't', '_', 'p', 'i', 't', 'c', 'h', '_', 'b', 'i', 'a', 's' };

    static const char_T tmp_4[41] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'f', 'r', 'o', 'n',
      't', '_', 'f', 'o', 'r', 'w', 'a', 'r', 'd', '_', 'd', 'e', 'c', 'o', 'u',
      'p', 'l', 'e' };

    static const char_T tmp_5[40] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'f', 'r', 'o', 'n',
      't', '_', 's', 't', 'r', 'a', 'f', 'e', '_', 'd', 'e', 'c', 'o', 'u', 'p',
      'l', 'e' };

    static const char_T tmp_6[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_7[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_8[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_9[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_a[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_b[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_c[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_d[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_e[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_f[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_g[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_h[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_i[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_j[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_k[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_l[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_m[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_n[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_o[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_p[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_q[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_r[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_s[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_t[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_u[37] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 'i', 'n', 't', 'e', 'g', 'r', 'a', 't', 'i', 'o', 'n' };

    static const char_T tmp_v[21] = { '/', 's', 'e', 'n', 's', 'o', 'r', '_',
      'f', 'u', 's', 'i', 'o', 'n', '/', 's', 't', 'a', 't', 'e', 's' };

    static const char_T tmp_w[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_x[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'c', 'o', 'n', 't',
      'r', 'o', 'l', 'l', 'e', 'r' };

    static const char_T tmp_y[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '6' };

    static const char_T tmp_z[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '6' };

    static const char_T tmp_10[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '6' };

    static const char_T tmp_11[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '5' };

    static const char_T tmp_12[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '5' };

    static const char_T tmp_13[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '5' };

    static const char_T tmp_14[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '4' };

    static const char_T tmp_15[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '4' };

    static const char_T tmp_16[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '4' };

    static const char_T tmp_17[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '3' };

    static const char_T tmp_18[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '3' };

    static const char_T tmp_19[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '3' };

    static const char_T tmp_1a[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '2' };

    static const char_T tmp_1b[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '2' };

    static const char_T tmp_1c[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '2' };

    static const char_T tmp_1d[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '1' };

    static const char_T tmp_1e[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '1' };

    static const char_T tmp_1f[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '1' };

    static const char_T tmp_1g[30] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 't', 'e', 's', 't',
      '_', 'e', 'n', 'a', 'b', 'l', 'e' };

    // Start for MATLABSystem: '<Root>/Get test'
    Controller_without_ref_DWork.obj_h2.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_pr = true;
    Controller_without_ref_DWork.obj_h2.SampleTime =
      Controller_without_ref_P.Gettest_SampleTime;
    Controller_without_ref_DWork.obj_h2.isInitialized = 1;
    for (i = 0; i < 30; i++) {
      Controller_without_ref_B.cv7[i] = tmp_1g[i];
    }

    Controller_without_ref_B.cv7[30] = '\x00';
    ParamGet_Controller_without_ref_823.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<Root>/Get test'

    // Start for Enabled SubSystem: '<Root>/Telegraph'
    // Start for S-Function (sdsprandsrc2): '<S15>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_without_ref_DWork.RandomSource_SEED_DWORK, 1);
    RandSrcInitState_U_64(&Controller_without_ref_DWork.RandomSource_SEED_DWORK,
                          Controller_without_ref_DWork.RandomSource_STATE_DWORK,
                          1);

    // Start for MATLABSystem: '<S15>/Swtiching factor'
    Controller_without_ref_DWork.obj_of.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ls = true;
    Controller_without_ref_DWork.obj_of.SampleTime =
      Controller_without_ref_P.Swtichingfactor_SampleTime;
    Controller_without_ref_DWork.obj_of.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_without_ref_B.cv6[i] = tmp_1f[i];
    }

    Controller_without_ref_B.cv6[33] = '\x00';
    ParamGet_Controller_without_ref_714.initialize(Controller_without_ref_B.cv6,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S15>/Swtiching factor'

    // Start for MATLABSystem: '<S15>/Swtiching factor1'
    Controller_without_ref_DWork.obj_fx.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_jb = true;
    Controller_without_ref_DWork.obj_fx.SampleTime =
      Controller_without_ref_P.Swtichingfactor1_SampleTime;
    Controller_without_ref_DWork.obj_fx.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_1e[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_715.initialize(Controller_without_ref_B.cv8,
      Contr_ParameterInitialValue_oea, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S15>/Swtiching factor1'

    // Start for MATLABSystem: '<S15>/Swtiching factor2'
    Controller_without_ref_DWork.obj_d3.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_jr = true;
    Controller_without_ref_DWork.obj_d3.SampleTime =
      Controller_without_ref_P.Swtichingfactor2_SampleTime;
    Controller_without_ref_DWork.obj_d3.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_1d[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_716.initialize(Controller_without_ref_B.cv8,
      Contr_ParameterInitialValue_oea, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S15>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S16>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_without_ref_DWork.RandomSource_SEED_DWORK_l, 1);
    RandSrcInitState_U_64
      (&Controller_without_ref_DWork.RandomSource_SEED_DWORK_l,
       Controller_without_ref_DWork.RandomSource_STATE_DWORK_i, 1);

    // Start for MATLABSystem: '<S16>/Swtiching factor'
    Controller_without_ref_DWork.obj_i.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_mo = true;
    Controller_without_ref_DWork.obj_i.SampleTime =
      Controller_without_ref_P.Swtichingfactor_SampleTime_k;
    Controller_without_ref_DWork.obj_i.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_without_ref_B.cv6[i] = tmp_1c[i];
    }

    Controller_without_ref_B.cv6[33] = '\x00';
    ParamGet_Controller_without_ref_724.initialize(Controller_without_ref_B.cv6,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S16>/Swtiching factor'

    // Start for MATLABSystem: '<S16>/Swtiching factor1'
    Controller_without_ref_DWork.obj_j5.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ng = true;
    Controller_without_ref_DWork.obj_j5.SampleTime =
      Controller_without_ref_P.Swtichingfactor1_SampleTime_i;
    Controller_without_ref_DWork.obj_j5.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_1b[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_725.initialize(Controller_without_ref_B.cv8,
      Contr_ParameterInitialValue_oea, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S16>/Swtiching factor1'

    // Start for MATLABSystem: '<S16>/Swtiching factor2'
    Controller_without_ref_DWork.obj_fu.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_fp = true;
    Controller_without_ref_DWork.obj_fu.SampleTime =
      Controller_without_ref_P.Swtichingfactor2_SampleTime_b;
    Controller_without_ref_DWork.obj_fu.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_1a[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_726.initialize(Controller_without_ref_B.cv8,
      Contr_ParameterInitialValue_oea, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S16>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S17>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_without_ref_DWork.RandomSource_SEED_DWORK_c, 1);
    RandSrcInitState_U_64
      (&Controller_without_ref_DWork.RandomSource_SEED_DWORK_c,
       Controller_without_ref_DWork.RandomSource_STATE_DWORK_a, 1);

    // Start for MATLABSystem: '<S17>/Swtiching factor'
    Controller_without_ref_DWork.obj_o.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ev = true;
    Controller_without_ref_DWork.obj_o.SampleTime =
      Controller_without_ref_P.Swtichingfactor_SampleTime_g;
    Controller_without_ref_DWork.obj_o.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_without_ref_B.cv6[i] = tmp_19[i];
    }

    Controller_without_ref_B.cv6[33] = '\x00';
    ParamGet_Controller_without_ref_734.initialize(Controller_without_ref_B.cv6,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S17>/Swtiching factor'

    // Start for MATLABSystem: '<S17>/Swtiching factor1'
    Controller_without_ref_DWork.obj_f.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_em = true;
    Controller_without_ref_DWork.obj_f.SampleTime =
      Controller_without_ref_P.Swtichingfactor1_SampleTime_o;
    Controller_without_ref_DWork.obj_f.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_18[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_735.initialize(Controller_without_ref_B.cv8,
      Contr_ParameterInitialValue_oea, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S17>/Swtiching factor1'

    // Start for MATLABSystem: '<S17>/Swtiching factor2'
    Controller_without_ref_DWork.obj_mb.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ks = true;
    Controller_without_ref_DWork.obj_mb.SampleTime =
      Controller_without_ref_P.Swtichingfactor2_SampleTime_o;
    Controller_without_ref_DWork.obj_mb.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_17[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_736.initialize(Controller_without_ref_B.cv8,
      Contr_ParameterInitialValue_oea, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S17>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S18>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_without_ref_DWork.RandomSource_SEED_DWORK_i, 1);
    RandSrcInitState_U_64
      (&Controller_without_ref_DWork.RandomSource_SEED_DWORK_i,
       Controller_without_ref_DWork.RandomSource_STATE_DWORK_g, 1);

    // Start for MATLABSystem: '<S18>/Swtiching factor'
    Controller_without_ref_DWork.obj_gv.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_a3 = true;
    Controller_without_ref_DWork.obj_gv.SampleTime =
      Controller_without_ref_P.Swtichingfactor_SampleTime_n;
    Controller_without_ref_DWork.obj_gv.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_without_ref_B.cv6[i] = tmp_16[i];
    }

    Controller_without_ref_B.cv6[33] = '\x00';
    ParamGet_Controller_without_ref_744.initialize(Controller_without_ref_B.cv6,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S18>/Swtiching factor'

    // Start for MATLABSystem: '<S18>/Swtiching factor1'
    Controller_without_ref_DWork.obj_c2.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_hv = true;
    Controller_without_ref_DWork.obj_c2.SampleTime =
      Controller_without_ref_P.Swtichingfactor1_SampleTime_j;
    Controller_without_ref_DWork.obj_c2.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_15[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_745.initialize(Controller_without_ref_B.cv8,
      Contr_ParameterInitialValue_oea, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S18>/Swtiching factor1'

    // Start for MATLABSystem: '<S18>/Swtiching factor2'
    Controller_without_ref_DWork.obj_g0e.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_o = true;
    Controller_without_ref_DWork.obj_g0e.SampleTime =
      Controller_without_ref_P.Swtichingfactor2_SampleTime_e;
    Controller_without_ref_DWork.obj_g0e.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_14[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_746.initialize(Controller_without_ref_B.cv8,
      Contr_ParameterInitialValue_oea, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S18>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S19>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_without_ref_DWork.RandomSource_SEED_DWORK_k, 1);
    RandSrcInitState_U_64
      (&Controller_without_ref_DWork.RandomSource_SEED_DWORK_k,
       Controller_without_ref_DWork.RandomSource_STATE_DWORK_j, 1);

    // Start for MATLABSystem: '<S19>/Swtiching factor'
    Controller_without_ref_DWork.obj_j0.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_fj = true;
    Controller_without_ref_DWork.obj_j0.SampleTime =
      Controller_without_ref_P.Swtichingfactor_SampleTime_nq;
    Controller_without_ref_DWork.obj_j0.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_without_ref_B.cv6[i] = tmp_13[i];
    }

    Controller_without_ref_B.cv6[33] = '\x00';
    ParamGet_Controller_without_ref_850.initialize(Controller_without_ref_B.cv6,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S19>/Swtiching factor'

    // Start for MATLABSystem: '<S19>/Swtiching factor1'
    Controller_without_ref_DWork.obj_hr.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_nl = true;
    Controller_without_ref_DWork.obj_hr.SampleTime =
      Controller_without_ref_P.Swtichingfactor1_SampleTime_a;
    Controller_without_ref_DWork.obj_hr.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_12[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_851.initialize(Controller_without_ref_B.cv8,
      Contr_ParameterInitialValue_oea, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S19>/Swtiching factor1'

    // Start for MATLABSystem: '<S19>/Swtiching factor2'
    Controller_without_ref_DWork.obj_dn.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_kk = true;
    Controller_without_ref_DWork.obj_dn.SampleTime =
      Controller_without_ref_P.Swtichingfactor2_SampleTime_n;
    Controller_without_ref_DWork.obj_dn.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_11[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_852.initialize(Controller_without_ref_B.cv8,
      Contr_ParameterInitialValue_oea, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S19>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S20>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_without_ref_DWork.RandomSource_SEED_DWORK_g, 1);
    RandSrcInitState_U_64
      (&Controller_without_ref_DWork.RandomSource_SEED_DWORK_g,
       Controller_without_ref_DWork.RandomSource_STATE_DWORK_h, 1);

    // Start for MATLABSystem: '<S20>/Swtiching factor'
    Controller_without_ref_DWork.obj_gf.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_k1 = true;
    Controller_without_ref_DWork.obj_gf.SampleTime =
      Controller_without_ref_P.Swtichingfactor_SampleTime_f;
    Controller_without_ref_DWork.obj_gf.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_without_ref_B.cv6[i] = tmp_10[i];
    }

    Controller_without_ref_B.cv6[33] = '\x00';
    ParamGet_Controller_without_ref_764.initialize(Controller_without_ref_B.cv6,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S20>/Swtiching factor'

    // Start for MATLABSystem: '<S20>/Swtiching factor1'
    Controller_without_ref_DWork.obj_cvy.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_gk = true;
    Controller_without_ref_DWork.obj_cvy.SampleTime =
      Controller_without_ref_P.Swtichingfactor1_SampleTime_e;
    Controller_without_ref_DWork.obj_cvy.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_z[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_765.initialize(Controller_without_ref_B.cv8,
      Contr_ParameterInitialValue_oea, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S20>/Swtiching factor1'

    // Start for MATLABSystem: '<S20>/Swtiching factor2'
    Controller_without_ref_DWork.obj_dt.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_kl = true;
    Controller_without_ref_DWork.obj_dt.SampleTime =
      Controller_without_ref_P.Swtichingfactor2_SampleTime_c;
    Controller_without_ref_DWork.obj_dt.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_y[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_766.initialize(Controller_without_ref_B.cv8,
      Contr_ParameterInitialValue_oea, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S20>/Swtiching factor2'
    // End of Start for SubSystem: '<Root>/Telegraph'

    // InitializeConditions for Enabled SubSystem: '<Root>/Telegraph'

    // InitializeConditions for State Transition Table: '<S15>/State Transition Table' 
    Contr_StateTransitionTable_Init
      (&Controller_without_ref_DWork.sf_StateTransitionTable);

    // InitializeConditions for State Transition Table: '<S16>/State Transition Table' 
    Contr_StateTransitionTable_Init
      (&Controller_without_ref_DWork.sf_StateTransitionTable_i);

    // InitializeConditions for State Transition Table: '<S17>/State Transition Table' 
    Contr_StateTransitionTable_Init
      (&Controller_without_ref_DWork.sf_StateTransitionTable_m);

    // InitializeConditions for State Transition Table: '<S18>/State Transition Table' 
    Contr_StateTransitionTable_Init
      (&Controller_without_ref_DWork.sf_StateTransitionTable_mx);

    // InitializeConditions for State Transition Table: '<S19>/State Transition Table' 
    Contr_StateTransitionTable_Init
      (&Controller_without_ref_DWork.sf_StateTransitionTable_o);

    // InitializeConditions for State Transition Table: '<S20>/State Transition Table' 
    Contr_StateTransitionTable_Init
      (&Controller_without_ref_DWork.sf_StateTransitionTable_o2);

    // End of InitializeConditions for SubSystem: '<Root>/Telegraph'

    // Start for Enabled SubSystem: '<Root>/Telegraph'
    // VirtualOutportStart for Outport: '<S5>/Thrusters'
    for (i = 0; i < 6; i++) {
      Controller_without_ref_B.OutportBufferForThrusters[i] =
        Controller_without_ref_P.Thrusters_Y0;
    }

    // End of VirtualOutportStart for Outport: '<S5>/Thrusters'
    // End of Start for SubSystem: '<Root>/Telegraph'

    // Start for MATLABSystem: '<Root>/Get controller type'
    Controller_without_ref_DWork.obj_nl.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_m0 = true;
    Controller_without_ref_DWork.obj_nl.SampleTime =
      Controller_without_ref_P.Getcontrollertype_SampleTime;
    Controller_without_ref_DWork.obj_nl.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv8[i] = tmp_x[i];
    }

    Controller_without_ref_B.cv8[29] = '\x00';
    ParamGet_Controller_without_ref_106.initialize(Controller_without_ref_B.cv8,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<Root>/Get controller type'

    // Start for Atomic SubSystem: '<Root>/cmd_vel'
    // Start for MATLABSystem: '<S8>/SourceBlock'
    Controller_without_ref_DWork.obj_nf.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_gn = true;
    Controller_without_ref_DWork.obj_nf.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      Controller_without_ref_B.cv13[i] = tmp_w[i];
    }

    Controller_without_ref_B.cv13[8] = '\x00';
    Sub_Controller_without_ref_1.create_subscriber(Controller_without_ref_B.cv13,
      Controller_with_MessageQueueLen);

    // End of Start for MATLABSystem: '<S8>/SourceBlock'

    // Start for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S33>/Out1'
    Controller_without_ref_B.In1_m = Controller_without_ref_P.Out1_Y0_f;

    // End of Start for SubSystem: '<S8>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/cmd_vel'

    // Start for Atomic SubSystem: '<Root>/imu_data'
    // Start for MATLABSystem: '<S10>/SourceBlock'
    Controller_without_ref_DWork.obj_k.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_i = true;
    Controller_without_ref_DWork.obj_k.isInitialized = 1;
    for (i = 0; i < 21; i++) {
      Controller_without_ref_B.cv11[i] = tmp_v[i];
    }

    Controller_without_ref_B.cv11[21] = '\x00';
    Sub_Controller_without_ref_28.create_subscriber
      (Controller_without_ref_B.cv11, Controller_with_MessageQueueLen);

    // End of Start for MATLABSystem: '<S10>/SourceBlock'

    // Start for Enabled SubSystem: '<S10>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S58>/Out1'
    Controller_without_ref_B.In1 = Controller_without_ref_P.Out1_Y0;

    // End of Start for SubSystem: '<S10>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/imu_data'

    // Start for Enabled SubSystem: '<Root>/Xbox_input'
    // VirtualOutportStart for Outport: '<S6>/<angular_vel X>'
    Controller_without_ref_B.X_hw = Controller_without_ref_P.angular_velX_Y0;

    // VirtualOutportStart for Outport: '<S6>/<angular_vel Y>'
    Controller_without_ref_B.Y_in = Controller_without_ref_P.angular_velY_Y0;

    // VirtualOutportStart for Outport: '<S6>/<angular_vel Z> '
    Controller_without_ref_B.Z_n = Controller_without_ref_P.angular_velZ_Y0;

    // VirtualOutportStart for Outport: '<S6>/<velocity X>'
    Controller_without_ref_B.X_h = Controller_without_ref_P.velocityX_Y0;

    // VirtualOutportStart for Outport: '<S6>/<veloctiy Y>'
    Controller_without_ref_B.Y_i = Controller_without_ref_P.veloctiyY_Y0;

    // VirtualOutportStart for Outport: '<S6>/<velocity Z>'
    Controller_without_ref_B.Z = Controller_without_ref_P.velocityZ_Y0;

    // End of Start for SubSystem: '<Root>/Xbox_input'

    // Start for MATLABSystem: '<S4>/Get front strafe decouple'
    Controller_without_ref_DWork.obj_mp.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_gp = true;
    Controller_without_ref_DWork.obj_mp.SampleTime =
      Controller_without_ref_P.Getfrontstrafedecouple_Sample_b;
    Controller_without_ref_DWork.obj_mp.isInitialized = 1;
    for (i = 0; i < 40; i++) {
      Controller_without_ref_B.cv1[i] = tmp_5[i];
    }

    Controller_without_ref_B.cv1[40] = '\x00';
    ParamGet_Controller_without_ref_810.initialize(Controller_without_ref_B.cv1,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S4>/Get front strafe decouple'

    // Start for MATLABSystem: '<S4>/Get front forward decouple'
    Controller_without_ref_DWork.obj_ij.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_do = true;
    Controller_without_ref_DWork.obj_ij.SampleTime =
      Controller_without_ref_P.Getfrontforwarddecouple_Sampl_h;
    Controller_without_ref_DWork.obj_ij.isInitialized = 1;
    for (i = 0; i < 41; i++) {
      Controller_without_ref_B.cv0[i] = tmp_4[i];
    }

    Controller_without_ref_B.cv0[41] = '\x00';
    ParamGet_Controller_without_ref_808.initialize(Controller_without_ref_B.cv0,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S4>/Get front forward decouple'

    // Start for MATLABSystem: '<S4>/Get front pitch bias'
    Controller_without_ref_DWork.obj_nr.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_gx = true;
    Controller_without_ref_DWork.obj_nr.SampleTime =
      Controller_without_ref_P.Getfrontpitchbias_SampleTime_n;
    Controller_without_ref_DWork.obj_nr.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_without_ref_B.cv4[i] = tmp_3[i];
    }

    Controller_without_ref_B.cv4[35] = '\x00';
    ParamGet_Controller_without_ref_809.initialize(Controller_without_ref_B.cv4,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S4>/Get front pitch bias'

    // Start for MATLABSystem: '<S4>/Get front vertical bias'
    Controller_without_ref_DWork.obj_o5.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_o0 = true;
    Controller_without_ref_DWork.obj_o5.SampleTime =
      Controller_without_ref_P.Getfrontverticalbias_SampleTi_e;
    Controller_without_ref_DWork.obj_o5.isInitialized = 1;
    for (i = 0; i < 38; i++) {
      Controller_without_ref_B.cv2[i] = tmp_2[i];
    }

    Controller_without_ref_B.cv2[38] = '\x00';
    ParamGet_Controller_without_ref_811.initialize(Controller_without_ref_B.cv2,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S4>/Get front vertical bias'

    // Start for MATLABSystem: '<S4>/Get buoyancy'
    Controller_without_ref_DWork.obj_ot.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_bn = true;
    Controller_without_ref_DWork.obj_ot.SampleTime =
      Controller_without_ref_P.Getbuoyancy_SampleTime_e;
    Controller_without_ref_DWork.obj_ot.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_without_ref_B.cv4[i] = tmp_1[i];
    }

    Controller_without_ref_B.cv4[35] = '\x00';
    ParamGet_Controller_without_ref_807.initialize(Controller_without_ref_B.cv4,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S4>/Get buoyancy'

    // Start for Enabled SubSystem: '<Root>/states'
    // VirtualOutportStart for Outport: '<S11>/<angular_vel X [degrees//s]>'
    Controller_without_ref_B.X =
      Controller_without_ref_P.angular_velXdegreess_Y0;

    // VirtualOutportStart for Outport: '<S11>/<angular_vel Y [degrees//s]>'
    Controller_without_ref_B.Y =
      Controller_without_ref_P.angular_velYdegreess_Y0;

    // VirtualOutportStart for Outport: '<S11>/<angular_vel Z [degrees//s]>'
    Controller_without_ref_B.OutportBufferForangular_velZdeg =
      Controller_without_ref_P.angular_velZdegreess_Y0;

    // VirtualOutportStart for Outport: '<S11>/<acc X [m//s^2]>'
    Controller_without_ref_B.OutportBufferForaccXms2 =
      Controller_without_ref_P.accXms2_Y0;

    // VirtualOutportStart for Outport: '<S11>/<acc Y [m//s^2]>'
    Controller_without_ref_B.OutportBufferForaccYms2 =
      Controller_without_ref_P.accYms2_Y0;

    // VirtualOutportStart for Outport: '<S11>/<acc Z [m//s^2]>'
    Controller_without_ref_B.OutportBufferForaccZms2 =
      Controller_without_ref_P.accZms2_Y0;

    // End of Start for SubSystem: '<Root>/states'

    // Start for MATLABSystem: '<S7>/Enable integration?'
    Controller_without_ref_DWork.obj_g0.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_lj = true;
    Controller_without_ref_DWork.obj_g0.SampleTime =
      Controller_without_ref_P.Enableintegration_SampleTime;
    Controller_without_ref_DWork.obj_g0.isInitialized = 1;
    for (i = 0; i < 37; i++) {
      Controller_without_ref_B.cv3[i] = tmp_u[i];
    }

    Controller_without_ref_B.cv3[37] = '\x00';
    ParamGet_Controller_without_ref_686.initialize(Controller_without_ref_B.cv3,
      Cont_ParameterInitialValue_oeap, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S7>/Enable integration?'

    // Start for Enabled SubSystem: '<Root>/Create errors'
    // VirtualOutportStart for Outport: '<S2>/angular_vel x error [degrees]'
    Controller_without_ref_B.Errorx =
      Controller_without_ref_P.angular_velxerrordegrees_Y0;

    // VirtualOutportStart for Outport: '<S2>/angular_vel y error [degrees]'
    Controller_without_ref_B.Errory =
      Controller_without_ref_P.angular_velyerrordegrees_Y0;

    // VirtualOutportStart for Outport: '<S2>/angular_vel z error [degrees]'
    Controller_without_ref_B.Errorz =
      Controller_without_ref_P.angular_velzerrordegrees_Y0;

    // VirtualOutportStart for Outport: '<S2>/vel x error [m//s]'
    Controller_without_ref_B.Errorz8 = Controller_without_ref_P.velxerrorms_Y0;

    // VirtualOutportStart for Outport: '<S2>/vel y error [m//s]'
    Controller_without_ref_B.Errorz9 = Controller_without_ref_P.velyerrorms_Y0;

    // VirtualOutportStart for Outport: '<S2>/vel z error [m//s]'
    Controller_without_ref_B.Errorz10 = Controller_without_ref_P.velzerrorms_Y0;

    // End of Start for SubSystem: '<Root>/Create errors'

    // Start for Enabled SubSystem: '<Root>/decController'
    // Start for MATLABSystem: '<S41>/P_angular_vel_x'
    Controller_without_ref_DWork.obj_bm.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_f = true;
    Controller_without_ref_DWork.obj_bm.SampleTime =
      Controller_without_ref_P.P_angular_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_bm.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_t[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_508.initialize(Controller_without_ref_B.cv5,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S41>/P_angular_vel_x'

    // Start for MATLABSystem: '<S41>/D_angular_vel_x'
    Controller_without_ref_DWork.obj_be.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_g = true;
    Controller_without_ref_DWork.obj_be.SampleTime =
      Controller_without_ref_P.D_angular_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_be.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_s[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_505.initialize(Controller_without_ref_B.cv5,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S41>/D_angular_vel_x'

    // Start for MATLABSystem: '<S41>/N_angular_vel_x '
    Controller_without_ref_DWork.obj_l.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_d0 = true;
    Controller_without_ref_DWork.obj_l.SampleTime =
      Controller_without_ref_P.N_angular_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_l.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_r[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_507.initialize(Controller_without_ref_B.cv5,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S41>/N_angular_vel_x '

    // Start for MATLABSystem: '<S41>/I_angular_vel_x'
    Controller_without_ref_DWork.obj_pb.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_mb = true;
    Controller_without_ref_DWork.obj_pb.SampleTime =
      Controller_without_ref_P.I_angular_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_pb.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_q[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_506.initialize(Controller_without_ref_B.cv5,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S41>/I_angular_vel_x'

    // Start for MATLABSystem: '<S44>/P_angular_vel_y'
    Controller_without_ref_DWork.obj_b.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_j = true;
    Controller_without_ref_DWork.obj_b.SampleTime =
      Controller_without_ref_P.P_angular_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_b.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_p[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_522.initialize(Controller_without_ref_B.cv5,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S44>/P_angular_vel_y'

    // Start for MATLABSystem: '<S44>/D_angular_vel_y'
    Controller_without_ref_DWork.obj_m.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_h1 = true;
    Controller_without_ref_DWork.obj_m.SampleTime =
      Controller_without_ref_P.D_angular_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_m.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_o[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_519.initialize(Controller_without_ref_B.cv5,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S44>/D_angular_vel_y'

    // Start for MATLABSystem: '<S44>/N_angular_vel_y '
    Controller_without_ref_DWork.obj_dp.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ex = true;
    Controller_without_ref_DWork.obj_dp.SampleTime =
      Controller_without_ref_P.N_angular_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_dp.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_n[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_521.initialize(Controller_without_ref_B.cv5,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S44>/N_angular_vel_y '

    // Start for MATLABSystem: '<S44>/I_angular_vel_y'
    Controller_without_ref_DWork.obj_ep.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ef = true;
    Controller_without_ref_DWork.obj_ep.SampleTime =
      Controller_without_ref_P.I_angular_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_ep.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_m[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_520.initialize(Controller_without_ref_B.cv5,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S44>/I_angular_vel_y'

    // Start for MATLABSystem: '<S47>/P_angular_vel_z'
    Controller_without_ref_DWork.obj_e.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_h = true;
    Controller_without_ref_DWork.obj_e.SampleTime =
      Controller_without_ref_P.P_angular_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_e.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_l[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_536.initialize(Controller_without_ref_B.cv5,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S47>/P_angular_vel_z'

    // Start for MATLABSystem: '<S47>/D_angular_vel_z'
    Controller_without_ref_DWork.obj_jg.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_if = true;
    Controller_without_ref_DWork.obj_jg.SampleTime =
      Controller_without_ref_P.D_angular_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_jg.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_k[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_533.initialize(Controller_without_ref_B.cv5,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S47>/D_angular_vel_z'

    // Start for MATLABSystem: '<S47>/N_angular_vel_z '
    Controller_without_ref_DWork.obj_g.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_m1 = true;
    Controller_without_ref_DWork.obj_g.SampleTime =
      Controller_without_ref_P.N_angular_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_g.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_j[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_535.initialize(Controller_without_ref_B.cv5,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S47>/N_angular_vel_z '

    // Start for MATLABSystem: '<S47>/I_angular_vel_z'
    Controller_without_ref_DWork.obj_p.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_k = true;
    Controller_without_ref_DWork.obj_p.SampleTime =
      Controller_without_ref_P.I_angular_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_p.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_i[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_534.initialize(Controller_without_ref_B.cv5,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S47>/I_angular_vel_z'

    // Start for MATLABSystem: '<S50>/P_vel_x'
    Controller_without_ref_DWork.obj_ns.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_a = true;
    Controller_without_ref_DWork.obj_ns.SampleTime =
      Controller_without_ref_P.P_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_ns.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv9[i] = tmp_h[i];
    }

    Controller_without_ref_B.cv9[26] = '\x00';
    ParamGet_Controller_without_ref_550.initialize(Controller_without_ref_B.cv9,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S50>/P_vel_x'

    // Start for MATLABSystem: '<S50>/D_vel_x'
    Controller_without_ref_DWork.obj_d.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_d = true;
    Controller_without_ref_DWork.obj_d.SampleTime =
      Controller_without_ref_P.D_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_d.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv9[i] = tmp_g[i];
    }

    Controller_without_ref_B.cv9[26] = '\x00';
    ParamGet_Controller_without_ref_547.initialize(Controller_without_ref_B.cv9,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S50>/D_vel_x'

    // Start for MATLABSystem: '<S50>/N_vel_x '
    Controller_without_ref_DWork.obj_a3.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_il = true;
    Controller_without_ref_DWork.obj_a3.SampleTime =
      Controller_without_ref_P.N_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_a3.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv9[i] = tmp_f[i];
    }

    Controller_without_ref_B.cv9[26] = '\x00';
    ParamGet_Controller_without_ref_549.initialize(Controller_without_ref_B.cv9,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S50>/N_vel_x '

    // Start for MATLABSystem: '<S50>/I_vel_x'
    Controller_without_ref_DWork.obj_cv.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_p = true;
    Controller_without_ref_DWork.obj_cv.SampleTime =
      Controller_without_ref_P.I_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_cv.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv9[i] = tmp_e[i];
    }

    Controller_without_ref_B.cv9[26] = '\x00';
    ParamGet_Controller_without_ref_548.initialize(Controller_without_ref_B.cv9,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S50>/I_vel_x'

    // Start for MATLABSystem: '<S53>/P_vel_y'
    Controller_without_ref_DWork.obj_ji.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ej = true;
    Controller_without_ref_DWork.obj_ji.SampleTime =
      Controller_without_ref_P.P_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_ji.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv9[i] = tmp_d[i];
    }

    Controller_without_ref_B.cv9[26] = '\x00';
    ParamGet_Controller_without_ref_564.initialize(Controller_without_ref_B.cv9,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S53>/P_vel_y'

    // Start for MATLABSystem: '<S53>/D_vel_y'
    Controller_without_ref_DWork.obj_n.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_c = true;
    Controller_without_ref_DWork.obj_n.SampleTime =
      Controller_without_ref_P.D_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_n.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv9[i] = tmp_c[i];
    }

    Controller_without_ref_B.cv9[26] = '\x00';
    ParamGet_Controller_without_ref_561.initialize(Controller_without_ref_B.cv9,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S53>/D_vel_y'

    // Start for MATLABSystem: '<S53>/N_vel_y '
    Controller_without_ref_DWork.obj_c.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_b = true;
    Controller_without_ref_DWork.obj_c.SampleTime =
      Controller_without_ref_P.N_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_c.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv9[i] = tmp_b[i];
    }

    Controller_without_ref_B.cv9[26] = '\x00';
    ParamGet_Controller_without_ref_563.initialize(Controller_without_ref_B.cv9,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S53>/N_vel_y '

    // Start for MATLABSystem: '<S53>/I_vel_y'
    Controller_without_ref_DWork.obj_jx.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_m = true;
    Controller_without_ref_DWork.obj_jx.SampleTime =
      Controller_without_ref_P.I_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_jx.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv9[i] = tmp_a[i];
    }

    Controller_without_ref_B.cv9[26] = '\x00';
    ParamGet_Controller_without_ref_562.initialize(Controller_without_ref_B.cv9,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S53>/I_vel_y'

    // Start for MATLABSystem: '<S56>/P_vel_z'
    Controller_without_ref_DWork.obj.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_l = true;
    Controller_without_ref_DWork.obj.SampleTime =
      Controller_without_ref_P.P_vel_z_SampleTime;
    Controller_without_ref_DWork.obj.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv9[i] = tmp_9[i];
    }

    Controller_without_ref_B.cv9[26] = '\x00';
    ParamGet_Controller_without_ref_578.initialize(Controller_without_ref_B.cv9,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S56>/P_vel_z'

    // Start for MATLABSystem: '<S56>/D_vel_z'
    Controller_without_ref_DWork.obj_a.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_n = true;
    Controller_without_ref_DWork.obj_a.SampleTime =
      Controller_without_ref_P.D_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_a.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv9[i] = tmp_8[i];
    }

    Controller_without_ref_B.cv9[26] = '\x00';
    ParamGet_Controller_without_ref_575.initialize(Controller_without_ref_B.cv9,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S56>/D_vel_z'

    // Start for MATLABSystem: '<S56>/N_vel_z '
    Controller_without_ref_DWork.obj_h.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_e = true;
    Controller_without_ref_DWork.obj_h.SampleTime =
      Controller_without_ref_P.N_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_h.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv9[i] = tmp_7[i];
    }

    Controller_without_ref_B.cv9[26] = '\x00';
    ParamGet_Controller_without_ref_577.initialize(Controller_without_ref_B.cv9,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S56>/N_vel_z '

    // Start for MATLABSystem: '<S56>/I_vel_z'
    Controller_without_ref_DWork.obj_j.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_n4 = true;
    Controller_without_ref_DWork.obj_j.SampleTime =
      Controller_without_ref_P.I_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_j.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv9[i] = tmp_6[i];
    }

    Controller_without_ref_B.cv9[26] = '\x00';
    ParamGet_Controller_without_ref_576.initialize(Controller_without_ref_B.cv9,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S56>/I_vel_z'
    // End of Start for SubSystem: '<Root>/decController'

    // InitializeConditions for Enabled SubSystem: '<Root>/decController'
    // InitializeConditions for DiscreteIntegrator: '<S40>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE =
      Controller_without_ref_P.Integrator_IC;

    // InitializeConditions for DiscreteIntegrator: '<S40>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE =
      Controller_without_ref_P.Filter_IC;

    // InitializeConditions for DiscreteIntegrator: '<S43>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_h =
      Controller_without_ref_P.Integrator_IC_o;

    // InitializeConditions for DiscreteIntegrator: '<S43>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_c =
      Controller_without_ref_P.Filter_IC_n;

    // InitializeConditions for DiscreteIntegrator: '<S46>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_a =
      Controller_without_ref_P.Integrator_IC_d;

    // InitializeConditions for DiscreteIntegrator: '<S46>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_f =
      Controller_without_ref_P.Filter_IC_c;

    // InitializeConditions for DiscreteIntegrator: '<S49>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_f =
      Controller_without_ref_P.Integrator_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S49>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_a =
      Controller_without_ref_P.Filter_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S52>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_n =
      Controller_without_ref_P.Integrator_IC_i;

    // InitializeConditions for DiscreteIntegrator: '<S52>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_g =
      Controller_without_ref_P.Filter_IC_jx;

    // InitializeConditions for DiscreteIntegrator: '<S55>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_ny =
      Controller_without_ref_P.Integrator_IC_m;

    // InitializeConditions for DiscreteIntegrator: '<S55>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_cw =
      Controller_without_ref_P.Filter_IC_p;

    // End of InitializeConditions for SubSystem: '<Root>/decController'

    // Start for Enabled SubSystem: '<Root>/decController'
    // VirtualOutportStart for Outport: '<S9>/velocites [angular xyz, linear xyz]' 
    Controller_without_ref_B.Saturate =
      Controller_without_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_without_ref_B.Saturate_f =
      Controller_without_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_without_ref_B.Saturate_i =
      Controller_without_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_without_ref_B.Saturate_b =
      Controller_without_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_without_ref_B.Saturate_h =
      Controller_without_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_without_ref_B.Saturate_bk =
      Controller_without_ref_P.velocitesangularxyzlinearxyz_Y0;

    // End of Start for SubSystem: '<Root>/decController'

    // Start for MATLABSystem: '<S3>/Get front strafe decouple'
    Controller_without_ref_DWork.obj_np.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_gg = true;
    Controller_without_ref_DWork.obj_np.SampleTime =
      Controller_without_ref_P.Getfrontstrafedecouple_SampleTi;
    Controller_without_ref_DWork.obj_np.isInitialized = 1;
    for (i = 0; i < 40; i++) {
      Controller_without_ref_B.cv1[i] = tmp_5[i];
    }

    Controller_without_ref_B.cv1[40] = '\x00';
    ParamGet_Controller_without_ref_787.initialize(Controller_without_ref_B.cv1,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S3>/Get front strafe decouple'

    // Start for MATLABSystem: '<S3>/Get front forward decouple'
    Controller_without_ref_DWork.obj_dti.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ol = true;
    Controller_without_ref_DWork.obj_dti.SampleTime =
      Controller_without_ref_P.Getfrontforwarddecouple_SampleT;
    Controller_without_ref_DWork.obj_dti.isInitialized = 1;
    for (i = 0; i < 41; i++) {
      Controller_without_ref_B.cv0[i] = tmp_4[i];
    }

    Controller_without_ref_B.cv0[41] = '\x00';
    ParamGet_Controller_without_ref_785.initialize(Controller_without_ref_B.cv0,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S3>/Get front forward decouple'

    // Start for MATLABSystem: '<S3>/Get front pitch bias'
    Controller_without_ref_DWork.obj_cp.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ds = true;
    Controller_without_ref_DWork.obj_cp.SampleTime =
      Controller_without_ref_P.Getfrontpitchbias_SampleTime;
    Controller_without_ref_DWork.obj_cp.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_without_ref_B.cv4[i] = tmp_3[i];
    }

    Controller_without_ref_B.cv4[35] = '\x00';
    ParamGet_Controller_without_ref_786.initialize(Controller_without_ref_B.cv4,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S3>/Get front pitch bias'

    // Start for MATLABSystem: '<S3>/Get front vertical bias'
    Controller_without_ref_DWork.obj_ci.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ml = true;
    Controller_without_ref_DWork.obj_ci.SampleTime =
      Controller_without_ref_P.Getfrontverticalbias_SampleTime;
    Controller_without_ref_DWork.obj_ci.isInitialized = 1;
    for (i = 0; i < 38; i++) {
      Controller_without_ref_B.cv2[i] = tmp_2[i];
    }

    Controller_without_ref_B.cv2[38] = '\x00';
    ParamGet_Controller_without_ref_788.initialize(Controller_without_ref_B.cv2,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S3>/Get front vertical bias'

    // Start for MATLABSystem: '<S3>/Get buoyancy'
    Controller_without_ref_DWork.obj_ae.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_mt = true;
    Controller_without_ref_DWork.obj_ae.SampleTime =
      Controller_without_ref_P.Getbuoyancy_SampleTime;
    Controller_without_ref_DWork.obj_ae.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_without_ref_B.cv4[i] = tmp_1[i];
    }

    Controller_without_ref_B.cv4[35] = '\x00';
    ParamGet_Controller_without_ref_784.initialize(Controller_without_ref_B.cv4,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S3>/Get buoyancy'

    // Start for Enabled SubSystem: '<Root>/toPWM'
    // Start for Atomic SubSystem: '<S12>/Publish'
    // Start for MATLABSystem: '<S63>/SinkBlock'
    Controller_without_ref_DWork.obj_pw.isInitialized = 0;
    Controller_without_ref_DWork.objisempty = true;
    Controller_without_ref_DWork.obj_pw.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      Controller_without_ref_B.cv12[i] = tmp_0[i];
    }

    Controller_without_ref_B.cv12[16] = '\x00';
    Pub_Controller_without_ref_607.create_publisher
      (Controller_without_ref_B.cv12, Controller_wi_MessageQueueLen_o);

    // End of Start for MATLABSystem: '<S63>/SinkBlock'
    // End of Start for SubSystem: '<S12>/Publish'
    // End of Start for SubSystem: '<Root>/toPWM'

    // Start for MATLABSystem: '<S7>/Get alpha'
    Controller_without_ref_DWork.obj_hx.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_g0 = true;
    Controller_without_ref_DWork.obj_hx.SampleTime =
      Controller_without_ref_P.Getalpha_SampleTime;
    Controller_without_ref_DWork.obj_hx.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      Controller_without_ref_B.cv10[i] = tmp[i];
    }

    Controller_without_ref_B.cv10[24] = '\x00';
    ParamGet_Controller_without_ref_687.initialize(Controller_without_ref_B.cv10,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S7>/Get alpha'

    // InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' 
    Controller_without_ref_DWork.DiscreteTimeIntegrator_DSTATE =
      Controller_without_ref_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' 
    Controller_without_ref_DWork.DiscreteTimeIntegrator1_DSTATE =
      Controller_without_ref_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator2' 
    Controller_without_ref_DWork.DiscreteTimeIntegrator2_DSTATE =
      Controller_without_ref_P.DiscreteTimeIntegrator2_IC;

    // InitializeConditions for DiscreteFilter: '<S7>/Discrete Filter'
    Controller_without_ref_DWork.DiscreteFilter_denStates =
      Controller_without_ref_P.DiscreteFilter_InitialDenominat;

    // InitializeConditions for DiscreteFilter: '<S7>/Discrete Filter1'
    Controller_without_ref_DWork.DiscreteFilter1_denStates =
      Controller_without_ref_P.DiscreteFilter1_InitialDenomina;

    // InitializeConditions for DiscreteFilter: '<S7>/Discrete Filter2'
    Controller_without_ref_DWork.DiscreteFilter2_denStates =
      Controller_without_ref_P.DiscreteFilter2_InitialDenomina;
  }
}

// Model terminate function
void ControllerModelClass::terminate()
{
  // Start for MATLABSystem: '<Root>/Get test' incorporates:
  //   Terminate for MATLABSystem: '<Root>/Get test'

  if (Controller_without_ref_DWork.obj_h2.isInitialized == 1) {
    Controller_without_ref_DWork.obj_h2.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/Get test'

  // Terminate for Enabled SubSystem: '<Root>/Telegraph'
  // Start for MATLABSystem: '<S15>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S15>/Swtiching factor'

  if (Controller_without_ref_DWork.obj_of.isInitialized == 1) {
    Controller_without_ref_DWork.obj_of.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S15>/Swtiching factor'

  // Start for MATLABSystem: '<S15>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S15>/Swtiching factor1'

  if (Controller_without_ref_DWork.obj_fx.isInitialized == 1) {
    Controller_without_ref_DWork.obj_fx.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S15>/Swtiching factor1'

  // Start for MATLABSystem: '<S15>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S15>/Swtiching factor2'

  if (Controller_without_ref_DWork.obj_d3.isInitialized == 1) {
    Controller_without_ref_DWork.obj_d3.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S15>/Swtiching factor2'

  // Start for MATLABSystem: '<S16>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S16>/Swtiching factor'

  if (Controller_without_ref_DWork.obj_i.isInitialized == 1) {
    Controller_without_ref_DWork.obj_i.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S16>/Swtiching factor'

  // Start for MATLABSystem: '<S16>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S16>/Swtiching factor1'

  if (Controller_without_ref_DWork.obj_j5.isInitialized == 1) {
    Controller_without_ref_DWork.obj_j5.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S16>/Swtiching factor1'

  // Start for MATLABSystem: '<S16>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S16>/Swtiching factor2'

  if (Controller_without_ref_DWork.obj_fu.isInitialized == 1) {
    Controller_without_ref_DWork.obj_fu.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S16>/Swtiching factor2'

  // Start for MATLABSystem: '<S17>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S17>/Swtiching factor'

  if (Controller_without_ref_DWork.obj_o.isInitialized == 1) {
    Controller_without_ref_DWork.obj_o.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S17>/Swtiching factor'

  // Start for MATLABSystem: '<S17>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S17>/Swtiching factor1'

  if (Controller_without_ref_DWork.obj_f.isInitialized == 1) {
    Controller_without_ref_DWork.obj_f.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S17>/Swtiching factor1'

  // Start for MATLABSystem: '<S17>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S17>/Swtiching factor2'

  if (Controller_without_ref_DWork.obj_mb.isInitialized == 1) {
    Controller_without_ref_DWork.obj_mb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S17>/Swtiching factor2'

  // Start for MATLABSystem: '<S18>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S18>/Swtiching factor'

  if (Controller_without_ref_DWork.obj_gv.isInitialized == 1) {
    Controller_without_ref_DWork.obj_gv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S18>/Swtiching factor'

  // Start for MATLABSystem: '<S18>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S18>/Swtiching factor1'

  if (Controller_without_ref_DWork.obj_c2.isInitialized == 1) {
    Controller_without_ref_DWork.obj_c2.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S18>/Swtiching factor1'

  // Start for MATLABSystem: '<S18>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S18>/Swtiching factor2'

  if (Controller_without_ref_DWork.obj_g0e.isInitialized == 1) {
    Controller_without_ref_DWork.obj_g0e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S18>/Swtiching factor2'

  // Start for MATLABSystem: '<S19>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S19>/Swtiching factor'

  if (Controller_without_ref_DWork.obj_j0.isInitialized == 1) {
    Controller_without_ref_DWork.obj_j0.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S19>/Swtiching factor'

  // Start for MATLABSystem: '<S19>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S19>/Swtiching factor1'

  if (Controller_without_ref_DWork.obj_hr.isInitialized == 1) {
    Controller_without_ref_DWork.obj_hr.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S19>/Swtiching factor1'

  // Start for MATLABSystem: '<S19>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S19>/Swtiching factor2'

  if (Controller_without_ref_DWork.obj_dn.isInitialized == 1) {
    Controller_without_ref_DWork.obj_dn.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S19>/Swtiching factor2'

  // Start for MATLABSystem: '<S20>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S20>/Swtiching factor'

  if (Controller_without_ref_DWork.obj_gf.isInitialized == 1) {
    Controller_without_ref_DWork.obj_gf.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S20>/Swtiching factor'

  // Start for MATLABSystem: '<S20>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S20>/Swtiching factor1'

  if (Controller_without_ref_DWork.obj_cvy.isInitialized == 1) {
    Controller_without_ref_DWork.obj_cvy.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S20>/Swtiching factor1'

  // Start for MATLABSystem: '<S20>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S20>/Swtiching factor2'

  if (Controller_without_ref_DWork.obj_dt.isInitialized == 1) {
    Controller_without_ref_DWork.obj_dt.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S20>/Swtiching factor2'
  // End of Terminate for SubSystem: '<Root>/Telegraph'

  // Start for MATLABSystem: '<Root>/Get controller type' incorporates:
  //   Terminate for MATLABSystem: '<Root>/Get controller type'

  if (Controller_without_ref_DWork.obj_nl.isInitialized == 1) {
    Controller_without_ref_DWork.obj_nl.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/Get controller type'

  // Terminate for Atomic SubSystem: '<Root>/cmd_vel'
  // Start for MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S8>/SourceBlock'

  if (Controller_without_ref_DWork.obj_nf.isInitialized == 1) {
    Controller_without_ref_DWork.obj_nf.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/cmd_vel'

  // Terminate for Atomic SubSystem: '<Root>/imu_data'
  // Start for MATLABSystem: '<S10>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S10>/SourceBlock'

  if (Controller_without_ref_DWork.obj_k.isInitialized == 1) {
    Controller_without_ref_DWork.obj_k.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S10>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/imu_data'

  // Start for MATLABSystem: '<S4>/Get front strafe decouple' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get front strafe decouple'

  if (Controller_without_ref_DWork.obj_mp.isInitialized == 1) {
    Controller_without_ref_DWork.obj_mp.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get front strafe decouple'

  // Start for MATLABSystem: '<S4>/Get front forward decouple' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get front forward decouple'

  if (Controller_without_ref_DWork.obj_ij.isInitialized == 1) {
    Controller_without_ref_DWork.obj_ij.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get front forward decouple'

  // Start for MATLABSystem: '<S4>/Get front pitch bias' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get front pitch bias'

  if (Controller_without_ref_DWork.obj_nr.isInitialized == 1) {
    Controller_without_ref_DWork.obj_nr.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get front pitch bias'

  // Start for MATLABSystem: '<S4>/Get front vertical bias' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get front vertical bias'

  if (Controller_without_ref_DWork.obj_o5.isInitialized == 1) {
    Controller_without_ref_DWork.obj_o5.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get front vertical bias'

  // Start for MATLABSystem: '<S4>/Get buoyancy' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get buoyancy'

  if (Controller_without_ref_DWork.obj_ot.isInitialized == 1) {
    Controller_without_ref_DWork.obj_ot.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get buoyancy'

  // Start for MATLABSystem: '<S7>/Enable integration?' incorporates:
  //   Terminate for MATLABSystem: '<S7>/Enable integration?'

  if (Controller_without_ref_DWork.obj_g0.isInitialized == 1) {
    Controller_without_ref_DWork.obj_g0.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/Enable integration?'

  // Terminate for Enabled SubSystem: '<Root>/decController'
  // Start for MATLABSystem: '<S41>/P_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S41>/P_angular_vel_x'

  if (Controller_without_ref_DWork.obj_bm.isInitialized == 1) {
    Controller_without_ref_DWork.obj_bm.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S41>/P_angular_vel_x'

  // Start for MATLABSystem: '<S41>/D_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S41>/D_angular_vel_x'

  if (Controller_without_ref_DWork.obj_be.isInitialized == 1) {
    Controller_without_ref_DWork.obj_be.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S41>/D_angular_vel_x'

  // Start for MATLABSystem: '<S41>/N_angular_vel_x ' incorporates:
  //   Terminate for MATLABSystem: '<S41>/N_angular_vel_x '

  if (Controller_without_ref_DWork.obj_l.isInitialized == 1) {
    Controller_without_ref_DWork.obj_l.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S41>/N_angular_vel_x '

  // Start for MATLABSystem: '<S41>/I_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S41>/I_angular_vel_x'

  if (Controller_without_ref_DWork.obj_pb.isInitialized == 1) {
    Controller_without_ref_DWork.obj_pb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S41>/I_angular_vel_x'

  // Start for MATLABSystem: '<S44>/P_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S44>/P_angular_vel_y'

  if (Controller_without_ref_DWork.obj_b.isInitialized == 1) {
    Controller_without_ref_DWork.obj_b.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S44>/P_angular_vel_y'

  // Start for MATLABSystem: '<S44>/D_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S44>/D_angular_vel_y'

  if (Controller_without_ref_DWork.obj_m.isInitialized == 1) {
    Controller_without_ref_DWork.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S44>/D_angular_vel_y'

  // Start for MATLABSystem: '<S44>/N_angular_vel_y ' incorporates:
  //   Terminate for MATLABSystem: '<S44>/N_angular_vel_y '

  if (Controller_without_ref_DWork.obj_dp.isInitialized == 1) {
    Controller_without_ref_DWork.obj_dp.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S44>/N_angular_vel_y '

  // Start for MATLABSystem: '<S44>/I_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S44>/I_angular_vel_y'

  if (Controller_without_ref_DWork.obj_ep.isInitialized == 1) {
    Controller_without_ref_DWork.obj_ep.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S44>/I_angular_vel_y'

  // Start for MATLABSystem: '<S47>/P_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S47>/P_angular_vel_z'

  if (Controller_without_ref_DWork.obj_e.isInitialized == 1) {
    Controller_without_ref_DWork.obj_e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S47>/P_angular_vel_z'

  // Start for MATLABSystem: '<S47>/D_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S47>/D_angular_vel_z'

  if (Controller_without_ref_DWork.obj_jg.isInitialized == 1) {
    Controller_without_ref_DWork.obj_jg.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S47>/D_angular_vel_z'

  // Start for MATLABSystem: '<S47>/N_angular_vel_z ' incorporates:
  //   Terminate for MATLABSystem: '<S47>/N_angular_vel_z '

  if (Controller_without_ref_DWork.obj_g.isInitialized == 1) {
    Controller_without_ref_DWork.obj_g.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S47>/N_angular_vel_z '

  // Start for MATLABSystem: '<S47>/I_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S47>/I_angular_vel_z'

  if (Controller_without_ref_DWork.obj_p.isInitialized == 1) {
    Controller_without_ref_DWork.obj_p.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S47>/I_angular_vel_z'

  // Start for MATLABSystem: '<S50>/P_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S50>/P_vel_x'

  if (Controller_without_ref_DWork.obj_ns.isInitialized == 1) {
    Controller_without_ref_DWork.obj_ns.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S50>/P_vel_x'

  // Start for MATLABSystem: '<S50>/D_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S50>/D_vel_x'

  if (Controller_without_ref_DWork.obj_d.isInitialized == 1) {
    Controller_without_ref_DWork.obj_d.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S50>/D_vel_x'

  // Start for MATLABSystem: '<S50>/N_vel_x ' incorporates:
  //   Terminate for MATLABSystem: '<S50>/N_vel_x '

  if (Controller_without_ref_DWork.obj_a3.isInitialized == 1) {
    Controller_without_ref_DWork.obj_a3.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S50>/N_vel_x '

  // Start for MATLABSystem: '<S50>/I_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S50>/I_vel_x'

  if (Controller_without_ref_DWork.obj_cv.isInitialized == 1) {
    Controller_without_ref_DWork.obj_cv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S50>/I_vel_x'

  // Start for MATLABSystem: '<S53>/P_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S53>/P_vel_y'

  if (Controller_without_ref_DWork.obj_ji.isInitialized == 1) {
    Controller_without_ref_DWork.obj_ji.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S53>/P_vel_y'

  // Start for MATLABSystem: '<S53>/D_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S53>/D_vel_y'

  if (Controller_without_ref_DWork.obj_n.isInitialized == 1) {
    Controller_without_ref_DWork.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S53>/D_vel_y'

  // Start for MATLABSystem: '<S53>/N_vel_y ' incorporates:
  //   Terminate for MATLABSystem: '<S53>/N_vel_y '

  if (Controller_without_ref_DWork.obj_c.isInitialized == 1) {
    Controller_without_ref_DWork.obj_c.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S53>/N_vel_y '

  // Start for MATLABSystem: '<S53>/I_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S53>/I_vel_y'

  if (Controller_without_ref_DWork.obj_jx.isInitialized == 1) {
    Controller_without_ref_DWork.obj_jx.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S53>/I_vel_y'

  // Start for MATLABSystem: '<S56>/P_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S56>/P_vel_z'

  if (Controller_without_ref_DWork.obj.isInitialized == 1) {
    Controller_without_ref_DWork.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S56>/P_vel_z'

  // Start for MATLABSystem: '<S56>/D_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S56>/D_vel_z'

  if (Controller_without_ref_DWork.obj_a.isInitialized == 1) {
    Controller_without_ref_DWork.obj_a.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S56>/D_vel_z'

  // Start for MATLABSystem: '<S56>/N_vel_z ' incorporates:
  //   Terminate for MATLABSystem: '<S56>/N_vel_z '

  if (Controller_without_ref_DWork.obj_h.isInitialized == 1) {
    Controller_without_ref_DWork.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S56>/N_vel_z '

  // Start for MATLABSystem: '<S56>/I_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S56>/I_vel_z'

  if (Controller_without_ref_DWork.obj_j.isInitialized == 1) {
    Controller_without_ref_DWork.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S56>/I_vel_z'
  // End of Terminate for SubSystem: '<Root>/decController'

  // Start for MATLABSystem: '<S3>/Get front strafe decouple' incorporates:
  //   Terminate for MATLABSystem: '<S3>/Get front strafe decouple'

  if (Controller_without_ref_DWork.obj_np.isInitialized == 1) {
    Controller_without_ref_DWork.obj_np.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/Get front strafe decouple'

  // Start for MATLABSystem: '<S3>/Get front forward decouple' incorporates:
  //   Terminate for MATLABSystem: '<S3>/Get front forward decouple'

  if (Controller_without_ref_DWork.obj_dti.isInitialized == 1) {
    Controller_without_ref_DWork.obj_dti.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/Get front forward decouple'

  // Start for MATLABSystem: '<S3>/Get front pitch bias' incorporates:
  //   Terminate for MATLABSystem: '<S3>/Get front pitch bias'

  if (Controller_without_ref_DWork.obj_cp.isInitialized == 1) {
    Controller_without_ref_DWork.obj_cp.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/Get front pitch bias'

  // Start for MATLABSystem: '<S3>/Get front vertical bias' incorporates:
  //   Terminate for MATLABSystem: '<S3>/Get front vertical bias'

  if (Controller_without_ref_DWork.obj_ci.isInitialized == 1) {
    Controller_without_ref_DWork.obj_ci.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/Get front vertical bias'

  // Start for MATLABSystem: '<S3>/Get buoyancy' incorporates:
  //   Terminate for MATLABSystem: '<S3>/Get buoyancy'

  if (Controller_without_ref_DWork.obj_ae.isInitialized == 1) {
    Controller_without_ref_DWork.obj_ae.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/Get buoyancy'

  // Terminate for Enabled SubSystem: '<Root>/toPWM'
  // Terminate for Atomic SubSystem: '<S12>/Publish'
  // Start for MATLABSystem: '<S63>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S63>/SinkBlock'

  if (Controller_without_ref_DWork.obj_pw.isInitialized == 1) {
    Controller_without_ref_DWork.obj_pw.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S63>/SinkBlock'
  // End of Terminate for SubSystem: '<S12>/Publish'
  // End of Terminate for SubSystem: '<Root>/toPWM'

  // Start for MATLABSystem: '<S7>/Get alpha' incorporates:
  //   Terminate for MATLABSystem: '<S7>/Get alpha'

  if (Controller_without_ref_DWork.obj_hx.isInitialized == 1) {
    Controller_without_ref_DWork.obj_hx.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/Get alpha'
}

// Constructor
ControllerModelClass::ControllerModelClass()
{
  static const Parameters_Controller_without_T Controller_without_ref_P_temp = {
    1.0,                               // Mask Parameter: PIDController_Kt
                                       //  Referenced by: '<S40>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_j
                                       //  Referenced by: '<S43>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_p
                                       //  Referenced by: '<S46>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_jw
                                       //  Referenced by: '<S49>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_c
                                       //  Referenced by: '<S52>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_l
                                       //  Referenced by: '<S55>/Kt'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturationLi
                                       //  Referenced by:
                                       //    '<S40>/Saturate'
                                       //    '<S42>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_e
                                       //  Referenced by:
                                       //    '<S43>/Saturate'
                                       //    '<S45>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_p
                                       //  Referenced by:
                                       //    '<S46>/Saturate'
                                       //    '<S48>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_i
                                       //  Referenced by:
                                       //    '<S49>/Saturate'
                                       //    '<S51>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_g
                                       //  Referenced by:
                                       //    '<S52>/Saturate'
                                       //    '<S54>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturatio_pm
                                       //  Referenced by:
                                       //    '<S55>/Saturate'
                                       //    '<S57>/DeadZone'

    100.0,                             // Mask Parameter: RandomSource_MaxVal
                                       //  Referenced by: '<S15>/Random Source'

    100.0,                             // Mask Parameter: RandomSource_MaxVal_o
                                       //  Referenced by: '<S16>/Random Source'

    100.0,                             // Mask Parameter: RandomSource_MaxVal_g
                                       //  Referenced by: '<S17>/Random Source'

    100.0,                             // Mask Parameter: RandomSource_MaxVal_d
                                       //  Referenced by: '<S18>/Random Source'

    100.0,                             // Mask Parameter: RandomSource_MaxVal_n
                                       //  Referenced by: '<S19>/Random Source'

    100.0,                             // Mask Parameter: RandomSource_MaxVal_i
                                       //  Referenced by: '<S20>/Random Source'

    1.0,                               // Mask Parameter: RandomSource_MinVal
                                       //  Referenced by: '<S15>/Random Source'

    1.0,                               // Mask Parameter: RandomSource_MinVal_h
                                       //  Referenced by: '<S16>/Random Source'

    1.0,                               // Mask Parameter: RandomSource_MinVal_b
                                       //  Referenced by: '<S17>/Random Source'

    1.0,                               // Mask Parameter: RandomSource_MinVal_d
                                       //  Referenced by: '<S18>/Random Source'

    1.0,                               // Mask Parameter: RandomSource_MinVal_n
                                       //  Referenced by: '<S19>/Random Source'

    1.0,                               // Mask Parameter: RandomSource_MinVal_i
                                       //  Referenced by: '<S20>/Random Source'

    1.0,                               // Mask Parameter: PIDController_UpperSaturationLi
                                       //  Referenced by:
                                       //    '<S40>/Saturate'
                                       //    '<S42>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_o
                                       //  Referenced by:
                                       //    '<S43>/Saturate'
                                       //    '<S45>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_e
                                       //  Referenced by:
                                       //    '<S46>/Saturate'
                                       //    '<S48>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_d
                                       //  Referenced by:
                                       //    '<S49>/Saturate'
                                       //    '<S51>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_b
                                       //  Referenced by:
                                       //    '<S52>/Saturate'
                                       //    '<S54>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturatio_ba
                                       //  Referenced by:
                                       //    '<S55>/Saturate'
                                       //    '<S57>/DeadZone'

    0,                                 // Mask Parameter: CompareToConstant_const
                                       //  Referenced by: '<S1>/Constant'


    {
      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // Data

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // Data_SL_Info

      {
        0U,                            // DataOffset

        {
          {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          } }
        ,                              // Dim

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        }                              // Dim_SL_Info
      }                                // Layout
    },                                 // Computed Parameter: Out1_Y0
                                       //  Referenced by: '<S58>/Out1'


    {
      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // Data

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // Data_SL_Info

      {
        0U,                            // DataOffset

        {
          {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          } }
        ,                              // Dim

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        }                              // Dim_SL_Info
      }                                // Layout
    },                                 // Computed Parameter: Constant_Value
                                       //  Referenced by: '<S10>/Constant'


    {
      {
        0U, 0U, 0U, 0U, 0U, 0U }
      ,                                // Data

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // Data_SL_Info

      {
        0U,                            // DataOffset

        {
          {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          } }
        ,                              // Dim

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        }                              // Dim_SL_Info
      }                                // Layout
    },                                 // Computed Parameter: Constant_Value_i
                                       //  Referenced by: '<S60>/Constant'


    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Linear

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      }                                // Angular
    },                                 // Computed Parameter: Out1_Y0_f
                                       //  Referenced by: '<S33>/Out1'


    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Linear

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      }                                // Angular
    },                                 // Computed Parameter: Constant_Value_d
                                       //  Referenced by: '<S8>/Constant'


    //  Expression: zeros(6,1)
    //  Referenced by: '<Root>/Constant4'

    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<Root>/Get controller type'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<Root>/Get test'

    0.0,                               // Computed Parameter: yawerrordegrees_Y0
                                       //  Referenced by: '<S2>/yaw error [degrees]'

    0.0,                               // Computed Parameter: pitcherrordegrees_Y0
                                       //  Referenced by: '<S2>/pitch error [degrees]'

    0.0,                               // Computed Parameter: rollerrordegrees_Y0
                                       //  Referenced by: '<S2>/roll error [degrees]'

    0.0,                               // Computed Parameter: angular_velxerrordegrees_Y0
                                       //  Referenced by: '<S2>/angular_vel x error [degrees]'

    0.0,                               // Computed Parameter: angular_velyerrordegrees_Y0
                                       //  Referenced by: '<S2>/angular_vel y error [degrees]'

    0.0,                               // Computed Parameter: angular_velzerrordegrees_Y0
                                       //  Referenced by: '<S2>/angular_vel z error [degrees]'

    0.0,                               // Computed Parameter: xerrorms_Y0
                                       //  Referenced by: '<S2>/x error [m//s]'

    0.0,                               // Computed Parameter: yerrorm_Y0
                                       //  Referenced by: '<S2>/y error [m]'

    0.0,                               // Computed Parameter: zerrorm_Y0
                                       //  Referenced by: '<S2>/z error [m]'

    0.0,                               // Computed Parameter: velxerrorms_Y0
                                       //  Referenced by: '<S2>/vel x error [m//s]'

    0.0,                               // Computed Parameter: velyerrorms_Y0
                                       //  Referenced by: '<S2>/vel y error [m//s]'

    0.0,                               // Computed Parameter: velzerrorms_Y0
                                       //  Referenced by: '<S2>/vel z error [m//s]'

    0.0,                               // Computed Parameter: accxerrorms_Y0
                                       //  Referenced by: '<S2>/acc x error [m//s]'

    0.0,                               // Computed Parameter: accyerrorms_Y0
                                       //  Referenced by: '<S2>/acc y error [m//s]'

    0.0,                               // Computed Parameter: acczerrorms_Y0
                                       //  Referenced by: '<S2>/acc z error [m//s]'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S3>/Get buoyancy'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S3>/Get front vertical bias'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S3>/Get front pitch bias'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S3>/Get front forward decouple'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S3>/Get front strafe decouple'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get buoyancy'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get front vertical bias'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get front pitch bias'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get front forward decouple'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get front strafe decouple'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S15>/Swtiching factor2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S15>/Swtiching factor1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S15>/Swtiching factor'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S16>/Swtiching factor2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S16>/Swtiching factor1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S16>/Swtiching factor'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S17>/Swtiching factor2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S17>/Swtiching factor1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S17>/Swtiching factor'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S18>/Swtiching factor2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S18>/Swtiching factor1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S18>/Swtiching factor'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S19>/Swtiching factor2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S19>/Swtiching factor1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S19>/Swtiching factor'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S20>/Swtiching factor2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S20>/Swtiching factor1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S20>/Swtiching factor'

    0.0,                               // Computed Parameter: Thrusters_Y0
                                       //  Referenced by: '<S5>/Thrusters'

    100.0,                             // Expression: 100
                                       //  Referenced by: '<S15>/Constant'

    100.0,                             // Expression: 100
                                       //  Referenced by: '<S16>/Constant'

    100.0,                             // Expression: 100
                                       //  Referenced by: '<S17>/Constant'

    100.0,                             // Expression: 100
                                       //  Referenced by: '<S18>/Constant'

    100.0,                             // Expression: 100
                                       //  Referenced by: '<S19>/Constant'

    100.0,                             // Expression: 100
                                       //  Referenced by: '<S20>/Constant'

    0.0,                               // Computed Parameter: angular_velX_Y0
                                       //  Referenced by: '<S6>/<angular_vel X>'

    0.0,                               // Computed Parameter: angular_velY_Y0
                                       //  Referenced by: '<S6>/<angular_vel Y>'

    0.0,                               // Computed Parameter: angular_velZ_Y0
                                       //  Referenced by: '<S6>/<angular_vel Z> '

    0.0,                               // Computed Parameter: velocityX_Y0
                                       //  Referenced by: '<S6>/<velocity X>'

    0.0,                               // Computed Parameter: veloctiyY_Y0
                                       //  Referenced by: '<S6>/<veloctiy Y>'

    0.0,                               // Computed Parameter: velocityZ_Y0
                                       //  Referenced by: '<S6>/<velocity Z>'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S7>/Get alpha'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S7>/Enable integration?'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S41>/I_angular_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S41>/N_angular_vel_x '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S41>/D_angular_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S41>/P_angular_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S44>/I_angular_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S44>/N_angular_vel_y '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S44>/D_angular_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S44>/P_angular_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S47>/I_angular_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S47>/N_angular_vel_z '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S47>/D_angular_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S47>/P_angular_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S50>/I_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S50>/N_vel_x '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S50>/D_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S50>/P_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S53>/I_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S53>/N_vel_y '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S53>/D_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S53>/P_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S56>/I_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S56>/N_vel_z '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S56>/D_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S56>/P_vel_z'

    0.0,                               // Computed Parameter: velocitesangularxyzlinearxyz_Y0
                                       //  Referenced by: '<S9>/velocites [angular xyz, linear xyz]'

    0.2,                               // Computed Parameter: Integrator_gainval
                                       //  Referenced by: '<S40>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S40>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval
                                       //  Referenced by: '<S40>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S40>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S42>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S40>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_c
                                       //  Referenced by: '<S43>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S43>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_i
                                       //  Referenced by: '<S43>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S43>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S45>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S43>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_n
                                       //  Referenced by: '<S46>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S46>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_k
                                       //  Referenced by: '<S46>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S46>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S48>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S46>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_j
                                       //  Referenced by: '<S49>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S49>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_h
                                       //  Referenced by: '<S49>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S49>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S51>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S49>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_np
                                       //  Referenced by: '<S52>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S52>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_h0
                                       //  Referenced by: '<S52>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S52>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S54>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S52>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_m
                                       //  Referenced by: '<S55>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S55>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_b
                                       //  Referenced by: '<S55>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S55>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S57>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S55>/Constant'

    0.0,                               // Computed Parameter: yawdegrees_Y0
                                       //  Referenced by: '<S11>/<yaw [degrees]>'

    0.0,                               // Computed Parameter: pitchdegrees_Y0
                                       //  Referenced by: '<S11>/<pitch [degrees]>'

    0.0,                               // Computed Parameter: rolldegrees_Y0
                                       //  Referenced by: '<S11>/<roll [degrees]>'

    0.0,                               // Computed Parameter: angular_velXdegreess_Y0
                                       //  Referenced by: '<S11>/<angular_vel X [degrees//s]>'

    0.0,                               // Computed Parameter: angular_velYdegreess_Y0
                                       //  Referenced by: '<S11>/<angular_vel Y [degrees//s]>'

    0.0,                               // Computed Parameter: angular_velZdegreess_Y0
                                       //  Referenced by: '<S11>/<angular_vel Z [degrees//s]>'

    0.0,                               // Computed Parameter: Zm_Y0
                                       //  Referenced by: '<S11>/<Z [m]>'

    0.0,                               // Computed Parameter: accXms2_Y0
                                       //  Referenced by: '<S11>/<acc X [m//s^2]>'

    0.0,                               // Computed Parameter: accYms2_Y0
                                       //  Referenced by: '<S11>/<acc Y [m//s^2]>'

    0.0,                               // Computed Parameter: accZms2_Y0
                                       //  Referenced by: '<S11>/<acc Z [m//s^2]>'

    1.0,                               // Expression: 1
                                       //  Referenced by: '<S12>/Saturation'

    -1.0,                              // Expression: -1
                                       //  Referenced by: '<S12>/Saturation'

    0.2,                               // Computed Parameter: DiscreteTimeIntegrator_gainval
                                       //  Referenced by: '<S7>/Discrete-Time Integrator'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S7>/Discrete-Time Integrator'

    0.2,                               // Computed Parameter: DiscreteTimeIntegrator1_gainval
                                       //  Referenced by: '<S7>/Discrete-Time Integrator1'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S7>/Discrete-Time Integrator1'

    0.2,                               // Computed Parameter: DiscreteTimeIntegrator2_gainval
                                       //  Referenced by: '<S7>/Discrete-Time Integrator2'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S7>/Discrete-Time Integrator2'

    1.0,                               // Expression: 1
                                       //  Referenced by: '<S7>/Constant'

    1.0,                               // Expression: [1]
                                       //  Referenced by: '<S7>/Discrete Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S7>/Discrete Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S7>/Discrete Filter'

    1.0,                               // Expression: [1]
                                       //  Referenced by: '<S7>/Discrete Filter1'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S7>/Discrete Filter1'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S7>/Discrete Filter1'

    1.0,                               // Expression: [1]
                                       //  Referenced by: '<S7>/Discrete Filter2'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S7>/Discrete Filter2'

    0.0                                // Expression: 0
                                       //  Referenced by: '<S7>/Discrete Filter2'

  };                                   // Modifiable parameters

  // Initialize tunable parameters
  Controller_without_ref_P = Controller_without_ref_P_temp;
}

// Destructor
ControllerModelClass::~ControllerModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Controller_without_r_T * ControllerModelClass::getRTM()
{
  return (&Controller_without_ref_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
