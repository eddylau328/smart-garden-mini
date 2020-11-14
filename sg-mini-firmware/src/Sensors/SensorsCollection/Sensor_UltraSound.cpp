/*
  Sensor_UltraSound - UltraSound sensor child class from Sensor Abstract class
*/

#include "Sensor_UltraSound.h"

Sensor_UltraSound::Sensor_UltraSound() {}

Sensor_UltraSound::~Sensor_UltraSound() {}

void Sensor_UltraSound::init() {
  pinMode(UltraSound_Trigger_PIN, OUTPUT);// Ultra Sound pin setting
  pinMode(UltraSound_Echo_PIN, INPUT);
}

void Sensor_UltraSound::read() {
  digitalWrite(UltraSound_Trigger_PIN, LOW);
  delayMicroseconds(2);
  
  digitalWrite(UltraSound_Trigger_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(UltraSound_Trigger_PIN, LOW);
  
  duration = pulseIn(UltraSound_Echo_PIN, HIGH);
  float distance = duration*0.034/2;
  
  Helper::getIntegerValue(distance, distanceInt);
  Helper::getDecimalValue(distance, distanceDec);
}

bool Sensor_UltraSound::get(Sensors::SensorDataType dataType, uint8_t &integerValue, uint8_t &decimalValue) {
  if (dataType == Sensors::SensorDataType::WaterLevel) {
    integerValue = distanceInt;
    decimalValue = distanceDec;
    return true;
  }
  return false;
}