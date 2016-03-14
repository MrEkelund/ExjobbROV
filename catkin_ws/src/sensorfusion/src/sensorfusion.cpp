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
  states_pub = node_handle.advertise<std_msgs::Float64MultiArray>("/sensor_fusion/states", 50);
  state_message.data.resize(10);

  setInitiaMeasurements();
  p=p0;
  states = initial_states;
  normQuaternions();

  new_mag_data = false;
  new_imu_data = false;
  new_pressure_data = false;

  imu_first_data = true;

  any_updates = false;

}

void Ekf::restartFilter(){
  setInitiaMeasurements();
  p=p0;
  states = initial_states;
  normQuaternions();
  new_mag_data = false;
  new_imu_data = false;
  new_pressure_data = false;

  imu_first_data = true;

  any_updates = false;
}

//what to do when i configure request is received
void Ekf::configCallback(sensorfusion::ekfConfig &update, uint level){
  //since some parameters from the parameter server are parts of matrices,
  // we need to update the config and put the parameters in their respective matrix.
  ROS_INFO("Reconfigure request received");
  config=update;
  setRMag();
  setRAcc();
  setRPressure();
  setQ();
  setInitialStates();
  setP0();

}

void Ekf::setRMag(){
  r_mag(0,0) = config.r_mag_00;
  r_mag(0,1) = 0.0;
  r_mag(0,2) = 0.0;

  r_mag(1,0) = 0.0;
  r_mag(1,1) = config.r_mag_11;
  r_mag(1,2) = 0.0;

  r_mag(2,0) = 0.0;
  r_mag(2,1) = 0.0;
  r_mag(2,2) = config.r_mag_22;
}


void Ekf::setRAcc(){
  r_acc(0,0) = config.r_acc_00;
  r_acc(0,1) = 0.0;
  r_acc(0,2) = 0.0;

  r_acc(1,0) = 0.0;
  r_acc(1,1) = config.r_acc_11;
  r_acc(1,2) = 0.0;

  r_acc(2,0) = 0.0;
  r_acc(2,1) = 0.0;
  r_acc(2,2) = config.r_acc_22;
}

void Ekf::setRPressure(){
  r_pressure(0,0) = config.r_pressure;
}

void Ekf::setQ(){
  q(0,0) = config.q_00;
  q(0,1) = 0.0;
  q(0,2) = 0.0;
  q(0,3) = 0.0;

  q(1,0) = 0.0;
  q(1,1) = config.q_11;
  q(1,2) = 0.0;
  q(1,3) = 0.0;

  q(2,0) = 0.0;
  q(2,1) = 0.0;
  q(2,2) = config.q_22;
  q(2,3) = 0.0;

  q(3,0) = 0.0;
  q(3,1) = 0.0;
  q(3,2) = 0.0;
  q(3,3) = config.q_33;
}

void Ekf::setInitialStates(){
  initial_states(0) = config.initial_q0;
  initial_states(1) = config.initial_q1;
  initial_states(2) = config.initial_q2;
  initial_states(3) = config.initial_q3;
  initial_states(4) = config.initial_d;
}

void Ekf::setInitiaMeasurements(){
  omega(0) = 0.0;
  omega(1) = 0.0;
  omega(2) = 0.0;

  meas_mag(0) = 0.0;
  meas_mag(1) = 0.0;
  meas_mag(2) = 0.0;

  meas_acc(0) = 0.0;
  meas_acc(1) = 0.0;
  meas_acc(2) = 0.0;

  meas_pressure(0) = 0.0;
}

void Ekf::setP0(){
  p0(0,0) = config.p0_00;
  p0(0,1) = 0.0;
  p0(0,2) = 0.0;
  p0(0,3) = 0.0;
  p0(0,4) = 0.0;

  p0(1,0) = 0.0;
  p0(1,1) = config.p0_11;
  p0(1,2) = 0.0;
  p0(1,3) = 0.0;
  p0(1,4) = 0.0;

  p0(2,0) = 0.0;
  p0(2,1) = 0.0;
  p0(2,2) = config.p0_22;
  p0(2,3) = 0.0;
  p0(2,4) = 0.0;

  p0(3,0) = 0.0;
  p0(3,1) = 0.0;
  p0(3,2) = 0.0;
  p0(3,3) = config.p0_33;
  p0(3,4) = 0.0;

  p0(4,0) = 0.0;
  p0(4,1) = 0.0;
  p0(4,2) = 0.0;
  p0(4,3) = 0.0;
  p0(4,4) = config.p0_44;

}


