

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../MCU/Registers.h"
#include <avr/interrupt.h>

/*   Definitions of External Interrupt IDs   */
#define EX_INT0	    6
#define EX_INT1 	7
#define EX_INT2	    5

/*   Definitions of External Interrupt Modes   */
#define LOW_LEVEL			0x00
#define ANY_CHANGE			0x01
#define FALLING_EDGE		0x10
#define RISING_EDGE			0x11

// Bit 0,1 – ISC01,ISC00: Interrupt Sense Control 0 Bit0 and Bit1
#define EXTI_ISC00		0
#define EXTI_ISC01		1

// Bit 2,3 – ISC11,ISC10: Interrupt Sense Control 1 Bit2 and Bit3
#define EXTI_ISC10		2
#define EXTI_ISC11   	3

//  Bit 6 – ISC2: Interrupt Sense Control 2
#define EXTI_ISC2		6




void Interrupt_Enable(uint8_t ID, uint8_t Mode);




#endif /* INTERRUPT_H_ */