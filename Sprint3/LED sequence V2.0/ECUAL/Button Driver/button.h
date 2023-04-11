
#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/DIO.h"

// Button states
#define PRESSED		1
#define NOT_PRESSED		0


void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin );

void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value );



#endif /* BUTTON_H_ */