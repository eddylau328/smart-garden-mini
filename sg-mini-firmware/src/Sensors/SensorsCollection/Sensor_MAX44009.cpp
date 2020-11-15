/*
  Sensor_MAX44009 - Lux sensor
*/

#include "Sensor_MAX44009.h"

Sensor_MAX44009::Sensor_MAX44009() {
  max44009 = new Max44009(MAX44009_MAX_ADDR);
}

Sensor_MAX44009::~Sensor_MAX44009() {
  free(max44009);
}

bool Sensor_MAX44009::init() {
  return true;
}

void Sensor_MAX44009::read() {
  lux = max44009->getLux();
  int err = max44009->getError();
}

bool Sensor_MAX44009::get(Sensors::SensorDataType dataType, float &measureValue) {
  if (dataType == Sensors::SensorDataType::Light) {
    measureValue = lux;
    return true;
  }

  return false;
}