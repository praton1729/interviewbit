
/*=========================================

* File Name : redundant_braces.c

* Purpose 	: A func() that detects redundant
			  braces in a given string, for 
			  example "(a+(b))" has a redundant brace 
			  pair.

* Creation Date : 16-10-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

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
 * @Output Integer
 */

int braces(char* A) {

		char stack[1000];
		int i,top = -1;

		for(i=0;i<strlen(A);i++){

				if(A[i]==')')
				{
						char top_char = stack[top--];
						int result = 1;

						while(top_char!='(')
						{
								if(top_char=='+' || top_char=='-' || top_char=='*' || top_char=='/') result = 0;
								top_char = stack[top--];
						}
						if(result==1) return 1;
				}
				else stack[++top] = A[i];
		}
		return 0;
}


int main(int argc, char* argv)
{

	return 0;
}
