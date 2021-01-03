/*
  Sensors_DS18B20.h - DS18B20 sensor child class from Sensor Abstract class
*/

#ifndef Sensor_DS18B20_h
#define Sensor_DS18B20_h

#include "Sensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DebugLog.h>

/**
 * @brief Sensor derived class for measuring the temperature of the soil
 * 
 */
class Sensor_DS18B20 : public Sensor {
  public:
    Sensor_DS18B20();
    ~Sensor_DS18B20();
    bool init();
    bool read();
    bool get(SensorCollection::SensorDataType dataType, float &measureValue);
    
  private:
    const uint8_t address[8] = {40,66,102,7,214,1,60,31};
    float soilTemp;
    OneWire *oneWire;
    DallasTemperature *sensor;
};

#endif