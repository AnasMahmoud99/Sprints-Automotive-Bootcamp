

// include .h files
#include "DIO.h"
#include "../../Service/bit_manipulation.h"



// function definition

// -------------init------------------------

void DIO_init(uint8_t portNumber ,uint8_t pintNumber , uint8_t direction){
	
	switch (portNumber)
	{
		case PORT_A :
		
		if(direction == IN){
			Clear_Bit(pintNumber,DDRA); //input
		}
		
		else if(direction == OUT){
			Set_Bit(pintNumber,DDRA); //output
		}
		
		else{
			// error handling
		}
		break;
		
		case PORT_B :
		
		if(direction == IN){
			Clear_Bit(pintNumber,DDRB); //input
		}
		
		else if(direction == OUT){
			Set_Bit(pintNumber,DDRB); //output
		}
		
		else{
			// error handling
		}
		break;
		
		
		
		case PORT_C :
		
		if(direction == IN){
			Clear_Bit(pintNumber,DDRC); //input
		}
		
		else if(direction == OUT){
			Set_Bit(pintNumber,DDRC); //output
		}
		
		else{
			// error handling
		}
		break;
		
		case PORT_D :
		
		if(direction == IN){
			Clear_Bit(pintNumber,DDRD); //input
		}
		
		else if(direction == OUT){
			Set_Bit(pintNumber,DDRD); //output
		}
		
		else{
			// error handling
		}
		break;
		
		default:
		//error handling
		break;
	}
}

// ---------------Write----------------------

void DIO_write(uint8_t portNumber ,uint8_t pintNumber , uint8_t value){
	
	switch (portNumber)
	{
		case PORT_A :
		
		if(value == LOW){
			Clear_Bit(pintNumber,PORTA); //write 0
		}
		
		else if(value == HIGH){
			Set_Bit(pintNumber,PORTA); //write 1
		}
		
		else{
			// error handling
		}
		break;
		
		case PORT_B :
		
		if(value == LOW){
			Clear_Bit(pintNumber,PORTB); //write 0
		}
		
		else if(value == HIGH){
			Set_Bit(pintNumber,PORTB); //write 1
		}
		
		else{
			// error handling
		}
		break;
		
		
		
		case PORT_C :
		
		if(value == LOW){
			Clear_Bit(pintNumber,PORTC); //write 0
		}
		
		else if(value == HIGH){
			Set_Bit(pintNumber,PORTC); //write 1
		}
		
		else{
			// error handling
		}
		break;
		
		case PORT_D :
		
		if(value == LOW){
			Clear_Bit(pintNumber,PORTD); //write 0
		}
		
		else if(value == HIGH){
			Set_Bit(pintNumber,PORTD); //write 1
		}
		
		else{
			// error handling
		}
		break;
		
		default:
		//error handling
		break;
	}
}


//-----------------read------------------------

void DIO_read(uint8_t portNumber ,uint8_t pintNumber , uint8_t* value){
	
	switch(portNumber){
		
		case PORT_A :
		*value = Read_Bit(pintNumber,PINA) ;  //get state read bit 0 or 1
		break;
		
		case PORT_B :
		*value = Read_Bit(pintNumber,PINB) ;
		break;
		
		case PORT_C :
		*value = Read_Bit(pintNumber,PINC) ;
		break;
		
		case PORT_D :
		*value = Read_Bit(pintNumber,PIND) ;
		break;
		
		default:
		//error handling
		break;
		
	}
	
}


//-----------------toggle------------------------

void DIO_toggle(uint8_t portNumber ,uint8_t pintNumber){
	
	switch(portNumber){
		
		case PORT_A :
		Toggle_Bit(pintNumber,PORTA) ;
		break;
		
		case PORT_B :
		Toggle_Bit(pintNumber,PORTB) ;
		break;
		
		case PORT_C :
		Toggle_Bit(pintNumber,PORTC) ;
		break;
		
		case PORT_D :
		Toggle_Bit(pintNumber,PORTD) ;
		break;
		
		default:
		//error handling
		break;
		
	}
	
}