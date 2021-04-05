#include "ScheduleModeSetting.h"


ScheduleModeSetting::ScheduleModeSetting() {}

ScheduleModeSetting::ScheduleModeSetting(unsigned long scheduleDuration, float targetHumidity) {
    setScheduleDuration(scheduleDuration);
    setTargetHumidity(targetHumidity);
}

void ScheduleModeSetting::setScheduleDuration(unsigned long scheduleDuration) {
    this->scheduleDuration = scheduleDuration;
}

void ScheduleModeSetting::setTargetHumidity(float targetHumidity) {
    if (Helper::isInRange(targetHumidity, 0.0, 100.0))
        this->targetHumidity = targetHumidity;
}

unsigned long ScheduleModeSetting::getScheduleDuration() {
    return this->scheduleDuration;
}

float ScheduleModeSetting::getTargetHumidity() {
    return this->targetHumidity;
}

void ScheduleModeSetting::operator = (const ScheduleModeSetting &setting) {
    this->scheduleDuration = setting.scheduleDuration;
    this->targetHumidity = setting.targetHumidity;
}

