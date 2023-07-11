/*
 * TIMER0.c
 *
 * Created: 7/8/2023 12:01:20 AM
 *  Author: hp
 */
#include "TIMER2.h"
#include "TIMER1.h"

void (*Timer2TOVIntFunPtr)(void) = 0;
void TIMER2_Init(TIMER2_InitTypes * options){
	switch(options->mode){
		case Normal_2:
		TIMER2_TCCR2_Reg.Bits.WGM21_Bit = 0;
		TIMER2_TCCR2_Reg.Bits.WGM20_Bit = 0;
		break;					 
		case PWM_PhaseCorrect_2: 
		TIMER2_TCCR2_Reg.Bits.WGM21_Bit = 0;
		TIMER2_TCCR2_Reg.Bits.WGM20_Bit = 1;
		break;					 
		case CTC_2:				 
		TIMER2_TCCR2_Reg.Bits.WGM21_Bit = 1;
		TIMER2_TCCR2_Reg.Bits.WGM20_Bit = 0;
		break;					 
		case PWM_Fast_2:		 
		TIMER2_TCCR2_Reg.Bits.WGM21_Bit = 1;
		TIMER2_TCCR2_Reg.Bits.WGM20_Bit = 1;
		break;
	}
	TIMER2_TCCR2_Reg.AllRegister |= ((options->prescaling)<<0);
	TIMER2_TCCR2_Reg.AllRegister |= ((options->COM2Mode)<<4);
	TIMER1_TIMSK_Reg |= ((options->TOVInt_Status)<<0);
	
}
void TIMER2_OCR2_SetValue(u16 value){
	TIMER2_OCR2_Reg = value;
}
void TIMER2_TCNT2_SetValue(u16 value){
	TIMER2_TCNT2_Reg = value;
}
void TIMER2_TOVInt_SetCallBack(void (*Timer2TOVIntCopyFunPtr)(void)){
	Timer2TOVIntFunPtr = Timer2TOVIntCopyFunPtr;
}
/*ISR(TIMER2_OVF_vect){
	Timer2TOVIntFunPtr();
}*/