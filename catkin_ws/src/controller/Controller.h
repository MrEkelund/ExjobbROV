//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Controller.h
//
// Code generated for Simulink model 'Controller'.
//
// Model version                  : 1.174
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Sun Mar 20 10:44:52 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Controller_h_
#define RTW_HEADER_Controller_h_
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
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals for system '<S31>/MATLAB Function'
typedef struct {
  real_T y;                            // '<S31>/MATLAB Function'
} rtB_MATLABFunction_Controller_T;

// Block signals for system '<S31>/State Transition Table'
typedef struct {
  real_T u;                            // '<S31>/State Transition Table'
} rtB_StateTransitionTable_Cont_T;

// Block states (auto storage) for system '<S31>/State Transition Table'
typedef struct {
  uint8_T is_active_c6_Controller;     // '<S31>/State Transition Table'
  uint8_T is_c6_Controller;            // '<S31>/State Transition Table'
} rtDW_StateTransitionTable_Con_T;

// Block signals for system '<Root>/thrust alloc'
typedef struct {
  real_T thrusters[6];                 // '<Root>/thrust alloc'
} rtB_thrustalloc_Controller_T;

// Block signals (auto storage)
typedef struct {
  SL_Bus_Controller_std_msgs_Float64MultiArray In1;// '<S74>/In1'
  SL_Bus_Controller_std_msgs_Float64MultiArray varargout_2;
  SL_Bus_Controller_std_msgs_UInt16MultiArray msg;// '<S16>/PWM assign'
  real_T rotmatrix[36];
  real_T state[35];
  real_T Data[10];
  real_T r[9];
  real_T cpsi[9];
  SL_Bus_Controller_geometry_msgs_Twist In1_m;// '<S49>/In1'
  SL_Bus_Controller_geometry_msgs_Twist varargout_2_m;
  real_T ChooseControllersignal[6];    // '<Root>/Choose Controller signal'
  real_T dv0[6];
  char_T cv0[38];
  char_T cv1[37];
  char_T cv2[36];
  char_T cv3[35];
  char_T cv4[34];
  char_T cv5[30];
  char_T cv6[28];
  char_T cv7[27];
  char_T cv8[26];
  char_T cv9[25];
  real_T acc[3];
  char_T cv10[24];
  char_T cv11[22];
  char_T cv12[17];
  real_T TmpSignalConversionAtDiscreteFi[2];
  char_T cv13[9];
  int32_T ii[2];
  real_T OutportBufferForaccXms2;      // '<S12>/removeGravity'
  real_T OutportBufferForaccYms2;      // '<S12>/removeGravity'
  real_T OutportBufferForaccZms2;      // '<S12>/removeGravity'
  real_T X;
  real_T Y;
  real_T OutportBufferForangular_velZrad;
  real_T OutportBufferForpitchradians;
  real_T OutportBufferForrollradians;
  real_T Saturate;                     // '<S56>/Saturate'
  real_T Saturate_f;                   // '<S59>/Saturate'
  real_T Saturate_i;                   // '<S62>/Saturate'
  real_T Saturate_b;                   // '<S65>/Saturate'
  real_T Saturate_h;                   // '<S68>/Saturate'
  real_T Saturate_bk;                  // '<S71>/Saturate'
  real_T X_h;
  real_T Y_i;
  real_T Z;
  real_T X_hw;
  real_T Y_in;
  real_T Z_n;
  real_T OutportBufferForThrusters[6];
  real_T OutportBufferForOut2[6];      // '<S5>/convert to local'
  real_T Product;                      // '<S4>/Product'
  real_T Product1;                     // '<S4>/Product1'
  real_T Product2;                     // '<S4>/Product2'
  real_T Product3;                     // '<S4>/Product3'
  real_T Product4;                     // '<S4>/Product4'
  real_T Product5;                     // '<S4>/Product5'
  real_T Errorx;                       // '<S2>/Error x'
  real_T Errory;                       // '<S2>/Error y'
  real_T Errorz;                       // '<S2>/Error z'
  real_T Errorz8;                      // '<S2>/Error z8'
  real_T Errorz9;                      // '<S2>/Error z9'
  real_T Errorz10;                     // '<S2>/Error z10'
  real_T sfi;
  real_T cfi;
  real_T spsi;
  real_T cpsi_c;
  real_T stheta;
  real_T ctheta;
  real_T RandomSource;                 // '<S36>/Random Source'
  real_T SignPreIntegrator_k;          // '<S73>/SignPreIntegrator'
  real_T SumI1_d;                      // '<S71>/SumI1'
  real_T NOut_e;                       // '<S59>/NOut'
  real_T NOut_m;                       // '<S62>/NOut'
  real_T NOut_b;                       // '<S65>/NOut'
  real_T NOut_i;                       // '<S68>/NOut'
  real_T Switch;                       // '<S56>/Switch'
  real_T Switch_o;                     // '<S59>/Switch'
  real_T Switch_j;                     // '<S62>/Switch'
  real_T Switch_e;                     // '<S65>/Switch'
  real_T Switch_i;                     // '<S68>/Switch'
  real_T min;
  real_T max;
  real_T d;
  SL_Bus_Controller_std_msgs_Bool In1_b;// '<S17>/In1'
  int32_T value;
  int32_T value_k;
  int32_T i;
  int32_T i0;
  int32_T one;
  int32_T lsw;
  int32_T chan;
  int32_T samps;
  int32_T i_c;
  uint32_T j;
  int8_T rtb_DataTypeConv2_c_b;
  int8_T i1;
  boolean_T p;
  boolean_T p_p;
  boolean_T value_c;
  boolean_T value_f;
  boolean_T Compare;                   // '<S1>/Compare'
  boolean_T LogicalOperator;           // '<Root>/Logical Operator'
  boolean_T NotEqual;                  // '<S58>/NotEqual'
  SL_Bus_Controller_std_msgs_Bool varargout_2_g;
  rtB_thrustalloc_Controller_T sf_thrustalloc1;// '<Root>/thrust alloc1'
  rtB_thrustalloc_Controller_T sf_thrustalloc;// '<Root>/thrust alloc'
  rtB_StateTransitionTable_Cont_T sf_StateTransitionTable_o2;// '<S36>/State Transition Table' 
  rtB_MATLABFunction_Controller_T sf_MATLABFunction_i;// '<S36>/MATLAB Function' 
  rtB_StateTransitionTable_Cont_T sf_StateTransitionTable_o;// '<S35>/State Transition Table' 
  rtB_MATLABFunction_Controller_T sf_MATLABFunction_e;// '<S35>/MATLAB Function' 
  rtB_StateTransitionTable_Cont_T sf_StateTransitionTable_mx;// '<S34>/State Transition Table' 
  rtB_MATLABFunction_Controller_T sf_MATLABFunction_o;// '<S34>/MATLAB Function' 
  rtB_StateTransitionTable_Cont_T sf_StateTransitionTable_m;// '<S33>/State Transition Table' 
  rtB_MATLABFunction_Controller_T sf_MATLABFunction_j;// '<S33>/MATLAB Function' 
  rtB_StateTransitionTable_Cont_T sf_StateTransitionTable_i;// '<S32>/State Transition Table' 
  rtB_MATLABFunction_Controller_T sf_MATLABFunction_l;// '<S32>/MATLAB Function' 
  rtB_StateTransitionTable_Cont_T sf_StateTransitionTable;// '<S31>/State Transition Table' 
  rtB_MATLABFunction_Controller_T sf_MATLABFunction;// '<S31>/MATLAB Function'
} BlockIO_Controller_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  robotics_slros_internal_block_T obj; // '<S78>/Get Parameter'
  robotics_slros_internal_block_T obj_l;// '<S78>/Get Parameter1'
  robotics_slros_internal_block_T obj_n;// '<S78>/Get Parameter2'
  robotics_slros_internal_block_T obj_c;// '<S78>/Get Parameter3'
  robotics_slros_internal_block_T obj_nt;// '<S78>/Get Parameter4'
  robotics_slros_internal_block_T obj_ls;// '<S78>/Get Parameter5'
  robotics_slros_internal_block_T obj_j;// '<S72>/P_vel_z'
  robotics_slros_internal_block_T obj_a;// '<S72>/D_vel_z'
  robotics_slros_internal_block_T obj_h;// '<S72>/N_vel_z '
  robotics_slros_internal_block_T obj_js;// '<S72>/I_vel_z'
  robotics_slros_internal_block_T obj_ji;// '<S69>/P_vel_y'
  robotics_slros_internal_block_T obj_ny;// '<S69>/D_vel_y'
  robotics_slros_internal_block_T obj_cb;// '<S69>/N_vel_y '
  robotics_slros_internal_block_T obj_jx;// '<S69>/I_vel_y'
  robotics_slros_internal_block_T obj_ns;// '<S66>/P_vel_x'
  robotics_slros_internal_block_T obj_d;// '<S66>/D_vel_x'
  robotics_slros_internal_block_T obj_a3;// '<S66>/N_vel_x '
  robotics_slros_internal_block_T obj_cv;// '<S66>/I_vel_x'
  robotics_slros_internal_block_T obj_e;// '<S63>/P_angular_vel_z'
  robotics_slros_internal_block_T obj_jg;// '<S63>/D_angular_vel_z'
  robotics_slros_internal_block_T obj_g;// '<S63>/N_angular_vel_z '
  robotics_slros_internal_block_T obj_p;// '<S63>/I_angular_vel_z'
  robotics_slros_internal_block_T obj_b;// '<S60>/P_angular_vel_y'
  robotics_slros_internal_block_T obj_m;// '<S60>/D_angular_vel_y'
  robotics_slros_internal_block_T obj_dp;// '<S60>/N_angular_vel_y '
  robotics_slros_internal_block_T obj_ep;// '<S60>/I_angular_vel_y'
  robotics_slros_internal_block_T obj_bm;// '<S57>/P_angular_vel_x'
  robotics_slros_internal_block_T obj_be;// '<S57>/D_angular_vel_x'
  robotics_slros_internal_block_T obj_lb;// '<S57>/N_angular_vel_x '
  robotics_slros_internal_block_T obj_pb;// '<S57>/I_angular_vel_x'
  robotics_slros_internal_block_T obj_g0;// '<S8>/Enable integration?'
  robotics_slros_internal_block_T obj_hx;// '<S8>/Get alpha'
  robotics_slros_internal_block_T obj_gf;// '<S36>/Swtiching factor'
  robotics_slros_internal_block_T obj_cvy;// '<S36>/Swtiching factor1'
  robotics_slros_internal_block_T obj_dt;// '<S36>/Swtiching factor2'
  robotics_slros_internal_block_T obj_j0;// '<S35>/Swtiching factor'
  robotics_slros_internal_block_T obj_hr;// '<S35>/Swtiching factor1'
  robotics_slros_internal_block_T obj_dn;// '<S35>/Swtiching factor2'
  robotics_slros_internal_block_T obj_gv;// '<S34>/Swtiching factor'
  robotics_slros_internal_block_T obj_c2;// '<S34>/Swtiching factor1'
  robotics_slros_internal_block_T obj_g0e;// '<S34>/Swtiching factor2'
  robotics_slros_internal_block_T obj_o;// '<S33>/Swtiching factor'
  robotics_slros_internal_block_T obj_f;// '<S33>/Swtiching factor1'
  robotics_slros_internal_block_T obj_mb;// '<S33>/Swtiching factor2'
  robotics_slros_internal_block_T obj_i;// '<S32>/Swtiching factor'
  robotics_slros_internal_block_T obj_j5;// '<S32>/Swtiching factor1'
  robotics_slros_internal_block_T obj_fu;// '<S32>/Swtiching factor2'
  robotics_slros_internal_block_T obj_of;// '<S31>/Swtiching factor'
  robotics_slros_internal_block_T obj_fx;// '<S31>/Swtiching factor1'
  robotics_slros_internal_block_T obj_d3;// '<S31>/Swtiching factor2'
  robotics_slros_internal_block_T obj_hn;// '<S29>/P_yaw'
  robotics_slros_internal_block_T obj_ha;// '<S29>/D_yaw'
  robotics_slros_internal_block_T obj_py;// '<S29>/N_yaw '
  robotics_slros_internal_block_T obj_om;// '<S29>/I_yaw'
  robotics_slros_internal_block_T obj_jp;// '<S26>/P_roll'
  robotics_slros_internal_block_T obj_k;// '<S26>/D_roll'
  robotics_slros_internal_block_T obj_dp3;// '<S26>/N_roll '
  robotics_slros_internal_block_T obj_c1;// '<S26>/I_roll'
  robotics_slros_internal_block_T obj_m1;// '<S23>/P_pitch'
  robotics_slros_internal_block_T obj_b4;// '<S23>/D_pitch'
  robotics_slros_internal_block_T obj_fq;// '<S23>/N_pitch '
  robotics_slros_internal_block_T obj_jb;// '<S23>/I_pitch'
  robotics_slros_internal_block_T obj_pk;// '<S5>/roll_ref'
  robotics_slros_internal_block_T obj_mbl;// '<S5>/pitch_ref'
  robotics_slros_internal_block_T obj_o5;// '<S5>/yaw_ref'
  robotics_slros_internal_block_T obj_km;// '<S4>/Get Parameter'
  robotics_slros_internal_block_T obj_oz;// '<S4>/Get Parameter1'
  robotics_slros_internal_block_T obj_iv;// '<S4>/Get Parameter2'
  robotics_slros_internal_block_T obj_dy;// '<S4>/Get Parameter3'
  robotics_slros_internal_block_T obj_kg;// '<S4>/Get Parameter4'
  robotics_slros_internal_block_T obj_ku;// '<S4>/Get Parameter5'
  robotics_slros_internal_block_T obj_h2;// '<Root>/Get test'
  robotics_slros_internal_block_T obj_nl;// '<Root>/Get controller type'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S8>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S8>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator2_DSTATE;// '<S8>/Discrete-Time Integrator2'
  real_T DiscreteFilter_denStates;     // '<S8>/Discrete Filter'
  real_T DiscreteFilter1_denStates;    // '<S8>/Discrete Filter1'
  real_T DiscreteFilter2_denStates;    // '<S8>/Discrete Filter2'
  real_T Integrator_DSTATE;            // '<S56>/Integrator'
  real_T Filter_DSTATE;                // '<S56>/Filter'
  real_T Integrator_DSTATE_h;          // '<S59>/Integrator'
  real_T Filter_DSTATE_c;              // '<S59>/Filter'
  real_T Integrator_DSTATE_a;          // '<S62>/Integrator'
  real_T Filter_DSTATE_f;              // '<S62>/Filter'
  real_T Integrator_DSTATE_f;          // '<S65>/Integrator'
  real_T Filter_DSTATE_a;              // '<S65>/Filter'
  real_T Integrator_DSTATE_n;          // '<S68>/Integrator'
  real_T Filter_DSTATE_g;              // '<S68>/Filter'
  real_T Integrator_DSTATE_ny;         // '<S71>/Integrator'
  real_T Filter_DSTATE_cw;             // '<S71>/Filter'
  real_T Integrator_DSTATE_nm;         // '<S25>/Integrator'
  real_T Filter_DSTATE_gs;             // '<S25>/Filter'
  real_T Integrator_DSTATE_c;          // '<S22>/Integrator'
  real_T Filter_DSTATE_fb;             // '<S22>/Filter'
  real_T Integrator_DSTATE_ch;         // '<S28>/Integrator'
  real_T Filter_DSTATE_l;              // '<S28>/Filter'
  real_T DiscreteFilter_tmp;           // '<S8>/Discrete Filter'
  real_T DiscreteFilter1_tmp;          // '<S8>/Discrete Filter1'
  real_T DiscreteFilter2_tmp;          // '<S8>/Discrete Filter2'
  real_T RandomSource_STATE_DWORK[35]; // '<S31>/Random Source'
  real_T RandomSource_STATE_DWORK_i[35];// '<S32>/Random Source'
  real_T RandomSource_STATE_DWORK_a[35];// '<S33>/Random Source'
  real_T RandomSource_STATE_DWORK_g[35];// '<S34>/Random Source'
  real_T RandomSource_STATE_DWORK_j[35];// '<S35>/Random Source'
  real_T RandomSource_STATE_DWORK_h[35];// '<S36>/Random Source'
  void *SinkBlock_PWORK;               // '<S80>/SinkBlock'
  void *GetParameter_PWORK;            // '<S78>/Get Parameter'
  void *GetParameter1_PWORK;           // '<S78>/Get Parameter1'
  void *GetParameter2_PWORK;           // '<S78>/Get Parameter2'
  void *GetParameter3_PWORK;           // '<S78>/Get Parameter3'
  void *GetParameter4_PWORK;           // '<S78>/Get Parameter4'
  void *GetParameter5_PWORK;           // '<S78>/Get Parameter5'
  void *SourceBlock_PWORK;             // '<S11>/SourceBlock'
  void *P_vel_z_PWORK;                 // '<S72>/P_vel_z'
  void *D_vel_z_PWORK;                 // '<S72>/D_vel_z'
  void *N_vel_z_PWORK;                 // '<S72>/N_vel_z '
  void *I_vel_z_PWORK;                 // '<S72>/I_vel_z'
  void *P_vel_y_PWORK;                 // '<S69>/P_vel_y'
  void *D_vel_y_PWORK;                 // '<S69>/D_vel_y'
  void *N_vel_y_PWORK;                 // '<S69>/N_vel_y '
  void *I_vel_y_PWORK;                 // '<S69>/I_vel_y'
  void *P_vel_x_PWORK;                 // '<S66>/P_vel_x'
  void *D_vel_x_PWORK;                 // '<S66>/D_vel_x'
  void *N_vel_x_PWORK;                 // '<S66>/N_vel_x '
  void *I_vel_x_PWORK;                 // '<S66>/I_vel_x'
  void *P_angular_vel_z_PWORK;         // '<S63>/P_angular_vel_z'
  void *D_angular_vel_z_PWORK;         // '<S63>/D_angular_vel_z'
  void *N_angular_vel_z_PWORK;         // '<S63>/N_angular_vel_z '
  void *I_angular_vel_z_PWORK;         // '<S63>/I_angular_vel_z'
  void *P_angular_vel_y_PWORK;         // '<S60>/P_angular_vel_y'
  void *D_angular_vel_y_PWORK;         // '<S60>/D_angular_vel_y'
  void *N_angular_vel_y_PWORK;         // '<S60>/N_angular_vel_y '
  void *I_angular_vel_y_PWORK;         // '<S60>/I_angular_vel_y'
  void *P_angular_vel_x_PWORK;         // '<S57>/P_angular_vel_x'
  void *D_angular_vel_x_PWORK;         // '<S57>/D_angular_vel_x'
  void *N_angular_vel_x_PWORK;         // '<S57>/N_angular_vel_x '
  void *I_angular_vel_x_PWORK;         // '<S57>/I_angular_vel_x'
  void *SourceBlock_PWORK_f;           // '<S9>/SourceBlock'
  void *Enableintegration_PWORK;       // '<S8>/Enable integration?'
  void *Getalpha_PWORK;                // '<S8>/Get alpha'
  void *Swtichingfactor_PWORK;         // '<S36>/Swtiching factor'
  void *Swtichingfactor1_PWORK;        // '<S36>/Swtiching factor1'
  void *Swtichingfactor2_PWORK;        // '<S36>/Swtiching factor2'
  void *Swtichingfactor_PWORK_p;       // '<S35>/Swtiching factor'
  void *Swtichingfactor1_PWORK_n;      // '<S35>/Swtiching factor1'
  void *Swtichingfactor2_PWORK_f;      // '<S35>/Swtiching factor2'
  void *Swtichingfactor_PWORK_j;       // '<S34>/Swtiching factor'
  void *Swtichingfactor1_PWORK_d;      // '<S34>/Swtiching factor1'
  void *Swtichingfactor2_PWORK_h;      // '<S34>/Swtiching factor2'
  void *Swtichingfactor_PWORK_k;       // '<S33>/Swtiching factor'
  void *Swtichingfactor1_PWORK_k;      // '<S33>/Swtiching factor1'
  void *Swtichingfactor2_PWORK_p;      // '<S33>/Swtiching factor2'
  void *Swtichingfactor_PWORK_a;       // '<S32>/Swtiching factor'
  void *Swtichingfactor1_PWORK_c;      // '<S32>/Swtiching factor1'
  void *Swtichingfactor2_PWORK_i;      // '<S32>/Swtiching factor2'
  void *Swtichingfactor_PWORK_n;       // '<S31>/Swtiching factor'
  void *Swtichingfactor1_PWORK_l;      // '<S31>/Swtiching factor1'
  void *Swtichingfactor2_PWORK_l;      // '<S31>/Swtiching factor2'
  void *P_yaw_PWORK;                   // '<S29>/P_yaw'
  void *D_yaw_PWORK;                   // '<S29>/D_yaw'
  void *N_yaw_PWORK;                   // '<S29>/N_yaw '
  void *I_yaw_PWORK;                   // '<S29>/I_yaw'
  void *P_roll_PWORK;                  // '<S26>/P_roll'
  void *D_roll_PWORK;                  // '<S26>/D_roll'
  void *N_roll_PWORK;                  // '<S26>/N_roll '
  void *I_roll_PWORK;                  // '<S26>/I_roll'
  void *P_pitch_PWORK;                 // '<S23>/P_pitch'
  void *D_pitch_PWORK;                 // '<S23>/D_pitch'
  void *N_pitch_PWORK;                 // '<S23>/N_pitch '
  void *I_pitch_PWORK;                 // '<S23>/I_pitch'
  void *roll_ref_PWORK;                // '<S5>/roll_ref'
  void *pitch_ref_PWORK;               // '<S5>/pitch_ref'
  void *yaw_ref_PWORK;                 // '<S5>/yaw_ref'
  void *GetParameter_PWORK_m;          // '<S4>/Get Parameter'
  void *GetParameter1_PWORK_o;         // '<S4>/Get Parameter1'
  void *GetParameter2_PWORK_h;         // '<S4>/Get Parameter2'
  void *GetParameter3_PWORK_m;         // '<S4>/Get Parameter3'
  void *GetParameter4_PWORK_l;         // '<S4>/Get Parameter4'
  void *GetParameter5_PWORK_l;         // '<S4>/Get Parameter5'
  void *SourceBlock_PWORK_fw;          // '<S3>/SourceBlock'
  void *Gettest_PWORK;                 // '<Root>/Get test'
  void *Getcontrollertype_PWORK;       // '<Root>/Get controller type'
  uint32_T RandomSource_SEED_DWORK;    // '<S31>/Random Source'
  uint32_T RandomSource_SEED_DWORK_l;  // '<S32>/Random Source'
  uint32_T RandomSource_SEED_DWORK_c;  // '<S33>/Random Source'
  uint32_T RandomSource_SEED_DWORK_i;  // '<S34>/Random Source'
  uint32_T RandomSource_SEED_DWORK_k;  // '<S35>/Random Source'
  uint32_T RandomSource_SEED_DWORK_g;  // '<S36>/Random Source'
  robotics_slros_internal_blo_l_T obj_ki;// '<S11>/SourceBlock'
  robotics_slros_internal_blo_l_T obj_nf;// '<S9>/SourceBlock'
  robotics_slros_internal_blo_l_T obj_mv;// '<S3>/SourceBlock'
  robotics_slros_internal_bl_l5_T obj_pw;// '<S80>/SinkBlock'
  boolean_T objisempty;                // '<S80>/SinkBlock'
  boolean_T objisempty_n;              // '<S78>/Get Parameter'
  boolean_T objisempty_p;              // '<S78>/Get Parameter1'
  boolean_T objisempty_l;              // '<S78>/Get Parameter2'
  boolean_T objisempty_n4;             // '<S78>/Get Parameter3'
  boolean_T objisempty_ns;             // '<S78>/Get Parameter4'
  boolean_T objisempty_a;              // '<S78>/Get Parameter5'
  boolean_T objisempty_i;              // '<S11>/SourceBlock'
  boolean_T objisempty_le;             // '<S72>/P_vel_z'
  boolean_T objisempty_nm;             // '<S72>/D_vel_z'
  boolean_T objisempty_e;              // '<S72>/N_vel_z '
  boolean_T objisempty_n43;            // '<S72>/I_vel_z'
  boolean_T objisempty_ej;             // '<S69>/P_vel_y'
  boolean_T objisempty_c;              // '<S69>/D_vel_y'
  boolean_T objisempty_b;              // '<S69>/N_vel_y '
  boolean_T objisempty_m;              // '<S69>/I_vel_y'
  boolean_T objisempty_a3;             // '<S66>/P_vel_x'
  boolean_T objisempty_d;              // '<S66>/D_vel_x'
  boolean_T objisempty_il;             // '<S66>/N_vel_x '
  boolean_T objisempty_pu;             // '<S66>/I_vel_x'
  boolean_T objisempty_h;              // '<S63>/P_angular_vel_z'
  boolean_T objisempty_if;             // '<S63>/D_angular_vel_z'
  boolean_T objisempty_m1;             // '<S63>/N_angular_vel_z '
  boolean_T objisempty_k;              // '<S63>/I_angular_vel_z'
  boolean_T objisempty_j;              // '<S60>/P_angular_vel_y'
  boolean_T objisempty_h1;             // '<S60>/D_angular_vel_y'
  boolean_T objisempty_ex;             // '<S60>/N_angular_vel_y '
  boolean_T objisempty_ef;             // '<S60>/I_angular_vel_y'
  boolean_T objisempty_f;              // '<S57>/P_angular_vel_x'
  boolean_T objisempty_g;              // '<S57>/D_angular_vel_x'
  boolean_T objisempty_d0;             // '<S57>/N_angular_vel_x '
  boolean_T objisempty_mb;             // '<S57>/I_angular_vel_x'
  boolean_T objisempty_gn;             // '<S9>/SourceBlock'
  boolean_T objisempty_lj;             // '<S8>/Enable integration?'
  boolean_T objisempty_g0;             // '<S8>/Get alpha'
  boolean_T objisempty_k1;             // '<S36>/Swtiching factor'
  boolean_T objisempty_gk;             // '<S36>/Swtiching factor1'
  boolean_T objisempty_kl;             // '<S36>/Swtiching factor2'
  boolean_T objisempty_fj;             // '<S35>/Swtiching factor'
  boolean_T objisempty_nl;             // '<S35>/Swtiching factor1'
  boolean_T objisempty_kk;             // '<S35>/Swtiching factor2'
  boolean_T objisempty_a3j;            // '<S34>/Swtiching factor'
  boolean_T objisempty_hv;             // '<S34>/Swtiching factor1'
  boolean_T objisempty_o;              // '<S34>/Swtiching factor2'
  boolean_T objisempty_ev;             // '<S33>/Swtiching factor'
  boolean_T objisempty_em;             // '<S33>/Swtiching factor1'
  boolean_T objisempty_ks;             // '<S33>/Swtiching factor2'
  boolean_T objisempty_mo;             // '<S32>/Swtiching factor'
  boolean_T objisempty_ng;             // '<S32>/Swtiching factor1'
  boolean_T objisempty_fp;             // '<S32>/Swtiching factor2'
  boolean_T objisempty_ls;             // '<S31>/Swtiching factor'
  boolean_T objisempty_jb;             // '<S31>/Swtiching factor1'
  boolean_T objisempty_jr;             // '<S31>/Swtiching factor2'
  boolean_T objisempty_gj;             // '<S29>/P_yaw'
  boolean_T objisempty_pl;             // '<S29>/D_yaw'
  boolean_T objisempty_ifg;            // '<S29>/N_yaw '
  boolean_T objisempty_gr;             // '<S29>/I_yaw'
  boolean_T objisempty_kq;             // '<S26>/P_roll'
  boolean_T objisempty_h0;             // '<S26>/D_roll'
  boolean_T objisempty_fn;             // '<S26>/N_roll '
  boolean_T objisempty_e5;             // '<S26>/I_roll'
  boolean_T objisempty_m4;             // '<S23>/P_pitch'
  boolean_T objisempty_o5;             // '<S23>/D_pitch'
  boolean_T objisempty_jg;             // '<S23>/N_pitch '
  boolean_T objisempty_ljn;            // '<S23>/I_pitch'
  boolean_T objisempty_lg;             // '<S5>/roll_ref'
  boolean_T objisempty_ho;             // '<S5>/pitch_ref'
  boolean_T objisempty_j5;             // '<S5>/yaw_ref'
  boolean_T objisempty_c1;             // '<S4>/Get Parameter'
  boolean_T objisempty_k3;             // '<S4>/Get Parameter1'
  boolean_T objisempty_jz;             // '<S4>/Get Parameter2'
  boolean_T objisempty_pe;             // '<S4>/Get Parameter3'
  boolean_T objisempty_dt;             // '<S4>/Get Parameter4'
  boolean_T objisempty_br;             // '<S4>/Get Parameter5'
  boolean_T objisempty_j0;             // '<S3>/SourceBlock'
  boolean_T objisempty_pr;             // '<Root>/Get test'
  boolean_T objisempty_m0;             // '<Root>/Get controller type'
  rtDW_StateTransitionTable_Con_T sf_StateTransitionTable_o2;// '<S36>/State Transition Table' 
  rtDW_StateTransitionTable_Con_T sf_StateTransitionTable_o;// '<S35>/State Transition Table' 
  rtDW_StateTransitionTable_Con_T sf_StateTransitionTable_mx;// '<S34>/State Transition Table' 
  rtDW_StateTransitionTable_Con_T sf_StateTransitionTable_m;// '<S33>/State Transition Table' 
  rtDW_StateTransitionTable_Con_T sf_StateTransitionTable_i;// '<S32>/State Transition Table' 
  rtDW_StateTransitionTable_Con_T sf_StateTransitionTable;// '<S31>/State Transition Table' 
} D_Work_Controller_T;

