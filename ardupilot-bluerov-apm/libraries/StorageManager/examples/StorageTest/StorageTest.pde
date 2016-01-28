// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

//
// Simple test for the StorageManager class
//

#include <stdarg.h>
#include <AP_Common.h>
#include <AP_Progmem.h>
#include <AP_HAL.h>
#include <AP_HAL_AVR.h>
#include <AP_HAL_AVR_SITL.h>
#include <AP_HAL_Linux.h>
#include <AP_HAL_FLYMAPLE.h>
#include <AP_HAL_PX4.h>
#include <AP_HAL_Empty.h>
#include <AP_Math.h>
#include <AP_Param.h>
#include <StorageManager.h>
#include <AP_ADC.h>
#include <AP_InertialSensor.h>
#include <AP_Notify.h>
#include <AP_GPS.h>
#include <SITL.h>
#include <AP_Baro.h>
#include <Filter.h>
#include <DataFlash.h>
#include <GCS_MAVLink.h>
#include <AP_Mission.h>
#include <AP_Terrain.h>
#include <AP_Rally.h>
#include <AP_AHRS.h>
#include <AP_Airspeed.h>
#include <AP_Vehicle.h>
#include <AP_ADC_AnalogSource.h>
#include <AP_Compass.h>
#include <AP_Declination.h>
#include <AP_NavEKF.h>
#include <AP_HAL_Linux.h>
#include <AP_Scheduler.h>

const AP_HAL::HAL& hal = AP_HAL_BOARD_DRIVER;

#define DO_INITIALISATION 1

/*
  instantiate all 4 storage types
 */
static StorageAccess all_storage[4] = { 
    StorageAccess(StorageManager::StorageParam),
    StorageAccess(StorageManager::StorageMission),
    StorageAccess(StorageManager::StorageFence),
    StorageAccess(StorageManager::StorageRally)
};

/*
  simple random generator, see http://en.wikipedia.org/wiki/Random_number_generation
 */
static uint16_t get_random(void)
{
    static uint32_t m_z = 1234;
    static uint32_t m_w = 76542;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return ((m_z << 16) + m_w) & 0xFFFF;
}

/*
  return a predictable value for an offset
 */
static uint8_t pvalue(uint16_t offset)
{
    return ((offset * 7) + 13) % 65536;
}

void setup(void)
{
    hal.console->println("StorageTest startup...");
#if DO_INITIALISATION
    for (uint8_t type=0; type<4; type++) {
        const StorageAccess &storage = all_storage[type];
        hal.console->printf("Init type %u\n", (unsigned)type);
        for (uint16_t i=0; i<storage.size(); i++) {
            storage.write_byte(i, pvalue(i));
        }
    }
#endif
}

void loop(void)
{
    static uint32_t count;
    uint8_t type = get_random() % 4;
    const StorageAccess &storage = all_storage[type];
    uint16_t offset = get_random() % storage.size();
    uint8_t  length = (get_random() & 31);
    if (offset + length > storage.size()) {
        length = storage.size() - offset;
    }
    if (length == 0) {
        return;
    }
    uint8_t b[length];
    for (uint8_t i=0; i<length; i++) {
        b[i] = pvalue(offset+i);
    }

    if (get_random() % 2 == 1) {
        if (!storage.write_block(offset, b, length)) {
            hal.console->printf("write failed at offset %u length %u\n",
                                (unsigned)offset, (unsigned)length);
        }
    } else {
        uint8_t b2[length];
        if (!storage.read_block(b2, offset, length)) {
            hal.console->printf("read failed at offset %u length %u\n",
                                (unsigned)offset, (unsigned)length);
        }
        if (memcmp(b, b2, length) != 0) {
            hal.console->printf("bad data at offset %u length %u\n",
                                (unsigned)offset, (unsigned)length);
        }
    }

    count++;
    if (count % 10000 == 0) {
        hal.console->printf("%u ops\n", count);
    }
}



AP_HAL_MAIN();
