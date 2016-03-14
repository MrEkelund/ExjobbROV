//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Controller.h
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
#ifndef RTW_HEADER_Controller_h_
#define RTW_HEADER_Controller_h_
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#ifndef Controller_COMMON_INCLUDES_
# define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "stdlib.h"
#endif                                 // Controller_COMMON_INCLUDES_

#include "Controller_types.h"
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

// Block signals for system '<S3>/MATLAB Function'
typedef struct {
  real_T thrusters[6];                 // '<S3>/MATLAB Function'
  real_T rtu_control_signals[6];
} rtB_MATLABFunction_Controller_T;

// Block signals for system '<S15>/MATLAB Function'
typedef struct {
  real_T y;                            // '<S15>/MATLAB Function'
} rtB_MATLABFunction_Controll_n_T;

// Block signals for system '<S15>/State Transition Table'
typedef struct {
  real_T u;                            // '<S15>/State Transition Table'
} rtB_StateTransitionTable_Cont_T;

// Block states (auto storage) for system '<S15>/State Transition Table'
typedef struct {
  uint8_T is_active_c6_Controller;     // '<S15>/State Transition Table'
  uint8_T is_c6_Controller;            // '<S15>/State Transition Table'
} rtDW_StateTransitionTable_Con_T;

// Block signals (auto storage)
typedef struct {
  SL_Bus_Controller_std_msgs_Float64MultiArray In1;// '<S58>/In1'
  SL_Bus_Controller_std_msgs_Float64MultiArray varargout_2;
  SL_Bus_Controller_std_msgs_UInt16MultiArray msg;// '<S12>/PWM assign'
  real_T state[35];
  real_T cpsi[9];
  SL_Bus_Controller_geometry_msgs_Twist In1_m;// '<S33>/In1'
  SL_Bus_Controller_geometry_msgs_Twist varargout_2_m;
  real_T ChooseControllersignal[6];    // '<Root>/Choose Controller signal'
  char_T cv0[38];
  char_T cv1[36];
  char_T cv2[35];
  char_T cv3[34];
  char_T cv4[30];
  char_T cv5[27];
  char_T cv6[25];
  real_T acc[3];
  char_T cv7[24];
  char_T cv8[22];
  char_T cv9[17];
  real_T TmpSignalConversionAtDiscreteFi[2];
  char_T cv10[9];
  int32_T ii[2];
  real_T OutportBufferForaccXms2;      // '<S11>/removeGravity'
  real_T OutportBufferForaccYms2;      // '<S11>/removeGravity'
  real_T OutportBufferForaccZms2;      // '<S11>/removeGravity'
  real_T X;
  real_T Y;
  real_T OutportBufferForangular_velZdeg;
  real_T Saturate;                     // '<S40>/Saturate'
  real_T Saturate_f;                   // '<S43>/Saturate'
  real_T Saturate_i;                   // '<S46>/Saturate'
  real_T Saturate_b;                   // '<S49>/Saturate'
  real_T Saturate_h;                   // '<S52>/Saturate'
  real_T Saturate_bk;                  // '<S55>/Saturate'
  real_T X_h;
  real_T Y_i;
  real_T Z;
  real_T X_hw;
  real_T Y_in;
  real_T Z_n;
  real_T OutportBufferForThrusters[6];
  real_T Errorx;                       // '<S2>/Error x'
  real_T Errory;                       // '<S2>/Error y'
  real_T Errorz;                       // '<S2>/Error z'
  real_T Errorz8;                      // '<S2>/Error z8'
  real_T Errorz9;                      // '<S2>/Error z9'
  real_T Errorz10;                     // '<S2>/Error z10'
  real_T cfi;
  real_T spsi;
  real_T cpsi_c;
  real_T stheta;
  real_T ctheta;
  real_T rtb_I_vel_z_k;
  real_T RandomSource;                 // '<S20>/Random Source'
  real_T SignPreIntegrator;            // '<S57>/SignPreIntegrator'
  real_T SumI1;                        // '<S55>/SumI1'
  real_T NOut_b;                       // '<S49>/NOut'
  real_T NOut_i;                       // '<S52>/NOut'
  real_T NOut_d;                       // '<S55>/NOut'
  real_T Switch_e;                     // '<S49>/Switch'
  real_T Switch_i;                     // '<S52>/Switch'
  real_T min;
  real_T max;
  real_T d;
  real_T b_x;
  real_T absx;
  real_T u1;
  real_T c_x;
  real_T absx_c;
  int32_T rtb_Gettest_b;
  int32_T rtb_Swtichingfactor_d_p;
  int32_T i;
  int32_T one;
  int32_T lsw;
  int32_T chan;
  int32_T samps;
  int32_T i_c;
  uint32_T j;
  int8_T rtb_DataTypeConv2_f;
  int8_T i0;
  int8_T n;
  int8_T n_g;
  boolean_T rtb_GetParameter3_g;
  boolean_T rtb_GetParameter4_m;
  boolean_T p;
  boolean_T p_n;
  boolean_T Compare;                   // '<S1>/Compare'
  boolean_T LogicalOperator;           // '<Root>/Logical Operator'
  boolean_T NotEqual;                  // '<S42>/NotEqual'
  rtB_StateTransitionTable_Cont_T sf_StateTransitionTable_o2;// '<S20>/State Transition Table' 
  rtB_MATLABFunction_Controll_n_T sf_MATLABFunction_i;// '<S20>/MATLAB Function' 
  rtB_StateTransitionTable_Cont_T sf_StateTransitionTable_o;// '<S19>/State Transition Table' 
  rtB_MATLABFunction_Controll_n_T sf_MATLABFunction_e;// '<S19>/MATLAB Function' 
  rtB_StateTransitionTable_Cont_T sf_StateTransitionTable_mx;// '<S18>/State Transition Table' 
  rtB_MATLABFunction_Controll_n_T sf_MATLABFunction_o;// '<S18>/MATLAB Function' 
  rtB_StateTransitionTable_Cont_T sf_StateTransitionTable_m;// '<S17>/State Transition Table' 
  rtB_MATLABFunction_Controll_n_T sf_MATLABFunction_j;// '<S17>/MATLAB Function' 
  rtB_StateTransitionTable_Cont_T sf_StateTransitionTable_i;// '<S16>/State Transition Table' 
  rtB_MATLABFunction_Controll_n_T sf_MATLABFunction_l;// '<S16>/MATLAB Function' 
  rtB_StateTransitionTable_Cont_T sf_StateTransitionTable;// '<S15>/State Transition Table' 
  rtB_MATLABFunction_Controll_n_T sf_MATLABFunction_a;// '<S15>/MATLAB Function' 
  rtB_MATLABFunction_Controller_T sf_MATLABFunction_b;// '<S4>/MATLAB Function'
  rtB_MATLABFunction_Controller_T sf_MATLABFunction;// '<S3>/MATLAB Function'
} BlockIO_Controller_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  robotics_slros_internal_block_T obj; // '<S62>/Get Parameter'
  robotics_slros_internal_block_T obj_l;// '<S62>/Get Parameter1'
  robotics_slros_internal_block_T obj_n;// '<S62>/Get Parameter2'
  robotics_slros_internal_block_T obj_c;// '<S62>/Get Parameter3'
  robotics_slros_internal_block_T obj_nt;// '<S62>/Get Parameter4'
  robotics_slros_internal_block_T obj_ls;// '<S62>/Get Parameter5'
  robotics_slros_internal_block_T obj_j;// '<S56>/P_vel_z'
  robotics_slros_internal_block_T obj_a;// '<S56>/D_vel_z'
  robotics_slros_internal_block_T obj_h;// '<S56>/N_vel_z '
  robotics_slros_internal_block_T obj_js;// '<S56>/I_vel_z'
  robotics_slros_internal_block_T obj_ji;// '<S53>/P_vel_y'
  robotics_slros_internal_block_T obj_ny;// '<S53>/D_vel_y'
  robotics_slros_internal_block_T obj_cb;// '<S53>/N_vel_y '
  robotics_slros_internal_block_T obj_jx;// '<S53>/I_vel_y'
  robotics_slros_internal_block_T obj_ns;// '<S50>/P_vel_x'
  robotics_slros_internal_block_T obj_d;// '<S50>/D_vel_x'
  robotics_slros_internal_block_T obj_a3;// '<S50>/N_vel_x '
  robotics_slros_internal_block_T obj_cv;// '<S50>/I_vel_x'
  robotics_slros_internal_block_T obj_e;// '<S47>/P_angular_vel_z'
  robotics_slros_internal_block_T obj_jg;// '<S47>/D_angular_vel_z'
  robotics_slros_internal_block_T obj_g;// '<S47>/N_angular_vel_z '
  robotics_slros_internal_block_T obj_p;// '<S47>/I_angular_vel_z'
  robotics_slros_internal_block_T obj_b;// '<S44>/P_angular_vel_y'
  robotics_slros_internal_block_T obj_m;// '<S44>/D_angular_vel_y'
  robotics_slros_internal_block_T obj_dp;// '<S44>/N_angular_vel_y '
  robotics_slros_internal_block_T obj_ep;// '<S44>/I_angular_vel_y'
  robotics_slros_internal_block_T obj_bm;// '<S41>/P_angular_vel_x'
  robotics_slros_internal_block_T obj_be;// '<S41>/D_angular_vel_x'
  robotics_slros_internal_block_T obj_lb;// '<S41>/N_angular_vel_x '
  robotics_slros_internal_block_T obj_pb;// '<S41>/I_angular_vel_x'
  robotics_slros_internal_block_T obj_g0;// '<S7>/Enable integration?'
  robotics_slros_internal_block_T obj_hx;// '<S7>/Get alpha'
  robotics_slros_internal_block_T obj_gf;// '<S20>/Swtiching factor'
  robotics_slros_internal_block_T obj_cvy;// '<S20>/Swtiching factor1'
  robotics_slros_internal_block_T obj_dt;// '<S20>/Swtiching factor2'
  robotics_slros_internal_block_T obj_j0;// '<S19>/Swtiching factor'
  robotics_slros_internal_block_T obj_hr;// '<S19>/Swtiching factor1'
  robotics_slros_internal_block_T obj_dn;// '<S19>/Swtiching factor2'
  robotics_slros_internal_block_T obj_gv;// '<S18>/Swtiching factor'
  robotics_slros_internal_block_T obj_c2;// '<S18>/Swtiching factor1'
  robotics_slros_internal_block_T obj_g0e;// '<S18>/Swtiching factor2'
  robotics_slros_internal_block_T obj_o;// '<S17>/Swtiching factor'
  robotics_slros_internal_block_T obj_f;// '<S17>/Swtiching factor1'
  robotics_slros_internal_block_T obj_mb;// '<S17>/Swtiching factor2'
  robotics_slros_internal_block_T obj_i;// '<S16>/Swtiching factor'
  robotics_slros_internal_block_T obj_j5;// '<S16>/Swtiching factor1'
  robotics_slros_internal_block_T obj_fu;// '<S16>/Swtiching factor2'
  robotics_slros_internal_block_T obj_of;// '<S15>/Swtiching factor'
  robotics_slros_internal_block_T obj_fx;// '<S15>/Swtiching factor1'
  robotics_slros_internal_block_T obj_d3;// '<S15>/Swtiching factor2'
  robotics_slros_internal_block_T obj_l0;// '<S4>/Get buoyancy'
  robotics_slros_internal_block_T obj_fe;// '<S3>/Get buoyancy'
  robotics_slros_internal_block_T obj_h2;// '<Root>/Get test'
  robotics_slros_internal_block_T obj_nl;// '<Root>/Get controller type'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S7>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S7>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator2_DSTATE;// '<S7>/Discrete-Time Integrator2'
  real_T DiscreteFilter_denStates;     // '<S7>/Discrete Filter'
  real_T DiscreteFilter1_denStates;    // '<S7>/Discrete Filter1'
  real_T DiscreteFilter2_denStates;    // '<S7>/Discrete Filter2'
  real_T Integrator_DSTATE;            // '<S40>/Integrator'
  real_T Filter_DSTATE;                // '<S40>/Filter'
  real_T Integrator_DSTATE_h;          // '<S43>/Integrator'
  real_T Filter_DSTATE_c;              // '<S43>/Filter'
  real_T Integrator_DSTATE_a;          // '<S46>/Integrator'
  real_T Filter_DSTATE_f;              // '<S46>/Filter'
  real_T Integrator_DSTATE_f;          // '<S49>/Integrator'
  real_T Filter_DSTATE_a;              // '<S49>/Filter'
  real_T Integrator_DSTATE_n;          // '<S52>/Integrator'
  real_T Filter_DSTATE_g;              // '<S52>/Filter'
  real_T Integrator_DSTATE_ny;         // '<S55>/Integrator'
  real_T Filter_DSTATE_cw;             // '<S55>/Filter'
  real_T DiscreteFilter_tmp;           // '<S7>/Discrete Filter'
  real_T DiscreteFilter1_tmp;          // '<S7>/Discrete Filter1'
  real_T DiscreteFilter2_tmp;          // '<S7>/Discrete Filter2'
  real_T RandomSource_STATE_DWORK[35]; // '<S15>/Random Source'
  real_T RandomSource_STATE_DWORK_i[35];// '<S16>/Random Source'
  real_T RandomSource_STATE_DWORK_a[35];// '<S17>/Random Source'
  real_T RandomSource_STATE_DWORK_g[35];// '<S18>/Random Source'
  real_T RandomSource_STATE_DWORK_j[35];// '<S19>/Random Source'
  real_T RandomSource_STATE_DWORK_h[35];// '<S20>/Random Source'
  void *SinkBlock_PWORK;               // '<S64>/SinkBlock'
  void *GetParameter_PWORK;            // '<S62>/Get Parameter'
  void *GetParameter1_PWORK;           // '<S62>/Get Parameter1'
  void *GetParameter2_PWORK;           // '<S62>/Get Parameter2'
  void *GetParameter3_PWORK;           // '<S62>/Get Parameter3'
  void *GetParameter4_PWORK;           // '<S62>/Get Parameter4'
  void *GetParameter5_PWORK;           // '<S62>/Get Parameter5'
  void *SourceBlock_PWORK;             // '<S10>/SourceBlock'
  void *P_vel_z_PWORK;                 // '<S56>/P_vel_z'
  void *D_vel_z_PWORK;                 // '<S56>/D_vel_z'
  void *N_vel_z_PWORK;                 // '<S56>/N_vel_z '
  void *I_vel_z_PWORK;                 // '<S56>/I_vel_z'
  void *P_vel_y_PWORK;                 // '<S53>/P_vel_y'
  void *D_vel_y_PWORK;                 // '<S53>/D_vel_y'
  void *N_vel_y_PWORK;                 // '<S53>/N_vel_y '
  void *I_vel_y_PWORK;                 // '<S53>/I_vel_y'
  void *P_vel_x_PWORK;                 // '<S50>/P_vel_x'
  void *D_vel_x_PWORK;                 // '<S50>/D_vel_x'
  void *N_vel_x_PWORK;                 // '<S50>/N_vel_x '
  void *I_vel_x_PWORK;                 // '<S50>/I_vel_x'
  void *P_angular_vel_z_PWORK;         // '<S47>/P_angular_vel_z'
  void *D_angular_vel_z_PWORK;         // '<S47>/D_angular_vel_z'
  void *N_angular_vel_z_PWORK;         // '<S47>/N_angular_vel_z '
  void *I_angular_vel_z_PWORK;         // '<S47>/I_angular_vel_z'
  void *P_angular_vel_y_PWORK;         // '<S44>/P_angular_vel_y'
  void *D_angular_vel_y_PWORK;         // '<S44>/D_angular_vel_y'
  void *N_angular_vel_y_PWORK;         // '<S44>/N_angular_vel_y '
  void *I_angular_vel_y_PWORK;         // '<S44>/I_angular_vel_y'
  void *P_angular_vel_x_PWORK;         // '<S41>/P_angular_vel_x'
  void *D_angular_vel_x_PWORK;         // '<S41>/D_angular_vel_x'
  void *N_angular_vel_x_PWORK;         // '<S41>/N_angular_vel_x '
  void *I_angular_vel_x_PWORK;         // '<S41>/I_angular_vel_x'
  void *SourceBlock_PWORK_f;           // '<S8>/SourceBlock'
  void *Enableintegration_PWORK;       // '<S7>/Enable integration?'
  void *Getalpha_PWORK;                // '<S7>/Get alpha'
  void *Swtichingfactor_PWORK;         // '<S20>/Swtiching factor'
  void *Swtichingfactor1_PWORK;        // '<S20>/Swtiching factor1'
  void *Swtichingfactor2_PWORK;        // '<S20>/Swtiching factor2'
  void *Swtichingfactor_PWORK_p;       // '<S19>/Swtiching factor'
  void *Swtichingfactor1_PWORK_n;      // '<S19>/Swtiching factor1'
  void *Swtichingfactor2_PWORK_f;      // '<S19>/Swtiching factor2'
  void *Swtichingfactor_PWORK_j;       // '<S18>/Swtiching factor'
  void *Swtichingfactor1_PWORK_d;      // '<S18>/Swtiching factor1'
  void *Swtichingfactor2_PWORK_h;      // '<S18>/Swtiching factor2'
  void *Swtichingfactor_PWORK_k;       // '<S17>/Swtiching factor'
  void *Swtichingfactor1_PWORK_k;      // '<S17>/Swtiching factor1'
  void *Swtichingfactor2_PWORK_p;      // '<S17>/Swtiching factor2'
  void *Swtichingfactor_PWORK_a;       // '<S16>/Swtiching factor'
  void *Swtichingfactor1_PWORK_c;      // '<S16>/Swtiching factor1'
  void *Swtichingfactor2_PWORK_i;      // '<S16>/Swtiching factor2'
  void *Swtichingfactor_PWORK_n;       // '<S15>/Swtiching factor'
  void *Swtichingfactor1_PWORK_l;      // '<S15>/Swtiching factor1'
  void *Swtichingfactor2_PWORK_l;      // '<S15>/Swtiching factor2'
  void *Getbuoyancy_PWORK;             // '<S4>/Get buoyancy'
  void *Getbuoyancy_PWORK_k;           // '<S3>/Get buoyancy'
  void *Gettest_PWORK;                 // '<Root>/Get test'
  void *Getcontrollertype_PWORK;       // '<Root>/Get controller type'
  uint32_T RandomSource_SEED_DWORK;    // '<S15>/Random Source'
  uint32_T RandomSource_SEED_DWORK_l;  // '<S16>/Random Source'
  uint32_T RandomSource_SEED_DWORK_c;  // '<S17>/Random Source'
  uint32_T RandomSource_SEED_DWORK_i;  // '<S18>/Random Source'
  uint32_T RandomSource_SEED_DWORK_k;  // '<S19>/Random Source'
  uint32_T RandomSource_SEED_DWORK_g;  // '<S20>/Random Source'
  robotics_slros_internal_blo_l_T obj_k;// '<S10>/SourceBlock'
  robotics_slros_internal_blo_l_T obj_nf;// '<S8>/SourceBlock'
  robotics_slros_internal_bl_l5_T obj_pw;// '<S64>/SinkBlock'
  boolean_T objisempty;                // '<S64>/SinkBlock'
  boolean_T objisempty_n;              // '<S62>/Get Parameter'
  boolean_T objisempty_p;              // '<S62>/Get Parameter1'
  boolean_T objisempty_l;              // '<S62>/Get Parameter2'
  boolean_T objisempty_n4;             // '<S62>/Get Parameter3'
  boolean_T objisempty_ns;             // '<S62>/Get Parameter4'
  boolean_T objisempty_a;              // '<S62>/Get Parameter5'
  boolean_T objisempty_i;              // '<S10>/SourceBlock'
  boolean_T objisempty_le;             // '<S56>/P_vel_z'
  boolean_T objisempty_nm;             // '<S56>/D_vel_z'
  boolean_T objisempty_e;              // '<S56>/N_vel_z '
  boolean_T objisempty_n43;            // '<S56>/I_vel_z'
  boolean_T objisempty_ej;             // '<S53>/P_vel_y'
  boolean_T objisempty_c;              // '<S53>/D_vel_y'
  boolean_T objisempty_b;              // '<S53>/N_vel_y '
  boolean_T objisempty_m;              // '<S53>/I_vel_y'
  boolean_T objisempty_a3;             // '<S50>/P_vel_x'
  boolean_T objisempty_d;              // '<S50>/D_vel_x'
  boolean_T objisempty_il;             // '<S50>/N_vel_x '
  boolean_T objisempty_pu;             // '<S50>/I_vel_x'
  boolean_T objisempty_h;              // '<S47>/P_angular_vel_z'
  boolean_T objisempty_if;             // '<S47>/D_angular_vel_z'
  boolean_T objisempty_m1;             // '<S47>/N_angular_vel_z '
  boolean_T objisempty_k;              // '<S47>/I_angular_vel_z'
  boolean_T objisempty_j;              // '<S44>/P_angular_vel_y'
  boolean_T objisempty_h1;             // '<S44>/D_angular_vel_y'
  boolean_T objisempty_ex;             // '<S44>/N_angular_vel_y '
  boolean_T objisempty_ef;             // '<S44>/I_angular_vel_y'
  boolean_T objisempty_f;              // '<S41>/P_angular_vel_x'
  boolean_T objisempty_g;              // '<S41>/D_angular_vel_x'
  boolean_T objisempty_d0;             // '<S41>/N_angular_vel_x '
  boolean_T objisempty_mb;             // '<S41>/I_angular_vel_x'
  boolean_T objisempty_gn;             // '<S8>/SourceBlock'
  boolean_T objisempty_lj;             // '<S7>/Enable integration?'
  boolean_T objisempty_g0;             // '<S7>/Get alpha'
  boolean_T objisempty_k1;             // '<S20>/Swtiching factor'
  boolean_T objisempty_gk;             // '<S20>/Swtiching factor1'
  boolean_T objisempty_kl;             // '<S20>/Swtiching factor2'
  boolean_T objisempty_fj;             // '<S19>/Swtiching factor'
  boolean_T objisempty_nl;             // '<S19>/Swtiching factor1'
  boolean_T objisempty_kk;             // '<S19>/Swtiching factor2'
  boolean_T objisempty_a3j;            // '<S18>/Swtiching factor'
  boolean_T objisempty_hv;             // '<S18>/Swtiching factor1'
  boolean_T objisempty_o;              // '<S18>/Swtiching factor2'
  boolean_T objisempty_ev;             // '<S17>/Swtiching factor'
  boolean_T objisempty_em;             // '<S17>/Swtiching factor1'
  boolean_T objisempty_ks;             // '<S17>/Swtiching factor2'
  boolean_T objisempty_mo;             // '<S16>/Swtiching factor'
  boolean_T objisempty_ng;             // '<S16>/Swtiching factor1'
  boolean_T objisempty_fp;             // '<S16>/Swtiching factor2'
  boolean_T objisempty_ls;             // '<S15>/Swtiching factor'
  boolean_T objisempty_jb;             // '<S15>/Swtiching factor1'
  boolean_T objisempty_jr;             // '<S15>/Swtiching factor2'
  boolean_T objisempty_ig;             // '<S4>/Get buoyancy'
  boolean_T objisempty_ct;             // '<S3>/Get buoyancy'
  boolean_T objisempty_pr;             // '<Root>/Get test'
  boolean_T objisempty_m0;             // '<Root>/Get controller type'
  rtDW_StateTransitionTable_Con_T sf_StateTransitionTable_o2;// '<S20>/State Transition Table' 
  rtDW_StateTransitionTable_Con_T sf_StateTransitionTable_o;// '<S19>/State Transition Table' 
  rtDW_StateTransitionTable_Con_T sf_StateTransitionTable_mx;// '<S18>/State Transition Table' 
  rtDW_StateTransitionTable_Con_T sf_StateTransitionTable_m;// '<S17>/State Transition Table' 
  rtDW_StateTransitionTable_Con_T sf_StateTransitionTable_i;// '<S16>/State Transition Table' 
  rtDW_StateTransitionTable_Con_T sf_StateTransitionTable;// '<S15>/State Transition Table' 
} D_Work_Controller_T;

