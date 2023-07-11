/*
 * Ext_Int_Reg.h
 *
 * Created: 4/7/2023 9:09:37 PM
 *  Author: user
 */ 


#ifndef EXT_INT_REG_H_
#define EXT_INT_REG_H_

#include "STD_Types.h"

#define Ext_Int_MCUCR_Reg (*((volatile u8*)0x55))
#define Ext_Int_MCUCSR_Reg (*((volatile u8*)0x54))
#define Ext_Int_GICR_Reg (*((volatile u8*)0x5B))
#define Ext_Int_GIFR_Reg (*((volatile u8*)0x5A))

#endif /* EXT_INT_REG_H_ */