

#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/DIO.h"
#include "../../Service/Types_define.h"

void LED_init(uint8_t LedPort, uint8_t LedPin );

void LED_on(uint8_t LedPort, uint8_t LedPin );

void LED_off(uint8_t LedPort, uint8_t LedPin );

void LED_toggle(uint8_t LedPort, uint8_t LedPin );


#endif /* LED_H_ */