/*
  Sensor_SoilHumidity.h - SoilHumidity sensor child class from Sensor Abstract class
*/

#ifndef Sensor_SoilHumidity_h
#define Sensor_SoilHumidity_h

#include "Sensor.h"

class Sensor_SoilHumidity : public Sensor {

  public:
    Sensor_SoilHumidity();
    ~Sensor_SoilHumidity();
    void init();
    void read();
    bool get(Sensors::SensorDataType dataType, uint8_t &integerValue, uint8_t &decimalValue);

  private:
    uint8_t soilMoisturePercentage;
  
    const int AirValue = 3600;   //you need to replace this value with Value_1
    const int WaterValue = 1260;  //you need to replace this value with Value_2
};

#endif