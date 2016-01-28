/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 *       AP_Compass_HIL.cpp - Arduino Library for HIL model of HMC5843 I2C Magnetometer
 *       Code by James Goppert. DIYDrones.com
 *
 */


#include <AP_HAL.h>
#include "AP_Compass_HIL.h"

extern const AP_HAL::HAL& hal;

// constructor
AP_Compass_HIL::AP_Compass_HIL() : Compass() 
{
    product_id = AP_COMPASS_TYPE_HIL;
    _setup_earth_field();
}

// setup _Bearth
void AP_Compass_HIL::_setup_earth_field(void)
{
    // assume a earth field strength of 400
    _Bearth(400, 0, 0);
	
    // rotate _Bearth for inclination and declination. -66 degrees
    // is the inclination in Canberra, Australia
    Matrix3f R;
    R.from_euler(0, ToRad(66), _declination.get());
    _Bearth = R * _Bearth;
}

// Public Methods //////////////////////////////////////////////////////////////

bool AP_Compass_HIL::read()
{
    _field[0] = _hil_mag;
    
    apply_corrections(_field[0],0);

    // values set by setHIL function
    last_update = hal.scheduler->micros();      // record time of update
    return true;
}

#define MAG_OFS_X 5.0
#define MAG_OFS_Y 13.0
#define MAG_OFS_Z -18.0

// Update raw magnetometer values from HIL data
//
void AP_Compass_HIL::setHIL(float roll, float pitch, float yaw)
{
    Matrix3f R;

    // create a rotation matrix for the given attitude
    R.from_euler(roll, pitch, yaw);

    if (_last_declination != _declination.get()) {
        _setup_earth_field();
        _last_declination = _declination.get();
    }

    // convert the earth frame magnetic vector to body frame, and
    // apply the offsets
    _hil_mag = R.mul_transpose(_Bearth);
    _hil_mag -= Vector3f(MAG_OFS_X, MAG_OFS_Y, MAG_OFS_Z);

    // apply default board orientation for this compass type. This is
    // a noop on most boards
    _hil_mag.rotate(MAG_BOARD_ORIENTATION);

    // add user selectable orientation
    _hil_mag.rotate((enum Rotation)_orientation[0].get());

    if (!_external[0]) {
        // and add in AHRS_ORIENTATION setting if not an external compass
        _hil_mag.rotate(_board_orientation);
    }

    _healthy[0] = true;
}

// Update raw magnetometer values from HIL mag vector
//
void AP_Compass_HIL::setHIL(const Vector3f &mag)
{
    _hil_mag.x = mag.x;
    _hil_mag.y = mag.y;
    _hil_mag.z = mag.z;
    _healthy[0] = true;
}

const Vector3f& AP_Compass_HIL::getHIL() const {
    return _hil_mag;
}

void AP_Compass_HIL::accumulate(void)
{
    // nothing to do
}
