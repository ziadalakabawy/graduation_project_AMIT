/*
 * ADC.c
 *
 * Created: 4/8/2023 9:01:29 PM
 *  Author: user
 */ 
#include "ADC.h"
#include "LCD.h"

void ADC_Init(ADC_InitTypes * options){
	ADC_ADMUX_Reg = ((options->adcVref)<<6);//set Vref
	ADC_ADCSRA_Reg = (1<<ADC_ADCSRA_ADEN_Bit)|(options->adcClock);//Enable ADC & Prescaler
}
u16 ADC_Read(ADC_ChannelTypes channelId){
	u16 readValue = 0,celsius=0;
	s8 strvalue[10];
	ADC_ADMUX_Reg = (ADC_ADMUX_Reg & 0b11100000)|(channelId & 0b00011111);
	SetBit(ADC_ADCSRA_Reg,ADC_ADCSRA_ADSC_Bit);//start Conv.
	while(GetBit(ADC_ADCSRA_Reg,ADC_ADCSRA_ADIF_Bit) == 0);//Waiting to finish the Conv.
	SetBit(ADC_ADCSRA_Reg,ADC_ADCSRA_ADIF_Bit);//Clear the Flag
	readValue = (ADC_ADCL_Reg)|(ADC_ADCH_Reg<<8);
	celsius = readValue/4;
	/*itoa(celsius,strvalue,10);
	LCD_String(strvalue);
	_delay_ms(100);
	LCD_Clear();*/
	return celsius;
}