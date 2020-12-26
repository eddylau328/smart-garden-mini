#ifndef Storage_h
#define Storage_h

#include <EEPROM.h>
#include <Arduino.h>
#include <DebugLog.h>
#include "StorageConstant.h"
class Storage {
  
  public:
    enum Key {
      UserName = 0,
    };
    static void init();
    static byte* get(Storage::Key key);
    static void set(Storage::Key key, byte* target);
  
  private:
    static void copyByte(int address, byte *target, int length);
    static void writeByte(int address, byte *target, int length);
};

#endif