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
  for (int i = 0; i < length; i++)
    *(selectWifiName + i) = *(name + i);
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
  for (int i = 0; i < length; i++)
    *(selectWifiPassword + i) = *(password + i);
}

void TempStorage::freeSelectWifiPassword() {
  if (selectWifiPassword != NULL) {
    delete[] selectWifiPassword;
    selectWifiPassword = NULL;
    selectWifiPasswordLength = 0;
  }
}