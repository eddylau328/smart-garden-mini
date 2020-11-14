

#include "Sensor_DHT.h"

Sensor_DHT::Sensor_DHT() {
  dht = new DHT(DHT_PIN, DHT_TYPE);
}

Sensor_DHT::~Sensor_DHT() {
  free(dht);
}

void Sensor_DHT::init() {
  dht->begin();

  // need to do connection test !!!  
  // if (isnan(h) || isnan(t) || isnan(f))
  // Serial.println(F("Failed to read from DHT sensor!"));
}

void Sensor_DHT::read() {
  float measure;
  measure = dht->readTemperature();
  Helper::getIntegerValue(measure, tempInt);
  Helper::getDecimalValue(measure, tempDec);

  measure = dht->readHumidity();
  Helper::getIntegerValue(measure, humInt);
  Helper::getDecimalValue(measure, humDec);
}

bool Sensor_DHT::get(Sensors::SensorDataType dataType, uint8_t integerValue, uint8_t decimalValue) {
  if (dataType == Sensors::SensorDataType::Temp) {
    integerValue = tempInt;
    decimalValue = tempDec;
    return true;
  }
  else if (dataType == Sensors::SensorDataType::Hum) {
    integerValue = humInt;
    decimalValue = humDec;
    return true;
  }
  return false;
}