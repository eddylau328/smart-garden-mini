/*
  Config.h - Header Files for all the configuration this firmware needs
  - Pin Configuration
*/
#ifndef Config_h
#define Config_h

// Pin Configuration
#define DS18B20_PIN 33  
#define SoilHumidity_PIN 14
#define DHT_PIN 13
#define DHT_TYPE DHT12
#define UltraSound_Trigger_PIN 32
#define UltraSound_Echo_PIN 35


// INA219 current sensor I2C address
#define I2C_ADDRESS 0x40

// MAX44009 Light Intensity Sensor
#define MAX44009_MAX_ADDR 0x4A // or 0x4B if A0 pin connected to Vcc

#endif