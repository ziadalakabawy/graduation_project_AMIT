/*
 * SPI.h
 *
 * Created: 5/5/2023 8:04:17 PM
 *  Author: user
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"
#include "SPI_Reg.h"
#include "SPI_Types.h"

void SPI_Init(SPI_ConfigTypes * options);
u8 SPI_TxRx(u8 data);
void SPI_SlaveEnable(DIO_ChannelTypes channelId);
void SPI_SlaveDisable(DIO_ChannelTypes channelId);

#endif /* SPI_H_ */