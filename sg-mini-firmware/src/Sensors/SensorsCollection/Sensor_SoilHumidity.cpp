/*
  Sensor_SoilHumidity.cpp - SoilHumidity sensor child class from Sensor Abstract class
*/

#include "Sensor_SoilHumidity.h"

Sensor_SoilHumidity::Sensor_SoilHumidity() {}

Sensor_SoilHumidity::~Sensor_SoilHumidity() {}

void Sensor_SoilHumidity::init() {} // no init is needed as analog pins are input only

void Sensor_SoilHumidity::read() {
  int soilMoistureValue = analogRead(SoilHumidity_PIN);  //put Sensor insert into soil
  int measureValue = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

  if (measureValue < 0)
    soilMoisturePercentage = 0;
  else if (measureValue > 100)
    soilMoisturePercentage = 100;
  else
    soilMoisturePercentage = measureValue;
}

bool Sensor_SoilHumidity::get(Sensors::SensorDataType dataType, uint8_t &integerValue, uint8_t &decimalValue) {
  if (dataType == Sensors::SensorDataType::SoilHum) {
    integerValue = soilMoisturePercentage;
    decimalValue = 0;
    return true;
  }
  
  return false;
}