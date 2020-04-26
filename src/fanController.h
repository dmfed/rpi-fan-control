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
    const Logger& mLogger;
    FanLevel mFanLevel;
    const float mThreashold;
    const float mAverageThreashold;
    const float mHighTreashold;
    time_t* mStartedByTime;

public:
    FanController(Fan& mFan, const float threasholdTemperature,
                    const float criticalTemperature, const Logger& logger);
    ~FanController();
    void handleTemperatureChange(const float temperature);

private:
    void startContinuingByTime();
    void handleContinuingByTime(const FanController::FanLevel level);
    void setLevelAndUpdate(const FanController::FanLevel level);
    void updateFan();
    bool is_continuing_by_time() const;
    const char* getFanLevelName(const FanController::FanLevel &level) const;
};