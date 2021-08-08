#include "UInt8Data.h"


UInt8Data::UInt8Data(StorageLocation location) {
    setStorageLocation(location);
}

UInt8Data::UInt8Data(uint8_t data, StorageLocation location) {
    setStorageLocation(location);
    setByteData(data);
    setData(data);
}

uint8_t UInt8Data::getData() {
    return this->data;
}

void UInt8Data::parseData() {
    this->data = (uint8_t) this->rawByte[0];
}

void UInt8Data::setByteData(uint8_t data) {
    this->rawByte = new byte[1];
    rawByte[0] = byte(data);
}

void UInt8Data::setData(uint8_t data) {
    this->data = data;
}