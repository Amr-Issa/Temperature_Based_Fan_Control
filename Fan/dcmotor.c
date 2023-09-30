/*
 * dcmotor.c
 *
 *  Created on: 7 Oct 2022
 *      Author: Amr Issa
 */
#include "dcmotor.h"
#include"pwm.h"
#include"gpio.h"


/*
 function description : this function is used to setup the pins for the module

 */


void DcMotor_init(void)
{
	GPIO_setupPinDirection(DcMotor_Port,DcMotor_IN1,PIN_OUTPUT);
	GPIO_setupPinDirection(DcMotor_Port,DcMotor_IN2,PIN_OUTPUT);

	GPIO_writePin(DcMotor_Port,DcMotor_IN1,LOGIC_LOW);
	GPIO_writePin(DcMotor_Port,DcMotor_IN2,LOGIC_LOW);

}



/*
 function description : this function controls the direction of the dc motor and the speed
 Arg1:direction --->enum with three motor states in it
 Arg2:speed -----> duty cycle in xx%
 */

void DcMotor_Rotate(MotorDirection direction,uint8 speed )
{
	/*the condition checks the input of the function and sets the duty cycle and the direction	*/
	if(direction==CW)
	{
	GPIO_writePin(DcMotor_Port,DcMotor_IN2,LOGIC_HIGH);
	GPIO_writePin(DcMotor_Port,DcMotor_IN1,LOGIC_LOW);
	PWM_SetDutyCyclePercentage(speed);
	}

	if(direction==CCW)
	{
	GPIO_writePin(DcMotor_Port,DcMotor_IN1,LOGIC_HIGH);
	GPIO_writePin(DcMotor_Port,DcMotor_IN2,LOGIC_LOW);
	PWM_SetDutyCyclePercentage(speed);
	}
	if(direction==STOP)
	{
	GPIO_writePin(DcMotor_Port,DcMotor_IN2,LOGIC_LOW);
	GPIO_writePin(DcMotor_Port,DcMotor_IN1,LOGIC_LOW);
	PWM_SetDutyCyclePercentage(0);
	}
}


