
#include "Timer.h"

uint16 overflows_number=0 ;

void Timer0_init(){
	
	// Normal State
	Set_Bit(TCCR0,COM00);
	Clear_Bit(TCCR0,COM01);	  
	Clear_Bit(TCCR0, WGM00);
	Clear_Bit(TCCR0, WGM01);
		
}



void Timer0_prescaler (uint16 prescaler){
		
		if(prescaler == 0) //Stop Timer
		{
			Clear_Bit(TCCR0,CS00);
			Clear_Bit(TCCR0,CS01);
			Clear_Bit(TCCR0,CS02);
		}
			
		else if(prescaler == 1)  //NO PRESCALLER
		{
			Set_Bit(TCCR0,CS00);
			Clear_Bit(TCCR0,CS01);
			Clear_Bit(TCCR0,CS02);	
		}

		
		else if(prescaler == 8)
		{
          	Clear_Bit(TCCR0,CS00);
          	Set_Bit(TCCR0,CS01);
          	Clear_Bit(TCCR0,CS02);			
		}


		else if(prescaler == 64)
		{
			Set_Bit(TCCR0,CS00);
			Set_Bit(TCCR0,CS01);
			Clear_Bit(TCCR0,CS02);
		}


		else if(prescaler == 256)
		{
			Clear_Bit(TCCR0,CS00);
			Clear_Bit(TCCR0,CS01);
			Set_Bit(TCCR0,CS02);	
		}

		
		else if(prescaler == 1024)
		{
			Set_Bit(TCCR0,CS00);
			Clear_Bit(TCCR0,CS01);
			Set_Bit(TCCR0,CS02);	
		}

		
		else 
		{
			//Handling Error
		}
}




void Timer0_delay( uint16 time_ms){
	
		uint16 counter = 0 ;
		
		
		overflows_number =( time_ms  / 0.256);  
		
		TCNT0 = 0 ;   
		
		Timer0_prescaler (1);
		
		while(counter < overflows_number)
		{
			while((TIFR & (1<<0)) == 0);

			Set_Bit(TIFR,0);
			
			counter++;
		}
		counter =0;
		
		Timer0_prescaler (0);
}
	
	
	 


