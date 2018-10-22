
/*=========================================

* File Name : candy_distribution.c

* Purpose 	: A func() that returns min number
			  of candies to be distibuted such that 
			  high rated person gets more candies than
			  their neighbours.

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

int candy(int* A, int n1) {

		int* left_candy = (int*) malloc(n1*sizeof(int));
		int* right_candy = (int*) malloc(n1*sizeof(int));
		int i, total=0;

		for(i=0;i<n1;i++){
				left_candy[i] = 1;
				right_candy[i] = 1;
		}

		for(i=0;i<n1-1;i++){
				if(A[i+1] > A[i]){
						left_candy[i+1] = left_candy[i] + 1;
				}
		}

		for(i=n1-1;i >0;i--){
				if(A[i-1] > A[i]){
						right_candy[i-1] = right_candy[i] + 1;
				}
		}

		for(i=0;i<n1;i++){
				total += max(left_candy[i], right_candy[i]);
		}
		return total;
}


int main(int argc, char* argv)
{

		return 0;
}
