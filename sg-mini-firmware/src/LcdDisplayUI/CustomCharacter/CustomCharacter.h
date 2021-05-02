/*
  CustomCharacter.h - used to define custom character you want to show in your lcd monitor
*/

#ifndef CustomCharacter_h
#define CustomCharacter_h

#define CUSTOM_BACKSLASH 0
#define CUSTOM_ENTER 1
#define CUSTOM_BACKSPACE 2

class CustomCharacter {
  public:
    static unsigned char BACKSLASH[8];
    static unsigned char ENTER[8];
    static unsigned char BACKSPACE[8];
    static unsigned char WIFICONNECTED[8];
    static unsigned char WIFIDISCONNECTED[8];
    static unsigned char WIFIOFF[8];
};

#endif