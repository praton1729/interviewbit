
/*=================================================

* File Name 	: pointer_test.c

* Purpose 		: pointer passing between functions

* Creation Date : 01-11-2018

* Last Modified : Thursday 01 November 2018 11:52:27 PM IST

* Created By 	: Prathu Baronia, 14D070046 

==================================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

void direct_change(int* a, int n)
{
	*a = n;
	return;	
}

void indirect_change(int* a,int n)
{
	direct_change(a,n);
	return;
}

int main(int argc, char* argv)
{
	int x = 0;
	int* a = &x;

	*a = 0;
	direct_change(a,2);
	printf("a now points to : %d\n",*a);
	*a = 3;
	indirect_change(a,3);
	printf("a now points to : %d\n",*a);	
	return 0;
}
