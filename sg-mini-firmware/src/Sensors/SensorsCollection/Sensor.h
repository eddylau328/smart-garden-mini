/*
  Sensor.h - Abstract class for All Type of Sensors
*/

#ifndef Sensor_h
#define Sensor_h

#include "../Sensors.h"

class Sensor {
  public:
    virtual void init() = 0;
    virtual void read() = 0;
    virtual bool get(Sensors::SensorDataType dataType, uint8_t &integerValue, uint8_t &decimalValue) = 0;
};

#endif