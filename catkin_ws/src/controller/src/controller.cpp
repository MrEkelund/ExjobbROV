#include "controller.h"

Controller::Controller() {
  // connect dynamic reconfigure
  dynamic_reconfigure::Server<controller::controllerConfig>::CallbackType f;
  f = boost::bind(&Controller::configCallback, this, _1, _2);
  _server.setCallback(f);

  // setup subscribers and publishers
  _states_sub = _node_handle.
      subscribe("/sensor_fusion/states", 50, &Controller::stateCallback, this);
  _cmd_vel_sub = _node_handle.
      subscribe("/cmd_vel", 50, &Controller::cmdVelCallback, this);
  _dec_inc_depth_sub = _node_handle.
      subscribe("/dec_inc_depth_sub", 50, &Controller::decIncDepthCallback, this);

  _control_pub = _node_handle.
      advertise<std_msgs::UInt16MultiArray>("/rovio/thrusters", 50);
  _reference_pub = _node_handle.
      advertise<std_msgs::Float64MultiArray>("/reference", 50);
  initT();
  _ang_vel.setZero();
  _euler_angles.setZero();
  _ang_vel_ref.setZero();
  _velocity_ref.setZero();
  _euler_angles_ref.setZero();
  _depth_ref = 0;
  _T.setZero();
  _J.setZero();
  _J_dot.setZero();
  _R.setZero();
  _rate_integral.setZero();
  _attitude_integral.setZero();
  _depth_integral = 0;
  _cphi = 0;
  _cphi = 0;
  _cth = 0;
  _sth = 0;
  _tth = 1;
  _cpsi = 0;
  _spsi = 0;
  _reference_t0 = 0;
}

void Controller::initT() {
  _T << 0, 0, 1, 1, 0, 0,
  0, 0, 0, 0, 0, -1,
  -1, -1, 0, 0, -1, 0,
  ly1, -ly2, 0, 0, 0, lz6,
  lx1, lx2, 0, 0, -lx5, 0,
  0, 0, ly3, -ly4, 0, 0;
}

void Controller::calcJ() {
  _J(0,0) = 1;
  _J(0,1) = _sphi*_tth;
  _J(0,2) = _cphi*_tth;
  _J(1,0) = 0;
  _J(1,1) = _cphi;
  _J(1,2) = -_sphi;
  _J(2,0) = 0;
  _J(2,1) = _sphi/_cth;
  _J(2,2) = _cphi/_cth;
}

void Controller::calcJdot() {
  Eigen::Vector3d euler_angles_dot;

  euler_angles_dot = _J*_ang_vel;

  _J_dot(0,0) = 0;
  _J_dot(0,1) = _cphi*_tth*euler_angles_dot(0) + _sphi*(1+_tth*_tth)*euler_angles_dot(1);
  _J_dot(0,2) = -_sphi*_tth*euler_angles_dot(1)+_cphi*(1+_tth*_tth)*euler_angles_dot(1);
  _J_dot(1,0) = 0;
  _J_dot(1,1) = -_sphi*euler_angles_dot(1);
  _J_dot(1,2) = -_cphi*euler_angles_dot(1);
  _J_dot(2,0) = 0;
  _J_dot(2,1) = (_cphi*_cth*euler_angles_dot(1)+_sphi*_sth*euler_angles_dot(1))/(_cth*_cth);
  _J_dot(2,2) = (-_sphi*_cth*euler_angles_dot(1)+_cphi*_sth*euler_angles_dot(2))/(_cth*_cth);
}

// NED to body for moments
Eigen::Vector3d Controller::momentsNEDToBody(Eigen::Vector3d moments) {
  calcJ();
  calcJdot();

  return _J.inverse()*(moments - _J_dot*_ang_vel);
}

void Controller::calcR() {
  _R << _cpsi*_cth, -_spsi*_cphi+_cpsi*_sth*_sphi, _spsi*_sphi + _cpsi*_cphi*_sth,
    _spsi*_cth ,_cpsi*_cphi + _sphi*_sth*_spsi, -_cpsi*_sphi+_sth*_spsi*_cphi,
    -_sth, _cth*_sphi, _cth*_cphi;
}

