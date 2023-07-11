/*
 * TIMER2_Reg.h
 *
 * Created: 7/10/2023 8:35:01 AM
 *  Author: hp
 */ 


#ifndef TIMER2_REG_H_
#define TIMER2_REG_H_

#include "STD_Types.h"

#define TIMER2_TCCR2_Reg (*((volatile TIMER2_TCCR2Types*)0x45))
#define TIMER2_OCR2_Reg (*((volatile u16*)0x43))
#define TIMER2_TCNT2_Reg (*((volatile u16*)0x44))



#endif /* TIMER2_REG_H_ */