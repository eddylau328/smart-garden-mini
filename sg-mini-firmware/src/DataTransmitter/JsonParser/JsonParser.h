#ifndef JsonParser_h
#define JsonParser_h

#include <ArduinoJson.h>
#include "../../Sensors/Sensors.h"

class JsonParser {

    public:
        virtual void parse(String &str) = 0;
        virtual void parse(char **str, size_t outputSize) = 0;

};

#endif