
/*=========================================

* File Name		:	stairs.c

* Purpose		:	A func() that computes the
					number of ways a stair can be reached
					by jumping either 1 or 2 stairs at a time.

* Creation Date	:	06-11-2018

* Last Modified	:	Tuesday 06 November 2018 04:12:50 PM IST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : Integer
 * 
 * @Output Integer
 */

#define MAX_N 1000
 
int climbStairs(int A, int* ways)
{
	if(A<=2) return ways[A];

    int i;
 
	if(ways[A] == -1) 
			ways[A] = climbStairs(A-1,ways) + climbStairs(A-2,ways);
    
    return ways[A];
}

int main(int argc, char* argv)
{
		int* ways = (int*) malloc(MAX_N*sizeof(int));
		int i;

		for(i=0;i<MAX_N;i++) ways[i] = -1;

		ways[0] = 0;
		ways[1] = 1;
		ways[2] = 2;

		climbStairs(10,ways);
		return 0;
}
