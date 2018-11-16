
/*=========================================

* File Name		:	stocks_II.c

* Purpose		:	A func() to find the max profit
					that can be made through a given stock
					by following a trend based approach
					of buying when the price seems to find a
					local minima and selling when it gets to
					a local maxima.

* Creation Date	:	16-11-2018

* Last Modified	:	Friday 16 November 2018 01:26:43 PM IST

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

int maxProfit(const int* A, int n1)
{
		if(n1==1) return 0;

		int profit=0,i=0,buy,sell;

		while(i<n1-1)
		{
				while((i<n1-1) && (A[i+1]<=A[i])) i++;

				if(i==n1-1) break;

				buy = i++;

				while((i<n1) && (A[i]>=A[i-1])) i++;

				sell = i-1;

				profit += (A[sell]-A[buy]);
		}

		return profit;
}

int main(int argc, char* argv)
{

		return 0;
}
