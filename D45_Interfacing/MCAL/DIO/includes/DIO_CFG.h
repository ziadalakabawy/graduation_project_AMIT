/*
* DIO_CFG.h
*
* Created: 3/25/2023 9:18:54 PM
*  Author: user
*/


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "STD_Types.h"
#include "BitMath.h"
#include "DIO_Reg.h"
#include "DIO_Types.h"
#include "DIO.h"

typedef struct{
	DIO_DirTypes direction;
	STD_LevelTypes level;
}DIO_PinCfg;

#define PINCOUNT 32

void DIO_Init(void);

#endif /* DIO_CFG_H_ */