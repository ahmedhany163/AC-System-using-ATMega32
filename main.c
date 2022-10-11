/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: Hany
 */
#include <stdlib.h>
#include "MCAL/GPIO/gpio.h"
#include "HAL/LCD/lcd.h"
#include "MCAL/ADC/adc.h"
#include "HAL/DcMotor/dcmotor.h"


int main(void){
	uint8 temp=0;
	LCD_init();
	ADC_ConfigType ADC_Config = {Internal,DF_8};
	ADC_Init(&ADC_Config);
	DcMotor_Init();
	LCD_moveCursor(0, 4);
	LCD_displayString("Fan is ");
	LCD_moveCursor(1, 3);
	LCD_displayString("Temp =     C");
	while(1){
		temp=LM35_getTemperature();

		if(temp>100){
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
		}
		else{
			if(temp>=30 && temp<60){
				LCD_moveCursor(0, 11);
				LCD_displayString("ON ");
				DcMotor_Rotate(CW,25);
			}
			else if(temp>=60 && temp<90 ){
				DcMotor_Rotate(CW, 50);
			}
			else if(temp>=90){
				DcMotor_Rotate(CW, 100);
			}
			else{
				DcMotor_Rotate(Stop,0);
				LCD_moveCursor(0, 11);
				LCD_displayString("OFF");
			}
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}
	}

	return 0;
}
