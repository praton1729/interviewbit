
/*=========================================

* File Name : find_matrix_median.c

* Purpose :

* Creation Date : 14-09-2018

* Last Modified : Friday 14 September 2018 09:57:03 PM IST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer
 */

int upper_bound(int** A, int i, int low, int high, int B){

		//Binary search to find count of numbers less than
		// mid in i_th row of A
		if(B<=A[i][low]) return low;  

		int mid = (low+high)/2;

		if(A[i][mid]==B){
				return mid;  
		} 
		else if(A[i][mid]<B){
				if(mid+1<=high && B<=A[i][mid+1]) return mid+1;
				else return upper_bound(A, i, mid+1, high, B);
		}
		else{
				if(mid-1>= low && B>A[i][mid-1]) return mid;
				else return upper_bound(A, i, low, mid-1, B);
		}
}

int findMedian(int A[][], int n11, int n12) {

		int min = INT_MAX;
		int max = INT_MIN;
		int i;

		for(i=0;i<n11;i++){
				if(A[i][0] < min) min = A[i][0];
				if(A[i][n12-1] > max) max = A[i][n12-1];
		}

		int req_count = (n11*n12+1)/2;
		int mid;
		int place = 0;
		int j;

		while(min<max)
		{
				mid = min + (max-min)/2;
				for(j=0;j<n11;j++){
						place += upper_bound(A, i, 0, n12-1, mid);
				}
				if(place < req_count) min = mid + 1;
				else max = mid;
		}

		return mid;
}

int main(int argc, char* argv)
{
		int r=3,c=3;

		//int** A = (int**) malloc(r*sizeof(int*));

		//int j;

		//for(j=0;j<r;j++) A[j] = (int*) malloc(c*sizeof(int));

		int A[3][3] = {{1,3,5},{2,6,9},{3,6,9}};

		findMedian(A,r,c);
		return 0;
}
