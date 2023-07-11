/*
* DIO.c
*
* Created: 3/25/2023 8:59:05 PM
*  Author: user
*/
#include "DIO.h"

void DIO_WriteChannel(DIO_ChannelTypes channelId,STD_LevelTypes level){
	DIO_PortTypes Portx = channelId/8;
	DIO_ChannelTypes BitNo = channelId%8;
	switch(Portx){
		case DIO_PortA:
		if (level == STD_High)
		{
			SetBit(PORTA_Reg,BitNo);
		}
		else
		{
			ClearBit(PORTA_Reg,BitNo);
		}
		break;
		case DIO_PortB:
		if (level == STD_High)
		{
			SetBit(PORTB_Reg,BitNo);
		}
		else
		{
			ClearBit(PORTB_Reg,BitNo);
		}
		break;
		case DIO_PortC:
		if (level == STD_High)
		{
			SetBit(PORTC_Reg,BitNo);
		}
		else
		{
			ClearBit(PORTC_Reg,BitNo);
		}
		break;
		case DIO_PortD:
		if (level == STD_High)
		{
			SetBit(PORTD_Reg,BitNo);
		}
		else
		{
			ClearBit(PORTD_Reg,BitNo);
		}
		break;
	}
}
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes channelId){
	DIO_PortTypes Portx = channelId/8;
	DIO_ChannelTypes BitNo = channelId%8;
	STD_LevelTypes bitValue = STD_Low;
	switch(Portx){
		case DIO_PortA:
		bitValue = GetBit(PINA_Reg,BitNo);
		break;
		case DIO_PortB:
		bitValue = GetBit(PINB_Reg,BitNo);
		break;
		case DIO_PortC:
		bitValue = GetBit(PINC_Reg,BitNo);
		break;
		case DIO_PortD:
		bitValue = GetBit(PIND_Reg,BitNo);
		break;
	}
	return bitValue;
}
void DIO_ToggleChannel(DIO_ChannelTypes channelId){
	DIO_PortTypes Portx = channelId/8;
	DIO_ChannelTypes BitNo = channelId%8;
	switch(Portx){
		case DIO_PortA:
		ToggleBit(PORTA_Reg,BitNo);
		break;
		case DIO_PortB:
		ToggleBit(PORTB_Reg,BitNo);
		break;
		case DIO_PortC:
		ToggleBit(PORTC_Reg,BitNo);
		break;
		case DIO_PortD:
		ToggleBit(PORTD_Reg,BitNo);
		break;
	}
}
void DIO_ConfigChannel(DIO_ChannelTypes channelId,DIO_DirTypes direction){
	DIO_PortTypes Portx = channelId/8;
	DIO_ChannelTypes BitNo = channelId%8;
	switch(Portx){
		case DIO_PortA:
		if (direction == Output)
		{
			SetBit(DDRA_Reg,BitNo);
		}
		else
		{
			ClearBit(DDRA_Reg,BitNo);
		}
		break;
		case DIO_PortB:
		if (direction == Output)
		{
			SetBit(DDRB_Reg,BitNo);
		}
		else
		{
			ClearBit(DDRB_Reg,BitNo);
		}
		break;
		case DIO_PortC:
		if (direction == Output)
		{
			SetBit(DDRC_Reg,BitNo);
		}
		else
		{
			ClearBit(DDRC_Reg,BitNo);
		}
		break;
		case DIO_PortD:
		if (direction == Output)
		{
			SetBit(DDRD_Reg,BitNo);
		}
		else
		{
			ClearBit(DDRD_Reg,BitNo);
		}
		break;
	}
}
void DIO_WritePort(DIO_PortTypes portId,u8 portValue){
	switch(portId){
		case DIO_PortA:
		PORTA_Reg = portValue;
		break;
		case DIO_PortB:
		PORTB_Reg = portValue;
		break;
		case DIO_PortC:
		PORTC_Reg = portValue;
		break;
		case DIO_PortD:
		PORTD_Reg = portValue;
		break;
	}
}
u8 DIO_ReadPort(DIO_PortTypes portId){
	u8 portValue = STD_Low;
	switch(portId){
		case DIO_PortA:
		portValue = PORTA_Reg;
		break;
		case DIO_PortB:
		portValue = PORTB_Reg;
		break;
		case DIO_PortC:
		portValue = PORTC_Reg;
		break;
		case DIO_PortD:
		portValue = PORTD_Reg;
		break;
	}
	return portValue;
}
void DIO_WriteChannelGroup(DIO_PortTypes portId,u8 portValue,u8 mask){
	switch(portId){
		case DIO_PortA:
		PORTA_Reg = (PORTA_Reg & ~mask)|(portValue & mask);
		break;
		case DIO_PortB:
		PORTB_Reg = (PORTB_Reg & ~mask)|(portValue & mask);
		break;
		case DIO_PortC:
		PORTC_Reg = (PORTC_Reg & ~mask)|(portValue & mask);
		break;
		case DIO_PortD:
		PORTD_Reg = (PORTD_Reg & ~mask)|(portValue & mask);
		break;	
	}
}