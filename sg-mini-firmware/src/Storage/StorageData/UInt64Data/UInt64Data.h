#ifndef UInt64Data_h
#define UInt64Data_h


#include "../DataBuffer.h"

class UInt64Data : public DataBuffer {
    public:
        UInt64Data(StorageLocation location);
        UInt64Data(unsigned long data, StorageLocation location);

        void parseData();
        unsigned long getData();
    
    private:
        void setByteData(unsigned long data);
        void setData(unsigned long data);
    
        unsigned long data;
};

#endif