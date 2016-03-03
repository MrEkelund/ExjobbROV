//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Controller_without_ref.h
//
// Code generated for Simulink model 'Controller_without_ref'.
//
// Model version                  : 1.144
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Thu Mar  3 12:17:05 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Controller_without_ref_h_
#define RTW_HEADER_Controller_without_ref_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Controller_without_ref_COMMON_INCLUDES_
# define Controller_without_ref_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // Controller_without_ref_COMMON_INCLUDES_ 

#include "Controller_without_ref_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  SL_Bus_Controller_without_ref_std_msgs_Int64MultiArray In1;// '<S36>/In1'
  SL_Bus_Controller_without_ref_std_msgs_Int64MultiArray varargout_2;
  SL_Bus_Controller_without_ref_std_msgs_UInt16MultiArray msg;// '<S9>/PWM assign' 
  real_T ctheta[9];
  real_T dv0[9];
  real_T b_x[9];
  SL_Bus_Controller_without_ref_geometry_msgs_Twist In1_m;// '<S11>/In1'
  SL_Bus_Controller_without_ref_geometry_msgs_Twist varargout_2_m;
  real_T ChooseControllersignal[6];    // '<Root>/Choose Controller signal'
  char_T cv0[42];
  char_T cv1[41];
  char_T cv2[39];
  char_T cv3[38];
  char_T cv4[36];
  char_T cv5[35];
  char_T cv6[30];
  char_T cv7[27];
  char_T cv8[25];
  real_T acc[3];
  real_T TmpSignalConversionAtDiscreteFi[2];
  real_T Gain;                         // '<S8>/Gain'
  real_T Gain1;                        // '<S8>/Gain1'
  real_T Gain2;                        // '<S8>/Gain2'
  real_T OutportBufferForaccXms2;      // '<S8>/removeGravity'
  real_T OutportBufferForaccYms2;      // '<S8>/removeGravity'
  real_T OutportBufferForaccZms2;      // '<S8>/removeGravity'
  real_T Saturate;                     // '<S18>/Saturate'
  real_T Saturate_f;                   // '<S21>/Saturate'
  real_T Saturate_i;                   // '<S24>/Saturate'
  real_T Saturate_b;                   // '<S27>/Saturate'
  real_T Saturate_h;                   // '<S30>/Saturate'
  real_T Saturate_bk;                  // '<S33>/Saturate'
  real_T X;
  real_T Y;
  real_T Z;
  real_T X_h;
  real_T Y_i;
  real_T Z_n;
  real_T Errorx;                       // '<S1>/Error x'
  real_T Errory;                       // '<S1>/Error y'
  real_T Errorz;                       // '<S1>/Error z'
  real_T Errorz8;                      // '<S1>/Error z8'
  real_T Errorz9;                      // '<S1>/Error z9'
  real_T Errorz10;                     // '<S1>/Error z10'
  real_T sfi;
  real_T cfi;
  real_T spsi;
  real_T cpsi;
  real_T stheta;
  real_T ctheta_c;
  real_T rtb_I_vel_z_k;
  real_T SignPreIntegrator;            // '<S35>/SignPreIntegrator'
  real_T SumI1;                        // '<S33>/SumI1'
  real_T NOut_b;                       // '<S27>/NOut'
  real_T NOut_i;                       // '<S30>/NOut'
  real_T NOut_d;                       // '<S33>/NOut'
  real_T Switch_e;                     // '<S27>/Switch'
} BlockIO_Controller_without_re_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  robotics_slros_internal_block_T obj; // '<S34>/P_vel_z'
  robotics_slros_internal_block_T obj_a;// '<S34>/D_vel_z'
  robotics_slros_internal_block_T obj_h;// '<S34>/N_vel_z '
  robotics_slros_internal_block_T obj_j;// '<S34>/I_vel_z'
  robotics_slros_internal_block_T obj_ji;// '<S31>/P_vel_y'
  robotics_slros_internal_block_T obj_n;// '<S31>/D_vel_y'
  robotics_slros_internal_block_T obj_c;// '<S31>/N_vel_y '
  robotics_slros_internal_block_T obj_jx;// '<S31>/I_vel_y'
  robotics_slros_internal_block_T obj_ns;// '<S28>/P_vel_x'
  robotics_slros_internal_block_T obj_d;// '<S28>/D_vel_x'
  robotics_slros_internal_block_T obj_a3;// '<S28>/N_vel_x '
  robotics_slros_internal_block_T obj_cv;// '<S28>/I_vel_x'
  robotics_slros_internal_block_T obj_e;// '<S25>/P_angular_vel_z'
  robotics_slros_internal_block_T obj_jg;// '<S25>/D_angular_vel_z'
  robotics_slros_internal_block_T obj_g;// '<S25>/N_angular_vel_z '
  robotics_slros_internal_block_T obj_p;// '<S25>/I_angular_vel_z'
  robotics_slros_internal_block_T obj_b;// '<S22>/P_angular_vel_y'
  robotics_slros_internal_block_T obj_m;// '<S22>/D_angular_vel_y'
  robotics_slros_internal_block_T obj_dp;// '<S22>/N_angular_vel_y '
  robotics_slros_internal_block_T obj_ep;// '<S22>/I_angular_vel_y'
  robotics_slros_internal_block_T obj_bm;// '<S19>/P_angular_vel_x'
  robotics_slros_internal_block_T obj_be;// '<S19>/D_angular_vel_x'
  robotics_slros_internal_block_T obj_l;// '<S19>/N_angular_vel_x '
  robotics_slros_internal_block_T obj_pb;// '<S19>/I_angular_vel_x'
  robotics_slros_internal_block_T obj_g0;// '<S4>/Enable integration?'
  robotics_slros_internal_block_T obj_hx;// '<S4>/Get alpha'
  robotics_slros_internal_block_T obj_jl;// '<S2>/Get front strafe decouple'
  robotics_slros_internal_block_T obj_ec;// '<S2>/Get front forward decouple'
  robotics_slros_internal_block_T obj_nj;// '<S2>/Get front pitch bias'
  robotics_slros_internal_block_T obj_lo;// '<S2>/Get front vertical bias'
  robotics_slros_internal_block_T obj_ef;// '<S2>/Get buoyancy'
  robotics_slros_internal_block_T obj_nl;// '<Root>/Get controller type'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S4>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S4>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator2_DSTATE;// '<S4>/Discrete-Time Integrator2'
  real_T DiscreteFilter_denStates;     // '<S4>/Discrete Filter'
  real_T DiscreteFilter1_denStates;    // '<S4>/Discrete Filter1'
  real_T DiscreteFilter2_denStates;    // '<S4>/Discrete Filter2'
  real_T Integrator_DSTATE;            // '<S18>/Integrator'
  real_T Filter_DSTATE;                // '<S18>/Filter'
  real_T Integrator_DSTATE_h;          // '<S21>/Integrator'
  real_T Filter_DSTATE_c;              // '<S21>/Filter'
  real_T Integrator_DSTATE_a;          // '<S24>/Integrator'
  real_T Filter_DSTATE_f;              // '<S24>/Filter'
  real_T Integrator_DSTATE_f;          // '<S27>/Integrator'
  real_T Filter_DSTATE_a;              // '<S27>/Filter'
  real_T Integrator_DSTATE_n;          // '<S30>/Integrator'
  real_T Filter_DSTATE_g;              // '<S30>/Filter'
  real_T Integrator_DSTATE_ny;         // '<S33>/Integrator'
  real_T Filter_DSTATE_cw;             // '<S33>/Filter'
  real_T DiscreteFilter_tmp;           // '<S4>/Discrete Filter'
  real_T DiscreteFilter1_tmp;          // '<S4>/Discrete Filter1'
  real_T DiscreteFilter2_tmp;          // '<S4>/Discrete Filter2'
  void *SinkBlock_PWORK;               // '<S41>/SinkBlock'
  void *SourceBlock_PWORK;             // '<S7>/SourceBlock'
  void *P_vel_z_PWORK;                 // '<S34>/P_vel_z'
  void *D_vel_z_PWORK;                 // '<S34>/D_vel_z'
  void *N_vel_z_PWORK;                 // '<S34>/N_vel_z '
  void *I_vel_z_PWORK;                 // '<S34>/I_vel_z'
  void *P_vel_y_PWORK;                 // '<S31>/P_vel_y'
  void *D_vel_y_PWORK;                 // '<S31>/D_vel_y'
  void *N_vel_y_PWORK;                 // '<S31>/N_vel_y '
  void *I_vel_y_PWORK;                 // '<S31>/I_vel_y'
  void *P_vel_x_PWORK;                 // '<S28>/P_vel_x'
  void *D_vel_x_PWORK;                 // '<S28>/D_vel_x'
  void *N_vel_x_PWORK;                 // '<S28>/N_vel_x '
  void *I_vel_x_PWORK;                 // '<S28>/I_vel_x'
  void *P_angular_vel_z_PWORK;         // '<S25>/P_angular_vel_z'
  void *D_angular_vel_z_PWORK;         // '<S25>/D_angular_vel_z'
  void *N_angular_vel_z_PWORK;         // '<S25>/N_angular_vel_z '
  void *I_angular_vel_z_PWORK;         // '<S25>/I_angular_vel_z'
  void *P_angular_vel_y_PWORK;         // '<S22>/P_angular_vel_y'
  void *D_angular_vel_y_PWORK;         // '<S22>/D_angular_vel_y'
  void *N_angular_vel_y_PWORK;         // '<S22>/N_angular_vel_y '
  void *I_angular_vel_y_PWORK;         // '<S22>/I_angular_vel_y'
  void *P_angular_vel_x_PWORK;         // '<S19>/P_angular_vel_x'
  void *D_angular_vel_x_PWORK;         // '<S19>/D_angular_vel_x'
  void *N_angular_vel_x_PWORK;         // '<S19>/N_angular_vel_x '
  void *I_angular_vel_x_PWORK;         // '<S19>/I_angular_vel_x'
  void *SourceBlock_PWORK_f;           // '<S5>/SourceBlock'
  void *Enableintegration_PWORK;       // '<S4>/Enable integration?'
  void *Getalpha_PWORK;                // '<S4>/Get alpha'
  void *Getfrontstrafedecouple_PWORK;  // '<S2>/Get front strafe decouple'
  void *Getfrontforwarddecouple_PWORK; // '<S2>/Get front forward decouple'
  void *Getfrontpitchbias_PWORK;       // '<S2>/Get front pitch bias'
  void *Getfrontverticalbias_PWORK;    // '<S2>/Get front vertical bias'
  void *Getbuoyancy_PWORK;             // '<S2>/Get buoyancy'
  void *Getcontrollertype_PWORK;       // '<Root>/Get controller type'
  robotics_slros_internal_blo_o_T obj_k;// '<S7>/SourceBlock'
  robotics_slros_internal_blo_o_T obj_nf;// '<S5>/SourceBlock'
  robotics_slros_internal_bl_oe_T obj_pw;// '<S41>/SinkBlock'
  boolean_T objisempty;                // '<S41>/SinkBlock'
  boolean_T objisempty_i;              // '<S7>/SourceBlock'
  boolean_T objisempty_l;              // '<S34>/P_vel_z'
  boolean_T objisempty_n;              // '<S34>/D_vel_z'
  boolean_T objisempty_e;              // '<S34>/N_vel_z '
  boolean_T objisempty_n4;             // '<S34>/I_vel_z'
  boolean_T objisempty_ej;             // '<S31>/P_vel_y'
  boolean_T objisempty_c;              // '<S31>/D_vel_y'
  boolean_T objisempty_b;              // '<S31>/N_vel_y '
  boolean_T objisempty_m;              // '<S31>/I_vel_y'
  boolean_T objisempty_a;              // '<S28>/P_vel_x'
  boolean_T objisempty_d;              // '<S28>/D_vel_x'
  boolean_T objisempty_il;             // '<S28>/N_vel_x '
  boolean_T objisempty_p;              // '<S28>/I_vel_x'
  boolean_T objisempty_h;              // '<S25>/P_angular_vel_z'
  boolean_T objisempty_if;             // '<S25>/D_angular_vel_z'
  boolean_T objisempty_m1;             // '<S25>/N_angular_vel_z '
  boolean_T objisempty_k;              // '<S25>/I_angular_vel_z'
  boolean_T objisempty_j;              // '<S22>/P_angular_vel_y'
  boolean_T objisempty_h1;             // '<S22>/D_angular_vel_y'
  boolean_T objisempty_ex;             // '<S22>/N_angular_vel_y '
  boolean_T objisempty_ef;             // '<S22>/I_angular_vel_y'
  boolean_T objisempty_f;              // '<S19>/P_angular_vel_x'
  boolean_T objisempty_g;              // '<S19>/D_angular_vel_x'
  boolean_T objisempty_d0;             // '<S19>/N_angular_vel_x '
  boolean_T objisempty_mb;             // '<S19>/I_angular_vel_x'
  boolean_T objisempty_gn;             // '<S5>/SourceBlock'
  boolean_T objisempty_lj;             // '<S4>/Enable integration?'
  boolean_T objisempty_g0;             // '<S4>/Get alpha'
  boolean_T objisempty_o;              // '<S2>/Get front strafe decouple'
  boolean_T objisempty_fw;             // '<S2>/Get front forward decouple'
  boolean_T objisempty_jf;             // '<S2>/Get front pitch bias'
  boolean_T objisempty_b1;             // '<S2>/Get front vertical bias'
  boolean_T objisempty_bb;             // '<S2>/Get buoyancy'
  boolean_T objisempty_m0;             // '<Root>/Get controller type'
} D_Work_Controller_without_ref_T;

