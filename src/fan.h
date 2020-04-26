#pragma once

class Fan
{
private:
	int mPin;
	int mDutyCycle;

public:
	Fan(int pin);
	void setDutyCycle(int dutyCycle);
	int getDutyCycle() const;
};
