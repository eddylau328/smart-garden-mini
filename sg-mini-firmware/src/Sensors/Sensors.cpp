/*
  Sensors.cpp - library for access all the sensors
*/

#include "Sensors.h"

Sensors::Sensors(){
  sensorList[DHT_Key] = new Sensor_DHT();
  sensorList[DS18B20_Key] = new Sensor_DS18B20();
  sensorList[SoilHumidity_Key] = new Sensor_SoilHumidity();
  sensorList[MAX44009_Key] = new Sensor_MAX44009();
  sensorList[UltraSound_Key] = new Sensor_UltraSound();
  sensorList[INA219_Key] = new Sensor_INA219();
}

Sensors::~Sensors(){
  // free the allocated memory and delete the object
  for (int i = 0 ; i < TotalSensors; i++)
    delete sensorList[i];
}