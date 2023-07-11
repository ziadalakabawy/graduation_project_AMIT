/*
 * TIMER0_Types.h
 *
 * Created: 7/8/2023 12:00:59 AM
 *  Author: hp
 */ 


#ifndef TIMER0_TYPES_H_
#define TIMER0_TYPES_H_
//FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00

typedef struct
{
	u8 CS00_Bit:1;
	u8 CS01_Bit:1;
	u8 CS02_Bit:1;
	u8 WGM01_Bit:1;
	u8 COM00_Bit:1;
	u8 COM01_Bit:1;
	u8 WGM00_Bit:1;
	u8 FOC0_Bit:1;
}TIMER0_TCCR0Bits;

typedef union{
	u8 AllRegister;
	TIMER0_TCCR0Bits Bits;
}TIMER0_TCCR0Types;


typedef enum{
	Normal_0=0,
	PWM_PhaseCorrect_0,
	CTC_0,
	PWM_Fast_0
}TIMER0_ModeTypes;

typedef enum{
	No_Clock_0=0,
	No_Prescaling_0,
	Clock_8_0,
	Clock_64_0,
	Clock_256_0,
	Clock_1024_0,
	Clock_Ext_Falling_0,
	Clock_Ext_Rising_0
}TIMER0_PrescalingTypes;

typedef enum{
	COM0_Disable_0=0,
	COM0_Non_Inverting_0=2,
	COM0_Inverting_0
}TIMER0_COM0Types;


typedef enum{
	TOVInt_Disable_0=0,
	TOVInt_Enable_0
}TIMER0_TOVIntTypes;

typedef struct
{
	TIMER0_ModeTypes mode;
	TIMER0_PrescalingTypes prescaling;
	TIMER0_COM0Types COM0Mode;
	TIMER0_TOVIntTypes TOVInt_Status;
}TIMER0_InitTypes;




#endif /* TIMER0_TYPES_H_ */