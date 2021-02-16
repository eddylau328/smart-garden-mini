#include "WifiScan.h"

char **WifiScan::networks;
int WifiScan::networkCount = 0;
bool WifiScan::isScanNetwork = false;
int WifiScan::scanNetworkCount = 0;
uint8_t WifiScan::rescanNetworkCount = 0;


/* Public Methods */
int WifiScan::getNetworkCount(){
  return WifiScan::networkCount;
}

void WifiScan::getNetwork(char **name, int *length, int index) {
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

void WifiScan::startScanNetwork(uint8_t rescanCount) {
  isScanNetwork = true;
  rescanNetworkCount = rescanCount;
}

void WifiScan::stopScanNetwork() {
  isScanNetwork = false;
  rescanNetworkCount = 0;
}

bool WifiScan::isScanningNetwork() {
  return isScanNetwork;
}

/* Private Methods */
void WifiScan::setNetwork(String networkName, int index) {
  Helper::assignStrValue(networks[index], ' ', BufferSize);
  networkName.toCharArray(networks[index], BufferSize);
}

void WifiScan::initializeNetworks(int networkCount) {
  // Delete old memory allocation
  for (int i = 0; i < WifiScan::networkCount; i++)
    delete [] networks[i];
  delete [] networks;

  // set the new allocation size
  WifiScan::networkCount = networkCount;

  // Allocate new memory for the network
  networks = new char*[WifiScan::networkCount];
  for (int i = 0; i < WifiScan::networkCount; i++)
    networks[i] = new char[BufferSize];
}

void WifiScan::scanNetworks() {
  scanNetworkCount = WiFi.scanNetworks();
}

void WifiScan::handleScanNetworks(WiFiEvent_t event, WiFiEventInfo_t info) {
  initializeNetworks(scanNetworkCount);
  LOG_WARNING("Finish scan network");
  if (getNetworkCount() == 0)
    LOG_WARNING("No networks found");
  else
    for (int i = 0 ; i < getNetworkCount(); i++)
      setNetwork(WiFi.SSID(i), i);
}

/* Protected Methods */
void WifiScan::mainLoop() {
  if (isScanNetwork) {
    scanNetworks();
    rescanNetworkCount--;
    if (rescanNetworkCount <= 0)
      isScanNetwork = false;
  }
}