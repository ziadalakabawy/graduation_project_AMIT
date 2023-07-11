/*
 * TIMER0.c
 *
 * Created: 7/8/2023 12:01:20 AM
 *  Author: hp
 */
#include "TIMER0.h"
#include "TIMER1.h"

void (*Timer0TOVIntFunPtr)(void) = 0;
void TIMER0_Init(TIMER0_InitTypes * options){
	switch(options->mode){
		case Normal_0:
		TIMER0_TCCR0_Reg.Bits.WGM01_Bit = 0;
		TIMER0_TCCR0_Reg.Bits.WGM00_Bit = 0;
		break;
		case PWM_PhaseCorrect_0:
		TIMER0_TCCR0_Reg.Bits.WGM01_Bit = 0;
		TIMER0_TCCR0_Reg.Bits.WGM00_Bit = 1;
		break;
		case CTC_0:
		TIMER0_TCCR0_Reg.Bits.WGM01_Bit = 1;
		TIMER0_TCCR0_Reg.Bits.WGM00_Bit = 0;
		break;
		case PWM_Fast_0:
		TIMER0_TCCR0_Reg.Bits.WGM01_Bit = 1;
		TIMER0_TCCR0_Reg.Bits.WGM00_Bit = 1;
		break;
	}
	TIMER0_TCCR0_Reg.AllRegister |= ((options->prescaling)<<0);
	TIMER0_TCCR0_Reg.AllRegister |= ((options->COM0Mode)<<4);
	TIMER1_TIMSK_Reg |= ((options->TOVInt_Status)<<0);
	
}
void TIMER0_OCR0_SetValue(u16 value){
	TIMER0_OCR0_Reg = value;
}
void TIMER0_TCNT0_SetValue(u16 value){
	TIMER0_TCNT0_Reg = value;
}
void TIMER0_TOVInt_SetCallBack(void (*Timer0TOVIntCopyFunPtr)(void)){
	Timer0TOVIntFunPtr = Timer0TOVIntCopyFunPtr;
}
/*ISR(TIMER0_OVF_vect){
	Timer0TOVIntFunPtr();
}*/