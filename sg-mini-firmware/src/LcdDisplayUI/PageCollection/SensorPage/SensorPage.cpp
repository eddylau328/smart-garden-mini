#include "SensorPage.h"

SensorPage::SensorPage(Sensors *sensors) {
  this->sensors = sensors;
  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 5));
}

SensorPage::~SensorPage() {
}

void SensorPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
}

void SensorPage::updateContents() {
  // if sensors pointer is not null
  if (sensors) {
    updateSensorData(SensorCollection::SensorDataType::Temp, 6);
    updateSensorData(SensorCollection::SensorDataType::Hum, 7);
    updateSensorData(SensorCollection::SensorDataType::SoilTemp, 8);
    updateSensorData(SensorCollection::SensorDataType::SoilHum, 9);
    updateSensorData(SensorCollection::SensorDataType::Light, 10);
    updateSensorData(SensorCollection::SensorDataType::WaterLevel, 11);
  }
}

void SensorPage::interactiveUpdate(int counter, bool isPress) {
  scroll.updateScroll(contents, contentSize, counter);
}

void SensorPage::updateSensorData(SensorCollection::SensorDataType dataType, int contentIndex) {
  float value;
  bool isCorrect = sensors->getSensorData(dataType, value);
  if (isCorrect)
    this->contents[contentIndex].updateContent(value, 1);
  else
    this->contents[contentIndex].updateContent("NULL", 4);
}