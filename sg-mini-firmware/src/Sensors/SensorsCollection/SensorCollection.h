#ifndef SensorCollection_h
#define SensorCollection_h

#include <Arduino.h>
#include "../../Config/Config.h"

class SensorCollection {
  public:
    // Follow the Array Number
    enum SensorDataType {
      Temp = 0,
      Hum,
      SoilTemp,
      SoilHum,   
      Light,     
      WaterLevel,
      ShuntVoltage,
      LoadVoltage,
      BusVoltage,
      Current,
      Power,
    };

    static uint8_t getSensorListKey(SensorCollection::SensorDataType dataType);
};

#endif