/*
* Keypad_Config.h
*
* Created: 4/1/2023 8:41:09 PM
*  Author: user
*/


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "DIO.h"

#define r0 DIO_ChannelD0
#define r1 DIO_ChannelD1
#define r2 DIO_ChannelD2
#define r3 DIO_ChannelD3

#define c0 DIO_ChannelD4
#define c1 DIO_ChannelD5
#define c2 DIO_ChannelD6
#define c3 DIO_ChannelD7

#define rowsCount 4
#define colsCount 4

u8 keypadRows[rowsCount] = {r0,r1,r2,r3};
u8 keypadCols[colsCount] = {c0,c1,c2,c3};
u8 keypad[rowsCount][colsCount] = {{'7','8','9','/'},
								   {'4','5','6','*'},
								   {'1','2','3','-'},
								   {'C','0','=','+'}};


#endif /* KEYPAD_CONFIG_H_ */