
#include "V2_App.h"

void V2_AppInit(){
	
	// initialize 4 LEDs
	LED_init(PORT_A,0);
	LED_init(PORT_A,2);
	LED_init(PORT_A,4);
	LED_init(PORT_A,6);
	
	// initialize Button
	BUTTON_init(PORT_D, 2);
	
	LED_off(PORT_A,0);
	LED_off(PORT_A,2);
	LED_off(PORT_A,4);
	LED_off(PORT_A,6);
	
	sei();
	Interrupt_Enable(INT0,FALLING_EDGE);
	
}

//static uint8_t buttonState;
//static uint8_t count =0 ;
static uint8_t count =0;

void  V2_AppStart(void){
	
	static uint8_t buttonState = 0;
  
  while (1)
  {

	  BUTTON_read(PORT_D, 2, &buttonState);
	 
	  
	  
	  if(count == 1 && buttonState==PRESSED){
		  LED_on(PORT_A,0);
		  LED_off(PORT_A,2);
		  LED_off(PORT_A,4);
		  LED_off(PORT_A,6);
	  }

	  else if(count == 2 && buttonState==PRESSED){
		  LED_on(PORT_A,0);
		  LED_on(PORT_A,2);
		  LED_off(PORT_A,4);
		  LED_off(PORT_A,6);
	  }

	  else if(count == 3 && buttonState==PRESSED){
		  LED_on(PORT_A,0);
		  LED_on(PORT_A,2);
		  LED_on(PORT_A,4);
		  LED_off(PORT_A,6);
	  }


	  else if(count == 4 && buttonState==PRESSED){
		  LED_on(PORT_A,0);
		  LED_on(PORT_A,2);
		  LED_on(PORT_A,4);
		  LED_on(PORT_A,6);
	  }

	  else if(count == 5 && buttonState==PRESSED){
		  LED_off(PORT_A,0);
		  LED_on(PORT_A,2);
		  LED_on(PORT_A,4);
		  LED_on(PORT_A,6);
	  }


	  else if(count == 6 && buttonState==PRESSED){
		  LED_off(PORT_A,0);
		  LED_off(PORT_A,2);
		  LED_on(PORT_A,4);
		  LED_on(PORT_A,6);
	  }


	  else if(count == 7 && buttonState==PRESSED){
		  LED_off(PORT_A,0);
		  LED_off(PORT_A,2);
		  LED_off(PORT_A,4);
		  LED_on(PORT_A,6);
	  }

	  else if(count == 8 && buttonState==PRESSED){
		  LED_off(PORT_A,0);
		  LED_off(PORT_A,2);
		  LED_off(PORT_A,4);
		  LED_off(PORT_A,6);
		  
		  count =0 ;
	  }
	  
  }
  
}

  ISR(INT0_vect)
  {
	  count++;
  }

