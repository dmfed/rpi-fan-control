#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include <wiringPi.h>

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
    
    Fan fan(6);
    FanController fanController(fan, 55f, 70f, logger);
    float temp;
    int dutyCycle = 0;
    
    while (true)
    {
        temp = getCpuTemperature();
        logger.Debug("CPU temperature: " + std::to_string(temp));
)
        fanController.handleTemperatureChange(temp);
        
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    return 0;
}
