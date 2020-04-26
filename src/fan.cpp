#include <iostream>

#include <wiringPi.h>
#include <softPwm.h>
#include "fan.h"

using namespace std;

static const int INITIAL_DUTY_CYCLE = 0;
static const int DUTY_CYCLE_MAX = 100;

Fan::Fan(int pin) :
	mPin(pin)
{
	int status = softPwmCreate(pin, INITIAL_DUTY_CYCLE, DUTY_CYCLE_MAX);
	if (status)
	{
		cout << "Failed to init GPIO pin: " << status << endl;
		throw status;
	}
	
	setDutyCycle(0);
}

void Fan::setDutyCycle(int dutyCycle)
{
	if (dutyCycle < 0)
	{
		mDutyCycle = 0;
	}
	else if (dutyCycle > 100)
	{
		mDutyCycle = 100;
	}
	else
	{
		mDutyCycle = dutyCycle;
	}
	
	softPwmWrite(mPin, mDutyCycle);
}

int Fan::getDutyCycle()
{
	return mDutyCycle;
}
