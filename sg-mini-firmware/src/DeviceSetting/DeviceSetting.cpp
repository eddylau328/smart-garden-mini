#include "DeviceSetting.h"

char DeviceSetting::userName[UserNameLength];
DS1307 DeviceSetting::clock;
uint8_t DeviceSetting::time[3];
unsigned long DeviceSetting::lastTimeRecord;

void DeviceSetting::init() {
  clock.begin();

  byte *data = Storage::get(Storage::Key::UserName);
  for (int i = 0; i < UserNameLength; i++) {
    *(userName + i) = *(data + i);
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
  Storage::set(Storage::Key::UserName, target);
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

void DeviceSetting::mainLoop() {
  if (millis() - lastTimeRecord > 400) {
    clock.getTime();
    time[0] = clock.hour;
    time[1] = clock.minute;
    time[2] = clock.second;
  }
}