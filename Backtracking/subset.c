
/*=========================================

* File Name : subset.c

* Purpose 	: Generate all subsets out of a
			  given array and return a 2D array.

* Creation Date : 01-10-2018

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
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, len2 as columns 
 */
 
int compare(const void* a, const void* b){
		return (*(int*)a - *(int*)b);
}

int** subsets(int* A, int n1, int *len1, int *len2) {

		qsort(A, n1,sizeof(int),compare);

		int rows = pow(2,n1),i,j,k;

		*len1 = rows;
		*len2 = n1;

		int** result = (int**) malloc(rows*sizeof(int*));

		for(i=0;i<n1;i++){

				result[i] = (int*) malloc(i*sizeof(int));
				k=0;
				for(j=0,k=0;j<n1,k < i;j++){
						if(i & (1<<j)) result[i][k] = A[j],k++;
				}
		}

		return result;
}

int main(int argc, char* argv)
{

	return 0;
}
