#ifndef DataBuffer_h
#define DataBuffer_h

#include <Arduino.h>
#include "../../Helper/Helper.h"
#include "StorageLocation.h"

class DataBuffer {

    public:
        ~DataBuffer();

        byte* getRawByte();
        void setRawByte(byte *rawData, int length);

        StorageLocation getStorageLocation();
        void setStorageLocation(StorageLocation location);

        virtual void parseData();
        
    protected:
        byte *rawByte;
        StorageLocation storageLocation;
};


#endif