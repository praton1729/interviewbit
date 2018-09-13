
/*=========================================

* File Name : merge_sorted_lists.c

* Purpose : Merge two sorted arrays

* Creation Date : 13-09-2018

* Last Modified : Thursday 13 September 2018 06:52:20 PM IST

* Created By : Prathu Baronia 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Return Returns a array of size n1 + n2 with A and B merged. 
 */
 
int comparator(const void *p, const void *q)  
{ 
    return ( *(int*)p - *(int*)q);
} 


int* merge(int* A, int n1, int* B, int n2) {
    
    int* result = (int*) malloc(sizeof(int)*(n1+n2));
    int j;
    for(j=0;j<n1+n2;j++){
        
        if(j<n1){
            result[j] = A[j];
        }
        else{
            result[j] = B[j-n1];
        }
    }
    
    qsort((void*)result,n1+n2,sizeof(int),comparator);

    return result;
}

int main(int argc, char* argv)
{

	int A[] = {10,2,30};

	int B[] = {1,20,3};

//	qsort(A,3,sizeof(int),comparator);
//	qsort(B,3,sizeof(int),comparator);
//
//	printf("A is [%d,%d,%d]\n",A[0],A[1],A[2]);
//	printf("B is [%d,%d,%d]\n",B[0],B[1],B[2]);

    int* result = (int*) malloc(sizeof(int)*(6));

	result = merge(A,3,B,3);

	printf("result is [%d,%d,%d,%d,%d,%d]\n",result[0],result[1],result[2],result[3],result[4],result[5]);
	return 0;
}
