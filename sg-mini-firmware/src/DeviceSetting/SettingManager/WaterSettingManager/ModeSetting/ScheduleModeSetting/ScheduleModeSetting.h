#ifndef ScheduleModeSetting_h
#define ScheduleModeSetting_h

#include "../../../../../Helper/Helper.h"


class ScheduleModeSetting {

    public:
        ScheduleModeSetting();
        ScheduleModeSetting(unsigned long scheduleDuration, uint8_t targetHumidity);

        void setScheduleDuration(unsigned long scheduleDuration);
        void setTargetHumidity(uint8_t targetHumidity);

        unsigned long getScheduleDuration();
        uint8_t getTargetHumidity();

        void operator = (const ScheduleModeSetting &setting);
    
    private:
        uint8_t targetHumidity = 0;
        unsigned long scheduleDuration = 0;
};

#endif