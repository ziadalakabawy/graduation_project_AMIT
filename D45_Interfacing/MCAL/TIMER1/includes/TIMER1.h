/*
 * TIMER1.h
 *
 * Created: 4/14/2023 8:24:04 PM
 *  Author: user
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "TIMER1_Reg.h"
#include "TIMER1_Types.h"
#include <avr/interrupt.h>

void TIMER1_Init(TIMER1_InitTypes * options);
void TIMER1_OCR1A_SetValue(u16 value);
void TIMER1_OCR1B_SetValue(u16 value);
void TIMER1_ICR1_SetValue(u16 value);
void TIMER1_TCNT1_SetValue(u16 value);
void TIMER1_TOVInt_SetCallBack(void (*Timer1TOVIntCopyFunPtr)(void));
#endif /* TIMER1_H_ */