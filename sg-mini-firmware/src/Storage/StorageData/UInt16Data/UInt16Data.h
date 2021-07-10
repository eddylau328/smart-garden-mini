#ifndef UInt16Data_h
#define UInt16Data_h


#include "../DataBuffer.h"

class UInt16Data : public DataBuffer {
    public:
        UInt16Data(StorageLocation location);
        UInt16Data(uint16_t data, StorageLocation location);

        void parseData();
        unsigned long getData();
    
    private:
        void setByteData(uint16_t data);
        void setData(uint16_t data);
    
        uint16_t data;
};

#endif