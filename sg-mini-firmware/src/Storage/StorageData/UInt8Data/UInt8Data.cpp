#include "UInt8Data.h"


void UInt8Data::setByteData(uint8_t data, StorageLocation storageLocation) {
    this->storageLocation = storageLocation;
    this->dataBuffer = new byte[1];
    dataBuffer[0] = byte(data);
}