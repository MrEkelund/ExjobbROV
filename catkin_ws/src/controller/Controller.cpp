//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Controller.cpp
//
// Code generated for Simulink model 'Controller'.
//
// Model version                  : 1.185
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Thu Mar 31 10:34:44 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Controller.h"
#include "Controller_private.h"

// Named constants for State Transition Table: '<S31>/State Transition Table'
#define Controller_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define Controller_IN_state1           ((uint8_T)1U)
#define Controller_IN_state2           ((uint8_T)2U)
#define Con_ParameterInitialValue_l5xxx (true)
#define Cont_ParameterInitialValue_l5xx (false)
#define Contr_ParameterInitialValue_l5x (1.0)
#define Contro_ParameterInitialValue_l5 (1)
#define Control_ParameterInitialValue_l (0)
#define Controlle_ParameterInitialValue (0.0)
#define Controller_MessageQueueLen     (1)
#define Controller_MessageQueueLen_l   (10)

//
// Output and update for atomic system:
//    '<S31>/MATLAB Function'
//    '<S32>/MATLAB Function'
//    '<S33>/MATLAB Function'
//    '<S34>/MATLAB Function'
//    '<S35>/MATLAB Function'
//    '<S36>/MATLAB Function'
//
void Controller_MATLABFunction(real_T rtu_u, real_T rtu_min_scale, real_T
  rtu_max_scale, rtB_MATLABFunction_Controller_T *localB)
{
  // MATLAB Function 'Telegraph/Thruster1 block/MATLAB Function': '<S37>:1'
  if (rtu_u < 0.0) {
    // '<S37>:1:4'
    // '<S37>:1:5'
    localB->y = rtu_min_scale * rtu_u;
  } else {
    // '<S37>:1:7'
    localB->y = rtu_max_scale * rtu_u;
  }
}

//
// System initialize for atomic system:
//    '<S31>/State Transition Table'
//    '<S32>/State Transition Table'
//    '<S33>/State Transition Table'
//    '<S34>/State Transition Table'
//    '<S35>/State Transition Table'
//    '<S36>/State Transition Table'
//
void Contr_StateTransitionTable_Init(rtDW_StateTransitionTable_Con_T *localDW)
{
  localDW->is_active_c6_Controller = 0U;
  localDW->is_c6_Controller = Controller_IN_NO_ACTIVE_CHILD;
}

//
// Output and update for atomic system:
//    '<S31>/State Transition Table'
//    '<S32>/State Transition Table'
//    '<S33>/State Transition Table'
//    '<S34>/State Transition Table'
//    '<S35>/State Transition Table'
//    '<S36>/State Transition Table'
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
    // Transition: '<S38>:15'
    localDW->is_c6_Controller = Controller_IN_state1;
  } else if (localDW->is_c6_Controller == Controller_IN_state1) {
    // During 'state1': '<S38>:13'
    if (rtu_x > 0.0) {
      // Transition: '<S38>:17'
      localB->u = 1.0;
      localDW->is_c6_Controller = Controller_IN_state2;
    } else {
      // Transition: '<S38>:19'
      // Transition: '<S38>:21'
      localDW->is_c6_Controller = Controller_IN_state1;
    }
  } else {
    // During 'state2': '<S38>:14'
    if (rtu_x > 0.0) {
      // Transition: '<S38>:18'
      localB->u = -1.0;
      localDW->is_c6_Controller = Controller_IN_state1;
    } else {
      // Transition: '<S38>:23'
      // Transition: '<S38>:25'
      localDW->is_c6_Controller = Controller_IN_state2;
    }
  }
}

//
// Output and update for atomic system:
//    '<Root>/thrust alloc'
//    '<Root>/thrust alloc1'
//
void Controller_thrustalloc(real_T rtu_control_signals, real_T
  rtu_control_signals_n, real_T rtu_control_signals_a, real_T
  rtu_control_signals_o, real_T rtu_control_signals_k, real_T
  rtu_control_signals_f, rtB_thrustalloc_Controller_T *localB)
{
  static const real_T a[36] = { 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, 0.5, -0.5, 0.0,
    0.0, 0.0, -1.0, -0.25, -0.25, 0.0, 0.0, -0.5, 0.0, 0.5, -0.5, 0.0, 0.0, 0.0,
    0.0, 0.25, 0.25, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 0.5, -0.5, 0.0, 0.0 };

  real_T rtu_control_signals_0[6];
  int32_T i;
  int32_T i_0;

  // SignalConversion: '<S13>/TmpSignal ConversionAt SFunction Inport1'
  // MATLAB Function 'thrust alloc': '<S13>:1'
  // '<S13>:1:39'
  //  lx1 = 0.16;
  //  ly1 = 0.11;
  //  ly2 = 0.11;
  //  lx2 = 0.16;
  //  ly3 = 0.11;
  //  lx5 = 0.2;
  //  ly4 = 0.11;
  //  lz6 = 0.1; % Måste mätas
  //
  //  T = [...
  //      0, 0, 1, 1, 0, 0;
  //      0, 0, 0, 0, 0, -1;
  //      -1, -1, 0, 0, -1, 0;
  //      ly1, -ly2, 0, 0, 0, lz6;
  //      lx1, lx2, 0, 0, -lx5, 0;
  //      0, 0, ly3, -ly4, 0, 0];
  //
  //  T = [...
  //          0, 0, 1, 1, 0, 0;
  //      0, 0, 0, 0, 0, -1;
  //      -1, -1, 0, 0, -1, 0;
  //      1, -1, 0, 0, 0, 1;
  //      1, 1, 0, 0, -1, 0;
  //      0, 0, 1, -1, 0, 0];
  //  thrust_allocation = (T.')*inv(T*(T.'));
  // '<S13>:1:39'
  rtu_control_signals_0[0] = rtu_control_signals;
  rtu_control_signals_0[1] = rtu_control_signals_n;
  rtu_control_signals_0[2] = rtu_control_signals_a;
  rtu_control_signals_0[3] = rtu_control_signals_o;
  rtu_control_signals_0[4] = rtu_control_signals_k;
  rtu_control_signals_0[5] = rtu_control_signals_f;
  for (i = 0; i < 6; i++) {
    localB->thrusters[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      localB->thrusters[i] += a[6 * i_0 + i] * rtu_control_signals_0[i_0];
    }
  }
}

void ControllerModelClass::Controller_RandSrc_U_D(real_T y[], const real_T
  minVec[], int32_T minLen, const real_T maxVec[], int32_T maxLen, real_T state[],
  int32_T nChans, int32_T nSamps)
{
  int8_T *onePtr;

  // Start for S-Function (sdsprandsrc2): '<S31>/Random Source'
  // RandSrc_U_D
  Controller_B.one = 1;
  onePtr = (int8_T *)&Controller_B.one;
  Controller_B.lsw = (onePtr[0U] == 0);
  Controller_B.chan = 0;
  while (Controller_B.chan < nChans) {
    Controller_B.min = minVec[minLen > 1 ? Controller_B.chan : 0];
    Controller_B.max = maxVec[maxLen > 1 ? Controller_B.chan : 0];
    Controller_B.max -= Controller_B.min;
    Controller_B.i_b = (int32_T)((uint32_T)state[Controller_B.chan * 35 + 33] &
      31U);
    Controller_B.j = (uint32_T)state[Controller_B.chan * 35 + 34];
    Controller_B.samps = 0;
    while (Controller_B.samps < nSamps) {
      // "Subtract with borrow" generator
      Controller_B.d = state[((Controller_B.i_b + 20) & 31) + Controller_B.chan *
        35];
      Controller_B.d -= state[((Controller_B.i_b + 5) & 31) + Controller_B.chan *
        35];
      Controller_B.d -= state[Controller_B.chan * 35 + 32];
      if (Controller_B.d >= 0.0) {
        state[Controller_B.chan * 35 + 32] = 0.0;
      } else {
        Controller_B.d++;

        // set 1 in LSB
        state[Controller_B.chan * 35 + 32] = 1.1102230246251565E-16;
      }

      state[Controller_B.chan * 35 + Controller_B.i_b] = Controller_B.d;
      Controller_B.i_b = (Controller_B.i_b + 1) & 31;

      // XOR with shift register sequence
      memcpy(&Controller_B.ii[0U], &Controller_B.d, sizeof(real_T));
      Controller_B.ii[Controller_B.lsw] ^= Controller_B.j;
      Controller_B.j ^= Controller_B.j << 13;
      Controller_B.j ^= Controller_B.j >> 17;
      Controller_B.j ^= Controller_B.j << 5;
      Controller_B.ii[Controller_B.lsw ^ 1] ^= Controller_B.j & 1048575U;
      memcpy(&Controller_B.d, &Controller_B.ii[0U], sizeof(real_T));
      y[Controller_B.chan * nSamps + Controller_B.samps] = Controller_B.max *
        Controller_B.d + Controller_B.min;
      Controller_B.samps++;
    }

    state[Controller_B.chan * 35 + 33] = Controller_B.i_b;
    state[Controller_B.chan * 35 + 34] = Controller_B.j;
    Controller_B.chan++;
  }

  // End of Start for S-Function (sdsprandsrc2): '<S31>/Random Source'
}

void RandSrcInitState_U_64(const uint32_T seed[], real_T state[], int32_T nChans)
{
  int32_T i;
  uint32_T j;
  int32_T k;
  int32_T n;
  real_T d;

  // Start for S-Function (sdsprandsrc2): '<S31>/Random Source'
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

  // End of Start for S-Function (sdsprandsrc2): '<S31>/Random Source'
}

void ControllerModelClass::Controlle_RandSrcCreateSeeds_64(uint32_T initSeed,
  uint32_T seedArray[], int32_T numSeeds)
{
  real_T tmp;
  real_T min;
  real_T max;
  int32_T i;

  // Start for S-Function (sdsprandsrc2): '<S31>/Random Source'
  // RandSrcCreateSeeds_64
  min = 0.0;
  max = 1.0;
  RandSrcInitState_U_64(&initSeed, Controller_B.state, 1);
  for (i = 0; i < numSeeds; i++) {
    Controller_RandSrc_U_D(&tmp, &min, 1, &max, 1, Controller_B.state, 1, 1);
    seedArray[i] = (uint32_T)(tmp * 2.147483648E+9);
  }

  // End of Start for S-Function (sdsprandsrc2): '<S31>/Random Source'
}

