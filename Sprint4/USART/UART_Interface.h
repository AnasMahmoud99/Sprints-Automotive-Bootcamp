
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "Utilities.h"

#define F_CPU  16000000



/*        USART_Registers_bits         */

/*
 * USART Control and Status Register A
 */
#define    MPCM         0	/* Multi-processor Communication Mode */
#define    U2X          1	/* Double the USART Transmission Speed */
#define    PE           2	/* Parity Error */
#define    DOR          3	/* Data OverRun */
#define    FE           4	/* Frame Error */
#define    UDRE         5	/* USART Data Register Empty */
#define    TXC          6	/* USART Transmit Complete */
#define    RXC          7	/* USART Receive Complete */


/*
 * USART Control and Control Register B
 */
#define    TXB8         0	/* Transmit Data Bit 8 */
#define    RXB8         1	/* Receive Data Bit 8 */
#define    UCSZ2        2	/* Character Size */
#define    TXEN         3	/* Transmitter Enable */
#define    RXEN         4	/* Receiver Enable */
#define    UDRIE        5	/* USART Data Register Empty Interrupt Enable */
#define    TXCIE        6	/* TX Complete Interrupt Enable */
#define    RXCIE        7	/* RX Complete Interrupt Enable */


/*
 * USART Control and Control Register C
 */
#define    UCPOL        0	/* Clock Polarity */
#define    UCSZ0        1	/* Character Size */
#define    UCSZ1        2	/* Character Size */
#define    USBS         3	/* Stop Bit Select */
#define    UPM0         4	/* Parity Mode */
#define    UPM1         5	/* Parity Mode */
#define    UMSEL        6	/* Mode Select */
#define    URSEL        7	/* Register Select */

/*
 * Pins & ports Handling
 */
 
 #define TX_Pin     1
 #define RX_Pin		0
 
 #define TX_Port	PORT_D
 #define RX_Port	PORT_D

/* ================================================================ */
/* ============= APIs ============================================= */
/* ================================================================ */

extern USART_Config_t USART;

void USART_Init(void);

void USART_Send( uint16_t data);

 uint16_t USART_Receive (void);

 
#endif /* UART_INTERFACE_H_ */
