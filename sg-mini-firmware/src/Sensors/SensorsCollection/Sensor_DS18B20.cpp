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
bool Sensor_DS18B20::init() {
  return true; // for now
}

bool Sensor_DS18B20::read() {
  sensor->requestTemperatures(); 
  soilTemp = sensor->getTempCByIndex(0);
  return true;  // Currently, no way to define wrong value or not
}

bool Sensor_DS18B20::get(SensorCollection::SensorDataType dataType, float &measureValue) {
  if (dataType == SensorCollection::SensorDataType::SoilTemp) {
    measureValue = soilTemp;
    return true;
  }

  return false;
}