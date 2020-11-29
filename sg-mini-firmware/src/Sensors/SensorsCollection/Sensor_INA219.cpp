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
  Helper::handleWireBegin();  // Wire Begin
  isConnect = ina219->init();
  if(isConnect) {
    ina219->setADCMode(SAMPLE_MODE_128);
    ina219->setMeasureMode(CONTINUOUS);
  }
  return isConnect;
}

bool Sensor_INA219::read() {
  if (!isConnect) {
    // try reconnect
    init();
  }

  if (isConnect) {
    // Read data
    shuntVoltage = ina219->getShuntVoltage_mV();
    busVoltage = ina219->getBusVoltage_V();
    current_mA = ina219->getCurrent_mA();
    power_mW = ina219->getBusPower();
    loadVoltage = busVoltage + shuntVoltage / 1000.0;
    LOG_VERBOSE("Shunt Volt", shuntVoltage, "mV", "|", "Bus Volt", busVoltage, "V","|", "Current", current_mA, "mA","|", "Power", power_mW, "mW","|", "Load Volt", loadVoltage, "V");
  }

  return isConnect;  // Currently, no way to define wrong value or not
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