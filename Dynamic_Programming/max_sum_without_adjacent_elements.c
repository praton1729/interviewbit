
/*=========================================

* File Name		:	max_sum_without_adjacent_elements.c

* Purpose		:	A func() that returns the max sum that can be
					obtained from a 2*N grid without including adjacent
					or same column values.

* Creation Date	:	14-11-2018

* Last Modified	:	Wednesday 14 November 2018 01:16:34 AM IST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer
 */
 
int max(int a, int b)
{
		return ((a)>(b))?(a):(b);
}

int adjacent(int** A, int n11, int n12) {
		int included = max(A[0][0],A[1][0]);
		int excluded = 0, excluded_new;
		int i;
		for(i=1;i<n12;i++)
		{
				excluded_new = max(included,excluded);
				included = excluded + max(A[0][i],A[1][i]);
				excluded = excluded_new;
		}
		return max(excluded,included);
}


int main(int argc, char* argv)
{

		return 0;
}
