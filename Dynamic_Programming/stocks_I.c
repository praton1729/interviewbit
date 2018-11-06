
/*=========================================

* File Name		:	stocks_I.c

* Purpose		:	A func() to calculate the max 
					diff between elements such that
					the bigger element appears after 
					the smaller one.

* Creation Date	:	06-11-2018

* Last Modified	:	Tuesday 06 November 2018 05:27:57 PM IST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

int max(int a, int b)
{
		return ((a)>(b))?(a):(b);
}

int min(int a, int b)
{
		return ((a)<(b))?(a):(b);
}

int maxProfit(const int* A, int n1) {

		// find j for an i such that A[j] - A[i] is maximum;
		int max_profit_till_now, new_profit;
		int min_rate_till_now, i;

		max_profit_till_now = 0;
		min_rate_till_now = A[0];

		for(i=1;i<n1;i++)
		{
				new_profit = A[i] - min_rate_till_now;
				max_profit_till_now = max(new_profit, max_profit_till_now);
				min_rate_till_now = min(A[i],min_rate_till_now);
		}

		return max_profit_till_now;
}


int main(int argc, char* argv)
{

		return 0;
}
