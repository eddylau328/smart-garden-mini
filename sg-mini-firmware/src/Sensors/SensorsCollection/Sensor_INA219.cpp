/*
  Sensor_INA219 - current sensor child class from Sensor Abstract class 
*/

#include "Sensor_INA219.h"

Sensor_INA219::Sensor_INA219() {
  ina219 = new INA219_WE(I2C_ADDRESS);
}

Sensor_INA219::~Sensor_INA219() {
  free(ina219);
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

void Sensor_INA219::read() {
  shuntVoltage = ina219->getShuntVoltage_mV();
  busVoltage = ina219->getBusVoltage_V();
  current_mA = ina219->getCurrent_mA();
  power_mW = ina219->getBusPower();
  loadVoltage = busVoltage + shuntVoltage / 1000.0;
}

bool Sensor_INA219::get(Sensors::SensorDataType dataType, float &measureValue) {
  switch (dataType) {
    case Sensors::SensorDataType::ShuntVoltage:
      measureValue = shuntVoltage;
      return true;
    case Sensors::SensorDataType::BusVoltage:
      measureValue = busVoltage;
      return true;
    case Sensors::SensorDataType::Current:
      measureValue = current_mA;
      return true;
    case Sensors::SensorDataType::Power:
      measureValue = power_mW;
      return true;
    case Sensors::SensorDataType::LoadVoltage:
      measureValue = loadVoltage;
      return true;
    default:
      return false;
  }
}