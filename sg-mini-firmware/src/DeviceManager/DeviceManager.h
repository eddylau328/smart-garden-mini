#ifndef DeviceManager_h
#define DeviceManager_h

#include "../WifiController/Setting/WifiSettingManager.h"

class DeviceManager {
	public:
		static WifiSettingManager getWifiSettingManager();
		static void setWifiSettingManager(WifiSettingManager wifiSettingManager);

   	private:
		static WifiSettingManager wifiSettingManager;
};

#endif