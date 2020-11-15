/*
  DHT - DHT sensor child class from Sensor Abstract class
*/

#ifndef Sensor_DHT_h
#define Sensor_DHT_h

#include "Sensor.h"
#include <DHT.h>

class Sensor_DHT : public Sensor {

  public:
    Sensor_DHT();
    ~Sensor_DHT();
    bool init();
    void read();
    bool get(Sensors::SensorDataType dataType, float &measureValue);

  private:
    DHT *dht;
    float temp;
    float hum;
};

#endif