// Parameters (auto storage)
struct Parameters_Controller_T_ {
  real_T PIDController_Kt;             // Mask Parameter: PIDController_Kt
                                       //  Referenced by: '<S40>/Kt'

  real_T PIDController_Kt_j;           // Mask Parameter: PIDController_Kt_j
                                       //  Referenced by: '<S43>/Kt'

  real_T PIDController_Kt_p;           // Mask Parameter: PIDController_Kt_p
                                       //  Referenced by: '<S46>/Kt'

  real_T PIDController_Kt_jw;          // Mask Parameter: PIDController_Kt_jw
                                       //  Referenced by: '<S49>/Kt'

  real_T PIDController_Kt_c;           // Mask Parameter: PIDController_Kt_c
                                       //  Referenced by: '<S52>/Kt'

  real_T PIDController_Kt_l;           // Mask Parameter: PIDController_Kt_l
                                       //  Referenced by: '<S55>/Kt'

  real_T PIDController_LowerSaturationLi;// Mask Parameter: PIDController_LowerSaturationLi
                                         //  Referenced by:
                                         //    '<S40>/Saturate'
                                         //    '<S42>/DeadZone'

  real_T PIDController_LowerSaturation_e;// Mask Parameter: PIDController_LowerSaturation_e
                                         //  Referenced by:
                                         //    '<S43>/Saturate'
                                         //    '<S45>/DeadZone'

