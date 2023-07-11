/*
 * LM35.h
 *
 * Created: 4/8/2023 9:35:21 PM
 *  Author: user
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "ADC.h"

void LM35_Init(ADC_InitTypes * options);
u16 LM35_Read(ADC_ChannelTypes channelId);

#endif /* LM35_H_ */