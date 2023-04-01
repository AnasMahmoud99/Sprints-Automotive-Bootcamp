/*
 ============================================================================
 Name        : LCS.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed int int32_t;

int8_t insertionSort(int32_t *array, uint8_t arraySize){

	int32_t temp ,i,j;

	if(arraySize==0 || arraySize>10)
		return -2;
	if(array == NULL)
		return -1;

	for(i=1 ;i<arraySize;i++){

		temp = array[i];

		for(j=i-1 ;j>=0 && array[j]>temp ;j--)
			array[j+1] = array[j];

		array[j+1]=temp;

		}
		return 0;
	}



 void printArray(int32_t *array, uint8_t arraySize){
	 for(int32_t i=0 ;i<arraySize;i++)
		 printf("  %d  ",array[i]);
 }

 int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS){

 	 if(array == NULL)
 		 return -1;

 	 if(arraySize == 0 || arraySize>10)
 		 return -2;

 	 uint8_t LCS_count =1;
 	 *sizeofLCS = 0 ;
 	 for(int32_t i=0 ;i<arraySize-1;i++){
 	     if (((array[i + 1]) - (array[i])) == 1)
 	    	 LCS_count++;
 	    else
 	    	LCS_count=1;

 		 if(LCS_count>*sizeofLCS)
 		 	  *sizeofLCS= LCS_count;

 	 }

 	 if(LCS_count == 1)
 		 return -3; // No sequence

 	 return 0;

  }




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


/*
 * 1. Test Case 1
- Ask the user to enter array elements
- Enter the following elements
- [9, 0, 7, 5, 3, 8, -10, 4, 2, 1]
- Print the LCS size
2. Test Case 2
- Ask the user to enter array elements
- Press Enter without entering any element
3. Test Case 3
- Ask the user to enter array elements
- Enter the following elements
- [9, 0, 7, 5, 3, 8, -10, 4, 2, 1, 6, 12]
4. Test Case 4
- Ask the user to enter array elements
- Enter the following elements
- [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
- Print the LCS size
5. Test Case 5
- Ask the user to enter array elements
- Enter the following elements
- [2, 8, 4, 10, 6, 20, 16, 12, 14, 16]
*
 */









