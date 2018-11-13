
/*=========================================

* File Name		:	jump_game_array.c

* Purpose		:	A func() that returns whether the last index 
					of an array is reachable if the max jumps are from
					any index is the array value at that index.

* Creation Date	:	14-11-2018

* Last Modified	:	Wednesday 14 November 2018 12:50:58 AM IST

* Created By	: 	Prathu Baronia, 14D070046 

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

int canJump(int* A, int n1) {

		// Basecases
		if(n1==1) return 1;

		if(A[0]==0) return 0;

		int i,j;

		// An array which says if a particular index is reachable or not
		int* can_reach = (int*) malloc(n1*sizeof(int));
		for(i=0;i<n1;i++) can_reach[i] = 0;
		can_reach[0]=1; // Initial condition since A[0]==0 has been handled above

		for(i=0;i<n1-1;i++)
		{
				// Mark points reachable from i if i is reachable
				if(can_reach[i]==1)
				{
						for(j=i;j<=i+A[i];j++)
						{
								if(j<n1) can_reach[j]=1;
						}
				}
		}
		return can_reach[n1-1];
}


int main(int argc, char* argv)
{

		return 0;
}
