#include <sstream>
#include <fstream>
#include <string>
#include "TemperatureSensor.h"
using namespace std;

const string THERMAL_ZONE_PATH = "/sys/class/thermal/thermal_zone0/temp";

TemperatureSensor::TemperatureSensor()
{
};

TemperatureSensor::~TemperatureSensor()
{
};
    
float TemperatureSensor::getCurrentTemperature()
{
    int res = 0;
    int data;
    
    ifstream fs(THERMAL_ZONE_PATH);
    while(fs >> data)
    {
        res += data;
    }
    
    return (float) res / 1000.0;
}