  real_T PIDController_LowerSaturation_p;// Mask Parameter: PIDController_LowerSaturation_p
                                         //  Referenced by:
                                         //    '<S46>/Saturate'
                                         //    '<S48>/DeadZone'

  real_T PIDController_LowerSaturation_i;// Mask Parameter: PIDController_LowerSaturation_i
                                         //  Referenced by:
                                         //    '<S49>/Saturate'
                                         //    '<S51>/DeadZone'

  real_T PIDController_LowerSaturation_g;// Mask Parameter: PIDController_LowerSaturation_g
                                         //  Referenced by:
                                         //    '<S52>/Saturate'
                                         //    '<S54>/DeadZone'

  real_T PIDController_LowerSaturatio_pm;// Mask Parameter: PIDController_LowerSaturatio_pm
                                         //  Referenced by:
                                         //    '<S55>/Saturate'
                                         //    '<S57>/DeadZone'

  real_T RandomSource_MaxVal;          // Mask Parameter: RandomSource_MaxVal
                                       //  Referenced by: '<S15>/Random Source'

  real_T RandomSource_MaxVal_o;        // Mask Parameter: RandomSource_MaxVal_o
                                       //  Referenced by: '<S16>/Random Source'

  real_T RandomSource_MaxVal_g;        // Mask Parameter: RandomSource_MaxVal_g
                                       //  Referenced by: '<S17>/Random Source'

