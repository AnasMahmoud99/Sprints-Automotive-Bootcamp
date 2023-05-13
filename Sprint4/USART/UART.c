
#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"
#include "Utilities.h"
#include "DIO.h"
USART_Config_t USART = {0};
	
void USART_Init(void)
{	
	DIO_init(TX_Port,TX_Pin,OUT);
	DIO_init(RX_Port,RX_Pin,IN);
	
	float32_t UBRR_Temp = 0.0;
	
	switch(USART.State)
		{
			case USART_Disable:
			CLR_BIT(UCSRB,RXEN);
			CLR_BIT(UCSRB,TXEN);
			break;
			
			case USART_Receiver:
			SET_BIT(UCSRB,RXEN);
			CLR_BIT(UCSRB,TXEN);
			break;
			
			case USART_Transmitter:
			CLR_BIT(UCSRB,RXEN);
			SET_BIT(UCSRB,TXEN);
			break;
			
			case USART_Receiver_Transmitter:
			SET_BIT(UCSRB,RXEN);
			SET_BIT(UCSRB,TXEN);
			break;
			
			default:
			break;
		}
		
	switch(USART.Communcation_Mode)
		{
			case USART_Asyn_Normal:
			CLR_BIT(UCSRC,UMSEL);
			CLR_BIT(UCSRA,U2X);
			CLR_BIT(UCSRC,UCPOL);
			UBRR_Temp = ((float32_t)F_CPU)/(16.0 * USART.Baud_Rate) - 1;
			break;
			
			case USART_Asyn_DoupleSpeed:
			CLR_BIT(UCSRC,UMSEL);
			SET_BIT  (UCSRA,U2X);
			CLR_BIT(UCSRC,UCPOL);
			UBRR_Temp = ((float32_t)F_CPU)/(8.0 * USART.Baud_Rate) - 1;
			break;
			
			case USART_Sync_Master:
			SET_BIT  (UCSRC,UMSEL);
			CLR_BIT(UCSRA,U2X);
			UBRR_Temp = ((float32_t)F_CPU)/(2.0 * USART.Baud_Rate) - 1;
			
			switch(USART.Clock_Parity)
			{
				case USART_SamplingOnFaling:
				CLR_BIT(UCSRC,UCPOL);
				break;
				
				case USART_SamplingOnRising:
				SET_BIT(UCSRC,UCPOL);
				break;
				
				default:
				break;
			}
			
			break;
			
			default:
			break;
		}
		
	switch(USART.Character_Size)
		{
			case Size_5bit:
			CLR_BIT(UCSRB,UCSZ2);
			CLR_BIT(UCSRC,UCSZ1);
			CLR_BIT(UCSRC,UCSZ0);
			break;
			
			case Size_6bit:
			CLR_BIT(UCSRB,UCSZ2);
			CLR_BIT(UCSRC,UCSZ1);
			SET_BIT(UCSRC,UCSZ0);
			break;
			
			case Size_7bit:
			CLR_BIT(UCSRB,UCSZ2);
			SET_BIT(UCSRC,UCSZ1);
			CLR_BIT(UCSRC,UCSZ0);
			break;
			
			case Size_8bit:
			CLR_BIT(UCSRB,UCSZ2);
			SET_BIT(UCSRC,UCSZ1);
			SET_BIT(UCSRC,UCSZ0);
			break;
			
			case Size_9bit:
			SET_BIT(UCSRB,UCSZ2);
			SET_BIT(UCSRC,UCSZ1);
			SET_BIT(UCSRC,UCSZ0);
			break;
			
			default:
			break;
			
		}
		switch(USART.Frame_Control)
		{
			case USART_Parity_Disable_1StopBit:
			CLR_BIT(UCSRC,UPM1);
			CLR_BIT(UCSRC,UPM0);
			CLR_BIT(UCSRC,USBS);
			break;
			
			case USART_Parity_Disable_2StopBit:
			CLR_BIT(UCSRC,UPM1);
			CLR_BIT(UCSRC,UPM0);
			SET_BIT(UCSRC,USBS);
			break;
			
			case USART_Parity_Even_1StopBit:
			SET_BIT(UCSRC,UPM1);
			CLR_BIT(UCSRC,UPM0);
			CLR_BIT(UCSRC,USBS);
			break;
			
			case USART_Parity_Even_2StopBit:
			SET_BIT(UCSRC,UPM1);
			CLR_BIT(UCSRC,UPM0);
			SET_BIT(UCSRC,USBS);
			break;
			
			case USART_Parity_Odd_1StopBit:
			SET_BIT(UCSRC,UPM1);
			SET_BIT(UCSRC,UPM0);
			CLR_BIT(UCSRC,USBS);
			break;
			
			case USART_Parity_Odd_2StopBit:
			SET_BIT(UCSRC,UPM1);
			SET_BIT(UCSRC,UPM0);
			SET_BIT(UCSRC,USBS);
			break;
			
			default:
			break;
		}
		
		UBRRH = ((uint16_t)UBRR_Temp) >> 8; /* Shift right to get the most bits of UBBR */
		UBRRL = ((uint16_t)UBRR_Temp);		
}

void USART_Send(uint16_t data)
{
	while(GET_BIT(UCSRA,UDRE) == 0);
	
	if(USART.Character_Size == Size_9bit)
	{
		/*
		* UCSRB & 1111 1110 to make sure the bit 0 is reset to hold the new value because it does not mention in data sheet
		* we need to take the bit 9  in the data and hold it in the bit 0  in the UCSRB so we & the data with 8 to get
		*  and shift it again to put in the position of the bit 0
		*/
		UCSRB = (UCSRB & 0xFE) | ((data & (1<<8))>>8);
	}
	
	UDR = (uint8_t) data;
	
}


uint16_t USART_Receive (void)
{
	uint16_t Recived_Data = 0;
	
	if(GET_BIT(UCSRA,RXC) != 0);
	
	if(GET_BIT(UCSRA,FE) | GET_BIT(UCSRA,DOR) | GET_BIT(UCSRA,PE))
	{
		if(GET_BIT(UCSRA,FE))
		{
			USART.Error_Type = USART_FrameError;
		}
		else if (GET_BIT(UCSRA,DOR))
		{
			USART.Error_Type = USART_DataOverRunError;
		}
		else if (GET_BIT(UCSRA,PE))
		{
			USART.Error_Type = USART_ParityError;
		}
	}
	
	if(USART.Character_Size == Size_9bit)
	{
		/* read the 9bit from the bit 1 in the UCSRB then shift it to left by 7 to hold in 9bit */
		Recived_Data = UCSRB & (1 << RXB8) >> 7;
	}
	
	Recived_Data = UDR;
	
	return Recived_Data;
}