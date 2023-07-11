/*
 * SSD.h
 *
 * Created: 4/1/2023 9:55:13 PM
 *  Author: user
 */ 


#ifndef SSD_H_
#define SSD_H_

#include "DIO.h"
#include "Clock.h"

void SSD_Init(void);
void SSD_Display(u8 num);
void SSD_Display_With_Delay(u8 num,u32 delay);


#endif /* SSD_H_ */