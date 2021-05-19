#include "BooleanData.h"


void BooleanData::setByteData(bool data, StorageLocation storageLocation) {
    this->storageLocation = storageLocation;
    dataBuffer = new byte[1];
    dataBuffer[0] = data? 1 : 0;
}