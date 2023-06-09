



#ifndef REGISTERS_H_
#define REGISTERS_H_

#include"Types_define.h"
#include <avr/interrupt.h> 
/*******************************************/
/*             DIO Registers               */
/*******************************************/

// PORTA Registers
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)


// PORTC Registers
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

// PORTB Registers
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)


// PORTD Registers
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)


/*******************************************/
/*           Interrupt Registers               */
/*******************************************/
#define SREG   (* (volatile uint8_t *) (0x5F))
#define GICR   (* (volatile uint8_t *) (0x5B))
#define GIFR   (* (volatile uint8_t *) (0x5A))
#define MCUCR  (* (volatile uint8_t *) (0x55))

#endif /* REGISTERS_H_ */
