
/*=========================================

* File Name : 3sum_zero_interviewbit_solution.c

* Purpose :

* Creation Date : 27-09-2018

* Last Modified : Thursday 27 September 2018 09:52:05 PM IST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

int compare (const void * a, const void * b)
{
		return ( *(int*)a - *(int*)b );
}

int** threeSum(int* A, int n1, int *len1, int *len2) {
		int **B,i=0,j,k,temp;
		B=malloc(((n1*(n1-1))/2)*sizeof(int *));
		*len1=0;
		qsort(A,n1,sizeof(int),compare);
		while(i<n1 && A[i]<=0){
				j=i+1;
				k=n1-1;
				while(j<k){
						if(A[i]+A[j]+A[k]>0)
								k--;
						else if(A[i]+A[j]+A[k]<0)
								j++;
						else{
								B[*len1]=malloc(3*sizeof(int));
								B[*len1][0]=A[i];
								B[*len1][1]=A[j];
								B[*len1][2]=A[k];
								(*len1)++;
								temp=A[j];
								while(j<n1 && A[j]==temp)
										j++;
						}
				}
				temp=A[i];
				while(i<n1 && A[i]==temp)
						i++;
		}
		*len2=3;
		return B;

}

int main(int argc, char* argv)
{

		return 0;
}
