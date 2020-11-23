/*
  Sensor.h - Abstract class for All Type of Sensors
*/

#ifndef Sensor_h
#define Sensor_h

#include "../../Config/Config.h"
#include "SensorCollection.h"

class Sensor {
  public:
  
    /**
     * initialize the sensor if it has any initalize process
     * @return bool - Sensor Status (Connected = True / Disconnected = False)
     */
    virtual bool init() = 0;
    
    /**
     * only ask the sensor to read the data
     * perform this in a cycle is a proper approach
     * @return bool - Whether Sensor Reading is normal or unusual
     */
    virtual bool read() = 0;


    /** 
      * Combining the integer and decimal parts to floating point number
      * @param [Sensors::SensorsDataType] data type you asking for, as one sensor may have two different types data
      * @param [float] measure value from your sensor
      * @return bool - whether the asking type of data is existed or not
    */
    virtual bool get(SensorCollection::SensorDataType dataType, float &measureValue) = 0;
};

#endif