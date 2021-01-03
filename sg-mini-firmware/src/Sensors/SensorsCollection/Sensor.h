/*
  Sensor.h - Abstract class for All Type of Sensors
*/

#ifndef Sensor_h
#define Sensor_h

#include "../../Config/Config.h"
#include "SensorCollection.h"

/**
 * @brief provides a base structure for a newly added sensor to inherit
 * 
 */
class Sensor {
  public:

    /**
     * @brief initialize the sensor if it has any initalize process
     * 
     * @return true - Sensor Status Connected
     * @return false - Sensor Status Disconnected
     */
    virtual bool init() = 0;
    
    /**
     * @brief only ask the sensor to read the data, perform this in a cycle is a proper approach
     * 
     * @return true - Sensor Reading is normal
     * @return false - Sensor Reading is unusual
     */
    virtual bool read() = 0;

    /**
     * @brief Combining the integer and decimal parts to floating point number
     * 
     * @param dataType - sesnor data type you asking for, as one sensor may have two different types data
     * @param measureValue - measure value from your sensor
     * @return true - the asking type of data is existed
     * @return false - the asking type of data is not existed
     */
    virtual bool get(SensorCollection::SensorDataType dataType, float &measureValue) = 0;
    
    /**
     * @brief Get the connect status of the sensor
     * 
     * @return true - the connection between the sensor and the board is established
     * @return false - the connection between the sensor and the board is not established
     */
    bool isConnected();

  protected:
    // check whether the sensor is connected or not
    bool isConnect = false;
};

#endif