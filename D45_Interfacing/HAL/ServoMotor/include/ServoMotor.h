/*
 * ServoMotor.h
 *
 * Created: 4/14/2023 9:45:12 PM
 *  Author: user
 */ 


#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_

#include "TIMER1.h"
#include "DIO.h"

#define MiniAngle 0
#define MaxAngle 180
#define MiniCount 250
#define MaxCount 500

void ServoMotor(s32 angle);

#endif /* SERVOMOTOR_H_ */