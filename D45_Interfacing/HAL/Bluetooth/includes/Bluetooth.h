/*
 * Bluetooth.h
 *
 * Created: 4/29/2023 9:22:36 PM
 *  Author: user
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "UART.h"

void Bluetooth_Init(UART_ConfigTypes * options);
void Bluetooth_Transmit(u8 data);
void Bluetooth_TransmitString(s8 * string);
u8 Bluetooth_Receive(void);

#endif /* BLUETOOTH_H_ */