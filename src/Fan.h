
class Fan
{
	private:
		int pin;
		int dutyCycle;
	
	public:
		Fan(int pin);
		~Fan();
		void setDutyCycle(int dutyCycle);
		int getDutyCycle();
};
