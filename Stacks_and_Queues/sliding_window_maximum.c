
/*=========================================

* File Name : sliding_window_maximum.c

* Purpose 	: A func() outputting an array 
			  of maximums of subarrays of size K.

* Creation Date : 16-10-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
 
int max(int a, int b){
    return (a>b)?(a):(b);
}

int* slidingMaximum(const int* A, int n1, int B, int *len1) {
    
    int i=0;
    *len1 = n1 - B + 1;
    int K = n1 - B + 1;
    
    int* result = (int*)malloc(K*sizeof(int));
    int* LR = (int*)malloc(n1*sizeof(int));
    int* RL = (int*)malloc(n1*sizeof(int));
    
    for(i=0;i<n1;i++){
        if(i%B==0) LR[i] = A[i];
        else LR[i] = max(LR[i-1],A[i]);
    }
    
    for(i=n1-1;i>=0;i--){
        if(i==n1-1) RL[i] = A[i];
        else if(i%B == B - 1) RL[i] = A[i];
        else RL[i] = max(RL[i+1],A[i]);
    }
    
    for(i=0;i<K;i++){
        result[i] = max(RL[i], LR[i+B-1]);
    }
    
    return result;
}

int main(int argc, char* argv)
{

	return 0;
}
