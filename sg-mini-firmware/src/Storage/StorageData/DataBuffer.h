#ifndef DataBuffer_h
#define DataBuffer_h

#include <Arduino.h>
#include "../../Helper/Helper.h"
#include "StorageLocation.h"

class DataBuffer {

    public:
        ~DataBuffer();
        const byte* getDataBuffer();
        StorageLocation getStorageLocation();
        
    protected:
        byte *dataBuffer = nullptr;
        StorageLocation storageLocation;
};


#endif