// NED to body for forces
Eigen::Matrix<double, 6, 1> Controller::forcesNEDToBody(Eigen::Vector3d moments) {
  calcR();

  Eigen::Matrix<double, 6, 1> temp;
  temp << _R.transpose(), 0, 0, 0;
  return temp;
}

void Controller::calcLinControl(Eigen::Matrix<double, 6, 1>& acc, Eigen::Matrix<double, 6, 1>& control_signals) {
  Eigen::Matrix<double, 6, 1> tau;
  tau << acc(0),
  acc(1),
  acc(2),
  Ix_Kp_dot*acc(3) - _ang_vel(0)*(Kp + Kp_abs_p*abs(_ang_vel(0))) - _ang_vel(1)*_ang_vel(2)*(Iy_Mq_dot - Iz_Nr_dot) - B*_cth*_sphi*zb,
  Iy_Mq_dot*acc(4) - _ang_vel(1)*(Mq + Mq_abs_q*abs(_ang_vel(1))) - B*_sth*zb + _ang_vel(0)*_ang_vel(2)*(Ix_Kp_dot - Iz_Nr_dot),
  Iz_Nr_dot*acc(5) - _ang_vel(2)*(Nr + Nr_abs_r*abs(_ang_vel(2))) - _ang_vel(0)*_ang_vel(1)*(Ix_Kp_dot - Iy_Mq_dot);

  Eigen::Matrix<double, 6, 1> moments;
  moments = _T.inverse()*tau;

  control_signals = interpolate(moments);
}

Eigen::Matrix<double, 6, 1> Controller::interpolate(Eigen::Matrix<double, 6, 1>& moments) {
  Eigen::Matrix<double, 6, 1> control_signals;
  control_signals.setZero();
  // Saturate
  for (uint j = 0; j < 6; j++) {
    if (moments(j,0) <= thrustmap[0].x) {
      control_signals(j,0) = thrustmap[0].y;
    } else if (moments(j,0) >= thrustmap[76].x) {
      control_signals(j,0) = thrustmap[76].y;
    }
  }

  // Do linear interpolation
  for (uint j = 0; j < 6; j++) {
    // Interpolate if the control signal hasn't been set
    if (control_signals(j,0) == 0) {
      for (int i = 0; i < 76-1; i++) {
        if (thrustmap[i].x <= moments(j,0) && thrustmap[i+1].x >= moments(j,0)) {
          double diffx = moments(j,0) - thrustmap[i].x;
          double diffn = thrustmap[i+1].x - thrustmap[i].x;

          control_signals(j,0) = thrustmap[i].y + (thrustmap[i+1].y - thrustmap[i].y)*diffx/diffn;
        }
      }
    }
  }
}
//****** Reference signals ****************************************************
void Controller::calcReferenceSignals() {
  std::cout << "Phi enable: " << _config.phi_enable << std::endl;
  std::cout << "P enable: " << _config.p_enable << std::endl;
  if (_config.phi_enable) {
    switch (_config.phi_reference_signal) {
      case 1:
      std::cout << "calc step" << std::endl;
      _euler_angles_ref(0) = calcStepReference(_phi_reference);
      break;
      case 2:
      std::cout << "calc sin" << std::endl;
      _euler_angles_ref(0) = calcSinReference(_phi_reference);
      break;
      case 3:
      _euler_angles_ref(0) = _phi_reference.constant;
      break;
      default:
      _euler_angles_ref(0) = _phi_reference.constant;
      break;
    }
  } else if (_config.p_enable) {
    switch (_config.p_reference_signal) {
      case 1:
      _ang_vel_ref(0) = calcStepReference(_p_reference);
      break;
      case 2:
      _ang_vel_ref(0) = calcSinReference(_p_reference);
      break;
      case 3:
      _ang_vel_ref(0) = _p_reference.constant;
      break;
      default:
      _ang_vel_ref(0) = _p_reference.constant;
      break;
    }
  } else {
    _euler_angles_ref(0) = _euler_angles(0);
    _ang_vel_ref(0) = _ang_vel(0);
  }
}

