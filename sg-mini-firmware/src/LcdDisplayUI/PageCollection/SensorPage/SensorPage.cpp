#include "SensorPage.h"

SensorPage::SensorPage(Sensors *sensors) {
  this->sensors = sensors;
}

SensorPage::~SensorPage() {}

void SensorPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = *(&(this->contents) + 1) - this->contents;
}

void SensorPage::updateContents() {
  float value;
  bool isCorrect;
  // if sensors pointer is not null
  if (sensors) {
    isCorrect = sensors->getSensorData(SensorCollection::SensorDataType::Temp, value);
    
    if (isCorrect)
      this->contents[2].updateContent(value, 2);
    else
      this->contents[2].updateContent("NULL", 4);

    isCorrect = sensors->getSensorData(SensorCollection::SensorDataType::Hum,  value);

    if (isCorrect)
      this->contents[3].updateContent(value, 2);
    else
      this->contents[3].updateContent("NULL", 4);
  }
}