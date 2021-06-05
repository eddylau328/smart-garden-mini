#include "BooleanData.h"


BooleanData::BooleanData(StorageLocation location) {
    setStorageLocation(location);
}

BooleanData::BooleanData(bool data, StorageLocation location) {
    setStorageLocation(location);
    setByteData(data);
    setData(data);
}

void BooleanData::parseData() {
    this->data = !(this->rawByte[0] == 0x00);
}

bool BooleanData::getData() {
    return this->data;
}

void BooleanData::setByteData(bool data) {
    this->storageLocation = storageLocation;
    this->rawByte = new byte[1];
    this->rawByte[0] = data? 0xFF : 0x00;
}

void BooleanData::setData(bool data) {
    this->data = data;
}