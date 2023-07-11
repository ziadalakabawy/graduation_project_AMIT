/*
 * UART_Reg.h
 *
 * Created: 4/29/2023 8:08:50 PM
 *  Author: user
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_

#include "UART_Types.h"

#define UCSRC_SelectEnable (1<<7)

#define UART ((volatile UART_Registers*)0x29)


#endif /* UART_REG_H_ */