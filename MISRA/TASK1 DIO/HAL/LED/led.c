
#include "led.h"

void LED_init(uint8_t LedPort, uint8_t LedPin ){
	
	DIO_init(LedPort,LedPin,OUT);
	
}

void LED_on(uint8_t LedPort, uint8_t LedPin ){
	
	DIO_write(LedPort,LedPin,HIGH);
}

void LED_off(uint8_t LedPort, uint8_t LedPin ){
	
	DIO_write(LedPort,LedPin,LOW);
	
}

void LED_toggle(uint8_t LedPort, uint8_t LedPin ){
	
	DIO_toggle(LedPort, LedPin);

}

