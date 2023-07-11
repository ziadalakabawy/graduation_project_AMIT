/*
* TIMER1.c
*
* Created: 4/14/2023 8:25:47 PM
*  Author: user
*/
#include "TIMER1.h"
#include "LCD.h"

void (*Timer1TOVIntFunPtr)(void) = 0;

void TIMER1_Init(TIMER1_InitTypes * options){
	switch(options->mode){
		case Normal:
		TIMER1_TCCR1A_Reg.Bits.WGM10_Bit = 0;
		TIMER1_TCCR1A_Reg.Bits.WGM11_Bit = 0;
		TIMER1_TCCR1B_Reg.Bits.WGM12_Bit = 0;
		TIMER1_TCCR1B_Reg.Bits.WGM13_Bit = 0;
		break;
		case CTC:
		TIMER1_TCCR1A_Reg.Bits.WGM10_Bit = 0;
		TIMER1_TCCR1A_Reg.Bits.WGM11_Bit = 0;
		TIMER1_TCCR1B_Reg.Bits.WGM12_Bit = 1;
		TIMER1_TCCR1B_Reg.Bits.WGM13_Bit = 0;
		break;
		case PWM_Fast:
		TIMER1_TCCR1A_Reg.Bits.WGM10_Bit = 0;
		TIMER1_TCCR1A_Reg.Bits.WGM11_Bit = 1;
		TIMER1_TCCR1B_Reg.Bits.WGM12_Bit = 1;
		TIMER1_TCCR1B_Reg.Bits.WGM13_Bit = 1;
		break;
		case PWM_PhaseCorrect:
		TIMER1_TCCR1A_Reg.Bits.WGM10_Bit = 0;
		TIMER1_TCCR1A_Reg.Bits.WGM11_Bit = 1;
		TIMER1_TCCR1B_Reg.Bits.WGM12_Bit = 0;
		TIMER1_TCCR1B_Reg.Bits.WGM13_Bit = 1;
		break;
	}
	TIMER1_TCCR1B_Reg.AllRegister |= ((options->prescaling)<<0);
	TIMER1_TCCR1A_Reg.AllRegister |= ((options->COM1AMode)<<6);
	TIMER1_TCCR1A_Reg.AllRegister |= ((options->COM1BMode)<<4);
	TIMER1_TIMSK_Reg |= ((options->TOVInt_Status)<<4);
	
}
void TIMER1_OCR1A_SetValue(u16 value){
	TIMER1_OCR1A_Reg = value;
}
void TIMER1_OCR1B_SetValue(u16 value){
	TIMER1_OCR1B_Reg = value;
}
void TIMER1_ICR1_SetValue(u16 value){
	TIMER1_ICR1_Reg = value;
}
void TIMER1_TCNT1_SetValue(u16 value){
	TIMER1_TCNT1_Reg = value;
}
void TIMER1_TOVInt_SetCallBack(void (*Timer1TOVIntCopyFunPtr)(void)){
	Timer1TOVIntFunPtr = Timer1TOVIntCopyFunPtr;
}

/*ISR(TIMER1_OVF_vect){
	Timer1TOVIntFunPtr();
}*/