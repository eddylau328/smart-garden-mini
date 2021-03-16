#ifndef TempStorage_h
#define TempStorage_h

#include <Arduino.h>
#include "../../Helper/Helper.h"

class TempStorage {
  public:
    static void getSelectWifiName(char **str, int *length);
    static void setSelectWifiName(char *name, int length);
    static void freeSelectWifiName();
    static void getSelectWifiPassword(char **str, int *length);
    static void setSelectWifiPassword(char *password, int length);
    static void freeSelectWifiPassword();

  private:
    static int selectWifiNameLength;
    static char *selectWifiName;
    static char *selectWifiPassword;
    static int selectWifiPasswordLength;

};

#endif