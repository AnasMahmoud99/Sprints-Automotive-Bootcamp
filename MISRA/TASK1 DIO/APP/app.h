

#ifndef APP_H_
#define APP_H_
#define F_CPU	4000000UL

#include "../ECUAL/BUTTON Driver/button.h"
#include "../ECUAL/LED Driver/led.h"
#include <util/delay.h>


void appInit();

void appStart(void);


#endif /* APP_H_ */