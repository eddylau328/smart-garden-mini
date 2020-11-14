/*
  Sensors_DS18B20.cpp - DS18B20 sensor child class from Sensor Abstract class
*/

#include "Sensor_DS18B20.h"

Sensor_DS18B20::Sensor_DS18B20() {
  oneWire = new OneWire(DS18B20_PIN);
  sensor = new DallasTemperature(oneWire);
}

Sensor_DS18B20::~Sensor_DS18B20() {
  free(oneWire);
  free(sensor);
}

// nothing to init
void Sensor_DS18B20::init() {}

void Sensor_DS18B20::read() {
  sensor->requestTemperatures(); 
  float measure = sensor->getTempCByIndex(0);
  Helper::getIntegerValue(measure, soilTempInt);
  Helper::getDecimalValue(measure, soilTempDec);
}

bool Sensor_DS18B20::get(Sensors::SensorDataType dataType, uint8_t &integerValue, uint8_t &decimalValue) {
  if (dataType == Sensors::SensorDataType::SoilTemp) {
    integerValue = soilTempInt;
    decimalValue = soilTempDec;
    return true;
  }

  return false;
}