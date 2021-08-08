#include "UCharArrayData.h"


UCharArrayData::UCharArrayData(StorageLocation location) {
    setStorageLocation(location);
}

UCharArrayData::UCharArrayData(unsigned char *data, StorageLocation location) {
    setStorageLocation(location);
    setByteData(data, location);
    setData(data);
}

UCharArrayData::~UCharArrayData() {
    if (this->data)
        delete []this->data;
}

void UCharArrayData::setData(unsigned char *data) {
    int length = Helper::getStringLength(data);
    this->data = new unsigned char[length];
    Helper::copyUInt8_t(this->data, data, length);
}

void UCharArrayData::setByteData(unsigned char* data, StorageLocation storageLocation) {
    int totalLength = storageLocation.getLength();
    int strLength = Helper::getStringLength(data);
    this->rawByte = new byte[totalLength];
    for (int i = 0; i < totalLength; i++)
        if (i < strLength)
            *(this->rawByte + i) = byte(*(data + i));
        else
            *(this->rawByte + i) = byte('\0');
}

unsigned char* UCharArrayData::getData() {
    return this->data;
}

void UCharArrayData::parseData() {
    int length = this->storageLocation.getLength();
    this->data = new unsigned char[length];
    for (int i = 0; i < length; i++)
        *(this->data + i) = (unsigned char) *(rawByte + i);
}