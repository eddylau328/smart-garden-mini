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
#include <DebugLog.h>

class Sensors {
  public:
    /**
     * @brief It creates the Sensor object array and initializes all the sensor objects by invoking the sensor init()
     * 
     */
    static void init();

    /**
     * @brief It will invokes all the sensor read() from sensor array within a period 
     * 
     */
    static void mainLoop();

    /**
     * @brief Get the sensor measure data 
     * 
     * @param dataType - the sensor data type you want to get
     * @param data - the actual sensor data will be assigned to the variable you parse into
     * @return true - indicates the data is correct
     * @return false - indicates the data is corrupted or the sensor lost connection
     */
    static bool getSensorData(SensorCollection::SensorDataType dataType, float &data);

  private:
    static Sensor *sensorList[TotalSensors];
    static unsigned long lastBatchRead;
    static unsigned long lastSensorRead;
    static uint8_t currentReadIndex;
    static bool isStartRead;
    static void read(uint8_t index);
};

#endif