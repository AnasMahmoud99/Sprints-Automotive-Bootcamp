#include"sort.h"

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
