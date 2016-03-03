#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block sensorfusion/Get measurements/Subscribe
extern SimulinkSubscriber<std_msgs::Float32MultiArray, SL_Bus_sensorfusion_std_msgs_Float32MultiArray> Sub_sensorfusion_427;

// For Block sensorfusion/Send states and measurements/Publish
extern SimulinkPublisher<std_msgs::Float64MultiArray, SL_Bus_sensorfusion_std_msgs_Float64MultiArray> Pub_sensorfusion_426;

// For Block sensorfusion/Measurement update/Get eps acc
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_615;

// For Block sensorfusion/Measurement update/Get eps mag
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_616;

// For Block sensorfusion/Measurement update/Get gravitational constant
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_617;

// For Block sensorfusion/Measurement update/Get water density
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_618;

// For Block sensorfusion/Measurement update/Get x offset of pressure sensor
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_619;

// For Block sensorfusion/Measurement update/enable acc
extern SimulinkParameterGetter<boolean_T, bool> ParamGet_sensorfusion_628;

// For Block sensorfusion/Measurement update/enable mag
extern SimulinkParameterGetter<boolean_T, bool> ParamGet_sensorfusion_629;

// For Block sensorfusion/Measurement update/enable pressure
extern SimulinkParameterGetter<boolean_T, bool> ParamGet_sensorfusion_630;

// For Block sensorfusion/Measurement update/get R acc [1,1]
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_632;

// For Block sensorfusion/Measurement update/get R acc [3,3]
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_633;

// For Block sensorfusion/Measurement update/get R acc[2,2]
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_634;

// For Block sensorfusion/Measurement update/get R mag [1,1]
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_635;

// For Block sensorfusion/Measurement update/get R mag [2,2]
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_636;

// For Block sensorfusion/Measurement update/get R mag [3,3]
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_637;

// For Block sensorfusion/Measurement update/get R pressure [1,1]
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_638;

// For Block sensorfusion/Time update/Get T
extern SimulinkParameterGetter<real64_T, double> ParamGet_sensorfusion_589;

void slros_node_init(int argc, char** argv);

#endif
