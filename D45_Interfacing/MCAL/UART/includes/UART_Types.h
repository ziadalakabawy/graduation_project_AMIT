/*
* UART_Types.h
*
* Created: 4/29/2023 8:09:02 PM
*  Author: user
*/


#ifndef UART_TYPES_H_
#define UART_TYPES_H_

#include "STD_Types.h"

typedef struct{
	u8 MPCM_Bit:1;
	u8 U2X_Bit:1;
	u8 PE_Bit:1;
	u8 DOR_Bit:1;
	u8 FE_Bit:1;
	u8 UDRE_Bit:1;
	u8 TXC_Bit:1;
	u8 RXC_Bit:1;
}UART_UCSRABits;

typedef struct{
	u8 TXB8_Bit:1;
	u8 RXB8_Bit:1;
	u8 UCSZ2_Bit:1;
	u8 TXEN_Bit:1;
	u8 RXEN_Bit:1;
	u8 UDRIE_Bit:1;
	u8 TXCIE_Bit:1;
	u8 RXCIE_Bit:1;
}UART_UCSRBBits;

typedef struct{
	u8 UCPOL_Bit:1;
	u8 UCSZ0_Bit:1;
	u8 UCSZ1_Bit:1;
	u8 USBS_Bit:1;
	u8 UPM0_Bit:1;
	u8 UPM1_Bit:1;
	u8 UMSEL_Bit:1;
	u8 URSEL_Bit:1;
}UART_UCSRCBits;

typedef union{
	u8 AllRegister;
	UART_UCSRABits Bits;
}UART_UCSRATypes;

typedef union{
	u8 AllRegister;
	UART_UCSRBBits Bits;
}UART_UCSRBTypes;

typedef union{
	u8 UCSRC_UBRRH_AllRegister;
	UART_UCSRCBits UCSRC_Bits;
}UART_UCSRC_UBRRHTypes;

typedef struct{
	u8 UBRRL_Reg;
	UART_UCSRBTypes UCSRB_Reg;
	UART_UCSRATypes UCSRA_Reg;
	u8 UDR_Reg;
	u8 Reserved[19];
	UART_UCSRC_UBRRHTypes UCSRC_UBRRH_Reg;
}UART_Registers;

typedef enum{
	TX_Disable=0,
	TX_Enable
}UART_TXTypes;

typedef enum{
	RX_Disable=0,
	RX_Enable
}UART_RXTypes;

typedef enum{
	CharacterSize_5Bits=0,
	CharacterSize_6Bits,
	CharacterSize_7Bits,
	CharacterSize_8Bits,
	CharacterSize_Reserved1,
	CharacterSize_Reserved2,
	CharacterSize_Reserved3,
	CharacterSize_9Bits
}UART_CharacterSizeTypes;

typedef enum{
	StopBits_1=0,
	StopBits_2
}UART_StopBitsTypes;

typedef enum{
	Parity_Disable=0,
	Parity_Reserved,
	Parity_Even,
	Parity_Odd
}UART_ParityTypes;

typedef enum{
	BaudRate_2400=2400,
	BaudRate_4800=4800,
	BaudRate_9600=9600
}UART_BaudRateTypes;

typedef enum{
	DoubleSpeed_Disable=0,
	DoubleSpeed_Enable
}UART_DoubleSpeedTypes;

typedef struct
{
	UART_BaudRateTypes baudRateMode;
	UART_DoubleSpeedTypes doubleSpeedMode;
	UART_CharacterSizeTypes characterSizeMode;
	UART_ParityTypes parityMode;
	UART_StopBitsTypes stopBitsMode;
	UART_TXTypes txMode;
	UART_RXTypes rxMode;
}UART_ConfigTypes;


#endif /* UART_TYPES_H_ */