#include "Storage.h"

void Storage::init() {
  EEPROM.begin(TotalStorageSize);
}

// need to destroy the pointer after using it
byte* Storage::get(Storage::Key key){
  byte *target;
  switch (key) {
    case Storage::Key::UserName:
      target = new byte[UserNameLength];
      copyByte(key, target, UserNameLength);
      return target;
    default:
      return NULL;
  }
}

void Storage::set(Storage::Key key, byte* target) {
  switch (key) {
    case Storage::Key::UserName:
      writeByte(key, target, UserNameLength);
      break;
    default:
      break;
  }
}

void Storage::copyByte(int address, byte *target, int length) {
  for (int i = 0; i < length ; i++) {
    *(target + i) = EEPROM.read(address + i);
    // LOG_ERROR(EEPROM.read(address + i));
  }
}

void Storage::writeByte(int address, byte *target, int length) {
  for (int i = 0; i < length; i++) {
    EEPROM.write(address + i, *(target+i));
    EEPROM.commit();
    // LOG_ERROR(*(target + i));
  }
}