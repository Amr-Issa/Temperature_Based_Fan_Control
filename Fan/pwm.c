/*
 * pwm.c
 *
 *  Created on: 7 Oct 2022
 *      Author: Amr Issa
 */
#include "pwm.h"


void PWM_SetDutyCyclePercentage(uint8 set_duty_cycle_percentage)
{

	TCNT0 = 0; /*Set Timer Initial value*/

	OCR0  = 2.55*(set_duty_cycle_percentage); // Set Compare Value

	SET_BIT(DDRB,PWM_OUTPUT_PIN); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,CS01);
}

