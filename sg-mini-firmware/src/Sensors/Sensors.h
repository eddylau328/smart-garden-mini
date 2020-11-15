/*
  Sensors.h - library for access all the sensors
*/

#ifndef Sensors_h
#define Sensors_h

#include <Arduino.h>

#include "../Config/Config.h"
#include "SensorsCollection/SensorCollection.h"
#include "SensorsCollection/Sensor.h"
#include "SensorsCollection/Sensor_DHT.h"
#include "SensorsCollection/Sensor_DS18B20.h"
#include "SensorsCollection/Sensor_INA219.h"
#include "SensorsCollection/Sensor_MAX44009.h"
#include "SensorsCollection/Sensor_SoilHumidity.h"
#include "SensorsCollection/Sensor_UltraSound.h"

class Sensors {
  public:
    Sensors();
    ~Sensors();

  private:
    Sensor *sensorList[TotalSensors];

};

#endif