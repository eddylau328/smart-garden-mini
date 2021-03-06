#include "ScheduleModeSetting.h"


ScheduleModeSetting::ScheduleModeSetting() {}

ScheduleModeSetting::ScheduleModeSetting(unsigned long scheduleDuration, uint8_t targetHumidity) {
    setScheduleDuration(scheduleDuration);
    setTargetHumidity(targetHumidity);
}

void ScheduleModeSetting::setScheduleDuration(unsigned long scheduleDuration) {
    this->scheduleDuration = scheduleDuration;
}

void ScheduleModeSetting::setTargetHumidity(uint8_t targetHumidity) {
    if (Helper::isInRange(targetHumidity, 0, 100))
        this->targetHumidity = targetHumidity;
}

unsigned long ScheduleModeSetting::getScheduleDuration() {
    return this->scheduleDuration;
}

uint8_t ScheduleModeSetting::getTargetHumidity() {
    return this->targetHumidity;
}

void ScheduleModeSetting::operator = (const ScheduleModeSetting &setting) {
    this->scheduleDuration = setting.scheduleDuration;
    this->targetHumidity = setting.targetHumidity;
}

