#include <chrono>
#include <string>

#include "fanController.h"
#include "fan.h"

using namespace std;
using namespace std::chrono;

FanController::FanController(Fan& fan, const float threasholdTemperature,
                            const float criticalTemperature, Logger& logger)
    : mFan(fan),
    mLogger(logger),
    mFanLevel(FanLevel::Off),
    mThreashold(threasholdTemperature),
    mAverageThreashold((criticalTemperature - threasholdTemperature) / 2 + threasholdTemperature),
    mHighTreashold(criticalTemperature),
    mStartedByTime(nullptr)
{
    updateFan();
}

FanController::~FanController()
{
    if (mStartedByTime != nullptr)
        delete mStartedByTime;
}

void FanController::handleTemperatureChange(float temperature)
{
    FanLevel level;
    if (temperature > mHighTreashold)
        level = High;
    else if (temperature > mAverageThreashold)
        level = Average;
    else if (temperature > mThreashold)
        level = Low;
    else
        level = Off;
    
    mLogger.Debug(("New fan level: " + string(getFanLevelName(level))).c_str());

    
    if (level > mFanLevel)
    {
        setLevelAndUpdate(level);
    }
    else if (is_continuing_by_time())
    {
        handleContinuingByTime(level);
    }
    else if (level < mFanLevel)
    {
        startContinuingByTime();
    }
}

void FanController::startContinuingByTime()
{
    mLogger.Debug("Start continuing by time");
    auto time = system_clock::to_time_t(system_clock::now());
    mStartedByTime = new time_t(time);
}

void FanController::handleContinuingByTime(FanController::FanLevel level)
{
    mLogger.Debug("Continuing by time");
    auto started = system_clock::from_time_t(*mStartedByTime);
    auto now = system_clock::now();
    if (duration_cast<std::chrono::seconds>(now - started).count() > 20)
    {
        mLogger.Debug("20 sec past. Stop continuing by time");
        setLevelAndUpdate(level);
        delete mStartedByTime;
        mStartedByTime = nullptr;
    }
}

void FanController::setLevelAndUpdate(FanController::FanLevel level)
{
    mLogger.Debug(("Set fan level: " + string(getFanLevelName(level))).c_str());
    mFanLevel = level;
    updateFan();
}

void FanController::updateFan()
{
    int dutyCycle;
    switch (mFanLevel)
    {
        case FanLevel::Off:
            dutyCycle = 0;
            break;
        case FanLevel::Low:
            dutyCycle = 33;
            break;
        case FanLevel::Average:
            dutyCycle = 75;
            break;
        default:
            dutyCycle = 100;
            break;
    }

    mFan.setDutyCycle(dutyCycle);
}

bool FanController::is_continuing_by_time() const
{
    return mStartedByTime != nullptr;
}

const char* FanController::getFanLevelName(const FanController::FanLevel &level)
{
    switch (level)
    {
        case Off:
            return "Off";
        case Low:
            return "Low";
        case Average:
            return "Average";
        case High:
            return "High";
        default:
            return "";
    }
}
