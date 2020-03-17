#include <sstream>
#include <fstream>
#include <string>
#include "temperature.h"
using namespace std;

const string THERMAL_ZONE_PATH = "/sys/class/thermal/thermal_zone0/temp";
    
float getCpuTemperature()
{
    int data;
    
    ifstream fs(THERMAL_ZONE_PATH);
    fs >> data;
    fs.close();
    
    return (float) data / 1000.0;
}
