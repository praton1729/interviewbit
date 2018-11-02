
/*=========================================

* File Name : letter_phone.c

* Purpose :

* Creation Date : 01-11-2018

* Last Modified : Thursday 01 November 2018 08:31:48 AM IST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : String termination by '\0'
 * 
 * @Output string array. You need to malloc memory. 
 *   Fill in len1 as number of strings. Make sure every string ends with null character
 */

void print_matrix(char** A, int rows, int cols)
{

		int i,j;
		for(i=0;i<rows;i++)
		{
				for(j=0;j<cols;j++)
				{
						printf("%c ",A[i][j]);
				}
				printf("\n");
		}
		printf("\n");
		return;
}
 
int total_combinations(char* A,char** map)
{
		int total = 1,i;
		int key_len;
		int key;

		for(i=0;i<strlen(A);i++){
				key = A[i]- 48;
				key_len = strlen(map[key]);
				total *= key_len;
		}
		return total;
}

void fill_result_with_combinations(char* A, int n, char** result, int** len, int index,char* temp, char** map)
{
		if(index>=n)
		{
				int j;
				int row = **len;
				for(j=0;j<=n;j++) result[row][j] = temp[j];
				(**len)++;
				return;
		}
		int i;
		int key = A[index]- 48;
		int key_len = strlen(map[key]);
		for(i=0;i<key_len;i++){
				temp[index] = map[key][i];
				temp[n] = '\0';
				fill_result_with_combinations(A,n,result,len,index+1,temp,map);
		}
}

char** letterCombinations(char* A, int *len1)
 {
		char* letter_map[10] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		printf("char at 2,0 is %c \n ",letter_map[2][0]);
		int n = strlen(A),i;
		int MAX_STRINGS = 10000;
		//char result[MAX_STRINGS][n+1];

		char** result = (char**) malloc(sizeof(char*));	
		for(i=0;i<MAX_STRINGS;i++) result[i] = (char*) malloc((n+1)*sizeof(char));

		char* temp = (char*) malloc((n+1)*sizeof(char));

		fill_result_with_combinations(A,n,result,&len1,0,temp,letter_map);
		//*len1 = total_combinations(A,letter_map);

		print_matrix(result,(*len1),n);

		return result;
}


int main(int argc, char** argv)
{
	char* A = argv[1];
	int* len1 = 0;
	letterCombinations(A,len1);
	return 0;
}