// Parameters (auto storage)
struct Parameters_Controller_T_ {
  real_T PIDController_Kt;             // Mask Parameter: PIDController_Kt
                                       //  Referenced by: '<S22>/Kt'

  real_T PIDController_Kt_d;           // Mask Parameter: PIDController_Kt_d
                                       //  Referenced by: '<S25>/Kt'

  real_T PIDController_Kt_j;           // Mask Parameter: PIDController_Kt_j
                                       //  Referenced by: '<S28>/Kt'

  real_T PIDController_Kt_l;           // Mask Parameter: PIDController_Kt_l
                                       //  Referenced by: '<S56>/Kt'

  real_T PIDController_Kt_jo;          // Mask Parameter: PIDController_Kt_jo
                                       //  Referenced by: '<S59>/Kt'

  real_T PIDController_Kt_p;           // Mask Parameter: PIDController_Kt_p
                                       //  Referenced by: '<S62>/Kt'

  real_T PIDController_Kt_jw;          // Mask Parameter: PIDController_Kt_jw
                                       //  Referenced by: '<S65>/Kt'

  real_T PIDController_Kt_c;           // Mask Parameter: PIDController_Kt_c
                                       //  Referenced by: '<S68>/Kt'

  real_T PIDController_Kt_li;          // Mask Parameter: PIDController_Kt_li
                                       //  Referenced by: '<S71>/Kt'

