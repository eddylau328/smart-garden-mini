#include "MainPage.h"


void MainPage::mountPage() {
  Page::allocateStaticContents(staticContents, 9);

  LocalSettingManager *manager = DeviceManager::getLocalSettingManager();
  DateTime dateTime = manager->getDeviceDateTime();
  staticContents[ContentIndex::HOUR].updateContent((int) dateTime.hour(), true);
  staticContents[ContentIndex::MINUTE].updateContent((int) dateTime.minute(), true);

  const char* username = manager->getUsername();
  staticContents[ContentIndex::USERNAME].updateContent(username, USERNAME_LENGTH);

  updateWifiStatus();
}

void MainPage::updateContents() {
  LocalSettingManager *manager = DeviceManager::getLocalSettingManager();
  DateTime dateTime = manager->getDeviceDateTime();
  staticContents[ContentIndex::HOUR].updateContent((int) dateTime.hour(), true);
  staticContents[ContentIndex::MINUTE].updateContent((int) dateTime.minute(), true);
  staticContents[ContentIndex::SECOND].updateContent((int) dateTime.second() % 2 == 1 ? " " : ":", 1);
  
  updateSensorData(SensorCollection::SensorDataType::Temp, ContentIndex::TEMPERATURE);
  updateSensorData(SensorCollection::SensorDataType::Hum, ContentIndex::HUMIDITY);

  updateWifiStatus();
}

void MainPage::updateSensorData(SensorCollection::SensorDataType dataType, int contentIndex) {
  float value;
  bool isCorrect = Sensors::getSensorData(dataType, value);
  if (isCorrect)
    staticContents[contentIndex].updateContent((int)round(value));
  else
    staticContents[contentIndex].updateContent("--", 2);
}

void MainPage::updateWifiStatus() {
  WifiSettingManager *settingManager = DeviceManager::getWifiSettingManager();
  bool isWifiOn = settingManager->getIsWifiOn();
  bool isConnectWifi = WifiController::isConnectedNetwork();

  int8_t characterIndex;
  if (isWifiOn && isConnectWifi)
    characterIndex = CUSTOM_WIFI_CONNECTED;
  else if (isWifiOn)
    characterIndex = CUSTOM_WIFI_DISCONNECTED;
  else
    characterIndex = CUSTOM_WIFI_OFF;

  staticContents[ContentIndex::WIFI_STATUS].setCustomCharacterIndex(characterIndex);
}