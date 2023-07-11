/*
 * Keypad.c
 *
 * Created: 4/1/2023 8:41:23 PM
 *  Author: user
 */ 
#include "Keypad_Config.h"
#include "Keypad.h"

void Keypad_Init(void){
	//cols -> Input & connect Pullup Res.
	for (u8 i=0;i<colsCount;i++)
	{
		DIO_ConfigChannel(keypadCols[i],Input);//cols -> Input
		DIO_WriteChannel(keypadCols[i],STD_High);//connect Pullup Res.
	}
	//rows -> output & 5V
	for (u8 j=0;j<rowsCount;j++)
	{
		DIO_ConfigChannel(keypadRows[j],Output);//rows -> output
		DIO_WriteChannel(keypadRows[j],STD_High);// 5V
	}
}
u8 GetKey(void){
	for (u8 i=0;i<rowsCount;i++)
	{
		DIO_WriteChannel(keypadRows[i],STD_Low);
		for (u8 j=0;j<colsCount;j++)
		{
			if(DIO_ReadChannel(keypadCols[j]) == STD_Low){
				while(DIO_ReadChannel(keypadCols[j]) == STD_Low);
				return keypad[i][j];
			}
		}
		DIO_WriteChannel(keypadRows[i],STD_High);
	}
	return STD_Low;
}