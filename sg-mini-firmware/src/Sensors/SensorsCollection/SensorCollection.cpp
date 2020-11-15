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