  real_T PIDController_LowerSaturationLi;// Mask Parameter: PIDController_LowerSaturationLi
                                         //  Referenced by:
                                         //    '<S25>/Saturate'
                                         //    '<S27>/DeadZone'

  real_T PIDController_LowerSaturation_n;// Mask Parameter: PIDController_LowerSaturation_n
                                         //  Referenced by:
                                         //    '<S22>/Saturate'
                                         //    '<S24>/DeadZone'

  real_T PIDController_LowerSaturation_e;// Mask Parameter: PIDController_LowerSaturation_e
                                         //  Referenced by:
                                         //    '<S28>/Saturate'
                                         //    '<S30>/DeadZone'

  real_T PIDController_LowerSaturation_l;// Mask Parameter: PIDController_LowerSaturation_l
                                         //  Referenced by:
                                         //    '<S56>/Saturate'
                                         //    '<S58>/DeadZone'

  real_T PIDController_LowerSaturatio_ek;// Mask Parameter: PIDController_LowerSaturatio_ek
                                         //  Referenced by:
                                         //    '<S59>/Saturate'
                                         //    '<S61>/DeadZone'

  real_T PIDController_LowerSaturation_p;// Mask Parameter: PIDController_LowerSaturation_p
                                         //  Referenced by:
                                         //    '<S62>/Saturate'
                                         //    '<S64>/DeadZone'

