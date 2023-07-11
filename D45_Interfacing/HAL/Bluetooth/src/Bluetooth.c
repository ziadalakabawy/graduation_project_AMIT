/*
 * Bluetooth.c
 *
 * Created: 4/29/2023 9:22:52 PM
 *  Author: user
 */ 
#include "Bluetooth.h"

void Bluetooth_Init(UART_ConfigTypes * options){
	UART_Init(options);
}
void Bluetooth_Transmit(u8 data){
	UART_Transmit(data);
}
void Bluetooth_TransmitString(s8 * string){
	UART_TransmitString(string);
}
u8 Bluetooth_Receive(void){
	return UART_Receive();
}