/*
 * UART.c
 *
 * Created: 4/29/2023 8:09:16 PM
 *  Author: user
 */ 
#include "UART.h"

void UART_Init(UART_ConfigTypes * options){
	u16 MyUBRR = 0;
	if (options->doubleSpeedMode == DoubleSpeed_Enable)
	{
		UART->UCSRA_Reg.Bits.U2X_Bit = 1;
		MyUBRR = (F_CPU/(8UL*options->baudRateMode))-1;
	} 
	else
	{
		UART->UCSRA_Reg.Bits.U2X_Bit = 0;
		MyUBRR = (F_CPU/(16UL*options->baudRateMode))-1;
	}
	UART->UBRRL_Reg = MyUBRR;
	UART->UCSRC_UBRRH_Reg.UCSRC_UBRRH_AllRegister = MyUBRR>>8;
	UART->UCSRB_Reg.Bits.RXEN_Bit = options->rxMode;
	UART->UCSRB_Reg.Bits.TXEN_Bit = options->txMode;
	UART->UCSRC_UBRRH_Reg.UCSRC_UBRRH_AllRegister |= (UCSRC_SelectEnable)|(options->stopBitsMode<<3);
	UART->UCSRC_UBRRH_Reg.UCSRC_UBRRH_AllRegister |= (UCSRC_SelectEnable)|(options->parityMode<<4);
	if (options->characterSizeMode == CharacterSize_9Bits)
	{
				UART->UCSRC_UBRRH_Reg.UCSRC_Bits.UCSZ0_Bit = 1;
				UART->UCSRC_UBRRH_Reg.UCSRC_Bits.UCSZ1_Bit = 1;
				UART->UCSRB_Reg.Bits.UCSZ2_Bit = 1;
	} 
	else
	{
		UART->UCSRC_UBRRH_Reg.UCSRC_UBRRH_AllRegister |= (UCSRC_SelectEnable)|(options->characterSizeMode<<1);
	}
	
}
void UART_Transmit(u8 data){
	while(UART->UCSRA_Reg.Bits.UDRE_Bit == 0);
	UART->UDR_Reg = data;
}
void UART_TransmitString(s8 * string){
	u8 i = 0;
	while(string[i] != '\0'){
		UART_Transmit(string[i]);
		i++;
	}
}
u8 UART_Receive(void){
	while(UART->UCSRA_Reg.Bits.RXC_Bit == 0);
	return UART->UDR_Reg;
}