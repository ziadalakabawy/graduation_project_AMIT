/*
 * Ext_Int.h
 *
 * Created: 4/7/2023 9:10:15 PM
 *  Author: user
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "Ext_Int_Reg.h"
#include "Ext_Int_Types.h"
#include "BitMath.h"
#include <avr/interrupt.h>


void Ext_Interrupt_Enable(Ext_Int_Types interruptId);
void Ext_Interrupt_Disable(Ext_Int_Types interruptId);
void Ext_Interrupt_Sncontrol(Ext_Int_Types interruptId,Snc_Mode_Types mode);
void Ext_Interrupt_SetCallBack(Ext_Int_Types interruptId,void (*ExtIntFunCopyPtr)(void));

#endif /* EXT_INT_H_ */