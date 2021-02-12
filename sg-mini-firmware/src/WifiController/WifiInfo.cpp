#include "WifiInfo.h"

char **WifiInfo::networks;
int WifiInfo::networkCount = 0;

/* Public Methods */
int WifiInfo::getNetworkCount(){
  return WifiInfo::networkCount;
}

void WifiInfo::getNetwork(char **name, int *length, int index) {
  if (Helper::intInRange(index, 0, networkCount)) {
    *name = networks[index];
    *length = BufferSize;
    for (int i = BufferSize - 1; i >= 0; i--)
      if (networks[index][i] == ' ')
        *length--;
      else
        break;
  }
  else
    *length = 0;
}


/* Protected Methods */
void WifiInfo::setNetwork(String networkName, int index) {
  Helper::assignStrValue(networks[index], ' ', BufferSize);
  networkName.toCharArray(networks[index], BufferSize);
}

void WifiInfo::initializeNetworks(int networkCount) {
  // Delete old memory allocation
  for (int i = 0; i < WifiInfo::networkCount; i++)
    delete [] networks[i];
  delete [] networks;

  // set the new allocation size
  WifiInfo::networkCount = networkCount;

  // Allocate new memory for the network
  networks = new char*[WifiInfo::networkCount];
  for (int i = 0; i < WifiInfo::networkCount; i++)
    networks[i] = new char[BufferSize];
}