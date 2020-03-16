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
    int status = wiringPiSetup();
    if (status)
    {
        cout << "Failed to init GPIO: " << status << endl;
        throw status;
    }
    
    TemperatureSensor sensor;
    Fan fan(25);
    float temp;
    int dutyCycle = 0;
    
    while (true)
    {
        temp = sensor.getCurrentTemperature();
        std::cout << temp << std::endl;
        
        dutyCycle = temp > 55 ? (int) (temp + temp * 0.25) : 0;
        
        fan.setDutyCycle(dutyCycle);
        
        this_thread::sleep_for(chrono::milliseconds(2000));
    }

    return 0;
}
