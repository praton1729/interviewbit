
/*=========================================

* File Name : Array_3_pointers.c

* Purpose :

* Creation Date : 27-09-2018

* Last Modified : Thursday 27 September 2018 03:34:38 AM IST

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
 * @input B : Read only ( DON'T MODIFY ) Integer array
 * @input n2 : Integer array's ( B ) length
 * @input C : Read only ( DON'T MODIFY ) Integer array
 * @input n3 : Integer array's ( C ) length
 * 
 * @Output Integer
 */
 
#define max(a,b) (a>b)?(a):(b)
#define min(a,b) (b>a)?(a):(b)

int minimize(const int* A, int n1, const int* B, int n2, const int* C, int n3) {

		int diff = INT_MAX;

		int res_i=0, res_j=0, res_k=0;
		int i=0,j=0,k=0;

		while(i< n1 && j<n2 && k<n3){

				int temp_max = max(B[j],C[k]);
				int maximum = max(A[i],temp_max);
				int temp_min = min(B[j],C[k]);
				int minimum = min(A[i],temp_min); 

				if(maximum-minimum < diff){
						res_i = i, res_j = j, res_k = k;
						diff = maximum - minimum;
						printf("diff is %d\n", diff);
				}
				if(diff==0) break;

				if(A[i]==minimum) i++;
				else if(B[j]==minimum) j++;
				else k++;
		}
		//printf("A is %d, B is %d and C is %d", A[i],B[j],C[k]);
		printf("res_i is %d, res_j is %d, res_j is %d\n", res_i, res_j, res_k);
		return diff;

}

int main(int argc, char* argv)
{

		int A[] = {1, 4, 10};
		int B[] = {2, 15, 20};
		int C[] = {10, 12};

		printf("Output : %d\n",minimize(A,3,B,3,C,2));
		return 0;
}