  real_T PIDController_LowerSaturation_i;// Mask Parameter: PIDController_LowerSaturation_i
                                         //  Referenced by:
                                         //    '<S65>/Saturate'
                                         //    '<S67>/DeadZone'

  real_T PIDController_LowerSaturation_g;// Mask Parameter: PIDController_LowerSaturation_g
                                         //  Referenced by:
                                         //    '<S68>/Saturate'
                                         //    '<S70>/DeadZone'

  real_T PIDController_LowerSaturatio_pm;// Mask Parameter: PIDController_LowerSaturatio_pm
                                         //  Referenced by:
                                         //    '<S71>/Saturate'
                                         //    '<S73>/DeadZone'

  real_T RandomSource_MaxVal;          // Mask Parameter: RandomSource_MaxVal
                                       //  Referenced by: '<S31>/Random Source'

  real_T RandomSource_MaxVal_o;        // Mask Parameter: RandomSource_MaxVal_o
                                       //  Referenced by: '<S32>/Random Source'

  real_T RandomSource_MaxVal_g;        // Mask Parameter: RandomSource_MaxVal_g
                                       //  Referenced by: '<S33>/Random Source'

  real_T RandomSource_MaxVal_d;        // Mask Parameter: RandomSource_MaxVal_d
                                       //  Referenced by: '<S34>/Random Source'

