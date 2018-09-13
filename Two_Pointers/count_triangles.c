
/*=========================================

* File Name : count_triangles.c

* Purpose : Count the number of possible
			triangles from array elements

* Creation Date : 14-09-2018

* Last Modified : Friday 14 September 2018 01:46:39 AM IST

* Created By : Prathu Baronia 

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
 
 int compare(const void* a, const void* b){
     return ( *(int*)a - *(int*)b);
 }
 
int nTriang(int* A, int n1) {
    
    qsort(A, n1, sizeof(int),compare);
 
    int i = 0,j = 0,k;
    long int count = 0;
    
    for(i=0;i<n1-2;i++){
        
        k = n1-1;
        
        for(j=i+1;j<n1;j++){
            
            while(k>j && A[i]+A[j] <= A[k]) k--;
            
            count += k-j-1;
        }
    }
    
    return (int) (count%((long int) pow(10,9)+7));
}

int main(int argc, char* argv)
{
	return 0;
}
