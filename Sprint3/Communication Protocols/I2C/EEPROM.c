
#include "EEPROM.h"


void EEPROM_Write (char data, char adress){
	
	I2C_start();
	I2C_adress_select(0xA8, WRITE);
	I2C_adress_select(adress, WRITE);  //slave address is 1010.100 and a 0 in the 8th bit to indicate Writing.
	I2C_adress_select(data, WRITE);
	I2C_stop();

}

void EEPROM_Read (char adress, char* ptr){
	
	I2C_start();
	I2C_adress_select(0xA8, WRITE);
	I2C_adress_select(adress, WRITE);  
	I2C_start();
	I2C_adress_select(0xA9, WRITE);        //A9 to make least significant bit = 1
	I2C_data_event(ptr, READ, NACK);
	I2C_stop();
	
}
