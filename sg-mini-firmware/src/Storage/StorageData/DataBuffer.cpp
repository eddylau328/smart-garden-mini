#include "DataBuffer.h"


const byte* DataBuffer::getDataBuffer() {
    return this->dataBuffer;
}

StorageLocation DataBuffer::getStorageLocation() {
    return this->storageLocation;
}

DataBuffer::~DataBuffer() {
    if (this->dataBuffer != nullptr)
        delete []this->dataBuffer;
}