//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Controller_without_ref.cpp
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
#include "Controller_without_ref.h"
#include "Controller_without_ref_private.h"
#define Contro_ParameterInitialValue_oe (false)
#define Control_ParameterInitialValue_o (0.0)
#define Controlle_ParameterInitialValue (0)
#define Controller_wi_MessageQueueLen_o (1)
#define Controller_with_MessageQueueLen (10)

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

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = u0 / u1;
      if (fabs(u1_0 - rt_roundd_snf(u1_0)) <= DBL_EPSILON * fabs(u1_0)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S8>/removeGravity'
void ControllerModelClass::Controller_without_ref_sind(real_T *x)
{
  int8_T n;
  real_T c_x;
  real_T absx;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    c_x = (rtNaN);
  } else {
    c_x = rt_remd_snf(*x, 360.0);
    absx = fabs(c_x);
    if (absx > 180.0) {
      if (c_x > 0.0) {
        c_x -= 360.0;
      } else {
        c_x += 360.0;
      }

      absx = fabs(c_x);
    }

    if (absx <= 45.0) {
      c_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (c_x > 0.0) {
        c_x = (c_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        c_x = (c_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (c_x > 0.0) {
      c_x = (c_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      c_x = (c_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    if (n == 0) {
      c_x = sin(c_x);
    } else if (n == 1) {
      c_x = cos(c_x);
    } else if (n == -1) {
      c_x = -cos(c_x);
    } else {
      c_x = -sin(c_x);
    }
  }

  *x = c_x;
}

// Function for MATLAB Function: '<S8>/removeGravity'
void ControllerModelClass::Controller_without_ref_cosd(real_T *x)
{
  int8_T n;
  real_T b_x;
  real_T absx;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    *x = (rtNaN);
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    if (n == 0) {
      *x = cos(b_x);
    } else if (n == 1) {
      *x = -sin(b_x);
    } else if (n == -1) {
      *x = sin(b_x);
    } else {
      *x = -cos(b_x);
    }
  }
}

// Function for MATLAB Function: '<S8>/removeGravity'
void ControllerModelClass::Controller_without_ref_inv(const real_T x[9], real_T
  y[9])
{
  int32_T p1;
  int32_T p2;
  int32_T p3;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T itmp;
  memcpy(&Controller_without_ref_B.b_x[0], &x[0], 9U * sizeof(real_T));
  p1 = 0;
  p2 = 3;
  p3 = 6;
  absx11 = fabs(x[0]);
  absx21 = fabs(x[1]);
  absx31 = fabs(x[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    Controller_without_ref_B.b_x[0] = x[1];
    Controller_without_ref_B.b_x[1] = x[0];
    Controller_without_ref_B.b_x[3] = x[4];
    Controller_without_ref_B.b_x[4] = x[3];
    Controller_without_ref_B.b_x[6] = x[7];
    Controller_without_ref_B.b_x[7] = x[6];
  } else {
    if (absx31 > absx11) {
      p1 = 6;
      p3 = 0;
      Controller_without_ref_B.b_x[0] = x[2];
      Controller_without_ref_B.b_x[2] = x[0];
      Controller_without_ref_B.b_x[3] = x[5];
      Controller_without_ref_B.b_x[5] = x[3];
      Controller_without_ref_B.b_x[6] = x[8];
      Controller_without_ref_B.b_x[8] = x[6];
    }
  }

  absx11 = Controller_without_ref_B.b_x[1] / Controller_without_ref_B.b_x[0];
  Controller_without_ref_B.b_x[1] /= Controller_without_ref_B.b_x[0];
  absx21 = Controller_without_ref_B.b_x[2] / Controller_without_ref_B.b_x[0];
  Controller_without_ref_B.b_x[2] /= Controller_without_ref_B.b_x[0];
  Controller_without_ref_B.b_x[4] -= absx11 * Controller_without_ref_B.b_x[3];
  Controller_without_ref_B.b_x[5] -= absx21 * Controller_without_ref_B.b_x[3];
  Controller_without_ref_B.b_x[7] -= absx11 * Controller_without_ref_B.b_x[6];
  Controller_without_ref_B.b_x[8] -= absx21 * Controller_without_ref_B.b_x[6];
  if (fabs(Controller_without_ref_B.b_x[5]) > fabs(Controller_without_ref_B.b_x
       [4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    Controller_without_ref_B.b_x[1] = absx21;
    Controller_without_ref_B.b_x[2] = absx11;
    absx11 = Controller_without_ref_B.b_x[4];
    Controller_without_ref_B.b_x[4] = Controller_without_ref_B.b_x[5];
    Controller_without_ref_B.b_x[5] = absx11;
    absx11 = Controller_without_ref_B.b_x[7];
    Controller_without_ref_B.b_x[7] = Controller_without_ref_B.b_x[8];
    Controller_without_ref_B.b_x[8] = absx11;
  }

  absx11 = Controller_without_ref_B.b_x[5] / Controller_without_ref_B.b_x[4];
  Controller_without_ref_B.b_x[5] /= Controller_without_ref_B.b_x[4];
  Controller_without_ref_B.b_x[8] -= absx11 * Controller_without_ref_B.b_x[7];
  absx11 = (Controller_without_ref_B.b_x[5] * Controller_without_ref_B.b_x[1] -
            Controller_without_ref_B.b_x[2]) / Controller_without_ref_B.b_x[8];
  absx21 = -(Controller_without_ref_B.b_x[7] * absx11 +
             Controller_without_ref_B.b_x[1]) / Controller_without_ref_B.b_x[4];
  y[p1] = ((1.0 - Controller_without_ref_B.b_x[3] * absx21) -
           Controller_without_ref_B.b_x[6] * absx11) /
    Controller_without_ref_B.b_x[0];
  y[p1 + 1] = absx21;
  y[p1 + 2] = absx11;
  absx11 = -Controller_without_ref_B.b_x[5] / Controller_without_ref_B.b_x[8];
  absx21 = (1.0 - Controller_without_ref_B.b_x[7] * absx11) /
    Controller_without_ref_B.b_x[4];
  y[p2] = -(Controller_without_ref_B.b_x[3] * absx21 +
            Controller_without_ref_B.b_x[6] * absx11) /
    Controller_without_ref_B.b_x[0];
  y[p2 + 1] = absx21;
  y[p2 + 2] = absx11;
  absx11 = 1.0 / Controller_without_ref_B.b_x[8];
  absx21 = -Controller_without_ref_B.b_x[7] * absx11 /
    Controller_without_ref_B.b_x[4];
  y[p3] = -(Controller_without_ref_B.b_x[3] * absx21 +
            Controller_without_ref_B.b_x[6] * absx11) /
    Controller_without_ref_B.b_x[0];
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
  if (!(Controller_without_ref_DWork.obj_nl.SampleTime ==
        Controller_without_ref_P.Getcontrollertype_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_nl.SampleTime =
      Controller_without_ref_P.Getcontrollertype_SampleTime;
  }

  ParamGet_Controller_without_ref_106.get_parameter(&i);

  // End of Start for MATLABSystem: '<Root>/Get controller type'

  // Outputs for Atomic SubSystem: '<Root>/cmd_vel'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   MATLABSystem: '<S5>/SourceBlock'

  rtb_LogicalOperator = Sub_Controller_without_ref_1.get_latest_msg
    (&Controller_without_ref_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  // MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S11>/In1'

  if (rtb_LogicalOperator) {
    Controller_without_ref_B.In1_m = Controller_without_ref_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/cmd_vel'

  // Outputs for Atomic SubSystem: '<Root>/imu_data'
  // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   MATLABSystem: '<S7>/SourceBlock'

  p = Sub_Controller_without_ref_28.get_latest_msg
    (&Controller_without_ref_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S36>/Enable'

  // MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Inport: '<S36>/In1'

  if (p) {
    Controller_without_ref_B.In1 = Controller_without_ref_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/cmd_vel'
  // Logic: '<Root>/Logical Operator' incorporates:
  //   MATLABSystem: '<S5>/SourceBlock'
  //   MATLABSystem: '<S7>/SourceBlock'

  rtb_LogicalOperator = (rtb_LogicalOperator || p);

  // End of Outputs for SubSystem: '<Root>/cmd_vel'
  // End of Outputs for SubSystem: '<Root>/imu_data'

  // Outputs for Enabled SubSystem: '<Root>/states' incorporates:
  //   EnablePort: '<S8>/Enable'

  // Outputs for Enabled SubSystem: '<Root>/Xbox_input' incorporates:
  //   EnablePort: '<S3>/Enable'

  if (rtb_LogicalOperator) {
    // SignalConversion: '<S3>/TmpSignal ConversionAtBus SelectorOutport1'
    Controller_without_ref_B.X = Controller_without_ref_B.In1_m.Linear.X;

    // SignalConversion: '<S3>/TmpSignal ConversionAtBus SelectorOutport2'
    Controller_without_ref_B.Y = Controller_without_ref_B.In1_m.Linear.Y;

    // SignalConversion: '<S3>/TmpSignal ConversionAtBus SelectorOutport3'
    Controller_without_ref_B.Z = Controller_without_ref_B.In1_m.Linear.Z;

    // SignalConversion: '<S3>/TmpSignal ConversionAtBus SelectorOutport4'
    Controller_without_ref_B.X_h = Controller_without_ref_B.In1_m.Angular.X;

    // SignalConversion: '<S3>/TmpSignal ConversionAtBus SelectorOutport5'
    Controller_without_ref_B.Y_i = Controller_without_ref_B.In1_m.Angular.Y;

    // SignalConversion: '<S3>/TmpSignal ConversionAtBus SelectorOutport6'
    Controller_without_ref_B.Z_n = Controller_without_ref_B.In1_m.Angular.Z;

    // Gain: '<S8>/Gain' incorporates:
    //   SignalConversion: '<S8>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_without_ref_B.Gain = Controller_without_ref_P.Gain_Gain *
      Controller_without_ref_B.In1.Data[3];

    // Gain: '<S8>/Gain1' incorporates:
    //   SignalConversion: '<S8>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_without_ref_B.Gain1 = Controller_without_ref_P.Gain1_Gain *
      Controller_without_ref_B.In1.Data[4];

    // Gain: '<S8>/Gain2' incorporates:
    //   SignalConversion: '<S8>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_without_ref_B.Gain2 = Controller_without_ref_P.Gain2_Gain *
      Controller_without_ref_B.In1.Data[5];

    // MATLAB Function: '<S8>/removeGravity' incorporates:
    //   SignalConversion: '<S8>/TmpSignal ConversionAtBus SelectorOutport1'

    // MATLAB Function 'states/removeGravity': '<S37>:1'
    //  rotmatrix = [2*w^2+2*x^2-1, 2*x*y-2*w*z, 2*x*z+2*w*y;
    //      2*x*y+2*w*z, 2*w^2+2*y^2-1, 2*x*z-2*w*x;
    //      2*x*z-2*w*y, 2*y*z+2*w*x, 2*w^2+2*z^2-1];
    // '<S37>:1:8'
    Controller_without_ref_B.sfi = Controller_without_ref_B.In1.Data[2];
    Controller_without_ref_sind(&Controller_without_ref_B.sfi);

    // '<S37>:1:9'
    Controller_without_ref_B.cfi = Controller_without_ref_B.In1.Data[2];
    Controller_without_ref_cosd(&Controller_without_ref_B.cfi);

    // '<S37>:1:10'
    Controller_without_ref_B.spsi = Controller_without_ref_B.In1.Data[0];
    Controller_without_ref_sind(&Controller_without_ref_B.spsi);

    // '<S37>:1:11'
    Controller_without_ref_B.cpsi = Controller_without_ref_B.In1.Data[0];
    Controller_without_ref_cosd(&Controller_without_ref_B.cpsi);

    // '<S37>:1:12'
    Controller_without_ref_B.stheta = Controller_without_ref_B.In1.Data[1];
    Controller_without_ref_sind(&Controller_without_ref_B.stheta);

    // '<S37>:1:13'
    Controller_without_ref_B.ctheta_c = Controller_without_ref_B.In1.Data[1];
    Controller_without_ref_cosd(&Controller_without_ref_B.ctheta_c);

    // '<S37>:1:16'
    //  Gravity projected in the body fixed frame
    // '<S37>:1:22'
    Controller_without_ref_B.ctheta[0] = Controller_without_ref_B.ctheta_c *
      Controller_without_ref_B.cpsi;
    Controller_without_ref_B.ctheta[3] = Controller_without_ref_B.ctheta_c *
      Controller_without_ref_B.spsi;
    Controller_without_ref_B.ctheta[6] = -Controller_without_ref_B.sfi;
    Controller_without_ref_B.ctheta[1] = Controller_without_ref_B.sfi *
      Controller_without_ref_B.stheta * Controller_without_ref_B.cpsi -
      Controller_without_ref_B.cfi * Controller_without_ref_B.spsi;
    Controller_without_ref_B.ctheta[4] = Controller_without_ref_B.sfi *
      Controller_without_ref_B.stheta * Controller_without_ref_B.spsi +
      Controller_without_ref_B.cfi * Controller_without_ref_B.cpsi;
    Controller_without_ref_B.ctheta[7] = Controller_without_ref_B.sfi *
      Controller_without_ref_B.ctheta_c;
    Controller_without_ref_B.ctheta[2] = Controller_without_ref_B.cfi *
      Controller_without_ref_B.stheta * Controller_without_ref_B.cpsi +
      Controller_without_ref_B.sfi * Controller_without_ref_B.spsi;
    Controller_without_ref_B.ctheta[5] = Controller_without_ref_B.cfi *
      Controller_without_ref_B.stheta * Controller_without_ref_B.spsi -
      Controller_without_ref_B.sfi * Controller_without_ref_B.spsi;
    Controller_without_ref_B.ctheta[8] = Controller_without_ref_B.cfi *
      Controller_without_ref_B.ctheta_c;
    Controller_without_ref_inv(Controller_without_ref_B.ctheta,
      Controller_without_ref_B.dv0);
    for (i_0 = 0; i_0 < 3; i_0++) {
      Controller_without_ref_B.acc[i_0] = Controller_without_ref_B.dv0[i_0 + 6] *
        -9.8 + (Controller_without_ref_B.dv0[i_0 + 3] * 0.0 +
                Controller_without_ref_B.dv0[i_0] * 0.0);
    }

    // SignalConversion: '<S8>/OutportBufferFor<acc X [m//s^2]>' incorporates:
    //   MATLAB Function: '<S8>/removeGravity'
    //   SignalConversion: '<S8>/TmpSignal ConversionAtBus SelectorOutport1'

    //  Removed gravity from the acceleration
    // '<S37>:1:25'
    // '<S37>:1:26'
    // '<S37>:1:27'
    Controller_without_ref_B.OutportBufferForaccXms2 =
      Controller_without_ref_B.In1.Data[7] + Controller_without_ref_B.acc[0];

    // SignalConversion: '<S8>/OutportBufferFor<acc Y [m//s^2]>' incorporates:
    //   MATLAB Function: '<S8>/removeGravity'
    //   SignalConversion: '<S8>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_without_ref_B.OutportBufferForaccYms2 =
      Controller_without_ref_B.In1.Data[8] + Controller_without_ref_B.acc[1];

    // SignalConversion: '<S8>/OutportBufferFor<acc Z [m//s^2]>' incorporates:
    //   MATLAB Function: '<S8>/removeGravity'
    //   SignalConversion: '<S8>/TmpSignal ConversionAtBus SelectorOutport1'

    Controller_without_ref_B.OutportBufferForaccZms2 =
      Controller_without_ref_B.In1.Data[9] + Controller_without_ref_B.acc[2];
  }

  // End of Outputs for SubSystem: '<Root>/Xbox_input'
  // End of Outputs for SubSystem: '<Root>/states'

  // Start for MATLABSystem: '<S4>/Enable integration?' incorporates:
  //   MATLABSystem: '<S4>/Enable integration?'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_g0.SampleTime ==
        Controller_without_ref_P.Enableintegration_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_g0.SampleTime =
      Controller_without_ref_P.Enableintegration_SampleTime;
  }

  ParamGet_Controller_without_ref_686.get_parameter(&p);

  // End of Start for MATLABSystem: '<S4>/Enable integration?'

  // DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator2'
  //   Logic: '<S4>/Logical Operator'
  //   MATLABSystem: '<S4>/Enable integration?'

  if (!p) {
    Controller_without_ref_DWork.DiscreteTimeIntegrator_DSTATE =
      Controller_without_ref_P.DiscreteTimeIntegrator_IC;
    Controller_without_ref_DWork.DiscreteTimeIntegrator1_DSTATE =
      Controller_without_ref_P.DiscreteTimeIntegrator1_IC;
    Controller_without_ref_DWork.DiscreteTimeIntegrator2_DSTATE =
      Controller_without_ref_P.DiscreteTimeIntegrator2_IC;
  }

  // Outputs for Enabled SubSystem: '<Root>/decController' incorporates:
  //   EnablePort: '<S6>/Enable'

  // Outputs for Enabled SubSystem: '<Root>/Create errors' incorporates:
  //   EnablePort: '<S1>/Enable'

  if (rtb_LogicalOperator) {
    // Sum: '<S1>/Error x'
    Controller_without_ref_B.Errorx = Controller_without_ref_B.X_h -
      Controller_without_ref_B.Gain;

    // Sum: '<S1>/Error y'
    Controller_without_ref_B.Errory = Controller_without_ref_B.Y_i -
      Controller_without_ref_B.Gain1;

    // Sum: '<S1>/Error z'
    Controller_without_ref_B.Errorz = Controller_without_ref_B.Z_n -
      Controller_without_ref_B.Gain2;

    // Sum: '<S1>/Error z8' incorporates:
    //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator'

    Controller_without_ref_B.Errorz8 = Controller_without_ref_B.X -
      Controller_without_ref_DWork.DiscreteTimeIntegrator_DSTATE;

    // Sum: '<S1>/Error z9' incorporates:
    //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'

    Controller_without_ref_B.Errorz9 = Controller_without_ref_B.Y -
      Controller_without_ref_DWork.DiscreteTimeIntegrator1_DSTATE;

    // Sum: '<S1>/Error z10' incorporates:
    //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator2'

    Controller_without_ref_B.Errorz10 = Controller_without_ref_B.Z -
      Controller_without_ref_DWork.DiscreteTimeIntegrator2_DSTATE;

    // Start for MATLABSystem: '<S19>/P_angular_vel_x' incorporates:
    //   MATLABSystem: '<S19>/P_angular_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_bm.SampleTime ==
          Controller_without_ref_P.P_angular_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_bm.SampleTime =
        Controller_without_ref_P.P_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_508.get_parameter
      (&Controller_without_ref_B.cfi);

    // End of Start for MATLABSystem: '<S19>/P_angular_vel_x'

    // Start for MATLABSystem: '<S19>/D_angular_vel_x' incorporates:
    //   MATLABSystem: '<S19>/D_angular_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_be.SampleTime ==
          Controller_without_ref_P.D_angular_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_be.SampleTime =
        Controller_without_ref_P.D_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_505.get_parameter
      (&Controller_without_ref_B.sfi);

    // End of Start for MATLABSystem: '<S19>/D_angular_vel_x'

    // Start for MATLABSystem: '<S19>/N_angular_vel_x ' incorporates:
    //   MATLABSystem: '<S19>/N_angular_vel_x '

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_l.SampleTime ==
          Controller_without_ref_P.N_angular_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_l.SampleTime =
        Controller_without_ref_P.N_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_507.get_parameter
      (&Controller_without_ref_B.spsi);

    // End of Start for MATLABSystem: '<S19>/N_angular_vel_x '

    // Product: '<S18>/NOut' incorporates:
    //   DiscreteIntegrator: '<S18>/Filter'
    //   MATLABSystem: '<S19>/D_angular_vel_x'
    //   MATLABSystem: '<S19>/N_angular_vel_x '
    //   Product: '<S18>/DOut'
    //   Sum: '<S18>/SumD'

    Controller_without_ref_B.sfi = (Controller_without_ref_B.Errorx *
      Controller_without_ref_B.sfi - Controller_without_ref_DWork.Filter_DSTATE)
      * Controller_without_ref_B.spsi;

    // Sum: '<S18>/Sum' incorporates:
    //   DiscreteIntegrator: '<S18>/Integrator'
    //   MATLABSystem: '<S19>/P_angular_vel_x'
    //   Product: '<S18>/POut'

    Controller_without_ref_B.SignPreIntegrator =
      (Controller_without_ref_B.Errorx * Controller_without_ref_B.cfi +
       Controller_without_ref_DWork.Integrator_DSTATE) +
      Controller_without_ref_B.sfi;

    // DeadZone: '<S20>/DeadZone'
    if (Controller_without_ref_B.SignPreIntegrator >
        Controller_without_ref_P.PIDController_UpperSaturationLi) {
      Controller_without_ref_B.SumI1 =
        Controller_without_ref_B.SignPreIntegrator -
        Controller_without_ref_P.PIDController_UpperSaturationLi;
    } else if (Controller_without_ref_B.SignPreIntegrator >=
               Controller_without_ref_P.PIDController_LowerSaturationLi) {
      Controller_without_ref_B.SumI1 = 0.0;
    } else {
      Controller_without_ref_B.SumI1 =
        Controller_without_ref_B.SignPreIntegrator -
        Controller_without_ref_P.PIDController_LowerSaturationLi;
    }

    // End of DeadZone: '<S20>/DeadZone'

    // RelationalOperator: '<S20>/NotEqual' incorporates:
    //   Gain: '<S20>/ZeroGain'

    rtb_NotEqual = (Controller_without_ref_P.ZeroGain_Gain *
                    Controller_without_ref_B.SignPreIntegrator !=
                    Controller_without_ref_B.SumI1);

    // Signum: '<S20>/SignDeltaU'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      Controller_without_ref_B.SumI1 = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      Controller_without_ref_B.SumI1 = 1.0;
    } else {
      if (Controller_without_ref_B.SumI1 == 0.0) {
        Controller_without_ref_B.SumI1 = 0.0;
      }
    }

    // End of Signum: '<S20>/SignDeltaU'

    // DataTypeConversion: '<S20>/DataTypeConv1'
    if (Controller_without_ref_B.SumI1 < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_without_ref_B.SumI1;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // Start for MATLABSystem: '<S19>/I_angular_vel_x' incorporates:
    //   MATLABSystem: '<S19>/I_angular_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_pb.SampleTime ==
          Controller_without_ref_P.I_angular_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_pb.SampleTime =
        Controller_without_ref_P.I_angular_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_506.get_parameter
      (&Controller_without_ref_B.cfi);

    // End of Start for MATLABSystem: '<S19>/I_angular_vel_x'

    // Saturate: '<S18>/Saturate'
    if (Controller_without_ref_B.SignPreIntegrator >
        Controller_without_ref_P.PIDController_UpperSaturationLi) {
      Controller_without_ref_B.Saturate =
        Controller_without_ref_P.PIDController_UpperSaturationLi;
    } else if (Controller_without_ref_B.SignPreIntegrator <
               Controller_without_ref_P.PIDController_LowerSaturationLi) {
      Controller_without_ref_B.Saturate =
        Controller_without_ref_P.PIDController_LowerSaturationLi;
    } else {
      Controller_without_ref_B.Saturate =
        Controller_without_ref_B.SignPreIntegrator;
    }

    // End of Saturate: '<S18>/Saturate'

    // Sum: '<S18>/SumI1' incorporates:
    //   Gain: '<S18>/Kt'
    //   MATLABSystem: '<S19>/I_angular_vel_x'
    //   Product: '<S18>/IOut'
    //   Sum: '<S18>/SumI3'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.X_h -
      Controller_without_ref_B.Saturate) *
      Controller_without_ref_P.PIDController_Kt +
      Controller_without_ref_B.Errorx * Controller_without_ref_B.cfi;

    // Signum: '<S20>/SignPreIntegrator'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S20>/DataTypeConv2'
      rtb_Switch_ax = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S20>/DataTypeConv2'
      rtb_Switch_ax = 1.0;
    } else if (Controller_without_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S20>/DataTypeConv2'
      rtb_Switch_ax = 0.0;
    } else {
      // DataTypeConversion: '<S20>/DataTypeConv2'
      rtb_Switch_ax = Controller_without_ref_B.SumI1;
    }

    // End of Signum: '<S20>/SignPreIntegrator'

    // DataTypeConversion: '<S20>/DataTypeConv2'
    if (rtb_Switch_ax < 128.0) {
      tmp = (int8_T)rtb_Switch_ax;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S18>/Switch' incorporates:
    //   Constant: '<S18>/Constant'
    //   DataTypeConversion: '<S20>/DataTypeConv1'
    //   Logic: '<S20>/AND'
    //   RelationalOperator: '<S20>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_without_ref_B.cfi = Controller_without_ref_P.Constant_Value_k;
    } else {
      Controller_without_ref_B.cfi = Controller_without_ref_B.SumI1;
    }

    // End of Switch: '<S18>/Switch'

    // Start for MATLABSystem: '<S22>/P_angular_vel_y' incorporates:
    //   MATLABSystem: '<S22>/P_angular_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_b.SampleTime ==
          Controller_without_ref_P.P_angular_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_b.SampleTime =
        Controller_without_ref_P.P_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_522.get_parameter
      (&Controller_without_ref_B.cpsi);

    // End of Start for MATLABSystem: '<S22>/P_angular_vel_y'

    // Start for MATLABSystem: '<S22>/D_angular_vel_y' incorporates:
    //   MATLABSystem: '<S22>/D_angular_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_m.SampleTime ==
          Controller_without_ref_P.D_angular_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_m.SampleTime =
        Controller_without_ref_P.D_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_519.get_parameter
      (&Controller_without_ref_B.spsi);

    // End of Start for MATLABSystem: '<S22>/D_angular_vel_y'

    // Start for MATLABSystem: '<S22>/N_angular_vel_y ' incorporates:
    //   MATLABSystem: '<S22>/N_angular_vel_y '

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_dp.SampleTime ==
          Controller_without_ref_P.N_angular_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_dp.SampleTime =
        Controller_without_ref_P.N_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_521.get_parameter
      (&Controller_without_ref_B.stheta);

    // End of Start for MATLABSystem: '<S22>/N_angular_vel_y '

    // Product: '<S21>/NOut' incorporates:
    //   DiscreteIntegrator: '<S21>/Filter'
    //   MATLABSystem: '<S22>/D_angular_vel_y'
    //   MATLABSystem: '<S22>/N_angular_vel_y '
    //   Product: '<S21>/DOut'
    //   Sum: '<S21>/SumD'

    Controller_without_ref_B.spsi = (Controller_without_ref_B.Errory *
      Controller_without_ref_B.spsi -
      Controller_without_ref_DWork.Filter_DSTATE_c) *
      Controller_without_ref_B.stheta;

    // Sum: '<S21>/Sum' incorporates:
    //   DiscreteIntegrator: '<S21>/Integrator'
    //   MATLABSystem: '<S22>/P_angular_vel_y'
    //   Product: '<S21>/POut'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Errory *
      Controller_without_ref_B.cpsi +
      Controller_without_ref_DWork.Integrator_DSTATE_h) +
      Controller_without_ref_B.spsi;

    // DeadZone: '<S23>/DeadZone'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_o) {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_UpperSaturation_o;
    } else if (Controller_without_ref_B.SumI1 >=
               Controller_without_ref_P.PIDController_LowerSaturation_e) {
      Controller_without_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_LowerSaturation_e;
    }

    // End of DeadZone: '<S23>/DeadZone'

    // RelationalOperator: '<S23>/NotEqual' incorporates:
    //   Gain: '<S23>/ZeroGain'

    rtb_NotEqual = (Controller_without_ref_P.ZeroGain_Gain_k *
                    Controller_without_ref_B.SumI1 !=
                    Controller_without_ref_B.SignPreIntegrator);

    // Signum: '<S23>/SignDeltaU'
    if (Controller_without_ref_B.SignPreIntegrator < 0.0) {
      Controller_without_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_without_ref_B.SignPreIntegrator > 0.0) {
      Controller_without_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_without_ref_B.SignPreIntegrator == 0.0) {
        Controller_without_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S23>/SignDeltaU'

    // Start for MATLABSystem: '<S22>/I_angular_vel_y' incorporates:
    //   MATLABSystem: '<S22>/I_angular_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_ep.SampleTime ==
          Controller_without_ref_P.I_angular_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_ep.SampleTime =
        Controller_without_ref_P.I_angular_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_520.get_parameter
      (&Controller_without_ref_B.cpsi);

    // End of Start for MATLABSystem: '<S22>/I_angular_vel_y'

    // Saturate: '<S21>/Saturate'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_o) {
      Controller_without_ref_B.Saturate_f =
        Controller_without_ref_P.PIDController_UpperSaturation_o;
    } else if (Controller_without_ref_B.SumI1 <
               Controller_without_ref_P.PIDController_LowerSaturation_e) {
      Controller_without_ref_B.Saturate_f =
        Controller_without_ref_P.PIDController_LowerSaturation_e;
    } else {
      Controller_without_ref_B.Saturate_f = Controller_without_ref_B.SumI1;
    }

    // End of Saturate: '<S21>/Saturate'

    // Sum: '<S21>/SumI1' incorporates:
    //   Gain: '<S21>/Kt'
    //   MATLABSystem: '<S22>/I_angular_vel_y'
    //   Product: '<S21>/IOut'
    //   Sum: '<S21>/SumI3'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Y_i -
      Controller_without_ref_B.Saturate_f) *
      Controller_without_ref_P.PIDController_Kt_j +
      Controller_without_ref_B.Errory * Controller_without_ref_B.cpsi;

    // Signum: '<S23>/SignPreIntegrator'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S23>/DataTypeConv2'
      rtb_Switch_ax = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S23>/DataTypeConv2'
      rtb_Switch_ax = 1.0;
    } else if (Controller_without_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S23>/DataTypeConv2'
      rtb_Switch_ax = 0.0;
    } else {
      // DataTypeConversion: '<S23>/DataTypeConv2'
      rtb_Switch_ax = Controller_without_ref_B.SumI1;
    }

    // End of Signum: '<S23>/SignPreIntegrator'

    // DataTypeConversion: '<S23>/DataTypeConv1'
    if (Controller_without_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_without_ref_B.SignPreIntegrator;
    } else {
      rtb_DataTypeConv2_0 = MAX_int8_T;
    }

    // End of DataTypeConversion: '<S23>/DataTypeConv1'

    // DataTypeConversion: '<S23>/DataTypeConv2'
    if (rtb_Switch_ax < 128.0) {
      tmp = (int8_T)rtb_Switch_ax;
    } else {
      tmp = MAX_int8_T;
    }

    // Switch: '<S21>/Switch' incorporates:
    //   Constant: '<S21>/Constant'
    //   Logic: '<S23>/AND'
    //   RelationalOperator: '<S23>/Equal'

    if (rtb_NotEqual && (rtb_DataTypeConv2_0 == tmp)) {
      Controller_without_ref_B.cpsi = Controller_without_ref_P.Constant_Value_m;
    } else {
      Controller_without_ref_B.cpsi = Controller_without_ref_B.SumI1;
    }

    // End of Switch: '<S21>/Switch'

    // Start for MATLABSystem: '<S25>/P_angular_vel_z' incorporates:
    //   MATLABSystem: '<S25>/P_angular_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_e.SampleTime ==
          Controller_without_ref_P.P_angular_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_e.SampleTime =
        Controller_without_ref_P.P_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_536.get_parameter
      (&Controller_without_ref_B.ctheta_c);

    // End of Start for MATLABSystem: '<S25>/P_angular_vel_z'

    // Start for MATLABSystem: '<S25>/D_angular_vel_z' incorporates:
    //   MATLABSystem: '<S25>/D_angular_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_jg.SampleTime ==
          Controller_without_ref_P.D_angular_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_jg.SampleTime =
        Controller_without_ref_P.D_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_533.get_parameter
      (&Controller_without_ref_B.stheta);

    // End of Start for MATLABSystem: '<S25>/D_angular_vel_z'

    // Start for MATLABSystem: '<S25>/N_angular_vel_z ' incorporates:
    //   MATLABSystem: '<S25>/N_angular_vel_z '

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_g.SampleTime ==
          Controller_without_ref_P.N_angular_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_g.SampleTime =
        Controller_without_ref_P.N_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_535.get_parameter
      (&Controller_without_ref_B.NOut_b);

    // End of Start for MATLABSystem: '<S25>/N_angular_vel_z '

    // Product: '<S24>/NOut' incorporates:
    //   DiscreteIntegrator: '<S24>/Filter'
    //   MATLABSystem: '<S25>/D_angular_vel_z'
    //   MATLABSystem: '<S25>/N_angular_vel_z '
    //   Product: '<S24>/DOut'
    //   Sum: '<S24>/SumD'

    Controller_without_ref_B.stheta = (Controller_without_ref_B.Errorz *
      Controller_without_ref_B.stheta -
      Controller_without_ref_DWork.Filter_DSTATE_f) *
      Controller_without_ref_B.NOut_b;

    // Sum: '<S24>/Sum' incorporates:
    //   DiscreteIntegrator: '<S24>/Integrator'
    //   MATLABSystem: '<S25>/P_angular_vel_z'
    //   Product: '<S24>/POut'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Errorz *
      Controller_without_ref_B.ctheta_c +
      Controller_without_ref_DWork.Integrator_DSTATE_a) +
      Controller_without_ref_B.stheta;

    // DeadZone: '<S26>/DeadZone'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_e) {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_UpperSaturation_e;
    } else if (Controller_without_ref_B.SumI1 >=
               Controller_without_ref_P.PIDController_LowerSaturation_p) {
      Controller_without_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_LowerSaturation_p;
    }

    // End of DeadZone: '<S26>/DeadZone'

    // RelationalOperator: '<S26>/NotEqual' incorporates:
    //   Gain: '<S26>/ZeroGain'

    rtb_NotEqual = (Controller_without_ref_P.ZeroGain_Gain_a *
                    Controller_without_ref_B.SumI1 !=
                    Controller_without_ref_B.SignPreIntegrator);

    // Signum: '<S26>/SignDeltaU'
    if (Controller_without_ref_B.SignPreIntegrator < 0.0) {
      Controller_without_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_without_ref_B.SignPreIntegrator > 0.0) {
      Controller_without_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_without_ref_B.SignPreIntegrator == 0.0) {
        Controller_without_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S26>/SignDeltaU'

    // Start for MATLABSystem: '<S25>/I_angular_vel_z' incorporates:
    //   MATLABSystem: '<S25>/I_angular_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_p.SampleTime ==
          Controller_without_ref_P.I_angular_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_p.SampleTime =
        Controller_without_ref_P.I_angular_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_534.get_parameter
      (&Controller_without_ref_B.ctheta_c);

    // End of Start for MATLABSystem: '<S25>/I_angular_vel_z'

    // Saturate: '<S24>/Saturate'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_e) {
      Controller_without_ref_B.Saturate_i =
        Controller_without_ref_P.PIDController_UpperSaturation_e;
    } else if (Controller_without_ref_B.SumI1 <
               Controller_without_ref_P.PIDController_LowerSaturation_p) {
      Controller_without_ref_B.Saturate_i =
        Controller_without_ref_P.PIDController_LowerSaturation_p;
    } else {
      Controller_without_ref_B.Saturate_i = Controller_without_ref_B.SumI1;
    }

    // End of Saturate: '<S24>/Saturate'

    // Sum: '<S24>/SumI1' incorporates:
    //   Gain: '<S24>/Kt'
    //   MATLABSystem: '<S25>/I_angular_vel_z'
    //   Product: '<S24>/IOut'
    //   Sum: '<S24>/SumI3'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Z_n -
      Controller_without_ref_B.Saturate_i) *
      Controller_without_ref_P.PIDController_Kt_p +
      Controller_without_ref_B.Errorz * Controller_without_ref_B.ctheta_c;

    // Signum: '<S26>/SignPreIntegrator'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S26>/DataTypeConv2'
      rtb_Switch_ax = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S26>/DataTypeConv2'
      rtb_Switch_ax = 1.0;
    } else if (Controller_without_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S26>/DataTypeConv2'
      rtb_Switch_ax = 0.0;
    } else {
      // DataTypeConversion: '<S26>/DataTypeConv2'
      rtb_Switch_ax = Controller_without_ref_B.SumI1;
    }

    // End of Signum: '<S26>/SignPreIntegrator'

    // DataTypeConversion: '<S26>/DataTypeConv1'
    if (Controller_without_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_without_ref_B.SignPreIntegrator;
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
      Controller_without_ref_B.ctheta_c =
        Controller_without_ref_P.Constant_Value_f;
    } else {
      Controller_without_ref_B.ctheta_c = Controller_without_ref_B.SumI1;
    }

    // End of Switch: '<S24>/Switch'

    // Start for MATLABSystem: '<S28>/P_vel_x' incorporates:
    //   MATLABSystem: '<S28>/P_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_ns.SampleTime ==
          Controller_without_ref_P.P_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_ns.SampleTime =
        Controller_without_ref_P.P_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_550.get_parameter
      (&Controller_without_ref_B.Switch_e);

    // End of Start for MATLABSystem: '<S28>/P_vel_x'

    // Start for MATLABSystem: '<S28>/D_vel_x' incorporates:
    //   MATLABSystem: '<S28>/D_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_d.SampleTime ==
          Controller_without_ref_P.D_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_d.SampleTime =
        Controller_without_ref_P.D_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_547.get_parameter
      (&Controller_without_ref_B.NOut_b);

    // End of Start for MATLABSystem: '<S28>/D_vel_x'

    // Start for MATLABSystem: '<S28>/N_vel_x ' incorporates:
    //   MATLABSystem: '<S28>/N_vel_x '

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_a3.SampleTime ==
          Controller_without_ref_P.N_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_a3.SampleTime =
        Controller_without_ref_P.N_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_549.get_parameter
      (&Controller_without_ref_B.SignPreIntegrator);

    // End of Start for MATLABSystem: '<S28>/N_vel_x '

    // Product: '<S27>/NOut' incorporates:
    //   DiscreteIntegrator: '<S27>/Filter'
    //   MATLABSystem: '<S28>/D_vel_x'
    //   MATLABSystem: '<S28>/N_vel_x '
    //   Product: '<S27>/DOut'
    //   Sum: '<S27>/SumD'

    Controller_without_ref_B.NOut_b = (Controller_without_ref_B.Errorz8 *
      Controller_without_ref_B.NOut_b -
      Controller_without_ref_DWork.Filter_DSTATE_a) *
      Controller_without_ref_B.SignPreIntegrator;

    // Sum: '<S27>/Sum' incorporates:
    //   DiscreteIntegrator: '<S27>/Integrator'
    //   MATLABSystem: '<S28>/P_vel_x'
    //   Product: '<S27>/POut'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Errorz8 *
      Controller_without_ref_B.Switch_e +
      Controller_without_ref_DWork.Integrator_DSTATE_f) +
      Controller_without_ref_B.NOut_b;

    // DeadZone: '<S29>/DeadZone'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_d) {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_UpperSaturation_d;
    } else if (Controller_without_ref_B.SumI1 >=
               Controller_without_ref_P.PIDController_LowerSaturation_i) {
      Controller_without_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_LowerSaturation_i;
    }

    // End of DeadZone: '<S29>/DeadZone'

    // RelationalOperator: '<S29>/NotEqual' incorporates:
    //   Gain: '<S29>/ZeroGain'

    rtb_NotEqual = (Controller_without_ref_P.ZeroGain_Gain_j *
                    Controller_without_ref_B.SumI1 !=
                    Controller_without_ref_B.SignPreIntegrator);

    // Signum: '<S29>/SignDeltaU'
    if (Controller_without_ref_B.SignPreIntegrator < 0.0) {
      Controller_without_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_without_ref_B.SignPreIntegrator > 0.0) {
      Controller_without_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_without_ref_B.SignPreIntegrator == 0.0) {
        Controller_without_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S29>/SignDeltaU'

    // Start for MATLABSystem: '<S28>/I_vel_x' incorporates:
    //   MATLABSystem: '<S28>/I_vel_x'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_cv.SampleTime ==
          Controller_without_ref_P.I_vel_x_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_cv.SampleTime =
        Controller_without_ref_P.I_vel_x_SampleTime;
    }

    ParamGet_Controller_without_ref_548.get_parameter
      (&Controller_without_ref_B.Switch_e);

    // End of Start for MATLABSystem: '<S28>/I_vel_x'

    // Saturate: '<S27>/Saturate'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_d) {
      Controller_without_ref_B.Saturate_b =
        Controller_without_ref_P.PIDController_UpperSaturation_d;
    } else if (Controller_without_ref_B.SumI1 <
               Controller_without_ref_P.PIDController_LowerSaturation_i) {
      Controller_without_ref_B.Saturate_b =
        Controller_without_ref_P.PIDController_LowerSaturation_i;
    } else {
      Controller_without_ref_B.Saturate_b = Controller_without_ref_B.SumI1;
    }

    // End of Saturate: '<S27>/Saturate'

    // Sum: '<S27>/SumI1' incorporates:
    //   Gain: '<S27>/Kt'
    //   MATLABSystem: '<S28>/I_vel_x'
    //   Product: '<S27>/IOut'
    //   Sum: '<S27>/SumI3'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.X -
      Controller_without_ref_B.Saturate_b) *
      Controller_without_ref_P.PIDController_Kt_jw +
      Controller_without_ref_B.Errorz8 * Controller_without_ref_B.Switch_e;

    // Signum: '<S29>/SignPreIntegrator'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S29>/DataTypeConv2'
      rtb_Switch_ax = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S29>/DataTypeConv2'
      rtb_Switch_ax = 1.0;
    } else if (Controller_without_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S29>/DataTypeConv2'
      rtb_Switch_ax = 0.0;
    } else {
      // DataTypeConversion: '<S29>/DataTypeConv2'
      rtb_Switch_ax = Controller_without_ref_B.SumI1;
    }

    // End of Signum: '<S29>/SignPreIntegrator'

    // DataTypeConversion: '<S29>/DataTypeConv1'
    if (Controller_without_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_without_ref_B.SignPreIntegrator;
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
      Controller_without_ref_B.Switch_e =
        Controller_without_ref_P.Constant_Value_m0;
    } else {
      Controller_without_ref_B.Switch_e = Controller_without_ref_B.SumI1;
    }

    // End of Switch: '<S27>/Switch'

    // Start for MATLABSystem: '<S31>/P_vel_y' incorporates:
    //   MATLABSystem: '<S31>/P_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_ji.SampleTime ==
          Controller_without_ref_P.P_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_ji.SampleTime =
        Controller_without_ref_P.P_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_564.get_parameter
      (&Controller_without_ref_B.SignPreIntegrator);

    // End of Start for MATLABSystem: '<S31>/P_vel_y'

    // Start for MATLABSystem: '<S31>/D_vel_y' incorporates:
    //   MATLABSystem: '<S31>/D_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_n.SampleTime ==
          Controller_without_ref_P.D_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_n.SampleTime =
        Controller_without_ref_P.D_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_561.get_parameter
      (&Controller_without_ref_B.NOut_i);

    // End of Start for MATLABSystem: '<S31>/D_vel_y'

    // Start for MATLABSystem: '<S31>/N_vel_y ' incorporates:
    //   MATLABSystem: '<S31>/N_vel_y '

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_c.SampleTime ==
          Controller_without_ref_P.N_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_c.SampleTime =
        Controller_without_ref_P.N_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_563.get_parameter
      (&Controller_without_ref_B.SumI1);

    // End of Start for MATLABSystem: '<S31>/N_vel_y '

    // Product: '<S30>/NOut' incorporates:
    //   DiscreteIntegrator: '<S30>/Filter'
    //   MATLABSystem: '<S31>/D_vel_y'
    //   MATLABSystem: '<S31>/N_vel_y '
    //   Product: '<S30>/DOut'
    //   Sum: '<S30>/SumD'

    Controller_without_ref_B.NOut_i = (Controller_without_ref_B.Errorz9 *
      Controller_without_ref_B.NOut_i -
      Controller_without_ref_DWork.Filter_DSTATE_g) *
      Controller_without_ref_B.SumI1;

    // Sum: '<S30>/Sum' incorporates:
    //   DiscreteIntegrator: '<S30>/Integrator'
    //   MATLABSystem: '<S31>/P_vel_y'
    //   Product: '<S30>/POut'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Errorz9 *
      Controller_without_ref_B.SignPreIntegrator +
      Controller_without_ref_DWork.Integrator_DSTATE_n) +
      Controller_without_ref_B.NOut_i;

    // DeadZone: '<S32>/DeadZone'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_b) {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_UpperSaturation_b;
    } else if (Controller_without_ref_B.SumI1 >=
               Controller_without_ref_P.PIDController_LowerSaturation_g) {
      Controller_without_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_LowerSaturation_g;
    }

    // End of DeadZone: '<S32>/DeadZone'

    // RelationalOperator: '<S32>/NotEqual' incorporates:
    //   Gain: '<S32>/ZeroGain'

    rtb_NotEqual = (Controller_without_ref_P.ZeroGain_Gain_jk *
                    Controller_without_ref_B.SumI1 !=
                    Controller_without_ref_B.SignPreIntegrator);

    // Signum: '<S32>/SignDeltaU'
    if (Controller_without_ref_B.SignPreIntegrator < 0.0) {
      Controller_without_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_without_ref_B.SignPreIntegrator > 0.0) {
      Controller_without_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_without_ref_B.SignPreIntegrator == 0.0) {
        Controller_without_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S32>/SignDeltaU'

    // Start for MATLABSystem: '<S31>/I_vel_y' incorporates:
    //   MATLABSystem: '<S31>/I_vel_y'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_jx.SampleTime ==
          Controller_without_ref_P.I_vel_y_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_jx.SampleTime =
        Controller_without_ref_P.I_vel_y_SampleTime;
    }

    ParamGet_Controller_without_ref_562.get_parameter(&rtb_Switch_ax);

    // End of Start for MATLABSystem: '<S31>/I_vel_y'

    // Saturate: '<S30>/Saturate'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturation_b) {
      Controller_without_ref_B.Saturate_h =
        Controller_without_ref_P.PIDController_UpperSaturation_b;
    } else if (Controller_without_ref_B.SumI1 <
               Controller_without_ref_P.PIDController_LowerSaturation_g) {
      Controller_without_ref_B.Saturate_h =
        Controller_without_ref_P.PIDController_LowerSaturation_g;
    } else {
      Controller_without_ref_B.Saturate_h = Controller_without_ref_B.SumI1;
    }

    // End of Saturate: '<S30>/Saturate'

    // Sum: '<S30>/SumI1' incorporates:
    //   Gain: '<S30>/Kt'
    //   MATLABSystem: '<S31>/I_vel_y'
    //   Product: '<S30>/IOut'
    //   Sum: '<S30>/SumI3'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Y -
      Controller_without_ref_B.Saturate_h) *
      Controller_without_ref_P.PIDController_Kt_c +
      Controller_without_ref_B.Errorz9 * rtb_Switch_ax;

    // Signum: '<S32>/SignPreIntegrator'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S32>/DataTypeConv2'
      rtb_Switch_ax = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S32>/DataTypeConv2'
      rtb_Switch_ax = 1.0;
    } else if (Controller_without_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S32>/DataTypeConv2'
      rtb_Switch_ax = 0.0;
    } else {
      // DataTypeConversion: '<S32>/DataTypeConv2'
      rtb_Switch_ax = Controller_without_ref_B.SumI1;
    }

    // End of Signum: '<S32>/SignPreIntegrator'

    // DataTypeConversion: '<S32>/DataTypeConv1'
    if (Controller_without_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_without_ref_B.SignPreIntegrator;
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
      rtb_Switch_ax = Controller_without_ref_P.Constant_Value_p;
    } else {
      rtb_Switch_ax = Controller_without_ref_B.SumI1;
    }

    // End of Switch: '<S30>/Switch'

    // Start for MATLABSystem: '<S34>/P_vel_z' incorporates:
    //   MATLABSystem: '<S34>/P_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj.SampleTime ==
          Controller_without_ref_P.P_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj.SampleTime =
        Controller_without_ref_P.P_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_578.get_parameter
      (&Controller_without_ref_B.SignPreIntegrator);

    // End of Start for MATLABSystem: '<S34>/P_vel_z'

    // Start for MATLABSystem: '<S34>/D_vel_z' incorporates:
    //   MATLABSystem: '<S34>/D_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_a.SampleTime ==
          Controller_without_ref_P.D_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_a.SampleTime =
        Controller_without_ref_P.D_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_575.get_parameter
      (&Controller_without_ref_B.SumI1);

    // End of Start for MATLABSystem: '<S34>/D_vel_z'

    // Start for MATLABSystem: '<S34>/N_vel_z ' incorporates:
    //   MATLABSystem: '<S34>/N_vel_z '

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_h.SampleTime ==
          Controller_without_ref_P.N_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_h.SampleTime =
        Controller_without_ref_P.N_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_577.get_parameter
      (&Controller_without_ref_B.NOut_d);

    // End of Start for MATLABSystem: '<S34>/N_vel_z '

    // Product: '<S33>/NOut' incorporates:
    //   DiscreteIntegrator: '<S33>/Filter'
    //   MATLABSystem: '<S34>/D_vel_z'
    //   MATLABSystem: '<S34>/N_vel_z '
    //   Product: '<S33>/DOut'
    //   Sum: '<S33>/SumD'

    Controller_without_ref_B.NOut_d *= Controller_without_ref_B.Errorz10 *
      Controller_without_ref_B.SumI1 -
      Controller_without_ref_DWork.Filter_DSTATE_cw;

    // Sum: '<S33>/Sum' incorporates:
    //   DiscreteIntegrator: '<S33>/Integrator'
    //   MATLABSystem: '<S34>/P_vel_z'
    //   Product: '<S33>/POut'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Errorz10 *
      Controller_without_ref_B.SignPreIntegrator +
      Controller_without_ref_DWork.Integrator_DSTATE_ny) +
      Controller_without_ref_B.NOut_d;

    // DeadZone: '<S35>/DeadZone'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturatio_ba) {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_UpperSaturatio_ba;
    } else if (Controller_without_ref_B.SumI1 >=
               Controller_without_ref_P.PIDController_LowerSaturatio_pm) {
      Controller_without_ref_B.SignPreIntegrator = 0.0;
    } else {
      Controller_without_ref_B.SignPreIntegrator =
        Controller_without_ref_B.SumI1 -
        Controller_without_ref_P.PIDController_LowerSaturatio_pm;
    }

    // End of DeadZone: '<S35>/DeadZone'

    // RelationalOperator: '<S35>/NotEqual' incorporates:
    //   Gain: '<S35>/ZeroGain'

    rtb_NotEqual = (Controller_without_ref_P.ZeroGain_Gain_p *
                    Controller_without_ref_B.SumI1 !=
                    Controller_without_ref_B.SignPreIntegrator);

    // Signum: '<S35>/SignDeltaU'
    if (Controller_without_ref_B.SignPreIntegrator < 0.0) {
      Controller_without_ref_B.SignPreIntegrator = -1.0;
    } else if (Controller_without_ref_B.SignPreIntegrator > 0.0) {
      Controller_without_ref_B.SignPreIntegrator = 1.0;
    } else {
      if (Controller_without_ref_B.SignPreIntegrator == 0.0) {
        Controller_without_ref_B.SignPreIntegrator = 0.0;
      }
    }

    // End of Signum: '<S35>/SignDeltaU'

    // Start for MATLABSystem: '<S34>/I_vel_z' incorporates:
    //   MATLABSystem: '<S34>/I_vel_z'

    p = false;
    p_0 = true;
    if (!(Controller_without_ref_DWork.obj_j.SampleTime ==
          Controller_without_ref_P.I_vel_z_SampleTime)) {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Controller_without_ref_DWork.obj_j.SampleTime =
        Controller_without_ref_P.I_vel_z_SampleTime;
    }

    ParamGet_Controller_without_ref_576.get_parameter
      (&Controller_without_ref_B.rtb_I_vel_z_k);

    // End of Start for MATLABSystem: '<S34>/I_vel_z'

    // Saturate: '<S33>/Saturate'
    if (Controller_without_ref_B.SumI1 >
        Controller_without_ref_P.PIDController_UpperSaturatio_ba) {
      Controller_without_ref_B.Saturate_bk =
        Controller_without_ref_P.PIDController_UpperSaturatio_ba;
    } else if (Controller_without_ref_B.SumI1 <
               Controller_without_ref_P.PIDController_LowerSaturatio_pm) {
      Controller_without_ref_B.Saturate_bk =
        Controller_without_ref_P.PIDController_LowerSaturatio_pm;
    } else {
      Controller_without_ref_B.Saturate_bk = Controller_without_ref_B.SumI1;
    }

    // End of Saturate: '<S33>/Saturate'

    // Sum: '<S33>/SumI1' incorporates:
    //   Gain: '<S33>/Kt'
    //   MATLABSystem: '<S34>/I_vel_z'
    //   Product: '<S33>/IOut'
    //   Sum: '<S33>/SumI3'

    Controller_without_ref_B.SumI1 = (Controller_without_ref_B.Z -
      Controller_without_ref_B.Saturate_bk) *
      Controller_without_ref_P.PIDController_Kt_l +
      Controller_without_ref_B.Errorz10 * Controller_without_ref_B.rtb_I_vel_z_k;

    // Update for DiscreteIntegrator: '<S18>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE +=
      Controller_without_ref_P.Integrator_gainval * Controller_without_ref_B.cfi;

    // Update for DiscreteIntegrator: '<S18>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE +=
      Controller_without_ref_P.Filter_gainval * Controller_without_ref_B.sfi;

    // Update for DiscreteIntegrator: '<S21>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_h +=
      Controller_without_ref_P.Integrator_gainval_c *
      Controller_without_ref_B.cpsi;

    // Update for DiscreteIntegrator: '<S21>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_c +=
      Controller_without_ref_P.Filter_gainval_i * Controller_without_ref_B.spsi;

    // Update for DiscreteIntegrator: '<S24>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_a +=
      Controller_without_ref_P.Integrator_gainval_n *
      Controller_without_ref_B.ctheta_c;

    // Update for DiscreteIntegrator: '<S24>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_f +=
      Controller_without_ref_P.Filter_gainval_k *
      Controller_without_ref_B.stheta;

    // Update for DiscreteIntegrator: '<S27>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_f +=
      Controller_without_ref_P.Integrator_gainval_j *
      Controller_without_ref_B.Switch_e;

    // Update for DiscreteIntegrator: '<S27>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_a +=
      Controller_without_ref_P.Filter_gainval_h *
      Controller_without_ref_B.NOut_b;

    // Update for DiscreteIntegrator: '<S30>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_n +=
      Controller_without_ref_P.Integrator_gainval_np * rtb_Switch_ax;

    // Update for DiscreteIntegrator: '<S30>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_g +=
      Controller_without_ref_P.Filter_gainval_h0 *
      Controller_without_ref_B.NOut_i;

    // Signum: '<S35>/SignPreIntegrator'
    if (Controller_without_ref_B.SumI1 < 0.0) {
      // DataTypeConversion: '<S35>/DataTypeConv2'
      rtb_Switch_ax = -1.0;
    } else if (Controller_without_ref_B.SumI1 > 0.0) {
      // DataTypeConversion: '<S35>/DataTypeConv2'
      rtb_Switch_ax = 1.0;
    } else if (Controller_without_ref_B.SumI1 == 0.0) {
      // DataTypeConversion: '<S35>/DataTypeConv2'
      rtb_Switch_ax = 0.0;
    } else {
      // DataTypeConversion: '<S35>/DataTypeConv2'
      rtb_Switch_ax = Controller_without_ref_B.SumI1;
    }

    // End of Signum: '<S35>/SignPreIntegrator'

    // DataTypeConversion: '<S35>/DataTypeConv1'
    if (Controller_without_ref_B.SignPreIntegrator < 128.0) {
      rtb_DataTypeConv2_0 = (int8_T)Controller_without_ref_B.SignPreIntegrator;
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
      Controller_without_ref_B.SumI1 = Controller_without_ref_P.Constant_Value_l;
    }

    // End of Switch: '<S33>/Switch'

    // Update for DiscreteIntegrator: '<S33>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_ny +=
      Controller_without_ref_P.Integrator_gainval_m *
      Controller_without_ref_B.SumI1;

    // Update for DiscreteIntegrator: '<S33>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_cw +=
      Controller_without_ref_P.Filter_gainval_b *
      Controller_without_ref_B.NOut_d;
  }

  // End of Outputs for SubSystem: '<Root>/Create errors'
  // End of Outputs for SubSystem: '<Root>/decController'

  // MultiPortSwitch: '<Root>/Choose Controller signal' incorporates:
  //   Constant: '<Root>/Constant4'
  //   MATLABSystem: '<Root>/Get controller type'

  switch (i) {
   case 0:
    Controller_without_ref_B.ChooseControllersignal[0] =
      Controller_without_ref_B.X_h;
    Controller_without_ref_B.ChooseControllersignal[1] =
      Controller_without_ref_B.Y_i;
    Controller_without_ref_B.ChooseControllersignal[2] =
      Controller_without_ref_B.Z_n;
    Controller_without_ref_B.ChooseControllersignal[3] =
      Controller_without_ref_B.X;
    Controller_without_ref_B.ChooseControllersignal[4] =
      Controller_without_ref_B.Y;
    Controller_without_ref_B.ChooseControllersignal[5] =
      Controller_without_ref_B.Z;
    break;

   case 1:
    Controller_without_ref_B.ChooseControllersignal[0] =
      Controller_without_ref_B.Saturate;
    Controller_without_ref_B.ChooseControllersignal[1] =
      Controller_without_ref_B.Saturate_f;
    Controller_without_ref_B.ChooseControllersignal[2] =
      Controller_without_ref_B.Saturate_i;
    Controller_without_ref_B.ChooseControllersignal[3] =
      Controller_without_ref_B.Saturate_b;
    Controller_without_ref_B.ChooseControllersignal[4] =
      Controller_without_ref_B.Saturate_h;
    Controller_without_ref_B.ChooseControllersignal[5] =
      Controller_without_ref_B.Saturate_bk;
    break;

   default:
    for (i = 0; i < 6; i++) {
      Controller_without_ref_B.ChooseControllersignal[i] =
        Controller_without_ref_P.Constant4_Value;
    }
    break;
  }

  // End of MultiPortSwitch: '<Root>/Choose Controller signal'

  // Start for MATLABSystem: '<S2>/Get front strafe decouple' incorporates:
  //   MATLABSystem: '<S2>/Get front strafe decouple'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_jl.SampleTime ==
        Controller_without_ref_P.Getfrontstrafedecouple_SampleTi)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_jl.SampleTime =
      Controller_without_ref_P.Getfrontstrafedecouple_SampleTi;
  }

  ParamGet_Controller_without_ref_465.get_parameter
    (&Controller_without_ref_B.sfi);

  // Start for MATLABSystem: '<S2>/Get front forward decouple' incorporates:
  //   MATLABSystem: '<S2>/Get front forward decouple'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_ec.SampleTime ==
        Controller_without_ref_P.Getfrontforwarddecouple_SampleT)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_ec.SampleTime =
      Controller_without_ref_P.Getfrontforwarddecouple_SampleT;
  }

  ParamGet_Controller_without_ref_463.get_parameter
    (&Controller_without_ref_B.cfi);

  // Start for MATLABSystem: '<S2>/Get front pitch bias' incorporates:
  //   MATLABSystem: '<S2>/Get front pitch bias'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_nj.SampleTime ==
        Controller_without_ref_P.Getfrontpitchbias_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_nj.SampleTime =
      Controller_without_ref_P.Getfrontpitchbias_SampleTime;
  }

  ParamGet_Controller_without_ref_464.get_parameter
    (&Controller_without_ref_B.spsi);

  // Start for MATLABSystem: '<S2>/Get front vertical bias' incorporates:
  //   MATLABSystem: '<S2>/Get front vertical bias'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_lo.SampleTime ==
        Controller_without_ref_P.Getfrontverticalbias_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_lo.SampleTime =
      Controller_without_ref_P.Getfrontverticalbias_SampleTime;
  }

  ParamGet_Controller_without_ref_466.get_parameter
    (&Controller_without_ref_B.cpsi);

  // Start for MATLABSystem: '<S2>/Get buoyancy' incorporates:
  //   MATLABSystem: '<S2>/Get buoyancy'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_ef.SampleTime ==
        Controller_without_ref_P.Getbuoyancy_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_ef.SampleTime =
      Controller_without_ref_P.Getbuoyancy_SampleTime;
  }

  ParamGet_Controller_without_ref_462.get_parameter
    (&Controller_without_ref_B.stheta);

  // Outputs for Enabled SubSystem: '<Root>/toPWM' incorporates:
  //   EnablePort: '<S9>/Enable'

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
    // MATLAB Function: '<S9>/PWM assign' incorporates:
    //   Constant: '<S38>/Constant'

    // MATLAB Function 'toPWM/Calc pwm signal': '<S39>:1'
    //  thruster values should be between 1100 and 1900 microseconds (us)
    //  values less than 1500 us are backwards; values more than are forwards
    // '<S39>:1:5'
    Controller_without_ref_B.msg = Controller_without_ref_P.Constant_Value_i;

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

    // MATLAB Function 'toPWM/PWM assign': '<S40>:1'
    // '<S40>:1:4'
    Controller_without_ref_B.ctheta_c =
      ((((Controller_without_ref_B.ChooseControllersignal[0] -
          Controller_without_ref_B.cfi *
          Controller_without_ref_B.ChooseControllersignal[3]) -
         Controller_without_ref_B.sfi *
         Controller_without_ref_B.ChooseControllersignal[4]) -
        Controller_without_ref_B.spsi *
        Controller_without_ref_B.ChooseControllersignal[1]) +
       Controller_without_ref_B.cpsi *
       Controller_without_ref_B.ChooseControllersignal[5]) +
      Controller_without_ref_B.stheta;

    // Saturate: '<S9>/Saturation'
    if (Controller_without_ref_B.ctheta_c >
        Controller_without_ref_P.Saturation_UpperSat) {
      Controller_without_ref_B.ctheta_c =
        Controller_without_ref_P.Saturation_UpperSat;
    } else {
      if (Controller_without_ref_B.ctheta_c <
          Controller_without_ref_P.Saturation_LowerSat) {
        Controller_without_ref_B.ctheta_c =
          Controller_without_ref_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S9>/Calc pwm signal'
    //   Saturate: '<S9>/Saturation'

    rtb_Switch_ax = floor((Controller_without_ref_B.ctheta_c + 1.0) * 400.0 +
                          1100.0);
    if (rtIsNaN(rtb_Switch_ax) || rtIsInf(rtb_Switch_ax)) {
      rtb_Switch_ax = 0.0;
    } else {
      rtb_Switch_ax = fmod(rtb_Switch_ax, 65536.0);
    }

    // MATLAB Function: '<S9>/PWM assign' incorporates:
    //   DataTypeConversion: '<S9>/Data Type Conversion'

    Controller_without_ref_B.msg.Data[0] = (uint16_T)(rtb_Switch_ax < 0.0 ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Switch_ax : (int32_T)(uint16_T)
      rtb_Switch_ax);

    // MATLAB Function: '<S2>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S2>/Get buoyancy'
    //   Start for MATLABSystem: '<S2>/Get buoyancy'
    //   MATLABSystem: '<S2>/Get front forward decouple'
    //   Start for MATLABSystem: '<S2>/Get front forward decouple'

    Controller_without_ref_B.ctheta_c = ((Controller_without_ref_B.cfi *
      Controller_without_ref_B.ChooseControllersignal[3] +
      Controller_without_ref_B.ChooseControllersignal[1]) +
      Controller_without_ref_B.ChooseControllersignal[5]) +
      Controller_without_ref_B.stheta;

    // Saturate: '<S9>/Saturation'
    if (Controller_without_ref_B.ctheta_c >
        Controller_without_ref_P.Saturation_UpperSat) {
      Controller_without_ref_B.ctheta_c =
        Controller_without_ref_P.Saturation_UpperSat;
    } else {
      if (Controller_without_ref_B.ctheta_c <
          Controller_without_ref_P.Saturation_LowerSat) {
        Controller_without_ref_B.ctheta_c =
          Controller_without_ref_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S9>/Calc pwm signal'
    //   Saturate: '<S9>/Saturation'

    rtb_Switch_ax = floor((Controller_without_ref_B.ctheta_c + 1.0) * 400.0 +
                          1100.0);
    if (rtIsNaN(rtb_Switch_ax) || rtIsInf(rtb_Switch_ax)) {
      rtb_Switch_ax = 0.0;
    } else {
      rtb_Switch_ax = fmod(rtb_Switch_ax, 65536.0);
    }

    // MATLAB Function: '<S9>/PWM assign' incorporates:
    //   DataTypeConversion: '<S9>/Data Type Conversion'

    Controller_without_ref_B.msg.Data[1] = (uint16_T)(rtb_Switch_ax < 0.0 ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Switch_ax : (int32_T)(uint16_T)
      rtb_Switch_ax);

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

    Controller_without_ref_B.ctheta_c =
      ((((-Controller_without_ref_B.ChooseControllersignal[0] -
          Controller_without_ref_B.cfi *
          Controller_without_ref_B.ChooseControllersignal[3]) +
         Controller_without_ref_B.sfi *
         Controller_without_ref_B.ChooseControllersignal[4]) -
        Controller_without_ref_B.spsi *
        Controller_without_ref_B.ChooseControllersignal[1]) +
       Controller_without_ref_B.cpsi *
       Controller_without_ref_B.ChooseControllersignal[5]) +
      Controller_without_ref_B.stheta;

    // Saturate: '<S9>/Saturation'
    if (Controller_without_ref_B.ctheta_c >
        Controller_without_ref_P.Saturation_UpperSat) {
      Controller_without_ref_B.ctheta_c =
        Controller_without_ref_P.Saturation_UpperSat;
    } else {
      if (Controller_without_ref_B.ctheta_c <
          Controller_without_ref_P.Saturation_LowerSat) {
        Controller_without_ref_B.ctheta_c =
          Controller_without_ref_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S9>/Calc pwm signal'
    //   Saturate: '<S9>/Saturation'

    rtb_Switch_ax = floor((Controller_without_ref_B.ctheta_c + 1.0) * 400.0 +
                          1100.0);
    if (rtIsNaN(rtb_Switch_ax) || rtIsInf(rtb_Switch_ax)) {
      rtb_Switch_ax = 0.0;
    } else {
      rtb_Switch_ax = fmod(rtb_Switch_ax, 65536.0);
    }

    // MATLAB Function: '<S9>/PWM assign' incorporates:
    //   DataTypeConversion: '<S9>/Data Type Conversion'

    Controller_without_ref_B.msg.Data[2] = (uint16_T)(rtb_Switch_ax < 0.0 ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Switch_ax : (int32_T)(uint16_T)
      rtb_Switch_ax);

    // MATLAB Function: '<S2>/MATLAB Function'
    Controller_without_ref_B.ctheta_c =
      -Controller_without_ref_B.ChooseControllersignal[2] +
      Controller_without_ref_B.ChooseControllersignal[3];

    // Saturate: '<S9>/Saturation'
    if (Controller_without_ref_B.ctheta_c >
        Controller_without_ref_P.Saturation_UpperSat) {
      Controller_without_ref_B.ctheta_c =
        Controller_without_ref_P.Saturation_UpperSat;
    } else {
      if (Controller_without_ref_B.ctheta_c <
          Controller_without_ref_P.Saturation_LowerSat) {
        Controller_without_ref_B.ctheta_c =
          Controller_without_ref_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S9>/Calc pwm signal'
    //   Saturate: '<S9>/Saturation'

    rtb_Switch_ax = floor((Controller_without_ref_B.ctheta_c + 1.0) * 400.0 +
                          1100.0);
    if (rtIsNaN(rtb_Switch_ax) || rtIsInf(rtb_Switch_ax)) {
      rtb_Switch_ax = 0.0;
    } else {
      rtb_Switch_ax = fmod(rtb_Switch_ax, 65536.0);
    }

    // MATLAB Function: '<S9>/PWM assign' incorporates:
    //   DataTypeConversion: '<S9>/Data Type Conversion'

    Controller_without_ref_B.msg.Data[3] = (uint16_T)(rtb_Switch_ax < 0.0 ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Switch_ax : (int32_T)(uint16_T)
      rtb_Switch_ax);

    // Saturate: '<S9>/Saturation' incorporates:
    //   MATLAB Function: '<S2>/MATLAB Function'

    if (Controller_without_ref_B.ChooseControllersignal[4] >
        Controller_without_ref_P.Saturation_UpperSat) {
      Controller_without_ref_B.sfi =
        Controller_without_ref_P.Saturation_UpperSat;
    } else if (Controller_without_ref_B.ChooseControllersignal[4] <
               Controller_without_ref_P.Saturation_LowerSat) {
      Controller_without_ref_B.sfi =
        Controller_without_ref_P.Saturation_LowerSat;
    } else {
      Controller_without_ref_B.sfi =
        Controller_without_ref_B.ChooseControllersignal[4];
    }

    // DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S9>/Calc pwm signal'
    //   Saturate: '<S9>/Saturation'

    rtb_Switch_ax = floor((Controller_without_ref_B.sfi + 1.0) * 400.0 + 1100.0);
    if (rtIsNaN(rtb_Switch_ax) || rtIsInf(rtb_Switch_ax)) {
      rtb_Switch_ax = 0.0;
    } else {
      rtb_Switch_ax = fmod(rtb_Switch_ax, 65536.0);
    }

    // MATLAB Function: '<S9>/PWM assign' incorporates:
    //   DataTypeConversion: '<S9>/Data Type Conversion'

    Controller_without_ref_B.msg.Data[4] = (uint16_T)(rtb_Switch_ax < 0.0 ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Switch_ax : (int32_T)(uint16_T)
      rtb_Switch_ax);

    // MATLAB Function: '<S2>/MATLAB Function'
    Controller_without_ref_B.ctheta_c =
      Controller_without_ref_B.ChooseControllersignal[2] +
      Controller_without_ref_B.ChooseControllersignal[3];

    // Saturate: '<S9>/Saturation'
    if (Controller_without_ref_B.ctheta_c >
        Controller_without_ref_P.Saturation_UpperSat) {
      Controller_without_ref_B.ctheta_c =
        Controller_without_ref_P.Saturation_UpperSat;
    } else {
      if (Controller_without_ref_B.ctheta_c <
          Controller_without_ref_P.Saturation_LowerSat) {
        Controller_without_ref_B.ctheta_c =
          Controller_without_ref_P.Saturation_LowerSat;
      }
    }

    // DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
    //   MATLAB Function: '<S9>/Calc pwm signal'
    //   Saturate: '<S9>/Saturation'

    rtb_Switch_ax = floor((Controller_without_ref_B.ctheta_c + 1.0) * 400.0 +
                          1100.0);
    if (rtIsNaN(rtb_Switch_ax) || rtIsInf(rtb_Switch_ax)) {
      rtb_Switch_ax = 0.0;
    } else {
      rtb_Switch_ax = fmod(rtb_Switch_ax, 65536.0);
    }

    // MATLAB Function: '<S9>/PWM assign' incorporates:
    //   DataTypeConversion: '<S9>/Data Type Conversion'

    Controller_without_ref_B.msg.Data[5] = (uint16_T)(rtb_Switch_ax < 0.0 ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Switch_ax : (int32_T)(uint16_T)
      rtb_Switch_ax);

    // '<S40>:1:5'
    Controller_without_ref_B.msg.Layout.DataOffset = 0U;

    // '<S40>:1:6'
    Controller_without_ref_B.msg.Layout.Dim[0].Stride = 1U;

    // '<S40>:1:7'
    Controller_without_ref_B.msg.Layout.Dim[0].Size = 6U;

    // '<S40>:1:8'
    Controller_without_ref_B.msg.Data_SL_Info.CurrentLength = 6U;

    // Outputs for Atomic SubSystem: '<S9>/Publish'
    // MATLABSystem: '<S41>/SinkBlock'
    // '<S40>:1:9'
    Pub_Controller_without_ref_607.publish(&Controller_without_ref_B.msg);

    // End of Outputs for SubSystem: '<S9>/Publish'
  }

  // End of Outputs for SubSystem: '<Root>/toPWM'

  // Start for MATLABSystem: '<S4>/Get alpha' incorporates:
  //   MATLABSystem: '<S4>/Get alpha'

  p = false;
  p_0 = true;
  if (!(Controller_without_ref_DWork.obj_hx.SampleTime ==
        Controller_without_ref_P.Getalpha_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    Controller_without_ref_DWork.obj_hx.SampleTime =
      Controller_without_ref_P.Getalpha_SampleTime;
  }

  ParamGet_Controller_without_ref_687.get_parameter
    (&Controller_without_ref_B.sfi);

  // End of Start for MATLABSystem: '<S4>/Get alpha'

  // SignalConversion: '<S4>/TmpSignal ConversionAtDiscrete FilterInport2' incorporates:
  //   Constant: '<S4>/Constant'
  //   MATLABSystem: '<S4>/Get alpha'

  Controller_without_ref_B.TmpSignalConversionAtDiscreteFi[0] =
    Controller_without_ref_P.Constant_Value_a;
  Controller_without_ref_B.TmpSignalConversionAtDiscreteFi[1] =
    Controller_without_ref_B.sfi;

  // DiscreteFilter: '<S4>/Discrete Filter'
  Controller_without_ref_B.sfi = Controller_without_ref_P.DiscreteFilter_NumCoef
    * Controller_without_ref_B.OutportBufferForaccXms2 -
    Controller_without_ref_B.TmpSignalConversionAtDiscreteFi[1] *
    Controller_without_ref_DWork.DiscreteFilter_denStates;
  Controller_without_ref_DWork.DiscreteFilter_tmp = Controller_without_ref_B.sfi;

  // DiscreteFilter: '<S4>/Discrete Filter1'
  Controller_without_ref_B.cfi =
    Controller_without_ref_P.DiscreteFilter1_NumCoef *
    Controller_without_ref_B.OutportBufferForaccYms2 -
    Controller_without_ref_B.TmpSignalConversionAtDiscreteFi[1] *
    Controller_without_ref_DWork.DiscreteFilter1_denStates;
  Controller_without_ref_DWork.DiscreteFilter1_tmp =
    Controller_without_ref_B.cfi;

  // DiscreteFilter: '<S4>/Discrete Filter2'
  Controller_without_ref_B.spsi =
    Controller_without_ref_P.DiscreteFilter2_NumCoef *
    Controller_without_ref_B.OutportBufferForaccZms2 -
    Controller_without_ref_B.TmpSignalConversionAtDiscreteFi[1] *
    Controller_without_ref_DWork.DiscreteFilter2_denStates;
  Controller_without_ref_DWork.DiscreteFilter2_tmp =
    Controller_without_ref_B.spsi;

  // Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  Controller_without_ref_DWork.DiscreteTimeIntegrator_DSTATE +=
    Controller_without_ref_P.DiscreteTimeIntegrator_gainval *
    Controller_without_ref_B.sfi;

  // Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
  Controller_without_ref_DWork.DiscreteTimeIntegrator1_DSTATE +=
    Controller_without_ref_P.DiscreteTimeIntegrator1_gainval *
    Controller_without_ref_B.cfi;

  // Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator2'
  Controller_without_ref_DWork.DiscreteTimeIntegrator2_DSTATE +=
    Controller_without_ref_P.DiscreteTimeIntegrator2_gainval *
    Controller_without_ref_B.spsi;

  // Update for DiscreteFilter: '<S4>/Discrete Filter'
  Controller_without_ref_DWork.DiscreteFilter_denStates =
    Controller_without_ref_DWork.DiscreteFilter_tmp;

  // Update for DiscreteFilter: '<S4>/Discrete Filter1'
  Controller_without_ref_DWork.DiscreteFilter1_denStates =
    Controller_without_ref_DWork.DiscreteFilter1_tmp;

  // Update for DiscreteFilter: '<S4>/Discrete Filter2'
  Controller_without_ref_DWork.DiscreteFilter2_denStates =
    Controller_without_ref_DWork.DiscreteFilter2_tmp;
}

// Model initialize function
void ControllerModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus((&Controller_without_ref_M), (NULL));

  // block I/O
  (void) memset(((void *) &Controller_without_ref_B), 0,
                sizeof(BlockIO_Controller_without_re_T));

  // states (dwork)
  (void) memset((void *)&Controller_without_ref_DWork, 0,
                sizeof(D_Work_Controller_without_ref_T));

  {
    static const char_T tmp[24] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_', 'c',
      'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'a', 'l', 'p', 'h', 'a'
    };

    static const char_T tmp_0[16] = { '/', 'r', 'o', 'v', 'i', 'o', '/', 't',
      'h', 'r', 'u', 's', 't', 'e', 'r', 's' };

    static const char_T tmp_1[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'b', 'u', 'o', 'y',
      'a', 'n', 'c', 'y', '_', 'c', 'o', 'n', 't', 'r', 'o', 'l' };

    static const char_T tmp_2[38] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'f', 'r', 'o', 'n',
      't', '_', 'v', 'e', 'r', 't', 'i', 'c', 'a', 'l', '_', 'b', 'i', 'a', 's'
    };

    static const char_T tmp_3[35] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'f', 'r', 'o', 'n',
      't', '_', 'p', 'i', 't', 'c', 'h', '_', 'b', 'i', 'a', 's' };

    static const char_T tmp_4[41] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'f', 'r', 'o', 'n',
      't', '_', 'f', 'o', 'r', 'w', 'a', 'r', 'd', '_', 'd', 'e', 'c', 'o', 'u',
      'p', 'l', 'e' };

    static const char_T tmp_5[40] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'f', 'r', 'o', 'n',
      't', '_', 's', 't', 'r', 'a', 'f', 'e', '_', 'd', 'e', 'c', 'o', 'u', 'p',
      'l', 'e' };

    static const char_T tmp_6[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_7[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_8[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_9[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'z' };

    static const char_T tmp_a[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_b[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_c[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_d[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'y' };

    static const char_T tmp_e[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_f[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_g[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_h[26] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'v', 'e',
      'l', '_', 'x' };

    static const char_T tmp_i[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_j[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_k[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_l[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'z' };

    static const char_T tmp_m[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_n[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_o[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_p[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'y' };

    static const char_T tmp_q[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'I', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_r[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'N', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_s[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'D', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_t[34] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'P', '_', 'a', 'n',
      'g', 'u', 'l', 'a', 'r', '_', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_u[37] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'e', 'n', 'a', 'b',
      'l', 'e', '_', 'i', 'n', 't', 'e', 'g', 'r', 'a', 't', 'i', 'o', 'n' };

    static const char_T tmp_v[21] = { '/', 's', 'e', 'n', 's', 'o', 'r', '_',
      'f', 'u', 's', 'i', 'o', 'n', '/', 's', 't', 'a', 't', 'e', 's' };

    static const char_T tmp_w[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_x[29] = { '/', 'm', 'a', 't', 'l', 'a', 'b', '_',
      'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r', '/', 'c', 'o', 'n', 't',
      'r', 'o', 'l', 'l', 'e', 'r' };

    char_T tmp_y[17];
    char_T tmp_z[22];
    char_T tmp_10[9];
    int32_T i;

    // Start for MATLABSystem: '<Root>/Get controller type'
    Controller_without_ref_DWork.obj_nl.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_m0 = true;
    Controller_without_ref_DWork.obj_nl.SampleTime =
      Controller_without_ref_P.Getcontrollertype_SampleTime;
    Controller_without_ref_DWork.obj_nl.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      Controller_without_ref_B.cv6[i] = tmp_x[i];
    }

    Controller_without_ref_B.cv6[29] = '\x00';
    ParamGet_Controller_without_ref_106.initialize(Controller_without_ref_B.cv6,
      Controlle_ParameterInitialValue, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<Root>/Get controller type'

    // Start for Atomic SubSystem: '<Root>/cmd_vel'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    Controller_without_ref_DWork.obj_nf.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_gn = true;
    Controller_without_ref_DWork.obj_nf.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_10[i] = tmp_w[i];
    }

    tmp_10[8] = '\x00';
    Sub_Controller_without_ref_1.create_subscriber(tmp_10,
      Controller_with_MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SourceBlock'

    // Start for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S11>/Out1'
    Controller_without_ref_B.In1_m = Controller_without_ref_P.Out1_Y0_f;

    // End of Start for SubSystem: '<S5>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/cmd_vel'

    // Start for Atomic SubSystem: '<Root>/imu_data'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    Controller_without_ref_DWork.obj_k.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_i = true;
    Controller_without_ref_DWork.obj_k.isInitialized = 1;
    for (i = 0; i < 21; i++) {
      tmp_z[i] = tmp_v[i];
    }

    tmp_z[21] = '\x00';
    Sub_Controller_without_ref_28.create_subscriber(tmp_z,
      Controller_with_MessageQueueLen);

    // End of Start for MATLABSystem: '<S7>/SourceBlock'

    // Start for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S36>/Out1'
    Controller_without_ref_B.In1 = Controller_without_ref_P.Out1_Y0;

    // End of Start for SubSystem: '<S7>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/imu_data'

    // Start for Enabled SubSystem: '<Root>/Xbox_input'
    // VirtualOutportStart for Outport: '<S3>/<angular_vel X>'
    Controller_without_ref_B.X_h = Controller_without_ref_P.angular_velX_Y0;

    // VirtualOutportStart for Outport: '<S3>/<angular_vel Y>'
    Controller_without_ref_B.Y_i = Controller_without_ref_P.angular_velY_Y0;

    // VirtualOutportStart for Outport: '<S3>/<angular_vel Z> '
    Controller_without_ref_B.Z_n = Controller_without_ref_P.angular_velZ_Y0;

    // VirtualOutportStart for Outport: '<S3>/<velocity X>'
    Controller_without_ref_B.X = Controller_without_ref_P.velocityX_Y0;

    // VirtualOutportStart for Outport: '<S3>/<veloctiy Y>'
    Controller_without_ref_B.Y = Controller_without_ref_P.veloctiyY_Y0;

    // VirtualOutportStart for Outport: '<S3>/<velocity Z>'
    Controller_without_ref_B.Z = Controller_without_ref_P.velocityZ_Y0;

    // End of Start for SubSystem: '<Root>/Xbox_input'

    // Start for Enabled SubSystem: '<Root>/states'
    // VirtualOutportStart for Outport: '<S8>/<angular_vel X [degrees//s]>'
    Controller_without_ref_B.Gain =
      Controller_without_ref_P.angular_velXdegreess_Y0;

    // VirtualOutportStart for Outport: '<S8>/<angular_vel Y [degrees//s]>'
    Controller_without_ref_B.Gain1 =
      Controller_without_ref_P.angular_velYdegreess_Y0;

    // VirtualOutportStart for Outport: '<S8>/<angular_vel Z [degrees//s]>'
    Controller_without_ref_B.Gain2 =
      Controller_without_ref_P.angular_velZdegreess_Y0;

    // VirtualOutportStart for Outport: '<S8>/<acc X [m//s^2]>'
    Controller_without_ref_B.OutportBufferForaccXms2 =
      Controller_without_ref_P.accXms2_Y0;

    // VirtualOutportStart for Outport: '<S8>/<acc Y [m//s^2]>'
    Controller_without_ref_B.OutportBufferForaccYms2 =
      Controller_without_ref_P.accYms2_Y0;

    // VirtualOutportStart for Outport: '<S8>/<acc Z [m//s^2]>'
    Controller_without_ref_B.OutportBufferForaccZms2 =
      Controller_without_ref_P.accZms2_Y0;

    // End of Start for SubSystem: '<Root>/states'

    // Start for MATLABSystem: '<S4>/Enable integration?'
    Controller_without_ref_DWork.obj_g0.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_lj = true;
    Controller_without_ref_DWork.obj_g0.SampleTime =
      Controller_without_ref_P.Enableintegration_SampleTime;
    Controller_without_ref_DWork.obj_g0.isInitialized = 1;
    for (i = 0; i < 37; i++) {
      Controller_without_ref_B.cv3[i] = tmp_u[i];
    }

    Controller_without_ref_B.cv3[37] = '\x00';
    ParamGet_Controller_without_ref_686.initialize(Controller_without_ref_B.cv3,
      Contro_ParameterInitialValue_oe, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S4>/Enable integration?'

    // Start for Enabled SubSystem: '<Root>/Create errors'
    // VirtualOutportStart for Outport: '<S1>/angular_vel x error [degrees]'
    Controller_without_ref_B.Errorx =
      Controller_without_ref_P.angular_velxerrordegrees_Y0;

    // VirtualOutportStart for Outport: '<S1>/angular_vel y error [degrees]'
    Controller_without_ref_B.Errory =
      Controller_without_ref_P.angular_velyerrordegrees_Y0;

    // VirtualOutportStart for Outport: '<S1>/angular_vel z error [degrees]'
    Controller_without_ref_B.Errorz =
      Controller_without_ref_P.angular_velzerrordegrees_Y0;

    // VirtualOutportStart for Outport: '<S1>/vel x error [m//s]'
    Controller_without_ref_B.Errorz8 = Controller_without_ref_P.velxerrorms_Y0;

    // VirtualOutportStart for Outport: '<S1>/vel y error [m//s]'
    Controller_without_ref_B.Errorz9 = Controller_without_ref_P.velyerrorms_Y0;

    // VirtualOutportStart for Outport: '<S1>/vel z error [m//s]'
    Controller_without_ref_B.Errorz10 = Controller_without_ref_P.velzerrorms_Y0;

    // End of Start for SubSystem: '<Root>/Create errors'

    // Start for Enabled SubSystem: '<Root>/decController'
    // Start for MATLABSystem: '<S19>/P_angular_vel_x'
    Controller_without_ref_DWork.obj_bm.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_f = true;
    Controller_without_ref_DWork.obj_bm.SampleTime =
      Controller_without_ref_P.P_angular_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_bm.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_t[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_508.initialize(Controller_without_ref_B.cv5,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S19>/P_angular_vel_x'

    // Start for MATLABSystem: '<S19>/D_angular_vel_x'
    Controller_without_ref_DWork.obj_be.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_g = true;
    Controller_without_ref_DWork.obj_be.SampleTime =
      Controller_without_ref_P.D_angular_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_be.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_s[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_505.initialize(Controller_without_ref_B.cv5,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S19>/D_angular_vel_x'

    // Start for MATLABSystem: '<S19>/N_angular_vel_x '
    Controller_without_ref_DWork.obj_l.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_d0 = true;
    Controller_without_ref_DWork.obj_l.SampleTime =
      Controller_without_ref_P.N_angular_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_l.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_r[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_507.initialize(Controller_without_ref_B.cv5,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S19>/N_angular_vel_x '

    // Start for MATLABSystem: '<S19>/I_angular_vel_x'
    Controller_without_ref_DWork.obj_pb.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_mb = true;
    Controller_without_ref_DWork.obj_pb.SampleTime =
      Controller_without_ref_P.I_angular_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_pb.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_q[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_506.initialize(Controller_without_ref_B.cv5,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S19>/I_angular_vel_x'

    // Start for MATLABSystem: '<S22>/P_angular_vel_y'
    Controller_without_ref_DWork.obj_b.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_j = true;
    Controller_without_ref_DWork.obj_b.SampleTime =
      Controller_without_ref_P.P_angular_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_b.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_p[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_522.initialize(Controller_without_ref_B.cv5,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S22>/P_angular_vel_y'

    // Start for MATLABSystem: '<S22>/D_angular_vel_y'
    Controller_without_ref_DWork.obj_m.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_h1 = true;
    Controller_without_ref_DWork.obj_m.SampleTime =
      Controller_without_ref_P.D_angular_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_m.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_o[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_519.initialize(Controller_without_ref_B.cv5,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S22>/D_angular_vel_y'

    // Start for MATLABSystem: '<S22>/N_angular_vel_y '
    Controller_without_ref_DWork.obj_dp.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ex = true;
    Controller_without_ref_DWork.obj_dp.SampleTime =
      Controller_without_ref_P.N_angular_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_dp.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_n[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_521.initialize(Controller_without_ref_B.cv5,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S22>/N_angular_vel_y '

    // Start for MATLABSystem: '<S22>/I_angular_vel_y'
    Controller_without_ref_DWork.obj_ep.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ef = true;
    Controller_without_ref_DWork.obj_ep.SampleTime =
      Controller_without_ref_P.I_angular_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_ep.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_m[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_520.initialize(Controller_without_ref_B.cv5,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S22>/I_angular_vel_y'

    // Start for MATLABSystem: '<S25>/P_angular_vel_z'
    Controller_without_ref_DWork.obj_e.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_h = true;
    Controller_without_ref_DWork.obj_e.SampleTime =
      Controller_without_ref_P.P_angular_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_e.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_l[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_536.initialize(Controller_without_ref_B.cv5,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S25>/P_angular_vel_z'

    // Start for MATLABSystem: '<S25>/D_angular_vel_z'
    Controller_without_ref_DWork.obj_jg.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_if = true;
    Controller_without_ref_DWork.obj_jg.SampleTime =
      Controller_without_ref_P.D_angular_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_jg.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_k[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_533.initialize(Controller_without_ref_B.cv5,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S25>/D_angular_vel_z'

    // Start for MATLABSystem: '<S25>/N_angular_vel_z '
    Controller_without_ref_DWork.obj_g.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_m1 = true;
    Controller_without_ref_DWork.obj_g.SampleTime =
      Controller_without_ref_P.N_angular_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_g.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_j[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_535.initialize(Controller_without_ref_B.cv5,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S25>/N_angular_vel_z '

    // Start for MATLABSystem: '<S25>/I_angular_vel_z'
    Controller_without_ref_DWork.obj_p.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_k = true;
    Controller_without_ref_DWork.obj_p.SampleTime =
      Controller_without_ref_P.I_angular_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_p.isInitialized = 1;
    for (i = 0; i < 34; i++) {
      Controller_without_ref_B.cv5[i] = tmp_i[i];
    }

    Controller_without_ref_B.cv5[34] = '\x00';
    ParamGet_Controller_without_ref_534.initialize(Controller_without_ref_B.cv5,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S25>/I_angular_vel_z'

    // Start for MATLABSystem: '<S28>/P_vel_x'
    Controller_without_ref_DWork.obj_ns.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_a = true;
    Controller_without_ref_DWork.obj_ns.SampleTime =
      Controller_without_ref_P.P_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_ns.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv7[i] = tmp_h[i];
    }

    Controller_without_ref_B.cv7[26] = '\x00';
    ParamGet_Controller_without_ref_550.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S28>/P_vel_x'

    // Start for MATLABSystem: '<S28>/D_vel_x'
    Controller_without_ref_DWork.obj_d.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_d = true;
    Controller_without_ref_DWork.obj_d.SampleTime =
      Controller_without_ref_P.D_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_d.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv7[i] = tmp_g[i];
    }

    Controller_without_ref_B.cv7[26] = '\x00';
    ParamGet_Controller_without_ref_547.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S28>/D_vel_x'

    // Start for MATLABSystem: '<S28>/N_vel_x '
    Controller_without_ref_DWork.obj_a3.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_il = true;
    Controller_without_ref_DWork.obj_a3.SampleTime =
      Controller_without_ref_P.N_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_a3.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv7[i] = tmp_f[i];
    }

    Controller_without_ref_B.cv7[26] = '\x00';
    ParamGet_Controller_without_ref_549.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S28>/N_vel_x '

    // Start for MATLABSystem: '<S28>/I_vel_x'
    Controller_without_ref_DWork.obj_cv.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_p = true;
    Controller_without_ref_DWork.obj_cv.SampleTime =
      Controller_without_ref_P.I_vel_x_SampleTime;
    Controller_without_ref_DWork.obj_cv.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv7[i] = tmp_e[i];
    }

    Controller_without_ref_B.cv7[26] = '\x00';
    ParamGet_Controller_without_ref_548.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S28>/I_vel_x'

    // Start for MATLABSystem: '<S31>/P_vel_y'
    Controller_without_ref_DWork.obj_ji.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_ej = true;
    Controller_without_ref_DWork.obj_ji.SampleTime =
      Controller_without_ref_P.P_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_ji.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv7[i] = tmp_d[i];
    }

    Controller_without_ref_B.cv7[26] = '\x00';
    ParamGet_Controller_without_ref_564.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S31>/P_vel_y'

    // Start for MATLABSystem: '<S31>/D_vel_y'
    Controller_without_ref_DWork.obj_n.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_c = true;
    Controller_without_ref_DWork.obj_n.SampleTime =
      Controller_without_ref_P.D_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_n.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv7[i] = tmp_c[i];
    }

    Controller_without_ref_B.cv7[26] = '\x00';
    ParamGet_Controller_without_ref_561.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S31>/D_vel_y'

    // Start for MATLABSystem: '<S31>/N_vel_y '
    Controller_without_ref_DWork.obj_c.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_b = true;
    Controller_without_ref_DWork.obj_c.SampleTime =
      Controller_without_ref_P.N_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_c.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv7[i] = tmp_b[i];
    }

    Controller_without_ref_B.cv7[26] = '\x00';
    ParamGet_Controller_without_ref_563.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S31>/N_vel_y '

    // Start for MATLABSystem: '<S31>/I_vel_y'
    Controller_without_ref_DWork.obj_jx.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_m = true;
    Controller_without_ref_DWork.obj_jx.SampleTime =
      Controller_without_ref_P.I_vel_y_SampleTime;
    Controller_without_ref_DWork.obj_jx.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv7[i] = tmp_a[i];
    }

    Controller_without_ref_B.cv7[26] = '\x00';
    ParamGet_Controller_without_ref_562.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S31>/I_vel_y'

    // Start for MATLABSystem: '<S34>/P_vel_z'
    Controller_without_ref_DWork.obj.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_l = true;
    Controller_without_ref_DWork.obj.SampleTime =
      Controller_without_ref_P.P_vel_z_SampleTime;
    Controller_without_ref_DWork.obj.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv7[i] = tmp_9[i];
    }

    Controller_without_ref_B.cv7[26] = '\x00';
    ParamGet_Controller_without_ref_578.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S34>/P_vel_z'

    // Start for MATLABSystem: '<S34>/D_vel_z'
    Controller_without_ref_DWork.obj_a.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_n = true;
    Controller_without_ref_DWork.obj_a.SampleTime =
      Controller_without_ref_P.D_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_a.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv7[i] = tmp_8[i];
    }

    Controller_without_ref_B.cv7[26] = '\x00';
    ParamGet_Controller_without_ref_575.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S34>/D_vel_z'

    // Start for MATLABSystem: '<S34>/N_vel_z '
    Controller_without_ref_DWork.obj_h.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_e = true;
    Controller_without_ref_DWork.obj_h.SampleTime =
      Controller_without_ref_P.N_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_h.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv7[i] = tmp_7[i];
    }

    Controller_without_ref_B.cv7[26] = '\x00';
    ParamGet_Controller_without_ref_577.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S34>/N_vel_z '

    // Start for MATLABSystem: '<S34>/I_vel_z'
    Controller_without_ref_DWork.obj_j.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_n4 = true;
    Controller_without_ref_DWork.obj_j.SampleTime =
      Controller_without_ref_P.I_vel_z_SampleTime;
    Controller_without_ref_DWork.obj_j.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      Controller_without_ref_B.cv7[i] = tmp_6[i];
    }

    Controller_without_ref_B.cv7[26] = '\x00';
    ParamGet_Controller_without_ref_576.initialize(Controller_without_ref_B.cv7,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S34>/I_vel_z'
    // End of Start for SubSystem: '<Root>/decController'

    // InitializeConditions for Enabled SubSystem: '<Root>/decController'
    // InitializeConditions for DiscreteIntegrator: '<S18>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE =
      Controller_without_ref_P.Integrator_IC;

    // InitializeConditions for DiscreteIntegrator: '<S18>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE =
      Controller_without_ref_P.Filter_IC;

    // InitializeConditions for DiscreteIntegrator: '<S21>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_h =
      Controller_without_ref_P.Integrator_IC_o;

    // InitializeConditions for DiscreteIntegrator: '<S21>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_c =
      Controller_without_ref_P.Filter_IC_n;

    // InitializeConditions for DiscreteIntegrator: '<S24>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_a =
      Controller_without_ref_P.Integrator_IC_d;

    // InitializeConditions for DiscreteIntegrator: '<S24>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_f =
      Controller_without_ref_P.Filter_IC_c;

    // InitializeConditions for DiscreteIntegrator: '<S27>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_f =
      Controller_without_ref_P.Integrator_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S27>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_a =
      Controller_without_ref_P.Filter_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S30>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_n =
      Controller_without_ref_P.Integrator_IC_i;

    // InitializeConditions for DiscreteIntegrator: '<S30>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_g =
      Controller_without_ref_P.Filter_IC_jx;

    // InitializeConditions for DiscreteIntegrator: '<S33>/Integrator'
    Controller_without_ref_DWork.Integrator_DSTATE_ny =
      Controller_without_ref_P.Integrator_IC_m;

    // InitializeConditions for DiscreteIntegrator: '<S33>/Filter'
    Controller_without_ref_DWork.Filter_DSTATE_cw =
      Controller_without_ref_P.Filter_IC_p;

    // End of InitializeConditions for SubSystem: '<Root>/decController'

    // Start for Enabled SubSystem: '<Root>/decController'
    // VirtualOutportStart for Outport: '<S6>/velocites [angular xyz, linear xyz]' 
    Controller_without_ref_B.Saturate =
      Controller_without_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_without_ref_B.Saturate_f =
      Controller_without_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_without_ref_B.Saturate_i =
      Controller_without_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_without_ref_B.Saturate_b =
      Controller_without_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_without_ref_B.Saturate_h =
      Controller_without_ref_P.velocitesangularxyzlinearxyz_Y0;
    Controller_without_ref_B.Saturate_bk =
      Controller_without_ref_P.velocitesangularxyzlinearxyz_Y0;

    // End of Start for SubSystem: '<Root>/decController'

    // Start for MATLABSystem: '<S2>/Get front strafe decouple'
    Controller_without_ref_DWork.obj_jl.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_o = true;
    Controller_without_ref_DWork.obj_jl.SampleTime =
      Controller_without_ref_P.Getfrontstrafedecouple_SampleTi;
    Controller_without_ref_DWork.obj_jl.isInitialized = 1;
    for (i = 0; i < 40; i++) {
      Controller_without_ref_B.cv1[i] = tmp_5[i];
    }

    Controller_without_ref_B.cv1[40] = '\x00';
    ParamGet_Controller_without_ref_465.initialize(Controller_without_ref_B.cv1,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S2>/Get front strafe decouple'

    // Start for MATLABSystem: '<S2>/Get front forward decouple'
    Controller_without_ref_DWork.obj_ec.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_fw = true;
    Controller_without_ref_DWork.obj_ec.SampleTime =
      Controller_without_ref_P.Getfrontforwarddecouple_SampleT;
    Controller_without_ref_DWork.obj_ec.isInitialized = 1;
    for (i = 0; i < 41; i++) {
      Controller_without_ref_B.cv0[i] = tmp_4[i];
    }

    Controller_without_ref_B.cv0[41] = '\x00';
    ParamGet_Controller_without_ref_463.initialize(Controller_without_ref_B.cv0,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S2>/Get front forward decouple'

    // Start for MATLABSystem: '<S2>/Get front pitch bias'
    Controller_without_ref_DWork.obj_nj.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_jf = true;
    Controller_without_ref_DWork.obj_nj.SampleTime =
      Controller_without_ref_P.Getfrontpitchbias_SampleTime;
    Controller_without_ref_DWork.obj_nj.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_without_ref_B.cv4[i] = tmp_3[i];
    }

    Controller_without_ref_B.cv4[35] = '\x00';
    ParamGet_Controller_without_ref_464.initialize(Controller_without_ref_B.cv4,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S2>/Get front pitch bias'

    // Start for MATLABSystem: '<S2>/Get front vertical bias'
    Controller_without_ref_DWork.obj_lo.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_b1 = true;
    Controller_without_ref_DWork.obj_lo.SampleTime =
      Controller_without_ref_P.Getfrontverticalbias_SampleTime;
    Controller_without_ref_DWork.obj_lo.isInitialized = 1;
    for (i = 0; i < 38; i++) {
      Controller_without_ref_B.cv2[i] = tmp_2[i];
    }

    Controller_without_ref_B.cv2[38] = '\x00';
    ParamGet_Controller_without_ref_466.initialize(Controller_without_ref_B.cv2,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S2>/Get front vertical bias'

    // Start for MATLABSystem: '<S2>/Get buoyancy'
    Controller_without_ref_DWork.obj_ef.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_bb = true;
    Controller_without_ref_DWork.obj_ef.SampleTime =
      Controller_without_ref_P.Getbuoyancy_SampleTime;
    Controller_without_ref_DWork.obj_ef.isInitialized = 1;
    for (i = 0; i < 35; i++) {
      Controller_without_ref_B.cv4[i] = tmp_1[i];
    }

    Controller_without_ref_B.cv4[35] = '\x00';
    ParamGet_Controller_without_ref_462.initialize(Controller_without_ref_B.cv4,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S2>/Get buoyancy'

    // Start for Enabled SubSystem: '<Root>/toPWM'
    // Start for Atomic SubSystem: '<S9>/Publish'
    // Start for MATLABSystem: '<S41>/SinkBlock'
    Controller_without_ref_DWork.obj_pw.isInitialized = 0;
    Controller_without_ref_DWork.objisempty = true;
    Controller_without_ref_DWork.obj_pw.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      tmp_y[i] = tmp_0[i];
    }

    tmp_y[16] = '\x00';
    Pub_Controller_without_ref_607.create_publisher(tmp_y,
      Controller_wi_MessageQueueLen_o);

    // End of Start for MATLABSystem: '<S41>/SinkBlock'
    // End of Start for SubSystem: '<S9>/Publish'
    // End of Start for SubSystem: '<Root>/toPWM'

    // Start for MATLABSystem: '<S4>/Get alpha'
    Controller_without_ref_DWork.obj_hx.isInitialized = 0;
    Controller_without_ref_DWork.objisempty_g0 = true;
    Controller_without_ref_DWork.obj_hx.SampleTime =
      Controller_without_ref_P.Getalpha_SampleTime;
    Controller_without_ref_DWork.obj_hx.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      Controller_without_ref_B.cv8[i] = tmp[i];
    }

    Controller_without_ref_B.cv8[24] = '\x00';
    ParamGet_Controller_without_ref_687.initialize(Controller_without_ref_B.cv8,
      Control_ParameterInitialValue_o, 0U, 1U, 2U);

    // End of Start for MATLABSystem: '<S4>/Get alpha'

    // InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' 
    Controller_without_ref_DWork.DiscreteTimeIntegrator_DSTATE =
      Controller_without_ref_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' 
    Controller_without_ref_DWork.DiscreteTimeIntegrator1_DSTATE =
      Controller_without_ref_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' 
    Controller_without_ref_DWork.DiscreteTimeIntegrator2_DSTATE =
      Controller_without_ref_P.DiscreteTimeIntegrator2_IC;

    // InitializeConditions for DiscreteFilter: '<S4>/Discrete Filter'
    Controller_without_ref_DWork.DiscreteFilter_denStates =
      Controller_without_ref_P.DiscreteFilter_InitialDenominat;

    // InitializeConditions for DiscreteFilter: '<S4>/Discrete Filter1'
    Controller_without_ref_DWork.DiscreteFilter1_denStates =
      Controller_without_ref_P.DiscreteFilter1_InitialDenomina;

    // InitializeConditions for DiscreteFilter: '<S4>/Discrete Filter2'
    Controller_without_ref_DWork.DiscreteFilter2_denStates =
      Controller_without_ref_P.DiscreteFilter2_InitialDenomina;
  }
}

// Model terminate function
void ControllerModelClass::terminate()
{
  // Start for MATLABSystem: '<Root>/Get controller type' incorporates:
  //   Terminate for MATLABSystem: '<Root>/Get controller type'

  if (Controller_without_ref_DWork.obj_nl.isInitialized == 1) {
    Controller_without_ref_DWork.obj_nl.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/Get controller type'

  // Terminate for Atomic SubSystem: '<Root>/cmd_vel'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S5>/SourceBlock'

  if (Controller_without_ref_DWork.obj_nf.isInitialized == 1) {
    Controller_without_ref_DWork.obj_nf.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/cmd_vel'

  // Terminate for Atomic SubSystem: '<Root>/imu_data'
  // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S7>/SourceBlock'

  if (Controller_without_ref_DWork.obj_k.isInitialized == 1) {
    Controller_without_ref_DWork.obj_k.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/imu_data'

  // Start for MATLABSystem: '<S4>/Enable integration?' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Enable integration?'

  if (Controller_without_ref_DWork.obj_g0.isInitialized == 1) {
    Controller_without_ref_DWork.obj_g0.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Enable integration?'

  // Terminate for Enabled SubSystem: '<Root>/decController'
  // Start for MATLABSystem: '<S19>/P_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S19>/P_angular_vel_x'

  if (Controller_without_ref_DWork.obj_bm.isInitialized == 1) {
    Controller_without_ref_DWork.obj_bm.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S19>/P_angular_vel_x'

  // Start for MATLABSystem: '<S19>/D_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S19>/D_angular_vel_x'

  if (Controller_without_ref_DWork.obj_be.isInitialized == 1) {
    Controller_without_ref_DWork.obj_be.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S19>/D_angular_vel_x'

  // Start for MATLABSystem: '<S19>/N_angular_vel_x ' incorporates:
  //   Terminate for MATLABSystem: '<S19>/N_angular_vel_x '

  if (Controller_without_ref_DWork.obj_l.isInitialized == 1) {
    Controller_without_ref_DWork.obj_l.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S19>/N_angular_vel_x '

  // Start for MATLABSystem: '<S19>/I_angular_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S19>/I_angular_vel_x'

  if (Controller_without_ref_DWork.obj_pb.isInitialized == 1) {
    Controller_without_ref_DWork.obj_pb.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S19>/I_angular_vel_x'

  // Start for MATLABSystem: '<S22>/P_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S22>/P_angular_vel_y'

  if (Controller_without_ref_DWork.obj_b.isInitialized == 1) {
    Controller_without_ref_DWork.obj_b.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S22>/P_angular_vel_y'

  // Start for MATLABSystem: '<S22>/D_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S22>/D_angular_vel_y'

  if (Controller_without_ref_DWork.obj_m.isInitialized == 1) {
    Controller_without_ref_DWork.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S22>/D_angular_vel_y'

  // Start for MATLABSystem: '<S22>/N_angular_vel_y ' incorporates:
  //   Terminate for MATLABSystem: '<S22>/N_angular_vel_y '

  if (Controller_without_ref_DWork.obj_dp.isInitialized == 1) {
    Controller_without_ref_DWork.obj_dp.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S22>/N_angular_vel_y '

  // Start for MATLABSystem: '<S22>/I_angular_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S22>/I_angular_vel_y'

  if (Controller_without_ref_DWork.obj_ep.isInitialized == 1) {
    Controller_without_ref_DWork.obj_ep.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S22>/I_angular_vel_y'

  // Start for MATLABSystem: '<S25>/P_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S25>/P_angular_vel_z'

  if (Controller_without_ref_DWork.obj_e.isInitialized == 1) {
    Controller_without_ref_DWork.obj_e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S25>/P_angular_vel_z'

  // Start for MATLABSystem: '<S25>/D_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S25>/D_angular_vel_z'

  if (Controller_without_ref_DWork.obj_jg.isInitialized == 1) {
    Controller_without_ref_DWork.obj_jg.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S25>/D_angular_vel_z'

  // Start for MATLABSystem: '<S25>/N_angular_vel_z ' incorporates:
  //   Terminate for MATLABSystem: '<S25>/N_angular_vel_z '

  if (Controller_without_ref_DWork.obj_g.isInitialized == 1) {
    Controller_without_ref_DWork.obj_g.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S25>/N_angular_vel_z '

  // Start for MATLABSystem: '<S25>/I_angular_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S25>/I_angular_vel_z'

  if (Controller_without_ref_DWork.obj_p.isInitialized == 1) {
    Controller_without_ref_DWork.obj_p.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S25>/I_angular_vel_z'

  // Start for MATLABSystem: '<S28>/P_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S28>/P_vel_x'

  if (Controller_without_ref_DWork.obj_ns.isInitialized == 1) {
    Controller_without_ref_DWork.obj_ns.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S28>/P_vel_x'

  // Start for MATLABSystem: '<S28>/D_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S28>/D_vel_x'

  if (Controller_without_ref_DWork.obj_d.isInitialized == 1) {
    Controller_without_ref_DWork.obj_d.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S28>/D_vel_x'

  // Start for MATLABSystem: '<S28>/N_vel_x ' incorporates:
  //   Terminate for MATLABSystem: '<S28>/N_vel_x '

  if (Controller_without_ref_DWork.obj_a3.isInitialized == 1) {
    Controller_without_ref_DWork.obj_a3.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S28>/N_vel_x '

  // Start for MATLABSystem: '<S28>/I_vel_x' incorporates:
  //   Terminate for MATLABSystem: '<S28>/I_vel_x'

  if (Controller_without_ref_DWork.obj_cv.isInitialized == 1) {
    Controller_without_ref_DWork.obj_cv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S28>/I_vel_x'

  // Start for MATLABSystem: '<S31>/P_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S31>/P_vel_y'

  if (Controller_without_ref_DWork.obj_ji.isInitialized == 1) {
    Controller_without_ref_DWork.obj_ji.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S31>/P_vel_y'

  // Start for MATLABSystem: '<S31>/D_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S31>/D_vel_y'

  if (Controller_without_ref_DWork.obj_n.isInitialized == 1) {
    Controller_without_ref_DWork.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S31>/D_vel_y'

  // Start for MATLABSystem: '<S31>/N_vel_y ' incorporates:
  //   Terminate for MATLABSystem: '<S31>/N_vel_y '

  if (Controller_without_ref_DWork.obj_c.isInitialized == 1) {
    Controller_without_ref_DWork.obj_c.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S31>/N_vel_y '

  // Start for MATLABSystem: '<S31>/I_vel_y' incorporates:
  //   Terminate for MATLABSystem: '<S31>/I_vel_y'

  if (Controller_without_ref_DWork.obj_jx.isInitialized == 1) {
    Controller_without_ref_DWork.obj_jx.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S31>/I_vel_y'

  // Start for MATLABSystem: '<S34>/P_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S34>/P_vel_z'

  if (Controller_without_ref_DWork.obj.isInitialized == 1) {
    Controller_without_ref_DWork.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S34>/P_vel_z'

  // Start for MATLABSystem: '<S34>/D_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S34>/D_vel_z'

  if (Controller_without_ref_DWork.obj_a.isInitialized == 1) {
    Controller_without_ref_DWork.obj_a.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S34>/D_vel_z'

  // Start for MATLABSystem: '<S34>/N_vel_z ' incorporates:
  //   Terminate for MATLABSystem: '<S34>/N_vel_z '

  if (Controller_without_ref_DWork.obj_h.isInitialized == 1) {
    Controller_without_ref_DWork.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S34>/N_vel_z '

  // Start for MATLABSystem: '<S34>/I_vel_z' incorporates:
  //   Terminate for MATLABSystem: '<S34>/I_vel_z'

  if (Controller_without_ref_DWork.obj_j.isInitialized == 1) {
    Controller_without_ref_DWork.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S34>/I_vel_z'
  // End of Terminate for SubSystem: '<Root>/decController'

  // Start for MATLABSystem: '<S2>/Get front strafe decouple' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get front strafe decouple'

  if (Controller_without_ref_DWork.obj_jl.isInitialized == 1) {
    Controller_without_ref_DWork.obj_jl.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get front strafe decouple'

  // Start for MATLABSystem: '<S2>/Get front forward decouple' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get front forward decouple'

  if (Controller_without_ref_DWork.obj_ec.isInitialized == 1) {
    Controller_without_ref_DWork.obj_ec.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get front forward decouple'

  // Start for MATLABSystem: '<S2>/Get front pitch bias' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get front pitch bias'

  if (Controller_without_ref_DWork.obj_nj.isInitialized == 1) {
    Controller_without_ref_DWork.obj_nj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get front pitch bias'

  // Start for MATLABSystem: '<S2>/Get front vertical bias' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get front vertical bias'

  if (Controller_without_ref_DWork.obj_lo.isInitialized == 1) {
    Controller_without_ref_DWork.obj_lo.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get front vertical bias'

  // Start for MATLABSystem: '<S2>/Get buoyancy' incorporates:
  //   Terminate for MATLABSystem: '<S2>/Get buoyancy'

  if (Controller_without_ref_DWork.obj_ef.isInitialized == 1) {
    Controller_without_ref_DWork.obj_ef.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/Get buoyancy'

  // Terminate for Enabled SubSystem: '<Root>/toPWM'
  // Terminate for Atomic SubSystem: '<S9>/Publish'
  // Start for MATLABSystem: '<S41>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S41>/SinkBlock'

  if (Controller_without_ref_DWork.obj_pw.isInitialized == 1) {
    Controller_without_ref_DWork.obj_pw.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S41>/SinkBlock'
  // End of Terminate for SubSystem: '<S9>/Publish'
  // End of Terminate for SubSystem: '<Root>/toPWM'

  // Start for MATLABSystem: '<S4>/Get alpha' incorporates:
  //   Terminate for MATLABSystem: '<S4>/Get alpha'

  if (Controller_without_ref_DWork.obj_hx.isInitialized == 1) {
    Controller_without_ref_DWork.obj_hx.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/Get alpha'
}

// Constructor
ControllerModelClass::ControllerModelClass()
{
  static const Parameters_Controller_without_T Controller_without_ref_P_temp = {
    1.0,                               // Mask Parameter: PIDController_Kt
                                       //  Referenced by: '<S18>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_j
                                       //  Referenced by: '<S21>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_p
                                       //  Referenced by: '<S24>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_jw
                                       //  Referenced by: '<S27>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_c
                                       //  Referenced by: '<S30>/Kt'

    1.0,                               // Mask Parameter: PIDController_Kt_l
                                       //  Referenced by: '<S33>/Kt'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturationLi
                                       //  Referenced by:
                                       //    '<S18>/Saturate'
                                       //    '<S20>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_e
                                       //  Referenced by:
                                       //    '<S21>/Saturate'
                                       //    '<S23>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_p
                                       //  Referenced by:
                                       //    '<S24>/Saturate'
                                       //    '<S26>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_i
                                       //  Referenced by:
                                       //    '<S27>/Saturate'
                                       //    '<S29>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturation_g
                                       //  Referenced by:
                                       //    '<S30>/Saturate'
                                       //    '<S32>/DeadZone'

    -1.0,                              // Mask Parameter: PIDController_LowerSaturatio_pm
                                       //  Referenced by:
                                       //    '<S33>/Saturate'
                                       //    '<S35>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturationLi
                                       //  Referenced by:
                                       //    '<S18>/Saturate'
                                       //    '<S20>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_o
                                       //  Referenced by:
                                       //    '<S21>/Saturate'
                                       //    '<S23>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_e
                                       //  Referenced by:
                                       //    '<S24>/Saturate'
                                       //    '<S26>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_d
                                       //  Referenced by:
                                       //    '<S27>/Saturate'
                                       //    '<S29>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturation_b
                                       //  Referenced by:
                                       //    '<S30>/Saturate'
                                       //    '<S32>/DeadZone'

    1.0,                               // Mask Parameter: PIDController_UpperSaturatio_ba
                                       //  Referenced by:
                                       //    '<S33>/Saturate'
                                       //    '<S35>/DeadZone'


    {
      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // Data

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // Data_SL_Info

      {
        0U,                            // DataOffset

        {
          {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          } }
        ,                              // Dim

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        }                              // Dim_SL_Info
      }                                // Layout
    },                                 // Computed Parameter: Out1_Y0
                                       //  Referenced by: '<S36>/Out1'


    {
      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // Data

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // Data_SL_Info

      {
        0U,                            // DataOffset

        {
          {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          } }
        ,                              // Dim

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        }                              // Dim_SL_Info
      }                                // Layout
    },                                 // Computed Parameter: Constant_Value
                                       //  Referenced by: '<S7>/Constant'


    {
      {
        0U, 0U, 0U, 0U, 0U, 0U }
      ,                                // Data

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // Data_SL_Info

      {
        0U,                            // DataOffset

        {
          {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          }, {
            {
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
              0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
            ,                          // Label

            {
              0U,                      // CurrentLength
              0U                       // ReceivedLength
            },                         // Label_SL_Info
            0U,                        // Size
            0U                         // Stride
          } }
        ,                              // Dim

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        }                              // Dim_SL_Info
      }                                // Layout
    },                                 // Computed Parameter: Constant_Value_i
                                       //  Referenced by: '<S38>/Constant'


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
                                       //  Referenced by: '<S11>/Out1'


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
                                       //  Referenced by: '<S5>/Constant'

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

    0.0,                               // Computed Parameter: angular_velX_Y0
                                       //  Referenced by: '<S3>/<angular_vel X>'

    0.0,                               // Computed Parameter: angular_velY_Y0
                                       //  Referenced by: '<S3>/<angular_vel Y>'

    0.0,                               // Computed Parameter: angular_velZ_Y0
                                       //  Referenced by: '<S3>/<angular_vel Z> '

    0.0,                               // Computed Parameter: velocityX_Y0
                                       //  Referenced by: '<S3>/<velocity X>'

    0.0,                               // Computed Parameter: veloctiyY_Y0
                                       //  Referenced by: '<S3>/<veloctiy Y>'

    0.0,                               // Computed Parameter: velocityZ_Y0
                                       //  Referenced by: '<S3>/<velocity Z>'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S4>/Get alpha'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S4>/Enable integration?'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S19>/I_angular_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S19>/N_angular_vel_x '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S19>/D_angular_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S19>/P_angular_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S22>/I_angular_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S22>/N_angular_vel_y '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S22>/D_angular_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S22>/P_angular_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S25>/I_angular_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S25>/N_angular_vel_z '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S25>/D_angular_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S25>/P_angular_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S28>/I_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S28>/N_vel_x '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S28>/D_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S28>/P_vel_x'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S31>/I_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S31>/N_vel_y '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S31>/D_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S31>/P_vel_y'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S34>/I_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S34>/N_vel_z '

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S34>/D_vel_z'

    -1.0,                              // Expression: SampleTime
                                       //  Referenced by: '<S34>/P_vel_z'

    0.0,                               // Computed Parameter: velocitesangularxyzlinearxyz_Y0
                                       //  Referenced by: '<S6>/velocites [angular xyz, linear xyz]'

    0.2,                               // Computed Parameter: Integrator_gainval
                                       //  Referenced by: '<S18>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S18>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval
                                       //  Referenced by: '<S18>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S18>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S20>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S18>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_c
                                       //  Referenced by: '<S21>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S21>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_i
                                       //  Referenced by: '<S21>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S21>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S23>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S21>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_n
                                       //  Referenced by: '<S24>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S24>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_k
                                       //  Referenced by: '<S24>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S24>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S26>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S24>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_j
                                       //  Referenced by: '<S27>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S27>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_h
                                       //  Referenced by: '<S27>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S27>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S29>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S27>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_np
                                       //  Referenced by: '<S30>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S30>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_h0
                                       //  Referenced by: '<S30>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S30>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S32>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S30>/Constant'

    0.2,                               // Computed Parameter: Integrator_gainval_m
                                       //  Referenced by: '<S33>/Integrator'

    0.0,                               // Expression: InitialConditionForIntegrator
                                       //  Referenced by: '<S33>/Integrator'

    0.2,                               // Computed Parameter: Filter_gainval_b
                                       //  Referenced by: '<S33>/Filter'

    0.0,                               // Expression: InitialConditionForFilter
                                       //  Referenced by: '<S33>/Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S35>/ZeroGain'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S33>/Constant'

    0.0,                               // Computed Parameter: yawdegrees_Y0
                                       //  Referenced by: '<S8>/<yaw [degrees]>'

    0.0,                               // Computed Parameter: pitchdegrees_Y0
                                       //  Referenced by: '<S8>/<pitch [degrees]>'

    0.0,                               // Computed Parameter: rolldegrees_Y0
                                       //  Referenced by: '<S8>/<roll [degrees]>'

    0.0,                               // Computed Parameter: angular_velXdegreess_Y0
                                       //  Referenced by: '<S8>/<angular_vel X [degrees//s]>'

    0.0,                               // Computed Parameter: angular_velYdegreess_Y0
                                       //  Referenced by: '<S8>/<angular_vel Y [degrees//s]>'

    0.0,                               // Computed Parameter: angular_velZdegreess_Y0
                                       //  Referenced by: '<S8>/<angular_vel Z [degrees//s]>'

    0.0,                               // Computed Parameter: Zm_Y0
                                       //  Referenced by: '<S8>/<Z [m]>'

    0.0,                               // Computed Parameter: accXms2_Y0
                                       //  Referenced by: '<S8>/<acc X [m//s^2]>'

    0.0,                               // Computed Parameter: accYms2_Y0
                                       //  Referenced by: '<S8>/<acc Y [m//s^2]>'

    0.0,                               // Computed Parameter: accZms2_Y0
                                       //  Referenced by: '<S8>/<acc Z [m//s^2]>'

    57.295779513082323,                // Expression: 180/pi
                                       //  Referenced by: '<S8>/Gain'

    -57.295779513082323,               // Expression: -180/pi
                                       //  Referenced by: '<S8>/Gain1'

    -57.295779513082323,               // Expression: -180/pi
                                       //  Referenced by: '<S8>/Gain2'

    1.0,                               // Expression: 1
                                       //  Referenced by: '<S9>/Saturation'

    -1.0,                              // Expression: -1
                                       //  Referenced by: '<S9>/Saturation'

    0.2,                               // Computed Parameter: DiscreteTimeIntegrator_gainval
                                       //  Referenced by: '<S4>/Discrete-Time Integrator'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S4>/Discrete-Time Integrator'

    0.2,                               // Computed Parameter: DiscreteTimeIntegrator1_gainval
                                       //  Referenced by: '<S4>/Discrete-Time Integrator1'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S4>/Discrete-Time Integrator1'

    0.2,                               // Computed Parameter: DiscreteTimeIntegrator2_gainval
                                       //  Referenced by: '<S4>/Discrete-Time Integrator2'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S4>/Discrete-Time Integrator2'

    1.0,                               // Expression: 1
                                       //  Referenced by: '<S4>/Constant'

    1.0,                               // Expression: [1]
                                       //  Referenced by: '<S4>/Discrete Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S4>/Discrete Filter'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S4>/Discrete Filter'

    1.0,                               // Expression: [1]
                                       //  Referenced by: '<S4>/Discrete Filter1'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S4>/Discrete Filter1'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S4>/Discrete Filter1'

    1.0,                               // Expression: [1]
                                       //  Referenced by: '<S4>/Discrete Filter2'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S4>/Discrete Filter2'

    0.0                                // Expression: 0
                                       //  Referenced by: '<S4>/Discrete Filter2'

  };                                   // Modifiable parameters

  // Initialize tunable parameters
  Controller_without_ref_P = Controller_without_ref_P_temp;
}

// Destructor
ControllerModelClass::~ControllerModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Controller_without_r_T * ControllerModelClass::getRTM()
{
  return (&Controller_without_ref_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
