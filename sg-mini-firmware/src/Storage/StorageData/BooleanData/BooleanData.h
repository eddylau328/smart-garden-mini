#ifndef BooleanData_h
#define BooleanData_h


#include "../DataBuffer.h"

class BooleanData : public DataBuffer {
    public:
        BooleanData(StorageLocation location);
        BooleanData(bool data, StorageLocation location);

        void parseData();
        bool getData();
    
    private:
        void setByteData(bool data);
        void setData(bool data);

        bool data;
};

#endif