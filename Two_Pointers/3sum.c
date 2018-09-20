
/*=========================================

* File Name : 3sum.c

* Purpose   : Finds the sum closest to a 
			  given target value 

* Creation Date : 21-09-2018

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
 * @input B : Integer
 * 
 * @Output Integer
 */
 
int compare(const void* a, const void* b){
		return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* A, int n1, int B) {

		int min_input_length = 3;

		if(n1 < min_input_length) return -1;

		qsort(A, n1, sizeof(int), compare);

		int result = A[0] + A[1] + A[2], temp_sum;
		int prev_diff = abs(B - result), temp_diff;
		int i,j,k;

		for(i=0;i<n1-1;i++){
				j = i+1;
				k = n1-1;

				while(j<k){
						temp_sum = A[i]+A[j]+A[k];
						temp_diff = abs(B - temp_sum);

						if(temp_diff==0) return (temp_sum);
						else if(temp_sum < B){
								if(temp_diff < prev_diff) prev_diff = temp_diff, result = temp_sum;
								j++;
						}
						else{
								if(temp_diff < prev_diff) prev_diff = temp_diff, result = temp_sum;
								k--;
						}
				}

		}

		return result;

}

int main(int argc, char* argv)
{

	return 0;
}
