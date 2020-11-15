/*
  Sensor_UltraSound - UltraSound sensor child class from Sensor Abstract class
*/

#include "Sensor_UltraSound.h"

Sensor_UltraSound::Sensor_UltraSound() {}

Sensor_UltraSound::~Sensor_UltraSound() {}

bool Sensor_UltraSound::init() {
  pinMode(UltraSound_Trigger_PIN, OUTPUT);// Ultra Sound pin setting
  pinMode(UltraSound_Echo_PIN, INPUT);

  return true;  // for now
}

bool Sensor_UltraSound::read() {
  digitalWrite(UltraSound_Trigger_PIN, LOW);
  delayMicroseconds(2);
  
  digitalWrite(UltraSound_Trigger_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(UltraSound_Trigger_PIN, LOW);
  
  duration = pulseIn(UltraSound_Echo_PIN, HIGH);
  float distance = duration*0.034/2;
  
  return distance >= 0; // if distance is negative, it may indicate a wrong reading or water level is over
}

bool Sensor_UltraSound::get(SensorCollection::SensorDataType dataType, float &measureValue) {
  if (dataType == SensorCollection::SensorDataType::WaterLevel) {
    measureValue = distance;
    return true;
  }
  return false;
}