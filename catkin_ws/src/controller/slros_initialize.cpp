#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "Controller";

// For Block Controller/cmd_vel
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_Controller_geometry_msgs_Twist> Sub_Controller_1;

// For Block Controller/imu_data
SimulinkSubscriber<std_msgs::Float64MultiArray, SL_Bus_Controller_std_msgs_Float64MultiArray> Sub_Controller_28;

// For Block Controller/toPWM/Publish
SimulinkPublisher<std_msgs::UInt16MultiArray, SL_Bus_Controller_std_msgs_UInt16MultiArray> Pub_Controller_607;

// For Block Controller/Decouple1/Get buoyancy
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_879;

// For Block Controller/Decouple2/Get buoyancy
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_873;

// For Block Controller/Enabled Subsystem/Get Parameter
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_901;

// For Block Controller/Enabled Subsystem/Get Parameter1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_905;

// For Block Controller/Enabled Subsystem/Get Parameter2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_907;

// For Block Controller/Enabled Subsystem/Get Parameter3
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_909;

// For Block Controller/Enabled Subsystem/Get Parameter4
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_911;

// For Block Controller/Enabled Subsystem/Get Parameter5
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_913;

// For Block Controller/Get controller type
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_106;

// For Block Controller/Get test
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_823;

// For Block Controller/Telegraph/Thruster1 block/Swtiching factor
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_714;

// For Block Controller/Telegraph/Thruster1 block/Swtiching factor1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_715;

// For Block Controller/Telegraph/Thruster1 block/Swtiching factor2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_716;

// For Block Controller/Telegraph/Thruster2 block/Swtiching factor
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_724;

// For Block Controller/Telegraph/Thruster2 block/Swtiching factor1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_725;

// For Block Controller/Telegraph/Thruster2 block/Swtiching factor2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_726;

// For Block Controller/Telegraph/Thruster3 block/Swtiching factor
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_734;

// For Block Controller/Telegraph/Thruster3 block/Swtiching factor1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_735;

// For Block Controller/Telegraph/Thruster3 block/Swtiching factor2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_736;

// For Block Controller/Telegraph/Thruster4 block/Swtiching factor
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_744;

// For Block Controller/Telegraph/Thruster4 block/Swtiching factor1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_745;

// For Block Controller/Telegraph/Thruster4 block/Swtiching factor2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_746;

// For Block Controller/Telegraph/Thruster5 block /Swtiching factor
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_850;

// For Block Controller/Telegraph/Thruster5 block /Swtiching factor1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_851;

// For Block Controller/Telegraph/Thruster5 block /Swtiching factor2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_852;

// For Block Controller/Telegraph/Thruster6 block/Swtiching factor
SimulinkParameterGetter<int32_T, int> ParamGet_Controller_764;

// For Block Controller/Telegraph/Thruster6 block/Swtiching factor1
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_765;

// For Block Controller/Telegraph/Thruster6 block/Swtiching factor2
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_766;

// For Block Controller/acc integration/Enable integration?
SimulinkParameterGetter<boolean_T, bool> ParamGet_Controller_686;

// For Block Controller/acc integration/Get alpha
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_687;

// For Block Controller/decController/angular_vel x/Retrive PID-Parameters/D_angular_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_505;

// For Block Controller/decController/angular_vel x/Retrive PID-Parameters/I_angular_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_506;

// For Block Controller/decController/angular_vel x/Retrive PID-Parameters/N_angular_vel_x 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_507;

// For Block Controller/decController/angular_vel x/Retrive PID-Parameters/P_angular_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_508;

// For Block Controller/decController/angular_vel y/Retrive PID-Parameters/D_angular_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_519;

// For Block Controller/decController/angular_vel y/Retrive PID-Parameters/I_angular_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_520;

// For Block Controller/decController/angular_vel y/Retrive PID-Parameters/N_angular_vel_y 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_521;

// For Block Controller/decController/angular_vel y/Retrive PID-Parameters/P_angular_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_522;

// For Block Controller/decController/angular_vel z/Retrive PID-Parameters/D_angular_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_533;

// For Block Controller/decController/angular_vel z/Retrive PID-Parameters/I_angular_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_534;

// For Block Controller/decController/angular_vel z/Retrive PID-Parameters/N_angular_vel_z 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_535;

// For Block Controller/decController/angular_vel z/Retrive PID-Parameters/P_angular_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_536;

// For Block Controller/decController/vel x/Retrive PID-Parameters/D_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_547;

// For Block Controller/decController/vel x/Retrive PID-Parameters/I_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_548;

// For Block Controller/decController/vel x/Retrive PID-Parameters/N_vel_x 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_549;

// For Block Controller/decController/vel x/Retrive PID-Parameters/P_vel_x
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_550;

// For Block Controller/decController/vel y/Retrive PID-Parameters/D_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_561;

// For Block Controller/decController/vel y/Retrive PID-Parameters/I_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_562;

// For Block Controller/decController/vel y/Retrive PID-Parameters/N_vel_y 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_563;

// For Block Controller/decController/vel y/Retrive PID-Parameters/P_vel_y
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_564;

// For Block Controller/decController/vel z/Retrive PID-Parameters/D_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_575;

// For Block Controller/decController/vel z/Retrive PID-Parameters/I_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_576;

// For Block Controller/decController/vel z/Retrive PID-Parameters/N_vel_z 
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_577;

// For Block Controller/decController/vel z/Retrive PID-Parameters/P_vel_z
SimulinkParameterGetter<real64_T, double> ParamGet_Controller_578;

// For Block Controller/toPWM/Enable thrusters /Get Parameter
SimulinkParameterGetter<boolean_T, bool> ParamGet_Controller_858;

// For Block Controller/toPWM/Enable thrusters /Get Parameter1
SimulinkParameterGetter<boolean_T, bool> ParamGet_Controller_861;

// For Block Controller/toPWM/Enable thrusters /Get Parameter2
SimulinkParameterGetter<boolean_T, bool> ParamGet_Controller_862;

// For Block Controller/toPWM/Enable thrusters /Get Parameter3
SimulinkParameterGetter<boolean_T, bool> ParamGet_Controller_863;

// For Block Controller/toPWM/Enable thrusters /Get Parameter4
SimulinkParameterGetter<boolean_T, bool> ParamGet_Controller_864;

// For Block Controller/toPWM/Enable thrusters /Get Parameter5
SimulinkParameterGetter<boolean_T, bool> ParamGet_Controller_865;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

