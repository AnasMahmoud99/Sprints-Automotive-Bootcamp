
#include "I2C_Interface.h"

#ifndef EEPROM_H_
#define EEPROM_H_



void EEPROM_Write (char data, char adress);

void EEPROM_Read (char address, char* ptr); 
/* the function arguments are an address in the EEPROM to read 
from and a pointer to a memory place in the MCU to store the read data in*/



#endif /* EEPROM_H_ */