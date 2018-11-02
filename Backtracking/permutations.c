
/*=========================================

* File Name 	: permutations.c

* Purpose 		: A func() that returns all 
				  permutations of an array.

* Creation Date : 28-10-2018

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
 
int fact(int n){
		if(n==0) return 1;
		else return n*fact(n-1);
}
void swap(int* A,int i, int j){
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
}

int count = 0;

void print_array(int* A,int n1)
{
		int i;
		printf("%d\t",count);
		count++;
		for(i=0;i<n1;i++) printf("%d\t",A[i]);
		printf("\n");
}

void permute_helper(int* A, int n1,int start, int end,int** result)
{
		if(start==end)
		{
				// print_array(A,end+1);
				int j;
				for(j=0;j<n1;j++) result[count][j] = A[j];
				count++;
				return;
		}

		int i;
		for(i=start;i<=end;i++)
		{
				swap(A,i,start);
				permute_helper(A,n1,start+1,end,result);
				swap(A,i,start);
		}
}

int** permute(int* A, int n1, int *len1, int *len2) {

		*len2 = n1;
		int rows = fact(n1),i;
		*len1 = rows;

		int** result = (int**) malloc(rows*sizeof(int*));

		for(i=0;i<rows;i++) result[i] = (int*) malloc(n1*sizeof(int));

		permute_helper(A,n1,0,n1-1,result);
		return result;

}

int main(int argc, char* argv)
{
		int A[] = {1,2,3};

		int* len1;
		int* len2;

		permute(A,3,len1,len2);

		return 0;
}
