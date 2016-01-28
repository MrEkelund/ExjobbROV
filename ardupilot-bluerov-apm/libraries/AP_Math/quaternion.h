// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
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

// Copyright 2012 Andrew Tridgell, all rights reserved.
// Refactored by Jonathan Challinger

#ifndef QUATERNION_H
#define QUATERNION_H

#include <math.h>
#if defined(MATH_CHECK_INDEXES) && (MATH_CHECK_INDEXES == 1)
#include <assert.h>
#endif

class Quaternion
{
public:
    float        q1, q2, q3, q4;

    // constructor creates a quaternion equivalent
    // to roll=0, pitch=0, yaw=0
    Quaternion() {
        q1 = 1; q2 = q3 = q4 = 0;
    }

    // setting constructor
    Quaternion(const float _q1, const float _q2, const float _q3, const float _q4) :
        q1(_q1), q2(_q2), q3(_q3), q4(_q4) {
    }

    // function call operator
    void operator        ()(const float _q1, const float _q2, const float _q3, const float _q4)
    {
        q1 = _q1; q2 = _q2; q3 = _q3; q4 = _q4;
    }

    // check if any elements are NAN
    bool        is_nan(void) const
    {
        return isnan(q1) || isnan(q2) || isnan(q3) || isnan(q4);
    }

    // return the rotation matrix equivalent for this quaternion
    void        rotation_matrix(Matrix3f &m) const;

    void		from_rotation_matrix(const Matrix3f &m);

    // convert a vector from earth to body frame
    void        earth_to_body(Vector3f &v) const;

    // create a quaternion from Euler angles
    void        from_euler(float roll, float pitch, float yaw);

    void to_axis_angle(Vector3f &v);

    void from_axis_angle(Vector3f v);

    void from_axis_angle(const Vector3f &axis, float theta);

    void rotate(const Vector3f &v);

    void from_axis_angle_fast(Vector3f v);

    void from_axis_angle_fast(const Vector3f &axis, float theta);

    void rotate_fast(const Vector3f &v);


    // create eulers from a quaternion
    void        to_euler(float &roll, float &pitch, float &yaw) const;

    float length(void) const;
    void normalize();

    Quaternion inverse(void) const;

    // allow a quaternion to be used as an array, 0 indexed
    float & operator[](uint8_t i) {
        float *_v = &q1;
#if defined(MATH_CHECK_INDEXES) && (MATH_CHECK_INDEXES == 1)
        assert(i < 4);
#endif
        return _v[i];
    }

    const float & operator[](uint8_t i) const {
        const float *_v = &q1;
#if defined(MATH_CHECK_INDEXES) && (MATH_CHECK_INDEXES == 1)
        assert(i < 4);
#endif
        return _v[i];
    }

    Quaternion operator*(const Quaternion &v);
    Quaternion &operator*=(const Quaternion &v);
    Quaternion operator/(const Quaternion &v);
};
#endif // QUATERNION_H