// Parameters (auto storage)
struct Parameters_Controller_without_T_ {
  real_T PIDController_Kt;             // Mask Parameter: PIDController_Kt
                                       //  Referenced by: '<S18>/Kt'

  real_T PIDController_Kt_j;           // Mask Parameter: PIDController_Kt_j
                                       //  Referenced by: '<S21>/Kt'

  real_T PIDController_Kt_p;           // Mask Parameter: PIDController_Kt_p
                                       //  Referenced by: '<S24>/Kt'

  real_T PIDController_Kt_jw;          // Mask Parameter: PIDController_Kt_jw
                                       //  Referenced by: '<S27>/Kt'

  real_T PIDController_Kt_c;           // Mask Parameter: PIDController_Kt_c
                                       //  Referenced by: '<S30>/Kt'

  real_T PIDController_Kt_l;           // Mask Parameter: PIDController_Kt_l
                                       //  Referenced by: '<S33>/Kt'

  real_T PIDController_LowerSaturationLi;// Mask Parameter: PIDController_LowerSaturationLi
                                         //  Referenced by:
                                         //    '<S18>/Saturate'
                                         //    '<S20>/DeadZone'

  real_T PIDController_LowerSaturation_e;// Mask Parameter: PIDController_LowerSaturation_e
                                         //  Referenced by:
                                         //    '<S21>/Saturate'
                                         //    '<S23>/DeadZone'

