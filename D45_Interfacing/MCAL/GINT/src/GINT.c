/*
 * GINT.c
 *
 * Created: 4/7/2023 9:05:54 PM
 *  Author: user
 */ 
#include "GINT.h"

void GINT_EnableAllInterrupts(void){
	SetBit(GINT_SREG_Reg,GINT_SREG_IBit);
}
void GINT_DisableAllInterrupts(void){
	ClearBit(GINT_SREG_Reg,GINT_SREG_IBit);
}