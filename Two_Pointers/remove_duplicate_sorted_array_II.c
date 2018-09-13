
/*=========================================

* File Name : remove_duplicate_sorted_array_II.c

* Purpose : remove duplicates and leave atmost 
			two copies in a sorted array

* Creation Date : 13-09-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

* Created By : Prathu Baronia 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int removeDuplicates(int* A, int n1) {

		if(n1==1) return 1;

		int i,j = 0,count = 0;

		for(i=0;i<n1-1;i++){

				if(A[i]!=A[i+1] && count>=1){
						A[j++] = A[i];
						A[j++] = A[i];
						count = 0;
				}
				else if(A[i]!=A[i+1] && count==0){
						A[j++] = A[i];
						count = 0;
				}
				else
				{
						count++;
				}
		}
		if(count==0){
				A[j++] = A[n1-1];
		}
		else{

				A[j++] = A[n1-1];
				A[j++] = A[n1-1];
		}

		return j;
}

int main(int argc, char* argv)
{

	return 0;
}
