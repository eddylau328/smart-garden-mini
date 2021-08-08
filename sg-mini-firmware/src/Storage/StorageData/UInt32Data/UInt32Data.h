#ifndef UInt32Data_h
#define UInt32Data_h


#include "../DataBuffer.h"

class UInt32Data : public DataBuffer {
    public:
        UInt32Data(StorageLocation location);
        UInt32Data(unsigned long data, StorageLocation location);

        void parseData();
        unsigned long getData();
    
    private:
        void setByteData(unsigned long data);
        void setData(unsigned long data);
    
        unsigned long data;
};

#endif