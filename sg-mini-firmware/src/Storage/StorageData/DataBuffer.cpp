#include "DataBuffer.h"


byte* DataBuffer::getRawByte() {
    return this->rawByte;
}

void DataBuffer::setRawByte(byte *rawData, int length) {
    this->rawByte = new byte[length];
    for (int i = 0; i < length; i++) 
        *(this->rawByte + i) = *(rawData + i);
}

StorageLocation DataBuffer::getStorageLocation() {
    return this->storageLocation;
}

void DataBuffer::setStorageLocation(StorageLocation location) {
    this->storageLocation = location;
}

void DataBuffer::parseData() {

}

DataBuffer::~DataBuffer() {
    if (this->rawByte)
        delete []this->rawByte;
}