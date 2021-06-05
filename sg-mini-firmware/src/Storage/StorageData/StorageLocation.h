#ifndef StorageData_h
#define StorageData_h

#include <Arduino.h>

class StorageLocation {

    public:
        StorageLocation();
        StorageLocation(int length, int address);
        void operator = (const StorageLocation &storageLocation);
        int getLength();
        int getAddress();

    private:
        int length;
        int address;
};


#endif