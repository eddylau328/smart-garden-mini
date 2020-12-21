#ifndef Storage_h
#define Storage_h

#include <EEPROM.h>
#include <Arduino.h>

#define UserNameLength 10

class Storage {
  
  public:
    enum Key {
      UserName = 0,
    };

    static byte* get(Storage::Key key);
    static void set(Storage::Key key, byte* target);
  
  private:
    static void copyByte(int address, byte *target, int length);
};

#endif