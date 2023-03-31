/*
 ============================================================================
 Name        : check.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define STACK_SIZE 10

typedef unsigned char uint8_t;
typedef signed char int8_t;

typedef struct stack {
uint8_t elements[STACK_SIZE];
int8_t top;
}ST_stack_t;

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
int8_t isBalancedParanthethes(uint8_t *expression){

	ST_stack_t stack_check;

	createEmptyStack(&stack_check);

	uint8_t Top = 0 ;

	for(short i=0 ; i<strlen(expression);i++){
		getStackTop(&stack_check, &Top);

		if(expression[i]=='(' || expression[i]=='{')
			push(&stack_check,expression[i]);

		else if(expression[i]==')' || expression[i]=='}'){

			if(stack_check.top == -1)
				return -1;

			pop(&stack_check,&Top);

		    if((expression[i]==')' && Top!='(') || (expression[i]=='}'&& Top!='{'))
				return -1;
			}
		}
	if(stack_check.top != -1)
		return -1;

	else if(Top=='\0')
		return -2;

	return 0;

	}


int main(void) {

	uint8_t test_balance[10];

	while(1){

		printf("enter the expression \n");

		fflush(stdout);

		scanf("%s",&test_balance);

		int8_t output = isBalancedParanthethes(&test_balance);

		if(output==0)
			printf("parentheses are balanced\n\n");

		if(output==-1)
			printf("parentheses are not balanced\n\n");

		if(output== -2)
			printf("neither of parentheses is used\n\n");

			}

}

/*
 1. Test Case 1
- Ask the user for an expression
- Write this expression {(2+3)}
2. Test Case 2
- Ask the user for an expression
- Write this expression {((2+3)}
3. Test Case 3
- Ask the user for an expression
- Write this expression [(2+3)]
4. Test Case 4
- Ask the user for an expression
- Write this expression {(2+3)/((3+3)*(15-10))}
5. Test Case 5
- Ask the user for an expression
- Write this expression (2+3)/((3+3)*(15-10))
6. Test Case 6
- Ask the user for an expression
- Write this expression {{2+3)/((3+3)*(15-10)))
7. Test Case 7
- Ask the user for an expression
- Write this expression {(2+3(/((3+3)*(15-10))}
8. Test Case 8
- Ask the user for an expression
- Write this expression {(2+3)/((3+3(*)15-10))}
9. Test Case 9
- Ask the user for an expression
- Write this expression })2+3)/((3+3)*(15-10))}
10. Test Case 10
- Ask the user for an expression
- Write this expression {(2+3)/(<3+3>*(15-10))}
 */
