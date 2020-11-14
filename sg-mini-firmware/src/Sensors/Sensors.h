/*
  Sensors.h - library for access all the sensors
*/

#ifndef Sensors_h
#define Sensors_h

class Sensors {
  public:
    enum SensorDataType {
      None, Temp, Hum, SoilTemp, SoilHum, Light
    };

    Sensors();
    ~Sensors();
};

#endif