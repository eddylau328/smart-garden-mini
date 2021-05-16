#ifndef ScheduleModeSetting_h
#define ScheduleModeSetting_h

#include "../../../../../Helper/Helper.h"


class ScheduleModeSetting {

    public:
        ScheduleModeSetting();
        ScheduleModeSetting(unsigned long scheduleDuration, float targetHumidity);

        void setScheduleDuration(unsigned long scheduleDuration);
        void setTargetHumidity(float targetHumidity);

        unsigned long getScheduleDuration();
        float getTargetHumidity();

        void operator = (const ScheduleModeSetting &setting);
    
    private:
        float targetHumidity = 0;
        unsigned long scheduleDuration = 0;
};

#endif