  real_T PIDController_LowerSaturation_p;// Mask Parameter: PIDController_LowerSaturation_p
                                         //  Referenced by:
                                         //    '<S24>/Saturate'
                                         //    '<S26>/DeadZone'

  real_T PIDController_LowerSaturation_i;// Mask Parameter: PIDController_LowerSaturation_i
                                         //  Referenced by:
                                         //    '<S27>/Saturate'
                                         //    '<S29>/DeadZone'

  real_T PIDController_LowerSaturation_g;// Mask Parameter: PIDController_LowerSaturation_g
                                         //  Referenced by:
                                         //    '<S30>/Saturate'
                                         //    '<S32>/DeadZone'

  real_T PIDController_LowerSaturatio_pm;// Mask Parameter: PIDController_LowerSaturatio_pm
                                         //  Referenced by:
                                         //    '<S33>/Saturate'
                                         //    '<S35>/DeadZone'

  real_T PIDController_UpperSaturationLi;// Mask Parameter: PIDController_UpperSaturationLi
                                         //  Referenced by:
                                         //    '<S18>/Saturate'
                                         //    '<S20>/DeadZone'

  real_T PIDController_UpperSaturation_o;// Mask Parameter: PIDController_UpperSaturation_o
                                         //  Referenced by:
                                         //    '<S21>/Saturate'
                                         //    '<S23>/DeadZone'

