#ifndef HumidityModeSetting_h
#define HumidityModeSetting_h


#include "../../../../../Helper/Helper.h"


class HumidityModeSetting {
    public:
        HumidityModeSetting();
        HumidityModeSetting(uint8_t targetHumidity, uint8_t minHumidity, uint8_t maxHumidity);

        void setMinHumidity(uint8_t minHumidity);
        void setMaxHumidity(uint8_t maxHumidity);
        void setTargetHumidity(uint8_t targetHumidity);

        uint8_t getMinHumidity();
        uint8_t getMaxHumidity();
        uint8_t getTargetHumidity();

        void operator = (const HumidityModeSetting &setting);

    private:
        uint8_t targetHumidity = 0;
        uint8_t minHumidity = 0;
        uint8_t maxHumidity = 0;

        bool isValidHumidityLevel(uint8_t humidityLevel);

};

#endif