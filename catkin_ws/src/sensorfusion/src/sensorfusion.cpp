#include "sensorfusion.h"
Ekf::Ekf(){
  // connect dynamic reconfigure
  dynamic_reconfigure::Server<sensorfusion::ekfConfig>::CallbackType f;
  f = boost::bind(&Ekf::configCallback, this, _1, _2);
  server.setCallback(f);
  initFilter();
}
void Ekf::initFilter(){
  imu_data_sub = node_handle.subscribe("/rovio/imu/data", 20, &Ekf::imuCallback,this);
  pressure_data_sub = node_handle.subscribe("/rovio/water_pressure/data", 20, &Ekf::pressureCallback,this);
  mag_data_sub = node_handle.subscribe("/rovio/magnetometer/data", 20, &Ekf::magCallback,this);
  restart_sub = node_handle.subscribe("/sensor_fusion/restart",10, &Ekf::restartCallback,this);
  calibrate_mag_sub = node_handle.subscribe("/sensor_fusion/calibrate_mag",10,&Ekf::calibrateMagCallback,this);
  states_pub = node_handle.advertise<std_msgs::Float64MultiArray>("/sensor_fusion/states", 50);
  state_message.data.resize(10);

  setInitiaMeasurements();
  state_cov = initial_state_cov;
  states = initial_states;
  normQuaternions();

  new_mag_data = false;
  new_imu_data = false;
  new_pressure_data = false;
  imu_first_data = true;
  any_updates = false;

  mag_n = 1000;
  mag_e = 1000;
  mag_d = 1000;
}
void Ekf::restartFilter(){
  setInitiaMeasurements();
  state_cov = initial_state_cov;
  states = initial_states;
  normQuaternions();
  new_mag_data = false;
  new_imu_data = false;
  new_pressure_data = false;
  imu_first_data = true;
  any_updates = false;
}
void Ekf::calibrateMagCallback(const std_msgs::Bool &msg){
  mag_n = meas_mag(0);
  mag_e = meas_mag(1);
  mag_d = meas_mag(2);
  ROS_INFO("Calibrated mag to %f uT %f uT %f uT", mag_n, mag_e, mag_d);
}
void Ekf::configCallback(sensorfusion::ekfConfig &update, uint level){
  //since some parameters from the parameter server are parts of matrices,
  // we need to update the config and put the parameters in their respective matrix.
  ROS_INFO("Reconfigure request received");
  config=update;
  setCovMag();
  setCovAcc();
  setCovPressure();
  setCovGyro();
  setProcessCov();
  setInitialStates();
  setInitialStateCov();

}
void Ekf::restartCallback(const std_msgs::Bool &msg){
 restartFilter();
}
void Ekf::setCovMag(){
  cov_mag.setZero();
  cov_mag(0,0) = config.cov_mag_x;
  cov_mag(1,1) = config.cov_mag_y;
  cov_mag(2,2) = config.cov_mag_z;
}
void Ekf::setCovAcc(){
  cov_acc.setZero();
  cov_acc(0,0) = config.cov_acc_x;
  cov_acc(1,1) = config.cov_acc_y;
  cov_acc(2,2) = config.cov_acc_z;
  // cov_acc(0,1) = 0.0;
  // cov_acc(0,2) = 0.0;
  //
  // cov_acc(1,0) = 0.0;
  //
  // cov_acc(1,2) = 0.0;
  //
  // cov_acc(2,0) = 0.0;
  // cov_acc(2,1) = 0.0;

}
void Ekf::setCovPressure(){
  cov_pressure(0,0) = config.cov_pressure;
}
void Ekf::setCovGyro(){
  cov_gyro.setZero();
  cov_gyro(0,0) = config.cov_gyro_x;
  cov_gyro(1,1) = config.cov_gyro_x;
  cov_gyro(2,2) = config.cov_gyro_x;
}
void Ekf::setProcessCov(){
  process_cov.setZero();
  process_cov(0,0) = config.process_cov_p;
  process_cov(1,1) = config.process_cov_q;
  process_cov(2,2) = config.process_cov_r;
  process_cov(3,3) = config.process_cov_bias_p;
  process_cov(4,4) = config.process_cov_bias_q;
  process_cov(5,5) = config.process_cov_bias_r;
  process_cov(6,6) = config.process_cov_d;

}
void Ekf::setInitialStates(){
  // no need to set idividual states
  initial_states.setZero();
  initial_states(0) = 1;
}
void Ekf::setInitiaMeasurements(){
  // make sure matrices are defined
  meas_gyro.setZero();
  meas_mag.setZero();
  meas_acc.setZero();
  meas_pressure.setZero();
}
void Ekf::setInitialStateCov(){
  // rename P0 starting_state_cov and  P0_11 to respective state+cov
  initial_state_cov.setZero();
  initial_state_cov(0,0) = config.initial_cov_quat_0;
  initial_state_cov(1,1) = config.initial_cov_quat_1;
  initial_state_cov(2,2) = config.initial_cov_quat_2;
  initial_state_cov(3,3) = config.initial_cov_quat_3;
  initial_state_cov(4,4) = config.initial_cov_p;
  initial_state_cov(5,5) = config.initial_cov_q;
  initial_state_cov(6,6) = config.initial_cov_r;
  initial_state_cov(7,7) = config.initial_cov_bias_p;
  initial_state_cov(8,8) = config.initial_cov_bias_q;
  initial_state_cov(9,9) = config.initial_cov_bias_r;
  initial_state_cov(10,10) = config.initial_cov_d;
}
void Ekf::calcHPressure(){
  H_pressure.setZero();
  H_pressure.setZero();
  double quat_0 = states(0); double quat_1 = states(1);
  double quat_2 = states(2); double quat_3 = states(3);
  double d = states(10);
  double rho = config.rho; double x_offset = config.x_offset;
  double g = config.g;

  H_pressure(0,0) = g*quat_2*rho*x_offset*-2.0;
  H_pressure(0,1) = g*quat_3*rho*x_offset*2.0;
  H_pressure(0,2) = g*quat_0*rho*x_offset*-2.0;
  H_pressure(0,3) = g*quat_1*rho*x_offset*2.0;
  H_pressure(0,10) = g*rho;

  h_pressure(0,0) = g*rho*(d-x_offset*(quat_0*quat_2*2.0-quat_1*quat_3*2.0));
}
void Ekf::pressureUpdate(){
  if(config.enable_pressure_update && (meas_pressure(0) > 0))
  {
    Eigen::Matrix<double, 11, 1> k;
    Eigen::Matrix<double, 1, 1> innovation;
    calcHPressure();

    innovation = meas_pressure - h_pressure;
    k = state_cov*H_pressure.transpose()*((H_pressure*state_cov*H_pressure.transpose() + cov_pressure).inverse());

    new_states = states + k*innovation;
    states = new_states;

    new_state_cov = state_cov - k*H_pressure*state_cov;
    state_cov = new_state_cov/2 + new_state_cov.transpose()/2;
    normQuaternions();
    any_updates = true;
  }

}
void Ekf::calcHAcc(){
  H_acc.setZero();
  h_acc.setZero();
  double quat_0 = states(0); double quat_1 = states(1);
  double quat_2 = states(2); double quat_3 = states(3);
  double g = config.g;
  // derivative of measurement eq:s with respect to states
  H_acc(0,0) = g*quat_2*2.0;
  H_acc(0,1) = g*quat_3*-2.0;
  H_acc(0,2) = g*quat_0*2.0;
  H_acc(0,3) = g*quat_1*-2.0;
  H_acc(1,0) = g*quat_1*-2.0;
  H_acc(1,1) = g*quat_0*-2.0;
  H_acc(1,2) = g*quat_3*-2.0;
  H_acc(1,3) = g*quat_2*-2.0;
  H_acc(2,0) = g*quat_0*-4.0;
  H_acc(2,3) = g*quat_3*-4.0;

  //measurement eq
  h_acc(0,0) = g*(quat_0*quat_2*2.0-quat_1*quat_3*2.0);
  h_acc(1,0) = -g*(quat_0*quat_1*2.0+quat_2*quat_3*2.0);
  h_acc(2,0) = -g*((quat_0*quat_0)*2.0+(quat_3*quat_3)*2.0-1.0);

}
void Ekf::accUpdate(){
  if (config.enable_acceleration_update && (abs(meas_acc.norm() - config.g) < config.eps_acc)) {
    calcHAcc();
    Eigen::Matrix<double, 3, 1> innovation;
    Eigen::Matrix<double, 11, 3> k;

    innovation = meas_acc - h_acc;
    k = state_cov*H_acc.transpose()*((H_acc*state_cov*H_acc.transpose() + cov_acc).inverse());
    new_states = states + k*innovation;
    states = new_states;
    new_state_cov = state_cov - k*H_acc*state_cov;
    state_cov = new_state_cov/2 + new_state_cov.transpose()/2;

    normQuaternions();
    any_updates = true;
  }
}
void Ekf::calcHMag(){
  H_mag.setZero();
  h_mag.setZero();
  double quat_0 = states(0); double quat_1 = states(1);
  double quat_2 = states(2); double quat_3 = states(3);
  H_mag(0,0) = quat_0*sqrt(mag_e*mag_e+mag_n*mag_n)*4.0-mag_d*quat_2*2.0;
  H_mag(0,1) = quat_1*sqrt(mag_e*mag_e+mag_n*mag_n)*4.0+mag_d*quat_3*2.0;
  H_mag(0,2) = mag_d*quat_0*-2.0;
  H_mag(0,3) = mag_d*quat_1*2.0;
  H_mag(1,0) = quat_3*sqrt(mag_e*mag_e+mag_n*mag_n)*-2.0+mag_d*quat_1*2.0;
  H_mag(1,1) = quat_2*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0+mag_d*quat_0*2.0;
  H_mag(1,2) = quat_1*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0+mag_d*quat_3*2.0;
  H_mag(1,3) = quat_0*sqrt(mag_e*mag_e+mag_n*mag_n)*-2.0+mag_d*quat_2*2.0;
  H_mag(2,0) = quat_2*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0+mag_d*quat_0*4.0;
  H_mag(2,1) = quat_3*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0;
  H_mag(2,2) = quat_0*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0;
  H_mag(2,3) = quat_1*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0+mag_d*quat_3*4.0;

  h_mag(0,0) = sqrt(mag_e*mag_e+mag_n*mag_n)*((quat_0*quat_0)*2.0+(quat_1*quat_1)*2.0-1.0)-mag_d*(quat_0*quat_2*2.0-quat_1*quat_3*2.0);
  h_mag(1,0) = -(quat_0*quat_3*2.0-quat_1*quat_2*2.0)*sqrt(mag_e*mag_e+mag_n*mag_n)+mag_d*(quat_0*quat_1*2.0+quat_2*quat_3*2.0);
  h_mag(2,0) = mag_d*((quat_0*quat_0)*2.0+(quat_3*quat_3)*2.0-1.0)+(quat_0*quat_2*2.0+quat_1*quat_3*2.0)*sqrt(mag_e*mag_e+mag_n*mag_n);
}
void Ekf::magUpdate(){
  if (config.enable_magnetometer_update && (abs(meas_mag.norm() - sqrt(mag_n*mag_n + mag_e*mag_e + mag_d*mag_d)) < config.eps_mag)) {
    calcHMag();
    Eigen::Matrix<double, 3, 1> innovation;
    Eigen::Matrix<double, 11, 3> k;

    innovation = meas_mag - h_mag;
    k = state_cov*H_mag.transpose()*((H_mag*state_cov*H_mag.transpose() + cov_mag).inverse());
    new_states = states + k*innovation;
    states = new_states;
    new_state_cov = state_cov - k*H_mag*state_cov;

    state_cov = new_state_cov/2 + new_state_cov.transpose()/2;
    normQuaternions();
    any_updates = true;
  }
}
void Ekf::calcHGyro(){
  H_gyro.setZero();
  h_gyro.setZero();
  double p = states(4); double q = states(5); double r = states(6);
  double bias_p = states(7); double bias_q = states(8); double bias_r = states(9);
  H_gyro(0,4) = 1.0;
  H_gyro(0,7) = 1.0;
  H_gyro(1,5) = 1.0;
  H_gyro(1,8) = 1.0;
  H_gyro(2,6) = 1.0;
  H_gyro(2,9) = 1.0;

  h_gyro(0,0) = bias_p + p;
  h_gyro(1,0) = bias_q + q;
  h_gyro(2,0) = bias_r + r;
}
void Ekf::gyroUpdate(){
  if (config.enable_gyro_update){
    calcHGyro();
    Eigen::Matrix<double, 3, 1> innovation;
    Eigen::Matrix<double, 11, 3> k;

    innovation = meas_gyro - h_gyro;
    k = state_cov*H_gyro.transpose()*((H_gyro*state_cov*H_gyro.transpose() + cov_gyro).inverse());
    new_states = states + k*innovation;
    states = new_states;
    new_state_cov = state_cov - k*H_gyro*state_cov;


    state_cov = new_state_cov/2 + new_state_cov.transpose()/2;
    normQuaternions();
    any_updates = true;
  }
}
void Ekf::calcF(){
  F.setZero();
  double quat_0 = states(0); double quat_1 = states(1); double quat_2 = states(2);
  double quat_3 = states(3); double p = states(4); double q = states(5); double r = states(6);
  F(0,0) = 1.0;
  F(0,1) = delta_t*p*(-1.0/2.0);
  F(0,2) = delta_t*q*(-1.0/2.0);
  F(0,3) = delta_t*r*(-1.0/2.0);
  F(0,4) = (delta_t*delta_t)*quat_1*(-1.0/2.0);
  F(0,5) = (delta_t*delta_t)*quat_2*(-1.0/2.0);
  F(0,6) = (delta_t*delta_t)*quat_3*(-1.0/2.0);
  F(1,0) = delta_t*p*(1.0/2.0);
  F(1,1) = 1.0;
  F(1,2) = delta_t*r*(1.0/2.0);
  F(1,3) = delta_t*q*(-1.0/2.0);
  F(1,4) = (delta_t*delta_t)*quat_0*(1.0/2.0);
  F(1,5) = (delta_t*delta_t)*quat_3*(-1.0/2.0);
  F(1,6) = (delta_t*delta_t)*quat_2*(1.0/2.0);
  F(2,0) = delta_t*q*(1.0/2.0);
  F(2,1) = delta_t*r*(-1.0/2.0);
  F(2,2) = 1.0;
  F(2,3) = delta_t*p*(1.0/2.0);
  F(2,4) = (delta_t*delta_t)*quat_3*(1.0/2.0);
  F(2,5) = (delta_t*delta_t)*quat_0*(1.0/2.0);
  F(2,6) = (delta_t*delta_t)*quat_1*(-1.0/2.0);
  F(3,0) = delta_t*r*(1.0/2.0);
  F(3,1) = delta_t*q*(1.0/2.0);
  F(3,2) = delta_t*p*(-1.0/2.0);
  F(3,3) = 1.0;
  F(3,4) = (delta_t*delta_t)*quat_2*(-1.0/2.0);
  F(3,5) = (delta_t*delta_t)*quat_1*(1.0/2.0);
  F(3,6) = (delta_t*delta_t)*quat_0*(1.0/2.0);
  F(4,4) = 1.0;
  F(5,5) = 1.0;
  F(6,6) = 1.0;
  F(7,7) = 1.0;
  F(8,8) = 1.0;
  F(9,9) = 1.0;
  F(10,10) = 1.0;
}
void Ekf::calcGv(){
  Gv.setZero();
  double quat_0 = states(0); double quat_1 = states(1); double quat_2 = states(2);
  double quat_3 = states(3);
  Gv(0,0) = (delta_t*delta_t*delta_t)*quat_1*(-1.0/4.0);
  Gv(0,1) = (delta_t*delta_t*delta_t)*quat_2*(-1.0/4.0);
  Gv(0,2) = (delta_t*delta_t*delta_t)*quat_3*(-1.0/4.0);
  Gv(1,0) = (delta_t*delta_t*delta_t)*quat_0*(1.0/4.0);
  Gv(1,1) = (delta_t*delta_t*delta_t)*quat_3*(-1.0/4.0);
  Gv(1,2) = (delta_t*delta_t*delta_t)*quat_2*(1.0/4.0);
  Gv(2,0) = (delta_t*delta_t*delta_t)*quat_3*(1.0/4.0);
  Gv(2,1) = (delta_t*delta_t*delta_t)*quat_0*(1.0/4.0);
  Gv(2,2) = (delta_t*delta_t*delta_t)*quat_1*(-1.0/4.0);
  Gv(3,0) = (delta_t*delta_t*delta_t)*quat_2*(-1.0/4.0);
  Gv(3,1) = (delta_t*delta_t*delta_t)*quat_1*(1.0/4.0);
  Gv(3,2) = (delta_t*delta_t*delta_t)*quat_0*(1.0/4.0);
  Gv(4,0) = delta_t;
  Gv(5,1) = delta_t;
  Gv(6,2) = delta_t;
  Gv(7,3) = delta_t;
  Gv(8,4) = delta_t;
  Gv(9,5) = delta_t;
  Gv(10,6) = delta_t;
}
void Ekf::timeUpdate(){
  //read states
  if(config.enable_time_update){
    //calculate f matrix
    calcF();
    calcGv();
    // Calculate new state
    new_states = F*states;
    states = new_states;
    normQuaternions();
    //update state covariance
    new_state_cov = F*state_cov*F.transpose() + Gv*process_cov*Gv.transpose();

    state_cov = new_state_cov/2 + new_state_cov.transpose()/2;
    any_updates = true;
  }
}
void Ekf::normQuaternions(){
  Eigen::Matrix<double, 4, 1>store;
  store(0) = states(0);
  store(1) = states(1);
  store(2) = states(2);
  store(3) = states(3);
  double normfactor = store.norm();

  double sign = (states(0) > 0)-(states(0) < 0);
  states(0) = states(0)*sign/normfactor;
  states(1) = states(1)*sign/normfactor;
  states(2) = states(2)*sign/normfactor;
  states(3) = states(3)*sign/normfactor;
}
void Ekf::imuCallback(const std_msgs::Float32MultiArray &imu_msg){
  if(imu_first_data)
  {
    store_t = imu_msg.data[0]/1000.0;
    imu_first_data = false;
  }
  else
  {
    delta_t  = (imu_msg.data[0]/1000.0) - store_t; // delta t is sent in [ms] and should be [s]
    store_t = (imu_msg.data[0]/1000.0);
    meas_gyro(0) = imu_msg.data[1]; //get omega x [rad/s]
    meas_gyro(1) = imu_msg.data[2]; //get omega y
    meas_gyro(2) = imu_msg.data[3]; //get omega z
    meas_acc(0) = imu_msg.data[4]; // get acc x [m/s^2]
    meas_acc(1) = imu_msg.data[5]; // get acc y
    meas_acc(2) = imu_msg.data[6]; // get acc z
    new_imu_data = true;
  }

}
void Ekf::magCallback(const std_msgs::Float32MultiArray &mag_msg){
  meas_mag(0) = mag_msg.data[0]; //get mag  x [uTesla]
  meas_mag(1) = mag_msg.data[1]; //get mag y
  meas_mag(2) = mag_msg.data[2]; //get mag z
  new_mag_data = true;
}
void Ekf::pressureCallback(const std_msgs::Float32 &pressure_msg){
  meas_pressure(0) = pressure_msg.data;
  new_pressure_data = true;
}
void Ekf::sendStates(){
  double quat_0 = states(0); double quat_1 = states(1);
  double quat_2 = states(2); double quat_3 = states(3);
  double p = states(4); double q = states(5); double r = states(6);
  double d = states(10); //depth

  //calc yaw pitch roll
  double yaw = atan2(2.0*quat_0*quat_3+2.0*quat_1*quat_2,1.0-2.0*(quat_2*quat_2 + quat_3*quat_3));
  double pitch = asin(2.0*(quat_0*quat_2-quat_3*quat_1));
  double roll = atan2(2.0*quat_0*quat_1+2.0*quat_2*quat_3,1.0-2.0*(quat_1*quat_1 + quat_2*quat_2));

  // remove extra 2p
  yaw = fmod(yaw + M_PI,2.0*M_PI) - M_PI;
  pitch= fmod(pitch + M_PI,2.0*M_PI) - M_PI;
  roll = fmod(roll + M_PI,2.0*M_PI) - M_PI;

  state_message.data.resize(10);
  // convert to correct format and send
  state_message.data[0] = roll;
  state_message.data[1] = pitch;
  state_message.data[2] = yaw;
  state_message.data[3] = p;
  state_message.data[4] = q;
  state_message.data[5] = r;
  state_message.data[6] = d;
  state_message.data[7] = meas_gyro(0);
  state_message.data[8] = meas_gyro(1);
  state_message.data[9] = meas_gyro(2);
  states_pub.publish(state_message);
  any_updates = false;

}
void Ekf::spin(){
  ros::Rate rate(300);
  while(ros::ok())
  {
    ros::spinOnce();
    if(new_imu_data)
    {
      accUpdate();
      gyroUpdate();
      timeUpdate();
      new_imu_data = false;
    }

    if(new_mag_data)
    {
      magUpdate();
      new_mag_data = false;
    }

    if(new_pressure_data)
    {
      pressureUpdate();
      new_pressure_data = false;
    }

    if(any_updates)
    {
      sendStates();
    }
    std::cout << state_cov - state_cov.transpose() << "\n"<< std::endl;
    rate.sleep();
  }

}
int main(int argc, char **argv){
  ros::init(argc, argv, "Sensorfusion");
  Ekf ekf;
  ekf.spin();
}
