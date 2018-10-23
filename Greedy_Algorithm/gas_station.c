
/*=========================================

* File Name : gas_station.c

* Purpose 	: A func() that finds the min index 
			  from where a complete trip is possible
			  on a track with location of petrol pumps 
			  and travel costs provided in two arrays.

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
 * @input B : Read only ( DON'T MODIFY ) Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer
 */

int canCompleteCircuit(const int* A, int n1, const int* B, int n2) {
    
    // Assuuming A is Gas Array and B is Cost Array
    
    int start=0;
    int end = 1;
    
    int current_gas = A[start] - B[start];
    
    while(end!=start || current_gas<0){
        while(current_gas < 0 && start!=end){
            current_gas -= A[start] - B[start];
            start = (start+1)%n1;
            if(start==0) return -1;
        }
        current_gas += A[end] - B[end];
        end = (end+1)%n1;
    }
    
    return start;
}

int main(int argc, char* argv)
{

	return 0;
}
