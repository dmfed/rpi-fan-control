#include <iostream>

#include <wiringPi.h>
#include <softPwm.h>
#include "Fan.h"

using namespace std;

const int INITIAL_DUTY_CYCLE = 0;
const int DUTY_CYCLE_RANGE = 100;

Fan::Fan(int pin)
{
	this->pin = pin;
	
	int status = softPwmCreate(pin, INITIAL_DUTY_CYCLE, DUTY_CYCLE_RANGE);
	if (status)
	{
		cout << "Failed to init GPIO pin: " << status << endl;
		throw status;
	}
	
	this->setDutyCycle(0);
}

Fan::~Fan()
{
	
}

void Fan::setDutyCycle(int dutyCycle)
{
	if (dutyCycle < 0)
	{
		this->dutyCycle = 0;
	}
	else if (dutyCycle > 100)
	{
		this->dutyCycle = 100;
	}
	else
	{
		this->dutyCycle = dutyCycle;
	}
	
	softPwmWrite(this->pin, this->dutyCycle);
}

int Fan::getDutyCycle()
{
	return this->dutyCycle;
}
