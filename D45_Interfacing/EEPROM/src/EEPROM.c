/*
 * EEPROM.c
 *
 * Created: 7/11/2023 12:48:48 AM
 *  Author: hp
 */ 
#include "EEPROM.h"
void EEPROM_WriteByte(u8 DeviceAdd,u8 LocAdd,u8 data){
	u8 wDeviceAdd=(DeviceAdd & 0xFE);
	if(TWI_Start()==0x08)
	{
		if (TWI_Send(wDeviceAdd)==0x18)
		{
			if (TWI_Send(LocAdd)==0x28)
			{
				if (TWI_Send(data)==0x28)
				{
					TWI_Stop();
				}
			}
		}
	}
}
u8 EEPROM_ReadByte(u8 DeviceAdd,u8 LocAdd){
	u8 wDeviceAdd=(DeviceAdd & 0xFE);
	u8 rDeviceAdd= (DeviceAdd| 0x01);
	u8 data;
	if(TWI_Start()==0x08)
	{
		if (TWI_Send(wDeviceAdd)==0x18)
		{
			if (TWI_Send(LocAdd)==0x28)
			{
				if (TWI_Start()==0x10)
				{
					if (TWI_Send(rDeviceAdd)== 0x40)
					{
						if (TWI_Read_NAck(&data)==0x58)
						{
							TWI_Stop();
						}
					}
				}
			}
		}
	}
	return data;
}