double Controller::calcStepReference(reference_t& ref_struct) {
  double t = ros::Time::now().toNSec() - _reference_t0;
  double V = ref_struct.speed;
  double q0 = ref_struct.bias;
  double qf = ref_struct.final_value;
  double tf = ref_struct.final_time;

  double tb = (q0 - qf + V*tf)/V;
  double alfa = V/tb;

  if (0 <= t & t <= tb) {
    return q0 + alfa*t*t/2;
  } else if (tb < t & t <= tf - tb) {
    return (qf + q0 - V*tf)/2 + V*t;
  } else if (tf - tb < t & t <= tf) {
    return qf - alfa*tf*tf/2 + alfa*tf*t - alfa*t*t/2;
  } else {
    return qf;
  }
}

double Controller::calcSinReference(reference_t& ref_struct) {
  double t = ros::Time::now().toNSec() - _reference_t0;
  double frequency = ref_struct.frequency;
  double t_start = ref_struct.start_time;
  double t_final = ref_struct.final_time;
  double bias = ref_struct.bias;
  double amplitude = ref_struct.amplitude;
  bool time_reached = ref_struct.time_reached;

  if ( t < t_start ) {
    return bias;
  } else if (t <= t_final) {
    return amplitude*sin(ref_struct.frequency*(t - t_start)) + bias;
  } else if (!time_reached) { // For negating the jerk
    time_reached = true;
    ref_struct.bias = amplitude*sin(ref_struct.frequency*(t - t_start)) + bias;
    return ref_struct.bias;
  } else {
    return bias;
  }
}
//****** Callbacks ************************************************************
bool Controller::checkReferenceValues() {
  /*
  double tf = _config.reference_end_time;
  if (_config.phi_start_time > tf || _config.theta_start_time > tf ||
    _config.psi_start_time > tf || _config.p_start_time > tf ||
    _config.q_start_time > tf || _config.r_start_time > tf ||
    _config.d_start_time > tf) {
      ROS_INFO("Start time of a reference signal can't be later than the final reference time");
      return false;
    }

  if (_config.phi_final_time > tf || _config.theta_final_time > tf ||
    _config.psi_final_time > tf || _config.p_final_time > tf ||
    _config.q_final_time > tf || _config.r_final_time > tf ||
    _config.d_final_time > tf) {
      ROS_INFO("Final time of a reference signal can't be later than the final reference time");
      return false;
    }*/
  if (_config.phi_start_time >= _config.phi_final_time  ||
    _config.theta_start_time >= _config.theta_final_time ||
    _config.psi_start_time >= _config.psi_final_time ||
    _config.p_start_time >= _config.p_final_time ||
    _config.q_start_time >= _config.q_final_time ||
    _config.r_start_time >= _config.r_final_time ||
    _config.d_start_time >= _config.d_final_time) {
      ROS_INFO("Start time of a reference signal can't be later than the final time of a reference signal.");
      return false;
    }
  return true;
}

