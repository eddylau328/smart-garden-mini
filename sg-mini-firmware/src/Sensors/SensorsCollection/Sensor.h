/*
  Sensor.h - Abstract class for All Type of Sensors
*/

#ifndef Sensor_h
#define Sensor_h

#include "../../Config/Config.h"
#include "../Sensors.h"

class Sensor {
  public:
    virtual void init() = 0;
    virtual void read() = 0;
    virtual float get(Sensors::SensorDataType dataType) = 0;
};

#endif