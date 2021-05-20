#ifndef UInt8Data_h
#define UInt8Data_h


#include "../DataBuffer.h"

class UInt8Data : public DataBuffer {
    public:
        void setByteData(uint8_t data, StorageLocation storageLocation);
};

#endif