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
    void init();
    void read();
    bool get(Sensors::SensorDataType dataType, uint8_t integerValue, uint8_t decimalValue);

  private:
    DHT *dht;
    uint8_t tempInt;
    uint8_t tempDec;
    uint8_t humInt;
    uint8_t humDec;
};

#endif