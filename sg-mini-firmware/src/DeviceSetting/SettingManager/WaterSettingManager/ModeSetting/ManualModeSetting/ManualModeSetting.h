#ifndef ManualModeSetting_h
#define ManualModeSetting_h


#include "../../../../../Helper/Helper.h"


class ManualModeSetting {
    public:
        ManualModeSetting();
        ManualModeSetting(uint8_t duration);

        bool getIsTurnOnWaterPump();
        void setIsTurnOnWaterPump(bool isTurnOn);

        uint8_t getTurnOnDuration();
        void setTurnOnDuration(uint8_t duration);

        void operator = (const ManualModeSetting &setting);

    private:
        bool isTurnOnWaterPump;
        uint8_t turnOnDuration;
};

#endif