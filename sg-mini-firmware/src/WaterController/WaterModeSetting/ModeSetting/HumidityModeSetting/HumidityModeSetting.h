#ifndef HumidityModeSetting_h
#define HumidityModeSetting_h

#include "../../../../Helper/Helper.h"


class HumidityModeSetting {
    public:
        HumidityModeSetting();
        HumidityModeSetting(float targetHumidity, float minHumidity, float maxHumidity);

        void setMinHumidity(float minHumidity);
        void setMaxHumidity(float maxHumidity);
        void setTargetHumidity(float targetHumidity);

        float getMinHumidity();
        float getMaxHumidity();
        float getTargetHumidity();

        void operator = (const HumidityModeSetting &setting);

    private:
        float targetHumidity = 0;
        float minHumidity = 0;
        float maxHumidity = 0;

        bool isValidHumidityLevel(float humidityLevel);

};

#endif