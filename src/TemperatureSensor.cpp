#include <sstream>
#include <fstream>
#include <string>
#include "TemperatureSensor.h"
using namespace std;

const string THERMAL_ZONE_PATH = "/sys/class/thermal/thermal_zone0/temp";

TemperatureSensor::TemperatureSensor()
{
    this->stream = new ifstream(THERMAL_ZONE_PATH);
};

TemperatureSensor::~TemperatureSensor()
{
    delete this->stream;
};
    
float TemperatureSensor::getCurrentTemperature()
{
    int res = 0;
    int data;
    while(*(this->stream) >> data)
    {
        res += data;
    }
    
    return (float) res / 1000.0;
}