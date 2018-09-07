#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* LCP_two_strings(char* x, char* y)
{
	int len_x = strlen(x);
	int len_y = strlen(y);

	int min_len = (len_x < len_y) ? len_x:len_y;

	char* result = (char*)malloc(sizeof(char)*min_len);

	int i = 0;

	for( i=0;i<min_len;i++)
	{
		if(x[i]!=y[i]) break;

		result[i] = x[i];
		//strcpy(result);
	}

	return result;	

}

char* longestCommonPrefix(char** A, int n1) {

	char* result = (char*)malloc(sizeof(char)*strlen(A[0]));

	result = A[0];

	int i = 0;

	for(i=1;i<n1;i++){

		result = LCP_two_strings(result,A[i]); 

	}

	return result;
}

int main(){

//	char sample[2][10] = { "hello", "world" };

	return 0;
}
