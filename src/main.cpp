#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include <wiringPi.h>

#include "configuration.h"
#include "temperature.h"
#include "fan.h"
#include "fanController.h"
#include "log.h"

using namespace std;

void initGpio()
{
    int status = wiringPiSetup();
    if (status)
    {
        Logger::getInstance().Error("Failed to initialize wiringPi!");
        throw status;
    }
}

int main()
{
    Logger logger = Logger::getInstance();
#ifdef DEBUG
    logger.setLevel(LogLevel::Debug);
#else
    logger.setLevel(LogLevel::Error);
#endif
    initGpio();
    
    Fan fan(WIRING_PI_FAN_PIN);
    FanController fanController(fan, TEMP_THREASHOLD, TEMP_CRITICAL, logger);
    float temp;
    
    while (true)
    {
        temp = getCpuTemperature();
        logger.Debug("CPU temperature: " + std::to_string(temp));

        fanController.handleTemperatureChange(temp);
        
        this_thread::sleep_for(chrono::milliseconds(UPDATE_INTERVAL_MSEC));
    }

    return 0;
}
