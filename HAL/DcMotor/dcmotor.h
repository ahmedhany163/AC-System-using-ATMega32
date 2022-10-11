 /******************************************************************************
 *
 * File Name: dcmotor.h
 *
 * Description: Header file for the DC motor driver
 *
 * Author: Ahmed Hany
 *
 *******************************************************************************/
#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "../../MCAL/std_types.h"
#include "../../MCAL/GPIO/gpio.h"

typedef enum
{
	Stop,CW,ACW
}DcMotor_State;


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DCMOTOR_H_ */