  real_T RandomSource_MaxVal_d;        // Mask Parameter: RandomSource_MaxVal_d
                                       //  Referenced by: '<S18>/Random Source'

  real_T RandomSource_MaxVal_n;        // Mask Parameter: RandomSource_MaxVal_n
                                       //  Referenced by: '<S19>/Random Source'

  real_T RandomSource_MaxVal_i;        // Mask Parameter: RandomSource_MaxVal_i
                                       //  Referenced by: '<S20>/Random Source'

  real_T RandomSource_MinVal;          // Mask Parameter: RandomSource_MinVal
                                       //  Referenced by: '<S15>/Random Source'

  real_T RandomSource_MinVal_h;        // Mask Parameter: RandomSource_MinVal_h
                                       //  Referenced by: '<S16>/Random Source'

  real_T RandomSource_MinVal_b;        // Mask Parameter: RandomSource_MinVal_b
                                       //  Referenced by: '<S17>/Random Source'

  real_T RandomSource_MinVal_d;        // Mask Parameter: RandomSource_MinVal_d
                                       //  Referenced by: '<S18>/Random Source'

  real_T RandomSource_MinVal_n;        // Mask Parameter: RandomSource_MinVal_n
                                       //  Referenced by: '<S19>/Random Source'

  real_T RandomSource_MinVal_i;        // Mask Parameter: RandomSource_MinVal_i
                                       //  Referenced by: '<S20>/Random Source'

