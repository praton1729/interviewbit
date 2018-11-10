
/*=========================================

* File Name		:	LIS.c

* Purpose		:	A func() that returns length
					of LIS of an integer array.

* Creation Date	:	10-11-2018

* Last Modified	:	Mon 22 Dec 2008 10:36:49 PM PST

* Created By	: 	Prathu Baronia, 14D070046 

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

int max(int a, int b)
{
		return ((a)>(b))?(a):(b);
}

int array_max(int* A, int n1)
{
		int max_element = A[0];
		int i;
		for(i=1;i<n1;i++) max_element = max(max_element,A[i]);
		return max_element;
}

int array_LIS(const int* A, int n1)
{
		int* Length_of_LIS_ending_at_index = (int*) malloc(n1*sizeof(int));
		int i,j;

		Length_of_LIS_ending_at_index[0] = 1;

		for(i=1;i<n1;i++)
		{
				Length_of_LIS_ending_at_index[i] = 1;
				for(j=0;j<i;j++)
				{
						if(A[i]>A[j] && Length_of_LIS_ending_at_index[i] < Length_of_LIS_ending_at_index[j]+1)
								Length_of_LIS_ending_at_index[i] = Length_of_LIS_ending_at_index[j]+1;
				}
		}

		return array_max(Length_of_LIS_ending_at_index,n1);
}

int main(int argc, char* argv)
{
		return 0;
}
