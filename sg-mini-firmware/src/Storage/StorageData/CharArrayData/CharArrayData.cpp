#include "CharArrayData.h"


void CharArrayData::setByteData(char* data, StorageLocation storageLocation) {
    this->storageLocation = storageLocation;
    int totalLength = storageLocation.getLength();
    int strLength = Helper::getStringLength(data);
    this->dataBuffer = new byte[totalLength];
    for (int i = 0; i < totalLength; i++)
        if (i < strLength)
            *(this->dataBuffer + i) = byte(*(data + i));
        else
            *(this->dataBuffer + i) = byte('\0');
}