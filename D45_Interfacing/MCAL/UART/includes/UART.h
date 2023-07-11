/*
 * UART.h
 *
 * Created: 4/29/2023 8:08:29 PM
 *  Author: user
 */ 


#ifndef UART_H_
#define UART_H_

#include "UART_Reg.h"
#include "UART_Types.h"
#include "Clock.h"

void UART_Init(UART_ConfigTypes * options);
void UART_Transmit(u8 data);
void UART_TransmitString(s8 * string);
u8 UART_Receive(void);

#endif /* UART_H_ */