#ifndef DataTransmitManager_h
#define DataTransmitManager_h

#include "MqttTransmitSetting/MqttTransmitSetting.h"
#include "../SettingManager.h"
#include "../../../DataTransmitter/TransmitConstant.h"


class DataTransmitManager : public SettingManager {
    public:
        void init();
        void restoreDefault();

        void setIsEnableTransmit(bool isTransmitData);
        bool getIsEnableTransmit();

        void setIsTransmitSensorData(bool isTransmitSensorData);
        bool getIsTransmitSensorData();

        void setTransmitMethod(TransmitConstant::TransmitMethod method);
        TransmitConstant::TransmitMethod getTransmitMethod();

        void setMqttTransmitSetting(MqttTransmitSetting MqttTransmitSetting);
        MqttTransmitSetting getMqttTransmitSetting();
        bool getIsMqttTransmitSet();
    
    private:
        MqttTransmitSetting mqttTransmitSetting;
        bool isMqttTransmitSet;
        bool isEnableTransmit;
        bool isTransmitSensorData;
        TransmitConstant::TransmitMethod transmitMethod;

        void retrieveIsMqttTransmitSet();
        void storeIsMqttTransmitSet();

        void retrieveIsEnableTransmit();
        void storeIsEnableTransmit();

        void retrieveIsTransmitSensorData();
        void storeIsTransmitSensorData();

        void storeMqttTransmitSetting();
        void retrieveMqttTransmitSetting();

        void storeTransmitMethod();
        void retrieveTransmitMethod();
};

#endif