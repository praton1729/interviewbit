
/*=========================================

 * File Name : N_queens_all_solutions_interviewbit.c

 * Purpose :

 * Creation Date : 01-11-2018

 * Last Modified : Thursday 01 November 2018 05:34:06 AM IST

 * Created By : Prathu Baronia, 14D070046 

 ==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : Integer
 * 
 * @Output 2D string array. You need to malloc memory. Fill in len1 as row, len2 as columns. All strings should end with '\0'. 
 * For example, a valid output : [["..Q.","Q...", "...Q", ".Q.." ], [".Q..", "...Q", "Q...", "..Q."]] 
 * len1 = 2, len2 = 4. 
 */

int count =0;
int count1 =0;
int mRow;
char **arr;
char *col;
char *diag1;
char *diag2;
char ***result;
char *order;

void Solve1(int row,int c)
{
		int i,j;

		if(row==mRow)
		{

				for(j=0;j<mRow;j++)
				{
						result[count1][j] = &arr[order[j]][0];
				}
				count1++;
				return;
		}

		for(i=0;i<mRow;i++)
		{
				if(col[i]==0&&diag1[i+row]==0&&diag2[i-row+mRow]==0)
				{
						col[i] = 1;
						diag1[i+row] = 1;
						diag2[i-row+mRow] = 1;
						order[c] = i;
						Solve1(row+1,c+1);
						col[i] = 0;
						diag1[i+row] = 0;
						diag2[i-row+mRow] = 0;
				}
		}



}

void Solve(int row)
{
		int i;

		if(row==mRow)
		{
				count++;
				return;
		}

		for(i=0;i<mRow;i++)
		{
				if(col[i]==0&&diag1[i+row]==0&&diag2[i-row+mRow]==0)
				{
						col[i] = 1;
						diag1[i+row] = 1;
						diag2[i-row+mRow] = 1;
						Solve(row+1);
						col[i] = 0;
						diag1[i+row] = 0;
						diag2[i-row+mRow] = 0;
				}
		}
}

char*** solveNQueens(int A, int *len1, int *len2) {
		int i,j,k;
		arr = (char**)malloc(A*sizeof(char*));
		for(i=0;i<A;i++)
		{
				arr[i] = (char*) malloc((A+1)*sizeof(char));
				memset(arr[i],'.',(A+1)*sizeof(char));
		}
		for(i=0;i<A;i++)
		{
				arr[i][i] = 'Q';
				arr[i][A] = '\0';
		}

		col = (char*)malloc(sizeof(char)*A);
		order = (char*)malloc(sizeof(char)*A);
		diag1 = (char*)malloc(sizeof(char)*(2*A));
		diag2 = (char*)malloc(sizeof(char)*(2*A));

		memset(col,0,sizeof(char)*A);
		memset(diag1,0,sizeof(char)*2*A);
		memset(diag2,0,sizeof(char)*2*A);


		count = 0;
		mRow = A;
		Solve(0);
		//   printf("::%d\n",count);

		*len1 = count;
		*len2 = A;


		result = (char***)malloc(sizeof(char**)*count);
		for(i=0;i<count;i++)
		{
				result[i] = (char**)malloc(sizeof(char*)*A);
				for(j=0;j<A;j++)
						result[i][j] = &arr[j][0];
		}
		count1 =0;
		Solve1(0,0);

		return result;
}

int main(int argc, char* argv)
{

	return 0;
}