void Ekf::pressureUpdate()
{
  if(config.enable_pressure_update && (meas_pressure(0) > 0))
  {
    //std::cout << "Pressure update" << std::endl;
    //read states
    double q0 = states(0); double q1 = states(1);
    double q2 = states(2); double q3 = states(3);
    double d = states(4); //depth
    double g = config.g;

    double rho = config.rho;
    double x_offset = config.x_offset;
    Eigen::Matrix<double, 1, 1> h_pressure;

    h_pressure(0) = g*rho*(d - x_offset*(2*q0*q2 - 2*q1*q3));

    //generated via script in matlab
    Eigen::Matrix<double, 1, 5> H_pressure;
    H_pressure(0,0) = -2*g*q2*rho*x_offset;
    H_pressure(0,1) = 2*g*q3*rho*x_offset;
    H_pressure(0,2) = -2*g*q0*rho*x_offset;
    H_pressure(0,3) = 2*g*q1*rho*x_offset;
    H_pressure(0,4) = g*rho;

    Eigen::Matrix<double, 1, 1> innovation = meas_pressure - h_pressure;
    Eigen::Matrix<double, 5, 1> k = p*H_pressure.transpose()*((H_pressure*p*H_pressure.transpose() + r_pressure).inverse());

    Eigen::Matrix<double, 5, 1> new_states = states + k*innovation;
    states = new_states;

    Eigen::Matrix<double, 5, 5> p_new = p - k*H_pressure*p;
    p = p_new;
    normQuaternions();
    any_updates = true;
  }

}
//Calculation of h and H matrix for accelerometer measurement update
void Ekf::accUpdate(){
  double g = config.g;

  if (config.enable_acceleration_update && (abs(meas_acc.norm() - g) < config.eps_acc)) {
    //std::cout << "Acc update" << std::endl;
    //read states
    double q0 = states(0); double q1 = states(1);
    double q2 = states(2); double q3 = states(3);
    double d = states(4); //depth

    // calculate predicted measurements
    Eigen::Matrix<double, 3, 1> h_acc;
    h_acc(0)  = g*(q0*q2*2.0-q1*q3*2.0);
    h_acc(1)  = -g*(q0*q1*2.0+q2*q3*2.0);
    h_acc(2)  = -g*((q0*q0)*2.0+(q3*q3)*2.0-1.0);

    //generated via script in matlab
    Eigen::Matrix<double, 3, 5> H_acc;
    H_acc(0,0) = 2*g*q2; H_acc(0,1) = -2*g*q3; H_acc(0,2) =  2*g*q0; H_acc(0,3) = -2*g*q1, H_acc(0,4) = 0.0;
    H_acc(1,0) = -2*g*q1; H_acc(1,1) = -2*g*q0;  H_acc(1,2) = -2*g*q3; H_acc(1,3) = -2*g*q2;  H_acc(1,4) = 0.0;
    H_acc(2,0) = -4*g*q0; H_acc(2,1) = 0.0; H_acc(2,2) = 0.0;  H_acc(2,3) = -4*g*q3,H_acc(2,4) = 0.0;


    Eigen::Matrix<double, 3, 1> innovation = meas_acc - h_acc;
    Eigen::Matrix<double, 5, 3> k = p*H_acc.transpose()*((H_acc*p*H_acc.transpose() + r_acc).inverse());

    Eigen::Matrix<double, 5, 1> new_states = states + k*innovation;
    states = new_states;

    Eigen::Matrix<double, 5, 5> p_new = p - k*H_acc*p;
    p = p_new;
    normQuaternions();
    any_updates = true;
  }
}

