
#include "main.h"
#include <stdio.h>


int main(void) {

	int32_t test_arr[50];
	uint8_t arr_size;
	uint8_t LCS_size = 1;
	int8_t Return_LCS;

	// arrange array by sorting

	printf("Enter array size: ");
	fflush(stdout);
	scanf("%d",&arr_size);
	for(int32_t i=0;i<arr_size;i++){
		fflush(stdout);
		scanf("%d",&test_arr[i]);
		}

    insertionSort(test_arr,arr_size);

  // finding LCS

	Return_LCS = lcsGetSize(test_arr, arr_size,&LCS_size);

	if(Return_LCS == -1)
		printf("Empty Array");

	if(Return_LCS == -2)
		printf("size of array out of range");

	if(Return_LCS == -3)
		printf("No sequence");

	if(!Return_LCS){

		printf("\nSorted array is: \n");

		printArray(test_arr,arr_size);

		printf("\n\n Longest Consecutive Subsequence is: %d",LCS_size);
	}

}
