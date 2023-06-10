


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Service/Registers.h"
#include "../../Service/Types_define.h"
#include "../../Service/bit_manipulation.h"
#include "math.h"



#define F_CPU 1000000   //1MHZ

//TCCR0- Timer/Counter Control Register, pin definitions
#define CS00     0
#define CS01     1
#define CS02     2
#define WGM01    3
#define COM00    4
#define COM01    5
#define WGM00    6
#define FOC0     7

//TCCR1B – Timer/Counter1 Control Register B, pin definitions
#define CS10     0
#define CS11     1
#define CS12     2
#define WGM12    3
#define WGM13    4

void Timer0_init(); //no prescaler

void Timer0_prescaler (uint16 prescaler);

void Timer0_delay(uint16 time_ms);






#endif /* TIMER_H_ */