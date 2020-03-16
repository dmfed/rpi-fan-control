#include <sstream>
#include <fstream>

class TemperatureSensor
{
    std::ifstream* stream;

public:
    TemperatureSensor();

    ~TemperatureSensor();
    
    float getCurrentTemperature();
};