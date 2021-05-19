#include "StorageLocation.h"


StorageLocation::StorageLocation() {
    this->address = 0;
    this->length = 0;
}

StorageLocation::StorageLocation(int length, int address) {
    this->address = address;
    this->length = length;
}

void StorageLocation::operator = (const StorageLocation &storageLocation) {
    this->address = storageLocation.address;
    this->length = storageLocation.length;
}

int StorageLocation::getAddress() {
    return this->address;
}

int StorageLocation::getLength() {
    return this->length;
}