/*
 * dcmotor.h
 *
 *  Created on: 7 Oct 2022
 *      Author: Amr Issa
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_


#include "std_types.h"


#define DcMotor_Port	PORTB_ID
#define DcMotor_IN1		PIN0_ID
#define DcMotor_IN2		PIN1_ID
#define DcMotor_Enable	PIN3_ID


typedef enum
{
	STOP,CW,CCW
}MotorDirection;

void DcMotor_Rotate(MotorDirection direction,uint8 speed );
void DcMotor_init(void);

#endif /* DCMOTOR_H_ */

