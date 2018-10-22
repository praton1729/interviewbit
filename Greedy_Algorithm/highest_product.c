
/*=========================================

* File Name : highest_product.c

* Purpose 	: A func() that returns the highest
			  product of any triplet choosen from
			  the array.

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
 * 
 * @Output Integer
 */

int max(int x, int y){
		return (x>y)?(x):(y);
}
int compare(const void* a, const void* b){
		return ( *(int*)a - *(int*)b );
}
int maxp3(int* A, int n1) {
		qsort(A, n1, sizeof(int), compare);
		return max(A[0]*A[1]*A[n1-1],A[n1-1]*A[n1-2]*A[n1-3]);
}

int main(int argc, char* argv)
{

	return 0;
}
