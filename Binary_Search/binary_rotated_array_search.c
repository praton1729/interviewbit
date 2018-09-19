
/*=========================================

* File Name : binary_rotated_array_search.c

* Purpose : Search for the minimum element
			through binary search in a rotated
			sorted array.

* Creation Date : 20-09-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/*
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 *
*/
 
int binary_rotation_index(const int* A, int n1){
    
    int low = 0, high = n1-1;
    
    while(low <= high){
        
        if(A[low]<=A[high]) return low;
        int mid = low + (high-low)/2;
        int next = (mid+1)%n1;
        int prev = (mid+n1-1)%n1;
        
        if(A[prev] >= A[mid] && A[next] >= A[mid]) return mid;
        else if(A[mid] <= A[high]) high = mid - 1;
        else if(A[mid] >= A[low]) low = mid + 1;
    }
    
   return -1;
}

int findMin(const int* A, int n1) {
    
    int result = binary_rotation_index(A, n1);
    
    return A[result];
}

int main(int argc, char* argv)
{

	return 0;
}
