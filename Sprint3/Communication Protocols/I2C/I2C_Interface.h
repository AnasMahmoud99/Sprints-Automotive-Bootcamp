

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "I2C_Private.h"
#include "standard_types.h"
#include<math.h>

#define F_CPU			1000000U
#define SCL_CLK			400000U
#define BITRATE(TWSR)    ((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

#define WRITE	0
#define READ    1

#define ACK		0
#define NACK	1

/* States */
#define START_STATE				0x08
#define	REPETED_START_STATE		0x10
#define SLA_W_ACK_STATE			0x18
#define SLA_W_NACK_STATE		0x20
#define SLA_R_ACK_STATE			0x40
#define SLA_R_NACK_STATE		0x48
#define DATA_WRITE_ACK_STATE	0x28
#define DATA_WRITE_NACK_STATE	0x30
#define DATA_READ_ACK_STATE		0x50
#define DATA_READ_NACK_STATE	0x58


/* Returns */
#define EVENT_OK					0
#define START_NOT_SENT				1
#define REPETED_START_NOT_SENT		2
#define SLA_W_ACK_SENT				3
#define SLA_W_NACK_SENT				4
#define SLA_R_ACK_SENT				5
#define SLA_R_NACK_SENT				6
#define SLA_RW_FAILED               7
#define DATA_WRITE_ACK_SENT			8
#define DATA_WRITE_NACK_SENT		9
#define DATA_WRITE_FAILED			10
#define DATA_READ_ACK_SENT			11
#define DATA_READ_NACK_SENT 		12
#define DATA_READ_FAILED			13

//TWI Control Register(TWCR)  pin definitions
#define TWIE	0
#define TWEN	2
#define TWWC	3
#define TWSTO	4
#define TWSTA	5
#define TWEA	6
#define TWINT	7

//TWI Status Register(TWSR)  pin definitions
#define TWPS0	0
#define TWPS1	1

void I2C_init(void);

uint8_t I2C_start(void);

uint8_t I2C_repeted_start(void);

uint8_t I2C_adress_select(uint8_t adress, uint8_t rw);

uint8_t I2C_data_event(uint8_t *data, uint8_t rw, uint8_t ack);

void I2C_stop(void);

#endif /* I2C_INTERFACE_H_ */