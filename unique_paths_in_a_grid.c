
/*=========================================

* File Name		:	unique_paths_in_a_grid.c

* Purpose		:	Count number of unique paths
					from top left to bottom right
					point in a grid with obstacles.

* Creation Date	:	10-11-2018

* Last Modified	:	Mon 22 Dec 2008 10:36:49 PM PST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer
 */

int uniquePathsWithObstacles(int** A, int n11, int n12) {
		int** path_matrix = (int**) malloc(n11*sizeof(int*));
		int i,j;

		for(i=0;i<n11;i++) path_matrix[i] = (int*) malloc(n12*sizeof(int));

		//path matrix initialization
		for(i=0;i<n11;i++)
		{
				for(j=0;j<n12;j++)
				{
						path_matrix[i][j] = 0;
				}
		}

		if(A[0][0]==0) path_matrix[0][0] = 1;

		// first col initialization
		for(i=1;i<n11;i++)
		{
				if(A[i][0]==0) path_matrix[i][0] = path_matrix[i-1][0];
		}

		//first row initialization
		for(j=1;j<n12;j++)
		{
				if(A[0][j]==0) path_matrix[0][j] = path_matrix[0][j-1];
		}

		for(i=1;i<n11;i++)
		{
				for(j=1;j<n12;j++)
				{
						if(A[i][j]==0) path_matrix[i][j] = path_matrix[i-1][j] + path_matrix[i][j-1];
				}
		}
		return path_matrix[n11-1][n12-1];
}

int main(int argc, char* argv)
{

		return 0;
}
