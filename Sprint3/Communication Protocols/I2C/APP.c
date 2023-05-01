
#include "APP.h"

void APP_init(void){
	
	I2C_init();
}


void APP_start(void){
	
	uint8_t data;
	
	//Master receive
	if(I2C_start() == EVENT_OK){
		
		if(I2C_adress_select(0x10, READ) == SLA_R_ACK_SENT){
			
			if(I2C_data_event(&data, READ, NACK) == DATA_READ_NACK_SENT){
				
				I2C_stop();
			}
		}
	}
	
	//Master transmit
	if(I2C_start() == EVENT_OK){
		
		if(I2C_adress_select(0x10, WRITE) == SLA_W_ACK_SENT){
			
			if(I2C_data_event(&data, WRITE, NACK) == DATA_WRITE_ACK_SENT){
				
				I2C_stop();
			}
		}
	}
}