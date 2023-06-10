

// include .h files
#include "DIO.h"


// function definition

// -------------init------------------------

void DIO_init(uint8_t portNumber ,uint8_t pintNumber , uint8_t direction){
	
	
		if(portNumber == PORT_A)
		{
			if(direction == IN){
				DDRA &= ~(1<<pintNumber); //input
			}
		
			else if(direction == OUT){
				DDRA |= (1<<pintNumber); //output
			}
		
			else{
				// error handling
			}
		}
		
		else if(portNumber == PORT_B)
		{
			if(direction == IN){
				DDRB &= ~(1<<pintNumber); //input
				}
			
			else if(direction == OUT){
				DDRB |= (1<<pintNumber); //output
				}
			
			else{
				// error handling
				}
		}
		
		
		
		
		else if(portNumber == PORT_C)
		{
			if(direction == IN){
				DDRC &= ~(1<<pintNumber); //input
				}
			
			else if(direction == OUT){
				DDRC |= (1<<pintNumber); //output
				}
			
			else{
					// error handling
				}
		}
			
		else if(portNumber == PORT_D)
		{
			
			if(direction == IN){
				DDRD &= ~(1<<pintNumber); //input
			}
				
			else if(direction == OUT){
				DDRD |= (1<<pintNumber); //output
				}
			
			else{
				// error handling
				}
		}
		
		else 
		{
			// Hanling Error
		}
}

// ---------------Write----------------------

void DIO_write(uint8_t portNumber ,uint8_t pintNumber , uint8_t value){
	
	

		if(portNumber == PORT_A)
		{
			if(value == LOW){
				PORTA &= ~(1<<pintNumber); //write 0
				}
			
			else if(value == HIGH){
				PORTA |= (1<<pintNumber); //write 1
				}
			
			else{
				// error handling
				}
		}
	
		
		else if(portNumber == PORT_B)
		{
			if(value == LOW){
				PORTB &= ~(1<<pintNumber); //write 0
				}
			
			else if(value == HIGH){
				PORTB |= (1<<pintNumber); //write 1
				}
			
			else{
				// error handling
				}
		}
		
		
		else if(portNumber == PORT_C)
		{
			if(value == LOW){
				PORTC &= ~(1<<pintNumber); //write 0
				}
			
			else if(value == HIGH){
				PORTC |= (1<<pintNumber); //write 1
				}
			
			else{
				// error handling
				}
		}
		
		
		else if(portNumber == PORT_D)
		{
			if(value == LOW){
				PORTD &= ~(1<<pintNumber); //write 0
				}
			
			else if(value == HIGH){
				PORTD |= (1<<pintNumber); //write 1
				}
			
			else{
				// error handling
				}
		}
	
		else
		{
			//Handling Errors	
		}
	
}


//-----------------read------------------------

void DIO_read(uint8_t portNumber ,uint8_t pintNumber , uint8_t* value){
	
	
		
		if(portNumber == PORT_A){
			
			*value = (PINA &(1<<pintNumber))>>pintNumber ;  //get state read bit 0 or 1
		}
		

		
		else if(portNumber == PORT_B){
			
			*value = (PINB &(1<<pintNumber))>>pintNumber ;
		}
		

		
		else if(portNumber == PORT_C){
			
			*value = (PINC &(1<<pintNumber))>>pintNumber ;
		}
		

		
		else if(portNumber == PORT_D){
			
			*value = (PIND &(1<<pintNumber))>>pintNumber ;
		}


		else
		{
			//Handling Errors
		}
	
	
}


//-----------------toggle------------------------

void DIO_toggle(uint8_t portNumber ,uint8_t pintNumber){
	
	
		
		if(portNumber == PORT_A){
		PORTA ^= (1<<pintNumber) ;
		}
		
		else if(portNumber == PORT_B){
		PORTB ^= (1<<pintNumber) ;
		}
		
		else if(portNumber == PORT_C){
		PORTC ^= (1<<pintNumber) ;
		}

		else if(portNumber == PORT_D){
		PORTD ^= (1<<pintNumber) ;
		}
		
		else
		{
			//Handling Errors
		}
	
}