  real_T RandomSource_MaxVal_n;        // Mask Parameter: RandomSource_MaxVal_n
                                       //  Referenced by: '<S35>/Random Source'

  real_T RandomSource_MaxVal_i;        // Mask Parameter: RandomSource_MaxVal_i
                                       //  Referenced by: '<S36>/Random Source'

  real_T RandomSource_MinVal;          // Mask Parameter: RandomSource_MinVal
                                       //  Referenced by: '<S31>/Random Source'

  real_T RandomSource_MinVal_h;        // Mask Parameter: RandomSource_MinVal_h
                                       //  Referenced by: '<S32>/Random Source'

  real_T RandomSource_MinVal_b;        // Mask Parameter: RandomSource_MinVal_b
                                       //  Referenced by: '<S33>/Random Source'

  real_T RandomSource_MinVal_d;        // Mask Parameter: RandomSource_MinVal_d
                                       //  Referenced by: '<S34>/Random Source'

  real_T RandomSource_MinVal_n;        // Mask Parameter: RandomSource_MinVal_n
                                       //  Referenced by: '<S35>/Random Source'

  real_T RandomSource_MinVal_i;        // Mask Parameter: RandomSource_MinVal_i
                                       //  Referenced by: '<S36>/Random Source'

  real_T PIDController_UpperSaturationLi;// Mask Parameter: PIDController_UpperSaturationLi
                                         //  Referenced by:
                                         //    '<S25>/Saturate'
                                         //    '<S27>/DeadZone'

  real_T PIDController_UpperSaturation_n;// Mask Parameter: PIDController_UpperSaturation_n
                                         //  Referenced by:
                                         //    '<S22>/Saturate'
                                         //    '<S24>/DeadZone'

  real_T PIDController_UpperSaturation_j;// Mask Parameter: PIDController_UpperSaturation_j
                                         //  Referenced by:
                                         //    '<S28>/Saturate'
                                         //    '<S30>/DeadZone'

  real_T PIDController_UpperSaturation_b;// Mask Parameter: PIDController_UpperSaturation_b
                                         //  Referenced by:
                                         //    '<S56>/Saturate'
                                         //    '<S58>/DeadZone'

  real_T PIDController_UpperSaturation_o;// Mask Parameter: PIDController_UpperSaturation_o
                                         //  Referenced by:
                                         //    '<S59>/Saturate'
                                         //    '<S61>/DeadZone'

  real_T PIDController_UpperSaturation_e;// Mask Parameter: PIDController_UpperSaturation_e
                                         //  Referenced by:
                                         //    '<S62>/Saturate'
                                         //    '<S64>/DeadZone'

  real_T PIDController_UpperSaturation_d;// Mask Parameter: PIDController_UpperSaturation_d
                                         //  Referenced by:
                                         //    '<S65>/Saturate'
                                         //    '<S67>/DeadZone'

  real_T PIDController_UpperSaturatio_bf;// Mask Parameter: PIDController_UpperSaturatio_bf
                                         //  Referenced by:
                                         //    '<S68>/Saturate'
                                         //    '<S70>/DeadZone'

  real_T PIDController_UpperSaturatio_ba;// Mask Parameter: PIDController_UpperSaturatio_ba
                                         //  Referenced by:
                                         //    '<S71>/Saturate'
                                         //    '<S73>/DeadZone'

  int32_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                       //  Referenced by: '<S1>/Constant'

  SL_Bus_Controller_std_msgs_Float64MultiArray Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S74>/Out1'

  SL_Bus_Controller_std_msgs_Float64MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S11>/Constant'

  SL_Bus_Controller_std_msgs_UInt16MultiArray Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                               //  Referenced by: '<S76>/Constant'

  SL_Bus_Controller_geometry_msgs_Twist Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                                  //  Referenced by: '<S49>/Out1'

  SL_Bus_Controller_geometry_msgs_Twist Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                         //  Referenced by: '<S9>/Constant'

  real_T nocontrol_Value[6];           // Expression: zeros(6,1)
                                       //  Referenced by: '<Root>/no control'

  real_T Getcontrollertype_SampleTime; // Expression: SampleTime
                                       //  Referenced by: '<Root>/Get controller type'

  real_T Gettest_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<Root>/Get test'

  real_T yawerrorradians_Y0;           // Computed Parameter: yawerrorradians_Y0
                                       //  Referenced by: '<S2>/yaw error [radians]'

  real_T pitcherrorradians_Y0;         // Computed Parameter: pitcherrorradians_Y0
                                       //  Referenced by: '<S2>/pitch error [radians]'

  real_T rollerrorradians_Y0;          // Computed Parameter: rollerrorradians_Y0
                                       //  Referenced by: '<S2>/roll error [radians]'

  real_T angular_velxerrorradians_Y0;  // Computed Parameter: angular_velxerrorradians_Y0
                                       //  Referenced by: '<S2>/angular_vel x error [radians]'

  real_T angular_velyerrorradians_Y0;  // Computed Parameter: angular_velyerrorradians_Y0
                                       //  Referenced by: '<S2>/angular_vel y error [radians]'

  real_T angular_velzerrorradians_Y0;  // Computed Parameter: angular_velzerrorradians_Y0
                                       //  Referenced by: '<S2>/angular_vel z error [radians]'

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

  real_T GetParameter5_SampleTime;     // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get Parameter5'

  real_T GetParameter4_SampleTime;     // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get Parameter4'

  real_T GetParameter3_SampleTime;     // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get Parameter3'

  real_T GetParameter2_SampleTime;     // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get Parameter2'

  real_T GetParameter1_SampleTime;     // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get Parameter1'

  real_T GetParameter_SampleTime;      // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get Parameter'

  real_T angular_velX_Y0;              // Computed Parameter: angular_velX_Y0
                                       //  Referenced by: '<S4>/<angular_vel X>'

  real_T angular_velY_Y0;              // Computed Parameter: angular_velY_Y0
                                       //  Referenced by: '<S4>/<angular_vel Y>'

  real_T angular_velZ_Y0;              // Computed Parameter: angular_velZ_Y0
                                       //  Referenced by: '<S4>/<angular_vel Z> '

  real_T velocityX_Y0;                 // Computed Parameter: velocityX_Y0
                                       //  Referenced by: '<S4>/<velocity X>'

  real_T veloctiyY_Y0;                 // Computed Parameter: veloctiyY_Y0
                                       //  Referenced by: '<S4>/<veloctiy Y>'

  real_T velocityZ_Y0;                 // Computed Parameter: velocityZ_Y0
                                       //  Referenced by: '<S4>/<velocity Z>'

  real_T yaw_ref_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S5>/yaw_ref'

  real_T pitch_ref_SampleTime;         // Expression: SampleTime
                                       //  Referenced by: '<S5>/pitch_ref'

  real_T roll_ref_SampleTime;          // Expression: SampleTime
                                       //  Referenced by: '<S5>/roll_ref'

  real_T I_pitch_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S23>/I_pitch'

  real_T N_pitch_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S23>/N_pitch '

  real_T D_pitch_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S23>/D_pitch'

