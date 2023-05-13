

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


/* ========================================================= */
/* =============== Configuration References ================ */
/* ========================================================= */
typedef enum
{
	USART_Asyn_Normal,
	USART_Asyn_DoupleSpeed,
	USART_Sync_Master,
}USART_Mode;

typedef enum
{
	USART_Disable,
	USART_Receiver,
	USART_Transmitter,
	USART_Receiver_Transmitter,
}USART_State;


typedef enum
{
	Size_5bit,
	Size_6bit,
	Size_7bit,
	Size_8bit,
	Size_9bit,
}USART_Character_Size;


typedef enum
{
	USART_NoError,
	USART_ParityError,
	USART_DataOverRunError,
	USART_FrameError,
}USART_ErrorsType;

typedef enum
{
	USART_SamplingOnFaling,
	USART_SamplingOnRising,
}USART_Clock_Parity;

typedef enum
{
	USART_Parity_Disable_1StopBit,
	USART_Parity_Disable_2StopBit,
	USART_Parity_Even_1StopBit,
	USART_Parity_Even_2StopBit,
	USART_Parity_Odd_1StopBit,
	USART_Parity_Odd_2StopBit,
}USART_Frame_Control;


typedef enum
{
	USART_BAUD_RATE_2400 = 2400,
	USART_BAUD_RATE_4800 = 4800,
	USART_BAUD_RATE_9600 = 9600 ,
	USART_BAUD_RATE_14400 = 14400,
	USART_BAUD_RATE_19200 = 19200,
	USART_BAUD_RATE_28800 = 28800,
}USART_Baud_Rate;

/* ================================================================ */
/* =============== User type definitions (structures) ============= */
/* ================================================================ */

typedef struct
{
	USART_State		      State;
	USART_Mode                    Communcation_Mode;
	USART_Character_Size          Character_Size;
	USART_Frame_Control           Frame_Control;
	USART_Clock_Parity            Clock_Parity;
	USART_Baud_Rate		      Baud_Rate;
	USART_ErrorsType              Error_Type;
}USART_Config_t;



#endif /* UART_CONFIG_H_ */
