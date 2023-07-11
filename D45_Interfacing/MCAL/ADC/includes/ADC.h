/*
 * ADC.h
 *
 * Created: 4/8/2023 9:00:51 PM
 *  Author: user
 */ 


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
#include "ADC_Reg.h"
#include "ADC_Types.h"
#include "BitMath.h"


void ADC_Init(ADC_InitTypes * options);
u16 ADC_Read(ADC_ChannelTypes channelId);


#endif /* ADC_H_ */