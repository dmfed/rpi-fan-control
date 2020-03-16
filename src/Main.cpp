#include <iostream>
#include <fstream>

#include <chrono>
#include <thread>

#include <wiringPi.h>

#include "TemperatureSensor.h"
#include "Fan.h"

using namespace std;

int main()
{
    TemperatureSensor sensor;
    float temp = sensor.getCurrentTemperature();
    std::cout << temp << std::endl;
    
    int status = wiringPiSetup();
    if (status)
    {
        cout << "Failed to init GPIO: " << status << endl;
        throw status;
    }
    
    Fan fan(25);
    while (true)
    {
        for (int i = 0; i < 100; i+=5)
        {
            fan.setDutyCycle(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        
        for (int i = 100; i > 0; i-=5)
        {
            fan.setDutyCycle(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    return 0;
}
