//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Controller_private.h
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
#ifndef RTW_HEADER_Controller_private_h_
#define RTW_HEADER_Controller_private_h_
#include "rtwtypes.h"
#include "Controller.h"

extern void RandSrcInitState_U_64(const uint32_T seed[], real_T state[], int32_T
  nChans);
extern void Controller_MATLABFunction(real_T rtu_u, real_T rtu_min_scale, real_T
  rtu_max_scale, rtB_MATLABFunction_Controller_T *localB);
extern void Contr_StateTransitionTable_Init(rtDW_StateTransitionTable_Con_T
  *localDW);
extern void Controller_StateTransitionTable(real_T rtu_x,
  rtB_StateTransitionTable_Cont_T *localB, rtDW_StateTransitionTable_Con_T
  *localDW);
extern void Controller_thrustalloc(real_T rtu_control_signals, real_T
  rtu_control_signals_n, real_T rtu_control_signals_a, real_T
  rtu_control_signals_o, real_T rtu_control_signals_k, real_T
  rtu_control_signals_f, rtB_thrustalloc_Controller_T *localB);

#endif                                 // RTW_HEADER_Controller_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
