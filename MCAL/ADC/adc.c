 /******************************************************************************
 *
 * File Name: adc.c
 *
 * Description: source file for the ADC driver
 *
 * Author: Ahmed Hany
 *
 *******************************************************************************/
#include <avr/io.h>
#include "../std_types.h"
#include "../common_macros.h"
#include "adc.h"


void ADC_Init(const ADC_ConfigType *Config_Ptr)
{
	ADMUX = (Config_Ptr ->ref_volt << REFS0); // Selects reference voltage

	ADCSRA = (1<<ADEN); // Enables ADC
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr -> prescaler); // Selects prescaler
}

uint16 ADC_readChannel(uint8 ch_num){
	ADMUX = (ADMUX & 0xE0) | (ch_num & 0x07); // inserts channel num in the mux bits
	ADCSRA |= (1<<ADSC); // starts conversion
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); // POLLING
	ADCSRA |= (1<<ADIF); // clears adc flag
	return ADC; // returns adc result
}

