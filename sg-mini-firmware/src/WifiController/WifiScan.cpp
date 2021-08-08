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

void WifiScan::getNetwork(char *name, int *length, int index, int nameBufferSize) {
  if (Helper::isInRange(index, 0, networkCount)) {
    *length = (int) Helper::getStringLength(networks[index]);
    Helper::copyString(name, networks[index], *length);
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
    delete networks[i];
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
  LOG_WARNING("Finish scan network");
  if (getScanNetworkCount() == 0) {
    LOG_WARNING("No networks found");
  }
  else {
    int validateNetworkIndexes[10], validateNetworkCount = 0, bufferSize = 10;
    getValidateNetworkIndexes(validateNetworkIndexes, &validateNetworkCount, bufferSize);
    LOG_ERROR(validateNetworkCount);
    for (int i = 0; i < validateNetworkCount; i++)
      LOG_ERROR(validateNetworkIndexes[i]);
    initializeNetworks(validateNetworkCount);
    setValidateNetworks(validateNetworkIndexes, validateNetworkCount);
  }
}

int WifiScan::getScanNetworkCount() {
  return scanNetworkCount;
}

void WifiScan::setValidateNetworks(int *indexes, int count) {
  for (int i = 0 ; i < count; i++)
    setNetwork(WiFi.SSID(indexes[i]), i);
}

void WifiScan::getValidateNetworkIndexes(int *indexes, int *count, int bufferSize) {
  int temp = 0;
  for (int i = 0; i < getScanNetworkCount(); i++)
    if (validateNetwork(WiFi.SSID(i)) && i < bufferSize)
      indexes[temp++] = i;
  *count = temp;
}

bool WifiScan::validateNetwork(String network) {
  for (int i = 0; i < (int)network.length(); i++)
    if (!isPrintable(network[i]))
      return false;
  return true;
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