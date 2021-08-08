#include "UInt16Data.h"


UInt16Data::UInt16Data(StorageLocation location) {
    setStorageLocation(location);
}

UInt16Data::UInt16Data(uint16_t data, StorageLocation location) {
    setStorageLocation(location);
    setByteData(data);
    setData(data);
}

unsigned long UInt16Data::getData() {
    return this->data;
}

void UInt16Data::parseData() {
    this->data = 0;
    this->data |= this->rawByte[0] << 8;
    this->data |= this->rawByte[1];
}

void UInt16Data::setByteData(uint16_t data) {
    this->rawByte = new byte[2];
    this->rawByte[0] = (data & 0x0000FF00) >> 8;
    this->rawByte[1] = data & 0x000000FF;
}

void UInt16Data::setData(uint16_t data) {
    this->data = data;
}