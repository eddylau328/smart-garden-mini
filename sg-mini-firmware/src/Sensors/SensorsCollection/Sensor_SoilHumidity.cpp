/*
  Sensor_SoilHumidity.cpp - SoilHumidity sensor child class from Sensor Abstract class
*/

#include "Sensor_SoilHumidity.h"

Sensor_SoilHumidity::Sensor_SoilHumidity() {}

Sensor_SoilHumidity::~Sensor_SoilHumidity() {}

bool Sensor_SoilHumidity::init() {  
// no init is needed as analog pins are input only
  return true;  // for now
}

bool Sensor_SoilHumidity::read() {
  int soilMoistureValue = analogRead(SoilHumidity_PIN);  //put Sensor insert into soil
  int measureValue = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

  if (measureValue < 0)
    soilMoisturePercentage = 0;
  else if (measureValue > 100)
    soilMoisturePercentage = 100;
  else
    soilMoisturePercentage = (float) measureValue;

  return true;  // Currently, cannot find a way to detect whether it is correct value or not
}

bool Sensor_SoilHumidity::get(Sensors::SensorDataType dataType, float &measureValue) {
  if (dataType == Sensors::SensorDataType::SoilHum) {
    measureValue = soilMoisturePercentage;
    return true;
  }
  
  return false;
}