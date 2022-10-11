 /******************************************************************************
 *
 * File Name: adc.h
 *
 * Description: header file for the ADC driver
 *
 * Author: Ahmed Hany
 *
 *******************************************************************************/
#ifndef ADC_H_
#define ADC_H_

#include "../std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	AREF,AVCC,Reserved,Internal
}ADC_ReferenceVolatge;

typedef enum
{
	DF_20,DF_21,DF_4,DF_8,DF_16,DF_32,DF_64,DF_128
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_Init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
