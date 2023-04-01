#include"LCS.h"


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