  real_T PIDController_UpperSaturationLi;// Mask Parameter: PIDController_UpperSaturationLi
                                         //  Referenced by:
                                         //    '<S40>/Saturate'
                                         //    '<S42>/DeadZone'

  real_T PIDController_UpperSaturation_o;// Mask Parameter: PIDController_UpperSaturation_o
                                         //  Referenced by:
                                         //    '<S43>/Saturate'
                                         //    '<S45>/DeadZone'

  real_T PIDController_UpperSaturation_e;// Mask Parameter: PIDController_UpperSaturation_e
                                         //  Referenced by:
                                         //    '<S46>/Saturate'
                                         //    '<S48>/DeadZone'

  real_T PIDController_UpperSaturation_d;// Mask Parameter: PIDController_UpperSaturation_d
                                         //  Referenced by:
                                         //    '<S49>/Saturate'
                                         //    '<S51>/DeadZone'

  real_T PIDController_UpperSaturation_b;// Mask Parameter: PIDController_UpperSaturation_b
                                         //  Referenced by:
                                         //    '<S52>/Saturate'
                                         //    '<S54>/DeadZone'

  real_T PIDController_UpperSaturatio_ba;// Mask Parameter: PIDController_UpperSaturatio_ba
                                         //  Referenced by:
                                         //    '<S55>/Saturate'
                                         //    '<S57>/DeadZone'

  int32_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                       //  Referenced by: '<S1>/Constant'

  SL_Bus_Controller_std_msgs_Float64MultiArray Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S58>/Out1'

  SL_Bus_Controller_std_msgs_Float64MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S10>/Constant'

  SL_Bus_Controller_std_msgs_UInt16MultiArray Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                               //  Referenced by: '<S60>/Constant'

  SL_Bus_Controller_geometry_msgs_Twist Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                                  //  Referenced by: '<S33>/Out1'

  SL_Bus_Controller_geometry_msgs_Twist Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                         //  Referenced by: '<S8>/Constant'

  real_T Constant4_Value[6];           // Expression: zeros(6,1)
                                       //  Referenced by: '<Root>/Constant4'

  real_T Getcontrollertype_SampleTime; // Expression: SampleTime
                                       //  Referenced by: '<Root>/Get controller type'

  real_T Gettest_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<Root>/Get test'

  real_T yawerrordegrees_Y0;           // Computed Parameter: yawerrordegrees_Y0
                                       //  Referenced by: '<S2>/yaw error [degrees]'

  real_T pitcherrordegrees_Y0;         // Computed Parameter: pitcherrordegrees_Y0
                                       //  Referenced by: '<S2>/pitch error [degrees]'

  real_T rollerrordegrees_Y0;          // Computed Parameter: rollerrordegrees_Y0
                                       //  Referenced by: '<S2>/roll error [degrees]'

  real_T angular_velxerrordegrees_Y0;  // Computed Parameter: angular_velxerrordegrees_Y0
                                       //  Referenced by: '<S2>/angular_vel x error [degrees]'

  real_T angular_velyerrordegrees_Y0;  // Computed Parameter: angular_velyerrordegrees_Y0
                                       //  Referenced by: '<S2>/angular_vel y error [degrees]'

  real_T angular_velzerrordegrees_Y0;  // Computed Parameter: angular_velzerrordegrees_Y0
                                       //  Referenced by: '<S2>/angular_vel z error [degrees]'

  real_T xerrorms_Y0;                  // Computed Parameter: xerrorms_Y0
                                       //  Referenced by: '<S2>/x error [m//s]'

  real_T yerrorm_Y0;                   // Computed Parameter: yerrorm_Y0
                                       //  Referenced by: '<S2>/y error [m]'

  real_T zerrorm_Y0;                   // Computed Parameter: zerrorm_Y0
                                       //  Referenced by: '<S2>/z error [m]'

  real_T velxerrorms_Y0;               // Computed Parameter: velxerrorms_Y0
                                       //  Referenced by: '<S2>/vel x error [m//s]'

  real_T velyerrorms_Y0;               // Computed Parameter: velyerrorms_Y0
                                       //  Referenced by: '<S2>/vel y error [m//s]'

  real_T velzerrorms_Y0;               // Computed Parameter: velzerrorms_Y0
                                       //  Referenced by: '<S2>/vel z error [m//s]'

  real_T accxerrorms_Y0;               // Computed Parameter: accxerrorms_Y0
                                       //  Referenced by: '<S2>/acc x error [m//s]'

  real_T accyerrorms_Y0;               // Computed Parameter: accyerrorms_Y0
                                       //  Referenced by: '<S2>/acc y error [m//s]'

  real_T acczerrorms_Y0;               // Computed Parameter: acczerrorms_Y0
                                       //  Referenced by: '<S2>/acc z error [m//s]'

  real_T Getbuoyancy_SampleTime;       // Expression: SampleTime
                                       //  Referenced by: '<S3>/Get buoyancy'

  real_T Getbuoyancy_SampleTime_l;     // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get buoyancy'

  real_T Swtichingfactor2_SampleTime;  // Expression: SampleTime
                                       //  Referenced by: '<S15>/Swtiching factor2'

  real_T Swtichingfactor1_SampleTime;  // Expression: SampleTime
                                       //  Referenced by: '<S15>/Swtiching factor1'

  real_T Swtichingfactor_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S15>/Swtiching factor'

