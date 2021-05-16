#ifndef DeviceManager_h
#define DeviceManager_h

#include "SettingManager/WifiSettingManager/WifiSettingManager.h"
#include "SettingManager/WaterSettingManager/WaterSettingManager.h"

class DeviceManager {
	public:
		static WifiSettingManager getWifiSettingManager();
		static WaterSettingManager getWaterSettingManager();

  private:
		static WifiSettingManager wifiSettingManager;
		static WaterSettingManager waterSettingManager;
};

#endif