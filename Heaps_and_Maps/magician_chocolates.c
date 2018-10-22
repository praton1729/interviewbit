
/*=========================================

* File Name : magician_chocolates.c

* Purpose 	: Random problem of max_heap formation

* Creation Date : 22-10-2018

* Last Modified : Monday 22 October 2018 03:48:42 AM IST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : Integer
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer
 */

int compare(const void* a, const void* b){
		return ( *(int*)a - *(int*)b);
}

int nchoc(int A, int* B, int n2) {

		long long int result=0;
		int i;

		for(i=0;i<A;i++){

				//sort the array
				qsort(B,n2,sizeof(int),compare);
				// add the maximum to the result
				result += (long long int) B[n2-1];
				// edit the max element to its half
				B[n2-1] = B[n2-1]/2;
		}
		int MOD = (int) (pow(10,9) + 7);
		return (result%MOD);
}

int main(int argc, char* argv)
{

	return 0;
}