  real_T Swtichingfactor2_SampleTime_b;// Expression: SampleTime
                                       //  Referenced by: '<S16>/Swtiching factor2'

  real_T Swtichingfactor1_SampleTime_i;// Expression: SampleTime
                                       //  Referenced by: '<S16>/Swtiching factor1'

  real_T Swtichingfactor_SampleTime_k; // Expression: SampleTime
                                       //  Referenced by: '<S16>/Swtiching factor'

  real_T Swtichingfactor2_SampleTime_o;// Expression: SampleTime
                                       //  Referenced by: '<S17>/Swtiching factor2'

  real_T Swtichingfactor1_SampleTime_o;// Expression: SampleTime
                                       //  Referenced by: '<S17>/Swtiching factor1'

  real_T Swtichingfactor_SampleTime_g; // Expression: SampleTime
                                       //  Referenced by: '<S17>/Swtiching factor'

  real_T Swtichingfactor2_SampleTime_e;// Expression: SampleTime
                                       //  Referenced by: '<S18>/Swtiching factor2'

  real_T Swtichingfactor1_SampleTime_j;// Expression: SampleTime
                                       //  Referenced by: '<S18>/Swtiching factor1'

  real_T Swtichingfactor_SampleTime_n; // Expression: SampleTime
                                       //  Referenced by: '<S18>/Swtiching factor'

  real_T Swtichingfactor2_SampleTime_n;// Expression: SampleTime
                                       //  Referenced by: '<S19>/Swtiching factor2'

  real_T Swtichingfactor1_SampleTime_a;// Expression: SampleTime
                                       //  Referenced by: '<S19>/Swtiching factor1'

  real_T Swtichingfactor_SampleTime_nq;// Expression: SampleTime
                                       //  Referenced by: '<S19>/Swtiching factor'

  real_T Swtichingfactor2_SampleTime_c;// Expression: SampleTime
                                       //  Referenced by: '<S20>/Swtiching factor2'

  real_T Swtichingfactor1_SampleTime_e;// Expression: SampleTime
                                       //  Referenced by: '<S20>/Swtiching factor1'

  real_T Swtichingfactor_SampleTime_f; // Expression: SampleTime
                                       //  Referenced by: '<S20>/Swtiching factor'

  real_T Thrusters_Y0;                 // Computed Parameter: Thrusters_Y0
                                       //  Referenced by: '<S5>/Thrusters'

  real_T Constant_Value_f;             // Expression: 100
                                       //  Referenced by: '<S15>/Constant'

  real_T Constant_Value_k;             // Expression: 100
                                       //  Referenced by: '<S16>/Constant'

  real_T Constant_Value_a;             // Expression: 100
                                       //  Referenced by: '<S17>/Constant'

  real_T Constant_Value_a4;            // Expression: 100
                                       //  Referenced by: '<S18>/Constant'

  real_T Constant_Value_dg;            // Expression: 100
                                       //  Referenced by: '<S19>/Constant'

  real_T Constant_Value_fo;            // Expression: 100
                                       //  Referenced by: '<S20>/Constant'

  real_T angular_velX_Y0;              // Computed Parameter: angular_velX_Y0
                                       //  Referenced by: '<S6>/<angular_vel X>'

  real_T angular_velY_Y0;              // Computed Parameter: angular_velY_Y0
                                       //  Referenced by: '<S6>/<angular_vel Y>'

  real_T angular_velZ_Y0;              // Computed Parameter: angular_velZ_Y0
                                       //  Referenced by: '<S6>/<angular_vel Z> '

  real_T velocityX_Y0;                 // Computed Parameter: velocityX_Y0
                                       //  Referenced by: '<S6>/<velocity X>'

  real_T veloctiyY_Y0;                 // Computed Parameter: veloctiyY_Y0
                                       //  Referenced by: '<S6>/<veloctiy Y>'

  real_T velocityZ_Y0;                 // Computed Parameter: velocityZ_Y0
                                       //  Referenced by: '<S6>/<velocity Z>'

  real_T Getalpha_SampleTime;          // Expression: SampleTime
                                       //  Referenced by: '<S7>/Get alpha'

  real_T Enableintegration_SampleTime; // Expression: SampleTime
                                       //  Referenced by: '<S7>/Enable integration?'

  real_T I_angular_vel_x_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S41>/I_angular_vel_x'

  real_T N_angular_vel_x_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S41>/N_angular_vel_x '

  real_T D_angular_vel_x_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S41>/D_angular_vel_x'

  real_T P_angular_vel_x_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S41>/P_angular_vel_x'

  real_T I_angular_vel_y_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S44>/I_angular_vel_y'

  real_T N_angular_vel_y_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S44>/N_angular_vel_y '

  real_T D_angular_vel_y_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S44>/D_angular_vel_y'

  real_T P_angular_vel_y_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S44>/P_angular_vel_y'

  real_T I_angular_vel_z_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S47>/I_angular_vel_z'

  real_T N_angular_vel_z_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S47>/N_angular_vel_z '

  real_T D_angular_vel_z_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S47>/D_angular_vel_z'

  real_T P_angular_vel_z_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S47>/P_angular_vel_z'

  real_T I_vel_x_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S50>/I_vel_x'

  real_T N_vel_x_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S50>/N_vel_x '

  real_T D_vel_x_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S50>/D_vel_x'

  real_T P_vel_x_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S50>/P_vel_x'

  real_T I_vel_y_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S53>/I_vel_y'

  real_T N_vel_y_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S53>/N_vel_y '

  real_T D_vel_y_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S53>/D_vel_y'

  real_T P_vel_y_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S53>/P_vel_y'

  real_T I_vel_z_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S56>/I_vel_z'

  real_T N_vel_z_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S56>/N_vel_z '

  real_T D_vel_z_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S56>/D_vel_z'

  real_T P_vel_z_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S56>/P_vel_z'

  real_T velocitesangularxyzlinearxyz_Y0;// Computed Parameter: velocitesangularxyzlinearxyz_Y0
                                         //  Referenced by: '<S9>/velocites [angular xyz, linear xyz]'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                       //  Referenced by: '<S40>/Integrator'

  real_T Integrator_IC;                // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S40>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                       //  Referenced by: '<S40>/Filter'

  real_T Filter_IC;                    // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S40>/Filter'

  real_T ZeroGain_Gain;                // Expression: 0
                                       //  Referenced by: '<S42>/ZeroGain'

  real_T Constant_Value_ke;            // Expression: 0
                                       //  Referenced by: '<S40>/Constant'

  real_T Integrator_gainval_c;         // Computed Parameter: Integrator_gainval_c
                                       //  Referenced by: '<S43>/Integrator'

  real_T Integrator_IC_o;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S43>/Integrator'

  real_T Filter_gainval_i;             // Computed Parameter: Filter_gainval_i
                                       //  Referenced by: '<S43>/Filter'

  real_T Filter_IC_n;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S43>/Filter'

