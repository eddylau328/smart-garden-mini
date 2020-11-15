/*
  Sensor_MAX44009 - Lux sensor
*/

#ifndef Sensor_MAX44009_h
#define Sensor_MAX44009_h

#include "Sensor.h"
#include <Max44009.h>


class Sensor_MAX44009 : public Sensor {

  public:
    Sensor_MAX44009();
    ~Sensor_MAX44009();

    bool init();
    void read();
    bool get(Sensors::SensorDataType dataType, float &measureValue);

  private:
    Max44009 *max44009;
    float lux;

};

#endif