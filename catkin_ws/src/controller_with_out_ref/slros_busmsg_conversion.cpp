#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_Controller_with_out_ref_geometry_msgs_Quaternion and geometry_msgs::Quaternion

void convert_from_bus(geometry_msgs::Quaternion* msgPtr, SL_Bus_Controller_with_out_ref_geometry_msgs_Quaternion const* busPtr)
{
  msgPtr->w =  busPtr->W;
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convert_to_bus(SL_Bus_Controller_with_out_ref_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr)
{
  busPtr->W =  msgPtr->w;
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_Controller_with_out_ref_geometry_msgs_Twist and geometry_msgs::Twist

void convert_from_bus(geometry_msgs::Twist* msgPtr, SL_Bus_Controller_with_out_ref_geometry_msgs_Twist const* busPtr)
{
  convert_from_bus(&msgPtr->angular, &busPtr->Angular);
  convert_from_bus(&msgPtr->linear, &busPtr->Linear);
}

void convert_to_bus(SL_Bus_Controller_with_out_ref_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr)
{
  convert_to_bus(&busPtr->Angular, &msgPtr->angular);
  convert_to_bus(&busPtr->Linear, &msgPtr->linear);
}


// Conversions between SL_Bus_Controller_with_out_ref_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_Controller_with_out_ref_geometry_msgs_Vector3 const* busPtr)
{
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convert_to_bus(SL_Bus_Controller_with_out_ref_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_Controller_with_out_ref_mavros_msgs_ActuatorControl and mavros_msgs::ActuatorControl

void convert_from_bus(mavros_msgs::ActuatorControl* msgPtr, SL_Bus_Controller_with_out_ref_mavros_msgs_ActuatorControl const* busPtr)
{
  {
    const int numItemsToCopy = 8;
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->controls[i] =  busPtr->Controls[i];
    }
  }
  msgPtr->group_mix =  busPtr->GroupMix;
  convert_from_bus(&msgPtr->header, &busPtr->Header);
}

void convert_to_bus(SL_Bus_Controller_with_out_ref_mavros_msgs_ActuatorControl* busPtr, mavros_msgs::ActuatorControl const* msgPtr)
{
  {
    const int numItemsToCopy = 8;
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Controls[i] =  msgPtr->controls[i];
    }
  }
  busPtr->GroupMix =  msgPtr->group_mix;
  convert_to_bus(&busPtr->Header, &msgPtr->header);
}


// Conversions between SL_Bus_Controller_with_out_ref_ros_time_Time and ros::Time

void convert_from_bus(ros::Time* msgPtr, SL_Bus_Controller_with_out_ref_ros_time_Time const* busPtr)
{
  msgPtr->sec =  busPtr->Sec;
  msgPtr->nsec =  busPtr->Nsec;
}

void convert_to_bus(SL_Bus_Controller_with_out_ref_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  busPtr->Sec =  msgPtr->sec;
  busPtr->Nsec =  msgPtr->nsec;
}


// Conversions between SL_Bus_Controller_with_out_ref_sensor_msgs_Imu and sensor_msgs::Imu

void convert_from_bus(sensor_msgs::Imu* msgPtr, SL_Bus_Controller_with_out_ref_sensor_msgs_Imu const* busPtr)
{
  convert_from_bus(&msgPtr->angular_velocity, &busPtr->AngularVelocity);
  {
    const int numItemsToCopy = 9;
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->angular_velocity_covariance[i] =  busPtr->AngularVelocityCovariance[i];
    }
  }
  convert_from_bus(&msgPtr->header, &busPtr->Header);
  convert_from_bus(&msgPtr->linear_acceleration, &busPtr->LinearAcceleration);
  {
    const int numItemsToCopy = 9;
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->linear_acceleration_covariance[i] =  busPtr->LinearAccelerationCovariance[i];
    }
  }
  convert_from_bus(&msgPtr->orientation, &busPtr->Orientation);
  {
    const int numItemsToCopy = 9;
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->orientation_covariance[i] =  busPtr->OrientationCovariance[i];
    }
  }
}

void convert_to_bus(SL_Bus_Controller_with_out_ref_sensor_msgs_Imu* busPtr, sensor_msgs::Imu const* msgPtr)
{
  convert_to_bus(&busPtr->AngularVelocity, &msgPtr->angular_velocity);
  {
    const int numItemsToCopy = 9;
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->AngularVelocityCovariance[i] =  msgPtr->angular_velocity_covariance[i];
    }
  }
  convert_to_bus(&busPtr->Header, &msgPtr->header);
  convert_to_bus(&busPtr->LinearAcceleration, &msgPtr->linear_acceleration);
  {
    const int numItemsToCopy = 9;
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->LinearAccelerationCovariance[i] =  msgPtr->linear_acceleration_covariance[i];
    }
  }
  convert_to_bus(&busPtr->Orientation, &msgPtr->orientation);
  {
    const int numItemsToCopy = 9;
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->OrientationCovariance[i] =  msgPtr->orientation_covariance[i];
    }
  }
}


// Conversions between SL_Bus_Controller_with_out_ref_std_msgs_Header and std_msgs::Header

void convert_from_bus(std_msgs::Header* msgPtr, SL_Bus_Controller_with_out_ref_std_msgs_Header const* busPtr)
{
  {
    const int numItemsToCopy = busPtr->FrameId_SL_Info.CurrentLength;
    msgPtr->frame_id.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->frame_id[i] =  busPtr->FrameId[i];
    }
  }
  msgPtr->seq =  busPtr->Seq;
  convert_from_bus(&msgPtr->stamp, &busPtr->Stamp);
}

void convert_to_bus(SL_Bus_Controller_with_out_ref_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->frame_id.size();
    if (numItemsToCopy > 128)
    {
      ROS_WARN_NAMED("Controller_with_out_ref", "Truncating array '%s' in received message '%s' from %d to %d items", "frame_id", "std_msgs/Header", numItemsToCopy, 128);
      numItemsToCopy = 128;
    }
    busPtr->FrameId_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->FrameId[i] = (uint8_T) msgPtr->frame_id[i];
    }
  }
  busPtr->Seq =  msgPtr->seq;
  convert_to_bus(&busPtr->Stamp, &msgPtr->stamp);
}

