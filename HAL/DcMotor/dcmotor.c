 /******************************************************************************
 *
 * File Name: dcmotor.c
 *
 * Description: Source file for the DC motor driver
 *
 * Author: Ahmed Hany
 *
 *******************************************************************************/

#include "dcmotor.h"

void DcMotor_Init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,LOGIC_HIGH);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,LOGIC_HIGH);
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
}


void DcMotor_Rotate(DcMotor_State state, uint8 speed){
	switch(state){
	case Stop:
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
		break;
	case ACW:
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_HIGH);
		break;
	}

	switch(speed){
	case 25:
		Timer0_PWM_Init(64);
		break;
	case 50:
		Timer0_PWM_Init(128);
		break;
	case 100:
		Timer0_PWM_Init(255);
		break;
	}
}
