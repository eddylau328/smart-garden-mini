#include "MainPage.h"


void MainPage::mountPage() {
  Page::allocateStaticContents(staticContents, 8);

  int hour, min, sec;
  DeviceSetting::getTime(&hour, &min, &sec);
  staticContents[ContentIndex::HOUR].updateContent(hour, true);
  staticContents[ContentIndex::MINUTE].updateContent(min, true);

  LocalSettingManager *localSettingManager = DeviceManager::getLocalSettingManager();
  const char* username = localSettingManager->getUserName();
  staticContents[ContentIndex::USERNAME].updateContent(username, USERNAME_LENGTH);
}

void MainPage::updateContents() {
  int hour, min, sec;
  DeviceSetting::getTime(&hour, &min, &sec);
  staticContents[ContentIndex::HOUR].updateContent(hour, true);
  staticContents[ContentIndex::MINUTE].updateContent(min, true);
  staticContents[ContentIndex::SECOND].updateContent(sec % 2 == 1? " " : ":", 1);
  
  updateSensorData(SensorCollection::SensorDataType::Temp, ContentIndex::TEMPERATURE);
  updateSensorData(SensorCollection::SensorDataType::Hum, ContentIndex::HUMIDITY);
}

void MainPage::updateSensorData(SensorCollection::SensorDataType dataType, int contentIndex) {
  float value;
  bool isCorrect = Sensors::getSensorData(dataType, value);
  if (isCorrect)
    staticContents[contentIndex].updateContent((int)round(value));
  else
    staticContents[contentIndex].updateContent("--", 2);
}