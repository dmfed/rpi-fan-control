#pragma once

class Fan
{
	private:
		int pin;
		int dutyCycle;
	
	public:
		Fan(int pin);
		void setDutyCycle(int dutyCycle);
		int getDutyCycle();
};
