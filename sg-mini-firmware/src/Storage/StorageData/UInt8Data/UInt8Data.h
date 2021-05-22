#ifndef UInt8Data_h
#define UInt8Data_h


#include "../DataBuffer.h"

class UInt8Data : public DataBuffer {
    public:
        UInt8Data(StorageLocation location);
        UInt8Data(uint8_t data, StorageLocation location);

        void parseData();
        uint8_t getData();
    
    private:
        void setByteData(uint8_t data);
        void setData(uint8_t data);
    
        uint8_t data;
};

#endif