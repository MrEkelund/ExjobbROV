//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Controller_with_out_ref.cpp
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
#include "Controller_with_out_ref.h"
#include "Controller_with_out_ref_private.h"
#define Control_ParameterInitialValue_i (0.0)
#define Controlle_ParameterInitialValue (0)
#define Controller_wi_MessageQueueLen_i (10)
#define Controller_with_MessageQueueLen (1)

// Function for MATLAB Function: '<S9>/removeGravity'
void ControllerModelClass::Controller_with_out_ref_inv(const real_T x[9], real_T
  y[9])
{
  int32_T p1;
  int32_T p2;
  int32_T p3;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T itmp;
  memcpy(&Controller_with_out_ref_B.b_x[0], &x[0], 9U * sizeof(real_T));
  p1 = 0;
  p2 = 3;
  p3 = 6;
  absx11 = fabs(x[0]);
  absx21 = fabs(x[1]);
  absx31 = fabs(x[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    Controller_with_out_ref_B.b_x[0] = x[1];
    Controller_with_out_ref_B.b_x[1] = x[0];
    Controller_with_out_ref_B.b_x[3] = x[4];
    Controller_with_out_ref_B.b_x[4] = x[3];
    Controller_with_out_ref_B.b_x[6] = x[7];
    Controller_with_out_ref_B.b_x[7] = x[6];
  } else {
    if (absx31 > absx11) {
      p1 = 6;
      p3 = 0;
      Controller_with_out_ref_B.b_x[0] = x[2];
      Controller_with_out_ref_B.b_x[2] = x[0];
      Controller_with_out_ref_B.b_x[3] = x[5];
      Controller_with_out_ref_B.b_x[5] = x[3];
      Controller_with_out_ref_B.b_x[6] = x[8];
      Controller_with_out_ref_B.b_x[8] = x[6];
    }
  }

  absx11 = Controller_with_out_ref_B.b_x[1] / Controller_with_out_ref_B.b_x[0];
  Controller_with_out_ref_B.b_x[1] /= Controller_with_out_ref_B.b_x[0];
  absx21 = Controller_with_out_ref_B.b_x[2] / Controller_with_out_ref_B.b_x[0];
  Controller_with_out_ref_B.b_x[2] /= Controller_with_out_ref_B.b_x[0];
  Controller_with_out_ref_B.b_x[4] -= absx11 * Controller_with_out_ref_B.b_x[3];
  Controller_with_out_ref_B.b_x[5] -= absx21 * Controller_with_out_ref_B.b_x[3];
  Controller_with_out_ref_B.b_x[7] -= absx11 * Controller_with_out_ref_B.b_x[6];
  Controller_with_out_ref_B.b_x[8] -= absx21 * Controller_with_out_ref_B.b_x[6];
  if (fabs(Controller_with_out_ref_B.b_x[5]) > fabs
      (Controller_with_out_ref_B.b_x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    Controller_with_out_ref_B.b_x[1] = absx21;
    Controller_with_out_ref_B.b_x[2] = absx11;
    absx11 = Controller_with_out_ref_B.b_x[4];
    Controller_with_out_ref_B.b_x[4] = Controller_with_out_ref_B.b_x[5];
    Controller_with_out_ref_B.b_x[5] = absx11;
    absx11 = Controller_with_out_ref_B.b_x[7];
    Controller_with_out_ref_B.b_x[7] = Controller_with_out_ref_B.b_x[8];
    Controller_with_out_ref_B.b_x[8] = absx11;
  }

  absx11 = Controller_with_out_ref_B.b_x[5] / Controller_with_out_ref_B.b_x[4];
  Controller_with_out_ref_B.b_x[5] /= Controller_with_out_ref_B.b_x[4];
  Controller_with_out_ref_B.b_x[8] -= absx11 * Controller_with_out_ref_B.b_x[7];
  absx11 = (Controller_with_out_ref_B.b_x[5] * Controller_with_out_ref_B.b_x[1]
            - Controller_with_out_ref_B.b_x[2]) / Controller_with_out_ref_B.b_x
    [8];
  absx21 = -(Controller_with_out_ref_B.b_x[7] * absx11 +
             Controller_with_out_ref_B.b_x[1]) / Controller_with_out_ref_B.b_x[4];
  y[p1] = ((1.0 - Controller_with_out_ref_B.b_x[3] * absx21) -
           Controller_with_out_ref_B.b_x[6] * absx11) /
    Controller_with_out_ref_B.b_x[0];
  y[p1 + 1] = absx21;
  y[p1 + 2] = absx11;
  absx11 = -Controller_with_out_ref_B.b_x[5] / Controller_with_out_ref_B.b_x[8];
  absx21 = (1.0 - Controller_with_out_ref_B.b_x[7] * absx11) /
    Controller_with_out_ref_B.b_x[4];
  y[p2] = -(Controller_with_out_ref_B.b_x[3] * absx21 +
            Controller_with_out_ref_B.b_x[6] * absx11) /
    Controller_with_out_ref_B.b_x[0];
  y[p2 + 1] = absx21;
  y[p2 + 2] = absx11;
  absx11 = 1.0 / Controller_with_out_ref_B.b_x[8];
  absx21 = -Controller_with_out_ref_B.b_x[7] * absx11 /
    Controller_with_out_ref_B.b_x[4];
  y[p3] = -(Controller_with_out_ref_B.b_x[3] * absx21 +
            Controller_with_out_ref_B.b_x[6] * absx11) /
    Controller_with_out_ref_B.b_x[0];
  y[p3 + 1] = absx21;
  y[p3 + 2] = absx11;
}

// Model step function
void ControllerModelClass::step()
{
  boolean_T p;
  boolean_T p_0;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_NotEqual;
  real_T rtb_Switch_ax;
  int32_T i;
  int32_T i_0;
  int8_T rtb_DataTypeConv2_0;
  int8_T tmp;

  // Start for MATLABSystem: '<Root>/Get controller type' incorporates:
  //   MATLABSystem: '<Root>/Get controller type'

  p = false;
  p_0 = true;
  if (!(Controller_with_out_ref_DW.obj_nl.SampleTime ==
        Controller_with_out_ref_P.Getcontrollertype_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_with_out_ref_DW.obj_nl.SampleTime =
      Controller_with_out_ref_P.Getcontrollertype_SampleTime;
  }

  ParamGet_Controller_with_out_ref_106.get_parameter(&i);

  // End of Start for MATLABSystem: '<Root>/Get controller type'

  // Outputs for Atomic SubSystem: '<Root>/cmd_vel'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   MATLABSystem: '<S6>/SourceBlock'

  p = Sub_Controller_with_out_ref_1.get_latest_msg
    (&Controller_with_out_ref_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S14>/In1'

  if (p) {
    Controller_with_out_ref_B.In1_m = Controller_with_out_ref_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/cmd_vel'

  // Outputs for Atomic SubSystem: '<Root>/imu_data'
  // Start for MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   MATLABSystem: '<S8>/SourceBlock'

  p_0 = Sub_Controller_with_out_ref_28.get_latest_msg
    (&Controller_with_out_ref_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S39>/Enable'

  // MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Inport: '<S39>/In1'

  if (p_0) {
    Controller_with_out_ref_B.In1 = Controller_with_out_ref_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/cmd_vel'
  // Logic: '<Root>/Logical Operator' incorporates:
  //   MATLABSystem: '<S6>/SourceBlock'
  //   MATLABSystem: '<S8>/SourceBlock'

  rtb_LogicalOperator = (p || p_0);

  // End of Outputs for SubSystem: '<Root>/cmd_vel'
  // End of Outputs for SubSystem: '<Root>/imu_data'

  // Outputs for Enabled SubSystem: '<Root>/decController' incorporates:
  //   EnablePort: '<S7>/Enable'

  // Outputs for Enabled SubSystem: '<Root>/Create errors' incorporates:
  //   EnablePort: '<S1>/Enable'

  // Outputs for Enabled SubSystem: '<Root>/mavros_data' incorporates:
  //   EnablePort: '<S9>/Enable'

  // Outputs for Enabled SubSystem: '<Root>/Xbox_input' incorporates:
  //   EnablePort: '<S4>/Enable'

  if (rtb_LogicalOperator) {
    // SignalConversion: '<S4>/TmpSignal ConversionAtBus SelectorOutport1'
    Controller_with_out_ref_B.X = Controller_with_out_ref_B.In1_m.Linear.X;

    // SignalConversion: '<S4>/TmpSignal ConversionAtBus SelectorOutport2'
    Controller_with_out_ref_B.Y = Controller_with_out_ref_B.In1_m.Linear.Y;

    // SignalConversion: '<S4>/TmpSignal ConversionAtBus SelectorOutport3'
    Controller_with_out_ref_B.Z = Controller_with_out_ref_B.In1_m.Linear.Z;

    // SignalConversion: '<S4>/TmpSignal ConversionAtBus SelectorOutport4'
    Controller_with_out_ref_B.X_h = Controller_with_out_ref_B.In1_m.Angular.X;

    // SignalConversion: '<S4>/TmpSignal ConversionAtBus SelectorOutport5'
    Controller_with_out_ref_B.Y_i = Controller_with_out_ref_B.In1_m.Angular.Y;

    // SignalConversion: '<S4>/TmpSignal ConversionAtBus SelectorOutport6'
    Controller_with_out_ref_B.Z_n = Controller_with_out_ref_B.In1_m.Angular.Z;

    // Gain: '<S9>/Gain'
    // MATLAB Function 'mavros_data/Conversion': '<S40>:1'
    //  Convert the quaternion to a yaw angle (zyx euler angle)
    // '<S40>:1:5'
    // '<S40>:1:6'
    // '<S40>:1:7'
    // '<S40>:1:8'
    Controller_with_out_ref_B.Gain = Controller_with_out_ref_P.Gain_Gain *
      Controller_with_out_ref_B.In1.AngularVelocity.X;

    // Gain: '<S9>/Gain1'
    Controller_with_out_ref_B.Gain1 = Controller_with_out_ref_P.Gain1_Gain *
      Controller_with_out_ref_B.In1.AngularVelocity.Y;

    // Gain: '<S9>/Gain2'
    Controller_with_out_ref_B.Gain2 = Controller_with_out_ref_P.Gain2_Gain *
      Controller_with_out_ref_B.In1.AngularVelocity.Z;

    // MATLAB Function: '<S9>/removeGravity'
    // MATLAB Function 'mavros_data/removeGravity': '<S41>:1'
    // '<S41>:1:4'
    //  Gravity projected in the body fixed frame
    // '<S41>:1:10'
    Controller_with_out_ref_B.dv0[0] =
      (Controller_with_out_ref_B.In1.Orientation.W *
       Controller_with_out_ref_B.In1.Orientation.W * 2.0 +
       Controller_with_out_ref_B.In1.Orientation.X *
       Controller_with_out_ref_B.In1.Orientation.X * 2.0) - 1.0;
    Controller_with_out_ref_B.dv0[3] = 2.0 *
      Controller_with_out_ref_B.In1.Orientation.X *
      Controller_with_out_ref_B.In1.Orientation.Y - 2.0 *
      Controller_with_out_ref_B.In1.Orientation.W *
      Controller_with_out_ref_B.In1.Orientation.Z;
    Controller_with_out_ref_B.dv0[6] = 2.0 *
      Controller_with_out_ref_B.In1.Orientation.X *
      Controller_with_out_ref_B.In1.Orientation.Z + 2.0 *
      Controller_with_out_ref_B.In1.Orientation.W *
      Controller_with_out_ref_B.In1.Orientation.Y;
    Controller_with_out_ref_B.dv0[1] = 2.0 *
      Controller_with_out_ref_B.In1.Orientation.X *
      Controller_with_out_ref_B.In1.Orientation.Y + 2.0 *
      Controller_with_out_ref_B.In1.Orientation.W *
      Controller_with_out_ref_B.In1.Orientation.Z;
    Controller_with_out_ref_B.dv0[4] =
      (Controller_with_out_ref_B.In1.Orientation.W *
       Controller_with_out_ref_B.In1.Orientation.W * 2.0 +
       Controller_with_out_ref_B.In1.Orientation.Y *
       Controller_with_out_ref_B.In1.Orientation.Y * 2.0) - 1.0;
    Controller_with_out_ref_B.dv0[7] = 2.0 *
      Controller_with_out_ref_B.In1.Orientation.X *
      Controller_with_out_ref_B.In1.Orientation.Z - 2.0 *
      Controller_with_out_ref_B.In1.Orientation.W *
      Controller_with_out_ref_B.In1.Orientation.X;
    Controller_with_out_ref_B.dv0[2] = 2.0 *
      Controller_with_out_ref_B.In1.Orientation.X *
      Controller_with_out_ref_B.In1.Orientation.Z - 2.0 *
      Controller_with_out_ref_B.In1.Orientation.W *
      Controller_with_out_ref_B.In1.Orientation.Y;
    Controller_with_out_ref_B.dv0[5] = 2.0 *
      Controller_with_out_ref_B.In1.Orientation.Y *
      Controller_with_out_ref_B.In1.Orientation.Z + 2.0 *
      Controller_with_out_ref_B.In1.Orientation.W *
      Controller_with_out_ref_B.In1.Orientation.X;
    Controller_with_out_ref_B.dv0[8] =
      (Controller_with_out_ref_B.In1.Orientation.W *
       Controller_with_out_ref_B.In1.Orientation.W * 2.0 +
       Controller_with_out_ref_B.In1.Orientation.Z *
       Controller_with_out_ref_B.In1.Orientation.Z * 2.0) - 1.0;
    Controller_with_out_ref_inv(Controller_with_out_ref_B.dv0,
      Controller_with_out_ref_B.dv1);
    for (i_0 = 0; i_0 < 3; i_0++) {
      Controller_with_out_ref_B.acc[i_0] = Controller_with_out_ref_B.dv1[i_0 + 6]
        * -9.79 + (Controller_with_out_ref_B.dv1[i_0 + 3] * 0.0 +
                   Controller_with_out_ref_B.dv1[i_0] * 0.0);
    }

    // SignalConversion: '<S9>/OutportBufferFor<acc X [m//s^2]>' incorporates:
    //   MATLAB Function: '<S9>/removeGravity'

    //  Removed gravity from the acceleration
    // '<S41>:1:13'
    // '<S41>:1:14'
    // '<S41>:1:15'
    Controller_with_out_ref_B.OutportBufferForaccXms2 =
      Controller_with_out_ref_B.In1.LinearAcceleration.X +
      Controller_with_out_ref_B.acc[0];

    // SignalConversion: '<S9>/OutportBufferFor<acc Y [m//s^2]>' incorporates:
    //   MATLAB Function: '<S9>/removeGravity'

    Controller_with_out_ref_B.OutportBufferForaccYms2 =
      Controller_with_out_ref_B.In1.LinearAcceleration.Y +
      Controller_with_out_ref_B.acc[1];

    // SignalConversion: '<S9>/OutportBufferFor<acc Z [m//s^2]>' incorporates:
    //   MATLAB Function: '<S9>/removeGravity'

    Controller_with_out_ref_B.OutportBufferForaccZms2 =
      Controller_with_out_ref_B.In1.LinearAcceleration.Z +
      Controller_with_out_ref_B.acc[2];

    // Sum: '<S1>/Error x'
    Controller_with_out_ref_B.Errorx = Controller_with_out_ref_B.X_h -
      Controller_with_out_ref_B.Gain;

    // Sum: '<S1>/Error y'
    Controller_with_out_ref_B.Errory = Controller_with_out_ref_B.Y_i -
      Controller_with_out_ref_B.Gain1;

    // Sum: '<S1>/Error z'
    Controller_with_out_ref_B.Errorz = Controller_with_out_ref_B.Z_n -
      Controller_with_out_ref_B.Gain2;

    // Sum: '<S1>/Error z8' incorporates:
    //   DiscreteIntegrator: '<S5>/Discrete-Time Integrator'

    Controller_with_out_ref_B.Errorz8 = Controller_with_out_ref_B.X -
      Controller_with_out_ref_DW.DiscreteTimeIntegrator_DSTATE;

    // Sum: '<S1>/Error z9' incorporates:
    //   DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'

    Controller_with_out_ref_B.Errorz9 = Controller_with_out_ref_B.Y -
      Controller_with_out_ref_DW.DiscreteTimeIntegrator1_DSTATE;

    // Sum: '<S1>/Error z10' incorporates:
    //   DiscreteIntegrator: '<S5>/Discrete-Time Integrator2'

    Controller_with_out_ref_B.Errorz10 = Controller_with_out_ref_B.Z -
      Controller_with_out_ref_DW.DiscreteTimeIntegrator2_DSTATE;

    // Start for MATLABSystem: '<S22>/P_angular_vel_x' incorporates:
    //   MATLABSystem: '<S22>/P_angular_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_bm.SampleTime ==
          Controller_with_out_ref_P.P_angular_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_bm.SampleTime =
        Controller_with_out_ref_P.P_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_with_out_ref_508.get_parameter
      (&Controller_with_out_ref_B.Switch);

    // End of Start for MATLABSystem: '<S22>/P_angular_vel_x'

    // Start for MATLABSystem: '<S22>/D_angular_vel_x' incorporates:
    //   MATLABSystem: '<S22>/D_angular_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_be.SampleTime ==
          Controller_with_out_ref_P.D_angular_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_be.SampleTime =
        Controller_with_out_ref_P.D_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_with_out_ref_505.get_parameter
      (&Controller_with_out_ref_B.NOut);

    // End of Start for MATLABSystem: '<S22>/D_angular_vel_x'

    // Start for MATLABSystem: '<S22>/N_angular_vel_x ' incorporates:
    //   MATLABSystem: '<S22>/N_angular_vel_x '

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_l.SampleTime ==
          Controller_with_out_ref_P.N_angular_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_l.SampleTime =
        Controller_with_out_ref_P.N_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_with_out_ref_507.get_parameter
      (&Controller_with_out_ref_B.NOut_e);

    // End of Start for MATLABSystem: '<S22>/N_angular_vel_x '

    // Product: '<S21>/NOut' incorporates:
    //   DiscreteIntegrator: '<S21>/Filter'
    //   MATLABSystem: '<S22>/D_angular_vel_x'
    //   MATLABSystem: '<S22>/N_angular_vel_x '
    //   Product: '<S21>/DOut'
    //   Sum: '<S21>/SumD'

    Controller_with_out_ref_B.NOut = (Controller_with_out_ref_B.Errorx *
      Controller_with_out_ref_B.NOut - Controller_with_out_ref_DW.Filter_DSTATE)
      * Controller_with_out_ref_B.NOut_e;

    // Sum: '<S21>/Sum' incorporates:
    //   DiscreteIntegrator: '<S21>/Integrator'
    //   MATLABSystem: '<S22>/P_angular_vel_x'
    //   Product: '<S21>/POut'

    Controller_with_out_ref_B.SignPreIntegrator =
      (Controller_with_out_ref_B.Errorx * Controller_with_out_ref_B.Switch +
       Controller_with_out_ref_DW.Integrator_DSTATE) +
      Controller_with_out_ref_B.NOut;

    // DeadZone: '<S23>/DeadZone'
    if (Controller_with_out_ref_B.SignPreIntegrator >
        Controller_with_out_ref_P.PIDController_UpperSaturationLi) {
      Controller_with_out_ref_B.SumI1 =
        Controller_with_out_ref_B.SignPreIntegrator -
        Controller_with_out_ref_P.PIDController_UpperSaturationLi;
    } else if (Controller_with_out_ref_B.SignPreIntegrator >=
               Controller_with_out_ref_P.PIDController_LowerSaturationLi) {
      Controller_with_out_ref_B.SumI1 = 0.0;
    } else {
      Controller_with_out_ref_B.SumI1 =
        Controller_with_out_ref_B.SignPreIntegrator -
        Controller_with_out_ref_P.PIDController_LowerSaturationLi;
    }

    // End of DeadZone: '<S23>/DeadZone'

    // RelationalOperator: '<S23>/NotEqual' incorporates:
    //   Gain: '<S23>/ZeroGain'

    rtb_NotEqual = (Controller_with_out_ref_P.ZeroGain_Gain *
                    Controller_with_out_ref_B.SignPreIntegrator !=
                    Controller_with_out_ref_B.SumI1);

    // Signum: '<S23>/SignDeltaU'
    if (Controller_with_out_ref_B.SumI1 < 0.0) {
      Controller_with_out_ref_B.SumI1 = -1.0;
    } else if (Controller_with_out_ref_B.SumI1 > 0.0) {
      Controller_with_out_ref_B.SumI1 = 1.0;
    } else {
      if (Controller_with_out_ref_B.SumI1 == 0.0) {
        Controller_with_out_ref_B.SumI1 = 0.0;
      }
    }

    // End of Signum: '<S23>/SignDeltaU'

    // DataTypeConversion: '<S23>/DataTypeConv1'
    if (Controller_with_out_ref_B.SumI1 < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_with_out_ref_B.SumI1;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // Start for MATLABSystem: '<S22>/I_angular_vel_x' incorporates:
    //   MATLABSystem: '<S22>/I_angular_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_pb.SampleTime ==
          Controller_with_out_ref_P.I_angular_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_pb.SampleTime =
        Controller_with_out_ref_P.I_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_with_out_ref_506.get_parameter
      (&Controller_with_out_ref_B.Switch);

    // End of Start for MATLABSystem: '<S22>/I_angular_vel_x'

    // Saturate: '<S21>/Saturate'
    if (Controller_with_out_ref_B.SignPreIntegrator >
        Controller_with_out_ref_P.PIDController_UpperSaturationLi) {
      Controller_with_out_ref_B.Saturate =
        Controller_with_out_ref_P.PIDController_UpperSaturationLi;
    } else if (Controller_with_out_ref_B.SignPreIntegrator <
               Controller_with_out_ref_P.PIDController_LowerSaturationLi) {
      Controller_with_out_ref_B.Saturate =
        Controller_with_out_ref_P.PIDController_LowerSaturationLi;
    } else {
      Controller_with_out_ref_B.Saturate =
        Controller_with_out_ref_B.SignPreIntegrator;
    }

    // End of Saturate: '<S21>/Saturate'

    // Sum: '<S21>/SumI1' incorporates:
    //   Gain: '<S21>/Kt'
    //   MATLABSystem: '<S22>/I_angular_vel_x'
    //   Product: '<S21>/IOut'
    //   Sum: '<S21>/SumI3'

    Controller_with_out_ref_B.SumI1 = (Controller_with_out_ref_B.X_h -
      Controller_with_out_ref_B.Saturate) *
      Controller_with_out_ref_P.PIDController_Kt +
      Controller_with_out_ref_B.Errorx * Controller_with_out_ref_B.Switch;

    // Signum: '<S23>/SignPreIntegrator'
    if (Controller_with_out_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S23>/DataTypeConv2'
      rtb_Switch_ax = -1.0;
    } else if (Controller_with_out_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S23>/DataTypeConv2'
      rtb_Switch_ax = 1.0;
    } else if (Controller_with_out_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S23>/DataTypeConv2'
      rtb_Switch_ax = 0.0;
    } else {
      // DataTypeConversion: '<S23>/DataTypeConv2'
      rtb_Switch_ax = Controller_with_out_ref_B.SumI1;
    }

    // End of Signum: '<S23>/SignPreIntegrator'

    // DataTypeConversion: '<S23>/DataTypeConv2'
    if (rtb_Switch_ax < 128.0) {
      tmp = (int8_T)rtb_Switch_ax;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S21>/Switch' incorporates:
    //   Constant: '<S21>/Constant'
    //   DataTypeConversion: '<S23>/DataTypeConv1'
    //   Logic: '<S23>/AND'
    //   RelationalOperator: '<S23>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_with_out_ref_B.Switch =
        Controller_with_out_ref_P.Constant_Value_k;
    } else {
      Controller_with_out_ref_B.Switch = Controller_with_out_ref_B.SumI1;
    }

    // End of Switch: '<S21>/Switch'

    // Start for MATLABSystem: '<S25>/P_angular_vel_y' incorporates:
    //   MATLABSystem: '<S25>/P_angular_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_b.SampleTime ==
          Controller_with_out_ref_P.P_angular_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_b.SampleTime =
        Controller_with_out_ref_P.P_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_with_out_ref_522.get_parameter
      (&Controller_with_out_ref_B.Switch_o);

    // End of Start for MATLABSystem: '<S25>/P_angular_vel_y'

    // Start for MATLABSystem: '<S25>/D_angular_vel_y' incorporates:
    //   MATLABSystem: '<S25>/D_angular_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_m.SampleTime ==
          Controller_with_out_ref_P.D_angular_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_m.SampleTime =
        Controller_with_out_ref_P.D_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_with_out_ref_519.get_parameter
      (&Controller_with_out_ref_B.NOut_e);

    // End of Start for MATLABSystem: '<S25>/D_angular_vel_y'

    // Start for MATLABSystem: '<S25>/N_angular_vel_y ' incorporates:
    //   MATLABSystem: '<S25>/N_angular_vel_y '

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_dp.SampleTime ==
          Controller_with_out_ref_P.N_angular_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_dp.SampleTime =
        Controller_with_out_ref_P.N_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_with_out_ref_521.get_parameter
      (&Controller_with_out_ref_B.NOut_m);

    // End of Start for MATLABSystem: '<S25>/N_angular_vel_y '

    // Product: '<S24>/NOut' incorporates:
    //   DiscreteIntegrator: '<S24>/Filter'
    //   MATLABSystem: '<S25>/D_angular_vel_y'
    //   MATLABSystem: '<S25>/N_angular_vel_y '
    //   Product: '<S24>/DOut'
    //   Sum: '<S24>/SumD'

    Controller_with_out_ref_B.NOut_e = (Controller_with_out_ref_B.Errory *
      Controller_with_out_ref_B.NOut_e -
      Controller_with_out_ref_DW.Filter_DSTATE_c) *
      Controller_with_out_ref_B.NOut_m;

    // Sum: '<S24>/Sum' incorporates:
    //   DiscreteIntegrator: '<S24>/Integrator'
    //   MATLABSystem: '<S25>/P_angular_vel_y'
    //   Product: '<S24>/POut'

    Controller_with_out_ref_B.SumI1 = (Controller_with_out_ref_B.Errory *
      Controller_with_out_ref_B.Switch_o +
      Controller_with_out_ref_DW.Integrator_DSTATE_h) +
      Controller_with_out_ref_B.NOut_e;

    // DeadZone: '<S26>/DeadZone'
    if (Controller_with_out_ref_B.SumI1 >
        Controller_with_out_ref_P.PIDController_UpperSaturation_o) {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_B.SumI1 -
        Controller_with_out_ref_P.PIDController_UpperSaturation_o;
    } else if (Controller_with_out_ref_B.SumI1 >=
               Controller_with_out_ref_P.PIDController_LowerSaturation_e) {
      Controller_with_out_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_B.SumI1 -
        Controller_with_out_ref_P.PIDController_LowerSaturation_e;
    }

    // End of DeadZone: '<S26>/DeadZone'

    // RelationalOperator: '<S26>/NotEqual' incorporates:
    //   Gain: '<S26>/ZeroGain'

    rtb_NotEqual = (Controller_with_out_ref_P.ZeroGain_Gain_k *
                    Controller_with_out_ref_B.SumI1 !=
                    Controller_with_out_ref_B.SignPreIntegrator);

    // Signum: '<S26>/SignDeltaU'
    if (Controller_with_out_ref_B.SignPreIntegrator < 0.0) {
      Controller_with_out_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_with_out_ref_B.SignPreIntegrator > 0.0) {
      Controller_with_out_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_with_out_ref_B.SignPreIntegrator == 0.0) {
        Controller_with_out_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S26>/SignDeltaU'

    // Start for MATLABSystem: '<S25>/I_angular_vel_y' incorporates:
    //   MATLABSystem: '<S25>/I_angular_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_ep.SampleTime ==
          Controller_with_out_ref_P.I_angular_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_ep.SampleTime =
        Controller_with_out_ref_P.I_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_with_out_ref_520.get_parameter
      (&Controller_with_out_ref_B.Switch_o);

    // End of Start for MATLABSystem: '<S25>/I_angular_vel_y'

    // Saturate: '<S24>/Saturate'
    if (Controller_with_out_ref_B.SumI1 >
        Controller_with_out_ref_P.PIDController_UpperSaturation_o) {
      Controller_with_out_ref_B.Saturate_f =
        Controller_with_out_ref_P.PIDController_UpperSaturation_o;
    } else if (Controller_with_out_ref_B.SumI1 <
               Controller_with_out_ref_P.PIDController_LowerSaturation_e) {
      Controller_with_out_ref_B.Saturate_f =
        Controller_with_out_ref_P.PIDController_LowerSaturation_e;
    } else {
      Controller_with_out_ref_B.Saturate_f = Controller_with_out_ref_B.SumI1;
    }

    // End of Saturate: '<S24>/Saturate'

    // Sum: '<S24>/SumI1' incorporates:
    //   Gain: '<S24>/Kt'
    //   MATLABSystem: '<S25>/I_angular_vel_y'
    //   Product: '<S24>/IOut'
    //   Sum: '<S24>/SumI3'

    Controller_with_out_ref_B.SumI1 = (Controller_with_out_ref_B.Y_i -
      Controller_with_out_ref_B.Saturate_f) *
      Controller_with_out_ref_P.PIDController_Kt_j +
      Controller_with_out_ref_B.Errory * Controller_with_out_ref_B.Switch_o;

    // Signum: '<S26>/SignPreIntegrator'
    if (Controller_with_out_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S26>/DataTypeConv2'
      rtb_Switch_ax = -1.0;
    } else if (Controller_with_out_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S26>/DataTypeConv2'
      rtb_Switch_ax = 1.0;
    } else if (Controller_with_out_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S26>/DataTypeConv2'
      rtb_Switch_ax = 0.0;
    } else {
      // DataTypeConversion: '<S26>/DataTypeConv2'
      rtb_Switch_ax = Controller_with_out_ref_B.SumI1;
    }

    // End of Signum: '<S26>/SignPreIntegrator'

    // DataTypeConversion: '<S26>/DataTypeConv1'
    if (Controller_with_out_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_with_out_ref_B.SignPreIntegrator;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S26>/DataTypeConv1'

    // DataTypeConversion: '<S26>/DataTypeConv2'
    if (rtb_Switch_ax < 128.0) {
      tmp = (int8_T)rtb_Switch_ax;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S24>/Switch' incorporates:
    //   Constant: '<S24>/Constant'
    //   Logic: '<S26>/AND'
    //   RelationalOperator: '<S26>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_with_out_ref_B.Switch_o =
        Controller_with_out_ref_P.Constant_Value_m;
    } else {
      Controller_with_out_ref_B.Switch_o = Controller_with_out_ref_B.SumI1;
    }

    // End of Switch: '<S24>/Switch'

    // Start for MATLABSystem: '<S28>/P_angular_vel_z' incorporates:
    //   MATLABSystem: '<S28>/P_angular_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_e.SampleTime ==
          Controller_with_out_ref_P.P_angular_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_e.SampleTime =
        Controller_with_out_ref_P.P_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_with_out_ref_536.get_parameter
      (&Controller_with_out_ref_B.Switch_j);

    // End of Start for MATLABSystem: '<S28>/P_angular_vel_z'

    // Start for MATLABSystem: '<S28>/D_angular_vel_z' incorporates:
    //   MATLABSystem: '<S28>/D_angular_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_jg.SampleTime ==
          Controller_with_out_ref_P.D_angular_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_jg.SampleTime =
        Controller_with_out_ref_P.D_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_with_out_ref_533.get_parameter
      (&Controller_with_out_ref_B.NOut_m);

    // End of Start for MATLABSystem: '<S28>/D_angular_vel_z'

    // Start for MATLABSystem: '<S28>/N_angular_vel_z ' incorporates:
    //   MATLABSystem: '<S28>/N_angular_vel_z '

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_g.SampleTime ==
          Controller_with_out_ref_P.N_angular_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_g.SampleTime =
        Controller_with_out_ref_P.N_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_with_out_ref_535.get_parameter
      (&Controller_with_out_ref_B.NOut_b);

    // End of Start for MATLABSystem: '<S28>/N_angular_vel_z '

    // Product: '<S27>/NOut' incorporates:
    //   DiscreteIntegrator: '<S27>/Filter'
    //   MATLABSystem: '<S28>/D_angular_vel_z'
    //   MATLABSystem: '<S28>/N_angular_vel_z '
    //   Product: '<S27>/DOut'
    //   Sum: '<S27>/SumD'

    Controller_with_out_ref_B.NOut_m = (Controller_with_out_ref_B.Errorz *
      Controller_with_out_ref_B.NOut_m -
      Controller_with_out_ref_DW.Filter_DSTATE_f) *
      Controller_with_out_ref_B.NOut_b;

    // Sum: '<S27>/Sum' incorporates:
    //   DiscreteIntegrator: '<S27>/Integrator'
    //   MATLABSystem: '<S28>/P_angular_vel_z'
    //   Product: '<S27>/POut'

    Controller_with_out_ref_B.SumI1 = (Controller_with_out_ref_B.Errorz *
      Controller_with_out_ref_B.Switch_j +
      Controller_with_out_ref_DW.Integrator_DSTATE_a) +
      Controller_with_out_ref_B.NOut_m;

    // DeadZone: '<S29>/DeadZone'
    if (Controller_with_out_ref_B.SumI1 >
        Controller_with_out_ref_P.PIDController_UpperSaturation_e) {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_B.SumI1 -
        Controller_with_out_ref_P.PIDController_UpperSaturation_e;
    } else if (Controller_with_out_ref_B.SumI1 >=
               Controller_with_out_ref_P.PIDController_LowerSaturation_p) {
      Controller_with_out_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_B.SumI1 -
        Controller_with_out_ref_P.PIDController_LowerSaturation_p;
    }

    // End of DeadZone: '<S29>/DeadZone'

    // RelationalOperator: '<S29>/NotEqual' incorporates:
    //   Gain: '<S29>/ZeroGain'

    rtb_NotEqual = (Controller_with_out_ref_P.ZeroGain_Gain_a *
                    Controller_with_out_ref_B.SumI1 !=
                    Controller_with_out_ref_B.SignPreIntegrator);

    // Signum: '<S29>/SignDeltaU'
    if (Controller_with_out_ref_B.SignPreIntegrator < 0.0) {
      Controller_with_out_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_with_out_ref_B.SignPreIntegrator > 0.0) {
      Controller_with_out_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_with_out_ref_B.SignPreIntegrator == 0.0) {
        Controller_with_out_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S29>/SignDeltaU'

    // Start for MATLABSystem: '<S28>/I_angular_vel_z' incorporates:
    //   MATLABSystem: '<S28>/I_angular_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_p.SampleTime ==
          Controller_with_out_ref_P.I_angular_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_p.SampleTime =
        Controller_with_out_ref_P.I_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_with_out_ref_534.get_parameter
      (&Controller_with_out_ref_B.Switch_j);

    // End of Start for MATLABSystem: '<S28>/I_angular_vel_z'

    // Saturate: '<S27>/Saturate'
    if (Controller_with_out_ref_B.SumI1 >
        Controller_with_out_ref_P.PIDController_UpperSaturation_e) {
      Controller_with_out_ref_B.Saturate_i =
        Controller_with_out_ref_P.PIDController_UpperSaturation_e;
    } else if (Controller_with_out_ref_B.SumI1 <
               Controller_with_out_ref_P.PIDController_LowerSaturation_p) {
      Controller_with_out_ref_B.Saturate_i =
        Controller_with_out_ref_P.PIDController_LowerSaturation_p;
    } else {
      Controller_with_out_ref_B.Saturate_i = Controller_with_out_ref_B.SumI1;
    }

    // End of Saturate: '<S27>/Saturate'

    // Sum: '<S27>/SumI1' incorporates:
    //   Gain: '<S27>/Kt'
    //   MATLABSystem: '<S28>/I_angular_vel_z'
    //   Product: '<S27>/IOut'
    //   Sum: '<S27>/SumI3'

    Controller_with_out_ref_B.SumI1 = (Controller_with_out_ref_B.Z_n -
      Controller_with_out_ref_B.Saturate_i) *
      Controller_with_out_ref_P.PIDController_Kt_p +
      Controller_with_out_ref_B.Errorz * Controller_with_out_ref_B.Switch_j;

    // Signum: '<S29>/SignPreIntegrator'
    if (Controller_with_out_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S29>/DataTypeConv2'
      rtb_Switch_ax = -1.0;
    } else if (Controller_with_out_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S29>/DataTypeConv2'
      rtb_Switch_ax = 1.0;
    } else if (Controller_with_out_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S29>/DataTypeConv2'
      rtb_Switch_ax = 0.0;
    } else {
      // DataTypeConversion: '<S29>/DataTypeConv2'
      rtb_Switch_ax = Controller_with_out_ref_B.SumI1;
    }

    // End of Signum: '<S29>/SignPreIntegrator'

    // DataTypeConversion: '<S29>/DataTypeConv1'
    if (Controller_with_out_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_with_out_ref_B.SignPreIntegrator;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S29>/DataTypeConv1'

    // DataTypeConversion: '<S29>/DataTypeConv2'
    if (rtb_Switch_ax < 128.0) {
      tmp = (int8_T)rtb_Switch_ax;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S27>/Switch' incorporates:
    //   Constant: '<S27>/Constant'
    //   Logic: '<S29>/AND'
    //   RelationalOperator: '<S29>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_with_out_ref_B.Switch_j =
        Controller_with_out_ref_P.Constant_Value_f;
    } else {
      Controller_with_out_ref_B.Switch_j = Controller_with_out_ref_B.SumI1;
    }

    // End of Switch: '<S27>/Switch'

    // Start for MATLABSystem: '<S31>/P_vel_x' incorporates:
    //   MATLABSystem: '<S31>/P_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_ns.SampleTime ==
          Controller_with_out_ref_P.P_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_ns.SampleTime =
        Controller_with_out_ref_P.P_vel_x_SampleTime;
    }

    ParamGet_Controller_with_out_ref_550.get_parameter
      (&Controller_with_out_ref_B.Switch_e);

    // End of Start for MATLABSystem: '<S31>/P_vel_x'

    // Start for MATLABSystem: '<S31>/D_vel_x' incorporates:
    //   MATLABSystem: '<S31>/D_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_d.SampleTime ==
          Controller_with_out_ref_P.D_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_d.SampleTime =
        Controller_with_out_ref_P.D_vel_x_SampleTime;
    }

    ParamGet_Controller_with_out_ref_547.get_parameter
      (&Controller_with_out_ref_B.NOut_b);

    // End of Start for MATLABSystem: '<S31>/D_vel_x'

    // Start for MATLABSystem: '<S31>/N_vel_x ' incorporates:
    //   MATLABSystem: '<S31>/N_vel_x '

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_a3.SampleTime ==
          Controller_with_out_ref_P.N_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_a3.SampleTime =
        Controller_with_out_ref_P.N_vel_x_SampleTime;
    }

    ParamGet_Controller_with_out_ref_549.get_parameter
      (&Controller_with_out_ref_B.SignPreIntegrator);

    // End of Start for MATLABSystem: '<S31>/N_vel_x '

    // Product: '<S30>/NOut' incorporates:
    //   DiscreteIntegrator: '<S30>/Filter'
    //   MATLABSystem: '<S31>/D_vel_x'
    //   MATLABSystem: '<S31>/N_vel_x '
    //   Product: '<S30>/DOut'
    //   Sum: '<S30>/SumD'

    Controller_with_out_ref_B.NOut_b = (Controller_with_out_ref_B.Errorz8 *
      Controller_with_out_ref_B.NOut_b -
      Controller_with_out_ref_DW.Filter_DSTATE_a) *
      Controller_with_out_ref_B.SignPreIntegrator;

    // Sum: '<S30>/Sum' incorporates:
    //   DiscreteIntegrator: '<S30>/Integrator'
    //   MATLABSystem: '<S31>/P_vel_x'
    //   Product: '<S30>/POut'

    Controller_with_out_ref_B.SumI1 = (Controller_with_out_ref_B.Errorz8 *
      Controller_with_out_ref_B.Switch_e +
      Controller_with_out_ref_DW.Integrator_DSTATE_f) +
      Controller_with_out_ref_B.NOut_b;

    // DeadZone: '<S32>/DeadZone'
    if (Controller_with_out_ref_B.SumI1 >
        Controller_with_out_ref_P.PIDController_UpperSaturation_d) {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_B.SumI1 -
        Controller_with_out_ref_P.PIDController_UpperSaturation_d;
    } else if (Controller_with_out_ref_B.SumI1 >=
               Controller_with_out_ref_P.PIDController_LowerSaturation_i) {
      Controller_with_out_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_B.SumI1 -
        Controller_with_out_ref_P.PIDController_LowerSaturation_i;
    }

    // End of DeadZone: '<S32>/DeadZone'

    // RelationalOperator: '<S32>/NotEqual' incorporates:
    //   Gain: '<S32>/ZeroGain'

    rtb_NotEqual = (Controller_with_out_ref_P.ZeroGain_Gain_j *
                    Controller_with_out_ref_B.SumI1 !=
                    Controller_with_out_ref_B.SignPreIntegrator);

    // Signum: '<S32>/SignDeltaU'
    if (Controller_with_out_ref_B.SignPreIntegrator < 0.0) {
      Controller_with_out_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_with_out_ref_B.SignPreIntegrator > 0.0) {
      Controller_with_out_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_with_out_ref_B.SignPreIntegrator == 0.0) {
        Controller_with_out_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S32>/SignDeltaU'

    // Start for MATLABSystem: '<S31>/I_vel_x' incorporates:
    //   MATLABSystem: '<S31>/I_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_cv.SampleTime ==
          Controller_with_out_ref_P.I_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_cv.SampleTime =
        Controller_with_out_ref_P.I_vel_x_SampleTime;
    }

    ParamGet_Controller_with_out_ref_548.get_parameter
      (&Controller_with_out_ref_B.Switch_e);

    // End of Start for MATLABSystem: '<S31>/I_vel_x'

    // Saturate: '<S30>/Saturate'
    if (Controller_with_out_ref_B.SumI1 >
        Controller_with_out_ref_P.PIDController_UpperSaturation_d) {
      Controller_with_out_ref_B.Saturate_b =
        Controller_with_out_ref_P.PIDController_UpperSaturation_d;
    } else if (Controller_with_out_ref_B.SumI1 <
               Controller_with_out_ref_P.PIDController_LowerSaturation_i) {
      Controller_with_out_ref_B.Saturate_b =
        Controller_with_out_ref_P.PIDController_LowerSaturation_i;
    } else {
      Controller_with_out_ref_B.Saturate_b = Controller_with_out_ref_B.SumI1;
    }

    // End of Saturate: '<S30>/Saturate'

    // Sum: '<S30>/SumI1' incorporates:
    //   Gain: '<S30>/Kt'
    //   MATLABSystem: '<S31>/I_vel_x'
    //   Product: '<S30>/IOut'
    //   Sum: '<S30>/SumI3'

    Controller_with_out_ref_B.SumI1 = (Controller_with_out_ref_B.X -
      Controller_with_out_ref_B.Saturate_b) *
      Controller_with_out_ref_P.PIDController_Kt_jw +
      Controller_with_out_ref_B.Errorz8 * Controller_with_out_ref_B.Switch_e;

    // Signum: '<S32>/SignPreIntegrator'
    if (Controller_with_out_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S32>/DataTypeConv2'
      rtb_Switch_ax = -1.0;
    } else if (Controller_with_out_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S32>/DataTypeConv2'
      rtb_Switch_ax = 1.0;
    } else if (Controller_with_out_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S32>/DataTypeConv2'
      rtb_Switch_ax = 0.0;
    } else {
      // DataTypeConversion: '<S32>/DataTypeConv2'
      rtb_Switch_ax = Controller_with_out_ref_B.SumI1;
    }

    // End of Signum: '<S32>/SignPreIntegrator'

    // DataTypeConversion: '<S32>/DataTypeConv1'
    if (Controller_with_out_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_with_out_ref_B.SignPreIntegrator;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S32>/DataTypeConv1'

    // DataTypeConversion: '<S32>/DataTypeConv2'
    if (rtb_Switch_ax < 128.0) {
      tmp = (int8_T)rtb_Switch_ax;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S30>/Switch' incorporates:
    //   Constant: '<S30>/Constant'
    //   Logic: '<S32>/AND'
    //   RelationalOperator: '<S32>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_with_out_ref_B.Switch_e =
        Controller_with_out_ref_P.Constant_Value_m0;
    } else {
      Controller_with_out_ref_B.Switch_e = Controller_with_out_ref_B.SumI1;
    }

    // End of Switch: '<S30>/Switch'

    // Start for MATLABSystem: '<S34>/P_vel_y' incorporates:
    //   MATLABSystem: '<S34>/P_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_ji.SampleTime ==
          Controller_with_out_ref_P.P_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_ji.SampleTime =
        Controller_with_out_ref_P.P_vel_y_SampleTime;
    }

    ParamGet_Controller_with_out_ref_564.get_parameter
      (&Controller_with_out_ref_B.SignPreIntegrator);

    // End of Start for MATLABSystem: '<S34>/P_vel_y'

    // Start for MATLABSystem: '<S34>/D_vel_y' incorporates:
    //   MATLABSystem: '<S34>/D_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_n.SampleTime ==
          Controller_with_out_ref_P.D_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_n.SampleTime =
        Controller_with_out_ref_P.D_vel_y_SampleTime;
    }

    ParamGet_Controller_with_out_ref_561.get_parameter
      (&Controller_with_out_ref_B.NOut_i);

    // End of Start for MATLABSystem: '<S34>/D_vel_y'

    // Start for MATLABSystem: '<S34>/N_vel_y ' incorporates:
    //   MATLABSystem: '<S34>/N_vel_y '

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_c.SampleTime ==
          Controller_with_out_ref_P.N_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_c.SampleTime =
        Controller_with_out_ref_P.N_vel_y_SampleTime;
    }

    ParamGet_Controller_with_out_ref_563.get_parameter
      (&Controller_with_out_ref_B.SumI1);

    // End of Start for MATLABSystem: '<S34>/N_vel_y '

    // Product: '<S33>/NOut' incorporates:
    //   DiscreteIntegrator: '<S33>/Filter'
    //   MATLABSystem: '<S34>/D_vel_y'
    //   MATLABSystem: '<S34>/N_vel_y '
    //   Product: '<S33>/DOut'
    //   Sum: '<S33>/SumD'

    Controller_with_out_ref_B.NOut_i = (Controller_with_out_ref_B.Errorz9 *
      Controller_with_out_ref_B.NOut_i -
      Controller_with_out_ref_DW.Filter_DSTATE_g) *
      Controller_with_out_ref_B.SumI1;

    // Sum: '<S33>/Sum' incorporates:
    //   DiscreteIntegrator: '<S33>/Integrator'
    //   MATLABSystem: '<S34>/P_vel_y'
    //   Product: '<S33>/POut'

    Controller_with_out_ref_B.SumI1 = (Controller_with_out_ref_B.Errorz9 *
      Controller_with_out_ref_B.SignPreIntegrator +
      Controller_with_out_ref_DW.Integrator_DSTATE_n) +
      Controller_with_out_ref_B.NOut_i;

    // DeadZone: '<S35>/DeadZone'
    if (Controller_with_out_ref_B.SumI1 >
        Controller_with_out_ref_P.PIDController_UpperSaturation_b) {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_B.SumI1 -
        Controller_with_out_ref_P.PIDController_UpperSaturation_b;
    } else if (Controller_with_out_ref_B.SumI1 >=
               Controller_with_out_ref_P.PIDController_LowerSaturation_g) {
      Controller_with_out_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_B.SumI1 -
        Controller_with_out_ref_P.PIDController_LowerSaturation_g;
    }

    // End of DeadZone: '<S35>/DeadZone'

    // RelationalOperator: '<S35>/NotEqual' incorporates:
    //   Gain: '<S35>/ZeroGain'

    rtb_NotEqual = (Controller_with_out_ref_P.ZeroGain_Gain_jk *
                    Controller_with_out_ref_B.SumI1 !=
                    Controller_with_out_ref_B.SignPreIntegrator);

    // Signum: '<S35>/SignDeltaU'
    if (Controller_with_out_ref_B.SignPreIntegrator < 0.0) {
      Controller_with_out_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_with_out_ref_B.SignPreIntegrator > 0.0) {
      Controller_with_out_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_with_out_ref_B.SignPreIntegrator == 0.0) {
        Controller_with_out_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S35>/SignDeltaU'

    // Start for MATLABSystem: '<S34>/I_vel_y' incorporates:
    //   MATLABSystem: '<S34>/I_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_jx.SampleTime ==
          Controller_with_out_ref_P.I_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_jx.SampleTime =
        Controller_with_out_ref_P.I_vel_y_SampleTime;
    }

    ParamGet_Controller_with_out_ref_562.get_parameter(&rtb_Switch_ax);

    // End of Start for MATLABSystem: '<S34>/I_vel_y'

    // Saturate: '<S33>/Saturate'
    if (Controller_with_out_ref_B.SumI1 >
        Controller_with_out_ref_P.PIDController_UpperSaturation_b) {
      Controller_with_out_ref_B.Saturate_h =
        Controller_with_out_ref_P.PIDController_UpperSaturation_b;
    } else if (Controller_with_out_ref_B.SumI1 <
               Controller_with_out_ref_P.PIDController_LowerSaturation_g) {
      Controller_with_out_ref_B.Saturate_h =
        Controller_with_out_ref_P.PIDController_LowerSaturation_g;
    } else {
      Controller_with_out_ref_B.Saturate_h = Controller_with_out_ref_B.SumI1;
    }

    // End of Saturate: '<S33>/Saturate'

    // Sum: '<S33>/SumI1' incorporates:
    //   Gain: '<S33>/Kt'
    //   MATLABSystem: '<S34>/I_vel_y'
    //   Product: '<S33>/IOut'
    //   Sum: '<S33>/SumI3'

    Controller_with_out_ref_B.SumI1 = (Controller_with_out_ref_B.Y -
      Controller_with_out_ref_B.Saturate_h) *
      Controller_with_out_ref_P.PIDController_Kt_c +
      Controller_with_out_ref_B.Errorz9 * rtb_Switch_ax;

    // Signum: '<S35>/SignPreIntegrator'
    if (Controller_with_out_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S35>/DataTypeConv2'
      rtb_Switch_ax = -1.0;
    } else if (Controller_with_out_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S35>/DataTypeConv2'
      rtb_Switch_ax = 1.0;
    } else if (Controller_with_out_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S35>/DataTypeConv2'
      rtb_Switch_ax = 0.0;
    } else {
      // DataTypeConversion: '<S35>/DataTypeConv2'
      rtb_Switch_ax = Controller_with_out_ref_B.SumI1;
    }

    // End of Signum: '<S35>/SignPreIntegrator'

    // DataTypeConversion: '<S35>/DataTypeConv1'
    if (Controller_with_out_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_with_out_ref_B.SignPreIntegrator;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S35>/DataTypeConv1'

    // DataTypeConversion: '<S35>/DataTypeConv2'
    if (rtb_Switch_ax < 128.0) {
      tmp = (int8_T)rtb_Switch_ax;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S33>/Switch' incorporates:
    //   Constant: '<S33>/Constant'
    //   Logic: '<S35>/AND'
    //   RelationalOperator: '<S35>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      rtb_Switch_ax = Controller_with_out_ref_P.Constant_Value_p;
    } else {
      rtb_Switch_ax = Controller_with_out_ref_B.SumI1;
    }

    // End of Switch: '<S33>/Switch'

    // Start for MATLABSystem: '<S37>/P_vel_z' incorporates:
    //   MATLABSystem: '<S37>/P_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj.SampleTime ==
          Controller_with_out_ref_P.P_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj.SampleTime =
        Controller_with_out_ref_P.P_vel_z_SampleTime;
    }

    ParamGet_Controller_with_out_ref_578.get_parameter
      (&Controller_with_out_ref_B.SignPreIntegrator);

    // End of Start for MATLABSystem: '<S37>/P_vel_z'

    // Start for MATLABSystem: '<S37>/D_vel_z' incorporates:
    //   MATLABSystem: '<S37>/D_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_a.SampleTime ==
          Controller_with_out_ref_P.D_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_a.SampleTime =
        Controller_with_out_ref_P.D_vel_z_SampleTime;
    }

    ParamGet_Controller_with_out_ref_575.get_parameter
      (&Controller_with_out_ref_B.SumI1);

    // End of Start for MATLABSystem: '<S37>/D_vel_z'

    // Start for MATLABSystem: '<S37>/N_vel_z ' incorporates:
    //   MATLABSystem: '<S37>/N_vel_z '

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_h.SampleTime ==
          Controller_with_out_ref_P.N_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_h.SampleTime =
        Controller_with_out_ref_P.N_vel_z_SampleTime;
    }

    ParamGet_Controller_with_out_ref_577.get_parameter
      (&Controller_with_out_ref_B.NOut_d);

    // End of Start for MATLABSystem: '<S37>/N_vel_z '

    // Product: '<S36>/NOut' incorporates:
    //   DiscreteIntegrator: '<S36>/Filter'
    //   MATLABSystem: '<S37>/D_vel_z'
    //   MATLABSystem: '<S37>/N_vel_z '
    //   Product: '<S36>/DOut'
    //   Sum: '<S36>/SumD'

    Controller_with_out_ref_B.NOut_d *= Controller_with_out_ref_B.Errorz10 *
      Controller_with_out_ref_B.SumI1 -
      Controller_with_out_ref_DW.Filter_DSTATE_cw;

    // Sum: '<S36>/Sum' incorporates:
    //   DiscreteIntegrator: '<S36>/Integrator'
    //   MATLABSystem: '<S37>/P_vel_z'
    //   Product: '<S36>/POut'

    Controller_with_out_ref_B.SumI1 = (Controller_with_out_ref_B.Errorz10 *
      Controller_with_out_ref_B.SignPreIntegrator +
      Controller_with_out_ref_DW.Integrator_DSTATE_ny) +
      Controller_with_out_ref_B.NOut_d;

    // DeadZone: '<S38>/DeadZone'
    if (Controller_with_out_ref_B.SumI1 >
        Controller_with_out_ref_P.PIDController_UpperSaturatio_ba) {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_B.SumI1 -
        Controller_with_out_ref_P.PIDController_UpperSaturatio_ba;
    } else if (Controller_with_out_ref_B.SumI1 >=
               Controller_with_out_ref_P.PIDController_LowerSaturatio_pm) {
      Controller_with_out_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_B.SumI1 -
        Controller_with_out_ref_P.PIDController_LowerSaturatio_pm;
    }

    // End of DeadZone: '<S38>/DeadZone'

    // RelationalOperator: '<S38>/NotEqual' incorporates:
    //   Gain: '<S38>/ZeroGain'

    rtb_NotEqual = (Controller_with_out_ref_P.ZeroGain_Gain_p *
                    Controller_with_out_ref_B.SumI1 !=
                    Controller_with_out_ref_B.SignPreIntegrator);

    // Signum: '<S38>/SignDeltaU'
    if (Controller_with_out_ref_B.SignPreIntegrator < 0.0) {
      Controller_with_out_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_with_out_ref_B.SignPreIntegrator > 0.0) {
      Controller_with_out_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_with_out_ref_B.SignPreIntegrator == 0.0) {
        Controller_with_out_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S38>/SignDeltaU'

    // Start for MATLABSystem: '<S37>/I_vel_z' incorporates:
    //   MATLABSystem: '<S37>/I_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_with_out_ref_DW.obj_j.SampleTime ==
          Controller_with_out_ref_P.I_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_with_out_ref_DW.obj_j.SampleTime =
        Controller_with_out_ref_P.I_vel_z_SampleTime;
    }

    ParamGet_Controller_with_out_ref_576.get_parameter
      (&Controller_with_out_ref_B.rtb_I_vel_z_c);

    // End of Start for MATLABSystem: '<S37>/I_vel_z'

    // Saturate: '<S36>/Saturate'
    if (Controller_with_out_ref_B.SumI1 >
        Controller_with_out_ref_P.PIDController_UpperSaturatio_ba) {
      Controller_with_out_ref_B.Saturate_bk =
        Controller_with_out_ref_P.PIDController_UpperSaturatio_ba;
    } else if (Controller_with_out_ref_B.SumI1 <
               Controller_with_out_ref_P.PIDController_LowerSaturatio_pm) {
      Controller_with_out_ref_B.Saturate_bk =
        Controller_with_out_ref_P.PIDController_LowerSaturatio_pm;
    } else {
      Controller_with_out_ref_B.Saturate_bk = Controller_with_out_ref_B.SumI1;
    }

    // End of Saturate: '<S36>/Saturate'

    // Sum: '<S36>/SumI1' incorporates:
    //   Gain: '<S36>/Kt'
    //   MATLABSystem: '<S37>/I_vel_z'
    //   Product: '<S36>/IOut'
    //   Sum: '<S36>/SumI3'

    Controller_with_out_ref_B.SumI1 = (Controller_with_out_ref_B.Z -
      Controller_with_out_ref_B.Saturate_bk) *
      Controller_with_out_ref_P.PIDController_Kt_l +
      Controller_with_out_ref_B.Errorz10 *
      Controller_with_out_ref_B.rtb_I_vel_z_c;

    // Update for DiscreteIntegrator: '<S21>/Integrator'
    Controller_with_out_ref_DW.Integrator_DSTATE +=
      Controller_with_out_ref_P.Integrator_gainval *
      Controller_with_out_ref_B.Switch;

    // Update for DiscreteIntegrator: '<S21>/Filter'
    Controller_with_out_ref_DW.Filter_DSTATE +=
      Controller_with_out_ref_P.Filter_gainval * Controller_with_out_ref_B.NOut;

    // Update for DiscreteIntegrator: '<S24>/Integrator'
    Controller_with_out_ref_DW.Integrator_DSTATE_h +=
      Controller_with_out_ref_P.Integrator_gainval_c *
      Controller_with_out_ref_B.Switch_o;

    // Update for DiscreteIntegrator: '<S24>/Filter'
    Controller_with_out_ref_DW.Filter_DSTATE_c +=
      Controller_with_out_ref_P.Filter_gainval_i *
      Controller_with_out_ref_B.NOut_e;

    // Update for DiscreteIntegrator: '<S27>/Integrator'
    Controller_with_out_ref_DW.Integrator_DSTATE_a +=
      Controller_with_out_ref_P.Integrator_gainval_n *
      Controller_with_out_ref_B.Switch_j;

    // Update for DiscreteIntegrator: '<S27>/Filter'
    Controller_with_out_ref_DW.Filter_DSTATE_f +=
      Controller_with_out_ref_P.Filter_gainval_k *
      Controller_with_out_ref_B.NOut_m;

    // Update for DiscreteIntegrator: '<S30>/Integrator'
    Controller_with_out_ref_DW.Integrator_DSTATE_f +=
      Controller_with_out_ref_P.Integrator_gainval_j *
      Controller_with_out_ref_B.Switch_e;

    // Update for DiscreteIntegrator: '<S30>/Filter'
    Controller_with_out_ref_DW.Filter_DSTATE_a +=
      Controller_with_out_ref_P.Filter_gainval_h *
      Controller_with_out_ref_B.NOut_b;

    // Update for DiscreteIntegrator: '<S33>/Integrator'
    Controller_with_out_ref_DW.Integrator_DSTATE_n +=
      Controller_with_out_ref_P.Integrator_gainval_np * rtb_Switch_ax;

    // Update for DiscreteIntegrator: '<S33>/Filter'
    Controller_with_out_ref_DW.Filter_DSTATE_g +=
      Controller_with_out_ref_P.Filter_gainval_h0 *
      Controller_with_out_ref_B.NOut_i;

    // Signum: '<S38>/SignPreIntegrator'
    if (Controller_with_out_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S38>/DataTypeConv2'
      rtb_Switch_ax = -1.0;
    } else if (Controller_with_out_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S38>/DataTypeConv2'
      rtb_Switch_ax = 1.0;
    } else if (Controller_with_out_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S38>/DataTypeConv2'
      rtb_Switch_ax = 0.0;
    } else {
      // DataTypeConversion: '<S38>/DataTypeConv2'
      rtb_Switch_ax = Controller_with_out_ref_B.SumI1;
    }

    // End of Signum: '<S38>/SignPreIntegrator'

    // DataTypeConversion: '<S38>/DataTypeConv1'
    if (Controller_with_out_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_with_out_ref_B.SignPreIntegrator;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S38>/DataTypeConv1'

    // DataTypeConversion: '<S38>/DataTypeConv2'
    if (rtb_Switch_ax < 128.0) {
      tmp = (int8_T)rtb_Switch_ax;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S36>/Switch' incorporates:
    //   Constant: '<S36>/Constant'
    //   Logic: '<S38>/AND'
    //   RelationalOperator: '<S38>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_with_out_ref_B.SumI1 =
        Controller_with_out_ref_P.Constant_Value_l;
    }

    // End of Switch: '<S36>/Switch'

    // Update for DiscreteIntegrator: '<S36>/Integrator'
    Controller_with_out_ref_DW.Integrator_DSTATE_ny +=
      Controller_with_out_ref_P.Integrator_gainval_m *
      Controller_with_out_ref_B.SumI1;

    // Update for DiscreteIntegrator: '<S36>/Filter'
    Controller_with_out_ref_DW.Filter_DSTATE_cw +=
      Controller_with_out_ref_P.Filter_gainval_b *
      Controller_with_out_ref_B.NOut_d;
  }

  // End of Outputs for SubSystem: '<Root>/Xbox_input'
  // End of Outputs for SubSystem: '<Root>/mavros_data'
  // End of Outputs for SubSystem: '<Root>/Create errors'
  // End of Outputs for SubSystem: '<Root>/decController'

  // MultiPortSwitch: '<Root>/Choose Controller signal' incorporates:
  //   Constant: '<Root>/Constant4'
  //   MATLABSystem: '<Root>/Get controller type'

  switch (i) {
   case 0:
    Controller_with_out_ref_B.ChooseControllersignal[0] =
      Controller_with_out_ref_B.X_h;
    Controller_with_out_ref_B.ChooseControllersignal[1] =
      Controller_with_out_ref_B.Y_i;
    Controller_with_out_ref_B.ChooseControllersignal[2] =
      Controller_with_out_ref_B.Z_n;
    Controller_with_out_ref_B.ChooseControllersignal[3] =
      Controller_with_out_ref_B.X;
    Controller_with_out_ref_B.ChooseControllersignal[4] =
      Controller_with_out_ref_B.Y;
    Controller_with_out_ref_B.ChooseControllersignal[5] =
      Controller_with_out_ref_B.Z;
    break;

   case 1:
    Controller_with_out_ref_B.ChooseControllersignal[0] =
      Controller_with_out_ref_B.Saturate;
    Controller_with_out_ref_B.ChooseControllersignal[1] =
      Controller_with_out_ref_B.Saturate_f;
    Controller_with_out_ref_B.ChooseControllersignal[2] =
      Controller_with_out_ref_B.Saturate_i;
    Controller_with_out_ref_B.ChooseControllersignal[3] =
      Controller_with_out_ref_B.Saturate_b;
    Controller_with_out_ref_B.ChooseControllersignal[4] =
      Controller_with_out_ref_B.Saturate_h;
    Controller_with_out_ref_B.ChooseControllersignal[5] =
      Controller_with_out_ref_B.Saturate_bk;
    break;

   default:
    for (i = 0; i < 6; i++) {
      Controller_with_out_ref_B.ChooseControllersignal[i] =
        Controller_with_out_ref_P.Constant4_Value;
    }
    break;
  }

  // End of MultiPortSwitch: '<Root>/Choose Controller signal'

  // Start for MATLABSystem: '<S2>/Get front strafe decouple' incorporates:
  //   MATLABSystem: '<S2>/Get front strafe decouple'

  p = false;
  p_0 = true;
  if (!(Controller_with_out_ref_DW.obj_jl.SampleTime ==
        Controller_with_out_ref_P.Getfrontstrafedecouple_SampleTi)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_with_out_ref_DW.obj_jl.SampleTime =
      Controller_with_out_ref_P.Getfrontstrafedecouple_SampleTi;
  }

  ParamGet_Controller_with_out_ref_465.get_parameter
    (&Controller_with_out_ref_B.NOut);

  // Start for MATLABSystem: '<S2>/Get front forward decouple' incorporates:
  //   MATLABSystem: '<S2>/Get front forward decouple'

  p = false;
  p_0 = true;
  if (!(Controller_with_out_ref_DW.obj_ec.SampleTime ==
        Controller_with_out_ref_P.Getfrontforwarddecouple_SampleT)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_with_out_ref_DW.obj_ec.SampleTime =
      Controller_with_out_ref_P.Getfrontforwarddecouple_SampleT;
  }

  ParamGet_Controller_with_out_ref_463.get_parameter
    (&Controller_with_out_ref_B.Switch);

  // Start for MATLABSystem: '<S2>/Get front pitch bias' incorporates:
  //   MATLABSystem: '<S2>/Get front pitch bias'

  p = false;
  p_0 = true;
  if (!(Controller_with_out_ref_DW.obj_nj.SampleTime ==
        Controller_with_out_ref_P.Getfrontpitchbias_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_with_out_ref_DW.obj_nj.SampleTime =
      Controller_with_out_ref_P.Getfrontpitchbias_SampleTime;
  }

  ParamGet_Controller_with_out_ref_464.get_parameter
    (&Controller_with_out_ref_B.NOut_e);

  // Start for MATLABSystem: '<S2>/Get front vertical bias' incorporates:
  //   MATLABSystem: '<S2>/Get front vertical bias'

  p = false;
  p_0 = true;
  if (!(Controller_with_out_ref_DW.obj_lo.SampleTime ==
        Controller_with_out_ref_P.Getfrontverticalbias_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_with_out_ref_DW.obj_lo.SampleTime =
      Controller_with_out_ref_P.Getfrontverticalbias_SampleTime;
  }

  ParamGet_Controller_with_out_ref_466.get_parameter
    (&Controller_with_out_ref_B.Switch_o);

  // Start for MATLABSystem: '<S2>/Get buoyancy' incorporates:
  //   MATLABSystem: '<S2>/Get buoyancy'

  p = false;
  p_0 = true;
  if (!(Controller_with_out_ref_DW.obj_ef.SampleTime ==
        Controller_with_out_ref_P.Getbuoyancy_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_with_out_ref_DW.obj_ef.SampleTime =
      Controller_with_out_ref_P.Getbuoyancy_SampleTime;
  }

  ParamGet_Controller_with_out_ref_462.get_parameter
    (&Controller_with_out_ref_B.NOut_m);

  // Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
  //   EnablePort: '<S3>/Enable'

  // MATLAB Function 'Decouple/MATLAB Function': '<S10>:1'
  //  Vertical Left thruster (VL)
  // '<S10>:1:7'
  //  Vertical Back thruster (VB)
  // '<S10>:1:17'
  // '<S10>:1:24'
  // Forward Left (FL)
  // '<S10>:1:33'
  // '<S10>:1:36'
  //  LATeral (LAT)
  //  Forward Right (FR)
  // '<S10>:1:39'
  if (rtb_LogicalOperator) {
    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   Constant: '<S11>/Constant'

    // MATLAB Function 'Subsystem/Calc pwm signal': '<S12>:1'
    //  thruster values should be between 1100 and 1900 microseconds (us)
    //  values less than 1500 us are backwards; values more than are forwards
    // '<S12>:1:5'
    Controller_with_out_ref_B.BusAssignment =
      Controller_with_out_ref_P.Constant_Value_i;

    // MATLAB Function: '<S2>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S2>/Get buoyancy'
    //   Start for MATLABSystem: '<S2>/Get buoyancy'
    //   MATLABSystem: '<S2>/Get front forward decouple'
    //   Start for MATLABSystem: '<S2>/Get front forward decouple'
    //   MATLABSystem: '<S2>/Get front pitch bias'
    //   Start for MATLABSystem: '<S2>/Get front pitch bias'
    //   MATLABSystem: '<S2>/Get front strafe decouple'
    //   Start for MATLABSystem: '<S2>/Get front strafe decouple'
    //   MATLABSystem: '<S2>/Get front vertical bias'
    //   Start for MATLABSystem: '<S2>/Get front vertical bias'

    Controller_with_out_ref_B.SignPreIntegrator =
      ((((Controller_with_out_ref_B.ChooseControllersignal[0] -
          Controller_with_out_ref_B.Switch *
          Controller_with_out_ref_B.ChooseControllersignal[3]) -
         Controller_with_out_ref_B.NOut *
         Controller_with_out_ref_B.ChooseControllersignal[4]) -
        Controller_with_out_ref_B.NOut_e *
        Controller_with_out_ref_B.ChooseControllersignal[1]) +
       Controller_with_out_ref_B.Switch_o *
       Controller_with_out_ref_B.ChooseControllersignal[5]) +
      Controller_with_out_ref_B.NOut_m;

    // Saturate: '<S3>/Saturation'
    if (Controller_with_out_ref_B.SignPreIntegrator >
        Controller_with_out_ref_P.Saturation_UpperSat) {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_P.Saturation_UpperSat;
    } else {
      if (Controller_with_out_ref_B.SignPreIntegrator <
          Controller_with_out_ref_P.Saturation_LowerSat) {
        Controller_with_out_ref_B.SignPreIntegrator =
          Controller_with_out_ref_P.Saturation_LowerSat;
      }
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'
    //   MATLAB Function: '<S3>/Calc pwm signal'
    //   Saturate: '<S3>/Saturation'

    Controller_with_out_ref_B.BusAssignment.Controls[0] = (real32_T)
      ((Controller_with_out_ref_B.SignPreIntegrator + 1.0) * 400.0 + 1100.0);

    // MATLAB Function: '<S2>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S2>/Get buoyancy'
    //   Start for MATLABSystem: '<S2>/Get buoyancy'
    //   MATLABSystem: '<S2>/Get front forward decouple'
    //   Start for MATLABSystem: '<S2>/Get front forward decouple'

    Controller_with_out_ref_B.SignPreIntegrator =
      ((Controller_with_out_ref_B.Switch *
        Controller_with_out_ref_B.ChooseControllersignal[3] +
        Controller_with_out_ref_B.ChooseControllersignal[1]) +
       Controller_with_out_ref_B.ChooseControllersignal[5]) +
      Controller_with_out_ref_B.NOut_m;

    // Saturate: '<S3>/Saturation'
    if (Controller_with_out_ref_B.SignPreIntegrator >
        Controller_with_out_ref_P.Saturation_UpperSat) {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_P.Saturation_UpperSat;
    } else {
      if (Controller_with_out_ref_B.SignPreIntegrator <
          Controller_with_out_ref_P.Saturation_LowerSat) {
        Controller_with_out_ref_B.SignPreIntegrator =
          Controller_with_out_ref_P.Saturation_LowerSat;
      }
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'
    //   MATLAB Function: '<S3>/Calc pwm signal'
    //   Saturate: '<S3>/Saturation'

    Controller_with_out_ref_B.BusAssignment.Controls[1] = (real32_T)
      ((Controller_with_out_ref_B.SignPreIntegrator + 1.0) * 400.0 + 1100.0);

    // MATLAB Function: '<S2>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S2>/Get buoyancy'
    //   Start for MATLABSystem: '<S2>/Get buoyancy'
    //   MATLABSystem: '<S2>/Get front forward decouple'
    //   Start for MATLABSystem: '<S2>/Get front forward decouple'
    //   MATLABSystem: '<S2>/Get front pitch bias'
    //   Start for MATLABSystem: '<S2>/Get front pitch bias'
    //   MATLABSystem: '<S2>/Get front strafe decouple'
    //   Start for MATLABSystem: '<S2>/Get front strafe decouple'
    //   MATLABSystem: '<S2>/Get front vertical bias'
    //   Start for MATLABSystem: '<S2>/Get front vertical bias'

    Controller_with_out_ref_B.SignPreIntegrator =
      ((((-Controller_with_out_ref_B.ChooseControllersignal[0] -
          Controller_with_out_ref_B.Switch *
          Controller_with_out_ref_B.ChooseControllersignal[3]) +
         Controller_with_out_ref_B.NOut *
         Controller_with_out_ref_B.ChooseControllersignal[4]) -
        Controller_with_out_ref_B.NOut_e *
        Controller_with_out_ref_B.ChooseControllersignal[1]) +
       Controller_with_out_ref_B.Switch_o *
       Controller_with_out_ref_B.ChooseControllersignal[5]) +
      Controller_with_out_ref_B.NOut_m;

    // Saturate: '<S3>/Saturation'
    if (Controller_with_out_ref_B.SignPreIntegrator >
        Controller_with_out_ref_P.Saturation_UpperSat) {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_P.Saturation_UpperSat;
    } else {
      if (Controller_with_out_ref_B.SignPreIntegrator <
          Controller_with_out_ref_P.Saturation_LowerSat) {
        Controller_with_out_ref_B.SignPreIntegrator =
          Controller_with_out_ref_P.Saturation_LowerSat;
      }
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'
    //   MATLAB Function: '<S3>/Calc pwm signal'
    //   Saturate: '<S3>/Saturation'

    Controller_with_out_ref_B.BusAssignment.Controls[2] = (real32_T)
      ((Controller_with_out_ref_B.SignPreIntegrator + 1.0) * 400.0 + 1100.0);

    // MATLAB Function: '<S2>/MATLAB Function'
    Controller_with_out_ref_B.SignPreIntegrator =
      -Controller_with_out_ref_B.ChooseControllersignal[2] +
      Controller_with_out_ref_B.ChooseControllersignal[3];

    // Saturate: '<S3>/Saturation'
    if (Controller_with_out_ref_B.SignPreIntegrator >
        Controller_with_out_ref_P.Saturation_UpperSat) {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_P.Saturation_UpperSat;
    } else {
      if (Controller_with_out_ref_B.SignPreIntegrator <
          Controller_with_out_ref_P.Saturation_LowerSat) {
        Controller_with_out_ref_B.SignPreIntegrator =
          Controller_with_out_ref_P.Saturation_LowerSat;
      }
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'
    //   MATLAB Function: '<S3>/Calc pwm signal'
    //   Saturate: '<S3>/Saturation'

    Controller_with_out_ref_B.BusAssignment.Controls[3] = (real32_T)
      ((Controller_with_out_ref_B.SignPreIntegrator + 1.0) * 400.0 + 1100.0);

    // Saturate: '<S3>/Saturation' incorporates:
    //   MATLAB Function: '<S2>/MATLAB Function'

    if (Controller_with_out_ref_B.ChooseControllersignal[4] >
        Controller_with_out_ref_P.Saturation_UpperSat) {
      Controller_with_out_ref_B.Switch =
        Controller_with_out_ref_P.Saturation_UpperSat;
    } else if (Controller_with_out_ref_B.ChooseControllersignal[4] <
               Controller_with_out_ref_P.Saturation_LowerSat) {
      Controller_with_out_ref_B.Switch =
        Controller_with_out_ref_P.Saturation_LowerSat;
    } else {
      Controller_with_out_ref_B.Switch =
        Controller_with_out_ref_B.ChooseControllersignal[4];
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'
    //   MATLAB Function: '<S3>/Calc pwm signal'
    //   Saturate: '<S3>/Saturation'

    Controller_with_out_ref_B.BusAssignment.Controls[4] = (real32_T)
      ((Controller_with_out_ref_B.Switch + 1.0) * 400.0 + 1100.0);

    // MATLAB Function: '<S2>/MATLAB Function'
    Controller_with_out_ref_B.SignPreIntegrator =
      Controller_with_out_ref_B.ChooseControllersignal[2] +
      Controller_with_out_ref_B.ChooseControllersignal[3];

    // Saturate: '<S3>/Saturation'
    if (Controller_with_out_ref_B.SignPreIntegrator >
        Controller_with_out_ref_P.Saturation_UpperSat) {
      Controller_with_out_ref_B.SignPreIntegrator =
        Controller_with_out_ref_P.Saturation_UpperSat;
    } else {
      if (Controller_with_out_ref_B.SignPreIntegrator <
          Controller_with_out_ref_P.Saturation_LowerSat) {
        Controller_with_out_ref_B.SignPreIntegrator =
          Controller_with_out_ref_P.Saturation_LowerSat;
      }
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'
    //   MATLAB Function: '<S3>/Calc pwm signal'
    //   Saturate: '<S3>/Saturation'

    Controller_with_out_ref_B.BusAssignment.Controls[5] = (real32_T)
      ((Controller_with_out_ref_B.SignPreIntegrator + 1.0) * 400.0 + 1100.0);

    // Saturate: '<S3>/Saturation' incorporates:
    //   Constant: '<S3>/zero on last two channels'

    if (Controller_with_out_ref_P.zeroonlasttwochannels_Value >
        Controller_with_out_ref_P.Saturation_UpperSat) {
      rtb_Switch_ax = Controller_with_out_ref_P.Saturation_UpperSat;
    } else if (Controller_with_out_ref_P.zeroonlasttwochannels_Value <
               Controller_with_out_ref_P.Saturation_LowerSat) {
      rtb_Switch_ax = Controller_with_out_ref_P.Saturation_LowerSat;
    } else {
      rtb_Switch_ax = Controller_with_out_ref_P.zeroonlasttwochannels_Value;
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'
    //   MATLAB Function: '<S3>/Calc pwm signal'
    //   Saturate: '<S3>/Saturation'

    Controller_with_out_ref_B.BusAssignment.Controls[6] = (real32_T)
      ((rtb_Switch_ax + 1.0) * 400.0 + 1100.0);

    // Saturate: '<S3>/Saturation' incorporates:
    //   Constant: '<S3>/zero on last two channels'

    if (Controller_with_out_ref_P.zeroonlasttwochannels_Value >
        Controller_with_out_ref_P.Saturation_UpperSat) {
      rtb_Switch_ax = Controller_with_out_ref_P.Saturation_UpperSat;
    } else if (Controller_with_out_ref_P.zeroonlasttwochannels_Value <
               Controller_with_out_ref_P.Saturation_LowerSat) {
      rtb_Switch_ax = Controller_with_out_ref_P.Saturation_LowerSat;
    } else {
      rtb_Switch_ax = Controller_with_out_ref_P.zeroonlasttwochannels_Value;
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   Constant: '<S3>/Constant'
    //   DataTypeConversion: '<S3>/Data Type Conversion'
    //   MATLAB Function: '<S3>/Calc pwm signal'
    //   Saturate: '<S3>/Saturation'

    Controller_with_out_ref_B.BusAssignment.Controls[7] = (real32_T)
      ((rtb_Switch_ax + 1.0) * 400.0 + 1100.0);
    Controller_with_out_ref_B.BusAssignment.GroupMix =
      Controller_with_out_ref_P.Constant_Value_j;

    // Outputs for Atomic SubSystem: '<S3>/Publish'
    // MATLABSystem: '<S13>/SinkBlock'
    Pub_Controller_with_out_ref_607.publish
      (&Controller_with_out_ref_B.BusAssignment);

    // End of Outputs for SubSystem: '<S3>/Publish'
  }

  // End of Outputs for SubSystem: '<Root>/Subsystem'

  // Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
  Controller_with_out_ref_DW.DiscreteTimeIntegrator_DSTATE +=
    Controller_with_out_ref_P.DiscreteTimeIntegrator_gainval *
    Controller_with_out_ref_B.OutportBufferForaccXms2;

  // Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
  Controller_with_out_ref_DW.DiscreteTimeIntegrator1_DSTATE +=
    Controller_with_out_ref_P.DiscreteTimeIntegrator1_gainval *
    Controller_with_out_ref_B.OutportBufferForaccYms2;

  // Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator2'
  Controller_with_out_ref_DW.DiscreteTimeIntegrator2_DSTATE +=
    Controller_with_out_ref_P.DiscreteTimeIntegrator2_gainval *
    Controller_with_out_ref_B.OutportBufferForaccZms2;
}

// Model initialize function
void ControllerModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus((&Controller_with_out_ref_M), (NULL));

  // block I/O
  (void) memset(((void *) &Controller_with_out_ref_B), 0,
                sizeof(B_Controller_with_out_ref_T));

  // states (dwork)
  (void) memset((void *)&Controller_with_out_ref_DW, 0,
                sizeof(DW_Controller_with_out_ref_T));

  {
    static const char_T tmp[24] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/', 'a',
      'c', 't', 'u', 'a', 't', 'o', 'r', '_', 'c', 'o', 'n', 't', 'r', 'o', 'l'
    };

    static const char_T tmp_0[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'b', 'u', 'o', 'y',
      'a', 'n', 'c', 'y', '_', 'c', 'o', 'n', 't', 'r', 'o', 'l' };

    static const char_T tmp_1[38] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'f', 'r', 'o', 'n',
      't', '_', 'v', 'e', 'r', 't', 'i', 'c', 'a', 'l', '_', 'b', 'i', 'a', 's'
    };

    static const char_T tmp_2[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'f', 'r', 'o', 'n',
      't', '_', 'p', 'i', 't', 'c', 'h', '_', 'b', 'i', 'a', 's' };

    static const char_T tmp_3[41] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'f', 'r', 'o', 'n',
      't', '_', 'f', 'o', 'r', 'w', 'a', 'r', 'd', '_', 'd', 'e', 'c', 'o', 'u',
      'p', 'l', 'e' };

    static const char_T tmp_4[40] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'f', 'r', 'o', 'n',
      't', '_', 's', 't', 'r', 'a', 'f', 'e', '_', 'd', 'e', 'c', 'o', 'u', 'p',
      'l', 'e' };

    static const char_T tmp_5[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_6[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_7[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_8[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_9[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_a[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_b[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_c[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_d[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_e[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_f[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_g[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_h[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_i[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_j[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_k[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_l[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_m[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_n[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_o[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_p[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_q[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_r[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_s[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_t[16] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'm', 'u', '/', 'd', 'a', 't', 'a' };

    static const char_T tmp_u[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_v[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'c', 'o', 'n', 't',
      'r', 'o', 'l', 'l', 'e', 'r' };

    char_T tmp_w[25];
    char_T tmp_x[17];
    char_T tmp_y[9];
    int32_T i;

    // Start for MATLABSystem: '<Root>/Get controller type'
    Controller_with_out_ref_DW.obj_nl.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_m0 = true;
    Controller_with_out_ref_DW.obj_nl.SampleTime =
      Controller_with_out_ref_P.Getcontrollertype_SampleTime;
    Controller_with_out_ref_DW.obj_nl.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_with_out_ref_B.cv5[i] = tmp_v[i];
    }

    Controller_with_out_ref_B.cv5[29] = '\x00';
    ParamGet_Controller_with_out_ref_106.initialize
      (Controller_with_out_ref_B.cv5, Controlle_ParameterInitialValue, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<Root>/Get controller type'

    // Start for Atomic SubSystem: '<Root>/cmd_vel'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    Controller_with_out_ref_DW.obj_nf.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_gn = true;
    Controller_with_out_ref_DW.obj_nf.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_y[i] = tmp_u[i];
    }

    tmp_y[8] = '\x00';
    Sub_Controller_with_out_ref_1.create_subscriber(tmp_y,
      Controller_wi_MessageQueueLen_i);

    // End of Start for MATLABSystem: '<S6>/SourceBlock'

    // Start for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S14>/Out1'
    Controller_with_out_ref_B.In1_m = Controller_with_out_ref_P.Out1_Y0_f;

    // End of Start for SubSystem: '<S6>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/cmd_vel'

    // Start for Atomic SubSystem: '<Root>/imu_data'
    // Start for MATLABSystem: '<S8>/SourceBlock'
    Controller_with_out_ref_DW.obj_k.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty = true;
    Controller_with_out_ref_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      tmp_x[i] = tmp_t[i];
    }

    tmp_x[16] = '\x00';
    Sub_Controller_with_out_ref_28.create_subscriber(tmp_x,
      Controller_wi_MessageQueueLen_i);

    // End of Start for MATLABSystem: '<S8>/SourceBlock'

    // Start for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S39>/Out1'
    Controller_with_out_ref_B.In1 = Controller_with_out_ref_P.Out1_Y0;

    // End of Start for SubSystem: '<S8>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/imu_data'

    // Start for Enabled SubSystem: '<Root>/Xbox_input'
    // VirtualOutportStart for Outport: '<S4>/<angular_vel X>'
    Controller_with_out_ref_B.X_h = Controller_with_out_ref_P.angular_velX_Y0;

    // VirtualOutportStart for Outport: '<S4>/<angular_vel Y>'
    Controller_with_out_ref_B.Y_i = Controller_with_out_ref_P.angular_velY_Y0;

    // VirtualOutportStart for Outport: '<S4>/<angular_vel Z> '
    Controller_with_out_ref_B.Z_n = Controller_with_out_ref_P.angular_velZ_Y0;

    // VirtualOutportStart for Outport: '<S4>/<velocity X>'
    Controller_with_out_ref_B.X = Controller_with_out_ref_P.velocityX_Y0;

    // VirtualOutportStart for Outport: '<S4>/<veloctiy Y>'
    Controller_with_out_ref_B.Y = Controller_with_out_ref_P.veloctiyY_Y0;

    // VirtualOutportStart for Outport: '<S4>/<velocity Z>'
    Controller_with_out_ref_B.Z = Controller_with_out_ref_P.velocityZ_Y0;

    // End of Start for SubSystem: '<Root>/Xbox_input'

    // Start for Enabled SubSystem: '<Root>/mavros_data'
    // VirtualOutportStart for Outport: '<S9>/<angular_vel X [degrees]>'
    Controller_with_out_ref_B.Gain =
      Controller_with_out_ref_P.angular_velXdegrees_Y0;

    // VirtualOutportStart for Outport: '<S9>/<angular_vel Y [degrees]>'
    Controller_with_out_ref_B.Gain1 =
      Controller_with_out_ref_P.angular_velYdegrees_Y0;

    // VirtualOutportStart for Outport: '<S9>/<angular_vel Z [degrees]>'
    Controller_with_out_ref_B.Gain2 =
      Controller_with_out_ref_P.angular_velZdegrees_Y0;

    // VirtualOutportStart for Outport: '<S9>/<acc X [m//s^2]>'
    Controller_with_out_ref_B.OutportBufferForaccXms2 =
      Controller_with_out_ref_P.accXms2_Y0;

    // VirtualOutportStart for Outport: '<S9>/<acc Y [m//s^2]>'
    Controller_with_out_ref_B.OutportBufferForaccYms2 =
      Controller_with_out_ref_P.accYms2_Y0;

    // VirtualOutportStart for Outport: '<S9>/<acc Z [m//s^2]>'
    Controller_with_out_ref_B.OutportBufferForaccZms2 =
      Controller_with_out_ref_P.accZms2_Y0;

    // End of Start for SubSystem: '<Root>/mavros_data'

    // Start for Enabled SubSystem: '<Root>/Create errors'
    // VirtualOutportStart for Outport: '<S1>/angular_vel x error [degrees]'
    Controller_with_out_ref_B.Errorx =
      Controller_with_out_ref_P.angular_velxerrordegrees_Y0;

    // VirtualOutportStart for Outport: '<S1>/angular_vel y error [degrees]'
    Controller_with_out_ref_B.Errory =
      Controller_with_out_ref_P.angular_velyerrordegrees_Y0;

    // VirtualOutportStart for Outport: '<S1>/angular_vel z error [degrees]'
    Controller_with_out_ref_B.Errorz =
      Controller_with_out_ref_P.angular_velzerrordegrees_Y0;

    // VirtualOutportStart for Outport: '<S1>/vel x error [m//s]'
    Controller_with_out_ref_B.Errorz8 = Controller_with_out_ref_P.velxerrorms_Y0;

    // VirtualOutportStart for Outport: '<S1>/vel y error [m//s]'
    Controller_with_out_ref_B.Errorz9 = Controller_with_out_ref_P.velyerrorms_Y0;

    // VirtualOutportStart for Outport: '<S1>/vel z error [m//s]'
    Controller_with_out_ref_B.Errorz10 =
      Controller_with_out_ref_P.velzerrorms_Y0;

    // End of Start for SubSystem: '<Root>/Create errors'

    // Start for Enabled SubSystem: '<Root>/decController'
    // Start for MATLABSystem: '<S22>/P_angular_vel_x'
    Controller_with_out_ref_DW.obj_bm.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_f = true;
    Controller_with_out_ref_DW.obj_bm.SampleTime =
      Controller_with_out_ref_P.P_angular_vel_x_SampleTime;
    Controller_with_out_ref_DW.obj_bm.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_with_out_ref_B.cv4[i] = tmp_s[i];
    }

    Controller_with_out_ref_B.cv4[34] = '\x00';
    ParamGet_Controller_with_out_ref_508.initialize
      (Controller_with_out_ref_B.cv4, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S22>/P_angular_vel_x'

    // Start for MATLABSystem: '<S22>/D_angular_vel_x'
    Controller_with_out_ref_DW.obj_be.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_g = true;
    Controller_with_out_ref_DW.obj_be.SampleTime =
      Controller_with_out_ref_P.D_angular_vel_x_SampleTime;
    Controller_with_out_ref_DW.obj_be.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_with_out_ref_B.cv4[i] = tmp_r[i];
    }

    Controller_with_out_ref_B.cv4[34] = '\x00';
    ParamGet_Controller_with_out_ref_505.initialize
      (Controller_with_out_ref_B.cv4, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S22>/D_angular_vel_x'

    // Start for MATLABSystem: '<S22>/N_angular_vel_x '
    Controller_with_out_ref_DW.obj_l.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_d0 = true;
    Controller_with_out_ref_DW.obj_l.SampleTime =
      Controller_with_out_ref_P.N_angular_vel_x_SampleTime;
    Controller_with_out_ref_DW.obj_l.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_with_out_ref_B.cv4[i] = tmp_q[i];
    }

    Controller_with_out_ref_B.cv4[34] = '\x00';
    ParamGet_Controller_with_out_ref_507.initialize
      (Controller_with_out_ref_B.cv4, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S22>/N_angular_vel_x '

    // Start for MATLABSystem: '<S22>/I_angular_vel_x'
    Controller_with_out_ref_DW.obj_pb.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_mb = true;
    Controller_with_out_ref_DW.obj_pb.SampleTime =
      Controller_with_out_ref_P.I_angular_vel_x_SampleTime;
    Controller_with_out_ref_DW.obj_pb.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_with_out_ref_B.cv4[i] = tmp_p[i];
    }

    Controller_with_out_ref_B.cv4[34] = '\x00';
    ParamGet_Controller_with_out_ref_506.initialize
      (Controller_with_out_ref_B.cv4, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S22>/I_angular_vel_x'

    // Start for MATLABSystem: '<S25>/P_angular_vel_y'
    Controller_with_out_ref_DW.obj_b.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_j = true;
    Controller_with_out_ref_DW.obj_b.SampleTime =
      Controller_with_out_ref_P.P_angular_vel_y_SampleTime;
    Controller_with_out_ref_DW.obj_b.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_with_out_ref_B.cv4[i] = tmp_o[i];
    }

    Controller_with_out_ref_B.cv4[34] = '\x00';
    ParamGet_Controller_with_out_ref_522.initialize
      (Controller_with_out_ref_B.cv4, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S25>/P_angular_vel_y'

    // Start for MATLABSystem: '<S25>/D_angular_vel_y'
    Controller_with_out_ref_DW.obj_m.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_h1 = true;
    Controller_with_out_ref_DW.obj_m.SampleTime =
      Controller_with_out_ref_P.D_angular_vel_y_SampleTime;
    Controller_with_out_ref_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_with_out_ref_B.cv4[i] = tmp_n[i];
    }

    Controller_with_out_ref_B.cv4[34] = '\x00';
    ParamGet_Controller_with_out_ref_519.initialize
      (Controller_with_out_ref_B.cv4, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S25>/D_angular_vel_y'

    // Start for MATLABSystem: '<S25>/N_angular_vel_y '
    Controller_with_out_ref_DW.obj_dp.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_ex = true;
    Controller_with_out_ref_DW.obj_dp.SampleTime =
      Controller_with_out_ref_P.N_angular_vel_y_SampleTime;
    Controller_with_out_ref_DW.obj_dp.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_with_out_ref_B.cv4[i] = tmp_m[i];
    }

    Controller_with_out_ref_B.cv4[34] = '\x00';
    ParamGet_Controller_with_out_ref_521.initialize
      (Controller_with_out_ref_B.cv4, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S25>/N_angular_vel_y '

    // Start for MATLABSystem: '<S25>/I_angular_vel_y'
    Controller_with_out_ref_DW.obj_ep.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_ef = true;
    Controller_with_out_ref_DW.obj_ep.SampleTime =
      Controller_with_out_ref_P.I_angular_vel_y_SampleTime;
    Controller_with_out_ref_DW.obj_ep.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_with_out_ref_B.cv4[i] = tmp_l[i];
    }

    Controller_with_out_ref_B.cv4[34] = '\x00';
    ParamGet_Controller_with_out_ref_520.initialize
      (Controller_with_out_ref_B.cv4, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S25>/I_angular_vel_y'

    // Start for MATLABSystem: '<S28>/P_angular_vel_z'
    Controller_with_out_ref_DW.obj_e.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_h = true;
    Controller_with_out_ref_DW.obj_e.SampleTime =
      Controller_with_out_ref_P.P_angular_vel_z_SampleTime;
    Controller_with_out_ref_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_with_out_ref_B.cv4[i] = tmp_k[i];
    }

    Controller_with_out_ref_B.cv4[34] = '\x00';
    ParamGet_Controller_with_out_ref_536.initialize
      (Controller_with_out_ref_B.cv4, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S28>/P_angular_vel_z'

    // Start for MATLABSystem: '<S28>/D_angular_vel_z'
    Controller_with_out_ref_DW.obj_jg.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_if = true;
    Controller_with_out_ref_DW.obj_jg.SampleTime =
      Controller_with_out_ref_P.D_angular_vel_z_SampleTime;
    Controller_with_out_ref_DW.obj_jg.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_with_out_ref_B.cv4[i] = tmp_j[i];
    }

    Controller_with_out_ref_B.cv4[34] = '\x00';
    ParamGet_Controller_with_out_ref_533.initialize
      (Controller_with_out_ref_B.cv4, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S28>/D_angular_vel_z'

    // Start for MATLABSystem: '<S28>/N_angular_vel_z '
    Controller_with_out_ref_DW.obj_g.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_m1 = true;
    Controller_with_out_ref_DW.obj_g.SampleTime =
      Controller_with_out_ref_P.N_angular_vel_z_SampleTime;
    Controller_with_out_ref_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_with_out_ref_B.cv4[i] = tmp_i[i];
    }

    Controller_with_out_ref_B.cv4[34] = '\x00';
    ParamGet_Controller_with_out_ref_535.initialize
      (Controller_with_out_ref_B.cv4, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S28>/N_angular_vel_z '

    // Start for MATLABSystem: '<S28>/I_angular_vel_z'
    Controller_with_out_ref_DW.obj_p.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_k = true;
    Controller_with_out_ref_DW.obj_p.SampleTime =
      Controller_with_out_ref_P.I_angular_vel_z_SampleTime;
    Controller_with_out_ref_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_with_out_ref_B.cv4[i] = tmp_h[i];
    }

    Controller_with_out_ref_B.cv4[34] = '\x00';
    ParamGet_Controller_with_out_ref_534.initialize
      (Controller_with_out_ref_B.cv4, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S28>/I_angular_vel_z'

    // Start for MATLABSystem: '<S31>/P_vel_x'
    Controller_with_out_ref_DW.obj_ns.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_a = true;
    Controller_with_out_ref_DW.obj_ns.SampleTime =
      Controller_with_out_ref_P.P_vel_x_SampleTime;
    Controller_with_out_ref_DW.obj_ns.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_with_out_ref_B.cv6[i] = tmp_g[i];
    }

    Controller_with_out_ref_B.cv6[26] = '\x00';
    ParamGet_Controller_with_out_ref_550.initialize
      (Controller_with_out_ref_B.cv6, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S31>/P_vel_x'

    // Start for MATLABSystem: '<S31>/D_vel_x'
    Controller_with_out_ref_DW.obj_d.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_d = true;
    Controller_with_out_ref_DW.obj_d.SampleTime =
      Controller_with_out_ref_P.D_vel_x_SampleTime;
    Controller_with_out_ref_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_with_out_ref_B.cv6[i] = tmp_f[i];
    }

    Controller_with_out_ref_B.cv6[26] = '\x00';
    ParamGet_Controller_with_out_ref_547.initialize
      (Controller_with_out_ref_B.cv6, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S31>/D_vel_x'

    // Start for MATLABSystem: '<S31>/N_vel_x '
    Controller_with_out_ref_DW.obj_a3.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_i = true;
    Controller_with_out_ref_DW.obj_a3.SampleTime =
      Controller_with_out_ref_P.N_vel_x_SampleTime;
    Controller_with_out_ref_DW.obj_a3.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_with_out_ref_B.cv6[i] = tmp_e[i];
    }

    Controller_with_out_ref_B.cv6[26] = '\x00';
    ParamGet_Controller_with_out_ref_549.initialize
      (Controller_with_out_ref_B.cv6, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S31>/N_vel_x '

    // Start for MATLABSystem: '<S31>/I_vel_x'
    Controller_with_out_ref_DW.obj_cv.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_p = true;
    Controller_with_out_ref_DW.obj_cv.SampleTime =
      Controller_with_out_ref_P.I_vel_x_SampleTime;
    Controller_with_out_ref_DW.obj_cv.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_with_out_ref_B.cv6[i] = tmp_d[i];
    }

    Controller_with_out_ref_B.cv6[26] = '\x00';
    ParamGet_Controller_with_out_ref_548.initialize
      (Controller_with_out_ref_B.cv6, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S31>/I_vel_x'

    // Start for MATLABSystem: '<S34>/P_vel_y'
    Controller_with_out_ref_DW.obj_ji.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_ej = true;
    Controller_with_out_ref_DW.obj_ji.SampleTime =
      Controller_with_out_ref_P.P_vel_y_SampleTime;
    Controller_with_out_ref_DW.obj_ji.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_with_out_ref_B.cv6[i] = tmp_c[i];
    }

    Controller_with_out_ref_B.cv6[26] = '\x00';
    ParamGet_Controller_with_out_ref_564.initialize
      (Controller_with_out_ref_B.cv6, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S34>/P_vel_y'

    // Start for MATLABSystem: '<S34>/D_vel_y'
    Controller_with_out_ref_DW.obj_n.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_c = true;
    Controller_with_out_ref_DW.obj_n.SampleTime =
      Controller_with_out_ref_P.D_vel_y_SampleTime;
    Controller_with_out_ref_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_with_out_ref_B.cv6[i] = tmp_b[i];
    }

    Controller_with_out_ref_B.cv6[26] = '\x00';
    ParamGet_Controller_with_out_ref_561.initialize
      (Controller_with_out_ref_B.cv6, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S34>/D_vel_y'

    // Start for MATLABSystem: '<S34>/N_vel_y '
    Controller_with_out_ref_DW.obj_c.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_b = true;
    Controller_with_out_ref_DW.obj_c.SampleTime =
      Controller_with_out_ref_P.N_vel_y_SampleTime;
    Controller_with_out_ref_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_with_out_ref_B.cv6[i] = tmp_a[i];
    }

    Controller_with_out_ref_B.cv6[26] = '\x00';
    ParamGet_Controller_with_out_ref_563.initialize
      (Controller_with_out_ref_B.cv6, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S34>/N_vel_y '

    // Start for MATLABSystem: '<S34>/I_vel_y'
    Controller_with_out_ref_DW.obj_jx.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_m = true;
    Controller_with_out_ref_DW.obj_jx.SampleTime =
      Controller_with_out_ref_P.I_vel_y_SampleTime;
    Controller_with_out_ref_DW.obj_jx.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_with_out_ref_B.cv6[i] = tmp_9[i];
    }

    Controller_with_out_ref_B.cv6[26] = '\x00';
    ParamGet_Controller_with_out_ref_562.initialize
      (Controller_with_out_ref_B.cv6, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S34>/I_vel_y'

    // Start for MATLABSystem: '<S37>/P_vel_z'
    Controller_with_out_ref_DW.obj.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_l = true;
    Controller_with_out_ref_DW.obj.SampleTime =
      Controller_with_out_ref_P.P_vel_z_SampleTime;
    Controller_with_out_ref_DW.obj.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_with_out_ref_B.cv6[i] = tmp_8[i];
    }

    Controller_with_out_ref_B.cv6[26] = '\x00';
    ParamGet_Controller_with_out_ref_578.initialize
      (Controller_with_out_ref_B.cv6, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S37>/P_vel_z'

    // Start for MATLABSystem: '<S37>/D_vel_z'
    Controller_with_out_ref_DW.obj_a.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_n = true;
    Controller_with_out_ref_DW.obj_a.SampleTime =
      Controller_with_out_ref_P.D_vel_z_SampleTime;
    Controller_with_out_ref_DW.obj_a.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_with_out_ref_B.cv6[i] = tmp_7[i];
    }

    Controller_with_out_ref_B.cv6[26] = '\x00';
    ParamGet_Controller_with_out_ref_575.initialize
      (Controller_with_out_ref_B.cv6, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S37>/D_vel_z'

    // Start for MATLABSystem: '<S37>/N_vel_z '
    Controller_with_out_ref_DW.obj_h.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_e = true;
    Controller_with_out_ref_DW.obj_h.SampleTime =
      Controller_with_out_ref_P.N_vel_z_SampleTime;
    Controller_with_out_ref_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_with_out_ref_B.cv6[i] = tmp_6[i];
    }

    Controller_with_out_ref_B.cv6[26] = '\x00';
    ParamGet_Controller_with_out_ref_577.initialize
      (Controller_with_out_ref_B.cv6, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S37>/N_vel_z '

    // Start for MATLABSystem: '<S37>/I_vel_z'
    Controller_with_out_ref_DW.obj_j.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_n4 = true;
    Controller_with_out_ref_DW.obj_j.SampleTime =
      Controller_with_out_ref_P.I_vel_z_SampleTime;
    Controller_with_out_ref_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_with_out_ref_B.cv6[i] = tmp_5[i];
    }

    Controller_with_out_ref_B.cv6[26] = '\x00';
    ParamGet_Controller_with_out_ref_576.initialize
      (Controller_with_out_ref_B.cv6, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S37>/I_vel_z'
    // End of Start for SubSystem: '<Root>/decController'

    // InitializeConditions for Enabled SubSystem: '<Root>/decController'
    // InitializeConditions for DiscreteIntegrator: '<S21>/Integrator'
    Controller_with_out_ref_DW.Integrator_DSTATE =
      Controller_with_out_ref_P.Integrator_IC;

    // InitializeConditions for DiscreteIntegrator: '<S21>/Filter'
    Controller_with_out_ref_DW.Filter_DSTATE =
      Controller_with_out_ref_P.Filter_IC;

    // InitializeConditions for DiscreteIntegrator: '<S24>/Integrator'
    Controller_with_out_ref_DW.Integrator_DSTATE_h =
      Controller_with_out_ref_P.Integrator_IC_o;

    // InitializeConditions for DiscreteIntegrator: '<S24>/Filter'
    Controller_with_out_ref_DW.Filter_DSTATE_c =
      Controller_with_out_ref_P.Filter_IC_n;

    // InitializeConditions for DiscreteIntegrator: '<S27>/Integrator'
    Controller_with_out_ref_DW.Integrator_DSTATE_a =
      Controller_with_out_ref_P.Integrator_IC_d;

    // InitializeConditions for DiscreteIntegrator: '<S27>/Filter'
    Controller_with_out_ref_DW.Filter_DSTATE_f =
      Controller_with_out_ref_P.Filter_IC_c;

    // InitializeConditions for DiscreteIntegrator: '<S30>/Integrator'
    Controller_with_out_ref_DW.Integrator_DSTATE_f =
      Controller_with_out_ref_P.Integrator_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S30>/Filter'
    Controller_with_out_ref_DW.Filter_DSTATE_a =
      Controller_with_out_ref_P.Filter_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S33>/Integrator'
    Controller_with_out_ref_DW.Integrator_DSTATE_n =
      Controller_with_out_ref_P.Integrator_IC_i;

    // InitializeConditions for DiscreteIntegrator: '<S33>/Filter'
    Controller_with_out_ref_DW.Filter_DSTATE_g =
      Controller_with_out_ref_P.Filter_IC_jx;

    // InitializeConditions for DiscreteIntegrator: '<S36>/Integrator'
    Controller_with_out_ref_DW.Integrator_DSTATE_ny =
      Controller_with_out_ref_P.Integrator_IC_m;

    // InitializeConditions for DiscreteIntegrator: '<S36>/Filter'
    Controller_with_out_ref_DW.Filter_DSTATE_cw =
      Controller_with_out_ref_P.Filter_IC_p;

    // End of InitializeConditions for SubSystem: '<Root>/decController'

    // Start for Enabled SubSystem: '<Root>/decController'
    // VirtualOutportStart for Outport: '<S7>/velocites [angular xyz, linear xyz]' 
    Controller_with_out_ref_B.Saturate =
      Controller_with_out_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_with_out_ref_B.Saturate_f =
      Controller_with_out_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_with_out_ref_B.Saturate_i =
      Controller_with_out_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_with_out_ref_B.Saturate_b =
      Controller_with_out_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_with_out_ref_B.Saturate_h =
      Controller_with_out_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_with_out_ref_B.Saturate_bk =
      Controller_with_out_ref_P.velocitesangularxyzlinearxyz_Y0;

    // End of Start for SubSystem: '<Root>/decController'

    // Start for MATLABSystem: '<S2>/Get front strafe decouple'
    Controller_with_out_ref_DW.obj_jl.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_o = true;
    Controller_with_out_ref_DW.obj_jl.SampleTime =
      Controller_with_out_ref_P.Getfrontstrafedecouple_SampleTi;
    Controller_with_out_ref_DW.obj_jl.isInitialized = 1;
    for (i = 0; i < 40; i++) {
      Controller_with_out_ref_B.cv1[i] = tmp_4[i];
    }

    Controller_with_out_ref_B.cv1[40] = '\x00';
    ParamGet_Controller_with_out_ref_465.initialize
      (Controller_with_out_ref_B.cv1, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S2>/Get front strafe decouple'

    // Start for MATLABSystem: '<S2>/Get front forward decouple'
    Controller_with_out_ref_DW.obj_ec.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_fw = true;
    Controller_with_out_ref_DW.obj_ec.SampleTime =
      Controller_with_out_ref_P.Getfrontforwarddecouple_SampleT;
    Controller_with_out_ref_DW.obj_ec.isInitialized = 1;
    for (i = 0; i < 41; i++) {
      Controller_with_out_ref_B.cv0[i] = tmp_3[i];
    }

    Controller_with_out_ref_B.cv0[41] = '\x00';
    ParamGet_Controller_with_out_ref_463.initialize
      (Controller_with_out_ref_B.cv0, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S2>/Get front forward decouple'

    // Start for MATLABSystem: '<S2>/Get front pitch bias'
    Controller_with_out_ref_DW.obj_nj.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_jf = true;
    Controller_with_out_ref_DW.obj_nj.SampleTime =
      Controller_with_out_ref_P.Getfrontpitchbias_SampleTime;
    Controller_with_out_ref_DW.obj_nj.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_with_out_ref_B.cv3[i] = tmp_2[i];
    }

    Controller_with_out_ref_B.cv3[35] = '\x00';
    ParamGet_Controller_with_out_ref_464.initialize
      (Controller_with_out_ref_B.cv3, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S2>/Get front pitch bias'

    // Start for MATLABSystem: '<S2>/Get front vertical bias'
    Controller_with_out_ref_DW.obj_lo.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_b1 = true;
    Controller_with_out_ref_DW.obj_lo.SampleTime =
      Controller_with_out_ref_P.Getfrontverticalbias_SampleTime;
    Controller_with_out_ref_DW.obj_lo.isInitialized = 1;
    for (i = 0; i < 38; i++) {
      Controller_with_out_ref_B.cv2[i] = tmp_1[i];
    }

    Controller_with_out_ref_B.cv2[38] = '\x00';
    ParamGet_Controller_with_out_ref_466.initialize
      (Controller_with_out_ref_B.cv2, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S2>/Get front vertical bias'

    // Start for MATLABSystem: '<S2>/Get buoyancy'
    Controller_with_out_ref_DW.obj_ef.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_bb = true;
    Controller_with_out_ref_DW.obj_ef.SampleTime =
      Controller_with_out_ref_P.Getbuoyancy_SampleTime;
    Controller_with_out_ref_DW.obj_ef.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_with_out_ref_B.cv3[i] = tmp_0[i];
    }

    Controller_with_out_ref_B.cv3[35] = '\x00';
    ParamGet_Controller_with_out_ref_462.initialize
      (Controller_with_out_ref_B.cv3, Control_ParameterInitialValue_i, 0U, 1U,
       2U);

    // End of Start for MATLABSystem: '<S2>/Get buoyancy'

    // Start for Enabled SubSystem: '<Root>/Subsystem'
    // Start for Atomic SubSystem: '<S3>/Publish'
    // Start for MATLABSystem: '<S13>/SinkBlock'
    Controller_with_out_ref_DW.obj_pw.isInitialized = 0;
    Controller_with_out_ref_DW.objisempty_nu = true;
    Controller_with_out_ref_DW.obj_pw.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      tmp_w[i] = tmp[i];
    }

    tmp_w[24] = '\x00';
    Pub_Controller_with_out_ref_607.create_publisher(tmp_w,
      Controller_with_MessageQueueLen);

    // End of Start for MATLABSystem: '<S13>/SinkBlock'
    // End of Start for SubSystem: '<S3>/Publish'
    // End of Start for SubSystem: '<Root>/Subsystem'

    // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' 
    Controller_with_out_ref_DW.DiscreteTimeIntegrator_DSTATE =
      Controller_with_out_ref_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' 
    Controller_with_out_ref_DW.DiscreteTimeIntegrator1_DSTATE =
      Controller_with_out_ref_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator2' 
    Controller_with_out_ref_DW.DiscreteTimeIntegrator2_DSTATE =
      Controller_with_out_ref_P.DiscreteTimeIntegrator2_IC;
  }
}

// Model terminate function
void ControllerModelClass::terminate()
{
  // Start for MATLABSystem: '<Root>/Get controller type' incorporates:
  //   Terminate for MATLABSystem: '<Root>/Get controller type'

  if (Controller_with_out_ref_DW.obj_nl.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_nl.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/Get controller type'

  // Terminate for Atomic SubSystem: '<Root>/cmd_vel'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SourceBlock'

  if (Controller_with_out_ref_DW.obj_nf.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_nf.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/cmd_vel'

  // Terminate for Atomic SubSystem: '<Root>/imu_data'
  // Start for MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S8>/SourceBlock'

  if (Controller_with_out_ref_DW.obj_k.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_k.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/imu_data'

  // Terminate for Enabled SubSystem: '<Root>/decController'
  // Start for MATLABSystem: '<S22>/P_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S22>/P_angular_vel_x'

  if (Controller_with_out_ref_DW.obj_bm.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_bm.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S22>/P_angular_vel_x'

  // Start for MATLABSystem: '<S22>/D_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S22>/D_angular_vel_x'

  if (Controller_with_out_ref_DW.obj_be.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_be.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S22>/D_angular_vel_x'

  // Start for MATLABSystem: '<S22>/N_angular_vel_x ' incorporates:
  //   Terminate for MATLABSystem: '<S22>/N_angular_vel_x '

  if (Controller_with_out_ref_DW.obj_l.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_l.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S22>/N_angular_vel_x '

  // Start for MATLABSystem: '<S22>/I_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S22>/I_angular_vel_x'

  if (Controller_with_out_ref_DW.obj_pb.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_pb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S22>/I_angular_vel_x'

  // Start for MATLABSystem: '<S25>/P_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S25>/P_angular_vel_y'

  if (Controller_with_out_ref_DW.obj_b.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_b.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S25>/P_angular_vel_y'

  // Start for MATLABSystem: '<S25>/D_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S25>/D_angular_vel_y'

  if (Controller_with_out_ref_DW.obj_m.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S25>/D_angular_vel_y'

  // Start for MATLABSystem: '<S25>/N_angular_vel_y ' incorporates:
  //   Terminate for MATLABSystem: '<S25>/N_angular_vel_y '

  if (Controller_with_out_ref_DW.obj_dp.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_dp.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S25>/N_angular_vel_y '

  // Start for MATLABSystem: '<S25>/I_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S25>/I_angular_vel_y'

  if (Controller_with_out_ref_DW.obj_ep.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_ep.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S25>/I_angular_vel_y'

  // Start for MATLABSystem: '<S28>/P_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S28>/P_angular_vel_z'

  if (Controller_with_out_ref_DW.obj_e.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S28>/P_angular_vel_z'

  // Start for MATLABSystem: '<S28>/D_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S28>/D_angular_vel_z'

  if (Controller_with_out_ref_DW.obj_jg.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_jg.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S28>/D_angular_vel_z'

  // Start for MATLABSystem: '<S28>/N_angular_vel_z ' incorporates:
  //   Terminate for MATLABSystem: '<S28>/N_angular_vel_z '

  if (Controller_with_out_ref_DW.obj_g.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_g.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S28>/N_angular_vel_z '

  // Start for MATLABSystem: '<S28>/I_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S28>/I_angular_vel_z'

  if (Controller_with_out_ref_DW.obj_p.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_p.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S28>/I_angular_vel_z'

  // Start for MATLABSystem: '<S31>/P_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S31>/P_vel_x'

  if (Controller_with_out_ref_DW.obj_ns.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_ns.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S31>/P_vel_x'

  // Start for MATLABSystem: '<S31>/D_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S31>/D_vel_x'

  if (Controller_with_out_ref_DW.obj_d.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_d.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S31>/D_vel_x'

  // Start for MATLABSystem: '<S31>/N_vel_x ' incorporates:
  //   Terminate for MATLABSystem: '<S31>/N_vel_x '

  if (Controller_with_out_ref_DW.obj_a3.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_a3.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S31>/N_vel_x '

  // Start for MATLABSystem: '<S31>/I_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S31>/I_vel_x'

  if (Controller_with_out_ref_DW.obj_cv.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_cv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S31>/I_vel_x'

  // Start for MATLABSystem: '<S34>/P_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S34>/P_vel_y'

  if (Controller_with_out_ref_DW.obj_ji.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_ji.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S34>/P_vel_y'

  // Start for MATLABSystem: '<S34>/D_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S34>/D_vel_y'

  if (Controller_with_out_ref_DW.obj_n.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S34>/D_vel_y'

  // Start for MATLABSystem: '<S34>/N_vel_y ' incorporates:
  //   Terminate for MATLABSystem: '<S34>/N_vel_y '

  if (Controller_with_out_ref_DW.obj_c.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_c.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S34>/N_vel_y '

  // Start for MATLABSystem: '<S34>/I_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S34>/I_vel_y'

  if (Controller_with_out_ref_DW.obj_jx.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_jx.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S34>/I_vel_y'

  // Start for MATLABSystem: '<S37>/P_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S37>/P_vel_z'

  if (Controller_with_out_ref_DW.obj.isInitialized == 1) {
    Controller_with_out_ref_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S37>/P_vel_z'

  // Start for MATLABSystem: '<S37>/D_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S37>/D_vel_z'

  if (Controller_with_out_ref_DW.obj_a.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_a.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S37>/D_vel_z'

  // Start for MATLABSystem: '<S37>/N_vel_z ' incorporates:
  //   Terminate for MATLABSystem: '<S37>/N_vel_z '

  if (Controller_with_out_ref_DW.obj_h.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S37>/N_vel_z '

  // Start for MATLABSystem: '<S37>/I_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S37>/I_vel_z'

  if (Controller_with_out_ref_DW.obj_j.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S37>/I_vel_z'
  // End of Terminate for SubSystem: '<Root>/decController'

  // Start for MATLABSystem: '<S2>/Get front strafe decouple' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get front strafe decouple'

  if (Controller_with_out_ref_DW.obj_jl.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_jl.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get front strafe decouple'

  // Start for MATLABSystem: '<S2>/Get front forward decouple' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get front forward decouple'

  if (Controller_with_out_ref_DW.obj_ec.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_ec.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get front forward decouple'

  // Start for MATLABSystem: '<S2>/Get front pitch bias' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get front pitch bias'

  if (Controller_with_out_ref_DW.obj_nj.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_nj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get front pitch bias'

  // Start for MATLABSystem: '<S2>/Get front vertical bias' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get front vertical bias'

  if (Controller_with_out_ref_DW.obj_lo.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_lo.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get front vertical bias'

  // Start for MATLABSystem: '<S2>/Get buoyancy' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get buoyancy'

  if (Controller_with_out_ref_DW.obj_ef.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_ef.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get buoyancy'

  // Terminate for Enabled SubSystem: '<Root>/Subsystem'
  // Terminate for Atomic SubSystem: '<S3>/Publish'
  // Start for MATLABSystem: '<S13>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S13>/SinkBlock'

  if (Controller_with_out_ref_DW.obj_pw.isInitialized == 1) {
    Controller_with_out_ref_DW.obj_pw.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S13>/SinkBlock'
  // End of Terminate for SubSystem: '<S3>/Publish'
  // End of Terminate for SubSystem: '<Root>/Subsystem'
}

// Constructor
ControllerModelClass::ControllerModelClass()
{
  static const P_Controller_with_out_ref_T Controller_with_out_ref_P_temp = {
    1.0,                               // Mask Parameter: PIDController_Kt
                                       //  Referenced by: '<S21>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_j
                                       //  Referenced by: '<S24>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_p
                                       //  Referenced by: '<S27>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_jw
                                       //  Referenced by: '<S30>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_c
                                       //  Referenced by: '<S33>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_l
                                       //  Referenced by: '<S36>/Kt'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturationLi
                                       //  Referenced by:
                                       //    '<S21>/Saturate'
                                       //    '<S23>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_e
                                       //  Referenced by:
                                       //    '<S24>/Saturate'
                                       //    '<S26>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_p
                                       //  Referenced by:
                                       //    '<S27>/Saturate'
                                       //    '<S29>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_i
                                       //  Referenced by:
                                       //    '<S30>/Saturate'
                                       //    '<S32>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_g
                                       //  Referenced by:
                                       //    '<S33>/Saturate'
                                       //    '<S35>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturatio_pm
                                       //  Referenced by:
                                       //    '<S36>/Saturate'
                                       //    '<S38>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturationLi
                                       //  Referenced by:
                                       //    '<S21>/Saturate'
                                       //    '<S23>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_o
                                       //  Referenced by:
                                       //    '<S24>/Saturate'
                                       //    '<S26>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_e
                                       //  Referenced by:
                                       //    '<S27>/Saturate'
                                       //    '<S29>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_d
                                       //  Referenced by:
                                       //    '<S30>/Saturate'
                                       //    '<S32>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_b
                                       //  Referenced by:
                                       //    '<S33>/Saturate'
                                       //    '<S35>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturatio_ba
                                       //  Referenced by:
                                       //    '<S36>/Saturate'
                                       //    '<S38>/DeadZone'


    {
      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // OrientationCovariance

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // AngularVelocityCovariance

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // LinearAccelerationCovariance

      {
        0U,                            // Seq

        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // FrameId

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // FrameId_SL_Info

        {
          0,                           // Sec
          0                            // Nsec
        }                              // Stamp
      },                               // Header

      {
        0.0,                           // X
        0.0,                           // Y
        0.0,                           // Z
        0.0                            // W
      },                               // Orientation

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // AngularVelocity

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      }                                // LinearAcceleration
    },                                 // Computed Parameter: Out1_Y0
                                       //  Referenced by: '<S39>/Out1'


    {
      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // OrientationCovariance

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // AngularVelocityCovariance

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // LinearAccelerationCovariance

      {
        0U,                            // Seq

        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // FrameId

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // FrameId_SL_Info

        {
          0,                           // Sec
          0                            // Nsec
        }                              // Stamp
      },                               // Header

      {
        0.0,                           // X
        0.0,                           // Y
        0.0,                           // Z
        0.0                            // W
      },                               // Orientation

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // AngularVelocity

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      }                                // LinearAcceleration
    },                                 // Computed Parameter: Constant_Value
                                       //  Referenced by: '<S8>/Constant'


    {
      0U,                              // GroupMix

      {
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
      ,                                // Controls

      {
        0U,                            // Seq

        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // FrameId

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // FrameId_SL_Info

        {
          0,                           // Sec
          0                            // Nsec
        }                              // Stamp
      }                                // Header
    },                                 // Computed Parameter: Constant_Value_i
                                       //  Referenced by: '<S11>/Constant'


    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Linear

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      }                                // Angular
    },                                 // Computed Parameter: Out1_Y0_f
                                       //  Referenced by: '<S14>/Out1'


    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Linear

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      }                                // Angular
    },                                 // Computed Parameter: Constant_Value_d
                                       //  Referenced by: '<S6>/Constant'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<Root>/Constant4'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<Root>/Get controller type'

    0.0,                               // Computed Parameter: yawerrordegrees_Y0
                                       //  Referenced by: '<S1>/yaw error [degrees]'

    0.0,                               // Computed Parameter: pitcherrordegrees_Y0
                                       //  Referenced by: '<S1>/pitch error [degrees]'

    0.0,                               // Computed Parameter: rollerrordegrees_Y0
                                       //  Referenced by: '<S1>/roll error [degrees]'

    0.0,                               // Computed Parameter: angular_velxerrordegrees_Y0
                                       //  Referenced by: '<S1>/angular_vel x error [degrees]'

    0.0,                               // Computed Parameter: angular_velyerrordegrees_Y0
                                       //  Referenced by: '<S1>/angular_vel y error [degrees]'

    0.0,                               // Computed Parameter: angular_velzerrordegrees_Y0
                                       //  Referenced by: '<S1>/angular_vel z error [degrees]'

    0.0,                               // Computed Parameter: xerrorms_Y0
                                       //  Referenced by: '<S1>/x error [m//s]'

    0.0,                               // Computed Parameter: yerrorm_Y0
                                       //  Referenced by: '<S1>/y error [m]'

    0.0,                               // Computed Parameter: zerrorm_Y0
                                       //  Referenced by: '<S1>/z error [m]'

    0.0,                               // Computed Parameter: velxerrorms_Y0
                                       //  Referenced by: '<S1>/vel x error [m//s]'

    0.0,                               // Computed Parameter: velyerrorms_Y0
                                       //  Referenced by: '<S1>/vel y error [m//s]'

    0.0,                               // Computed Parameter: velzerrorms_Y0
                                       //  Referenced by: '<S1>/vel z error [m//s]'

    0.0,                               // Computed Parameter: accxerrorms_Y0
                                       //  Referenced by: '<S1>/acc x error [m//s]'

    0.0,                               // Computed Parameter: accyerrorms_Y0
                                       //  Referenced by: '<S1>/acc y error [m//s]'

    0.0,                               // Computed Parameter: acczerrorms_Y0
                                       //  Referenced by: '<S1>/acc z error [m//s]'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S2>/Get buoyancy'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S2>/Get front vertical bias'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S2>/Get front pitch bias'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S2>/Get front forward decouple'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S2>/Get front strafe decouple'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S3>/zero on last two channels'

    1.0,                               // Expression: 1
                                       //  Referenced by: '<S3>/Saturation'

    -1.0,                              // Expression: -1
                                       //  Referenced by: '<S3>/Saturation'

    0.0,                               // Computed Parameter: angular_velX_Y0
                                       //  Referenced by: '<S4>/<angular_vel X>'

    0.0,                               // Computed Parameter: angular_velY_Y0
                                       //  Referenced by: '<S4>/<angular_vel Y>'

    0.0,                               // Computed Parameter: angular_velZ_Y0
                                       //  Referenced by: '<S4>/<angular_vel Z> '

    0.0,                               // Computed Parameter: velocityX_Y0
                                       //  Referenced by: '<S4>/<velocity X>'

    0.0,                               // Computed Parameter: veloctiyY_Y0
                                       //  Referenced by: '<S4>/<veloctiy Y>'

    0.0,                               // Computed Parameter: velocityZ_Y0
                                       //  Referenced by: '<S4>/<velocity Z>'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S22>/I_angular_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S22>/N_angular_vel_x '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S22>/D_angular_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S22>/P_angular_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S25>/I_angular_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S25>/N_angular_vel_y '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S25>/D_angular_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S25>/P_angular_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S28>/I_angular_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S28>/N_angular_vel_z '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S28>/D_angular_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S28>/P_angular_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S31>/I_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S31>/N_vel_x '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S31>/D_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S31>/P_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S34>/I_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S34>/N_vel_y '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S34>/D_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S34>/P_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S37>/I_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S37>/N_vel_z '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S37>/D_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S37>/P_vel_z'

    0.0,                               // Computed Parameter: velocitesangularxyzlinearxyz_Y0
                                       //  Referenced by: '<S7>/velocites [angular xyz, linear xyz]'

    0.2,                               // Computed Parameter: Integrator_gainval
                                       //  Referenced by: '<S21>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S21>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval
                                       //  Referenced by: '<S21>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S21>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S23>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S21>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_c
                                       //  Referenced by: '<S24>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S24>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_i
                                       //  Referenced by: '<S24>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S24>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S26>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S24>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_n
                                       //  Referenced by: '<S27>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S27>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_k
                                       //  Referenced by: '<S27>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S27>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S29>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S27>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_j
                                       //  Referenced by: '<S30>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S30>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_h
                                       //  Referenced by: '<S30>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S30>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S32>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S30>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_np
                                       //  Referenced by: '<S33>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S33>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_h0
                                       //  Referenced by: '<S33>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S33>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S35>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S33>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_m
                                       //  Referenced by: '<S36>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S36>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_b
                                       //  Referenced by: '<S36>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S36>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S38>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S36>/Constant'

    0.0,                               // Computed Parameter: yawdegrees_Y0
                                       //  Referenced by: '<S9>/<yaw [degrees]>'

    0.0,                               // Computed Parameter: pitchdegrees_Y0
                                       //  Referenced by: '<S9>/<pitch [degrees]>'

    0.0,                               // Computed Parameter: rolldegrees_Y0
                                       //  Referenced by: '<S9>/<roll [degrees]>'

    0.0,                               // Computed Parameter: angular_velXdegrees_Y0
                                       //  Referenced by: '<S9>/<angular_vel X [degrees]>'

    0.0,                               // Computed Parameter: angular_velYdegrees_Y0
                                       //  Referenced by: '<S9>/<angular_vel Y [degrees]>'

    0.0,                               // Computed Parameter: angular_velZdegrees_Y0
                                       //  Referenced by: '<S9>/<angular_vel Z [degrees]>'

    0.0,                               // Computed Parameter: accXms2_Y0
                                       //  Referenced by: '<S9>/<acc X [m//s^2]>'

    0.0,                               // Computed Parameter: accYms2_Y0
                                       //  Referenced by: '<S9>/<acc Y [m//s^2]>'

    0.0,                               // Computed Parameter: accZms2_Y0
                                       //  Referenced by: '<S9>/<acc Z [m//s^2]>'

    57.295779513082323,                // Expression: 180/pi
                                       //  Referenced by: '<S9>/Gain'

    -57.295779513082323,               // Expression: -180/pi
                                       //  Referenced by: '<S9>/Gain1'

    -57.295779513082323,               // Expression: -180/pi
                                       //  Referenced by: '<S9>/Gain2'

    0.2,                               // Computed Parameter: DiscreteTimeIntegrator_gainval
                                       //  Referenced by: '<S5>/Discrete-Time Integrator'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S5>/Discrete-Time Integrator'

    0.2,                               // Computed Parameter: DiscreteTimeIntegrator1_gainval
                                       //  Referenced by: '<S5>/Discrete-Time Integrator1'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S5>/Discrete-Time Integrator1'

    0.2,                               // Computed Parameter: DiscreteTimeIntegrator2_gainval
                                       //  Referenced by: '<S5>/Discrete-Time Integrator2'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S5>/Discrete-Time Integrator2'

    0U                                 // Computed Parameter: Constant_Value_j
                                       //  Referenced by: '<S3>/Constant'

  };                                   // Modifiable parameters

  // Initialize tunable parameters
  Controller_with_out_ref_P = Controller_with_out_ref_P_temp;
}

// Destructor
ControllerModelClass::~ControllerModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Controller_with_out__T * ControllerModelClass::getRTM()
{
  return (&Controller_with_out_ref_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
