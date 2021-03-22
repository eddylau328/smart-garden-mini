#ifndef WifiScan_h
#define WifiScan_h

#define BufferSize 20

#include <WiFi.h>
#include <Arduino.h>
#include <DebugLog.h>

#include "../Helper/Helper.h"

class WifiScan{

  public:
    /**
     * @brief Get the number of networks after scanning
     * 
     * @return integer - the number of the networks 
     */
    static int getNetworkCount();

    /**
     * @brief Get the network name after scanning
     * 
     * @param name the network name in char array 
     * @param length the network name length 
     * @param index the index in the network array
     * @param nameBufferSize the buffer size of the name char array
     */
    static void getNetwork(char *name, int *length, int index, int nameBufferSize=BufferSize);

    /**
     * @brief start scanning the nearby access points
     * 
     * @param rescanCount the number of times to rescan the network
     */
    static void startScanNetwork(uint8_t rescanCount=3);

    /**
     * @brief stop scanning the nearby access points
     * 
     */
    static void stopScanNetwork();

    /**
     * @brief is scanning network
     * 
     */
    static bool isScanningNetwork();

  protected:
    /**
     * @brief performs the scanning task inside a event loop that will be trigger every 2 seconds
     * 
     */
    static void mainLoop();

    /**
     * @brief the callback function after scanning the nearby access points 
     * 
     * @param event the Event type defined by WiFi.h 
     * @param info the Event info defined by WiFi.h 
     */
    static void handleScanNetworks(WiFiEvent_t event, WiFiEventInfo_t info);

  private:
    /**
     * @brief scanning the nearby networks
     * 
     */
    static void scanNetworks();
    
    /**
     * @brief initializing the array for storing the networks nearby
     * 
     * @param networkCount - integer for storing the total number of access points after scanning
     */
    static void initializeNetworks(int networkCount);

    /**
     * @brief Set the Network name into the networks array 
     * 
     * @param networkName - the String of the network name
     * @param index - the index assigned to the network array 
     */
    static void setNetwork(String networkName, int index);

    static bool validateNetwork(String networkName);
    static void getValidateNetworkIndexes(int *validateNetworkIndexes, int *validateNetworkCount, int bufferSize);
    static void setValidateNetworks(int *validateNetworkIndexes, int validatNetworkCount);
    static int getScanNetworkCount();

    static char **networks;
    static int networkCount;
    static bool isScanNetwork;
    static int scanNetworkCount;
    static uint8_t rescanNetworkCount;
};

#endif