void Controller::configCallback(controller::controllerConfig &update, uint level) {
  _config = update;

  if (_config.start_reference_signals) {
    _node_handle.setParam("/start_reference_signals", false);
    if (checkReferenceValues()) {
      _reference_t0 = ros::Time::now().toNSec();
      _phi_reference.start_time = _config.phi_start_time;
      _phi_reference.amplitude = _config.phi_amplitude;
      _phi_reference.frequency = _config.phi_frequency;
      _phi_reference.bias = _euler_angles(0);
      _phi_reference.final_value = _config.phi_final_value;
      _phi_reference.final_time = _config.phi_final_time;
      _phi_reference.speed = _config.phi_speed_scaling*(
        (_phi_reference.final_value - _phi_reference.bias)/_phi_reference.final_time);
      _phi_reference.constant = _config.phi_constant;
      _phi_reference.time_reached = false;

      _theta_reference.start_time = _config.theta_start_time;
      _theta_reference.amplitude = _config.theta_amplitude;
      _theta_reference.frequency = _config.theta_frequency;
      _theta_reference.bias = _euler_angles(1);
      _theta_reference.final_value = _config.theta_final_value;
      _theta_reference.final_time = _config.theta_final_time;
      _theta_reference.speed = _config.theta_speed_scaling*(
        (_theta_reference.final_value - _theta_reference.bias)/_theta_reference.final_time);
      _theta_reference.constant = _config.theta_constant;
      _theta_reference.time_reached = false;

      _psi_reference.start_time = _config.psi_start_time;
      _psi_reference.amplitude = _config.psi_amplitude;
      _psi_reference.frequency = _config.psi_frequency;
      _psi_reference.bias = _euler_angles(2);
      _psi_reference.final_value = _config.psi_final_value;
      _psi_reference.final_time = _config.psi_final_time;
      _psi_reference.speed = _config.psi_speed_scaling*(
        (_psi_reference.final_value - _psi_reference.bias)/_psi_reference.final_time);
      _psi_reference.constant = _config.psi_constant;
      _psi_reference.time_reached = false;

      _p_reference.start_time = _config.p_start_time;
      _p_reference.amplitude = _config.p_amplitude;
      _p_reference.frequency = _config.p_frequency;
      _p_reference.bias = _ang_vel(0);
      _p_reference.final_value = _config.p_final_value;
      _p_reference.final_time = _config.p_final_time;
      _p_reference.speed = _config.p_speed_scaling*(
        (_p_reference.final_value - _p_reference.bias)/_p_reference.final_time);
      _p_reference.constant = _config.p_constant;
      _p_reference.time_reached = false;

      _q_reference.start_time = _config.q_start_time;
      _q_reference.amplitude = _config.q_amplitude;
      _q_reference.frequency = _config.q_frequency;
      _q_reference.bias = _ang_vel(1);
      _q_reference.final_value = _config.q_final_value;
      _q_reference.final_time = _config.q_final_time;
      _q_reference.speed = _config.q_speed_scaling*(
        (_q_reference.final_value - _q_reference.bias)/_q_reference.final_time);
      _q_reference.constant = _config.q_constant;
      _q_reference.time_reached = false;

      _r_reference.start_time = _config.r_start_time;
      _r_reference.amplitude = _config.r_amplitude;
      _r_reference.frequency = _config.r_frequency;
      _r_reference.bias = _ang_vel(2);
      _r_reference.final_value = _config.r_final_value;
      _r_reference.final_time = _config.r_final_time;
      _r_reference.speed = _config.r_speed_scaling*(
        (_r_reference.final_value - _r_reference.bias)/_r_reference.final_time);
      _r_reference.constant = _config.r_constant;
      _r_reference.time_reached = false;

      _d_reference.start_time = _config.d_start_time;
      _d_reference.amplitude = _config.d_amplitude;
      _d_reference.frequency = _config.d_frequency;
      _d_reference.bias = _depth;
      _d_reference.final_value = _config.d_final_value;
      _d_reference.final_time = _config.d_final_time;
      _d_reference.speed = _config.d_speed_scaling*(
        (_d_reference.final_value - _d_reference.bias)/_d_reference.final_time);
      _d_reference.constant = _config.d_constant;
      _d_reference.time_reached = false;
      }
    }
}

void Controller::stateCallback(const std_msgs::Float64MultiArray &msg) {
  _euler_angles(0) = msg.data[0];
  _euler_angles(1) = msg.data[1];
  _euler_angles(2) = msg.data[2];
  _ang_vel(0) = msg.data[3];
  _ang_vel(1) = msg.data[4];
  _ang_vel(2) = msg.data[5];
  _depth = msg.data[6];

  _cphi = cos(_euler_angles(0,0));
  _sphi = sin(_euler_angles(0,0));
  _cth = cos(_euler_angles(1,0));
  _sth = sin(_euler_angles(1,0));
  _tth = tan(_euler_angles(1,0));
  _cpsi = cos(_euler_angles(2,0));
  _spsi = sin(_euler_angles(2,0));
}