  real_T PIDController_UpperSaturation_e;// Mask Parameter: PIDController_UpperSaturation_e
                                         //  Referenced by:
                                         //    '<S24>/Saturate'
                                         //    '<S26>/DeadZone'

  real_T PIDController_UpperSaturation_d;// Mask Parameter: PIDController_UpperSaturation_d
                                         //  Referenced by:
                                         //    '<S27>/Saturate'
                                         //    '<S29>/DeadZone'

  real_T PIDController_UpperSaturation_b;// Mask Parameter: PIDController_UpperSaturation_b
                                         //  Referenced by:
                                         //    '<S30>/Saturate'
                                         //    '<S32>/DeadZone'

  real_T PIDController_UpperSaturatio_ba;// Mask Parameter: PIDController_UpperSaturatio_ba
                                         //  Referenced by:
                                         //    '<S33>/Saturate'
                                         //    '<S35>/DeadZone'

  SL_Bus_Controller_without_ref_std_msgs_Int64MultiArray Out1_Y0;// Computed Parameter: Out1_Y0
                                                                 //  Referenced by: '<S36>/Out1'

  SL_Bus_Controller_without_ref_std_msgs_Int64MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S7>/Constant'

  SL_Bus_Controller_without_ref_std_msgs_UInt16MultiArray Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                                      //  Referenced by: '<S38>/Constant'

  SL_Bus_Controller_without_ref_geometry_msgs_Twist Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                                              //  Referenced by: '<S11>/Out1'

  SL_Bus_Controller_without_ref_geometry_msgs_Twist Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                     //  Referenced by: '<S5>/Constant'

  real_T Constant4_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant4'

  real_T Getcontrollertype_SampleTime; // Expression: SampleTime
                                       //  Referenced by: '<Root>/Get controller type'

  real_T yawerrordegrees_Y0;           // Computed Parameter: yawerrordegrees_Y0
                                       //  Referenced by: '<S1>/yaw error [degrees]'

  real_T pitcherrordegrees_Y0;         // Computed Parameter: pitcherrordegrees_Y0
                                       //  Referenced by: '<S1>/pitch error [degrees]'

