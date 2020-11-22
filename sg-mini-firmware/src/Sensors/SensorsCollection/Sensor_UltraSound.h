/*
  Sensor_UltraSound - UltraSound sensor child class from Sensor Abstract class
*/

#ifndef Sensor_UltraSound_h
#define Sensor_UltraSound_h

#include "Sensor.h"
#include <DebugLog.h>

class Sensor_UltraSound : public Sensor {

  public:
    Sensor_UltraSound();
    ~Sensor_UltraSound();

    bool init();
    bool read();
    bool get(SensorCollection::SensorDataType dataType, float &measureValue);

  private:
    float distance;    
    long duration;
};

#endif