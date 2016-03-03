//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: sensorfusion_types.h
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
#ifndef RTW_HEADER_sensorfusion_types_h_
#define RTW_HEADER_sensorfusion_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_sensorfusion_std_msgs_MultiArrayDimension_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_sensorfusion_std_msgs_MultiArrayDimension_

// MsgType=std_msgs/MultiArrayDimension
typedef struct {
  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=Label_SL_Info:TruncateAction=warn 
  uint8_T Label[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Label
  SL_Bus_ROSVariableLengthArrayInfo Label_SL_Info;
  uint32_T Size;
  uint32_T Stride;
} SL_Bus_sensorfusion_std_msgs_MultiArrayDimension;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_sensorfusion_std_msgs_MultiArrayLayout_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_sensorfusion_std_msgs_MultiArrayLayout_

// MsgType=std_msgs/MultiArrayLayout
typedef struct {
  uint32_T DataOffset;

  // MsgType=std_msgs/MultiArrayDimension:IsVarLen=1:VarLenCategory=data:VarLenElem=Dim_SL_Info:TruncateAction=warn 
  SL_Bus_sensorfusion_std_msgs_MultiArrayDimension Dim[16];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Dim
  SL_Bus_ROSVariableLengthArrayInfo Dim_SL_Info;
} SL_Bus_sensorfusion_std_msgs_MultiArrayLayout;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_sensorfusion_std_msgs_Float32MultiArray_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_sensorfusion_std_msgs_Float32MultiArray_

// MsgType=std_msgs/Float32MultiArray
typedef struct {
  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  real32_T Data[10];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;

  // MsgType=std_msgs/MultiArrayLayout
  SL_Bus_sensorfusion_std_msgs_MultiArrayLayout Layout;
} SL_Bus_sensorfusion_std_msgs_Float32MultiArray;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_sensorfusion_std_msgs_Float64MultiArray_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_sensorfusion_std_msgs_Float64MultiArray_

// MsgType=std_msgs/Float64MultiArray
typedef struct {
  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  real_T Data[10];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;

  // MsgType=std_msgs/MultiArrayLayout
  SL_Bus_sensorfusion_std_msgs_MultiArrayLayout Layout;
} SL_Bus_sensorfusion_std_msgs_Float64MultiArray;

#endif

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_block_S
#define typedef_robotics_slros_internal_block_S

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_block_S;

#endif                                 //typedef_robotics_slros_internal_block_S

#ifndef struct_tag_sqJEGmxoWxi4N8y8xwSXwQD
#define struct_tag_sqJEGmxoWxi4N8y8xwSXwQD

struct tag_sqJEGmxoWxi4N8y8xwSXwQD
{
  int32_T isInitialized;
  real_T SampleTime;
};

#endif                                 //struct_tag_sqJEGmxoWxi4N8y8xwSXwQD

#ifndef typedef_robotics_slros_internal_block_G
#define typedef_robotics_slros_internal_block_G

typedef struct tag_sqJEGmxoWxi4N8y8xwSXwQD robotics_slros_internal_block_G;

#endif                                 //typedef_robotics_slros_internal_block_G

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_block_P
#define typedef_robotics_slros_internal_block_P

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_block_P;

#endif                                 //typedef_robotics_slros_internal_block_P

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  char_T f0[4];
} struct_T;

#endif                                 //typedef_struct_T

#ifndef typedef_struct_T_i
#define typedef_struct_T_i

typedef struct {
  char_T f0[8];
} struct_T_i;

#endif                                 //typedef_struct_T_i

#ifndef typedef_struct_T_id
#define typedef_struct_T_id

typedef struct {
  char_T f0[7];
} struct_T_id;

#endif                                 //typedef_struct_T_id

#ifndef typedef_struct_T_idu
#define typedef_struct_T_idu

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_idu;

#endif                                 //typedef_struct_T_idu

#ifndef typedef_struct_T_iduq
#define typedef_struct_T_iduq

typedef struct {
  char_T f0[5];
  char_T f1[4];
  char_T f2[6];
  char_T f3[5];
  char_T f4[6];
  char_T f5[5];
  char_T f6[6];
  char_T f7[6];
} struct_T_iduq;

#endif                                 //typedef_struct_T_iduq

#ifndef typedef_struct_T_iduq0
#define typedef_struct_T_iduq0

typedef struct {
  char_T f0[8];
  char_T f1[4];
  char_T f2[6];
} struct_T_iduq0;

#endif                                 //typedef_struct_T_iduq0

#ifndef typedef_struct_T_iduq0o
#define typedef_struct_T_iduq0o

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
} struct_T_iduq0o;

#endif                                 //typedef_struct_T_iduq0o

#ifndef typedef_struct_T_iduq0o2
#define typedef_struct_T_iduq0o2

typedef struct {
  char_T f0[8];
  char_T f1[4];
  char_T f2[6];
  char_T f3[6];
  char_T f4[6];
} struct_T_iduq0o2;

#endif                                 //typedef_struct_T_iduq0o2

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

#endif                                 // RTW_HEADER_sensorfusion_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