  real_T P_pitch_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S23>/P_pitch'

  real_T I_roll_SampleTime;            // Expression: SampleTime
                                       //  Referenced by: '<S26>/I_roll'

  real_T N_roll_SampleTime;            // Expression: SampleTime
                                       //  Referenced by: '<S26>/N_roll '

  real_T D_roll_SampleTime;            // Expression: SampleTime
                                       //  Referenced by: '<S26>/D_roll'

  real_T P_roll_SampleTime;            // Expression: SampleTime
                                       //  Referenced by: '<S26>/P_roll'

  real_T I_yaw_SampleTime;             // Expression: SampleTime
                                       //  Referenced by: '<S29>/I_yaw'

  real_T N_yaw_SampleTime;             // Expression: SampleTime
                                       //  Referenced by: '<S29>/N_yaw '

  real_T D_yaw_SampleTime;             // Expression: SampleTime
                                       //  Referenced by: '<S29>/D_yaw'

  real_T P_yaw_SampleTime;             // Expression: SampleTime
                                       //  Referenced by: '<S29>/P_yaw'

  real_T Out2_Y0;                      // Computed Parameter: Out2_Y0
                                       //  Referenced by: '<S5>/Out2'

  real_T Constant_Value_b;             // Expression: 0
                                       //  Referenced by: '<S5>/Constant'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                       //  Referenced by: '<S25>/Integrator'

  real_T Integrator_IC;                // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S25>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                       //  Referenced by: '<S25>/Filter'

  real_T Filter_IC;                    // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S25>/Filter'

  real_T Integrator_gainval_b;         // Computed Parameter: Integrator_gainval_b
                                       //  Referenced by: '<S22>/Integrator'

  real_T Integrator_IC_n;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S22>/Integrator'

  real_T Filter_gainval_l;             // Computed Parameter: Filter_gainval_l
                                       //  Referenced by: '<S22>/Filter'

  real_T Filter_IC_a;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S22>/Filter'

  real_T Integrator_gainval_l;         // Computed Parameter: Integrator_gainval_l
                                       //  Referenced by: '<S28>/Integrator'

  real_T Integrator_IC_e;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S28>/Integrator'

  real_T Filter_gainval_e;             // Computed Parameter: Filter_gainval_e
                                       //  Referenced by: '<S28>/Filter'

  real_T Filter_IC_e;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S28>/Filter'

  real_T ZeroGain_Gain;                // Expression: 0
                                       //  Referenced by: '<S24>/ZeroGain'

  real_T Constant_Value_d0;            // Expression: 0
                                       //  Referenced by: '<S22>/Constant'

  real_T ZeroGain_Gain_g;              // Expression: 0
                                       //  Referenced by: '<S27>/ZeroGain'

  real_T Constant_Value_g;             // Expression: 0
                                       //  Referenced by: '<S25>/Constant'

  real_T ZeroGain_Gain_n;              // Expression: 0
                                       //  Referenced by: '<S30>/ZeroGain'

  real_T Constant_Value_e;             // Expression: 0
                                       //  Referenced by: '<S28>/Constant'

  real_T Swtichingfactor2_SampleTime;  // Expression: SampleTime
                                       //  Referenced by: '<S31>/Swtiching factor2'

  real_T Swtichingfactor1_SampleTime;  // Expression: SampleTime
                                       //  Referenced by: '<S31>/Swtiching factor1'

  real_T Swtichingfactor_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S31>/Swtiching factor'

  real_T Swtichingfactor2_SampleTime_b;// Expression: SampleTime
                                       //  Referenced by: '<S32>/Swtiching factor2'

  real_T Swtichingfactor1_SampleTime_i;// Expression: SampleTime
                                       //  Referenced by: '<S32>/Swtiching factor1'

  real_T Swtichingfactor_SampleTime_k; // Expression: SampleTime
                                       //  Referenced by: '<S32>/Swtiching factor'

  real_T Swtichingfactor2_SampleTime_o;// Expression: SampleTime
                                       //  Referenced by: '<S33>/Swtiching factor2'

  real_T Swtichingfactor1_SampleTime_o;// Expression: SampleTime
                                       //  Referenced by: '<S33>/Swtiching factor1'

  real_T Swtichingfactor_SampleTime_g; // Expression: SampleTime
                                       //  Referenced by: '<S33>/Swtiching factor'

  real_T Swtichingfactor2_SampleTime_e;// Expression: SampleTime
                                       //  Referenced by: '<S34>/Swtiching factor2'

  real_T Swtichingfactor1_SampleTime_j;// Expression: SampleTime
                                       //  Referenced by: '<S34>/Swtiching factor1'

  real_T Swtichingfactor_SampleTime_n; // Expression: SampleTime
                                       //  Referenced by: '<S34>/Swtiching factor'

  real_T Swtichingfactor2_SampleTime_n;// Expression: SampleTime
                                       //  Referenced by: '<S35>/Swtiching factor2'

  real_T Swtichingfactor1_SampleTime_a;// Expression: SampleTime
                                       //  Referenced by: '<S35>/Swtiching factor1'

  real_T Swtichingfactor_SampleTime_nq;// Expression: SampleTime
                                       //  Referenced by: '<S35>/Swtiching factor'

  real_T Swtichingfactor2_SampleTime_c;// Expression: SampleTime
                                       //  Referenced by: '<S36>/Swtiching factor2'

  real_T Swtichingfactor1_SampleTime_e;// Expression: SampleTime
                                       //  Referenced by: '<S36>/Swtiching factor1'

  real_T Swtichingfactor_SampleTime_f; // Expression: SampleTime
                                       //  Referenced by: '<S36>/Swtiching factor'

  real_T Thrusters_Y0;                 // Computed Parameter: Thrusters_Y0
                                       //  Referenced by: '<S6>/Thrusters'

  real_T Constant_Value_f;             // Expression: 100
                                       //  Referenced by: '<S31>/Constant'

  real_T Constant_Value_k;             // Expression: 100
                                       //  Referenced by: '<S32>/Constant'

  real_T Constant_Value_a;             // Expression: 100
                                       //  Referenced by: '<S33>/Constant'

  real_T Constant_Value_a4;            // Expression: 100
                                       //  Referenced by: '<S34>/Constant'

  real_T Constant_Value_dg;            // Expression: 100
                                       //  Referenced by: '<S35>/Constant'

  real_T Constant_Value_fo;            // Expression: 100
                                       //  Referenced by: '<S36>/Constant'

  real_T angular_velX_Y0_o;            // Computed Parameter: angular_velX_Y0_o
                                       //  Referenced by: '<S7>/<angular_vel X>'

  real_T angular_velY_Y0_j;            // Computed Parameter: angular_velY_Y0_j
                                       //  Referenced by: '<S7>/<angular_vel Y>'

  real_T angular_velZ_Y0_g;            // Computed Parameter: angular_velZ_Y0_g
                                       //  Referenced by: '<S7>/<angular_vel Z> '

  real_T velocityX_Y0_f;               // Computed Parameter: velocityX_Y0_f
                                       //  Referenced by: '<S7>/<velocity X>'

  real_T veloctiyY_Y0_a;               // Computed Parameter: veloctiyY_Y0_a
                                       //  Referenced by: '<S7>/<veloctiy Y>'

  real_T velocityZ_Y0_l;               // Computed Parameter: velocityZ_Y0_l
                                       //  Referenced by: '<S7>/<velocity Z>'

  real_T Getalpha_SampleTime;          // Expression: SampleTime
                                       //  Referenced by: '<S8>/Get alpha'

  real_T Enableintegration_SampleTime; // Expression: SampleTime
                                       //  Referenced by: '<S8>/Enable integration?'

  real_T I_angular_vel_x_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S57>/I_angular_vel_x'

  real_T N_angular_vel_x_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S57>/N_angular_vel_x '

  real_T D_angular_vel_x_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S57>/D_angular_vel_x'

  real_T P_angular_vel_x_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S57>/P_angular_vel_x'

  real_T I_angular_vel_y_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S60>/I_angular_vel_y'

  real_T N_angular_vel_y_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S60>/N_angular_vel_y '

  real_T D_angular_vel_y_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S60>/D_angular_vel_y'

  real_T P_angular_vel_y_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S60>/P_angular_vel_y'

