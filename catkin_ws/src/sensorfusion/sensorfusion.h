//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: sensorfusion.h
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
#ifndef RTW_HEADER_sensorfusion_h_
#define RTW_HEADER_sensorfusion_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef sensorfusion_COMMON_INCLUDES_
# define sensorfusion_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // sensorfusion_COMMON_INCLUDES_

#include "sensorfusion_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define sensorfusion_M                 (rtM)

// Block signals (auto storage)
typedef struct {
  SL_Bus_sensorfusion_std_msgs_Float64MultiArray out_message;// '<S3>/MATLAB Function' 
  SL_Bus_sensorfusion_std_msgs_Float32MultiArray In1;// '<S6>/In1'
  SL_Bus_sensorfusion_std_msgs_Float32MultiArray varargout_2;
  real_T OutportBufferForP_time_update[25];// '<S4>/Time update'
  real_T OutportBufferForP_measurement_u[25];// '<S2>/MATLAB Function'
  real_T F[25];
  real_T F_m[25];
  real_T F_c[25];
  real_T Gv[25];
  real_T Gv_k[20];
  real_T Gv_c[20];
  real_T H_acc[15];
  real_T K[15];
  real_T F_b[15];
  real_T DataTypeConversion[10];       // '<S1>/Data Type Conversion'
  real_T CreateDiagonalMatrixRacc[9];  // '<S2>/Create Diagonal Matrix R acc'
  real_T CreateDiagonalMatrixRmag[9];  // '<S2>/Create Diagonal Matrix R mag'
  real_T H_acc_p[9];
  real_T b_A[9];
  real_T InitialStates[5];             // '<Root>/Initial States'
  real_T OutportBufferForStates_time_upd[5];// '<S4>/Time update'
  real_T OutportBufferForStates_measurem[5];// '<S2>/MATLAB Function'
  real_T H_pressure[5];
  real_T b_K[5];
  real_T states_update_j[5];           // '<S2>/MATLAB Function'
  real_T H_pressure_c[5];
  char_T cv0[39];
  char_T cv1[35];
  char_T cv2[31];
  char_T cv3[30];
  char_T cv4[28];
  char_T cv5[27];
  real_T TmpSignalConversionAtCreate[3];
  real_T rtb_TmpSignalConversionAtCrea_f[3];
  real_T rtb_Getepsacc_d;
  real_T innovation;
  real_T xzpwy;
  real_T d0;
  real_T b_b_data;
  real_T tmp_data;
  real_T q_data;
  real_T q_data_d;
  real_T q_idx_1;
  real_T q_idx_2;
  real_T q_idx_3;
  real_T rtb_DataTypeConversion_idx_1;
  int32_T b_b_sizes[2];
  int32_T q_sizes[2];
  int32_T tmp_sizes[2];
  int32_T tmp_sizes_g[2];
  int32_T q_sizes_g[2];
  int32_T q_sizes_m[2];
  int32_T tmp_sizes_n[2];
  int32_T tmp_sizes_p[2];
  int32_T q_sizes_l[2];
  int32_T q_sizes_j[2];
  int32_T q_sizes_d[2];
  int32_T q_sizes_gu[2];
  int32_T q_sizes_ld[2];
} BlockIO;

