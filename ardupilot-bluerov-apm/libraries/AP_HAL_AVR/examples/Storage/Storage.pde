
#include <AP_Common.h>
#include <AP_Math.h>
#include <AP_Param.h>
#include <StorageManager.h>
#include <AP_Progmem.h>

#include <AP_HAL.h>
#include <AP_HAL_AVR.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_APM2
const AP_HAL::HAL& hal = AP_HAL_AVR_APM2;
#elif CONFIG_HAL_BOARD == HAL_BOARD_APM1
const AP_HAL::HAL& hal = AP_HAL_AVR_APM1;
#endif

uint8_t fibs[12] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };

void test_write() {
    hal.console->printf_P(PSTR("writing... "));
    hal.storage->write_block(0, fibs, 12);
    hal.console->printf_P(PSTR(" done.\r\n"));
}

void test_readback() {
    hal.console->printf_P(PSTR("reading back...\r\n"));
    uint8_t readback[12];
    bool success = true;
    hal.storage->read_block(readback, 0, 12);
    for (int i = 0; i < 12; i++) {
        if (readback[i] != fibs[i]) {
            success = false;
            hal.console->printf_P(PSTR("At index %d expected %d got %d\r\n"),
                    i, (int) fibs[i], (int) readback[i]); 
        }   
    }
    if (success) {
        hal.console->printf_P(PSTR("all bytes read successfully\r\n"));
    }
    hal.console->printf_P(PSTR("done reading back.\r\n"));
}

void setup (void) {
    hal.console->printf_P(PSTR("Starting AP_HAL_AVR::Storage test\r\n"));
    test_write();
    test_readback();
}

void loop (void) { }

AP_HAL_MAIN();
