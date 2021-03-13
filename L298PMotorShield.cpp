#include "Arduino.h"
#include "L298PMotorShield.h"
const unsigned char L298PMotorShield::_INA = 12; // A DIRECTION PIN
const unsigned char L298PMotorShield::_INB = 13; // B DIRECTION PIN
const unsigned char L298PMotorShield::_ENA = 10; // PWM A ENABLE PIN
const unsigned char L298PMotorShield::_ENB = 11; // PWM B ENABLE PIN
const unsigned char L298PMotorShield::_BUZZER = 4; // ROUTE TO BUZZER
const unsigned char L298PMotorShield::_SERVO = 9;
const unsigned char L298PMotorShield::_USPC1 = 7;
const unsigned char	L298PMotorShield::_USPC2 = 8;

void L298PMotorShield::initPins(){
	// initialize PWM A
	digitalWrite(_ENA, LOW);
	pinMode(_ENA, OUTPUT);
	digitalWrite(_ENA, LOW);
	// initialize PWM B
	digitalWrite(_ENB, LOW);
	pinMode(_ENB, OUTPUT);
	digitalWrite(_ENB, LOW);
	// initialize DIR A
	digitalWrite(_INA, LOW);
	pinMode(_INA, OUTPUT);
	digitalWrite(_INA, LOW);
	// initialize DIR B
	digitalWrite(_INB, LOW);
	pinMode(_INB, OUTPUT);
	digitalWrite(_INB, LOW);

}

void L298PMotorShield::setMotorASpeed(int speed){
  init(); // initialize if necessary
    
  boolean reverse = 0;
  
  if (speed < 0) {
    speed = -speed; // make speed a positive quantity
    reverse = 1;    // preserve the direction
  }
  if (speed > 255)  // max 
    speed = 255;
    

  analogWrite(_ENA, speed); // default to using analogWrite, mapping 400 to 255

  if (reverse) // flip if speed was negative or _flipM1 setting is active, but not both
    digitalWrite(_INA, HIGH);
  else
    digitalWrite(_INA, LOW);
}

void L298PMotorShield::setMotorBSpeed(int speed) {
  init(); // initialize if necessary
    
  boolean reverse = 0;
  
  if (speed < 0) {
    speed = -speed;  // make speed a positive quantity
    reverse = 1;  // preserve the direction
  }
  if (speed > 255)  // max PWM duty cycle
    speed = 255;
    
  analogWrite(_ENB, speed);

  if (reverse) // flip if speed was negative or _flipM2 setting is active, but not both
    digitalWrite(_INB, HIGH);
  else
    digitalWrite(_INB, LOW);
}

void L298PMotorShield::setMotorABSpeed(int mASpeed, int mBspeed){

	setMotorASpeed(mASpeed);
	setMotorBSpeed(mBspeed);
}

void L298PMotorShield::buzz(int freq, int time){

	tone(_BUZZER, freq, time);
	noTone(_BUZZER);
}