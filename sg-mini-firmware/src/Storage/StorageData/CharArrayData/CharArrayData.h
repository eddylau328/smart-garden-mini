#ifndef CharArrayData_h
#define CharArrayData_h


#include "../DataBuffer.h"


class CharArrayData : public DataBuffer {
    public:
        void setByteData(char *data, StorageLocation storageLocation);
};

#endif