
/*=========================================

* File Name		:	n_chords.c

* Purpose		:	A func() that returns the number of ways N
					non intersecting chords can be drawn with 
					2*N points in a circle.

* Creation Date	:	16-11-2018

* Last Modified	:	Friday 16 November 2018 07:54:42 PM IST

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

#define MOD 1000000007

int chordCnt(int A) {

		int n = 2*A,i,j;
		unsigned long long int* chord_array = (unsigned long long int*) malloc((n+1)*sizeof(unsigned long long int));

		for(i=0;i<n+1;i++) chord_array[i] = 0;

		chord_array[0] = 1;
		chord_array[2] = 1;

		for(i=4;i<=n;i+=2)
		{
				for(j=0;j<i-1;j+=2)
				{
						chord_array[i] += (chord_array[j]*chord_array[i-2-j]);
						chord_array[i] %= MOD;  
				}
		}
		return chord_array[n];
}


int main(int argc, char* argv)
{

		return 0;
}
