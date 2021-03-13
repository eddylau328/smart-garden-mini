#ifndef JsonParser_h
#define JsonParser_h

#include <ArduinoJson.h>
#include "../../Sensors/Sensors.h"

class JsonParser {

    public:
        static void writeSensorData(String &str);

};

#endif