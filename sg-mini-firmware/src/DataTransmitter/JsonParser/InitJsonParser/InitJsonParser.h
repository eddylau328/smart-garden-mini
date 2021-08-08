#ifndef InitJsonParser_h
#define InitJsonParser_h


#include "../JsonParser.h"


class InitJsonParser : public JsonParser {

    public:
        void parse(String &str);
        void parse(char **str, size_t outputSize);

    private:
        static void setupSensors(JsonDocument &doc);
};

#endif