#ifndef DataTransmitManager_h
#define DataTransmitManager_h

#include "MqttTransmitSetting/MqttTransmitSetting.h"
#include "../SettingManager.h"
#include "../../../DataTransmitter/TransmitConstant.h"


class DataTransmitManager : public SettingManager {
    public:
        void init();
        void restoreDefault();

        void setIsTransmitData(bool isTransmitData);
        bool getIsTransmitData();

        void setTransmitMethod(TransmitConstant::TransmitMethod method);
        TransmitConstant::TransmitMethod getTransmitMethod();

        void setMqttTransmitSetting(MqttTransmitSetting MqttTransmitSetting);
        MqttTransmitSetting getMqttTransmitSetting();
        bool getIsMqttTransmitSet();
    
    private:
        MqttTransmitSetting mqttTransmitSetting;
        bool isMqttTransmitSet;
        bool isTransmitData;
        TransmitConstant::TransmitMethod transmitMethod;

        void retrieveIsMqttTransmitSet();
        void storeIsMqttTransmitSet();

        void retrieveIsTransmitData();
        void storeIsTransmitData();

        void storeMqttTransmitSetting();
        void retrieveMqttTransmitSetting();

        void storeTransmitMethod();
        void retrieveTransmitMethod();
};

#endif