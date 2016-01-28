
#include "SPIDriver.h"

using namespace Empty;

EmptySPIDeviceDriver::EmptySPIDeviceDriver()
{}

void EmptySPIDeviceDriver::init()
{}

AP_HAL::Semaphore* EmptySPIDeviceDriver::get_semaphore()
{
    return &_semaphore;
}

void EmptySPIDeviceDriver::transaction(const uint8_t *tx, uint8_t *rx, uint16_t len)
{}


void EmptySPIDeviceDriver::cs_assert()
{}

void EmptySPIDeviceDriver::cs_release()
{}

uint8_t EmptySPIDeviceDriver::transfer (uint8_t data)
{
    return 0;
}

void EmptySPIDeviceDriver::transfer (const uint8_t *data, uint16_t len)
{
}

EmptySPIDeviceManager::EmptySPIDeviceManager()
{}

void EmptySPIDeviceManager::init(void *)
{}

AP_HAL::SPIDeviceDriver* EmptySPIDeviceManager::device(enum AP_HAL::SPIDevice)
{
    return &_device;
}

