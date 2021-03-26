#ifndef WaterControllerSetting_h
#define WaterControllerSetting_h

#include "../../Helper/Helper.h"

class WaterControllerSetting {
    public:
        static void setMinHumidityLevel(uint8_t humidityLevel);
        static void setMaxHumidityLevel(uint8_t humidityLevel);
        static void setTargetHumidityLevel(uint8_t humidityLevel);

        static uint8_t getMinHumidityLevel();
        static uint8_t getMaxHumidityLevel();
        static uint8_t getTargetHumidityLevel();

    private:
        static uint8_t targetHumidityLevel;
        static uint8_t minHumidityLevel;
        static uint8_t maxHumidityLevel;

        static bool isValidHumidityLevel(uint8_t humidityLevel);
};

#endif