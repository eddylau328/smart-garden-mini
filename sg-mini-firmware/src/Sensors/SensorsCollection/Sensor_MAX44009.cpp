/*
  Sensor_MAX44009 - Lux sensor
*/

#include "Sensor_MAX44009.h"

Sensor_MAX44009::Sensor_MAX44009() {
  max44009 = new Max44009(MAX44009_MAX_ADDR);
}

Sensor_MAX44009::~Sensor_MAX44009() {
  delete max44009;
}

bool Sensor_MAX44009::init() {
  isConnect = !max44009->getError();
  return isConnect;
}

bool Sensor_MAX44009::read() {
  if (!isConnect) {
    init();
  }

  if (isConnect) {
    lux = max44009->getLux();
    LOG_VERBOSE("Light Int" ,lux, "lux");
  }
  
  return isConnect;
}

bool Sensor_MAX44009::get(SensorCollection::SensorDataType dataType, float &measureValue) {
  if (dataType == SensorCollection::SensorDataType::Light) {
    measureValue = lux;
    return true;
  }

  return false;
}