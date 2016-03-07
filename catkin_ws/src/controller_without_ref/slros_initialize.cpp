#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "Controller_without_ref";

// For Block Controller_without_ref/cmd_vel
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_Controller_without_ref_geometry_msgs_Twist> Sub_Controller_without_ref_1;

// For Block Controller_without_ref/imu_data
SimulinkSubscriber<std_msgs::Float64MultiArray, SL_Bus_Controller_without_ref_std_msgs_Float64MultiArray> Sub_Controller_without_ref_28;

// For Block Controller_without_ref/toPWM/Publish
SimulinkPublisher<std_msgs::UInt16MultiArray, SL_Bus_Controller_without_ref_std_msgs_UInt16MultiArray> Pub_Controller_without_ref_607;

// For Block Controller_without_ref/Decouple1/Get buoyancy
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_784;

// For Block Controller_without_ref/Decouple1/Get front forward decouple
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_785;

// For Block Controller_without_ref/Decouple1/Get front pitch bias
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_786;

// For Block Controller_without_ref/Decouple1/Get front strafe decouple
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_787;

// For Block Controller_without_ref/Decouple1/Get front vertical bias
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_788;

// For Block Controller_without_ref/Decouple2/Get buoyancy
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_807;

// For Block Controller_without_ref/Decouple2/Get front forward decouple
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_808;

// For Block Controller_without_ref/Decouple2/Get front pitch bias
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_809;

// For Block Controller_without_ref/Decouple2/Get front strafe decouple
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_810;

// For Block Controller_without_ref/Decouple2/Get front vertical bias
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_811;

// For Block Controller_without_ref/Get controller type
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_without_ref_106;

// For Block Controller_without_ref/Get test
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_without_ref_823;

// For Block Controller_without_ref/Telegraph/Thruster1 block/Swtiching factor
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_without_ref_714;

// For Block Controller_without_ref/Telegraph/Thruster1 block/Swtiching factor1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_715;

// For Block Controller_without_ref/Telegraph/Thruster1 block/Swtiching factor2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_716;

// For Block Controller_without_ref/Telegraph/Thruster2 block/Swtiching factor
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_without_ref_724;

// For Block Controller_without_ref/Telegraph/Thruster2 block/Swtiching factor1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_725;

// For Block Controller_without_ref/Telegraph/Thruster2 block/Swtiching factor2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_726;

// For Block Controller_without_ref/Telegraph/Thruster3 block/Swtiching factor
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_without_ref_734;

// For Block Controller_without_ref/Telegraph/Thruster3 block/Swtiching factor1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_735;

// For Block Controller_without_ref/Telegraph/Thruster3 block/Swtiching factor2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_736;

// For Block Controller_without_ref/Telegraph/Thruster4 block/Swtiching factor
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_without_ref_744;

// For Block Controller_without_ref/Telegraph/Thruster4 block/Swtiching factor1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_745;

// For Block Controller_without_ref/Telegraph/Thruster4 block/Swtiching factor2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_746;

// For Block Controller_without_ref/Telegraph/Thruster5 block /Swtiching factor
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_without_ref_850;

// For Block Controller_without_ref/Telegraph/Thruster5 block /Swtiching factor1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_851;

// For Block Controller_without_ref/Telegraph/Thruster5 block /Swtiching factor2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_852;

// For Block Controller_without_ref/Telegraph/Thruster6 block/Swtiching factor
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_without_ref_764;

// For Block Controller_without_ref/Telegraph/Thruster6 block/Swtiching factor1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_765;

// For Block Controller_without_ref/Telegraph/Thruster6 block/Swtiching factor2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_766;

// For Block Controller_without_ref/acc integration/Enable integration?
SimulinkParameterGetter<boolean_T, bool> ParamGet_Controller_without_ref_686;

// For Block Controller_without_ref/acc integration/Get alpha
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_687;

// For Block Controller_without_ref/decController/angular_vel x/Retrive PID-Parameters/D_angular_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_505;

// For Block Controller_without_ref/decController/angular_vel x/Retrive PID-Parameters/I_angular_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_506;

// For Block Controller_without_ref/decController/angular_vel x/Retrive PID-Parameters/N_angular_vel_x 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_507;

// For Block Controller_without_ref/decController/angular_vel x/Retrive PID-Parameters/P_angular_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_508;

// For Block Controller_without_ref/decController/angular_vel y/Retrive PID-Parameters/D_angular_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_519;

// For Block Controller_without_ref/decController/angular_vel y/Retrive PID-Parameters/I_angular_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_520;

// For Block Controller_without_ref/decController/angular_vel y/Retrive PID-Parameters/N_angular_vel_y 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_521;

// For Block Controller_without_ref/decController/angular_vel y/Retrive PID-Parameters/P_angular_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_522;

// For Block Controller_without_ref/decController/angular_vel z/Retrive PID-Parameters/D_angular_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_533;

// For Block Controller_without_ref/decController/angular_vel z/Retrive PID-Parameters/I_angular_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_534;

// For Block Controller_without_ref/decController/angular_vel z/Retrive PID-Parameters/N_angular_vel_z 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_535;

// For Block Controller_without_ref/decController/angular_vel z/Retrive PID-Parameters/P_angular_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_536;

// For Block Controller_without_ref/decController/vel x/Retrive PID-Parameters/D_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_547;

// For Block Controller_without_ref/decController/vel x/Retrive PID-Parameters/I_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_548;

// For Block Controller_without_ref/decController/vel x/Retrive PID-Parameters/N_vel_x 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_549;

// For Block Controller_without_ref/decController/vel x/Retrive PID-Parameters/P_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_550;

// For Block Controller_without_ref/decController/vel y/Retrive PID-Parameters/D_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_561;

// For Block Controller_without_ref/decController/vel y/Retrive PID-Parameters/I_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_562;

// For Block Controller_without_ref/decController/vel y/Retrive PID-Parameters/N_vel_y 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_563;

// For Block Controller_without_ref/decController/vel y/Retrive PID-Parameters/P_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_564;

// For Block Controller_without_ref/decController/vel z/Retrive PID-Parameters/D_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_575;

// For Block Controller_without_ref/decController/vel z/Retrive PID-Parameters/I_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_576;

// For Block Controller_without_ref/decController/vel z/Retrive PID-Parameters/N_vel_z 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_577;

// For Block Controller_without_ref/decController/vel z/Retrive PID-Parameters/P_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_without_ref_578;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

