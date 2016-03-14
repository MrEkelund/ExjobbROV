//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Controller.cpp
//
// Code generated for Simulink model 'Controller'.
//
// Model version                  : 1.160
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Mon Mar 14 10:07:11 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Controller.h"
#include "Controller_private.h"

// Named constants for State Transition Table: '<S15>/State Transition Table'
#define Controller_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define Controller_IN_state1           ((uint8_T)1U)
#define Controller_IN_state2           ((uint8_T)2U)
#define Con_ParameterInitialValue_l5xxx (true)
#define Cont_ParameterInitialValue_l5xx (false)
#define Contr_ParameterInitialValue_l5x (1.0)
#define Contro_ParameterInitialValue_l5 (0.0)
#define Control_ParameterInitialValue_l (1)
#define Controlle_ParameterInitialValue (0)
#define Controller_MessageQueueLen     (10)
#define Controller_MessageQueueLen_l   (1)

//
// Output and update for atomic system:
//    '<S3>/MATLAB Function'
//    '<S4>/MATLAB Function'
//
void Controller_MATLABFunction(real_T rtu_control_signals, real_T
  rtu_control_signals_h, real_T rtu_control_signals_m, real_T
  rtu_control_signals_e, real_T rtu_control_signals_d, real_T
  rtu_control_signals_hm, real_T rtu_buoyancy_control,
  rtB_MATLABFunction_Controller_T *localB)
{
  static const real_T a[36] = { 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -1.0, -1.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.11, -0.11, 0.0, 0.0, 0.0, 1.0,
    0.16, 0.16, 0.0, 0.0, -0.2, 0.0, 0.0, 0.0, 0.11, -0.11, 0.0, 0.0 };

  real_T rtu_buoyancy_control_0[6];
  int32_T i;
  int32_T i_0;
  real_T tmp;

  // SignalConversion: '<S13>/TmpSignal ConversionAt SFunction Inport1'
  // MATLAB Function 'Decouple1/MATLAB Function': '<S13>:1'
  //  % Vertical Left thruster (VL)
  //  thruster1 =...
  //      angular_x...
  //      -front_forward_decouple*vel_x...
  //      -front_strafe_decouple*vel_y...
  //      -front_pitch_bias*angular_y...
  //      +front_vertical_bias*vel_z...
  //      +buoyancy_control;
  //
  //  % Vertical Back thruster (VB)
  //  thruster3 =...
  //      front_forward_decouple * vel_x...
  //      +angular_y...
  //      +vel_z...
  //      +buoyancy_control;
  //
  //  thruster2 =...
  //      -angular_x...
  //      -front_forward_decouple * vel_x+...
  //      front_strafe_decouple*vel_y...
  //      -front_pitch_bias*angular_y...
  //      +front_vertical_bias * vel_z...
  //      +buoyancy_control;
  //
  //   %Forward Left (FL)
  //  thruster4 =...
  //      -angular_z...
  //      + vel_x;
  //  thruster5 = vel_y; % LATeral (LAT)
  //
  //  % Forward Right (FR)
  //  thruster6 =...
  //      angular_z...
  //      + vel_x;
  // '<S13>:1:58'
  localB->rtu_control_signals[0] = rtu_control_signals;
  localB->rtu_control_signals[1] = rtu_control_signals_h;
  localB->rtu_control_signals[2] = rtu_control_signals_m;
  localB->rtu_control_signals[3] = rtu_control_signals_e;
  localB->rtu_control_signals[4] = rtu_control_signals_d;
  localB->rtu_control_signals[5] = rtu_control_signals_hm;
  rtu_buoyancy_control_0[0] = rtu_buoyancy_control;
  rtu_buoyancy_control_0[1] = rtu_buoyancy_control;
  rtu_buoyancy_control_0[2] = 0.0;
  rtu_buoyancy_control_0[3] = 0.0;
  rtu_buoyancy_control_0[4] = rtu_buoyancy_control;
  rtu_buoyancy_control_0[5] = 0.0;
  for (i = 0; i < 6; i++) {
    tmp = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp += a[6 * i_0 + i] * localB->rtu_control_signals[i_0];
    }

    localB->thrusters[i] = tmp + rtu_buoyancy_control_0[i];
  }
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
void Controller_MATLABFunction_a(real_T rtu_u, real_T rtu_min_scale, real_T
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
  localDW->is_active_c6_Controller = 0U;
  localDW->is_c6_Controller = Controller_IN_NO_ACTIVE_CHILD;
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
  if (localDW->is_active_c6_Controller == 0U) {
    // Entry: Telegraph/Thruster1 block/State Transition Table
    localDW->is_active_c6_Controller = 1U;

    // Entry Internal: Telegraph/Thruster1 block/State Transition Table
    // Transition: '<S22>:15'
    localDW->is_c6_Controller = Controller_IN_state1;
  } else if (localDW->is_c6_Controller == Controller_IN_state1) {
    // During 'state1': '<S22>:13'
    if (rtu_x > 0.0) {
      // Transition: '<S22>:17'
      localB->u = 1.0;
      localDW->is_c6_Controller = Controller_IN_state2;
    } else {
      // Transition: '<S22>:19'
      // Transition: '<S22>:21'
      localDW->is_c6_Controller = Controller_IN_state1;
    }
  } else {
    // During 'state2': '<S22>:14'
    if (rtu_x > 0.0) {
      // Transition: '<S22>:18'
      localB->u = -1.0;
      localDW->is_c6_Controller = Controller_IN_state1;
    } else {
      // Transition: '<S22>:23'
      // Transition: '<S22>:25'
      localDW->is_c6_Controller = Controller_IN_state2;
    }
  }
}

void ControllerModelClass::Controller_RandSrc_U_D(real_T y[], const real_T
  minVec[], int32_T minLen, const real_T maxVec[], int32_T maxLen, real_T state[],
  int32_T nChans, int32_T nSamps)
{
  int8_T *onePtr;

  // Start for S-Function (sdsprandsrc2): '<S15>/Random Source'
  // RandSrc_U_D
  Controller_B.one = 1;
  onePtr = (int8_T *)&Controller_B.one;
  Controller_B.lsw = (onePtr[0U] == 0);
  Controller_B.chan = 0;
  while (Controller_B.chan < nChans) {
    Controller_B.min = minVec[minLen > 1 ? Controller_B.chan : 0];
    Controller_B.max = maxVec[maxLen > 1 ? Controller_B.chan : 0];
    Controller_B.max -= Controller_B.min;
    Controller_B.i_c = (int32_T)((uint32_T)state[Controller_B.chan * 35 + 33] &
      31U);
    Controller_B.j = (uint32_T)state[Controller_B.chan * 35 + 34];
    Controller_B.samps = 0;
    while (Controller_B.samps < nSamps) {
      // "Subtract with borrow" generator
      Controller_B.d = state[((Controller_B.i_c + 20) & 31) + Controller_B.chan *
        35];
      Controller_B.d -= state[((Controller_B.i_c + 5) & 31) + Controller_B.chan *
        35];
      Controller_B.d -= state[Controller_B.chan * 35 + 32];
      if (Controller_B.d >= 0.0) {
        state[Controller_B.chan * 35 + 32] = 0.0;
      } else {
        Controller_B.d++;

        // set 1 in LSB
        state[Controller_B.chan * 35 + 32] = 1.1102230246251565E-16;
      }

      state[Controller_B.chan * 35 + Controller_B.i_c] = Controller_B.d;
      Controller_B.i_c = (Controller_B.i_c + 1) & 31;

      // XOR with shift register sequence
      memcpy((void *)&Controller_B.ii[0U], (void *)&Controller_B.d, sizeof
             (real_T));
      Controller_B.ii[Controller_B.lsw] ^= Controller_B.j;
      Controller_B.j ^= Controller_B.j << 13;
      Controller_B.j ^= Controller_B.j >> 17;
      Controller_B.j ^= Controller_B.j << 5;
      Controller_B.ii[Controller_B.lsw ^ 1] ^= Controller_B.j & 1048575U;
      memcpy((void *)&Controller_B.d, (void *)&Controller_B.ii[0U], sizeof
             (real_T));
      y[Controller_B.chan * nSamps + Controller_B.samps] = Controller_B.max *
        Controller_B.d + Controller_B.min;
      Controller_B.samps++;
    }

    state[Controller_B.chan * 35 + 33] = Controller_B.i_c;
    state[Controller_B.chan * 35 + 34] = Controller_B.j;
    Controller_B.chan++;
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

real_T ControllerModelClass::Controller_rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      Controller_B.u1 = ceil(u1);
    } else {
      Controller_B.u1 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != Controller_B.u1)) {
      Controller_B.u1 = u0 / u1;
      if (fabs(Controller_B.u1 - rt_roundd_snf(Controller_B.u1)) <= DBL_EPSILON *
          fabs(Controller_B.u1)) {
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
void ControllerModelClass::Controller_sind(real_T *x)
{
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    Controller_B.c_x = (rtNaN);
  } else {
    Controller_B.c_x = Controller_rt_remd_snf(*x, 360.0);
    Controller_B.absx_c = fabs(Controller_B.c_x);
    if (Controller_B.absx_c > 180.0) {
      if (Controller_B.c_x > 0.0) {
        Controller_B.c_x -= 360.0;
      } else {
        Controller_B.c_x += 360.0;
      }

      Controller_B.absx_c = fabs(Controller_B.c_x);
    }

    if (Controller_B.absx_c <= 45.0) {
      Controller_B.c_x *= 0.017453292519943295;
      Controller_B.n_g = 0;
    } else if (Controller_B.absx_c <= 135.0) {
      if (Controller_B.c_x > 0.0) {
        Controller_B.c_x = (Controller_B.c_x - 90.0) * 0.017453292519943295;
        Controller_B.n_g = 1;
      } else {
        Controller_B.c_x = (Controller_B.c_x + 90.0) * 0.017453292519943295;
        Controller_B.n_g = -1;
      }
    } else if (Controller_B.c_x > 0.0) {
      Controller_B.c_x = (Controller_B.c_x - 180.0) * 0.017453292519943295;
      Controller_B.n_g = 2;
    } else {
      Controller_B.c_x = (Controller_B.c_x + 180.0) * 0.017453292519943295;
      Controller_B.n_g = -2;
    }

    if (Controller_B.n_g == 0) {
      Controller_B.c_x = sin(Controller_B.c_x);
    } else if (Controller_B.n_g == 1) {
      Controller_B.c_x = cos(Controller_B.c_x);
    } else if (Controller_B.n_g == -1) {
      Controller_B.c_x = -cos(Controller_B.c_x);
    } else {
      Controller_B.c_x = -sin(Controller_B.c_x);
    }
  }

  *x = Controller_B.c_x;
}

// Function for MATLAB Function: '<S11>/removeGravity'
void ControllerModelClass::Controller_cosd(real_T *x)
{
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    *x = (rtNaN);
  } else {
    Controller_B.b_x = Controller_rt_remd_snf(*x, 360.0);
    Controller_B.absx = fabs(Controller_B.b_x);
    if (Controller_B.absx > 180.0) {
      if (Controller_B.b_x > 0.0) {
        Controller_B.b_x -= 360.0;
      } else {
        Controller_B.b_x += 360.0;
      }

      Controller_B.absx = fabs(Controller_B.b_x);
    }

    if (Controller_B.absx <= 45.0) {
      Controller_B.b_x *= 0.017453292519943295;
      Controller_B.n = 0;
    } else if (Controller_B.absx <= 135.0) {
      if (Controller_B.b_x > 0.0) {
        Controller_B.b_x = (Controller_B.b_x - 90.0) * 0.017453292519943295;
        Controller_B.n = 1;
      } else {
        Controller_B.b_x = (Controller_B.b_x + 90.0) * 0.017453292519943295;
        Controller_B.n = -1;
      }
    } else if (Controller_B.b_x > 0.0) {
      Controller_B.b_x = (Controller_B.b_x - 180.0) * 0.017453292519943295;
      Controller_B.n = 2;
    } else {
      Controller_B.b_x = (Controller_B.b_x + 180.0) * 0.017453292519943295;
      Controller_B.n = -2;
    }

    if (Controller_B.n == 0) {
      *x = cos(Controller_B.b_x);
    } else if (Controller_B.n == 1) {
      *x = -sin(Controller_B.b_x);
    } else if (Controller_B.n == -1) {
      *x = sin(Controller_B.b_x);
    } else {
      *x = -cos(Controller_B.b_x);
    }
  }
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
  real_T tmp;
  real_T min;
  real_T max;
  int32_T i;

  // Start for S-Function (sdsprandsrc2): '<S15>/Random Source'
  // RandSrcCreateSeeds_64
  min = 0.0;
  max = 1.0;
  RandSrcInitState_U_64(&initSeed, Controller_B.state, 1);
  for (i = 0; i < numSeeds; i++) {
    Controller_RandSrc_U_D(&tmp, &min, 1, &max, 1, Controller_B.state, 1, 1);
    seedArray[i] = (uint32_T)(tmp * 2.147483648E+9);
  }

  // End of Start for S-Function (sdsprandsrc2): '<S15>/Random Source'
}

