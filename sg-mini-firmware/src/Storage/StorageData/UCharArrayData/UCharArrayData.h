#ifndef UCharArrayData_h
#define UCharArrayData_h


#include "../DataBuffer.h"


class UCharArrayData : public DataBuffer {
    public:
        UCharArrayData(unsigned char *data, StorageLocation location);
        UCharArrayData(StorageLocation location);
        ~UCharArrayData();

        unsigned char* getData();

        void parseData();

    private:
        unsigned char *data;
        void setByteData(unsigned char *data, StorageLocation storageLocation);
        void setData(unsigned char *data);

};

#endif