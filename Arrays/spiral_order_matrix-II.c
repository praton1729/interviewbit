
/*=========================================

* File Name		:	spiral_order_matrix-II.c

* Purpose		:	A func() that fills up a 
					matrix in a spiral order
					with elements from 1 to n^2	
					where n is a given integer.

* Creation Date	:	16-11-2018

* Last Modified	:	Mon 22 Dec 2008 10:36:49 PM PST

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
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, len2 as columns 
 */

int ** generateMatrix(int A, int *len1, int *len2) {

		int rows = A;
		int cols = A;

		*len1 = rows;
		*len2 = cols;

		int i,j;
		int** result = (int**) malloc(rows*sizeof(int*));

		for(i=0;i<rows;i++) result[i] = (int*) malloc(cols*sizeof(int));

		int Top = 0;
		int Bottom = rows-1;
		int Left = 0;
		int Right = cols-1;
		int count = 1;
		int dir = 0;

		while(Top<=Bottom && Left<=Right)
		{
				if(dir==0)
				{
						for(j=Left;j<=Right;j++) 
						{
								result[Top][j] = count;
								count++;
						}
						Top++;
				}
				else if(dir==1)
				{
						for(i=Top;i<=Bottom;i++) 
						{
								result[i][Right] = count;
								count++;
						}
						Right--;
				}
				else if(dir==2)
				{
						for(j=Right;j>=Left;j--) 
						{
								result[Bottom][j] = count;
								count++;
						}
						Bottom--;
				}
				else
				{
						for(i=Bottom;i>=Top;i--) 
						{
								result[i][Left] = count;
								count++;
						}
						Left++;
				}
				dir = (dir+1)%4;
		}
		return result;
}


int main(int argc, char* argv)
{

		return 0;
}
