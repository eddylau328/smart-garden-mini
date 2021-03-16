#include "TempStorage.h"

int TempStorage::selectWifiNameLength = 0;
char *TempStorage::selectWifiName = NULL;
int TempStorage::selectWifiPasswordLength = 0;
char *TempStorage::selectWifiPassword = NULL;

void TempStorage::getSelectWifiName(char **str, int *length) { 
  *str = selectWifiName;
  *length = selectWifiNameLength;
}

void TempStorage::setSelectWifiName(char *name, int length) {
  selectWifiName = new char[length];
  Helper::copyString(selectWifiName, name, length);
  selectWifiNameLength = length;
}

void TempStorage::freeSelectWifiName() {
  if (selectWifiName != NULL) {
    delete[] selectWifiName;
    selectWifiName = NULL;
    selectWifiNameLength = 0;
  }
}

void TempStorage::getSelectWifiPassword(char **str, int *length) {
  *str = selectWifiPassword;
  *length = selectWifiPasswordLength;
}

void TempStorage::setSelectWifiPassword(char *password, int length) {
  selectWifiPassword = new char[length];
  Helper::copyString(selectWifiName, password, length);
  selectWifiPasswordLength = length;
}

void TempStorage::freeSelectWifiPassword() {
  if (selectWifiPassword != NULL) {
    delete[] selectWifiPassword;
    selectWifiPassword = NULL;
    selectWifiPasswordLength = 0;
  }
}