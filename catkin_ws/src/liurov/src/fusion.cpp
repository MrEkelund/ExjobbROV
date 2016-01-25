/*
 * File: liurov/src/fusion.cpp
 * Author: Erik Ekelund
 * Date: Jan 2016
 * Description: Estimates states  of ROV via measurements from the I/O node.
 */

#include <fusion.h>

Fusion::Fusion(){
  // connect dynamic reconfigure
  dynamic_reconfigure::Server<liurov::fusionConfig>::CallbackType f;
  f = boost::bind(&Fusion::configCallback, this, _1, _2);
  server.setCallback(f);

  //connect subscribers
  sensor_data_sub = nh.subscribe<std_msgs::Float64MultiArray>("sensor_data", 1, &Fusion::sensorDataCallback, this);


};

// Accessors and mutators for position estimates
double Fusion::getPosX(){
  return pos_estimate[0];
};
double Fusion::getPosY(){
  return pos_estimate[1];
};
double Fusion::getPosZ(){
  return pos_estimate[2];
};

void Fusion::setPosX(double new_x){
  pos_estimate[0]=new_x;
};
void Fusion::setPosY(double new_y){
  pos_estimate[1]=new_y;
};
void Fusion::setPosZ(double new_z){
  pos_estimate[2]=new_z;
};

//Accessors and mutators for angle estimates
double Fusion::getAngleX(){
  return angle_estimate[0];
};
double Fusion::getAngleY(){
  return angle_estimate[1];
};
double Fusion::getAngleZ(){
  return angle_estimate[2];
};

void Fusion::setAngleX(double new_angle_x){
  angle_estimate[0]=new_angle_x;
};
void Fusion::setAngleY(double new_angle_y){
  angle_estimate[1]=new_angle_y;
};
void Fusion::setAngleZ(double new_angle_z){
  angle_estimate[2]=new_angle_z;
};

//Accessors and mutators for angle rate estimates
double Fusion::getAngleRateX(){
  return angle_rate_estimate[0];
};
double Fusion::getAngleRateY(){
  return angle_rate_estimate[1];
};
double Fusion::getAngleRateZ(){
  return angle_rate_estimate[2];
};

void Fusion::setAngleRateX(double new_angle_rate_x){
  angle_rate_estimate[0]=new_angle_rate_x;
};
void Fusion::setAngleRateY(double new_angle_rate_y){
  angle_rate_estimate[1]=new_angle_rate_y;
};
void Fusion::setAngleRateZ(double new_angle_rate_z){
  angle_rate_estimate[2]=new_angle_rate_z;
};

//Accessors and mutators for magnetic measurements
double Fusion::getMagneticMeasurementX(){
  return magnetic_measurement[0];
};
double Fusion::getMagneticMeasurementY(){
  return magnetic_measurement[1];
};
double Fusion::getMagneticMeasurementZ(){
  return magnetic_measurement[2];
};

void Fusion::setMagneticMeasurementX(double new_mag_x){
  magnetic_measurement[0] = new_mag_x;
};
void Fusion::setMagneticMeasurementY(double new_mag_y){
  magnetic_measurement[1] = new_mag_y;
};
void Fusion::setMagneticMeasurementZ(double new_mag_z){
  magnetic_measurement[2] = new_mag_z;
};


//Accessors and mutators for angular rate measurements
double Fusion::getAngularRateMeasurementX(){
  return angular_rate_measurement[0];
};
double Fusion::getAngularRateMeasurementY(){
  return angular_rate_measurement[1];
};
double Fusion::getAngularRateMeasurementZ(){
  return angular_rate_measurement[2];
};

void Fusion::setAngularRateMeasurementX(double new_angular_x){
  angular_rate_measurement[0] = new_angular_x;
};
void Fusion::setAngularRateMeasurementY(double new_angular_y){
  angular_rate_measurement[1] = new_angular_y;
};
void Fusion::setAngularRateMeasurementZ(double new_angular_z){
  angular_rate_measurement[2] = new_angular_z;
};


//Accessors and mutators for acceleration measurements
double Fusion::getAccelerationMeasurementX(){
  return acceleration_measurement[0];
};
double Fusion::getAccelerationMeasurementY(){
  return acceleration_measurement[1];
};
double Fusion::getAccelerationMeasurementZ(){
  return acceleration_measurement[2];
};

void Fusion::setAccelerationMeasurementX(double new_acceleration_x){
  acceleration_measurement[0] = new_acceleration_x;
};
void Fusion::setAccelerationMeasurementY(double new_acceleration_y){
  acceleration_measurement[1] = new_acceleration_y;
};
void Fusion::setAccelerationMeasurementZ(double new_acceleration_z){
  acceleration_measurement[2] = new_acceleration_z;
};


//Accessors and mutators for external pressure measurement
double Fusion::getExternalPressureMeasurement(){
  return external_pressure_measurement;
};
void Fusion::setExternalPressureMeasurement(double new_external_pressure){
  external_pressure_measurement = new_external_pressure;
};

//Accessors and mutators for internal pressure measurements
double Fusion::getInternalPressureMeasurement(){
  return internal_pressure_measurement;
};
void Fusion::setInternalPressureMeasurement(double new_internal_pressure){
  internal_pressure_measurement = new_internal_pressure;
};



// callbacks
void Fusion::configCallback(liurov::fusionConfig &update, uint32_t level) {
  ROS_INFO("Reconfigure request received in Fusion Node");
  config = update;
};
void Fusion::sensorDataCallback(const std_msgs::Float64MultiArray::ConstPtr& new_sensor_data){
  setAccelerationMeasurementX(new_sensor_data->data[0]);
  setAccelerationMeasurementY(new_sensor_data->data[1]);
  setAccelerationMeasurementZ(new_sensor_data->data[2]);

  setAngularRateMeasurementX(new_sensor_data->data[3]);
  setAngularRateMeasurementY(new_sensor_data->data[4]);
  setAngularRateMeasurementZ(new_sensor_data->data[5]);





};
void Fusion::spin() {
  //loads the rate variable from the config file.
  // may need to move
  ros::Rate rate(config.pub_rate);

  while(ros::ok()) {
    // call all waiting callbacks
    ros::spinOnce();
    // enforce a max publish rate
    // measurement update here
    // timeupdate here
    // ros::spinOnce();;
    rate.sleep();
  }
};


int main(int argc, char** argv) {
  ros::init(argc, argv, "fusion");
  Fusion fusion;

  fusion.spin();
  return 0;
};
