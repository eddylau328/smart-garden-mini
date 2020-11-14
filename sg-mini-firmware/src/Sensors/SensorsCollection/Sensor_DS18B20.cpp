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
  temperature = sensor->getTempCByIndex(0);
}

float Sensor_DS18B20::get(Sensors::SensorDataType dataType) {
  if (dataType == Sensors::SensorDataType::SoilTemp)
    return temperature;
  else
    return Error_WrongSensorType;
}