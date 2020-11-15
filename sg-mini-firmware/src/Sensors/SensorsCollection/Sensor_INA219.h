/*
  Sensor_INA219 - current sensor child class from Sensor Abstract class 
*/

#ifndef Sensor_INA219_h
#define Sensor_INA219_h

#include "Sensor.h"
#include <Wire.h>
#include <INA219_WE.h>
#include "../../Helper/Helper.h"

class Sensor_INA219 : public Sensor {

  public:
    Sensor_INA219();
    ~Sensor_INA219();

    bool init();
    bool read();
    bool get(SensorCollection::SensorDataType dataType, float &measureValue);

  private:
    INA219_WE *ina219;
    float shuntVoltage;
    float loadVoltage;
    float busVoltage;
    float current_mA;
    float power_mW;
};

#endif