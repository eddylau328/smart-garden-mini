/*
  Sensors.h - library for access all the sensors
*/

#ifndef Sensors_h
#define Sensors_h

#include <Arduino.h>
#include "../Config/Config.h"

class Sensors {
  public:
    enum SensorDataType {
      None, Temp, Hum, SoilTemp, SoilHum, Light
    };

    Sensors();
    ~Sensors();
};

#endif