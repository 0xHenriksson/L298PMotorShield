#ifndef L298PMotorShield_h
#define L298PMotorShield_h

#include <Arduino.h>


class L298PMotorShield {

public:
	static void setMotorASpeed(int speed);
	static void setMotorBSpeed(int speed);
	static void setMotorABSpeed(int mASpeed, int mBspeed);
	static void buzz(int freq, int time);

private:
	static void initPins();
	const static unsigned char _INA; // A DIRECTION PIN;
	const static unsigned char _INB; // B DIRECTION PIN
	const static unsigned char _ENA; // PWM A ENABLE PIN
	const static unsigned char _ENB; // PWM B ENABLE PIN
	const static unsigned char _BUZZER;
	const static unsigned char _SERVO;
	const static unsigned char _USPC1;
	const static unsigned char _USPC2;

	static inline void init(){
		static boolean initialized = false;
		if (!initialized){
			initialized = true;
			initPins();
		}
	}

};
#endif