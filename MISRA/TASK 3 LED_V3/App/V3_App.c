	
#include "V3_App.h"


static uint8_t count =0;
static uint8_t blink =0;
	
V3_AppInit(){

	
	// initialize 4 LEDs
	LED_init(PORT_A,0);
	LED_init(PORT_A,2);
	LED_init(PORT_A,4);
	LED_init(PORT_A,6);
	// initialize Button
	BUTTON1_init(PORT_D, 2);
	BUTTON2_init(PORT_D, 3);
	
	LED_off(PORT_A,0);
	LED_off(PORT_A,2);
	LED_off(PORT_A,4);
	LED_off(PORT_A,6);
	
	// enable global interrupt
	 sei();
	 Interrupt_Enable(INT0,RISING_EDGE);
	 Interrupt_Enable(INT1,RISING_EDGE);
	 
	 //enable global Timer
		Timer0_init();
	 	
}

	
V3_AppStart(){
	
count = 0;
blink = 0 ;
	
	while (1)
	{
		
		//Blinking 100 ON , 900OFF
		if(blink == 0)
		{	
			if(count == 0)
			{	
				 LED_off(PORT_A,0);
				 LED_off(PORT_A,2);
				 LED_off(PORT_A,4);
				 LED_off(PORT_A,6);				
			}
			else if(count == 1)
			{
				LED_on(PORT_A,0);
				Timer0_delay(100);
				LED_off(PORT_A,0);
				Timer0_delay(900);
			}
			else if(count == 2)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				Timer0_delay(100);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				Timer0_delay(900);
			}
			else if(count == 3)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				Timer0_delay(100);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				Timer0_delay(900);
			}
			else if(count == 4)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(100);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(900);
			}
			
			else if(count == 5)
			{
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(100);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(900);
			}
			else if(count == 6)
			{
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(100);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(900);
			}
			else if(count == 7)
			{
				LED_on(PORT_A,6);
				Timer0_delay(100);
				LED_off(PORT_A,6);
				Timer0_delay(900);
			}
			else
			{
				//handling error
			}
		}
		
		//Blinking 200 ON , 800 OFF		
		else if(blink == 1)
		{
			if(count == 0)
			{
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
			}
			else if(count == 1)
			{
				LED_on(PORT_A,0);
				Timer0_delay(200);
				LED_off(PORT_A,0);
				Timer0_delay(800);
			}
			else if(count == 2)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				Timer0_delay(200);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				Timer0_delay(800);
			}
			else if(count == 3)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				Timer0_delay(200);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				Timer0_delay(800);
			}
			else if(count == 4)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(200);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(800);
			}
			
			else if(count == 5)
			{
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(200);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(800);
			}
			else if(count == 6)
			{
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(200);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(800);
			}
			else if(count == 7)
			{
				LED_on(PORT_A,6);
				Timer0_delay(200);
				LED_off(PORT_A,6);
				Timer0_delay(800);
			}
			else{
				//handling error
			}
		}		
		
		//Blinking 300 ON , 70000 OFF
		else if(blink == 2)
		{
			if(count == 0)
			{
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
			}
			else if(count == 1)
			{
				LED_on(PORT_A,0);
				Timer0_delay(300);
				LED_off(PORT_A,0);
				Timer0_delay(700);
			}
			else if(count == 2)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				Timer0_delay(300);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				Timer0_delay(700);
			}
			else if(count == 3)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				Timer0_delay(300);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				Timer0_delay(700);
			}
			else if(count == 4)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(300);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(700);
			}
			
			else if(count == 5)
			{
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(300);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(700);
			}
			else if(count == 6)
			{
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(300);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(700);
			}
			else if(count == 7)
			{
				LED_on(PORT_A,6);
				Timer0_delay(300);
				LED_off(PORT_A,6);
				Timer0_delay(700);
			}
			else{
				//handling error
			}
		}
		
		//Blinking 500 ON , 500 OFF
		else if(blink == 3)
		{
			if(count == 0)
			{
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
			}
			else if(count == 1)
			{
				LED_on(PORT_A,0);
				Timer0_delay(500);
				LED_off(PORT_A,0);
				Timer0_delay(500);
			}
			else if(count == 2)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				Timer0_delay(500);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				Timer0_delay(500);
			}
			else if(count == 3)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				Timer0_delay(500);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				Timer0_delay(500);
			}
			else if(count == 4)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(500);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(500);
			}
			
			else if(count == 5)
			{
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(500);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(500);
			}
			else if(count == 6)
			{
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(500);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(500);
			}
			else if(count == 7)
			{
				LED_on(PORT_A,6);
				Timer0_delay(500);
				LED_off(PORT_A,6);
				Timer0_delay(500);
			}
			else{
				//handling error
			}
		}
		
		//Blinking 800 ON , 200 OFF		
		else if(blink == 4)
		{
			if(count == 0)
			{
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
			}
			else if(count == 1)
			{
				LED_on(PORT_A,0);
				Timer0_delay(800);
				LED_off(PORT_A,0);
				Timer0_delay(200);
			}
			else if(count == 2)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				Timer0_delay(800);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				Timer0_delay(200);
			}
			else if(count == 3)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				Timer0_delay(800);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				Timer0_delay(200);
			}
			else if(count == 4)
			{
				LED_on(PORT_A,0);
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(800);
				LED_off(PORT_A,0);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(200);
			}
			
			else if(count == 5)
			{
				LED_on(PORT_A,2);
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(800);
				LED_off(PORT_A,2);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(200);
			}
			else if(count == 6)
			{
				LED_on(PORT_A,4);
				LED_on(PORT_A,6);
				Timer0_delay(800);
				LED_off(PORT_A,4);
				LED_off(PORT_A,6);
				Timer0_delay(200);
			}
			else if(count == 7)
			{
				LED_on(PORT_A,6);
				Timer0_delay(800);
				LED_off(PORT_A,6);
				Timer0_delay(200);
			}
			else{
				//handling error
			}
		}			

		}
}

 
 ISR(EXT_INT0){
	 
	 count++;
	 
	 if(count==8)
		 count=0;
 }
 
 ISR(EXT_INT1){
	 
	 blink++;
	 if(blink==5){
		 blink=0;
	 }
	 
 }