  real_T ZeroGain_Gain_k;              // Expression: 0
                                       //  Referenced by: '<S45>/ZeroGain'

  real_T Constant_Value_m;             // Expression: 0
                                       //  Referenced by: '<S43>/Constant'

  real_T Integrator_gainval_n;         // Computed Parameter: Integrator_gainval_n
                                       //  Referenced by: '<S46>/Integrator'

  real_T Integrator_IC_d;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S46>/Integrator'

  real_T Filter_gainval_k;             // Computed Parameter: Filter_gainval_k
                                       //  Referenced by: '<S46>/Filter'

  real_T Filter_IC_c;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S46>/Filter'

  real_T ZeroGain_Gain_a;              // Expression: 0
                                       //  Referenced by: '<S48>/ZeroGain'

  real_T Constant_Value_fw;            // Expression: 0
                                       //  Referenced by: '<S46>/Constant'

  real_T Integrator_gainval_j;         // Computed Parameter: Integrator_gainval_j
                                       //  Referenced by: '<S49>/Integrator'

  real_T Integrator_IC_e;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S49>/Integrator'

  real_T Filter_gainval_h;             // Computed Parameter: Filter_gainval_h
                                       //  Referenced by: '<S49>/Filter'

  real_T Filter_IC_j;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S49>/Filter'

  real_T ZeroGain_Gain_j;              // Expression: 0
                                       //  Referenced by: '<S51>/ZeroGain'

  real_T Constant_Value_m0;            // Expression: 0
                                       //  Referenced by: '<S49>/Constant'

  real_T Integrator_gainval_np;        // Computed Parameter: Integrator_gainval_np
                                       //  Referenced by: '<S52>/Integrator'

  real_T Integrator_IC_i;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S52>/Integrator'

  real_T Filter_gainval_h0;            // Computed Parameter: Filter_gainval_h0
                                       //  Referenced by: '<S52>/Filter'

  real_T Filter_IC_jx;                 // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S52>/Filter'

  real_T ZeroGain_Gain_jk;             // Expression: 0
                                       //  Referenced by: '<S54>/ZeroGain'

  real_T Constant_Value_p;             // Expression: 0
                                       //  Referenced by: '<S52>/Constant'

  real_T Integrator_gainval_m;         // Computed Parameter: Integrator_gainval_m
                                       //  Referenced by: '<S55>/Integrator'

  real_T Integrator_IC_m;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S55>/Integrator'

  real_T Filter_gainval_b;             // Computed Parameter: Filter_gainval_b
                                       //  Referenced by: '<S55>/Filter'

  real_T Filter_IC_p;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S55>/Filter'

  real_T ZeroGain_Gain_p;              // Expression: 0
                                       //  Referenced by: '<S57>/ZeroGain'

  real_T Constant_Value_l;             // Expression: 0
                                       //  Referenced by: '<S55>/Constant'

  real_T yawdegrees_Y0;                // Computed Parameter: yawdegrees_Y0
                                       //  Referenced by: '<S11>/<yaw [degrees]>'

  real_T pitchdegrees_Y0;              // Computed Parameter: pitchdegrees_Y0
                                       //  Referenced by: '<S11>/<pitch [degrees]>'

  real_T rolldegrees_Y0;               // Computed Parameter: rolldegrees_Y0
                                       //  Referenced by: '<S11>/<roll [degrees]>'

  real_T angular_velXdegreess_Y0;      // Computed Parameter: angular_velXdegreess_Y0
                                       //  Referenced by: '<S11>/<angular_vel X [degrees//s]>'

  real_T angular_velYdegreess_Y0;      // Computed Parameter: angular_velYdegreess_Y0
                                       //  Referenced by: '<S11>/<angular_vel Y [degrees//s]>'

  real_T angular_velZdegreess_Y0;      // Computed Parameter: angular_velZdegreess_Y0
                                       //  Referenced by: '<S11>/<angular_vel Z [degrees//s]>'

  real_T Zm_Y0;                        // Computed Parameter: Zm_Y0
                                       //  Referenced by: '<S11>/<Z [m]>'

  real_T accXms2_Y0;                   // Computed Parameter: accXms2_Y0
                                       //  Referenced by: '<S11>/<acc X [m//s^2]>'

  real_T accYms2_Y0;                   // Computed Parameter: accYms2_Y0
                                       //  Referenced by: '<S11>/<acc Y [m//s^2]>'

  real_T accZms2_Y0;                   // Computed Parameter: accZms2_Y0
                                       //  Referenced by: '<S11>/<acc Z [m//s^2]>'

  real_T GetParameter5_SampleTime;     // Expression: SampleTime
                                       //  Referenced by: '<S62>/Get Parameter5'

  real_T GetParameter4_SampleTime;     // Expression: SampleTime
                                       //  Referenced by: '<S62>/Get Parameter4'

  real_T GetParameter3_SampleTime;     // Expression: SampleTime
                                       //  Referenced by: '<S62>/Get Parameter3'

  real_T GetParameter2_SampleTime;     // Expression: SampleTime
                                       //  Referenced by: '<S62>/Get Parameter2'

  real_T GetParameter1_SampleTime;     // Expression: SampleTime
                                       //  Referenced by: '<S62>/Get Parameter1'

  real_T GetParameter_SampleTime;      // Expression: SampleTime
                                       //  Referenced by: '<S62>/Get Parameter'

  real_T Saturation_UpperSat;          // Expression: 1
                                       //  Referenced by: '<S12>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -1
                                       //  Referenced by: '<S12>/Saturation'

  real_T DiscreteTimeIntegrator_gainval;// Computed Parameter: DiscreteTimeIntegrator_gainval
                                        //  Referenced by: '<S7>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                       //  Referenced by: '<S7>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator1_gainval;// Computed Parameter: DiscreteTimeIntegrator1_gainval
                                         //  Referenced by: '<S7>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                       //  Referenced by: '<S7>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator2_gainval;// Computed Parameter: DiscreteTimeIntegrator2_gainval
                                         //  Referenced by: '<S7>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_IC;   // Expression: 0
                                       //  Referenced by: '<S7>/Discrete-Time Integrator2'

  real_T Constant_Value_ay;            // Expression: 1
                                       //  Referenced by: '<S7>/Constant'

  real_T DiscreteFilter_NumCoef;       // Expression: [1]
                                       //  Referenced by: '<S7>/Discrete Filter'

  real_T DiscreteFilter_InitialStates; // Expression: 0
                                       //  Referenced by: '<S7>/Discrete Filter'

  real_T DiscreteFilter_InitialDenominat;// Expression: 0
                                         //  Referenced by: '<S7>/Discrete Filter'

  real_T DiscreteFilter1_NumCoef;      // Expression: [1]
                                       //  Referenced by: '<S7>/Discrete Filter1'

  real_T DiscreteFilter1_InitialStates;// Expression: 0
                                       //  Referenced by: '<S7>/Discrete Filter1'

