#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block Controller_without_ref/cmd_vel
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_Controller_without_ref_geometry_msgs_Twist> Sub_Controller_without_ref_1;

// For Block Controller_without_ref/imu_data
extern SimulinkSubscriber<std_msgs::Int64MultiArray, SL_Bus_Controller_without_ref_std_msgs_Int64MultiArray> Sub_Controller_without_ref_28;

// For Block Controller_without_ref/toPWM/Publish
extern SimulinkPublisher<std_msgs::UInt16MultiArray, SL_Bus_Controller_without_ref_std_msgs_UInt16MultiArray> Pub_Controller_without_ref_607;

// For Block Controller_without_ref/Decouple/Get buoyancy
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_462;

// For Block Controller_without_ref/Decouple/Get front forward decouple
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_463;

// For Block Controller_without_ref/Decouple/Get front pitch bias
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_464;

// For Block Controller_without_ref/Decouple/Get front strafe decouple
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_465;

// For Block Controller_without_ref/Decouple/Get front vertical bias
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_466;

// For Block Controller_without_ref/Get controller type
extern SimulinkParameterGetter<int32_T, int> ParamGet_Controller_without_ref_106;

// For Block Controller_without_ref/acc integration/Enable integration?
extern SimulinkParameterGetter<boolean_T, bool> ParamGet_Controller_without_ref_686;

// For Block Controller_without_ref/acc integration/Get alpha
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_687;

// For Block Controller_without_ref/decController/angular_vel x/Retrive PID-Parameters/D_angular_vel_x
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_505;

// For Block Controller_without_ref/decController/angular_vel x/Retrive PID-Parameters/I_angular_vel_x
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_506;

// For Block Controller_without_ref/decController/angular_vel x/Retrive PID-Parameters/N_angular_vel_x 
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_507;

// For Block Controller_without_ref/decController/angular_vel x/Retrive PID-Parameters/P_angular_vel_x
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_508;

// For Block Controller_without_ref/decController/angular_vel y/Retrive PID-Parameters/D_angular_vel_y
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_519;

// For Block Controller_without_ref/decController/angular_vel y/Retrive PID-Parameters/I_angular_vel_y
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_520;

// For Block Controller_without_ref/decController/angular_vel y/Retrive PID-Parameters/N_angular_vel_y 
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_521;

// For Block Controller_without_ref/decController/angular_vel y/Retrive PID-Parameters/P_angular_vel_y
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_522;

// For Block Controller_without_ref/decController/angular_vel z/Retrive PID-Parameters/D_angular_vel_z
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_533;

// For Block Controller_without_ref/decController/angular_vel z/Retrive PID-Parameters/I_angular_vel_z
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_534;

// For Block Controller_without_ref/decController/angular_vel z/Retrive PID-Parameters/N_angular_vel_z 
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_535;

// For Block Controller_without_ref/decController/angular_vel z/Retrive PID-Parameters/P_angular_vel_z
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_536;

// For Block Controller_without_ref/decController/vel x/Retrive PID-Parameters/D_vel_x
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_547;

// For Block Controller_without_ref/decController/vel x/Retrive PID-Parameters/I_vel_x
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_548;

// For Block Controller_without_ref/decController/vel x/Retrive PID-Parameters/N_vel_x 
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_549;

// For Block Controller_without_ref/decController/vel x/Retrive PID-Parameters/P_vel_x
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_550;

// For Block Controller_without_ref/decController/vel y/Retrive PID-Parameters/D_vel_y
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_561;

// For Block Controller_without_ref/decController/vel y/Retrive PID-Parameters/I_vel_y
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_562;

// For Block Controller_without_ref/decController/vel y/Retrive PID-Parameters/N_vel_y 
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_563;

// For Block Controller_without_ref/decController/vel y/Retrive PID-Parameters/P_vel_y
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_564;

// For Block Controller_without_ref/decController/vel z/Retrive PID-Parameters/D_vel_z
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_575;

// For Block Controller_without_ref/decController/vel z/Retrive PID-Parameters/I_vel_z
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_576;

// For Block Controller_without_ref/decController/vel z/Retrive PID-Parameters/N_vel_z 
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_577;

// For Block Controller_without_ref/decController/vel z/Retrive PID-Parameters/P_vel_z
extern SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_578;

void slros_node_init(int argc, char** argv);

#endif
