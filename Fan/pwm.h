/*
 * pwm.h
 *
 *  Created on: 7 Oct 2022
 *      Author: Amr Issa
 */

#include "common_macros.h"
#include "std_types.h"
#include <avr/io.h>
#ifndef PWM_H_
#define PWM_H_


#define PWM_OUTPUT_PIN 3


void PWM_SetDutyCyclePercentage(uint8 set_duty_cycle_percentage);


#endif /* PWM_H_ */
