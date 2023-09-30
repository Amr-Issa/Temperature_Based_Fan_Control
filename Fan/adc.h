/*
 * adc.h
 *
 *  Created on: 7 Oct 2022
 *      Author: Amr Issa
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

typedef enum
{
	INTERNAL_voltOff,AVCC,RESERVED,INTERNAL_2V
}ADC_referenceVoltage;

typedef enum
{
	TWO=1,FOUR,EIGHT,SIXTEEN,THIRTY_TWO,SIXTY_FOUR,ONE_HUNDRED_TWENTY_EIGHT
}ADC_preScaler;

typedef struct{
	ADC_referenceVoltage ref_volt;
	ADC_preScaler prescaler;
}ADC_ConfigType;

uint16 ADC_readChannel(uint8 channel_num);
void ADC_init(ADC_ConfigType *configurations);


#endif /* ADC_H_ */
