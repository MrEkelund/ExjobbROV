//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: sensorfusion.cpp
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
#define MessageQueueLen                (1)
#define ParameterInitialValue          (0.0)
#define ParameterInitialValue_i        (false)

const SL_Bus_sensorfusion_std_msgs_Float64MultiArray
  sensorfusion_rtZSL_Bus_sensorfusion_std_msgs_Float64MultiArray = {
  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
  ,                                    // Data

  {
    0U,                                // CurrentLength
    0U                                 // ReceivedLength
  },                                   // Data_SL_Info

  {
    0U,                                // DataOffset

    {
      {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      } }
    ,                                  // Dim

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    }                                  // Dim_SL_Info
  }                                    // Layout
} ;                                    // SL_Bus_sensorfusion_std_msgs_Float64MultiArray ground 

// Function for MATLAB Function: '<S2>/MATLAB Function'
real_T sensorfusionModelClass::norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

// Function for MATLAB Function: '<S2>/MATLAB Function'
void sensorfusionModelClass::mrdivide(const real_T A[15], const real_T B[9],
  real_T y[15])
{
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real_T maxval;
  real_T a21;
  int32_T rtemp;
  memcpy(&rtB.b_A[0], &B[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(B[0]);
  a21 = fabs(B[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(B[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  rtB.b_A[r2] = B[r2] / B[r1];
  rtB.b_A[r3] /= rtB.b_A[r1];
  rtB.b_A[3 + r2] -= rtB.b_A[3 + r1] * rtB.b_A[r2];
  rtB.b_A[3 + r3] -= rtB.b_A[3 + r1] * rtB.b_A[r3];
  rtB.b_A[6 + r2] -= rtB.b_A[6 + r1] * rtB.b_A[r2];
  rtB.b_A[6 + r3] -= rtB.b_A[6 + r1] * rtB.b_A[r3];
  if (fabs(rtB.b_A[3 + r3]) > fabs(rtB.b_A[3 + r2])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  rtB.b_A[3 + r3] /= rtB.b_A[3 + r2];
  rtB.b_A[6 + r3] -= rtB.b_A[3 + r3] * rtB.b_A[6 + r2];
  for (rtemp = 0; rtemp < 5; rtemp++) {
    y[rtemp + 5 * r1] = A[rtemp] / rtB.b_A[r1];
    y[rtemp + 5 * r2] = A[5 + rtemp] - y[5 * r1 + rtemp] * rtB.b_A[3 + r1];
    y[rtemp + 5 * r3] = A[10 + rtemp] - y[5 * r1 + rtemp] * rtB.b_A[6 + r1];
    y[rtemp + 5 * r2] /= rtB.b_A[3 + r2];
    y[rtemp + 5 * r3] -= y[5 * r2 + rtemp] * rtB.b_A[6 + r2];
    y[rtemp + 5 * r3] /= rtB.b_A[6 + r3];
    y[rtemp + 5 * r2] -= y[5 * r3 + rtemp] * rtB.b_A[3 + r3];
    y[rtemp + 5 * r1] -= y[5 * r3 + rtemp] * rtB.b_A[r3];
    y[rtemp + 5 * r1] -= y[5 * r2 + rtemp] * rtB.b_A[r2];
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function'
real_T sensorfusionModelClass::norm_p(const real_T x[4])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[3]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2((real_T)u0_0, (real_T)u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Function for MATLAB Function: '<S3>/MATLAB Function'
void sensorfusionModelClass::atan2_o(const real_T y_data[], const int32_T
  y_sizes[2], const real_T x_data[], const int32_T x_sizes[2], real_T r_data[],
  int32_T r_sizes[2])
{
  int32_T k;
  r_sizes[0] = 1;
  if (y_sizes[1] <= x_sizes[1]) {
    r_sizes[1] = (int8_T)y_sizes[1];
  } else {
    r_sizes[1] = 0;
  }

  k = 1;
  while (k <= y_sizes[1]) {
    r_data[0] = rt_atan2d_snf(y_data[0], x_data[0]);
    k = 2;
  }
}

// Function for MATLAB Function: '<S3>/MATLAB Function'
void sensorfusionModelClass::power(const real_T a_data[], const int32_T a_sizes
  [2], real_T y_data[], int32_T y_sizes[2])
{
  int32_T k;
  y_sizes[0] = 1;
  y_sizes[1] = (int8_T)a_sizes[1];
  k = 1;
  while (k <= a_sizes[1]) {
    y_data[0] = a_data[0] * a_data[0];
    k = 2;
  }
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

// Function for MATLAB Function: '<S3>/MATLAB Function'
void sensorfusionModelClass::mod(const real_T x[3], real_T r[3])
{
  real_T b_r;
  b_r = x[0] / 6.2831853071795862;
  if (fabs(b_r - rt_roundd_snf(b_r)) <= 2.2204460492503131E-16 * fabs(b_r)) {
    b_r = 0.0;
  } else {
    b_r = (b_r - floor(b_r)) * 6.2831853071795862;
  }

  r[0] = b_r;
  b_r = x[1] / 6.2831853071795862;
  if (fabs(b_r - rt_roundd_snf(b_r)) <= 2.2204460492503131E-16 * fabs(b_r)) {
    b_r = 0.0;
  } else {
    b_r = (b_r - floor(b_r)) * 6.2831853071795862;
  }

  r[1] = b_r;
  b_r = x[2] / 6.2831853071795862;
  if (fabs(b_r - rt_roundd_snf(b_r)) <= 2.2204460492503131E-16 * fabs(b_r)) {
    b_r = 0.0;
  } else {
    b_r = (b_r - floor(b_r)) * 6.2831853071795862;
  }

  r[2] = b_r;
}

// Model step function
void sensorfusionModelClass::step()
{
  static const int8_T c[5] = { 0, 0, 0, 0, 1 };

  boolean_T rtb_enableacc_0;
  boolean_T rtb_enablemag_0;
  boolean_T rtb_enablepressure_0;
  static const real_T b[3] = { 16.0, 0.0, 48.0 };

  boolean_T varargout_1;
  boolean_T p;
  int32_T i;
  int32_T i_0;
  int32_T c_sizes_idx_1;
  real_T rtb_DataTypeConversion_idx_2;

  // Memory: '<Root>/Initial States'
  for (i = 0; i < 5; i++) {
    rtB.InitialStates[i] = rtDWork.InitialStates_PreviousInput[i];
  }

  // End of Memory: '<Root>/Initial States'

  // Outputs for Atomic SubSystem: '<S1>/Subscribe'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   MATLABSystem: '<S5>/SourceBlock'

  varargout_1 = Sub_sensorfusion_427.get_latest_msg(&rtB.varargout_2);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S6>/Enable'

  // MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S6>/In1'

  if (varargout_1) {
    rtB.In1 = rtB.varargout_2;
  }

  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S1>/Subscribe'

  // DataTypeConversion: '<S1>/Data Type Conversion'
  for (i = 0; i < 10; i++) {
    rtB.DataTypeConversion[i] = rtB.In1.Data[i];
  }

  // End of DataTypeConversion: '<S1>/Data Type Conversion'

  // Outputs for Enabled SubSystem: '<Root>/Send states and measurements' incorporates:
  //   EnablePort: '<S3>/Enable'

  // Outputs for Enabled SubSystem: '<Root>/Measurement update' incorporates:
  //   EnablePort: '<S2>/Enable'

  // Outputs for Enabled SubSystem: '<Root>/Time update' incorporates:
  //   EnablePort: '<S4>/Enable'

  // Outputs for Atomic SubSystem: '<S1>/Subscribe'
  // MATLABSystem: '<S5>/SourceBlock'
  if (varargout_1) {
    // Start for MATLABSystem: '<S4>/Get T' incorporates:
    //   MATLABSystem: '<S4>/Get T'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_589.get_parameter(&rtB.xzpwy);

    // End of Start for MATLABSystem: '<S4>/Get T'

    // MATLAB Function: '<S4>/Time update' incorporates:
    //   Constant: '<S4>/Constant2'
    //   MATLABSystem: '<S4>/Get T'
    //   Memory: '<Root>/Initial P'

    // MATLAB Function 'Time update/Time update': '<S11>:1'
    // '<S11>:1:3'
    // '<S11>:1:4'
    // obs must be correct measurement
    // '<S11>:1:7'
    // '<S11>:1:8'
    // '<S11>:1:9'
    // calculated from calc derivatives script
    // '<S11>:1:12'
    rtB.F[0] = 1.0;
    rtB.F[5] = -(rtB.xzpwy * rtB.DataTypeConversion[0]) / 2.0;
    rtB.F[10] = -(rtB.xzpwy * rtB.DataTypeConversion[1]) / 2.0;
    rtB.F[15] = -(rtB.xzpwy * rtB.DataTypeConversion[2]) / 2.0;
    rtB.F[20] = 0.0;
    rtB.F[1] = rtB.xzpwy * rtB.DataTypeConversion[0] / 2.0;
    rtB.F[6] = 1.0;
    rtB.F[11] = rtB.xzpwy * rtB.DataTypeConversion[2] / 2.0;
    rtB.F[16] = -(rtB.xzpwy * rtB.DataTypeConversion[1]) / 2.0;
    rtB.F[21] = 0.0;
    rtB.F[2] = rtB.xzpwy * rtB.DataTypeConversion[1] / 2.0;
    rtB.F[7] = -(rtB.xzpwy * rtB.DataTypeConversion[2]) / 2.0;
    rtB.F[12] = 1.0;
    rtB.F[17] = rtB.xzpwy * rtB.DataTypeConversion[0] / 2.0;
    rtB.F[22] = 0.0;
    rtB.F[3] = rtB.xzpwy * rtB.DataTypeConversion[2] / 2.0;
    rtB.F[8] = rtB.xzpwy * rtB.DataTypeConversion[1] / 2.0;
    rtB.F[13] = -(rtB.xzpwy * rtB.DataTypeConversion[0]) / 2.0;
    rtB.F[18] = 1.0;
    rtB.F[23] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtB.F[4 + 5 * i_0] = c[i_0];
    }

    // calculated from calc derivatives script
    // '<S11>:1:19'
    rtB.Gv_k[0] = -(rtB.xzpwy * rtB.InitialStates[1]) / 2.0;
    rtB.Gv_k[5] = -(rtB.xzpwy * rtB.InitialStates[2]) / 2.0;
    rtB.Gv_k[10] = -(rtB.xzpwy * rtB.InitialStates[3]) / 2.0;
    rtB.Gv_k[15] = 0.0;
    rtB.Gv_k[1] = rtB.xzpwy * rtB.InitialStates[0] / 2.0;
    rtB.Gv_k[6] = -(rtB.xzpwy * rtB.InitialStates[3]) / 2.0;
    rtB.Gv_k[11] = rtB.xzpwy * rtB.InitialStates[2] / 2.0;
    rtB.Gv_k[16] = 0.0;
    rtB.Gv_k[2] = rtB.xzpwy * rtB.InitialStates[3] / 2.0;
    rtB.Gv_k[7] = rtB.xzpwy * rtB.InitialStates[0] / 2.0;
    rtB.Gv_k[12] = -(rtB.xzpwy * rtB.InitialStates[1]) / 2.0;
    rtB.Gv_k[17] = 0.0;
    rtB.Gv_k[3] = -(rtB.xzpwy * rtB.InitialStates[2]) / 2.0;
    rtB.Gv_k[8] = rtB.xzpwy * rtB.InitialStates[1] / 2.0;
    rtB.Gv_k[13] = rtB.xzpwy * rtB.InitialStates[0] / 2.0;
    rtB.Gv_k[18] = 0.0;
    rtB.Gv_k[4] = 0.0;
    rtB.Gv_k[9] = 0.0;
    rtB.Gv_k[14] = 0.0;
    rtB.Gv_k[19] = 1.0;

    // '<S11>:1:27'
    // '<S11>:1:28'
    for (i_0 = 0; i_0 < 5; i_0++) {
      for (i = 0; i < 5; i++) {
        rtB.F_m[i_0 + 5 * i] = 0.0;
        for (c_sizes_idx_1 = 0; c_sizes_idx_1 < 5; c_sizes_idx_1++) {
          rtB.F_m[i_0 + 5 * i] += rtB.F[5 * c_sizes_idx_1 + i_0] *
            rtDWork.InitialP_PreviousInput[5 * i + c_sizes_idx_1];
        }
      }

      for (i = 0; i < 4; i++) {
        rtB.Gv_c[i_0 + 5 * i] = 0.0;
        rtB.Gv_c[i_0 + 5 * i] += rtConstP.Constant2_Value[i << 2] * rtB.Gv_k[i_0];
        rtB.Gv_c[i_0 + 5 * i] += rtConstP.Constant2_Value[(i << 2) + 1] *
          rtB.Gv_k[i_0 + 5];
        rtB.Gv_c[i_0 + 5 * i] += rtConstP.Constant2_Value[(i << 2) + 2] *
          rtB.Gv_k[i_0 + 10];
        rtB.Gv_c[i_0 + 5 * i] += rtConstP.Constant2_Value[(i << 2) + 3] *
          rtB.Gv_k[i_0 + 15];
      }
    }

    for (i_0 = 0; i_0 < 5; i_0++) {
      for (i = 0; i < 5; i++) {
        rtB.F_c[i_0 + 5 * i] = 0.0;
        for (c_sizes_idx_1 = 0; c_sizes_idx_1 < 5; c_sizes_idx_1++) {
          rtB.F_c[i_0 + 5 * i] += rtB.F_m[5 * c_sizes_idx_1 + i_0] * rtB.F[5 *
            c_sizes_idx_1 + i];
        }

        rtB.Gv[i_0 + 5 * i] = 0.0;
        rtB.Gv[i_0 + 5 * i] += rtB.Gv_c[i_0] * rtB.Gv_k[i];
        rtB.Gv[i_0 + 5 * i] += rtB.Gv_c[i_0 + 5] * rtB.Gv_k[i + 5];
        rtB.Gv[i_0 + 5 * i] += rtB.Gv_c[i_0 + 10] * rtB.Gv_k[i + 10];
        rtB.Gv[i_0 + 5 * i] += rtB.Gv_c[i_0 + 15] * rtB.Gv_k[i + 15];
      }
    }

    for (i_0 = 0; i_0 < 5; i_0++) {
      // SignalConversion: '<S4>/OutportBufferForStates_time_update' incorporates:
      //   MATLAB Function: '<S4>/Time update'

      rtB.OutportBufferForStates_time_upd[i_0] = 0.0;
      for (i = 0; i < 5; i++) {
        // SignalConversion: '<S4>/OutportBufferForP_time_update' incorporates:
        //   MATLAB Function: '<S4>/Time update'

        rtB.OutportBufferForP_time_update[i + 5 * i_0] = rtB.F_c[5 * i_0 + i] +
          rtB.Gv[5 * i_0 + i];

        // SignalConversion: '<S4>/OutportBufferForStates_time_update' incorporates:
        //   MATLAB Function: '<S4>/Time update'

        rtB.OutportBufferForStates_time_upd[i_0] += rtB.F[5 * i + i_0] *
          rtB.InitialStates[i];
      }
    }

    // Start for MATLABSystem: '<S2>/get R acc [1,1]' incorporates:
    //   MATLABSystem: '<S2>/get R acc [1,1]'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_m.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_m.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_632.get_parameter(&rtB.xzpwy);

    // End of Start for MATLABSystem: '<S2>/get R acc [1,1]'

    // Start for MATLABSystem: '<S2>/get R acc[2,2]' incorporates:
    //   MATLABSystem: '<S2>/get R acc[2,2]'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_h.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_h.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_634.get_parameter(&rtB.innovation);

    // End of Start for MATLABSystem: '<S2>/get R acc[2,2]'

    // Start for MATLABSystem: '<S2>/get R acc [3,3]' incorporates:
    //   MATLABSystem: '<S2>/get R acc [3,3]'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_mc.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_mc.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_633.get_parameter(&rtB.q_idx_1);

    // End of Start for MATLABSystem: '<S2>/get R acc [3,3]'

    // S-Function (sdspdiag2): '<S2>/Create Diagonal Matrix R acc' incorporates:
    //   MATLABSystem: '<S2>/get R acc [1,1]'
    //   MATLABSystem: '<S2>/get R acc [3,3]'
    //   MATLABSystem: '<S2>/get R acc[2,2]'

    memset(&rtB.CreateDiagonalMatrixRacc[0], 0, 9U * sizeof(real_T));
    rtB.CreateDiagonalMatrixRacc[0] = rtB.xzpwy;
    rtB.CreateDiagonalMatrixRacc[4] = rtB.innovation;
    rtB.CreateDiagonalMatrixRacc[8] = rtB.q_idx_1;

    // Start for MATLABSystem: '<S2>/get R mag [1,1]' incorporates:
    //   MATLABSystem: '<S2>/get R mag [1,1]'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_i.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_i.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_635.get_parameter(&rtB.xzpwy);

    // End of Start for MATLABSystem: '<S2>/get R mag [1,1]'

    // Start for MATLABSystem: '<S2>/get R mag [2,2]' incorporates:
    //   MATLABSystem: '<S2>/get R mag [2,2]'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_k.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_k.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_636.get_parameter(&rtB.innovation);

    // End of Start for MATLABSystem: '<S2>/get R mag [2,2]'

    // Start for MATLABSystem: '<S2>/get R mag [3,3]' incorporates:
    //   MATLABSystem: '<S2>/get R mag [3,3]'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_p.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_p.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_637.get_parameter(&rtB.q_idx_1);

    // End of Start for MATLABSystem: '<S2>/get R mag [3,3]'

    // S-Function (sdspdiag2): '<S2>/Create Diagonal Matrix R mag' incorporates:
    //   MATLABSystem: '<S2>/get R mag [1,1]'
    //   MATLABSystem: '<S2>/get R mag [2,2]'
    //   MATLABSystem: '<S2>/get R mag [3,3]'

    memset(&rtB.CreateDiagonalMatrixRmag[0], 0, 9U * sizeof(real_T));
    rtB.CreateDiagonalMatrixRmag[0] = rtB.xzpwy;
    rtB.CreateDiagonalMatrixRmag[4] = rtB.innovation;
    rtB.CreateDiagonalMatrixRmag[8] = rtB.q_idx_1;

    // Start for MATLABSystem: '<S2>/Get eps acc' incorporates:
    //   MATLABSystem: '<S2>/Get eps acc'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_b.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_b.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_615.get_parameter(&rtB.rtb_Getepsacc_d);

    // End of Start for MATLABSystem: '<S2>/Get eps acc'

    // Start for MATLABSystem: '<S2>/Get eps mag' incorporates:
    //   MATLABSystem: '<S2>/Get eps mag'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_f.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_f.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_616.get_parameter(&rtB.q_idx_2);

    // End of Start for MATLABSystem: '<S2>/Get eps mag'

    // Start for MATLABSystem: '<S2>/Get gravitational constant' incorporates:
    //   MATLABSystem: '<S2>/Get gravitational constant'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_c.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_c.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_617.get_parameter(&rtB.innovation);

    // End of Start for MATLABSystem: '<S2>/Get gravitational constant'

    // Start for MATLABSystem: '<S2>/Get water density' incorporates:
    //   MATLABSystem: '<S2>/Get water density'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_e.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_e.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_618.get_parameter(&rtB.q_idx_1);

    // End of Start for MATLABSystem: '<S2>/Get water density'

    // Start for MATLABSystem: '<S2>/Get x offset of  pressure sensor' incorporates:
    //   MATLABSystem: '<S2>/Get x offset of  pressure sensor'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_hb.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_hb.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_619.get_parameter(&rtB.q_idx_3);

    // End of Start for MATLABSystem: '<S2>/Get x offset of  pressure sensor'

    // Start for MATLABSystem: '<S2>/enable acc' incorporates:
    //   MATLABSystem: '<S2>/enable acc'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_l.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_l.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_628.get_parameter(&rtb_enableacc_0);

    // End of Start for MATLABSystem: '<S2>/enable acc'

    // Start for MATLABSystem: '<S2>/enable mag' incorporates:
    //   MATLABSystem: '<S2>/enable mag'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_ls.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_ls.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_629.get_parameter(&rtb_enablemag_0);

    // End of Start for MATLABSystem: '<S2>/enable mag'

    // Start for MATLABSystem: '<S2>/enable pressure' incorporates:
    //   MATLABSystem: '<S2>/enable pressure'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_mh.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_mh.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_630.get_parameter(&rtb_enablepressure_0);

    // End of Start for MATLABSystem: '<S2>/enable pressure'

    // Start for MATLABSystem: '<S2>/get R pressure [1,1]' incorporates:
    //   MATLABSystem: '<S2>/get R pressure [1,1]'

    varargout_1 = false;
    p = true;
    if (!(rtDWork.obj_g.SampleTime == -1.0)) {
      p = false;
    }

    if (p) {
      varargout_1 = true;
    }

    if (!varargout_1) {
      rtDWork.obj_g.SampleTime = -1.0;
    }

    ParamGet_sensorfusion_638.get_parameter(&rtB.xzpwy);

    // End of Start for MATLABSystem: '<S2>/get R pressure [1,1]'

    // MATLAB Function: '<S2>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S2>/Get eps acc'
    //   MATLABSystem: '<S2>/Get eps mag'
    //   MATLABSystem: '<S2>/Get gravitational constant'
    //   MATLABSystem: '<S2>/Get water density'
    //   MATLABSystem: '<S2>/Get x offset of  pressure sensor'
    //   MATLABSystem: '<S2>/enable acc'
    //   MATLABSystem: '<S2>/enable mag'
    //   MATLABSystem: '<S2>/enable pressure'
    //   MATLABSystem: '<S2>/get R pressure [1,1]'

    for (i = 0; i < 5; i++) {
      rtB.states_update_j[i] = rtB.OutportBufferForStates_time_upd[i];
    }

    memcpy(&rtB.F[0], &rtB.OutportBufferForP_time_update[0], 25U * sizeof(real_T));

    // MATLAB Function 'Measurement update/MATLAB Function': '<S7>:1'
    //  Get states
    // '<S7>:1:5'
    // '<S7>:1:6'
    // '<S7>:1:7'
    //  Get measurements
    // '<S7>:1:10'
    // '<S7>:1:11'
    // '<S7>:1:12'
    //  Constants for magnetic field ad hoc solution
    //  Magnetic field in mircoTesla
    // '<S7>:1:18'
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
    //  Acc measurement update
    //  Outlier reject eq
    if ((fabs(norm(*(real_T (*)[3])&rtB.DataTypeConversion[3]) - rtB.innovation)
         < rtB.rtb_Getepsacc_d) && rtb_enableacc_0) {
      // '<S7>:1:25'
      //  Measurement equations
      //  Calculate the measurement we should get with the current states
      // '<S7>:1:29'
      //  Calc innovation
      // '<S7>:1:34'
      //  H matrix generated from calcderivatives file
      //  Hij = d(measeq(i))/d(state(j))
      // '<S7>:1:38'
      rtB.H_acc[0] = 2.0 * rtB.innovation * rtB.OutportBufferForStates_time_upd
        [2];
      rtB.H_acc[3] = -2.0 * rtB.innovation *
        rtB.OutportBufferForStates_time_upd[3];
      rtB.H_acc[6] = 2.0 * rtB.innovation * rtB.OutportBufferForStates_time_upd
        [0];
      rtB.H_acc[9] = -2.0 * rtB.innovation *
        rtB.OutportBufferForStates_time_upd[1];
      rtB.H_acc[12] = 0.0;
      rtB.H_acc[1] = -2.0 * rtB.innovation *
        rtB.OutportBufferForStates_time_upd[1];
      rtB.H_acc[4] = -2.0 * rtB.innovation *
        rtB.OutportBufferForStates_time_upd[0];
      rtB.H_acc[7] = -2.0 * rtB.innovation *
        rtB.OutportBufferForStates_time_upd[3];
      rtB.H_acc[10] = -2.0 * rtB.innovation *
        rtB.OutportBufferForStates_time_upd[2];
      rtB.H_acc[13] = 0.0;
      rtB.H_acc[2] = -4.0 * rtB.innovation *
        rtB.OutportBufferForStates_time_upd[0];
      rtB.H_acc[5] = 0.0;
      rtB.H_acc[8] = 0.0;
      rtB.H_acc[11] = -4.0 * rtB.innovation *
        rtB.OutportBufferForStates_time_upd[3];
      rtB.H_acc[14] = 0.0;

      //  Calc kalman gain
      // '<S7>:1:44'
      for (i_0 = 0; i_0 < 5; i_0++) {
        for (i = 0; i < 3; i++) {
          rtB.F_b[i_0 + 5 * i] = 0.0;
          for (c_sizes_idx_1 = 0; c_sizes_idx_1 < 5; c_sizes_idx_1++) {
            rtB.F_b[i_0 + 5 * i] += rtB.OutportBufferForP_time_update[5 *
              c_sizes_idx_1 + i_0] * rtB.H_acc[3 * c_sizes_idx_1 + i];
          }
        }
      }

      for (i_0 = 0; i_0 < 3; i_0++) {
        for (i = 0; i < 5; i++) {
          rtB.K[i_0 + 3 * i] = 0.0;
          for (c_sizes_idx_1 = 0; c_sizes_idx_1 < 5; c_sizes_idx_1++) {
            rtB.K[i_0 + 3 * i] += rtB.H_acc[3 * c_sizes_idx_1 + i_0] *
              rtB.OutportBufferForP_time_update[5 * i + c_sizes_idx_1];
          }
        }
      }

      for (i_0 = 0; i_0 < 3; i_0++) {
        for (i = 0; i < 3; i++) {
          rtB.d0 = 0.0;
          for (c_sizes_idx_1 = 0; c_sizes_idx_1 < 5; c_sizes_idx_1++) {
            rtB.d0 += rtB.K[3 * c_sizes_idx_1 + i_0] * rtB.H_acc[3 *
              c_sizes_idx_1 + i];
          }

          rtB.H_acc_p[i_0 + 3 * i] = rtB.CreateDiagonalMatrixRacc[3 * i + i_0] +
            rtB.d0;
        }
      }

      mrdivide(rtB.F_b, rtB.H_acc_p, rtB.K);

      //  Update P
      // '<S7>:1:49'
      for (i_0 = 0; i_0 < 5; i_0++) {
        for (i = 0; i < 5; i++) {
          rtB.F_c[i_0 + 5 * i] = 0.0;
          rtB.F_c[i_0 + 5 * i] += rtB.H_acc[3 * i] * rtB.K[i_0];
          rtB.F_c[i_0 + 5 * i] += rtB.H_acc[3 * i + 1] * rtB.K[i_0 + 5];
          rtB.F_c[i_0 + 5 * i] += rtB.H_acc[3 * i + 2] * rtB.K[i_0 + 10];
        }
      }

      //  Update states
      // '<S7>:1:54'
      rtB.rtb_Getepsacc_d = rtB.DataTypeConversion[3] - (2.0 *
        rtB.OutportBufferForStates_time_upd[0] *
        rtB.OutportBufferForStates_time_upd[2] - 2.0 *
        rtB.OutportBufferForStates_time_upd[1] *
        rtB.OutportBufferForStates_time_upd[3]) * rtB.innovation;
      rtB.rtb_DataTypeConversion_idx_1 = rtB.DataTypeConversion[4] - (2.0 *
        rtB.OutportBufferForStates_time_upd[0] *
        rtB.OutportBufferForStates_time_upd[1] + 2.0 *
        rtB.OutportBufferForStates_time_upd[2] *
        rtB.OutportBufferForStates_time_upd[3]) * -rtB.innovation;
      rtb_DataTypeConversion_idx_2 = rtB.DataTypeConversion[5] -
        ((rtB.OutportBufferForStates_time_upd[0] *
          rtB.OutportBufferForStates_time_upd[0] * 2.0 +
          rtB.OutportBufferForStates_time_upd[3] *
          rtB.OutportBufferForStates_time_upd[3] * 2.0) - 1.0) * -rtB.innovation;
      for (i_0 = 0; i_0 < 5; i_0++) {
        for (i = 0; i < 5; i++) {
          rtB.d0 = 0.0;
          for (c_sizes_idx_1 = 0; c_sizes_idx_1 < 5; c_sizes_idx_1++) {
            rtB.d0 += rtB.F_c[5 * c_sizes_idx_1 + i_0] *
              rtB.OutportBufferForP_time_update[5 * i + c_sizes_idx_1];
          }

          rtB.F[i_0 + 5 * i] = rtB.OutportBufferForP_time_update[5 * i + i_0] -
            rtB.d0;
        }

        rtB.states_update_j[i_0] = ((rtB.K[i_0 + 5] *
          rtB.rtb_DataTypeConversion_idx_1 + rtB.K[i_0] * rtB.rtb_Getepsacc_d) +
          rtB.K[i_0 + 10] * rtb_DataTypeConversion_idx_2) +
          rtB.OutportBufferForStates_time_upd[i_0];
      }

      //  norm quaternions
      // '<S7>:1:56'
      rtB.rtb_Getepsacc_d = norm_p(*(real_T (*)[4])&rtB.states_update_j[0]);
      rtB.states_update_j[0] /= rtB.rtb_Getepsacc_d;
      rtB.states_update_j[1] /= rtB.rtb_Getepsacc_d;
      rtB.states_update_j[2] /= rtB.rtb_Getepsacc_d;
      rtB.states_update_j[3] /= rtB.rtb_Getepsacc_d;

      // '<S7>:1:57'
      if (rtB.states_update_j[0] < 0.0) {
        rtB.rtb_Getepsacc_d = -1.0;
      } else if (rtB.states_update_j[0] > 0.0) {
        rtB.rtb_Getepsacc_d = 1.0;
      } else if (rtB.states_update_j[0] == 0.0) {
        rtB.rtb_Getepsacc_d = 0.0;
      } else {
        rtB.rtb_Getepsacc_d = rtB.states_update_j[0];
      }

      rtB.states_update_j[0] *= rtB.rtb_Getepsacc_d;
      rtB.states_update_j[1] *= rtB.rtb_Getepsacc_d;
      rtB.states_update_j[2] *= rtB.rtb_Getepsacc_d;
      rtB.states_update_j[3] *= rtB.rtb_Getepsacc_d;
    }

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  Mag measurement update
    //  Outlier reject eq
    if ((fabs(norm(*(real_T (*)[3])&rtB.DataTypeConversion[6]) - norm(b)) <
         rtB.q_idx_2) && rtb_enablemag_0) {
      // '<S7>:1:65'
      //  Measurement equations
      // '<S7>:1:68'
      //  Calc innovation
      // '<S7>:1:74'
      //  H matrix generated from calcderivatives file
      //  Hij = d(measeq(i))/d(state(j))
      // '<S7>:1:78'
      rtB.H_acc[0] = 4.0 * rtB.OutportBufferForStates_time_upd[0] * 16.0 - 96.0 *
        rtB.OutportBufferForStates_time_upd[2];
      rtB.H_acc[3] = 4.0 * rtB.OutportBufferForStates_time_upd[1] * 16.0 + 96.0 *
        rtB.OutportBufferForStates_time_upd[3];
      rtB.H_acc[6] = -96.0 * rtB.OutportBufferForStates_time_upd[0];
      rtB.H_acc[9] = 96.0 * rtB.OutportBufferForStates_time_upd[1];
      rtB.H_acc[12] = 0.0;
      rtB.H_acc[1] = 96.0 * rtB.OutportBufferForStates_time_upd[1] - 2.0 *
        rtB.OutportBufferForStates_time_upd[3] * 16.0;
      rtB.H_acc[4] = 2.0 * rtB.OutportBufferForStates_time_upd[2] * 16.0 + 96.0 *
        rtB.OutportBufferForStates_time_upd[0];
      rtB.H_acc[7] = 2.0 * rtB.OutportBufferForStates_time_upd[1] * 16.0 + 96.0 *
        rtB.OutportBufferForStates_time_upd[3];
      rtB.H_acc[10] = 96.0 * rtB.OutportBufferForStates_time_upd[2] - 2.0 *
        rtB.OutportBufferForStates_time_upd[0] * 16.0;
      rtB.H_acc[13] = 0.0;
      rtB.H_acc[2] = 2.0 * rtB.OutportBufferForStates_time_upd[2] * 16.0 + 192.0
        * rtB.OutportBufferForStates_time_upd[0];
      rtB.H_acc[5] = 2.0 * rtB.OutportBufferForStates_time_upd[3] * 16.0;
      rtB.H_acc[8] = 2.0 * rtB.OutportBufferForStates_time_upd[0] * 16.0;
      rtB.H_acc[11] = 2.0 * rtB.OutportBufferForStates_time_upd[1] * 16.0 +
        192.0 * rtB.OutportBufferForStates_time_upd[3];
      rtB.H_acc[14] = 0.0;

      //  Calc kalman gain
      // '<S7>:1:86'
      for (i_0 = 0; i_0 < 5; i_0++) {
        for (i = 0; i < 3; i++) {
          rtB.F_b[i_0 + 5 * i] = 0.0;
          for (c_sizes_idx_1 = 0; c_sizes_idx_1 < 5; c_sizes_idx_1++) {
            rtB.F_b[i_0 + 5 * i] += rtB.F[5 * c_sizes_idx_1 + i_0] * rtB.H_acc[3
              * c_sizes_idx_1 + i];
          }
        }
      }

      for (i_0 = 0; i_0 < 3; i_0++) {
        for (i = 0; i < 5; i++) {
          rtB.K[i_0 + 3 * i] = 0.0;
          for (c_sizes_idx_1 = 0; c_sizes_idx_1 < 5; c_sizes_idx_1++) {
            rtB.K[i_0 + 3 * i] += rtB.H_acc[3 * c_sizes_idx_1 + i_0] * rtB.F[5 *
              i + c_sizes_idx_1];
          }
        }
      }

      for (i_0 = 0; i_0 < 3; i_0++) {
        for (i = 0; i < 3; i++) {
          rtB.d0 = 0.0;
          for (c_sizes_idx_1 = 0; c_sizes_idx_1 < 5; c_sizes_idx_1++) {
            rtB.d0 += rtB.K[3 * c_sizes_idx_1 + i_0] * rtB.H_acc[3 *
              c_sizes_idx_1 + i];
          }

          rtB.H_acc_p[i_0 + 3 * i] = rtB.CreateDiagonalMatrixRmag[3 * i + i_0] +
            rtB.d0;
        }
      }

      mrdivide(rtB.F_b, rtB.H_acc_p, rtB.K);

      //  Update P
      // '<S7>:1:92'
      for (i_0 = 0; i_0 < 5; i_0++) {
        for (i = 0; i < 5; i++) {
          rtB.F_c[i_0 + 5 * i] = 0.0;
          rtB.F_c[i_0 + 5 * i] += rtB.H_acc[3 * i] * rtB.K[i_0];
          rtB.F_c[i_0 + 5 * i] += rtB.H_acc[3 * i + 1] * rtB.K[i_0 + 5];
          rtB.F_c[i_0 + 5 * i] += rtB.H_acc[3 * i + 2] * rtB.K[i_0 + 10];
        }
      }

      for (i_0 = 0; i_0 < 5; i_0++) {
        for (i = 0; i < 5; i++) {
          rtB.d0 = 0.0;
          for (c_sizes_idx_1 = 0; c_sizes_idx_1 < 5; c_sizes_idx_1++) {
            rtB.d0 += rtB.F_c[5 * c_sizes_idx_1 + i_0] * rtB.F[5 * i +
              c_sizes_idx_1];
          }

          rtB.F_m[i_0 + 5 * i] = rtB.F[5 * i + i_0] - rtB.d0;
        }
      }

      //  Update states
      // '<S7>:1:97'
      rtB.rtb_Getepsacc_d = rtB.DataTypeConversion[6] -
        (((rtB.OutportBufferForStates_time_upd[0] *
           rtB.OutportBufferForStates_time_upd[0] * 2.0 +
           rtB.OutportBufferForStates_time_upd[1] *
           rtB.OutportBufferForStates_time_upd[1] * 2.0) - 1.0) * 16.0 - (2.0 *
          rtB.OutportBufferForStates_time_upd[0] *
          rtB.OutportBufferForStates_time_upd[2] - 2.0 *
          rtB.OutportBufferForStates_time_upd[1] *
          rtB.OutportBufferForStates_time_upd[3]) * 48.0);
      rtB.rtb_DataTypeConversion_idx_1 = rtB.DataTypeConversion[7] - ((2.0 *
        rtB.OutportBufferForStates_time_upd[0] *
        rtB.OutportBufferForStates_time_upd[1] + 2.0 *
        rtB.OutportBufferForStates_time_upd[2] *
        rtB.OutportBufferForStates_time_upd[3]) * 48.0 - (2.0 *
        rtB.OutportBufferForStates_time_upd[0] *
        rtB.OutportBufferForStates_time_upd[3] - 2.0 *
        rtB.OutportBufferForStates_time_upd[1] *
        rtB.OutportBufferForStates_time_upd[2]) * 16.0);
      rtb_DataTypeConversion_idx_2 = rtB.DataTypeConversion[8] -
        (((rtB.OutportBufferForStates_time_upd[0] *
           rtB.OutportBufferForStates_time_upd[0] * 2.0 +
           rtB.OutportBufferForStates_time_upd[3] *
           rtB.OutportBufferForStates_time_upd[3] * 2.0) - 1.0) * 48.0 + (2.0 *
          rtB.OutportBufferForStates_time_upd[0] *
          rtB.OutportBufferForStates_time_upd[2] + 2.0 *
          rtB.OutportBufferForStates_time_upd[1] *
          rtB.OutportBufferForStates_time_upd[3]) * 16.0);
      for (i_0 = 0; i_0 < 5; i_0++) {
        for (i = 0; i < 5; i++) {
          rtB.F[i + 5 * i_0] = rtB.F_m[5 * i_0 + i];
        }

        rtB.states_update_j[i_0] += (rtB.K[i_0 + 5] *
          rtB.rtb_DataTypeConversion_idx_1 + rtB.K[i_0] * rtB.rtb_Getepsacc_d) +
          rtB.K[i_0 + 10] * rtb_DataTypeConversion_idx_2;
      }

      //  norm quaternions
      // '<S7>:1:100'
      rtB.q_idx_2 = norm_p(*(real_T (*)[4])&rtB.states_update_j[0]);
      rtB.states_update_j[0] /= rtB.q_idx_2;
      rtB.states_update_j[1] /= rtB.q_idx_2;
      rtB.states_update_j[2] /= rtB.q_idx_2;
      rtB.states_update_j[3] /= rtB.q_idx_2;

      // '<S7>:1:101'
      if (rtB.states_update_j[0] < 0.0) {
        rtB.q_idx_2 = -1.0;
      } else if (rtB.states_update_j[0] > 0.0) {
        rtB.q_idx_2 = 1.0;
      } else if (rtB.states_update_j[0] == 0.0) {
        rtB.q_idx_2 = 0.0;
      } else {
        rtB.q_idx_2 = rtB.states_update_j[0];
      }

      rtB.states_update_j[0] *= rtB.q_idx_2;
      rtB.states_update_j[1] *= rtB.q_idx_2;
      rtB.states_update_j[2] *= rtB.q_idx_2;
      rtB.states_update_j[3] *= rtB.q_idx_2;
    }

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
    //  Pressure measurement update
    //  Outlier reject eq
    if ((rtB.DataTypeConversion[9] > 0.0) && rtb_enablepressure_0) {
      // '<S7>:1:109'
      //  Measurement equation. Asume that atmospheric pressure has been subtracted 
      //  in ardupilot
      // '<S7>:1:113'
      //  H matrix generated from calcderivatives file
      //  Hij = d(measeq(i))/d(state(j))
      // '<S7>:1:117'
      rtB.H_pressure[0] = -2.0 * rtB.innovation *
        rtB.OutportBufferForStates_time_upd[2] * rtB.q_idx_1 * rtB.q_idx_3;
      rtB.H_pressure[1] = 2.0 * rtB.innovation *
        rtB.OutportBufferForStates_time_upd[3] * rtB.q_idx_1 * rtB.q_idx_3;
      rtB.H_pressure[2] = -2.0 * rtB.innovation *
        rtB.OutportBufferForStates_time_upd[0] * rtB.q_idx_1 * rtB.q_idx_3;
      rtB.H_pressure[3] = 2.0 * rtB.innovation *
        rtB.OutportBufferForStates_time_upd[1] * rtB.q_idx_1 * rtB.q_idx_3;
      rtB.H_pressure[4] = rtB.innovation * rtB.q_idx_1;

      //  Calc innovation
      // '<S7>:1:120'
      rtB.innovation = rtB.DataTypeConversion[9] -
        (rtB.OutportBufferForStates_time_upd[4] - (2.0 *
          rtB.OutportBufferForStates_time_upd[0] *
          rtB.OutportBufferForStates_time_upd[2] - 2.0 *
          rtB.OutportBufferForStates_time_upd[1] *
          rtB.OutportBufferForStates_time_upd[3]) * rtB.q_idx_3) *
        (rtB.innovation * rtB.q_idx_1);

      //  Calc kalman gain
      // '<S7>:1:123'
      rtB.d0 = 0.0;
      for (i_0 = 0; i_0 < 5; i_0++) {
        rtB.H_pressure_c[i_0] = 0.0;
        for (i = 0; i < 5; i++) {
          rtB.H_pressure_c[i_0] += rtB.F[5 * i_0 + i] * rtB.H_pressure[i];
        }

        rtB.d0 += rtB.H_pressure_c[i_0] * rtB.H_pressure[i_0];
      }

      rtB.xzpwy += rtB.d0;

      //  Update P
      // '<S7>:1:128'
      for (i_0 = 0; i_0 < 5; i_0++) {
        rtB.d0 = 0.0;
        for (i = 0; i < 5; i++) {
          rtB.d0 += rtB.F[5 * i + i_0] * rtB.H_pressure[i];
        }

        rtB.b_K[i_0] = rtB.d0 / rtB.xzpwy;
        for (i = 0; i < 5; i++) {
          rtB.F_m[i_0 + 5 * i] = rtB.b_K[i_0] * rtB.H_pressure[i];
        }
      }

      // SignalConversion: '<S2>/OutportBufferForP_measurement_update' incorporates:
      //   MATLABSystem: '<S2>/Get water density'
      //   MATLABSystem: '<S2>/Get x offset of  pressure sensor'
      //   MATLABSystem: '<S2>/get R pressure [1,1]'

      //  Update x
      // '<S7>:1:132'
      for (i_0 = 0; i_0 < 5; i_0++) {
        for (i = 0; i < 5; i++) {
          rtB.d0 = 0.0;
          for (c_sizes_idx_1 = 0; c_sizes_idx_1 < 5; c_sizes_idx_1++) {
            rtB.d0 += rtB.F_m[5 * c_sizes_idx_1 + i_0] * rtB.F[5 * i +
              c_sizes_idx_1];
          }

          rtB.OutportBufferForP_measurement_u[i_0 + 5 * i] = rtB.F[5 * i + i_0]
            - rtB.d0;
        }

        rtB.states_update_j[i_0] += rtB.b_K[i_0] * rtB.innovation;
      }

      //  norm quaternions
      // '<S7>:1:135'
      rtB.xzpwy = norm_p(*(real_T (*)[4])&rtB.states_update_j[0]);
      rtB.states_update_j[0] /= rtB.xzpwy;
      rtB.states_update_j[1] /= rtB.xzpwy;
      rtB.states_update_j[2] /= rtB.xzpwy;
      rtB.states_update_j[3] /= rtB.xzpwy;

      // '<S7>:1:136'
      if (rtB.states_update_j[0] < 0.0) {
        rtB.xzpwy = -1.0;
      } else if (rtB.states_update_j[0] > 0.0) {
        rtB.xzpwy = 1.0;
      } else if (rtB.states_update_j[0] == 0.0) {
        rtB.xzpwy = 0.0;
      } else {
        rtB.xzpwy = rtB.states_update_j[0];
      }

      rtB.states_update_j[0] *= rtB.xzpwy;
      rtB.states_update_j[1] *= rtB.xzpwy;
      rtB.states_update_j[2] *= rtB.xzpwy;
      rtB.states_update_j[3] *= rtB.xzpwy;

      // '<S7>:1:138'
    } else {
      // SignalConversion: '<S2>/OutportBufferForP_measurement_update'
      // '<S7>:1:141'
      memcpy(&rtB.OutportBufferForP_measurement_u[0], &rtB.F[0], 25U * sizeof
             (real_T));

      // '<S7>:1:142'
    }

    // End of MATLAB Function: '<S2>/MATLAB Function'

    // SignalConversion: '<S2>/OutportBufferForStates_measurement_update'
    for (i = 0; i < 5; i++) {
      rtB.OutportBufferForStates_measurem[i] = rtB.states_update_j[i];
    }

    // End of SignalConversion: '<S2>/OutportBufferForStates_measurement_update' 

    // MATLAB Function: '<S3>/MATLAB Function' incorporates:
    //   Constant: '<S8>/Constant'

    rtB.out_message =
      sensorfusion_rtZSL_Bus_sensorfusion_std_msgs_Float64MultiArray;

    // MATLAB Function 'Send states and measurements/MATLAB Function': '<S9>:1'
    // Convert quaternions to Euler angles
    //  Example code from tsrt14 Lab2 at Liu is used.
    //  Due to the reordering of quaternions in the supplied code
    //  some sign adjustments had to be made
    //
    // '<S9>:1:8'
    rtB.innovation = rtB.OutportBufferForStates_measurem[0];
    rtB.q_idx_1 = rtB.OutportBufferForStates_measurem[2];
    rtB.q_idx_2 = rtB.OutportBufferForStates_measurem[1];
    rtB.q_idx_3 = rtB.OutportBufferForStates_measurem[3];

    // '<S9>:1:9'
    rtB.TmpSignalConversionAtCreate[0] = 0.0;
    rtB.TmpSignalConversionAtCreate[1] = 0.0;

    // '<S9>:1:11'
    rtB.xzpwy = rtB.OutportBufferForStates_measurem[2] *
      rtB.OutportBufferForStates_measurem[3] +
      rtB.OutportBufferForStates_measurem[0] *
      rtB.OutportBufferForStates_measurem[1];

    //  Handle the north pole
    i = 0;
    if (rtB.xzpwy + 1.4901161193847656E-8 > 0.5) {
      // '<S9>:1:13'
      i = 1;
    }

    rtB.q_sizes_gu[0] = 1;
    rtB.q_sizes_gu[1] = i;
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.q_data = rtB.q_idx_1;
    }

    rtB.q_sizes_ld[0] = 1;
    rtB.q_sizes_ld[1] = i;
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.q_data_d = rtB.innovation;
    }

    atan2_o(&rtB.q_data, rtB.q_sizes_gu, &rtB.q_data_d, rtB.q_sizes_ld,
            &rtB.b_b_data, rtB.b_b_sizes);

    // '<S9>:1:14'
    i = rtB.b_b_sizes[1];
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.TmpSignalConversionAtCreate[0] = rtB.b_b_data * 2.0;
    }

    //  Handle the south pole
    i = 0;
    if (rtB.xzpwy - 1.4901161193847656E-8 < -0.5) {
      // '<S9>:1:15'
      i = 1;
    }

    rtB.q_sizes_j[0] = 1;
    rtB.q_sizes_j[1] = i;
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.q_data = rtB.q_idx_1;
    }

    rtB.q_sizes_d[0] = 1;
    rtB.q_sizes_d[1] = i;
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.q_data_d = rtB.innovation;
    }

    atan2_o(&rtB.q_data, rtB.q_sizes_j, &rtB.q_data_d, rtB.q_sizes_d,
            &rtB.b_b_data, rtB.b_b_sizes);

    // '<S9>:1:16'
    i = rtB.b_b_sizes[1];
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.TmpSignalConversionAtCreate[0] = rtB.b_b_data * -2.0;
    }

    varargout_1 = (rtB.xzpwy + 1.4901161193847656E-8 > 0.5);
    p = (rtB.xzpwy - 1.4901161193847656E-8 < -0.5);

    //  Handle the default case
    // yaw
    i = 0;
    if (!(varargout_1 || p)) {
      // '<S9>:1:18'
      i = 1;
    }

    c_sizes_idx_1 = i;
    i = 0;
    if (!(varargout_1 || p)) {
      // '<S9>:1:18'
      i = 1;
    }

    rtB.q_sizes_l[0] = 1;
    rtB.q_sizes_l[1] = i;
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.q_data = rtB.q_idx_2;
    }

    power(&rtB.q_data, rtB.q_sizes_l, &rtB.b_b_data, rtB.b_b_sizes);
    i = 0;
    if (!(varargout_1 || p)) {
      // '<S9>:1:18'
      i = 1;
    }

    rtB.q_sizes_m[0] = 1;
    rtB.q_sizes_m[1] = i;
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.q_data = rtB.q_idx_3;
    }

    power(&rtB.q_data, rtB.q_sizes_m, &rtB.q_data_d, rtB.q_sizes_gu);
    rtB.tmp_sizes_n[0] = 1;
    rtB.tmp_sizes_n[1] = c_sizes_idx_1;
    for (i_0 = 0; i_0 < c_sizes_idx_1; i_0++) {
      rtB.q_data = (rtB.q_idx_1 * rtB.q_idx_2 - rtB.innovation * rtB.q_idx_3) *
        2.0;
    }

    rtB.tmp_sizes_p[0] = 1;
    rtB.tmp_sizes_p[1] = rtB.b_b_sizes[1];
    i = rtB.b_b_sizes[0] * rtB.b_b_sizes[1];
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.tmp_data = 1.0 - (rtB.b_b_data + rtB.q_data_d) * 2.0;
    }

    atan2_o(&rtB.q_data, rtB.tmp_sizes_n, &rtB.tmp_data, rtB.tmp_sizes_p,
            &rtB.b_b_data, rtB.b_b_sizes);
    i = rtB.b_b_sizes[1];
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.b_b_data = -rtB.b_b_data;
    }

    // '<S9>:1:21'
    i = rtB.b_b_sizes[1];
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.TmpSignalConversionAtCreate[0] = rtB.b_b_data;
    }

    // Pitch
    i = 0;
    if (!(varargout_1 || p)) {
      // '<S9>:1:18'
      i = 1;
    }

    c_sizes_idx_1 = i;
    i = 0;
    if (!(varargout_1 || p)) {
      // '<S9>:1:18'
      i = 1;
    }

    rtB.q_sizes_g[0] = 1;
    rtB.q_sizes_g[1] = i;
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.q_data = rtB.q_idx_1;
    }

    power(&rtB.q_data, rtB.q_sizes_g, &rtB.b_b_data, rtB.b_b_sizes);
    i = 0;
    if (!(varargout_1 || p)) {
      // '<S9>:1:18'
      i = 1;
    }

    rtB.q_sizes[0] = 1;
    rtB.q_sizes[1] = i;
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.q_data = rtB.q_idx_2;
    }

    power(&rtB.q_data, rtB.q_sizes, &rtB.q_data_d, rtB.q_sizes_gu);
    rtB.tmp_sizes[0] = 1;
    rtB.tmp_sizes[1] = c_sizes_idx_1;
    for (i_0 = 0; i_0 < c_sizes_idx_1; i_0++) {
      rtB.q_data = (rtB.q_idx_2 * rtB.q_idx_3 - rtB.innovation * rtB.q_idx_1) *
        2.0;
    }

    rtB.tmp_sizes_g[0] = 1;
    rtB.tmp_sizes_g[1] = rtB.b_b_sizes[1];
    i = rtB.b_b_sizes[0] * rtB.b_b_sizes[1];
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.tmp_data = 1.0 - (rtB.b_b_data + rtB.q_data_d) * 2.0;
    }

    atan2_o(&rtB.q_data, rtB.tmp_sizes, &rtB.tmp_data, rtB.tmp_sizes_g,
            &rtB.b_b_data, rtB.b_b_sizes);
    i = rtB.b_b_sizes[1];
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.b_b_data = -rtB.b_b_data;
    }

    // '<S9>:1:24'
    i = rtB.b_b_sizes[1];
    for (i_0 = 0; i_0 < i; i_0++) {
      rtB.TmpSignalConversionAtCreate[1] = rtB.b_b_data;
    }

    // Roll
    // '<S9>:1:27'
    // '<S9>:1:29'
    rtB.rtb_TmpSignalConversionAtCrea_f[0] = rtB.TmpSignalConversionAtCreate[0]
      + 3.1415926535897931;
    rtB.rtb_TmpSignalConversionAtCrea_f[1] = rtB.TmpSignalConversionAtCreate[1]
      + 3.1415926535897931;
    rtB.rtb_TmpSignalConversionAtCrea_f[2] = asin(2.0 * rtB.xzpwy) +
      3.1415926535897931;
    mod(rtB.rtb_TmpSignalConversionAtCrea_f, rtB.TmpSignalConversionAtCreate);

    //  output format for controller euler [deg/s], omega [deg/s], depth[m], acc[m/s2]  
    // '<S9>:1:32'
    // '<S9>:1:33'
    // '<S9>:1:34'
    // '<S9>:1:35'
    // '<S9>:1:36'
    // '<S9>:1:38'
    rtB.out_message.Data[6] = rtB.OutportBufferForStates_measurem[4];
    rtB.out_message.Data[0] = (rtB.TmpSignalConversionAtCreate[0] -
      3.1415926535897931) * 180.0 / 3.1415926535897931;
    rtB.out_message.Data[3] = rtB.DataTypeConversion[0] * 180.0 /
      3.1415926535897931;
    rtB.out_message.Data[7] = rtB.DataTypeConversion[3];
    rtB.out_message.Data[1] = (rtB.TmpSignalConversionAtCreate[1] -
      3.1415926535897931) * 180.0 / 3.1415926535897931;
    rtB.out_message.Data[4] = rtB.DataTypeConversion[1] * 180.0 /
      3.1415926535897931;
    rtB.out_message.Data[8] = rtB.DataTypeConversion[4];
    rtB.out_message.Data[2] = (rtB.TmpSignalConversionAtCreate[2] -
      3.1415926535897931) * 180.0 / 3.1415926535897931;
    rtB.out_message.Data[5] = rtB.DataTypeConversion[2] * 180.0 /
      3.1415926535897931;
    rtB.out_message.Data[9] = rtB.DataTypeConversion[5];

    // '<S9>:1:39'
    rtB.out_message.Data_SL_Info.CurrentLength = 10U;

    // End of MATLAB Function: '<S3>/MATLAB Function'

    // Outputs for Atomic SubSystem: '<S3>/Publish'
    // MATLABSystem: '<S10>/SinkBlock'
    // '<S9>:1:40'
    Pub_sensorfusion_426.publish(&rtB.out_message);

    // End of Outputs for SubSystem: '<S3>/Publish'
  }

  // End of Outputs for SubSystem: '<S1>/Subscribe'
  // End of Outputs for SubSystem: '<Root>/Time update'
  // End of Outputs for SubSystem: '<Root>/Measurement update'
  // End of Outputs for SubSystem: '<Root>/Send states and measurements'

  // Update for Memory: '<Root>/Initial States'
  for (i = 0; i < 5; i++) {
    rtDWork.InitialStates_PreviousInput[i] =
      rtB.OutportBufferForStates_measurem[i];
  }

  // End of Update for Memory: '<Root>/Initial States'

  // Update for Memory: '<Root>/Initial P'
  memcpy(&rtDWork.InitialP_PreviousInput[0],
         &rtB.OutportBufferForP_measurement_u[0], 25U * sizeof(real_T));
}

