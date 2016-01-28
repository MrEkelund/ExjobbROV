/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#ifndef __AP_INERTIALNAV_H__
#define __AP_INERTIALNAV_H__

#include <AP_AHRS.h>
#include <AP_InertialSensor.h>          // ArduPilot Mega IMU Library
#include <AP_Baro.h>                    // ArduPilot Mega Barometer Library
#include <AP_Buffer.h>                  // FIFO buffer library
#include <AP_GPS_Glitch.h>              // GPS Glitch detection library
#include <AP_Baro_Glitch.h>             // Baro Glitch detection library
#include "../AP_NavEKF/AP_Nav_Common.h" // definitions shared by inertial and ekf nav filters

#define AP_INTERTIALNAV_TC_XY   2.5f // default time constant for complementary filter's X & Y axis
#define AP_INTERTIALNAV_TC_Z    5.0f // default time constant for complementary filter's Z axis

// #defines to control how often historical accel based positions are saved
// so they can later be compared to laggy gps readings
#define AP_INTERTIALNAV_SAVE_POS_AFTER_ITERATIONS   10
#define AP_INTERTIALNAV_GPS_LAG_IN_10HZ_INCREMENTS  4       // must not be larger than size of _hist_position_estimate_x and _hist_position_estimate_y
#define AP_INTERTIALNAV_GPS_TIMEOUT_MS              300     // timeout after which position error from GPS will fall to zero

/*
 * AP_InertialNav blends accelerometer data with gps and barometer data to improve altitude and position hold.
 *
 * Most of the functions have to be called at 100Hz. (see defines above)
 *
 * The accelerometer values are integrated over time to approximate velocity and position.
 * The inaccurcy of these estimates grows over time due to noisy sensor data.
 * To improve the accuracy, baro and gps readings are used:
 *      An error value is calculated as the difference between the sensor's measurement and the last position estimation.
 *   	This value is weighted with a gain factor and incorporated into the new estimation
 *
 * Special thanks to Tony Lambregts (FAA) for advice which contributed to the development of this filter.
 *
 */
class AP_InertialNav
{
public:

    // Constructor
    AP_InertialNav(AP_AHRS &ahrs, AP_Baro &baro, GPS_Glitch& gps_glitch, Baro_Glitch &baro_glitch) :
        _ahrs(ahrs),
        _baro(baro),
        _xy_enabled(false),
        _k1_xy(0.0f),
        _k2_xy(0.0f),
        _k3_xy(0.0f),
        _gps_last_update(0),
        _gps_last_time(0),
        _historic_xy_counter(0),
        _lon_to_cm_scaling(LATLON_TO_CM),
        _k1_z(0.0f),
        _k2_z(0.0f),
        _k3_z(0.0f),
        _baro_last_update(0),
        _glitch_detector(gps_glitch),
        _baro_glitch(baro_glitch),
        _error_count(0)
        {
            AP_Param::setup_object_defaults(this, var_info);
        }

    /**
     * initializes the object.
     */
    virtual void init();

    /**
     * update - updates velocity and position estimates using latest info from accelerometers
     * augmented with gps and baro readings
     *
     * @param dt : time since last update in seconds
     */
    virtual void update(float dt);

    /**
     * get_filter_status : returns filter status as a series of flags
     */
    virtual nav_filter_status get_filter_status() const;

    /**
     * get_origin - returns the inertial navigation origin in lat/lon/alt
     *
     * @return origin Location
     */
    virtual struct Location get_origin() const { return _ahrs.get_home(); }

    //
    // XY Axis specific methods
    //

    /**
     * get_position - returns the current position relative to the home location in cm.
     *
     * @return
     */
    virtual const Vector3f&    get_position() const { return _position; }

    /**
     * get_latitude - returns the latitude of the current position estimation in 100 nano degrees (i.e. degree value multiplied by 10,000,000)
     * @return
     */
    virtual int32_t     get_latitude() const;

    /**
     * get_longitude - returns the longitude of the current position estimation in 100 nano degrees (i.e. degree value multiplied by 10,000,000)
     * @return
     */
    virtual int32_t     get_longitude() const;

    /**
     * get_latitude_diff - returns the current latitude difference from the home location.
     *
     * @return difference in 100 nano degrees (i.e. degree value multiplied by 10,000,000)
     */
    virtual float       get_latitude_diff() const;

    /**
     * get_longitude_diff - returns the current longitude difference from the home location.
     *
     * @return difference in 100 nano degrees (i.e. degree value multiplied by 10,000,000)
     */
    virtual float       get_longitude_diff() const;

    /**
     * get_velocity - returns the current velocity in cm/s
     *
     * @return velocity vector:
     *      		.x : latitude  velocity in cm/s
     * 				.y : longitude velocity in cm/s
     * 				.z : vertical  velocity in cm/s
     */
    virtual const Vector3f&    get_velocity() const { return _velocity; }

    /**
     * get_velocity_xy - returns the current horizontal velocity in cm/s
     *
     * @returns the current horizontal velocity in cm/s
     */
    virtual float get_velocity_xy() const;

    /**
     * set_velocity_xy - overwrites the current horizontal velocity in cm/s
     *
     * @param x : latitude  velocity in cm/s
     * @param y : longitude velocity in cm/s
     */
    void        set_velocity_xy(float x, float y);

    /**
       setup_home_position - reset on home position change
    */
    void setup_home_position(void);

    //
    // Z Axis methods
    //

    /**
     * get_altitude - get latest altitude estimate in cm above the
     * reference position
     * @return
     */
    virtual float       get_altitude() const { return _position.z; }

