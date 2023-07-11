/*
 * TIMER2.h
 *
 * Created: 7/10/2023 8:34:37 AM
 *  Author: hp
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_


#include <avr/interrupt.h>
#include "TIMER2_Reg.h"
#include "TIMER2_Types.h"

void TIMER2_Init(TIMER2_InitTypes * options);
void TIMER2_OCR2_SetValue(u16 value);
void TIMER2_TCNT2_SetValue(u16 value);
void TIMER2_TOVInt_SetCallBack(void (*Timer2TOVIntCopyFunPtr)(void));




#endif /* TIMER2_H_ */