

#include "interrupt.h"
#include "../../Service/bit_manipulation.h"


void Interrupt_Enable(uint8_t ID, uint8_t Mode){
	
	Set_Bit(SREG , 7);
	
	switch(ID){
		
		case EX_INT0 :
				Set_Bit(GICR , EX_INT0);
				
				if(Mode == RISING_EDGE)
				{
					Set_Bit(MCUCR , 0);
					Set_Bit(MCUCR , 1);	
				}
				else if(Mode == FALLING_EDGE)
				{
					Set_Bit(MCUCR , 1);
					Clear_Bit(MCUCR  , 0);
				}
				else if(Mode == LOW_LEVEL)
				{
					 Clear_Bit(MCUCR , 0);
					 Clear_Bit(MCUCR , 1);
				}
				else if(Mode == ANY_CHANGE)
				{
					Set_Bit(MCUCR , 0);
					Clear_Bit(MCUCR ,1);
				}
				else
				{
					// Handling Error
				}

				break;
				
		case EX_INT1 :	
			Set_Bit(GICR , EX_INT1);
			
			if(Mode == RISING_EDGE)
			{
				Set_Bit(MCUCR , 0);
				Set_Bit(MCUCR , 1);
			}
			else if(Mode == FALLING_EDGE)
			{
				Set_Bit(MCUCR , 1);
				Clear_Bit(MCUCR  , 0);
			}
			else if(Mode == LOW_LEVEL)
			{
				Clear_Bit(MCUCR , 0);
				Clear_Bit(MCUCR , 1);
			}
			else if(Mode == ANY_CHANGE)
			{
				Set_Bit(MCUCR , 0);
				Clear_Bit(MCUCR ,1);
			}
			else
			{
				// Handling Error
			}

			break;
			
		case EX_INT2 :
			Set_Bit(GICR , EX_INT2);
			
			if(Mode == RISING_EDGE)
			{
				Set_Bit(MCUCR , 0);
				Set_Bit(MCUCR , 1);
			}
			else if(Mode == FALLING_EDGE)
			{
				Set_Bit(MCUCR , 1);
				Clear_Bit(MCUCR  , 0);
			}
			else if(Mode == LOW_LEVEL)
			{
				Clear_Bit(MCUCR , 0);
				Clear_Bit(MCUCR , 1);
			}
			else if(Mode == ANY_CHANGE)
			{
				Set_Bit(MCUCR , 0);
				Clear_Bit(MCUCR ,1);
			}
			else
			{
				// Handling Error
			}

			break;	
	}
	
}

void Interrupt_Disable(){
	
	Clear_Bit(SREG,7);
	
}
