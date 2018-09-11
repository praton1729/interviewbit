
/*=========================================

* File Name : search_insert.c

* Purpose : Returns the index of the insertable 
			position in a sorted array of integers 

* Creation Date : 11-09-2018

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
 * @input B : Integer
 * 
 * @Output Integer
 */

int searchInsert(int* A, int n1, int B) {
    
    int left = 0;
    int right = n1-1;
    
    int mid = (left+right)/2;
    
    while(right>left)
    {
        if(A[mid] < B)
        {
            left = mid+1;
        }
        else
        {
            right = mid;
        }
        mid = (left + right)/2 ;
    }
    
    if(A[left]==B || A[left]>B)
    {
        return left;
    }
    else if(A[left]<B)
    {
        return left+1;
    }
}

int main(int argc, char* argv)
{

	return 0;
}
