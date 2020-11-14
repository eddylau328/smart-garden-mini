/*
  Sensors_DS18B20.h - DS18B20 sensor child class from Sensor Abstract class
*/

#ifndef Sensor_DS18B20_h
#define Sensor_DS18B20_h

#include "Sensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>

class Sensor_DS18B20 : public Sensor {
  public:
    Sensor_DS18B20();
    ~Sensor_DS18B20();
    void init();
    void read();
    bool get(Sensors::SensorDataType dataType, uint8_t &integerValue, uint8_t &decimalValue);
    
  private:
    uint8_t soilTempInt;
    uint8_t soilTempDec;
    OneWire *oneWire;
    DallasTemperature *sensor;
};

#endif