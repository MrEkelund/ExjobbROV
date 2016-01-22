/*
 * File: liurov/include/fusion.h
 * Author: Erik Ekelund
 * Date: Jan 2016
 * Description: Headerfile for fusion node for liurov.
 */
#include <math.h>
#include <ros/ros.h>
#include <ros/console.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Float64MultiArray.h>
#include <dynamic_reconfigure/server.h>
#include <liurov/fusionConfig.h>

class Fusion {
  public:
    Fusion();

    // Accessingfunctions for position estimates
    double getPosX();
    double getPosY();
    double getPosZ();

    void setPosX(double);
    void setPosY(double);
    void setPosZ(double);

    //Accessingfunctions for angle estimates
    double getAngleX();
    double getAngleY();
    double getAngleZ();

    void setAngleX(double);
    void setAngleY(double);
    void setAngleZ(double);

    //Accessingfunctions for angle rate estimates
    double getAngleRateX();
    double getAngleRateY();
    double getAngleRateZ();

    void setAngleRateX(double);
    void setAngleRateY(double);
    void setAngleRateZ(double);


    //Accessingfunctions for magnetic measurements
    double getMagneticMeasurementX();
    double getMagneticMeasurementY();
    double getMagneticMeasurementZ();

    void setMagneticMeasurementX(double);
    void setMagneticMeasurementY(double);
    void setMagneticMeasurementZ(double);

    //Accessingfunctions for angular rate measurements
    double getAngularRateMeasurementX();
    double getAngularRateMeasurementY();
    double getAngularRateMeasurementZ();

    void setAngularRateMeasurementX(double);
    void setAngularRateMeasurementY(double);
    void setAngularRateMeasurementZ(double);


    //Accessingfunctions for angular rate measurements
    double getAccelerationMeasurementX();
    double getAccelerationMeasurementY();
    double getAccelerationMeasurementZ();

    void setAccelerationMeasurementX(double);
    void setAccelerationMeasurementY(double);
    void setAccelerationMeasurementZ(double);

    //Accessingfunctions for external pressure measurements
    double getExternalPressureMeasurement();
    void setExternalPressureMeasurement(double);

    //Accessingfunctions for internal pressure measurements
    double getInternalPressureMeasurement();
    void setInternalPressureMeasurement(double);

    // Ros specific functions and variables
    void spin();


  private:
    //ros node, subscribers publishers.
    ros::NodeHandle nh;
    ros::Subscriber sensor_data_sub;
    //callbacks
    void measurementCallback(const geometry_msgs::Twist::ConstPtr& );
    void sensorDataCallback(const std_msgs::Float64MultiArray::ConstPtr&);


    //Dynamic reconfigure and reconfigure callback
    dynamic_reconfigure::Server<liurov::fusionConfig> server;
    liurov::fusionConfig config;
    void configCallback(liurov::fusionConfig &update, uint32_t level);

    //Estimates
    double pos_estimate[3];
    double angle_estimate[3];
    double angle_rate_estimate[3];

    //Current measurements
    double magnetic_measurement[3];
    double angular_rate_measurement[3];
    double acceleration_measurement[3];
    double external_pressure_measurement;
    double internal_pressure_measurement;
    double thrusterlevel[6];
};
