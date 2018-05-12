#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

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

//Array of unsigned integers used to store up to 6 different sensor values located on different analog channels.
volatile uint16_t sensorValues[6];

//Initial channel set to Infra red sensor right.
volatile uint8_t currentAnalogChannel = OPTICAL_FRONT;


int main(void)
{
	initializeMotors();
	initializeADC();

	while (1)
	{
		/*drive(100);
		_delay_ms(16000);
		drive(-100);
		_delay_ms(16000);*/
		readSensor(IR_LEFT);
		readSensor(IR_RIGHT);
	}
	
	return 0;
}