  real_T DiscreteFilter1_InitialDenomina;// Expression: 0
                                         //  Referenced by: '<S7>/Discrete Filter1'

  real_T DiscreteFilter2_NumCoef;      // Expression: [1]
                                       //  Referenced by: '<S7>/Discrete Filter2'

  real_T DiscreteFilter2_InitialStates;// Expression: 0
                                       //  Referenced by: '<S7>/Discrete Filter2'

  real_T DiscreteFilter2_InitialDenomina;// Expression: 0
                                         //  Referenced by: '<S7>/Discrete Filter2'

};

// Real-time Model Data Structure
struct tag_RTM_Controller_T {
  const char_T *errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Class declaration for model Controller
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
  RT_MODEL_Controller_T * getRTM();

  // private data and function members
 private:
  // Tunable parameters
  Parameters_Controller_T Controller_P;

  // Block signals
  BlockIO_Controller_T Controller_B;

  // Block states
  D_Work_Controller_T Controller_DWork;

  // Real-Time Model
  RT_MODEL_Controller_T Controller_M;

  // private member function(s) for subsystem '<Root>'
  void Controller_RandSrc_U_D(real_T y[], const real_T minVec[], int32_T minLen,
    const real_T maxVec[], int32_T maxLen, real_T state[], int32_T nChans,
    int32_T nSamps);
  real_T Controller_rt_remd_snf(real_T u0, real_T u1);
  void Controller_sind(real_T *x);
  void Controller_cosd(real_T *x);
  void Controlle_RandSrcCreateSeeds_64(uint32_T initSeed, uint32_T seedArray[],
    int32_T numSeeds);
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
//  '<Root>' : 'Controller'
//  '<S1>'   : 'Controller/Compare To Constant'
//  '<S2>'   : 'Controller/Create errors'
//  '<S3>'   : 'Controller/Decouple1'
//  '<S4>'   : 'Controller/Decouple2'
//  '<S5>'   : 'Controller/Telegraph'
//  '<S6>'   : 'Controller/Xbox_input'
//  '<S7>'   : 'Controller/acc integration'
//  '<S8>'   : 'Controller/cmd_vel'
//  '<S9>'   : 'Controller/decController'
//  '<S10>'  : 'Controller/imu_data'
//  '<S11>'  : 'Controller/states'
//  '<S12>'  : 'Controller/toPWM'
//  '<S13>'  : 'Controller/Decouple1/MATLAB Function'
//  '<S14>'  : 'Controller/Decouple2/MATLAB Function'
//  '<S15>'  : 'Controller/Telegraph/Thruster1 block'
//  '<S16>'  : 'Controller/Telegraph/Thruster2 block'
//  '<S17>'  : 'Controller/Telegraph/Thruster3 block'
//  '<S18>'  : 'Controller/Telegraph/Thruster4 block'
//  '<S19>'  : 'Controller/Telegraph/Thruster5 block '
//  '<S20>'  : 'Controller/Telegraph/Thruster6 block'
//  '<S21>'  : 'Controller/Telegraph/Thruster1 block/MATLAB Function'
//  '<S22>'  : 'Controller/Telegraph/Thruster1 block/State Transition Table'
//  '<S23>'  : 'Controller/Telegraph/Thruster2 block/MATLAB Function'
//  '<S24>'  : 'Controller/Telegraph/Thruster2 block/State Transition Table'
//  '<S25>'  : 'Controller/Telegraph/Thruster3 block/MATLAB Function'
//  '<S26>'  : 'Controller/Telegraph/Thruster3 block/State Transition Table'
//  '<S27>'  : 'Controller/Telegraph/Thruster4 block/MATLAB Function'
//  '<S28>'  : 'Controller/Telegraph/Thruster4 block/State Transition Table'
//  '<S29>'  : 'Controller/Telegraph/Thruster5 block /MATLAB Function'
//  '<S30>'  : 'Controller/Telegraph/Thruster5 block /State Transition Table'
//  '<S31>'  : 'Controller/Telegraph/Thruster6 block/MATLAB Function'
//  '<S32>'  : 'Controller/Telegraph/Thruster6 block/State Transition Table'
//  '<S33>'  : 'Controller/cmd_vel/Enabled Subsystem'
//  '<S34>'  : 'Controller/decController/angular_vel x'
//  '<S35>'  : 'Controller/decController/angular_vel y'
//  '<S36>'  : 'Controller/decController/angular_vel z'
//  '<S37>'  : 'Controller/decController/vel x'
//  '<S38>'  : 'Controller/decController/vel y'
//  '<S39>'  : 'Controller/decController/vel z'
//  '<S40>'  : 'Controller/decController/angular_vel x/PID Controller'
//  '<S41>'  : 'Controller/decController/angular_vel x/Retrive PID-Parameters'
//  '<S42>'  : 'Controller/decController/angular_vel x/PID Controller/Clamping circuit'
//  '<S43>'  : 'Controller/decController/angular_vel y/PID Controller'
//  '<S44>'  : 'Controller/decController/angular_vel y/Retrive PID-Parameters'
//  '<S45>'  : 'Controller/decController/angular_vel y/PID Controller/Clamping circuit'
//  '<S46>'  : 'Controller/decController/angular_vel z/PID Controller'
//  '<S47>'  : 'Controller/decController/angular_vel z/Retrive PID-Parameters'
//  '<S48>'  : 'Controller/decController/angular_vel z/PID Controller/Clamping circuit'
//  '<S49>'  : 'Controller/decController/vel x/PID Controller'
//  '<S50>'  : 'Controller/decController/vel x/Retrive PID-Parameters'
//  '<S51>'  : 'Controller/decController/vel x/PID Controller/Clamping circuit'
//  '<S52>'  : 'Controller/decController/vel y/PID Controller'
//  '<S53>'  : 'Controller/decController/vel y/Retrive PID-Parameters'
//  '<S54>'  : 'Controller/decController/vel y/PID Controller/Clamping circuit'
//  '<S55>'  : 'Controller/decController/vel z/PID Controller'
//  '<S56>'  : 'Controller/decController/vel z/Retrive PID-Parameters'
//  '<S57>'  : 'Controller/decController/vel z/PID Controller/Clamping circuit'
//  '<S58>'  : 'Controller/imu_data/Enabled Subsystem'
//  '<S59>'  : 'Controller/states/removeGravity'
//  '<S60>'  : 'Controller/toPWM/Actuator message '
//  '<S61>'  : 'Controller/toPWM/Calc pwm signal'
//  '<S62>'  : 'Controller/toPWM/Enable thrusters '
//  '<S63>'  : 'Controller/toPWM/PWM assign'
//  '<S64>'  : 'Controller/toPWM/Publish'


//-
//  Requirements for '<Root>': Controller

#endif                                 // RTW_HEADER_Controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
