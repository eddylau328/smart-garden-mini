#ifndef SensorCollection_h
#define SensorCollection_h

#include <Arduino.h>
#include "../../Config/Config.h"

/**
 * @brief provides function for accessing the sensor data types and the sensor names  
 * 
 */
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

    /**
     * @brief Get the Sensor List Key object
     * 
     * @param dataType - sensor data type
     * @return uint8_t - the index of the sensor in sensor object array
     */
    static uint8_t getSensorListKey(SensorCollection::SensorDataType dataType);

    /**
     * @brief Get the Sensor Name object
     * 
     * @param key - the index of the sensor in sensor object array
     * @return char* - the name of the sensor
     */
    static char* getSensorName(uint8_t key);
};

#endif