



#ifndef REGISTERS_H_
#define REGISTERS_H_

#include"Types_define.h"

#define EXT_INT0 __vector_1
#define EXT_INT1 __vector_2
#define TIMER0_OVF __vector_11
#define ISR(INT_VECT)	void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)
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
//#define GICR   (* (volatile uint8_t *) (0x5B))
//#define GIFR   (* (volatile uint8_t *) (0x5A))
//#define MCUCR  (* (volatile uint8_t *) (0x55))
//#define MCUCSR (* (volatile uint8_t *) (0x54))


/*******************************************/
/*            TIMER0 Registers               */
/*******************************************/
#define OCR0   *((volatile uint8_t*)0x5C)
#define GICR   *((volatile uint8_t*)0x5B)
#define GIFR   *((volatile uint8_t*)0x5A)
#define TIMSK  *((volatile uint8_t*)0x59)
#define TIFR   *((volatile uint8_t*)0x58)
#define SPMCR  *((volatile uint8_t*)0x57)
#define TWCR   *((volatile uint8_t*)0x56)
#define MCUCR  *((volatile uint8_t*)0x55)
#define MCUCSR *((volatile uint8_t*)0x54)
#define TCCR0  *((volatile uint8_t*)0x53)
#define TCNT0  *((volatile uint8_t*)0x52)
#define TCCR2  *((volatile uint8_t*)0x45)
#define TCNT2  *((volatile uint8_t*)0x44)

//void __vector_2( void )		__attribute__((signal));

#define SFIOR   *((volatile uint8_t*)0x50)




#endif /* REGISTERS_H_ */