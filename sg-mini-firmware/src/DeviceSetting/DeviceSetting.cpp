#include "DeviceSetting.h"

char DeviceSetting::userName[UserNameLength];
DS1307 DeviceSetting::clock;
uint8_t DeviceSetting::time[3];
uint8_t DeviceSetting::date[4];
unsigned long DeviceSetting::lastTimeRecord;

void DeviceSetting::init() {
  Storage::init();
  clock.begin();

  byte *data = Storage::get(Storage::Key::UserName);
  for (int i = 0; i < UserNameLength; i++) {
    *(userName + i) = char(*(data + i));
  }
  delete data;
}

void DeviceSetting::getUserName(char **userName, int *length) {
  *userName = DeviceSetting::userName;
  for (int i = UserNameLength - 1; i >= 0 ; i--)
    if (*(DeviceSetting::userName + i) != ' ') {
      *length = i + 1;
      break;
    }
}

void DeviceSetting::setUserName(char *newUserName, int length) {
  for (int i = 0 ; i < UserNameLength; i++)
    if (i < length)
      *(userName + i) = *(newUserName + i);
    else
      *(userName + i) = ' ';
  byte *target = new byte[UserNameLength];
  for (int i = 0; i < UserNameLength; i++)
    *(target + i) = byte(*(userName + i));
  Storage::set(Storage::Key::UserName, target);
  delete[] target;
}

void DeviceSetting::setTime(int hour, int minute, int second) {
  if (Helper::intInRange(hour, 0, 23) && Helper::intInRange(minute, 0, 59) && Helper::intInRange(second, 0, 59)) {
    clock.fillByHMS(hour, minute, second);
    clock.setTime();//write time to the RTC chip
  }
}

void DeviceSetting::getTime(int *hour, int *minute, int *second) {
  *hour = time[0];
  *minute = time[1];
  *second = time[2];
}

void DeviceSetting::getDate(int *year, int *month, int *day, int *dayOfWeek) {
  *year = ((int)date[0]) + 2000;
  *month = date[1];
  *day = date[2];
  *dayOfWeek = date[3];
}

void DeviceSetting::setDate(int year, int month, int day, int dayOfWeek) {
  if (Helper::isValidDate(year, month, day) && Helper::intInRange(dayOfWeek, MON , SUN)) {
    clock.fillByYMD(year, month, day);
    clock.fillDayOfWeek(dayOfWeek);//Saturday
    clock.setTime();
  }
}

void DeviceSetting::mainLoop() {
  if (millis() - lastTimeRecord > 200) {
    clock.getTime();
    time[0] = clock.hour;
    time[1] = clock.minute;
    time[2] = clock.second;
    date[0] = clock.year;
    date[1] = clock.month;
    date[2] = clock.dayOfMonth;
    date[3] = clock.dayOfWeek;
  }
}

void DeviceSetting::ControllerModeUpdate (DeviceSetting::ControllerMode CurrentMode, DeviceSetting::ControllerMode UpdatedMode){
  if (!(CurrentMode == UpdatedMode)){
  switch (UpdatedMode)
  {
  case DeviceSetting::ControllerMode::HumidMode:
    //DeviceSetting::HumiditySetlevel == something;
    DeviceSetting::WateringSettime = 2000;  // 2000ms i guess the unit is     
    break;

  case DeviceSetting::ControllerMode::ScheduleMode:
    /* code */
    DeviceSetting::WateringSettime = 5000;
    break;

  case DeviceSetting::ControllerMode::ManualMode:
    /* code */
    DeviceSetting::WateringSettime = 0;
    break;
  }
  CurrentMode == UpdatedMode;
  }

}

float DeviceSetting::getHumiditylevel(){
  float humiditylevel;
  Sensors::getSensorData(SensorCollection::SensorDataType::SoilHum, humiditylevel);
  return(humiditylevel);
}