  real_T I_angular_vel_z_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S63>/I_angular_vel_z'

  real_T N_angular_vel_z_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S63>/N_angular_vel_z '

  real_T D_angular_vel_z_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S63>/D_angular_vel_z'

  real_T P_angular_vel_z_SampleTime;   // Expression: SampleTime
                                       //  Referenced by: '<S63>/P_angular_vel_z'

  real_T I_vel_x_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S66>/I_vel_x'

  real_T N_vel_x_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S66>/N_vel_x '

  real_T D_vel_x_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S66>/D_vel_x'

  real_T P_vel_x_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S66>/P_vel_x'

  real_T I_vel_y_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S69>/I_vel_y'

  real_T N_vel_y_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S69>/N_vel_y '

  real_T D_vel_y_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S69>/D_vel_y'

  real_T P_vel_y_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S69>/P_vel_y'

  real_T I_vel_z_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S72>/I_vel_z'

  real_T N_vel_z_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S72>/N_vel_z '

  real_T D_vel_z_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S72>/D_vel_z'

  real_T P_vel_z_SampleTime;           // Expression: SampleTime
                                       //  Referenced by: '<S72>/P_vel_z'

  real_T velociteslinearxyzangularxyz_Y0;// Computed Parameter: velociteslinearxyzangularxyz_Y0
                                         //  Referenced by: '<S10>/velocites [linear xyz, angular xyz]'

  real_T Integrator_gainval_h;         // Computed Parameter: Integrator_gainval_h
                                       //  Referenced by: '<S56>/Integrator'

  real_T Integrator_IC_i;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S56>/Integrator'

  real_T Filter_gainval_n;             // Computed Parameter: Filter_gainval_n
                                       //  Referenced by: '<S56>/Filter'

  real_T Filter_IC_h;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S56>/Filter'

  real_T ZeroGain_Gain_d;              // Expression: 0
                                       //  Referenced by: '<S58>/ZeroGain'

  real_T Constant_Value_ke;            // Expression: 0
                                       //  Referenced by: '<S56>/Constant'

  real_T Integrator_gainval_c;         // Computed Parameter: Integrator_gainval_c
                                       //  Referenced by: '<S59>/Integrator'

  real_T Integrator_IC_o;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S59>/Integrator'

  real_T Filter_gainval_i;             // Computed Parameter: Filter_gainval_i
                                       //  Referenced by: '<S59>/Filter'

  real_T Filter_IC_n;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S59>/Filter'

  real_T ZeroGain_Gain_k;              // Expression: 0
                                       //  Referenced by: '<S61>/ZeroGain'

  real_T Constant_Value_m;             // Expression: 0
                                       //  Referenced by: '<S59>/Constant'

  real_T Integrator_gainval_n;         // Computed Parameter: Integrator_gainval_n
                                       //  Referenced by: '<S62>/Integrator'

  real_T Integrator_IC_d;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S62>/Integrator'

  real_T Filter_gainval_k;             // Computed Parameter: Filter_gainval_k
                                       //  Referenced by: '<S62>/Filter'

  real_T Filter_IC_c;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S62>/Filter'

  real_T ZeroGain_Gain_a;              // Expression: 0
                                       //  Referenced by: '<S64>/ZeroGain'

  real_T Constant_Value_fw;            // Expression: 0
                                       //  Referenced by: '<S62>/Constant'

  real_T Integrator_gainval_j;         // Computed Parameter: Integrator_gainval_j
                                       //  Referenced by: '<S65>/Integrator'

  real_T Integrator_IC_el;             // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S65>/Integrator'

  real_T Filter_gainval_h;             // Computed Parameter: Filter_gainval_h
                                       //  Referenced by: '<S65>/Filter'

  real_T Filter_IC_j;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S65>/Filter'

  real_T ZeroGain_Gain_j;              // Expression: 0
                                       //  Referenced by: '<S67>/ZeroGain'

  real_T Constant_Value_m0;            // Expression: 0
                                       //  Referenced by: '<S65>/Constant'

  real_T Integrator_gainval_np;        // Computed Parameter: Integrator_gainval_np
                                       //  Referenced by: '<S68>/Integrator'

  real_T Integrator_IC_ig;             // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S68>/Integrator'

  real_T Filter_gainval_h0;            // Computed Parameter: Filter_gainval_h0
                                       //  Referenced by: '<S68>/Filter'

  real_T Filter_IC_jx;                 // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S68>/Filter'

  real_T ZeroGain_Gain_jk;             // Expression: 0
                                       //  Referenced by: '<S70>/ZeroGain'

  real_T Constant_Value_p;             // Expression: 0
                                       //  Referenced by: '<S68>/Constant'

  real_T Integrator_gainval_m;         // Computed Parameter: Integrator_gainval_m
                                       //  Referenced by: '<S71>/Integrator'

  real_T Integrator_IC_m;              // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S71>/Integrator'

  real_T Filter_gainval_b;             // Computed Parameter: Filter_gainval_b
                                       //  Referenced by: '<S71>/Filter'

  real_T Filter_IC_p;                  // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S71>/Filter'

  real_T ZeroGain_Gain_p;              // Expression: 0
                                       //  Referenced by: '<S73>/ZeroGain'

  real_T Constant_Value_l;             // Expression: 0
                                       //  Referenced by: '<S71>/Constant'

  real_T yawradians_Y0;                // Computed Parameter: yawradians_Y0
                                       //  Referenced by: '<S12>/<yaw [radians]>'

  real_T pitchradians_Y0;              // Computed Parameter: pitchradians_Y0
                                       //  Referenced by: '<S12>/<pitch [radians]>'

  real_T rollradians_Y0;               // Computed Parameter: rollradians_Y0
                                       //  Referenced by: '<S12>/<roll [radians]>'

  real_T angular_velXradianss_Y0;      // Computed Parameter: angular_velXradianss_Y0
                                       //  Referenced by: '<S12>/<angular_vel X [radians//s]>'

  real_T angular_velYradianss_Y0;      // Computed Parameter: angular_velYradianss_Y0
                                       //  Referenced by: '<S12>/<angular_vel Y [radians//s]>'

  real_T angular_velZradianss_Y0;      // Computed Parameter: angular_velZradianss_Y0
                                       //  Referenced by: '<S12>/<angular_vel Z [radians//s]>'

  real_T Zm_Y0;                        // Computed Parameter: Zm_Y0
                                       //  Referenced by: '<S12>/<Z [m]>'

  real_T accXms2_Y0;                   // Computed Parameter: accXms2_Y0
                                       //  Referenced by: '<S12>/<acc X [m//s^2]>'

  real_T accYms2_Y0;                   // Computed Parameter: accYms2_Y0
                                       //  Referenced by: '<S12>/<acc Y [m//s^2]>'

  real_T accZms2_Y0;                   // Computed Parameter: accZms2_Y0
                                       //  Referenced by: '<S12>/<acc Z [m//s^2]>'

  real_T GetParameter5_SampleTime_p;   // Expression: SampleTime
                                       //  Referenced by: '<S78>/Get Parameter5'

  real_T GetParameter4_SampleTime_b;   // Expression: SampleTime
                                       //  Referenced by: '<S78>/Get Parameter4'

  real_T GetParameter3_SampleTime_n;   // Expression: SampleTime
                                       //  Referenced by: '<S78>/Get Parameter3'

  real_T GetParameter2_SampleTime_m;   // Expression: SampleTime
                                       //  Referenced by: '<S78>/Get Parameter2'

  real_T GetParameter1_SampleTime_a;   // Expression: SampleTime
                                       //  Referenced by: '<S78>/Get Parameter1'

  real_T GetParameter_SampleTime_e;    // Expression: SampleTime
                                       //  Referenced by: '<S78>/Get Parameter'

  real_T Saturation_UpperSat;          // Expression: 1
                                       //  Referenced by: '<S16>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -1
                                       //  Referenced by: '<S16>/Saturation'

  real_T DiscreteTimeIntegrator_gainval;// Computed Parameter: DiscreteTimeIntegrator_gainval
                                        //  Referenced by: '<S8>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                       //  Referenced by: '<S8>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator1_gainval;// Computed Parameter: DiscreteTimeIntegrator1_gainval
                                         //  Referenced by: '<S8>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                       //  Referenced by: '<S8>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator2_gainval;// Computed Parameter: DiscreteTimeIntegrator2_gainval
                                         //  Referenced by: '<S8>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_IC;   // Expression: 0
                                       //  Referenced by: '<S8>/Discrete-Time Integrator2'