void Controller::Controller::cmdVelCallback(const geometry_msgs::Twist &msg) {

  if (_config.xbox) {
    _velocity_ref(0) = msg.linear.x;
    _velocity_ref(1) = msg.linear.y;
    _velocity_ref(2) = msg.linear.z;

    _ang_vel_ref(0) = msg.angular.x;
    _ang_vel_ref(1) = msg.angular.y;
    _ang_vel_ref(2) = msg.angular.z;
  }
}

void Controller::Controller::decIncDepthCallback(const std_msgs::Float32 &msg) {
  _depth_ref = _depth_ref + 0.1*msg.data;
}

//****** Controllers **********************************************************
Eigen::Matrix<double, 6, 1> Controller::calcRateControl() {
  Eigen::Matrix3d Kp;
  Eigen::Matrix3d Ki;

  Kp << _config.kp_p, 0, 0,
  0, _config.kp_q, 0,
  0, 0, _config.kp_r;

  Ki << _config.ki_p, 0, 0,
  0, _config.ki_q, 0,
  0, 0, _config.ki_r;

  double Ts = 1/_config.loop_rate;

  Eigen::Vector3d eta_tilde;
  eta_tilde =  _ang_vel - _ang_vel_ref;

  _rate_integral = _rate_integral + Ts*eta_tilde;
  for (uint i = 0; i < 3; i++) {
    if (_rate_integral(i) > 5) {
      _rate_integral(i) = 5;
    } else if (_rate_integral(i) < -5) {
      _rate_integral(i) = -5;
    }
  }

  Eigen::Matrix<double, 6, 1> velocities_and_rates;
  Eigen::Matrix<double, 6, 1> control_signals;
  velocities_and_rates << _velocity_ref, -Kp*eta_tilde - Ki*_rate_integral;

  calcLinControl(velocities_and_rates, control_signals);
  return control_signals;
}

Eigen::Matrix<double, 6, 1> Controller::calcAttitudeControl() {
  Eigen::Matrix3d Kp;
  Eigen::Matrix3d Ki;
  Eigen::Matrix3d Kd;

  Kp << _config.kp_roll, 0, 0,
  0, _config.kp_pitch, 0,
  0, 0, _config.kp_yaw;

  Ki << _config.ki_roll, 0, 0,
  0, _config.ki_pitch, 0,
  0, 0, _config.ki_yaw;

  Kd << _config.kd_roll, 0, 0,
  0, _config.kd_pitch, 0,
  0, 0, _config.kd_yaw;

  double Ts = 1/_config.loop_rate;

  calcJ();
  calcJdot();

  Eigen::Vector3d eta_tilde_dot;
  eta_tilde_dot = _J_dot*_euler_angles;

  Eigen::Vector3d eta_tilde;
  eta_tilde = _euler_angles - _euler_angles_ref;

  _attitude_integral = _attitude_integral + Ts*eta_tilde;
  for (uint i = 0; i < 3; i++) {
    if (_attitude_integral(i) > 5) {
      _attitude_integral(i) = 5;
    } else if (_attitude_integral(i) < -5) {
      _attitude_integral(i) = -5;
    }
  }

  Eigen::Matrix<double, 6, 1> control_signals;
  Eigen::Matrix<double, 6, 1> position_and_angles;
  position_and_angles << 0,0,0, momentsNEDToBody(- Kd*eta_tilde_dot - Kp*eta_tilde - Ki*_attitude_integral);
  calcLinControl(position_and_angles, control_signals);
  return control_signals;
}

Eigen::Matrix<double, 6, 1> Controller::calcDepthControl() {
  double Kp = _config.kp_depth;
  double Ki = _config.ki_depth;

  double eta_tilde = _depth - _depth_ref;
  double Ts = 1/_config.loop_rate;

  _depth_integral = _depth_integral + Ts*eta_tilde;

  if (_depth_integral > 1) {
    _depth_integral = 1;
  } else if (_depth_integral < -1) {
    _depth_integral = -1;
  }

  Eigen::Vector3d forces;
  forces << 0,0,-Kp*eta_tilde - Ki*_depth_integral;
  return _T*forcesNEDToBody(forces);
}

