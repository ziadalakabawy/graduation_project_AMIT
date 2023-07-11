/*
 * LM35.c
 *
 * Created: 4/8/2023 9:35:34 PM
 *  Author: user
 */ 
#include "LM35.h"

void LM35_Init(ADC_InitTypes * options){
	ADC_Init(options);
}
u16 LM35_Read(ADC_ChannelTypes channelId){
	u16 readValue = 0;
	//readValue = ADC_Read(channelId);
	readValue = readValue/4;
	return readValue;
}