
#include "interrupt.h"

void Interrupt_Enable(uint8_t ID, uint8_t Mode){
	
	GICR |= (1<<ID);
	
	switch(ID){
		
		case EX_INT0 :
				MCUCR &= ~(1 << EXTI_ISC00);
				MCUCR &= ~(1 << EXTI_ISC01);
				
				MCUCR |= ( ((Mode >> 0) & 1) << EXTI_ISC00 );
				MCUCR |= ( ((Mode >> 1) & 1) << EXTI_ISC01 );
				break;
				
		case EX_INT1 :	
			MCUCR &= ~(1 << EXTI_ISC10);
			MCUCR &= ~(1 << EXTI_ISC11);
			
			MCUCR |= ( ((Mode >> 0) & 1) << EXTI_ISC10 );
			MCUCR |= ( ((Mode >> 1) & 1) << EXTI_ISC11 );
			break;	
			
		case EX_INT2 :
			MCUCR &= ~(1 << EXTI_ISC2);
		
			MCUCR |= ( ((Mode >> 0) & 1) << EXTI_ISC10 );
				
	}
	
}

void Interrupt_Disable(uint8_t ID){
	
	GICR &= ~(1<<ID);
	
}