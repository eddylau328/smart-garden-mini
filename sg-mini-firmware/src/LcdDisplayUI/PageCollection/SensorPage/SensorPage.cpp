#include "SensorPage.h"

SensorPage::SensorPage(Sensors *sensors) {
  this->sensors = sensors;
}

SensorPage::~SensorPage() {}

void SensorPage::getContents(PageContent **contents, int *length) {
  float value;
  // if sensors pointer is not null
  if (!sensors) {
    sensors->getSensorData(SensorCollection::SensorDataType::Temp, value);
    this->contents[3].updateContent(value, 2);

    sensors->getSensorData(SensorCollection::SensorDataType::Hum,  value);
    this->contents[4].updateContent(value, 2);
  }

  *contents = this->contents;
  *length = *(&(this->contents) + 1) - this->contents;
}