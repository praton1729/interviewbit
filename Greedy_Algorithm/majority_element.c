
/*=========================================

* File Name : majority_element.c

* Purpose 	: A func() that returns the majority
			  element in an array given it exists.

* Creation Date : 23-10-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

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
 * 
 * @Output Integer
 */

int majorityElement(const int* A, int n1) {
    int major_index = 0;
    int count = 1,i;
    
    for(i=0;i<n1;i++){
        if(A[major_index]==A[i]) count++;
        else count--;
        
        if(count==0){
            major_index = i;
            count = 1;
        }
    }
    
    for(i=0;i<n1;i++){
        if(A[i]==A[major_index]) count++;
        if(count > n1/2) return A[major_index];
    }
    return ;
}

int main(int argc, char* argv)
{

	return 0;
}