  real_T rollerrordegrees_Y0;          // Computed Parameter: rollerrordegrees_Y0
                                       //  Referenced by: '<S1>/roll error [degrees]'

  real_T angular_velxerrordegrees_Y0;  // Computed Parameter: angular_velxerrordegrees_Y0
                                       //  Referenced by: '<S1>/angular_vel x error [degrees]'

  real_T angular_velyerrordegrees_Y0;  // Computed Parameter: angular_velyerrordegrees_Y0
                                       //  Referenced by: '<S1>/angular_vel y error [degrees]'

  real_T angular_velzerrordegrees_Y0;  // Computed Parameter: angular_velzerrordegrees_Y0
                                       //  Referenced by: '<S1>/angular_vel z error [degrees]'

  real_T xerrorms_Y0;                  // Computed Parameter: xerrorms_Y0
                                       //  Referenced by: '<S1>/x error [m//s]'

  real_T yerrorm_Y0;                   // Computed Parameter: yerrorm_Y0
                                       //  Referenced by: '<S1>/y error [m]'

  real_T zerrorm_Y0;                   // Computed Parameter: zerrorm_Y0
                                       //  Referenced by: '<S1>/z error [m]'

  real_T velxerrorms_Y0;               // Computed Parameter: velxerrorms_Y0
                                       //  Referenced by: '<S1>/vel x error [m//s]'

  real_T velyerrorms_Y0;               // Computed Parameter: velyerrorms_Y0
                                       //  Referenced by: '<S1>/vel y error [m//s]'

  real_T velzerrorms_Y0;               // Computed Parameter: velzerrorms_Y0
                                       //  Referenced by: '<S1>/vel z error [m//s]'

  real_T accxerrorms_Y0;               // Computed Parameter: accxerrorms_Y0
                                       //  Referenced by: '<S1>/acc x error [m//s]'

  real_T accyerrorms_Y0;               // Computed Parameter: accyerrorms_Y0
                                       //  Referenced by: '<S1>/acc y error [m//s]'

  real_T acczerrorms_Y0;               // Computed Parameter: acczerrorms_Y0
                                       //  Referenced by: '<S1>/acc z error [m//s]'

  real_T Getbuoyancy_SampleTime;       // Expression: SampleTime
                                       //  Referenced by: '<S2>/Get buoyancy'

  real_T Getfrontverticalbias_SampleTime;// Expression: SampleTime
                                         //  Referenced by: '<S2>/Get front vertical bias'

  real_T Getfrontpitchbias_SampleTime; // Expression: SampleTime
                                       //  Referenced by: '<S2>/Get front pitch bias'

  real_T Getfrontforwarddecouple_SampleT;// Expression: SampleTime
                                         //  Referenced by: '<S2>/Get front forward decouple'

  real_T Getfrontstrafedecouple_SampleTi;// Expression: SampleTime
                                         //  Referenced by: '<S2>/Get front strafe decouple'

  real_T angular_velX_Y0;              // Computed Parameter: angular_velX_Y0
                                       //  Referenced by: '<S3>/<angular_vel X>'

  real_T angular_velY_Y0;              // Computed Parameter: angular_velY_Y0
                                       //  Referenced by: '<S3>/<angular_vel Y>'

  real_T angular_velZ_Y0;              // Computed Parameter: angular_velZ_Y0
                                       //  Referenced by: '<S3>/<angular_vel Z> '

  real_T velocityX_Y0;                 // Computed Parameter: velocityX_Y0
                                       //  Referenced by: '<S3>/<velocity X>'

  real_T veloctiyY_Y0;                 // Computed Parameter: veloctiyY_Y0
                                       //  Referenced by: '<S3>/<veloctiy Y>'

  real_T velocityZ_Y0;                 // Computed Parameter: velocityZ_Y0
                                       //  Referenced by: '<S3>/<velocity Z>'

  real_T Getalpha_SampleTime;          // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get alpha'

  real_T Enableintegration_SampleTime; // Expression: SampleTime
                                       //  Referenced by: '<S4>/Enable integration?'

  real_T I_angular_vel_x_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S19>/I_angular_vel_x'

  real_T N_angular_vel_x_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S19>/N_angular_vel_x '

  real_T D_angular_vel_x_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S19>/D_angular_vel_x'

  real_T P_angular_vel_x_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S19>/P_angular_vel_x'

  real_T I_angular_vel_y_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S22>/I_angular_vel_y'

  real_T N_angular_vel_y_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S22>/N_angular_vel_y '

  real_T D_angular_vel_y_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S22>/D_angular_vel_y'

  real_T P_angular_vel_y_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S22>/P_angular_vel_y'

