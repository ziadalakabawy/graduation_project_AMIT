/*
 * TIMER0_Reg.h
 *
 * Created: 7/8/2023 12:00:30 AM
 *  Author: hp
 */ 


#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_
#include "STD_Types.h"

#define TIMER0_TCCR0_Reg (*((volatile TIMER0_TCCR0Types*)0x53))
#define TIMER0_OCR0_Reg (*((volatile u16*)0x5C))
#define TIMER0_TCNT0_Reg (*((volatile u16*)0x52))
#endif /* TIMER0_REG_H_ */