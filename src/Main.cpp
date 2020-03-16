#include <iostream>
#include <fstream>
#include "TemperatureSensor.h"

int main()
{
    TemperatureSensor sensor;

    float temp = sensor.getCurrentTemperature();

    std::cout << temp << std::endl;

    return 0;
}