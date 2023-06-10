

#include "button.h"

void BUTTON1_init(uint8_t buttonPort, uint8_t buttonPin )
{
	DIO_init(buttonPort,buttonPin,IN);
}

void BUTTON1_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value )
{
	DIO_read(buttonPort,buttonPin,value);
}


void BUTTON2_init(uint8_t buttonPort, uint8_t buttonPin )
{
	DIO_init(buttonPort,buttonPin,IN);
}

void BUTTON2_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value )
{
	DIO_read(buttonPort,buttonPin,value);
}