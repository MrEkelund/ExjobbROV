//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Controller_without_ref_private.h
//
// Code generated for Simulink model 'Controller_without_ref'.
//
// Model version                  : 1.150
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Mon Mar  7 21:18:35 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Controller_without_ref_private_h_
#define RTW_HEADER_Controller_without_ref_private_h_
#include "rtwtypes.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern void RandSrcInitState_U_64(const uint32_T seed[], real_T state[], int32_T
  nChans);
extern void Controller_witho_MATLABFunction(real_T rtu_angular_x, real_T
  rtu_angular_y, real_T rtu_angular_z, real_T rtu_vel_x, real_T rtu_vel_y,
  real_T rtu_vel_z, real_T rtu_front_strafe_decouple, real_T
  rtu_front_forward_decouple, real_T rtu_front_pitch_bias, real_T
  rtu_front_vertical_bias, real_T rtu_buoyancy_control,
  rtB_MATLABFunction_Controller_T *localB);
extern void Controller_wit_MATLABFunction_a(real_T rtu_u, real_T rtu_min_scale,
  real_T rtu_max_scale, rtB_MATLABFunction_Controll_n_T *localB);
extern void Contr_StateTransitionTable_Init(rtDW_StateTransitionTable_Con_T
  *localDW);
extern void Controller_StateTransitionTable(real_T rtu_x,
  rtB_StateTransitionTable_Cont_T *localB, rtDW_StateTransitionTable_Con_T
  *localDW);

#endif                                 // RTW_HEADER_Controller_without_ref_private_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
