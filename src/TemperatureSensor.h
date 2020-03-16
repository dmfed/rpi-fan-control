#include <sstream>
#include <fstream>

class TemperatureSensor
{
public:
    TemperatureSensor();

    ~TemperatureSensor();
    
    float getCurrentTemperature();
};
