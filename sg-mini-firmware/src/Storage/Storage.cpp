#include "Storage.h"

// need to destroy the pointer after using it
byte* Storage::get(Storage::Key key){
  byte *target;
  switch (key) {
    case Storage::Key::UserName:
      target = new byte[UserNameLength];
      copyByte(Storage::Key::UserName, target, UserNameLength);
      return target;
    default:
      return NULL;
  }
}

void Storage::set(Storage::Key key, byte* target) {
  switch (key) {
  case Storage::Key::UserName:
    for (int i = 0 ; i < UserNameLength; i++)
      EEPROM.write(key + i, *(target+i));
    break;
  default:
    break;
  }
}

void Storage::copyByte(int address, byte *target, int length) {
  for (int i = 0; i < length ; i++)
    *(target + i) = EEPROM.read(address + i);
}