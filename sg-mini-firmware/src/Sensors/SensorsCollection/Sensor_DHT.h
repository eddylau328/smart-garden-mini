/*
  DHT - DHT sensor child class from Sensor Abstract class
*/

#ifndef Sensor_DHT_h
#define Sensor_DHT_h

#include "Sensor.h"
#include <DHT.h>
#include <DebugLog.h>

/**
 * @brief Sensor derived class for measuring the temperature and humidity
 * 
 */
class Sensor_DHT : public Sensor {

  public:
    Sensor_DHT();
    ~Sensor_DHT();
    bool init();
    bool read();
    bool get(SensorCollection::SensorDataType dataType, float &measureValue);

  private:
    DHT *dht;
    float temp;
    float hum;
};

#endif