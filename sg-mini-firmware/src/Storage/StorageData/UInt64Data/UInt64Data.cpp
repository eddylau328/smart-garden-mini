#include "UInt64Data.h"


UInt64Data::UInt64Data(StorageLocation location) {
    setStorageLocation(location);
}

UInt64Data::UInt64Data(unsigned long data, StorageLocation location) {
    setStorageLocation(location);
    setByteData(data);
    setData(data);
}

unsigned long UInt64Data::getData() {
    return this->data;
}

void UInt64Data::parseData() {
    this->data = 0;
    this->data |= this->rawByte[0] << 24;
    this->data |= this->rawByte[1] << 16;
    this->data |= this->rawByte[2] << 8;
    this->data |= this->rawByte[3];
}

void UInt64Data::setByteData(unsigned long data) {
    this->rawByte = new byte[4];
    this->rawByte[0] = (data & 0xFF000000) >> 24;
    this->rawByte[1] = (data & 0x00FF0000) >> 16;
    this->rawByte[2] = (data & 0x0000FF00) >> 8;
    this->rawByte[3] = data & 0x000000FF;
}

void UInt64Data::setData(unsigned long data) {
    this->data = data;
}