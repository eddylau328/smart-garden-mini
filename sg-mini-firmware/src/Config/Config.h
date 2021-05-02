/*
  Config.h - Header Files for all the configuration this firmware needs
  - Pin Configuration
*/
#ifndef Config_h
#define Config_h

// Total Number of Sensors
#define TotalSensors 6
// Sensors Key Mapping, Range [0 - 254]
#define DHT_Key 0
#define DS18B20_Key 1
#define SoilHumidity_Key 2
#define UltraSound_Key 3
#define INA219_Key 4
#define MAX44009_Key 5
// NOT FOUND KEY
#define NOT_FOUND 255


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
#define MAX44009_MAX_ADDR 0x4B // 0x4B is no interrupt, or 0x4B if A0 pin connected to Vcc

// Rotary Encoder
#define DT_PIN 39
#define CLK_PIN 36
#define SW_PIN 25

// LCD Screen Size
#define LCDScreenWidth 16
#define LCDScreenHeight 2
// Define the reading time for sensors
#define ReadingInterval 5000000  // 5s = 5000ms = 5000 000 micro sec

// WIFI ACCESS POINT
#define ACCESS_POINT_NAME_BUFFER_SIZE 25
#define ACCESS_POINT_PASSWORD_BUFFER_SIZE 25
#endif