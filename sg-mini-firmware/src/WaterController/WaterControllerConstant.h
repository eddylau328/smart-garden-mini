#ifndef WaterControllerConstant_h
#define WaterControllerConstant_h


#define TOTAL_WATER_MODE 3

class WaterControllerConstant {
    public:
        enum WaterMode {
          ManualMode = 0,
          ScheduleMode = 1,
          HumidityMode = 2,
        };
};

#endif