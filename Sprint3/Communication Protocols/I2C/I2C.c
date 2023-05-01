
#include "I2C_Interface.h"

 void I2C_init(void){
	
	TWSR = 0x00;  //prescaler=1
	
	TWBR = BITRATE(TWSR);  //set bit rate
	
}


uint8_t I2C_start(void){
	
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); 
	
	while(!(TWCR & (1<<TWINT)));
	
	if((TWSR & 0XF8) != START_STATE)   // IN OU CASE START_STATE= 0x08
	{
		
		return START_NOT_SENT;
	}
	else
	{
		return EVENT_OK	;
	}
}


uint8_t I2C_repeted_start(void){
	
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	
	while(!(TWCR & (1<<TWINT)));   // Wait until TWI finish its current job
	
	if((TWSR & 0XF8) != REPETED_START_STATE)   
	{
		
		return REPETED_START_NOT_SENT;
	}
	else
	{
		return EVENT_OK	;
	}
}

uint8_t I2C_adress_select(uint8_t adress, uint8_t rw){
	
	uint8_t status;
	
	if(rw == WRITE)
	{
		TWDR = adress + 0;      //write SLA+w in TWI data register
	}
	else if(rw == READ)
	{
		TWDR = adress + 1;      //write SLA+R in TWI data register
	}
	
	TWCR = (1<<TWINT)|(1<<TWEN);   // Enable TWI & clear interrupt flag
	
	while(!(TWCR & (1<<TWINT)));   // Wait until TWI finish its current job
	
	status = TWSR & 0XF8 ;         // Read TWI status register
	
	if(status == SLA_W_ACK_STATE)     //check for SLA+W transmitted & ACk received
	{
		return SLA_W_ACK_SENT;
	}
	else if(status == SLA_W_NACK_STATE)
	{
		return SLA_W_NACK_SENT;
	}
	if(status == SLA_R_ACK_STATE)    //check for SLA+R transmitted & ACk received
	{
		return SLA_R_ACK_SENT;
	}
	else if (status == SLA_R_NACK_STATE)
	{
		return SLA_R_NACK_SENT;
	}
	else
	{
		return SLA_RW_FAILED;
	}
	
}

uint8_t I2C_data_event(uint8_t *data, uint8_t rw, uint8_t ack){
	
	uint8_t status;
	
	if(rw == WRITE)
	{
		TWDR = *data;
		TWCR = (1<<TWINT)|(1<<TWEN);   // Enable TWI & clear interrupt flag
		while(!(TWCR & (1<<TWINT)));   // Wait until TWI finish its current job
		status = TWSR & 0XF8 ;         // Read TWI status register
		if(status == DATA_WRITE_ACK_STATE)    //check for data transmitted & ACk received
		{
			return DATA_WRITE_ACK_SENT;
		}
		else if (status == DATA_WRITE_NACK_STATE)
		{
			return DATA_WRITE_NACK_SENT;
		}
		else
		{
			return DATA_WRITE_FAILED;
		}
	}
	
	else if(rw == READ)
	{
		if(ack == ACK)
		{
			TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);    // Enable TWI with generation of ack
		}
		else if(ack=NACK)
		{
			TWCR = (1<<TWINT)|(1<<TWEN);
		}

		while(!(TWCR & (1<<TWINT)));   // Wait until TWI finish its current job
		TWDR = *data;                  // read data
		status = TWSR & 0XF8 ;         // Read TWI status register
		if(status == DATA_READ_ACK_STATE)    //check for data transmitted & ACk received
		{
			return DATA_READ_ACK_SENT;
		}
		else if (status == DATA_READ_NACK_STATE)
		{
			return DATA_READ_NACK_SENT;
		}
		else
		{
			return DATA_READ_FAILED;
		}
	}
	
}

void I2C_stop(void){
	
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);     // Enable TWI with generation of stop
	while(TWCR & (1<<TWSTO)); 
}



