#include "MainPage.h"


void MainPage::mountPage() {
  Page::allocateStaticContents(staticContents, 7);

  int hour, min, sec;
  DeviceSetting::getTime(&hour, &min, &sec);
  staticContents[0].updateContent(hour, true);
  staticContents[2].updateContent(min, true);
}

void MainPage::updateContents() {
  int hour, min, sec;
  DeviceSetting::getTime(&hour, &min, &sec);
  staticContents[0].updateContent(hour, true);
  staticContents[2].updateContent(min, true);
  staticContents[1].updateContent(sec % 2 == 1? " " : ":", 1);
  
  updateSensorData(SensorCollection::SensorDataType::Temp, 4);
  updateSensorData(SensorCollection::SensorDataType::Hum, 6);
}

void MainPage::updateSensorData(SensorCollection::SensorDataType dataType, int contentIndex) {
  float value;
  bool isCorrect = Sensors::getSensorData(dataType, value);
  if (isCorrect)
    staticContents[contentIndex].updateContent((int)round(value));
  else
    staticContents[contentIndex].updateContent("--", 2);
}