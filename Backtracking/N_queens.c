
/*=========================================

 * File Name : N_queens.c

 * Purpose 	: A func() that solves the famous 
 N Queen problem and prints it.

 * Creation Date : 31-10-2018

 * Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

 * Created By : Prathu Baronia, 14D070046 

 ==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

void print_matrix(int** A, int rows, int cols)
{

		int i,j;
		for(i=0;i<rows;i++)
		{
				for(j=0;j<cols;j++)
				{
						printf("%d ",A[i][j]);
				}
				printf("\n");
		}
		printf("\n");
		return;
}

int Lower_diag_is_clear(int** board,int N, int row, int col)
{
		int i,j;
		for(i=row,j=col;i>=0 && j>=0;i--,j--)
		{
				if(board[i][j]==1) return 0;
		}
		return 1;
}

int Upper_diag_is_clear(int** board, int N,int row, int col)
{
		int i,j;
		for(i=row,j=col;i<N && j>=0;i++,j--)
		{
				if(board[i][j]==1) return 0;
		}
		return 1;
}

int Row_is_clear(int** board, int row, int col)
{
		int j;
		for(j=0;j<col;j++)
		{
				if(board[row][j]==1) return 0;
		}
		return 1;
}

int is_safe(int** board, int N, int row, int col)
{
		return (Lower_diag_is_clear(board,N,row,col) && Upper_diag_is_clear(board,N,row,col) && Row_is_clear(board, row,col));
}

void Place_queen(int** board, int row, int col)
{
		board[row][col] = 1;
		return;
}

void Remove_queen(int** board, int row, int col)
{
		board[row][col] = 0;
		return;
}

int solve_n_queens(int** board,int N,int col)
{
		if(col >= N)
		{ 
				print_matrix(board,N,N);
				return 1;
		}
		int row_to_try = 0;

		for(row_to_try=0;row_to_try<N;row_to_try++)
		{
				if(is_safe(board,N,row_to_try,col))
				{
						Place_queen(board,row_to_try,col);
						//printf("Col value: %d \n\n",col);
						//print_matrix(board,N,N);
						if(solve_n_queens(board,N,col+1)) 
						{
								//print_matrix(board,N,N);
								return 1;
								//break;
						}
						Remove_queen(board,row_to_try,col);
				}

		}
		return 0;
}

void clear_matrix(int** A,int rows,int cols)
{
		int i,j;
		for(i=0;i<rows;i++)
		{
				for(j=0;j<cols;j++)
				{ 
						A[i][j] = 0;
				}
		}

}
void solve_n_queens_wrapper(int** board,int N)
{
		clear_matrix(board,N,N);
		solve_n_queens(board,N,0); 
		return ;
}

int main(int argc, char** argv)
{
		int N = atoi(argv[1]);
		int i;
		
		if(N<=3)
		{
				printf("No solution exists\n");
				return 0;
		}

		int** solution = (int**) malloc(N*sizeof(int*));
		for(i=0;i<N;i++) solution[i] = (int*) malloc(N*sizeof(int));
		
		printf("\n Final Output: \n \n");
		solve_n_queens_wrapper(solution,N);
		//print_matrix(solution,N,N);

		return 0;
}
