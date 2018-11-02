
/*=========================================

 * File Name : combinations.c

 * Purpose 	: A func() that returns nCr sets
 from an array of unique integers.

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
 * @input A : Integer
 * @input B : Integer
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, len2 as columns 
 */

int row = 0;

int combination(int A, int B){
		if(B==0 || B==A) return 1;
		return (combination(A-1,B-1) + combination(A-1,B));
}

void combination_util(int* sample, int start, int end, int index,int* temp, int** result,int r){
		if(index==r)
		{
				int j;
				for(j=0;j<r;j++) result[row][j] = temp[j];
				return;
		}            
		int i=start;
		while(i<=end && end-i+1 >= r - index){
				temp[index] = sample[i];
				combination_util(sample,i+1,end,index+1,temp,result,r);
				i = i + 1;
		}
}

int** combine(int A, int B, int *len1, int *len2) {
		int rows = combination(A,B);
		int i;
		*len1 = rows;
		*len2 = B;

		//declaration
		int** result = (int**) malloc(rows*sizeof(int*));
		for(i=0;i<rows;i++) result[i] = (int*) malloc(B*sizeof(int));

		//declaration
		int* sample = (int*) malloc(A*sizeof(int));
		int* temp = (int*) malloc(B*sizeof(int));

		//Initialization
		for(i=0;i<A;i++) sample[i] = i;
		for(i=0;i<B;i++) temp[i] = 0;

		combination_util(sample,0,A-1,0,temp,result,B);
		return result;
}

int main(int argc, char* argv)
{

		return 0;
}
