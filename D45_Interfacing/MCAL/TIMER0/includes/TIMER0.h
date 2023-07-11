/*
 * TIMER0.h
 *
 * Created: 7/7/2023 11:59:53 PM
 *  Author: hp
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include <avr/interrupt.h>
#include "TIMER0_Reg.h"
#include "TIMER0_Types.h"

void TIMER0_Init(TIMER0_InitTypes * options);
void TIMER0_OCR0_SetValue(u16 value);
void TIMER0_TCNT0_SetValue(u16 value);
void TIMER0_TOVInt_SetCallBack(void (*Timer0TOVIntCopyFunPtr)(void));



#endif /* TIMER0_H_ */