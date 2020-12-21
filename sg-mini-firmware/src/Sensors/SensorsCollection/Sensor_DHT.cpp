

#include "Sensor_DHT.h"

Sensor_DHT::Sensor_DHT() {
  dht = new DHT(DHT_PIN, DHT_TYPE);
}

Sensor_DHT::~Sensor_DHT() {
  delete dht;
}

bool Sensor_DHT::init() {
  dht->begin();
  return read();
}

bool Sensor_DHT::read() {
  temp = dht->readTemperature();
  hum = dht->readHumidity();
  LOG_VERBOSE("Air Temp", temp, "deg C", "|", "Air Hum", hum, "%");
  
  isConnect = !(isnan(hum) || isnan(temp));
  return isConnect;
}  

bool Sensor_DHT::get(SensorCollection::SensorDataType dataType, float &measureValue) {
  if (dataType == SensorCollection::SensorDataType::Temp) {
    measureValue = temp;
    return true;
  }
  else if (dataType == SensorCollection::SensorDataType::Hum) {
    measureValue = hum;
    return true;
  }
  return false;
}