// Model step function
void ControllerModelClass::step()
{
  // Start for MATLABSystem: '<Root>/Get test' incorporates:
  //   MATLABSystem: '<Root>/Get test'

  Controller_B.p = false;
  Controller_B.p_n = true;
  if (!(Controller_DWork.obj_h2.SampleTime == Controller_P.Gettest_SampleTime))
  {
    Controller_B.p_n = false;
  }

  if (Controller_B.p_n) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_h2.SampleTime = Controller_P.Gettest_SampleTime;
  }

  ParamGet_Controller_823.get_parameter(&Controller_B.rtb_Gettest_b);

  // End of Start for MATLABSystem: '<Root>/Get test'

  // RelationalOperator: '<S1>/Compare' incorporates:
  //   Constant: '<S1>/Constant'
  //   MATLABSystem: '<Root>/Get test'

  Controller_B.Compare = (Controller_B.rtb_Gettest_b <=
    Controller_P.CompareToConstant_const);

  // Outputs for Enabled SubSystem: '<Root>/Telegraph' incorporates:
  //   EnablePort: '<S5>/Enable'

  if (Controller_B.Compare) {
    // S-Function (sdsprandsrc2): '<S15>/Random Source'
    Controller_RandSrc_U_D(&Controller_B.RandomSource,
      &Controller_P.RandomSource_MinVal, 1, &Controller_P.RandomSource_MaxVal, 1,
      Controller_DWork.RandomSource_STATE_DWORK, 1, 1);

    // Start for MATLABSystem: '<S15>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S15>/Swtiching factor'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_of.SampleTime ==
          Controller_P.Swtichingfactor_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_of.SampleTime =
        Controller_P.Swtichingfactor_SampleTime;
    }

    ParamGet_Controller_714.get_parameter(&Controller_B.rtb_Swtichingfactor_d_p);

    // End of Start for MATLABSystem: '<S15>/Swtiching factor'

    // State Transition Table: '<S15>/State Transition Table' incorporates:
    //   Constant: '<S15>/Constant'
    //   MATLABSystem: '<S15>/Swtiching factor'
    //   Sum: '<S15>/Add'

    Controller_StateTransitionTable((Controller_B.RandomSource + (real_T)
      Controller_B.rtb_Swtichingfactor_d_p) - Controller_P.Constant_Value_f,
      &Controller_B.sf_StateTransitionTable,
      &Controller_DWork.sf_StateTransitionTable);

    // Start for MATLABSystem: '<S15>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S15>/Swtiching factor1'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_fx.SampleTime ==
          Controller_P.Swtichingfactor1_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_fx.SampleTime =
        Controller_P.Swtichingfactor1_SampleTime;
    }

    ParamGet_Controller_715.get_parameter(&Controller_B.cfi);

    // End of Start for MATLABSystem: '<S15>/Swtiching factor1'

    // Start for MATLABSystem: '<S15>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S15>/Swtiching factor2'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_d3.SampleTime ==
          Controller_P.Swtichingfactor2_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_d3.SampleTime =
        Controller_P.Swtichingfactor2_SampleTime;
    }

    ParamGet_Controller_716.get_parameter(&Controller_B.spsi);

    // End of Start for MATLABSystem: '<S15>/Swtiching factor2'

    // MATLAB Function: '<S15>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S15>/Swtiching factor1'
    //   MATLABSystem: '<S15>/Swtiching factor2'

    Controller_MATLABFunction_a(Controller_B.sf_StateTransitionTable.u,
      Controller_B.cfi, Controller_B.spsi, &Controller_B.sf_MATLABFunction_a);

    // S-Function (sdsprandsrc2): '<S16>/Random Source'
    Controller_RandSrc_U_D(&Controller_B.RandomSource,
      &Controller_P.RandomSource_MinVal_h, 1,
      &Controller_P.RandomSource_MaxVal_o, 1,
      Controller_DWork.RandomSource_STATE_DWORK_i, 1, 1);

    // Start for MATLABSystem: '<S16>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S16>/Swtiching factor'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_i.SampleTime ==
          Controller_P.Swtichingfactor_SampleTime_k)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_i.SampleTime =
        Controller_P.Swtichingfactor_SampleTime_k;
    }

    ParamGet_Controller_724.get_parameter(&Controller_B.rtb_Swtichingfactor_d_p);

    // End of Start for MATLABSystem: '<S16>/Swtiching factor'

    // State Transition Table: '<S16>/State Transition Table' incorporates:
    //   Constant: '<S16>/Constant'
    //   MATLABSystem: '<S16>/Swtiching factor'
    //   Sum: '<S16>/Add'

    Controller_StateTransitionTable((Controller_B.RandomSource + (real_T)
      Controller_B.rtb_Swtichingfactor_d_p) - Controller_P.Constant_Value_k,
      &Controller_B.sf_StateTransitionTable_i,
      &Controller_DWork.sf_StateTransitionTable_i);

    // Start for MATLABSystem: '<S16>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S16>/Swtiching factor1'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_j5.SampleTime ==
          Controller_P.Swtichingfactor1_SampleTime_i)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_j5.SampleTime =
        Controller_P.Swtichingfactor1_SampleTime_i;
    }

    ParamGet_Controller_725.get_parameter(&Controller_B.cfi);

    // End of Start for MATLABSystem: '<S16>/Swtiching factor1'

    // Start for MATLABSystem: '<S16>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S16>/Swtiching factor2'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_fu.SampleTime ==
          Controller_P.Swtichingfactor2_SampleTime_b)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_fu.SampleTime =
        Controller_P.Swtichingfactor2_SampleTime_b;
    }

    ParamGet_Controller_726.get_parameter(&Controller_B.spsi);

    // End of Start for MATLABSystem: '<S16>/Swtiching factor2'

    // MATLAB Function: '<S16>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S16>/Swtiching factor1'
    //   MATLABSystem: '<S16>/Swtiching factor2'

    Controller_MATLABFunction_a(Controller_B.sf_StateTransitionTable_i.u,
      Controller_B.cfi, Controller_B.spsi, &Controller_B.sf_MATLABFunction_l);

    // S-Function (sdsprandsrc2): '<S17>/Random Source'
    Controller_RandSrc_U_D(&Controller_B.RandomSource,
      &Controller_P.RandomSource_MinVal_b, 1,
      &Controller_P.RandomSource_MaxVal_g, 1,
      Controller_DWork.RandomSource_STATE_DWORK_a, 1, 1);

    // Start for MATLABSystem: '<S17>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S17>/Swtiching factor'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_o.SampleTime ==
          Controller_P.Swtichingfactor_SampleTime_g)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_o.SampleTime =
        Controller_P.Swtichingfactor_SampleTime_g;
    }

    ParamGet_Controller_734.get_parameter(&Controller_B.rtb_Swtichingfactor_d_p);

    // End of Start for MATLABSystem: '<S17>/Swtiching factor'

    // State Transition Table: '<S17>/State Transition Table' incorporates:
    //   Constant: '<S17>/Constant'
    //   MATLABSystem: '<S17>/Swtiching factor'
    //   Sum: '<S17>/Add'

    Controller_StateTransitionTable((Controller_B.RandomSource + (real_T)
      Controller_B.rtb_Swtichingfactor_d_p) - Controller_P.Constant_Value_a,
      &Controller_B.sf_StateTransitionTable_m,
      &Controller_DWork.sf_StateTransitionTable_m);

    // Start for MATLABSystem: '<S17>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S17>/Swtiching factor1'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_f.SampleTime ==
          Controller_P.Swtichingfactor1_SampleTime_o)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_f.SampleTime =
        Controller_P.Swtichingfactor1_SampleTime_o;
    }

    ParamGet_Controller_735.get_parameter(&Controller_B.cfi);

    // End of Start for MATLABSystem: '<S17>/Swtiching factor1'

    // Start for MATLABSystem: '<S17>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S17>/Swtiching factor2'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_mb.SampleTime ==
          Controller_P.Swtichingfactor2_SampleTime_o)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_mb.SampleTime =
        Controller_P.Swtichingfactor2_SampleTime_o;
    }

    ParamGet_Controller_736.get_parameter(&Controller_B.spsi);

    // End of Start for MATLABSystem: '<S17>/Swtiching factor2'

    // MATLAB Function: '<S17>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S17>/Swtiching factor1'
    //   MATLABSystem: '<S17>/Swtiching factor2'

    Controller_MATLABFunction_a(Controller_B.sf_StateTransitionTable_m.u,
      Controller_B.cfi, Controller_B.spsi, &Controller_B.sf_MATLABFunction_j);

    // S-Function (sdsprandsrc2): '<S18>/Random Source'
    Controller_RandSrc_U_D(&Controller_B.RandomSource,
      &Controller_P.RandomSource_MinVal_d, 1,
      &Controller_P.RandomSource_MaxVal_d, 1,
      Controller_DWork.RandomSource_STATE_DWORK_g, 1, 1);

    // Start for MATLABSystem: '<S18>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S18>/Swtiching factor'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_gv.SampleTime ==
          Controller_P.Swtichingfactor_SampleTime_n)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_gv.SampleTime =
        Controller_P.Swtichingfactor_SampleTime_n;
    }

    ParamGet_Controller_744.get_parameter(&Controller_B.rtb_Swtichingfactor_d_p);

    // End of Start for MATLABSystem: '<S18>/Swtiching factor'

    // State Transition Table: '<S18>/State Transition Table' incorporates:
    //   Constant: '<S18>/Constant'
    //   MATLABSystem: '<S18>/Swtiching factor'
    //   Sum: '<S18>/Add'

    Controller_StateTransitionTable((Controller_B.RandomSource + (real_T)
      Controller_B.rtb_Swtichingfactor_d_p) - Controller_P.Constant_Value_a4,
      &Controller_B.sf_StateTransitionTable_mx,
      &Controller_DWork.sf_StateTransitionTable_mx);

    // Start for MATLABSystem: '<S18>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S18>/Swtiching factor1'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_c2.SampleTime ==
          Controller_P.Swtichingfactor1_SampleTime_j)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_c2.SampleTime =
        Controller_P.Swtichingfactor1_SampleTime_j;
    }

    ParamGet_Controller_745.get_parameter(&Controller_B.cfi);

    // End of Start for MATLABSystem: '<S18>/Swtiching factor1'

    // Start for MATLABSystem: '<S18>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S18>/Swtiching factor2'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_g0e.SampleTime ==
          Controller_P.Swtichingfactor2_SampleTime_e)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_g0e.SampleTime =
        Controller_P.Swtichingfactor2_SampleTime_e;
    }

    ParamGet_Controller_746.get_parameter(&Controller_B.spsi);

    // End of Start for MATLABSystem: '<S18>/Swtiching factor2'

    // MATLAB Function: '<S18>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S18>/Swtiching factor1'
    //   MATLABSystem: '<S18>/Swtiching factor2'

    Controller_MATLABFunction_a(Controller_B.sf_StateTransitionTable_mx.u,
      Controller_B.cfi, Controller_B.spsi, &Controller_B.sf_MATLABFunction_o);

    // S-Function (sdsprandsrc2): '<S19>/Random Source'
    Controller_RandSrc_U_D(&Controller_B.RandomSource,
      &Controller_P.RandomSource_MinVal_n, 1,
      &Controller_P.RandomSource_MaxVal_n, 1,
      Controller_DWork.RandomSource_STATE_DWORK_j, 1, 1);

    // Start for MATLABSystem: '<S19>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S19>/Swtiching factor'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_j0.SampleTime ==
          Controller_P.Swtichingfactor_SampleTime_nq)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_j0.SampleTime =
        Controller_P.Swtichingfactor_SampleTime_nq;
    }

    ParamGet_Controller_850.get_parameter(&Controller_B.rtb_Swtichingfactor_d_p);

    // End of Start for MATLABSystem: '<S19>/Swtiching factor'

    // State Transition Table: '<S19>/State Transition Table' incorporates:
    //   Constant: '<S19>/Constant'
    //   MATLABSystem: '<S19>/Swtiching factor'
    //   Sum: '<S19>/Add'

    Controller_StateTransitionTable((Controller_B.RandomSource + (real_T)
      Controller_B.rtb_Swtichingfactor_d_p) - Controller_P.Constant_Value_dg,
      &Controller_B.sf_StateTransitionTable_o,
      &Controller_DWork.sf_StateTransitionTable_o);

    // Start for MATLABSystem: '<S19>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S19>/Swtiching factor1'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_hr.SampleTime ==
          Controller_P.Swtichingfactor1_SampleTime_a)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_hr.SampleTime =
        Controller_P.Swtichingfactor1_SampleTime_a;
    }

    ParamGet_Controller_851.get_parameter(&Controller_B.cfi);

    // End of Start for MATLABSystem: '<S19>/Swtiching factor1'

    // Start for MATLABSystem: '<S19>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S19>/Swtiching factor2'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_dn.SampleTime ==
          Controller_P.Swtichingfactor2_SampleTime_n)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_dn.SampleTime =
        Controller_P.Swtichingfactor2_SampleTime_n;
    }

    ParamGet_Controller_852.get_parameter(&Controller_B.spsi);

    // End of Start for MATLABSystem: '<S19>/Swtiching factor2'

    // MATLAB Function: '<S19>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S19>/Swtiching factor1'
    //   MATLABSystem: '<S19>/Swtiching factor2'

    Controller_MATLABFunction_a(Controller_B.sf_StateTransitionTable_o.u,
      Controller_B.cfi, Controller_B.spsi, &Controller_B.sf_MATLABFunction_e);

    // S-Function (sdsprandsrc2): '<S20>/Random Source'
    Controller_RandSrc_U_D(&Controller_B.RandomSource,
      &Controller_P.RandomSource_MinVal_i, 1,
      &Controller_P.RandomSource_MaxVal_i, 1,
      Controller_DWork.RandomSource_STATE_DWORK_h, 1, 1);

    // Start for MATLABSystem: '<S20>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S20>/Swtiching factor'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_gf.SampleTime ==
          Controller_P.Swtichingfactor_SampleTime_f)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_gf.SampleTime =
        Controller_P.Swtichingfactor_SampleTime_f;
    }

    ParamGet_Controller_764.get_parameter(&Controller_B.rtb_Swtichingfactor_d_p);

    // End of Start for MATLABSystem: '<S20>/Swtiching factor'

    // State Transition Table: '<S20>/State Transition Table' incorporates:
    //   Constant: '<S20>/Constant'
    //   MATLABSystem: '<S20>/Swtiching factor'
    //   Sum: '<S20>/Add'

    Controller_StateTransitionTable((Controller_B.RandomSource + (real_T)
      Controller_B.rtb_Swtichingfactor_d_p) - Controller_P.Constant_Value_fo,
      &Controller_B.sf_StateTransitionTable_o2,
      &Controller_DWork.sf_StateTransitionTable_o2);

    // Start for MATLABSystem: '<S20>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S20>/Swtiching factor1'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_cvy.SampleTime ==
          Controller_P.Swtichingfactor1_SampleTime_e)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_cvy.SampleTime =
        Controller_P.Swtichingfactor1_SampleTime_e;
    }

    ParamGet_Controller_765.get_parameter(&Controller_B.cfi);

    // End of Start for MATLABSystem: '<S20>/Swtiching factor1'

    // Start for MATLABSystem: '<S20>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S20>/Swtiching factor2'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_dt.SampleTime ==
          Controller_P.Swtichingfactor2_SampleTime_c)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_dt.SampleTime =
        Controller_P.Swtichingfactor2_SampleTime_c;
    }

    ParamGet_Controller_766.get_parameter(&Controller_B.spsi);

    // End of Start for MATLABSystem: '<S20>/Swtiching factor2'

    // MATLAB Function: '<S20>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S20>/Swtiching factor1'
    //   MATLABSystem: '<S20>/Swtiching factor2'

    Controller_MATLABFunction_a(Controller_B.sf_StateTransitionTable_o2.u,
      Controller_B.cfi, Controller_B.spsi, &Controller_B.sf_MATLABFunction_i);

    // SignalConversion: '<S5>/OutportBufferForThrusters'
    Controller_B.OutportBufferForThrusters[0] =
      Controller_B.sf_MATLABFunction_a.y;
    Controller_B.OutportBufferForThrusters[1] =
      Controller_B.sf_MATLABFunction_l.y;
    Controller_B.OutportBufferForThrusters[2] =
      Controller_B.sf_MATLABFunction_j.y;
    Controller_B.OutportBufferForThrusters[3] =
      Controller_B.sf_MATLABFunction_o.y;
    Controller_B.OutportBufferForThrusters[4] =
      Controller_B.sf_MATLABFunction_e.y;
    Controller_B.OutportBufferForThrusters[5] =
      Controller_B.sf_MATLABFunction_i.y;
  }

  // End of Outputs for SubSystem: '<Root>/Telegraph'

  // Start for MATLABSystem: '<Root>/Get controller type' incorporates:
  //   MATLABSystem: '<Root>/Get controller type'

  Controller_B.p = false;
  Controller_B.p_n = true;
  if (!(Controller_DWork.obj_nl.SampleTime ==
        Controller_P.Getcontrollertype_SampleTime)) {
    Controller_B.p_n = false;
  }

  if (Controller_B.p_n) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_nl.SampleTime =
      Controller_P.Getcontrollertype_SampleTime;
  }

  ParamGet_Controller_106.get_parameter(&Controller_B.rtb_Swtichingfactor_d_p);

  // End of Start for MATLABSystem: '<Root>/Get controller type'

  // Outputs for Atomic SubSystem: '<Root>/cmd_vel'
  // Start for MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   MATLABSystem: '<S8>/SourceBlock'

  Controller_B.p = Sub_Controller_1.get_latest_msg(&Controller_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S33>/Enable'

  // MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Inport: '<S33>/In1'

  if (Controller_B.p) {
    Controller_B.In1_m = Controller_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/cmd_vel'

  // Outputs for Atomic SubSystem: '<Root>/imu_data'
  // Start for MATLABSystem: '<S10>/SourceBlock' incorporates:
  //   MATLABSystem: '<S10>/SourceBlock'

  Controller_B.p_n = Sub_Controller_28.get_latest_msg(&Controller_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S58>/Enable'

  // MATLABSystem: '<S10>/SourceBlock' incorporates:
  //   Inport: '<S58>/In1'

  if (Controller_B.p_n) {
    Controller_B.In1 = Controller_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/cmd_vel'
  // Logic: '<Root>/Logical Operator' incorporates:
  //   MATLABSystem: '<S10>/SourceBlock'
  //   MATLABSystem: '<S8>/SourceBlock'

  Controller_B.LogicalOperator = (Controller_B.p || Controller_B.p_n);

  // End of Outputs for SubSystem: '<Root>/cmd_vel'
  // End of Outputs for SubSystem: '<Root>/imu_data'

  // Outputs for Enabled SubSystem: '<Root>/Xbox_input' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (Controller_B.LogicalOperator) {
    // SignalConversion: '<S6>/TmpSignal ConversionAtBus SelectorOutport1'
    Controller_B.X_h = Controller_B.In1_m.Linear.X;

    // SignalConversion: '<S6>/TmpSignal ConversionAtBus SelectorOutport2'
    Controller_B.Y_i = Controller_B.In1_m.Linear.Y;

    // SignalConversion: '<S6>/TmpSignal ConversionAtBus SelectorOutport3'
    Controller_B.Z = Controller_B.In1_m.Linear.Z;

    // SignalConversion: '<S6>/TmpSignal ConversionAtBus SelectorOutport4'
    Controller_B.X_hw = Controller_B.In1_m.Angular.X;

    // SignalConversion: '<S6>/TmpSignal ConversionAtBus SelectorOutport5'
    Controller_B.Y_in = Controller_B.In1_m.Angular.Y;

    // SignalConversion: '<S6>/TmpSignal ConversionAtBus SelectorOutport6'
    Controller_B.Z_n = Controller_B.In1_m.Angular.Z;
  }

  // End of Outputs for SubSystem: '<Root>/Xbox_input'

  // Start for MATLABSystem: '<S3>/Get buoyancy' incorporates:
  //   MATLABSystem: '<S3>/Get buoyancy'

  Controller_B.p = false;
  Controller_B.p_n = true;
  if (!(Controller_DWork.obj_fe.SampleTime ==
        Controller_P.Getbuoyancy_SampleTime)) {
    Controller_B.p_n = false;
  }

  if (Controller_B.p_n) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_fe.SampleTime = Controller_P.Getbuoyancy_SampleTime;
  }

  ParamGet_Controller_879.get_parameter(&Controller_B.cfi);

  // End of Start for MATLABSystem: '<S3>/Get buoyancy'

  // MATLAB Function: '<S3>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S3>/Get buoyancy'

  Controller_MATLABFunction(Controller_B.X_hw, Controller_B.Y_in,
    Controller_B.Z_n, Controller_B.X_h, Controller_B.Y_i, Controller_B.Z,
    Controller_B.cfi, &Controller_B.sf_MATLABFunction);

  // Outputs for Enabled SubSystem: '<Root>/states' incorporates:
  //   EnablePort: '<S11>/Enable'

  if (Controller_B.LogicalOperator) {
    // MATLAB Function: '<S11>/removeGravity' incorporates:
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    // MATLAB Function 'states/removeGravity': '<S59>:1'
    //  rotmatrix = [2*w^2+2*x^2-1, 2*x*y-2*w*z, 2*x*z+2*w*y;
    //      2*x*y+2*w*z, 2*w^2+2*y^2-1, 2*x*z-2*w*x;
    //      2*x*z-2*w*y, 2*y*z+2*w*x, 2*w^2+2*z^2-1];
    // '<S59>:1:8'
    Controller_B.RandomSource = Controller_B.In1.Data[2];
    Controller_sind(&Controller_B.RandomSource);

    // '<S59>:1:9'
    Controller_B.cfi = Controller_B.In1.Data[2];
    Controller_cosd(&Controller_B.cfi);

    // '<S59>:1:10'
    Controller_B.spsi = Controller_B.In1.Data[0];
    Controller_sind(&Controller_B.spsi);

    // '<S59>:1:11'
    Controller_B.cpsi_c = Controller_B.In1.Data[0];
    Controller_cosd(&Controller_B.cpsi_c);

    // '<S59>:1:12'
    Controller_B.stheta = Controller_B.In1.Data[1];
    Controller_sind(&Controller_B.stheta);

    // '<S59>:1:13'
    Controller_B.ctheta = Controller_B.In1.Data[1];
    Controller_cosd(&Controller_B.ctheta);

    // '<S59>:1:16'
    //  Gravity projected in the body fixed frame
    // '<S59>:1:23'
    Controller_B.cpsi[0] = Controller_B.cpsi_c * Controller_B.ctheta;
    Controller_B.cpsi[1] = Controller_B.cpsi_c * Controller_B.stheta *
      Controller_B.RandomSource + -Controller_B.spsi * Controller_B.cfi;
    Controller_B.cpsi[2] = Controller_B.cpsi_c * Controller_B.cfi *
      Controller_B.stheta + Controller_B.spsi * Controller_B.RandomSource;
    Controller_B.cpsi[3] = Controller_B.spsi * Controller_B.ctheta;
    Controller_B.cpsi[4] = Controller_B.RandomSource * Controller_B.stheta *
      Controller_B.spsi + Controller_B.cpsi_c * Controller_B.cfi;
    Controller_B.cpsi[5] = Controller_B.stheta * Controller_B.spsi *
      Controller_B.cfi + -Controller_B.cpsi_c * Controller_B.RandomSource;
    Controller_B.cpsi[6] = -Controller_B.stheta;
    Controller_B.cpsi[7] = Controller_B.ctheta * Controller_B.RandomSource;
    Controller_B.cpsi[8] = Controller_B.ctheta * Controller_B.cfi;
    for (Controller_B.i = 0; Controller_B.i < 3; Controller_B.i++) {
      Controller_B.acc[Controller_B.i] = Controller_B.cpsi[Controller_B.i + 6] *
        9.8 + (Controller_B.cpsi[Controller_B.i + 3] * 0.0 +
               Controller_B.cpsi[Controller_B.i] * 0.0);
    }

    // SignalConversion: '<S11>/OutportBufferFor<acc X [m//s^2]>' incorporates:
    //   MATLAB Function: '<S11>/removeGravity'
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    //  Removed gravity from the acceleration
    // '<S59>:1:26'
    // '<S59>:1:27'
    // '<S59>:1:28'
    Controller_B.OutportBufferForaccXms2 = Controller_B.In1.Data[7] +
      Controller_B.acc[0];

    // SignalConversion: '<S11>/OutportBufferFor<acc Y [m//s^2]>' incorporates:
    //   MATLAB Function: '<S11>/removeGravity'
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_B.OutportBufferForaccYms2 = Controller_B.In1.Data[8] +
      Controller_B.acc[1];

    // SignalConversion: '<S11>/OutportBufferFor<acc Z [m//s^2]>' incorporates:
    //   MATLAB Function: '<S11>/removeGravity'
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_B.OutportBufferForaccZms2 = Controller_B.In1.Data[9] +
      Controller_B.acc[2];

    // SignalConversion: '<S11>/OutportBufferFor<angular_vel X [degrees//s]>' incorporates:
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_B.X = Controller_B.In1.Data[3];

    // SignalConversion: '<S11>/OutportBufferFor<angular_vel Y [degrees//s]>' incorporates:
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_B.Y = Controller_B.In1.Data[4];

    // SignalConversion: '<S11>/OutportBufferFor<angular_vel Z [degrees//s]>' incorporates:
    //   SignalConversion: '<S11>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_B.OutportBufferForangular_velZdeg = Controller_B.In1.Data[5];
  }

  // End of Outputs for SubSystem: '<Root>/states'

  // Start for MATLABSystem: '<S7>/Enable integration?' incorporates:
  //   MATLABSystem: '<S7>/Enable integration?'

  Controller_B.p = false;
  Controller_B.p_n = true;
  if (!(Controller_DWork.obj_g0.SampleTime ==
        Controller_P.Enableintegration_SampleTime)) {
    Controller_B.p_n = false;
  }

  if (Controller_B.p_n) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_g0.SampleTime =
      Controller_P.Enableintegration_SampleTime;
  }

  ParamGet_Controller_686.get_parameter(&Controller_B.p);

  // End of Start for MATLABSystem: '<S7>/Enable integration?'

  // DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S7>/Discrete-Time Integrator2'
  //   Logic: '<S7>/Logical Operator'
  //   MATLABSystem: '<S7>/Enable integration?'

  if (!Controller_B.p) {
    Controller_DWork.DiscreteTimeIntegrator_DSTATE =
      Controller_P.DiscreteTimeIntegrator_IC;
    Controller_DWork.DiscreteTimeIntegrator1_DSTATE =
      Controller_P.DiscreteTimeIntegrator1_IC;
    Controller_DWork.DiscreteTimeIntegrator2_DSTATE =
      Controller_P.DiscreteTimeIntegrator2_IC;
  }

  // Outputs for Enabled SubSystem: '<Root>/decController' incorporates:
  //   EnablePort: '<S9>/Enable'

  // Outputs for Enabled SubSystem: '<Root>/Create errors' incorporates:
  //   EnablePort: '<S2>/Enable'

  if (Controller_B.LogicalOperator) {
    // Sum: '<S2>/Error x'
    Controller_B.Errorx = Controller_B.X_hw - Controller_B.X;

    // Sum: '<S2>/Error y'
    Controller_B.Errory = Controller_B.Y_in - Controller_B.Y;

    // Sum: '<S2>/Error z'
    Controller_B.Errorz = Controller_B.Z_n -
      Controller_B.OutportBufferForangular_velZdeg;

    // Sum: '<S2>/Error z8' incorporates:
    //   DiscreteIntegrator: '<S7>/Discrete-Time Integrator'

    Controller_B.Errorz8 = Controller_B.X_h -
      Controller_DWork.DiscreteTimeIntegrator_DSTATE;

    // Sum: '<S2>/Error z9' incorporates:
    //   DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'

    Controller_B.Errorz9 = Controller_B.Y_i -
      Controller_DWork.DiscreteTimeIntegrator1_DSTATE;

    // Sum: '<S2>/Error z10' incorporates:
    //   DiscreteIntegrator: '<S7>/Discrete-Time Integrator2'

    Controller_B.Errorz10 = Controller_B.Z -
      Controller_DWork.DiscreteTimeIntegrator2_DSTATE;

    // Start for MATLABSystem: '<S41>/P_angular_vel_x' incorporates:
    //   MATLABSystem: '<S41>/P_angular_vel_x'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_bm.SampleTime ==
          Controller_P.P_angular_vel_x_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_bm.SampleTime =
        Controller_P.P_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_508.get_parameter(&Controller_B.cfi);

    // End of Start for MATLABSystem: '<S41>/P_angular_vel_x'

    // Start for MATLABSystem: '<S41>/D_angular_vel_x' incorporates:
    //   MATLABSystem: '<S41>/D_angular_vel_x'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_be.SampleTime ==
          Controller_P.D_angular_vel_x_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_be.SampleTime =
        Controller_P.D_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_505.get_parameter(&Controller_B.RandomSource);

    // End of Start for MATLABSystem: '<S41>/D_angular_vel_x'

    // Start for MATLABSystem: '<S41>/N_angular_vel_x ' incorporates:
    //   MATLABSystem: '<S41>/N_angular_vel_x '

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_lb.SampleTime ==
          Controller_P.N_angular_vel_x_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_lb.SampleTime =
        Controller_P.N_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_507.get_parameter(&Controller_B.spsi);

    // End of Start for MATLABSystem: '<S41>/N_angular_vel_x '

    // Product: '<S40>/NOut' incorporates:
    //   DiscreteIntegrator: '<S40>/Filter'
    //   MATLABSystem: '<S41>/D_angular_vel_x'
    //   MATLABSystem: '<S41>/N_angular_vel_x '
    //   Product: '<S40>/DOut'
    //   Sum: '<S40>/SumD'

    Controller_B.RandomSource = (Controller_B.Errorx * Controller_B.RandomSource
      - Controller_DWork.Filter_DSTATE) * Controller_B.spsi;

    // Sum: '<S40>/Sum' incorporates:
    //   DiscreteIntegrator: '<S40>/Integrator'
    //   MATLABSystem: '<S41>/P_angular_vel_x'
    //   Product: '<S40>/POut'

    Controller_B.SignPreIntegrator = (Controller_B.Errorx * Controller_B.cfi +
      Controller_DWork.Integrator_DSTATE) + Controller_B.RandomSource;

    // DeadZone: '<S42>/DeadZone'
    if (Controller_B.SignPreIntegrator >
        Controller_P.PIDController_UpperSaturationLi) {
      Controller_B.SumI1 = Controller_B.SignPreIntegrator -
        Controller_P.PIDController_UpperSaturationLi;
    } else if (Controller_B.SignPreIntegrator >=
               Controller_P.PIDController_LowerSaturationLi) {
      Controller_B.SumI1 = 0.0;
    } else {
      Controller_B.SumI1 = Controller_B.SignPreIntegrator -
        Controller_P.PIDController_LowerSaturationLi;
    }

    // End of DeadZone: '<S42>/DeadZone'

    // RelationalOperator: '<S42>/NotEqual' incorporates:
    //   Gain: '<S42>/ZeroGain'

    Controller_B.NotEqual = (Controller_P.ZeroGain_Gain *
      Controller_B.SignPreIntegrator != Controller_B.SumI1);

    // Signum: '<S42>/SignDeltaU'
    if (Controller_B.SumI1 < 0.0) {
      Controller_B.SumI1 = -1.0;
    } else if (Controller_B.SumI1 > 0.0) {
      Controller_B.SumI1 = 1.0;
    } else {
      if (Controller_B.SumI1 == 0.0) {
        Controller_B.SumI1 = 0.0;
      }
    }

    // End of Signum: '<S42>/SignDeltaU'

    // DataTypeConversion: '<S42>/DataTypeConv1'
    if (Controller_B.SumI1 < 128.0) {
      Controller_B.rtb_DataTypeConv2_f = (int8_T)Controller_B.SumI1;
    } else {
      Controller_B.rtb_DataTypeConv2_f = MAX_int8_T;
    }

    // Start for MATLABSystem: '<S41>/I_angular_vel_x' incorporates:
    //   MATLABSystem: '<S41>/I_angular_vel_x'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_pb.SampleTime ==
          Controller_P.I_angular_vel_x_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_pb.SampleTime =
        Controller_P.I_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_506.get_parameter(&Controller_B.cfi);

    // End of Start for MATLABSystem: '<S41>/I_angular_vel_x'

    // Saturate: '<S40>/Saturate'
    if (Controller_B.SignPreIntegrator >
        Controller_P.PIDController_UpperSaturationLi) {
      Controller_B.Saturate = Controller_P.PIDController_UpperSaturationLi;
    } else if (Controller_B.SignPreIntegrator <
               Controller_P.PIDController_LowerSaturationLi) {
      Controller_B.Saturate = Controller_P.PIDController_LowerSaturationLi;
    } else {
      Controller_B.Saturate = Controller_B.SignPreIntegrator;
    }

    // End of Saturate: '<S40>/Saturate'

    // Sum: '<S40>/SumI1' incorporates:
    //   Gain: '<S40>/Kt'
    //   MATLABSystem: '<S41>/I_angular_vel_x'
    //   Product: '<S40>/IOut'
    //   Sum: '<S40>/SumI3'

    Controller_B.SumI1 = (Controller_B.X_hw - Controller_B.Saturate) *
      Controller_P.PIDController_Kt + Controller_B.Errorx * Controller_B.cfi;

    // Signum: '<S42>/SignPreIntegrator'
    if (Controller_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S42>/DataTypeConv2'
      Controller_B.Switch_i = -1.0;
    } else if (Controller_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S42>/DataTypeConv2'
      Controller_B.Switch_i = 1.0;
    } else if (Controller_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S42>/DataTypeConv2'
      Controller_B.Switch_i = 0.0;
    } else {
      // DataTypeConversion: '<S42>/DataTypeConv2'
      Controller_B.Switch_i = Controller_B.SumI1;
    }

    // End of Signum: '<S42>/SignPreIntegrator'

    // DataTypeConversion: '<S42>/DataTypeConv2'
    if (Controller_B.Switch_i < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.Switch_i;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S40>/Switch' incorporates:
    //   Constant: '<S40>/Constant'
    //   DataTypeConversion: '<S42>/DataTypeConv1'
    //   Logic: '<S42>/AND'
    //   RelationalOperator: '<S42>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_f ==
         Controller_B.i0)) {
      Controller_B.cfi = Controller_P.Constant_Value_ke;
    } else {
      Controller_B.cfi = Controller_B.SumI1;
    }

    // End of Switch: '<S40>/Switch'

    // Start for MATLABSystem: '<S44>/P_angular_vel_y' incorporates:
    //   MATLABSystem: '<S44>/P_angular_vel_y'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_b.SampleTime ==
          Controller_P.P_angular_vel_y_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_b.SampleTime =
        Controller_P.P_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_522.get_parameter(&Controller_B.cpsi_c);

    // End of Start for MATLABSystem: '<S44>/P_angular_vel_y'

    // Start for MATLABSystem: '<S44>/D_angular_vel_y' incorporates:
    //   MATLABSystem: '<S44>/D_angular_vel_y'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_m.SampleTime ==
          Controller_P.D_angular_vel_y_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_m.SampleTime =
        Controller_P.D_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_519.get_parameter(&Controller_B.spsi);

    // End of Start for MATLABSystem: '<S44>/D_angular_vel_y'

    // Start for MATLABSystem: '<S44>/N_angular_vel_y ' incorporates:
    //   MATLABSystem: '<S44>/N_angular_vel_y '

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_dp.SampleTime ==
          Controller_P.N_angular_vel_y_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_dp.SampleTime =
        Controller_P.N_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_521.get_parameter(&Controller_B.stheta);

    // End of Start for MATLABSystem: '<S44>/N_angular_vel_y '

    // Product: '<S43>/NOut' incorporates:
    //   DiscreteIntegrator: '<S43>/Filter'
    //   MATLABSystem: '<S44>/D_angular_vel_y'
    //   MATLABSystem: '<S44>/N_angular_vel_y '
    //   Product: '<S43>/DOut'
    //   Sum: '<S43>/SumD'

    Controller_B.spsi = (Controller_B.Errory * Controller_B.spsi -
                         Controller_DWork.Filter_DSTATE_c) * Controller_B.stheta;

    // Sum: '<S43>/Sum' incorporates:
    //   DiscreteIntegrator: '<S43>/Integrator'
    //   MATLABSystem: '<S44>/P_angular_vel_y'
    //   Product: '<S43>/POut'

    Controller_B.SumI1 = (Controller_B.Errory * Controller_B.cpsi_c +
                          Controller_DWork.Integrator_DSTATE_h) +
      Controller_B.spsi;

    // DeadZone: '<S45>/DeadZone'
    if (Controller_B.SumI1 > Controller_P.PIDController_UpperSaturation_o) {
      Controller_B.SignPreIntegrator = Controller_B.SumI1 -
        Controller_P.PIDController_UpperSaturation_o;
    } else if (Controller_B.SumI1 >=
               Controller_P.PIDController_LowerSaturation_e) {
      Controller_B.SignPreIntegrator = 0.0;
    } else {
      Controller_B.SignPreIntegrator = Controller_B.SumI1 -
        Controller_P.PIDController_LowerSaturation_e;
    }

    // End of DeadZone: '<S45>/DeadZone'

    // RelationalOperator: '<S45>/NotEqual' incorporates:
    //   Gain: '<S45>/ZeroGain'

    Controller_B.NotEqual = (Controller_P.ZeroGain_Gain_k * Controller_B.SumI1
      != Controller_B.SignPreIntegrator);

    // Signum: '<S45>/SignDeltaU'
    if (Controller_B.SignPreIntegrator < 0.0) {
      Controller_B.SignPreIntegrator = -1.0;
    } else if (Controller_B.SignPreIntegrator > 0.0) {
      Controller_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_B.SignPreIntegrator == 0.0) {
        Controller_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S45>/SignDeltaU'

    // Start for MATLABSystem: '<S44>/I_angular_vel_y' incorporates:
    //   MATLABSystem: '<S44>/I_angular_vel_y'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_ep.SampleTime ==
          Controller_P.I_angular_vel_y_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_ep.SampleTime =
        Controller_P.I_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_520.get_parameter(&Controller_B.cpsi_c);

    // End of Start for MATLABSystem: '<S44>/I_angular_vel_y'

    // Saturate: '<S43>/Saturate'
    if (Controller_B.SumI1 > Controller_P.PIDController_UpperSaturation_o) {
      Controller_B.Saturate_f = Controller_P.PIDController_UpperSaturation_o;
    } else if (Controller_B.SumI1 < Controller_P.PIDController_LowerSaturation_e)
    {
      Controller_B.Saturate_f = Controller_P.PIDController_LowerSaturation_e;
    } else {
      Controller_B.Saturate_f = Controller_B.SumI1;
    }

    // End of Saturate: '<S43>/Saturate'

    // Sum: '<S43>/SumI1' incorporates:
    //   Gain: '<S43>/Kt'
    //   MATLABSystem: '<S44>/I_angular_vel_y'
    //   Product: '<S43>/IOut'
    //   Sum: '<S43>/SumI3'

    Controller_B.SumI1 = (Controller_B.Y_in - Controller_B.Saturate_f) *
      Controller_P.PIDController_Kt_j + Controller_B.Errory *
      Controller_B.cpsi_c;

    // Signum: '<S45>/SignPreIntegrator'
    if (Controller_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S45>/DataTypeConv2'
      Controller_B.Switch_i = -1.0;
    } else if (Controller_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S45>/DataTypeConv2'
      Controller_B.Switch_i = 1.0;
    } else if (Controller_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S45>/DataTypeConv2'
      Controller_B.Switch_i = 0.0;
    } else {
      // DataTypeConversion: '<S45>/DataTypeConv2'
      Controller_B.Switch_i = Controller_B.SumI1;
    }

    // End of Signum: '<S45>/SignPreIntegrator'

    // DataTypeConversion: '<S45>/DataTypeConv1'
    if (Controller_B.SignPreIntegrator < 128.0) {
      Controller_B.rtb_DataTypeConv2_f = (int8_T)Controller_B.SignPreIntegrator;
    } else {
      Controller_B.rtb_DataTypeConv2_f = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S45>/DataTypeConv1'

    // DataTypeConversion: '<S45>/DataTypeConv2'
    if (Controller_B.Switch_i < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.Switch_i;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S43>/Switch' incorporates:
    //   Constant: '<S43>/Constant'
    //   Logic: '<S45>/AND'
    //   RelationalOperator: '<S45>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_f ==
         Controller_B.i0)) {
      Controller_B.cpsi_c = Controller_P.Constant_Value_m;
    } else {
      Controller_B.cpsi_c = Controller_B.SumI1;
    }

    // End of Switch: '<S43>/Switch'

    // Start for MATLABSystem: '<S47>/P_angular_vel_z' incorporates:
    //   MATLABSystem: '<S47>/P_angular_vel_z'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_e.SampleTime ==
          Controller_P.P_angular_vel_z_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_e.SampleTime =
        Controller_P.P_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_536.get_parameter(&Controller_B.ctheta);

    // End of Start for MATLABSystem: '<S47>/P_angular_vel_z'

    // Start for MATLABSystem: '<S47>/D_angular_vel_z' incorporates:
    //   MATLABSystem: '<S47>/D_angular_vel_z'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_jg.SampleTime ==
          Controller_P.D_angular_vel_z_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_jg.SampleTime =
        Controller_P.D_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_533.get_parameter(&Controller_B.stheta);

    // End of Start for MATLABSystem: '<S47>/D_angular_vel_z'

    // Start for MATLABSystem: '<S47>/N_angular_vel_z ' incorporates:
    //   MATLABSystem: '<S47>/N_angular_vel_z '

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_g.SampleTime ==
          Controller_P.N_angular_vel_z_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_g.SampleTime =
        Controller_P.N_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_535.get_parameter(&Controller_B.NOut_b);

    // End of Start for MATLABSystem: '<S47>/N_angular_vel_z '

    // Product: '<S46>/NOut' incorporates:
    //   DiscreteIntegrator: '<S46>/Filter'
    //   MATLABSystem: '<S47>/D_angular_vel_z'
    //   MATLABSystem: '<S47>/N_angular_vel_z '
    //   Product: '<S46>/DOut'
    //   Sum: '<S46>/SumD'

    Controller_B.stheta = (Controller_B.Errorz * Controller_B.stheta -
      Controller_DWork.Filter_DSTATE_f) * Controller_B.NOut_b;

    // Sum: '<S46>/Sum' incorporates:
    //   DiscreteIntegrator: '<S46>/Integrator'
    //   MATLABSystem: '<S47>/P_angular_vel_z'
    //   Product: '<S46>/POut'

    Controller_B.SumI1 = (Controller_B.Errorz * Controller_B.ctheta +
                          Controller_DWork.Integrator_DSTATE_a) +
      Controller_B.stheta;

    // DeadZone: '<S48>/DeadZone'
    if (Controller_B.SumI1 > Controller_P.PIDController_UpperSaturation_e) {
      Controller_B.SignPreIntegrator = Controller_B.SumI1 -
        Controller_P.PIDController_UpperSaturation_e;
    } else if (Controller_B.SumI1 >=
               Controller_P.PIDController_LowerSaturation_p) {
      Controller_B.SignPreIntegrator = 0.0;
    } else {
      Controller_B.SignPreIntegrator = Controller_B.SumI1 -
        Controller_P.PIDController_LowerSaturation_p;
    }

    // End of DeadZone: '<S48>/DeadZone'

    // RelationalOperator: '<S48>/NotEqual' incorporates:
    //   Gain: '<S48>/ZeroGain'

    Controller_B.NotEqual = (Controller_P.ZeroGain_Gain_a * Controller_B.SumI1
      != Controller_B.SignPreIntegrator);

    // Signum: '<S48>/SignDeltaU'
    if (Controller_B.SignPreIntegrator < 0.0) {
      Controller_B.SignPreIntegrator = -1.0;
    } else if (Controller_B.SignPreIntegrator > 0.0) {
      Controller_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_B.SignPreIntegrator == 0.0) {
        Controller_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S48>/SignDeltaU'

    // Start for MATLABSystem: '<S47>/I_angular_vel_z' incorporates:
    //   MATLABSystem: '<S47>/I_angular_vel_z'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_p.SampleTime ==
          Controller_P.I_angular_vel_z_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_p.SampleTime =
        Controller_P.I_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_534.get_parameter(&Controller_B.ctheta);

    // End of Start for MATLABSystem: '<S47>/I_angular_vel_z'

    // Saturate: '<S46>/Saturate'
    if (Controller_B.SumI1 > Controller_P.PIDController_UpperSaturation_e) {
      Controller_B.Saturate_i = Controller_P.PIDController_UpperSaturation_e;
    } else if (Controller_B.SumI1 < Controller_P.PIDController_LowerSaturation_p)
    {
      Controller_B.Saturate_i = Controller_P.PIDController_LowerSaturation_p;
    } else {
      Controller_B.Saturate_i = Controller_B.SumI1;
    }

    // End of Saturate: '<S46>/Saturate'

    // Sum: '<S46>/SumI1' incorporates:
    //   Gain: '<S46>/Kt'
    //   MATLABSystem: '<S47>/I_angular_vel_z'
    //   Product: '<S46>/IOut'
    //   Sum: '<S46>/SumI3'

    Controller_B.SumI1 = (Controller_B.Z_n - Controller_B.Saturate_i) *
      Controller_P.PIDController_Kt_p + Controller_B.Errorz *
      Controller_B.ctheta;

    // Signum: '<S48>/SignPreIntegrator'
    if (Controller_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S48>/DataTypeConv2'
      Controller_B.Switch_i = -1.0;
    } else if (Controller_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S48>/DataTypeConv2'
      Controller_B.Switch_i = 1.0;
    } else if (Controller_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S48>/DataTypeConv2'
      Controller_B.Switch_i = 0.0;
    } else {
      // DataTypeConversion: '<S48>/DataTypeConv2'
      Controller_B.Switch_i = Controller_B.SumI1;
    }

    // End of Signum: '<S48>/SignPreIntegrator'

    // DataTypeConversion: '<S48>/DataTypeConv1'
    if (Controller_B.SignPreIntegrator < 128.0) {
      Controller_B.rtb_DataTypeConv2_f = (int8_T)Controller_B.SignPreIntegrator;
    } else {
      Controller_B.rtb_DataTypeConv2_f = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S48>/DataTypeConv1'

    // DataTypeConversion: '<S48>/DataTypeConv2'
    if (Controller_B.Switch_i < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.Switch_i;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S46>/Switch' incorporates:
    //   Constant: '<S46>/Constant'
    //   Logic: '<S48>/AND'
    //   RelationalOperator: '<S48>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_f ==
         Controller_B.i0)) {
      Controller_B.ctheta = Controller_P.Constant_Value_fw;
    } else {
      Controller_B.ctheta = Controller_B.SumI1;
    }

    // End of Switch: '<S46>/Switch'

    // Start for MATLABSystem: '<S50>/P_vel_x' incorporates:
    //   MATLABSystem: '<S50>/P_vel_x'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_ns.SampleTime == Controller_P.P_vel_x_SampleTime))
    {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_ns.SampleTime = Controller_P.P_vel_x_SampleTime;
    }

    ParamGet_Controller_550.get_parameter(&Controller_B.Switch_e);

    // End of Start for MATLABSystem: '<S50>/P_vel_x'

    // Start for MATLABSystem: '<S50>/D_vel_x' incorporates:
    //   MATLABSystem: '<S50>/D_vel_x'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_d.SampleTime == Controller_P.D_vel_x_SampleTime))
    {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_d.SampleTime = Controller_P.D_vel_x_SampleTime;
    }

    ParamGet_Controller_547.get_parameter(&Controller_B.NOut_b);

    // End of Start for MATLABSystem: '<S50>/D_vel_x'

    // Start for MATLABSystem: '<S50>/N_vel_x ' incorporates:
    //   MATLABSystem: '<S50>/N_vel_x '

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_a3.SampleTime == Controller_P.N_vel_x_SampleTime))
    {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_a3.SampleTime = Controller_P.N_vel_x_SampleTime;
    }

    ParamGet_Controller_549.get_parameter(&Controller_B.SignPreIntegrator);

    // End of Start for MATLABSystem: '<S50>/N_vel_x '

    // Product: '<S49>/NOut' incorporates:
    //   DiscreteIntegrator: '<S49>/Filter'
    //   MATLABSystem: '<S50>/D_vel_x'
    //   MATLABSystem: '<S50>/N_vel_x '
    //   Product: '<S49>/DOut'
    //   Sum: '<S49>/SumD'

    Controller_B.NOut_b = (Controller_B.Errorz8 * Controller_B.NOut_b -
      Controller_DWork.Filter_DSTATE_a) * Controller_B.SignPreIntegrator;

    // Sum: '<S49>/Sum' incorporates:
    //   DiscreteIntegrator: '<S49>/Integrator'
    //   MATLABSystem: '<S50>/P_vel_x'
    //   Product: '<S49>/POut'

    Controller_B.SumI1 = (Controller_B.Errorz8 * Controller_B.Switch_e +
                          Controller_DWork.Integrator_DSTATE_f) +
      Controller_B.NOut_b;

    // DeadZone: '<S51>/DeadZone'
    if (Controller_B.SumI1 > Controller_P.PIDController_UpperSaturation_d) {
      Controller_B.SignPreIntegrator = Controller_B.SumI1 -
        Controller_P.PIDController_UpperSaturation_d;
    } else if (Controller_B.SumI1 >=
               Controller_P.PIDController_LowerSaturation_i) {
      Controller_B.SignPreIntegrator = 0.0;
    } else {
      Controller_B.SignPreIntegrator = Controller_B.SumI1 -
        Controller_P.PIDController_LowerSaturation_i;
    }

    // End of DeadZone: '<S51>/DeadZone'

    // RelationalOperator: '<S51>/NotEqual' incorporates:
    //   Gain: '<S51>/ZeroGain'

    Controller_B.NotEqual = (Controller_P.ZeroGain_Gain_j * Controller_B.SumI1
      != Controller_B.SignPreIntegrator);

    // Signum: '<S51>/SignDeltaU'
    if (Controller_B.SignPreIntegrator < 0.0) {
      Controller_B.SignPreIntegrator = -1.0;
    } else if (Controller_B.SignPreIntegrator > 0.0) {
      Controller_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_B.SignPreIntegrator == 0.0) {
        Controller_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S51>/SignDeltaU'

    // Start for MATLABSystem: '<S50>/I_vel_x' incorporates:
    //   MATLABSystem: '<S50>/I_vel_x'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_cv.SampleTime == Controller_P.I_vel_x_SampleTime))
    {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_cv.SampleTime = Controller_P.I_vel_x_SampleTime;
    }

    ParamGet_Controller_548.get_parameter(&Controller_B.Switch_e);

    // End of Start for MATLABSystem: '<S50>/I_vel_x'

    // Saturate: '<S49>/Saturate'
    if (Controller_B.SumI1 > Controller_P.PIDController_UpperSaturation_d) {
      Controller_B.Saturate_b = Controller_P.PIDController_UpperSaturation_d;
    } else if (Controller_B.SumI1 < Controller_P.PIDController_LowerSaturation_i)
    {
      Controller_B.Saturate_b = Controller_P.PIDController_LowerSaturation_i;
    } else {
      Controller_B.Saturate_b = Controller_B.SumI1;
    }

    // End of Saturate: '<S49>/Saturate'

    // Sum: '<S49>/SumI1' incorporates:
    //   Gain: '<S49>/Kt'
    //   MATLABSystem: '<S50>/I_vel_x'
    //   Product: '<S49>/IOut'
    //   Sum: '<S49>/SumI3'

    Controller_B.SumI1 = (Controller_B.X_h - Controller_B.Saturate_b) *
      Controller_P.PIDController_Kt_jw + Controller_B.Errorz8 *
      Controller_B.Switch_e;

    // Signum: '<S51>/SignPreIntegrator'
    if (Controller_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S51>/DataTypeConv2'
      Controller_B.Switch_i = -1.0;
    } else if (Controller_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S51>/DataTypeConv2'
      Controller_B.Switch_i = 1.0;
    } else if (Controller_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S51>/DataTypeConv2'
      Controller_B.Switch_i = 0.0;
    } else {
      // DataTypeConversion: '<S51>/DataTypeConv2'
      Controller_B.Switch_i = Controller_B.SumI1;
    }

    // End of Signum: '<S51>/SignPreIntegrator'

    // DataTypeConversion: '<S51>/DataTypeConv1'
    if (Controller_B.SignPreIntegrator < 128.0) {
      Controller_B.rtb_DataTypeConv2_f = (int8_T)Controller_B.SignPreIntegrator;
    } else {
      Controller_B.rtb_DataTypeConv2_f = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S51>/DataTypeConv1'

    // DataTypeConversion: '<S51>/DataTypeConv2'
    if (Controller_B.Switch_i < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.Switch_i;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S49>/Switch' incorporates:
    //   Constant: '<S49>/Constant'
    //   Logic: '<S51>/AND'
    //   RelationalOperator: '<S51>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_f ==
         Controller_B.i0)) {
      Controller_B.Switch_e = Controller_P.Constant_Value_m0;
    } else {
      Controller_B.Switch_e = Controller_B.SumI1;
    }

    // End of Switch: '<S49>/Switch'

    // Start for MATLABSystem: '<S53>/P_vel_y' incorporates:
    //   MATLABSystem: '<S53>/P_vel_y'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_ji.SampleTime == Controller_P.P_vel_y_SampleTime))
    {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_ji.SampleTime = Controller_P.P_vel_y_SampleTime;
    }

    ParamGet_Controller_564.get_parameter(&Controller_B.SignPreIntegrator);

    // End of Start for MATLABSystem: '<S53>/P_vel_y'

    // Start for MATLABSystem: '<S53>/D_vel_y' incorporates:
    //   MATLABSystem: '<S53>/D_vel_y'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_ny.SampleTime == Controller_P.D_vel_y_SampleTime))
    {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_ny.SampleTime = Controller_P.D_vel_y_SampleTime;
    }

    ParamGet_Controller_561.get_parameter(&Controller_B.NOut_i);

    // End of Start for MATLABSystem: '<S53>/D_vel_y'

    // Start for MATLABSystem: '<S53>/N_vel_y ' incorporates:
    //   MATLABSystem: '<S53>/N_vel_y '

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_cb.SampleTime == Controller_P.N_vel_y_SampleTime))
    {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_cb.SampleTime = Controller_P.N_vel_y_SampleTime;
    }

    ParamGet_Controller_563.get_parameter(&Controller_B.SumI1);

    // End of Start for MATLABSystem: '<S53>/N_vel_y '

    // Product: '<S52>/NOut' incorporates:
    //   DiscreteIntegrator: '<S52>/Filter'
    //   MATLABSystem: '<S53>/D_vel_y'
    //   MATLABSystem: '<S53>/N_vel_y '
    //   Product: '<S52>/DOut'
    //   Sum: '<S52>/SumD'

    Controller_B.NOut_i = (Controller_B.Errorz9 * Controller_B.NOut_i -
      Controller_DWork.Filter_DSTATE_g) * Controller_B.SumI1;

    // Sum: '<S52>/Sum' incorporates:
    //   DiscreteIntegrator: '<S52>/Integrator'
    //   MATLABSystem: '<S53>/P_vel_y'
    //   Product: '<S52>/POut'

    Controller_B.SumI1 = (Controller_B.Errorz9 * Controller_B.SignPreIntegrator
                          + Controller_DWork.Integrator_DSTATE_n) +
      Controller_B.NOut_i;

    // DeadZone: '<S54>/DeadZone'
    if (Controller_B.SumI1 > Controller_P.PIDController_UpperSaturation_b) {
      Controller_B.SignPreIntegrator = Controller_B.SumI1 -
        Controller_P.PIDController_UpperSaturation_b;
    } else if (Controller_B.SumI1 >=
               Controller_P.PIDController_LowerSaturation_g) {
      Controller_B.SignPreIntegrator = 0.0;
    } else {
      Controller_B.SignPreIntegrator = Controller_B.SumI1 -
        Controller_P.PIDController_LowerSaturation_g;
    }

    // End of DeadZone: '<S54>/DeadZone'

    // RelationalOperator: '<S54>/NotEqual' incorporates:
    //   Gain: '<S54>/ZeroGain'

    Controller_B.NotEqual = (Controller_P.ZeroGain_Gain_jk * Controller_B.SumI1
      != Controller_B.SignPreIntegrator);

    // Signum: '<S54>/SignDeltaU'
    if (Controller_B.SignPreIntegrator < 0.0) {
      Controller_B.SignPreIntegrator = -1.0;
    } else if (Controller_B.SignPreIntegrator > 0.0) {
      Controller_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_B.SignPreIntegrator == 0.0) {
        Controller_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S54>/SignDeltaU'

    // Start for MATLABSystem: '<S53>/I_vel_y' incorporates:
    //   MATLABSystem: '<S53>/I_vel_y'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_jx.SampleTime == Controller_P.I_vel_y_SampleTime))
    {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_jx.SampleTime = Controller_P.I_vel_y_SampleTime;
    }

    ParamGet_Controller_562.get_parameter(&Controller_B.Switch_i);

    // End of Start for MATLABSystem: '<S53>/I_vel_y'

    // Saturate: '<S52>/Saturate'
    if (Controller_B.SumI1 > Controller_P.PIDController_UpperSaturation_b) {
      Controller_B.Saturate_h = Controller_P.PIDController_UpperSaturation_b;
    } else if (Controller_B.SumI1 < Controller_P.PIDController_LowerSaturation_g)
    {
      Controller_B.Saturate_h = Controller_P.PIDController_LowerSaturation_g;
    } else {
      Controller_B.Saturate_h = Controller_B.SumI1;
    }

    // End of Saturate: '<S52>/Saturate'

    // Sum: '<S52>/SumI1' incorporates:
    //   Gain: '<S52>/Kt'
    //   MATLABSystem: '<S53>/I_vel_y'
    //   Product: '<S52>/IOut'
    //   Sum: '<S52>/SumI3'

    Controller_B.SumI1 = (Controller_B.Y_i - Controller_B.Saturate_h) *
      Controller_P.PIDController_Kt_c + Controller_B.Errorz9 *
      Controller_B.Switch_i;

    // Signum: '<S54>/SignPreIntegrator'
    if (Controller_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S54>/DataTypeConv2'
      Controller_B.Switch_i = -1.0;
    } else if (Controller_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S54>/DataTypeConv2'
      Controller_B.Switch_i = 1.0;
    } else if (Controller_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S54>/DataTypeConv2'
      Controller_B.Switch_i = 0.0;
    } else {
      // DataTypeConversion: '<S54>/DataTypeConv2'
      Controller_B.Switch_i = Controller_B.SumI1;
    }

    // End of Signum: '<S54>/SignPreIntegrator'

    // DataTypeConversion: '<S54>/DataTypeConv1'
    if (Controller_B.SignPreIntegrator < 128.0) {
      Controller_B.rtb_DataTypeConv2_f = (int8_T)Controller_B.SignPreIntegrator;
    } else {
      Controller_B.rtb_DataTypeConv2_f = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S54>/DataTypeConv1'

    // DataTypeConversion: '<S54>/DataTypeConv2'
    if (Controller_B.Switch_i < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.Switch_i;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S52>/Switch' incorporates:
    //   Constant: '<S52>/Constant'
    //   Logic: '<S54>/AND'
    //   RelationalOperator: '<S54>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_f ==
         Controller_B.i0)) {
      Controller_B.Switch_i = Controller_P.Constant_Value_p;
    } else {
      Controller_B.Switch_i = Controller_B.SumI1;
    }

    // End of Switch: '<S52>/Switch'

    // Start for MATLABSystem: '<S56>/P_vel_z' incorporates:
    //   MATLABSystem: '<S56>/P_vel_z'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_j.SampleTime == Controller_P.P_vel_z_SampleTime))
    {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_j.SampleTime = Controller_P.P_vel_z_SampleTime;
    }

    ParamGet_Controller_578.get_parameter(&Controller_B.SignPreIntegrator);

    // End of Start for MATLABSystem: '<S56>/P_vel_z'

    // Start for MATLABSystem: '<S56>/D_vel_z' incorporates:
    //   MATLABSystem: '<S56>/D_vel_z'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_a.SampleTime == Controller_P.D_vel_z_SampleTime))
    {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_a.SampleTime = Controller_P.D_vel_z_SampleTime;
    }

    ParamGet_Controller_575.get_parameter(&Controller_B.SumI1);

    // End of Start for MATLABSystem: '<S56>/D_vel_z'

    // Start for MATLABSystem: '<S56>/N_vel_z ' incorporates:
    //   MATLABSystem: '<S56>/N_vel_z '

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_h.SampleTime == Controller_P.N_vel_z_SampleTime))
    {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_h.SampleTime = Controller_P.N_vel_z_SampleTime;
    }

    ParamGet_Controller_577.get_parameter(&Controller_B.NOut_d);

    // End of Start for MATLABSystem: '<S56>/N_vel_z '

    // Product: '<S55>/NOut' incorporates:
    //   DiscreteIntegrator: '<S55>/Filter'
    //   MATLABSystem: '<S56>/D_vel_z'
    //   MATLABSystem: '<S56>/N_vel_z '
    //   Product: '<S55>/DOut'
    //   Sum: '<S55>/SumD'

    Controller_B.NOut_d *= Controller_B.Errorz10 * Controller_B.SumI1 -
      Controller_DWork.Filter_DSTATE_cw;

    // Sum: '<S55>/Sum' incorporates:
    //   DiscreteIntegrator: '<S55>/Integrator'
    //   MATLABSystem: '<S56>/P_vel_z'
    //   Product: '<S55>/POut'

    Controller_B.SumI1 = (Controller_B.Errorz10 * Controller_B.SignPreIntegrator
                          + Controller_DWork.Integrator_DSTATE_ny) +
      Controller_B.NOut_d;

    // DeadZone: '<S57>/DeadZone'
    if (Controller_B.SumI1 > Controller_P.PIDController_UpperSaturatio_ba) {
      Controller_B.SignPreIntegrator = Controller_B.SumI1 -
        Controller_P.PIDController_UpperSaturatio_ba;
    } else if (Controller_B.SumI1 >=
               Controller_P.PIDController_LowerSaturatio_pm) {
      Controller_B.SignPreIntegrator = 0.0;
    } else {
      Controller_B.SignPreIntegrator = Controller_B.SumI1 -
        Controller_P.PIDController_LowerSaturatio_pm;
    }

    // End of DeadZone: '<S57>/DeadZone'

    // RelationalOperator: '<S57>/NotEqual' incorporates:
    //   Gain: '<S57>/ZeroGain'

    Controller_B.NotEqual = (Controller_P.ZeroGain_Gain_p * Controller_B.SumI1
      != Controller_B.SignPreIntegrator);

    // Signum: '<S57>/SignDeltaU'
    if (Controller_B.SignPreIntegrator < 0.0) {
      Controller_B.SignPreIntegrator = -1.0;
    } else if (Controller_B.SignPreIntegrator > 0.0) {
      Controller_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_B.SignPreIntegrator == 0.0) {
        Controller_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S57>/SignDeltaU'

    // Start for MATLABSystem: '<S56>/I_vel_z' incorporates:
    //   MATLABSystem: '<S56>/I_vel_z'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_js.SampleTime == Controller_P.I_vel_z_SampleTime))
    {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_js.SampleTime = Controller_P.I_vel_z_SampleTime;
    }

    ParamGet_Controller_576.get_parameter(&Controller_B.rtb_I_vel_z_k);

    // End of Start for MATLABSystem: '<S56>/I_vel_z'

    // Saturate: '<S55>/Saturate'
    if (Controller_B.SumI1 > Controller_P.PIDController_UpperSaturatio_ba) {
      Controller_B.Saturate_bk = Controller_P.PIDController_UpperSaturatio_ba;
    } else if (Controller_B.SumI1 < Controller_P.PIDController_LowerSaturatio_pm)
    {
      Controller_B.Saturate_bk = Controller_P.PIDController_LowerSaturatio_pm;
    } else {
      Controller_B.Saturate_bk = Controller_B.SumI1;
    }

    // End of Saturate: '<S55>/Saturate'

    // Sum: '<S55>/SumI1' incorporates:
    //   Gain: '<S55>/Kt'
    //   MATLABSystem: '<S56>/I_vel_z'
    //   Product: '<S55>/IOut'
    //   Sum: '<S55>/SumI3'

    Controller_B.SumI1 = (Controller_B.Z - Controller_B.Saturate_bk) *
      Controller_P.PIDController_Kt_l + Controller_B.Errorz10 *
      Controller_B.rtb_I_vel_z_k;

    // Update for DiscreteIntegrator: '<S40>/Integrator'
    Controller_DWork.Integrator_DSTATE += Controller_P.Integrator_gainval *
      Controller_B.cfi;

    // Update for DiscreteIntegrator: '<S40>/Filter'
    Controller_DWork.Filter_DSTATE += Controller_P.Filter_gainval *
      Controller_B.RandomSource;

    // Update for DiscreteIntegrator: '<S43>/Integrator'
    Controller_DWork.Integrator_DSTATE_h += Controller_P.Integrator_gainval_c *
      Controller_B.cpsi_c;

    // Update for DiscreteIntegrator: '<S43>/Filter'
    Controller_DWork.Filter_DSTATE_c += Controller_P.Filter_gainval_i *
      Controller_B.spsi;

    // Update for DiscreteIntegrator: '<S46>/Integrator'
    Controller_DWork.Integrator_DSTATE_a += Controller_P.Integrator_gainval_n *
      Controller_B.ctheta;

    // Update for DiscreteIntegrator: '<S46>/Filter'
    Controller_DWork.Filter_DSTATE_f += Controller_P.Filter_gainval_k *
      Controller_B.stheta;

    // Update for DiscreteIntegrator: '<S49>/Integrator'
    Controller_DWork.Integrator_DSTATE_f += Controller_P.Integrator_gainval_j *
      Controller_B.Switch_e;

    // Update for DiscreteIntegrator: '<S49>/Filter'
    Controller_DWork.Filter_DSTATE_a += Controller_P.Filter_gainval_h *
      Controller_B.NOut_b;

    // Update for DiscreteIntegrator: '<S52>/Integrator'
    Controller_DWork.Integrator_DSTATE_n += Controller_P.Integrator_gainval_np *
      Controller_B.Switch_i;

    // Update for DiscreteIntegrator: '<S52>/Filter'
    Controller_DWork.Filter_DSTATE_g += Controller_P.Filter_gainval_h0 *
      Controller_B.NOut_i;

    // Signum: '<S57>/SignPreIntegrator'
    if (Controller_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S57>/DataTypeConv2'
      Controller_B.Switch_i = -1.0;
    } else if (Controller_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S57>/DataTypeConv2'
      Controller_B.Switch_i = 1.0;
    } else if (Controller_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S57>/DataTypeConv2'
      Controller_B.Switch_i = 0.0;
    } else {
      // DataTypeConversion: '<S57>/DataTypeConv2'
      Controller_B.Switch_i = Controller_B.SumI1;
    }

    // End of Signum: '<S57>/SignPreIntegrator'

    // DataTypeConversion: '<S57>/DataTypeConv1'
    if (Controller_B.SignPreIntegrator < 128.0) {
      Controller_B.rtb_DataTypeConv2_f = (int8_T)Controller_B.SignPreIntegrator;
    } else {
      Controller_B.rtb_DataTypeConv2_f = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S57>/DataTypeConv1'

    // DataTypeConversion: '<S57>/DataTypeConv2'
    if (Controller_B.Switch_i < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.Switch_i;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S55>/Switch' incorporates:
    //   Constant: '<S55>/Constant'
    //   Logic: '<S57>/AND'
    //   RelationalOperator: '<S57>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_f ==
         Controller_B.i0)) {
      Controller_B.SumI1 = Controller_P.Constant_Value_l;
    }

    // End of Switch: '<S55>/Switch'

    // Update for DiscreteIntegrator: '<S55>/Integrator'
    Controller_DWork.Integrator_DSTATE_ny += Controller_P.Integrator_gainval_m *
      Controller_B.SumI1;

    // Update for DiscreteIntegrator: '<S55>/Filter'
    Controller_DWork.Filter_DSTATE_cw += Controller_P.Filter_gainval_b *
      Controller_B.NOut_d;
  }

  // End of Outputs for SubSystem: '<Root>/Create errors'
  // End of Outputs for SubSystem: '<Root>/decController'

  // Start for MATLABSystem: '<S4>/Get buoyancy' incorporates:
  //   MATLABSystem: '<S4>/Get buoyancy'

  Controller_B.p = false;
  Controller_B.p_n = true;
  if (!(Controller_DWork.obj_l0.SampleTime ==
        Controller_P.Getbuoyancy_SampleTime_l)) {
    Controller_B.p_n = false;
  }

  if (Controller_B.p_n) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_l0.SampleTime = Controller_P.Getbuoyancy_SampleTime_l;
  }

  ParamGet_Controller_873.get_parameter(&Controller_B.cfi);

  // End of Start for MATLABSystem: '<S4>/Get buoyancy'

  // MATLAB Function: '<S4>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S4>/Get buoyancy'

  Controller_MATLABFunction(Controller_B.Saturate, Controller_B.Saturate_f,
    Controller_B.Saturate_i, Controller_B.Saturate_b, Controller_B.Saturate_h,
    Controller_B.Saturate_bk, Controller_B.cfi,
    &Controller_B.sf_MATLABFunction_b);
  for (Controller_B.i = 0; Controller_B.i < 6; Controller_B.i++) {
    // MultiPortSwitch: '<Root>/Choose Controller or test' incorporates:
    //   MATLABSystem: '<Root>/Get test'

    if (Controller_B.rtb_Gettest_b == 0) {
      Controller_B.ChooseControllersignal[Controller_B.i] =
        Controller_B.OutportBufferForThrusters[Controller_B.i];
    } else {
      // MultiPortSwitch: '<Root>/Choose Controller signal' incorporates:
      //   Constant: '<Root>/Constant4'
      //   MATLABSystem: '<Root>/Get controller type'

      switch (Controller_B.rtb_Swtichingfactor_d_p) {
       case 0:
        Controller_B.ChooseControllersignal[Controller_B.i] =
          Controller_B.sf_MATLABFunction.thrusters[Controller_B.i];
        break;

       case 1:
        Controller_B.ChooseControllersignal[Controller_B.i] =
          Controller_B.sf_MATLABFunction_b.thrusters[Controller_B.i];
        break;

       default:
        Controller_B.ChooseControllersignal[Controller_B.i] =
          Controller_P.Constant4_Value[Controller_B.i];
        break;
      }

      // End of MultiPortSwitch: '<Root>/Choose Controller signal'
    }

    // End of MultiPortSwitch: '<Root>/Choose Controller or test'
  }

  // Outputs for Enabled SubSystem: '<Root>/toPWM' incorporates:
  //   EnablePort: '<S12>/Enable'

  // Logic: '<Root>/Logical Operator1'
  if (Controller_B.Compare || Controller_B.LogicalOperator) {
    // Start for MATLABSystem: '<S62>/Get Parameter' incorporates:
    //   MATLABSystem: '<S62>/Get Parameter'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj.SampleTime ==
          Controller_P.GetParameter_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj.SampleTime = Controller_P.GetParameter_SampleTime;
    }

    ParamGet_Controller_858.get_parameter(&Controller_B.Compare);

    // End of Start for MATLABSystem: '<S62>/Get Parameter'

    // Start for MATLABSystem: '<S62>/Get Parameter1' incorporates:
    //   MATLABSystem: '<S62>/Get Parameter1'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_l.SampleTime ==
          Controller_P.GetParameter1_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_l.SampleTime = Controller_P.GetParameter1_SampleTime;
    }

    ParamGet_Controller_861.get_parameter(&Controller_B.LogicalOperator);

    // End of Start for MATLABSystem: '<S62>/Get Parameter1'

    // Start for MATLABSystem: '<S62>/Get Parameter2' incorporates:
    //   MATLABSystem: '<S62>/Get Parameter2'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_n.SampleTime ==
          Controller_P.GetParameter2_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_n.SampleTime = Controller_P.GetParameter2_SampleTime;
    }

    ParamGet_Controller_862.get_parameter(&Controller_B.NotEqual);

    // End of Start for MATLABSystem: '<S62>/Get Parameter2'

    // Start for MATLABSystem: '<S62>/Get Parameter3' incorporates:
    //   MATLABSystem: '<S62>/Get Parameter3'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_c.SampleTime ==
          Controller_P.GetParameter3_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_c.SampleTime = Controller_P.GetParameter3_SampleTime;
    }

    ParamGet_Controller_863.get_parameter(&Controller_B.rtb_GetParameter3_g);

    // End of Start for MATLABSystem: '<S62>/Get Parameter3'

    // Start for MATLABSystem: '<S62>/Get Parameter4' incorporates:
    //   MATLABSystem: '<S62>/Get Parameter4'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_nt.SampleTime ==
          Controller_P.GetParameter4_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_nt.SampleTime = Controller_P.GetParameter4_SampleTime;
    }

    ParamGet_Controller_864.get_parameter(&Controller_B.rtb_GetParameter4_m);

    // End of Start for MATLABSystem: '<S62>/Get Parameter4'

    // Start for MATLABSystem: '<S62>/Get Parameter5' incorporates:
    //   MATLABSystem: '<S62>/Get Parameter5'

    Controller_B.p = false;
    Controller_B.p_n = true;
    if (!(Controller_DWork.obj_ls.SampleTime ==
          Controller_P.GetParameter5_SampleTime)) {
      Controller_B.p_n = false;
    }

    if (Controller_B.p_n) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_ls.SampleTime = Controller_P.GetParameter5_SampleTime;
    }

    ParamGet_Controller_865.get_parameter(&Controller_B.p);

    // End of Start for MATLABSystem: '<S62>/Get Parameter5'

    // MATLAB Function: '<S12>/PWM assign' incorporates:
    //   Constant: '<S60>/Constant'

    // MATLAB Function 'toPWM/Calc pwm signal': '<S61>:1'
    //  thruster values should be between 1100 and 1900 microseconds (us)
    //  values less than 1500 us are backwards; values more than are forwards
    // '<S61>:1:5'
    Controller_B.msg = Controller_P.Constant_Value_i;

    // Product: '<S12>/Product' incorporates:
    //   MATLABSystem: '<S62>/Get Parameter'

    // MATLAB Function 'toPWM/PWM assign': '<S63>:1'
    // '<S63>:1:4'
    Controller_B.RandomSource = Controller_B.ChooseControllersignal[0] * (real_T)
      Controller_B.Compare;

    // Saturate: '<S12>/Saturation'
    if (Controller_B.RandomSource > Controller_P.Saturation_UpperSat) {
      Controller_B.RandomSource = Controller_P.Saturation_UpperSat;
    } else {
      if (Controller_B.RandomSource < Controller_P.Saturation_LowerSat) {
        Controller_B.RandomSource = Controller_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S12>/Calc pwm signal'
    //   Saturate: '<S12>/Saturation'

    Controller_B.Switch_i = floor((Controller_B.RandomSource + 1.0) * 400.0 +
      1100.0);
    if (rtIsNaN(Controller_B.Switch_i) || rtIsInf(Controller_B.Switch_i)) {
      Controller_B.Switch_i = 0.0;
    } else {
      Controller_B.Switch_i = fmod(Controller_B.Switch_i, 65536.0);
    }

    // MATLAB Function: '<S12>/PWM assign' incorporates:
    //   DataTypeConversion: '<S12>/Data Type Conversion'

    Controller_B.msg.Data[0] = (uint16_T)(Controller_B.Switch_i < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-Controller_B.Switch_i : (int32_T)(uint16_T)
      Controller_B.Switch_i);

    // Product: '<S12>/Product' incorporates:
    //   MATLABSystem: '<S62>/Get Parameter1'

    Controller_B.RandomSource = Controller_B.ChooseControllersignal[1] * (real_T)
      Controller_B.LogicalOperator;

    // Saturate: '<S12>/Saturation'
    if (Controller_B.RandomSource > Controller_P.Saturation_UpperSat) {
      Controller_B.RandomSource = Controller_P.Saturation_UpperSat;
    } else {
      if (Controller_B.RandomSource < Controller_P.Saturation_LowerSat) {
        Controller_B.RandomSource = Controller_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S12>/Calc pwm signal'
    //   Saturate: '<S12>/Saturation'

    Controller_B.Switch_i = floor((Controller_B.RandomSource + 1.0) * 400.0 +
      1100.0);
    if (rtIsNaN(Controller_B.Switch_i) || rtIsInf(Controller_B.Switch_i)) {
      Controller_B.Switch_i = 0.0;
    } else {
      Controller_B.Switch_i = fmod(Controller_B.Switch_i, 65536.0);
    }

    // MATLAB Function: '<S12>/PWM assign' incorporates:
    //   DataTypeConversion: '<S12>/Data Type Conversion'

    Controller_B.msg.Data[1] = (uint16_T)(Controller_B.Switch_i < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-Controller_B.Switch_i : (int32_T)(uint16_T)
      Controller_B.Switch_i);

    // Product: '<S12>/Product' incorporates:
    //   MATLABSystem: '<S62>/Get Parameter2'

    Controller_B.RandomSource = Controller_B.ChooseControllersignal[2] * (real_T)
      Controller_B.NotEqual;

    // Saturate: '<S12>/Saturation'
    if (Controller_B.RandomSource > Controller_P.Saturation_UpperSat) {
      Controller_B.RandomSource = Controller_P.Saturation_UpperSat;
    } else {
      if (Controller_B.RandomSource < Controller_P.Saturation_LowerSat) {
        Controller_B.RandomSource = Controller_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S12>/Calc pwm signal'
    //   Saturate: '<S12>/Saturation'

    Controller_B.Switch_i = floor((Controller_B.RandomSource + 1.0) * 400.0 +
      1100.0);
    if (rtIsNaN(Controller_B.Switch_i) || rtIsInf(Controller_B.Switch_i)) {
      Controller_B.Switch_i = 0.0;
    } else {
      Controller_B.Switch_i = fmod(Controller_B.Switch_i, 65536.0);
    }

    // MATLAB Function: '<S12>/PWM assign' incorporates:
    //   DataTypeConversion: '<S12>/Data Type Conversion'

    Controller_B.msg.Data[2] = (uint16_T)(Controller_B.Switch_i < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-Controller_B.Switch_i : (int32_T)(uint16_T)
      Controller_B.Switch_i);

    // Product: '<S12>/Product' incorporates:
    //   MATLABSystem: '<S62>/Get Parameter3'

    Controller_B.RandomSource = Controller_B.ChooseControllersignal[3] * (real_T)
      Controller_B.rtb_GetParameter3_g;

    // Saturate: '<S12>/Saturation'
    if (Controller_B.RandomSource > Controller_P.Saturation_UpperSat) {
      Controller_B.RandomSource = Controller_P.Saturation_UpperSat;
    } else {
      if (Controller_B.RandomSource < Controller_P.Saturation_LowerSat) {
        Controller_B.RandomSource = Controller_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S12>/Calc pwm signal'
    //   Saturate: '<S12>/Saturation'

    Controller_B.Switch_i = floor((Controller_B.RandomSource + 1.0) * 400.0 +
      1100.0);
    if (rtIsNaN(Controller_B.Switch_i) || rtIsInf(Controller_B.Switch_i)) {
      Controller_B.Switch_i = 0.0;
    } else {
      Controller_B.Switch_i = fmod(Controller_B.Switch_i, 65536.0);
    }

    // MATLAB Function: '<S12>/PWM assign' incorporates:
    //   DataTypeConversion: '<S12>/Data Type Conversion'

    Controller_B.msg.Data[3] = (uint16_T)(Controller_B.Switch_i < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-Controller_B.Switch_i : (int32_T)(uint16_T)
      Controller_B.Switch_i);

    // Product: '<S12>/Product' incorporates:
    //   MATLABSystem: '<S62>/Get Parameter4'

    Controller_B.RandomSource = Controller_B.ChooseControllersignal[4] * (real_T)
      Controller_B.rtb_GetParameter4_m;

    // Saturate: '<S12>/Saturation'
    if (Controller_B.RandomSource > Controller_P.Saturation_UpperSat) {
      Controller_B.RandomSource = Controller_P.Saturation_UpperSat;
    } else {
      if (Controller_B.RandomSource < Controller_P.Saturation_LowerSat) {
        Controller_B.RandomSource = Controller_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S12>/Calc pwm signal'
    //   Saturate: '<S12>/Saturation'

    Controller_B.Switch_i = floor((Controller_B.RandomSource + 1.0) * 400.0 +
      1100.0);
    if (rtIsNaN(Controller_B.Switch_i) || rtIsInf(Controller_B.Switch_i)) {
      Controller_B.Switch_i = 0.0;
    } else {
      Controller_B.Switch_i = fmod(Controller_B.Switch_i, 65536.0);
    }

    // MATLAB Function: '<S12>/PWM assign' incorporates:
    //   DataTypeConversion: '<S12>/Data Type Conversion'

    Controller_B.msg.Data[4] = (uint16_T)(Controller_B.Switch_i < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-Controller_B.Switch_i : (int32_T)(uint16_T)
      Controller_B.Switch_i);

    // Product: '<S12>/Product' incorporates:
    //   MATLABSystem: '<S62>/Get Parameter5'

    Controller_B.RandomSource = Controller_B.ChooseControllersignal[5] * (real_T)
      Controller_B.p;

    // Saturate: '<S12>/Saturation'
    if (Controller_B.RandomSource > Controller_P.Saturation_UpperSat) {
      Controller_B.RandomSource = Controller_P.Saturation_UpperSat;
    } else {
      if (Controller_B.RandomSource < Controller_P.Saturation_LowerSat) {
        Controller_B.RandomSource = Controller_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S12>/Calc pwm signal'
    //   Saturate: '<S12>/Saturation'

    Controller_B.Switch_i = floor((Controller_B.RandomSource + 1.0) * 400.0 +
      1100.0);
    if (rtIsNaN(Controller_B.Switch_i) || rtIsInf(Controller_B.Switch_i)) {
      Controller_B.Switch_i = 0.0;
    } else {
      Controller_B.Switch_i = fmod(Controller_B.Switch_i, 65536.0);
    }

    // MATLAB Function: '<S12>/PWM assign' incorporates:
    //   DataTypeConversion: '<S12>/Data Type Conversion'

    Controller_B.msg.Data[5] = (uint16_T)(Controller_B.Switch_i < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-Controller_B.Switch_i : (int32_T)(uint16_T)
      Controller_B.Switch_i);

    // '<S63>:1:5'
    Controller_B.msg.Layout.DataOffset = 0U;

    // '<S63>:1:6'
    Controller_B.msg.Layout.Dim[0].Stride = 1U;

    // '<S63>:1:7'
    Controller_B.msg.Layout.Dim[0].Size = 6U;

    // '<S63>:1:8'
    Controller_B.msg.Data_SL_Info.CurrentLength = 6U;

    // Outputs for Atomic SubSystem: '<S12>/Publish'
    // MATLABSystem: '<S64>/SinkBlock'
    // '<S63>:1:9'
    Pub_Controller_607.publish(&Controller_B.msg);

    // End of Outputs for SubSystem: '<S12>/Publish'
  }

  // End of Logic: '<Root>/Logical Operator1'
  // End of Outputs for SubSystem: '<Root>/toPWM'

  // Start for MATLABSystem: '<S7>/Get alpha' incorporates:
  //   MATLABSystem: '<S7>/Get alpha'

  Controller_B.p = false;
  Controller_B.p_n = true;
  if (!(Controller_DWork.obj_hx.SampleTime == Controller_P.Getalpha_SampleTime))
  {
    Controller_B.p_n = false;
  }

  if (Controller_B.p_n) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_hx.SampleTime = Controller_P.Getalpha_SampleTime;
  }

  ParamGet_Controller_687.get_parameter(&Controller_B.RandomSource);

  // End of Start for MATLABSystem: '<S7>/Get alpha'

  // SignalConversion: '<S7>/TmpSignal ConversionAtDiscrete FilterInport2' incorporates:
  //   Constant: '<S7>/Constant'
  //   MATLABSystem: '<S7>/Get alpha'

  Controller_B.TmpSignalConversionAtDiscreteFi[0] =
    Controller_P.Constant_Value_ay;
  Controller_B.TmpSignalConversionAtDiscreteFi[1] = Controller_B.RandomSource;

  // DiscreteFilter: '<S7>/Discrete Filter'
  Controller_B.RandomSource = Controller_P.DiscreteFilter_NumCoef *
    Controller_B.OutportBufferForaccXms2 -
    Controller_B.TmpSignalConversionAtDiscreteFi[1] *
    Controller_DWork.DiscreteFilter_denStates;
  Controller_DWork.DiscreteFilter_tmp = Controller_B.RandomSource;

  // DiscreteFilter: '<S7>/Discrete Filter1'
  Controller_B.cfi = Controller_P.DiscreteFilter1_NumCoef *
    Controller_B.OutportBufferForaccYms2 -
    Controller_B.TmpSignalConversionAtDiscreteFi[1] *
    Controller_DWork.DiscreteFilter1_denStates;
  Controller_DWork.DiscreteFilter1_tmp = Controller_B.cfi;

  // DiscreteFilter: '<S7>/Discrete Filter2'
  Controller_B.spsi = Controller_P.DiscreteFilter2_NumCoef *
    Controller_B.OutportBufferForaccZms2 -
    Controller_B.TmpSignalConversionAtDiscreteFi[1] *
    Controller_DWork.DiscreteFilter2_denStates;
  Controller_DWork.DiscreteFilter2_tmp = Controller_B.spsi;

  // Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
  Controller_DWork.DiscreteTimeIntegrator_DSTATE +=
    Controller_P.DiscreteTimeIntegrator_gainval * Controller_B.RandomSource;

  // Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'
  Controller_DWork.DiscreteTimeIntegrator1_DSTATE +=
    Controller_P.DiscreteTimeIntegrator1_gainval * Controller_B.cfi;

  // Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator2'
  Controller_DWork.DiscreteTimeIntegrator2_DSTATE +=
    Controller_P.DiscreteTimeIntegrator2_gainval * Controller_B.spsi;

  // Update for DiscreteFilter: '<S7>/Discrete Filter'
  Controller_DWork.DiscreteFilter_denStates =
    Controller_DWork.DiscreteFilter_tmp;

  // Update for DiscreteFilter: '<S7>/Discrete Filter1'
  Controller_DWork.DiscreteFilter1_denStates =
    Controller_DWork.DiscreteFilter1_tmp;

  // Update for DiscreteFilter: '<S7>/Discrete Filter2'
  Controller_DWork.DiscreteFilter2_denStates =
    Controller_DWork.DiscreteFilter2_tmp;
}

// Model initialize function
void ControllerModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus((&Controller_M), (NULL));

  // block I/O
  (void) memset(((void *) &Controller_B), 0,
                sizeof(BlockIO_Controller_T));

  // states (dwork)
  (void) memset((void *)&Controller_DWork, 0,
                sizeof(D_Work_Controller_T));

  {
    int32_T i;
    static const char_T tmp[24] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_', 'c',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'a', 'l', 'p', 'h', 'a'
    };

    static const char_T tmp_0[16] = { '/', 'r', 'o', 'v', 'i', 'o', '/', 't',
      'h', 'r', 'u', 's', 't', 'e', 'r', 's' };

    static const char_T tmp_1[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 't', 'h', 'r', 'u', 's', 't', 'e', 'r', '6' };

    static const char_T tmp_2[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 't', 'h', 'r', 'u', 's', 't', 'e', 'r', '5' };

    static const char_T tmp_3[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 't', 'h', 'r', 'u', 's', 't', 'e', 'r', '4' };

    static const char_T tmp_4[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 't', 'h', 'r', 'u', 's', 't', 'e', 'r', '3' };

    static const char_T tmp_5[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 't', 'h', 'r', 'u', 's', 't', 'e', 'r', '2' };

    static const char_T tmp_6[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 't', 'h', 'r', 'u', 's', 't', 'e', 'r', '1' };

    static const char_T tmp_7[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'b', 'u', 'o', 'y',
      'a', 'n', 'c', 'y', '_', 'c', 'o', 'n', 't', 'r', 'o', 'l' };

    static const char_T tmp_8[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_9[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_a[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_b[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_c[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_d[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_e[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_f[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_g[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_h[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_i[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_j[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_k[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_l[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_m[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_n[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_o[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_p[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_q[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_r[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_s[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_t[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_u[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_v[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_w[37] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 'i', 'n', 't', 'e', 'g', 'r', 'a', 't', 'i', 'o', 'n' };

    static const char_T tmp_x[21] = { '/', 's', 'e', 'n', 's', 'o', 'r', '_',
      'f', 'u', 's', 'i', 'o', 'n', '/', 's', 't', 'a', 't', 'e', 's' };

    static const char_T tmp_y[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_z[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'c', 'o', 'n', 't',
      'r', 'o', 'l', 'l', 'e', 'r' };

    static const char_T tmp_10[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '6' };

    static const char_T tmp_11[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '6' };

    static const char_T tmp_12[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '6' };

    static const char_T tmp_13[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '5' };

    static const char_T tmp_14[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '5' };

    static const char_T tmp_15[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '5' };

    static const char_T tmp_16[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '4' };

    static const char_T tmp_17[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '4' };

    static const char_T tmp_18[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '4' };

    static const char_T tmp_19[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '3' };

    static const char_T tmp_1a[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '3' };

    static const char_T tmp_1b[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '3' };

    static const char_T tmp_1c[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '2' };

    static const char_T tmp_1d[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '2' };

    static const char_T tmp_1e[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '2' };

    static const char_T tmp_1f[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '1' };

    static const char_T tmp_1g[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '1' };

    static const char_T tmp_1h[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '1' };

    static const char_T tmp_1i[23] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 't', 'e', 's', 't'
    };

    // Start for MATLABSystem: '<Root>/Get test'
    Controller_DWork.obj_h2.isInitialized = 0;
    Controller_DWork.objisempty_pr = true;
    Controller_DWork.obj_h2.SampleTime = Controller_P.Gettest_SampleTime;
    Controller_DWork.obj_h2.isInitialized = 1;
    for (i = 0; i < 23; i++) {
      Controller_B.cv7[i] = tmp_1i[i];
    }

    Controller_B.cv7[23] = '\x00';
    ParamGet_Controller_823.initialize(Controller_B.cv7,
      Control_ParameterInitialValue_l, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<Root>/Get test'

    // Start for Enabled SubSystem: '<Root>/Telegraph'
    // Start for S-Function (sdsprandsrc2): '<S15>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_DWork.RandomSource_SEED_DWORK, 1);
    RandSrcInitState_U_64(&Controller_DWork.RandomSource_SEED_DWORK,
                          Controller_DWork.RandomSource_STATE_DWORK, 1);

    // Start for MATLABSystem: '<S15>/Swtiching factor'
    Controller_DWork.obj_of.isInitialized = 0;
    Controller_DWork.objisempty_ls = true;
    Controller_DWork.obj_of.SampleTime = Controller_P.Swtichingfactor_SampleTime;
    Controller_DWork.obj_of.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_B.cv3[i] = tmp_1h[i];
    }

    Controller_B.cv3[33] = '\x00';
    ParamGet_Controller_714.initialize(Controller_B.cv3,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S15>/Swtiching factor'

    // Start for MATLABSystem: '<S15>/Swtiching factor1'
    Controller_DWork.obj_fx.isInitialized = 0;
    Controller_DWork.objisempty_jb = true;
    Controller_DWork.obj_fx.SampleTime =
      Controller_P.Swtichingfactor1_SampleTime;
    Controller_DWork.obj_fx.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_1g[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_715.initialize(Controller_B.cv4,
      Contr_ParameterInitialValue_l5x, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S15>/Swtiching factor1'

    // Start for MATLABSystem: '<S15>/Swtiching factor2'
    Controller_DWork.obj_d3.isInitialized = 0;
    Controller_DWork.objisempty_jr = true;
    Controller_DWork.obj_d3.SampleTime =
      Controller_P.Swtichingfactor2_SampleTime;
    Controller_DWork.obj_d3.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_1f[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_716.initialize(Controller_B.cv4,
      Contr_ParameterInitialValue_l5x, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S15>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S16>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_DWork.RandomSource_SEED_DWORK_l, 1);
    RandSrcInitState_U_64(&Controller_DWork.RandomSource_SEED_DWORK_l,
                          Controller_DWork.RandomSource_STATE_DWORK_i, 1);

    // Start for MATLABSystem: '<S16>/Swtiching factor'
    Controller_DWork.obj_i.isInitialized = 0;
    Controller_DWork.objisempty_mo = true;
    Controller_DWork.obj_i.SampleTime =
      Controller_P.Swtichingfactor_SampleTime_k;
    Controller_DWork.obj_i.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_B.cv3[i] = tmp_1e[i];
    }

    Controller_B.cv3[33] = '\x00';
    ParamGet_Controller_724.initialize(Controller_B.cv3,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S16>/Swtiching factor'

    // Start for MATLABSystem: '<S16>/Swtiching factor1'
    Controller_DWork.obj_j5.isInitialized = 0;
    Controller_DWork.objisempty_ng = true;
    Controller_DWork.obj_j5.SampleTime =
      Controller_P.Swtichingfactor1_SampleTime_i;
    Controller_DWork.obj_j5.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_1d[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_725.initialize(Controller_B.cv4,
      Contr_ParameterInitialValue_l5x, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S16>/Swtiching factor1'

    // Start for MATLABSystem: '<S16>/Swtiching factor2'
    Controller_DWork.obj_fu.isInitialized = 0;
    Controller_DWork.objisempty_fp = true;
    Controller_DWork.obj_fu.SampleTime =
      Controller_P.Swtichingfactor2_SampleTime_b;
    Controller_DWork.obj_fu.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_1c[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_726.initialize(Controller_B.cv4,
      Contr_ParameterInitialValue_l5x, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S16>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S17>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_DWork.RandomSource_SEED_DWORK_c, 1);
    RandSrcInitState_U_64(&Controller_DWork.RandomSource_SEED_DWORK_c,
                          Controller_DWork.RandomSource_STATE_DWORK_a, 1);

    // Start for MATLABSystem: '<S17>/Swtiching factor'
    Controller_DWork.obj_o.isInitialized = 0;
    Controller_DWork.objisempty_ev = true;
    Controller_DWork.obj_o.SampleTime =
      Controller_P.Swtichingfactor_SampleTime_g;
    Controller_DWork.obj_o.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_B.cv3[i] = tmp_1b[i];
    }

    Controller_B.cv3[33] = '\x00';
    ParamGet_Controller_734.initialize(Controller_B.cv3,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S17>/Swtiching factor'

    // Start for MATLABSystem: '<S17>/Swtiching factor1'
    Controller_DWork.obj_f.isInitialized = 0;
    Controller_DWork.objisempty_em = true;
    Controller_DWork.obj_f.SampleTime =
      Controller_P.Swtichingfactor1_SampleTime_o;
    Controller_DWork.obj_f.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_1a[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_735.initialize(Controller_B.cv4,
      Contr_ParameterInitialValue_l5x, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S17>/Swtiching factor1'

    // Start for MATLABSystem: '<S17>/Swtiching factor2'
    Controller_DWork.obj_mb.isInitialized = 0;
    Controller_DWork.objisempty_ks = true;
    Controller_DWork.obj_mb.SampleTime =
      Controller_P.Swtichingfactor2_SampleTime_o;
    Controller_DWork.obj_mb.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_19[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_736.initialize(Controller_B.cv4,
      Contr_ParameterInitialValue_l5x, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S17>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S18>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_DWork.RandomSource_SEED_DWORK_i, 1);
    RandSrcInitState_U_64(&Controller_DWork.RandomSource_SEED_DWORK_i,
                          Controller_DWork.RandomSource_STATE_DWORK_g, 1);

    // Start for MATLABSystem: '<S18>/Swtiching factor'
    Controller_DWork.obj_gv.isInitialized = 0;
    Controller_DWork.objisempty_a3j = true;
    Controller_DWork.obj_gv.SampleTime =
      Controller_P.Swtichingfactor_SampleTime_n;
    Controller_DWork.obj_gv.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_B.cv3[i] = tmp_18[i];
    }

    Controller_B.cv3[33] = '\x00';
    ParamGet_Controller_744.initialize(Controller_B.cv3,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S18>/Swtiching factor'

    // Start for MATLABSystem: '<S18>/Swtiching factor1'
    Controller_DWork.obj_c2.isInitialized = 0;
    Controller_DWork.objisempty_hv = true;
    Controller_DWork.obj_c2.SampleTime =
      Controller_P.Swtichingfactor1_SampleTime_j;
    Controller_DWork.obj_c2.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_17[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_745.initialize(Controller_B.cv4,
      Contr_ParameterInitialValue_l5x, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S18>/Swtiching factor1'

    // Start for MATLABSystem: '<S18>/Swtiching factor2'
    Controller_DWork.obj_g0e.isInitialized = 0;
    Controller_DWork.objisempty_o = true;
    Controller_DWork.obj_g0e.SampleTime =
      Controller_P.Swtichingfactor2_SampleTime_e;
    Controller_DWork.obj_g0e.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_16[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_746.initialize(Controller_B.cv4,
      Contr_ParameterInitialValue_l5x, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S18>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S19>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_DWork.RandomSource_SEED_DWORK_k, 1);
    RandSrcInitState_U_64(&Controller_DWork.RandomSource_SEED_DWORK_k,
                          Controller_DWork.RandomSource_STATE_DWORK_j, 1);

    // Start for MATLABSystem: '<S19>/Swtiching factor'
    Controller_DWork.obj_j0.isInitialized = 0;
    Controller_DWork.objisempty_fj = true;
    Controller_DWork.obj_j0.SampleTime =
      Controller_P.Swtichingfactor_SampleTime_nq;
    Controller_DWork.obj_j0.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_B.cv3[i] = tmp_15[i];
    }

    Controller_B.cv3[33] = '\x00';
    ParamGet_Controller_850.initialize(Controller_B.cv3,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S19>/Swtiching factor'

    // Start for MATLABSystem: '<S19>/Swtiching factor1'
    Controller_DWork.obj_hr.isInitialized = 0;
    Controller_DWork.objisempty_nl = true;
    Controller_DWork.obj_hr.SampleTime =
      Controller_P.Swtichingfactor1_SampleTime_a;
    Controller_DWork.obj_hr.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_14[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_851.initialize(Controller_B.cv4,
      Contr_ParameterInitialValue_l5x, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S19>/Swtiching factor1'

    // Start for MATLABSystem: '<S19>/Swtiching factor2'
    Controller_DWork.obj_dn.isInitialized = 0;
    Controller_DWork.objisempty_kk = true;
    Controller_DWork.obj_dn.SampleTime =
      Controller_P.Swtichingfactor2_SampleTime_n;
    Controller_DWork.obj_dn.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_13[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_852.initialize(Controller_B.cv4,
      Contr_ParameterInitialValue_l5x, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S19>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S20>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_DWork.RandomSource_SEED_DWORK_g, 1);
    RandSrcInitState_U_64(&Controller_DWork.RandomSource_SEED_DWORK_g,
                          Controller_DWork.RandomSource_STATE_DWORK_h, 1);

    // Start for MATLABSystem: '<S20>/Swtiching factor'
    Controller_DWork.obj_gf.isInitialized = 0;
    Controller_DWork.objisempty_k1 = true;
    Controller_DWork.obj_gf.SampleTime =
      Controller_P.Swtichingfactor_SampleTime_f;
    Controller_DWork.obj_gf.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_B.cv3[i] = tmp_12[i];
    }

    Controller_B.cv3[33] = '\x00';
    ParamGet_Controller_764.initialize(Controller_B.cv3,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S20>/Swtiching factor'

    // Start for MATLABSystem: '<S20>/Swtiching factor1'
    Controller_DWork.obj_cvy.isInitialized = 0;
    Controller_DWork.objisempty_gk = true;
    Controller_DWork.obj_cvy.SampleTime =
      Controller_P.Swtichingfactor1_SampleTime_e;
    Controller_DWork.obj_cvy.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_11[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_765.initialize(Controller_B.cv4,
      Contr_ParameterInitialValue_l5x, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S20>/Swtiching factor1'

    // Start for MATLABSystem: '<S20>/Swtiching factor2'
    Controller_DWork.obj_dt.isInitialized = 0;
    Controller_DWork.objisempty_kl = true;
    Controller_DWork.obj_dt.SampleTime =
      Controller_P.Swtichingfactor2_SampleTime_c;
    Controller_DWork.obj_dt.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_10[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_766.initialize(Controller_B.cv4,
      Contr_ParameterInitialValue_l5x, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S20>/Swtiching factor2'
    // End of Start for SubSystem: '<Root>/Telegraph'

    // InitializeConditions for Enabled SubSystem: '<Root>/Telegraph'

    // InitializeConditions for State Transition Table: '<S15>/State Transition Table' 
    Contr_StateTransitionTable_Init(&Controller_DWork.sf_StateTransitionTable);

    // InitializeConditions for State Transition Table: '<S16>/State Transition Table' 
    Contr_StateTransitionTable_Init(&Controller_DWork.sf_StateTransitionTable_i);

    // InitializeConditions for State Transition Table: '<S17>/State Transition Table' 
    Contr_StateTransitionTable_Init(&Controller_DWork.sf_StateTransitionTable_m);

    // InitializeConditions for State Transition Table: '<S18>/State Transition Table' 
    Contr_StateTransitionTable_Init(&Controller_DWork.sf_StateTransitionTable_mx);

    // InitializeConditions for State Transition Table: '<S19>/State Transition Table' 
    Contr_StateTransitionTable_Init(&Controller_DWork.sf_StateTransitionTable_o);

    // InitializeConditions for State Transition Table: '<S20>/State Transition Table' 
    Contr_StateTransitionTable_Init(&Controller_DWork.sf_StateTransitionTable_o2);

    // End of InitializeConditions for SubSystem: '<Root>/Telegraph'

    // Start for Enabled SubSystem: '<Root>/Telegraph'
    // VirtualOutportStart for Outport: '<S5>/Thrusters'
    for (i = 0; i < 6; i++) {
      Controller_B.OutportBufferForThrusters[i] = Controller_P.Thrusters_Y0;
    }

    // End of VirtualOutportStart for Outport: '<S5>/Thrusters'
    // End of Start for SubSystem: '<Root>/Telegraph'

    // Start for MATLABSystem: '<Root>/Get controller type'
    Controller_DWork.obj_nl.isInitialized = 0;
    Controller_DWork.objisempty_m0 = true;
    Controller_DWork.obj_nl.SampleTime =
      Controller_P.Getcontrollertype_SampleTime;
    Controller_DWork.obj_nl.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv4[i] = tmp_z[i];
    }

    Controller_B.cv4[29] = '\x00';
    ParamGet_Controller_106.initialize(Controller_B.cv4,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<Root>/Get controller type'

    // Start for Atomic SubSystem: '<Root>/cmd_vel'
    // Start for MATLABSystem: '<S8>/SourceBlock'
    Controller_DWork.obj_nf.isInitialized = 0;
    Controller_DWork.objisempty_gn = true;
    Controller_DWork.obj_nf.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      Controller_B.cv10[i] = tmp_y[i];
    }

    Controller_B.cv10[8] = '\x00';
    Sub_Controller_1.create_subscriber(Controller_B.cv10,
      Controller_MessageQueueLen);

    // End of Start for MATLABSystem: '<S8>/SourceBlock'

    // Start for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S33>/Out1'
    Controller_B.In1_m = Controller_P.Out1_Y0_f;

    // End of Start for SubSystem: '<S8>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/cmd_vel'

    // Start for Atomic SubSystem: '<Root>/imu_data'
    // Start for MATLABSystem: '<S10>/SourceBlock'
    Controller_DWork.obj_k.isInitialized = 0;
    Controller_DWork.objisempty_i = true;
    Controller_DWork.obj_k.isInitialized = 1;
    for (i = 0; i < 21; i++) {
      Controller_B.cv8[i] = tmp_x[i];
    }

    Controller_B.cv8[21] = '\x00';
    Sub_Controller_28.create_subscriber(Controller_B.cv8,
      Controller_MessageQueueLen);

    // End of Start for MATLABSystem: '<S10>/SourceBlock'

    // Start for Enabled SubSystem: '<S10>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S58>/Out1'
    Controller_B.In1 = Controller_P.Out1_Y0;

    // End of Start for SubSystem: '<S10>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/imu_data'

    // Start for Enabled SubSystem: '<Root>/Xbox_input'
    // VirtualOutportStart for Outport: '<S6>/<angular_vel X>'
    Controller_B.X_hw = Controller_P.angular_velX_Y0;

    // VirtualOutportStart for Outport: '<S6>/<angular_vel Y>'
    Controller_B.Y_in = Controller_P.angular_velY_Y0;

    // VirtualOutportStart for Outport: '<S6>/<angular_vel Z> '
    Controller_B.Z_n = Controller_P.angular_velZ_Y0;

    // VirtualOutportStart for Outport: '<S6>/<velocity X>'
    Controller_B.X_h = Controller_P.velocityX_Y0;

    // VirtualOutportStart for Outport: '<S6>/<veloctiy Y>'
    Controller_B.Y_i = Controller_P.veloctiyY_Y0;

    // VirtualOutportStart for Outport: '<S6>/<velocity Z>'
    Controller_B.Z = Controller_P.velocityZ_Y0;

    // End of Start for SubSystem: '<Root>/Xbox_input'

    // Start for MATLABSystem: '<S3>/Get buoyancy'
    Controller_DWork.obj_fe.isInitialized = 0;
    Controller_DWork.objisempty_ct = true;
    Controller_DWork.obj_fe.SampleTime = Controller_P.Getbuoyancy_SampleTime;
    Controller_DWork.obj_fe.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv1[i] = tmp_7[i];
    }

    Controller_B.cv1[35] = '\x00';
    ParamGet_Controller_879.initialize(Controller_B.cv1,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S3>/Get buoyancy'

    // Start for Enabled SubSystem: '<Root>/states'
    // VirtualOutportStart for Outport: '<S11>/<angular_vel X [degrees//s]>'
    Controller_B.X = Controller_P.angular_velXdegreess_Y0;

    // VirtualOutportStart for Outport: '<S11>/<angular_vel Y [degrees//s]>'
    Controller_B.Y = Controller_P.angular_velYdegreess_Y0;

    // VirtualOutportStart for Outport: '<S11>/<angular_vel Z [degrees//s]>'
    Controller_B.OutportBufferForangular_velZdeg =
      Controller_P.angular_velZdegreess_Y0;

    // VirtualOutportStart for Outport: '<S11>/<acc X [m//s^2]>'
    Controller_B.OutportBufferForaccXms2 = Controller_P.accXms2_Y0;

    // VirtualOutportStart for Outport: '<S11>/<acc Y [m//s^2]>'
    Controller_B.OutportBufferForaccYms2 = Controller_P.accYms2_Y0;

    // VirtualOutportStart for Outport: '<S11>/<acc Z [m//s^2]>'
    Controller_B.OutportBufferForaccZms2 = Controller_P.accZms2_Y0;

    // End of Start for SubSystem: '<Root>/states'

    // Start for MATLABSystem: '<S7>/Enable integration?'
    Controller_DWork.obj_g0.isInitialized = 0;
    Controller_DWork.objisempty_lj = true;
    Controller_DWork.obj_g0.SampleTime =
      Controller_P.Enableintegration_SampleTime;
    Controller_DWork.obj_g0.isInitialized = 1;
    for (i = 0; i < 37; i++) {
      Controller_B.cv0[i] = tmp_w[i];
    }

    Controller_B.cv0[37] = '\x00';
    ParamGet_Controller_686.initialize(Controller_B.cv0,
      Cont_ParameterInitialValue_l5xx, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S7>/Enable integration?'

    // Start for Enabled SubSystem: '<Root>/Create errors'
    // VirtualOutportStart for Outport: '<S2>/angular_vel x error [degrees]'
    Controller_B.Errorx = Controller_P.angular_velxerrordegrees_Y0;

    // VirtualOutportStart for Outport: '<S2>/angular_vel y error [degrees]'
    Controller_B.Errory = Controller_P.angular_velyerrordegrees_Y0;

    // VirtualOutportStart for Outport: '<S2>/angular_vel z error [degrees]'
    Controller_B.Errorz = Controller_P.angular_velzerrordegrees_Y0;

    // VirtualOutportStart for Outport: '<S2>/vel x error [m//s]'
    Controller_B.Errorz8 = Controller_P.velxerrorms_Y0;

    // VirtualOutportStart for Outport: '<S2>/vel y error [m//s]'
    Controller_B.Errorz9 = Controller_P.velyerrorms_Y0;

    // VirtualOutportStart for Outport: '<S2>/vel z error [m//s]'
    Controller_B.Errorz10 = Controller_P.velzerrorms_Y0;

    // End of Start for SubSystem: '<Root>/Create errors'

    // Start for Enabled SubSystem: '<Root>/decController'
    // Start for MATLABSystem: '<S41>/P_angular_vel_x'
    Controller_DWork.obj_bm.isInitialized = 0;
    Controller_DWork.objisempty_f = true;
    Controller_DWork.obj_bm.SampleTime = Controller_P.P_angular_vel_x_SampleTime;
    Controller_DWork.obj_bm.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv2[i] = tmp_v[i];
    }

    Controller_B.cv2[34] = '\x00';
    ParamGet_Controller_508.initialize(Controller_B.cv2,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S41>/P_angular_vel_x'

    // Start for MATLABSystem: '<S41>/D_angular_vel_x'
    Controller_DWork.obj_be.isInitialized = 0;
    Controller_DWork.objisempty_g = true;
    Controller_DWork.obj_be.SampleTime = Controller_P.D_angular_vel_x_SampleTime;
    Controller_DWork.obj_be.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv2[i] = tmp_u[i];
    }

    Controller_B.cv2[34] = '\x00';
    ParamGet_Controller_505.initialize(Controller_B.cv2,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S41>/D_angular_vel_x'

    // Start for MATLABSystem: '<S41>/N_angular_vel_x '
    Controller_DWork.obj_lb.isInitialized = 0;
    Controller_DWork.objisempty_d0 = true;
    Controller_DWork.obj_lb.SampleTime = Controller_P.N_angular_vel_x_SampleTime;
    Controller_DWork.obj_lb.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv2[i] = tmp_t[i];
    }

    Controller_B.cv2[34] = '\x00';
    ParamGet_Controller_507.initialize(Controller_B.cv2,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S41>/N_angular_vel_x '

    // Start for MATLABSystem: '<S41>/I_angular_vel_x'
    Controller_DWork.obj_pb.isInitialized = 0;
    Controller_DWork.objisempty_mb = true;
    Controller_DWork.obj_pb.SampleTime = Controller_P.I_angular_vel_x_SampleTime;
    Controller_DWork.obj_pb.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv2[i] = tmp_s[i];
    }

    Controller_B.cv2[34] = '\x00';
    ParamGet_Controller_506.initialize(Controller_B.cv2,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S41>/I_angular_vel_x'

    // Start for MATLABSystem: '<S44>/P_angular_vel_y'
    Controller_DWork.obj_b.isInitialized = 0;
    Controller_DWork.objisempty_j = true;
    Controller_DWork.obj_b.SampleTime = Controller_P.P_angular_vel_y_SampleTime;
    Controller_DWork.obj_b.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv2[i] = tmp_r[i];
    }

    Controller_B.cv2[34] = '\x00';
    ParamGet_Controller_522.initialize(Controller_B.cv2,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S44>/P_angular_vel_y'

    // Start for MATLABSystem: '<S44>/D_angular_vel_y'
    Controller_DWork.obj_m.isInitialized = 0;
    Controller_DWork.objisempty_h1 = true;
    Controller_DWork.obj_m.SampleTime = Controller_P.D_angular_vel_y_SampleTime;
    Controller_DWork.obj_m.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv2[i] = tmp_q[i];
    }

    Controller_B.cv2[34] = '\x00';
    ParamGet_Controller_519.initialize(Controller_B.cv2,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S44>/D_angular_vel_y'

    // Start for MATLABSystem: '<S44>/N_angular_vel_y '
    Controller_DWork.obj_dp.isInitialized = 0;
    Controller_DWork.objisempty_ex = true;
    Controller_DWork.obj_dp.SampleTime = Controller_P.N_angular_vel_y_SampleTime;
    Controller_DWork.obj_dp.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv2[i] = tmp_p[i];
    }

    Controller_B.cv2[34] = '\x00';
    ParamGet_Controller_521.initialize(Controller_B.cv2,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S44>/N_angular_vel_y '

    // Start for MATLABSystem: '<S44>/I_angular_vel_y'
    Controller_DWork.obj_ep.isInitialized = 0;
    Controller_DWork.objisempty_ef = true;
    Controller_DWork.obj_ep.SampleTime = Controller_P.I_angular_vel_y_SampleTime;
    Controller_DWork.obj_ep.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv2[i] = tmp_o[i];
    }

    Controller_B.cv2[34] = '\x00';
    ParamGet_Controller_520.initialize(Controller_B.cv2,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S44>/I_angular_vel_y'

    // Start for MATLABSystem: '<S47>/P_angular_vel_z'
    Controller_DWork.obj_e.isInitialized = 0;
    Controller_DWork.objisempty_h = true;
    Controller_DWork.obj_e.SampleTime = Controller_P.P_angular_vel_z_SampleTime;
    Controller_DWork.obj_e.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv2[i] = tmp_n[i];
    }

    Controller_B.cv2[34] = '\x00';
    ParamGet_Controller_536.initialize(Controller_B.cv2,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S47>/P_angular_vel_z'

    // Start for MATLABSystem: '<S47>/D_angular_vel_z'
    Controller_DWork.obj_jg.isInitialized = 0;
    Controller_DWork.objisempty_if = true;
    Controller_DWork.obj_jg.SampleTime = Controller_P.D_angular_vel_z_SampleTime;
    Controller_DWork.obj_jg.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv2[i] = tmp_m[i];
    }

    Controller_B.cv2[34] = '\x00';
    ParamGet_Controller_533.initialize(Controller_B.cv2,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S47>/D_angular_vel_z'

    // Start for MATLABSystem: '<S47>/N_angular_vel_z '
    Controller_DWork.obj_g.isInitialized = 0;
    Controller_DWork.objisempty_m1 = true;
    Controller_DWork.obj_g.SampleTime = Controller_P.N_angular_vel_z_SampleTime;
    Controller_DWork.obj_g.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv2[i] = tmp_l[i];
    }

    Controller_B.cv2[34] = '\x00';
    ParamGet_Controller_535.initialize(Controller_B.cv2,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S47>/N_angular_vel_z '

    // Start for MATLABSystem: '<S47>/I_angular_vel_z'
    Controller_DWork.obj_p.isInitialized = 0;
    Controller_DWork.objisempty_k = true;
    Controller_DWork.obj_p.SampleTime = Controller_P.I_angular_vel_z_SampleTime;
    Controller_DWork.obj_p.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv2[i] = tmp_k[i];
    }

    Controller_B.cv2[34] = '\x00';
    ParamGet_Controller_534.initialize(Controller_B.cv2,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S47>/I_angular_vel_z'

    // Start for MATLABSystem: '<S50>/P_vel_x'
    Controller_DWork.obj_ns.isInitialized = 0;
    Controller_DWork.objisempty_a3 = true;
    Controller_DWork.obj_ns.SampleTime = Controller_P.P_vel_x_SampleTime;
    Controller_DWork.obj_ns.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv5[i] = tmp_j[i];
    }

    Controller_B.cv5[26] = '\x00';
    ParamGet_Controller_550.initialize(Controller_B.cv5,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S50>/P_vel_x'

    // Start for MATLABSystem: '<S50>/D_vel_x'
    Controller_DWork.obj_d.isInitialized = 0;
    Controller_DWork.objisempty_d = true;
    Controller_DWork.obj_d.SampleTime = Controller_P.D_vel_x_SampleTime;
    Controller_DWork.obj_d.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv5[i] = tmp_i[i];
    }

    Controller_B.cv5[26] = '\x00';
    ParamGet_Controller_547.initialize(Controller_B.cv5,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S50>/D_vel_x'

    // Start for MATLABSystem: '<S50>/N_vel_x '
    Controller_DWork.obj_a3.isInitialized = 0;
    Controller_DWork.objisempty_il = true;
    Controller_DWork.obj_a3.SampleTime = Controller_P.N_vel_x_SampleTime;
    Controller_DWork.obj_a3.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv5[i] = tmp_h[i];
    }

    Controller_B.cv5[26] = '\x00';
    ParamGet_Controller_549.initialize(Controller_B.cv5,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S50>/N_vel_x '

    // Start for MATLABSystem: '<S50>/I_vel_x'
    Controller_DWork.obj_cv.isInitialized = 0;
    Controller_DWork.objisempty_pu = true;
    Controller_DWork.obj_cv.SampleTime = Controller_P.I_vel_x_SampleTime;
    Controller_DWork.obj_cv.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv5[i] = tmp_g[i];
    }

    Controller_B.cv5[26] = '\x00';
    ParamGet_Controller_548.initialize(Controller_B.cv5,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S50>/I_vel_x'

    // Start for MATLABSystem: '<S53>/P_vel_y'
    Controller_DWork.obj_ji.isInitialized = 0;
    Controller_DWork.objisempty_ej = true;
    Controller_DWork.obj_ji.SampleTime = Controller_P.P_vel_y_SampleTime;
    Controller_DWork.obj_ji.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv5[i] = tmp_f[i];
    }

    Controller_B.cv5[26] = '\x00';
    ParamGet_Controller_564.initialize(Controller_B.cv5,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S53>/P_vel_y'

    // Start for MATLABSystem: '<S53>/D_vel_y'
    Controller_DWork.obj_ny.isInitialized = 0;
    Controller_DWork.objisempty_c = true;
    Controller_DWork.obj_ny.SampleTime = Controller_P.D_vel_y_SampleTime;
    Controller_DWork.obj_ny.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv5[i] = tmp_e[i];
    }

    Controller_B.cv5[26] = '\x00';
    ParamGet_Controller_561.initialize(Controller_B.cv5,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S53>/D_vel_y'

    // Start for MATLABSystem: '<S53>/N_vel_y '
    Controller_DWork.obj_cb.isInitialized = 0;
    Controller_DWork.objisempty_b = true;
    Controller_DWork.obj_cb.SampleTime = Controller_P.N_vel_y_SampleTime;
    Controller_DWork.obj_cb.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv5[i] = tmp_d[i];
    }

    Controller_B.cv5[26] = '\x00';
    ParamGet_Controller_563.initialize(Controller_B.cv5,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S53>/N_vel_y '

    // Start for MATLABSystem: '<S53>/I_vel_y'
    Controller_DWork.obj_jx.isInitialized = 0;
    Controller_DWork.objisempty_m = true;
    Controller_DWork.obj_jx.SampleTime = Controller_P.I_vel_y_SampleTime;
    Controller_DWork.obj_jx.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv5[i] = tmp_c[i];
    }

    Controller_B.cv5[26] = '\x00';
    ParamGet_Controller_562.initialize(Controller_B.cv5,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S53>/I_vel_y'

    // Start for MATLABSystem: '<S56>/P_vel_z'
    Controller_DWork.obj_j.isInitialized = 0;
    Controller_DWork.objisempty_le = true;
    Controller_DWork.obj_j.SampleTime = Controller_P.P_vel_z_SampleTime;
    Controller_DWork.obj_j.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv5[i] = tmp_b[i];
    }

    Controller_B.cv5[26] = '\x00';
    ParamGet_Controller_578.initialize(Controller_B.cv5,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S56>/P_vel_z'

    // Start for MATLABSystem: '<S56>/D_vel_z'
    Controller_DWork.obj_a.isInitialized = 0;
    Controller_DWork.objisempty_nm = true;
    Controller_DWork.obj_a.SampleTime = Controller_P.D_vel_z_SampleTime;
    Controller_DWork.obj_a.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv5[i] = tmp_a[i];
    }

    Controller_B.cv5[26] = '\x00';
    ParamGet_Controller_575.initialize(Controller_B.cv5,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S56>/D_vel_z'

    // Start for MATLABSystem: '<S56>/N_vel_z '
    Controller_DWork.obj_h.isInitialized = 0;
    Controller_DWork.objisempty_e = true;
    Controller_DWork.obj_h.SampleTime = Controller_P.N_vel_z_SampleTime;
    Controller_DWork.obj_h.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv5[i] = tmp_9[i];
    }

    Controller_B.cv5[26] = '\x00';
    ParamGet_Controller_577.initialize(Controller_B.cv5,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S56>/N_vel_z '

    // Start for MATLABSystem: '<S56>/I_vel_z'
    Controller_DWork.obj_js.isInitialized = 0;
    Controller_DWork.objisempty_n43 = true;
    Controller_DWork.obj_js.SampleTime = Controller_P.I_vel_z_SampleTime;
    Controller_DWork.obj_js.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv5[i] = tmp_8[i];
    }

    Controller_B.cv5[26] = '\x00';
    ParamGet_Controller_576.initialize(Controller_B.cv5,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S56>/I_vel_z'
    // End of Start for SubSystem: '<Root>/decController'

    // InitializeConditions for Enabled SubSystem: '<Root>/decController'
    // InitializeConditions for DiscreteIntegrator: '<S40>/Integrator'
    Controller_DWork.Integrator_DSTATE = Controller_P.Integrator_IC;

    // InitializeConditions for DiscreteIntegrator: '<S40>/Filter'
    Controller_DWork.Filter_DSTATE = Controller_P.Filter_IC;

    // InitializeConditions for DiscreteIntegrator: '<S43>/Integrator'
    Controller_DWork.Integrator_DSTATE_h = Controller_P.Integrator_IC_o;

    // InitializeConditions for DiscreteIntegrator: '<S43>/Filter'
    Controller_DWork.Filter_DSTATE_c = Controller_P.Filter_IC_n;

    // InitializeConditions for DiscreteIntegrator: '<S46>/Integrator'
    Controller_DWork.Integrator_DSTATE_a = Controller_P.Integrator_IC_d;

    // InitializeConditions for DiscreteIntegrator: '<S46>/Filter'
    Controller_DWork.Filter_DSTATE_f = Controller_P.Filter_IC_c;

    // InitializeConditions for DiscreteIntegrator: '<S49>/Integrator'
    Controller_DWork.Integrator_DSTATE_f = Controller_P.Integrator_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S49>/Filter'
    Controller_DWork.Filter_DSTATE_a = Controller_P.Filter_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S52>/Integrator'
    Controller_DWork.Integrator_DSTATE_n = Controller_P.Integrator_IC_i;

    // InitializeConditions for DiscreteIntegrator: '<S52>/Filter'
    Controller_DWork.Filter_DSTATE_g = Controller_P.Filter_IC_jx;

    // InitializeConditions for DiscreteIntegrator: '<S55>/Integrator'
    Controller_DWork.Integrator_DSTATE_ny = Controller_P.Integrator_IC_m;

    // InitializeConditions for DiscreteIntegrator: '<S55>/Filter'
    Controller_DWork.Filter_DSTATE_cw = Controller_P.Filter_IC_p;

    // End of InitializeConditions for SubSystem: '<Root>/decController'

    // Start for Enabled SubSystem: '<Root>/decController'
    // VirtualOutportStart for Outport: '<S9>/velocites [angular xyz, linear xyz]' 
    Controller_B.Saturate = Controller_P.velocitesangularxyzlinearxyz_Y0;
    Controller_B.Saturate_f = Controller_P.velocitesangularxyzlinearxyz_Y0;
    Controller_B.Saturate_i = Controller_P.velocitesangularxyzlinearxyz_Y0;
    Controller_B.Saturate_b = Controller_P.velocitesangularxyzlinearxyz_Y0;
    Controller_B.Saturate_h = Controller_P.velocitesangularxyzlinearxyz_Y0;
    Controller_B.Saturate_bk = Controller_P.velocitesangularxyzlinearxyz_Y0;

    // End of Start for SubSystem: '<Root>/decController'

    // Start for MATLABSystem: '<S4>/Get buoyancy'
    Controller_DWork.obj_l0.isInitialized = 0;
    Controller_DWork.objisempty_ig = true;
    Controller_DWork.obj_l0.SampleTime = Controller_P.Getbuoyancy_SampleTime_l;
    Controller_DWork.obj_l0.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv1[i] = tmp_7[i];
    }

    Controller_B.cv1[35] = '\x00';
    ParamGet_Controller_873.initialize(Controller_B.cv1,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S4>/Get buoyancy'

    // Start for Enabled SubSystem: '<Root>/toPWM'
    // Start for MATLABSystem: '<S62>/Get Parameter'
    Controller_DWork.obj.isInitialized = 0;
    Controller_DWork.objisempty_n = true;
    Controller_DWork.obj.SampleTime = Controller_P.GetParameter_SampleTime;
    Controller_DWork.obj.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv1[i] = tmp_6[i];
    }

    Controller_B.cv1[35] = '\x00';
    ParamGet_Controller_858.initialize(Controller_B.cv1,
      Con_ParameterInitialValue_l5xxx, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S62>/Get Parameter'

    // Start for MATLABSystem: '<S62>/Get Parameter1'
    Controller_DWork.obj_l.isInitialized = 0;
    Controller_DWork.objisempty_p = true;
    Controller_DWork.obj_l.SampleTime = Controller_P.GetParameter1_SampleTime;
    Controller_DWork.obj_l.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv1[i] = tmp_5[i];
    }

    Controller_B.cv1[35] = '\x00';
    ParamGet_Controller_861.initialize(Controller_B.cv1,
      Con_ParameterInitialValue_l5xxx, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S62>/Get Parameter1'

    // Start for MATLABSystem: '<S62>/Get Parameter2'
    Controller_DWork.obj_n.isInitialized = 0;
    Controller_DWork.objisempty_l = true;
    Controller_DWork.obj_n.SampleTime = Controller_P.GetParameter2_SampleTime;
    Controller_DWork.obj_n.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv1[i] = tmp_4[i];
    }

    Controller_B.cv1[35] = '\x00';
    ParamGet_Controller_862.initialize(Controller_B.cv1,
      Con_ParameterInitialValue_l5xxx, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S62>/Get Parameter2'

    // Start for MATLABSystem: '<S62>/Get Parameter3'
    Controller_DWork.obj_c.isInitialized = 0;
    Controller_DWork.objisempty_n4 = true;
    Controller_DWork.obj_c.SampleTime = Controller_P.GetParameter3_SampleTime;
    Controller_DWork.obj_c.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv1[i] = tmp_3[i];
    }

    Controller_B.cv1[35] = '\x00';
    ParamGet_Controller_863.initialize(Controller_B.cv1,
      Con_ParameterInitialValue_l5xxx, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S62>/Get Parameter3'

    // Start for MATLABSystem: '<S62>/Get Parameter4'
    Controller_DWork.obj_nt.isInitialized = 0;
    Controller_DWork.objisempty_ns = true;
    Controller_DWork.obj_nt.SampleTime = Controller_P.GetParameter4_SampleTime;
    Controller_DWork.obj_nt.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv1[i] = tmp_2[i];
    }

    Controller_B.cv1[35] = '\x00';
    ParamGet_Controller_864.initialize(Controller_B.cv1,
      Con_ParameterInitialValue_l5xxx, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S62>/Get Parameter4'

    // Start for MATLABSystem: '<S62>/Get Parameter5'
    Controller_DWork.obj_ls.isInitialized = 0;
    Controller_DWork.objisempty_a = true;
    Controller_DWork.obj_ls.SampleTime = Controller_P.GetParameter5_SampleTime;
    Controller_DWork.obj_ls.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv1[i] = tmp_1[i];
    }

    Controller_B.cv1[35] = '\x00';
    ParamGet_Controller_865.initialize(Controller_B.cv1,
      Con_ParameterInitialValue_l5xxx, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S62>/Get Parameter5'

    // Start for Atomic SubSystem: '<S12>/Publish'
    // Start for MATLABSystem: '<S64>/SinkBlock'
    Controller_DWork.obj_pw.isInitialized = 0;
    Controller_DWork.objisempty = true;
    Controller_DWork.obj_pw.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      Controller_B.cv9[i] = tmp_0[i];
    }

    Controller_B.cv9[16] = '\x00';
    Pub_Controller_607.create_publisher(Controller_B.cv9,
      Controller_MessageQueueLen_l);

    // End of Start for MATLABSystem: '<S64>/SinkBlock'
    // End of Start for SubSystem: '<S12>/Publish'
    // End of Start for SubSystem: '<Root>/toPWM'

    // Start for MATLABSystem: '<S7>/Get alpha'
    Controller_DWork.obj_hx.isInitialized = 0;
    Controller_DWork.objisempty_g0 = true;
    Controller_DWork.obj_hx.SampleTime = Controller_P.Getalpha_SampleTime;
    Controller_DWork.obj_hx.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      Controller_B.cv6[i] = tmp[i];
    }

    Controller_B.cv6[24] = '\x00';
    ParamGet_Controller_687.initialize(Controller_B.cv6,
      Contro_ParameterInitialValue_l5, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S7>/Get alpha'

    // InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' 
    Controller_DWork.DiscreteTimeIntegrator_DSTATE =
      Controller_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' 
    Controller_DWork.DiscreteTimeIntegrator1_DSTATE =
      Controller_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator2' 
    Controller_DWork.DiscreteTimeIntegrator2_DSTATE =
      Controller_P.DiscreteTimeIntegrator2_IC;

    // InitializeConditions for DiscreteFilter: '<S7>/Discrete Filter'
    Controller_DWork.DiscreteFilter_denStates =
      Controller_P.DiscreteFilter_InitialDenominat;

    // InitializeConditions for DiscreteFilter: '<S7>/Discrete Filter1'
    Controller_DWork.DiscreteFilter1_denStates =
      Controller_P.DiscreteFilter1_InitialDenomina;

    // InitializeConditions for DiscreteFilter: '<S7>/Discrete Filter2'
    Controller_DWork.DiscreteFilter2_denStates =
      Controller_P.DiscreteFilter2_InitialDenomina;
  }
}

// Model terminate function
void ControllerModelClass::terminate()
{
  // Start for MATLABSystem: '<Root>/Get test' incorporates:
  //   Terminate for MATLABSystem: '<Root>/Get test'

  if (Controller_DWork.obj_h2.isInitialized == 1) {
    Controller_DWork.obj_h2.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/Get test'

  // Terminate for Enabled SubSystem: '<Root>/Telegraph'
  // Start for MATLABSystem: '<S15>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S15>/Swtiching factor'

  if (Controller_DWork.obj_of.isInitialized == 1) {
    Controller_DWork.obj_of.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S15>/Swtiching factor'

  // Start for MATLABSystem: '<S15>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S15>/Swtiching factor1'

  if (Controller_DWork.obj_fx.isInitialized == 1) {
    Controller_DWork.obj_fx.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S15>/Swtiching factor1'

  // Start for MATLABSystem: '<S15>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S15>/Swtiching factor2'

  if (Controller_DWork.obj_d3.isInitialized == 1) {
    Controller_DWork.obj_d3.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S15>/Swtiching factor2'

  // Start for MATLABSystem: '<S16>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S16>/Swtiching factor'

  if (Controller_DWork.obj_i.isInitialized == 1) {
    Controller_DWork.obj_i.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S16>/Swtiching factor'

  // Start for MATLABSystem: '<S16>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S16>/Swtiching factor1'

  if (Controller_DWork.obj_j5.isInitialized == 1) {
    Controller_DWork.obj_j5.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S16>/Swtiching factor1'

  // Start for MATLABSystem: '<S16>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S16>/Swtiching factor2'

  if (Controller_DWork.obj_fu.isInitialized == 1) {
    Controller_DWork.obj_fu.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S16>/Swtiching factor2'

  // Start for MATLABSystem: '<S17>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S17>/Swtiching factor'

  if (Controller_DWork.obj_o.isInitialized == 1) {
    Controller_DWork.obj_o.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S17>/Swtiching factor'

  // Start for MATLABSystem: '<S17>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S17>/Swtiching factor1'

  if (Controller_DWork.obj_f.isInitialized == 1) {
    Controller_DWork.obj_f.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S17>/Swtiching factor1'

  // Start for MATLABSystem: '<S17>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S17>/Swtiching factor2'

  if (Controller_DWork.obj_mb.isInitialized == 1) {
    Controller_DWork.obj_mb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S17>/Swtiching factor2'

  // Start for MATLABSystem: '<S18>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S18>/Swtiching factor'

  if (Controller_DWork.obj_gv.isInitialized == 1) {
    Controller_DWork.obj_gv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S18>/Swtiching factor'

  // Start for MATLABSystem: '<S18>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S18>/Swtiching factor1'

  if (Controller_DWork.obj_c2.isInitialized == 1) {
    Controller_DWork.obj_c2.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S18>/Swtiching factor1'

  // Start for MATLABSystem: '<S18>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S18>/Swtiching factor2'

  if (Controller_DWork.obj_g0e.isInitialized == 1) {
    Controller_DWork.obj_g0e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S18>/Swtiching factor2'

  // Start for MATLABSystem: '<S19>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S19>/Swtiching factor'

  if (Controller_DWork.obj_j0.isInitialized == 1) {
    Controller_DWork.obj_j0.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S19>/Swtiching factor'

  // Start for MATLABSystem: '<S19>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S19>/Swtiching factor1'

  if (Controller_DWork.obj_hr.isInitialized == 1) {
    Controller_DWork.obj_hr.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S19>/Swtiching factor1'

  // Start for MATLABSystem: '<S19>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S19>/Swtiching factor2'

  if (Controller_DWork.obj_dn.isInitialized == 1) {
    Controller_DWork.obj_dn.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S19>/Swtiching factor2'

  // Start for MATLABSystem: '<S20>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S20>/Swtiching factor'

  if (Controller_DWork.obj_gf.isInitialized == 1) {
    Controller_DWork.obj_gf.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S20>/Swtiching factor'

  // Start for MATLABSystem: '<S20>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S20>/Swtiching factor1'

  if (Controller_DWork.obj_cvy.isInitialized == 1) {
    Controller_DWork.obj_cvy.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S20>/Swtiching factor1'

  // Start for MATLABSystem: '<S20>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S20>/Swtiching factor2'

  if (Controller_DWork.obj_dt.isInitialized == 1) {
    Controller_DWork.obj_dt.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S20>/Swtiching factor2'
  // End of Terminate for SubSystem: '<Root>/Telegraph'

  // Start for MATLABSystem: '<Root>/Get controller type' incorporates:
  //   Terminate for MATLABSystem: '<Root>/Get controller type'

  if (Controller_DWork.obj_nl.isInitialized == 1) {
    Controller_DWork.obj_nl.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/Get controller type'

  // Terminate for Atomic SubSystem: '<Root>/cmd_vel'
  // Start for MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S8>/SourceBlock'

  if (Controller_DWork.obj_nf.isInitialized == 1) {
    Controller_DWork.obj_nf.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/cmd_vel'

  // Terminate for Atomic SubSystem: '<Root>/imu_data'
  // Start for MATLABSystem: '<S10>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S10>/SourceBlock'

  if (Controller_DWork.obj_k.isInitialized == 1) {
    Controller_DWork.obj_k.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S10>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/imu_data'

  // Start for MATLABSystem: '<S3>/Get buoyancy' incorporates:
  //   Terminate for MATLABSystem: '<S3>/Get buoyancy'

  if (Controller_DWork.obj_fe.isInitialized == 1) {
    Controller_DWork.obj_fe.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/Get buoyancy'

  // Start for MATLABSystem: '<S7>/Enable integration?' incorporates:
  //   Terminate for MATLABSystem: '<S7>/Enable integration?'

  if (Controller_DWork.obj_g0.isInitialized == 1) {
    Controller_DWork.obj_g0.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/Enable integration?'

  // Terminate for Enabled SubSystem: '<Root>/decController'
  // Start for MATLABSystem: '<S41>/P_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S41>/P_angular_vel_x'

  if (Controller_DWork.obj_bm.isInitialized == 1) {
    Controller_DWork.obj_bm.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S41>/P_angular_vel_x'

  // Start for MATLABSystem: '<S41>/D_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S41>/D_angular_vel_x'

  if (Controller_DWork.obj_be.isInitialized == 1) {
    Controller_DWork.obj_be.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S41>/D_angular_vel_x'

  // Start for MATLABSystem: '<S41>/N_angular_vel_x ' incorporates:
  //   Terminate for MATLABSystem: '<S41>/N_angular_vel_x '

  if (Controller_DWork.obj_lb.isInitialized == 1) {
    Controller_DWork.obj_lb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S41>/N_angular_vel_x '

  // Start for MATLABSystem: '<S41>/I_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S41>/I_angular_vel_x'

  if (Controller_DWork.obj_pb.isInitialized == 1) {
    Controller_DWork.obj_pb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S41>/I_angular_vel_x'

  // Start for MATLABSystem: '<S44>/P_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S44>/P_angular_vel_y'

  if (Controller_DWork.obj_b.isInitialized == 1) {
    Controller_DWork.obj_b.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S44>/P_angular_vel_y'

  // Start for MATLABSystem: '<S44>/D_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S44>/D_angular_vel_y'

  if (Controller_DWork.obj_m.isInitialized == 1) {
    Controller_DWork.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S44>/D_angular_vel_y'

  // Start for MATLABSystem: '<S44>/N_angular_vel_y ' incorporates:
  //   Terminate for MATLABSystem: '<S44>/N_angular_vel_y '

  if (Controller_DWork.obj_dp.isInitialized == 1) {
    Controller_DWork.obj_dp.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S44>/N_angular_vel_y '

  // Start for MATLABSystem: '<S44>/I_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S44>/I_angular_vel_y'

  if (Controller_DWork.obj_ep.isInitialized == 1) {
    Controller_DWork.obj_ep.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S44>/I_angular_vel_y'

  // Start for MATLABSystem: '<S47>/P_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S47>/P_angular_vel_z'

  if (Controller_DWork.obj_e.isInitialized == 1) {
    Controller_DWork.obj_e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S47>/P_angular_vel_z'

  // Start for MATLABSystem: '<S47>/D_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S47>/D_angular_vel_z'

  if (Controller_DWork.obj_jg.isInitialized == 1) {
    Controller_DWork.obj_jg.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S47>/D_angular_vel_z'

  // Start for MATLABSystem: '<S47>/N_angular_vel_z ' incorporates:
  //   Terminate for MATLABSystem: '<S47>/N_angular_vel_z '

  if (Controller_DWork.obj_g.isInitialized == 1) {
    Controller_DWork.obj_g.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S47>/N_angular_vel_z '

  // Start for MATLABSystem: '<S47>/I_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S47>/I_angular_vel_z'

  if (Controller_DWork.obj_p.isInitialized == 1) {
    Controller_DWork.obj_p.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S47>/I_angular_vel_z'

  // Start for MATLABSystem: '<S50>/P_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S50>/P_vel_x'

  if (Controller_DWork.obj_ns.isInitialized == 1) {
    Controller_DWork.obj_ns.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S50>/P_vel_x'

  // Start for MATLABSystem: '<S50>/D_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S50>/D_vel_x'

  if (Controller_DWork.obj_d.isInitialized == 1) {
    Controller_DWork.obj_d.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S50>/D_vel_x'

  // Start for MATLABSystem: '<S50>/N_vel_x ' incorporates:
  //   Terminate for MATLABSystem: '<S50>/N_vel_x '

  if (Controller_DWork.obj_a3.isInitialized == 1) {
    Controller_DWork.obj_a3.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S50>/N_vel_x '

  // Start for MATLABSystem: '<S50>/I_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S50>/I_vel_x'

  if (Controller_DWork.obj_cv.isInitialized == 1) {
    Controller_DWork.obj_cv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S50>/I_vel_x'

  // Start for MATLABSystem: '<S53>/P_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S53>/P_vel_y'

  if (Controller_DWork.obj_ji.isInitialized == 1) {
    Controller_DWork.obj_ji.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S53>/P_vel_y'

  // Start for MATLABSystem: '<S53>/D_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S53>/D_vel_y'

  if (Controller_DWork.obj_ny.isInitialized == 1) {
    Controller_DWork.obj_ny.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S53>/D_vel_y'

  // Start for MATLABSystem: '<S53>/N_vel_y ' incorporates:
  //   Terminate for MATLABSystem: '<S53>/N_vel_y '

  if (Controller_DWork.obj_cb.isInitialized == 1) {
    Controller_DWork.obj_cb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S53>/N_vel_y '

  // Start for MATLABSystem: '<S53>/I_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S53>/I_vel_y'

  if (Controller_DWork.obj_jx.isInitialized == 1) {
    Controller_DWork.obj_jx.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S53>/I_vel_y'

  // Start for MATLABSystem: '<S56>/P_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S56>/P_vel_z'

  if (Controller_DWork.obj_j.isInitialized == 1) {
    Controller_DWork.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S56>/P_vel_z'

  // Start for MATLABSystem: '<S56>/D_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S56>/D_vel_z'

  if (Controller_DWork.obj_a.isInitialized == 1) {
    Controller_DWork.obj_a.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S56>/D_vel_z'

  // Start for MATLABSystem: '<S56>/N_vel_z ' incorporates:
  //   Terminate for MATLABSystem: '<S56>/N_vel_z '

  if (Controller_DWork.obj_h.isInitialized == 1) {
    Controller_DWork.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S56>/N_vel_z '

  // Start for MATLABSystem: '<S56>/I_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S56>/I_vel_z'

  if (Controller_DWork.obj_js.isInitialized == 1) {
    Controller_DWork.obj_js.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S56>/I_vel_z'
  // End of Terminate for SubSystem: '<Root>/decController'

  // Start for MATLABSystem: '<S4>/Get buoyancy' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get buoyancy'

  if (Controller_DWork.obj_l0.isInitialized == 1) {
    Controller_DWork.obj_l0.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get buoyancy'

  // Terminate for Enabled SubSystem: '<Root>/toPWM'
  // Start for MATLABSystem: '<S62>/Get Parameter' incorporates:
  //   Terminate for MATLABSystem: '<S62>/Get Parameter'

  if (Controller_DWork.obj.isInitialized == 1) {
    Controller_DWork.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S62>/Get Parameter'

  // Start for MATLABSystem: '<S62>/Get Parameter1' incorporates:
  //   Terminate for MATLABSystem: '<S62>/Get Parameter1'

  if (Controller_DWork.obj_l.isInitialized == 1) {
    Controller_DWork.obj_l.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S62>/Get Parameter1'

  // Start for MATLABSystem: '<S62>/Get Parameter2' incorporates:
  //   Terminate for MATLABSystem: '<S62>/Get Parameter2'

  if (Controller_DWork.obj_n.isInitialized == 1) {
    Controller_DWork.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S62>/Get Parameter2'

  // Start for MATLABSystem: '<S62>/Get Parameter3' incorporates:
  //   Terminate for MATLABSystem: '<S62>/Get Parameter3'

  if (Controller_DWork.obj_c.isInitialized == 1) {
    Controller_DWork.obj_c.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S62>/Get Parameter3'

  // Start for MATLABSystem: '<S62>/Get Parameter4' incorporates:
  //   Terminate for MATLABSystem: '<S62>/Get Parameter4'

  if (Controller_DWork.obj_nt.isInitialized == 1) {
    Controller_DWork.obj_nt.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S62>/Get Parameter4'

  // Start for MATLABSystem: '<S62>/Get Parameter5' incorporates:
  //   Terminate for MATLABSystem: '<S62>/Get Parameter5'

  if (Controller_DWork.obj_ls.isInitialized == 1) {
    Controller_DWork.obj_ls.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S62>/Get Parameter5'

  // Terminate for Atomic SubSystem: '<S12>/Publish'
  // Start for MATLABSystem: '<S64>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S64>/SinkBlock'

  if (Controller_DWork.obj_pw.isInitialized == 1) {
    Controller_DWork.obj_pw.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S64>/SinkBlock'
  // End of Terminate for SubSystem: '<S12>/Publish'
  // End of Terminate for SubSystem: '<Root>/toPWM'

  // Start for MATLABSystem: '<S7>/Get alpha' incorporates:
  //   Terminate for MATLABSystem: '<S7>/Get alpha'

  if (Controller_DWork.obj_hx.isInitialized == 1) {
    Controller_DWork.obj_hx.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/Get alpha'
}

// Constructor
ControllerModelClass::ControllerModelClass()
{
  static const Parameters_Controller_T Controller_P_temp = {
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
                                       //  Referenced by: '<S4>/Get buoyancy'

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

    0.1,                               // Computed Parameter: Integrator_gainval
                                       //  Referenced by: '<S40>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S40>/Integrator'

    0.1,                               // Computed Parameter: Filter_gainval
                                       //  Referenced by: '<S40>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S40>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S42>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S40>/Constant'

    0.1,                               // Computed Parameter: Integrator_gainval_c
                                       //  Referenced by: '<S43>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S43>/Integrator'

    0.1,                               // Computed Parameter: Filter_gainval_i
                                       //  Referenced by: '<S43>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S43>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S45>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S43>/Constant'

    0.1,                               // Computed Parameter: Integrator_gainval_n
                                       //  Referenced by: '<S46>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S46>/Integrator'

    0.1,                               // Computed Parameter: Filter_gainval_k
                                       //  Referenced by: '<S46>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S46>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S48>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S46>/Constant'

    0.1,                               // Computed Parameter: Integrator_gainval_j
                                       //  Referenced by: '<S49>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S49>/Integrator'

    0.1,                               // Computed Parameter: Filter_gainval_h
                                       //  Referenced by: '<S49>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S49>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S51>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S49>/Constant'

    0.1,                               // Computed Parameter: Integrator_gainval_np
                                       //  Referenced by: '<S52>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S52>/Integrator'

    0.1,                               // Computed Parameter: Filter_gainval_h0
                                       //  Referenced by: '<S52>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S52>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S54>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S52>/Constant'

    0.1,                               // Computed Parameter: Integrator_gainval_m
                                       //  Referenced by: '<S55>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S55>/Integrator'

    0.1,                               // Computed Parameter: Filter_gainval_b
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

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S62>/Get Parameter5'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S62>/Get Parameter4'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S62>/Get Parameter3'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S62>/Get Parameter2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S62>/Get Parameter1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S62>/Get Parameter'

    1.0,                               // Expression: 1
                                       //  Referenced by: '<S12>/Saturation'

    -1.0,                              // Expression: -1
                                       //  Referenced by: '<S12>/Saturation'

    0.1,                               // Computed Parameter: DiscreteTimeIntegrator_gainval
                                       //  Referenced by: '<S7>/Discrete-Time Integrator'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S7>/Discrete-Time Integrator'

    0.1,                               // Computed Parameter: DiscreteTimeIntegrator1_gainval
                                       //  Referenced by: '<S7>/Discrete-Time Integrator1'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S7>/Discrete-Time Integrator1'

    0.1,                               // Computed Parameter: DiscreteTimeIntegrator2_gainval
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
  Controller_P = Controller_P_temp;
}

// Destructor
ControllerModelClass::~ControllerModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Controller_T * ControllerModelClass::getRTM()
{
  return (&Controller_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
