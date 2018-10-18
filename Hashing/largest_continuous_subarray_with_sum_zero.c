
/*=========================================

 * File Name : largest_continuous_subarray_with_sum_zero.c

 * Purpose 	 : A func() that returns out the largest subarray 
			   with sum zero if it exits otherwise returns nothing.

 * Creation Date : 18-10-2018

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
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

int* lszero(int* A, int n1, int *len1) {

		if(n1<2) return A;

		int left = 0;
		int right = 0,i,j;
		int max_len = 0;
		int curr_len = 0;

		int* tmp = (int*) malloc(n1*sizeof(int));

		tmp[0] = A[0];

		for(i=1;i<n1;i++) tmp[i] = tmp[i-1] + A[i];

		for(j=0;j<n1;j++){
				if(tmp[j]==0){
						curr_len = j+1;
						if(curr_len > max_len){
								right = j;
								left  = 0;
								max_len = curr_len;
						}
				}
		}

		for(i=0;i<n1-1;i++){
				for(j=i;j<n1;j++){
						if(tmp[i]==tmp[j]){
								curr_len = j-i;
								if(curr_len > max_len){
										right = j;
										left = i+1;
										max_len = curr_len;
								}
						}
				}
		}

		// printf("right is : %d and left is : %d \n",right,left);
		if(right==0 && left==0) return;

		int result_len = right - left + 1;
		*len1 = result_len;
		int* result = (int*) malloc(result_len*sizeof(int));

		for(i=0;i<result_len;i++){
				result[i] = A[left+i];
		}
		return result;
}


int main(int argc, char* argv)
{

	return 0;
}
