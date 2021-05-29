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

void Storage::get(DataBuffer &emptyDataBuffer) {
  StorageLocation location = emptyDataBuffer.getStorageLocation();
  int length = location.getLength();
  int address = location.getAddress();
  byte *data = new byte[length];
  copyByte(address, data, length);
  emptyDataBuffer.setRawByte(data, length);
  emptyDataBuffer.parseData();
  delete []data;
}

void Storage::set(DataBuffer &dataBuffer) {
  StorageLocation location = dataBuffer.getStorageLocation();
  byte* target = dataBuffer.getRawByte();
  writeByte(target, location);
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

void Storage::clearAll() {
  int start = USERNAME_STORE_INDEX;
  int length = USERNAME_STORE_INDEX + STORAGE_COVER_RANGE;
  for (int i = start; i < length; i++) {
    EEPROM.write(i, 0);
    EEPROM.commit();
  }
}

// private

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

void Storage::writeByte(byte *target, StorageLocation location) {
  int length = location.getLength();
  int address = location.getAddress();
  for (int i = 0; i < length; i++) {
    EEPROM.write(address + i, *(target + i));
    EEPROM.commit();
  }
}