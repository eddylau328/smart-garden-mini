#ifndef SensorJsonParser_h
#define SensorJsonParser_h


#include "../JsonParser.h"


class SensorJsonParser : public JsonParser {

    public:
        void parse(String &str);
        void parse(char **str, size_t outputSize);

    private:
        static void setupSensorData(JsonDocument &doc);
        static void setupSingleSensorData(JsonDocument &doc, const char *dataName, SensorCollection::SensorDataType dataType);

};

#endif