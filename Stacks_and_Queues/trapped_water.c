
/*=========================================

* File Name : trapped_water.c

* Purpose 	: Find the amount of trapped water
			  in a array presented trap structure

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
 * 
 * @Output Integer
 */
 
int max(int a, int b) { return (a>b)?(a):(b);}

int min(int a, int b) { return (a>b)?(b):(a);}

int trap(const int* A, int n1) {

		int* left = (int*)malloc(n1*sizeof(int));
		int* right = (int*)malloc(n1*sizeof(int));

		int water=0,i;

		left[0] = A[0];
		for(i=0;i<n1;i++) left[i] = max(left[i - 1],A[i]);

		right[n1-1] = A[n1 - 1];
		for(i=n1-2;i>=0;i--) right[i] = max(right[i + 1],A[i]);

		for(i=0;i<n1;i++) water += min(left[i],right[i]) - A[i];

		return water;
}

int main(int argc, char* argv)
{

	return 0;
}
