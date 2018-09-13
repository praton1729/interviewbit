
/*=========================================

* File Name : remove_duplicate_sorted_array.c

* Purpose :

* Creation Date : 13-09-2018

* Last Modified : Thursday 13 September 2018 06:58:43 PM IST

* Created By : Prathu Baronia 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

int removeDuplicates(int* A, int n1) {
      
    if(n1==1) return 1;
    
    int i,j = 0;
    
    for(i=0;i<n1-1;i++){
        
        if(A[i]!=A[i+1]){
            A[j++] = A[i];            
        }
    }

    A[j++] = A[n1-1];
    
    return j;
}

int main(int argc, char* argv)
{
	int A[] = {1,2,2,3};

	printf("new length of A is %d\n",removeDuplicates(A,4));

	return 0;
}
