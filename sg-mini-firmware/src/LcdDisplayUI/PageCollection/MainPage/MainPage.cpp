#include "MainPage.h"


MainPage::MainPage(Sensors *sensors) {
  this->sensors = sensors;
}

MainPage::~MainPage() {}

void MainPage::mountPage() {
  int hour, min, sec;
  DeviceSetting::getTime(&hour, &min, &sec);
  contents[0].updateContent(hour, true);
  contents[2].updateContent(min, true);
}

void MainPage::getContents(PageContent **contents, int *length){
  *contents = this->contents;
  *length = *(&(this->contents) + 1) - this->contents;
}

void MainPage::updateContents() {
  int hour, min, sec;
  DeviceSetting::getTime(&hour, &min, &sec);
  contents[0].updateContent(hour, true);
  contents[2].updateContent(min, true);
  contents[1].updateContent(sec % 2 == 1? " " : ":", 1);
  if (sensors) {
    updateSensorData(SensorCollection::SensorDataType::Temp, 4);
    updateSensorData(SensorCollection::SensorDataType::Hum, 6);
  }
}

void MainPage::updateSensorData(SensorCollection::SensorDataType dataType, int contentIndex) {
  float value;
  bool isCorrect = sensors->getSensorData(dataType, value);
  if (isCorrect)
    this->contents[contentIndex].updateContent((int)round(value));
  else
    this->contents[contentIndex].updateContent("--", 2);
}