//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Controller_with_out_ref_types.h
//
// Code generated for Simulink model 'Controller_with_out_ref'.
//
// Model version                  : 1.68
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Tue Feb  9 13:39:08 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Controller_with_out_ref_types_h_
#define RTW_HEADER_Controller_with_out_ref_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_ros_time_Time_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_ros_time_Time_

typedef struct {
  int32_T Sec;
  int32_T Nsec;
} SL_Bus_Controller_with_out_ref_ros_time_Time;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_std_msgs_Header_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_std_msgs_Header_

typedef struct {
  uint32_T Seq;
  uint8_T FrameId[128];
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
  SL_Bus_Controller_with_out_ref_ros_time_Time Stamp;
} SL_Bus_Controller_with_out_ref_std_msgs_Header;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_mavros_msgs_ActuatorControl_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_mavros_msgs_ActuatorControl_

typedef struct {
  uint8_T GroupMix;
  real32_T Controls[8];
  SL_Bus_Controller_with_out_ref_std_msgs_Header Header;
} SL_Bus_Controller_with_out_ref_mavros_msgs_ActuatorControl;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_geometry_msgs_Vector3_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_geometry_msgs_Vector3_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_Controller_with_out_ref_geometry_msgs_Vector3;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_geometry_msgs_Twist_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_geometry_msgs_Twist_

typedef struct {
  SL_Bus_Controller_with_out_ref_geometry_msgs_Vector3 Linear;
  SL_Bus_Controller_with_out_ref_geometry_msgs_Vector3 Angular;
} SL_Bus_Controller_with_out_ref_geometry_msgs_Twist;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_geometry_msgs_Quaternion_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_geometry_msgs_Quaternion_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_Controller_with_out_ref_geometry_msgs_Quaternion;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_sensor_msgs_Imu_
#define _DEFINED_TYPEDEF_FOR_SL_Bus_Controller_with_out_ref_sensor_msgs_Imu_

typedef struct {
  real_T OrientationCovariance[9];
  real_T AngularVelocityCovariance[9];
  real_T LinearAccelerationCovariance[9];
  SL_Bus_Controller_with_out_ref_std_msgs_Header Header;
  SL_Bus_Controller_with_out_ref_geometry_msgs_Quaternion Orientation;
  SL_Bus_Controller_with_out_ref_geometry_msgs_Vector3 AngularVelocity;
  SL_Bus_Controller_with_out_ref_geometry_msgs_Vector3 LinearAcceleration;
} SL_Bus_Controller_with_out_ref_sensor_msgs_Imu;

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

#ifndef typedef_robotics_slros_internal_blo_i_T
#define typedef_robotics_slros_internal_blo_i_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_blo_i_T;

#endif                                 //typedef_robotics_slros_internal_blo_i_T

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_bl_i2_T
#define typedef_robotics_slros_internal_bl_i2_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_bl_i2_T;

#endif                                 //typedef_robotics_slros_internal_bl_i2_T

#ifndef typedef_struct_T_Controller_with_out__T
#define typedef_struct_T_Controller_with_out__T

typedef struct {
  char_T f0[4];
} struct_T_Controller_with_out__T;

#endif                                 //typedef_struct_T_Controller_with_out__T

#ifndef typedef_struct_T_Controller_with_ou_i_T
#define typedef_struct_T_Controller_with_ou_i_T

typedef struct {
  char_T f0[8];
} struct_T_Controller_with_ou_i_T;

#endif                                 //typedef_struct_T_Controller_with_ou_i_T

#ifndef typedef_struct_T_Controller_with_o_i2_T
#define typedef_struct_T_Controller_with_o_i2_T

typedef struct {
  char_T f0[5];
  char_T f1[4];
  char_T f2[6];
  char_T f3[5];
  char_T f4[6];
  char_T f5[5];
  char_T f6[6];
  char_T f7[6];
} struct_T_Controller_with_o_i2_T;

#endif                                 //typedef_struct_T_Controller_with_o_i2_T

#ifndef typedef_struct_T_Controller_with__i2y_T
#define typedef_struct_T_Controller_with__i2y_T

typedef struct {
  char_T f0[7];
} struct_T_Controller_with__i2y_T;

#endif                                 //typedef_struct_T_Controller_with__i2y_T

#ifndef typedef_struct_T_Controller_with_i2ya_T
#define typedef_struct_T_Controller_with_i2ya_T

typedef struct {
  char_T f0[8];
  char_T f1[4];
  char_T f2[6];
} struct_T_Controller_with_i2ya_T;

#endif                                 //typedef_struct_T_Controller_with_i2ya_T

#ifndef typedef_struct_T_Controller_wit_i2yad_T
#define typedef_struct_T_Controller_wit_i2yad_T

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_Controller_wit_i2yad_T;

#endif                                 //typedef_struct_T_Controller_wit_i2yad_T

// Custom Type definition for MATLAB Function: '<S9>/Conversion'
#ifndef typedef_struct_T_Controller_with_ou_k_T
#define typedef_struct_T_Controller_with_ou_k_T

typedef struct {
  char_T f0[6];
  char_T f1[6];
} struct_T_Controller_with_ou_k_T;

#endif                                 //typedef_struct_T_Controller_with_ou_k_T

#ifndef typedef_b_struct_T_Controller_with_ou_T
#define typedef_b_struct_T_Controller_with_ou_T

typedef struct {
  char_T f0[8];
  char_T f1[4];
  char_T f2[2];
  char_T f3[5];
  real_T f4;
} b_struct_T_Controller_with_ou_T;

#endif                                 //typedef_b_struct_T_Controller_with_ou_T

// Parameters (auto storage)
typedef struct P_Controller_with_out_ref_T_ P_Controller_with_out_ref_T;

// Forward declaration for rtModel
typedef struct tag_RTM_Controller_with_out_r_T RT_MODEL_Controller_with_out__T;

#endif                                 // RTW_HEADER_Controller_with_out_ref_types_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
