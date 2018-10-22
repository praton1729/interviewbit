
/*=========================================

* File Name : light_bulbs.c

* Purpose 	: A func() which returns minimum 
			  number of switches to be flipped
			  to light all the bulbs. 

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
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int bulbs(int* A, int n1) {
    int i,count=0;
    
    for(i=0;i<n1;i++){
        if(A[i]==1 && count%2==0) continue;
        else if(A[i]==0 && count%2==0) count++;
        else if(A[i]==1 && count%2!=0) count++;
        else if(A[i]==0 && count%2!=0) continue;
    }
    return count;
}

int main(int argc, char* argv)
{

	return 0;
}
