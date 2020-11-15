

#include "Sensor_DHT.h"

Sensor_DHT::Sensor_DHT() {
  dht = new DHT(DHT_PIN, DHT_TYPE);
}

Sensor_DHT::~Sensor_DHT() {
  free(dht);
}

bool Sensor_DHT::init() {
  dht->begin();

  // need to do connection test !!!  
  // if (isnan(h) || isnan(t) || isnan(f))
  // Serial.println(F("Failed to read from DHT sensor!"));
  return true; // for now
}

void Sensor_DHT::read() {
  temp = dht->readTemperature();
  hum = dht->readHumidity();
}

bool Sensor_DHT::get(Sensors::SensorDataType dataType, float &measureValue) {
  if (dataType == Sensors::SensorDataType::Temp) {
    measureValue = temp;
    return true;
  }
  else if (dataType == Sensors::SensorDataType::Hum) {
    measureValue = hum;
    return true;
  }
  return false;
}