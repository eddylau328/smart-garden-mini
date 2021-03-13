#include "JsonParser.h"

void JsonParser::writeSensorData(String &str) {
    const size_t capacity = JSON_OBJECT_SIZE(5);
    StaticJsonDocument<capacity> doc;
    bool isCorrect;
    float value;
    isCorrect = Sensors::getSensorData(SensorCollection::SensorDataType::Temp, value);
    doc["temp"] = isCorrect? value : 0;
    Serial.println(value);
    isCorrect = Sensors::getSensorData(SensorCollection::SensorDataType::Hum, value);
    doc["hum"] = isCorrect? value : 0;
    Serial.println(value);
    isCorrect = Sensors::getSensorData(SensorCollection::SensorDataType::SoilTemp, value);
    doc["soilTemp"] = isCorrect? value : 0;
    Serial.println(value);
    isCorrect = Sensors::getSensorData(SensorCollection::SensorDataType::SoilHum, value);
    doc["soilHum"] = isCorrect? value : 0;
    isCorrect = Sensors::getSensorData(SensorCollection::SensorDataType::Light, value);
    doc["light"] = isCorrect? value : 0;
    serializeJson(doc, str);
    Serial.println(str);
}