// Block states (auto storage) for system '<Root>'
typedef struct {
  robotics_slros_internal_block_G obj; // '<S4>/Get T'
  robotics_slros_internal_block_G obj_m;// '<S2>/get R acc [1,1]'
  robotics_slros_internal_block_G obj_h;// '<S2>/get R acc[2,2]'
  robotics_slros_internal_block_G obj_mc;// '<S2>/get R acc [3,3]'
  robotics_slros_internal_block_G obj_i;// '<S2>/get R mag [1,1]'
  robotics_slros_internal_block_G obj_k;// '<S2>/get R mag [2,2]'
  robotics_slros_internal_block_G obj_p;// '<S2>/get R mag [3,3]'
  robotics_slros_internal_block_G obj_b;// '<S2>/Get eps acc'
  robotics_slros_internal_block_G obj_f;// '<S2>/Get eps mag'
  robotics_slros_internal_block_G obj_c;// '<S2>/Get gravitational constant'
  robotics_slros_internal_block_G obj_e;// '<S2>/Get water density'
  robotics_slros_internal_block_G obj_hb;// '<S2>/Get x offset of  pressure sensor' 
  robotics_slros_internal_block_G obj_l;// '<S2>/enable acc'
  robotics_slros_internal_block_G obj_ls;// '<S2>/enable mag'
  robotics_slros_internal_block_G obj_mh;// '<S2>/enable pressure'
  robotics_slros_internal_block_G obj_g;// '<S2>/get R pressure [1,1]'
  real_T InitialStates_PreviousInput[5];// '<Root>/Initial States'
  real_T InitialP_PreviousInput[25];   // '<Root>/Initial P'
  struct {
    void *AQHandles;
  } HiddenToAsyncQueue_InsertedFor_;   // synthesized block

  void *GetT_PWORK;                    // '<S4>/Get T'
  void *SinkBlock_PWORK;               // '<S10>/SinkBlock'
  void *getRacc11_PWORK;               // '<S2>/get R acc [1,1]'
  void *getRacc22_PWORK;               // '<S2>/get R acc[2,2]'
  void *getRacc33_PWORK;               // '<S2>/get R acc [3,3]'
  void *getRmag11_PWORK;               // '<S2>/get R mag [1,1]'
  void *getRmag22_PWORK;               // '<S2>/get R mag [2,2]'
  void *getRmag33_PWORK;               // '<S2>/get R mag [3,3]'
  void *Getepsacc_PWORK;               // '<S2>/Get eps acc'
  void *Getepsmag_PWORK;               // '<S2>/Get eps mag'
  void *Getgravitationalconstant_PWORK;// '<S2>/Get gravitational constant'
  void *Getwaterdensity_PWORK;         // '<S2>/Get water density'
  void *Getxoffsetofpressuresensor_PWOR;// '<S2>/Get x offset of  pressure sensor' 
  void *enableacc_PWORK;               // '<S2>/enable acc'
  void *enablemag_PWORK;               // '<S2>/enable mag'
  void *enablepressure_PWORK;          // '<S2>/enable pressure'
  void *getRpressure11_PWORK;          // '<S2>/get R pressure [1,1]'
  void *SourceBlock_PWORK;             // '<S5>/SourceBlock'
  robotics_slros_internal_block_S obj_po;// '<S5>/SourceBlock'
  robotics_slros_internal_block_P obj_ic;// '<S10>/SinkBlock'
  boolean_T objisempty;                // '<S4>/Get T'
  boolean_T objisempty_h;              // '<S10>/SinkBlock'
  boolean_T objisempty_e;              // '<S2>/get R acc [1,1]'
  boolean_T objisempty_c;              // '<S2>/get R acc[2,2]'
  boolean_T objisempty_l;              // '<S2>/get R acc [3,3]'
  boolean_T objisempty_g;              // '<S2>/get R mag [1,1]'
  boolean_T objisempty_b;              // '<S2>/get R mag [2,2]'
  boolean_T objisempty_n;              // '<S2>/get R mag [3,3]'
  boolean_T objisempty_gy;             // '<S2>/Get eps acc'
  boolean_T objisempty_k;              // '<S2>/Get eps mag'
  boolean_T objisempty_bb;             // '<S2>/Get gravitational constant'
  boolean_T objisempty_j;              // '<S2>/Get water density'
  boolean_T objisempty_m;              // '<S2>/Get x offset of  pressure sensor' 
  boolean_T objisempty_hk;             // '<S2>/enable acc'
  boolean_T objisempty_mi;             // '<S2>/enable mag'
  boolean_T objisempty_ji;             // '<S2>/enable pressure'
  boolean_T objisempty_o;              // '<S2>/get R pressure [1,1]'
  boolean_T objisempty_jw;             // '<S5>/SourceBlock'
} D_Work;

// Constant parameters (auto storage)
typedef struct {
  // Expression: eye(4).*100
  //  Referenced by: '<S4>/Constant2'

  real_T Constant2_Value[16];

  // Expression: [1,0,0,0,0]'
  //  Referenced by: '<Root>/Initial States'

  real_T InitialStates_X0[5];

  // Expression: eye(5).*100
  //  Referenced by: '<Root>/Initial P'

  real_T InitialP_X0[25];
} ConstParam;

// Real-time Model Data Structure
struct tag_RTM {
  const char_T *errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Constant parameters (auto storage)
extern const ConstParam rtConstP;

// External data declarations for dependent source files
extern const SL_Bus_sensorfusion_std_msgs_Float64MultiArray
  sensorfusion_rtZSL_Bus_sensorfusion_std_msgs_Float64MultiArray;// SL_Bus_sensorfusion_std_msgs_Float64MultiArray ground 

// Class declaration for model sensorfusion
class sensorfusionModelClass {
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
  sensorfusionModelClass();

  // Destructor
  ~sensorfusionModelClass();

  // Real-Time Model get method
  RT_MODEL * getRTM();

  // private data and function members
 private:
  // Block signals
  BlockIO rtB;

  // Block states
  D_Work rtDWork;

  // Real-Time Model
  RT_MODEL rtM;

  // private member function(s) for subsystem '<Root>'
  real_T norm(const real_T x[3]);
  void mrdivide(const real_T A[15], const real_T B[9], real_T y[15]);
  real_T norm_p(const real_T x[4]);
  void atan2_o(const real_T y_data[], const int32_T y_sizes[2], const real_T
               x_data[], const int32_T x_sizes[2], real_T r_data[], int32_T
               r_sizes[2]);
  void power(const real_T a_data[], const int32_T a_sizes[2], real_T y_data[],
             int32_T y_sizes[2]);
  void mod(const real_T x[3], real_T r[3]);
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
//  '<Root>' : 'sensorfusion'
//  '<S1>'   : 'sensorfusion/Get measurements'
//  '<S2>'   : 'sensorfusion/Measurement update'
//  '<S3>'   : 'sensorfusion/Send states and measurements'
//  '<S4>'   : 'sensorfusion/Time update'
//  '<S5>'   : 'sensorfusion/Get measurements/Subscribe'
//  '<S6>'   : 'sensorfusion/Get measurements/Subscribe/Enabled Subsystem'
//  '<S7>'   : 'sensorfusion/Measurement update/MATLAB Function'
//  '<S8>'   : 'sensorfusion/Send states and measurements/Blank Message'
//  '<S9>'   : 'sensorfusion/Send states and measurements/MATLAB Function'
//  '<S10>'  : 'sensorfusion/Send states and measurements/Publish'
//  '<S11>'  : 'sensorfusion/Time update/Time update'

#endif                                 // RTW_HEADER_sensorfusion_h_

//
// File trailer for generated code.
//
// [EOF]
//
