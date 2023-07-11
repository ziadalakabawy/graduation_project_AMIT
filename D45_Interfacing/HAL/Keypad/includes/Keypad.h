/*
 * Keypad.h
 *
 * Created: 4/1/2023 8:40:54 PM
 *  Author: user
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"

void Keypad_Init(void);
u8 GetKey(void);


#endif /* KEYPAD_H_ */