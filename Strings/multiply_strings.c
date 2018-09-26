
/*=========================================

* File Name : multiply_strings.c

* Purpose 	: Returns the string product
			  of two very large numbers
			  in string format.

* Creation Date : 25-09-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/*
 * @input A : String termination by '\0'
 * @input B : String termination by '\0'
 * 
 * @Output string. Make sure the string ends with null character
 *
*/

char* multiply(char* A, char* B) {

		int n_A = strlen(A);
		int n_B = strlen(B);

		if(n_A==0 || n_B==0) return "0";

		int* result = (int*) malloc(sizeof(int)*(n_A+n_B));

		int i,j;
		for(j=0;j<n_A+n_B;result[j]=0,j++);

		int i_A=0;
		int i_B=0;

		for(i=n_A-1;i>=0;i--){

				int carry = 0;
				int digit_A = A[i] - '0';

				i_B = 0;

				for(j=n_B-1;j>=0;j--){

						int digit_B = B[j] - '0';

						int sum = digit_A*digit_B + result[i_A+i_B] + carry;

						carry = sum/10;
						result[i_A+i_B] = sum%10;
						i_B++;
				}
				if(carry>0) result[i_A+i_B] += carry;
				i_A++;
		}

		char* zero_string = "0";

		i = n_A+n_B-1;
		while(i>=0 && result[i]==0) i--;

		if(i==-1) return zero_string;

		char* ret = (char*) malloc(sizeof(char)*(i+2));

		ret[i+1] = '\0';
		int len = i;
		while(i>=0) ret[len-i] = result[i]+48,i--;
		free(result);
		return ret;

}


int main(int argc, char* argv)
{
	
	char* A = "99999";
	char* B = "99999";

	char* ret = (char*)malloc(sizeof(char)*12);
	ret = multiply(A,B);

	printf("product of %s and %s is : %s\n",A,B, ret);
	free(ret);

	return 0;
}
