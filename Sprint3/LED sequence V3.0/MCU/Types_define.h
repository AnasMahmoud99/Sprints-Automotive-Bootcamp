


#ifndef TYPES_DEFINE_H_
#define TYPES_DEFINE_H_

typedef unsigned char uint8_t ;

typedef unsigned short  uint16 ;

typedef unsigned int  uint32 ;

typedef float		  float32_t; 


typedef enum err_state
{
	SUCCESS,FAIL
}err_state;
typedef enum pin_dir
{
	INPUT,OUTPUT
}pin_dir;

typedef enum pin_state
{
	LOW,HIGH
}pin_state;

#endif /* TYPES_DEFINE_H_ */