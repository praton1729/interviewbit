
/*=========================================

 * File Name 	: gray_code.c

 * Purpose 		: Generate n-bit Gray Codes

 * Creation Date : 01-11-2018

 * Last Modified : Friday 02 November 2018 12:00:32 AM IST

 * Created By 	: Prathu Baronia, 14D070046 

 ==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

int count = 0;

void gray_code_util(int* result, int n, int* num)
{
		if(n==0)
		{
				result[count] = *num;
				count++;
				return;
		}

		gray_code_util(result,n-1,num);
		*num = (*num) ^ (1<<(n-1));
		gray_code_util(result,n-1,num);
}

int power(int a, int b)
{
		return (int) pow((double)a,(double)b);
}

int* grayCode(int A)
{
		int n = A;
		int len = power(2,A);
		//*len1 = len;
		int* result = (int*) malloc(len*sizeof(int));
		int* num = (int*) malloc(sizeof(int));
		*num = 0;
		gray_code_util(result,n,num);
		return result;
}

void print_array(int* A, int n)
{
		int i;
		for(i=0;i<n;i++) printf("%d ",A[i]);
		printf("\n");
}

int main(int argc, char** argv)
{
		int A = atoi(argv[1]);
		int len = power(2,A);
		//int* len1 = (int*) malloc(sizeof(int));

		int* result = (int*) malloc(len*sizeof(int));

		result = grayCode(A);

		print_array(result,len);

		return 0;
}