  real_T I_angular_vel_z_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S25>/I_angular_vel_z'

  real_T N_angular_vel_z_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S25>/N_angular_vel_z '

  real_T D_angular_vel_z_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S25>/D_angular_vel_z'

  real_T P_angular_vel_z_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S25>/P_angular_vel_z'

  real_T I_vel_x_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S28>/I_vel_x'

  real_T N_vel_x_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S28>/N_vel_x '

  real_T D_vel_x_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S28>/D_vel_x'

  real_T P_vel_x_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S28>/P_vel_x'

  real_T I_vel_y_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S31>/I_vel_y'

  real_T N_vel_y_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S31>/N_vel_y '

  real_T D_vel_y_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S31>/D_vel_y'

  real_T P_vel_y_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S31>/P_vel_y'

  real_T I_vel_z_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S34>/I_vel_z'

  real_T N_vel_z_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S34>/N_vel_z '

  real_T D_vel_z_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S34>/D_vel_z'

  real_T P_vel_z_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S34>/P_vel_z'

  real_T velocitesangularxyzlinearxyz_Y0;// Computed Parameter: velocitesangularxyzlinearxyz_Y0
                                         //  Referenced by: '<S6>/velocites [angular xyz, linear xyz]'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                       //  Referenced by: '<S18>/Integrator'

  real_T Integrator_IC;                // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S18>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                       //  Referenced by: '<S18>/Filter'

  real_T Filter_IC;                    // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S18>/Filter'

  real_T ZeroGain_Gain;                // Expression: 0
                                       //  Referenced by: '<S20>/ZeroGain'

  real_T Constant_Value_k;             // Expression: 0
                                       //  Referenced by: '<S18>/Constant'

  real_T Integrator_gainval_c;         // Computed Parameter: Integrator_gainval_c
                                       //  Referenced by: '<S21>/Integrator'

  real_T Integrator_IC_o;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S21>/Integrator'

  real_T Filter_gainval_i;             // Computed Parameter: Filter_gainval_i
                                       //  Referenced by: '<S21>/Filter'

  real_T Filter_IC_n;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S21>/Filter'

  real_T ZeroGain_Gain_k;              // Expression: 0
                                       //  Referenced by: '<S23>/ZeroGain'

  real_T Constant_Value_m;             // Expression: 0
                                       //  Referenced by: '<S21>/Constant'

  real_T Integrator_gainval_n;         // Computed Parameter: Integrator_gainval_n
                                       //  Referenced by: '<S24>/Integrator'

  real_T Integrator_IC_d;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S24>/Integrator'

  real_T Filter_gainval_k;             // Computed Parameter: Filter_gainval_k
                                       //  Referenced by: '<S24>/Filter'

  real_T Filter_IC_c;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S24>/Filter'

  real_T ZeroGain_Gain_a;              // Expression: 0
                                       //  Referenced by: '<S26>/ZeroGain'

  real_T Constant_Value_f;             // Expression: 0
                                       //  Referenced by: '<S24>/Constant'

  real_T Integrator_gainval_j;         // Computed Parameter: Integrator_gainval_j
                                       //  Referenced by: '<S27>/Integrator'

  real_T Integrator_IC_e;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S27>/Integrator'

  real_T Filter_gainval_h;             // Computed Parameter: Filter_gainval_h
                                       //  Referenced by: '<S27>/Filter'

  real_T Filter_IC_j;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S27>/Filter'

  real_T ZeroGain_Gain_j;              // Expression: 0
                                       //  Referenced by: '<S29>/ZeroGain'

  real_T Constant_Value_m0;            // Expression: 0
                                       //  Referenced by: '<S27>/Constant'

  real_T Integrator_gainval_np;        // Computed Parameter: Integrator_gainval_np
                                       //  Referenced by: '<S30>/Integrator'

  real_T Integrator_IC_i;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S30>/Integrator'

  real_T Filter_gainval_h0;            // Computed Parameter: Filter_gainval_h0
                                       //  Referenced by: '<S30>/Filter'

  real_T Filter_IC_jx;                 // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S30>/Filter'

  real_T ZeroGain_Gain_jk;             // Expression: 0
                                       //  Referenced by: '<S32>/ZeroGain'

  real_T Constant_Value_p;             // Expression: 0
                                       //  Referenced by: '<S30>/Constant'

  real_T Integrator_gainval_m;         // Computed Parameter: Integrator_gainval_m
                                       //  Referenced by: '<S33>/Integrator'

  real_T Integrator_IC_m;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S33>/Integrator'

  real_T Filter_gainval_b;             // Computed Parameter: Filter_gainval_b
                                       //  Referenced by: '<S33>/Filter'

