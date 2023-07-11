#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "TIMER1.h"
#include "BitMath.h"
#include "DIO.h"
#include "Clock.h"
#include "GINT.h"
#include "TIMER0.h"
#include "Ext_Int.h"
#include <stdlib.h>
#include "LCD.h"
#include <avr/interrupt.h>

#define TRIG_PIN DIO_ChannelD0
#define TRIG_PORT 3
#define ECHO_PIN DIO_ChannelD2
#define ECHO_PORT 3

u16 ultrasonic_u16_get_distance () ;
void ultrasonic_timer (void);


#endif /* ULTRASONIC_H_ */