// Model initialize function
void sensorfusionModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    static const char_T tmp[20] = { '/', 's', 'e', 'n', 's', 'o', 'r', 'f', 'u',
      's', 'i', 'o', 'n', '/', 's', 't', 'a', 't', 'e', 's' };

    static const char_T tmp_0[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'r', '_', 'p', 'r',
      'e', 's', 's', 'u', 'r', 'e' };

    static const char_T tmp_1[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 'p', 'r', 'e', 's', 's', 'u', 'r', 'e' };

    static const char_T tmp_2[38] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 'm', 'a', 'g', 'n', 'e', 't', 'o', 'm', 'e', 't', 'e', 'r'
    };

    static const char_T tmp_3[38] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 'a', 'c', 'c', 'e', 'l', 'e', 'r', 'a', 't', 'i', 'o', 'n'
    };

    static const char_T tmp_4[27] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'x', '_', 'o', 'f',
      'f', 's', 'e', 't' };

    static const char_T tmp_5[22] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'R', 'h', 'o' };

    static const char_T tmp_6[20] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'g' };

    static const char_T tmp_7[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'p', 's', '_',
      'm', 'a', 'g' };

    static const char_T tmp_8[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'p', 's', '_',
      'a', 'c', 'c' };

    static const char_T tmp_9[27] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'r', '_', 'm', 'a',
      'g', '_', '3', '3' };

    static const char_T tmp_a[27] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'r', '_', 'm', 'a',
      'g', '_', '2', '2' };

    static const char_T tmp_b[27] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'r', '_', 'm', 'a',
      'g', '_', '1', '1' };

    static const char_T tmp_c[27] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'r', '_', 'a', 'c',
      'c', '_', '3', '3' };

    static const char_T tmp_d[27] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'r', '_', 'a', 'c',
      'c', '_', '2', '2' };

    static const char_T tmp_e[27] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'r', '_', 'a', 'c',
      'c', '_', '1', '1' };

    static const char_T tmp_f[30] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'S', 'a', 'm', 'p',
      'l', 'e', '_', 't', 'i', 'm', 'e' };

    static const char_T tmp_g[14] = { '/', 'r', 'o', 'v', 'i', 'o', '/', 's',
      'e', 'n', 's', 'o', 'r', 's' };

    char_T tmp_h[23];
    char_T tmp_i[21];
    char_T tmp_j[15];

    // Start for Atomic SubSystem: '<S1>/Subscribe'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    rtDWork.obj_po.isInitialized = 0;
    rtDWork.objisempty_jw = true;
    rtDWork.obj_po.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      tmp_j[i] = tmp_g[i];
    }

    tmp_j[14] = '\x00';
    Sub_sensorfusion_427.create_subscriber(tmp_j, MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Start for SubSystem: '<S1>/Subscribe'

    // Start for Enabled SubSystem: '<Root>/Time update'
    // Start for MATLABSystem: '<S4>/Get T'
    rtDWork.obj.isInitialized = 0;
    rtDWork.objisempty = true;
    rtDWork.obj.SampleTime = -1.0;
    rtDWork.obj.isInitialized = 1;
    for (i = 0; i < 30; i++) {
      rtB.cv2[i] = tmp_f[i];
    }

    rtB.cv2[30] = '\x00';
    ParamGet_sensorfusion_589.initialize(rtB.cv2, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S4>/Get T'
    // End of Start for SubSystem: '<Root>/Time update'

    // Start for Enabled SubSystem: '<Root>/Measurement update'
    // Start for MATLABSystem: '<S2>/get R acc [1,1]'
    rtDWork.obj_m.isInitialized = 0;
    rtDWork.objisempty_e = true;
    rtDWork.obj_m.SampleTime = -1.0;
    rtDWork.obj_m.isInitialized = 1;
    for (i = 0; i < 27; i++) {
      rtB.cv4[i] = tmp_e[i];
    }

    rtB.cv4[27] = '\x00';
    ParamGet_sensorfusion_632.initialize(rtB.cv4, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S2>/get R acc [1,1]'

    // Start for MATLABSystem: '<S2>/get R acc[2,2]'
    rtDWork.obj_h.isInitialized = 0;
    rtDWork.objisempty_c = true;
    rtDWork.obj_h.SampleTime = -1.0;
    rtDWork.obj_h.isInitialized = 1;
    for (i = 0; i < 27; i++) {
      rtB.cv4[i] = tmp_d[i];
    }

    rtB.cv4[27] = '\x00';
    ParamGet_sensorfusion_634.initialize(rtB.cv4, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S2>/get R acc[2,2]'

    // Start for MATLABSystem: '<S2>/get R acc [3,3]'
    rtDWork.obj_mc.isInitialized = 0;
    rtDWork.objisempty_l = true;
    rtDWork.obj_mc.SampleTime = -1.0;
    rtDWork.obj_mc.isInitialized = 1;
    for (i = 0; i < 27; i++) {
      rtB.cv4[i] = tmp_c[i];
    }

    rtB.cv4[27] = '\x00';
    ParamGet_sensorfusion_633.initialize(rtB.cv4, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S2>/get R acc [3,3]'

    // Start for MATLABSystem: '<S2>/get R mag [1,1]'
    rtDWork.obj_i.isInitialized = 0;
    rtDWork.objisempty_g = true;
    rtDWork.obj_i.SampleTime = -1.0;
    rtDWork.obj_i.isInitialized = 1;
    for (i = 0; i < 27; i++) {
      rtB.cv4[i] = tmp_b[i];
    }

    rtB.cv4[27] = '\x00';
    ParamGet_sensorfusion_635.initialize(rtB.cv4, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S2>/get R mag [1,1]'

    // Start for MATLABSystem: '<S2>/get R mag [2,2]'
    rtDWork.obj_k.isInitialized = 0;
    rtDWork.objisempty_b = true;
    rtDWork.obj_k.SampleTime = -1.0;
    rtDWork.obj_k.isInitialized = 1;
    for (i = 0; i < 27; i++) {
      rtB.cv4[i] = tmp_a[i];
    }

    rtB.cv4[27] = '\x00';
    ParamGet_sensorfusion_636.initialize(rtB.cv4, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S2>/get R mag [2,2]'

    // Start for MATLABSystem: '<S2>/get R mag [3,3]'
    rtDWork.obj_p.isInitialized = 0;
    rtDWork.objisempty_n = true;
    rtDWork.obj_p.SampleTime = -1.0;
    rtDWork.obj_p.isInitialized = 1;
    for (i = 0; i < 27; i++) {
      rtB.cv4[i] = tmp_9[i];
    }

    rtB.cv4[27] = '\x00';
    ParamGet_sensorfusion_637.initialize(rtB.cv4, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S2>/get R mag [3,3]'

    // Start for MATLABSystem: '<S2>/Get eps acc'
    rtDWork.obj_b.isInitialized = 0;
    rtDWork.objisempty_gy = true;
    rtDWork.obj_b.SampleTime = -1.0;
    rtDWork.obj_b.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      rtB.cv5[i] = tmp_8[i];
    }

    rtB.cv5[26] = '\x00';
    ParamGet_sensorfusion_615.initialize(rtB.cv5, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S2>/Get eps acc'

    // Start for MATLABSystem: '<S2>/Get eps mag'
    rtDWork.obj_f.isInitialized = 0;
    rtDWork.objisempty_k = true;
    rtDWork.obj_f.SampleTime = -1.0;
    rtDWork.obj_f.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      rtB.cv5[i] = tmp_7[i];
    }

    rtB.cv5[26] = '\x00';
    ParamGet_sensorfusion_616.initialize(rtB.cv5, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S2>/Get eps mag'

    // Start for MATLABSystem: '<S2>/Get gravitational constant'
    rtDWork.obj_c.isInitialized = 0;
    rtDWork.objisempty_bb = true;
    rtDWork.obj_c.SampleTime = -1.0;
    rtDWork.obj_c.isInitialized = 1;
    for (i = 0; i < 20; i++) {
      tmp_i[i] = tmp_6[i];
    }

    tmp_i[20] = '\x00';
    ParamGet_sensorfusion_617.initialize(tmp_i, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S2>/Get gravitational constant'

    // Start for MATLABSystem: '<S2>/Get water density'
    rtDWork.obj_e.isInitialized = 0;
    rtDWork.objisempty_j = true;
    rtDWork.obj_e.SampleTime = -1.0;
    rtDWork.obj_e.isInitialized = 1;
    for (i = 0; i < 22; i++) {
      tmp_h[i] = tmp_5[i];
    }

    tmp_h[22] = '\x00';
    ParamGet_sensorfusion_618.initialize(tmp_h, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S2>/Get water density'

    // Start for MATLABSystem: '<S2>/Get x offset of  pressure sensor'
    rtDWork.obj_hb.isInitialized = 0;
    rtDWork.objisempty_m = true;
    rtDWork.obj_hb.SampleTime = -1.0;
    rtDWork.obj_hb.isInitialized = 1;
    for (i = 0; i < 27; i++) {
      rtB.cv4[i] = tmp_4[i];
    }

    rtB.cv4[27] = '\x00';
    ParamGet_sensorfusion_619.initialize(rtB.cv4, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S2>/Get x offset of  pressure sensor'

    // Start for MATLABSystem: '<S2>/enable acc'
    rtDWork.obj_l.isInitialized = 0;
    rtDWork.objisempty_hk = true;
    rtDWork.obj_l.SampleTime = -1.0;
    rtDWork.obj_l.isInitialized = 1;
    for (i = 0; i < 38; i++) {
      rtB.cv0[i] = tmp_3[i];
    }

    rtB.cv0[38] = '\x00';
    ParamGet_sensorfusion_628.initialize(rtB.cv0, ParameterInitialValue_i, 0U,
      1U, 2U);

    // End of Start for MATLABSystem: '<S2>/enable acc'

    // Start for MATLABSystem: '<S2>/enable mag'
    rtDWork.obj_ls.isInitialized = 0;
    rtDWork.objisempty_mi = true;
    rtDWork.obj_ls.SampleTime = -1.0;
    rtDWork.obj_ls.isInitialized = 1;
    for (i = 0; i < 38; i++) {
      rtB.cv0[i] = tmp_2[i];
    }

    rtB.cv0[38] = '\x00';
    ParamGet_sensorfusion_629.initialize(rtB.cv0, ParameterInitialValue_i, 0U,
      1U, 2U);

    // End of Start for MATLABSystem: '<S2>/enable mag'

    // Start for MATLABSystem: '<S2>/enable pressure'
    rtDWork.obj_mh.isInitialized = 0;
    rtDWork.objisempty_ji = true;
    rtDWork.obj_mh.SampleTime = -1.0;
    rtDWork.obj_mh.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      rtB.cv1[i] = tmp_1[i];
    }

    rtB.cv1[34] = '\x00';
    ParamGet_sensorfusion_630.initialize(rtB.cv1, ParameterInitialValue_i, 0U,
      1U, 2U);

    // End of Start for MATLABSystem: '<S2>/enable pressure'

    // Start for MATLABSystem: '<S2>/get R pressure [1,1]'
    rtDWork.obj_g.isInitialized = 0;
    rtDWork.objisempty_o = true;
    rtDWork.obj_g.SampleTime = -1.0;
    rtDWork.obj_g.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      rtB.cv3[i] = tmp_0[i];
    }

    rtB.cv3[29] = '\x00';
    ParamGet_sensorfusion_638.initialize(rtB.cv3, ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<S2>/get R pressure [1,1]'
    // End of Start for SubSystem: '<Root>/Measurement update'

    // Start for Enabled SubSystem: '<Root>/Send states and measurements'
    // Start for Atomic SubSystem: '<S3>/Publish'
    // Start for MATLABSystem: '<S10>/SinkBlock'
    rtDWork.obj_ic.isInitialized = 0;
    rtDWork.objisempty_h = true;
    rtDWork.obj_ic.isInitialized = 1;
    for (i = 0; i < 20; i++) {
      tmp_i[i] = tmp[i];
    }

    tmp_i[20] = '\x00';
    Pub_sensorfusion_426.create_publisher(tmp_i, MessageQueueLen);

    // End of Start for MATLABSystem: '<S10>/SinkBlock'
    // End of Start for SubSystem: '<S3>/Publish'
    // End of Start for SubSystem: '<Root>/Send states and measurements'

    // InitializeConditions for Memory: '<Root>/Initial States'
    for (i = 0; i < 5; i++) {
      rtDWork.InitialStates_PreviousInput[i] = rtConstP.InitialStates_X0[i];
    }

    // End of InitializeConditions for Memory: '<Root>/Initial States'

    // InitializeConditions for Memory: '<Root>/Initial P'
    memcpy(&rtDWork.InitialP_PreviousInput[0], &rtConstP.InitialP_X0[0], 25U *
           sizeof(real_T));
  }
}

// Model terminate function
void sensorfusionModelClass::terminate()
{
  // Terminate for Atomic SubSystem: '<S1>/Subscribe'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S5>/SourceBlock'

  if (rtDWork.obj_po.isInitialized == 1) {
    rtDWork.obj_po.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<S1>/Subscribe'

  // Terminate for Enabled SubSystem: '<Root>/Time update'
  // Start for MATLABSystem: '<S4>/Get T' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get T'

  if (rtDWork.obj.isInitialized == 1) {
    rtDWork.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get T'
  // End of Terminate for SubSystem: '<Root>/Time update'

  // Terminate for Enabled SubSystem: '<Root>/Measurement update'
  // Start for MATLABSystem: '<S2>/get R acc [1,1]' incorporates:
  //   Terminate for MATLABSystem: '<S2>/get R acc [1,1]'

  if (rtDWork.obj_m.isInitialized == 1) {
    rtDWork.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/get R acc [1,1]'

  // Start for MATLABSystem: '<S2>/get R acc[2,2]' incorporates:
  //   Terminate for MATLABSystem: '<S2>/get R acc[2,2]'

  if (rtDWork.obj_h.isInitialized == 1) {
    rtDWork.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/get R acc[2,2]'

  // Start for MATLABSystem: '<S2>/get R acc [3,3]' incorporates:
  //   Terminate for MATLABSystem: '<S2>/get R acc [3,3]'

  if (rtDWork.obj_mc.isInitialized == 1) {
    rtDWork.obj_mc.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/get R acc [3,3]'

  // Start for MATLABSystem: '<S2>/get R mag [1,1]' incorporates:
  //   Terminate for MATLABSystem: '<S2>/get R mag [1,1]'

  if (rtDWork.obj_i.isInitialized == 1) {
    rtDWork.obj_i.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/get R mag [1,1]'

  // Start for MATLABSystem: '<S2>/get R mag [2,2]' incorporates:
  //   Terminate for MATLABSystem: '<S2>/get R mag [2,2]'

  if (rtDWork.obj_k.isInitialized == 1) {
    rtDWork.obj_k.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/get R mag [2,2]'

  // Start for MATLABSystem: '<S2>/get R mag [3,3]' incorporates:
  //   Terminate for MATLABSystem: '<S2>/get R mag [3,3]'

  if (rtDWork.obj_p.isInitialized == 1) {
    rtDWork.obj_p.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/get R mag [3,3]'

  // Start for MATLABSystem: '<S2>/Get eps acc' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get eps acc'

  if (rtDWork.obj_b.isInitialized == 1) {
    rtDWork.obj_b.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get eps acc'

  // Start for MATLABSystem: '<S2>/Get eps mag' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get eps mag'

  if (rtDWork.obj_f.isInitialized == 1) {
    rtDWork.obj_f.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get eps mag'

  // Start for MATLABSystem: '<S2>/Get gravitational constant' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get gravitational constant'

  if (rtDWork.obj_c.isInitialized == 1) {
    rtDWork.obj_c.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get gravitational constant'

  // Start for MATLABSystem: '<S2>/Get water density' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get water density'

  if (rtDWork.obj_e.isInitialized == 1) {
    rtDWork.obj_e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get water density'

  // Start for MATLABSystem: '<S2>/Get x offset of  pressure sensor' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get x offset of  pressure sensor'

  if (rtDWork.obj_hb.isInitialized == 1) {
    rtDWork.obj_hb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get x offset of  pressure sensor'

  // Start for MATLABSystem: '<S2>/enable acc' incorporates:
  //   Terminate for MATLABSystem: '<S2>/enable acc'

  if (rtDWork.obj_l.isInitialized == 1) {
    rtDWork.obj_l.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/enable acc'

  // Start for MATLABSystem: '<S2>/enable mag' incorporates:
  //   Terminate for MATLABSystem: '<S2>/enable mag'

  if (rtDWork.obj_ls.isInitialized == 1) {
    rtDWork.obj_ls.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/enable mag'

  // Start for MATLABSystem: '<S2>/enable pressure' incorporates:
  //   Terminate for MATLABSystem: '<S2>/enable pressure'

  if (rtDWork.obj_mh.isInitialized == 1) {
    rtDWork.obj_mh.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/enable pressure'

  // Start for MATLABSystem: '<S2>/get R pressure [1,1]' incorporates:
  //   Terminate for MATLABSystem: '<S2>/get R pressure [1,1]'

  if (rtDWork.obj_g.isInitialized == 1) {
    rtDWork.obj_g.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/get R pressure [1,1]'
  // End of Terminate for SubSystem: '<Root>/Measurement update'

  // Terminate for Enabled SubSystem: '<Root>/Send states and measurements'
  // Terminate for Atomic SubSystem: '<S3>/Publish'
  // Start for MATLABSystem: '<S10>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S10>/SinkBlock'

  if (rtDWork.obj_ic.isInitialized == 1) {
    rtDWork.obj_ic.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S10>/SinkBlock'
  // End of Terminate for SubSystem: '<S3>/Publish'
  // End of Terminate for SubSystem: '<Root>/Send states and measurements'
}

// Constructor
sensorfusionModelClass::sensorfusionModelClass()
{
}

// Destructor
sensorfusionModelClass::~sensorfusionModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL * sensorfusionModelClass::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
