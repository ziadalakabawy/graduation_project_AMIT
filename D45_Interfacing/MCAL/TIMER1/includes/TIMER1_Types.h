/*
* TIMER1_Types.h
*
* Created: 4/14/2023 8:23:53 PM
*  Author: user
*/


#ifndef TIMER1_TYPES_H_
#define TIMER1_TYPES_H_

typedef struct
{
	u8 WGM10_Bit:1;
	u8 WGM11_Bit:1;
	u8 FOC1B_Bit:1;
	u8 FOC1A_Bit:1;
	u8 COM1B0_Bit:1;
	u8 COM1B1_Bit:1;
	u8 COM1A0_Bit:1;
	u8 COM1A1_Bit:1;
}TIMER1_TCCR1ABits;

typedef struct
{
	u8 CS10_Bit:1;
	u8 CS11_Bit:1;
	u8 CS12_Bit:1;
	u8 WGM12_Bit:1;
	u8 WGM13_Bit:1;
	u8 RESERVED_Bit:1;
	u8 ICES1_Bit:1;
	u8 ICNC1_Bit:1;
}TIMER1_TCCR1BBits;

typedef union{
	u8 AllRegister;
	TIMER1_TCCR1ABits Bits;
}TIMER1_TCCR1ATypes;

typedef union{
	u8 AllRegister;
	TIMER1_TCCR1BBits Bits;
}TIMER1_TCCR1BTypes;

typedef enum{
	Normal=0,
	CTC,
	PWM_Fast,
	PWM_PhaseCorrect
}TIMER1_ModeTypes;

typedef enum{
	No_Clock=0,
	No_Prescaling,
	Clock_8,
	Clock_64,
	Clock_256,
	Clock_1024,
	Clock_Ext_Falling,
	Clock_Ext_Rising
}TIMER1_PrescalingTypes;

typedef enum{
	COM1A_Disable=0,
	COM1A_Non_Inverting=2,
	COM1A_Inverting
}TIMER1_COM1ATypes;

typedef enum{
	COM1B_Disable=0,
	COM1B_Non_Inverting=2,
	COM1B_Inverting
}TIMER1_COM1BTypes;

typedef enum{
	TOVInt_Disable=0,
	TOVInt_Enable
}TIMER1_TOVIntTypes;

typedef struct
{
	TIMER1_ModeTypes mode;
	TIMER1_PrescalingTypes prescaling;
	TIMER1_COM1ATypes COM1AMode;
	TIMER1_COM1BTypes COM1BMode;
	TIMER1_TOVIntTypes TOVInt_Status;
}TIMER1_InitTypes;

#endif /* TIMER1_TYPES_H_ */