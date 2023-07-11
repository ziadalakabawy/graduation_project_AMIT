/*
 * TIMER2_Types.h
 *
 * Created: 7/10/2023 8:35:22 AM
 *  Author: hp
 */ 


#ifndef TIMER2_TYPES_H_
#define TIMER2_TYPES_H_

//FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00

typedef struct
{
	u8 CS20_Bit:1;
	u8 CS21_Bit:1;
	u8 CS22_Bit:1;
	u8 WGM21_Bit:1;
	u8 COM20_Bit:1;
	u8 COM21_Bit:1;
	u8 WGM20_Bit:1;
	u8 FOC2_Bit:1;
}TIMER2_TCCR2Bits;

typedef union{
	u8 AllRegister;
	TIMER2_TCCR2Bits Bits;
}TIMER2_TCCR2Types;


typedef enum{
	Normal_2=0,
	PWM_PhaseCorrect_2,
	CTC_2,
	PWM_Fast_2
}TIMER2_ModeTypes;

typedef enum{
	No_Clock_2=0,
	No_Prescaling_2,
	Clock_8_2,
	Clock_64_2,
	Clock_256_2,
	Clock_1024_2,
	Clock_Ext_Falling_2,
	Clock_Ext_Rising_2
}TIMER2_PrescalingTypes;

typedef enum{
	COM0_Disable_2=0,
	COM0_Non_Inverting_2=2,
	COM0_Inverting_2
}TIMER2_COM2Types;


typedef enum{
	TOVInt_Disable_2=0,
	TOVInt_Enable_2
}TIMER2_TOVIntTypes;

typedef struct
{
	TIMER2_ModeTypes mode;
	TIMER2_PrescalingTypes prescaling;
	TIMER2_COM2Types COM2Mode;
	TIMER2_TOVIntTypes TOVInt_Status;
}TIMER2_InitTypes;


#endif /* TIMER2_TYPES_H_ */