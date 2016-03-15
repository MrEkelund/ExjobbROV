//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Controller_types.h
//
// Code generated for Simulink model 'Controller'.
//
// Model version                  : 1.164
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Tue Mar 15 14:03:01 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Controller_types_h_
#define RTW_HEADER_Controller_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_geometry_msgs_Vector3_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_Controller_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_geometry_msgs_Twist_

typedef struct {
  SL_Bus_Controller_geometry_msgs_Vector3 Linear;
  SL_Bus_Controller_geometry_msgs_Vector3 Angular;
} SL_Bus_Controller_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_std_msgs_MultiArrayDimension_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_std_msgs_MultiArrayDimension_

typedef struct {
  uint8_T Label[128];
  SL_Bus_ROSVariableLengthArrayInfo Label_SL_Info;
  uint32_T Size;
  uint32_T Stride;
} SL_Bus_Controller_std_msgs_MultiArrayDimension;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_std_msgs_MultiArrayLayout_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_std_msgs_MultiArrayLayout_

typedef struct {
  uint32_T DataOffset;
  SL_Bus_Controller_std_msgs_MultiArrayDimension Dim[16];
  SL_Bus_ROSVariableLengthArrayInfo Dim_SL_Info;
} SL_Bus_Controller_std_msgs_MultiArrayLayout;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_std_msgs_Float64MultiArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_std_msgs_Float64MultiArray_

typedef struct {
  real_T Data[10];
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;
  SL_Bus_Controller_std_msgs_MultiArrayLayout Layout;
} SL_Bus_Controller_std_msgs_Float64MultiArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_std_msgs_UInt16MultiArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_std_msgs_UInt16MultiArray_

typedef struct {
  uint16_T Data[6];
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;
  SL_Bus_Controller_std_msgs_MultiArrayLayout Layout;
} SL_Bus_Controller_std_msgs_UInt16MultiArray;

#endif

#ifndef struct_tag_sqJEGmxoWxi4N8y8xwSXwQD
#define struct_tag_sqJEGmxoWxi4N8y8xwSXwQD

struct tag_sqJEGmxoWxi4N8y8xwSXwQD
{
  int32_T isInitialized;
  real_T SampleTime;
};

#endif                                 //struct_tag_sqJEGmxoWxi4N8y8xwSXwQD

#ifndef typedef_robotics_slros_internal_block_T
#define typedef_robotics_slros_internal_block_T

typedef struct tag_sqJEGmxoWxi4N8y8xwSXwQD robotics_slros_internal_block_T;

#endif                                 //typedef_robotics_slros_internal_block_T

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_blo_l_T
#define typedef_robotics_slros_internal_blo_l_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_blo_l_T;

#endif                                 //typedef_robotics_slros_internal_blo_l_T

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_bl_l5_T
#define typedef_robotics_slros_internal_bl_l5_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_bl_l5_T;

#endif                                 //typedef_robotics_slros_internal_bl_l5_T

#ifndef typedef_struct_T_Controller_T
#define typedef_struct_T_Controller_T

typedef struct {
  char_T f0[4];
} struct_T_Controller_T;

#endif                                 //typedef_struct_T_Controller_T

#ifndef typedef_struct_T_Controller_l_T
#define typedef_struct_T_Controller_l_T

typedef struct {
  char_T f0[8];
} struct_T_Controller_l_T;

#endif                                 //typedef_struct_T_Controller_l_T

#ifndef typedef_struct_T_Controller_l5_T
#define typedef_struct_T_Controller_l5_T

typedef struct {
  char_T f0[7];
} struct_T_Controller_l5_T;

#endif                                 //typedef_struct_T_Controller_l5_T

#ifndef typedef_struct_T_Controller_l5x_T
#define typedef_struct_T_Controller_l5x_T

typedef struct {
  char_T f0[8];
  char_T f1[4];
  char_T f2[6];
} struct_T_Controller_l5x_T;

#endif                                 //typedef_struct_T_Controller_l5x_T

#ifndef typedef_struct_T_Controller_l5xx_T
#define typedef_struct_T_Controller_l5xx_T

typedef struct {
  char_T f0[5];
  char_T f1[4];
  char_T f2[6];
  char_T f3[5];
  char_T f4[6];
  char_T f5[5];
  char_T f6[6];
  char_T f7[6];
  char_T f8[7];
} struct_T_Controller_l5xx_T;

#endif                                 //typedef_struct_T_Controller_l5xx_T

#ifndef typedef_struct_T_Controller_l5xxx_T
#define typedef_struct_T_Controller_l5xxx_T

typedef struct {
  char_T f0[8];
  char_T f1[4];
  char_T f2[6];
  char_T f3[6];
} struct_T_Controller_l5xxx_T;

#endif                                 //typedef_struct_T_Controller_l5xxx_T

#ifndef typedef_struct_T_Controller_l5xxx5_T
#define typedef_struct_T_Controller_l5xxx5_T

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_Controller_l5xxx5_T;

#endif                                 //typedef_struct_T_Controller_l5xxx5_T

// Parameters (auto storage)
typedef struct Parameters_Controller_T_ Parameters_Controller_T;

// Forward declaration for rtModel
typedef struct tag_RTM_Controller_T RT_MODEL_Controller_T;

#endif                                 // RTW_HEADER_Controller_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
