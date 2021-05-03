#include "DeviceSetting.h"

char DeviceSetting::userName[UserNameLength];
DS1307 DeviceSetting::clock;
uint8_t DeviceSetting::time[3];
uint8_t DeviceSetting::date[4];
bool DeviceSetting::wifiMode = false;
unsigned long DeviceSetting::lastTimeRecord;
uint8_t DeviceSetting::WateringDuration; //set the second the pump will be on
uint8_t DeviceSetting::ScheduleTime[3];// set what time the pump will be on
uint8_t DeviceSetting::HumidityLevel;

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
  if (Helper::isInRange(hour, 0, 23) && Helper::isInRange(minute, 0, 59) && Helper::isInRange(second, 0, 59)) {
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
  if (Helper::isValidDate(year, month, day) && Helper::isInRange(dayOfWeek, MON , SUN)) {
    clock.fillByYMD(year, month, day);
    clock.fillDayOfWeek(dayOfWeek);//Saturday
    clock.setTime();
  }
}

void DeviceSetting::setWifiMode(bool isWifiMode) {
  wifiMode = isWifiMode;
}

bool DeviceSetting::getWifiMode() {
  return wifiMode;
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


void DeviceSetting::setScheduleTime(int hour, int minute, int second) {
  if (Helper::isInRange(hour, 0, 23) && Helper::isInRange(minute, 0, 59) && Helper::isInRange(second, 0, 59)) {
    
  }
}

void DeviceSetting::getScheduleTime(int *hour, int *minute, int *second) {
  *hour = ScheduleTime[0];
  *minute = ScheduleTime[1];
  *second = ScheduleTime[2];
}

void DeviceSetting::setHumiditySetLevel(int HumidityLevel){
  if(Helper::isInRange(HumidityLevel,0,100)){

  }
  

}
float DeviceSetting::getHumiditySetLevel(int *humidity){
  *humidity = HumidityLevel;
  return(HumidityLevel);
}

