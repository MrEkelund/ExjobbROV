#include "ROVIO.h"

ROVIO::ROVIO() {
  _sensor_publisher = temp("rovio/sensors", std_msgs::UInt16MultiArray &message);
  // Publishers
  _sensor_publisher = _nh.
       advertise("rovio/sensors", 10);

  // Subscribers
  /*_thruster_subscriber = _nh.
  subscribe("rovio/thrusters", 10, &ROVIO::thrustersCallback, this);*/

  // Internal objects
  //_water_pressure_sensor.init();
  //_water_pressure_sensor.setFluidDensity(FLUIDDENSITY);
}

void ROVIO::spin() {
  _nh.spinOnce();
  _water_pressure_sensor.read();

  sendSensors();

}
/*****************************************
 *        Publisher functions            *
 *****************************************/
void ROVIO::sendSensors() {
  std_msgs::UInt16 message;

  message.data = _water_pressure_sensor.pressure();
  //this->_sensor_publisher.publish(message);
}


/*****************************************
 *     Callback functions                *
 *****************************************/
/*void ROVIO::thrustersCallback(
  const std_msgs::UInt16MultiArray::ConstPtr& message) {

    for (int i = 0; i < 6; i++) {
      _pwm_array[i] = message->data[i];
    }
    _rov_servo.setThrusters(_pwm_array);
  }
  */
