/*
 * DIO.h
 *
 * Created: 3/25/2023 8:55:43 PM
 *  Author: user
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "STD_Types.h"
#include "BitMath.h"
#include "DIO_Reg.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"

void DIO_WriteChannel(DIO_ChannelTypes channelId,STD_LevelTypes level);
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes channelId);
void DIO_ToggleChannel(DIO_ChannelTypes channelId);
void DIO_ConfigChannel(DIO_ChannelTypes channelId,DIO_DirTypes direction);
void DIO_WritePort(DIO_PortTypes portId,u8 portValue);
u8 DIO_ReadPort(DIO_PortTypes portId);
void DIO_WriteChannelGroup(DIO_PortTypes portId,u8 portValue,u8 mask);
#endif /* DIO_H_ */