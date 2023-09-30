/*
 * Fan.c
 *
 *  Created on: 7 Oct 2022
 *      Author: Amr Issa
 */
#include"adc.h"
#include"common_macros.h"
#include"dcmotor.h"
#include"gpio.h"
#include"lcd.h"
#include"lm35_sensor.h"


int main()
{
	enum fan_state
	{
		off,on
	};

	enum fan_state fan;

	/*
	 setting the configurations of the ADC MODULE
	 */

	ADC_ConfigType configurations;
	configurations.prescaler=EIGHT;
	configurations.ref_volt=INTERNAL_2V;
	GPIO_writePort(PORTA_ID,PORT_INPUT);
	/* initializing the LCD*/
	LCD_init();
	/* initializing the ADC MODULE*/
	ADC_init(&configurations);
	/*to store the readings of the LM35 sensor in it*/
	uint8 temperature;

	/*initializing DC MOTOR MODULE*/
	DcMotor_init();

	while(1)
	{

		temperature=LM35_getTemperature();

		/*to determine fan state based on temperature reading*/
		if(temperature<30)
		{
			fan=off;
			DcMotor_Rotate(STOP,0);
		}
		else if(temperature>30&&temperature<60)
		{
			fan=on;
			DcMotor_Rotate(CW,25);
		}
		else if(temperature>=60&&temperature<90)
		{
			fan=on;
			DcMotor_Rotate(CW,50);
		}
		else if(temperature>=90&&temperature<120)
		{
			fan=on;
			DcMotor_Rotate(CW,75);
		}
		else if(temperature>=120)
		{
			fan=on;
			DcMotor_Rotate(CW,100);
		}

		/*to print the state of the fan and the temperature value*/
		if(fan==on)
		{
			LCD_moveCursor(0,4);
			LCD_displayString("fan is on ");
			LCD_moveCursor(1,6);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
			LCD_displayCharacter(' ');
		}
		else if(fan==off)
		{
			LCD_moveCursor(0,4);
			LCD_displayString("fan is off");
			LCD_moveCursor(1,6);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
			LCD_displayCharacter(' ');
		}


	}

}

