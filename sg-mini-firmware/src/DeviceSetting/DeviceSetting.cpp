#include "DeviceSetting.h"

char DeviceSetting::userName[UserNameLength];

void DeviceSetting::init() {
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