// Model step function
void ControllerModelClass::step()
{
  static const real_T a[36] = { 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, 0.5, -0.5, 0.0,
    0.0, 0.0, -1.0, -0.25, -0.25, 0.0, 0.0, -0.5, 0.0, 0.5, -0.5, 0.0, 0.0, 0.0,
    0.0, 0.25, 0.25, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 0.5, -0.5, 0.0, 0.0 };

  // Start for MATLABSystem: '<Root>/Get test' incorporates:
  //   MATLABSystem: '<Root>/Get test'

  Controller_B.p = false;
  Controller_B.p_c = true;
  if (!(Controller_DWork.obj_h2.SampleTime == Controller_P.Gettest_SampleTime))
  {
    Controller_B.p_c = false;
  }

  if (Controller_B.p_c) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_h2.SampleTime = Controller_P.Gettest_SampleTime;
  }

  ParamGet_Controller_823.get_parameter(&Controller_B.value);

  // RelationalOperator: '<S1>/Compare' incorporates:
  //   Constant: '<S1>/Constant'
  //   MATLABSystem: '<Root>/Get test'
  //   Start for MATLABSystem: '<Root>/Get test'

  Controller_B.Compare = (Controller_B.value <=
    Controller_P.CompareToConstant_const);

  // Outputs for Enabled SubSystem: '<Root>/Telegraph' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (Controller_B.Compare) {
    // Start for MATLABSystem: '<S6>/Get Parameter' incorporates:
    //   MATLABSystem: '<S6>/Get Parameter'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_fg.SampleTime ==
          Controller_P.GetParameter_SampleTime_g)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_fg.SampleTime =
        Controller_P.GetParameter_SampleTime_g;
    }

    ParamGet_Controller_1018.get_parameter(&Controller_B.value_k);

    // S-Function (sdsprandsrc2): '<S31>/Random Source'
    Controller_RandSrc_U_D(&Controller_B.ChooseControllersignal_c,
      &Controller_P.RandomSource_MinVal, 1, &Controller_P.RandomSource_MaxVal, 1,
      Controller_DWork.RandomSource_STATE_DWORK, 1, 1);

    // Start for MATLABSystem: '<S31>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S31>/Swtiching factor'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_of.SampleTime ==
          Controller_P.Swtichingfactor_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_of.SampleTime =
        Controller_P.Swtichingfactor_SampleTime;
    }

    ParamGet_Controller_714.get_parameter(&Controller_B.value_c);

    // State Transition Table: '<S31>/State Transition Table' incorporates:
    //   Constant: '<S31>/Constant'
    //   MATLABSystem: '<S31>/Swtiching factor'
    //   Start for MATLABSystem: '<S31>/Swtiching factor'
    //   Sum: '<S31>/Add'

    Controller_StateTransitionTable((Controller_B.ChooseControllersignal_c +
      (real_T)Controller_B.value_c) - Controller_P.Constant_Value_f,
      &Controller_B.sf_StateTransitionTable,
      &Controller_DWork.sf_StateTransitionTable);

    // Start for MATLABSystem: '<S31>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S31>/Swtiching factor1'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_fx.SampleTime ==
          Controller_P.Swtichingfactor1_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_fx.SampleTime =
        Controller_P.Swtichingfactor1_SampleTime;
    }

    ParamGet_Controller_715.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S31>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S31>/Swtiching factor2'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_d3.SampleTime ==
          Controller_P.Swtichingfactor2_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_d3.SampleTime =
        Controller_P.Swtichingfactor2_SampleTime;
    }

    ParamGet_Controller_716.get_parameter(&Controller_B.SignPreIntegrator_k);

    // MATLAB Function: '<S31>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S31>/Swtiching factor1'
    //   Start for MATLABSystem: '<S31>/Swtiching factor1'
    //   MATLABSystem: '<S31>/Swtiching factor2'
    //   Start for MATLABSystem: '<S31>/Swtiching factor2'

    Controller_MATLABFunction(Controller_B.sf_StateTransitionTable.u,
      Controller_B.ZeroGain_e, Controller_B.SignPreIntegrator_k,
      &Controller_B.sf_MATLABFunction);

    // S-Function (sdsprandsrc2): '<S32>/Random Source'
    Controller_RandSrc_U_D(&Controller_B.ChooseControllersignal_c,
      &Controller_P.RandomSource_MinVal_h, 1,
      &Controller_P.RandomSource_MaxVal_o, 1,
      Controller_DWork.RandomSource_STATE_DWORK_i, 1, 1);

    // Start for MATLABSystem: '<S32>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S32>/Swtiching factor'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_i.SampleTime ==
          Controller_P.Swtichingfactor_SampleTime_k)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_i.SampleTime =
        Controller_P.Swtichingfactor_SampleTime_k;
    }

    ParamGet_Controller_724.get_parameter(&Controller_B.value_c);

    // State Transition Table: '<S32>/State Transition Table' incorporates:
    //   Constant: '<S32>/Constant'
    //   MATLABSystem: '<S32>/Swtiching factor'
    //   Start for MATLABSystem: '<S32>/Swtiching factor'
    //   Sum: '<S32>/Add'

    Controller_StateTransitionTable((Controller_B.ChooseControllersignal_c +
      (real_T)Controller_B.value_c) - Controller_P.Constant_Value_k,
      &Controller_B.sf_StateTransitionTable_i,
      &Controller_DWork.sf_StateTransitionTable_i);

    // Start for MATLABSystem: '<S32>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S32>/Swtiching factor1'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_j5.SampleTime ==
          Controller_P.Swtichingfactor1_SampleTime_i)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_j5.SampleTime =
        Controller_P.Swtichingfactor1_SampleTime_i;
    }

    ParamGet_Controller_725.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S32>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S32>/Swtiching factor2'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_fu.SampleTime ==
          Controller_P.Swtichingfactor2_SampleTime_b)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_fu.SampleTime =
        Controller_P.Swtichingfactor2_SampleTime_b;
    }

    ParamGet_Controller_726.get_parameter(&Controller_B.SignPreIntegrator_k);

    // MATLAB Function: '<S32>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S32>/Swtiching factor1'
    //   Start for MATLABSystem: '<S32>/Swtiching factor1'
    //   MATLABSystem: '<S32>/Swtiching factor2'
    //   Start for MATLABSystem: '<S32>/Swtiching factor2'

    Controller_MATLABFunction(Controller_B.sf_StateTransitionTable_i.u,
      Controller_B.ZeroGain_e, Controller_B.SignPreIntegrator_k,
      &Controller_B.sf_MATLABFunction_l);

    // MultiPortSwitch: '<S6>/Choose Controller signal' incorporates:
    //   MATLABSystem: '<S6>/Get Parameter'
    //   Start for MATLABSystem: '<S6>/Get Parameter'

    if (Controller_B.value_k == 1) {
      Controller_B.ChooseControllersignal_c = Controller_B.sf_MATLABFunction.y;
    } else {
      Controller_B.ChooseControllersignal_c = Controller_B.sf_MATLABFunction_l.y;
    }

    // End of MultiPortSwitch: '<S6>/Choose Controller signal'

    // S-Function (sdsprandsrc2): '<S33>/Random Source'
    Controller_RandSrc_U_D(&Controller_B.RandomSource,
      &Controller_P.RandomSource_MinVal_b, 1,
      &Controller_P.RandomSource_MaxVal_g, 1,
      Controller_DWork.RandomSource_STATE_DWORK_a, 1, 1);

    // Start for MATLABSystem: '<S33>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S33>/Swtiching factor'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_o.SampleTime ==
          Controller_P.Swtichingfactor_SampleTime_g)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_o.SampleTime =
        Controller_P.Swtichingfactor_SampleTime_g;
    }

    ParamGet_Controller_734.get_parameter(&Controller_B.value_k);

    // State Transition Table: '<S33>/State Transition Table' incorporates:
    //   Constant: '<S33>/Constant'
    //   MATLABSystem: '<S33>/Swtiching factor'
    //   Start for MATLABSystem: '<S33>/Swtiching factor'
    //   Sum: '<S33>/Add'

    Controller_StateTransitionTable((Controller_B.RandomSource + (real_T)
      Controller_B.value_k) - Controller_P.Constant_Value_a,
      &Controller_B.sf_StateTransitionTable_m,
      &Controller_DWork.sf_StateTransitionTable_m);

    // Start for MATLABSystem: '<S33>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S33>/Swtiching factor1'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_f.SampleTime ==
          Controller_P.Swtichingfactor1_SampleTime_o)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_f.SampleTime =
        Controller_P.Swtichingfactor1_SampleTime_o;
    }

    ParamGet_Controller_735.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S33>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S33>/Swtiching factor2'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_mb.SampleTime ==
          Controller_P.Swtichingfactor2_SampleTime_o)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_mb.SampleTime =
        Controller_P.Swtichingfactor2_SampleTime_o;
    }

    ParamGet_Controller_736.get_parameter(&Controller_B.SignPreIntegrator_k);

    // MATLAB Function: '<S33>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S33>/Swtiching factor1'
    //   Start for MATLABSystem: '<S33>/Swtiching factor1'
    //   MATLABSystem: '<S33>/Swtiching factor2'
    //   Start for MATLABSystem: '<S33>/Swtiching factor2'

    Controller_MATLABFunction(Controller_B.sf_StateTransitionTable_m.u,
      Controller_B.ZeroGain_e, Controller_B.SignPreIntegrator_k,
      &Controller_B.sf_MATLABFunction_j);

    // S-Function (sdsprandsrc2): '<S34>/Random Source'
    Controller_RandSrc_U_D(&Controller_B.RandomSource,
      &Controller_P.RandomSource_MinVal_d, 1,
      &Controller_P.RandomSource_MaxVal_d, 1,
      Controller_DWork.RandomSource_STATE_DWORK_g, 1, 1);

    // Start for MATLABSystem: '<S34>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S34>/Swtiching factor'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_gv.SampleTime ==
          Controller_P.Swtichingfactor_SampleTime_n)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_gv.SampleTime =
        Controller_P.Swtichingfactor_SampleTime_n;
    }

    ParamGet_Controller_744.get_parameter(&Controller_B.value_k);

    // State Transition Table: '<S34>/State Transition Table' incorporates:
    //   Constant: '<S34>/Constant'
    //   MATLABSystem: '<S34>/Swtiching factor'
    //   Start for MATLABSystem: '<S34>/Swtiching factor'
    //   Sum: '<S34>/Add'

    Controller_StateTransitionTable((Controller_B.RandomSource + (real_T)
      Controller_B.value_k) - Controller_P.Constant_Value_a4,
      &Controller_B.sf_StateTransitionTable_mx,
      &Controller_DWork.sf_StateTransitionTable_mx);

    // Start for MATLABSystem: '<S34>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S34>/Swtiching factor1'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_c2.SampleTime ==
          Controller_P.Swtichingfactor1_SampleTime_j)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_c2.SampleTime =
        Controller_P.Swtichingfactor1_SampleTime_j;
    }

    ParamGet_Controller_745.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S34>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S34>/Swtiching factor2'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_g0e.SampleTime ==
          Controller_P.Swtichingfactor2_SampleTime_e)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_g0e.SampleTime =
        Controller_P.Swtichingfactor2_SampleTime_e;
    }

    ParamGet_Controller_746.get_parameter(&Controller_B.SignPreIntegrator_k);

    // MATLAB Function: '<S34>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S34>/Swtiching factor1'
    //   Start for MATLABSystem: '<S34>/Swtiching factor1'
    //   MATLABSystem: '<S34>/Swtiching factor2'
    //   Start for MATLABSystem: '<S34>/Swtiching factor2'

    Controller_MATLABFunction(Controller_B.sf_StateTransitionTable_mx.u,
      Controller_B.ZeroGain_e, Controller_B.SignPreIntegrator_k,
      &Controller_B.sf_MATLABFunction_o);

    // S-Function (sdsprandsrc2): '<S35>/Random Source'
    Controller_RandSrc_U_D(&Controller_B.RandomSource,
      &Controller_P.RandomSource_MinVal_n, 1,
      &Controller_P.RandomSource_MaxVal_n, 1,
      Controller_DWork.RandomSource_STATE_DWORK_j, 1, 1);

    // Start for MATLABSystem: '<S35>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S35>/Swtiching factor'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_j0.SampleTime ==
          Controller_P.Swtichingfactor_SampleTime_nq)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_j0.SampleTime =
        Controller_P.Swtichingfactor_SampleTime_nq;
    }

    ParamGet_Controller_850.get_parameter(&Controller_B.value_k);

    // State Transition Table: '<S35>/State Transition Table' incorporates:
    //   Constant: '<S35>/Constant'
    //   MATLABSystem: '<S35>/Swtiching factor'
    //   Start for MATLABSystem: '<S35>/Swtiching factor'
    //   Sum: '<S35>/Add'

    Controller_StateTransitionTable((Controller_B.RandomSource + (real_T)
      Controller_B.value_k) - Controller_P.Constant_Value_dg,
      &Controller_B.sf_StateTransitionTable_o,
      &Controller_DWork.sf_StateTransitionTable_o);

    // Start for MATLABSystem: '<S35>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S35>/Swtiching factor1'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_hr.SampleTime ==
          Controller_P.Swtichingfactor1_SampleTime_a)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_hr.SampleTime =
        Controller_P.Swtichingfactor1_SampleTime_a;
    }

    ParamGet_Controller_851.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S35>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S35>/Swtiching factor2'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_dn.SampleTime ==
          Controller_P.Swtichingfactor2_SampleTime_n)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_dn.SampleTime =
        Controller_P.Swtichingfactor2_SampleTime_n;
    }

    ParamGet_Controller_852.get_parameter(&Controller_B.SignPreIntegrator_k);

    // MATLAB Function: '<S35>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S35>/Swtiching factor1'
    //   Start for MATLABSystem: '<S35>/Swtiching factor1'
    //   MATLABSystem: '<S35>/Swtiching factor2'
    //   Start for MATLABSystem: '<S35>/Swtiching factor2'

    Controller_MATLABFunction(Controller_B.sf_StateTransitionTable_o.u,
      Controller_B.ZeroGain_e, Controller_B.SignPreIntegrator_k,
      &Controller_B.sf_MATLABFunction_e);

    // S-Function (sdsprandsrc2): '<S36>/Random Source'
    Controller_RandSrc_U_D(&Controller_B.RandomSource,
      &Controller_P.RandomSource_MinVal_i, 1,
      &Controller_P.RandomSource_MaxVal_i, 1,
      Controller_DWork.RandomSource_STATE_DWORK_h, 1, 1);

    // Start for MATLABSystem: '<S36>/Swtiching factor' incorporates:
    //   MATLABSystem: '<S36>/Swtiching factor'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_gf.SampleTime ==
          Controller_P.Swtichingfactor_SampleTime_f)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_gf.SampleTime =
        Controller_P.Swtichingfactor_SampleTime_f;
    }

    ParamGet_Controller_764.get_parameter(&Controller_B.value_k);

    // State Transition Table: '<S36>/State Transition Table' incorporates:
    //   Constant: '<S36>/Constant'
    //   MATLABSystem: '<S36>/Swtiching factor'
    //   Start for MATLABSystem: '<S36>/Swtiching factor'
    //   Sum: '<S36>/Add'

    Controller_StateTransitionTable((Controller_B.RandomSource + (real_T)
      Controller_B.value_k) - Controller_P.Constant_Value_fo,
      &Controller_B.sf_StateTransitionTable_o2,
      &Controller_DWork.sf_StateTransitionTable_o2);

    // Start for MATLABSystem: '<S36>/Swtiching factor1' incorporates:
    //   MATLABSystem: '<S36>/Swtiching factor1'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_cvy.SampleTime ==
          Controller_P.Swtichingfactor1_SampleTime_e)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_cvy.SampleTime =
        Controller_P.Swtichingfactor1_SampleTime_e;
    }

    ParamGet_Controller_765.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S36>/Swtiching factor2' incorporates:
    //   MATLABSystem: '<S36>/Swtiching factor2'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_dt.SampleTime ==
          Controller_P.Swtichingfactor2_SampleTime_c)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_dt.SampleTime =
        Controller_P.Swtichingfactor2_SampleTime_c;
    }

    ParamGet_Controller_766.get_parameter(&Controller_B.SignPreIntegrator_k);

    // MATLAB Function: '<S36>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S36>/Swtiching factor1'
    //   Start for MATLABSystem: '<S36>/Swtiching factor1'
    //   MATLABSystem: '<S36>/Swtiching factor2'
    //   Start for MATLABSystem: '<S36>/Swtiching factor2'

    Controller_MATLABFunction(Controller_B.sf_StateTransitionTable_o2.u,
      Controller_B.ZeroGain_e, Controller_B.SignPreIntegrator_k,
      &Controller_B.sf_MATLABFunction_i);

    // SignalConversion: '<S6>/OutportBufferForThrusters'
    Controller_B.OutportBufferForThrusters[0] = Controller_B.sf_MATLABFunction.y;
    Controller_B.OutportBufferForThrusters[1] =
      Controller_B.ChooseControllersignal_c;
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
  Controller_B.p_c = true;
  if (!(Controller_DWork.obj_nl.SampleTime ==
        Controller_P.Getcontrollertype_SampleTime)) {
    Controller_B.p_c = false;
  }

  if (Controller_B.p_c) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_nl.SampleTime =
      Controller_P.Getcontrollertype_SampleTime;
  }

  ParamGet_Controller_106.get_parameter(&Controller_B.value_k);

  // Outputs for Atomic SubSystem: '<Root>/cmd_vel'
  // Start for MATLABSystem: '<S9>/SourceBlock' incorporates:
  //   Inport: '<S49>/In1'
  //   MATLABSystem: '<S9>/SourceBlock'

  Controller_B.p = Sub_Controller_1.getLatestMessage(&Controller_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S49>/Enable'

  if (Controller_B.p) {
    Controller_B.In1_m = Controller_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/cmd_vel'

  // Outputs for Atomic SubSystem: '<Root>/imu_data'
  // Start for MATLABSystem: '<S11>/SourceBlock' incorporates:
  //   Inport: '<S74>/In1'
  //   MATLABSystem: '<S11>/SourceBlock'

  Controller_B.p_c = Sub_Controller_28.getLatestMessage
    (&Controller_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S11>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S74>/Enable'

  if (Controller_B.p_c) {
    Controller_B.In1 = Controller_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S11>/Enabled Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/cmd_vel'
  // Logic: '<Root>/Logical Operator' incorporates:
  //   MATLABSystem: '<S11>/SourceBlock'
  //   Start for MATLABSystem: '<S11>/SourceBlock'
  //   MATLABSystem: '<S9>/SourceBlock'
  //   Start for MATLABSystem: '<S9>/SourceBlock'

  Controller_B.LogicalOperator = (Controller_B.p || Controller_B.p_c);

  // End of Outputs for SubSystem: '<Root>/cmd_vel'
  // End of Outputs for SubSystem: '<Root>/imu_data'

  // Outputs for Enabled SubSystem: '<Root>/Xbox_input' incorporates:
  //   EnablePort: '<S7>/Enable'

  if (Controller_B.LogicalOperator) {
    // SignalConversion: '<S7>/TmpSignal ConversionAtBus SelectorOutport1'
    Controller_B.X_h = Controller_B.In1_m.Linear.X;

    // SignalConversion: '<S7>/TmpSignal ConversionAtBus SelectorOutport2'
    Controller_B.Y_i = Controller_B.In1_m.Linear.Y;

    // SignalConversion: '<S7>/TmpSignal ConversionAtBus SelectorOutport3'
    Controller_B.Z = Controller_B.In1_m.Linear.Z;

    // SignalConversion: '<S7>/TmpSignal ConversionAtBus SelectorOutport4'
    Controller_B.X_hw = Controller_B.In1_m.Angular.X;

    // SignalConversion: '<S7>/TmpSignal ConversionAtBus SelectorOutport5'
    Controller_B.Y_in = Controller_B.In1_m.Angular.Y;

    // SignalConversion: '<S7>/TmpSignal ConversionAtBus SelectorOutport6'
    Controller_B.Z_n = Controller_B.In1_m.Angular.Z;
  }

  // End of Outputs for SubSystem: '<Root>/Xbox_input'

  // MATLAB Function: '<Root>/thrust alloc'
  Controller_thrustalloc(Controller_B.X_h, Controller_B.Y_i, Controller_B.Z,
    Controller_B.X_hw, Controller_B.Y_in, Controller_B.Z_n,
    &Controller_B.sf_thrustalloc);

  // Start for MATLABSystem: '<Root>/yaw_ref' incorporates:
  //   MATLABSystem: '<Root>/yaw_ref'

  Controller_B.p = false;
  Controller_B.p_c = true;
  if (!(Controller_DWork.obj_o5.SampleTime == Controller_P.yaw_ref_SampleTime))
  {
    Controller_B.p_c = false;
  }

  if (Controller_B.p_c) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_o5.SampleTime = Controller_P.yaw_ref_SampleTime;
  }

  ParamGet_Controller_981.get_parameter(&Controller_B.ZeroGain_e);

  // Start for MATLABSystem: '<Root>/pitch_ref' incorporates:
  //   MATLABSystem: '<Root>/pitch_ref'

  Controller_B.p = false;
  Controller_B.p_c = true;
  if (!(Controller_DWork.obj_mbl.SampleTime == Controller_P.pitch_ref_SampleTime))
  {
    Controller_B.p_c = false;
  }

  if (Controller_B.p_c) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_mbl.SampleTime = Controller_P.pitch_ref_SampleTime;
  }

  ParamGet_Controller_982.get_parameter(&Controller_B.SignPreIntegrator_k);

  // Start for MATLABSystem: '<Root>/roll_ref' incorporates:
  //   MATLABSystem: '<Root>/roll_ref'

  Controller_B.p = false;
  Controller_B.p_c = true;
  if (!(Controller_DWork.obj_pk.SampleTime == Controller_P.roll_ref_SampleTime))
  {
    Controller_B.p_c = false;
  }

  if (Controller_B.p_c) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_pk.SampleTime = Controller_P.roll_ref_SampleTime;
  }

  ParamGet_Controller_980.get_parameter(&Controller_B.ChooseControllersignal_c);

  // Outputs for Enabled SubSystem: '<Root>/states' incorporates:
  //   EnablePort: '<S12>/Enable'

  // Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S4>/Enable'

  if (Controller_B.LogicalOperator) {
    // Start for MATLABSystem: '<S4>/Get Parameter' incorporates:
    //   MATLABSystem: '<S4>/Get Parameter'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_km.SampleTime ==
          Controller_P.GetParameter_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_km.SampleTime = Controller_P.GetParameter_SampleTime;
    }

    ParamGet_Controller_901.get_parameter(&Controller_B.RandomSource);

    // Product: '<S4>/Product' incorporates:
    //   MATLABSystem: '<S4>/Get Parameter'
    //   Start for MATLABSystem: '<S4>/Get Parameter'

    Controller_B.Product = Controller_B.RandomSource * Controller_B.X_hw;

    // Start for MATLABSystem: '<S4>/Get Parameter1' incorporates:
    //   MATLABSystem: '<S4>/Get Parameter1'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_oz.SampleTime ==
          Controller_P.GetParameter1_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_oz.SampleTime = Controller_P.GetParameter1_SampleTime;
    }

    ParamGet_Controller_905.get_parameter(&Controller_B.RandomSource);

    // Product: '<S4>/Product1' incorporates:
    //   MATLABSystem: '<S4>/Get Parameter1'
    //   Start for MATLABSystem: '<S4>/Get Parameter1'

    Controller_B.Product1 = Controller_B.RandomSource * Controller_B.Y_in;

    // Start for MATLABSystem: '<S4>/Get Parameter2' incorporates:
    //   MATLABSystem: '<S4>/Get Parameter2'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_iv.SampleTime ==
          Controller_P.GetParameter2_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_iv.SampleTime = Controller_P.GetParameter2_SampleTime;
    }

    ParamGet_Controller_907.get_parameter(&Controller_B.RandomSource);

    // Product: '<S4>/Product2' incorporates:
    //   MATLABSystem: '<S4>/Get Parameter2'
    //   Start for MATLABSystem: '<S4>/Get Parameter2'

    Controller_B.Product2 = Controller_B.RandomSource * Controller_B.Z_n;

    // Start for MATLABSystem: '<S4>/Get Parameter3' incorporates:
    //   MATLABSystem: '<S4>/Get Parameter3'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_dy.SampleTime ==
          Controller_P.GetParameter3_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_dy.SampleTime = Controller_P.GetParameter3_SampleTime;
    }

    ParamGet_Controller_909.get_parameter(&Controller_B.RandomSource);

    // Product: '<S4>/Product3' incorporates:
    //   MATLABSystem: '<S4>/Get Parameter3'
    //   Start for MATLABSystem: '<S4>/Get Parameter3'

    Controller_B.Product3 = Controller_B.RandomSource * Controller_B.X_h;

    // Start for MATLABSystem: '<S4>/Get Parameter4' incorporates:
    //   MATLABSystem: '<S4>/Get Parameter4'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_kg.SampleTime ==
          Controller_P.GetParameter4_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_kg.SampleTime = Controller_P.GetParameter4_SampleTime;
    }

    ParamGet_Controller_911.get_parameter(&Controller_B.RandomSource);

    // Product: '<S4>/Product4' incorporates:
    //   MATLABSystem: '<S4>/Get Parameter4'
    //   Start for MATLABSystem: '<S4>/Get Parameter4'

    Controller_B.Product4 = Controller_B.RandomSource * Controller_B.Y_i;

    // Start for MATLABSystem: '<S4>/Get Parameter5' incorporates:
    //   MATLABSystem: '<S4>/Get Parameter5'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_ku.SampleTime ==
          Controller_P.GetParameter5_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_ku.SampleTime = Controller_P.GetParameter5_SampleTime;
    }

    ParamGet_Controller_913.get_parameter(&Controller_B.RandomSource);

    // Product: '<S4>/Product5' incorporates:
    //   MATLABSystem: '<S4>/Get Parameter5'
    //   Start for MATLABSystem: '<S4>/Get Parameter5'

    Controller_B.Product5 = Controller_B.RandomSource * Controller_B.Z;

    // SignalConversion: '<S12>/TmpSignal ConversionAtBus SelectorOutport1'
    memcpy(&Controller_B.Data[0], &Controller_B.In1.Data[0], 10U * sizeof(real_T));

    // MATLAB Function: '<S12>/removeGravity'
    // MATLAB Function 'states/removeGravity': '<S75>:1'
    // '<S75>:1:23'
    //  rotmatrix = [2*w^2+2*x^2-1, 2*x*y-2*w*z, 2*x*z+2*w*y;
    //      2*x*y+2*w*z, 2*w^2+2*y^2-1, 2*x*z-2*w*x;
    //      2*x*z-2*w*y, 2*y*z+2*w*x, 2*w^2+2*z^2-1];
    // '<S75>:1:8'
    Controller_B.sfi = sin(Controller_B.Data[2]);

    // '<S75>:1:9'
    Controller_B.cfi = cos(Controller_B.Data[2]);

    // '<S75>:1:10'
    Controller_B.spsi = sin(Controller_B.Data[0]);

    // '<S75>:1:11'
    Controller_B.cpsi_c = cos(Controller_B.Data[0]);

    // '<S75>:1:12'
    Controller_B.stheta = sin(Controller_B.Data[1]);

    // '<S75>:1:13'
    Controller_B.ctheta = cos(Controller_B.Data[1]);

    // '<S75>:1:16'
    //  Gravity projected in the body fixed frame
    // '<S75>:1:23'
    Controller_B.cpsi[0] = Controller_B.cpsi_c * Controller_B.ctheta;
    Controller_B.cpsi[1] = Controller_B.cpsi_c * Controller_B.stheta *
      Controller_B.sfi + -Controller_B.spsi * Controller_B.cfi;
    Controller_B.cpsi[2] = Controller_B.cpsi_c * Controller_B.cfi *
      Controller_B.stheta + Controller_B.spsi * Controller_B.sfi;
    Controller_B.cpsi[3] = Controller_B.spsi * Controller_B.ctheta;
    Controller_B.cpsi[4] = Controller_B.sfi * Controller_B.stheta *
      Controller_B.spsi + Controller_B.cpsi_c * Controller_B.cfi;
    Controller_B.cpsi[5] = Controller_B.stheta * Controller_B.spsi *
      Controller_B.cfi + -Controller_B.cpsi_c * Controller_B.sfi;
    Controller_B.cpsi[6] = -Controller_B.stheta;
    Controller_B.cpsi[7] = Controller_B.ctheta * Controller_B.sfi;
    Controller_B.cpsi[8] = Controller_B.ctheta * Controller_B.cfi;
    for (Controller_B.value_c = 0; Controller_B.value_c < 3;
         Controller_B.value_c++) {
      Controller_B.acc[Controller_B.value_c] =
        Controller_B.cpsi[Controller_B.value_c + 6] * 9.8 +
        (Controller_B.cpsi[Controller_B.value_c + 3] * 0.0 +
         Controller_B.cpsi[Controller_B.value_c] * 0.0);
    }

    // SignalConversion: '<S12>/OutportBufferFor<acc X [m//s^2]>' incorporates:
    //   MATLAB Function: '<S12>/removeGravity'

    //  Removed gravity from the acceleration
    // '<S75>:1:26'
    // '<S75>:1:27'
    // '<S75>:1:28'
    Controller_B.OutportBufferForaccXms2 = Controller_B.Data[7] +
      Controller_B.acc[0];

    // SignalConversion: '<S12>/OutportBufferFor<acc Y [m//s^2]>' incorporates:
    //   MATLAB Function: '<S12>/removeGravity'

    Controller_B.OutportBufferForaccYms2 = Controller_B.Data[8] +
      Controller_B.acc[1];

    // SignalConversion: '<S12>/OutportBufferFor<acc Z [m//s^2]>' incorporates:
    //   MATLAB Function: '<S12>/removeGravity'

    Controller_B.OutportBufferForaccZms2 = Controller_B.Data[9] +
      Controller_B.acc[2];

    // SignalConversion: '<S12>/OutportBufferFor<angular_vel X [radians//s]>'
    Controller_B.X = Controller_B.Data[3];

    // SignalConversion: '<S12>/OutportBufferFor<angular_vel Y [radians//s]>'
    Controller_B.Y = Controller_B.Data[4];

    // SignalConversion: '<S12>/OutportBufferFor<angular_vel Z [radians//s]>'
    Controller_B.OutportBufferForangular_velZrad = Controller_B.Data[5];

    // SignalConversion: '<S12>/OutportBufferFor<pitch [radians]>'
    Controller_B.OutportBufferForpitchradians = Controller_B.Data[1];

    // SignalConversion: '<S12>/OutportBufferFor<roll [radians]>'
    Controller_B.OutportBufferForrollradians = Controller_B.Data[0];
  }

  // End of Outputs for SubSystem: '<Root>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/states'

  // Start for MATLABSystem: '<S8>/Enable integration?' incorporates:
  //   MATLABSystem: '<S8>/Enable integration?'

  Controller_B.p = false;
  Controller_B.p_c = true;
  if (!(Controller_DWork.obj_g0.SampleTime ==
        Controller_P.Enableintegration_SampleTime)) {
    Controller_B.p_c = false;
  }

  if (Controller_B.p_c) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_g0.SampleTime =
      Controller_P.Enableintegration_SampleTime;
  }

  ParamGet_Controller_686.get_parameter(&Controller_B.NotEqual);

  // DiscreteIntegrator: '<S8>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S8>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S8>/Discrete-Time Integrator2'
  //   Logic: '<S8>/Logical Operator'
  //   MATLABSystem: '<S8>/Enable integration?'
  //   Start for MATLABSystem: '<S8>/Enable integration?'

  if (!Controller_B.NotEqual) {
    Controller_DWork.DiscreteTimeIntegrator_DSTATE =
      Controller_P.DiscreteTimeIntegrator_IC;
    Controller_DWork.DiscreteTimeIntegrator1_DSTATE =
      Controller_P.DiscreteTimeIntegrator1_IC;
    Controller_DWork.DiscreteTimeIntegrator2_DSTATE =
      Controller_P.DiscreteTimeIntegrator2_IC;
  }

  // Outputs for Enabled SubSystem: '<Root>/Create errors' incorporates:
  //   EnablePort: '<S2>/Enable'

  if (Controller_B.LogicalOperator) {
    // Sum: '<S2>/Error x1' incorporates:
    //   MATLABSystem: '<Root>/yaw_ref'
    //   Start for MATLABSystem: '<Root>/yaw_ref'

    Controller_B.Errorx1 = Controller_B.ZeroGain_e - Controller_B.Data[2];

    // Sum: '<S2>/Error y1' incorporates:
    //   MATLABSystem: '<Root>/pitch_ref'
    //   Start for MATLABSystem: '<Root>/pitch_ref'

    Controller_B.Errory1 = Controller_B.SignPreIntegrator_k -
      Controller_B.OutportBufferForpitchradians;

    // Sum: '<S2>/Error z4' incorporates:
    //   MATLABSystem: '<Root>/roll_ref'
    //   Start for MATLABSystem: '<Root>/roll_ref'

    Controller_B.Errorz4 = Controller_B.ChooseControllersignal_c -
      Controller_B.OutportBufferForrollradians;

    // Sum: '<S2>/Error x'
    Controller_B.Errorx = Controller_B.Product - Controller_B.X;

    // Sum: '<S2>/Error y'
    Controller_B.Errory = Controller_B.Product1 - Controller_B.Y;

    // Sum: '<S2>/Error z'
    Controller_B.Errorz = Controller_B.Product2 -
      Controller_B.OutportBufferForangular_velZrad;

    // Sum: '<S2>/Error z8' incorporates:
    //   DiscreteIntegrator: '<S8>/Discrete-Time Integrator'

    Controller_B.Errorz8 = Controller_B.Product3 -
      Controller_DWork.DiscreteTimeIntegrator_DSTATE;

    // Sum: '<S2>/Error z9' incorporates:
    //   DiscreteIntegrator: '<S8>/Discrete-Time Integrator1'

    Controller_B.Errorz9 = Controller_B.Product4 -
      Controller_DWork.DiscreteTimeIntegrator1_DSTATE;

    // Sum: '<S2>/Error z10' incorporates:
    //   DiscreteIntegrator: '<S8>/Discrete-Time Integrator2'

    Controller_B.Errorz10 = Controller_B.Product5 -
      Controller_DWork.DiscreteTimeIntegrator2_DSTATE;
  }

  // End of Outputs for SubSystem: '<Root>/Create errors'

  // Outputs for Enabled SubSystem: '<Root>/decController' incorporates:
  //   EnablePort: '<S10>/Enable'

  // Logic: '<Root>/Logical Operator3' incorporates:
  //   Constant: '<Root>/control 1'
  //   MATLABSystem: '<Root>/Get controller type'
  //   Start for MATLABSystem: '<Root>/Get controller type'
  //   RelationalOperator: '<Root>/Relational Operator'

  if (Controller_B.LogicalOperator && (Controller_P.control1_Value ==
       Controller_B.value_k)) {
    // Start for MATLABSystem: '<S57>/P_angular_vel_x' incorporates:
    //   MATLABSystem: '<S57>/P_angular_vel_x'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_bm.SampleTime ==
          Controller_P.P_angular_vel_x_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_bm.SampleTime =
        Controller_P.P_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_508.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S57>/D_angular_vel_x' incorporates:
    //   MATLABSystem: '<S57>/D_angular_vel_x'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_be.SampleTime ==
          Controller_P.D_angular_vel_x_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_be.SampleTime =
        Controller_P.D_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_505.get_parameter(&Controller_B.SignPreIntegrator_k);

    // Start for MATLABSystem: '<S57>/N_angular_vel_x ' incorporates:
    //   MATLABSystem: '<S57>/N_angular_vel_x '

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_lb.SampleTime ==
          Controller_P.N_angular_vel_x_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_lb.SampleTime =
        Controller_P.N_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_507.get_parameter(&Controller_B.ChooseControllersignal_c);

    // Product: '<S56>/NOut' incorporates:
    //   DiscreteIntegrator: '<S56>/Filter'
    //   MATLABSystem: '<S57>/D_angular_vel_x'
    //   Start for MATLABSystem: '<S57>/D_angular_vel_x'
    //   MATLABSystem: '<S57>/N_angular_vel_x '
    //   Start for MATLABSystem: '<S57>/N_angular_vel_x '
    //   Product: '<S56>/DOut'
    //   Sum: '<S56>/SumD'

    Controller_B.RandomSource = (Controller_B.Errorx *
      Controller_B.SignPreIntegrator_k - Controller_DWork.Filter_DSTATE) *
      Controller_B.ChooseControllersignal_c;

    // Sum: '<S56>/Sum' incorporates:
    //   DiscreteIntegrator: '<S56>/Integrator'
    //   MATLABSystem: '<S57>/P_angular_vel_x'
    //   Start for MATLABSystem: '<S57>/P_angular_vel_x'
    //   Product: '<S56>/POut'

    Controller_B.SignPreIntegrator_k = (Controller_B.Errorx *
      Controller_B.ZeroGain_e + Controller_DWork.Integrator_DSTATE) +
      Controller_B.RandomSource;

    // DeadZone: '<S58>/DeadZone'
    if (Controller_B.SignPreIntegrator_k >
        Controller_P.PIDController_UpperSaturation_b) {
      Controller_B.ChooseControllersignal_c = Controller_B.SignPreIntegrator_k -
        Controller_P.PIDController_UpperSaturation_b;
    } else if (Controller_B.SignPreIntegrator_k >=
               Controller_P.PIDController_LowerSaturation_l) {
      Controller_B.ChooseControllersignal_c = 0.0;
    } else {
      Controller_B.ChooseControllersignal_c = Controller_B.SignPreIntegrator_k -
        Controller_P.PIDController_LowerSaturation_l;
    }

    // End of DeadZone: '<S58>/DeadZone'

    // RelationalOperator: '<S58>/NotEqual' incorporates:
    //   Gain: '<S58>/ZeroGain'

    Controller_B.NotEqual = (Controller_P.ZeroGain_Gain_d *
      Controller_B.SignPreIntegrator_k != Controller_B.ChooseControllersignal_c);

    // Signum: '<S58>/SignDeltaU'
    if (Controller_B.ChooseControllersignal_c < 0.0) {
      Controller_B.ChooseControllersignal_c = -1.0;
    } else if (Controller_B.ChooseControllersignal_c > 0.0) {
      Controller_B.ChooseControllersignal_c = 1.0;
    } else {
      if (Controller_B.ChooseControllersignal_c == 0.0) {
        Controller_B.ChooseControllersignal_c = 0.0;
      }
    }

    // End of Signum: '<S58>/SignDeltaU'

    // DataTypeConversion: '<S58>/DataTypeConv1'
    if (Controller_B.ChooseControllersignal_c < 128.0) {
      Controller_B.rtb_DataTypeConv2_c_p = (int8_T)
        Controller_B.ChooseControllersignal_c;
    } else {
      Controller_B.rtb_DataTypeConv2_c_p = MAX_int8_T;
    }

    // Start for MATLABSystem: '<S57>/I_angular_vel_x' incorporates:
    //   MATLABSystem: '<S57>/I_angular_vel_x'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_pb.SampleTime ==
          Controller_P.I_angular_vel_x_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_pb.SampleTime =
        Controller_P.I_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_506.get_parameter(&Controller_B.ZeroGain_e);

    // Saturate: '<S56>/Saturate'
    if (Controller_B.SignPreIntegrator_k >
        Controller_P.PIDController_UpperSaturation_b) {
      Controller_B.Saturate = Controller_P.PIDController_UpperSaturation_b;
    } else if (Controller_B.SignPreIntegrator_k <
               Controller_P.PIDController_LowerSaturation_l) {
      Controller_B.Saturate = Controller_P.PIDController_LowerSaturation_l;
    } else {
      Controller_B.Saturate = Controller_B.SignPreIntegrator_k;
    }

    // End of Saturate: '<S56>/Saturate'

    // Sum: '<S56>/SumI1' incorporates:
    //   Gain: '<S56>/Kt'
    //   MATLABSystem: '<S57>/I_angular_vel_x'
    //   Start for MATLABSystem: '<S57>/I_angular_vel_x'
    //   Product: '<S56>/IOut'
    //   Sum: '<S56>/SumI3'

    Controller_B.ChooseControllersignal_c = (Controller_B.X_hw -
      Controller_B.Saturate) * Controller_P.PIDController_Kt_l +
      Controller_B.Errorx * Controller_B.ZeroGain_e;

    // Signum: '<S58>/SignPreIntegrator'
    if (Controller_B.ChooseControllersignal_c < 0.0) {
      // DataTypeConversion: '<S58>/DataTypeConv2'
      Controller_B.spsi = -1.0;
    } else if (Controller_B.ChooseControllersignal_c > 0.0) {
      // DataTypeConversion: '<S58>/DataTypeConv2'
      Controller_B.spsi = 1.0;
    } else if (Controller_B.ChooseControllersignal_c == 0.0) {
      // DataTypeConversion: '<S58>/DataTypeConv2'
      Controller_B.spsi = 0.0;
    } else {
      // DataTypeConversion: '<S58>/DataTypeConv2'
      Controller_B.spsi = Controller_B.ChooseControllersignal_c;
    }

    // End of Signum: '<S58>/SignPreIntegrator'

    // DataTypeConversion: '<S58>/DataTypeConv2'
    if (Controller_B.spsi < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.spsi;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S56>/Switch' incorporates:
    //   Constant: '<S56>/Constant'
    //   DataTypeConversion: '<S58>/DataTypeConv1'
    //   Logic: '<S58>/AND'
    //   RelationalOperator: '<S58>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_c_p ==
         Controller_B.i0)) {
      Controller_B.Switch = Controller_P.Constant_Value_ke;
    } else {
      Controller_B.Switch = Controller_B.ChooseControllersignal_c;
    }

    // End of Switch: '<S56>/Switch'

    // Start for MATLABSystem: '<S60>/P_angular_vel_y' incorporates:
    //   MATLABSystem: '<S60>/P_angular_vel_y'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_b.SampleTime ==
          Controller_P.P_angular_vel_y_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_b.SampleTime =
        Controller_P.P_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_522.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S60>/D_angular_vel_y' incorporates:
    //   MATLABSystem: '<S60>/D_angular_vel_y'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_m.SampleTime ==
          Controller_P.D_angular_vel_y_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_m.SampleTime =
        Controller_P.D_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_519.get_parameter(&Controller_B.SignPreIntegrator_k);

    // Start for MATLABSystem: '<S60>/N_angular_vel_y ' incorporates:
    //   MATLABSystem: '<S60>/N_angular_vel_y '

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_dp.SampleTime ==
          Controller_P.N_angular_vel_y_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_dp.SampleTime =
        Controller_P.N_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_521.get_parameter(&Controller_B.ChooseControllersignal_c);

    // Product: '<S59>/NOut' incorporates:
    //   DiscreteIntegrator: '<S59>/Filter'
    //   MATLABSystem: '<S60>/D_angular_vel_y'
    //   Start for MATLABSystem: '<S60>/D_angular_vel_y'
    //   MATLABSystem: '<S60>/N_angular_vel_y '
    //   Start for MATLABSystem: '<S60>/N_angular_vel_y '
    //   Product: '<S59>/DOut'
    //   Sum: '<S59>/SumD'

    Controller_B.NOut_e = (Controller_B.Errory *
      Controller_B.SignPreIntegrator_k - Controller_DWork.Filter_DSTATE_c) *
      Controller_B.ChooseControllersignal_c;

    // Sum: '<S59>/Sum' incorporates:
    //   DiscreteIntegrator: '<S59>/Integrator'
    //   MATLABSystem: '<S60>/P_angular_vel_y'
    //   Start for MATLABSystem: '<S60>/P_angular_vel_y'
    //   Product: '<S59>/POut'

    Controller_B.ChooseControllersignal_c = (Controller_B.Errory *
      Controller_B.ZeroGain_e + Controller_DWork.Integrator_DSTATE_h) +
      Controller_B.NOut_e;

    // DeadZone: '<S61>/DeadZone'
    if (Controller_B.ChooseControllersignal_c >
        Controller_P.PIDController_UpperSaturation_o) {
      Controller_B.SignPreIntegrator_k = Controller_B.ChooseControllersignal_c -
        Controller_P.PIDController_UpperSaturation_o;
    } else if (Controller_B.ChooseControllersignal_c >=
               Controller_P.PIDController_LowerSaturatio_ek) {
      Controller_B.SignPreIntegrator_k = 0.0;
    } else {
      Controller_B.SignPreIntegrator_k = Controller_B.ChooseControllersignal_c -
        Controller_P.PIDController_LowerSaturatio_ek;
    }

    // End of DeadZone: '<S61>/DeadZone'

    // RelationalOperator: '<S61>/NotEqual' incorporates:
    //   Gain: '<S61>/ZeroGain'

    Controller_B.NotEqual = (Controller_P.ZeroGain_Gain_k *
      Controller_B.ChooseControllersignal_c != Controller_B.SignPreIntegrator_k);

    // Signum: '<S61>/SignDeltaU'
    if (Controller_B.SignPreIntegrator_k < 0.0) {
      Controller_B.SignPreIntegrator_k = -1.0;
    } else if (Controller_B.SignPreIntegrator_k > 0.0) {
      Controller_B.SignPreIntegrator_k = 1.0;
    } else {
      if (Controller_B.SignPreIntegrator_k == 0.0) {
        Controller_B.SignPreIntegrator_k = 0.0;
      }
    }

    // End of Signum: '<S61>/SignDeltaU'

    // Start for MATLABSystem: '<S60>/I_angular_vel_y' incorporates:
    //   MATLABSystem: '<S60>/I_angular_vel_y'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_ep.SampleTime ==
          Controller_P.I_angular_vel_y_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_ep.SampleTime =
        Controller_P.I_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_520.get_parameter(&Controller_B.ZeroGain_e);

    // Saturate: '<S59>/Saturate'
    if (Controller_B.ChooseControllersignal_c >
        Controller_P.PIDController_UpperSaturation_o) {
      Controller_B.Saturate_f = Controller_P.PIDController_UpperSaturation_o;
    } else if (Controller_B.ChooseControllersignal_c <
               Controller_P.PIDController_LowerSaturatio_ek) {
      Controller_B.Saturate_f = Controller_P.PIDController_LowerSaturatio_ek;
    } else {
      Controller_B.Saturate_f = Controller_B.ChooseControllersignal_c;
    }

    // End of Saturate: '<S59>/Saturate'

    // Sum: '<S59>/SumI1' incorporates:
    //   Gain: '<S59>/Kt'
    //   MATLABSystem: '<S60>/I_angular_vel_y'
    //   Start for MATLABSystem: '<S60>/I_angular_vel_y'
    //   Product: '<S59>/IOut'
    //   Sum: '<S59>/SumI3'

    Controller_B.ChooseControllersignal_c = (Controller_B.Y_in -
      Controller_B.Saturate_f) * Controller_P.PIDController_Kt_jo +
      Controller_B.Errory * Controller_B.ZeroGain_e;

    // Signum: '<S61>/SignPreIntegrator'
    if (Controller_B.ChooseControllersignal_c < 0.0) {
      // DataTypeConversion: '<S61>/DataTypeConv2'
      Controller_B.spsi = -1.0;
    } else if (Controller_B.ChooseControllersignal_c > 0.0) {
      // DataTypeConversion: '<S61>/DataTypeConv2'
      Controller_B.spsi = 1.0;
    } else if (Controller_B.ChooseControllersignal_c == 0.0) {
      // DataTypeConversion: '<S61>/DataTypeConv2'
      Controller_B.spsi = 0.0;
    } else {
      // DataTypeConversion: '<S61>/DataTypeConv2'
      Controller_B.spsi = Controller_B.ChooseControllersignal_c;
    }

    // End of Signum: '<S61>/SignPreIntegrator'

    // DataTypeConversion: '<S61>/DataTypeConv1'
    if (Controller_B.SignPreIntegrator_k < 128.0) {
      Controller_B.rtb_DataTypeConv2_c_p = (int8_T)
        Controller_B.SignPreIntegrator_k;
    } else {
      Controller_B.rtb_DataTypeConv2_c_p = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S61>/DataTypeConv1'

    // DataTypeConversion: '<S61>/DataTypeConv2'
    if (Controller_B.spsi < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.spsi;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S59>/Switch' incorporates:
    //   Constant: '<S59>/Constant'
    //   Logic: '<S61>/AND'
    //   RelationalOperator: '<S61>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_c_p ==
         Controller_B.i0)) {
      Controller_B.Switch_o = Controller_P.Constant_Value_m;
    } else {
      Controller_B.Switch_o = Controller_B.ChooseControllersignal_c;
    }

    // End of Switch: '<S59>/Switch'

    // Start for MATLABSystem: '<S63>/P_angular_vel_z' incorporates:
    //   MATLABSystem: '<S63>/P_angular_vel_z'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_e.SampleTime ==
          Controller_P.P_angular_vel_z_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_e.SampleTime =
        Controller_P.P_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_536.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S63>/D_angular_vel_z' incorporates:
    //   MATLABSystem: '<S63>/D_angular_vel_z'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_jg.SampleTime ==
          Controller_P.D_angular_vel_z_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_jg.SampleTime =
        Controller_P.D_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_533.get_parameter(&Controller_B.SignPreIntegrator_k);

    // Start for MATLABSystem: '<S63>/N_angular_vel_z ' incorporates:
    //   MATLABSystem: '<S63>/N_angular_vel_z '

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_g.SampleTime ==
          Controller_P.N_angular_vel_z_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_g.SampleTime =
        Controller_P.N_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_535.get_parameter(&Controller_B.ChooseControllersignal_c);

    // Product: '<S62>/NOut' incorporates:
    //   DiscreteIntegrator: '<S62>/Filter'
    //   MATLABSystem: '<S63>/D_angular_vel_z'
    //   Start for MATLABSystem: '<S63>/D_angular_vel_z'
    //   MATLABSystem: '<S63>/N_angular_vel_z '
    //   Start for MATLABSystem: '<S63>/N_angular_vel_z '
    //   Product: '<S62>/DOut'
    //   Sum: '<S62>/SumD'

    Controller_B.NOut_m = (Controller_B.Errorz *
      Controller_B.SignPreIntegrator_k - Controller_DWork.Filter_DSTATE_f) *
      Controller_B.ChooseControllersignal_c;

    // Sum: '<S62>/Sum' incorporates:
    //   DiscreteIntegrator: '<S62>/Integrator'
    //   MATLABSystem: '<S63>/P_angular_vel_z'
    //   Start for MATLABSystem: '<S63>/P_angular_vel_z'
    //   Product: '<S62>/POut'

    Controller_B.ChooseControllersignal_c = (Controller_B.Errorz *
      Controller_B.ZeroGain_e + Controller_DWork.Integrator_DSTATE_a) +
      Controller_B.NOut_m;

    // DeadZone: '<S64>/DeadZone'
    if (Controller_B.ChooseControllersignal_c >
        Controller_P.PIDController_UpperSaturation_e) {
      Controller_B.SignPreIntegrator_k = Controller_B.ChooseControllersignal_c -
        Controller_P.PIDController_UpperSaturation_e;
    } else if (Controller_B.ChooseControllersignal_c >=
               Controller_P.PIDController_LowerSaturation_p) {
      Controller_B.SignPreIntegrator_k = 0.0;
    } else {
      Controller_B.SignPreIntegrator_k = Controller_B.ChooseControllersignal_c -
        Controller_P.PIDController_LowerSaturation_p;
    }

    // End of DeadZone: '<S64>/DeadZone'

    // RelationalOperator: '<S64>/NotEqual' incorporates:
    //   Gain: '<S64>/ZeroGain'

    Controller_B.NotEqual = (Controller_P.ZeroGain_Gain_a *
      Controller_B.ChooseControllersignal_c != Controller_B.SignPreIntegrator_k);

    // Signum: '<S64>/SignDeltaU'
    if (Controller_B.SignPreIntegrator_k < 0.0) {
      Controller_B.SignPreIntegrator_k = -1.0;
    } else if (Controller_B.SignPreIntegrator_k > 0.0) {
      Controller_B.SignPreIntegrator_k = 1.0;
    } else {
      if (Controller_B.SignPreIntegrator_k == 0.0) {
        Controller_B.SignPreIntegrator_k = 0.0;
      }
    }

    // End of Signum: '<S64>/SignDeltaU'

    // Start for MATLABSystem: '<S63>/I_angular_vel_z' incorporates:
    //   MATLABSystem: '<S63>/I_angular_vel_z'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_p.SampleTime ==
          Controller_P.I_angular_vel_z_SampleTime)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_p.SampleTime =
        Controller_P.I_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_534.get_parameter(&Controller_B.ZeroGain_e);

    // Saturate: '<S62>/Saturate'
    if (Controller_B.ChooseControllersignal_c >
        Controller_P.PIDController_UpperSaturation_e) {
      Controller_B.Saturate_i = Controller_P.PIDController_UpperSaturation_e;
    } else if (Controller_B.ChooseControllersignal_c <
               Controller_P.PIDController_LowerSaturation_p) {
      Controller_B.Saturate_i = Controller_P.PIDController_LowerSaturation_p;
    } else {
      Controller_B.Saturate_i = Controller_B.ChooseControllersignal_c;
    }

    // End of Saturate: '<S62>/Saturate'

    // Sum: '<S62>/SumI1' incorporates:
    //   Gain: '<S62>/Kt'
    //   MATLABSystem: '<S63>/I_angular_vel_z'
    //   Start for MATLABSystem: '<S63>/I_angular_vel_z'
    //   Product: '<S62>/IOut'
    //   Sum: '<S62>/SumI3'

    Controller_B.ChooseControllersignal_c = (Controller_B.Z_n -
      Controller_B.Saturate_i) * Controller_P.PIDController_Kt_p +
      Controller_B.Errorz * Controller_B.ZeroGain_e;

    // Signum: '<S64>/SignPreIntegrator'
    if (Controller_B.ChooseControllersignal_c < 0.0) {
      // DataTypeConversion: '<S64>/DataTypeConv2'
      Controller_B.spsi = -1.0;
    } else if (Controller_B.ChooseControllersignal_c > 0.0) {
      // DataTypeConversion: '<S64>/DataTypeConv2'
      Controller_B.spsi = 1.0;
    } else if (Controller_B.ChooseControllersignal_c == 0.0) {
      // DataTypeConversion: '<S64>/DataTypeConv2'
      Controller_B.spsi = 0.0;
    } else {
      // DataTypeConversion: '<S64>/DataTypeConv2'
      Controller_B.spsi = Controller_B.ChooseControllersignal_c;
    }

    // End of Signum: '<S64>/SignPreIntegrator'

    // DataTypeConversion: '<S64>/DataTypeConv1'
    if (Controller_B.SignPreIntegrator_k < 128.0) {
      Controller_B.rtb_DataTypeConv2_c_p = (int8_T)
        Controller_B.SignPreIntegrator_k;
    } else {
      Controller_B.rtb_DataTypeConv2_c_p = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S64>/DataTypeConv1'

    // DataTypeConversion: '<S64>/DataTypeConv2'
    if (Controller_B.spsi < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.spsi;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S62>/Switch' incorporates:
    //   Constant: '<S62>/Constant'
    //   Logic: '<S64>/AND'
    //   RelationalOperator: '<S64>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_c_p ==
         Controller_B.i0)) {
      Controller_B.Switch_j = Controller_P.Constant_Value_fw;
    } else {
      Controller_B.Switch_j = Controller_B.ChooseControllersignal_c;
    }

    // End of Switch: '<S62>/Switch'

    // Start for MATLABSystem: '<S66>/P_vel_x' incorporates:
    //   MATLABSystem: '<S66>/P_vel_x'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_ns.SampleTime == Controller_P.P_vel_x_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_ns.SampleTime = Controller_P.P_vel_x_SampleTime;
    }

    ParamGet_Controller_550.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S66>/D_vel_x' incorporates:
    //   MATLABSystem: '<S66>/D_vel_x'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_d.SampleTime == Controller_P.D_vel_x_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_d.SampleTime = Controller_P.D_vel_x_SampleTime;
    }

    ParamGet_Controller_547.get_parameter(&Controller_B.SignPreIntegrator_k);

    // Start for MATLABSystem: '<S66>/N_vel_x ' incorporates:
    //   MATLABSystem: '<S66>/N_vel_x '

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_a3.SampleTime == Controller_P.N_vel_x_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_a3.SampleTime = Controller_P.N_vel_x_SampleTime;
    }

    ParamGet_Controller_549.get_parameter(&Controller_B.ChooseControllersignal_c);

    // Product: '<S65>/NOut' incorporates:
    //   DiscreteIntegrator: '<S65>/Filter'
    //   MATLABSystem: '<S66>/D_vel_x'
    //   Start for MATLABSystem: '<S66>/D_vel_x'
    //   MATLABSystem: '<S66>/N_vel_x '
    //   Start for MATLABSystem: '<S66>/N_vel_x '
    //   Product: '<S65>/DOut'
    //   Sum: '<S65>/SumD'

    Controller_B.NOut_b = (Controller_B.Errorz8 *
      Controller_B.SignPreIntegrator_k - Controller_DWork.Filter_DSTATE_a) *
      Controller_B.ChooseControllersignal_c;

    // Sum: '<S65>/Sum' incorporates:
    //   DiscreteIntegrator: '<S65>/Integrator'
    //   MATLABSystem: '<S66>/P_vel_x'
    //   Start for MATLABSystem: '<S66>/P_vel_x'
    //   Product: '<S65>/POut'

    Controller_B.ChooseControllersignal_c = (Controller_B.Errorz8 *
      Controller_B.ZeroGain_e + Controller_DWork.Integrator_DSTATE_f) +
      Controller_B.NOut_b;

    // DeadZone: '<S67>/DeadZone'
    if (Controller_B.ChooseControllersignal_c >
        Controller_P.PIDController_UpperSaturation_d) {
      Controller_B.SignPreIntegrator_k = Controller_B.ChooseControllersignal_c -
        Controller_P.PIDController_UpperSaturation_d;
    } else if (Controller_B.ChooseControllersignal_c >=
               Controller_P.PIDController_LowerSaturation_i) {
      Controller_B.SignPreIntegrator_k = 0.0;
    } else {
      Controller_B.SignPreIntegrator_k = Controller_B.ChooseControllersignal_c -
        Controller_P.PIDController_LowerSaturation_i;
    }

    // End of DeadZone: '<S67>/DeadZone'

    // RelationalOperator: '<S67>/NotEqual' incorporates:
    //   Gain: '<S67>/ZeroGain'

    Controller_B.NotEqual = (Controller_P.ZeroGain_Gain_j *
      Controller_B.ChooseControllersignal_c != Controller_B.SignPreIntegrator_k);

    // Signum: '<S67>/SignDeltaU'
    if (Controller_B.SignPreIntegrator_k < 0.0) {
      Controller_B.SignPreIntegrator_k = -1.0;
    } else if (Controller_B.SignPreIntegrator_k > 0.0) {
      Controller_B.SignPreIntegrator_k = 1.0;
    } else {
      if (Controller_B.SignPreIntegrator_k == 0.0) {
        Controller_B.SignPreIntegrator_k = 0.0;
      }
    }

    // End of Signum: '<S67>/SignDeltaU'

    // Start for MATLABSystem: '<S66>/I_vel_x' incorporates:
    //   MATLABSystem: '<S66>/I_vel_x'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_cv.SampleTime == Controller_P.I_vel_x_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_cv.SampleTime = Controller_P.I_vel_x_SampleTime;
    }

    ParamGet_Controller_548.get_parameter(&Controller_B.ZeroGain_e);

    // Saturate: '<S65>/Saturate'
    if (Controller_B.ChooseControllersignal_c >
        Controller_P.PIDController_UpperSaturation_d) {
      Controller_B.Saturate_b = Controller_P.PIDController_UpperSaturation_d;
    } else if (Controller_B.ChooseControllersignal_c <
               Controller_P.PIDController_LowerSaturation_i) {
      Controller_B.Saturate_b = Controller_P.PIDController_LowerSaturation_i;
    } else {
      Controller_B.Saturate_b = Controller_B.ChooseControllersignal_c;
    }

    // End of Saturate: '<S65>/Saturate'

    // Sum: '<S65>/SumI1' incorporates:
    //   Gain: '<S65>/Kt'
    //   MATLABSystem: '<S66>/I_vel_x'
    //   Start for MATLABSystem: '<S66>/I_vel_x'
    //   Product: '<S65>/IOut'
    //   Sum: '<S65>/SumI3'

    Controller_B.ChooseControllersignal_c = (Controller_B.X_h -
      Controller_B.Saturate_b) * Controller_P.PIDController_Kt_jw +
      Controller_B.Errorz8 * Controller_B.ZeroGain_e;

    // Signum: '<S67>/SignPreIntegrator'
    if (Controller_B.ChooseControllersignal_c < 0.0) {
      // DataTypeConversion: '<S67>/DataTypeConv2'
      Controller_B.spsi = -1.0;
    } else if (Controller_B.ChooseControllersignal_c > 0.0) {
      // DataTypeConversion: '<S67>/DataTypeConv2'
      Controller_B.spsi = 1.0;
    } else if (Controller_B.ChooseControllersignal_c == 0.0) {
      // DataTypeConversion: '<S67>/DataTypeConv2'
      Controller_B.spsi = 0.0;
    } else {
      // DataTypeConversion: '<S67>/DataTypeConv2'
      Controller_B.spsi = Controller_B.ChooseControllersignal_c;
    }

    // End of Signum: '<S67>/SignPreIntegrator'

    // DataTypeConversion: '<S67>/DataTypeConv1'
    if (Controller_B.SignPreIntegrator_k < 128.0) {
      Controller_B.rtb_DataTypeConv2_c_p = (int8_T)
        Controller_B.SignPreIntegrator_k;
    } else {
      Controller_B.rtb_DataTypeConv2_c_p = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S67>/DataTypeConv1'

    // DataTypeConversion: '<S67>/DataTypeConv2'
    if (Controller_B.spsi < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.spsi;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S65>/Switch' incorporates:
    //   Constant: '<S65>/Constant'
    //   Logic: '<S67>/AND'
    //   RelationalOperator: '<S67>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_c_p ==
         Controller_B.i0)) {
      Controller_B.sfi = Controller_P.Constant_Value_m0;
    } else {
      Controller_B.sfi = Controller_B.ChooseControllersignal_c;
    }

    // End of Switch: '<S65>/Switch'

    // Start for MATLABSystem: '<S69>/P_vel_y' incorporates:
    //   MATLABSystem: '<S69>/P_vel_y'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_ji.SampleTime == Controller_P.P_vel_y_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_ji.SampleTime = Controller_P.P_vel_y_SampleTime;
    }

    ParamGet_Controller_564.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S69>/D_vel_y' incorporates:
    //   MATLABSystem: '<S69>/D_vel_y'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_ny.SampleTime == Controller_P.D_vel_y_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_ny.SampleTime = Controller_P.D_vel_y_SampleTime;
    }

    ParamGet_Controller_561.get_parameter(&Controller_B.SignPreIntegrator_k);

    // Start for MATLABSystem: '<S69>/N_vel_y ' incorporates:
    //   MATLABSystem: '<S69>/N_vel_y '

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_cb.SampleTime == Controller_P.N_vel_y_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_cb.SampleTime = Controller_P.N_vel_y_SampleTime;
    }

    ParamGet_Controller_563.get_parameter(&Controller_B.ChooseControllersignal_c);

    // Product: '<S68>/NOut' incorporates:
    //   DiscreteIntegrator: '<S68>/Filter'
    //   MATLABSystem: '<S69>/D_vel_y'
    //   Start for MATLABSystem: '<S69>/D_vel_y'
    //   MATLABSystem: '<S69>/N_vel_y '
    //   Start for MATLABSystem: '<S69>/N_vel_y '
    //   Product: '<S68>/DOut'
    //   Sum: '<S68>/SumD'

    Controller_B.cfi = (Controller_B.Errorz9 * Controller_B.SignPreIntegrator_k
                        - Controller_DWork.Filter_DSTATE_g) *
      Controller_B.ChooseControllersignal_c;

    // Sum: '<S68>/Sum' incorporates:
    //   DiscreteIntegrator: '<S68>/Integrator'
    //   MATLABSystem: '<S69>/P_vel_y'
    //   Start for MATLABSystem: '<S69>/P_vel_y'
    //   Product: '<S68>/POut'

    Controller_B.ChooseControllersignal_c = (Controller_B.Errorz9 *
      Controller_B.ZeroGain_e + Controller_DWork.Integrator_DSTATE_n) +
      Controller_B.cfi;

    // DeadZone: '<S70>/DeadZone'
    if (Controller_B.ChooseControllersignal_c >
        Controller_P.PIDController_UpperSaturatio_bf) {
      Controller_B.SignPreIntegrator_k = Controller_B.ChooseControllersignal_c -
        Controller_P.PIDController_UpperSaturatio_bf;
    } else if (Controller_B.ChooseControllersignal_c >=
               Controller_P.PIDController_LowerSaturation_g) {
      Controller_B.SignPreIntegrator_k = 0.0;
    } else {
      Controller_B.SignPreIntegrator_k = Controller_B.ChooseControllersignal_c -
        Controller_P.PIDController_LowerSaturation_g;
    }

    // End of DeadZone: '<S70>/DeadZone'

    // RelationalOperator: '<S70>/NotEqual' incorporates:
    //   Gain: '<S70>/ZeroGain'

    Controller_B.NotEqual = (Controller_P.ZeroGain_Gain_jk *
      Controller_B.ChooseControllersignal_c != Controller_B.SignPreIntegrator_k);

    // Signum: '<S70>/SignDeltaU'
    if (Controller_B.SignPreIntegrator_k < 0.0) {
      Controller_B.SignPreIntegrator_k = -1.0;
    } else if (Controller_B.SignPreIntegrator_k > 0.0) {
      Controller_B.SignPreIntegrator_k = 1.0;
    } else {
      if (Controller_B.SignPreIntegrator_k == 0.0) {
        Controller_B.SignPreIntegrator_k = 0.0;
      }
    }

    // End of Signum: '<S70>/SignDeltaU'

    // Start for MATLABSystem: '<S69>/I_vel_y' incorporates:
    //   MATLABSystem: '<S69>/I_vel_y'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_jx.SampleTime == Controller_P.I_vel_y_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_jx.SampleTime = Controller_P.I_vel_y_SampleTime;
    }

    ParamGet_Controller_562.get_parameter(&Controller_B.ZeroGain_e);

    // Saturate: '<S68>/Saturate'
    if (Controller_B.ChooseControllersignal_c >
        Controller_P.PIDController_UpperSaturatio_bf) {
      Controller_B.Saturate_h = Controller_P.PIDController_UpperSaturatio_bf;
    } else if (Controller_B.ChooseControllersignal_c <
               Controller_P.PIDController_LowerSaturation_g) {
      Controller_B.Saturate_h = Controller_P.PIDController_LowerSaturation_g;
    } else {
      Controller_B.Saturate_h = Controller_B.ChooseControllersignal_c;
    }

    // End of Saturate: '<S68>/Saturate'

    // Sum: '<S68>/SumI1' incorporates:
    //   Gain: '<S68>/Kt'
    //   MATLABSystem: '<S69>/I_vel_y'
    //   Start for MATLABSystem: '<S69>/I_vel_y'
    //   Product: '<S68>/IOut'
    //   Sum: '<S68>/SumI3'

    Controller_B.ChooseControllersignal_c = (Controller_B.Y_i -
      Controller_B.Saturate_h) * Controller_P.PIDController_Kt_c +
      Controller_B.Errorz9 * Controller_B.ZeroGain_e;

    // Signum: '<S70>/SignPreIntegrator'
    if (Controller_B.ChooseControllersignal_c < 0.0) {
      // DataTypeConversion: '<S70>/DataTypeConv2'
      Controller_B.spsi = -1.0;
    } else if (Controller_B.ChooseControllersignal_c > 0.0) {
      // DataTypeConversion: '<S70>/DataTypeConv2'
      Controller_B.spsi = 1.0;
    } else if (Controller_B.ChooseControllersignal_c == 0.0) {
      // DataTypeConversion: '<S70>/DataTypeConv2'
      Controller_B.spsi = 0.0;
    } else {
      // DataTypeConversion: '<S70>/DataTypeConv2'
      Controller_B.spsi = Controller_B.ChooseControllersignal_c;
    }

    // End of Signum: '<S70>/SignPreIntegrator'

    // DataTypeConversion: '<S70>/DataTypeConv1'
    if (Controller_B.SignPreIntegrator_k < 128.0) {
      Controller_B.rtb_DataTypeConv2_c_p = (int8_T)
        Controller_B.SignPreIntegrator_k;
    } else {
      Controller_B.rtb_DataTypeConv2_c_p = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S70>/DataTypeConv1'

    // DataTypeConversion: '<S70>/DataTypeConv2'
    if (Controller_B.spsi < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.spsi;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S68>/Switch' incorporates:
    //   Constant: '<S68>/Constant'
    //   Logic: '<S70>/AND'
    //   RelationalOperator: '<S70>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_c_p ==
         Controller_B.i0)) {
      Controller_B.spsi = Controller_P.Constant_Value_p;
    } else {
      Controller_B.spsi = Controller_B.ChooseControllersignal_c;
    }

    // End of Switch: '<S68>/Switch'

    // Start for MATLABSystem: '<S72>/P_vel_z' incorporates:
    //   MATLABSystem: '<S72>/P_vel_z'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_j.SampleTime == Controller_P.P_vel_z_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_j.SampleTime = Controller_P.P_vel_z_SampleTime;
    }

    ParamGet_Controller_578.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S72>/D_vel_z' incorporates:
    //   MATLABSystem: '<S72>/D_vel_z'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_a.SampleTime == Controller_P.D_vel_z_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_a.SampleTime = Controller_P.D_vel_z_SampleTime;
    }

    ParamGet_Controller_575.get_parameter(&Controller_B.SignPreIntegrator_k);

    // Start for MATLABSystem: '<S72>/N_vel_z ' incorporates:
    //   MATLABSystem: '<S72>/N_vel_z '

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_h.SampleTime == Controller_P.N_vel_z_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_h.SampleTime = Controller_P.N_vel_z_SampleTime;
    }

    ParamGet_Controller_577.get_parameter(&Controller_B.ChooseControllersignal_c);

    // Product: '<S71>/NOut' incorporates:
    //   DiscreteIntegrator: '<S71>/Filter'
    //   MATLABSystem: '<S72>/D_vel_z'
    //   Start for MATLABSystem: '<S72>/D_vel_z'
    //   MATLABSystem: '<S72>/N_vel_z '
    //   Start for MATLABSystem: '<S72>/N_vel_z '
    //   Product: '<S71>/DOut'
    //   Sum: '<S71>/SumD'

    Controller_B.cpsi_c = (Controller_B.Errorz10 *
      Controller_B.SignPreIntegrator_k - Controller_DWork.Filter_DSTATE_cw) *
      Controller_B.ChooseControllersignal_c;

    // Sum: '<S71>/Sum' incorporates:
    //   DiscreteIntegrator: '<S71>/Integrator'
    //   MATLABSystem: '<S72>/P_vel_z'
    //   Start for MATLABSystem: '<S72>/P_vel_z'
    //   Product: '<S71>/POut'

    Controller_B.ChooseControllersignal_c = (Controller_B.Errorz10 *
      Controller_B.ZeroGain_e + Controller_DWork.Integrator_DSTATE_ny) +
      Controller_B.cpsi_c;

    // DeadZone: '<S73>/DeadZone'
    if (Controller_B.ChooseControllersignal_c >
        Controller_P.PIDController_UpperSaturatio_ba) {
      Controller_B.SignPreIntegrator_k = Controller_B.ChooseControllersignal_c -
        Controller_P.PIDController_UpperSaturatio_ba;
    } else if (Controller_B.ChooseControllersignal_c >=
               Controller_P.PIDController_LowerSaturatio_pm) {
      Controller_B.SignPreIntegrator_k = 0.0;
    } else {
      Controller_B.SignPreIntegrator_k = Controller_B.ChooseControllersignal_c -
        Controller_P.PIDController_LowerSaturatio_pm;
    }

    // End of DeadZone: '<S73>/DeadZone'

    // RelationalOperator: '<S73>/NotEqual' incorporates:
    //   Gain: '<S73>/ZeroGain'

    Controller_B.NotEqual = (Controller_P.ZeroGain_Gain_p *
      Controller_B.ChooseControllersignal_c != Controller_B.SignPreIntegrator_k);

    // Signum: '<S73>/SignDeltaU'
    if (Controller_B.SignPreIntegrator_k < 0.0) {
      Controller_B.SignPreIntegrator_k = -1.0;
    } else if (Controller_B.SignPreIntegrator_k > 0.0) {
      Controller_B.SignPreIntegrator_k = 1.0;
    } else {
      if (Controller_B.SignPreIntegrator_k == 0.0) {
        Controller_B.SignPreIntegrator_k = 0.0;
      }
    }

    // End of Signum: '<S73>/SignDeltaU'

    // Start for MATLABSystem: '<S72>/I_vel_z' incorporates:
    //   MATLABSystem: '<S72>/I_vel_z'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_js.SampleTime == Controller_P.I_vel_z_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_js.SampleTime = Controller_P.I_vel_z_SampleTime;
    }

    ParamGet_Controller_576.get_parameter(&Controller_B.ZeroGain_e);

    // Saturate: '<S71>/Saturate'
    if (Controller_B.ChooseControllersignal_c >
        Controller_P.PIDController_UpperSaturatio_ba) {
      Controller_B.Saturate_bk = Controller_P.PIDController_UpperSaturatio_ba;
    } else if (Controller_B.ChooseControllersignal_c <
               Controller_P.PIDController_LowerSaturatio_pm) {
      Controller_B.Saturate_bk = Controller_P.PIDController_LowerSaturatio_pm;
    } else {
      Controller_B.Saturate_bk = Controller_B.ChooseControllersignal_c;
    }

    // End of Saturate: '<S71>/Saturate'

    // Sum: '<S71>/SumI1' incorporates:
    //   Gain: '<S71>/Kt'
    //   MATLABSystem: '<S72>/I_vel_z'
    //   Start for MATLABSystem: '<S72>/I_vel_z'
    //   Product: '<S71>/IOut'
    //   Sum: '<S71>/SumI3'

    Controller_B.ChooseControllersignal_c = (Controller_B.Z -
      Controller_B.Saturate_bk) * Controller_P.PIDController_Kt_li +
      Controller_B.Errorz10 * Controller_B.ZeroGain_e;

    // Update for DiscreteIntegrator: '<S56>/Integrator'
    Controller_DWork.Integrator_DSTATE += Controller_P.Integrator_gainval_h *
      Controller_B.Switch;

    // Update for DiscreteIntegrator: '<S56>/Filter'
    Controller_DWork.Filter_DSTATE += Controller_P.Filter_gainval_n *
      Controller_B.RandomSource;

    // Update for DiscreteIntegrator: '<S59>/Integrator'
    Controller_DWork.Integrator_DSTATE_h += Controller_P.Integrator_gainval_c *
      Controller_B.Switch_o;

    // Update for DiscreteIntegrator: '<S59>/Filter'
    Controller_DWork.Filter_DSTATE_c += Controller_P.Filter_gainval_i *
      Controller_B.NOut_e;

    // Update for DiscreteIntegrator: '<S62>/Integrator'
    Controller_DWork.Integrator_DSTATE_a += Controller_P.Integrator_gainval_n *
      Controller_B.Switch_j;

    // Update for DiscreteIntegrator: '<S62>/Filter'
    Controller_DWork.Filter_DSTATE_f += Controller_P.Filter_gainval_k *
      Controller_B.NOut_m;

    // Update for DiscreteIntegrator: '<S65>/Integrator'
    Controller_DWork.Integrator_DSTATE_f += Controller_P.Integrator_gainval_j *
      Controller_B.sfi;

    // Update for DiscreteIntegrator: '<S65>/Filter'
    Controller_DWork.Filter_DSTATE_a += Controller_P.Filter_gainval_h *
      Controller_B.NOut_b;

    // Update for DiscreteIntegrator: '<S68>/Integrator'
    Controller_DWork.Integrator_DSTATE_n += Controller_P.Integrator_gainval_np *
      Controller_B.spsi;

    // Update for DiscreteIntegrator: '<S68>/Filter'
    Controller_DWork.Filter_DSTATE_g += Controller_P.Filter_gainval_h0 *
      Controller_B.cfi;

    // Signum: '<S73>/SignPreIntegrator'
    if (Controller_B.ChooseControllersignal_c < 0.0) {
      // DataTypeConversion: '<S73>/DataTypeConv2'
      Controller_B.spsi = -1.0;
    } else if (Controller_B.ChooseControllersignal_c > 0.0) {
      // DataTypeConversion: '<S73>/DataTypeConv2'
      Controller_B.spsi = 1.0;
    } else if (Controller_B.ChooseControllersignal_c == 0.0) {
      // DataTypeConversion: '<S73>/DataTypeConv2'
      Controller_B.spsi = 0.0;
    } else {
      // DataTypeConversion: '<S73>/DataTypeConv2'
      Controller_B.spsi = Controller_B.ChooseControllersignal_c;
    }

    // End of Signum: '<S73>/SignPreIntegrator'

    // DataTypeConversion: '<S73>/DataTypeConv1'
    if (Controller_B.SignPreIntegrator_k < 128.0) {
      Controller_B.rtb_DataTypeConv2_c_p = (int8_T)
        Controller_B.SignPreIntegrator_k;
    } else {
      Controller_B.rtb_DataTypeConv2_c_p = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S73>/DataTypeConv1'

    // DataTypeConversion: '<S73>/DataTypeConv2'
    if (Controller_B.spsi < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.spsi;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S71>/Switch' incorporates:
    //   Constant: '<S71>/Constant'
    //   Logic: '<S73>/AND'
    //   RelationalOperator: '<S73>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_c_p ==
         Controller_B.i0)) {
      Controller_B.ChooseControllersignal_c = Controller_P.Constant_Value_l;
    }

    // End of Switch: '<S71>/Switch'

    // Update for DiscreteIntegrator: '<S71>/Integrator'
    Controller_DWork.Integrator_DSTATE_ny += Controller_P.Integrator_gainval_m *
      Controller_B.ChooseControllersignal_c;

    // Update for DiscreteIntegrator: '<S71>/Filter'
    Controller_DWork.Filter_DSTATE_cw += Controller_P.Filter_gainval_b *
      Controller_B.cpsi_c;
  }

  // End of Logic: '<Root>/Logical Operator3'
  // End of Outputs for SubSystem: '<Root>/decController'

  // MATLAB Function: '<Root>/thrust alloc1'
  Controller_thrustalloc(Controller_B.Saturate_b, Controller_B.Saturate_h,
    Controller_B.Saturate_bk, Controller_B.Saturate, Controller_B.Saturate_f,
    Controller_B.Saturate_i, &Controller_B.sf_thrustalloc1);

  // Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
  //   EnablePort: '<S5>/Enable'

  // Logic: '<Root>/Logical Operator4' incorporates:
  //   Constant: '<Root>/2'
  //   MATLABSystem: '<Root>/Get controller type'
  //   Start for MATLABSystem: '<Root>/Get controller type'
  //   RelationalOperator: '<Root>/Relational Operator1'

  if (Controller_B.LogicalOperator && (Controller_P.u_Value ==
       Controller_B.value_k)) {
    // Start for MATLABSystem: '<S26>/P_roll' incorporates:
    //   MATLABSystem: '<S26>/P_roll'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_jp.SampleTime == Controller_P.P_roll_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_jp.SampleTime = Controller_P.P_roll_SampleTime;
    }

    ParamGet_Controller_968.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S26>/D_roll' incorporates:
    //   MATLABSystem: '<S26>/D_roll'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_k.SampleTime == Controller_P.D_roll_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_k.SampleTime = Controller_P.D_roll_SampleTime;
    }

    ParamGet_Controller_965.get_parameter(&Controller_B.SignPreIntegrator_k);

    // Start for MATLABSystem: '<S26>/N_roll ' incorporates:
    //   MATLABSystem: '<S26>/N_roll '

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_dp3.SampleTime == Controller_P.N_roll_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_dp3.SampleTime = Controller_P.N_roll_SampleTime;
    }

    ParamGet_Controller_967.get_parameter(&Controller_B.ChooseControllersignal_c);

    // Product: '<S25>/NOut' incorporates:
    //   DiscreteIntegrator: '<S25>/Filter'
    //   MATLABSystem: '<S26>/D_roll'
    //   Start for MATLABSystem: '<S26>/D_roll'
    //   MATLABSystem: '<S26>/N_roll '
    //   Start for MATLABSystem: '<S26>/N_roll '
    //   Product: '<S25>/DOut'
    //   Sum: '<S25>/SumD'

    Controller_B.RandomSource = (Controller_B.Errorz4 *
      Controller_B.SignPreIntegrator_k - Controller_DWork.Filter_DSTATE_gs) *
      Controller_B.ChooseControllersignal_c;

    // Sum: '<S25>/Sum' incorporates:
    //   DiscreteIntegrator: '<S25>/Integrator'
    //   MATLABSystem: '<S26>/P_roll'
    //   Start for MATLABSystem: '<S26>/P_roll'
    //   Product: '<S25>/POut'

    Controller_B.NOut_e = (Controller_B.Errorz4 * Controller_B.ZeroGain_e +
      Controller_DWork.Integrator_DSTATE_nm) + Controller_B.RandomSource;

    // Saturate: '<S25>/Saturate'
    if (Controller_B.NOut_e > Controller_P.PIDController_UpperSaturationLi) {
      Controller_B.Switch_o = Controller_P.PIDController_UpperSaturationLi;
    } else if (Controller_B.NOut_e <
               Controller_P.PIDController_LowerSaturationLi) {
      Controller_B.Switch_o = Controller_P.PIDController_LowerSaturationLi;
    } else {
      Controller_B.Switch_o = Controller_B.NOut_e;
    }

    // End of Saturate: '<S25>/Saturate'

    // Start for MATLABSystem: '<S23>/P_pitch' incorporates:
    //   MATLABSystem: '<S23>/P_pitch'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_m1.SampleTime == Controller_P.P_pitch_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_m1.SampleTime = Controller_P.P_pitch_SampleTime;
    }

    ParamGet_Controller_954.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S23>/D_pitch' incorporates:
    //   MATLABSystem: '<S23>/D_pitch'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_b4.SampleTime == Controller_P.D_pitch_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_b4.SampleTime = Controller_P.D_pitch_SampleTime;
    }

    ParamGet_Controller_951.get_parameter(&Controller_B.SignPreIntegrator_k);

    // Start for MATLABSystem: '<S23>/N_pitch ' incorporates:
    //   MATLABSystem: '<S23>/N_pitch '

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_fq.SampleTime == Controller_P.N_pitch_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_fq.SampleTime = Controller_P.N_pitch_SampleTime;
    }

    ParamGet_Controller_953.get_parameter(&Controller_B.ChooseControllersignal_c);

    // Product: '<S22>/NOut' incorporates:
    //   DiscreteIntegrator: '<S22>/Filter'
    //   MATLABSystem: '<S23>/D_pitch'
    //   Start for MATLABSystem: '<S23>/D_pitch'
    //   MATLABSystem: '<S23>/N_pitch '
    //   Start for MATLABSystem: '<S23>/N_pitch '
    //   Product: '<S22>/DOut'
    //   Sum: '<S22>/SumD'

    Controller_B.Switch = (Controller_B.Errory1 *
      Controller_B.SignPreIntegrator_k - Controller_DWork.Filter_DSTATE_fb) *
      Controller_B.ChooseControllersignal_c;

    // Sum: '<S22>/Sum' incorporates:
    //   DiscreteIntegrator: '<S22>/Integrator'
    //   MATLABSystem: '<S23>/P_pitch'
    //   Start for MATLABSystem: '<S23>/P_pitch'
    //   Product: '<S22>/POut'

    Controller_B.Switch_j = (Controller_B.Errory1 * Controller_B.ZeroGain_e +
      Controller_DWork.Integrator_DSTATE_c) + Controller_B.Switch;

    // Saturate: '<S22>/Saturate'
    if (Controller_B.Switch_j > Controller_P.PIDController_UpperSaturation_n) {
      Controller_B.NOut_b = Controller_P.PIDController_UpperSaturation_n;
    } else if (Controller_B.Switch_j <
               Controller_P.PIDController_LowerSaturation_n) {
      Controller_B.NOut_b = Controller_P.PIDController_LowerSaturation_n;
    } else {
      Controller_B.NOut_b = Controller_B.Switch_j;
    }

    // End of Saturate: '<S22>/Saturate'

    // Start for MATLABSystem: '<S29>/P_yaw' incorporates:
    //   MATLABSystem: '<S29>/P_yaw'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_hn.SampleTime == Controller_P.P_yaw_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_hn.SampleTime = Controller_P.P_yaw_SampleTime;
    }

    ParamGet_Controller_940.get_parameter(&Controller_B.ZeroGain_e);

    // Start for MATLABSystem: '<S29>/D_yaw' incorporates:
    //   MATLABSystem: '<S29>/D_yaw'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_ha.SampleTime == Controller_P.D_yaw_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_ha.SampleTime = Controller_P.D_yaw_SampleTime;
    }

    ParamGet_Controller_937.get_parameter(&Controller_B.SignPreIntegrator_k);

    // Start for MATLABSystem: '<S29>/N_yaw ' incorporates:
    //   MATLABSystem: '<S29>/N_yaw '

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_py.SampleTime == Controller_P.N_yaw_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_py.SampleTime = Controller_P.N_yaw_SampleTime;
    }

    ParamGet_Controller_939.get_parameter(&Controller_B.ChooseControllersignal_c);

    // Product: '<S28>/NOut' incorporates:
    //   DiscreteIntegrator: '<S28>/Filter'
    //   MATLABSystem: '<S29>/D_yaw'
    //   Start for MATLABSystem: '<S29>/D_yaw'
    //   MATLABSystem: '<S29>/N_yaw '
    //   Start for MATLABSystem: '<S29>/N_yaw '
    //   Product: '<S28>/DOut'
    //   Sum: '<S28>/SumD'

    Controller_B.SignPreIntegrator_k = (Controller_B.Errorx1 *
      Controller_B.SignPreIntegrator_k - Controller_DWork.Filter_DSTATE_l) *
      Controller_B.ChooseControllersignal_c;

    // Sum: '<S28>/Sum' incorporates:
    //   DiscreteIntegrator: '<S28>/Integrator'
    //   MATLABSystem: '<S29>/P_yaw'
    //   Start for MATLABSystem: '<S29>/P_yaw'
    //   Product: '<S28>/POut'

    Controller_B.ChooseControllersignal_c = (Controller_B.Errorx1 *
      Controller_B.ZeroGain_e + Controller_DWork.Integrator_DSTATE_ch) +
      Controller_B.SignPreIntegrator_k;

    // Saturate: '<S28>/Saturate'
    if (Controller_B.ChooseControllersignal_c >
        Controller_P.PIDController_UpperSaturation_j) {
      Controller_B.NOut_m = Controller_P.PIDController_UpperSaturation_j;
    } else if (Controller_B.ChooseControllersignal_c <
               Controller_P.PIDController_LowerSaturation_e) {
      Controller_B.NOut_m = Controller_P.PIDController_LowerSaturation_e;
    } else {
      Controller_B.NOut_m = Controller_B.ChooseControllersignal_c;
    }

    // End of Saturate: '<S28>/Saturate'

    // MATLAB Function: '<S5>/convert to local'
    // MATLAB Function 'Subsystem/convert to local': '<S18>:1'
    // '<S18>:1:3'
    Controller_B.sfi = sin(Controller_B.OutportBufferForrollradians);

    // '<S18>:1:4'
    Controller_B.cfi = cos(Controller_B.OutportBufferForrollradians);

    // '<S18>:1:5'
    Controller_B.spsi = sin(Controller_B.Data[2]);

    // '<S18>:1:6'
    Controller_B.cpsi_c = cos(Controller_B.Data[2]);

    // '<S18>:1:7'
    Controller_B.stheta = sin(Controller_B.OutportBufferForpitchradians);

    // '<S18>:1:8'
    Controller_B.ctheta = cos(Controller_B.OutportBufferForpitchradians);

    // '<S18>:1:9'
    Controller_B.r[0] = Controller_B.cpsi_c * Controller_B.ctheta;
    Controller_B.r[3] = Controller_B.cpsi_c * Controller_B.stheta *
      Controller_B.sfi + -Controller_B.spsi * Controller_B.cfi;
    Controller_B.r[6] = Controller_B.cpsi_c * Controller_B.cfi *
      Controller_B.stheta + Controller_B.spsi * Controller_B.sfi;
    Controller_B.r[1] = Controller_B.spsi * Controller_B.ctheta;
    Controller_B.r[4] = Controller_B.sfi * Controller_B.stheta *
      Controller_B.spsi + Controller_B.cpsi_c * Controller_B.cfi;
    Controller_B.r[7] = Controller_B.stheta * Controller_B.spsi *
      Controller_B.cfi + -Controller_B.cpsi_c * Controller_B.sfi;
    Controller_B.r[2] = -Controller_B.stheta;
    Controller_B.r[5] = Controller_B.ctheta * Controller_B.sfi;
    Controller_B.r[8] = Controller_B.ctheta * Controller_B.cfi;

    // '<S18>:1:13'
    memset(&Controller_B.rotmatrix[0], 0, 36U * sizeof(real_T));
    for (Controller_B.value_c = 0; Controller_B.value_c < 3;
         Controller_B.value_c++) {
      Controller_B.rotmatrix[6 * Controller_B.value_c] = Controller_B.r[3 *
        Controller_B.value_c];
      Controller_B.rotmatrix[1 + 6 * Controller_B.value_c] = Controller_B.r[3 *
        Controller_B.value_c + 1];
      Controller_B.rotmatrix[2 + 6 * Controller_B.value_c] = Controller_B.r[3 *
        Controller_B.value_c + 2];
      Controller_B.rotmatrix[3 + 6 * (3 + Controller_B.value_c)] =
        Controller_B.r[3 * Controller_B.value_c];
      Controller_B.rotmatrix[4 + 6 * (3 + Controller_B.value_c)] =
        Controller_B.r[3 * Controller_B.value_c + 1];
      Controller_B.rotmatrix[5 + 6 * (3 + Controller_B.value_c)] =
        Controller_B.r[3 * Controller_B.value_c + 2];
    }

    // SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport4' incorporates:
    //   Constant: '<S5>/Constant'
    //   MATLAB Function: '<S5>/convert to local'

    // '<S18>:1:18'
    Controller_B.dv0[0] = Controller_P.Constant_Value_b;
    Controller_B.dv0[1] = Controller_P.Constant_Value_b;
    Controller_B.dv0[2] = Controller_P.Constant_Value_b;
    Controller_B.dv0[3] = Controller_B.Switch_o;
    Controller_B.dv0[4] = Controller_B.NOut_b;
    Controller_B.dv0[5] = Controller_B.NOut_m;

    // SignalConversion: '<S5>/OutportBufferForOut2' incorporates:
    //   MATLAB Function: '<S5>/convert to local'

    for (Controller_B.value_c = 0; Controller_B.value_c < 6;
         Controller_B.value_c++) {
      Controller_B.OutportBufferForOut2[Controller_B.value_c] = 0.0;
      for (Controller_B.i = 0; Controller_B.i < 6; Controller_B.i++) {
        Controller_B.OutportBufferForOut2[Controller_B.value_c] +=
          Controller_B.rotmatrix[6 * Controller_B.i + Controller_B.value_c] *
          Controller_B.dv0[Controller_B.i];
      }
    }

    // End of SignalConversion: '<S5>/OutportBufferForOut2'

    // Gain: '<S24>/ZeroGain'
    Controller_B.ZeroGain_e = Controller_P.ZeroGain_Gain * Controller_B.Switch_j;

    // DeadZone: '<S24>/DeadZone'
    if (Controller_B.Switch_j > Controller_P.PIDController_UpperSaturation_n) {
      Controller_B.Switch_j -= Controller_P.PIDController_UpperSaturation_n;
    } else if (Controller_B.Switch_j >=
               Controller_P.PIDController_LowerSaturation_n) {
      Controller_B.Switch_j = 0.0;
    } else {
      Controller_B.Switch_j -= Controller_P.PIDController_LowerSaturation_n;
    }

    // End of DeadZone: '<S24>/DeadZone'

    // RelationalOperator: '<S24>/NotEqual'
    Controller_B.NotEqual = (Controller_B.ZeroGain_e != Controller_B.Switch_j);

    // Signum: '<S24>/SignDeltaU'
    if (Controller_B.Switch_j < 0.0) {
      Controller_B.Switch_j = -1.0;
    } else if (Controller_B.Switch_j > 0.0) {
      Controller_B.Switch_j = 1.0;
    } else {
      if (Controller_B.Switch_j == 0.0) {
        Controller_B.Switch_j = 0.0;
      }
    }

    // End of Signum: '<S24>/SignDeltaU'

    // Start for MATLABSystem: '<S23>/I_pitch' incorporates:
    //   MATLABSystem: '<S23>/I_pitch'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_jb.SampleTime == Controller_P.I_pitch_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_jb.SampleTime = Controller_P.I_pitch_SampleTime;
    }

    ParamGet_Controller_952.get_parameter(&Controller_B.ZeroGain_e);

    // Sum: '<S22>/SumI1' incorporates:
    //   Constant: '<S5>/Constant'
    //   Gain: '<S22>/Kt'
    //   MATLABSystem: '<S23>/I_pitch'
    //   Start for MATLABSystem: '<S23>/I_pitch'
    //   Product: '<S22>/IOut'
    //   Sum: '<S22>/SumI3'

    Controller_B.ZeroGain_e = (Controller_P.Constant_Value_b -
      Controller_B.NOut_b) * Controller_P.PIDController_Kt +
      Controller_B.Errory1 * Controller_B.ZeroGain_e;

    // Signum: '<S24>/SignPreIntegrator'
    if (Controller_B.ZeroGain_e < 0.0) {
      // DataTypeConversion: '<S24>/DataTypeConv2'
      Controller_B.spsi = -1.0;
    } else if (Controller_B.ZeroGain_e > 0.0) {
      // DataTypeConversion: '<S24>/DataTypeConv2'
      Controller_B.spsi = 1.0;
    } else if (Controller_B.ZeroGain_e == 0.0) {
      // DataTypeConversion: '<S24>/DataTypeConv2'
      Controller_B.spsi = 0.0;
    } else {
      // DataTypeConversion: '<S24>/DataTypeConv2'
      Controller_B.spsi = Controller_B.ZeroGain_e;
    }

    // End of Signum: '<S24>/SignPreIntegrator'

    // DataTypeConversion: '<S24>/DataTypeConv1'
    if (Controller_B.Switch_j < 128.0) {
      Controller_B.rtb_DataTypeConv2_c_p = (int8_T)Controller_B.Switch_j;
    } else {
      Controller_B.rtb_DataTypeConv2_c_p = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S24>/DataTypeConv1'

    // DataTypeConversion: '<S24>/DataTypeConv2'
    if (Controller_B.spsi < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.spsi;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S22>/Switch' incorporates:
    //   Constant: '<S22>/Constant'
    //   Logic: '<S24>/AND'
    //   RelationalOperator: '<S24>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_c_p ==
         Controller_B.i0)) {
      Controller_B.Switch_j = Controller_P.Constant_Value_d0;
    } else {
      Controller_B.Switch_j = Controller_B.ZeroGain_e;
    }

    // End of Switch: '<S22>/Switch'

    // Gain: '<S27>/ZeroGain'
    Controller_B.ZeroGain_e = Controller_P.ZeroGain_Gain_g * Controller_B.NOut_e;

    // DeadZone: '<S27>/DeadZone'
    if (Controller_B.NOut_e > Controller_P.PIDController_UpperSaturationLi) {
      Controller_B.NOut_e -= Controller_P.PIDController_UpperSaturationLi;
    } else if (Controller_B.NOut_e >=
               Controller_P.PIDController_LowerSaturationLi) {
      Controller_B.NOut_e = 0.0;
    } else {
      Controller_B.NOut_e -= Controller_P.PIDController_LowerSaturationLi;
    }

    // End of DeadZone: '<S27>/DeadZone'

    // RelationalOperator: '<S27>/NotEqual'
    Controller_B.NotEqual = (Controller_B.ZeroGain_e != Controller_B.NOut_e);

    // Signum: '<S27>/SignDeltaU'
    if (Controller_B.NOut_e < 0.0) {
      Controller_B.NOut_e = -1.0;
    } else if (Controller_B.NOut_e > 0.0) {
      Controller_B.NOut_e = 1.0;
    } else {
      if (Controller_B.NOut_e == 0.0) {
        Controller_B.NOut_e = 0.0;
      }
    }

    // End of Signum: '<S27>/SignDeltaU'

    // Start for MATLABSystem: '<S26>/I_roll' incorporates:
    //   MATLABSystem: '<S26>/I_roll'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_c1.SampleTime == Controller_P.I_roll_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_c1.SampleTime = Controller_P.I_roll_SampleTime;
    }

    ParamGet_Controller_966.get_parameter(&Controller_B.ZeroGain_e);

    // Sum: '<S25>/SumI1' incorporates:
    //   Constant: '<S5>/Constant'
    //   Gain: '<S25>/Kt'
    //   MATLABSystem: '<S26>/I_roll'
    //   Start for MATLABSystem: '<S26>/I_roll'
    //   Product: '<S25>/IOut'
    //   Sum: '<S25>/SumI3'

    Controller_B.ZeroGain_e = (Controller_P.Constant_Value_b -
      Controller_B.Switch_o) * Controller_P.PIDController_Kt_d +
      Controller_B.Errorz4 * Controller_B.ZeroGain_e;

    // Signum: '<S27>/SignPreIntegrator'
    if (Controller_B.ZeroGain_e < 0.0) {
      // DataTypeConversion: '<S27>/DataTypeConv2'
      Controller_B.spsi = -1.0;
    } else if (Controller_B.ZeroGain_e > 0.0) {
      // DataTypeConversion: '<S27>/DataTypeConv2'
      Controller_B.spsi = 1.0;
    } else if (Controller_B.ZeroGain_e == 0.0) {
      // DataTypeConversion: '<S27>/DataTypeConv2'
      Controller_B.spsi = 0.0;
    } else {
      // DataTypeConversion: '<S27>/DataTypeConv2'
      Controller_B.spsi = Controller_B.ZeroGain_e;
    }

    // End of Signum: '<S27>/SignPreIntegrator'

    // DataTypeConversion: '<S27>/DataTypeConv1'
    if (Controller_B.NOut_e < 128.0) {
      Controller_B.rtb_DataTypeConv2_c_p = (int8_T)Controller_B.NOut_e;
    } else {
      Controller_B.rtb_DataTypeConv2_c_p = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S27>/DataTypeConv1'

    // DataTypeConversion: '<S27>/DataTypeConv2'
    if (Controller_B.spsi < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.spsi;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S25>/Switch' incorporates:
    //   Constant: '<S25>/Constant'
    //   Logic: '<S27>/AND'
    //   RelationalOperator: '<S27>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_c_p ==
         Controller_B.i0)) {
      Controller_B.NOut_e = Controller_P.Constant_Value_g;
    } else {
      Controller_B.NOut_e = Controller_B.ZeroGain_e;
    }

    // End of Switch: '<S25>/Switch'

    // Gain: '<S30>/ZeroGain'
    Controller_B.ZeroGain_e = Controller_P.ZeroGain_Gain_n *
      Controller_B.ChooseControllersignal_c;

    // DeadZone: '<S30>/DeadZone'
    if (Controller_B.ChooseControllersignal_c >
        Controller_P.PIDController_UpperSaturation_j) {
      Controller_B.ChooseControllersignal_c -=
        Controller_P.PIDController_UpperSaturation_j;
    } else if (Controller_B.ChooseControllersignal_c >=
               Controller_P.PIDController_LowerSaturation_e) {
      Controller_B.ChooseControllersignal_c = 0.0;
    } else {
      Controller_B.ChooseControllersignal_c -=
        Controller_P.PIDController_LowerSaturation_e;
    }

    // End of DeadZone: '<S30>/DeadZone'

    // RelationalOperator: '<S30>/NotEqual'
    Controller_B.NotEqual = (Controller_B.ZeroGain_e !=
      Controller_B.ChooseControllersignal_c);

    // Signum: '<S30>/SignDeltaU'
    if (Controller_B.ChooseControllersignal_c < 0.0) {
      Controller_B.ChooseControllersignal_c = -1.0;
    } else if (Controller_B.ChooseControllersignal_c > 0.0) {
      Controller_B.ChooseControllersignal_c = 1.0;
    } else {
      if (Controller_B.ChooseControllersignal_c == 0.0) {
        Controller_B.ChooseControllersignal_c = 0.0;
      }
    }

    // End of Signum: '<S30>/SignDeltaU'

    // Start for MATLABSystem: '<S29>/I_yaw' incorporates:
    //   MATLABSystem: '<S29>/I_yaw'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_om.SampleTime == Controller_P.I_yaw_SampleTime))
    {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_om.SampleTime = Controller_P.I_yaw_SampleTime;
    }

    ParamGet_Controller_938.get_parameter(&Controller_B.ZeroGain_e);

    // Sum: '<S28>/SumI1' incorporates:
    //   Constant: '<S5>/Constant'
    //   Gain: '<S28>/Kt'
    //   MATLABSystem: '<S29>/I_yaw'
    //   Start for MATLABSystem: '<S29>/I_yaw'
    //   Product: '<S28>/IOut'
    //   Sum: '<S28>/SumI3'

    Controller_B.ZeroGain_e = (Controller_P.Constant_Value_b -
      Controller_B.NOut_m) * Controller_P.PIDController_Kt_j +
      Controller_B.Errorx1 * Controller_B.ZeroGain_e;

    // Update for DiscreteIntegrator: '<S25>/Integrator'
    Controller_DWork.Integrator_DSTATE_nm += Controller_P.Integrator_gainval *
      Controller_B.NOut_e;

    // Update for DiscreteIntegrator: '<S25>/Filter'
    Controller_DWork.Filter_DSTATE_gs += Controller_P.Filter_gainval *
      Controller_B.RandomSource;

    // Update for DiscreteIntegrator: '<S22>/Integrator'
    Controller_DWork.Integrator_DSTATE_c += Controller_P.Integrator_gainval_b *
      Controller_B.Switch_j;

    // Update for DiscreteIntegrator: '<S22>/Filter'
    Controller_DWork.Filter_DSTATE_fb += Controller_P.Filter_gainval_l *
      Controller_B.Switch;

    // Signum: '<S30>/SignPreIntegrator'
    if (Controller_B.ZeroGain_e < 0.0) {
      // DataTypeConversion: '<S30>/DataTypeConv2'
      Controller_B.spsi = -1.0;
    } else if (Controller_B.ZeroGain_e > 0.0) {
      // DataTypeConversion: '<S30>/DataTypeConv2'
      Controller_B.spsi = 1.0;
    } else if (Controller_B.ZeroGain_e == 0.0) {
      // DataTypeConversion: '<S30>/DataTypeConv2'
      Controller_B.spsi = 0.0;
    } else {
      // DataTypeConversion: '<S30>/DataTypeConv2'
      Controller_B.spsi = Controller_B.ZeroGain_e;
    }

    // End of Signum: '<S30>/SignPreIntegrator'

    // DataTypeConversion: '<S30>/DataTypeConv1'
    if (Controller_B.ChooseControllersignal_c < 128.0) {
      Controller_B.rtb_DataTypeConv2_c_p = (int8_T)
        Controller_B.ChooseControllersignal_c;
    } else {
      Controller_B.rtb_DataTypeConv2_c_p = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S30>/DataTypeConv1'

    // DataTypeConversion: '<S30>/DataTypeConv2'
    if (Controller_B.spsi < 128.0) {
      Controller_B.i0 = (int8_T)Controller_B.spsi;
    } else {
      Controller_B.i0 = MAX_int8_T;
    }

    // Switch: '<S28>/Switch' incorporates:
    //   Constant: '<S28>/Constant'
    //   Logic: '<S30>/AND'
    //   RelationalOperator: '<S30>/Equal'

    if (Controller_B.NotEqual && (Controller_B.rtb_DataTypeConv2_c_p ==
         Controller_B.i0)) {
      Controller_B.ZeroGain_e = Controller_P.Constant_Value_e;
    }

    // End of Switch: '<S28>/Switch'

    // Update for DiscreteIntegrator: '<S28>/Integrator'
    Controller_DWork.Integrator_DSTATE_ch += Controller_P.Integrator_gainval_l *
      Controller_B.ZeroGain_e;

    // Update for DiscreteIntegrator: '<S28>/Filter'
    Controller_DWork.Filter_DSTATE_l += Controller_P.Filter_gainval_e *
      Controller_B.SignPreIntegrator_k;
  }

  // End of Logic: '<Root>/Logical Operator4'
  // End of Outputs for SubSystem: '<Root>/Subsystem'
  // MATLAB Function 'thrust alloc2': '<S15>:1'
  // '<S15>:1:39'
  //  lx1 = 0.16;
  //  ly1 = 0.11;
  //  ly2 = 0.11;
  //  lx2 = 0.16;
  //  ly3 = 0.11;
  //  lx5 = 0.2;
  //  ly4 = 0.11;
  //  lz6 = 0.1; % Måste mätas
  //
  //  T = [...
  //      0, 0, 1, 1, 0, 0;
  //      0, 0, 0, 0, 0, -1;
  //      -1, -1, 0, 0, -1, 0;
  //      ly1, -ly2, 0, 0, 0, lz6;
  //      lx1, lx2, 0, 0, -lx5, 0;
  //      0, 0, ly3, -ly4, 0, 0];
  //
  //  T = [...
  //          0, 0, 1, 1, 0, 0;
  //      0, 0, 0, 0, 0, -1;
  //      -1, -1, 0, 0, -1, 0;
  //      1, -1, 0, 0, 0, 1;
  //      1, 1, 0, 0, -1, 0;
  //      0, 0, 1, -1, 0, 0];
  //  thrust_allocation = (T.')*inv(T*(T.'));
  // '<S15>:1:39'
  for (Controller_B.i = 0; Controller_B.i < 6; Controller_B.i++) {
    // MultiPortSwitch: '<Root>/Choose Controller or test' incorporates:
    //   MATLABSystem: '<Root>/Get test'
    //   Start for MATLABSystem: '<Root>/Get test'

    if (Controller_B.value == 0) {
      Controller_B.ChooseControllersignal[Controller_B.i] =
        Controller_B.OutportBufferForThrusters[Controller_B.i];
    } else {
      // MultiPortSwitch: '<Root>/Choose Controller signal' incorporates:
      //   Constant: '<Root>/no control'
      //   MATLAB Function: '<Root>/thrust alloc2'
      //   MATLABSystem: '<Root>/Get controller type'
      //   Start for MATLABSystem: '<Root>/Get controller type'

      switch (Controller_B.value_k) {
       case 0:
        Controller_B.ChooseControllersignal[Controller_B.i] =
          Controller_B.sf_thrustalloc.thrusters[Controller_B.i];
        break;

       case 1:
        Controller_B.ChooseControllersignal[Controller_B.i] =
          Controller_B.sf_thrustalloc1.thrusters[Controller_B.i];
        break;

       case 2:
        Controller_B.ChooseControllersignal[Controller_B.i] = 0.0;
        for (Controller_B.value_c = 0; Controller_B.value_c < 6;
             Controller_B.value_c++) {
          Controller_B.ChooseControllersignal[Controller_B.i] += a[6 *
            Controller_B.value_c + Controller_B.i] *
            Controller_B.OutportBufferForOut2[Controller_B.value_c];
        }
        break;

       default:
        Controller_B.ChooseControllersignal[Controller_B.i] =
          Controller_P.nocontrol_Value[Controller_B.i];
        break;
      }

      // End of MultiPortSwitch: '<Root>/Choose Controller signal'
    }

    // End of MultiPortSwitch: '<Root>/Choose Controller or test'
  }

  // Outputs for Atomic SubSystem: '<Root>/Enable thrusters'
  // Start for MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Inport: '<S17>/In1'
  //   MATLABSystem: '<S3>/SourceBlock'

  Controller_B.p = Sub_Controller_997.getLatestMessage
    (&Controller_B.varargout_2_g);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S17>/Enable'

  if (Controller_B.p) {
    Controller_B.In1_b = Controller_B.varargout_2_g;
  }

  // End of Start for MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Enable thrusters'

  // Outputs for Enabled SubSystem: '<Root>/toPWM' incorporates:
  //   EnablePort: '<S16>/Enable'

  // Logic: '<Root>/Logical Operator2' incorporates:
  //   Logic: '<Root>/Logical Operator1'

  if ((Controller_B.Compare || Controller_B.LogicalOperator) &&
      Controller_B.In1_b.Data) {
    // Start for MATLABSystem: '<S78>/Get Parameter' incorporates:
    //   MATLABSystem: '<S78>/Get Parameter'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj.SampleTime ==
          Controller_P.GetParameter_SampleTime_e)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj.SampleTime = Controller_P.GetParameter_SampleTime_e;
    }

    ParamGet_Controller_858.get_parameter(&Controller_B.NotEqual);

    // Start for MATLABSystem: '<S78>/Get Parameter1' incorporates:
    //   MATLABSystem: '<S78>/Get Parameter1'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_l.SampleTime ==
          Controller_P.GetParameter1_SampleTime_a)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_l.SampleTime =
        Controller_P.GetParameter1_SampleTime_a;
    }

    ParamGet_Controller_861.get_parameter(&Controller_B.Compare);

    // Start for MATLABSystem: '<S78>/Get Parameter2' incorporates:
    //   MATLABSystem: '<S78>/Get Parameter2'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_n.SampleTime ==
          Controller_P.GetParameter2_SampleTime_m)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_n.SampleTime =
        Controller_P.GetParameter2_SampleTime_m;
    }

    ParamGet_Controller_862.get_parameter(&Controller_B.LogicalOperator);

    // Start for MATLABSystem: '<S78>/Get Parameter3' incorporates:
    //   MATLABSystem: '<S78>/Get Parameter3'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_c.SampleTime ==
          Controller_P.GetParameter3_SampleTime_n)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_c.SampleTime =
        Controller_P.GetParameter3_SampleTime_n;
    }

    ParamGet_Controller_863.get_parameter(&Controller_B.value_f);

    // Start for MATLABSystem: '<S78>/Get Parameter4' incorporates:
    //   MATLABSystem: '<S78>/Get Parameter4'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_nt.SampleTime ==
          Controller_P.GetParameter4_SampleTime_b)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_nt.SampleTime =
        Controller_P.GetParameter4_SampleTime_b;
    }

    ParamGet_Controller_864.get_parameter(&Controller_B.value_g);

    // Start for MATLABSystem: '<S78>/Get Parameter5' incorporates:
    //   MATLABSystem: '<S78>/Get Parameter5'

    Controller_B.p = false;
    Controller_B.p_c = true;
    if (!(Controller_DWork.obj_ls.SampleTime ==
          Controller_P.GetParameter5_SampleTime_p)) {
      Controller_B.p_c = false;
    }

    if (Controller_B.p_c) {
      Controller_B.p = true;
    }

    if (!Controller_B.p) {
      Controller_DWork.obj_ls.SampleTime =
        Controller_P.GetParameter5_SampleTime_p;
    }

    ParamGet_Controller_865.get_parameter(&Controller_B.p);

    // MATLAB Function: '<S16>/PWM assign' incorporates:
    //   Constant: '<S76>/Constant'

    // MATLAB Function 'toPWM/Calc pwm signal': '<S77>:1'
    //  thruster values should be between 1100 and 1900 microseconds (us)
    //  values less than 1500 us are backwards; values more than are forwards
    // '<S77>:1:5'
    Controller_B.msg = Controller_P.Constant_Value_i;

    // Product: '<S16>/Product' incorporates:
    //   MATLABSystem: '<S78>/Get Parameter'
    //   Start for MATLABSystem: '<S78>/Get Parameter'

    // MATLAB Function 'toPWM/PWM assign': '<S79>:1'
    // '<S79>:1:4'
    Controller_B.ChooseControllersignal_c = Controller_B.ChooseControllersignal
      [0] * (real_T)Controller_B.NotEqual;

    // Saturate: '<S16>/Saturation'
    if (Controller_B.ChooseControllersignal_c > Controller_P.Saturation_UpperSat)
    {
      Controller_B.ChooseControllersignal_c = Controller_P.Saturation_UpperSat;
    } else {
      if (Controller_B.ChooseControllersignal_c <
          Controller_P.Saturation_LowerSat) {
        Controller_B.ChooseControllersignal_c = Controller_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S16>/Calc pwm signal'
    //   Saturate: '<S16>/Saturation'

    Controller_B.spsi = floor((Controller_B.ChooseControllersignal_c + 1.0) *
      400.0 + 1100.0);
    if (rtIsNaN(Controller_B.spsi) || rtIsInf(Controller_B.spsi)) {
      Controller_B.spsi = 0.0;
    } else {
      Controller_B.spsi = fmod(Controller_B.spsi, 65536.0);
    }

    // MATLAB Function: '<S16>/PWM assign' incorporates:
    //   DataTypeConversion: '<S16>/Data Type Conversion'

    Controller_B.msg.Data[0] = (uint16_T)(Controller_B.spsi < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-Controller_B.spsi : (int32_T)(uint16_T)
      Controller_B.spsi);

    // Product: '<S16>/Product' incorporates:
    //   MATLABSystem: '<S78>/Get Parameter1'
    //   Start for MATLABSystem: '<S78>/Get Parameter1'

    Controller_B.ChooseControllersignal_c = Controller_B.ChooseControllersignal
      [1] * (real_T)Controller_B.Compare;

    // Saturate: '<S16>/Saturation'
    if (Controller_B.ChooseControllersignal_c > Controller_P.Saturation_UpperSat)
    {
      Controller_B.ChooseControllersignal_c = Controller_P.Saturation_UpperSat;
    } else {
      if (Controller_B.ChooseControllersignal_c <
          Controller_P.Saturation_LowerSat) {
        Controller_B.ChooseControllersignal_c = Controller_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S16>/Calc pwm signal'
    //   Saturate: '<S16>/Saturation'

    Controller_B.spsi = floor((Controller_B.ChooseControllersignal_c + 1.0) *
      400.0 + 1100.0);
    if (rtIsNaN(Controller_B.spsi) || rtIsInf(Controller_B.spsi)) {
      Controller_B.spsi = 0.0;
    } else {
      Controller_B.spsi = fmod(Controller_B.spsi, 65536.0);
    }

    // MATLAB Function: '<S16>/PWM assign' incorporates:
    //   DataTypeConversion: '<S16>/Data Type Conversion'

    Controller_B.msg.Data[1] = (uint16_T)(Controller_B.spsi < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-Controller_B.spsi : (int32_T)(uint16_T)
      Controller_B.spsi);

    // Product: '<S16>/Product' incorporates:
    //   MATLABSystem: '<S78>/Get Parameter2'
    //   Start for MATLABSystem: '<S78>/Get Parameter2'

    Controller_B.ChooseControllersignal_c = Controller_B.ChooseControllersignal
      [2] * (real_T)Controller_B.LogicalOperator;

    // Saturate: '<S16>/Saturation'
    if (Controller_B.ChooseControllersignal_c > Controller_P.Saturation_UpperSat)
    {
      Controller_B.ChooseControllersignal_c = Controller_P.Saturation_UpperSat;
    } else {
      if (Controller_B.ChooseControllersignal_c <
          Controller_P.Saturation_LowerSat) {
        Controller_B.ChooseControllersignal_c = Controller_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S16>/Calc pwm signal'
    //   Saturate: '<S16>/Saturation'

    Controller_B.spsi = floor((Controller_B.ChooseControllersignal_c + 1.0) *
      400.0 + 1100.0);
    if (rtIsNaN(Controller_B.spsi) || rtIsInf(Controller_B.spsi)) {
      Controller_B.spsi = 0.0;
    } else {
      Controller_B.spsi = fmod(Controller_B.spsi, 65536.0);
    }

    // MATLAB Function: '<S16>/PWM assign' incorporates:
    //   DataTypeConversion: '<S16>/Data Type Conversion'

    Controller_B.msg.Data[2] = (uint16_T)(Controller_B.spsi < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-Controller_B.spsi : (int32_T)(uint16_T)
      Controller_B.spsi);

    // Product: '<S16>/Product' incorporates:
    //   MATLABSystem: '<S78>/Get Parameter3'
    //   Start for MATLABSystem: '<S78>/Get Parameter3'

    Controller_B.ChooseControllersignal_c = Controller_B.ChooseControllersignal
      [3] * (real_T)Controller_B.value_f;

    // Saturate: '<S16>/Saturation'
    if (Controller_B.ChooseControllersignal_c > Controller_P.Saturation_UpperSat)
    {
      Controller_B.ChooseControllersignal_c = Controller_P.Saturation_UpperSat;
    } else {
      if (Controller_B.ChooseControllersignal_c <
          Controller_P.Saturation_LowerSat) {
        Controller_B.ChooseControllersignal_c = Controller_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S16>/Calc pwm signal'
    //   Saturate: '<S16>/Saturation'

    Controller_B.spsi = floor((Controller_B.ChooseControllersignal_c + 1.0) *
      400.0 + 1100.0);
    if (rtIsNaN(Controller_B.spsi) || rtIsInf(Controller_B.spsi)) {
      Controller_B.spsi = 0.0;
    } else {
      Controller_B.spsi = fmod(Controller_B.spsi, 65536.0);
    }

    // MATLAB Function: '<S16>/PWM assign' incorporates:
    //   DataTypeConversion: '<S16>/Data Type Conversion'

    Controller_B.msg.Data[3] = (uint16_T)(Controller_B.spsi < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-Controller_B.spsi : (int32_T)(uint16_T)
      Controller_B.spsi);

    // Product: '<S16>/Product' incorporates:
    //   MATLABSystem: '<S78>/Get Parameter4'
    //   Start for MATLABSystem: '<S78>/Get Parameter4'

    Controller_B.ChooseControllersignal_c = Controller_B.ChooseControllersignal
      [4] * (real_T)Controller_B.value_g;

    // Saturate: '<S16>/Saturation'
    if (Controller_B.ChooseControllersignal_c > Controller_P.Saturation_UpperSat)
    {
      Controller_B.ChooseControllersignal_c = Controller_P.Saturation_UpperSat;
    } else {
      if (Controller_B.ChooseControllersignal_c <
          Controller_P.Saturation_LowerSat) {
        Controller_B.ChooseControllersignal_c = Controller_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S16>/Calc pwm signal'
    //   Saturate: '<S16>/Saturation'

    Controller_B.spsi = floor((Controller_B.ChooseControllersignal_c + 1.0) *
      400.0 + 1100.0);
    if (rtIsNaN(Controller_B.spsi) || rtIsInf(Controller_B.spsi)) {
      Controller_B.spsi = 0.0;
    } else {
      Controller_B.spsi = fmod(Controller_B.spsi, 65536.0);
    }

    // MATLAB Function: '<S16>/PWM assign' incorporates:
    //   DataTypeConversion: '<S16>/Data Type Conversion'

    Controller_B.msg.Data[4] = (uint16_T)(Controller_B.spsi < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-Controller_B.spsi : (int32_T)(uint16_T)
      Controller_B.spsi);

    // Product: '<S16>/Product' incorporates:
    //   MATLABSystem: '<S78>/Get Parameter5'
    //   Start for MATLABSystem: '<S78>/Get Parameter5'

    Controller_B.ChooseControllersignal_c = Controller_B.ChooseControllersignal
      [5] * (real_T)Controller_B.p;

    // Saturate: '<S16>/Saturation'
    if (Controller_B.ChooseControllersignal_c > Controller_P.Saturation_UpperSat)
    {
      Controller_B.ChooseControllersignal_c = Controller_P.Saturation_UpperSat;
    } else {
      if (Controller_B.ChooseControllersignal_c <
          Controller_P.Saturation_LowerSat) {
        Controller_B.ChooseControllersignal_c = Controller_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S16>/Calc pwm signal'
    //   Saturate: '<S16>/Saturation'

    Controller_B.spsi = floor((Controller_B.ChooseControllersignal_c + 1.0) *
      400.0 + 1100.0);
    if (rtIsNaN(Controller_B.spsi) || rtIsInf(Controller_B.spsi)) {
      Controller_B.spsi = 0.0;
    } else {
      Controller_B.spsi = fmod(Controller_B.spsi, 65536.0);
    }

    // MATLAB Function: '<S16>/PWM assign' incorporates:
    //   DataTypeConversion: '<S16>/Data Type Conversion'

    Controller_B.msg.Data[5] = (uint16_T)(Controller_B.spsi < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-Controller_B.spsi : (int32_T)(uint16_T)
      Controller_B.spsi);

    // '<S79>:1:5'
    Controller_B.msg.Layout.DataOffset = 0U;

    // '<S79>:1:6'
    Controller_B.msg.Layout.Dim[0].Stride = 1U;

    // '<S79>:1:7'
    Controller_B.msg.Layout.Dim[0].Size = 6U;

    // '<S79>:1:8'
    Controller_B.msg.Data_SL_Info.CurrentLength = 6U;

    // Outputs for Atomic SubSystem: '<S16>/Publish'
    // Start for MATLABSystem: '<S80>/SinkBlock' incorporates:
    //   MATLABSystem: '<S80>/SinkBlock'

    // '<S79>:1:9'
    Pub_Controller_607.publish(&Controller_B.msg);

    // End of Outputs for SubSystem: '<S16>/Publish'
  }

  // End of Logic: '<Root>/Logical Operator2'
  // End of Outputs for SubSystem: '<Root>/toPWM'

  // Start for MATLABSystem: '<S8>/Get alpha' incorporates:
  //   MATLABSystem: '<S8>/Get alpha'

  Controller_B.p = false;
  Controller_B.p_c = true;
  if (!(Controller_DWork.obj_hx.SampleTime == Controller_P.Getalpha_SampleTime))
  {
    Controller_B.p_c = false;
  }

  if (Controller_B.p_c) {
    Controller_B.p = true;
  }

  if (!Controller_B.p) {
    Controller_DWork.obj_hx.SampleTime = Controller_P.Getalpha_SampleTime;
  }

  ParamGet_Controller_687.get_parameter(&Controller_B.ZeroGain_e);

  // SignalConversion: '<S8>/TmpSignal ConversionAtDiscrete FilterInport2' incorporates:
  //   Constant: '<S8>/Constant'
  //   MATLABSystem: '<S8>/Get alpha'
  //   Start for MATLABSystem: '<S8>/Get alpha'

  Controller_B.TmpSignalConversionAtDiscreteFi[0] =
    Controller_P.Constant_Value_ay;
  Controller_B.TmpSignalConversionAtDiscreteFi[1] = Controller_B.ZeroGain_e;

  // DiscreteFilter: '<S8>/Discrete Filter'
  Controller_B.ChooseControllersignal_c = Controller_P.DiscreteFilter_NumCoef *
    Controller_B.OutportBufferForaccXms2 -
    Controller_B.TmpSignalConversionAtDiscreteFi[1] *
    Controller_DWork.DiscreteFilter_denStates;
  Controller_DWork.DiscreteFilter_tmp = Controller_B.ChooseControllersignal_c;

  // DiscreteFilter: '<S8>/Discrete Filter1'
  Controller_B.ZeroGain_e = Controller_P.DiscreteFilter1_NumCoef *
    Controller_B.OutportBufferForaccYms2 -
    Controller_B.TmpSignalConversionAtDiscreteFi[1] *
    Controller_DWork.DiscreteFilter1_denStates;
  Controller_DWork.DiscreteFilter1_tmp = Controller_B.ZeroGain_e;

  // DiscreteFilter: '<S8>/Discrete Filter2'
  Controller_B.SignPreIntegrator_k = Controller_P.DiscreteFilter2_NumCoef *
    Controller_B.OutportBufferForaccZms2 -
    Controller_B.TmpSignalConversionAtDiscreteFi[1] *
    Controller_DWork.DiscreteFilter2_denStates;
  Controller_DWork.DiscreteFilter2_tmp = Controller_B.SignPreIntegrator_k;

  // Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
  Controller_DWork.DiscreteTimeIntegrator_DSTATE +=
    Controller_P.DiscreteTimeIntegrator_gainval *
    Controller_B.ChooseControllersignal_c;

  // Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1'
  Controller_DWork.DiscreteTimeIntegrator1_DSTATE +=
    Controller_P.DiscreteTimeIntegrator1_gainval * Controller_B.ZeroGain_e;

  // Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator2'
  Controller_DWork.DiscreteTimeIntegrator2_DSTATE +=
    Controller_P.DiscreteTimeIntegrator2_gainval *
    Controller_B.SignPreIntegrator_k;

  // Update for DiscreteFilter: '<S8>/Discrete Filter'
  Controller_DWork.DiscreteFilter_denStates =
    Controller_DWork.DiscreteFilter_tmp;

  // Update for DiscreteFilter: '<S8>/Discrete Filter1'
  Controller_DWork.DiscreteFilter1_denStates =
    Controller_DWork.DiscreteFilter1_tmp;

  // Update for DiscreteFilter: '<S8>/Discrete Filter2'
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

    static const char_T tmp_7[23] = { '/', 'r', 'o', 'v', 'i', 'o', '/', 'e',
      'n', 'a', 'b', 'l', 'e', '_', 't', 'h', 'r', 'u', 's', 't', 'e', 'r', 's'
    };

    static const char_T tmp_8[23] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'y', 'a', 'w'
    };

    static const char_T tmp_9[24] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'r', 'o', 'l',
      'l' };

    static const char_T tmp_a[25] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'p', 'i', 't',
      'c', 'h' };

    static const char_T tmp_b[23] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'y', 'a', 'w'
    };

    static const char_T tmp_c[23] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'y', 'a', 'w'
    };

    static const char_T tmp_d[23] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'y', 'a', 'w'
    };

    static const char_T tmp_e[25] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'p', 'i', 't',
      'c', 'h' };

    static const char_T tmp_f[25] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'p', 'i', 't',
      'c', 'h' };

    static const char_T tmp_g[25] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'p', 'i', 't',
      'c', 'h' };

    static const char_T tmp_h[24] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'r', 'o', 'l',
      'l' };

    static const char_T tmp_i[24] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'r', 'o', 'l',
      'l' };

    static const char_T tmp_j[24] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'r', 'o', 'l',
      'l' };

    static const char_T tmp_k[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_l[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_m[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_n[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_o[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_p[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_q[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_r[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_s[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_t[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_u[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_v[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_w[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_x[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_y[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_z[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_10[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_11[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_12[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_13[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_14[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_15[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_16[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_17[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_18[37] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 'i', 'n', 't', 'e', 'g', 'r', 'a', 't', 'i', 'o', 'n' };

    static const char_T tmp_19[37] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'v', 'e', 'l', 'o',
      'c', 'i', 't', 'y', '_', 'z', '_', 's', 'c', 'a', 'l', 'i', 'n', 'g' };

    static const char_T tmp_1a[37] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'v', 'e', 'l', 'o',
      'c', 'i', 't', 'y', '_', 'y', '_', 's', 'c', 'a', 'l', 'i', 'n', 'g' };

    static const char_T tmp_1b[37] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'v', 'e', 'l', 'o',
      'c', 'i', 't', 'y', '_', 'x', '_', 's', 'c', 'a', 'l', 'i', 'n', 'g' };

    static const char_T tmp_1c[36] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'a', 'n', 'g', 'u',
      'l', 'a', 'r', '_', 'z', '_', 's', 'c', 'a', 'l', 'i', 'n', 'g' };

    static const char_T tmp_1d[36] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'a', 'n', 'g', 'u',
      'l', 'a', 'r', '_', 'x', '_', 's', 'c', 'a', 'l', 'i', 'n', 'g' };

    static const char_T tmp_1e[26] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'r', 'o', 'l', 'l', '_',
      'r', 'e', 'f' };

    static const char_T tmp_1f[27] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'p', 'i', 't', 'c', 'h',
      '_', 'r', 'e', 'f' };

    static const char_T tmp_1g[25] = { '/', 'M', 'a', 't', 'l', 'a', 'b', 'C',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'y', 'a', 'w', '_', 'r',
      'e', 'f' };

    static const char_T tmp_1h[21] = { '/', 's', 'e', 'n', 's', 'o', 'r', '_',
      'f', 'u', 's', 'i', 'o', 'n', '/', 's', 't', 'a', 't', 'e', 's' };

    static const char_T tmp_1i[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_1j[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'c', 'o', 'n', 't',
      'r', 'o', 'l', 'l', 'e', 'r' };

    static const char_T tmp_1k[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '6' };

    static const char_T tmp_1l[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '6' };

    static const char_T tmp_1m[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '6' };

    static const char_T tmp_1n[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '5' };

    static const char_T tmp_1o[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '5' };

    static const char_T tmp_1p[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '5' };

    static const char_T tmp_1q[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '4' };

    static const char_T tmp_1r[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '4' };

    static const char_T tmp_1s[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '4' };

    static const char_T tmp_1t[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '3' };

    static const char_T tmp_1u[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '3' };

    static const char_T tmp_1v[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '3' };

    static const char_T tmp_1w[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '2' };

    static const char_T tmp_1x[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '2' };

    static const char_T tmp_1y[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '2' };

    static const char_T tmp_1z[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'a', 'x', '_',
      's', 'c', 'a', 'l', 'e', '1' };

    static const char_T tmp_20[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'm', 'i', 'n', '_',
      's', 'c', 'a', 'l', 'e', '1' };

    static const char_T tmp_21[33] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 's', 'w', 'i', 't',
      'c', 'h', '_', 'f', 'a', 'c', 't', 'o', 'r', '1' };

    static const char_T tmp_22[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'l', 'o', 'c', 'k',
      '_', 't', '1', '_', 't', '2' };

    static const char_T tmp_23[23] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 't', 'e', 's', 't'
    };

    // Start for MATLABSystem: '<Root>/Get test'
    Controller_DWork.obj_h2.isInitialized = 0;
    Controller_DWork.objisempty_pr = true;
    Controller_DWork.obj_h2.SampleTime = Controller_P.Gettest_SampleTime;
    Controller_DWork.obj_h2.isInitialized = 1;
    for (i = 0; i < 23; i++) {
      Controller_B.cv10[i] = tmp_23[i];
    }

    Controller_B.cv10[23] = '\x00';
    ParamGet_Controller_823.initialize(Controller_B.cv10);
    ParamGet_Controller_823.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_823.set_initial_value(Contro_ParameterInitialValue_l5);

    // End of Start for MATLABSystem: '<Root>/Get test'

    // Start for Enabled SubSystem: '<Root>/Telegraph'
    // Start for MATLABSystem: '<S6>/Get Parameter'
    Controller_DWork.obj_fg.isInitialized = 0;
    Controller_DWork.objisempty_ni = true;
    Controller_DWork.obj_fg.SampleTime = Controller_P.GetParameter_SampleTime_g;
    Controller_DWork.obj_fg.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_22[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_1018.initialize(Controller_B.cv5);
    ParamGet_Controller_1018.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_1018.set_initial_value(Control_ParameterInitialValue_l);

    // End of Start for MATLABSystem: '<S6>/Get Parameter'

    // Start for S-Function (sdsprandsrc2): '<S31>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_DWork.RandomSource_SEED_DWORK, 1);
    RandSrcInitState_U_64(&Controller_DWork.RandomSource_SEED_DWORK,
                          Controller_DWork.RandomSource_STATE_DWORK, 1);

    // Start for MATLABSystem: '<S31>/Swtiching factor'
    Controller_DWork.obj_of.isInitialized = 0;
    Controller_DWork.objisempty_ls = true;
    Controller_DWork.obj_of.SampleTime = Controller_P.Swtichingfactor_SampleTime;
    Controller_DWork.obj_of.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_B.cv4[i] = tmp_21[i];
    }

    Controller_B.cv4[33] = '\x00';
    ParamGet_Controller_714.initialize(Controller_B.cv4);
    ParamGet_Controller_714.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_714.set_initial_value(Control_ParameterInitialValue_l);

    // End of Start for MATLABSystem: '<S31>/Swtiching factor'

    // Start for MATLABSystem: '<S31>/Swtiching factor1'
    Controller_DWork.obj_fx.isInitialized = 0;
    Controller_DWork.objisempty_jb = true;
    Controller_DWork.obj_fx.SampleTime =
      Controller_P.Swtichingfactor1_SampleTime;
    Controller_DWork.obj_fx.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_20[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_715.initialize(Controller_B.cv5);
    ParamGet_Controller_715.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_715.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S31>/Swtiching factor1'

    // Start for MATLABSystem: '<S31>/Swtiching factor2'
    Controller_DWork.obj_d3.isInitialized = 0;
    Controller_DWork.objisempty_jr = true;
    Controller_DWork.obj_d3.SampleTime =
      Controller_P.Swtichingfactor2_SampleTime;
    Controller_DWork.obj_d3.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_1z[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_716.initialize(Controller_B.cv5);
    ParamGet_Controller_716.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_716.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S31>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S32>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_DWork.RandomSource_SEED_DWORK_l, 1);
    RandSrcInitState_U_64(&Controller_DWork.RandomSource_SEED_DWORK_l,
                          Controller_DWork.RandomSource_STATE_DWORK_i, 1);

    // Start for MATLABSystem: '<S32>/Swtiching factor'
    Controller_DWork.obj_i.isInitialized = 0;
    Controller_DWork.objisempty_mo = true;
    Controller_DWork.obj_i.SampleTime =
      Controller_P.Swtichingfactor_SampleTime_k;
    Controller_DWork.obj_i.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_B.cv4[i] = tmp_1y[i];
    }

    Controller_B.cv4[33] = '\x00';
    ParamGet_Controller_724.initialize(Controller_B.cv4);
    ParamGet_Controller_724.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_724.set_initial_value(Control_ParameterInitialValue_l);

    // End of Start for MATLABSystem: '<S32>/Swtiching factor'

    // Start for MATLABSystem: '<S32>/Swtiching factor1'
    Controller_DWork.obj_j5.isInitialized = 0;
    Controller_DWork.objisempty_ng = true;
    Controller_DWork.obj_j5.SampleTime =
      Controller_P.Swtichingfactor1_SampleTime_i;
    Controller_DWork.obj_j5.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_1x[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_725.initialize(Controller_B.cv5);
    ParamGet_Controller_725.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_725.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S32>/Swtiching factor1'

    // Start for MATLABSystem: '<S32>/Swtiching factor2'
    Controller_DWork.obj_fu.isInitialized = 0;
    Controller_DWork.objisempty_fp = true;
    Controller_DWork.obj_fu.SampleTime =
      Controller_P.Swtichingfactor2_SampleTime_b;
    Controller_DWork.obj_fu.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_1w[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_726.initialize(Controller_B.cv5);
    ParamGet_Controller_726.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_726.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S32>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S33>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_DWork.RandomSource_SEED_DWORK_c, 1);
    RandSrcInitState_U_64(&Controller_DWork.RandomSource_SEED_DWORK_c,
                          Controller_DWork.RandomSource_STATE_DWORK_a, 1);

    // Start for MATLABSystem: '<S33>/Swtiching factor'
    Controller_DWork.obj_o.isInitialized = 0;
    Controller_DWork.objisempty_ev = true;
    Controller_DWork.obj_o.SampleTime =
      Controller_P.Swtichingfactor_SampleTime_g;
    Controller_DWork.obj_o.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_B.cv4[i] = tmp_1v[i];
    }

    Controller_B.cv4[33] = '\x00';
    ParamGet_Controller_734.initialize(Controller_B.cv4);
    ParamGet_Controller_734.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_734.set_initial_value(Control_ParameterInitialValue_l);

    // End of Start for MATLABSystem: '<S33>/Swtiching factor'

    // Start for MATLABSystem: '<S33>/Swtiching factor1'
    Controller_DWork.obj_f.isInitialized = 0;
    Controller_DWork.objisempty_em = true;
    Controller_DWork.obj_f.SampleTime =
      Controller_P.Swtichingfactor1_SampleTime_o;
    Controller_DWork.obj_f.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_1u[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_735.initialize(Controller_B.cv5);
    ParamGet_Controller_735.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_735.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S33>/Swtiching factor1'

    // Start for MATLABSystem: '<S33>/Swtiching factor2'
    Controller_DWork.obj_mb.isInitialized = 0;
    Controller_DWork.objisempty_ks = true;
    Controller_DWork.obj_mb.SampleTime =
      Controller_P.Swtichingfactor2_SampleTime_o;
    Controller_DWork.obj_mb.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_1t[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_736.initialize(Controller_B.cv5);
    ParamGet_Controller_736.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_736.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S33>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S34>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_DWork.RandomSource_SEED_DWORK_i, 1);
    RandSrcInitState_U_64(&Controller_DWork.RandomSource_SEED_DWORK_i,
                          Controller_DWork.RandomSource_STATE_DWORK_g, 1);

    // Start for MATLABSystem: '<S34>/Swtiching factor'
    Controller_DWork.obj_gv.isInitialized = 0;
    Controller_DWork.objisempty_a3j = true;
    Controller_DWork.obj_gv.SampleTime =
      Controller_P.Swtichingfactor_SampleTime_n;
    Controller_DWork.obj_gv.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_B.cv4[i] = tmp_1s[i];
    }

    Controller_B.cv4[33] = '\x00';
    ParamGet_Controller_744.initialize(Controller_B.cv4);
    ParamGet_Controller_744.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_744.set_initial_value(Control_ParameterInitialValue_l);

    // End of Start for MATLABSystem: '<S34>/Swtiching factor'

    // Start for MATLABSystem: '<S34>/Swtiching factor1'
    Controller_DWork.obj_c2.isInitialized = 0;
    Controller_DWork.objisempty_hv = true;
    Controller_DWork.obj_c2.SampleTime =
      Controller_P.Swtichingfactor1_SampleTime_j;
    Controller_DWork.obj_c2.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_1r[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_745.initialize(Controller_B.cv5);
    ParamGet_Controller_745.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_745.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S34>/Swtiching factor1'

    // Start for MATLABSystem: '<S34>/Swtiching factor2'
    Controller_DWork.obj_g0e.isInitialized = 0;
    Controller_DWork.objisempty_o = true;
    Controller_DWork.obj_g0e.SampleTime =
      Controller_P.Swtichingfactor2_SampleTime_e;
    Controller_DWork.obj_g0e.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_1q[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_746.initialize(Controller_B.cv5);
    ParamGet_Controller_746.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_746.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S34>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S35>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_DWork.RandomSource_SEED_DWORK_k, 1);
    RandSrcInitState_U_64(&Controller_DWork.RandomSource_SEED_DWORK_k,
                          Controller_DWork.RandomSource_STATE_DWORK_j, 1);

    // Start for MATLABSystem: '<S35>/Swtiching factor'
    Controller_DWork.obj_j0.isInitialized = 0;
    Controller_DWork.objisempty_fj = true;
    Controller_DWork.obj_j0.SampleTime =
      Controller_P.Swtichingfactor_SampleTime_nq;
    Controller_DWork.obj_j0.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_B.cv4[i] = tmp_1p[i];
    }

    Controller_B.cv4[33] = '\x00';
    ParamGet_Controller_850.initialize(Controller_B.cv4);
    ParamGet_Controller_850.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_850.set_initial_value(Control_ParameterInitialValue_l);

    // End of Start for MATLABSystem: '<S35>/Swtiching factor'

    // Start for MATLABSystem: '<S35>/Swtiching factor1'
    Controller_DWork.obj_hr.isInitialized = 0;
    Controller_DWork.objisempty_nl = true;
    Controller_DWork.obj_hr.SampleTime =
      Controller_P.Swtichingfactor1_SampleTime_a;
    Controller_DWork.obj_hr.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_1o[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_851.initialize(Controller_B.cv5);
    ParamGet_Controller_851.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_851.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S35>/Swtiching factor1'

    // Start for MATLABSystem: '<S35>/Swtiching factor2'
    Controller_DWork.obj_dn.isInitialized = 0;
    Controller_DWork.objisempty_kk = true;
    Controller_DWork.obj_dn.SampleTime =
      Controller_P.Swtichingfactor2_SampleTime_n;
    Controller_DWork.obj_dn.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_1n[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_852.initialize(Controller_B.cv5);
    ParamGet_Controller_852.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_852.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S35>/Swtiching factor2'

    // Start for S-Function (sdsprandsrc2): '<S36>/Random Source'
    Controlle_RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
      &Controller_DWork.RandomSource_SEED_DWORK_g, 1);
    RandSrcInitState_U_64(&Controller_DWork.RandomSource_SEED_DWORK_g,
                          Controller_DWork.RandomSource_STATE_DWORK_h, 1);

    // Start for MATLABSystem: '<S36>/Swtiching factor'
    Controller_DWork.obj_gf.isInitialized = 0;
    Controller_DWork.objisempty_k1 = true;
    Controller_DWork.obj_gf.SampleTime =
      Controller_P.Swtichingfactor_SampleTime_f;
    Controller_DWork.obj_gf.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      Controller_B.cv4[i] = tmp_1m[i];
    }

    Controller_B.cv4[33] = '\x00';
    ParamGet_Controller_764.initialize(Controller_B.cv4);
    ParamGet_Controller_764.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_764.set_initial_value(Control_ParameterInitialValue_l);

    // End of Start for MATLABSystem: '<S36>/Swtiching factor'

    // Start for MATLABSystem: '<S36>/Swtiching factor1'
    Controller_DWork.obj_cvy.isInitialized = 0;
    Controller_DWork.objisempty_gk = true;
    Controller_DWork.obj_cvy.SampleTime =
      Controller_P.Swtichingfactor1_SampleTime_e;
    Controller_DWork.obj_cvy.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_1l[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_765.initialize(Controller_B.cv5);
    ParamGet_Controller_765.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_765.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S36>/Swtiching factor1'

    // Start for MATLABSystem: '<S36>/Swtiching factor2'
    Controller_DWork.obj_dt.isInitialized = 0;
    Controller_DWork.objisempty_kl = true;
    Controller_DWork.obj_dt.SampleTime =
      Controller_P.Swtichingfactor2_SampleTime_c;
    Controller_DWork.obj_dt.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_1k[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_766.initialize(Controller_B.cv5);
    ParamGet_Controller_766.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_766.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S36>/Swtiching factor2'
    // End of Start for SubSystem: '<Root>/Telegraph'

    // Start for MATLABSystem: '<Root>/Get controller type'
    Controller_DWork.obj_nl.isInitialized = 0;
    Controller_DWork.objisempty_m0 = true;
    Controller_DWork.obj_nl.SampleTime =
      Controller_P.Getcontrollertype_SampleTime;
    Controller_DWork.obj_nl.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_B.cv5[i] = tmp_1j[i];
    }

    Controller_B.cv5[29] = '\x00';
    ParamGet_Controller_106.initialize(Controller_B.cv5);
    ParamGet_Controller_106.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_106.set_initial_value(Control_ParameterInitialValue_l);

    // End of Start for MATLABSystem: '<Root>/Get controller type'

    // Start for Atomic SubSystem: '<Root>/cmd_vel'
    // Start for MATLABSystem: '<S9>/SourceBlock'
    Controller_DWork.obj_nf.isInitialized = 0;
    Controller_DWork.objisempty_gn = true;
    Controller_DWork.obj_nf.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      Controller_B.cv13[i] = tmp_1i[i];
    }

    Controller_B.cv13[8] = '\x00';
    Sub_Controller_1.createSubscriber(Controller_B.cv13,
      Controller_MessageQueueLen_l);

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of Start for SubSystem: '<Root>/cmd_vel'

    // Start for Atomic SubSystem: '<Root>/imu_data'
    // Start for MATLABSystem: '<S11>/SourceBlock'
    Controller_DWork.obj_ki.isInitialized = 0;
    Controller_DWork.objisempty_i = true;
    Controller_DWork.obj_ki.isInitialized = 1;
    for (i = 0; i < 21; i++) {
      Controller_B.cv11[i] = tmp_1h[i];
    }

    Controller_B.cv11[21] = '\x00';
    Sub_Controller_28.createSubscriber(Controller_B.cv11,
      Controller_MessageQueueLen_l);

    // End of Start for MATLABSystem: '<S11>/SourceBlock'
    // End of Start for SubSystem: '<Root>/imu_data'

    // Start for MATLABSystem: '<Root>/yaw_ref'
    Controller_DWork.obj_o5.isInitialized = 0;
    Controller_DWork.objisempty_j5 = true;
    Controller_DWork.obj_o5.SampleTime = Controller_P.yaw_ref_SampleTime;
    Controller_DWork.obj_o5.isInitialized = 1;
    for (i = 0; i < 25; i++) {
      Controller_B.cv8[i] = tmp_1g[i];
    }

    Controller_B.cv8[25] = '\x00';
    ParamGet_Controller_981.initialize(Controller_B.cv8);
    ParamGet_Controller_981.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_981.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<Root>/yaw_ref'

    // Start for MATLABSystem: '<Root>/pitch_ref'
    Controller_DWork.obj_mbl.isInitialized = 0;
    Controller_DWork.objisempty_ho = true;
    Controller_DWork.obj_mbl.SampleTime = Controller_P.pitch_ref_SampleTime;
    Controller_DWork.obj_mbl.isInitialized = 1;
    for (i = 0; i < 27; i++) {
      Controller_B.cv6[i] = tmp_1f[i];
    }

    Controller_B.cv6[27] = '\x00';
    ParamGet_Controller_982.initialize(Controller_B.cv6);
    ParamGet_Controller_982.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_982.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<Root>/pitch_ref'

    // Start for MATLABSystem: '<Root>/roll_ref'
    Controller_DWork.obj_pk.isInitialized = 0;
    Controller_DWork.objisempty_lg = true;
    Controller_DWork.obj_pk.SampleTime = Controller_P.roll_ref_SampleTime;
    Controller_DWork.obj_pk.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_1e[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_980.initialize(Controller_B.cv7);
    ParamGet_Controller_980.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_980.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<Root>/roll_ref'

    // Start for Enabled SubSystem: '<Root>/Enabled Subsystem'
    // Start for MATLABSystem: '<S4>/Get Parameter'
    Controller_DWork.obj_km.isInitialized = 0;
    Controller_DWork.objisempty_c1 = true;
    Controller_DWork.obj_km.SampleTime = Controller_P.GetParameter_SampleTime;
    Controller_DWork.obj_km.isInitialized = 1;
    for (i = 0; i < 36; i++) {
      Controller_B.cv1[i] = tmp_1d[i];
    }

    Controller_B.cv1[36] = '\x00';
    ParamGet_Controller_901.initialize(Controller_B.cv1);
    ParamGet_Controller_901.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_901.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S4>/Get Parameter'

    // Start for MATLABSystem: '<S4>/Get Parameter1'
    Controller_DWork.obj_oz.isInitialized = 0;
    Controller_DWork.objisempty_k3 = true;
    Controller_DWork.obj_oz.SampleTime = Controller_P.GetParameter1_SampleTime;
    Controller_DWork.obj_oz.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_12[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_905.initialize(Controller_B.cv3);
    ParamGet_Controller_905.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_905.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S4>/Get Parameter1'

    // Start for MATLABSystem: '<S4>/Get Parameter2'
    Controller_DWork.obj_iv.isInitialized = 0;
    Controller_DWork.objisempty_jz = true;
    Controller_DWork.obj_iv.SampleTime = Controller_P.GetParameter2_SampleTime;
    Controller_DWork.obj_iv.isInitialized = 1;
    for (i = 0; i < 36; i++) {
      Controller_B.cv1[i] = tmp_1c[i];
    }

    Controller_B.cv1[36] = '\x00';
    ParamGet_Controller_907.initialize(Controller_B.cv1);
    ParamGet_Controller_907.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_907.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S4>/Get Parameter2'

    // Start for MATLABSystem: '<S4>/Get Parameter3'
    Controller_DWork.obj_dy.isInitialized = 0;
    Controller_DWork.objisempty_pe = true;
    Controller_DWork.obj_dy.SampleTime = Controller_P.GetParameter3_SampleTime;
    Controller_DWork.obj_dy.isInitialized = 1;
    for (i = 0; i < 37; i++) {
      Controller_B.cv0[i] = tmp_1b[i];
    }

    Controller_B.cv0[37] = '\x00';
    ParamGet_Controller_909.initialize(Controller_B.cv0);
    ParamGet_Controller_909.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_909.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S4>/Get Parameter3'

    // Start for MATLABSystem: '<S4>/Get Parameter4'
    Controller_DWork.obj_kg.isInitialized = 0;
    Controller_DWork.objisempty_dt = true;
    Controller_DWork.obj_kg.SampleTime = Controller_P.GetParameter4_SampleTime;
    Controller_DWork.obj_kg.isInitialized = 1;
    for (i = 0; i < 37; i++) {
      Controller_B.cv0[i] = tmp_1a[i];
    }

    Controller_B.cv0[37] = '\x00';
    ParamGet_Controller_911.initialize(Controller_B.cv0);
    ParamGet_Controller_911.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_911.set_initial_value(Contr_ParameterInitialValue_l5x);

    // End of Start for MATLABSystem: '<S4>/Get Parameter4'

    // Start for MATLABSystem: '<S4>/Get Parameter5'
    Controller_DWork.obj_ku.isInitialized = 0;
    Controller_DWork.objisempty_br = true;
    Controller_DWork.obj_ku.SampleTime = Controller_P.GetParameter5_SampleTime;
    Controller_DWork.obj_ku.isInitialized = 1;
    for (i = 0; i < 37; i++) {
      Controller_B.cv0[i] = tmp_19[i];
    }

    Controller_B.cv0[37] = '\x00';
    ParamGet_Controller_913.initialize(Controller_B.cv0);
    ParamGet_Controller_913.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_913.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S4>/Get Parameter5'
    // End of Start for SubSystem: '<Root>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/Enable integration?'
    Controller_DWork.obj_g0.isInitialized = 0;
    Controller_DWork.objisempty_lj = true;
    Controller_DWork.obj_g0.SampleTime =
      Controller_P.Enableintegration_SampleTime;
    Controller_DWork.obj_g0.isInitialized = 1;
    for (i = 0; i < 37; i++) {
      Controller_B.cv0[i] = tmp_18[i];
    }

    Controller_B.cv0[37] = '\x00';
    ParamGet_Controller_686.initialize(Controller_B.cv0);
    ParamGet_Controller_686.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_686.set_initial_value(Cont_ParameterInitialValue_l5xx);

    // End of Start for MATLABSystem: '<S8>/Enable integration?'

    // Start for Enabled SubSystem: '<Root>/decController'
    // Start for MATLABSystem: '<S57>/P_angular_vel_x'
    Controller_DWork.obj_bm.isInitialized = 0;
    Controller_DWork.objisempty_f = true;
    Controller_DWork.obj_bm.SampleTime = Controller_P.P_angular_vel_x_SampleTime;
    Controller_DWork.obj_bm.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_17[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_508.initialize(Controller_B.cv3);
    ParamGet_Controller_508.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_508.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S57>/P_angular_vel_x'

    // Start for MATLABSystem: '<S57>/D_angular_vel_x'
    Controller_DWork.obj_be.isInitialized = 0;
    Controller_DWork.objisempty_g = true;
    Controller_DWork.obj_be.SampleTime = Controller_P.D_angular_vel_x_SampleTime;
    Controller_DWork.obj_be.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_16[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_505.initialize(Controller_B.cv3);
    ParamGet_Controller_505.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_505.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S57>/D_angular_vel_x'

    // Start for MATLABSystem: '<S57>/N_angular_vel_x '
    Controller_DWork.obj_lb.isInitialized = 0;
    Controller_DWork.objisempty_d0 = true;
    Controller_DWork.obj_lb.SampleTime = Controller_P.N_angular_vel_x_SampleTime;
    Controller_DWork.obj_lb.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_15[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_507.initialize(Controller_B.cv3);
    ParamGet_Controller_507.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_507.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S57>/N_angular_vel_x '

    // Start for MATLABSystem: '<S57>/I_angular_vel_x'
    Controller_DWork.obj_pb.isInitialized = 0;
    Controller_DWork.objisempty_mb = true;
    Controller_DWork.obj_pb.SampleTime = Controller_P.I_angular_vel_x_SampleTime;
    Controller_DWork.obj_pb.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_14[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_506.initialize(Controller_B.cv3);
    ParamGet_Controller_506.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_506.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S57>/I_angular_vel_x'

    // Start for MATLABSystem: '<S60>/P_angular_vel_y'
    Controller_DWork.obj_b.isInitialized = 0;
    Controller_DWork.objisempty_j = true;
    Controller_DWork.obj_b.SampleTime = Controller_P.P_angular_vel_y_SampleTime;
    Controller_DWork.obj_b.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_13[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_522.initialize(Controller_B.cv3);
    ParamGet_Controller_522.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_522.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S60>/P_angular_vel_y'

    // Start for MATLABSystem: '<S60>/D_angular_vel_y'
    Controller_DWork.obj_m.isInitialized = 0;
    Controller_DWork.objisempty_h1 = true;
    Controller_DWork.obj_m.SampleTime = Controller_P.D_angular_vel_y_SampleTime;
    Controller_DWork.obj_m.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_12[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_519.initialize(Controller_B.cv3);
    ParamGet_Controller_519.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_519.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S60>/D_angular_vel_y'

    // Start for MATLABSystem: '<S60>/N_angular_vel_y '
    Controller_DWork.obj_dp.isInitialized = 0;
    Controller_DWork.objisempty_ex = true;
    Controller_DWork.obj_dp.SampleTime = Controller_P.N_angular_vel_y_SampleTime;
    Controller_DWork.obj_dp.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_11[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_521.initialize(Controller_B.cv3);
    ParamGet_Controller_521.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_521.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S60>/N_angular_vel_y '

    // Start for MATLABSystem: '<S60>/I_angular_vel_y'
    Controller_DWork.obj_ep.isInitialized = 0;
    Controller_DWork.objisempty_ef = true;
    Controller_DWork.obj_ep.SampleTime = Controller_P.I_angular_vel_y_SampleTime;
    Controller_DWork.obj_ep.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_10[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_520.initialize(Controller_B.cv3);
    ParamGet_Controller_520.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_520.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S60>/I_angular_vel_y'

    // Start for MATLABSystem: '<S63>/P_angular_vel_z'
    Controller_DWork.obj_e.isInitialized = 0;
    Controller_DWork.objisempty_h = true;
    Controller_DWork.obj_e.SampleTime = Controller_P.P_angular_vel_z_SampleTime;
    Controller_DWork.obj_e.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_z[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_536.initialize(Controller_B.cv3);
    ParamGet_Controller_536.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_536.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S63>/P_angular_vel_z'

    // Start for MATLABSystem: '<S63>/D_angular_vel_z'
    Controller_DWork.obj_jg.isInitialized = 0;
    Controller_DWork.objisempty_if = true;
    Controller_DWork.obj_jg.SampleTime = Controller_P.D_angular_vel_z_SampleTime;
    Controller_DWork.obj_jg.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_y[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_533.initialize(Controller_B.cv3);
    ParamGet_Controller_533.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_533.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S63>/D_angular_vel_z'

    // Start for MATLABSystem: '<S63>/N_angular_vel_z '
    Controller_DWork.obj_g.isInitialized = 0;
    Controller_DWork.objisempty_m1 = true;
    Controller_DWork.obj_g.SampleTime = Controller_P.N_angular_vel_z_SampleTime;
    Controller_DWork.obj_g.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_x[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_535.initialize(Controller_B.cv3);
    ParamGet_Controller_535.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_535.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S63>/N_angular_vel_z '

    // Start for MATLABSystem: '<S63>/I_angular_vel_z'
    Controller_DWork.obj_p.isInitialized = 0;
    Controller_DWork.objisempty_k = true;
    Controller_DWork.obj_p.SampleTime = Controller_P.I_angular_vel_z_SampleTime;
    Controller_DWork.obj_p.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_B.cv3[i] = tmp_w[i];
    }

    Controller_B.cv3[34] = '\x00';
    ParamGet_Controller_534.initialize(Controller_B.cv3);
    ParamGet_Controller_534.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_534.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S63>/I_angular_vel_z'

    // Start for MATLABSystem: '<S66>/P_vel_x'
    Controller_DWork.obj_ns.isInitialized = 0;
    Controller_DWork.objisempty_a3 = true;
    Controller_DWork.obj_ns.SampleTime = Controller_P.P_vel_x_SampleTime;
    Controller_DWork.obj_ns.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_v[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_550.initialize(Controller_B.cv7);
    ParamGet_Controller_550.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_550.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S66>/P_vel_x'

    // Start for MATLABSystem: '<S66>/D_vel_x'
    Controller_DWork.obj_d.isInitialized = 0;
    Controller_DWork.objisempty_d = true;
    Controller_DWork.obj_d.SampleTime = Controller_P.D_vel_x_SampleTime;
    Controller_DWork.obj_d.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_u[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_547.initialize(Controller_B.cv7);
    ParamGet_Controller_547.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_547.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S66>/D_vel_x'

    // Start for MATLABSystem: '<S66>/N_vel_x '
    Controller_DWork.obj_a3.isInitialized = 0;
    Controller_DWork.objisempty_il = true;
    Controller_DWork.obj_a3.SampleTime = Controller_P.N_vel_x_SampleTime;
    Controller_DWork.obj_a3.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_t[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_549.initialize(Controller_B.cv7);
    ParamGet_Controller_549.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_549.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S66>/N_vel_x '

    // Start for MATLABSystem: '<S66>/I_vel_x'
    Controller_DWork.obj_cv.isInitialized = 0;
    Controller_DWork.objisempty_pu = true;
    Controller_DWork.obj_cv.SampleTime = Controller_P.I_vel_x_SampleTime;
    Controller_DWork.obj_cv.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_s[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_548.initialize(Controller_B.cv7);
    ParamGet_Controller_548.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_548.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S66>/I_vel_x'

    // Start for MATLABSystem: '<S69>/P_vel_y'
    Controller_DWork.obj_ji.isInitialized = 0;
    Controller_DWork.objisempty_ej = true;
    Controller_DWork.obj_ji.SampleTime = Controller_P.P_vel_y_SampleTime;
    Controller_DWork.obj_ji.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_r[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_564.initialize(Controller_B.cv7);
    ParamGet_Controller_564.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_564.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S69>/P_vel_y'

    // Start for MATLABSystem: '<S69>/D_vel_y'
    Controller_DWork.obj_ny.isInitialized = 0;
    Controller_DWork.objisempty_c = true;
    Controller_DWork.obj_ny.SampleTime = Controller_P.D_vel_y_SampleTime;
    Controller_DWork.obj_ny.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_q[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_561.initialize(Controller_B.cv7);
    ParamGet_Controller_561.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_561.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S69>/D_vel_y'

    // Start for MATLABSystem: '<S69>/N_vel_y '
    Controller_DWork.obj_cb.isInitialized = 0;
    Controller_DWork.objisempty_b = true;
    Controller_DWork.obj_cb.SampleTime = Controller_P.N_vel_y_SampleTime;
    Controller_DWork.obj_cb.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_p[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_563.initialize(Controller_B.cv7);
    ParamGet_Controller_563.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_563.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S69>/N_vel_y '

    // Start for MATLABSystem: '<S69>/I_vel_y'
    Controller_DWork.obj_jx.isInitialized = 0;
    Controller_DWork.objisempty_m = true;
    Controller_DWork.obj_jx.SampleTime = Controller_P.I_vel_y_SampleTime;
    Controller_DWork.obj_jx.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_o[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_562.initialize(Controller_B.cv7);
    ParamGet_Controller_562.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_562.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S69>/I_vel_y'

    // Start for MATLABSystem: '<S72>/P_vel_z'
    Controller_DWork.obj_j.isInitialized = 0;
    Controller_DWork.objisempty_le = true;
    Controller_DWork.obj_j.SampleTime = Controller_P.P_vel_z_SampleTime;
    Controller_DWork.obj_j.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_n[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_578.initialize(Controller_B.cv7);
    ParamGet_Controller_578.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_578.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S72>/P_vel_z'

    // Start for MATLABSystem: '<S72>/D_vel_z'
    Controller_DWork.obj_a.isInitialized = 0;
    Controller_DWork.objisempty_nm = true;
    Controller_DWork.obj_a.SampleTime = Controller_P.D_vel_z_SampleTime;
    Controller_DWork.obj_a.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_m[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_575.initialize(Controller_B.cv7);
    ParamGet_Controller_575.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_575.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S72>/D_vel_z'

    // Start for MATLABSystem: '<S72>/N_vel_z '
    Controller_DWork.obj_h.isInitialized = 0;
    Controller_DWork.objisempty_e = true;
    Controller_DWork.obj_h.SampleTime = Controller_P.N_vel_z_SampleTime;
    Controller_DWork.obj_h.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_l[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_577.initialize(Controller_B.cv7);
    ParamGet_Controller_577.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_577.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S72>/N_vel_z '

    // Start for MATLABSystem: '<S72>/I_vel_z'
    Controller_DWork.obj_js.isInitialized = 0;
    Controller_DWork.objisempty_n43 = true;
    Controller_DWork.obj_js.SampleTime = Controller_P.I_vel_z_SampleTime;
    Controller_DWork.obj_js.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_B.cv7[i] = tmp_k[i];
    }

    Controller_B.cv7[26] = '\x00';
    ParamGet_Controller_576.initialize(Controller_B.cv7);
    ParamGet_Controller_576.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_576.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S72>/I_vel_z'
    // End of Start for SubSystem: '<Root>/decController'

    // Start for Enabled SubSystem: '<Root>/Subsystem'
    // Start for MATLABSystem: '<S26>/P_roll'
    Controller_DWork.obj_jp.isInitialized = 0;
    Controller_DWork.objisempty_kq = true;
    Controller_DWork.obj_jp.SampleTime = Controller_P.P_roll_SampleTime;
    Controller_DWork.obj_jp.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      Controller_B.cv9[i] = tmp_j[i];
    }

    Controller_B.cv9[24] = '\x00';
    ParamGet_Controller_968.initialize(Controller_B.cv9);
    ParamGet_Controller_968.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_968.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S26>/P_roll'

    // Start for MATLABSystem: '<S26>/D_roll'
    Controller_DWork.obj_k.isInitialized = 0;
    Controller_DWork.objisempty_h0 = true;
    Controller_DWork.obj_k.SampleTime = Controller_P.D_roll_SampleTime;
    Controller_DWork.obj_k.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      Controller_B.cv9[i] = tmp_i[i];
    }

    Controller_B.cv9[24] = '\x00';
    ParamGet_Controller_965.initialize(Controller_B.cv9);
    ParamGet_Controller_965.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_965.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S26>/D_roll'

    // Start for MATLABSystem: '<S26>/N_roll '
    Controller_DWork.obj_dp3.isInitialized = 0;
    Controller_DWork.objisempty_fn = true;
    Controller_DWork.obj_dp3.SampleTime = Controller_P.N_roll_SampleTime;
    Controller_DWork.obj_dp3.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      Controller_B.cv9[i] = tmp_h[i];
    }

    Controller_B.cv9[24] = '\x00';
    ParamGet_Controller_967.initialize(Controller_B.cv9);
    ParamGet_Controller_967.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_967.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S26>/N_roll '

    // Start for MATLABSystem: '<S23>/P_pitch'
    Controller_DWork.obj_m1.isInitialized = 0;
    Controller_DWork.objisempty_m4 = true;
    Controller_DWork.obj_m1.SampleTime = Controller_P.P_pitch_SampleTime;
    Controller_DWork.obj_m1.isInitialized = 1;
    for (i = 0; i < 25; i++) {
      Controller_B.cv8[i] = tmp_g[i];
    }

    Controller_B.cv8[25] = '\x00';
    ParamGet_Controller_954.initialize(Controller_B.cv8);
    ParamGet_Controller_954.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_954.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S23>/P_pitch'

    // Start for MATLABSystem: '<S23>/D_pitch'
    Controller_DWork.obj_b4.isInitialized = 0;
    Controller_DWork.objisempty_o5 = true;
    Controller_DWork.obj_b4.SampleTime = Controller_P.D_pitch_SampleTime;
    Controller_DWork.obj_b4.isInitialized = 1;
    for (i = 0; i < 25; i++) {
      Controller_B.cv8[i] = tmp_f[i];
    }

    Controller_B.cv8[25] = '\x00';
    ParamGet_Controller_951.initialize(Controller_B.cv8);
    ParamGet_Controller_951.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_951.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S23>/D_pitch'

    // Start for MATLABSystem: '<S23>/N_pitch '
    Controller_DWork.obj_fq.isInitialized = 0;
    Controller_DWork.objisempty_jg = true;
    Controller_DWork.obj_fq.SampleTime = Controller_P.N_pitch_SampleTime;
    Controller_DWork.obj_fq.isInitialized = 1;
    for (i = 0; i < 25; i++) {
      Controller_B.cv8[i] = tmp_e[i];
    }

    Controller_B.cv8[25] = '\x00';
    ParamGet_Controller_953.initialize(Controller_B.cv8);
    ParamGet_Controller_953.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_953.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S23>/N_pitch '

    // Start for MATLABSystem: '<S29>/P_yaw'
    Controller_DWork.obj_hn.isInitialized = 0;
    Controller_DWork.objisempty_gj = true;
    Controller_DWork.obj_hn.SampleTime = Controller_P.P_yaw_SampleTime;
    Controller_DWork.obj_hn.isInitialized = 1;
    for (i = 0; i < 23; i++) {
      Controller_B.cv10[i] = tmp_d[i];
    }

    Controller_B.cv10[23] = '\x00';
    ParamGet_Controller_940.initialize(Controller_B.cv10);
    ParamGet_Controller_940.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_940.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S29>/P_yaw'

    // Start for MATLABSystem: '<S29>/D_yaw'
    Controller_DWork.obj_ha.isInitialized = 0;
    Controller_DWork.objisempty_pl = true;
    Controller_DWork.obj_ha.SampleTime = Controller_P.D_yaw_SampleTime;
    Controller_DWork.obj_ha.isInitialized = 1;
    for (i = 0; i < 23; i++) {
      Controller_B.cv10[i] = tmp_c[i];
    }

    Controller_B.cv10[23] = '\x00';
    ParamGet_Controller_937.initialize(Controller_B.cv10);
    ParamGet_Controller_937.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_937.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S29>/D_yaw'

    // Start for MATLABSystem: '<S29>/N_yaw '
    Controller_DWork.obj_py.isInitialized = 0;
    Controller_DWork.objisempty_ifg = true;
    Controller_DWork.obj_py.SampleTime = Controller_P.N_yaw_SampleTime;
    Controller_DWork.obj_py.isInitialized = 1;
    for (i = 0; i < 23; i++) {
      Controller_B.cv10[i] = tmp_b[i];
    }

    Controller_B.cv10[23] = '\x00';
    ParamGet_Controller_939.initialize(Controller_B.cv10);
    ParamGet_Controller_939.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_939.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S29>/N_yaw '

    // Start for MATLABSystem: '<S23>/I_pitch'
    Controller_DWork.obj_jb.isInitialized = 0;
    Controller_DWork.objisempty_ljn = true;
    Controller_DWork.obj_jb.SampleTime = Controller_P.I_pitch_SampleTime;
    Controller_DWork.obj_jb.isInitialized = 1;
    for (i = 0; i < 25; i++) {
      Controller_B.cv8[i] = tmp_a[i];
    }

    Controller_B.cv8[25] = '\x00';
    ParamGet_Controller_952.initialize(Controller_B.cv8);
    ParamGet_Controller_952.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_952.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S23>/I_pitch'

    // Start for MATLABSystem: '<S26>/I_roll'
    Controller_DWork.obj_c1.isInitialized = 0;
    Controller_DWork.objisempty_e5 = true;
    Controller_DWork.obj_c1.SampleTime = Controller_P.I_roll_SampleTime;
    Controller_DWork.obj_c1.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      Controller_B.cv9[i] = tmp_9[i];
    }

    Controller_B.cv9[24] = '\x00';
    ParamGet_Controller_966.initialize(Controller_B.cv9);
    ParamGet_Controller_966.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_966.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S26>/I_roll'

    // Start for MATLABSystem: '<S29>/I_yaw'
    Controller_DWork.obj_om.isInitialized = 0;
    Controller_DWork.objisempty_gr = true;
    Controller_DWork.obj_om.SampleTime = Controller_P.I_yaw_SampleTime;
    Controller_DWork.obj_om.isInitialized = 1;
    for (i = 0; i < 23; i++) {
      Controller_B.cv10[i] = tmp_8[i];
    }

    Controller_B.cv10[23] = '\x00';
    ParamGet_Controller_938.initialize(Controller_B.cv10);
    ParamGet_Controller_938.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_938.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S29>/I_yaw'
    // End of Start for SubSystem: '<Root>/Subsystem'

    // Start for Atomic SubSystem: '<Root>/Enable thrusters'
    // Start for MATLABSystem: '<S3>/SourceBlock'
    Controller_DWork.obj_mv.isInitialized = 0;
    Controller_DWork.objisempty_j0 = true;
    Controller_DWork.obj_mv.isInitialized = 1;
    for (i = 0; i < 23; i++) {
      Controller_B.cv10[i] = tmp_7[i];
    }

    Controller_B.cv10[23] = '\x00';
    Sub_Controller_997.createSubscriber(Controller_B.cv10,
      Controller_MessageQueueLen);

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Enable thrusters'

    // Start for Enabled SubSystem: '<Root>/toPWM'
    // Start for MATLABSystem: '<S78>/Get Parameter'
    Controller_DWork.obj.isInitialized = 0;
    Controller_DWork.objisempty_n = true;
    Controller_DWork.obj.SampleTime = Controller_P.GetParameter_SampleTime_e;
    Controller_DWork.obj.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv2[i] = tmp_6[i];
    }

    Controller_B.cv2[35] = '\x00';
    ParamGet_Controller_858.initialize(Controller_B.cv2);
    ParamGet_Controller_858.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_858.set_initial_value(Con_ParameterInitialValue_l5xxx);

    // End of Start for MATLABSystem: '<S78>/Get Parameter'

    // Start for MATLABSystem: '<S78>/Get Parameter1'
    Controller_DWork.obj_l.isInitialized = 0;
    Controller_DWork.objisempty_p = true;
    Controller_DWork.obj_l.SampleTime = Controller_P.GetParameter1_SampleTime_a;
    Controller_DWork.obj_l.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv2[i] = tmp_5[i];
    }

    Controller_B.cv2[35] = '\x00';
    ParamGet_Controller_861.initialize(Controller_B.cv2);
    ParamGet_Controller_861.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_861.set_initial_value(Con_ParameterInitialValue_l5xxx);

    // End of Start for MATLABSystem: '<S78>/Get Parameter1'

    // Start for MATLABSystem: '<S78>/Get Parameter2'
    Controller_DWork.obj_n.isInitialized = 0;
    Controller_DWork.objisempty_l = true;
    Controller_DWork.obj_n.SampleTime = Controller_P.GetParameter2_SampleTime_m;
    Controller_DWork.obj_n.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv2[i] = tmp_4[i];
    }

    Controller_B.cv2[35] = '\x00';
    ParamGet_Controller_862.initialize(Controller_B.cv2);
    ParamGet_Controller_862.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_862.set_initial_value(Con_ParameterInitialValue_l5xxx);

    // End of Start for MATLABSystem: '<S78>/Get Parameter2'

    // Start for MATLABSystem: '<S78>/Get Parameter3'
    Controller_DWork.obj_c.isInitialized = 0;
    Controller_DWork.objisempty_n4 = true;
    Controller_DWork.obj_c.SampleTime = Controller_P.GetParameter3_SampleTime_n;
    Controller_DWork.obj_c.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv2[i] = tmp_3[i];
    }

    Controller_B.cv2[35] = '\x00';
    ParamGet_Controller_863.initialize(Controller_B.cv2);
    ParamGet_Controller_863.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_863.set_initial_value(Con_ParameterInitialValue_l5xxx);

    // End of Start for MATLABSystem: '<S78>/Get Parameter3'

    // Start for MATLABSystem: '<S78>/Get Parameter4'
    Controller_DWork.obj_nt.isInitialized = 0;
    Controller_DWork.objisempty_ns = true;
    Controller_DWork.obj_nt.SampleTime = Controller_P.GetParameter4_SampleTime_b;
    Controller_DWork.obj_nt.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv2[i] = tmp_2[i];
    }

    Controller_B.cv2[35] = '\x00';
    ParamGet_Controller_864.initialize(Controller_B.cv2);
    ParamGet_Controller_864.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_864.set_initial_value(Con_ParameterInitialValue_l5xxx);

    // End of Start for MATLABSystem: '<S78>/Get Parameter4'

    // Start for MATLABSystem: '<S78>/Get Parameter5'
    Controller_DWork.obj_ls.isInitialized = 0;
    Controller_DWork.objisempty_a = true;
    Controller_DWork.obj_ls.SampleTime = Controller_P.GetParameter5_SampleTime_p;
    Controller_DWork.obj_ls.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_B.cv2[i] = tmp_1[i];
    }

    Controller_B.cv2[35] = '\x00';
    ParamGet_Controller_865.initialize(Controller_B.cv2);
    ParamGet_Controller_865.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_865.set_initial_value(Con_ParameterInitialValue_l5xxx);

    // End of Start for MATLABSystem: '<S78>/Get Parameter5'

    // Start for Atomic SubSystem: '<S16>/Publish'
    // Start for MATLABSystem: '<S80>/SinkBlock'
    Controller_DWork.obj_pw.isInitialized = 0;
    Controller_DWork.objisempty = true;
    Controller_DWork.obj_pw.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      Controller_B.cv12[i] = tmp_0[i];
    }

    Controller_B.cv12[16] = '\x00';
    Pub_Controller_607.createPublisher(Controller_B.cv12,
      Controller_MessageQueueLen);

    // End of Start for MATLABSystem: '<S80>/SinkBlock'
    // End of Start for SubSystem: '<S16>/Publish'
    // End of Start for SubSystem: '<Root>/toPWM'

    // Start for MATLABSystem: '<S8>/Get alpha'
    Controller_DWork.obj_hx.isInitialized = 0;
    Controller_DWork.objisempty_g0 = true;
    Controller_DWork.obj_hx.SampleTime = Controller_P.Getalpha_SampleTime;
    Controller_DWork.obj_hx.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      Controller_B.cv9[i] = tmp[i];
    }

    Controller_B.cv9[24] = '\x00';
    ParamGet_Controller_687.initialize(Controller_B.cv9);
    ParamGet_Controller_687.initialize_error_codes(0U, 1U, 2U, 3U);
    ParamGet_Controller_687.set_initial_value(Controlle_ParameterInitialValue);

    // End of Start for MATLABSystem: '<S8>/Get alpha'

    // InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' 
    Controller_DWork.DiscreteTimeIntegrator_DSTATE =
      Controller_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' 
    Controller_DWork.DiscreteTimeIntegrator1_DSTATE =
      Controller_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator2' 
    Controller_DWork.DiscreteTimeIntegrator2_DSTATE =
      Controller_P.DiscreteTimeIntegrator2_IC;

    // InitializeConditions for DiscreteFilter: '<S8>/Discrete Filter'
    Controller_DWork.DiscreteFilter_denStates =
      Controller_P.DiscreteFilter_InitialDenominat;

    // InitializeConditions for DiscreteFilter: '<S8>/Discrete Filter1'
    Controller_DWork.DiscreteFilter1_denStates =
      Controller_P.DiscreteFilter1_InitialDenomina;

    // InitializeConditions for DiscreteFilter: '<S8>/Discrete Filter2'
    Controller_DWork.DiscreteFilter2_denStates =
      Controller_P.DiscreteFilter2_InitialDenomina;

    // SystemInitialize for Enabled SubSystem: '<Root>/Telegraph'

    // SystemInitialize for State Transition Table: '<S31>/State Transition Table' 
    Contr_StateTransitionTable_Init(&Controller_DWork.sf_StateTransitionTable);

    // SystemInitialize for State Transition Table: '<S32>/State Transition Table' 
    Contr_StateTransitionTable_Init(&Controller_DWork.sf_StateTransitionTable_i);

    // SystemInitialize for State Transition Table: '<S33>/State Transition Table' 
    Contr_StateTransitionTable_Init(&Controller_DWork.sf_StateTransitionTable_m);

    // SystemInitialize for State Transition Table: '<S34>/State Transition Table' 
    Contr_StateTransitionTable_Init(&Controller_DWork.sf_StateTransitionTable_mx);

    // SystemInitialize for State Transition Table: '<S35>/State Transition Table' 
    Contr_StateTransitionTable_Init(&Controller_DWork.sf_StateTransitionTable_o);

    // SystemInitialize for State Transition Table: '<S36>/State Transition Table' 
    Contr_StateTransitionTable_Init(&Controller_DWork.sf_StateTransitionTable_o2);

    // End of SystemInitialize for SubSystem: '<Root>/Telegraph'

    // SystemInitialize for Atomic SubSystem: '<Root>/cmd_vel'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S49>/Out1'
    Controller_B.In1_m = Controller_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/cmd_vel'

    // SystemInitialize for Atomic SubSystem: '<Root>/imu_data'
    // SystemInitialize for Enabled SubSystem: '<S11>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S74>/Out1'
    Controller_B.In1 = Controller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S11>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/imu_data'

    // SystemInitialize for Enabled SubSystem: '<Root>/Xbox_input'
    // SystemInitialize for Outport: '<S7>/<angular_vel X>'
    Controller_B.X_hw = Controller_P.angular_velX_Y0_o;

    // SystemInitialize for Outport: '<S7>/<angular_vel Y>'
    Controller_B.Y_in = Controller_P.angular_velY_Y0_j;

    // SystemInitialize for Outport: '<S7>/<angular_vel Z> '
    Controller_B.Z_n = Controller_P.angular_velZ_Y0_g;

    // SystemInitialize for Outport: '<S7>/<velocity X>'
    Controller_B.X_h = Controller_P.velocityX_Y0_f;

    // SystemInitialize for Outport: '<S7>/<veloctiy Y>'
    Controller_B.Y_i = Controller_P.veloctiyY_Y0_a;

    // SystemInitialize for Outport: '<S7>/<velocity Z>'
    Controller_B.Z = Controller_P.velocityZ_Y0_l;

    // End of SystemInitialize for SubSystem: '<Root>/Xbox_input'

    // SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S4>/<angular_vel X>'
    Controller_B.Product = Controller_P.angular_velX_Y0;

    // SystemInitialize for Outport: '<S4>/<angular_vel Y>'
    Controller_B.Product1 = Controller_P.angular_velY_Y0;

    // SystemInitialize for Outport: '<S4>/<angular_vel Z> '
    Controller_B.Product2 = Controller_P.angular_velZ_Y0;

    // SystemInitialize for Outport: '<S4>/<velocity X>'
    Controller_B.Product3 = Controller_P.velocityX_Y0;

    // SystemInitialize for Outport: '<S4>/<veloctiy Y>'
    Controller_B.Product4 = Controller_P.veloctiyY_Y0;

    // SystemInitialize for Outport: '<S4>/<velocity Z>'
    Controller_B.Product5 = Controller_P.velocityZ_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/states'
    // SystemInitialize for Outport: '<S12>/<yaw [radians]>'
    Controller_B.Data[2] = Controller_P.yawradians_Y0;

    // SystemInitialize for Outport: '<S12>/<pitch [radians]>'
    Controller_B.OutportBufferForpitchradians = Controller_P.pitchradians_Y0;

    // SystemInitialize for Outport: '<S12>/<roll [radians]>'
    Controller_B.OutportBufferForrollradians = Controller_P.rollradians_Y0;

    // SystemInitialize for Outport: '<S12>/<angular_vel X [radians//s]>'
    Controller_B.X = Controller_P.angular_velXradianss_Y0;

    // SystemInitialize for Outport: '<S12>/<angular_vel Y [radians//s]>'
    Controller_B.Y = Controller_P.angular_velYradianss_Y0;

    // SystemInitialize for Outport: '<S12>/<angular_vel Z [radians//s]>'
    Controller_B.OutportBufferForangular_velZrad =
      Controller_P.angular_velZradianss_Y0;

    // SystemInitialize for Outport: '<S12>/<acc X [m//s^2]>'
    Controller_B.OutportBufferForaccXms2 = Controller_P.accXms2_Y0;

    // SystemInitialize for Outport: '<S12>/<acc Y [m//s^2]>'
    Controller_B.OutportBufferForaccYms2 = Controller_P.accYms2_Y0;

    // SystemInitialize for Outport: '<S12>/<acc Z [m//s^2]>'
    Controller_B.OutportBufferForaccZms2 = Controller_P.accZms2_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/states'

    // SystemInitialize for Enabled SubSystem: '<Root>/Create errors'
    // SystemInitialize for Outport: '<S2>/yaw error [radians]'
    Controller_B.Errorx1 = Controller_P.yawerrorradians_Y0;

    // SystemInitialize for Outport: '<S2>/pitch error [radians]'
    Controller_B.Errory1 = Controller_P.pitcherrorradians_Y0;

    // SystemInitialize for Outport: '<S2>/roll error [radians]'
    Controller_B.Errorz4 = Controller_P.rollerrorradians_Y0;

    // SystemInitialize for Outport: '<S2>/angular_vel x error [radians]'
    Controller_B.Errorx = Controller_P.angular_velxerrorradians_Y0;

    // SystemInitialize for Outport: '<S2>/angular_vel y error [radians]'
    Controller_B.Errory = Controller_P.angular_velyerrorradians_Y0;

    // SystemInitialize for Outport: '<S2>/angular_vel z error [radians]'
    Controller_B.Errorz = Controller_P.angular_velzerrorradians_Y0;

    // SystemInitialize for Outport: '<S2>/vel x error [m//s]'
    Controller_B.Errorz8 = Controller_P.velxerrorms_Y0;

    // SystemInitialize for Outport: '<S2>/vel y error [m//s]'
    Controller_B.Errorz9 = Controller_P.velyerrorms_Y0;

    // SystemInitialize for Outport: '<S2>/vel z error [m//s]'
    Controller_B.Errorz10 = Controller_P.velzerrorms_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/Create errors'

    // SystemInitialize for Enabled SubSystem: '<Root>/decController'
    // InitializeConditions for DiscreteIntegrator: '<S56>/Integrator'
    Controller_DWork.Integrator_DSTATE = Controller_P.Integrator_IC_i;

    // InitializeConditions for DiscreteIntegrator: '<S56>/Filter'
    Controller_DWork.Filter_DSTATE = Controller_P.Filter_IC_h;

    // InitializeConditions for DiscreteIntegrator: '<S59>/Integrator'
    Controller_DWork.Integrator_DSTATE_h = Controller_P.Integrator_IC_o;

    // InitializeConditions for DiscreteIntegrator: '<S59>/Filter'
    Controller_DWork.Filter_DSTATE_c = Controller_P.Filter_IC_n;

    // InitializeConditions for DiscreteIntegrator: '<S62>/Integrator'
    Controller_DWork.Integrator_DSTATE_a = Controller_P.Integrator_IC_d;

    // InitializeConditions for DiscreteIntegrator: '<S62>/Filter'
    Controller_DWork.Filter_DSTATE_f = Controller_P.Filter_IC_c;

    // InitializeConditions for DiscreteIntegrator: '<S65>/Integrator'
    Controller_DWork.Integrator_DSTATE_f = Controller_P.Integrator_IC_el;

    // InitializeConditions for DiscreteIntegrator: '<S65>/Filter'
    Controller_DWork.Filter_DSTATE_a = Controller_P.Filter_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S68>/Integrator'
    Controller_DWork.Integrator_DSTATE_n = Controller_P.Integrator_IC_ig;

    // InitializeConditions for DiscreteIntegrator: '<S68>/Filter'
    Controller_DWork.Filter_DSTATE_g = Controller_P.Filter_IC_jx;

    // InitializeConditions for DiscreteIntegrator: '<S71>/Integrator'
    Controller_DWork.Integrator_DSTATE_ny = Controller_P.Integrator_IC_m;

    // InitializeConditions for DiscreteIntegrator: '<S71>/Filter'
    Controller_DWork.Filter_DSTATE_cw = Controller_P.Filter_IC_p;

    // SystemInitialize for Outport: '<S10>/velocites [linear xyz, angular xyz]' 
    Controller_B.Saturate_b = Controller_P.velociteslinearxyzangularxyz_Y0;
    Controller_B.Saturate_h = Controller_P.velociteslinearxyzangularxyz_Y0;
    Controller_B.Saturate_bk = Controller_P.velociteslinearxyzangularxyz_Y0;
    Controller_B.Saturate = Controller_P.velociteslinearxyzangularxyz_Y0;
    Controller_B.Saturate_f = Controller_P.velociteslinearxyzangularxyz_Y0;
    Controller_B.Saturate_i = Controller_P.velociteslinearxyzangularxyz_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/decController'

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem'
    // InitializeConditions for DiscreteIntegrator: '<S25>/Integrator'
    Controller_DWork.Integrator_DSTATE_nm = Controller_P.Integrator_IC;

    // InitializeConditions for DiscreteIntegrator: '<S25>/Filter'
    Controller_DWork.Filter_DSTATE_gs = Controller_P.Filter_IC;

    // InitializeConditions for DiscreteIntegrator: '<S22>/Integrator'
    Controller_DWork.Integrator_DSTATE_c = Controller_P.Integrator_IC_n;

    // InitializeConditions for DiscreteIntegrator: '<S22>/Filter'
    Controller_DWork.Filter_DSTATE_fb = Controller_P.Filter_IC_a;

    // InitializeConditions for DiscreteIntegrator: '<S28>/Integrator'
    Controller_DWork.Integrator_DSTATE_ch = Controller_P.Integrator_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S28>/Filter'
    Controller_DWork.Filter_DSTATE_l = Controller_P.Filter_IC_e;

    // SystemInitialize for Enabled SubSystem: '<Root>/Telegraph'
    for (i = 0; i < 6; i++) {
      // SystemInitialize for Outport: '<S6>/Thrusters'
      Controller_B.OutportBufferForThrusters[i] = Controller_P.Thrusters_Y0;

      // SystemInitialize for Outport: '<S5>/Out2'
      Controller_B.OutportBufferForOut2[i] = Controller_P.Out2_Y0;
    }

    // End of SystemInitialize for SubSystem: '<Root>/Telegraph'
    // End of SystemInitialize for SubSystem: '<Root>/Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/Enable thrusters'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S17>/Out1'
    Controller_B.In1_b = Controller_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Enable thrusters'
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
  // Start for MATLABSystem: '<S6>/Get Parameter' incorporates:
  //   Terminate for MATLABSystem: '<S6>/Get Parameter'

  if (Controller_DWork.obj_fg.isInitialized == 1) {
    Controller_DWork.obj_fg.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/Get Parameter'

  // Start for MATLABSystem: '<S31>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S31>/Swtiching factor'

  if (Controller_DWork.obj_of.isInitialized == 1) {
    Controller_DWork.obj_of.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S31>/Swtiching factor'

  // Start for MATLABSystem: '<S31>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S31>/Swtiching factor1'

  if (Controller_DWork.obj_fx.isInitialized == 1) {
    Controller_DWork.obj_fx.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S31>/Swtiching factor1'

  // Start for MATLABSystem: '<S31>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S31>/Swtiching factor2'

  if (Controller_DWork.obj_d3.isInitialized == 1) {
    Controller_DWork.obj_d3.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S31>/Swtiching factor2'

  // Start for MATLABSystem: '<S32>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S32>/Swtiching factor'

  if (Controller_DWork.obj_i.isInitialized == 1) {
    Controller_DWork.obj_i.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S32>/Swtiching factor'

  // Start for MATLABSystem: '<S32>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S32>/Swtiching factor1'

  if (Controller_DWork.obj_j5.isInitialized == 1) {
    Controller_DWork.obj_j5.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S32>/Swtiching factor1'

  // Start for MATLABSystem: '<S32>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S32>/Swtiching factor2'

  if (Controller_DWork.obj_fu.isInitialized == 1) {
    Controller_DWork.obj_fu.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S32>/Swtiching factor2'

  // Start for MATLABSystem: '<S33>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S33>/Swtiching factor'

  if (Controller_DWork.obj_o.isInitialized == 1) {
    Controller_DWork.obj_o.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S33>/Swtiching factor'

  // Start for MATLABSystem: '<S33>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S33>/Swtiching factor1'

  if (Controller_DWork.obj_f.isInitialized == 1) {
    Controller_DWork.obj_f.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S33>/Swtiching factor1'

  // Start for MATLABSystem: '<S33>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S33>/Swtiching factor2'

  if (Controller_DWork.obj_mb.isInitialized == 1) {
    Controller_DWork.obj_mb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S33>/Swtiching factor2'

  // Start for MATLABSystem: '<S34>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S34>/Swtiching factor'

  if (Controller_DWork.obj_gv.isInitialized == 1) {
    Controller_DWork.obj_gv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S34>/Swtiching factor'

  // Start for MATLABSystem: '<S34>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S34>/Swtiching factor1'

  if (Controller_DWork.obj_c2.isInitialized == 1) {
    Controller_DWork.obj_c2.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S34>/Swtiching factor1'

  // Start for MATLABSystem: '<S34>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S34>/Swtiching factor2'

  if (Controller_DWork.obj_g0e.isInitialized == 1) {
    Controller_DWork.obj_g0e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S34>/Swtiching factor2'

  // Start for MATLABSystem: '<S35>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S35>/Swtiching factor'

  if (Controller_DWork.obj_j0.isInitialized == 1) {
    Controller_DWork.obj_j0.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S35>/Swtiching factor'

  // Start for MATLABSystem: '<S35>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S35>/Swtiching factor1'

  if (Controller_DWork.obj_hr.isInitialized == 1) {
    Controller_DWork.obj_hr.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S35>/Swtiching factor1'

  // Start for MATLABSystem: '<S35>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S35>/Swtiching factor2'

  if (Controller_DWork.obj_dn.isInitialized == 1) {
    Controller_DWork.obj_dn.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S35>/Swtiching factor2'

  // Start for MATLABSystem: '<S36>/Swtiching factor' incorporates:
  //   Terminate for MATLABSystem: '<S36>/Swtiching factor'

  if (Controller_DWork.obj_gf.isInitialized == 1) {
    Controller_DWork.obj_gf.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S36>/Swtiching factor'

  // Start for MATLABSystem: '<S36>/Swtiching factor1' incorporates:
  //   Terminate for MATLABSystem: '<S36>/Swtiching factor1'

  if (Controller_DWork.obj_cvy.isInitialized == 1) {
    Controller_DWork.obj_cvy.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S36>/Swtiching factor1'

  // Start for MATLABSystem: '<S36>/Swtiching factor2' incorporates:
  //   Terminate for MATLABSystem: '<S36>/Swtiching factor2'

  if (Controller_DWork.obj_dt.isInitialized == 1) {
    Controller_DWork.obj_dt.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S36>/Swtiching factor2'
  // End of Terminate for SubSystem: '<Root>/Telegraph'

  // Start for MATLABSystem: '<Root>/Get controller type' incorporates:
  //   Terminate for MATLABSystem: '<Root>/Get controller type'

  if (Controller_DWork.obj_nl.isInitialized == 1) {
    Controller_DWork.obj_nl.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/Get controller type'

  // Terminate for Atomic SubSystem: '<Root>/cmd_vel'
  // Start for MATLABSystem: '<S9>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S9>/SourceBlock'

  if (Controller_DWork.obj_nf.isInitialized == 1) {
    Controller_DWork.obj_nf.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/cmd_vel'

  // Terminate for Atomic SubSystem: '<Root>/imu_data'
  // Start for MATLABSystem: '<S11>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S11>/SourceBlock'

  if (Controller_DWork.obj_ki.isInitialized == 1) {
    Controller_DWork.obj_ki.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S11>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/imu_data'

  // Start for MATLABSystem: '<Root>/yaw_ref' incorporates:
  //   Terminate for MATLABSystem: '<Root>/yaw_ref'

  if (Controller_DWork.obj_o5.isInitialized == 1) {
    Controller_DWork.obj_o5.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/yaw_ref'

  // Start for MATLABSystem: '<Root>/pitch_ref' incorporates:
  //   Terminate for MATLABSystem: '<Root>/pitch_ref'

  if (Controller_DWork.obj_mbl.isInitialized == 1) {
    Controller_DWork.obj_mbl.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/pitch_ref'

  // Start for MATLABSystem: '<Root>/roll_ref' incorporates:
  //   Terminate for MATLABSystem: '<Root>/roll_ref'

  if (Controller_DWork.obj_pk.isInitialized == 1) {
    Controller_DWork.obj_pk.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/roll_ref'

  // Terminate for Enabled SubSystem: '<Root>/Enabled Subsystem'
  // Start for MATLABSystem: '<S4>/Get Parameter' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get Parameter'

  if (Controller_DWork.obj_km.isInitialized == 1) {
    Controller_DWork.obj_km.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get Parameter'

  // Start for MATLABSystem: '<S4>/Get Parameter1' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get Parameter1'

  if (Controller_DWork.obj_oz.isInitialized == 1) {
    Controller_DWork.obj_oz.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get Parameter1'

  // Start for MATLABSystem: '<S4>/Get Parameter2' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get Parameter2'

  if (Controller_DWork.obj_iv.isInitialized == 1) {
    Controller_DWork.obj_iv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get Parameter2'

  // Start for MATLABSystem: '<S4>/Get Parameter3' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get Parameter3'

  if (Controller_DWork.obj_dy.isInitialized == 1) {
    Controller_DWork.obj_dy.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get Parameter3'

  // Start for MATLABSystem: '<S4>/Get Parameter4' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get Parameter4'

  if (Controller_DWork.obj_kg.isInitialized == 1) {
    Controller_DWork.obj_kg.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get Parameter4'

  // Start for MATLABSystem: '<S4>/Get Parameter5' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get Parameter5'

  if (Controller_DWork.obj_ku.isInitialized == 1) {
    Controller_DWork.obj_ku.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get Parameter5'
  // End of Terminate for SubSystem: '<Root>/Enabled Subsystem'

  // Start for MATLABSystem: '<S8>/Enable integration?' incorporates:
  //   Terminate for MATLABSystem: '<S8>/Enable integration?'

  if (Controller_DWork.obj_g0.isInitialized == 1) {
    Controller_DWork.obj_g0.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/Enable integration?'

  // Terminate for Enabled SubSystem: '<Root>/decController'
  // Start for MATLABSystem: '<S57>/P_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S57>/P_angular_vel_x'

  if (Controller_DWork.obj_bm.isInitialized == 1) {
    Controller_DWork.obj_bm.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S57>/P_angular_vel_x'

  // Start for MATLABSystem: '<S57>/D_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S57>/D_angular_vel_x'

  if (Controller_DWork.obj_be.isInitialized == 1) {
    Controller_DWork.obj_be.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S57>/D_angular_vel_x'

  // Start for MATLABSystem: '<S57>/N_angular_vel_x ' incorporates:
  //   Terminate for MATLABSystem: '<S57>/N_angular_vel_x '

  if (Controller_DWork.obj_lb.isInitialized == 1) {
    Controller_DWork.obj_lb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S57>/N_angular_vel_x '

  // Start for MATLABSystem: '<S57>/I_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S57>/I_angular_vel_x'

  if (Controller_DWork.obj_pb.isInitialized == 1) {
    Controller_DWork.obj_pb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S57>/I_angular_vel_x'

  // Start for MATLABSystem: '<S60>/P_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S60>/P_angular_vel_y'

  if (Controller_DWork.obj_b.isInitialized == 1) {
    Controller_DWork.obj_b.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S60>/P_angular_vel_y'

  // Start for MATLABSystem: '<S60>/D_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S60>/D_angular_vel_y'

  if (Controller_DWork.obj_m.isInitialized == 1) {
    Controller_DWork.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S60>/D_angular_vel_y'

  // Start for MATLABSystem: '<S60>/N_angular_vel_y ' incorporates:
  //   Terminate for MATLABSystem: '<S60>/N_angular_vel_y '

  if (Controller_DWork.obj_dp.isInitialized == 1) {
    Controller_DWork.obj_dp.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S60>/N_angular_vel_y '

  // Start for MATLABSystem: '<S60>/I_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S60>/I_angular_vel_y'

  if (Controller_DWork.obj_ep.isInitialized == 1) {
    Controller_DWork.obj_ep.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S60>/I_angular_vel_y'

  // Start for MATLABSystem: '<S63>/P_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S63>/P_angular_vel_z'

  if (Controller_DWork.obj_e.isInitialized == 1) {
    Controller_DWork.obj_e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S63>/P_angular_vel_z'

  // Start for MATLABSystem: '<S63>/D_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S63>/D_angular_vel_z'

  if (Controller_DWork.obj_jg.isInitialized == 1) {
    Controller_DWork.obj_jg.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S63>/D_angular_vel_z'

  // Start for MATLABSystem: '<S63>/N_angular_vel_z ' incorporates:
  //   Terminate for MATLABSystem: '<S63>/N_angular_vel_z '

  if (Controller_DWork.obj_g.isInitialized == 1) {
    Controller_DWork.obj_g.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S63>/N_angular_vel_z '

  // Start for MATLABSystem: '<S63>/I_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S63>/I_angular_vel_z'

  if (Controller_DWork.obj_p.isInitialized == 1) {
    Controller_DWork.obj_p.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S63>/I_angular_vel_z'

  // Start for MATLABSystem: '<S66>/P_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S66>/P_vel_x'

  if (Controller_DWork.obj_ns.isInitialized == 1) {
    Controller_DWork.obj_ns.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S66>/P_vel_x'

  // Start for MATLABSystem: '<S66>/D_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S66>/D_vel_x'

  if (Controller_DWork.obj_d.isInitialized == 1) {
    Controller_DWork.obj_d.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S66>/D_vel_x'

  // Start for MATLABSystem: '<S66>/N_vel_x ' incorporates:
  //   Terminate for MATLABSystem: '<S66>/N_vel_x '

  if (Controller_DWork.obj_a3.isInitialized == 1) {
    Controller_DWork.obj_a3.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S66>/N_vel_x '

  // Start for MATLABSystem: '<S66>/I_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S66>/I_vel_x'

  if (Controller_DWork.obj_cv.isInitialized == 1) {
    Controller_DWork.obj_cv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S66>/I_vel_x'

  // Start for MATLABSystem: '<S69>/P_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S69>/P_vel_y'

  if (Controller_DWork.obj_ji.isInitialized == 1) {
    Controller_DWork.obj_ji.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S69>/P_vel_y'

  // Start for MATLABSystem: '<S69>/D_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S69>/D_vel_y'

  if (Controller_DWork.obj_ny.isInitialized == 1) {
    Controller_DWork.obj_ny.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S69>/D_vel_y'

  // Start for MATLABSystem: '<S69>/N_vel_y ' incorporates:
  //   Terminate for MATLABSystem: '<S69>/N_vel_y '

  if (Controller_DWork.obj_cb.isInitialized == 1) {
    Controller_DWork.obj_cb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S69>/N_vel_y '

  // Start for MATLABSystem: '<S69>/I_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S69>/I_vel_y'

  if (Controller_DWork.obj_jx.isInitialized == 1) {
    Controller_DWork.obj_jx.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S69>/I_vel_y'

  // Start for MATLABSystem: '<S72>/P_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S72>/P_vel_z'

  if (Controller_DWork.obj_j.isInitialized == 1) {
    Controller_DWork.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S72>/P_vel_z'

  // Start for MATLABSystem: '<S72>/D_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S72>/D_vel_z'

  if (Controller_DWork.obj_a.isInitialized == 1) {
    Controller_DWork.obj_a.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S72>/D_vel_z'

  // Start for MATLABSystem: '<S72>/N_vel_z ' incorporates:
  //   Terminate for MATLABSystem: '<S72>/N_vel_z '

  if (Controller_DWork.obj_h.isInitialized == 1) {
    Controller_DWork.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S72>/N_vel_z '

  // Start for MATLABSystem: '<S72>/I_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S72>/I_vel_z'

  if (Controller_DWork.obj_js.isInitialized == 1) {
    Controller_DWork.obj_js.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S72>/I_vel_z'
  // End of Terminate for SubSystem: '<Root>/decController'

  // Terminate for Enabled SubSystem: '<Root>/Subsystem'
  // Start for MATLABSystem: '<S26>/P_roll' incorporates:
  //   Terminate for MATLABSystem: '<S26>/P_roll'

  if (Controller_DWork.obj_jp.isInitialized == 1) {
    Controller_DWork.obj_jp.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S26>/P_roll'

  // Start for MATLABSystem: '<S26>/D_roll' incorporates:
  //   Terminate for MATLABSystem: '<S26>/D_roll'

  if (Controller_DWork.obj_k.isInitialized == 1) {
    Controller_DWork.obj_k.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S26>/D_roll'

  // Start for MATLABSystem: '<S26>/N_roll ' incorporates:
  //   Terminate for MATLABSystem: '<S26>/N_roll '

  if (Controller_DWork.obj_dp3.isInitialized == 1) {
    Controller_DWork.obj_dp3.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S26>/N_roll '

  // Start for MATLABSystem: '<S23>/P_pitch' incorporates:
  //   Terminate for MATLABSystem: '<S23>/P_pitch'

  if (Controller_DWork.obj_m1.isInitialized == 1) {
    Controller_DWork.obj_m1.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S23>/P_pitch'

  // Start for MATLABSystem: '<S23>/D_pitch' incorporates:
  //   Terminate for MATLABSystem: '<S23>/D_pitch'

  if (Controller_DWork.obj_b4.isInitialized == 1) {
    Controller_DWork.obj_b4.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S23>/D_pitch'

  // Start for MATLABSystem: '<S23>/N_pitch ' incorporates:
  //   Terminate for MATLABSystem: '<S23>/N_pitch '

  if (Controller_DWork.obj_fq.isInitialized == 1) {
    Controller_DWork.obj_fq.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S23>/N_pitch '

  // Start for MATLABSystem: '<S29>/P_yaw' incorporates:
  //   Terminate for MATLABSystem: '<S29>/P_yaw'

  if (Controller_DWork.obj_hn.isInitialized == 1) {
    Controller_DWork.obj_hn.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S29>/P_yaw'

  // Start for MATLABSystem: '<S29>/D_yaw' incorporates:
  //   Terminate for MATLABSystem: '<S29>/D_yaw'

  if (Controller_DWork.obj_ha.isInitialized == 1) {
    Controller_DWork.obj_ha.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S29>/D_yaw'

  // Start for MATLABSystem: '<S29>/N_yaw ' incorporates:
  //   Terminate for MATLABSystem: '<S29>/N_yaw '

  if (Controller_DWork.obj_py.isInitialized == 1) {
    Controller_DWork.obj_py.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S29>/N_yaw '

  // Start for MATLABSystem: '<S23>/I_pitch' incorporates:
  //   Terminate for MATLABSystem: '<S23>/I_pitch'

  if (Controller_DWork.obj_jb.isInitialized == 1) {
    Controller_DWork.obj_jb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S23>/I_pitch'

  // Start for MATLABSystem: '<S26>/I_roll' incorporates:
  //   Terminate for MATLABSystem: '<S26>/I_roll'

  if (Controller_DWork.obj_c1.isInitialized == 1) {
    Controller_DWork.obj_c1.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S26>/I_roll'

  // Start for MATLABSystem: '<S29>/I_yaw' incorporates:
  //   Terminate for MATLABSystem: '<S29>/I_yaw'

  if (Controller_DWork.obj_om.isInitialized == 1) {
    Controller_DWork.obj_om.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S29>/I_yaw'
  // End of Terminate for SubSystem: '<Root>/Subsystem'

  // Terminate for Atomic SubSystem: '<Root>/Enable thrusters'
  // Start for MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SourceBlock'

  if (Controller_DWork.obj_mv.isInitialized == 1) {
    Controller_DWork.obj_mv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Enable thrusters'

  // Terminate for Enabled SubSystem: '<Root>/toPWM'
  // Start for MATLABSystem: '<S78>/Get Parameter' incorporates:
  //   Terminate for MATLABSystem: '<S78>/Get Parameter'

  if (Controller_DWork.obj.isInitialized == 1) {
    Controller_DWork.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S78>/Get Parameter'

  // Start for MATLABSystem: '<S78>/Get Parameter1' incorporates:
  //   Terminate for MATLABSystem: '<S78>/Get Parameter1'

  if (Controller_DWork.obj_l.isInitialized == 1) {
    Controller_DWork.obj_l.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S78>/Get Parameter1'

  // Start for MATLABSystem: '<S78>/Get Parameter2' incorporates:
  //   Terminate for MATLABSystem: '<S78>/Get Parameter2'

  if (Controller_DWork.obj_n.isInitialized == 1) {
    Controller_DWork.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S78>/Get Parameter2'

  // Start for MATLABSystem: '<S78>/Get Parameter3' incorporates:
  //   Terminate for MATLABSystem: '<S78>/Get Parameter3'

  if (Controller_DWork.obj_c.isInitialized == 1) {
    Controller_DWork.obj_c.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S78>/Get Parameter3'

  // Start for MATLABSystem: '<S78>/Get Parameter4' incorporates:
  //   Terminate for MATLABSystem: '<S78>/Get Parameter4'

  if (Controller_DWork.obj_nt.isInitialized == 1) {
    Controller_DWork.obj_nt.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S78>/Get Parameter4'

  // Start for MATLABSystem: '<S78>/Get Parameter5' incorporates:
  //   Terminate for MATLABSystem: '<S78>/Get Parameter5'

  if (Controller_DWork.obj_ls.isInitialized == 1) {
    Controller_DWork.obj_ls.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S78>/Get Parameter5'

  // Terminate for Atomic SubSystem: '<S16>/Publish'
  // Start for MATLABSystem: '<S80>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S80>/SinkBlock'

  if (Controller_DWork.obj_pw.isInitialized == 1) {
    Controller_DWork.obj_pw.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S80>/SinkBlock'
  // End of Terminate for SubSystem: '<S16>/Publish'
  // End of Terminate for SubSystem: '<Root>/toPWM'

  // Start for MATLABSystem: '<S8>/Get alpha' incorporates:
  //   Terminate for MATLABSystem: '<S8>/Get alpha'

  if (Controller_DWork.obj_hx.isInitialized == 1) {
    Controller_DWork.obj_hx.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/Get alpha'
}

// Constructor
ControllerModelClass::ControllerModelClass()
{
  static const Parameters_Controller_T Controller_P_temp = {
    1.0,                               // Mask Parameter: PIDController_Kt
                                       //  Referenced by: '<S22>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_d
                                       //  Referenced by: '<S25>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_j
                                       //  Referenced by: '<S28>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_l
                                       //  Referenced by: '<S56>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_jo
                                       //  Referenced by: '<S59>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_p
                                       //  Referenced by: '<S62>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_jw
                                       //  Referenced by: '<S65>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_c
                                       //  Referenced by: '<S68>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_li
                                       //  Referenced by: '<S71>/Kt'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturationLi
                                       //  Referenced by:
                                       //    '<S25>/Saturate'
                                       //    '<S27>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_n
                                       //  Referenced by:
                                       //    '<S22>/Saturate'
                                       //    '<S24>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_e
                                       //  Referenced by:
                                       //    '<S28>/Saturate'
                                       //    '<S30>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_l
                                       //  Referenced by:
                                       //    '<S56>/Saturate'
                                       //    '<S58>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturatio_ek
                                       //  Referenced by:
                                       //    '<S59>/Saturate'
                                       //    '<S61>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_p
                                       //  Referenced by:
                                       //    '<S62>/Saturate'
                                       //    '<S64>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_i
                                       //  Referenced by:
                                       //    '<S65>/Saturate'
                                       //    '<S67>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_g
                                       //  Referenced by:
                                       //    '<S68>/Saturate'
                                       //    '<S70>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturatio_pm
                                       //  Referenced by:
                                       //    '<S71>/Saturate'
                                       //    '<S73>/DeadZone'

    100.0,                             // Mask Parameter: RandomSource_MaxVal
                                       //  Referenced by: '<S31>/Random Source'

    100.0,                             // Mask Parameter: RandomSource_MaxVal_o
                                       //  Referenced by: '<S32>/Random Source'

    100.0,                             // Mask Parameter: RandomSource_MaxVal_g
                                       //  Referenced by: '<S33>/Random Source'

    100.0,                             // Mask Parameter: RandomSource_MaxVal_d
                                       //  Referenced by: '<S34>/Random Source'

    100.0,                             // Mask Parameter: RandomSource_MaxVal_n
                                       //  Referenced by: '<S35>/Random Source'

    100.0,                             // Mask Parameter: RandomSource_MaxVal_i
                                       //  Referenced by: '<S36>/Random Source'

    1.0,                               // Mask Parameter: RandomSource_MinVal
                                       //  Referenced by: '<S31>/Random Source'

    1.0,                               // Mask Parameter: RandomSource_MinVal_h
                                       //  Referenced by: '<S32>/Random Source'

    1.0,                               // Mask Parameter: RandomSource_MinVal_b
                                       //  Referenced by: '<S33>/Random Source'

    1.0,                               // Mask Parameter: RandomSource_MinVal_d
                                       //  Referenced by: '<S34>/Random Source'

    1.0,                               // Mask Parameter: RandomSource_MinVal_n
                                       //  Referenced by: '<S35>/Random Source'

    1.0,                               // Mask Parameter: RandomSource_MinVal_i
                                       //  Referenced by: '<S36>/Random Source'

    1.0,                               // Mask Parameter: PIDController_UpperSaturationLi
                                       //  Referenced by:
                                       //    '<S25>/Saturate'
                                       //    '<S27>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_n
                                       //  Referenced by:
                                       //    '<S22>/Saturate'
                                       //    '<S24>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_j
                                       //  Referenced by:
                                       //    '<S28>/Saturate'
                                       //    '<S30>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_b
                                       //  Referenced by:
                                       //    '<S56>/Saturate'
                                       //    '<S58>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_o
                                       //  Referenced by:
                                       //    '<S59>/Saturate'
                                       //    '<S61>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_e
                                       //  Referenced by:
                                       //    '<S62>/Saturate'
                                       //    '<S64>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_d
                                       //  Referenced by:
                                       //    '<S65>/Saturate'
                                       //    '<S67>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturatio_bf
                                       //  Referenced by:
                                       //    '<S68>/Saturate'
                                       //    '<S70>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturatio_ba
                                       //  Referenced by:
                                       //    '<S71>/Saturate'
                                       //    '<S73>/DeadZone'

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
                                       //  Referenced by: '<S74>/Out1'


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
                                       //  Referenced by: '<S11>/Constant'


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
                                       //  Referenced by: '<S76>/Constant'


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
                                       //  Referenced by: '<S49>/Out1'


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
                                       //  Referenced by: '<S9>/Constant'


    //  Expression: zeros(6,1)
    //  Referenced by: '<Root>/no control'

    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<Root>/roll_ref'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<Root>/pitch_ref'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<Root>/yaw_ref'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<Root>/Get controller type'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<Root>/Get test'

    0.0,                               // Computed Parameter: yawerrorradians_Y0
                                       //  Referenced by: '<S2>/yaw error [radians]'

    0.0,                               // Computed Parameter: pitcherrorradians_Y0
                                       //  Referenced by: '<S2>/pitch error [radians]'

    0.0,                               // Computed Parameter: rollerrorradians_Y0
                                       //  Referenced by: '<S2>/roll error [radians]'

    0.0,                               // Computed Parameter: angular_velxerrorradians_Y0
                                       //  Referenced by: '<S2>/angular_vel x error [radians]'

    0.0,                               // Computed Parameter: angular_velyerrorradians_Y0
                                       //  Referenced by: '<S2>/angular_vel y error [radians]'

    0.0,                               // Computed Parameter: angular_velzerrorradians_Y0
                                       //  Referenced by: '<S2>/angular_vel z error [radians]'

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
                                       //  Referenced by: '<S4>/Get Parameter5'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get Parameter4'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get Parameter3'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get Parameter2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get Parameter1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get Parameter'

    0.0,                               // Computed Parameter: angular_velX_Y0
                                       //  Referenced by: '<S4>/<angular_vel X>'

    0.0,                               // Computed Parameter: angular_velY_Y0
                                       //  Referenced by: '<S4>/<angular_vel Y>'

    0.0,                               // Computed Parameter: angular_velZ_Y0
                                       //  Referenced by: '<S4>/<angular_vel Z> '

    0.0,                               // Computed Parameter: velocityX_Y0
                                       //  Referenced by: '<S4>/<velocity X>'

    0.0,                               // Computed Parameter: veloctiyY_Y0
                                       //  Referenced by: '<S4>/<veloctiy Y>'

    0.0,                               // Computed Parameter: velocityZ_Y0
                                       //  Referenced by: '<S4>/<velocity Z>'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S23>/I_pitch'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S23>/N_pitch '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S23>/D_pitch'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S23>/P_pitch'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S26>/I_roll'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S26>/N_roll '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S26>/D_roll'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S26>/P_roll'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S29>/I_yaw'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S29>/N_yaw '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S29>/D_yaw'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S29>/P_yaw'

    0.0,                               // Computed Parameter: Out2_Y0
                                       //  Referenced by: '<S5>/Out2'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S5>/Constant'

    0.01,                              // Computed Parameter: Integrator_gainval
                                       //  Referenced by: '<S25>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S25>/Integrator'

    0.01,                              // Computed Parameter: Filter_gainval
                                       //  Referenced by: '<S25>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S25>/Filter'

    0.01,                              // Computed Parameter: Integrator_gainval_b
                                       //  Referenced by: '<S22>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S22>/Integrator'

    0.01,                              // Computed Parameter: Filter_gainval_l
                                       //  Referenced by: '<S22>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S22>/Filter'

    0.01,                              // Computed Parameter: Integrator_gainval_l
                                       //  Referenced by: '<S28>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S28>/Integrator'

    0.01,                              // Computed Parameter: Filter_gainval_e
                                       //  Referenced by: '<S28>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S28>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S24>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S22>/Constant'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S27>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S25>/Constant'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S30>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S28>/Constant'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S6>/Get Parameter'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S31>/Swtiching factor2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S31>/Swtiching factor1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S31>/Swtiching factor'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S32>/Swtiching factor2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S32>/Swtiching factor1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S32>/Swtiching factor'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S33>/Swtiching factor2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S33>/Swtiching factor1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S33>/Swtiching factor'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S34>/Swtiching factor2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S34>/Swtiching factor1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S34>/Swtiching factor'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S35>/Swtiching factor2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S35>/Swtiching factor1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S35>/Swtiching factor'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S36>/Swtiching factor2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S36>/Swtiching factor1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S36>/Swtiching factor'

    0.0,                               // Computed Parameter: Thrusters_Y0
                                       //  Referenced by: '<S6>/Thrusters'

    100.0,                             // Expression: 100
                                       //  Referenced by: '<S31>/Constant'

    100.0,                             // Expression: 100
                                       //  Referenced by: '<S32>/Constant'

    100.0,                             // Expression: 100
                                       //  Referenced by: '<S33>/Constant'

    100.0,                             // Expression: 100
                                       //  Referenced by: '<S34>/Constant'

    100.0,                             // Expression: 100
                                       //  Referenced by: '<S35>/Constant'

    100.0,                             // Expression: 100
                                       //  Referenced by: '<S36>/Constant'

    0.0,                               // Computed Parameter: angular_velX_Y0_o
                                       //  Referenced by: '<S7>/<angular_vel X>'

    0.0,                               // Computed Parameter: angular_velY_Y0_j
                                       //  Referenced by: '<S7>/<angular_vel Y>'

    0.0,                               // Computed Parameter: angular_velZ_Y0_g
                                       //  Referenced by: '<S7>/<angular_vel Z> '

    0.0,                               // Computed Parameter: velocityX_Y0_f
                                       //  Referenced by: '<S7>/<velocity X>'

    0.0,                               // Computed Parameter: veloctiyY_Y0_a
                                       //  Referenced by: '<S7>/<veloctiy Y>'

    0.0,                               // Computed Parameter: velocityZ_Y0_l
                                       //  Referenced by: '<S7>/<velocity Z>'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S8>/Get alpha'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S8>/Enable integration?'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S57>/I_angular_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S57>/N_angular_vel_x '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S57>/D_angular_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S57>/P_angular_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S60>/I_angular_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S60>/N_angular_vel_y '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S60>/D_angular_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S60>/P_angular_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S63>/I_angular_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S63>/N_angular_vel_z '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S63>/D_angular_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S63>/P_angular_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S66>/I_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S66>/N_vel_x '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S66>/D_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S66>/P_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S69>/I_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S69>/N_vel_y '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S69>/D_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S69>/P_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S72>/I_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S72>/N_vel_z '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S72>/D_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S72>/P_vel_z'

    0.0,                               // Computed Parameter: velociteslinearxyzangularxyz_Y0
                                       //  Referenced by: '<S10>/velocites [linear xyz, angular xyz]'

    0.01,                              // Computed Parameter: Integrator_gainval_h
                                       //  Referenced by: '<S56>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S56>/Integrator'

    0.01,                              // Computed Parameter: Filter_gainval_n
                                       //  Referenced by: '<S56>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S56>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S58>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S56>/Constant'

    0.01,                              // Computed Parameter: Integrator_gainval_c
                                       //  Referenced by: '<S59>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S59>/Integrator'

    0.01,                              // Computed Parameter: Filter_gainval_i
                                       //  Referenced by: '<S59>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S59>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S61>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S59>/Constant'

    0.01,                              // Computed Parameter: Integrator_gainval_n
                                       //  Referenced by: '<S62>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S62>/Integrator'

    0.01,                              // Computed Parameter: Filter_gainval_k
                                       //  Referenced by: '<S62>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S62>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S64>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S62>/Constant'

    0.01,                              // Computed Parameter: Integrator_gainval_j
                                       //  Referenced by: '<S65>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S65>/Integrator'

    0.01,                              // Computed Parameter: Filter_gainval_h
                                       //  Referenced by: '<S65>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S65>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S67>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S65>/Constant'

    0.01,                              // Computed Parameter: Integrator_gainval_np
                                       //  Referenced by: '<S68>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S68>/Integrator'

    0.01,                              // Computed Parameter: Filter_gainval_h0
                                       //  Referenced by: '<S68>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S68>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S70>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S68>/Constant'

    0.01,                              // Computed Parameter: Integrator_gainval_m
                                       //  Referenced by: '<S71>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S71>/Integrator'

    0.01,                              // Computed Parameter: Filter_gainval_b
                                       //  Referenced by: '<S71>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S71>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S73>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S71>/Constant'

    0.0,                               // Computed Parameter: yawradians_Y0
                                       //  Referenced by: '<S12>/<yaw [radians]>'

    0.0,                               // Computed Parameter: pitchradians_Y0
                                       //  Referenced by: '<S12>/<pitch [radians]>'

    0.0,                               // Computed Parameter: rollradians_Y0
                                       //  Referenced by: '<S12>/<roll [radians]>'

    0.0,                               // Computed Parameter: angular_velXradianss_Y0
                                       //  Referenced by: '<S12>/<angular_vel X [radians//s]>'

    0.0,                               // Computed Parameter: angular_velYradianss_Y0
                                       //  Referenced by: '<S12>/<angular_vel Y [radians//s]>'

    0.0,                               // Computed Parameter: angular_velZradianss_Y0
                                       //  Referenced by: '<S12>/<angular_vel Z [radians//s]>'

    0.0,                               // Computed Parameter: Zm_Y0
                                       //  Referenced by: '<S12>/<Z [m]>'

    0.0,                               // Computed Parameter: accXms2_Y0
                                       //  Referenced by: '<S12>/<acc X [m//s^2]>'

    0.0,                               // Computed Parameter: accYms2_Y0
                                       //  Referenced by: '<S12>/<acc Y [m//s^2]>'

    0.0,                               // Computed Parameter: accZms2_Y0
                                       //  Referenced by: '<S12>/<acc Z [m//s^2]>'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S78>/Get Parameter5'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S78>/Get Parameter4'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S78>/Get Parameter3'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S78>/Get Parameter2'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S78>/Get Parameter1'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S78>/Get Parameter'

    1.0,                               // Expression: 1
                                       //  Referenced by: '<S16>/Saturation'

    -1.0,                              // Expression: -1
                                       //  Referenced by: '<S16>/Saturation'

    0.01,                              // Computed Parameter: DiscreteTimeIntegrator_gainval
                                       //  Referenced by: '<S8>/Discrete-Time Integrator'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S8>/Discrete-Time Integrator'

    0.01,                              // Computed Parameter: DiscreteTimeIntegrator1_gainval
                                       //  Referenced by: '<S8>/Discrete-Time Integrator1'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S8>/Discrete-Time Integrator1'

    0.01,                              // Computed Parameter: DiscreteTimeIntegrator2_gainval
                                       //  Referenced by: '<S8>/Discrete-Time Integrator2'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S8>/Discrete-Time Integrator2'

    1.0,                               // Expression: 1
                                       //  Referenced by: '<Root>/control 1'

    2.0,                               // Expression: 2
                                       //  Referenced by: '<Root>/2'

    1.0,                               // Expression: 1
                                       //  Referenced by: '<S8>/Constant'

    1.0,                               // Expression: [1]
                                       //  Referenced by: '<S8>/Discrete Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S8>/Discrete Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S8>/Discrete Filter'

    1.0,                               // Expression: [1]
                                       //  Referenced by: '<S8>/Discrete Filter1'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S8>/Discrete Filter1'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S8>/Discrete Filter1'

    1.0,                               // Expression: [1]
                                       //  Referenced by: '<S8>/Discrete Filter2'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S8>/Discrete Filter2'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S8>/Discrete Filter2'


    {
      false                            // Data
    },                                 // Computed Parameter: Out1_Y0_i
                                       //  Referenced by: '<S17>/Out1'


    {
      false                            // Data
    }                                  // Computed Parameter: Constant_Value_ba
                                       //  Referenced by: '<S3>/Constant'

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