  real_T Filter_IC_p;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S33>/Filter'

  real_T ZeroGain_Gain_p;              // Expression: 0
                                       //  Referenced by: '<S35>/ZeroGain'

  real_T Constant_Value_l;             // Expression: 0
                                       //  Referenced by: '<S33>/Constant'

  real_T yawdegrees_Y0;                // Computed Parameter: yawdegrees_Y0
                                       //  Referenced by: '<S8>/<yaw [degrees]>'

  real_T pitchdegrees_Y0;              // Computed Parameter: pitchdegrees_Y0
                                       //  Referenced by: '<S8>/<pitch [degrees]>'

  real_T rolldegrees_Y0;               // Computed Parameter: rolldegrees_Y0
                                       //  Referenced by: '<S8>/<roll [degrees]>'

  real_T angular_velXdegreess_Y0;      // Computed Parameter: angular_velXdegreess_Y0
                                       //  Referenced by: '<S8>/<angular_vel X [degrees//s]>'

  real_T angular_velYdegreess_Y0;      // Computed Parameter: angular_velYdegreess_Y0
                                       //  Referenced by: '<S8>/<angular_vel Y [degrees//s]>'

  real_T angular_velZdegreess_Y0;      // Computed Parameter: angular_velZdegreess_Y0
                                       //  Referenced by: '<S8>/<angular_vel Z [degrees//s]>'

  real_T Zm_Y0;                        // Computed Parameter: Zm_Y0
                                       //  Referenced by: '<S8>/<Z [m]>'

  real_T accXms2_Y0;                   // Computed Parameter: accXms2_Y0
                                       //  Referenced by: '<S8>/<acc X [m//s^2]>'

  real_T accYms2_Y0;                   // Computed Parameter: accYms2_Y0
                                       //  Referenced by: '<S8>/<acc Y [m//s^2]>'

  real_T accZms2_Y0;                   // Computed Parameter: accZms2_Y0
                                       //  Referenced by: '<S8>/<acc Z [m//s^2]>'

  real_T Gain_Gain;                    // Expression: 180/pi
                                       //  Referenced by: '<S8>/Gain'

  real_T Gain1_Gain;                   // Expression: -180/pi
                                       //  Referenced by: '<S8>/Gain1'

  real_T Gain2_Gain;                   // Expression: -180/pi
                                       //  Referenced by: '<S8>/Gain2'

  real_T Saturation_UpperSat;          // Expression: 1
                                       //  Referenced by: '<S9>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -1
                                       //  Referenced by: '<S9>/Saturation'

  real_T DiscreteTimeIntegrator_gainval;// Computed Parameter: DiscreteTimeIntegrator_gainval
                                        //  Referenced by: '<S4>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                       //  Referenced by: '<S4>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator1_gainval;// Computed Parameter: DiscreteTimeIntegrator1_gainval
                                         //  Referenced by: '<S4>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                       //  Referenced by: '<S4>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator2_gainval;// Computed Parameter: DiscreteTimeIntegrator2_gainval
                                         //  Referenced by: '<S4>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_IC;   // Expression: 0
                                       //  Referenced by: '<S4>/Discrete-Time Integrator2'

  real_T Constant_Value_a;             // Expression: 1
                                       //  Referenced by: '<S4>/Constant'

  real_T DiscreteFilter_NumCoef;       // Expression: [1]
                                       //  Referenced by: '<S4>/Discrete Filter'

  real_T DiscreteFilter_InitialStates; // Expression: 0
                                       //  Referenced by: '<S4>/Discrete Filter'

  real_T DiscreteFilter_InitialDenominat;// Expression: 0
                                         //  Referenced by: '<S4>/Discrete Filter'

  real_T DiscreteFilter1_NumCoef;      // Expression: [1]
                                       //  Referenced by: '<S4>/Discrete Filter1'

  real_T DiscreteFilter1_InitialStates;// Expression: 0
                                       //  Referenced by: '<S4>/Discrete Filter1'

  real_T DiscreteFilter1_InitialDenomina;// Expression: 0
                                         //  Referenced by: '<S4>/Discrete Filter1'

  real_T DiscreteFilter2_NumCoef;      // Expression: [1]
                                       //  Referenced by: '<S4>/Discrete Filter2'

  real_T DiscreteFilter2_InitialStates;// Expression: 0
                                       //  Referenced by: '<S4>/Discrete Filter2'

  real_T DiscreteFilter2_InitialDenomina;// Expression: 0
                                         //  Referenced by: '<S4>/Discrete Filter2'

};

// Real-time Model Data Structure
struct tag_RTM_Controller_without_re_T {
  const char_T *errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Class declaration for model Controller_without_ref
class ControllerModelClass {
  // public data and function members
 public:
  // Model entry point functions

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  ControllerModelClass();

