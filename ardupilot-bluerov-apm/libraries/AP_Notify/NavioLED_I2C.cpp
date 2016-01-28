/*
  NavioLED I2C driver
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

#include <AP_HAL.h>
#include "NavioLED_I2C.h"

#define PCA9685_ADDRESS 0x40
#define PCA9685_PWM 0x6

extern const AP_HAL::HAL& hal;

bool NavioLED_I2C::hw_init()
{
    // get pointer to i2c bus semaphore
    AP_HAL::Semaphore* i2c_sem = hal.i2c->get_semaphore();

    // take i2c bus sempahore
    if (!i2c_sem->take(HAL_SEMAPHORE_BLOCK_FOREVER)) {
        return false;
    }

    // disable recording of i2c lockup errors
    hal.i2c->ignore_errors(true);

    // enable the led
    bool ret = true;

    // re-enable recording of i2c lockup errors
    hal.i2c->ignore_errors(false);

    // give back i2c semaphore
    i2c_sem->give();

    return ret;
}

// set_rgb - set color as a combination of red, green and blue values
bool NavioLED_I2C::hw_set_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
    // get pointer to i2c bus semaphore
    AP_HAL::Semaphore* i2c_sem = hal.i2c->get_semaphore();

    // exit immediately if we can't take the semaphore
    if (i2c_sem == NULL || !i2c_sem->take(5)) {
        return false;
    }

    uint16_t red_adjusted = red * 0x10;
    uint16_t green_adjusted = green * 0x10;
    uint16_t blue_adjusted = blue * 0x10;

    uint8_t blue_channel_lsb = blue_adjusted & 0xFF;
    uint8_t blue_channel_msb = blue_adjusted >> 8;

    uint8_t green_channel_lsb = green_adjusted & 0xFF;
    uint8_t green_channel_msb = green_adjusted >> 8;

    uint8_t red_channel_lsb = red_adjusted & 0xFF;
    uint8_t red_channel_msb = red_adjusted >> 8;


    uint8_t transaction[] = {0x00, 0x00, blue_channel_lsb, blue_channel_msb,
                   0x00, 0x00, green_channel_lsb, green_channel_msb,
                   0x00, 0x00, red_channel_lsb, red_channel_msb
    };


    bool success = (hal.i2c->writeRegisters(PCA9685_ADDRESS, PCA9685_PWM, sizeof(transaction), transaction) == 0);

    // give back i2c semaphore
    i2c_sem->give();
    return success;
}
