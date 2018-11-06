
/*=========================================

* File Name		:	min_sum_path.c

* Purpose		:

* Creation Date	:	06-11-2018

* Last Modified	:	Tuesday 06 November 2018 05:04:08 PM IST

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

int min(int a, int b)
{
    return ((a)<(b))?(a):(b);
}

int minPathSum(int** A, int n11, int n12) {
    
    int** min_sum_matrix = (int**) malloc(n11*sizeof(int*));
    int i,j;
    
    for(i=0;i<n11;i++) min_sum_matrix[i] = (int*) malloc(n12*sizeof(int));
    
    min_sum_matrix[0][0] = A[0][0];
    
    //First Row    
    for(j=1;j<n12;j++) min_sum_matrix[0][j] = A[0][j] + min_sum_matrix[0][j-1];
    
    //First Col
    for(i=1;i<n11;i++) min_sum_matrix[i][0] = A[i][0] + min_sum_matrix[i-1][0];
    
    for(i=1;i<n11;i++)
    {
        for(j=1;j<n12;j++)
        {
        min_sum_matrix[i][j] = A[i][j] + min(min_sum_matrix[i-1][j],min_sum_matrix[i][j-1]);
        }
    }
    
    return min_sum_matrix[n11-1][n12-1];
}


int main(int argc, char* argv)
{
	int row,col;

	scanf("%d %d",&row,&col);

    int** A = (int**) malloc(row*sizeof(int*));
    int i,j;
    
    for(i=0;i<row;i++) A[i] = (int*) malloc(col*sizeof(int));

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			//printf("Enter input : \n");
			scanf("%d",&A[i][j]);
		}

	}
	
	int result=	minPathSum(A,row,col);

	printf("result is : %d\n",result);

	return 0;
}
