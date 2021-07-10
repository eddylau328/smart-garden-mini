#ifndef DeviceManager_h
#define DeviceManager_h

#include "SettingManager/SetupSettingManager/SetupSettingManager.h"
#include "SettingManager/WifiSettingManager/WifiSettingManager.h"
#include "SettingManager/WaterSettingManager/WaterSettingManager.h"
#include "SettingManager/LocalSettingManager/LocalSettingManager.h"
#include "SettingManager/DataTransmitManager/DataTransmitManager.h"

class DeviceManager {
	public:
		static void init();

		static SetupSettingManager* getSetupSettingManager();
		static WifiSettingManager* getWifiSettingManager();
		static WaterSettingManager* getWaterSettingManager();
		static LocalSettingManager* getLocalSettingManager();
		static DataTransmitManager* getDataTransmitManager();

  	private:
	  	static SetupSettingManager *setupSettingManager;
		static WifiSettingManager *wifiSettingManager;
		static WaterSettingManager *waterSettingManager;
		static LocalSettingManager *localSettingManager;
		static DataTransmitManager *dataTransmitManager;
};

#endif