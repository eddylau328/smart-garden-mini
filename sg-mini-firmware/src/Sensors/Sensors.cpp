/*
  Sensors.cpp - library for access all the sensors
*/

#include "Sensors.h"

Sensor *Sensors::sensorList[TotalSensors];
unsigned long Sensors::lastBatchRead;
unsigned long Sensors::lastSensorRead;
uint8_t Sensors::currentReadIndex = 0;
bool Sensors::isStartRead = true;

void Sensors::init() {
  sensorList[DHT_Key] = new Sensor_DHT();
  sensorList[DS18B20_Key] = new Sensor_DS18B20();
  sensorList[SoilHumidity_Key] = new Sensor_SoilHumidity();
  sensorList[MAX44009_Key] = new Sensor_MAX44009();
  sensorList[UltraSound_Key] = new Sensor_UltraSound();
  sensorList[INA219_Key] = new Sensor_INA219();

  int8_t sensorCount = 0;
  bool isConnected = false;
  for (int i = 0 ; i < TotalSensors; i++) {
    isConnected = sensorList[i]->init();
    isConnected ? sensorCount++ : sensorCount;
    LOG_WARNING(SensorCollection::getSensorName(i), "Connect", isConnected? "Success" : "Failed");
  }
  LOG_WARNING("Total Connected Sensors:", sensorCount);
}

void Sensors::mainLoop() {
  if (millis() - lastBatchRead > 5000 && !isStartRead) {
    isStartRead = true;
    lastBatchRead = millis();
  }
  if (isStartRead){
    if (millis() - lastSensorRead > 100) {
      LOG_ERROR(currentReadIndex, millis() - lastSensorRead);
      read(currentReadIndex);
      LOG_ERROR(currentReadIndex, millis() - lastSensorRead);
      currentReadIndex++;
      lastSensorRead = millis();

      if (currentReadIndex >= TotalSensors) {
        isStartRead = false;
        currentReadIndex = 0;
      }
    }
  }
}

bool Sensors::getSensorData(SensorCollection::SensorDataType dataType, float &data) {
  return (sensorList[SensorCollection::getSensorListKey(dataType)]->get(dataType, data) &&
          sensorList[SensorCollection::getSensorListKey(dataType)]->isConnected());
}

void Sensors::read(uint8_t index) {
  bool isSuccess;
  isSuccess = sensorList[index]->read();
  LOG_WARNING(SensorCollection::getSensorName(index), "Read", isSuccess? "Success" : "Failed");
}