#include "MS5837.h"
#include <Wire.h>

#define MS5837_ADDR               0x76
#define MS5837_RESET              0x1E
#define MS5837_ADC_READ           0x00
#define MS5837_PROM_READ          0xA0
#define MS5837_CONVERT_D1_8192    0x4A
#define MS5837_CONVERT_D2_8192    0x5A

MS5837::MS5837():_D1_converted(false),_D2_converted(false),_time_to_read(0) {}

bool MS5837::init() {

	// Reset the MS5837, per datasheet
	Wire.beginTransmission(MS5837_ADDR);
	Wire.write(MS5837_RESET);
	Wire.endTransmission();

	// Wait for reset to complete
	delay(10);

	uint8_t tries = 0;

	// Try to read prom 10 times
	while (!readProm() && (tries < 10)) {
		tries++;
		delay(100);
	}
	if(tries <= 10) {
		return true;
	}
	return false;
}

bool MS5837::readProm() {
	// Read calibration values and CRC
	for (uint8_t i = 0 ; i < 8 ; i++) {
		Wire.beginTransmission(MS5837_ADDR);
		Wire.write(MS5837_PROM_READ+i*2);
		Wire.endTransmission();

		Wire.requestFrom(MS5837_ADDR,2);
		C[i] = (Wire.read() << 8) | Wire.read();
	}

	// Verify that data is correct with CRC
	uint8_t crcRead = C[0] >> 12;
	uint8_t crcCalculated = crc4(C);

	if (crcCalculated == crcRead) {
		// succses
		return true;
	}
	// Fail
	return false;
}

bool MS5837::read() {

	if (!_D1_converted && !_D2_converted) {
		// Request D1 conversion
		Wire.beginTransmission(MS5837_ADDR);
		Wire.write(MS5837_CONVERT_D1_8192);
		Wire.endTransmission();
		_time_to_read = millis() + 20;
		_D1_converted = true;
		_D2_converted = false;
	} else if (_D1_converted && !_D2_converted && _time_to_read <= millis()) {
		Wire.beginTransmission(MS5837_ADDR);
		Wire.write(MS5837_ADC_READ);
		Wire.endTransmission();
		Wire.requestFrom(MS5837_ADDR,3);
		D1 = 0;
		D1 = Wire.read();
		D1 = (D1 << 8) | Wire.read();
		D1 = (D1 << 8) | Wire.read();
		// Request D2 conversion
		Wire.beginTransmission(MS5837_ADDR);
		Wire.write(MS5837_CONVERT_D2_8192);
		Wire.endTransmission();
		_time_to_read = millis() + 20;
		_D1_converted = false;
		_D2_converted = true;
	} else if (_time_to_read <= millis()) {
		Wire.beginTransmission(MS5837_ADDR);
		Wire.write(MS5837_ADC_READ);
		Wire.endTransmission();

		Wire.requestFrom(MS5837_ADDR,3);
		D2 = 0;
		D2 = Wire.read();
		D2 = (D2 << 8) | Wire.read();
		D2 = (D2 << 8) | Wire.read();
		_D1_converted = false;
		_D2_converted = false;

		calculate();
		return true;
	}
	return false;
}


void MS5837::calculate() {
	// Given C1-C6 and D1, D2, calculated TEMP and P
	// Do conversion first and then second order temp compensation

	int32_t dT;
	int64_t SENS;
	int64_t OFF;
	int32_t SENSi;
	int32_t OFFi;
	int32_t Ti;
	int64_t OFF2;
	int64_t SENS2;

	// Terms called
	dT = D2-uint32_t(C[5])*256l;
	SENS = int64_t(C[1])*32768l+(int64_t(C[3])*dT)/256l;
	OFF = int64_t(C[2])*65536l+(int64_t(C[4])*dT)/128l;


	//Temp and P conversion
	TEMP = 2000l+int64_t(dT)*C[6]/8388608LL;
	P = (D1*SENS/(2097152l)-OFF)/(8192l);

	//Second order compensation
	if((TEMP/100)<20){         //Low temp
		Ti = (3*int64_t(dT)*int64_t(dT))/(8589934592LL);
		OFFi = (3*(TEMP-2000)*(TEMP-2000))/2;
		SENSi = (5*(TEMP-2000)*(TEMP-2000))/8;
		if((TEMP/100)<-15){    //Very low temp
			OFFi = OFFi+7*(TEMP+1500l)*(TEMP+1500l);
			SENSi = SENSi+4*(TEMP+1500l)*(TEMP+1500l);
		}
	}
	else if((TEMP/100)>=20){    //High temp
		Ti = 2*(dT*dT)/(137438953472LL);
		OFFi = (1*(TEMP-2000)*(TEMP-2000))/16;
		SENSi = 0;
	}

	OFF2 = OFF-OFFi;           //Calculate pressure and temp second order
	SENS2 = SENS-SENSi;

	TEMP = (TEMP-Ti);
	P = (((D1*SENS2)/2097152l-OFF2)/8192l);
}

float MS5837::pressure(float conversion) {
	return P/10.0f*conversion;
}

float MS5837::temperature() {
	return TEMP/100.0f;
}

uint8_t MS5837::crc4(uint16_t n_prom[]) {
	uint16_t n_rem = 0;

	n_prom[0] = ((n_prom[0]) & 0x0FFF);
	n_prom[7] = 0;

	for ( uint8_t i = 0 ; i < 16; i++ ) {
		if ( i%2 == 1 ) {
			n_rem ^= (uint16_t)((n_prom[i>>1]) & 0x00FF);
		} else {
			n_rem ^= (uint16_t)(n_prom[i>>1] >> 8);
		}
		for ( uint8_t n_bit = 8 ; n_bit > 0 ; n_bit-- ) {
			if ( n_rem & 0x8000 ) {
				n_rem = (n_rem << 1) ^ 0x3000;
			} else {
				n_rem = (n_rem << 1);
			}
		}
	}

	n_rem = ((n_rem >> 12) & 0x000F);

	return n_rem ^ 0x00;
}
