
/*=========================================

* File Name : mice_and_holes.c

* Purpose 	: Assigining N mice to N holes
			  to minimize time for the last mouse
			  arrival.

* Creation Date : 23-10-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer
 */

int max(int x, int y){
    return (x>y)?(x):(y);
}

int compare(const void* a, const void* b){
    return ( *(int*)a - *(int*)b );
}
int mice(int* A, int n1, int* B, int n2) {
    qsort(A, n1, sizeof(int), compare);
    qsort(B, n2, sizeof(int), compare);
    int max_diff,i;
    
    max_diff = abs(A[0]-B[0]);
    
    for(i=1;i<n1;i++){
        max_diff = max(max_diff,abs(A[i]-B[i]));
    }
    return max_diff;
}

int main(int argc, char* argv)
{

	return 0;
}
