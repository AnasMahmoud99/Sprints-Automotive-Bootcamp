#include <stack.h>

void createEmptyStack(ST_stack_t *stack){

	stack->top=-1;

	for(int i=0 ;i<10;i++)
		stack->elements[i]=0;

}



int8_t push(ST_stack_t *stack, uint8_t data){

	if(stack->top == STACK_SIZE-1 )
		return -1;         // stack is full

	stack->elements[++stack->top]=data;

	return 0;
}



int8_t pop(ST_stack_t *stack, uint8_t *data){

	if(stack->top == -1 )
			return -2;     // stack is empty

	*data = stack->elements[stack->top];

	stack->top-- ;

	return 0 ;
}



int8_t printStack(ST_stack_t *stack){

	if(stack->top == STACK_SIZE-1 )
			return -1;         // stack is full

	if(stack->top == -1 )
			return -2;         // stack is empty

	for(int i=stack->top;i<-1;i--)
		printf("  %c  ",stack->elements[i]);
	return 0;
}


int8_t getStackTop(ST_stack_t *stack, uint8_t *topData){

	if(stack->top == -1 )
		return -2;         // stack is empty

	*topData = stack->elements[stack->top];

	return 0;
}



int8_t isFull(ST_stack_t *stack){

	if(stack->top == STACK_SIZE-1 )
		return -1;
	return 0;
}


int8_t isEmpty(ST_stack_t *stack){
	if(stack->top == -1 )
		return -2;
	return 0;
}
