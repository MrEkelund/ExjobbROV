#ifndef _ROV_DEFINES_H_
#define _ROV_DEFINES_H_

#define RED_LED_PIN     27
#define YELLOW_LED_PIN  26
#define BLUE_LED_PIN    25

#define RED_LED_ON digitalWrite(RED_LED_PIN,LOW);
#define RED_LED_OFF digitalWrite(RED_LED_PIN,HIGH);
#define YELLOW_LED_ON digitalWrite(YELLOW_LED_PIN,LOW);
#define YELLOW_LED_OFF digitalWrite(YELLOW_LED_PIN,HIGH);
#define BLUE_LED_ON digitalWrite(BLUE_LED_PIN,LOW);
#define BLUE_LED_OFF digitalWrite(BLUE_LED_PIN,HIGH);


// Defines for thrusters
#define SERVO1 12
#define SERVO2 11
#define SERVO3 8
#define SERVO4 7
#define SERVO5 6
#define SERVO6 3
//#define SERVO7 2
//#define SERVO8 5
#define THRUSTERSTOP 1500
#define THRUSTERMAX 1900
#define THRUSTERMIN 1100

// Defines for the water pressure sensor
#define FLUIDDENSITY 1000 // Kanske redundant

// Defines for the EEPROM address
#define EEPROM_MAGNETOMETER_OFFSET_X 0x00 // These are int16_t so 2x8 = 2 rows in memory
#define EEPROM_MAGNETOMETER_OFFSET_Y 0x02
#define EEPROM_MAGNETOMETER_OFFSET_Z 0x04
#define EEPROM_GYRO_OFFSET_X         0x06
#define EEPROM_GYRO_OFFSET_Y         0x08
#define EEPROM_GYRO_OFFSET_Z         0x0A
#define EEPROM_ACCELOMETER_OFFSET_X  0x0C
#define EEPROM_ACCELOMETER_OFFSET_Y  0x0E
#define EEPROM_ACCELOMETER_OFFSET_Z  0x10


#endif //_ROV_DEFINES_H_
