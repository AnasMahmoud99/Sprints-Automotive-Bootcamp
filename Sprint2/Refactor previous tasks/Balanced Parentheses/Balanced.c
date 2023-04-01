
#include<Balanced.h>

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
