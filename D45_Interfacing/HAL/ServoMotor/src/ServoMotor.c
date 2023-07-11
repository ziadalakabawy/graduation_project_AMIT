/*
* ServoMotor.c
*
* Created: 4/14/2023 9:45:25 PM
*  Author: user
*/
#include "ServoMotor.h"

void ServoMotor(s32 angle){
	DIO_ConfigChannel(DIO_ChannelD5,Output);
	u16 ICR_Value = 0xFFFF;
	u16 OCR1A_Value = (u16)(((angle-MiniAngle)*((float)(MaxCount-MiniCount)/(MaxAngle-MiniAngle)))+MiniCount-1);
	TIMER1_OCR1A_SetValue(OCR1A_Value);
	TIMER1_ICR1_SetValue(ICR_Value);
	//TIMER1_InitTypes options = {PWM_Fast,Clock_64,COM1A_Non_Inverting,COM1B_Disable,TOVInt_Disable};
	//TIMER1_Init(&options);
}