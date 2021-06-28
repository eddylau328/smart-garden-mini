#include "CharArrayData.h"


CharArrayData::CharArrayData(StorageLocation location) {
    setStorageLocation(location);
}

CharArrayData::CharArrayData(char *data, StorageLocation location) {
    setStorageLocation(location);
    setByteData(data, location);
    setData(data);
}

CharArrayData::~CharArrayData() {
    if (this->data)
        delete []this->data;
}

void CharArrayData::setData(char *data) {
    int length = Helper::getStringLength(data);
    this->data = new char[length];
    Helper::copyString(this->data, data, length);
}

void CharArrayData::setByteData(char* data, StorageLocation storageLocation) {
    int totalLength = storageLocation.getLength();
    int strLength = Helper::getStringLength(data);
    this->rawByte = new byte[totalLength];
    for (int i = 0; i < totalLength; i++)
        if (i < strLength)
            *(this->rawByte + i) = byte(*(data + i));
        else
            *(this->rawByte + i) = byte('\0');
}

char* CharArrayData::getData() {
    return this->data;
}

void CharArrayData::parseData() {
    int length = this->storageLocation.getLength();
    this->data = new char[length];
    for (int i = 0; i < length; i++)
        *(this->data + i) = (char) *(rawByte + i);
}