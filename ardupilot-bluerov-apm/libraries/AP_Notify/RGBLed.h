/*
 *  AP_Notify Library. 
 * based upon a prototype library by David "Buzz" Bussenschutt.
 */

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

#ifndef __RGBLED_H__
#define __RGBLED_H__

#include <AP_HAL.h>
#include "NotifyDevice.h"

class RGBLed: public NotifyDevice {
public:
    RGBLed(uint8_t led_off, uint8_t led_bright, uint8_t led_medium, uint8_t led_dim);

    // init - initialised the LED
    virtual bool init(void);

    // healthy - returns true if the LED is operating properly
    virtual bool healthy() { return _healthy; }

    // set_rgb - set color as a combination of red, green and blue levels from 0 ~ 15
    virtual void set_rgb(uint8_t red, uint8_t green, uint8_t blue);

    // update - updates led according to timed_updated.  Should be
    // called at 50Hz
    virtual void update();

protected:
    // methods implemented in hardware specific classes
    virtual bool hw_init(void) = 0;
    virtual bool hw_set_rgb(uint8_t red, uint8_t green, uint8_t blue) = 0;

    // meta-data common to all hw devices
    uint8_t counter;
    uint8_t step;
    bool _healthy;                               // true if the LED is operating properly
    uint8_t _red_des, _green_des, _blue_des;     // color requested by timed update
    uint8_t _red_curr, _green_curr, _blue_curr;  // current colours displayed by the led
    uint8_t _led_off;
    uint8_t _led_bright;
    uint8_t _led_medium;
    uint8_t _led_dim;
private:
    virtual void update_colours();
};

#endif //__RGBLED_H__
