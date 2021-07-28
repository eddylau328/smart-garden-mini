#include "InitJsonParser.h"


void InitJsonParser::parse(String &str) {
    const size_t capacity = JSON_OBJECT_SIZE(5);
    StaticJsonDocument<capacity> doc;
    setupSensors(doc);
    serializeJson(doc, str);
}

void InitJsonParser::parse(char **str, size_t outputSize) {
    const size_t capacity = JSON_OBJECT_SIZE(2) + JSON_ARRAY_SIZE(5);
    StaticJsonDocument<capacity> doc;
    doc.getOrAddMember("farmId").set("1");
    setupSensors(doc);
    serializeJson(doc, *str, outputSize);
}

// private
void InitJsonParser::setupSensors(JsonDocument &doc) {
    JsonArray sensors = doc.createNestedArray("sensors");
    sensors.add("temp");
    sensors.add("hum");
    sensors.add("soilTemp");
    sensors.add("soilHum");
    sensors.add("light");
}