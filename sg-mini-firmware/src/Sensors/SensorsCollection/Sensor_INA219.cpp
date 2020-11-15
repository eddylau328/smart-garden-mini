/*
  Sensor_INA219 - current sensor child class from Sensor Abstract class 
*/

#include "Sensor_INA219.h"

Sensor_INA219::Sensor_INA219() {
  ina219 = new INA219_WE(I2C_ADDRESS);
}

Sensor_INA219::~Sensor_INA219() {
  delete ina219;
}

bool Sensor_INA219::init() {
  if(!ina219->init())  // INA init
    return false;
  else {
    ina219->setADCMode(SAMPLE_MODE_128);
    ina219->setMeasureMode(CONTINUOUS);
    return true;
  }
}

bool Sensor_INA219::read() {
  shuntVoltage = ina219->getShuntVoltage_mV();
  busVoltage = ina219->getBusVoltage_V();
  current_mA = ina219->getCurrent_mA();
  power_mW = ina219->getBusPower();
  loadVoltage = busVoltage + shuntVoltage / 1000.0;
  return true;  // Currently, no way to define wrong value or not
}

bool Sensor_INA219::get(SensorCollection::SensorDataType dataType, float &measureValue) {
  switch (dataType) {
    case SensorCollection::SensorDataType::ShuntVoltage:
      measureValue = shuntVoltage;
      return true;
    case SensorCollection::SensorDataType::BusVoltage:
      measureValue = busVoltage;
      return true;
    case SensorCollection::SensorDataType::Current:
      measureValue = current_mA;
      return true;
    case SensorCollection::SensorDataType::Power:
      measureValue = power_mW;
      return true;
    case SensorCollection::SensorDataType::LoadVoltage:
      measureValue = loadVoltage;
      return true;
    default:
      return false;
  }
}