#include "UInt32Data.h"


UInt32Data::UInt32Data(StorageLocation location) {
    setStorageLocation(location);
}

UInt32Data::UInt32Data(unsigned long data, StorageLocation location) {
    setStorageLocation(location);
    setByteData(data);
    setData(data);
}

unsigned long UInt32Data::getData() {
    return this->data;
}

void UInt32Data::parseData() {
    this->data = 0;
    this->data |= this->rawByte[0] << 24;
    this->data |= this->rawByte[1] << 16;
    this->data |= this->rawByte[2] << 8;
    this->data |= this->rawByte[3];
}

void UInt32Data::setByteData(unsigned long data) {
    this->rawByte = new byte[4];
    this->rawByte[0] = (data & 0xFF000000) >> 24;
    this->rawByte[1] = (data & 0x00FF0000) >> 16;
    this->rawByte[2] = (data & 0x0000FF00) >> 8;
    this->rawByte[3] = data & 0x000000FF;
}

void UInt32Data::setData(unsigned long data) {
    this->data = data;
}