#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "sensorfusion";

// For Block sensorfusion/Get measurements/Subscribe
SimulinkSubscriber<std_msgs::Float32MultiArray, SL_Bus_sensorfusion_std_msgs_Float32MultiArray> Sub_sensorfusion_427;

// For Block sensorfusion/Send states and measurements/Publish
SimulinkPublisher<std_msgs::Float64MultiArray, SL_Bus_sensorfusion_std_msgs_Float64MultiArray> Pub_sensorfusion_426;

// For Block sensorfusion/Measurement update/Get eps acc
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_615;

// For Block sensorfusion/Measurement update/Get eps mag
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_616;

// For Block sensorfusion/Measurement update/Get gravitational constant
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_617;

// For Block sensorfusion/Measurement update/Get water density
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_618;

// For Block sensorfusion/Measurement update/Get x offset of pressure sensor
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_619;

// For Block sensorfusion/Measurement update/enable acc
SimulinkParameterGetter<boolean_T, bool> ParamGet_sensorfusion_628;

// For Block sensorfusion/Measurement update/enable mag
SimulinkParameterGetter<boolean_T, bool> ParamGet_sensorfusion_629;

// For Block sensorfusion/Measurement update/enable pressure
SimulinkParameterGetter<boolean_T, bool> ParamGet_sensorfusion_630;

// For Block sensorfusion/Measurement update/get R acc [1,1]
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_632;

// For Block sensorfusion/Measurement update/get R acc [3,3]
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_633;

// For Block sensorfusion/Measurement update/get R acc[2,2]
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_634;

// For Block sensorfusion/Measurement update/get R mag [1,1]
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_635;

// For Block sensorfusion/Measurement update/get R mag [2,2]
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_636;

// For Block sensorfusion/Measurement update/get R mag [3,3]
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_637;

// For Block sensorfusion/Measurement update/get R pressure [1,1]
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_638;

// For Block sensorfusion/Time update/Get T
SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_589;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

