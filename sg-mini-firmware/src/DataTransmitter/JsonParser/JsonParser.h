#ifndef JsonParser_h
#define JsonParser_h

#include <ArduinoJson.h>
#include "../../Sensors/Sensors.h"

class JsonParser {

    public:
        static void writeSensorData(String &str);
        static void writeSensorData(char **str, size_t outputSize);
    
    private:
        static void setupSensorData(JsonDocument &doc);
        static void setupSingleSensorData(JsonDocument &doc, const char *dataName, SensorCollection::SensorDataType dataType);

};

#endif