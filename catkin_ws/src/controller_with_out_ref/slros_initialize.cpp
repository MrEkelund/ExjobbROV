#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "Controller_with_out_ref";

// For Block Controller_with_out_ref/cmd_vel
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_Controller_with_out_ref_geometry_msgs_Twist> Sub_Controller_with_out_ref_1;

// For Block Controller_with_out_ref/imu_data
SimulinkSubscriber<sensor_msgs::Imu, SL_Bus_Controller_with_out_ref_sensor_msgs_Imu> Sub_Controller_with_out_ref_28;

// For Block Controller_with_out_ref/Subsystem/Publish
SimulinkPublisher<mavros_msgs::ActuatorControl, SL_Bus_Controller_with_out_ref_mavros_msgs_ActuatorControl> Pub_Controller_with_out_ref_607;

// For Block Controller_with_out_ref/Decouple/Get buoyancy
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_462;

// For Block Controller_with_out_ref/Decouple/Get front forward decouple
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_463;

// For Block Controller_with_out_ref/Decouple/Get front pitch bias
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_464;

// For Block Controller_with_out_ref/Decouple/Get front strafe decouple
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_465;

// For Block Controller_with_out_ref/Decouple/Get front vertical bias
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_466;

// For Block Controller_with_out_ref/Get controller type
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_with_out_ref_106;

// For Block Controller_with_out_ref/decController/angular_vel x/Retrive PID-Parameters/D_angular_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_505;

// For Block Controller_with_out_ref/decController/angular_vel x/Retrive PID-Parameters/I_angular_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_506;

// For Block Controller_with_out_ref/decController/angular_vel x/Retrive PID-Parameters/N_angular_vel_x 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_507;

// For Block Controller_with_out_ref/decController/angular_vel x/Retrive PID-Parameters/P_angular_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_508;

// For Block Controller_with_out_ref/decController/angular_vel y/Retrive PID-Parameters/D_angular_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_519;

// For Block Controller_with_out_ref/decController/angular_vel y/Retrive PID-Parameters/I_angular_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_520;

// For Block Controller_with_out_ref/decController/angular_vel y/Retrive PID-Parameters/N_angular_vel_y 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_521;

// For Block Controller_with_out_ref/decController/angular_vel y/Retrive PID-Parameters/P_angular_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_522;

// For Block Controller_with_out_ref/decController/angular_vel z/Retrive PID-Parameters/D_angular_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_533;

// For Block Controller_with_out_ref/decController/angular_vel z/Retrive PID-Parameters/I_angular_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_534;

// For Block Controller_with_out_ref/decController/angular_vel z/Retrive PID-Parameters/N_angular_vel_z 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_535;

// For Block Controller_with_out_ref/decController/angular_vel z/Retrive PID-Parameters/P_angular_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_536;

// For Block Controller_with_out_ref/decController/vel x/Retrive PID-Parameters/D_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_547;

// For Block Controller_with_out_ref/decController/vel x/Retrive PID-Parameters/I_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_548;

// For Block Controller_with_out_ref/decController/vel x/Retrive PID-Parameters/N_vel_x 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_549;

// For Block Controller_with_out_ref/decController/vel x/Retrive PID-Parameters/P_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_550;

// For Block Controller_with_out_ref/decController/vel y/Retrive PID-Parameters/D_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_561;

// For Block Controller_with_out_ref/decController/vel y/Retrive PID-Parameters/I_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_562;

// For Block Controller_with_out_ref/decController/vel y/Retrive PID-Parameters/N_vel_y 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_563;

// For Block Controller_with_out_ref/decController/vel y/Retrive PID-Parameters/P_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_564;

// For Block Controller_with_out_ref/decController/vel z/Retrive PID-Parameters/D_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_575;

// For Block Controller_with_out_ref/decController/vel z/Retrive PID-Parameters/I_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_576;

// For Block Controller_with_out_ref/decController/vel z/Retrive PID-Parameters/N_vel_z 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_577;

// For Block Controller_with_out_ref/decController/vel z/Retrive PID-Parameters/P_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_with_out_ref_578;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

