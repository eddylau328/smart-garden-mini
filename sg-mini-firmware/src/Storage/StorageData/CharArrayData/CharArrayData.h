#ifndef CharArrayData_h
#define CharArrayData_h


#include "../DataBuffer.h"


class CharArrayData : public DataBuffer {
    public:
        CharArrayData(char *data, StorageLocation location);
        CharArrayData(StorageLocation location);
        ~CharArrayData();

        char* getData();

        void parseData();

        char *data;
    private:
        void setByteData(char *data, StorageLocation storageLocation);
        void setData(char *data);

};

#endif