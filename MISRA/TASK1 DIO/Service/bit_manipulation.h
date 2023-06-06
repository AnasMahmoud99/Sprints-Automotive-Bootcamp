

#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_
#define Set_Bit(pinNumber,portNumber)		((portNumber) |= (1<<pinNumber))
#define Clear_Bit(pinNumber,portNumber)		((portNumber) &= ~(1<<pinNumber))
#define Read_Bit(pinNumber,portNumber)		(((portNumber) & (1<<pinNumber))>>pinNumber)
#define Toggle_Bit(pinNumber,portNumber)	((portNumber)^=(1<<pinNumber))

#define Set_mask(mask,portNumber)			((portNumber) |= mask)
#define Clear_mask(mask,portNumber)			((portNumber) &= ~(mask))
#define Toggle_mask(mask,portNumber)	    ((portNumber)^= (mask))




#endif /* BIT_MANIPULATION_H_ */