Eigen::Matrix<double, 6, 1> Controller::calcDecControll() {
  Eigen::Matrix<double, 6, 1> control_signals;
  control_signals << _velocity_ref, _ang_vel_ref;
  Eigen::Matrix<double, 6, 6> pseudo_inv_T;
  pseudo_inv_T << 0, 0, -0.2500, 0.5000, 0.2500, 0,
  0, 0, -0.2500, -0.5000, 0.2500, 0,
  0.5000, 0, 0, 0, 0, 0.5000,
  0.5000, 0, 0, 0, 0, -0.5000,
  0, 0, -0.5000, 0, -0.5000, 0,
  0, -1.0000, 0, 0, 0, 0;
  return pseudo_inv_T*control_signals;
}

//****** Main functions *******************************************************
void Controller::sendThrusterSignals(Eigen::Matrix<double, 6, 1>& control_signals) {
  std_msgs::UInt16MultiArray control_message;
  control_message.data.resize(6);
  Eigen::Matrix<double, 6, 6> enabled_thrusters;
  enabled_thrusters << _config.enable_thruster1, 0, 0, 0, 0, 0,
  0, _config.enable_thruster2, 0, 0, 0, 0,
  0, 0, _config.enable_thruster3, 0, 0, 0,
  0, 0, 0, _config.enable_thruster4, 0, 0,
  0, 0, 0, 0, _config.enable_thruster5, 0,
  0, 0, 0, 0, 0, _config.enable_thruster6;

  Eigen::Matrix<double, 6, 1> temp;
  control_signals = enabled_thrusters*control_signals;

  // Saturate
  for (uint i = 0; i < 6; i++) {
    if (control_signals(i,0) < -1) {
      control_signals(i,0) = -1;
    } else if (control_signals(i,0) > 1) {
      control_signals(i,0) = 1;
    }
  }

  // Convert to pwm
  for (uint i = 0; i < 6; i++) {
    control_message.data[i] = (control_signals(i,0) + 1)*400 + 1100;
  }
  _control_pub.publish(control_message);
}

void Controller::sendReferenceSignals() {
  std_msgs::Float64MultiArray reference_message;
  reference_message.data.resize(7);
  // Convert to pwm
  for (uint i = 0; i < 3; i++) {
    reference_message.data[i] = _euler_angles_ref(i);
  }
  for (uint i = 3; i < 6; i++) {
    reference_message.data[i] = _ang_vel_ref(i - 3);
  }
  reference_message.data[6] = _depth_ref;
  _reference_pub.publish(reference_message);
}

void Controller::spin() {
  ros::Rate loop(_config.loop_rate);
  Eigen::Matrix<double, 6, 1> control_signals;

  while(ros::ok()) {
    ros::spinOnce();
      std::cout << "xbox: " << _config.xbox << std::endl;
    if (!_config.xbox) {
      std::cout << "calc ref" << std::endl;
      calcReferenceSignals();
    }
    std::cout << "send ref" << std::endl;
    sendReferenceSignals();
    switch (_config.controller) {
      case 0:
      std::cout << "Cont 0" << std::endl;
      control_signals = calcDecControll();
      break;
      case 1:
      std::cout << "Cont 1" << std::endl;
      control_signals = calcRateControl();
      break;
      case 2:
      std::cout << "Cont 2" << std::endl;
      control_signals = calcAttitudeControl();
      break;
      default:
      std::cout << "Cont default" << std::endl;
      control_signals << 0, 0, 0, 0, 0, 0;
    }

    if (_config.enable_depth) {
      std::cout << "Cont depth" << std::endl;
      control_signals = control_signals + calcDepthControl();
    }
    std::cout << "send control" << std::endl;
    sendThrusterSignals(control_signals);
    ros::spinOnce();
    loop.sleep();
  }
}

int main(int argc, char **argv){
  ros::init(argc, argv, "Controller");
  Controller controller;
  controller.spin();
}
