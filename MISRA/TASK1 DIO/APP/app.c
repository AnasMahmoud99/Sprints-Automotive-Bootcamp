
#include "app.h"

void appInit(){
	
	// initialize 4 LEDs
	LED_init(PORT_A,0);
	LED_init(PORT_A,2);
	LED_init(PORT_A,4);
	LED_init(PORT_A,6);
	
	// initialize Button
	BUTTON_init(PORT_C, 4);
	
	LED_off(PORT_A,0);
	LED_off(PORT_A,2);
	LED_off(PORT_A,4);
	LED_off(PORT_A,6);
	
		
}

//static uint8_t buttonState;
//static uint8_t count =0 ;	

void appStart(void){
	  static uint8_t count =0;
	  static uint8_t buttonState = 0;
	  BUTTON_read(PORT_C, 4, &buttonState);
	_delay_ms(50);
		if(buttonState == PRESSED){
			count++;
			if(count==9){
				count=1;
			}
			
		}
if(count == 1){
	LED_on(PORT_A,0);
	LED_off(PORT_A,2);
	LED_off(PORT_A,4);
	LED_off(PORT_A,6);
}

else if(count == 2){
	LED_on(PORT_A,0);
	LED_on(PORT_A,2);
	LED_off(PORT_A,4);
	LED_off(PORT_A,6);
}

else if(count == 3){
	LED_on(PORT_A,0);
	LED_on(PORT_A,2);
	LED_on(PORT_A,4);
	LED_off(PORT_A,6);
}


else if(count == 4){
	LED_on(PORT_A,0);
	LED_on(PORT_A,2);
	LED_on(PORT_A,4);
	LED_on(PORT_A,6);
}

else if(count == 5){
	LED_off(PORT_A,0);
	LED_on(PORT_A,2);
	LED_on(PORT_A,4);
	LED_on(PORT_A,6);
}


else if(count == 6){
	LED_off(PORT_A,0);
	LED_off(PORT_A,2);
	LED_on(PORT_A,4);
	LED_on(PORT_A,6);
}


else if(count == 7){
	LED_off(PORT_A,0);
	LED_off(PORT_A,2);
	LED_off(PORT_A,4);
	LED_on(PORT_A,6);
}

else if(count == 8){
	LED_off(PORT_A,0);
	LED_off(PORT_A,2);
	LED_off(PORT_A,4);
	LED_off(PORT_A,6);
}
	
}

