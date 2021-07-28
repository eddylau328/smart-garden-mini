#include "SensorJsonParser.h"


void SensorJsonParser::parse(String &str) {
    const size_t capacity = JSON_OBJECT_SIZE(5);
    StaticJsonDocument<capacity> doc;
    setupSensorData(doc);
    serializeJson(doc, str);
}

void SensorJsonParser::parse(char **str, size_t outputSize) {
    const size_t capacity = JSON_OBJECT_SIZE(5);
    StaticJsonDocument<capacity> doc;
    setupSensorData(doc);
    serializeJson(doc, *str, outputSize);
}

// private
void SensorJsonParser::setupSensorData(JsonDocument &doc) {
    setupSingleSensorData(doc, "temp", SensorCollection::SensorDataType::Temp);
    setupSingleSensorData(doc, "hum", SensorCollection::SensorDataType::Hum);
    setupSingleSensorData(doc, "soilTemp", SensorCollection::SensorDataType::SoilTemp);
    setupSingleSensorData(doc, "soilHum", SensorCollection::SensorDataType::SoilHum);
    setupSingleSensorData(doc, "light", SensorCollection::SensorDataType::Light);
}

void SensorJsonParser::setupSingleSensorData(JsonDocument &doc, const char* dataName, SensorCollection::SensorDataType dataType) {
    float value;
    bool isCorrect = Sensors::getSensorData(dataType, value);
    doc.getOrAddMember(dataName).set(isCorrect? value : 0);
}