
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "Utilities.h"

#define F_CPU  16000000
/*
typedef struct{

	uint8_t USART_Baudrate;				//specifies the baud rate which is used in transmitting and receiving
	

	uint8_t USART_Databits;				//specifies the no. of data bits (5,6,7,8 or 9 bits)
	

	uint8_t USART_Paritybit;			//specifies the parity bit whether no parity, even parity or odd parity
	

	uint8_t USART_Stopbits;				//specifies the no. of stop bits (1 or 2 bits)
	
}USART_config;

// Macros to config Baud_rate
#define UART_BR_9600					0
#define UART_BR_14400					1
#define UART_BR_19200					2
#define UART_BR_28800					3
#define UART_BR_38400					4
#define UART_BR_57600					5
#define UART_BR_76800					6
#define UART_BR_115200					7


// Macros to config Data_bits
#define UART_5_DATA_BITS				0
#define UART_6_DATA_BITS				1
#define UART_7_DATA_BITS				2
#define UART_8_DATA_BITS				3
#define UART_9_DATA_BITS				4


// Macros to config Parity_bit
#define UART_NO_PARITY					0
#define UART_ODD_PARITY					1
#define UART_EVEN_PARITY				2


// Macros to config Stop_bits
#define UART_1_STOP_BIT				0
#define UART_2_STOP_BIT				1

*/

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



/* ================================================================ */
/* ============= APIs ============================================= */
/* ================================================================ */

extern USART_Config_t USART;

void USART_Init(void);

void USART_Send( uint16_t data);

 uint16_t USART_Receive (void);



/*
 * Pins & ports Handling
 */
 
 #define TX_Pin     1
 #define RX_Pin		0
 
 #define TX_Port	PORT_D
 #define RX_Port	PORT_D
 /*
 #define USART_Config_t->State					USART_Receiver_Transmitter
 #define USART_Config_t->Communcation_Mode		USART_Asyn_Normal
 #define USART_Config_t->Character_Size			Size_8bit
 #define USART_Config_t->Frame_Control			USART_Parity_Disable_2StopBit
 #define USART_Config_t->Clock_Parity			USART_SamplingOnFaling
 #define USART_Config_t->Baud_Rate				USART_BAUD_RATE_9600
*/
#endif /* UART_INTERFACE_H_ */