  real_T Constant_Value_ay;            // Expression: 1
                                       //  Referenced by: '<S8>/Constant'

  real_T DiscreteFilter_NumCoef;       // Expression: [1]
                                       //  Referenced by: '<S8>/Discrete Filter'

  real_T DiscreteFilter_InitialStates; // Expression: 0
                                       //  Referenced by: '<S8>/Discrete Filter'

  real_T DiscreteFilter_InitialDenominat;// Expression: 0
                                         //  Referenced by: '<S8>/Discrete Filter'

  real_T DiscreteFilter1_NumCoef;      // Expression: [1]
                                       //  Referenced by: '<S8>/Discrete Filter1'

  real_T DiscreteFilter1_InitialStates;// Expression: 0
                                       //  Referenced by: '<S8>/Discrete Filter1'

  real_T DiscreteFilter1_InitialDenomina;// Expression: 0
                                         //  Referenced by: '<S8>/Discrete Filter1'

  real_T DiscreteFilter2_NumCoef;      // Expression: [1]
                                       //  Referenced by: '<S8>/Discrete Filter2'

  real_T DiscreteFilter2_InitialStates;// Expression: 0
                                       //  Referenced by: '<S8>/Discrete Filter2'

  real_T DiscreteFilter2_InitialDenomina;// Expression: 0
                                         //  Referenced by: '<S8>/Discrete Filter2'

  SL_Bus_Controller_std_msgs_Bool Out1_Y0_i;// Computed Parameter: Out1_Y0_i
                                            //  Referenced by: '<S17>/Out1'

  SL_Bus_Controller_std_msgs_Bool Constant_Value_ba;// Computed Parameter: Constant_Value_ba
                                                    //  Referenced by: '<S3>/Constant'

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
//  '<S3>'   : 'Controller/Enable thrusters'
//  '<S4>'   : 'Controller/Enabled Subsystem'
//  '<S5>'   : 'Controller/Subsystem'
//  '<S6>'   : 'Controller/Telegraph'
//  '<S7>'   : 'Controller/Xbox_input'
//  '<S8>'   : 'Controller/acc integration'
//  '<S9>'   : 'Controller/cmd_vel'
//  '<S10>'  : 'Controller/decController'
//  '<S11>'  : 'Controller/imu_data'
//  '<S12>'  : 'Controller/states'
//  '<S13>'  : 'Controller/thrust alloc'
//  '<S14>'  : 'Controller/thrust alloc1'
//  '<S15>'  : 'Controller/thrust alloc2'
//  '<S16>'  : 'Controller/toPWM'
//  '<S17>'  : 'Controller/Enable thrusters/Enabled Subsystem'
//  '<S18>'  : 'Controller/Subsystem/convert to local'
//  '<S19>'  : 'Controller/Subsystem/pitch_control'
//  '<S20>'  : 'Controller/Subsystem/roll_control'
//  '<S21>'  : 'Controller/Subsystem/yaw_control'
//  '<S22>'  : 'Controller/Subsystem/pitch_control/PID Controller'
//  '<S23>'  : 'Controller/Subsystem/pitch_control/Retrive PID-Parameters'
//  '<S24>'  : 'Controller/Subsystem/pitch_control/PID Controller/Clamping circuit'
//  '<S25>'  : 'Controller/Subsystem/roll_control/PID Controller'
//  '<S26>'  : 'Controller/Subsystem/roll_control/Retrive PID-Parameters'
//  '<S27>'  : 'Controller/Subsystem/roll_control/PID Controller/Clamping circuit'
//  '<S28>'  : 'Controller/Subsystem/yaw_control/PID Controller'
//  '<S29>'  : 'Controller/Subsystem/yaw_control/Retrive PID-Parameters'
//  '<S30>'  : 'Controller/Subsystem/yaw_control/PID Controller/Clamping circuit'
//  '<S31>'  : 'Controller/Telegraph/Thruster1 block'
//  '<S32>'  : 'Controller/Telegraph/Thruster2 block'
//  '<S33>'  : 'Controller/Telegraph/Thruster3 block'
//  '<S34>'  : 'Controller/Telegraph/Thruster4 block'
//  '<S35>'  : 'Controller/Telegraph/Thruster5 block '
//  '<S36>'  : 'Controller/Telegraph/Thruster6 block'
//  '<S37>'  : 'Controller/Telegraph/Thruster1 block/MATLAB Function'
//  '<S38>'  : 'Controller/Telegraph/Thruster1 block/State Transition Table'
//  '<S39>'  : 'Controller/Telegraph/Thruster2 block/MATLAB Function'
//  '<S40>'  : 'Controller/Telegraph/Thruster2 block/State Transition Table'
//  '<S41>'  : 'Controller/Telegraph/Thruster3 block/MATLAB Function'
//  '<S42>'  : 'Controller/Telegraph/Thruster3 block/State Transition Table'
//  '<S43>'  : 'Controller/Telegraph/Thruster4 block/MATLAB Function'
//  '<S44>'  : 'Controller/Telegraph/Thruster4 block/State Transition Table'
//  '<S45>'  : 'Controller/Telegraph/Thruster5 block /MATLAB Function'
//  '<S46>'  : 'Controller/Telegraph/Thruster5 block /State Transition Table'
//  '<S47>'  : 'Controller/Telegraph/Thruster6 block/MATLAB Function'
//  '<S48>'  : 'Controller/Telegraph/Thruster6 block/State Transition Table'
//  '<S49>'  : 'Controller/cmd_vel/Enabled Subsystem'
//  '<S50>'  : 'Controller/decController/angular_vel x'
//  '<S51>'  : 'Controller/decController/angular_vel y'
//  '<S52>'  : 'Controller/decController/angular_vel z'
//  '<S53>'  : 'Controller/decController/vel x'
//  '<S54>'  : 'Controller/decController/vel y'
//  '<S55>'  : 'Controller/decController/vel z'
//  '<S56>'  : 'Controller/decController/angular_vel x/PID Controller'
//  '<S57>'  : 'Controller/decController/angular_vel x/Retrive PID-Parameters'
//  '<S58>'  : 'Controller/decController/angular_vel x/PID Controller/Clamping circuit'
//  '<S59>'  : 'Controller/decController/angular_vel y/PID Controller'
//  '<S60>'  : 'Controller/decController/angular_vel y/Retrive PID-Parameters'
//  '<S61>'  : 'Controller/decController/angular_vel y/PID Controller/Clamping circuit'
//  '<S62>'  : 'Controller/decController/angular_vel z/PID Controller'
//  '<S63>'  : 'Controller/decController/angular_vel z/Retrive PID-Parameters'
//  '<S64>'  : 'Controller/decController/angular_vel z/PID Controller/Clamping circuit'
//  '<S65>'  : 'Controller/decController/vel x/PID Controller'
//  '<S66>'  : 'Controller/decController/vel x/Retrive PID-Parameters'
//  '<S67>'  : 'Controller/decController/vel x/PID Controller/Clamping circuit'
//  '<S68>'  : 'Controller/decController/vel y/PID Controller'
//  '<S69>'  : 'Controller/decController/vel y/Retrive PID-Parameters'
//  '<S70>'  : 'Controller/decController/vel y/PID Controller/Clamping circuit'
//  '<S71>'  : 'Controller/decController/vel z/PID Controller'
//  '<S72>'  : 'Controller/decController/vel z/Retrive PID-Parameters'
//  '<S73>'  : 'Controller/decController/vel z/PID Controller/Clamping circuit'
//  '<S74>'  : 'Controller/imu_data/Enabled Subsystem'
//  '<S75>'  : 'Controller/states/removeGravity'
//  '<S76>'  : 'Controller/toPWM/Actuator message '
//  '<S77>'  : 'Controller/toPWM/Calc pwm signal'
//  '<S78>'  : 'Controller/toPWM/Enable thrusters '
//  '<S79>'  : 'Controller/toPWM/PWM assign'
//  '<S80>'  : 'Controller/toPWM/Publish'


//-
//  Requirements for '<Root>': Controller

#endif                                 // RTW_HEADER_Controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