    /**
     * set_altitude - overwrites the current altitude value.
     *
     * @param new_altitude : altitude in cm
     */
    void        set_altitude( float new_altitude);

    /**
     * get_velocity_z - returns the current climbrate.
     *
     * @see get_velocity().z
     *
     * @return climbrate in cm/s (positive up)
     */
    virtual float       get_velocity_z() const { return _velocity.z; }

    /**
     * set_velocity_z - overwrites the current climbrate.
     *
     * @param new_velocity : climbrate in cm/s
     */
    void        set_velocity_z( float new_velocity );

    /**
     * error_count - returns number of missed updates from GPS
     */
    uint8_t     error_count() const { return _error_count; }

    /**
     * ignore_next_error - the next error (if it occurs immediately) will not be added to the error count
     */
    void        ignore_next_error() { _flags.ignore_error = 7; }

    // class level parameters
    static const struct AP_Param::GroupInfo var_info[];

    // public variables
    Vector3f                accel_correction_hbf;       // horizontal body frame accelerometer corrections. here for logging purposes only

protected:

    /**
     * correct_with_gps - calculates horizontal position error using gps
     *
     * @param now : current time since boot in milliseconds
     * @param lon : longitude in 100 nano degrees (i.e. degree value multiplied by 10,000,000)
     * @param lat : latitude  in 100 nano degrees (i.e. degree value multiplied by 10,000,000)
     */
    void        correct_with_gps(uint32_t now, int32_t lon, int32_t lat);

    /**
     * check_home - checks if the home position has moved and offsets everything so it still lines up
     */
    void check_home();

    /**
     * check_gps - checks if new gps readings have arrived and calls correct_with_gps to
     * calculate the horizontal position error
     * @see correct_with_gps(int32_t lon, int32_t lat, float dt);
     */
    void        check_gps();

    /**
     * check_baro - checks if new baro readings have arrived and calls correct_with_baro to
     * calculate the vertical position error
     *
     * @see correct_with_baro(float baro_alt, float dt);
     */
    void        check_baro();

    /**
     * correct_with_baro - calculates vertical position error using barometer.
     *
     * @param baro_alt : altitude in cm
     * @param dt : time since last baro reading in s
     */
    void        correct_with_baro(float baro_alt, float dt);


    /**
     * update gains from time constant.
     */
    void                    update_gains();

    /**
     * set_position_xy - overwrites the current position relative to the home location in cm
     *
     * the home location was set with AP_InertialNav::set_home_location(int32_t, int32_t)
     *
     * @param x : relative latitude  position in cm
     * @param y : relative longitude position in cm
     */
    void set_position_xy(float x, float y);

    // structure for holding flags
    struct InertialNav_flags {
        uint8_t gps_glitching       : 1;                // 1 if glitch detector was previously indicating a gps glitch
        uint8_t baro_glitching      : 1;                // 1 if baro glitch detector was previously indicating a baro glitch
        uint8_t ignore_error        : 3;                // the number of iterations for which we should ignore errors
    } _flags;

    AP_AHRS                &_ahrs;                      // reference to ahrs object
    AP_Baro                &_baro;                      // reference to barometer

    // parameters
    AP_Float                _time_constant_xy;          // time constant for horizontal corrections in s
    AP_Float                _time_constant_z;           // time constant for vertical corrections in s

    // XY Axis specific variables
    bool                    _xy_enabled;                // xy position estimates enabled
    float                   _k1_xy;                     // gain for horizontal position correction
    float                   _k2_xy;                     // gain for horizontal velocity correction
    float                   _k3_xy;                     // gain for horizontal accelerometer offset correction
    uint32_t                _gps_last_update;           // system time of last gps update in ms
    uint32_t                _gps_last_time;             // time of last gps update according to the gps itself in ms
    uint8_t                 _historic_xy_counter;       // counter used to slow saving of position estimates for later comparison to gps
    AP_BufferFloat_Size5    _hist_position_estimate_x;  // buffer of historic accel based position to account for gpslag
    AP_BufferFloat_Size5    _hist_position_estimate_y;  // buffer of historic accel based position to account for gps lag
    float                   _lon_to_cm_scaling;         // conversion of longitude to centimeters

    // Z Axis specific variables
    float                   _k1_z;                      // gain for vertical position correction
    float                   _k2_z;                      // gain for vertical velocity correction
    float                   _k3_z;                      // gain for vertical accelerometer offset correction
    uint32_t                _baro_last_update;          // time of last barometer update in ms
    AP_BufferFloat_Size15   _hist_position_estimate_z;  // buffer of historic accel based altitudes to account for barometer lag

    // general variables
    Vector3f                _position_base;             // (uncorrected) position estimate in cm - relative to the home location (_base_lat, _base_lon, 0)
    Vector3f                _position_correction;       // sum of corrections to _position_base from delayed 1st order samples in cm
    Vector3f                _velocity;                  // latest velocity estimate (integrated from accelerometer values) in cm/s
    Vector3f                _position_error;            // current position error in cm - is set by the check_* methods and used by update method to calculate the correction terms
    Vector3f                _position;                  // sum(_position_base, _position_correction) - corrected position estimate in cm - relative to the home location (_base_lat, _base_lon, 0)

    // error handling
    GPS_Glitch&             _glitch_detector;           // GPS Glitch detector
    Baro_Glitch&            _baro_glitch;               // Baro glitch detector
    uint8_t                 _error_count;               // number of missed GPS updates

    int32_t                 _last_home_lat;
    int32_t                 _last_home_lng;

};

#if AP_AHRS_NAVEKF_AVAILABLE
#include "AP_InertialNav_NavEKF.h"
#endif

#endif // __AP_INERTIALNAV_H__