  // Destructor
  ~ControllerModelClass();

  // Real-Time Model get method
  RT_MODEL_Controller_without_r_T * getRTM();

  // private data and function members
 private:
  // Tunable parameters
  Parameters_Controller_without_T Controller_without_ref_P;

  // Block signals
  BlockIO_Controller_without_re_T Controller_without_ref_B;

  // Block states
  D_Work_Controller_without_ref_T Controller_without_ref_DWork;

  // Real-Time Model
  RT_MODEL_Controller_without_r_T Controller_without_ref_M;

  // private member function(s) for subsystem '<Root>'
  void Controller_without_ref_sind(real_T *x);
  void Controller_without_ref_cosd(real_T *x);
  void Controller_without_ref_inv(const real_T x[9], real_T y[9]);
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Controller_without_ref'
//  '<S1>'   : 'Controller_without_ref/Create errors'
//  '<S2>'   : 'Controller_without_ref/Decouple'
//  '<S3>'   : 'Controller_without_ref/Xbox_input'
//  '<S4>'   : 'Controller_without_ref/acc integration'
//  '<S5>'   : 'Controller_without_ref/cmd_vel'
//  '<S6>'   : 'Controller_without_ref/decController'
//  '<S7>'   : 'Controller_without_ref/imu_data'
//  '<S8>'   : 'Controller_without_ref/states'
//  '<S9>'   : 'Controller_without_ref/toPWM'
//  '<S10>'  : 'Controller_without_ref/Decouple/MATLAB Function'
//  '<S11>'  : 'Controller_without_ref/cmd_vel/Enabled Subsystem'
//  '<S12>'  : 'Controller_without_ref/decController/angular_vel x'
//  '<S13>'  : 'Controller_without_ref/decController/angular_vel y'
//  '<S14>'  : 'Controller_without_ref/decController/angular_vel z'
//  '<S15>'  : 'Controller_without_ref/decController/vel x'
//  '<S16>'  : 'Controller_without_ref/decController/vel y'
//  '<S17>'  : 'Controller_without_ref/decController/vel z'
//  '<S18>'  : 'Controller_without_ref/decController/angular_vel x/PID Controller'
//  '<S19>'  : 'Controller_without_ref/decController/angular_vel x/Retrive PID-Parameters'
//  '<S20>'  : 'Controller_without_ref/decController/angular_vel x/PID Controller/Clamping circuit'
//  '<S21>'  : 'Controller_without_ref/decController/angular_vel y/PID Controller'
//  '<S22>'  : 'Controller_without_ref/decController/angular_vel y/Retrive PID-Parameters'
//  '<S23>'  : 'Controller_without_ref/decController/angular_vel y/PID Controller/Clamping circuit'
//  '<S24>'  : 'Controller_without_ref/decController/angular_vel z/PID Controller'
//  '<S25>'  : 'Controller_without_ref/decController/angular_vel z/Retrive PID-Parameters'
//  '<S26>'  : 'Controller_without_ref/decController/angular_vel z/PID Controller/Clamping circuit'
//  '<S27>'  : 'Controller_without_ref/decController/vel x/PID Controller'
//  '<S28>'  : 'Controller_without_ref/decController/vel x/Retrive PID-Parameters'
//  '<S29>'  : 'Controller_without_ref/decController/vel x/PID Controller/Clamping circuit'
//  '<S30>'  : 'Controller_without_ref/decController/vel y/PID Controller'
//  '<S31>'  : 'Controller_without_ref/decController/vel y/Retrive PID-Parameters'
//  '<S32>'  : 'Controller_without_ref/decController/vel y/PID Controller/Clamping circuit'
//  '<S33>'  : 'Controller_without_ref/decController/vel z/PID Controller'
//  '<S34>'  : 'Controller_without_ref/decController/vel z/Retrive PID-Parameters'
//  '<S35>'  : 'Controller_without_ref/decController/vel z/PID Controller/Clamping circuit'
//  '<S36>'  : 'Controller_without_ref/imu_data/Enabled Subsystem'
//  '<S37>'  : 'Controller_without_ref/states/removeGravity'
//  '<S38>'  : 'Controller_without_ref/toPWM/Actuator message '
//  '<S39>'  : 'Controller_without_ref/toPWM/Calc pwm signal'
//  '<S40>'  : 'Controller_without_ref/toPWM/PWM assign'
//  '<S41>'  : 'Controller_without_ref/toPWM/Publish'


//-
//  Requirements for '<Root>': Controller_without_ref

#endif                                 // RTW_HEADER_Controller_without_ref_h_

//
// File trailer for generated code.
//
// [EOF]
//
