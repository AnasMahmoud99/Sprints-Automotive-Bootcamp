


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

// Registers definitions
#define UCSRB	(*(volatile uint8_t*)(0x2A))
#define UCSRA	(*(volatile uint8_t*)(0x2B))
#define UBRRL	(*(volatile uint8_t*)(0x29))
#define UDR		(*(volatile uint8_t*)(0x2C))
#define UCSRC   (*(volatile uint8_t*)(0x40))
#define UBRRH   (*(volatile uint8_t*)(0x40))


#endif /* UART_PRIVATE_H_ */