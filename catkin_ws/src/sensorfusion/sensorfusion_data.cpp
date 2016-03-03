//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: sensorfusion_data.cpp
//
// Code generated for Simulink model 'sensorfusion'.
//
// Model version                  : 1.288
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Thu Mar  3 10:30:28 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "sensorfusion.h"
#include "sensorfusion_private.h"

// Constant parameters (auto storage)
const ConstParam rtConstP = {
  // Expression: eye(4).*100
  //  Referenced by: '<S4>/Constant2'

  { 100.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0,
    0.0, 100.0 },

  // Expression: [1,0,0,0,0]'
  //  Referenced by: '<Root>/Initial States'

  { 1.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: eye(5).*100
  //  Referenced by: '<Root>/Initial P'

  { 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0 }
};

//
// File trailer for generated code.
//
// [EOF]
//
