
/*=========================================

* File Name : nearest_smaller_integer.c

* Purpose 	: A function which yields an array
			  which contains the closest neighbour 
			  of each element in the provided Array. 

* Creation Date : 15-10-2018

* Last Modified : Monday 15 October 2018 07:09:35 PM IST

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
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

int* prevSmaller(int* A, int n1, int *len1) {
		*len1 = 0;
		int* result = (int*) malloc(n1*sizeof(int));

		int* stack = (int*) malloc(n1*sizeof(int));
		int top = -1, i;

		for(i=0;i<n1;i++){
				while(top >=0 && stack[top] >= A[i]){
						top--;
				}
				if(top==-1) result[i] = -1;
				else result[i] = stack[top];
				(*len1)++;
				stack[++top] = A[i];
		}

		return result;
}

int main(int argc, char* argv)
{

	return 0;
}
