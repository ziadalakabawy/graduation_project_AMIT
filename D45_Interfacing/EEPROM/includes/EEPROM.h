/*
 * EEPROM.h
 *
 * Created: 7/11/2023 12:48:24 AM
 *  Author: hp
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "TWI.h"
void EEPROM_WriteByte(u8 DeviceAdd,u8 LocAdd,u8 data);
u8 EEPROM_ReadByte(u8 DeviceAdd,u8 LocAdd);




#endif /* EEPROM_H_ */