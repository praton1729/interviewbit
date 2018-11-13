
/*=========================================

* File Name		:	n_digits_with_sum_S.c

* Purpose		:	A func() that returns the 
					number of N digit numbers
					with digit sum as S.

* Creation Date	:	14-11-2018

* Last Modified	:	Wednesday 14 November 2018 03:40:48 AM IST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : Integer
 * @input B : Integer
 * 
 * @Output Integer
 */

#define MOD 1000000007
#define MAX_N 1000
#define MAX_SUM 1000

unsigned long long int lookup[MAX_N][MAX_SUM]; 

unsigned long long int count_sum(int n, int sum)
{
		if(n==0) return (sum==0);
		if(sum==0) return 1;

		if(lookup[n][sum] != -1) return lookup[n][sum];    
		unsigned long long int ans = 0;
		int i;

		for(i=0;i<=9;i++)
		{
				if(sum-i >= 0) 
				{
						ans += count_sum(n-1,sum-i);
						ans = ans%MOD;
				}
		}

		lookup[n][sum] = ans;
		return ans;
}

int solve(int N, int S)
{
		unsigned long long int ans = 0;
		int i=0,j;

		for(i=0;i<MAX_N;i++)
		{
				for(j=0;j<MAX_SUM;j++)
				{
						lookup[i][j] = -1;
				}
		}

		for(i=1;i<=9;i++)
		{
				ans += count_sum(N-1,S-i);
				ans = ans%MOD;
		}

		int result = ans%MOD;
		return result;
}


int main(int argc, char* argv)
{
		int N = 75;
		int S = 22;

		int result = solve(N,S);

		printf("Result is : %d\n",result);

		return 0;
}