//Calculation of h and H matrix for magnetometer measurement update
void Ekf::magUpdate(){
  double mag_n = config.mag_n;
  double mag_e = config.mag_e;
  double mag_d = config.mag_d;

  if (config.enable_magnetometer_update && (abs(meas_mag.norm() - sqrt(mag_n*mag_n + mag_e*mag_e + mag_d*mag_d)) < config.eps_mag)) {
    std::cout << "Mag update" << std::endl;
    //read states
    double q0 = states(0); double q1 = states(1);
    double q2 = states(2); double q3 = states(3);
    double d = states(4); //depth


    Eigen::Matrix<double, 3, 1> h_mag;
    // calculate predicted measurements
    h_mag(0)= sqrt(mag_e*mag_e+mag_n*mag_n)*((q0*q0)*2.0+(q1*q1)*2.0-1.0)-mag_d*(q0*q2*2.0-q1*q3*2.0);
    h_mag(1)= -(q0*q3*2.0-q1*q2*2.0)*sqrt(mag_e*mag_e+mag_n*mag_n)+mag_d*(q0*q1*2.0+q2*q3*2.0);
    h_mag(2)= mag_d*((q0*q0)*2.0+(q3*q3)*2.0-1.0)+(q0*q2*2.0+q1*q3*2.0)*sqrt(mag_e*mag_e+mag_n*mag_n);

    Eigen::Matrix<double, 3, 5> H_mag;
    H_mag(0,0) = q0*sqrt(mag_e*mag_e+mag_n*mag_n)*4.0-mag_d*q2*2.0;
    H_mag(0,1) = q1*sqrt(mag_e*mag_e+mag_n*mag_n)*4.0+mag_d*q3*2.0;
    H_mag(0,3) = mag_d*q0*-2.0;
    H_mag(0,3) = mag_d*q1*2.0;
    H_mag(0,4) = 0.0;

    H_mag(1,0) = q3*sqrt(mag_e*mag_e+mag_n*mag_n)*-2.0+mag_d*q1*2.0;
    H_mag(1,1) = q2*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0+mag_d*q0*2.0;
    H_mag(1,2) = q1*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0+mag_d*q3*2.0;
    H_mag(1,3) = q0*sqrt(mag_e*mag_e+mag_n*mag_n)*-2.0+mag_d*q2*2.0;
    H_mag(1,4) = 0.0;

    H_mag(2,0) = q2*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0+mag_d*q0*4.0;
    H_mag(2,1) = q3*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0;
    H_mag(2,2) = q0*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0;
    H_mag(2,3) = q1*sqrt(mag_e*mag_e+mag_n*mag_n)*2.0+mag_d*q3*4.0;
    H_mag(2,4) = 0.0;

    Eigen::Matrix<double, 3, 1> innovation = meas_mag - h_mag;
    Eigen::Matrix<double, 5, 3> k = p*H_mag.transpose()*((H_mag*p*H_mag.transpose() + r_mag).inverse());

    Eigen::Matrix<double, 5, 1> new_states = states + k*innovation;
    states = new_states;

    Eigen::Matrix<double, 5, 5> p_new = p - k*H_mag*p;
    p = p_new;
    std::cout << p << std::endl;
    normQuaternions();
    any_updates = true;
  }
}
void Ekf::timeUpdate(double T){
  //read states
  if(config.enable_time_update){
    //std::cout << "Time update" << std::endl;
    //std::cout << "T = " << T << std::endl;
    double q0 = states(0); double q1 = states(1);
    double q2 = states(2); double q3 = states(3);
    double wx = omega(0); double wy = omega(1); double wz = omega(2);
    //calculate f matrix
    f(0,0) = 1.0;
    f(0,1) = T*wx*(-1.0/2.0);
    f(0,2) = T*wy*(-1.0/2.0);
    f(0,3) = T*wz*(-1.0/2.0);
    f(0,4) = 0.0;

    f(1,0) = T*wx*(1.0/2.0);
    f(1,1) = 1.0;
    f(1,2) = T*wz*(1.0/2.0);
    f(1,3) = T*wy*(-1.0/2.0);
    f(1,4) = 0.0;

    f(2,0) = T*wy*(1.0/2.0);
    f(2,1) = T*wz*(-1.0/2.0);
    f(2,2) = 1.0;
    f(2,3) = T*wx*(1.0/2.0);
    f(2,4) = 0.0;

    f(3,0) = T*wz*(1.0/2.0);
    f(3,1) = T*wy*(1.0/2.0);
    f(3,2) = T*wx*(-1.0/2.0);
    f(3,3) = 1.0;
    f(3,4) = 0.0;

    f(4,0) = 0.0;
    f(4,1) = 0.0;
    f(4,2) = 0.0;
    f(4,3) = 0.0;
    f(4,4) = 1.0;


    //calculate gv matrix
    gv(0,0) = T*q1*(-1.0/2.0);
    gv(0,1) = T*q2*(-1.0/2.0);
    gv(0,2) = T*q3*(-1.0/2.0);
    gv(0,3) = 0.0;

    gv(1,0) = T*q0*(1.0/2.0);
    gv(1,1) = T*q3*(-1.0/2.0);
    gv(1,2) = T*q2*(1.0/2.0);
    gv(1,3) = 0.0;

    gv(2,0) = T*q3*(1.0/2.0);
    gv(2,1) = T*q0*(1.0/2.0);
    gv(2,2) = T*q1*(-1.0/2.0);
    gv(2,3) = 0;

    gv(3,0) = T*q2*(-1.0/2.0);
    gv(3,1) = T*q1*(1.0/2.0);
    gv(3,2) = T*q0*(1.0/2.0);
    gv(3,3) = 0.0;

    gv(4,0) = 0.0;
    gv(4,1) = 0.0;
    gv(4,2) = 0.0;
    gv(4,3) = 1.0;

    // time update
    Eigen::Matrix<double, 5, 1> new_states = f*states;
    states = new_states;

    //update P
    Eigen::Matrix<double, 5, 5> p_new = f*p*f.transpose() + gv*q*gv.transpose();
    p  = p_new;
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
    omega(0) = imu_msg.data[1]; //get omega x [rad/s]
    omega(1) = imu_msg.data[2]; //get omega y
    omega(2) = imu_msg.data[3]; //get omega z
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
  double q0 = states(0); double q1 = states(1);
  double q2 = states(2); double q3 = states(3);
  double d = states(4); //depth

  //calc yaw pitch roll
  double yaw = atan2(2.0*q0*q3+2.0*q1*q2,1.0-2.0*(q2*q2 + q3*q3));
  double pitch = asin(2.0*(q0*q2-q3*q1));
  double roll = atan2(2.0*q0*q1+2.0*q2*q3,1.0-2.0*(q1*q1 + q2*q2));

  // remove extra 2p
  yaw = fmod(yaw + M_PI,2.0*M_PI) - M_PI;
  pitch= fmod(pitch + M_PI,2.0*M_PI) - M_PI;
  roll = fmod(roll + M_PI,2.0*M_PI) - M_PI;

  state_message.data.resize(10);
  // convert to correct format and send
  state_message.data[0] = yaw*180.0/M_PI;
  state_message.data[1] = pitch*180.0/M_PI;
  state_message.data[2] = roll*180.0/M_PI;
  state_message.data[3] = omega(0)*180.0/M_PI;
  state_message.data[4] = omega(1)*180.0/M_PI;
  state_message.data[5] = omega(2)*180.0/M_PI;
  state_message.data[6] = d;
  state_message.data[7] = meas_acc(0);
  state_message.data[8] = meas_acc(1);
  state_message.data[9] = meas_acc(2);
  states_pub.publish(state_message);
  any_updates = false;

}

void Ekf::spin(){
  ros::Rate rate(150.);
  while(ros::ok())
  {
    ros::spinOnce();
    if(new_imu_data)
    {
      timeUpdate(delta_t);
      accUpdate();
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

    rate.sleep();
  }

}

int main(int argc, char **argv){
  ros::init(argc, argv, "Sensor_fusion_node");
  Ekf ekf;
  ekf.spin();
}
