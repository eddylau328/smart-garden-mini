#ifndef BooleanData_h
#define BooleanData_h


#include "../DataBuffer.h"

class BooleanData : public DataBuffer {
    public:
        void setByteData(bool data, StorageLocation storageLocation);
};

#endif