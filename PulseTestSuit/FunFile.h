#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#ifndef FunFile_H_
#define FunFile_H_


#define F_CPU 16000000

//Left motor operated internally by 3 inputs. Two control inputs and one PWM signal defined below as follows.
#define L_CTRL_1 PIND2
#define L_CTRL_2 PIND4
#define PWM_L PIND5 //OC0B

//Same as the left motor
#define R_CTRL_1 PIND7
#define R_CTRL_2 PINB0
#define PWM_R PIND6 //OC0A


//Definitions that allow us to more easily select which sensor we are targeting.
#define IR_LEFT 5
#define IR_RIGHT 3
#define OPTICAL_LEFT 4
#define OPTICAL_RIGHT 2
#define OPTICAL_FRONT 1

//Function prototypes for assisting subroutines.
void initializeMotors();
void initializePWM();
void initializePWM();
void initializeADC();
void startConversion();
void selectChannel(uint8_t analogPin);
uint16_t readSensor(uint8_t analogPin);

void analogWrite(uint8_t pin, uint8_t dutyCycle);


//Motor subroutines supporting CW and CCW rotation, coasting, braking and pivoting.
void rightFwd(uint8_t spd);
void rightRev(uint8_t spd);
void leftFwd(uint8_t spd);
void leftRev(uint8_t spd);
void rightCoast();
void leftCoast();
void rightStop();
void leftStop();
void rightBrake();
void leftBrake();
void rightDrive(int speed);
void leftDrive(int speed);
void rightMotor(int speed);
void leftMotor(int speed);
void pivot(int speed);
void drive(int speed);
void brake();
void coast();
void stop();


//Array of unsigned integers used to store up to 6 different sensor values located on different analog channels.
volatile uint16_t sensorValues[6];

//Initial channel set to Infra red sensor right.
volatile uint8_t currentAnalogChannel = OPTICAL_FRONT;

#endif /* FunFile_H_ */
