#include<main.h>

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
