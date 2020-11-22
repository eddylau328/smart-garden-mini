#include "SensorCollection.h"

uint8_t SensorCollection::getSensorListKey(SensorCollection::SensorDataType dataType) {
  switch (dataType) {
    case SensorCollection::SensorDataType::Temp:
      return DHT_Key;
    case SensorCollection::SensorDataType::Hum:
      return DHT_Key;
    case SensorCollection::SensorDataType::SoilTemp:
      return DS18B20_Key;
    case SensorCollection::SensorDataType::SoilHum:
      return SoilHumidity_Key;
    case SensorCollection::SensorDataType::Light:
      return MAX44009_Key;
    case SensorCollection::SensorDataType::WaterLevel:
      return UltraSound_Key;
    case SensorCollection::SensorDataType::ShuntVoltage:
      return INA219_Key;
    case SensorCollection::SensorDataType::LoadVoltage:
      return INA219_Key;
    case SensorCollection::SensorDataType::BusVoltage:
      return INA219_Key;
    case SensorCollection::SensorDataType::Current:
      return INA219_Key;
    case SensorCollection::SensorDataType::Power:
      return INA219_Key;
    default:
      return NOT_FOUND;
  }
}

char* SensorCollection::getSensorName(uint8_t key) {
  switch (key) {
    case DHT_Key:
      return "DHT Sensor";
    case DS18B20_Key:
      return "DS18B20 Sensor";
    case SoilHumidity_Key:
      return "SoilHumidity Sensor";
    case MAX44009_Key:
      return "MAX44009 Sensor";
    case UltraSound_Key:
      return "Ultrasound Sensor";
    case INA219_Key:
      return "INA219 Sensor";
    default:
      return "Not Found";
  }
}