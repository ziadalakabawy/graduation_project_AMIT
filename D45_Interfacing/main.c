/*
* D45_Interfacing.c
*
* Created: 3/18/2023 8:09:34 PM
* Author : user
*/

#include <avr/io.h>
#include <stdlib.h>
#include "stdio.h"
#include "Clock.h"
#include "BitMath.h"
#include "DIO.h"
#include "LCD.h"
#include "GINT.h"
#include "ADC.h"
#include "PWM.h"
#include <avr/eeprom.h>	
#include "TIMER1.h"
#include "ServoMotor.h"


volatile u32 buttonTimer = 0;
volatile u32 buttonTimer_2=0;
volatile u8 flag=0;
int main(void)
{
	DIO_Init();
	LCD_Init();
	TIMER1_InitTypes options_1={PWM_Fast,Clock_64,COM1A_Non_Inverting,COM1B_Non_Inverting,TOVInt_Disable};
	TIMER1_Init(&options_1);
	TCNT0=47;
	TCCR0=(1<<CS01)|(1<<CS00);
	TCCR2 |= (1 << CS22) | (1 << CS21);  // Timer2, normal mode, /64 prescaler
	ADC_InitTypes options={ADC_Prescaler64,ADC_Vref_Internal};
	ADC_Init(&options);
	u16 readvalue= 0;
	s8 crtvalue[10];
	s8 setvalue[10];
	s8 EE_read[10],EE_write;
	DIO_ConfigChannel(DIO_ChannelC2,Output); // Heater
	DIO_ConfigChannel(DIO_ChannelC3,Output);	// Cooler
	DIO_ConfigChannel(DIO_ChannelD2,Output);
	DIO_ConfigChannel(DIO_ChannelD3,Output);
	DIO_ConfigChannel(DIO_ChannelD6,Output);
	DIO_ConfigChannel(DIO_ChannelC4,Input);		//ON/OFF button
	DIO_ConfigChannel(DIO_ChannelD0,Input);		//DOWN button
	DIO_ConfigChannel(DIO_ChannelD1,Input);  //UP button
	GINT_EnableAllInterrupts();
	u8 displaystate=1,set_temp=25,Current_temp=0,ON=0;
	//LCD_String("current temp: ");
	memset(EE_read,0,15);
	while (1)
	{
		if(DIO_ReadChannel(DIO_ChannelC4) == STD_High && ON==0){ //////the power on function
			LCD_Init();
			
			displaystate=0;
			ON=1;
			TIMSK=(1<<TOIE0);
			TIMSK |= (1 << TOIE2);      // Enable Timer/Counter2 overflow interrupt
			eeprom_read_block(setvalue,0,strlen(setvalue));
			LCD_String(setvalue);
		}
		//s8 state[10];
		else if (DIO_ReadChannel(DIO_ChannelC4)==STD_High && ON==1)/////// the power off function
		{
			LCD_Cmd(0x08);
			TIMSK=(0<<TOIE0);
			TIMSK |= (0 << TOIE2);
			DIO_WriteChannel(DIO_ChannelD2,STD_Low);
			ON=0;
			displaystate=1;
			DIO_WriteChannel(DIO_ChannelC3,STD_Low);
			DIO_WriteChannel(DIO_ChannelC2,STD_Low);
			buttonTimer=0;
			eeprom_write_block(setvalue,0,strlen(setvalue));
		}
		if (buttonTimer == 0 && ON==1 &&displaystate==0) {
			// Exit the temperature setting mode
			// Perform necessary actions here
			// Reset button press count
			Current_temp= ADC_Read(ADC_Channel0);
			itoa(Current_temp,crtvalue,10);
			
			LCD_String(crtvalue);
			_delay_ms(200);
			LCD_Clear();
			if(Current_temp<(set_temp-5)){
				DIO_WriteChannel(DIO_ChannelC2,STD_High);
				DIO_WriteChannel(DIO_ChannelC3,STD_Low);
				DIO_WriteChannel(DIO_ChannelD3,STD_Low);
				DIO_WriteChannel(DIO_ChannelD6,STD_Low);
				PWM_Generate_COM1B(0);
				ServoMotor(0);
				if (flag==1)
				{
					
					DIO_ToggleChannel(DIO_ChannelD2);
				}
			}
			if(Current_temp>(set_temp+5)){
				
				DIO_WriteChannel(DIO_ChannelC3,STD_High);
				DIO_WriteChannel(DIO_ChannelC2,STD_Low);
				DIO_WriteChannel(DIO_ChannelD2,STD_High);
				DIO_WriteChannel(DIO_ChannelD3,STD_High);
				DIO_WriteChannel(DIO_ChannelD6,STD_Low);
				PWM_Generate_COM1B(100);
				ServoMotor(90);
			}
		}
		if(DIO_ReadChannel(DIO_ChannelD0) == STD_High || DIO_ReadChannel(DIO_ChannelD1) == STD_High){
			buttonTimer=4883;
		}
		if (buttonTimer>0)
		{
			buttonTimer_2=0;
			if (DIO_ReadChannel(DIO_ChannelD0) == STD_High && set_temp<50 )
			{
				DIO_WriteChannel(DIO_ChannelD2,STD_Low);
				set_temp+=5;
				//LCD_String("Button UP Pressed");
			}
			if (DIO_ReadChannel(DIO_ChannelD1) == STD_High && set_temp>0)
			{
				DIO_WriteChannel(DIO_ChannelD2,STD_Low);
				set_temp-=5;
				//LCD_String("Button DOWN Pressed");
				
			}
			itoa(set_temp,setvalue,10);
			LCD_String(setvalue);
			_delay_ms(200);
			LCD_Clear();
		}
		
	}
}
ISR(TIMER0_OVF_vect) {
	// Timer/Counter0 overflow interrupt handler
	if (buttonTimer > 0) {
		buttonTimer--;
		
	}
}
ISR(TIMER2_OVF_vect) {
	buttonTimer_2++;
	if (buttonTimer_2 == 2000) {
		TCNT2 = 111; 
		buttonTimer_2=0;
		flag=1;
		
	}
}
