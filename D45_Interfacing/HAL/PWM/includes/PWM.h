/*
 * PWM.h
 *
 * Created: 4/14/2023 9:00:12 PM
 *  Author: user
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "TIMER1.h"
#include "DIO.h"


void PWM_Generate_COM1A(u8 duty);
void PWM_Generate_COM1B(u8 duty);

#endif /* PWM_H_ */