/*
  Sensors_DS18B20.h - DS18B20 sensor child class from Sensor Abstract class
*/

#ifndef Sensor_DS18B20_h
#define Sensor_DS18B20_h

#include "Sensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DebugLog.h>

class Sensor_DS18B20 : public Sensor {
  public:
    Sensor_DS18B20();
    ~Sensor_DS18B20();
    bool init();
    bool read();
    bool get(SensorCollection::SensorDataType dataType, float &measureValue);
    
  private:
    float soilTemp;
    OneWire *oneWire;
    DallasTemperature *sensor;
};

#endif