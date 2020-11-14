/*
  Sensor_UltraSound - UltraSound sensor child class from Sensor Abstract class
*/

#ifndef Sensor_UltraSound_h
#define Sensor_UltraSound_h

#include "Sensor.h"

class Sensor_UltraSound : public Sensor {

  public:
    Sensor_UltraSound();
    ~Sensor_UltraSound();

    void init();
    void read();
    bool get(Sensors::SensorDataType dataType, uint8_t &integerValue, uint8_t &decimalValue);

  private:
    uint8_t distanceInt;
    uint8_t distanceDec;
    
    unsigned long duration;
};

#endif