/*
  Sensors_DS18B20.cpp - DS18B20 sensor child class from Sensor Abstract class
*/

#include "Sensor_DS18B20.h"

Sensor_DS18B20::Sensor_DS18B20() {
  oneWire = new OneWire(DS18B20_PIN);
  sensor = new DallasTemperature(oneWire);
}

Sensor_DS18B20::~Sensor_DS18B20() {
  delete oneWire;
  delete sensor;
}

// nothing to init
bool Sensor_DS18B20::init() {
  // sensor->getAddress(address, 0);
  sensor->setResolution(address, 9);
  return read(); // for now
}

bool Sensor_DS18B20::read() {
  sensor->requestTemperatures(); 
  soilTemp = sensor->getTempC(address);
  LOG_VERBOSE("Soil Temp", soilTemp, "deg C");

  isConnect = true;
  return isConnect;  // Currently, no way to define wrong value or not
}

bool Sensor_DS18B20::get(SensorCollection::SensorDataType dataType, float &measureValue) {
  if (dataType == SensorCollection::SensorDataType::SoilTemp) {
    measureValue = soilTemp;
    return true;
  }

  return false;
}