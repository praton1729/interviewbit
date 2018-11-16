/*=========================================

* File Name		:	is_scramble.c

* Purpose		:	A func() that returns true if
					the second string is a scrambled 
					form of the first string.

* Creation Date	:	16-11-2018

* Last Modified	:	Friday 16 November 2018 11:50:51 PM IST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : Read only ( DON'T MODIFY ) String termination by '\0'
 * @input B : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */

int isScramble(const char* A, const char* B)
{
		int len_A = strlen(A);
		int len_B = strlen(B);

		if(len_A!=len_B) return 0;

		int*** F =  (int***) malloc(len_A*sizeof(int**));

		int i,j,k,q;

		for(i=0;i<len_A;i++) F[i] = (int**) malloc(len_A*sizeof(int*));

		for(i=0;i<len_A;i++)
		{
				for(j=0;j<len_A;j++)
				{
						F[i][j] = (int*) malloc((len_A+1)*sizeof(int));
				}
		}

		for(k=0;k<=len_A;k++)
		{
				for(i=0;i+k<=len_A;i++)
				{
						for(j=0;j+k<=len_A;j++)
						{
								if(k==1)
								{
										if(A[i]==B[j]) F[i][j][k] = 1;
										else F[i][j][k] = 0;
								}
								else
								{
										for(q=1;q<k && !F[i][j][k];q++)
										{
												F[i][j][k] = (F[i][j][q] && F[i+q][j+q][k-q]) || (F[i][j+k-q][q] && F[i+q][j][k-q]);
										}
								}
						}
				}
		}
		return F[0][0][len_A];
}


int main(int argc, char* argv)
{

		return 0;
}
