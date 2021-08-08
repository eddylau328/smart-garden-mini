#include "Storage.h"

void Storage::init() {
  EEPROM.begin(STORAGE_COVER_RANGE);
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

void Storage::clearAll() {
  int start = USERNAME_STORE_INDEX;
  int length = USERNAME_STORE_INDEX + STORAGE_COVER_RANGE;
  for (int i = start; i < length; i++) {
    EEPROM.write(i, 0xFF);
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
    EEPROM.write(address + i, target[i]);
    EEPROM.commit();
  }
}