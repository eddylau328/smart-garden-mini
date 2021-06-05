#ifndef Storage_h
#define Storage_h

#include <EEPROM.h>
#include <Arduino.h>
#include <DebugLog.h>
#include "StorageConstant.h"
#include "StorageData/DataBuffer.h"
#include "StorageData/StorageLocation.h"

/**
 * @brief provides functions for storing data to a hardware storage (Noted: currently using the device EEPROM for storing the data)
 * 
 */
class Storage {
  
  public:
    /**
     * @brief this enum Key structure holds all the start point of the address 
     * 
     */
    enum Key {
      UserName = 0,
    };

    /**
     * @brief initializes the connection between the storage device
     * 
     */
    static void init();
    
    /**
     * @brief get the serialized data from the storage device
     * 
     * @param key - the key of the data you want to get
     * @return byte* - the byte pointer pointing to the first element of the serialized data which store in a byte array 
     */
    static byte* get(Storage::Key key);

    static void get(DataBuffer &emptyDataBuffer);

    /**
     * @brief update the storage with new data
     * 
     * @param key - the key of the data you want to update
     * @param target - the byte pointer pointing to the first element of the serialized data which you want to update
     */
    static void set(Storage::Key key, byte* target);

    static void set(DataBuffer &data);

    static void clearAll();
  
  private:

    /**
     * @brief copy the byte from the storage within a range starting from a specified address 
     * 
     * @param address - the starting address of reading from the storage
     * @param target - the byte pointer for storing the data
     * @param length - the lenght of the byte array you store the data, also serves as the range for accessing the data in the storage 
     */
    static void copyByte(int address, byte *target, int length);

    /**
     * @brief write the byte to the storage from a byte array starting from a specified address
     * 
     * @param address - the starting address of writing to the storage 
     * @param target - the byte pointer for writing data to the storage
     * @param length - the length of the byte array you write to the storage, also serves as the range for writing the data to the storage
     */
    static void writeByte(int address, byte *target, int length);

    static void writeByte(byte *target, StorageLocation location);
};

#endif