#include "Ultrasonic.h"
volatile u32 ultrasonic_counter=0;

void ultrasonic_timer(){
	ultrasonic_counter++;
}

u16 ultrasonic_u16_get_distance(){
	u32 ultrasonic_timer_ticks=0;
	u16 distance=0;
	DIO_ConfigChannel(TRIG_PIN,Output);
	DIO_ConfigChannel(ECHO_PIN,Input);
	DIO_WriteChannel(ECHO_PIN,STD_High);
	TIMER0_InitTypes  options={Normal_0,No_Prescaling_0,COM0_Disable_0,TOVInt_Enable_0};
	TIMER0_OCR0_SetValue(255);
	TIMER0_TOVInt_SetCallBack(ultrasonic_timer);
	DIO_WriteChannel(TRIG_PIN,STD_High);
	_delay_ms(10);
	DIO_WriteChannel(TRIG_PIN,STD_Low);
	TIMER0_TCNT0_SetValue(0);
	//GINT_EnableAllInterrupts();
	//Ext_Interrupt_Enable(Ext_INT0);
	Ext_Int_MCUCR_Reg=0x03;
	while(!GetBit(Ext_Int_GIFR_Reg,6));
	SetBit(Ext_Int_GIFR_Reg,6);
	TIMER0_TCNT0_SetValue(0);
	ultrasonic_counter=0;
	Ext_Int_MCUCR_Reg=0x02;
	while(!GetBit(Ext_Int_GIFR_Reg,6));
	SetBit(Ext_Int_GIFR_Reg,6);
	ultrasonic_timer_ticks = TCNT0 + (255 * ultrasonic_counter);
	ClearBit(GINT_SREG_Reg,7);
	distance=(u32)((34300 * (ultrasonic_timer_ticks/2))/16000000);
	_delay_ms(100);
	return distance;
}