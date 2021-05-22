#ifndef DeviceManager_h
#define DeviceManager_h

#include "SettingManager/WifiSettingManager/WifiSettingManager.h"
#include "SettingManager/WaterSettingManager/WaterSettingManager.h"
#include "SettingManager/LocalSettingManager/LocalSettingManager.h"

class DeviceManager {
	public:
		static void init();
		static WifiSettingManager* getWifiSettingManager();
		static WaterSettingManager* getWaterSettingManager();
		static LocalSettingManager* getLocalSettingManager();

  	private:
		static WifiSettingManager *wifiSettingManager;
		static WaterSettingManager *waterSettingManager;
		static LocalSettingManager *localSettingManager;
};

#endif