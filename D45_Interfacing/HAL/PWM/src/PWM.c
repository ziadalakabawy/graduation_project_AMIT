/*
 * PWM.c
 *
 * Created: 4/14/2023 9:00:25 PM
 *  Author: user
 */ 
#include "PWM.h"

void PWM_Generate_COM1A(u8 duty){
	DIO_ConfigChannel(DIO_ChannelD5,Output);
	u16 ICR_Value = 0xFFFF;
	u16 OCR1A_Value = (u16)((((float)duty/100)*((u32)ICR_Value+1))-1);
	TIMER1_OCR1A_SetValue(OCR1A_Value);
	TIMER1_ICR1_SetValue(ICR_Value);
	//TIMER1_InitTypes options = {PWM_Fast,Clock_64,COM1A_Non_Inverting,COM1B_Disable,TOVInt_Disable};
	//TIMER1_Init(&options);
}
void PWM_Generate_COM1B(u8 duty){
	DIO_ConfigChannel(DIO_ChannelD4,Output);
	u16 ICR_Value = 0xFFFF;
	u16 OCR1B_Value = (u16)((((float)duty/100)*((u32)ICR_Value+1))-1);
	TIMER1_OCR1B_SetValue(OCR1B_Value);
	TIMER1_ICR1_SetValue(ICR_Value);
	//TIMER1_InitTypes options = {PWM_Fast,Clock_64,COM1A_Non_Inverting,COM1B_Disable,TOVInt_Disable};
	//TIMER1_Init(&options);
}