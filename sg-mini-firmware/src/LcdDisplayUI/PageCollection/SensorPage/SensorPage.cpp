#include "SensorPage.h"

SensorPage::SensorPage() {
  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 5));
}

void SensorPage::mountPage() {
  Page::allocateStaticContents(staticContents, 12);
  scroll.resetScroll(contents, contentSize);
}

void SensorPage::updateContents() {
  updateSensorData(SensorCollection::SensorDataType::Temp, 6);
  updateSensorData(SensorCollection::SensorDataType::Hum, 7);
  updateSensorData(SensorCollection::SensorDataType::SoilTemp, 8);
  updateSensorData(SensorCollection::SensorDataType::SoilHum, 9);
  updateSensorData(SensorCollection::SensorDataType::Light, 10);
  updateSensorData(SensorCollection::SensorDataType::WaterLevel, 11);
}

void SensorPage::interactiveUpdate(int counter, bool isPress) {
  scroll.updateScroll(contents, contentSize, counter);
  Page::interactiveUpdate(counter, isPress);
}

void SensorPage::updateSensorData(SensorCollection::SensorDataType dataType, int contentIndex) {
  float value;
  bool isCorrect = Sensors::getSensorData(dataType, value);
  if (isCorrect)
    staticContents[contentIndex].updateContent(value, 1);
  else
    staticContents[contentIndex].updateContent("NULL", 4);
}