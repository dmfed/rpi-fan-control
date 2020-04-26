#pragma once

#include <iostream>
#include <ctime>
#include "fan.h"
#include "log.h"

class FanController
{
private:
    enum FanLevel
    {
        Off = 0,
        Low = 1,
        Average = 2,
        High = 3
    };

    Fan& mFan;
    Logger& mLogger;
    FanLevel mFanLevel;
    const float mThreashold;
    const float mAverageThreashold;
    const float mHighTreashold;
    time_t* mStartedByTime;

public:
    FanController(Fan& mFan, const float threasholdTemperature,
                    const float criticalTemperature, Logger& logger);
    ~FanController();
    void handleTemperatureChange(float temperature);

private:
    void startContinuingByTime();
    void handleContinuingByTime(FanController::FanLevel level);
    void setLevelAndUpdate(FanController::FanLevel level);
    void updateFan();
    bool is_continuing_by_time() const;
    const char* getFanLevelName(const FanController::FanLevel &level);
};