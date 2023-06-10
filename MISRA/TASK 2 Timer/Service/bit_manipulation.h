

#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_
#define Set_Bit(portNumber,pinNumber)		((portNumber) |= (1<<pinNumber))
#define Clear_Bit(portNumber,pinNumber) 	((portNumber) &= ~(1<<pinNumber))
#define Read_Bit(portNumber,pinNumber)		(((portNumber) &= (1<<pinNumber))>>pinNumber)
#define Toggle_Bit(portNumber,pinNumber)	((portNumber) ^= (1<<pinNumber))





#endif /* BIT_MANIPULATION_H_ */