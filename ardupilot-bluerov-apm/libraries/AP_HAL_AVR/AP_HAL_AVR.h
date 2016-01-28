
#ifndef __AP_HAL_AVR_H__
#define __AP_HAL_AVR_H__

#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_APM1 || CONFIG_HAL_BOARD == HAL_BOARD_APM2
/**
 * This module exports AP_HAL::HAL instances only.
 * All internal drivers must conform to AP_HAL interfaces
 * and not expose implementation details.
 */

#include "HAL_AVR_APM1_Class.h"
#include "HAL_AVR_APM2_Class.h"
#include "AP_HAL_AVR_Main.h"

#endif // CONFIG_HAL_BOARD

#endif // __AP_HAL_AVR_H__

